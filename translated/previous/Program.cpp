#include "RuntimeLibrary.h"

// Type Declarations
class Source_Text_;
class Source_File_Builder_;
class Emitter_;
class Lexer_;
class Parser_;
class Syntax_Node_;
class Token_Stream_;
class Token_Type_;

// Function Declarations
auto AcceptToken_() -> ::Syntax_Node_ const *;
auto ExpectToken_(int const tokenType_) -> ::Syntax_Node_ const *;
auto Accept_(string const expected_) -> bool;
auto Expect_(string const expected_) -> void;
auto IsValueType_(::Syntax_Node_ const *const type_) -> bool;
auto ConvertType_(::Syntax_Node_ const *const type_) -> string;
auto ConvertType_(bool const mutableBinding_, ::Syntax_Node_ const * type_) -> string;
auto ConvertParameterList_(::Syntax_Node_ const *const parameterList_, bool const isMainFunction_) -> string;
auto ConvertParameterList_(::Syntax_Node_ const *const parameterList_) -> string;
auto ConvertExpression_(::Syntax_Node_ const *const syntax_, ::Source_File_Builder_ *const builder_) -> void;
auto EmitStatement_(::Syntax_Node_ const *const statement_) -> void;
auto EmitClassMember_(::Syntax_Node_ const *const member_, string const className_) -> void;
auto EmitDeclaration_(::Syntax_Node_ const *const declaration_) -> void;
auto ParseType_() -> ::Syntax_Node_ const *;
auto ParseAtom_() -> ::Syntax_Node_ const *;
auto ParseCallArguments_() -> ::Syntax_Node_ const *;
auto ParseExpression_(int const minPrecedence_) -> ::Syntax_Node_ const *;
auto ParseExpression_() -> ::Syntax_Node_ const *;
auto ParseStatement_() -> ::Syntax_Node_ const *;
auto ParseIfStatement_() -> ::Syntax_Node_ const *;
auto ParseVariableDeclaration_(bool const allowInitializer_) -> ::Syntax_Node_ const *;
auto ParseBlock_() -> ::Syntax_Node_ const *;
auto ParseParameterList_() -> ::Syntax_Node_ const *;
auto ParseClassMember_() -> ::Syntax_Node_ const *;
auto ParseDeclaration_() -> ::Syntax_Node_ const *;
auto ParseCompilationUnit_() -> void;
auto EmitPreamble_() -> void;
auto EmitEntryPointAdapter_(::System_::Collections_::List_<::Source_Text_ const *> const *const resources_) -> void;
auto Compile_(::System_::Collections_::List_<::Source_Text_ const *> const *const sources_, ::System_::Collections_::List_<::Source_Text_ const *> const *const resources_) -> string;
auto Main_(::System_::Console_::Console_ *const console_, ::System_::Console_::Arguments_ const *const args_) -> void;
auto ReadSource_(string const path_) -> ::Source_Text_ const *;
auto FormatError_(string const message_) -> string;

// Class Declarations

class Source_Text_
{
public:
	string Package_;
	string Name_;
	string Text_;
	Source_Text_(string const package_, string const name_, string const text_);
};

class Source_File_Builder_
{
public:
	::System_::Text_::String_Builder_ * code_;
	::System_::Text_::String_Builder_ * indent_;
	bool firstElement_;
	bool afterBlock_;
	Source_File_Builder_();
	auto Error_(string const message_) -> void;
	auto BeginLine_(string const value_) -> void;
	auto Write_(string const value_) -> void;
	auto EndLine_(string const value_) -> void;
	auto WriteLine_(string const value_) -> void;
	auto BlankLine_() -> void;
	auto ElementSeparatorLine_() -> void;
	auto StatementSeparatorLine_() -> void;
	auto BeginBlock_() -> void;
	auto EndBlock_() -> void;
	auto EndBlockWithSemicolon_() -> void;
	auto ToString_() const -> string;
};

class Emitter_
{
public:
};

class Lexer_
{
public:
	auto Analyze_(::Source_Text_ const *const source_) const -> ::Token_Stream_ *;
};

class Parser_
{
public:
	Parser_();
	auto Parse_(::Token_Stream_ const *const tokenStream_) const -> ::Syntax_Node_ const *;
};

class Syntax_Node_
{
public:
	int Type_;
	::Source_Text_ const * Source_;
	unsigned int Start_;
	unsigned int Length_;
	::System_::Collections_::List_<::Syntax_Node_ const *> const * Children_;
	Syntax_Node_(int const type_, ::Source_Text_ const *const source_, unsigned int const start_, unsigned int const length_);
	Syntax_Node_(int const type_, ::Syntax_Node_ const *const child_);
	Syntax_Node_(int const type_, ::System_::Collections_::List_<::Syntax_Node_ const *> const *const children_);
	auto GetText_() const -> string;
	auto FirstChildOfType_(int const type_) const -> ::Syntax_Node_ const *;
	auto HasChildOfType_(int const type_) const -> bool;
};

class Token_Stream_
{
public:
	::Source_Text_ const * Source_;
	unsigned int position_;
	Token_Stream_(::Source_Text_ const *const source_);
	auto GetNextToken_() -> ::Syntax_Node_ const *;
	auto NewIdentifierOrKeyword_(unsigned int const end_) -> ::Syntax_Node_ const *;
	auto NewOperator_(int const type_) -> ::Syntax_Node_ const *;
	auto NewOperator_(int const type_, unsigned int const length_) -> ::Syntax_Node_ const *;
	auto NewToken_(int const type_, unsigned int const end_) -> ::Syntax_Node_ const *;
	static auto IsIdentifierChar_(char const c_) -> bool;
	static auto IsNumberChar_(char const c_) -> bool;
};

class Token_Type_
{
public:
};

// Global Definitions
::Token_Stream_ * tokenStream_ = ::None;
::Syntax_Node_ const * Token_ = ::None;
::Source_File_Builder_ *const TypeDeclarations_ = new ::Source_File_Builder_();
::Source_File_Builder_ *const FunctionDeclarations_ = new ::Source_File_Builder_();
::Source_File_Builder_ *const ClassDeclarations_ = new ::Source_File_Builder_();
::Source_File_Builder_ *const GlobalDefinitions_ = new ::Source_File_Builder_();
::Source_File_Builder_ *const Definitions_ = new ::Source_File_Builder_();
string MainFunctionReturnType_ = string("");
bool MainFunctionAcceptsConsole_ = false;
bool MainFunctionAcceptsArgs_ = false;
int const Error_ = -1;
int const LeftBrace_ = 1;
int const RightBrace_ = 2;
int const LeftParen_ = 3;
int const RightParen_ = 4;
int const Semicolon_ = 5;
int const Comma_ = 6;
int const Dot_ = 7;
int const Colon_ = 8;
int const LeftBracket_ = 9;
int const RightBracket_ = 10;
int const Question_ = 11;
int const Equal_ = 12;
int const Assign_ = 13;
int const AddAssign_ = 14;
int const Add_ = 15;
int const Arrow_ = 16;
int const SubAssign_ = 17;
int const Sub_ = 18;
int const Slash_ = 19;
int const NotEqual_ = 20;
int const LessThanOrEqual_ = 21;
int const LessThan_ = 22;
int const GreaterThanOrEqual_ = 23;
int const GreaterThan_ = 24;
int const StringLiteral_ = 25;
int const CodePointLiteral_ = 26;
int const Identifier_ = 27;
int const Number_ = 28;
int const NewKeyword_ = 29;
int const NotOperator_ = 30;
int const NullKeyword_ = 31;
int const SelfKeyword_ = 32;
int const TrueKeyword_ = 33;
int const FalseKeyword_ = 34;
int const IdentifierName_ = 35;
int const GenericName_ = 36;
int const QualifiedName_ = 37;
int const PackageQualifiedName_ = 38;
int const MutableKeyword_ = 39;
int const NullableType_ = 40;
int const PredefinedType_ = 41;
int const CodePoint_ = 42;
int const String_ = 43;
int const Int_ = 44;
int const Bool_ = 45;
int const Void_ = 46;
int const UnsignedInt_ = 47;
int const ParameterList_ = 48;
int const Parameter_ = 49;
int const SelfParameter_ = 50;
int const VarKeyword_ = 51;
int const MutableType_ = 52;
int const NewExpression_ = 53;
int const ArgumentList_ = 54;
int const NotExpression_ = 55;
int const ParenthesizedExpression_ = 56;
int const NullLiteralExpression_ = 57;
int const SelfExpression_ = 58;
int const TrueLiteralExpression_ = 59;
int const FalseLiteralExpression_ = 60;
int const StringLiteralExpression_ = 61;
int const CodePointLiteralExpression_ = 62;
int const NumericLiteralExpression_ = 63;
int const AssignmentExpression_ = 64;
int const OrExpression_ = 65;
int const AndExpression_ = 66;
int const EqualExpression_ = 67;
int const NotEqualExpression_ = 68;
int const AndKeyword_ = 69;
int const OrKeyword_ = 70;
int const ComparisionExpression_ = 71;
int const AddExpression_ = 72;
int const SubtractExpression_ = 73;
int const InvocationExpression_ = 74;
int const MemberAccessExpression_ = 75;
int const ElementAccessExpression_ = 76;
int const UnaryMinusExpression_ = 77;
int const ReturnKeyword_ = 78;
int const ReturnStatement_ = 79;
int const LoopKeyword_ = 80;
int const LoopStatement_ = 81;
int const Block_ = 82;
int const WhileKeyword_ = 83;
int const WhileStatement_ = 84;
int const ForKeyword_ = 85;
int const ForStatement_ = 86;
int const LetKeyword_ = 87;
int const VariableDeclaration_ = 88;
int const LocalDeclarationStatement_ = 89;
int const InKeyword_ = 90;
int const DoKeyword_ = 91;
int const DoWhileStatement_ = 92;
int const IfKeyword_ = 93;
int const ElseKeyword_ = 94;
int const IfStatement_ = 95;
int const ElseClause_ = 96;
int const BreakKeyword_ = 97;
int const BreakStatement_ = 98;
int const ContinueKeyword_ = 99;
int const ContinueStatement_ = 100;
int const ExpressionStatement_ = 101;
int const PublicKeyword_ = 102;
int const ProtectedKeyword_ = 103;
int const InternalKeyword_ = 104;
int const PrivateKeyword_ = 105;
int const ConstructorDeclaration_ = 106;
int const FieldDeclaration_ = 107;
int const MethodDeclaration_ = 108;
int const GlobalDeclaration_ = 109;
int const ClassKeyword_ = 110;
int const ClassDeclaration_ = 111;
int const EnumKeyword_ = 112;
int const StructKeyword_ = 113;
int const EnumDeclaration_ = 114;
int const EnumMemberDeclaration_ = 115;
int const FunctionDeclaration_ = 116;

// Definitions

auto AcceptToken_() -> ::Syntax_Node_ const *
{
	::Syntax_Node_ const *const node_ = Token_;
	Token_ = tokenStream_->GetNextToken_();
	return node_;
}

auto ExpectToken_(int const tokenType_) -> ::Syntax_Node_ const *
{
	if (Token_->Type_ != tokenType_)
	{
		Definitions_->Error_(string("Expected token type ") + tokenType_ + string(", found `") + Token_->GetText_() + string("` of type ") + Token_->Type_);
		Token_ = tokenStream_->GetNextToken_();
		return new ::Syntax_Node_(Error_, Token_->Source_, Token_->Start_, Token_->Length_);
	}

	::Syntax_Node_ const *const node_ = Token_;
	Token_ = tokenStream_->GetNextToken_();
	return node_;
}

auto Accept_(string const expected_) -> bool
{
	bool const accepted_ = Token_->GetText_() == expected_;
	if (accepted_)
	{
		Token_ = tokenStream_->GetNextToken_();
	}

	return accepted_;
}

auto Expect_(string const expected_) -> void
{
	if (Token_->GetText_() != expected_)
	{
		Definitions_->Error_(string("Expected `") + expected_ + string("` but found `") + Token_->GetText_() + string("`"));
		Token_ = tokenStream_->GetNextToken_();
	}
	else
	{
		Token_ = tokenStream_->GetNextToken_();
	}
}

auto IsValueType_(::Syntax_Node_ const *const type_) -> bool
{
	if (type_->Type_ == PredefinedType_)
	{
		return true;
	}

	if (type_->Type_ == NullableType_)
	{
		return IsValueType_(type_->Children_->Get_(0));
	}

	if (type_->Type_ == QualifiedName_)
	{
		return IsValueType_(type_->Children_->Get_(type_->Children_->Length_() - 1));
	}

	if (type_->Type_ == GenericName_)
	{
		char const firstChar_ = type_->FirstChildOfType_(IdentifierName_)->FirstChildOfType_(Identifier_)->GetText_()[0];
		return firstChar_ >= 'a' && firstChar_ <= 'z';
	}

	if (type_->Type_ == IdentifierName_)
	{
		char const firstChar_ = type_->FirstChildOfType_(Identifier_)->GetText_()[0];
		return firstChar_ >= 'a' && firstChar_ <= 'z';
	}

	if (type_->Type_ == MutableType_)
	{
		return IsValueType_(type_->Children_->Get_(1));
	}

	return true;
}

auto ConvertType_(::Syntax_Node_ const *const type_) -> string
{
	if (type_->Type_ == PredefinedType_)
	{
		::Syntax_Node_ const *const keyword_ = type_->Children_->Get_(0);
		if (keyword_->Type_ == CodePoint_)
		{
			return string("char");
		}

		if (keyword_->Type_ == UnsignedInt_)
		{
			return string("unsigned int");
		}

		return keyword_->GetText_();
	}

	if (type_->Type_ == IdentifierName_)
	{
		return string("::") + type_->GetText_() + string("_");
	}

	if (type_->Type_ == QualifiedName_)
	{
		return ConvertType_(type_->Children_->Get_(0)) + ConvertType_(type_->Children_->Get_(2));
	}

	if (type_->Type_ == GenericName_)
	{
		return ConvertType_(type_->Children_->Get_(0)) + string("<") + ConvertType_(true, type_->Children_->Get_(2)) + string(">");
	}

	return FormatError_(string("Unexpected Token of type ") + type_->Type_ + string(" found in CovertType(), `") + type_->GetText_() + string("`"));
}

auto ConvertType_(bool const mutableBinding_, ::Syntax_Node_ const * type_) -> string
{
	bool const nullable_ = type_->Type_ == NullableType_;
	if (nullable_)
	{
		type_ = type_->Children_->Get_(0);
	}

	bool const mutableValue_ = type_->Type_ == MutableType_;
	if (mutableValue_)
	{
		type_ = type_->Children_->Get_(1);
	}

	bool const isValueType_ = IsValueType_(type_);
	string cppType_ = ConvertType_(type_);
	if (isValueType_)
	{
		if (nullable_)
		{
			cppType_ = string("::Maybe<") + cppType_ + string(">");
		}

		if (!mutableBinding_ && !mutableValue_)
		{
			cppType_ = cppType_ + string(" const");
		}
	}
	else
	{
		if (!mutableValue_)
		{
			cppType_ = cppType_ + string(" const");
		}

		cppType_ = cppType_ + string(" *");
		if (!mutableBinding_)
		{
			cppType_ = cppType_ + string("const");
		}
	}

	return cppType_;
}

auto ConvertParameterList_(::Syntax_Node_ const *const parameterList_, bool const isMainFunction_) -> string
{
	::System_::Text_::String_Builder_ *const builder_ = new ::System_::Text_::String_Builder_();
	builder_->Append_(string("("));
	bool firstParameter_ = true;
	for (::Syntax_Node_ const *const parameter_ : *(parameterList_->Children_))
	{
		if (parameter_->Type_ == Parameter_)
		{
			if (!firstParameter_)
			{
				builder_->Append_(string(", "));
			}
			else
			{
				firstParameter_ = false;
			}

			bool const mutableBinding_ = parameter_->HasChildOfType_(VarKeyword_);
			::Syntax_Node_ const *const type_ = parameter_->Children_->Get_(parameter_->Children_->Length_() - 1);
			builder_->Append_(ConvertType_(mutableBinding_, type_));
			builder_->Append_(string(" "));
			builder_->Append_(parameter_->FirstChildOfType_(Identifier_)->GetText_());
			builder_->Append_(string("_"));
			if (isMainFunction_)
			{
				string typeString_;
				if (type_->Type_ == MutableType_)
				{
					typeString_ = type_->Children_->Get_(1)->GetText_();
				}
				else
				{
					typeString_ = type_->GetText_();
				}

				if (typeString_ == string("System.Console.Console"))
				{
					MainFunctionAcceptsConsole_ = true;
				}

				if (typeString_ == string("System.Console.Arguments"))
				{
					MainFunctionAcceptsArgs_ = true;
				}
			}
		}
	}

	builder_->Append_(string(")"));
	return builder_->ToString_();
}

auto ConvertParameterList_(::Syntax_Node_ const *const parameterList_) -> string
{
	return ConvertParameterList_(parameterList_, false);
}

auto ConvertExpression_(::Syntax_Node_ const *const syntax_, ::Source_File_Builder_ *const builder_) -> void
{
	if (syntax_->Type_ == NewExpression_)
	{
		::Syntax_Node_ const *const type_ = syntax_->Children_->Get_(1);
		if (!IsValueType_(type_))
		{
			builder_->Write_(string("new "));
		}

		builder_->Write_(ConvertType_(type_));
		::Syntax_Node_ const *const argumentList_ = syntax_->Children_->Get_(2);
		ConvertExpression_(argumentList_, builder_);
	}
	else if (syntax_->Type_ == ArgumentList_)
	{
		builder_->Write_(string("("));
		bool firstExpression_ = true;
		for (::Syntax_Node_ const *const arg_ : *(syntax_->Children_))
		{
			if (arg_->Type_ != LeftParen_ && arg_->Type_ != RightParen_ && arg_->Type_ != Comma_)
			{
				if (firstExpression_)
				{
					firstExpression_ = false;
				}
				else
				{
					builder_->Write_(string(", "));
				}

				ConvertExpression_(arg_, builder_);
			}
		}

		builder_->Write_(string(")"));
	}
	else if (syntax_->Type_ == NotExpression_)
	{
		builder_->Write_(string("!"));
		ConvertExpression_(syntax_->Children_->Get_(1), builder_);
	}
	else if (syntax_->Type_ == ParenthesizedExpression_)
	{
		builder_->Write_(string("("));
		ConvertExpression_(syntax_->Children_->Get_(1), builder_);
		builder_->Write_(string(")"));
	}
	else if (syntax_->Type_ == UnaryMinusExpression_)
	{
		builder_->Write_(string("-"));
		ConvertExpression_(syntax_->Children_->Get_(1), builder_);
	}
	else if (syntax_->Type_ == NullLiteralExpression_)
	{
		builder_->Write_(string("::None"));
	}
	else if (syntax_->Type_ == SelfExpression_)
	{
		builder_->Write_(string("this"));
	}
	else if (syntax_->Type_ == TrueLiteralExpression_ || syntax_->Type_ == FalseLiteralExpression_ || syntax_->Type_ == NumericLiteralExpression_ || syntax_->Type_ == CodePointLiteralExpression_)
	{
		builder_->Write_(syntax_->GetText_());
	}
	else if (syntax_->Type_ == IdentifierName_)
	{
		builder_->Write_(syntax_->GetText_() + string("_"));
	}
	else if (syntax_->Type_ == StringLiteralExpression_)
	{
		builder_->Write_(string("string(") + syntax_->GetText_() + string(")"));
	}
	else if (syntax_->Type_ == AssignmentExpression_ || syntax_->Type_ == EqualExpression_ || syntax_->Type_ == ComparisionExpression_ || syntax_->Type_ == AddExpression_ || syntax_->Type_ == SubtractExpression_)
	{
		ConvertExpression_(syntax_->Children_->Get_(0), builder_);
		builder_->Write_(string(" "));
		builder_->Write_(syntax_->Children_->Get_(1)->GetText_());
		builder_->Write_(string(" "));
		ConvertExpression_(syntax_->Children_->Get_(2), builder_);
	}
	else if (syntax_->Type_ == OrExpression_)
	{
		ConvertExpression_(syntax_->Children_->Get_(0), builder_);
		builder_->Write_(string(" || "));
		ConvertExpression_(syntax_->Children_->Get_(2), builder_);
	}
	else if (syntax_->Type_ == AndExpression_)
	{
		ConvertExpression_(syntax_->Children_->Get_(0), builder_);
		builder_->Write_(string(" && "));
		ConvertExpression_(syntax_->Children_->Get_(2), builder_);
	}
	else if (syntax_->Type_ == NotEqualExpression_)
	{
		ConvertExpression_(syntax_->Children_->Get_(0), builder_);
		builder_->Write_(string(" != "));
		ConvertExpression_(syntax_->Children_->Get_(2), builder_);
	}
	else if (syntax_->Type_ == InvocationExpression_)
	{
		ConvertExpression_(syntax_->Children_->Get_(0), builder_);
		ConvertExpression_(syntax_->Children_->Get_(1), builder_);
	}
	else if (syntax_->Type_ == MemberAccessExpression_)
	{
		ConvertExpression_(syntax_->Children_->Get_(0), builder_);
		builder_->Write_(string("->"));
		ConvertExpression_(syntax_->Children_->Get_(2), builder_);
	}
	else if (syntax_->Type_ == ElementAccessExpression_)
	{
		ConvertExpression_(syntax_->Children_->Get_(0), builder_);
		builder_->Write_(string("["));
		ConvertExpression_(syntax_->Children_->Get_(2), builder_);
		builder_->Write_(string("]"));
	}
	else
	{
		builder_->Error_(string("Could not convert expression of type ") + syntax_->Type_);
	}
}

auto EmitStatement_(::Syntax_Node_ const *const statement_) -> void
{
	Definitions_->StatementSeparatorLine_();
	if (statement_->Type_ == ReturnStatement_)
	{
		if (statement_->Children_->Length_() == 2)
		{
			Definitions_->WriteLine_(string("return;"));
		}
		else
		{
			Definitions_->BeginLine_(string("return "));
			ConvertExpression_(statement_->Children_->Get_(1), Definitions_);
			Definitions_->EndLine_(string(";"));
		}
	}
	else if (statement_->Type_ == LoopStatement_)
	{
		Definitions_->WriteLine_(string("for (;;)"));
		EmitStatement_(statement_->Children_->Get_(1));
	}
	else if (statement_->Type_ == Block_)
	{
		Definitions_->BeginBlock_();
		for (::Syntax_Node_ const *const blockStatement_ : *(statement_->Children_))
		{
			if (blockStatement_->Type_ != LeftBrace_ && blockStatement_->Type_ != RightBrace_)
			{
				EmitStatement_(blockStatement_);
			}
		}

		Definitions_->EndBlock_();
	}
	else if (statement_->Type_ == WhileStatement_)
	{
		Definitions_->BeginLine_(string("while ("));
		ConvertExpression_(statement_->Children_->Get_(1), Definitions_);
		Definitions_->EndLine_(string(")"));
		EmitStatement_(statement_->Children_->Get_(2));
	}
	else if (statement_->Type_ == ForStatement_)
	{
		Definitions_->BeginLine_(string("for ("));
		::Syntax_Node_ const *const variableDeclaration_ = statement_->Children_->Get_(1);
		bool const mutableBinding_ = variableDeclaration_->HasChildOfType_(VarKeyword_);
		string const name_ = variableDeclaration_->FirstChildOfType_(Identifier_)->GetText_();
		::Syntax_Node_ const *const type_ = variableDeclaration_->Children_->Get_(3);
		Definitions_->Write_(ConvertType_(mutableBinding_, type_) + string(" ") + name_ + string("_"));
		Definitions_->Write_(string(" : *("));
		ConvertExpression_(statement_->Children_->Get_(3), Definitions_);
		Definitions_->EndLine_(string("))"));
		EmitStatement_(statement_->Children_->Get_(4));
	}
	else if (statement_->Type_ == DoWhileStatement_)
	{
		Definitions_->WriteLine_(string("do"));
		EmitStatement_(statement_->Children_->Get_(1));
		Definitions_->BeginLine_(string("while ("));
		ConvertExpression_(statement_->Children_->Get_(3), Definitions_);
		Definitions_->EndLine_(string(");"));
	}
	else if (statement_->Type_ == IfStatement_)
	{
		::Syntax_Node_ const * ifStatement_ = statement_;
		Definitions_->BeginLine_(string(""));
		for (;;)
		{
			Definitions_->Write_(string("if ("));
			ConvertExpression_(ifStatement_->Children_->Get_(1), Definitions_);
			Definitions_->EndLine_(string(")"));
			EmitStatement_(ifStatement_->Children_->Get_(2));
			::Syntax_Node_ const *const elseClause_ = ifStatement_->FirstChildOfType_(ElseClause_);
			if (elseClause_ != ::None)
			{
				ifStatement_ = elseClause_->FirstChildOfType_(IfStatement_);
				if (ifStatement_ != ::None)
				{
					Definitions_->BeginLine_(string("else "));
				}
				else
				{
					Definitions_->WriteLine_(string("else"));
					EmitStatement_(elseClause_->Children_->Get_(1));
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	else if (statement_->Type_ == BreakStatement_)
	{
		Definitions_->WriteLine_(string("break;"));
	}
	else if (statement_->Type_ == ContinueStatement_)
	{
		Definitions_->WriteLine_(string("continue;"));
	}
	else if (statement_->Type_ == LocalDeclarationStatement_)
	{
		::Syntax_Node_ const *const variableDeclaration_ = statement_->Children_->Get_(0);
		string const variableName_ = variableDeclaration_->FirstChildOfType_(Identifier_)->GetText_();
		::Syntax_Node_ const *const variableType_ = variableDeclaration_->Children_->Get_(3);
		bool const mutableBinding_ = variableDeclaration_->HasChildOfType_(VarKeyword_);
		Definitions_->BeginLine_(ConvertType_(mutableBinding_, variableType_));
		Definitions_->Write_(string(" ") + variableName_ + string("_"));
		if (variableDeclaration_->HasChildOfType_(Assign_))
		{
			Definitions_->Write_(string(" = "));
			ConvertExpression_(variableDeclaration_->Children_->Get_(5), Definitions_);
		}

		Definitions_->EndLine_(string(";"));
	}
	else if (statement_->Type_ == ExpressionStatement_)
	{
		Definitions_->BeginLine_(string(""));
		ConvertExpression_(statement_->Children_->Get_(0), Definitions_);
		Definitions_->EndLine_(string(";"));
	}
	else
	{
		Definitions_->Error_(string("Could not emit statement of type ") + statement_->Type_);
	}
}

auto EmitClassMember_(::Syntax_Node_ const *const member_, string const className_) -> void
{
	if (member_->Type_ == ConstructorDeclaration_)
	{
		string const parameters_ = ConvertParameterList_(member_->Children_->Get_(2));
		ClassDeclarations_->WriteLine_(className_ + string("_") + parameters_ + string(";"));
		Definitions_->ElementSeparatorLine_();
		Definitions_->WriteLine_(string("::") + className_ + string("_::") + className_ + string("_") + parameters_ + string(""));
		EmitStatement_(member_->Children_->Get_(3));
	}
	else if (member_->Type_ == FieldDeclaration_)
	{
		::Syntax_Node_ const *const variableDeclaration_ = member_->Children_->Get_(1);
		string const fieldName_ = variableDeclaration_->Children_->Get_(1)->GetText_();
		::Syntax_Node_ const *const fieldType_ = variableDeclaration_->Children_->Get_(3);
		string const cppType_ = ConvertType_(true, fieldType_);
		ClassDeclarations_->WriteLine_(cppType_ + string(" ") + fieldName_ + string("_;"));
	}
	else if (member_->Type_ == MethodDeclaration_)
	{
		string const methodName_ = member_->Children_->Get_(1)->GetText_();
		::Syntax_Node_ const *const parameterList_ = member_->Children_->Get_(2);
		string const parameters_ = ConvertParameterList_(parameterList_);
		::Syntax_Node_ const *const selfParameter_ = parameterList_->FirstChildOfType_(SelfParameter_);
		bool const isAssociatedFuntion_ = selfParameter_ == ::None;
		bool const mutableSelf_ = !isAssociatedFuntion_ && selfParameter_->HasChildOfType_(MutableKeyword_);
		::Syntax_Node_ const *const returnType_ = member_->Children_->Get_(4);
		string const cppType_ = ConvertType_(true, returnType_);
		string staticModifier_ = string("");
		if (isAssociatedFuntion_)
		{
			staticModifier_ = string("static ");
		}

		string constModifier_ = string("");
		if (!mutableSelf_ && !isAssociatedFuntion_)
		{
			constModifier_ = string("const ");
		}

		ClassDeclarations_->WriteLine_(staticModifier_ + string("auto ") + methodName_ + string("_") + parameters_ + string(" ") + constModifier_ + string("-> ") + cppType_ + string(";"));
		Definitions_->ElementSeparatorLine_();
		Definitions_->WriteLine_(string("auto ::") + className_ + string("_::") + methodName_ + string("_") + parameters_ + string(" ") + constModifier_ + string("-> ") + cppType_);
		::Syntax_Node_ const *const block_ = member_->Children_->Get_(5);
		EmitStatement_(block_);
	}
	else
	{
		Definitions_->Error_(string("Could not emit member of type ") + member_->Type_);
	}
}

auto EmitDeclaration_(::Syntax_Node_ const *const declaration_) -> void
{
	if (declaration_->Type_ == GlobalDeclaration_)
	{
		::Syntax_Node_ const *const variableDeclaration_ = declaration_->Children_->Get_(1);
		string const variableName_ = variableDeclaration_->Children_->Get_(1)->GetText_();
		::Syntax_Node_ const *const variableType_ = variableDeclaration_->Children_->Get_(3);
		bool const mutableBinding_ = variableDeclaration_->HasChildOfType_(VarKeyword_);
		string const cppType_ = ConvertType_(mutableBinding_, variableType_);
		GlobalDefinitions_->BeginLine_(cppType_);
		GlobalDefinitions_->Write_(string(" ") + variableName_ + string("_ = "));
		::Syntax_Node_ const *const expression_ = variableDeclaration_->Children_->Get_(5);
		ConvertExpression_(expression_, GlobalDefinitions_);
		GlobalDefinitions_->EndLine_(string(";"));
	}
	else if (declaration_->Type_ == ClassDeclaration_)
	{
		string const className_ = declaration_->Children_->Get_(2)->GetText_();
		TypeDeclarations_->WriteLine_(string("class ") + className_ + string("_;"));
		ClassDeclarations_->ElementSeparatorLine_();
		ClassDeclarations_->WriteLine_(string("class ") + className_ + string("_"));
		ClassDeclarations_->BeginBlock_();
		ClassDeclarations_->EndLine_(string("public:"));
		for (::Syntax_Node_ const *const member_ : *(declaration_->Children_))
		{
			if (member_->Type_ == ConstructorDeclaration_ || member_->Type_ == FieldDeclaration_ || member_->Type_ == MethodDeclaration_)
			{
				EmitClassMember_(member_, className_);
			}
		}

		ClassDeclarations_->EndBlockWithSemicolon_();
	}
	else if (declaration_->Type_ == EnumDeclaration_)
	{
		string const enumName_ = declaration_->Children_->Get_(3)->GetText_();
		TypeDeclarations_->WriteLine_(string("enum class ") + enumName_ + string("_;"));
		ClassDeclarations_->ElementSeparatorLine_();
		ClassDeclarations_->WriteLine_(string("enum class ") + enumName_ + string("_"));
		ClassDeclarations_->BeginBlock_();
		for (::Syntax_Node_ const *const member_ : *(declaration_->Children_))
		{
			if (member_->Type_ == EnumMemberDeclaration_)
			{
				string const memberName_ = member_->Children_->Get_(0)->GetText_();
				ClassDeclarations_->BeginLine_(memberName_ + string("_"));
				::Syntax_Node_ const *const memberValue_ = member_->FirstChildOfType_(Number_);
				if (memberValue_ != ::None)
				{
					ClassDeclarations_->Write_(string(" = "));
					ClassDeclarations_->Write_(memberValue_->GetText_());
				}

				ClassDeclarations_->EndLine_(string(","));
			}
		}

		ClassDeclarations_->EndBlockWithSemicolon_();
	}
	else if (declaration_->Type_ == FunctionDeclaration_)
	{
		string const name_ = declaration_->Children_->Get_(1)->GetText_();
		bool const isMain_ = name_ == string("Main");
		string const parameters_ = ConvertParameterList_(declaration_->Children_->Get_(2), isMain_);
		::Syntax_Node_ const *const returnType_ = declaration_->Children_->Get_(4);
		string const cppType_ = ConvertType_(true, returnType_);
		FunctionDeclarations_->WriteLine_(string("auto ") + name_ + string("_") + parameters_ + string(" -> ") + cppType_ + string(";"));
		Definitions_->ElementSeparatorLine_();
		Definitions_->WriteLine_(string("auto ") + name_ + string("_") + parameters_ + string(" -> ") + cppType_);
		if (isMain_)
		{
			if (MainFunctionReturnType_ != string(""))
			{
				Definitions_->Error_(string("Multiple declarations of main"));
			}

			MainFunctionReturnType_ = cppType_;
		}

		EmitStatement_(declaration_->Children_->Get_(5));
	}
	else
	{
		Definitions_->Error_(string("Could not emit declaration of type ") + declaration_->Type_);
	}
}

auto ParseType_() -> ::Syntax_Node_ const *
{
	if (Token_->Type_ == MutableKeyword_)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
		children_->Add_(ExpectToken_(MutableKeyword_));
		children_->Add_(ParseType_());
		return new ::Syntax_Node_(MutableType_, children_);
	}

	::Syntax_Node_ const * type_;
	if (Token_->Type_ == CodePoint_ || Token_->Type_ == String_ || Token_->Type_ == Int_ || Token_->Type_ == Bool_ || Token_->Type_ == Void_ || Token_->Type_ == UnsignedInt_)
	{
		type_ = new ::Syntax_Node_(PredefinedType_, AcceptToken_());
	}
	else
	{
		type_ = new ::Syntax_Node_(IdentifierName_, ExpectToken_(Identifier_));
		while (Token_->Type_ == Dot_)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
			children_->Add_(type_);
			children_->Add_(ExpectToken_(Dot_));
			::Syntax_Node_ const *const identifier_ = ExpectToken_(Identifier_);
			if (Token_->Type_ == LessThan_)
			{
				::System_::Collections_::List_<::Syntax_Node_ const *> *const genericNameChildren_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
				genericNameChildren_->Add_(new ::Syntax_Node_(IdentifierName_, identifier_));
				genericNameChildren_->Add_(ExpectToken_(LessThan_));
				genericNameChildren_->Add_(ParseType_());
				genericNameChildren_->Add_(ExpectToken_(GreaterThan_));
				children_->Add_(new ::Syntax_Node_(GenericName_, genericNameChildren_));
			}
			else
			{
				children_->Add_(new ::Syntax_Node_(IdentifierName_, identifier_));
			}

			type_ = new ::Syntax_Node_(QualifiedName_, children_);
		}
	}

	if (Token_->Type_ == Question_)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
		children_->Add_(type_);
		children_->Add_(ExpectToken_(Question_));
		type_ = new ::Syntax_Node_(NullableType_, children_);
	}

	return type_;
}

auto ParseAtom_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	if (Token_->Type_ == NewKeyword_)
	{
		children_->Add_(ExpectToken_(NewKeyword_));
		children_->Add_(ParseType_());
		children_->Add_(ParseCallArguments_());
		return new ::Syntax_Node_(NewExpression_, children_);
	}

	if (Token_->Type_ == NotOperator_)
	{
		children_->Add_(ExpectToken_(NotOperator_));
		children_->Add_(ParseExpression_());
		return new ::Syntax_Node_(NotExpression_, children_);
	}

	if (Token_->Type_ == LeftParen_)
	{
		children_->Add_(ExpectToken_(LeftParen_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(RightParen_));
		return new ::Syntax_Node_(ParenthesizedExpression_, children_);
	}

	if (Token_->Type_ == Sub_)
	{
		children_->Add_(ExpectToken_(Sub_));
		children_->Add_(ParseExpression_(7));
		return new ::Syntax_Node_(UnaryMinusExpression_, children_);
	}

	if (Token_->Type_ == NullKeyword_)
	{
		children_->Add_(ExpectToken_(NullKeyword_));
		return new ::Syntax_Node_(NullLiteralExpression_, children_);
	}

	if (Token_->Type_ == SelfKeyword_)
	{
		children_->Add_(ExpectToken_(SelfKeyword_));
		return new ::Syntax_Node_(SelfExpression_, children_);
	}

	if (Token_->Type_ == TrueKeyword_)
	{
		children_->Add_(ExpectToken_(TrueKeyword_));
		return new ::Syntax_Node_(TrueLiteralExpression_, children_);
	}

	if (Token_->Type_ == FalseKeyword_)
	{
		children_->Add_(ExpectToken_(FalseKeyword_));
		return new ::Syntax_Node_(FalseLiteralExpression_, children_);
	}

	if (Token_->Type_ == Number_)
	{
		children_->Add_(ExpectToken_(Number_));
		return new ::Syntax_Node_(NumericLiteralExpression_, children_);
	}

	if (Token_->Type_ == Identifier_)
	{
		children_->Add_(ExpectToken_(Identifier_));
		return new ::Syntax_Node_(IdentifierName_, children_);
	}

	if (Token_->Type_ == StringLiteral_)
	{
		children_->Add_(ExpectToken_(StringLiteral_));
		return new ::Syntax_Node_(StringLiteralExpression_, children_);
	}

	if (Token_->Type_ == CodePointLiteral_)
	{
		children_->Add_(ExpectToken_(CodePointLiteral_));
		return new ::Syntax_Node_(CodePointLiteralExpression_, children_);
	}

	return ::None;
}

auto ParseCallArguments_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	children_->Add_(ExpectToken_(LeftParen_));
	if (Token_->Type_ != RightParen_)
	{
		for (;;)
		{
			children_->Add_(ParseExpression_());
			if (Token_->Type_ == Comma_)
			{
				children_->Add_(ExpectToken_(Comma_));
			}
			else
			{
				break;
			}
		}
	}

	children_->Add_(ExpectToken_(RightParen_));
	return new ::Syntax_Node_(ArgumentList_, children_);
}

auto ParseExpression_(int const minPrecedence_) -> ::Syntax_Node_ const *
{
	::Syntax_Node_ const * expression_ = ParseAtom_();
	if (expression_ == ::None)
	{
		return ::None;
	}

	for (;;)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
		children_->Add_(expression_);
		int precedence_;
		bool leftAssociative_;
		bool suffixOperator_ = false;
		int expressionType_;
		if ((Token_->Type_ == Assign_ || Token_->Type_ == AddAssign_ || Token_->Type_ == SubAssign_) && minPrecedence_ <= 1)
		{
			precedence_ = 1;
			leftAssociative_ = false;
			children_->Add_(AcceptToken_());
			expressionType_ = AssignmentExpression_;
		}
		else if (Token_->Type_ == OrKeyword_ && minPrecedence_ <= 2)
		{
			precedence_ = 2;
			leftAssociative_ = true;
			children_->Add_(ExpectToken_(OrKeyword_));
			expressionType_ = OrExpression_;
		}
		else if (Token_->Type_ == AndKeyword_ && minPrecedence_ <= 3)
		{
			precedence_ = 3;
			leftAssociative_ = true;
			children_->Add_(ExpectToken_(AndKeyword_));
			expressionType_ = AndExpression_;
		}
		else if (Token_->Type_ == Equal_ && minPrecedence_ <= 4)
		{
			precedence_ = 4;
			leftAssociative_ = true;
			children_->Add_(ExpectToken_(Equal_));
			expressionType_ = EqualExpression_;
		}
		else if (Token_->Type_ == NotEqual_ && minPrecedence_ <= 4)
		{
			precedence_ = 4;
			leftAssociative_ = true;
			children_->Add_(ExpectToken_(NotEqual_));
			expressionType_ = NotEqualExpression_;
		}
		else if ((Token_->Type_ == LessThan_ || Token_->Type_ == LessThanOrEqual_ || Token_->Type_ == GreaterThan_ || Token_->Type_ == GreaterThanOrEqual_) && minPrecedence_ <= 5)
		{
			precedence_ = 5;
			leftAssociative_ = true;
			children_->Add_(AcceptToken_());
			expressionType_ = ComparisionExpression_;
		}
		else if (Token_->Type_ == Add_ && minPrecedence_ <= 6)
		{
			precedence_ = 6;
			leftAssociative_ = true;
			children_->Add_(ExpectToken_(Add_));
			expressionType_ = AddExpression_;
		}
		else if (Token_->Type_ == Sub_ && minPrecedence_ <= 6)
		{
			precedence_ = 6;
			leftAssociative_ = true;
			children_->Add_(ExpectToken_(Sub_));
			expressionType_ = SubtractExpression_;
		}
		else if (Token_->Type_ == LeftParen_ && minPrecedence_ <= 8)
		{
			precedence_ = 8;
			leftAssociative_ = true;
			suffixOperator_ = true;
			children_->Add_(ParseCallArguments_());
			expressionType_ = InvocationExpression_;
		}
		else if (Token_->Type_ == Dot_ && minPrecedence_ <= 8)
		{
			precedence_ = 8;
			leftAssociative_ = true;
			children_->Add_(ExpectToken_(Dot_));
			expressionType_ = MemberAccessExpression_;
		}
		else if (Token_->Type_ == LeftBracket_ && minPrecedence_ <= 8)
		{
			precedence_ = 8;
			leftAssociative_ = true;
			suffixOperator_ = true;
			children_->Add_(ExpectToken_(LeftBracket_));
			children_->Add_(ParseExpression_());
			children_->Add_(ExpectToken_(RightBracket_));
			expressionType_ = ElementAccessExpression_;
		}
		else
		{
			return expression_;
		}

		if (!suffixOperator_)
		{
			if (leftAssociative_)
			{
				precedence_ += 1;
			}

			::Syntax_Node_ const *const rhs_ = ParseExpression_(precedence_);
			children_->Add_(rhs_);
			expression_ = new ::Syntax_Node_(expressionType_, children_);
		}
		else
		{
			expression_ = new ::Syntax_Node_(expressionType_, children_);
		}
	}
}

auto ParseExpression_() -> ::Syntax_Node_ const *
{
	return ParseExpression_(1);
}

auto ParseStatement_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	if (Token_->Type_ == ReturnKeyword_)
	{
		children_->Add_(ExpectToken_(ReturnKeyword_));
		if (Token_->Type_ != Semicolon_)
		{
			children_->Add_(ParseExpression_());
		}

		children_->Add_(ExpectToken_(Semicolon_));
		return new ::Syntax_Node_(ReturnStatement_, children_);
	}

	if (Token_->Type_ == LoopKeyword_)
	{
		children_->Add_(ExpectToken_(LoopKeyword_));
		children_->Add_(ParseBlock_());
		return new ::Syntax_Node_(LoopStatement_, children_);
	}

	if (Token_->Type_ == WhileKeyword_)
	{
		children_->Add_(ExpectToken_(WhileKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ParseBlock_());
		return new ::Syntax_Node_(WhileStatement_, children_);
	}

	if (Token_->Type_ == ForKeyword_)
	{
		children_->Add_(ExpectToken_(ForKeyword_));
		children_->Add_(ParseVariableDeclaration_(false));
		children_->Add_(ExpectToken_(InKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ParseBlock_());
		return new ::Syntax_Node_(ForStatement_, children_);
	}

	if (Token_->Type_ == DoKeyword_)
	{
		children_->Add_(ExpectToken_(DoKeyword_));
		children_->Add_(ParseBlock_());
		children_->Add_(ExpectToken_(WhileKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(Semicolon_));
		return new ::Syntax_Node_(DoWhileStatement_, children_);
	}

	if (Token_->Type_ == IfKeyword_)
	{
		return ParseIfStatement_();
	}

	if (Token_->Type_ == BreakKeyword_)
	{
		children_->Add_(ExpectToken_(BreakKeyword_));
		children_->Add_(ExpectToken_(Semicolon_));
		return new ::Syntax_Node_(BreakStatement_, children_);
	}

	if (Token_->Type_ == ContinueKeyword_)
	{
		children_->Add_(ExpectToken_(ContinueKeyword_));
		children_->Add_(ExpectToken_(Semicolon_));
		return new ::Syntax_Node_(ContinueStatement_, children_);
	}

	if (Token_->Type_ == VarKeyword_ || Token_->Type_ == LetKeyword_)
	{
		children_->Add_(ParseVariableDeclaration_(true));
		children_->Add_(ExpectToken_(Semicolon_));
		return new ::Syntax_Node_(LocalDeclarationStatement_, children_);
	}

	children_->Add_(ParseExpression_());
	children_->Add_(ExpectToken_(Semicolon_));
	return new ::Syntax_Node_(ExpressionStatement_, children_);
}

auto ParseIfStatement_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	children_->Add_(ExpectToken_(IfKeyword_));
	children_->Add_(ParseExpression_());
	children_->Add_(ParseBlock_());
	if (Token_->Type_ == ElseKeyword_)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *> *const elseChildren_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
		elseChildren_->Add_(ExpectToken_(ElseKeyword_));
		if (Token_->Type_ == IfKeyword_)
		{
			elseChildren_->Add_(ParseIfStatement_());
		}
		else
		{
			elseChildren_->Add_(ParseBlock_());
		}

		children_->Add_(new ::Syntax_Node_(ElseClause_, elseChildren_));
	}

	return new ::Syntax_Node_(IfStatement_, children_);
}

auto ParseVariableDeclaration_(bool const allowInitializer_) -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	if (Token_->Type_ == LetKeyword_ && Token_->Type_ != VarKeyword_)
	{
		children_->Add_(ExpectToken_(LetKeyword_));
	}
	else
	{
		children_->Add_(ExpectToken_(VarKeyword_));
	}

	children_->Add_(ExpectToken_(Identifier_));
	children_->Add_(ExpectToken_(Colon_));
	children_->Add_(ParseType_());
	if (allowInitializer_ && Token_->Type_ == Assign_)
	{
		children_->Add_(ExpectToken_(Assign_));
		children_->Add_(ParseExpression_());
	}

	return new ::Syntax_Node_(VariableDeclaration_, children_);
}

auto ParseBlock_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	children_->Add_(ExpectToken_(LeftBrace_));
	while (Token_->Type_ != RightBrace_)
	{
		children_->Add_(ParseStatement_());
	}

	children_->Add_(ExpectToken_(RightBrace_));
	return new ::Syntax_Node_(Block_, children_);
}

auto ParseParameterList_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	children_->Add_(ExpectToken_(LeftParen_));
	if (Token_->Type_ != RightParen_)
	{
		for (;;)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *> *const parameterChildren_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
			if (Token_->Type_ == MutableKeyword_ || Token_->Type_ == SelfKeyword_)
			{
				if (Token_->Type_ == MutableKeyword_)
				{
					parameterChildren_->Add_(ExpectToken_(MutableKeyword_));
				}

				parameterChildren_->Add_(ExpectToken_(SelfKeyword_));
				children_->Add_(new ::Syntax_Node_(SelfParameter_, parameterChildren_));
			}
			else
			{
				bool const mutableBinding_ = Token_->Type_ == VarKeyword_;
				if (Token_->Type_ == VarKeyword_)
				{
					parameterChildren_->Add_(ExpectToken_(VarKeyword_));
				}

				parameterChildren_->Add_(ExpectToken_(Identifier_));
				parameterChildren_->Add_(ExpectToken_(Colon_));
				::Syntax_Node_ const *const type_ = ParseType_();
				parameterChildren_->Add_(type_);
				children_->Add_(new ::Syntax_Node_(Parameter_, parameterChildren_));
			}

			if (Token_->Type_ == Comma_)
			{
				children_->Add_(ExpectToken_(Comma_));
			}
			else
			{
				break;
			}
		}
	}

	children_->Add_(ExpectToken_(RightParen_));
	return new ::Syntax_Node_(ParameterList_, children_);
}

auto ParseClassMember_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	if (Token_->Type_ == PublicKeyword_ || Token_->Type_ == ProtectedKeyword_ || Token_->Type_ == InternalKeyword_ || Token_->Type_ == PrivateKeyword_)
	{
		children_->Add_(AcceptToken_());
	}
	else
	{
		ExpectToken_(PublicKeyword_);
	}

	if (Token_->Type_ == NewKeyword_)
	{
		children_->Add_(ExpectToken_(NewKeyword_));
		children_->Add_(ParseParameterList_());
		children_->Add_(ParseBlock_());
		return new ::Syntax_Node_(ConstructorDeclaration_, children_);
	}

	if (Token_->Type_ == VarKeyword_ || Token_->Type_ == LetKeyword_)
	{
		children_->Add_(ParseVariableDeclaration_(false));
		children_->Add_(ExpectToken_(Semicolon_));
		return new ::Syntax_Node_(FieldDeclaration_, children_);
	}

	children_->Add_(ExpectToken_(Identifier_));
	children_->Add_(ParseParameterList_());
	children_->Add_(ExpectToken_(Arrow_));
	children_->Add_(ParseType_());
	children_->Add_(ParseBlock_());
	return new ::Syntax_Node_(MethodDeclaration_, children_);
}

auto ParseDeclaration_() -> ::Syntax_Node_ const *
{
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	if (Token_->Type_ == PublicKeyword_ || Token_->Type_ == ProtectedKeyword_ || Token_->Type_ == InternalKeyword_ || Token_->Type_ == PrivateKeyword_)
	{
		children_->Add_(AcceptToken_());
	}
	else
	{
		ExpectToken_(PublicKeyword_);
	}

	if (Token_->Type_ == VarKeyword_ || Token_->Type_ == LetKeyword_)
	{
		children_->Add_(ParseVariableDeclaration_(true));
		children_->Add_(ExpectToken_(Semicolon_));
		return new ::Syntax_Node_(GlobalDeclaration_, children_);
	}

	if (Token_->Type_ == ClassKeyword_)
	{
		children_->Add_(ExpectToken_(ClassKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (Token_->Type_ != RightBrace_)
		{
			children_->Add_(ParseClassMember_());
		}

		children_->Add_(ExpectToken_(RightBrace_));
		return new ::Syntax_Node_(ClassDeclaration_, children_);
	}

	if (Token_->Type_ == EnumKeyword_)
	{
		children_->Add_(ExpectToken_(EnumKeyword_));
		children_->Add_(ExpectToken_(StructKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (Token_->Type_ != RightBrace_)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *> *const memberChildren_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
			memberChildren_->Add_(ExpectToken_(Identifier_));
			if (Token_->Type_ == Assign_)
			{
				memberChildren_->Add_(ExpectToken_(Assign_));
				memberChildren_->Add_(ExpectToken_(Number_));
			}

			if (Token_->Type_ != RightBrace_)
			{
				memberChildren_->Add_(ExpectToken_(Comma_));
			}

			children_->Add_(new ::Syntax_Node_(EnumMemberDeclaration_, memberChildren_));
		}

		children_->Add_(ExpectToken_(RightBrace_));
		return new ::Syntax_Node_(EnumDeclaration_, children_);
	}

	children_->Add_(ExpectToken_(Identifier_));
	children_->Add_(ParseParameterList_());
	children_->Add_(ExpectToken_(Arrow_));
	children_->Add_(ParseType_());
	children_->Add_(ParseBlock_());
	return new ::Syntax_Node_(FunctionDeclaration_, children_);
}

auto ParseCompilationUnit_() -> void
{
	while (Token_ != ::None)
	{
		EmitDeclaration_(ParseDeclaration_());
	}
}

auto EmitPreamble_() -> void
{
	TypeDeclarations_->WriteLine_(string("#include \"RuntimeLibrary.h\""));
	TypeDeclarations_->BlankLine_();
	TypeDeclarations_->WriteLine_(string("// Type Declarations"));
	FunctionDeclarations_->BlankLine_();
	FunctionDeclarations_->WriteLine_(string("// Function Declarations"));
	ClassDeclarations_->BlankLine_();
	ClassDeclarations_->WriteLine_(string("// Class Declarations"));
	GlobalDefinitions_->BlankLine_();
	GlobalDefinitions_->WriteLine_(string("// Global Definitions"));
	Definitions_->BlankLine_();
	Definitions_->WriteLine_(string("// Definitions"));
}

auto EmitEntryPointAdapter_(::System_::Collections_::List_<::Source_Text_ const *> const *const resources_) -> void
{
	Definitions_->ElementSeparatorLine_();
	Definitions_->WriteLine_(string("// Entry Point Adapter"));
	Definitions_->WriteLine_(string("int main(int argc, char const *const * argv)"));
	Definitions_->BeginBlock_();
	for (::Source_Text_ const *const resource_ : *(resources_))
	{
		Definitions_->BeginLine_(string("resource_manager_->AddResource(::string(\""));
		Definitions_->Write_(resource_->Name_);
		Definitions_->Write_(string("\"), ::string(\""));
		Definitions_->Write_(resource_->Text_->Replace_(string("\\"), string("\\\\"))->Replace_(string("\n"), string("\\n"))->Replace_(string("\r"), string("\\r"))->Replace_(string("\""), string("\\\"")));
		Definitions_->EndLine_(string("\"));"));
	}

	if (resources_->Length_() > 0)
	{
		Definitions_->EndLine_(string(""));
	}

	::System_::Text_::String_Builder_ *const args_ = new ::System_::Text_::String_Builder_();
	if (MainFunctionAcceptsConsole_)
	{
		args_->Append_(string("new ::System_::Console_::Console_()"));
	}

	if (MainFunctionAcceptsArgs_)
	{
		if (MainFunctionAcceptsConsole_)
		{
			args_->Append_(string(", "));
		}

		args_->Append_(string("new ::System_::Console_::Arguments_(argc, argv)"));
	}

	if (MainFunctionReturnType_ == string("void"))
	{
		Definitions_->WriteLine_(string("Main_(") + args_->ToString_() + string(");"));
		Definitions_->WriteLine_(string("return 0;"));
	}
	else
	{
		Definitions_->WriteLine_(string("return Main_(") + args_->ToString_() + string(");"));
	}

	Definitions_->EndBlock_();
}

auto Compile_(::System_::Collections_::List_<::Source_Text_ const *> const *const sources_, ::System_::Collections_::List_<::Source_Text_ const *> const *const resources_) -> string
{
	EmitPreamble_();
	::Lexer_ const *const lexer_ = new ::Lexer_();
	for (::Source_Text_ const *const source_ : *(sources_))
	{
		tokenStream_ = lexer_->Analyze_(source_);
		Token_ = tokenStream_->GetNextToken_();
		ParseCompilationUnit_();
	}

	EmitEntryPointAdapter_(resources_);
	return TypeDeclarations_->ToString_() + FunctionDeclarations_->ToString_() + ClassDeclarations_->ToString_() + GlobalDefinitions_->ToString_() + Definitions_->ToString_();
}

auto Main_(::System_::Console_::Console_ *const console_, ::System_::Console_::Arguments_ const *const args_) -> void
{
	console_->WriteLine_(string("Adamant Compiler v0.1.0"));
	::System_::Collections_::List_<string> *const sourceFilePaths_ = new ::System_::Collections_::List_<string>();
	::System_::Collections_::List_<string> *const resourceFilePaths_ = new ::System_::Collections_::List_<string>();
	string outputFilePath_ = string("");
	int argType_ = 0;
	for (string const arg_ : *(args_))
	{
		if (argType_ == 1)
		{
			resourceFilePaths_->Add_(arg_);
			argType_ = 0;
		}
		else if (argType_ == 2)
		{
			outputFilePath_ = arg_;
			argType_ = 0;
		}
		else
		{
			if (arg_ == string("-r"))
			{
				argType_ = 1;
			}
			else if (arg_ == string("-o"))
			{
				argType_ = 2;
			}
			else
			{
				sourceFilePaths_->Add_(arg_);
			}
		}
	}

	if (sourceFilePaths_->Length_() == 0 || outputFilePath_ == string(""))
	{
		console_->WriteLine_(string("Args: <Input File(s)> -o <OutputFile> -r <Resource File>"));
		return;
	}

	::System_::Collections_::List_<::Source_Text_ const *> *const resources_ = new ::System_::Collections_::List_<::Source_Text_ const *>();
	if (resourceFilePaths_->Length_() > 0)
	{
		console_->WriteLine_(string("Reading Resources:"));
		for (string const resourceFilePath_ : *(resourceFilePaths_))
		{
			console_->WriteLine_(string("  ") + resourceFilePath_);
			resources_->Add_(ReadSource_(resourceFilePath_));
		}
	}

	console_->WriteLine_(string("Compiling:"));
	::System_::Collections_::List_<::Source_Text_ const *> *const sources_ = new ::System_::Collections_::List_<::Source_Text_ const *>();
	for (string const sourceFilePath_ : *(sourceFilePaths_))
	{
		console_->WriteLine_(string("  ") + sourceFilePath_);
		sources_->Add_(ReadSource_(sourceFilePath_));
	}

	string const translated_ = Compile_(sources_, resources_);
	console_->Write_(string("Output: "));
	console_->WriteLine_(outputFilePath_);
	::System_::IO_::File_Writer_ *const outputFile_ = new ::System_::IO_::File_Writer_(outputFilePath_);
	outputFile_->Write_(translated_);
	outputFile_->Close_();
	console_->Write_(string("Outputting RuntimeLibrary to: "));
	string outputDirPath_ = outputFilePath_;
	int index_ = outputDirPath_->LastIndexOf_('/');
	if (index_ != -1)
	{
		outputDirPath_ = outputDirPath_->Substring_(0, index_ + 1);
	}

	index_ = outputDirPath_->LastIndexOf_('\\');
	if (index_ != -1)
	{
		outputDirPath_ = outputDirPath_->Substring_(0, index_ + 1);
	}

	console_->WriteLine_(outputDirPath_);
	::System_::IO_::File_Writer_ * resourceFile_ = new ::System_::IO_::File_Writer_(outputDirPath_ + string("RuntimeLibrary.h"));
	resourceFile_->Write_(resource_manager_->GetString_(string("RuntimeLibrary.h")));
	resourceFile_->Close_();
	resourceFile_ = new ::System_::IO_::File_Writer_(outputDirPath_ + string("RuntimeLibrary.cpp"));
	resourceFile_->Write_(resource_manager_->GetString_(string("RuntimeLibrary.cpp")));
	resourceFile_->Close_();
}

auto ReadSource_(string const path_) -> ::Source_Text_ const *
{
	::System_::IO_::File_Reader_ *const file_ = new ::System_::IO_::File_Reader_(path_);
	string const contents_ = file_->ReadToEndSync_();
	file_->Close_();
	string name_ = path_;
	int index_ = name_->LastIndexOf_('/');
	if (index_ != -1)
	{
		name_ = name_->Substring_(index_ + 1);
	}

	index_ = name_->LastIndexOf_('\\');
	if (index_ != -1)
	{
		name_ = name_->Substring_(index_ + 1);
	}

	return new ::Source_Text_(string("<default>"), name_, contents_);
}

::Source_Text_::Source_Text_(string const package_, string const name_, string const text_)
{
	Package_ = package_;
	Name_ = name_;
	Text_ = text_;
}

auto FormatError_(string const message_) -> string
{
	return string("<$ ") + message_ + string(" $>");
}

::Source_File_Builder_::Source_File_Builder_()
{
	code_ = new ::System_::Text_::String_Builder_();
	indent_ = new ::System_::Text_::String_Builder_();
	firstElement_ = true;
	afterBlock_ = true;
}

auto ::Source_File_Builder_::Error_(string const message_) -> void
{
	code_->Append_(FormatError_(message_));
}

auto ::Source_File_Builder_::BeginLine_(string const value_) -> void
{
	code_->Append_(indent_);
	code_->Append_(value_);
	firstElement_ = afterBlock_ = false;
}

auto ::Source_File_Builder_::Write_(string const value_) -> void
{
	code_->Append_(value_);
	firstElement_ = afterBlock_ = false;
}

auto ::Source_File_Builder_::EndLine_(string const value_) -> void
{
	code_->Append_(value_);
	code_->AppendLine_();
	firstElement_ = afterBlock_ = false;
}

auto ::Source_File_Builder_::WriteLine_(string const value_) -> void
{
	code_->Append_(indent_);
	code_->Append_(value_);
	code_->AppendLine_();
	firstElement_ = afterBlock_ = false;
}

auto ::Source_File_Builder_::BlankLine_() -> void
{
	code_->AppendLine_();
	firstElement_ = true;
	afterBlock_ = false;
}

auto ::Source_File_Builder_::ElementSeparatorLine_() -> void
{
	if (!firstElement_)
	{
		code_->AppendLine_();
		firstElement_ = true;
		afterBlock_ = false;
	}
}

auto ::Source_File_Builder_::StatementSeparatorLine_() -> void
{
	if (afterBlock_)
	{
		code_->AppendLine_();
		firstElement_ = true;
		afterBlock_ = false;
	}
}

auto ::Source_File_Builder_::BeginBlock_() -> void
{
	WriteLine_(string("{"));
	indent_->Append_(string("\t"));
	firstElement_ = afterBlock_ = false;
}

auto ::Source_File_Builder_::EndBlock_() -> void
{
	indent_->Remove_(0, 1);
	WriteLine_(string("}"));
	afterBlock_ = true;
}

auto ::Source_File_Builder_::EndBlockWithSemicolon_() -> void
{
	indent_->Remove_(0, 1);
	WriteLine_(string("};"));
}

auto ::Source_File_Builder_::ToString_() const -> string
{
	return code_->ToString_();
}

auto ::Lexer_::Analyze_(::Source_Text_ const *const source_) const -> ::Token_Stream_ *
{
	return new ::Token_Stream_(source_);
}

::Parser_::Parser_()
{
}

auto ::Parser_::Parse_(::Token_Stream_ const *const tokenStream_) const -> ::Syntax_Node_ const *
{
	return ::None;
}

::Syntax_Node_::Syntax_Node_(int const type_, ::Source_Text_ const *const source_, unsigned int const start_, unsigned int const length_)
{
	Type_ = type_;
	Source_ = source_;
	Start_ = start_;
	Length_ = length_;
	Children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
}

::Syntax_Node_::Syntax_Node_(int const type_, ::Syntax_Node_ const *const child_)
{
	Type_ = type_;
	Source_ = child_->Source_;
	Start_ = child_->Start_;
	Length_ = child_->Length_;
	::System_::Collections_::List_<::Syntax_Node_ const *> *const children_ = new ::System_::Collections_::List_<::Syntax_Node_ const *>();
	children_->Add_(child_);
	Children_ = children_;
}

::Syntax_Node_::Syntax_Node_(int const type_, ::System_::Collections_::List_<::Syntax_Node_ const *> const *const children_)
{
	Type_ = type_;
	Source_ = children_->Get_(0)->Source_;
	Start_ = children_->Get_(0)->Start_;
	::Syntax_Node_ const *const lastChild_ = children_->Get_(children_->Length_() - 1);
	Length_ = lastChild_->Start_ - Start_ + lastChild_->Length_;
	Children_ = children_;
}

auto ::Syntax_Node_::GetText_() const -> string
{
	return Source_->Text_->Substring_(Start_, Length_);
}

auto ::Syntax_Node_::FirstChildOfType_(int const type_) const -> ::Syntax_Node_ const *
{
	for (::Syntax_Node_ const *const child_ : *(Children_))
	{
		if (child_->Type_ == type_)
		{
			return child_;
		}
	}

	return ::None;
}

auto ::Syntax_Node_::HasChildOfType_(int const type_) const -> bool
{
	for (::Syntax_Node_ const *const child_ : *(Children_))
	{
		if (child_->Type_ == type_)
		{
			return true;
		}
	}

	return false;
}

::Token_Stream_::Token_Stream_(::Source_Text_ const *const source_)
{
	Source_ = source_;
	position_ = 0;
}

auto ::Token_Stream_::GetNextToken_() -> ::Syntax_Node_ const *
{
	unsigned int end_ = -1;
	while (position_ < Source_->Text_->Length_)
	{
		char const curChar_ = Source_->Text_[position_];
		if (curChar_ == ' ' || curChar_ == '\t' || curChar_ == '\n' || curChar_ == '\r')
		{
			position_ += 1;
			continue;
		}
		else if (curChar_ == '{')
		{
			return NewOperator_(LeftBrace_);
		}
		else if (curChar_ == '}')
		{
			return NewOperator_(RightBrace_);
		}
		else if (curChar_ == '(')
		{
			return NewOperator_(LeftParen_);
		}
		else if (curChar_ == ')')
		{
			return NewOperator_(RightParen_);
		}
		else if (curChar_ == ';')
		{
			return NewOperator_(Semicolon_);
		}
		else if (curChar_ == ',')
		{
			return NewOperator_(Comma_);
		}
		else if (curChar_ == '.')
		{
			return NewOperator_(Dot_);
		}
		else if (curChar_ == ':')
		{
			return NewOperator_(Colon_);
		}
		else if (curChar_ == '[')
		{
			return NewOperator_(LeftBracket_);
		}
		else if (curChar_ == ']')
		{
			return NewOperator_(RightBracket_);
		}
		else if (curChar_ == '?')
		{
			return NewOperator_(Question_);
		}
		else if (curChar_ == '=')
		{
			if (position_ + 1 < Source_->Text_->Length_ && Source_->Text_[position_ + 1] == '=')
			{
				return NewOperator_(Equal_, 2);
			}

			return NewOperator_(Assign_);
		}
		else if (curChar_ == '+')
		{
			if (position_ + 1 < Source_->Text_->Length_ && Source_->Text_[position_ + 1] == '=')
			{
				return NewOperator_(AddAssign_, 2);
			}

			return NewOperator_(Add_);
		}
		else if (curChar_ == '-')
		{
			if (position_ + 1 < Source_->Text_->Length_ && Source_->Text_[position_ + 1] == '>')
			{
				return NewOperator_(Arrow_, 2);
			}

			if (position_ + 1 < Source_->Text_->Length_ && Source_->Text_[position_ + 1] == '=')
			{
				return NewOperator_(SubAssign_, 2);
			}

			return NewOperator_(Sub_);
		}
		else if (curChar_ == '/')
		{
			if (position_ + 1 < Source_->Text_->Length_ && Source_->Text_[position_ + 1] == '/')
			{
				while (position_ < Source_->Text_->Length_ && Source_->Text_[position_] != '\r' && Source_->Text_[position_] != '\n')
				{
					position_ += 1;
				}

				continue;
			}

			if (position_ + 1 < Source_->Text_->Length_ && Source_->Text_[position_ + 1] == '*')
			{
				position_ += 2;
				bool lastCharStar_ = false;
				while (position_ < Source_->Text_->Length_ && !(lastCharStar_ && Source_->Text_[position_] == '/'))
				{
					lastCharStar_ = Source_->Text_[position_] == '*';
					position_ += 1;
				}

				position_ += 1;
				continue;
			}

			return NewOperator_(Slash_);
		}
		else if (curChar_ == '<')
		{
			if (position_ + 1 < Source_->Text_->Length_ && Source_->Text_[position_ + 1] == '>')
			{
				return NewOperator_(NotEqual_, 2);
			}

			if (position_ + 1 < Source_->Text_->Length_ && Source_->Text_[position_ + 1] == '=')
			{
				return NewOperator_(LessThanOrEqual_, 2);
			}

			return NewOperator_(LessThan_);
		}
		else if (curChar_ == '>')
		{
			if (position_ + 1 < Source_->Text_->Length_ && Source_->Text_[position_ + 1] == '=')
			{
				return NewOperator_(GreaterThanOrEqual_, 2);
			}

			return NewOperator_(GreaterThan_);
		}
		else if (curChar_ == '"')
		{
			end_ = position_ + 1;
			bool escaped_ = false;
			while (end_ < Source_->Text_->Length_ && (Source_->Text_[end_] != '"' || escaped_))
			{
				escaped_ = Source_->Text_[end_] == '\\' && !escaped_;
				end_ += 1;
			}

			end_ += 1;
			return NewToken_(StringLiteral_, end_);
		}
		else if (curChar_ == '\'')
		{
			end_ = position_ + 1;
			bool escaped_ = false;
			while (end_ < Source_->Text_->Length_ && (Source_->Text_[end_] != '\'' || escaped_))
			{
				escaped_ = Source_->Text_[end_] == '\\' && !escaped_;
				end_ += 1;
			}

			end_ += 1;
			return NewToken_(CodePointLiteral_, end_);
		}
		else
		{
			if (IsIdentifierChar_(curChar_))
			{
				end_ = position_ + 1;
				while (IsIdentifierChar_(Source_->Text_[end_]))
				{
					end_ += 1;
				}

				return NewIdentifierOrKeyword_(end_);
			}

			if ((IsNumberChar_(curChar_)))
			{
				end_ = position_ + 1;
				while (IsNumberChar_(Source_->Text_[end_]))
				{
					end_ += 1;
				}

				return NewToken_(Number_, end_);
			}

			return NewToken_(Error_, position_ + 1);
		}
	}

	return ::None;
}

auto ::Token_Stream_::NewIdentifierOrKeyword_(unsigned int const end_) -> ::Syntax_Node_ const *
{
	unsigned int const length_ = end_ - position_;
	string const value_ = Source_->Text_->Substring_(position_, length_);
	int type_;
	if (value_ == string("new"))
	{
		type_ = NewKeyword_;
	}
	else if (value_ == string("not"))
	{
		type_ = NotOperator_;
	}
	else if (value_ == string("null"))
	{
		type_ = NullKeyword_;
	}
	else if (value_ == string("self"))
	{
		type_ = SelfKeyword_;
	}
	else if (value_ == string("true"))
	{
		type_ = TrueKeyword_;
	}
	else if (value_ == string("false"))
	{
		type_ = FalseKeyword_;
	}
	else if (value_ == string("mut"))
	{
		type_ = MutableKeyword_;
	}
	else if (value_ == string("code_point"))
	{
		type_ = CodePoint_;
	}
	else if (value_ == string("string"))
	{
		type_ = String_;
	}
	else if (value_ == string("int"))
	{
		type_ = Int_;
	}
	else if (value_ == string("bool"))
	{
		type_ = Bool_;
	}
	else if (value_ == string("void"))
	{
		type_ = Void_;
	}
	else if (value_ == string("uint"))
	{
		type_ = UnsignedInt_;
	}
	else if (value_ == string("var"))
	{
		type_ = VarKeyword_;
	}
	else if (value_ == string("and"))
	{
		type_ = AndKeyword_;
	}
	else if (value_ == string("or"))
	{
		type_ = OrKeyword_;
	}
	else if (value_ == string("return"))
	{
		type_ = ReturnKeyword_;
	}
	else if (value_ == string("loop"))
	{
		type_ = LoopKeyword_;
	}
	else if (value_ == string("while"))
	{
		type_ = WhileKeyword_;
	}
	else if (value_ == string("for"))
	{
		type_ = ForKeyword_;
	}
	else if (value_ == string("let"))
	{
		type_ = LetKeyword_;
	}
	else if (value_ == string("in"))
	{
		type_ = InKeyword_;
	}
	else if (value_ == string("do"))
	{
		type_ = DoKeyword_;
	}
	else if (value_ == string("if"))
	{
		type_ = IfKeyword_;
	}
	else if (value_ == string("else"))
	{
		type_ = ElseKeyword_;
	}
	else if (value_ == string("break"))
	{
		type_ = BreakKeyword_;
	}
	else if (value_ == string("continue"))
	{
		type_ = ContinueKeyword_;
	}
	else if (value_ == string("private"))
	{
		type_ = PrivateKeyword_;
	}
	else if (value_ == string("protected"))
	{
		type_ = ProtectedKeyword_;
	}
	else if (value_ == string("public"))
	{
		type_ = PublicKeyword_;
	}
	else if (value_ == string("internal"))
	{
		type_ = InternalKeyword_;
	}
	else if (value_ == string("class"))
	{
		type_ = ClassKeyword_;
	}
	else if (value_ == string("enum"))
	{
		type_ = EnumKeyword_;
	}
	else if (value_ == string("struct"))
	{
		type_ = StructKeyword_;
	}
	else
	{
		type_ = Identifier_;
	}

	return NewToken_(type_, end_);
}

auto ::Token_Stream_::NewOperator_(int const type_) -> ::Syntax_Node_ const *
{
	return NewToken_(type_, position_ + 1);
}

auto ::Token_Stream_::NewOperator_(int const type_, unsigned int const length_) -> ::Syntax_Node_ const *
{
	return NewToken_(type_, position_ + length_);
}

auto ::Token_Stream_::NewToken_(int const type_, unsigned int const end_) -> ::Syntax_Node_ const *
{
	::Syntax_Node_ const *const token_ = new ::Syntax_Node_(type_, Source_, position_, end_ - position_);
	position_ = end_;
	return token_;
}

auto ::Token_Stream_::IsIdentifierChar_(char const c_) -> bool
{
	return (c_ >= 'a' && c_ <= 'z') || (c_ >= 'A' && c_ <= 'Z') || c_ == '_';
}

auto ::Token_Stream_::IsNumberChar_(char const c_) -> bool
{
	return c_ >= '0' && c_ <= '9';
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	resource_manager_->AddResource(::string("RuntimeLibrary.cpp"), ::string("#include \"RuntimeLibrary.h\"\n#include <map>\n\nstring::string()\n	: Length_(0), Buffer(0)\n{\n}\n\nstring::string(char c, int repeat)\n	: Length_(repeat)\n{\n	char* buffer = new char[repeat];\n	for (int i = 0; i < repeat; i++)\n		buffer[i] = c;\n\n	Buffer = buffer;\n}\n\nstring::string(const char* s)\n	: Length_(std::strlen(s)), Buffer(s)\n{\n}\n\nstring::string(int length, const char* s)\n	: Length_(length), Buffer(s)\n{\n}\n\nchar const * string::cstr() const\n{\n	auto buffer = new char[Length_ + 1];\n	std::memcpy(buffer, Buffer, Length_);\n	buffer[Length_] = 0;\n	return buffer;\n}\n\nstring string::Substring_(int start, int length) const\n{\n	return string(length, Buffer + start);\n}\n\nstring string::Replace_(string oldValue, string newValue) const\n{\n	string buffer = \"\";\n	int limit = Length_ - oldValue.Length_ + 1;\n	int lastIndex = 0;\n	for(int i=0; i < limit; i++)\n		if (Substring_(i, oldValue.Length_) == oldValue)\n		{\n			buffer = buffer + Substring_(lastIndex, i-lastIndex) + newValue;\n			i += oldValue.Length_; // skip over the value we just matched\n			lastIndex = i;\n			i--; // we need i-- to offset the i++ that is about to happen\n		}\n\n	buffer = buffer + Substring_(lastIndex, Length_ - lastIndex);\n	return buffer;\n}\n\nint string::LastIndexOf_(char c) const\n{\n	for(int i=Length_-1; i>=0; i--)\n		if(Buffer[i]==c)\n			return i;\n\n	return -1;\n}\n\nchar string::operator[] (const int index) const\n{\n	return Buffer[index];\n}\n\nstring string::operator+(const string& value) const\n{\n	int newLength = Length_ + value.Length_;\n	char* chars = new char[newLength];\n	size_t offset = sizeof(char)*Length_;\n	std::memcpy(chars, Buffer, offset);\n	std::memcpy(chars + offset, value.Buffer, value.Length_);\n	return string(newLength, chars);\n}\n\nstring string::operator+(const char& value) const\n{\n	int newLength = Length_ + 1;\n	char* chars = new char[newLength];\n	size_t offset = sizeof(char)*Length_;\n	std::memcpy(chars, Buffer, offset);\n	chars[Length_] = value;\n	return string(newLength, chars);\n}\n\nbool string::operator==(const string &other) const\n{\n	if (Length_ != other.Length_)\n		return false;\n\n	for (int i = 0; i < Length_; i++)\n		if (Buffer[i] != other.Buffer[i])\n			return false;\n\n	return true;\n}\n\nbool operator < (string const& lhs, string const& rhs)\n{\n    return std::strcmp(lhs.cstr(), rhs.cstr()) < 0;\n}\n\nstd::map<string, string> resourceValues;\n\nstring const & ResourceManager::GetString_(string resourceName)\n{\n	return resourceValues.at(resourceName);\n}\nvoid ResourceManager::AddResource(string name, string value)\n{\n	resourceValues.insert(std::make_pair(name, value));\n}\n\nResourceManager *const resource_manager_ = new ResourceManager();\n\nnamespace System_\n{\n	namespace Console_\n	{\n		void Console_::Write_(string value)\n		{\n			std::printf(\"%.*s\", value.Length_, value.Buffer);\n		}\n\n		void Console_::WriteLine_(string value)\n		{\n			std::printf(\"%.*s\\n\", value.Length_, value.Buffer);\n		}\n\n		void Console_::WriteLine_()\n		{\n			std::printf(\"\\n\");\n		}\n\n		Arguments_::Arguments_(int argc, char const *const * argv)\n			: Count_(argc-1)\n		{\n			args = new string[Count_];\n			for (int i = 0; i < Count_; i++)\n				args[i] = string(argv[i+1]);\n		}\n	}\n\n	namespace IO_\n	{\n		File_Reader_::File_Reader_(const string& fileName)\n		{\n			std::FILE* foo;\n			auto fname = fileName.cstr();\n			file = std::fopen(fname, \"rb\");\n			delete[] fname;\n		}\n\n		string File_Reader_::ReadToEndSync_()\n		{\n			std::fseek(file, 0, SEEK_END);\n			auto length = std::ftell(file);\n			std::fseek(file, 0, SEEK_SET);\n			auto buffer = new char[length];\n			length = std::fread(buffer, sizeof(char), length, file);\n			return string(length, buffer);\n		}\n\n		void File_Reader_::Close_()\n		{\n			std::fclose(file);\n		}\n\n		File_Writer_::File_Writer_(const string& fileName)\n		{\n			auto fname = fileName.cstr();\n			file = std::fopen(fname, \"wb\"); // TODO check error\n			delete[] fname;\n		}\n\n		void File_Writer_::Write_(const string& value)\n		{\n			std::fwrite(value.Buffer, sizeof(char), value.Length_, file);\n		}\n\n		void File_Writer_::Close_()\n		{\n			std::fclose(file);\n		}\n	}\n\n	namespace Text_\n	{\n		String_Builder_::String_Builder_(string const & value)\n			: buffer(value)\n		{\n		}\n\n		String_Builder_::String_Builder_()\n			: buffer(\"\")\n		{\n		}\n\n		void String_Builder_::Append_(string const & value)\n		{\n			buffer = buffer + value;\n		}\n\n		void String_Builder_::Append_(String_Builder_ const * value)\n		{\n			buffer = buffer + value->buffer;\n		}\n\n		void String_Builder_::AppendLine_(string const & value)\n		{\n			buffer = buffer + value + string(\"\\n\");\n		}\n\n		void String_Builder_::AppendLine_()\n		{\n			buffer = buffer + string(\"\\n\");\n		}\n\n		void String_Builder_::Remove_(int start, int length)\n		{\n			buffer = buffer.Substring_(0, start) + buffer.Substring_(start+length);\n		}\n\n		void String_Builder_::Remove_(int start)\n		{\n			String_Builder_::Remove_(start, buffer.Length_-start);\n		}\n	}\n}\n"));
	resource_manager_->AddResource(::string("RuntimeLibrary.h"), ::string("// On windows this disables warnings about using fopen_s instead of fopen\r\n// It must be defined before including the headers.  The includes have been moved\r\n// here to avoid leaking this into the program being compiled.  This required the\r\n// use of void* instead of FILE* in some places.\r\n#define _CRT_SECURE_NO_WARNINGS\r\n#include <cstring>\r\n#include <cstdio>\r\n\r\nstruct string\r\n{\r\npublic:\r\n	int Length_;\r\n	char const * Buffer;\r\n\r\n	string();\r\n	string(char c, int repeat);\r\n	string(char const * s);\r\n	string(int length, char const * s);\r\n	char const * cstr() const;\r\n	string Substring_(int start, int length) const;\r\n	string Substring_(int start) const { return Substring_(start, Length_-start); }\r\n	string Replace_(string oldValue, string newValue) const;\r\n	int LastIndexOf_(char c) const;\r\n	char operator[] (int const index) const;\r\n	string operator+(string const & value) const;\r\n	string operator+(char const & value) const;\r\n	string const * operator->() const { return this; }\r\n	string const & operator* () const { return *this; }\r\n	bool operator==(string const & other) const;\r\n	bool operator!=(string const & other) const { return !(*this == other); }\r\n	friend bool operator<(string const & lhs, string const & rhs);\r\n\r\n	typedef char const * const_iterator;\r\n	const_iterator begin() const { return &Buffer[0]; }\r\n	const_iterator end() const { return &Buffer[Length_]; }\r\n};\r\n\r\nclass ResourceManager\r\n{\r\npublic:\r\n	string const & GetString_(string resourceName);\r\n	void AddResource(string name, string value);\r\n};\r\n\r\nextern ResourceManager *const resource_manager_;\r\n\r\nclass NoneType\r\n{\r\npublic:\r\n	template<class T>\r\n	operator T*() const { return static_cast<T*>(0); }\r\n};\r\nstatic const NoneType None = NoneType();\r\n\r\ntemplate<typename T>\r\nstruct Maybe\r\n{\r\nprivate:\r\n	T data;\r\n	bool hasValue;\r\n\r\npublic:\r\n	Maybe(T const & value) : data(value), hasValue(true) {}\r\n	Maybe(::NoneType const & none) : hasValue(false) {}\r\n	T& operator->() { return data; }\r\n	T const & operator->() const\r\n	{\r\n		if(!hasValue) throw \"Access to null Maybe value\";\r\n		return data;\r\n	}\r\n	T  & operator* ()\r\n	{\r\n		if(!hasValue) throw \"Access to null Maybe value\";\r\n		return data;\r\n	}\r\n	T const & operator* () const\r\n	{\r\n		if(!hasValue) throw \"Access to null Maybe value\";\r\n		return data;\r\n	}\r\n	bool operator==(T const & other) const\r\n	{\r\n		return hasValue && data == other;\r\n	}\r\n	bool operator!=(T const & other) const\r\n	{\r\n		return hasValue && data != other;\r\n	}\r\n};\r\n\r\nnamespace System_\r\n{\r\n	namespace Collections_\r\n	{\r\n		template<typename T>\r\n		class List_\r\n		{\r\n		private:\r\n			T* values;\r\n			int length;\r\n			int capacity;\r\n\r\n		public:\r\n			typedef T const * const_iterator;\r\n\r\n			List_() : values(0), length(0), capacity(0) { }\r\n			void Add_(T value);\r\n			int Length_() const { return length; }\r\n			const_iterator begin() const { return values; }\r\n			const_iterator end() const { return &values[length]; }\r\n			T const & Get_(int const index) const { return values[index]; }\r\n		};\r\n\r\n		template<typename T>\r\n		void List_<T>::Add_(T value)\r\n		{\r\n			if(length >= capacity)\r\n			{\r\n				int newCapacity = capacity == 0 ? 16 : capacity * 2;\r\n				T* newValues = new T[newCapacity];\r\n				std::memcpy(newValues, values, length * sizeof(T));\r\n				values = newValues;\r\n				capacity = newCapacity;\r\n			}\r\n			values[length] = value;\r\n			length++;\r\n		}\r\n	}\r\n\r\n	namespace Console_\r\n	{\r\n		class Console_\r\n		{\r\n		public:\r\n			void Write_(string value);\r\n			void WriteLine_(string value);\r\n			void WriteLine_();\r\n		};\r\n\r\n		class Arguments_\r\n		{\r\n		private:\r\n			string* args;\r\n		public:\r\n			typedef string const * const_iterator;\r\n			const int Count_;\r\n\r\n			Arguments_(int argc, char const *const * argv);\r\n			const_iterator begin() const { return &args[0]; }\r\n			const_iterator end() const { return &args[Count_]; }\r\n			string const & Get_(int const index) const { return args[index]; }\r\n		};\r\n	}\r\n\r\n	namespace IO_\r\n	{\r\n		class File_Reader_\r\n		{\r\n		private:\r\n			std::FILE* file;\r\n\r\n		public:\r\n			File_Reader_(const string& fileName);\r\n			string ReadToEndSync_();\r\n			void Close_();\r\n		};\r\n\r\n		class File_Writer_\r\n		{\r\n		private:\r\n			std::FILE* file;\r\n\r\n		public:\r\n			File_Writer_(const string& fileName);\r\n			void Write_(const string& value);\r\n			void Close_();\r\n		};\r\n	}\r\n\r\n	namespace Text_\r\n	{\r\n		class String_Builder_\r\n		{\r\n		private:\r\n			string buffer;\r\n		public:\r\n			String_Builder_();\r\n			String_Builder_(string const & value);\r\n			void Append_(string const & value);\r\n			void Append_(String_Builder_ const * value);\r\n			void AppendLine_(string const& value);\r\n			void AppendLine_();\r\n			void Remove_(int start, int length);\r\n			void Remove_(int start);\r\n			string ToString_() const { return buffer; }\r\n		};\r\n	}\r\n}\r\n"));

	Main_(new ::System_::Console_::Console_(), new ::System_::Console_::Arguments_(argc, argv));
	return 0;
}
