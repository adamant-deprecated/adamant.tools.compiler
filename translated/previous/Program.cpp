#include "runtime.h"

// Declarations
class SourceText;
class Lexer;
class TokenType;
class SyntaxToken;
class Parser;
class SyntaxNode;
auto Parse(::SourceText const *const source) -> ::SyntaxNode const *;
auto EmitCpp(::SyntaxNode const *const syntaxTree) -> void;
auto Error(::string const message) -> void;
auto BeginLine(::string const value) -> void;
auto Write(::string const value) -> void;
auto EndLine(::string const value) -> void;
auto WriteLine(::string const value) -> void;
auto BeginBlock() -> void;
auto EndBlock() -> void;
auto IsIdentifierChar(char const c) -> bool;
auto IsNumberChar(char const c) -> bool;
auto ReadToken() -> void;
auto ReadFirstToken() -> void;
auto TokenIsIdentifier() -> bool;
auto Accept(::string const expected) -> bool;
auto Expect(::string const expected) -> void;
auto AcceptIdentifier() -> bool;
auto AcceptString() -> bool;
auto AcceptCodePoint() -> bool;
auto AcceptNumber() -> bool;
auto ExpectIdentifier() -> ::string;
auto IsValueType(::string const type) -> bool;
auto ConvertType(::string const type) -> ::string;
auto ConvertType(bool const mutableBinding, bool const mutableValue, ::string type) -> ::string;
auto ParseType() -> ::string;
auto ParseAtom() -> bool;
auto ParseCallArguments() -> void;
auto ParseExpression(int const minPrecedence) -> void;
auto ParseExpression() -> void;
auto ParseStatement() -> bool;
auto ParseBlock() -> void;
auto ParseArgumentsDeclaration(bool const isMainFunction) -> ::string;
auto ParseClassMember(::string const className) -> void;
auto ParseDeclaration() -> void;
auto ParseProgram() -> void;
auto Transpile(::SourceText const *const source) -> ::string;
auto Main(::System::Console::Console *const console, ::System::Console::Arguments const *const args) -> void;
auto ReadSource(::string const path) -> ::SourceText const *;

// Class Declarations
class SourceText
{
public:
	::string Package;
	::string Name;
	::string Text;
	SourceText(::string const package, ::string const name, ::string const text);
};
class Lexer
{
public:
	::SourceText const * Source;
	unsigned int position;
	Lexer(::SourceText const *const source);
	auto NextToken() -> ::SyntaxToken const *;
	auto NewToken(::TokenType const *const type, unsigned int const end) -> ::SyntaxToken const *;
	auto NewToken(::TokenType const *const type) -> ::SyntaxToken const *;
};
class TokenType
{
public:
};
class SyntaxToken
{
public:
	::TokenType const * TokenType;
	::SourceText const * Source;
	unsigned int Start;
	unsigned int Length;
	SyntaxToken(::TokenType const *const tokenType, ::SourceText const *const source, unsigned int const start, unsigned int const length);
};
class Parser
{
public:
	::Lexer const * Lexer;
	Parser(::Lexer const *const lexer);
	auto Parse() -> ::SyntaxNode const *;
};
class SyntaxNode
{
public:
};

// Definitions
::SourceText::SourceText(::string const package, ::string const name, ::string const text)
{
	this->Package = package;
	this->Name = name;
	this->Text = text;
}

::Lexer::Lexer(::SourceText const *const source)
{
	this->Source = source;
}

auto ::Lexer::NextToken() -> ::SyntaxToken const *
{
	return ::None;
}

auto ::Lexer::NewToken(::TokenType const *const type, unsigned int const end) -> ::SyntaxToken const *
{
	unsigned int const start = position;
	position = end;
	return new ::SyntaxToken(type, Source, start, end);
}

auto ::Lexer::NewToken(::TokenType const *const type) -> ::SyntaxToken const *
{
	return NewToken(type, position + 1);
}

::SyntaxToken::SyntaxToken(::TokenType const *const tokenType, ::SourceText const *const source, unsigned int const start, unsigned int const length)
{
	TokenType = tokenType;
	Source = source;
	Start = start;
	Length = length;
}

::Parser::Parser(::Lexer const *const lexer)
{
	this->Lexer = lexer;
}

auto ::Parser::Parse() -> ::SyntaxNode const *
{
}

auto Parse(::SourceText const *const source) -> ::SyntaxNode const *
{
	::Lexer *const lexer = new ::Lexer(source);
	::Parser *const parser = new ::Parser(lexer);
	return parser->Parse();
}

auto EmitCpp(::SyntaxNode const *const syntaxTree) -> void
{
}

::SourceText const * Source = ::None;

::string Token = ::string("");

int NextTokenPosition = 0;

::System::Text::StringBuilder *const Declarations = new ::System::Text::StringBuilder();

::System::Text::StringBuilder *const ClassDeclarations = new ::System::Text::StringBuilder();

::System::Text::StringBuilder *const Definitions = new ::System::Text::StringBuilder();

int IndentDepth = 0;

bool AfterDeclaration = false;

::string MainFunctionReturnType = ::string("");

bool MainFunctionAcceptsConsole = false;

bool MainFunctionAcceptsArgs = false;

auto Error(::string const message) -> void
{
	Definitions->Append(::string("<$ ") + message + ::string(" $>"));
}

auto BeginLine(::string const value) -> void
{
	if (AfterDeclaration)
	{
		Definitions->AppendLine();
		AfterDeclaration = false;
	}

	Definitions->Append(::string('\t', IndentDepth));
	Definitions->Append(value);
}

auto Write(::string const value) -> void
{
	Definitions->Append(value);
}

auto EndLine(::string const value) -> void
{
	Definitions->Append(value);
	Definitions->AppendLine();
}

auto WriteLine(::string const value) -> void
{
	if (AfterDeclaration)
	{
		Definitions->AppendLine();
		AfterDeclaration = false;
	}

	Definitions->Append(::string('\t', IndentDepth));
	Definitions->Append(value);
	Definitions->AppendLine();
}

auto BeginBlock() -> void
{
	WriteLine(::string("{"));
	IndentDepth += 1;
}

auto EndBlock() -> void
{
	AfterDeclaration = false;
	IndentDepth -= 1;
	WriteLine(::string("}"));
	AfterDeclaration = true;
}

auto IsIdentifierChar(char const c) -> bool
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

auto IsNumberChar(char const c) -> bool
{
	return c >= '0' && c <= '9';
}

auto ReadToken() -> void
{
	int position = NextTokenPosition;
	int tokenEnd = -1;
	bool escaped;
	bool done = false;
	while (!done && position < Source->Text->Length)
	{
		char const curChar = Source->Text[position];
		if (curChar == ' ' || curChar == '\t' || curChar == '\n' || curChar == '\r')
		{
			position += 1;
			continue;
		}
		else if (curChar == '{' || curChar == '}' || curChar == '(' || curChar == ')' || curChar == ';' || curChar == ',' || curChar == '.' || curChar == ':' || curChar == '[' || curChar == ']' || curChar == '?')
		{
			tokenEnd = position + 1;
			break;
		}
		else if (curChar == '=')
		{
			if (position + 1 < Source->Text->Length && Source->Text[position + 1] == '=')
			{
				tokenEnd = position + 2;
				break;
			}

			tokenEnd = position + 1;
			break;
		}
		else if (curChar == '+')
		{
			if (position + 1 < Source->Text->Length && Source->Text[position + 1] == '=')
			{
				tokenEnd = position + 2;
				break;
			}

			tokenEnd = position + 1;
			break;
		}
		else if (curChar == '-')
		{
			if (position + 1 < Source->Text->Length && Source->Text[position + 1] == '>')
			{
				tokenEnd = position + 2;
				break;
			}

			if (position + 1 < Source->Text->Length && Source->Text[position + 1] == '=')
			{
				tokenEnd = position + 2;
				break;
			}

			tokenEnd = position + 1;
			break;
		}
		else if (curChar == '/')
		{
			if (position + 1 < Source->Text->Length && Source->Text[position + 1] == '/')
			{
				while (position < Source->Text->Length && Source->Text[position] != '\r' && Source->Text[position] != '\n')
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
			if (position + 1 < Source->Text->Length && Source->Text[position + 1] == '>')
			{
				tokenEnd = position + 2;
				break;
			}

			if (position + 1 < Source->Text->Length && Source->Text[position + 1] == '=')
			{
				tokenEnd = position + 2;
				break;
			}

			tokenEnd = position + 1;
			break;
		}
		else if (curChar == '>')
		{
			if (position + 1 < Source->Text->Length && Source->Text[position + 1] == '=')
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
			while (tokenEnd < Source->Text->Length && (Source->Text[tokenEnd] != '"' || escaped))
			{
				escaped = Source->Text[tokenEnd] == '\\' && !escaped;
				tokenEnd += 1;
			}

			tokenEnd += 1;
			break;
		}
		else if (curChar == '\'')
		{
			tokenEnd = position + 1;
			escaped = false;
			while (tokenEnd < Source->Text->Length && (Source->Text[tokenEnd] != '\'' || escaped))
			{
				escaped = Source->Text[tokenEnd] == '\\' && !escaped;
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
				while (IsIdentifierChar(Source->Text[tokenEnd]))
				{
					tokenEnd += 1;
				}

				break;
			}

			if ((IsNumberChar(curChar)))
			{
				tokenEnd = position + 1;
				while (IsNumberChar(Source->Text[tokenEnd]))
				{
					tokenEnd += 1;
				}

				break;
			}

			Error(::string("Lexer: Invalid character `") + curChar + ::string("`"));
			position += 1;
		}
	}

	if (tokenEnd == -1)
	{
		Token = ::string("");
		NextTokenPosition = position;
	}
	else
	{
		Token = Source->Text->Substring(position, tokenEnd - position);
		NextTokenPosition = tokenEnd;
	}
}

auto ReadFirstToken() -> void
{
	if (NextTokenPosition != 0)
	{
		Error(::string("Can't read first token of context that already has tokens read."));
	}

	ReadToken();
}

auto TokenIsIdentifier() -> bool
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

auto Accept(::string const expected) -> bool
{
	bool const accepted = Token == expected;
	if (accepted)
	{
		ReadToken();
	}

	return accepted;
}

auto Expect(::string const expected) -> void
{
	if (Token != expected)
	{
		Error(::string("Expected `") + expected + ::string("` but found `") + Token + ::string("`"));
		ReadToken();
	}
	else
	{
		ReadToken();
	}
}

auto AcceptIdentifier() -> bool
{
	if (!TokenIsIdentifier())
	{
		return false;
	}

	ReadToken();
	return true;
}

auto AcceptString() -> bool
{
	if (Token->Length == 0 || Token[0] != '"')
	{
		return false;
	}

	ReadToken();
	return true;
}

auto AcceptCodePoint() -> bool
{
	if (Token->Length == 0 || Token[0] != '\'')
	{
		return false;
	}

	ReadToken();
	return true;
}

auto AcceptNumber() -> bool
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

auto ExpectIdentifier() -> ::string
{
	if (!TokenIsIdentifier())
	{
		Error(::string("Expected identifier, found `") + Token + ::string("`"));
		ReadToken();
		return ::string("<missing>");
	}

	::string const identifier = Token;
	ReadToken();
	return identifier;
}

auto IsValueType(::string const type) -> bool
{
	char const firstChar = type[0];
	return firstChar >= 'a' && firstChar <= 'z';
}

auto ConvertType(::string const type) -> ::string
{
	if (type == ::string("code_point"))
	{
		return ::string("char");
	}

	if (type == ::string("uint"))
	{
		return ::string("unsigned int");
	}

	if (type == ::string("int") || type == ::string("bool") || type == ::string("void"))
	{
		return type;
	}

	return ::string("::") + type->Replace(::string("."), ::string("::"));
}

auto ConvertType(bool const mutableBinding, bool const mutableValue, ::string type) -> ::string
{
	bool const nullable = type[type->Length - 1] == '?';
	if (nullable)
	{
		type = type->Substring(0, type->Length - 1);
	}

	bool const isValueType = IsValueType(type);
	type = ConvertType(type);
	if (isValueType)
	{
		if (nullable)
		{
			type = ::string("::Maybe<") + type + ::string(">");
		}

		if (!mutableBinding && !mutableValue)
		{
			type = type + ::string(" const");
		}
	}
	else
	{
		if (!mutableValue)
		{
			type = type + ::string(" const");
		}

		type = type + ::string(" *");
		if (!mutableBinding)
		{
			type = type + ::string("const");
		}
	}

	return type;
}

auto ParseType() -> ::string
{
	::System::Text::StringBuilder *const type = new ::System::Text::StringBuilder(ExpectIdentifier());
	while (Accept(::string(".")))
	{
		type->Append(::string("."));
		type->Append(ExpectIdentifier());
	}

	if (Accept(::string("?")))
	{
		type->Append(::string("?"));
	}

	return type->ToString();
}

auto ParseAtom() -> bool
{
	if (Accept(::string("new")))
	{
		::string type = ParseType();
		if (!IsValueType(type))
		{
			Write(::string("new "));
		}

		type = ConvertType(type);
		Write(type);
		Expect(::string("("));
		Write(::string("("));
		ParseCallArguments();
		Expect(::string(")"));
		Write(::string(")"));
		return true;
	}

	if (Accept(::string("not")))
	{
		Write(::string("!"));
		ParseExpression();
		return true;
	}

	if (Accept(::string("(")))
	{
		Write(::string("("));
		ParseExpression();
		Expect(::string(")"));
		Write(::string(")"));
		return true;
	}

	if (Accept(::string("-")))
	{
		Write(::string("-"));
		ParseExpression(7);
		return true;
	}

	if (Accept(::string("null")))
	{
		Write(::string("::None"));
		return true;
	}

	::string const token = Token;
	if (AcceptIdentifier() || AcceptNumber())
	{
		Write(token);
		return true;
	}

	if (AcceptString())
	{
		Write(::string("::string(") + token + ::string(")"));
		return true;
	}

	if (AcceptCodePoint())
	{
		Write(token);
		return true;
	}

	return false;
}

auto ParseCallArguments() -> void
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
			Write(::string(", "));
		}

		ParseExpression();
	}
	while (Accept(::string(",")));
}

auto ParseExpression(int const minPrecedence) -> void
{
	if (!ParseAtom())
	{
		return;
	}

	for (;;)
	{
		::string const token = Token;
		int precedence;
		bool leftAssociative;
		bool suffixOperator = false;
		if ((token == ::string("=") || token == ::string("+=") || token == ::string("-=")) && minPrecedence <= 1)
		{
			precedence = 1;
			leftAssociative = false;
			Write(::string(" ") + token + ::string(" "));
		}
		else if (token == ::string("or") && minPrecedence <= 2)
		{
			precedence = 2;
			leftAssociative = true;
			Write(::string(" || "));
		}
		else if (token == ::string("and") && minPrecedence <= 3)
		{
			precedence = 3;
			leftAssociative = true;
			Write(::string(" && "));
		}
		else if (token == ::string("==") && minPrecedence <= 4)
		{
			precedence = 4;
			leftAssociative = true;
			Write(::string(" == "));
		}
		else if (token == ::string("<>") && minPrecedence <= 4)
		{
			precedence = 4;
			leftAssociative = true;
			Write(::string(" != "));
		}
		else if ((token == ::string("<") || token == ::string("<=") || token == ::string(">") || token == ::string(">=")) && minPrecedence <= 5)
		{
			precedence = 5;
			leftAssociative = true;
			Write(::string(" ") + token + ::string(" "));
		}
		else if ((token == ::string("+") || token == ::string("-")) && minPrecedence <= 6)
		{
			precedence = 6;
			leftAssociative = true;
			Write(::string(" ") + token + ::string(" "));
		}
		else if (token == ::string("(") && minPrecedence <= 8)
		{
			ReadToken();
			Write(::string("("));
			ParseCallArguments();
			if (Token != ::string(")"))
			{
				Error(::string("Expected `)` found `") + Token + ::string("`"));
			}

			Write(::string(")"));
			precedence = 8;
			leftAssociative = true;
			suffixOperator = true;
		}
		else if (token == ::string(".") && minPrecedence <= 8)
		{
			precedence = 8;
			leftAssociative = true;
			Write(::string("->"));
		}
		else if (token == ::string("[") && minPrecedence <= 8)
		{
			ReadToken();
			Write(::string("["));
			ParseExpression();
			if (Token != ::string("]"))
			{
				Error(::string("Expected `]` found `") + Token + ::string("`"));
			}

			Write(::string("]"));
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

auto ParseExpression() -> void
{
	ParseExpression(1);
}

auto ParseStatement() -> bool
{
	if (Accept(::string("return")))
	{
		if (Accept(::string(";")))
		{
			WriteLine(::string("return;"));
		}
		else
		{
			BeginLine(::string("return "));
			ParseExpression();
			Expect(::string(";"));
			EndLine(::string(";"));
		}

		return true;
	}

	if (Accept(::string("loop")))
	{
		WriteLine(::string("for (;;)"));
		ParseBlock();
		return true;
	}

	if (Accept(::string("while")))
	{
		BeginLine(::string("while ("));
		ParseExpression();
		EndLine(::string(")"));
		ParseBlock();
		return true;
	}

	if (Accept(::string("for")))
	{
		BeginLine(::string("for ("));
		::string const k = Token;
		if (!Accept(::string("let")) && !Accept(::string("var")))
		{
			Error(::string("Expected `let` or `var` but found `") + Token + ::string("`"));
		}

		::string const name = ExpectIdentifier();
		Expect(::string(":"));
		bool const mutableValue = Accept(::string("mut"));
		::string const type = ParseType();
		Write(ConvertType(k == ::string("var"), mutableValue, type) + ::string(" ") + name);
		Expect(::string("in"));
		Write(::string(" : *("));
		ParseExpression();
		EndLine(::string("))"));
		ParseBlock();
		return true;
	}

	if (Accept(::string("do")))
	{
		WriteLine(::string("do"));
		ParseBlock();
		AfterDeclaration = false;
		Expect(::string("while"));
		BeginLine(::string("while ("));
		ParseExpression();
		Expect(::string(";"));
		EndLine(::string(");"));
		return true;
	}

	if (Accept(::string("if")))
	{
		BeginLine(::string("if ("));
		ParseExpression();
		EndLine(::string(")"));
		ParseBlock();
		while (Accept(::string("else")))
		{
			AfterDeclaration = false;
			if (Accept(::string("if")))
			{
				BeginLine(::string("else if ("));
				ParseExpression();
				EndLine(::string(")"));
				ParseBlock();
			}
			else
			{
				WriteLine(::string("else"));
				ParseBlock();
				return true;
			}
		}

		return true;
	}

	::string const kind = Token;
	if (Accept(::string("let")) || Accept(::string("var")))
	{
		::string const variableName = ExpectIdentifier();
		Expect(::string(":"));
		bool const mutableValue = Accept(::string("mut"));
		::string variableType = ParseType();
		variableType = ConvertType(kind == ::string("var"), mutableValue, variableType);
		BeginLine(variableType);
		Write(::string(" ") + variableName);
		if (Accept(::string("=")))
		{
			Write(::string(" = "));
			ParseExpression();
		}

		Expect(::string(";"));
		EndLine(::string(";"));
		return true;
	}

	if (Token == ::string("}"))
	{
		return false;
	}

	BeginLine(::string(""));
	ParseExpression();
	Expect(::string(";"));
	EndLine(::string(";"));
	return true;
}

auto ParseBlock() -> void
{
	Expect(::string("{"));
	BeginBlock();
	while (ParseStatement())
	{
	}

	Expect(::string("}"));
	EndBlock();
}

auto ParseArgumentsDeclaration(bool const isMainFunction) -> ::string
{
	Expect(::string("("));
	if (Accept(::string(")")))
	{
		return ::string("");
	}

	::System::Text::StringBuilder *const arguments = new ::System::Text::StringBuilder();
	do
	{
		bool const mutableBinding = Accept(::string("var"));
		::string const name = ExpectIdentifier();
		Expect(::string(":"));
		bool const mutableValue = Accept(::string("mut"));
		::string const type = ParseType();
		if (isMainFunction)
		{
			if (type == ::string("System.Console.Console"))
			{
				MainFunctionAcceptsConsole = true;
			}

			if (type == ::string("System.Console.Arguments"))
			{
				MainFunctionAcceptsArgs = true;
			}
		}

		arguments->Append(ConvertType(mutableBinding, mutableValue, type) + ::string(" ") + name + ::string(", "));
	}
	while (Accept(::string(",")));
	Expect(::string(")"));
	::string const result = arguments->ToString();
	return result->Substring(0, result->Length - 2);
}

auto ParseClassMember(::string const className) -> void
{
	::string const accessModifier = Token;
	if (Accept(::string("public")) || Accept(::string("internal")) || Accept(::string("protected")) || Accept(::string("private")))
	{
	}
	else
	{
		Error(::string("Expected access modifier, found `") + accessModifier + ::string("`"));
	}

	if (Accept(::string("new")))
	{
		::string const arguments = ParseArgumentsDeclaration(false);
		ClassDeclarations->AppendLine(::string("\t") + className + ::string("(") + arguments + ::string(");"));
		WriteLine(::string("::") + className + ::string("::") + className + ::string("(") + arguments + ::string(")"));
		ParseBlock();
		return;
	}

	::string const kind = Token;
	if (Accept(::string("var")) || Accept(::string("let")))
	{
		::string const fieldName = ExpectIdentifier();
		Expect(::string(":"));
		bool const mutableValue = Accept(::string("mut"));
		::string fieldType = ParseType();
		fieldType = ConvertType(true, mutableValue, fieldType);
		Expect(::string(";"));
		ClassDeclarations->AppendLine(::string("\t") + fieldType + ::string(" ") + fieldName + ::string(";"));
		return;
	}

	::string const methodName = ExpectIdentifier();
	::string const arguments = ParseArgumentsDeclaration(false);
	Expect(::string("->"));
	bool const mutableValue = Accept(::string("mut"));
	::string const returnType = ParseType();
	::string const convertedReturnType = ConvertType(true, mutableValue, returnType);
	ClassDeclarations->AppendLine(::string("\tauto ") + methodName + ::string("(") + arguments + ::string(") -> ") + convertedReturnType + ::string(";"));
	WriteLine(::string("auto ::") + className + ::string("::") + methodName + ::string("(") + arguments + ::string(") -> ") + convertedReturnType);
	ParseBlock();
}

auto ParseDeclaration() -> void
{
	::string const accessModifier = Token;
	if (Accept(::string("public")) || Accept(::string("internal")))
	{
	}
	else
	{
		Error(::string("Expected access modifier, found `") + accessModifier + ::string("`"));
	}

	::string const kind = Token;
	if (Accept(::string("var")) || Accept(::string("let")))
	{
		::string const variableName = ExpectIdentifier();
		Expect(::string(":"));
		bool const mutableValue = Accept(::string("mut"));
		::string variableType = ParseType();
		Expect(::string("="));
		variableType = ConvertType(kind == ::string("var"), mutableValue, variableType);
		BeginLine(variableType);
		Write(::string(" ") + variableName + ::string(" = "));
		ParseExpression();
		Expect(::string(";"));
		EndLine(::string(";"));
		AfterDeclaration = true;
		return;
	}

	if (Accept(::string("class")))
	{
		::string const className = ExpectIdentifier();
		Declarations->AppendLine(::string("class ") + className + ::string(";"));
		ClassDeclarations->AppendLine(::string("class ") + className);
		Expect(::string("{"));
		ClassDeclarations->AppendLine(::string("{"));
		ClassDeclarations->AppendLine(::string("public:"));
		while (!Accept(::string("}")))
		{
			ParseClassMember(className);
		}

		ClassDeclarations->AppendLine(::string("};"));
		return;
	}

	if (Accept(::string("enum")))
	{
		Expect(::string("struct"));
		::string const enumName = ExpectIdentifier();
		Declarations->AppendLine(::string("enum ") + enumName + ::string(";"));
		ClassDeclarations->AppendLine(::string("enum ") + enumName);
		Expect(::string("{"));
		ClassDeclarations->AppendLine(::string("{"));
		do
		{
			::string const enumValue = ExpectIdentifier();
			ClassDeclarations->Append(::string("\t") + enumValue);
			if (Accept(::string("=")))
			{
				ClassDeclarations->Append(::string(" = "));
				::string const value = Token;
				if (AcceptNumber())
				{
					ClassDeclarations->Append(value);
				}
				else
				{
					Error(::string("Expected number found `") + value + ::string("`"));
				}
			}

			ClassDeclarations->AppendLine(::string(","));
		}
		while (Accept(::string(",")));
		Expect(::string("}"));
		ClassDeclarations->AppendLine(::string("};"));
		return;
	}

	::string const name = ExpectIdentifier();
	::string const arguments = ParseArgumentsDeclaration(name == ::string("Main"));
	Expect(::string("->"));
	bool const mutableValue = Accept(::string("mut"));
	::string const returnType = ParseType();
	::string const convertedReturnType = ConvertType(true, mutableValue, returnType);
	Declarations->AppendLine(::string("auto ") + name + ::string("(") + arguments + ::string(") -> ") + convertedReturnType + ::string(";"));
	WriteLine(::string("auto ") + name + ::string("(") + arguments + ::string(") -> ") + convertedReturnType);
	if (name == ::string("Main"))
	{
		if (MainFunctionReturnType != ::string(""))
		{
			Error(::string("Multiple declarations of main"));
		}

		MainFunctionReturnType = returnType;
	}

	ParseBlock();
}

auto ParseProgram() -> void
{
	Declarations->AppendLine(::string("#include \"runtime.h\""));
	Declarations->AppendLine(::string(""));
	Declarations->AppendLine(::string("// Declarations"));
	ClassDeclarations->AppendLine(::string(""));
	ClassDeclarations->AppendLine(::string("// Class Declarations"));
	WriteLine(::string(""));
	WriteLine(::string("// Definitions"));
	do
	{
		ParseDeclaration();
	}
	while (TokenIsIdentifier());
	WriteLine(::string("// Entry Point Adapter"));
	WriteLine(::string("int main(int argc, char const *const * argv)"));
	BeginBlock();
	::System::Text::StringBuilder *const args = new ::System::Text::StringBuilder();
	if (MainFunctionAcceptsConsole)
	{
		args->Append(::string("new ::System::Console::Console()"));
	}

	if (MainFunctionAcceptsArgs)
	{
		if (MainFunctionAcceptsConsole)
		{
			args->Append(::string(", "));
		}

		args->Append(::string("new ::System::Console::Arguments(argc, argv)"));
	}

	if (MainFunctionReturnType == ::string("void"))
	{
		WriteLine(::string("Main(") + args->ToString() + ::string(");"));
		WriteLine(::string("return 0;"));
	}
	else
	{
		WriteLine(::string("return Main(") + args->ToString() + ::string(");"));
	}

	EndBlock();
}

auto Transpile(::SourceText const *const source) -> ::string
{
	Source = source;
	ReadFirstToken();
	ParseProgram();
	return Declarations->ToString() + ClassDeclarations->ToString() + Definitions->ToString();
}

auto Main(::System::Console::Console *const console, ::System::Console::Arguments const *const args) -> void
{
	console->WriteLine(::string("Adamant Compiler v0.1.0"));
	if (args->Count != 2)
	{
		console->WriteLine(::string("Args: <Input File> <OutputFile>"));
		return;
	}

	::string const inputFilePath = args->Get(0);
	console->Write(::string("Compiling: "));
	console->WriteLine(inputFilePath);
	::SourceText const *const source = ReadSource(inputFilePath);
	::string const translated = Transpile(source);
	::string const outputFilePath = args->Get(1);
	console->Write(::string("Output: "));
	console->WriteLine(outputFilePath);
	::System::IO::FileWriter *const outputFile = new ::System::IO::FileWriter(outputFilePath);
	outputFile->Write(translated);
	outputFile->Close();
}

auto ReadSource(::string const path) -> ::SourceText const *
{
	::System::IO::FileReader *const file = new ::System::IO::FileReader(path);
	::string const contents = file->ReadToEndSync();
	file->Close();
	return new ::SourceText(::string("<default>"), path, contents);
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main(new ::System::Console::Console(), new ::System::Console::Arguments(argc, argv));
	return 0;
}
