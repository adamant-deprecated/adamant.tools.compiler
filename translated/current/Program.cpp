#include "runtime.h"

// Declarations
void Error(string const message);
void BeginLine(string const value);
void Write(string const value);
void EndLine(string const value);
void WriteLine(string const value);
void BeginBlock();
void EndBlock();
bool IsIdentifierChar(char const c);
bool IsNumberChar(char const c);
void ReadToken();
void ReadFirstToken();
bool TokenIsIdentifier();
bool Accept(string const expected);
void Expect(string const expected);
bool AcceptIdentifier();
bool AcceptString();
bool AcceptCodePoint();
bool AcceptNumber();
string ExpectIdentifier();
bool IsValueType(string const type);
string ConvertType(string const type);
string ConvertType(bool const mutableBinding, bool const mutableValue, string type);
string ParseType();
bool ParseAtom();
void ParseCallArguments();
void ParseExpression(int const minPrecedence);
void ParseExpression();
bool ParseStatement();
void ParseBlock();
string ParseArgumentsDeclaration(bool const isMainFunction);
void ParseDeclaration();
void ParseProgram();
string Transpile(string const source);
void Main(::System::Console::Console *const console, ::System::Console::Arguments const *const args);

// Definitions
string Source = string("");

string Token = string("");

int NextTokenPosition = 0;

::System::Text::StringBuilder *const Declarations = new ::System::Text::StringBuilder();

::System::Text::StringBuilder *const ClassDeclarations = new ::System::Text::StringBuilder();

::System::Text::StringBuilder *const Definitions = new ::System::Text::StringBuilder();

int IndentDepth = 0;

bool AfterDeclaration = false;

string MainFunctionReturnType = string("");

bool MainFunctionAcceptsConsole = false;

bool MainFunctionAcceptsArgs = false;

void Error(string const message)
{
	Definitions->Append(string("<$ ") + message + string(" $>"));
}

void BeginLine(string const value)
{
	if (AfterDeclaration)
	{
		Definitions->AppendLine();
		AfterDeclaration = false;
	}

	Definitions->Append(string('\t', IndentDepth));
	Definitions->Append(value);
}

void Write(string const value)
{
	Definitions->Append(value);
}

void EndLine(string const value)
{
	Definitions->Append(value);
	Definitions->AppendLine();
}

void WriteLine(string const value)
{
	if (AfterDeclaration)
	{
		Definitions->AppendLine();
		AfterDeclaration = false;
	}

	Definitions->Append(string('\t', IndentDepth));
	Definitions->Append(value);
	Definitions->AppendLine();
}

void BeginBlock()
{
	WriteLine(string("{"));
	IndentDepth += 1;
}

void EndBlock()
{
	AfterDeclaration = false;
	IndentDepth -= 1;
	WriteLine(string("}"));
	AfterDeclaration = true;
}

bool IsIdentifierChar(char const c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool IsNumberChar(char const c)
{
	return c >= '0' && c <= '9';
}

void ReadToken()
{
	int position = NextTokenPosition;
	int tokenEnd = -1;
	bool escaped;
	bool done = false;
	while (!done && position < Source->Length)
	{
		char const curChar = Source[position];
		if (curChar == ' ' || curChar == '\t' || curChar == '\n' || curChar == '\r')
		{
			position += 1;
			continue;
		}
		else if (curChar == '{' || curChar == '}' || curChar == '(' || curChar == ')' || curChar == ';' || curChar == ',' || curChar == '.' || curChar == ':' || curChar == '[' || curChar == ']')
		{
			tokenEnd = position + 1;
			break;
		}
		else if (curChar == '=')
		{
			if (position + 1 < Source->Length && Source[position + 1] == '=')
			{
				tokenEnd = position + 2;
				break;
			}

			tokenEnd = position + 1;
			break;
		}
		else if (curChar == '+')
		{
			if (position + 1 < Source->Length && Source[position + 1] == '=')
			{
				tokenEnd = position + 2;
				break;
			}

			tokenEnd = position + 1;
			break;
		}
		else if (curChar == '-')
		{
			if (position + 1 < Source->Length && Source[position + 1] == '>')
			{
				tokenEnd = position + 2;
				break;
			}

			if (position + 1 < Source->Length && Source[position + 1] == '=')
			{
				tokenEnd = position + 2;
				break;
			}

			tokenEnd = position + 1;
			break;
		}
		else if (curChar == '/')
		{
			if (position + 1 < Source->Length && Source[position + 1] == '/')
			{
				while (position < Source->Length && Source[position] != '\r' && Source[position] != '\n')
				{
					position += 1;
				}

				continue;
			}

			tokenEnd = position + 1;
			break;
		}
		else if (curChar == '<')
		{
			if (position + 1 < Source->Length && Source[position + 1] == '>')
			{
				tokenEnd = position + 2;
				break;
			}

			if (position + 1 < Source->Length && Source[position + 1] == '=')
			{
				tokenEnd = position + 2;
				break;
			}

			tokenEnd = position + 1;
			break;
		}
		else if (curChar == '>')
		{
			if (position + 1 < Source->Length && Source[position + 1] == '=')
			{
				tokenEnd = position + 2;
				break;
			}

			tokenEnd = position + 1;
			break;
		}
		else if (curChar == '"')
		{
			tokenEnd = position + 1;
			escaped = false;
			while (tokenEnd < Source->Length && (Source[tokenEnd] != '"' || escaped))
			{
				escaped = Source[tokenEnd] == '\\' && !escaped;
				tokenEnd += 1;
			}

			tokenEnd += 1;
			break;
		}
		else if (curChar == '\'')
		{
			tokenEnd = position + 1;
			escaped = false;
			while (tokenEnd < Source->Length && (Source[tokenEnd] != '\'' || escaped))
			{
				escaped = Source[tokenEnd] == '\\' && !escaped;
				tokenEnd += 1;
			}

			tokenEnd += 1;
			break;
		}
		else
		{
			if (IsIdentifierChar(curChar))
			{
				tokenEnd = position + 1;
				while (IsIdentifierChar(Source[tokenEnd]))
				{
					tokenEnd += 1;
				}

				break;
			}

			if ((IsNumberChar(curChar)))
			{
				tokenEnd = position + 1;
				while (IsNumberChar(Source[tokenEnd]))
				{
					tokenEnd += 1;
				}

				break;
			}

			Error(string("Lexer: Invalid character `") + curChar + string("`"));
			position += 1;
		}
	}

	if (tokenEnd == -1)
	{
		Token = string("");
		NextTokenPosition = position;
	}
	else
	{
		Token = Source->Substring(position, tokenEnd - position);
		NextTokenPosition = tokenEnd;
	}
}

void ReadFirstToken()
{
	if (NextTokenPosition != 0)
	{
		Error(string("Can't read first token of context that already has tokens read."));
	}

	ReadToken();
}

bool TokenIsIdentifier()
{
	if (Token->Length == 0)
	{
		return false;
	}

	for (char const c : *(Token))
	{
		if (!IsIdentifierChar(c))
		{
			return false;
		}
	}

	return true;
}

bool Accept(string const expected)
{
	bool const accepted = Token == expected;
	if (accepted)
	{
		ReadToken();
	}

	return accepted;
}

void Expect(string const expected)
{
	if (Token != expected)
	{
		Error(string("Expected `") + expected + string("` but found `") + Token + string("`"));
		ReadToken();
	}
	else
	{
		ReadToken();
	}
}

bool AcceptIdentifier()
{
	if (!TokenIsIdentifier())
	{
		return false;
	}

	ReadToken();
	return true;
}

bool AcceptString()
{
	if (Token->Length == 0 || Token[0] != '"')
	{
		return false;
	}

	ReadToken();
	return true;
}

bool AcceptCodePoint()
{
	if (Token->Length == 0 || Token[0] != '\'')
	{
		return false;
	}

	ReadToken();
	return true;
}

bool AcceptNumber()
{
	for (char const c : *(Token))
	{
		if (!IsNumberChar(c))
		{
			return false;
		}
	}

	ReadToken();
	return true;
}

string ExpectIdentifier()
{
	if (!TokenIsIdentifier())
	{
		Error(string("Expected identifier, found `") + Token + string("`"));
		ReadToken();
		return string("<missing>");
	}

	string const identifier = Token;
	ReadToken();
	return identifier;
}

bool IsValueType(string const type)
{
	char const firstChar = type[0];
	return firstChar >= 'a' && firstChar <= 'z';
}

string ConvertType(string const type)
{
	if (type == string("code_point"))
	{
		return string("char");
	}

	if (IsValueType(type))
	{
		return type;
	}

	return string("::") + type->Replace(string("."), string("::"));
}

string ConvertType(bool const mutableBinding, bool const mutableValue, string type)
{
	bool const isValueType = IsValueType(type);
	type = ConvertType(type);
	if (isValueType)
	{
		if (!mutableBinding && !mutableValue)
		{
			type = type + string(" const");
		}
	}
	else
	{
		if (!mutableValue)
		{
			type = type + string(" const");
		}

		type = type + string(" *");
		if (!mutableBinding)
		{
			type = type + string("const");
		}
	}

	return type;
}

string ParseType()
{
	::System::Text::StringBuilder *const type = new ::System::Text::StringBuilder(ExpectIdentifier());
	while (Accept(string(".")))
	{
		type->Append(string("."));
		type->Append(ExpectIdentifier());
	}

	return type->ToString();
}

bool ParseAtom()
{
	if (Accept(string("new")))
	{
		string type = ParseType();
		if (!IsValueType(type))
		{
			Write(string("new "));
		}

		type = ConvertType(type);
		Write(type);
		Expect(string("("));
		Write(string("("));
		ParseCallArguments();
		Expect(string(")"));
		Write(string(")"));
		return true;
	}

	if (Accept(string("not")))
	{
		Write(string("!"));
		ParseExpression();
		return true;
	}

	if (Accept(string("(")))
	{
		Write(string("("));
		ParseExpression();
		Expect(string(")"));
		Write(string(")"));
		return true;
	}

	if (Accept(string("-")))
	{
		Write(string("-"));
		ParseExpression(7);
		return true;
	}

	string const token = Token;
	if (AcceptIdentifier() || AcceptNumber())
	{
		Write(token);
		return true;
	}

	if (AcceptString())
	{
		Write(string("string(") + token + string(")"));
		return true;
	}

	if (AcceptCodePoint())
	{
		Write(token);
		return true;
	}

	return false;
}

void ParseCallArguments()
{
	bool first = true;
	do
	{
		if (first)
		{
			first = false;
		}
		else
		{
			Write(string(", "));
		}

		ParseExpression();
	}
	while (Accept(string(",")));
}

void ParseExpression(int const minPrecedence)
{
	if (!ParseAtom())
	{
		return;
	}

	for (;;)
	{
		string const token = Token;
		int precedence;
		bool leftAssociative;
		bool suffixOperator = false;
		if ((token == string("=") || token == string("+=") || token == string("-=")) && minPrecedence <= 1)
		{
			precedence = 1;
			leftAssociative = false;
			Write(string(" ") + token + string(" "));
		}
		else if (token == string("or") && minPrecedence <= 2)
		{
			precedence = 2;
			leftAssociative = true;
			Write(string(" || "));
		}
		else if (token == string("and") && minPrecedence <= 3)
		{
			precedence = 3;
			leftAssociative = true;
			Write(string(" && "));
		}
		else if (token == string("==") && minPrecedence <= 4)
		{
			precedence = 4;
			leftAssociative = true;
			Write(string(" == "));
		}
		else if (token == string("<>") && minPrecedence <= 4)
		{
			precedence = 4;
			leftAssociative = true;
			Write(string(" != "));
		}
		else if ((token == string("<") || token == string("<=") || token == string(">") || token == string(">=")) && minPrecedence <= 5)
		{
			precedence = 5;
			leftAssociative = true;
			Write(string(" ") + token + string(" "));
		}
		else if ((token == string("+") || token == string("-")) && minPrecedence <= 6)
		{
			precedence = 6;
			leftAssociative = true;
			Write(string(" ") + token + string(" "));
		}
		else if (token == string("(") && minPrecedence <= 8)
		{
			ReadToken();
			Write(string("("));
			ParseCallArguments();
			if (Token != string(")"))
			{
				Error(string("Expected `)` found `") + Token + string("`"));
			}

			Write(string(")"));
			precedence = 8;
			leftAssociative = true;
			suffixOperator = true;
		}
		else if (token == string(".") && minPrecedence <= 8)
		{
			precedence = 8;
			leftAssociative = true;
			Write(string("->"));
		}
		else if (token == string("[") && minPrecedence <= 8)
		{
			ReadToken();
			Write(string("["));
			ParseExpression();
			if (Token != string("]"))
			{
				Error(string("Expected `]` found `") + Token + string("`"));
			}

			Write(string("]"));
			precedence = 8;
			leftAssociative = true;
			suffixOperator = true;
		}
		else
		{
			break;
		}

		ReadToken();
		if (!suffixOperator)
		{
			if (leftAssociative)
			{
				precedence += 1;
			}

			ParseExpression(precedence);
		}
	}
}

void ParseExpression()
{
	ParseExpression(1);
}

bool ParseStatement()
{
	if (Accept(string("return")))
	{
		if (Accept(string(";")))
		{
			WriteLine(string("return;"));
		}
		else
		{
			BeginLine(string("return "));
			ParseExpression();
			Expect(string(";"));
			EndLine(string(";"));
		}

		return true;
	}

	if (Accept(string("loop")))
	{
		WriteLine(string("for (;;)"));
		ParseBlock();
		return true;
	}

	if (Accept(string("while")))
	{
		BeginLine(string("while ("));
		ParseExpression();
		EndLine(string(")"));
		ParseBlock();
		return true;
	}

	if (Accept(string("for")))
	{
		BeginLine(string("for ("));
		string const k = Token;
		if (!Accept(string("let")) && !Accept(string("var")))
		{
			Error(string("Expected `let` or `var` but found `") + Token + string("`"));
		}

		string const name = ExpectIdentifier();
		Expect(string(":"));
		bool const mutableValue = Accept(string("mut"));
		string const type = ParseType();
		Write(ConvertType(k == string("var"), mutableValue, type) + string(" ") + name);
		Expect(string("in"));
		Write(string(" : *("));
		ParseExpression();
		EndLine(string("))"));
		ParseBlock();
		return true;
	}

	if (Accept(string("do")))
	{
		WriteLine(string("do"));
		ParseBlock();
		AfterDeclaration = false;
		Expect(string("while"));
		BeginLine(string("while ("));
		ParseExpression();
		Expect(string(";"));
		EndLine(string(");"));
		return true;
	}

	if (Accept(string("if")))
	{
		BeginLine(string("if ("));
		ParseExpression();
		EndLine(string(")"));
		ParseBlock();
		while (Accept(string("else")))
		{
			AfterDeclaration = false;
			if (Accept(string("if")))
			{
				BeginLine(string("else if ("));
				ParseExpression();
				EndLine(string(")"));
				ParseBlock();
			}
			else
			{
				WriteLine(string("else"));
				ParseBlock();
				return true;
			}
		}

		return true;
	}

	string const kind = Token;
	if (Accept(string("let")) || Accept(string("var")))
	{
		string const variableName = ExpectIdentifier();
		Expect(string(":"));
		bool const mutableValue = Accept(string("mut"));
		string variableType = ParseType();
		variableType = ConvertType(kind == string("var"), mutableValue, variableType);
		BeginLine(variableType);
		Write(string(" ") + variableName);
		if (Accept(string("=")))
		{
			Write(string(" = "));
			ParseExpression();
		}

		Expect(string(";"));
		EndLine(string(";"));
		return true;
	}

	if (Token == string("}"))
	{
		return false;
	}

	BeginLine(string(""));
	ParseExpression();
	Expect(string(";"));
	EndLine(string(";"));
	return true;
}

void ParseBlock()
{
	Expect(string("{"));
	BeginBlock();
	while (ParseStatement())
	{
	}

	Expect(string("}"));
	EndBlock();
}

string ParseArgumentsDeclaration(bool const isMainFunction)
{
	Expect(string("("));
	if (Accept(string(")")))
	{
		return string("");
	}

	::System::Text::StringBuilder *const arguments = new ::System::Text::StringBuilder();
	do
	{
		bool const mutableBinding = Accept(string("var"));
		string const name = ExpectIdentifier();
		Expect(string(":"));
		bool const mutableValue = Accept(string("mut"));
		string const type = ParseType();
		if (isMainFunction)
		{
			if (type == string("System.Console.Console"))
			{
				MainFunctionAcceptsConsole = true;
			}

			if (type == string("System.Console.Arguments"))
			{
				MainFunctionAcceptsArgs = true;
			}
		}

		arguments->Append(ConvertType(mutableBinding, mutableValue, type) + string(" ") + name + string(", "));
	}
	while (Accept(string(",")));
	Expect(string(")"));
	string const result = arguments->ToString();
	return result->Substring(0, result->Length - 2);
}

void ParseDeclaration()
{
	string const kind = Token;
	if (Accept(string("var")) || Accept(string("let")))
	{
		string const variableName = ExpectIdentifier();
		Expect(string(":"));
		bool const mutableValue = Accept(string("mut"));
		string variableType = ParseType();
		Expect(string("="));
		variableType = ConvertType(kind == string("var"), mutableValue, variableType);
		BeginLine(variableType);
		Write(string(" ") + variableName + string(" = "));
		ParseExpression();
		Expect(string(";"));
		EndLine(string(";"));
		AfterDeclaration = true;
		return;
	}

	if (Accept(string("class")))
	{
		string const className = ExpectIdentifier();
		Declarations->AppendLine(string("class ") + className + string(";"));
		ClassDeclarations->AppendLine(string("class ") + className);
		Expect(string("{"));
		ClassDeclarations->AppendLine(string("{"));
		Expect(string("}"));
		ClassDeclarations->AppendLine(string("};"));
		return;
	}

	string const name = ExpectIdentifier();
	string const arguments = ParseArgumentsDeclaration(name == string("Main"));
	Expect(string("->"));
	bool const mutableValue = Accept(string("mut"));
	string const returnType = ParseType();
	string const convertedReturnType = ConvertType(true, mutableValue, returnType);
	Declarations->AppendLine(convertedReturnType + string(" ") + name + string("(") + arguments + string(");"));
	WriteLine(convertedReturnType + string(" ") + name + string("(") + arguments + string(")"));
	if (name == string("Main"))
	{
		if (MainFunctionReturnType != string(""))
		{
			Error(string("Multiple declarations of main"));
		}

		MainFunctionReturnType = returnType;
	}

	ParseBlock();
}

void ParseProgram()
{
	Declarations->AppendLine(string("#include \"runtime.h\""));
	Declarations->AppendLine(string(""));
	Declarations->AppendLine(string("// Declarations"));
	ClassDeclarations->AppendLine(string(""));
	ClassDeclarations->AppendLine(string("// Class Declarations"));
	WriteLine(string(""));
	WriteLine(string("// Definitions"));
	do
	{
		ParseDeclaration();
	}
	while (TokenIsIdentifier());
	WriteLine(string("// Entry Point Adapter"));
	WriteLine(string("int main(int argc, char const *const * argv)"));
	BeginBlock();
	::System::Text::StringBuilder *const args = new ::System::Text::StringBuilder();
	if (MainFunctionAcceptsConsole)
	{
		args->Append(string("new ::System::Console::Console()"));
	}

	if (MainFunctionAcceptsArgs)
	{
		if (MainFunctionAcceptsConsole)
		{
			args->Append(string(", "));
		}

		args->Append(string("new ::System::Console::Arguments(argc, argv)"));
	}

	if (MainFunctionReturnType == string("void"))
	{
		WriteLine(string("Main(") + args->ToString() + string(");"));
		WriteLine(string("return 0;"));
	}
	else
	{
		WriteLine(string("return Main(") + args->ToString() + string(");"));
	}

	EndBlock();
}

string Transpile(string const source)
{
	Source = source;
	ReadFirstToken();
	ParseProgram();
	return Declarations->ToString() + ClassDeclarations->ToString() + Definitions->ToString();
}

void Main(::System::Console::Console *const console, ::System::Console::Arguments const *const args)
{
	console->WriteLine(string("Adamant Compiler v0.1.0"));
	if (args->Count != 2)
	{
		console->WriteLine(string("Args: <Input File> <OutputFile>"));
		return;
	}

	string const inputFilePath = args->Get(0);
	console->Write(string("Compiling: "));
	console->WriteLine(inputFilePath);
	::System::IO::FileReader *const inputFile = new ::System::IO::FileReader(inputFilePath);
	string const source = inputFile->ReadToEndSync();
	inputFile->Close();
	string const translated = Transpile(source);
	string const outputFilePath = args->Get(1);
	console->Write(string("Output: "));
	console->WriteLine(outputFilePath);
	::System::IO::FileWriter *const outputFile = new ::System::IO::FileWriter(outputFilePath);
	outputFile->Write(translated);
	outputFile->Close();
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main(new ::System::Console::Console(), new ::System::Console::Arguments(argc, argv));
	return 0;
}
