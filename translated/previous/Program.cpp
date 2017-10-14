#include "RuntimeLibrary.h"

// Type Declarations
class Lexer;
class Parser;
class SourceText;
class SyntaxNode;
class SyntaxToken;
class TokenStream;
class TokenType;

// Function Declarations
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
auto ParseCompilationUnit() -> void;
auto EmitPreamble() -> void;
auto EmitEntryPointAdapter(::System::Collections::List<::SourceText const *> const *const resources) -> void;
auto Transpile(::System::Collections::List<::SourceText const *> const *const sources, ::System::Collections::List<::SourceText const *> const *const resources) -> ::string;
auto Main(::System::Console::Console *const console, ::System::Console::Arguments const *const args) -> void;
auto ReadSource(::string const path) -> ::SourceText const *;

// Class Declarations
class Lexer
{
public:
	auto Analyze(::SourceText const *const source) -> ::TokenStream *;
};
class Parser
{
public:
	Parser();
	auto Parse(::TokenStream const *const tokenStream) -> ::SyntaxNode const *;
};
class SourceText
{
public:
	::string Package;
	::string Name;
	::string Text;
	SourceText(::string const package, ::string const name, ::string const text);
};
class SyntaxNode
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
class TokenStream
{
public:
	::SourceText const * Source;
	unsigned int nextToken;
	TokenStream(::SourceText const *const source);
	auto GetNextToken() -> ::string;
	auto NewToken(::TokenType const *const type, unsigned int const end) -> ::SyntaxToken const *;
	auto NewToken(::TokenType const *const type) -> ::SyntaxToken const *;
};
class TokenType
{
public:
};

// Definitions
auto ::Lexer::Analyze(::SourceText const *const source) -> ::TokenStream *
{
	return new ::TokenStream(source);
}

::Parser::Parser()
{
}

auto ::Parser::Parse(::TokenStream const *const tokenStream) -> ::SyntaxNode const *
{
	return ::None;
}

auto Parse(::SourceText const *const source) -> ::SyntaxNode const *
{
	::Lexer *const lexer = new ::Lexer();
	::TokenStream *const tokenStream = lexer->Analyze(source);
	::Parser *const parser = new ::Parser();
	return parser->Parse(tokenStream);
}

auto EmitCpp(::SyntaxNode const *const syntaxTree) -> void
{
}

::TokenStream * tokenStream = ::None;

::string Token = ::string("");

::System::Text::StringBuilder *const TypeDeclarations = new ::System::Text::StringBuilder();

::System::Text::StringBuilder *const FunctionDeclarations = new ::System::Text::StringBuilder();

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
		Token = tokenStream->GetNextToken();
	}

	return accepted;
}

auto Expect(::string const expected) -> void
{
	if (Token != expected)
	{
		Error(::string("Expected `") + expected + ::string("` but found `") + Token + ::string("`"));
		Token = tokenStream->GetNextToken();
	}
	else
	{
		Token = tokenStream->GetNextToken();
	}
}

auto AcceptIdentifier() -> bool
{
	if (!TokenIsIdentifier())
	{
		return false;
	}

	Token = tokenStream->GetNextToken();
	return true;
}

auto AcceptString() -> bool
{
	if (Token->Length == 0 || Token[0] != '"')
	{
		return false;
	}

	Token = tokenStream->GetNextToken();
	return true;
}

auto AcceptCodePoint() -> bool
{
	if (Token->Length == 0 || Token[0] != '\'')
	{
		return false;
	}

	Token = tokenStream->GetNextToken();
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

	Token = tokenStream->GetNextToken();
	return true;
}

auto ExpectIdentifier() -> ::string
{
	if (!TokenIsIdentifier())
	{
		Error(::string("Expected identifier, found `") + Token + ::string("`"));
		Token = tokenStream->GetNextToken();
		return ::string("<missing>");
	}

	::string const identifier = Token;
	Token = tokenStream->GetNextToken();
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

	if (Accept(::string("<")))
	{
		type->Append(::string("<"));
		bool const mutableValue = Accept(::string("mut"));
		type->Append(ConvertType(true, mutableValue, ParseType()));
		Accept(::string(">"));
		type->Append(::string(">"));
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
			Token = tokenStream->GetNextToken();
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
			Token = tokenStream->GetNextToken();
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

		Token = tokenStream->GetNextToken();
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
		TypeDeclarations->AppendLine(::string("class ") + className + ::string(";"));
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
		TypeDeclarations->AppendLine(::string("enum class ") + enumName + ::string(";"));
		ClassDeclarations->AppendLine(::string("enum class ") + enumName);
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
	FunctionDeclarations->AppendLine(::string("auto ") + name + ::string("(") + arguments + ::string(") -> ") + convertedReturnType + ::string(";"));
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

auto ParseCompilationUnit() -> void
{
	while (TokenIsIdentifier())
	{
		ParseDeclaration();
	}
}

auto EmitPreamble() -> void
{
	TypeDeclarations->AppendLine(::string("#include \"RuntimeLibrary.h\""));
	TypeDeclarations->AppendLine(::string(""));
	TypeDeclarations->AppendLine(::string("// Type Declarations"));
	FunctionDeclarations->AppendLine(::string(""));
	FunctionDeclarations->AppendLine(::string("// Function Declarations"));
	ClassDeclarations->AppendLine(::string(""));
	ClassDeclarations->AppendLine(::string("// Class Declarations"));
	WriteLine(::string(""));
	WriteLine(::string("// Definitions"));
}

auto EmitEntryPointAdapter(::System::Collections::List<::SourceText const *> const *const resources) -> void
{
	WriteLine(::string("// Entry Point Adapter"));
	WriteLine(::string("int main(int argc, char const *const * argv)"));
	BeginBlock();
	for (::SourceText const *const resource : *(resources))
	{
		BeginLine(::string("resource_manager->AddResource(::string(\""));
		Write(resource->Name);
		Write(::string("\"), ::string(\""));
		Write(resource->Text->Replace(::string("\\"), ::string("\\\\"))->Replace(::string("\n"), ::string("\\n"))->Replace(::string("\r"), ::string("\\r"))->Replace(::string("\""), ::string("\\\"")));
		EndLine(::string("\"));"));
	}

	if (resources->Length() > 0)
	{
		EndLine(::string(""));
	}

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

auto Transpile(::System::Collections::List<::SourceText const *> const *const sources, ::System::Collections::List<::SourceText const *> const *const resources) -> ::string
{
	EmitPreamble();
	::Lexer *const lexer = new ::Lexer();
	for (::SourceText const *const source : *(sources))
	{
		tokenStream = lexer->Analyze(source);
		Token = tokenStream->GetNextToken();
		ParseCompilationUnit();
	}

	EmitEntryPointAdapter(resources);
	return TypeDeclarations->ToString() + FunctionDeclarations->ToString() + ClassDeclarations->ToString() + Definitions->ToString();
}

auto Main(::System::Console::Console *const console, ::System::Console::Arguments const *const args) -> void
{
	console->WriteLine(::string("Adamant Compiler v0.1.0"));
	::System::Collections::List<::string> *const sourceFilePaths = new ::System::Collections::List<::string>();
	::System::Collections::List<::string> *const resourceFilePaths = new ::System::Collections::List<::string>();
	::string outputFilePath = ::string("");
	int argType = 0;
	for (::string const arg : *(args))
	{
		if (argType == 1)
		{
			resourceFilePaths->Add(arg);
			argType = 0;
		}
		else if (argType == 2)
		{
			outputFilePath = arg;
			argType = 0;
		}
		else
		{
			if (arg == ::string("-r"))
			{
				argType = 1;
			}
			else if (arg == ::string("-o"))
			{
				argType = 2;
			}
			else
			{
				sourceFilePaths->Add(arg);
			}
		}
	}

	if (sourceFilePaths->Length() == 0 || outputFilePath == ::string(""))
	{
		console->WriteLine(::string("Args: <Input File(s)> -o <OutputFile> -r <Resource File>"));
		return;
	}

	::System::Collections::List<::SourceText const *> *const resources = new ::System::Collections::List<::SourceText const *>();
	if (resourceFilePaths->Length() > 0)
	{
		console->WriteLine(::string("Reading Resources:"));
		for (::string const resourceFilePath : *(resourceFilePaths))
		{
			console->WriteLine(::string("  ") + resourceFilePath);
			resources->Add(ReadSource(resourceFilePath));
		}
	}

	console->WriteLine(::string("Compiling:"));
	::System::Collections::List<::SourceText const *> *const sources = new ::System::Collections::List<::SourceText const *>();
	for (::string const sourceFilePath : *(sourceFilePaths))
	{
		console->WriteLine(::string("  ") + sourceFilePath);
		sources->Add(ReadSource(sourceFilePath));
	}

	::string const translated = Transpile(sources, resources);
	console->Write(::string("Output: "));
	console->WriteLine(outputFilePath);
	::System::IO::FileWriter *const outputFile = new ::System::IO::FileWriter(outputFilePath);
	outputFile->Write(translated);
	outputFile->Close();
	console->Write(::string("Outputting RuntimeLibrary to: "));
	::string outputDirPath = outputFilePath;
	int index = outputDirPath->LastIndexOf('/');
	if (index != -1)
	{
		outputDirPath = outputDirPath->Substring(0, index + 1);
	}

	index = outputDirPath->LastIndexOf('\\');
	if (index != -1)
	{
		outputDirPath = outputDirPath->Substring(0, index + 1);
	}

	console->WriteLine(outputDirPath);
	::System::IO::FileWriter * resourceFile = new ::System::IO::FileWriter(outputDirPath + ::string("RuntimeLibrary.h"));
	resourceFile->Write(resource_manager->GetString(::string("RuntimeLibrary.h")));
	resourceFile->Close();
	resourceFile = new ::System::IO::FileWriter(outputDirPath + ::string("RuntimeLibrary.cpp"));
	resourceFile->Write(resource_manager->GetString(::string("RuntimeLibrary.cpp")));
	resourceFile->Close();
}

auto ReadSource(::string const path) -> ::SourceText const *
{
	::System::IO::FileReader *const file = new ::System::IO::FileReader(path);
	::string const contents = file->ReadToEndSync();
	file->Close();
	::string name = path;
	int index = name->LastIndexOf('/');
	if (index != -1)
	{
		name = name->Substring(index + 1);
	}

	index = name->LastIndexOf('\\');
	if (index != -1)
	{
		name = name->Substring(index + 1);
	}

	return new ::SourceText(::string("<default>"), name, contents);
}

::SourceText::SourceText(::string const package, ::string const name, ::string const text)
{
	this->Package = package;
	this->Name = name;
	this->Text = text;
}

::SyntaxToken::SyntaxToken(::TokenType const *const tokenType, ::SourceText const *const source, unsigned int const start, unsigned int const length)
{
	TokenType = tokenType;
	Source = source;
	Start = start;
	Length = length;
}

::TokenStream::TokenStream(::SourceText const *const source)
{
	Source = source;
	nextToken = 0;
}

auto ::TokenStream::GetNextToken() -> ::string
{
	unsigned int position = nextToken;
	unsigned int tokenEnd = -1;
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

	::string token;
	if (tokenEnd == -1)
	{
		token = ::string("");
		nextToken = position;
	}
	else
	{
		token = Source->Text->Substring(position, tokenEnd - position);
		nextToken = tokenEnd;
	}

	return token;
}

auto ::TokenStream::NewToken(::TokenType const *const type, unsigned int const end) -> ::SyntaxToken const *
{
	return ::None;
}

auto ::TokenStream::NewToken(::TokenType const *const type) -> ::SyntaxToken const *
{
	return ::None;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	resource_manager->AddResource(::string("RuntimeLibrary.cpp"), ::string("#include \"RuntimeLibrary.h\"\n#include <map>\n\nstring::string()\n	: Length(0), Buffer(0)\n{\n}\n\nstring::string(char c, int repeat)\n	: Length(repeat)\n{\n	char* buffer = new char[repeat];\n	for (int i = 0; i < repeat; i++)\n		buffer[i] = c;\n\n	Buffer = buffer;\n}\n\nstring::string(const char* s)\n	: Length(std::strlen(s)), Buffer(s)\n{\n}\n\nstring::string(int length, const char* s)\n	: Length(length), Buffer(s)\n{\n}\n\nchar const * string::cstr() const\n{\n	auto buffer = new char[Length + 1];\n	std::memcpy(buffer, Buffer, Length);\n	buffer[Length] = 0;\n	return buffer;\n}\n\nstring string::Substring(int start, int length) const\n{\n	return string(length, Buffer + start);\n}\n\nstring string::Replace(string oldValue, string newValue) const\n{\n	string buffer = \"\";\n	int limit = Length - oldValue.Length + 1;\n	int lastIndex = 0;\n	for(int i=0; i < limit; i++)\n		if (Substring(i, oldValue.Length) == oldValue)\n		{\n			buffer = buffer + Substring(lastIndex, i-lastIndex) + newValue;\n			i += oldValue.Length; // skip over the value we just matched\n			lastIndex = i;\n			i--; // we need i-- to offset the i++ that is about to happen\n		}\n\n	buffer = buffer + Substring(lastIndex, Length - lastIndex);\n	return buffer;\n}\n\nint string::LastIndexOf(char c) const\n{\n	for(int i=Length-1; i>=0; i--)\n		if(Buffer[i]==c)\n			return i;\n\n	return -1;\n}\n\nchar string::operator[] (const int index) const\n{\n	return Buffer[index];\n}\n\nstring string::operator+(const string& value) const\n{\n	int newLength = Length + value.Length;\n	char* chars = new char[newLength];\n	size_t offset = sizeof(char)*Length;\n	std::memcpy(chars, Buffer, offset);\n	std::memcpy(chars + offset, value.Buffer, value.Length);\n	return string(newLength, chars);\n}\n\nstring string::operator+(const char& value) const\n{\n	int newLength = Length + 1;\n	char* chars = new char[newLength];\n	size_t offset = sizeof(char)*Length;\n	std::memcpy(chars, Buffer, offset);\n	chars[Length] = value;\n	return string(newLength, chars);\n}\n\nbool string::operator==(const string &other) const\n{\n	if (Length != other.Length)\n		return false;\n\n	for (int i = 0; i < Length; i++)\n		if (Buffer[i] != other.Buffer[i])\n			return false;\n\n	return true;\n}\n\nbool operator < (string const& lhs, string const& rhs)\n{\n    return std::strcmp(lhs.cstr(), rhs.cstr()) < 0;\n}\n\nstd::map<string, string> resourceValues;\n\nstring const & ResourceManager::GetString(string resourceName)\n{\n	return resourceValues.at(resourceName);\n}\nvoid ResourceManager::AddResource(string name, string value)\n{\n	resourceValues.insert(std::make_pair(name, value));\n}\n\nResourceManager *const resource_manager = new ResourceManager();\n\nnamespace System\n{\n	namespace Console\n	{\n		void Console::Write(string value)\n		{\n			std::printf(\"%.*s\", value.Length, value.Buffer);\n		}\n\n		void Console::WriteLine(string value)\n		{\n			std::printf(\"%.*s\\n\", value.Length, value.Buffer);\n		}\n\n		void Console::WriteLine()\n		{\n			std::printf(\"\\n\");\n		}\n\n		Arguments::Arguments(int argc, char const *const * argv)\n			: Count(argc-1)\n		{\n			args = new string[Count];\n			for (int i = 0; i < Count; i++)\n				args[i] = string(argv[i+1]);\n		}\n	}\n\n	namespace IO\n	{\n		FileReader::FileReader(const string& fileName)\n		{\n			std::FILE* foo;\n			auto fname = fileName.cstr();\n			file = std::fopen(fname, \"rb\");\n			delete[] fname;\n		}\n\n		string FileReader::ReadToEndSync()\n		{\n			std::fseek(file, 0, SEEK_END);\n			auto length = std::ftell(file);\n			std::fseek(file, 0, SEEK_SET);\n			auto buffer = new char[length];\n			length = std::fread(buffer, sizeof(char), length, file);\n			return string(length, buffer);\n		}\n\n		void FileReader::Close()\n		{\n			std::fclose(file);\n		}\n\n		FileWriter::FileWriter(const string& fileName)\n		{\n			auto fname = fileName.cstr();\n			file = std::fopen(fname, \"wb\"); // TODO check error\n			delete[] fname;\n		}\n\n		void FileWriter::Write(const string& value)\n		{\n			std::fwrite(value.Buffer, sizeof(char), value.Length, file);\n		}\n\n		void FileWriter::Close()\n		{\n			std::fclose(file);\n		}\n	}\n\n	namespace Text\n	{\n		StringBuilder::StringBuilder(string const & value)\n			: buffer(value)\n		{\n		}\n\n		StringBuilder::StringBuilder()\n			: buffer(\"\")\n		{\n		}\n\n		void StringBuilder::Append(string const & value)\n		{\n			buffer = buffer + value;\n		}\n\n		void StringBuilder::AppendLine(string const & value)\n		{\n			buffer = buffer + value + string(\"\\n\");\n		}\n\n		void StringBuilder::AppendLine()\n		{\n			buffer = buffer + string(\"\\n\");\n		}\n	}\n}\n"));
	resource_manager->AddResource(::string("RuntimeLibrary.h"), ::string("// On windows this disables warnings about using fopen_s instead of fopen\r\n// It must be defined before including the headers.  The includes have been moved\r\n// here to avoid leaking this into the program being compiled.  This required the\r\n// use of void* instead of FILE* in some places.\r\n#define _CRT_SECURE_NO_WARNINGS\r\n#include <cstring>\r\n#include <cstdio>\r\n\r\nstruct string\r\n{\r\npublic:\r\n	int Length;\r\n	char const * Buffer;\r\n\r\n	string();\r\n	string(char c, int repeat);\r\n	string(char const * s);\r\n	string(int length, char const * s);\r\n	char const * cstr() const;\r\n	string Substring(int start, int length) const;\r\n	string Substring(int start) const { return Substring(start, Length-start); }\r\n	string Replace(string oldValue, string newValue) const;\r\n	int LastIndexOf(char c) const;\r\n	char operator[] (int const index) const;\r\n	string operator+(string const & value) const;\r\n	string operator+(char const & value) const;\r\n	string const * operator->() const { return this; }\r\n	string const & operator* () const { return *this; }\r\n	bool operator==(string const & other) const;\r\n	bool operator!=(string const & other) const { return !(*this == other); }\r\n	friend bool operator<(string const & lhs, string const & rhs);\r\n\r\n	typedef char const * const_iterator;\r\n	const_iterator begin() const { return &Buffer[0]; }\r\n	const_iterator end() const { return &Buffer[Length]; }\r\n};\r\n\r\nclass ResourceManager\r\n{\r\npublic:\r\n	string const & GetString(string resourceName);\r\n	void AddResource(string name, string value);\r\n};\r\n\r\nextern ResourceManager *const resource_manager;\r\n\r\nclass NoneType\r\n{\r\npublic:\r\n	template<class T>\r\n	operator T*() const { return static_cast<T*>(0); }\r\n};\r\nstatic const NoneType None = NoneType();\r\n\r\ntemplate<typename T>\r\nstruct Maybe\r\n{\r\nprivate:\r\n	T data;\r\n	bool hasValue;\r\n\r\npublic:\r\n	Maybe(T const & value) : data(value), hasValue(true) {}\r\n	Maybe(::NoneType const & none) : hasValue(false) {}\r\n	T& operator->() { return data; }\r\n	T const & operator->() const\r\n	{\r\n		if(!hasValue) throw \"Access to null Maybe value\";\r\n		return data;\r\n	}\r\n	T  & operator* ()\r\n	{\r\n		if(!hasValue) throw \"Access to null Maybe value\";\r\n		return data;\r\n	}\r\n	T const & operator* () const\r\n	{\r\n		if(!hasValue) throw \"Access to null Maybe value\";\r\n		return data;\r\n	}\r\n	bool operator==(T const & other) const\r\n	{\r\n		return hasValue && data == other;\r\n	}\r\n	bool operator!=(T const & other) const\r\n	{\r\n		return hasValue && data != other;\r\n	}\r\n};\r\n\r\nnamespace System\r\n{\r\n	namespace Collections\r\n	{\r\n		template<typename T>\r\n		class List\r\n		{\r\n		private:\r\n			T* values;\r\n			int length;\r\n			int capacity;\r\n\r\n		public:\r\n			typedef T const * const_iterator;\r\n\r\n			List() : values(0), length(0), capacity(0) { }\r\n			void Add(T value);\r\n			int Length() const { return length; }\r\n			const_iterator begin() const { return values; }\r\n			const_iterator end() const { return &values[length]; }\r\n			T const & Get(int const index) const { return values[index]; }\r\n		};\r\n\r\n		template<typename T>\r\n		void List<T>::Add(T value)\r\n		{\r\n			if(length >= capacity)\r\n			{\r\n				int newCapacity = capacity == 0 ? 16 : capacity * 2;\r\n				T* newValues = new T[newCapacity];\r\n				std::memcpy(newValues, values, length * sizeof(T));\r\n				values = newValues;\r\n				capacity = newCapacity;\r\n			}\r\n			values[length] = value;\r\n			length++;\r\n		}\r\n	}\r\n\r\n	namespace Console\r\n	{\r\n		class Console\r\n		{\r\n		public:\r\n			void Write(string value);\r\n			void WriteLine(string value);\r\n			void WriteLine();\r\n		};\r\n\r\n		class Arguments\r\n		{\r\n		private:\r\n			string* args;\r\n		public:\r\n			typedef string const * const_iterator;\r\n			const int Count;\r\n\r\n			Arguments(int argc, char const *const * argv);\r\n			const_iterator begin() const { return &args[0]; }\r\n			const_iterator end() const { return &args[Count]; }\r\n			string const & Get(int const index) const { return args[index]; }\r\n		};\r\n	}\r\n\r\n	namespace IO\r\n	{\r\n		class FileReader\r\n		{\r\n		private:\r\n			std::FILE* file;\r\n\r\n		public:\r\n			FileReader(const string& fileName);\r\n			string ReadToEndSync();\r\n			void Close();\r\n		};\r\n\r\n		class FileWriter\r\n		{\r\n		private:\r\n			std::FILE* file;\r\n\r\n		public:\r\n			FileWriter(const string& fileName);\r\n			void Write(const string& value);\r\n			void Close();\r\n		};\r\n	}\r\n\r\n	namespace Text\r\n	{\r\n		class StringBuilder\r\n		{\r\n		private:\r\n			string buffer;\r\n		public:\r\n			StringBuilder();\r\n			StringBuilder(string const & value);\r\n			void Append(string const & value);\r\n			void AppendLine(string const& value);\r\n			void AppendLine();\r\n			string ToString() const { return buffer; }\r\n		};\r\n	}\r\n}\r\n"));

	Main(new ::System::Console::Console(), new ::System::Console::Arguments(argc, argv));
	return 0;
}
