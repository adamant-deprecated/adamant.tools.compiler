using System;
using System.Text;
using System.Web;

namespace Bootstrap.Transpiler
{
	public class Transpiler
	{
		private string Source;
		private string Token;
		private int NextTokenPosition;
		private readonly StringBuilder Output = new StringBuilder();
		private int IndentDepth;
		private bool AfterDeclaration;
		private string MainFunctionReturnType;
		private bool MainFunctionAcceptsConsole;
		private bool MainFunctionAcceptsArgs;

		#region Code Writing
		private void Error(string format, params object[] args)
		{
			Output.AppendFormat("<$ " + format + " $>", args);
		}

		private void BeginLine(string format, params object[] args)
		{
			if(AfterDeclaration)
			{
				Output.AppendLine();
				AfterDeclaration = false;
			}
			Output.Append(new string('\t', IndentDepth));
			Output.AppendFormat(format, args);
		}

		private void Write(string format, params object[] args)
		{
			Output.AppendFormat(format, args);
		}

		private void EndLine(string format, params object[] args)
		{
			Output.AppendFormat(format, args);
			Output.AppendLine();
		}

		private void WriteLine(string format, params object[] args)
		{
			if(AfterDeclaration)
			{
				Output.AppendLine();
				AfterDeclaration = false;
			}
			Output.Append(new string('\t', IndentDepth));
			Output.AppendFormat(format, args);
			Output.AppendLine();
		}

		private void BeginBlock()
		{
			WriteLine("{{");
			IndentDepth++;
		}

		private void EndBlock()
		{
			AfterDeclaration = false; // so that we don't put a blank line between two closing braces
			IndentDepth--;
			WriteLine("}}");
			AfterDeclaration = true;
		}
		#endregion

		#region Lexer
		private void ReadFirstToken()
		{
			if(NextTokenPosition != 0)
				throw new NotSupportedException("Can't read first token of context that already has tokens read.");

			ReadToken();
		}

		private void ReadToken()
		{
			var position = NextTokenPosition;
			var tokenEnd = -1;
			while(position < Source.Length)
			{
				var curChar = Source[position];
				switch(curChar)
				{
					case ' ':
					case '\t':
					case '\n':
					case '\r':
						position += 1;
						continue;
					case '{':
					case '}':
					case '(':
					case ')':
					case ';':
					case ',':
					case '.':
					case ':':
					case '=':
					case '+':
						tokenEnd = position + 1;
						goto done;
					case '-':
						if(position + 1 < Source.Length && Source[position + 1] == '>')
						{
							// it is `->`
							tokenEnd = position + 2;
							goto done;
						}
						// it is `-`
						tokenEnd = position + 1;
						goto done;
					case '"':
						tokenEnd = position + 1;
						while(tokenEnd < Source.Length && Source[tokenEnd] != '"')
							tokenEnd++;
						tokenEnd += 1; // To include the close quote
						goto done;
					case '\'':
						tokenEnd = position + 1;
						while(tokenEnd < Source.Length && Source[tokenEnd] != '\'')
							tokenEnd++;
						tokenEnd += 1; // To include the close quote
						goto done;
					default:
						if(IsIdentifierChar(curChar))
						{
							tokenEnd = position + 1;
							while(IsIdentifierChar(Source[tokenEnd]))
								tokenEnd++;
							goto done;
						}
						if(IsNumberChar(curChar))
						{
							tokenEnd = position + 1;
							while(IsNumberChar(Source[tokenEnd]))
								tokenEnd++;
							goto done;
						}
						Error("Lexer: Invalid character '{0}'", HttpUtility.JavaScriptStringEncode(curChar.ToString()));
						position += 1;
						break;
				}
			}

			done:
			if(tokenEnd == -1)
			{
				Token = null;
				NextTokenPosition = position;
			}
			else
			{
				Token = Source.Substring(position, tokenEnd - position);
				NextTokenPosition = tokenEnd;
			}
		}

		private bool IsIdentifierChar(char c)
		{
			return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
		}

		private bool IsNumberChar(char c)
		{
			return c >= '0' && c <= '9';
		}

		private bool TokenIsIdentifier()
		{
			if(Token == null || Token.Length == 0)
				return false;
			foreach(var @char in Token)
				if(!IsIdentifierChar(@char))
					return false;

			return true;
		}

		private bool Accept(string expected)
		{
			var accepted = Token == expected;
			if(accepted)
				ReadToken();

			return accepted;
		}

		private void Expect(string expected)
		{
			if(Token != expected)
			{
				Error("Expected '{0}' but found '{1}'", expected, Token);
				ReadToken(); // Skip token to advance
			}
			else
				ReadToken();
		}

		private bool AcceptIdentifier()
		{
			if(!TokenIsIdentifier())
				return false;

			ReadToken();
			return true;
		}

		private bool AcceptString()
		{
			if(Token.Length == 0 || Token[0] != '"')
				return false;

			ReadToken();
			return true;
		}

		private bool AcceptCodePoint()
		{
			if(Token.Length == 0 || Token[0] != '\'')
				return false;

			ReadToken();
			return true;
		}

		private bool AcceptNumber()
		{
			foreach(var @char in Token)
				if(!IsNumberChar(@char))
					return false;

			ReadToken();
			return true;
		}

		private string ExpectIdentifier()
		{
			if(!TokenIsIdentifier())
			{
				Error("Expected identifier, found '{0}'", HttpUtility.JavaScriptStringEncode(Token));
				ReadToken(); // Skip token to advance
				return "<missing>";
			}

			var identifier = Token;
			ReadToken();
			return identifier;
		}
		#endregion

		#region Parser
		// An Atom is the unit of an expression that occurs between infix operators, i.e. an identifier, literal, group, or new
		private bool ParseAtom()
		{
			if(Accept("new"))
			{
				// Constructor Call
				Write("new ");
				var type = ParseType();
				Write(ConvertType(type, true));
				Expect("(");
				Write("(");
				ParseCallArguments();
				Expect(")");
				Write(")");
				return true;
			}

			if(Accept("(")) // Order of operations parens
			{
				Write("(");
				ParseExpression();
				Expect(")");
				Write(")");
				return true;
			}

			var token = Token;
			if(AcceptIdentifier() || AcceptNumber())
			{
				Write(token);
				return true;
			}
			if(AcceptString())
			{
				Write("string({0})", token);
				return true;
			}
			if(AcceptCodePoint())
			{
				Write(token);
				return true;
			}

			return false;
		}

		private void ParseCallArguments()
		{
			var first = true;
			do
			{
				if(first)
					first = false;
				else
					Write(", ");
				ParseExpression();
			} while(Accept(","));
		}

		// Operator Precedence
		// 1: =
		// 2: +
		// 3: f() .
		private void ParseExpression(int minPrecedence = 1)
		{
			if(!ParseAtom())
				return;

			while(true)
			{
				var token = Token;
				int precedence;
				bool leftAssociative;
				if(token == "=" && minPrecedence <= 1)
				{
					// Assignment
					precedence = 1;
					leftAssociative = false;
					Write(" = ");
				}
				else if(token == "+" && minPrecedence <= 2)
				{
					// Assignment
					precedence = 2;
					leftAssociative = true;
					Write(" + ");
				}
				else if(token == "(" && minPrecedence <= 3)
				{
					// Call Expression
					ReadToken();
					Write("(");
					ParseCallArguments();
					if(Token != ")")
						Error("Expected ')' found '{0}'", Token);
					Write(")");
					precedence = 3;
					leftAssociative = true;
				}
				else if(token == "." && minPrecedence <= 3)
				{
					// Member Access
					precedence = 3;
					leftAssociative = true;
					Write("->");
				}
				else
					break;

				ReadToken();
				if(leftAssociative)
					precedence++;

				ParseExpression(precedence);
			}
		}

		private bool ParseStatement()
		{
			if(Accept("return"))
			{
				if(Accept(";"))
					WriteLine("return;");
				else
				{
					BeginLine("return ");
					ParseExpression();
					Expect(";");
					EndLine(";");
				}
				return true;
			}
			if(Accept("loop"))
			{
				WriteLine("for (;;)");
				ParseBlock();
				return true;
			}
			if(Accept("if"))
			{
				BeginLine("if(");
				ParseExpression();
				EndLine(")");
				ParseBlock();
				return true;
			}
			var kind = Token;
			if(Accept("let") || Accept("var"))
			{
				var variableName = ExpectIdentifier();
				Expect(":");
				var variableType = ParseType();
				variableType = ConvertType(variableType);
				if(kind == "let")
					variableType = "const " + variableType;
				BeginLine(variableType);
				Write(" {0}", variableName);
				if(Accept("="))
				{
					Write(" = ");
					ParseExpression();
				}
				Expect(";");
				EndLine(";");
				return true;
			}
			if(Token == "}")
				return false;

			// Assume it is an expression statement
			BeginLine("");
			ParseExpression();
			Expect(";");
			EndLine(";");
			return true;
		}

		private void ParseBlock()
		{
			Expect("{");
			BeginBlock();
			while(ParseStatement()) ;
			Expect("}");
			EndBlock();
		}

		private string ParseType()
		{
			var type = new StringBuilder(ExpectIdentifier());
			while(Accept("."))
			{
				type.Append(".");
				type.Append(ExpectIdentifier());
			}

			return type.ToString();
		}

		private string ParseArguments(bool isMainFunction)
		{
			Expect("(");
			if(Accept(")"))
				return "";

			var arguments = new StringBuilder();
			do
			{
				var name = ExpectIdentifier();
				Expect(":");
				var type = ParseType();
				if(isMainFunction && type == "System.Console")
					MainFunctionAcceptsConsole = true;
				arguments.AppendFormat("{1} {0}, ", name, ConvertType(type));
			} while(Accept(","));
			Expect(")");
			arguments.Length -= 2; // remove the trailing comma and space
			return arguments.ToString();
		}

		private void ParseDeclaration()
		{
			// Static Variable Declaration
			var kind = Token;
			if(Accept("var") || Accept("let"))
			{
				var variableName = ExpectIdentifier();
				Expect(":");
				var variableType = ParseType();
				Expect("=");
				variableType = ConvertType(variableType);
				if(kind == "let")
					variableType = "const " + variableType;
				BeginLine(variableType);
				Write(" {0} = ", variableName);
				ParseExpression();
				Expect(";");
				EndLine(";");
				AfterDeclaration = true;
				return;
			}

			// Function Declaration
			var name = ExpectIdentifier();
			var arguments = ParseArguments(name == "Main");
			Expect("->");
			var returnType = ParseType();
			WriteLine("{1} {0}({2})", name, ConvertType(returnType), arguments);
			if(name == "Main")
			{
				if(MainFunctionReturnType != null)
					throw new Exception("Multiple declarations of main");
				MainFunctionReturnType = returnType;
			}
			ParseBlock();
		}

		private void ParseProgram()
		{
			WriteLine("#include \"runtime.cpp\"");
			AfterDeclaration = true;

			do
			{
				ParseDeclaration();
			} while(TokenIsIdentifier());
			WriteLine("// Entry Point Adapter");
			WriteLine("int main(int argc, const char * argv[])");
			BeginBlock();

			var args = new StringBuilder();
			if(MainFunctionAcceptsConsole)
				args.AppendFormat("new ::System::Console()");

			if(MainFunctionReturnType == "void")
			{
				WriteLine("Main({0});", args);
				WriteLine("return 0;");
			}
			else
				WriteLine("return Main({0});", args);
			EndBlock();
		}

		private string ConvertType(string type, bool nameOnly = false)
		{
			switch(type)
			{
				case "string":
				case "int":
				case "bool":
				case "void":
					return type;
				case "code_point":
					return "char";
				default:

					return "::" + type.Replace(".", "::") + (nameOnly ? "" : "*");
			}
		}
		#endregion

		public string Transpile(string source)
		{
			Source = source;
			ReadFirstToken();
			ParseProgram();
			return Output.ToString();
		}
	}
}