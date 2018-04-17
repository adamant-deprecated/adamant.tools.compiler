#include "RuntimeLibrary.h"

// Type Declarations
class Line_Info_;
class Location_;
class Source_Text_;
class Text_Line_;
class Text_Position_;
class Text_Span_;
class Source_File_Builder_;
class Compilation_Unit_;
class Package_;
struct Package_Reference_;
class Primitives_Package_Builder_;
class Runtime_Library_Package_Builder_;
class Semantic_Analyzer_;
class Semantic_Node_;
class Semantic_Tree_Builder_;
class Symbol_Builder_;
class Compilation_Unit_Parser_;
class Lexer_;
class Parser_;
class Syntax_Node_;
class Syntax_Tree_;
class Token_Stream_;
class Token_Type_;
class Diagnostic_;
class Diagnostic_Info_;
class Emitter_;
class Name_;
class Package_Name_;
class Symbol_;
class Type_;
class Name_Subtable_;
class Name_Table_;
class Name_Table_Builder_;

// Function Declarations
auto compile_(::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const sources_) -> ::Package_ const *_Nonnull;
auto write_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_) -> void;
auto has_errors_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_) -> p_bool;
auto Main_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Console_::Arguments_ const *_Nonnull const args_) -> p_int;
auto read_source_(p_string const path_) -> ::Source_Text_ const *_Nonnull;
auto run_unit_tests_(::System_::Console_::Console_ *_Nonnull const console_) -> void;
auto unit_test_Text_Position_() -> void;
auto Text_Position_retains_given_offeset_line_and_column_() -> void;
auto format_error_(p_string const message_) -> p_string;
auto unit_test_Primitives_Package_Builder_() -> void;
auto Package_name_is_dollar_primitives_() -> void;
auto Package_has_no_references_or_compilation_units_() -> void;
auto Package_symbol_has_package_name_() -> void;
auto Package_symbol_has_children_() -> void;
auto Package_contains_the_string_type_() -> void;
auto Package_contains_optional_type_() -> void;
auto unit_test_Runtime_Library_Package_Builder_() -> void;
auto Runtime_Library_Package_contains_System_package_() -> void;
auto System_namespace_contains_Console_namespace_() -> void;
auto Console_namespace_contains_Console_class_() -> void;
auto System_namespace_contains_Collections_namespace_() -> void;
auto Collections_namespace_contains_List_class_() -> void;
auto new_syntax_node_missing_(p_int const type_, ::Source_Text_ const *_Nonnull const source_, p_uint const start_) -> ::Syntax_Node_ const *_Nonnull;
auto new_Syntax_Node_Skipped_(::Syntax_Node_ const *_Nonnull const skipped_node_) -> ::Syntax_Node_ const *_Nonnull;
auto new_Syntax_Node_Skipped_(::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull const skipped_nodes_) -> ::Syntax_Node_ const *_Nonnull;
auto unit_test_Name_() -> void;
auto name_with_unspecified_package_names_name_with_package_() -> void;
auto name_with_unspecified_package_names_itself_() -> void;
auto unit_test_Symbol_() -> void;
auto Package_symbol_children_can_be_found_by_name_and_kind_() -> void;
auto unit_test_Name_Subtable_() -> void;
auto global_namespace_contains_added_name_() -> void;
auto namespace_contains_added_name_() -> void;
auto unit_test_Name_Table_Builder_() -> void;
auto table_contains_referenced_child_names_() -> void;
auto can_get_root_namespace_from_name_() -> void;
auto can_get_Console_class_from_name_without_package_() -> void;
auto can_get_Optional_class_from_name_with_package_() -> void;

// Class Declarations

class Line_Info_
{
public:
	p_bool op_equal(Line_Info_ const * other) const { return this == other; }
	p_bool op_not_equal(Line_Info_ const * other) const { return this != other; }
private:
	::Source_Text_ const *_Nonnull source_;
	::System_::Collections_::List_<p_int> const *_Nonnull lineStarts_;
public:
	auto construct(::Source_Text_ const *_Nonnull const source_, ::System_::Collections_::List_<p_int> const *_Nonnull const lineStarts_) -> ::Line_Info_*;
	auto Count_() const -> p_int;
	auto get_(p_int const lineNumber_) const -> ::Text_Line_ const *_Nonnull;
	auto LineNumber_(p_int const offset_) const -> p_int;
};

class Location_
{
public:
	p_bool op_equal(Location_ const * other) const { return this == other; }
	p_bool op_not_equal(Location_ const * other) const { return this != other; }
	auto construct() -> ::Location_* { return this; }
};

class Source_Text_
{
public:
	p_bool op_equal(Source_Text_ const * other) const { return this == other; }
	p_bool op_not_equal(Source_Text_ const * other) const { return this != other; }
	p_string Package_;
	p_string Path_;
	p_string name_;
	p_string Text_;
	::Line_Info_ const *_Nonnull Lines_;
	auto construct(p_string const package_, p_string const path_, p_string const text_) -> ::Source_Text_*;
private:
	auto LineStarts_() const -> ::System_::Collections_::List_<p_int> const *_Nonnull;
public:
	auto ByteLength_() const -> p_int;
	auto PositionOfStart_(::Text_Span_ const *_Nonnull const span_) const -> ::Text_Position_ const *_Nonnull;
};

class Text_Line_
{
public:
	p_bool op_equal(Text_Line_ const * other) const { return this == other; }
	p_bool op_not_equal(Text_Line_ const * other) const { return this != other; }
	::Source_Text_ const *_Nonnull source_;
	p_int start_;
	p_int byte_length_;
	auto construct(::Source_Text_ const *_Nonnull const source_, p_int const start_, p_int const length_) -> ::Text_Line_*;
	auto construct_spanning(::Source_Text_ const *_Nonnull const source_, p_int const start_, p_int const end_) -> ::Text_Line_*;
	auto End_() const -> p_int;
};

class Text_Position_
{
public:
	p_bool op_equal(Text_Position_ const * other) const { return this == other; }
	p_bool op_not_equal(Text_Position_ const * other) const { return this != other; }
	p_int Offset_;
	p_int Line_;
	p_int Column_;
	auto construct(p_int const offset_, p_int const line_, p_int const column_) -> ::Text_Position_*;
};

class Text_Span_
{
public:
	p_bool op_equal(Text_Span_ const * other) const { return this == other; }
	p_bool op_not_equal(Text_Span_ const * other) const { return this != other; }
	p_int start_;
	p_int byte_length_;
	auto construct(p_int const start_, p_int const length_) -> ::Text_Span_*;
	auto End_() const -> p_int;
};

class Source_File_Builder_
{
public:
	p_bool op_equal(Source_File_Builder_ const * other) const { return this == other; }
	p_bool op_not_equal(Source_File_Builder_ const * other) const { return this != other; }
private:
	::System_::Text_::String_Builder_ *_Nonnull code_;
	::System_::Text_::String_Builder_ *_Nonnull indent_;
	p_bool firstElement_;
	p_bool afterBlock_;
public:
	auto construct() -> ::Source_File_Builder_*;
	auto Error_(p_string const message_) -> void;
	auto BeginLine_(p_string const value_) -> void;
	auto Write_(p_string const value_) -> void;
	auto EndLine_(p_string const value_) -> void;
	auto WriteLine_(p_string const value_) -> void;
	auto BlankLine_() -> void;
	auto ElementSeparatorLine_() -> void;
	auto StatementSeparatorLine_() -> void;
	auto BeginBlock_() -> void;
	auto EndBlock_() -> void;
	auto EndBlockWithSemicolon_() -> void;
	auto ToString_() const -> p_string;
};

class Compilation_Unit_
{
public:
	p_bool op_equal(Compilation_Unit_ const * other) const { return this == other; }
	p_bool op_not_equal(Compilation_Unit_ const * other) const { return this != other; }
	::Syntax_Node_ const *_Nonnull syntax_;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull declarations_;
	auto construct(::Syntax_Node_ const *_Nonnull const syntax_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_) -> ::Compilation_Unit_*;
	auto collect_diagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void;
};

class Package_
{
public:
	p_bool op_equal(Package_ const * other) const { return this == other; }
	p_bool op_not_equal(Package_ const * other) const { return this != other; }
	::Package_Name_ const *_Nonnull name_;
	::System_::Collections_::List_<::Package_Reference_> const *_Nonnull references_;
	::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull> const *_Nonnull compilation_units_;
	::Symbol_ const *_Nonnull symbol_;
	auto construct(::Package_Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Package_Reference_> const *_Nonnull const references_, ::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull> const *_Nonnull const compilation_units_, ::Symbol_ const *_Nonnull const symbol_) -> ::Package_*;
	auto all_diagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull;
};

struct Package_Reference_ final
{
public:
	Package_Reference_ * operator->() { return this; }
	Package_Reference_ const * operator->() const { return this; }
	Package_Reference_ & operator* () { return *this; }
	Package_Reference_ const & operator* () const { return *this; }
	p_string name_;
	::Package_ const *_Nonnull package_;
	static auto construct(::Package_ const *_Nonnull const package_) -> ::Package_Reference_;
	static auto construct(p_string const name_, ::Package_ const *_Nonnull const package_) -> ::Package_Reference_;
};

class Primitives_Package_Builder_
{
public:
	p_bool op_equal(Primitives_Package_Builder_ const * other) const { return this == other; }
	p_bool op_not_equal(Primitives_Package_Builder_ const * other) const { return this != other; }
	auto build_() const -> ::Package_ const *_Nonnull;
private:
	auto build_primitive_symbols_(::Package_Name_ const *_Nonnull const package_name_) const -> ::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull;
	static auto build_adamant_language_namespace_(::Name_ const *_Nonnull const global_namespace_) -> ::Symbol_ const *_Nonnull;
	static auto build_optional_(::Name_ const *_Nonnull const language_namespace_) -> ::Symbol_ const *_Nonnull;
	static auto build_primitive_(p_string const name_, ::Name_ const *_Nonnull const namespace_) -> ::Symbol_ const *_Nonnull;
	static auto build_fixed_point_primitives_(::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_, p_int const bits_, ::Name_ const *_Nonnull const namespace_) -> void;
public:
	auto construct() -> ::Primitives_Package_Builder_* { return this; }
};

class Runtime_Library_Package_Builder_
{
public:
	p_bool op_equal(Runtime_Library_Package_Builder_ const * other) const { return this == other; }
	p_bool op_not_equal(Runtime_Library_Package_Builder_ const * other) const { return this != other; }
	auto build_() const -> ::Package_ const *_Nonnull;
private:
	auto build_symbols_(::Package_Name_ const *_Nonnull const package_name_) const -> ::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull;
	static auto build_function_(::Name_ const *_Nonnull const name_) -> ::Symbol_ const *_Nonnull;
	static auto build_namespace_(::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_) -> ::Symbol_ const *_Nonnull;
	static auto build_class_(::Name_ const *_Nonnull const namespace_, p_string const class_name_) -> ::Symbol_ const *_Nonnull;
	static auto build_generic_class_(::Name_ const *_Nonnull const namespace_, p_string const class_name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_) -> ::Symbol_ const *_Nonnull;
public:
	auto construct() -> ::Runtime_Library_Package_Builder_* { return this; }
};

class Semantic_Analyzer_
{
public:
	p_bool op_equal(Semantic_Analyzer_ const * other) const { return this == other; }
	p_bool op_not_equal(Semantic_Analyzer_ const * other) const { return this != other; }
	static auto analyze_(::Syntax_Node_ const *_Nonnull const package_syntax_) -> ::Package_ const *_Nonnull;
	auto construct() -> ::Semantic_Analyzer_* { return this; }
};

class Semantic_Node_
{
public:
	p_bool op_equal(Semantic_Node_ const * other) const { return this == other; }
	p_bool op_not_equal(Semantic_Node_ const * other) const { return this != other; }
	::Syntax_Node_ const *_Nonnull syntax_;
	p_int kind_;
	p_bool is_missing_;
	::Source_Text_ const *_Nonnull source_;
	p_uint start_;
	p_uint byte_length_;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull children_;
private:
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull node_diagnostics_;
public:
	::Type_ const *_Nullable of_type_;
	::Type_ const *_Nullable converted_type_;
	::Type_ const *_Nullable declares_type_;
	::Type_ const *_Nullable referenced_type_;
	auto construct_token(::Syntax_Node_ const *_Nonnull const syntax_) -> ::Semantic_Node_*;
	auto construct_concrete(::Syntax_Node_ const *_Nonnull const syntax_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const children_) -> ::Semantic_Node_*;
	auto construct_of_type(::Type_ const *_Nonnull const of_type_, ::Syntax_Node_ const *_Nonnull const syntax_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const children_) -> ::Semantic_Node_*;
	auto construct_referencing_type(::Type_ const *_Nonnull const type_, ::Syntax_Node_ const *_Nonnull const syntax_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const children_) -> ::Semantic_Node_*;
	auto get_text_span_() const -> ::Text_Span_ const *_Nonnull;
	auto get_text_() const -> p_string;
	auto first_child_(p_int const kind_) const -> ::Semantic_Node_ const *_Nullable;
	auto children_of_kind_(p_int const kind_) const -> ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull;
	auto members_() const -> ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull;
	auto statements_() const -> ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull;
	auto parameters_() const -> ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull;
	auto access_modifier_() const -> ::Semantic_Node_ const *_Nullable;
	auto has_child_(p_int const kind_) const -> p_bool;
	auto add_(::Diagnostic_ const *_Nonnull const diagnostic_) -> void;
	auto diagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull;
public:
	auto collect_diagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void;
};

class Semantic_Tree_Builder_
{
public:
	p_bool op_equal(Semantic_Tree_Builder_ const * other) const { return this == other; }
	p_bool op_not_equal(Semantic_Tree_Builder_ const * other) const { return this != other; }
private:
	::Name_ const *_Nonnull optional_type_name_;
public:
	auto construct() -> ::Semantic_Tree_Builder_*;
	auto build_(::Syntax_Node_ const *_Nonnull const package_syntax_, ::Name_Table_ const *_Nonnull const name_table_) const -> ::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull> const *_Nonnull;
private:
	auto build_compilation_unit_(::Syntax_Node_ const *_Nonnull const compilation_unit_syntax_, ::Name_Table_ const *_Nonnull const name_table_) const -> ::Compilation_Unit_ const *_Nonnull;
	auto build_(::Syntax_Node_ const *_Nonnull const syntax_, ::Name_Table_ const *_Nonnull const name_table_, ::Name_Subtable_ const *_Nonnull const scope_) const -> ::Semantic_Node_ const *_Nonnull;
	auto build_parameters_(::Syntax_Node_ const *_Nonnull const parameters_syntax_, ::Name_Table_ const *_Nonnull const name_table_, ::Name_Subtable_ const *_Nonnull const scope_) const -> ::Semantic_Node_ *_Nonnull;
	auto build_type_name_(::Syntax_Node_ const *_Nonnull const syntax_, ::Name_Table_ const *_Nonnull const name_table_, ::Name_Subtable_ const *_Nonnull const scope_) const -> ::Semantic_Node_ *_Nonnull;
	auto build_type_arguments_(::Syntax_Node_ const *_Nonnull const syntax_, ::Name_Table_ const *_Nonnull const name_table_, ::Name_Subtable_ const *_Nonnull const scope_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const children_) const -> ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull;
	auto build_constructor_name_(::Syntax_Node_ const *_Nonnull const syntax_, ::Name_Table_ const *_Nonnull const name_table_, ::Name_Subtable_ const *_Nonnull const scope_) const -> ::Semantic_Node_ const *_Nonnull;
	static auto add_resolution_error_(::Semantic_Node_ *_Nonnull const node_) -> void;
	static auto add_resolution_error_(::Semantic_Node_ *_Nonnull const node_, ::Semantic_Node_ const *_Nonnull const qualifier_) -> void;
	static auto add_could_not_determine_type_error_(::Semantic_Node_ *_Nonnull const node_) -> void;
};

class Symbol_Builder_
{
public:
	p_bool op_equal(Symbol_Builder_ const * other) const { return this == other; }
	p_bool op_not_equal(Symbol_Builder_ const * other) const { return this != other; }
	static auto build_(::Package_Name_ const *_Nonnull const package_name_, ::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull> const *_Nonnull const compilation_units_) -> ::Symbol_ const *_Nonnull;
	auto construct() -> ::Symbol_Builder_* { return this; }
};

class Compilation_Unit_Parser_
{
public:
	p_bool op_equal(Compilation_Unit_Parser_ const * other) const { return this == other; }
	p_bool op_not_equal(Compilation_Unit_Parser_ const * other) const { return this != other; }
private:
	::Token_Stream_ *_Nonnull tokenStream_;
	::Syntax_Node_ const *_Nullable token_;
	::Syntax_Node_ const *_Nullable compilationUnit_;
public:
	auto construct(::Token_Stream_ *_Nonnull const tokenStream_) -> ::Compilation_Unit_Parser_*;
	auto Parse_() -> ::Syntax_Node_ const *_Nonnull;
private:
	auto AcceptToken_() -> ::Syntax_Node_ const *_Nullable;
	auto ExpectToken_(p_int const tokenType_) -> ::Syntax_Node_ const *_Nonnull;
	auto ParseTypeName_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseNonOptionalType_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseType_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseAtom_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseCallArguments_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseExpression_(p_int const minPrecedence_) -> ::Syntax_Node_ const *_Nonnull;
	auto ParseExpression_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseStatement_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseIfStatement_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseVariableDeclaration_(p_bool const allowInitializer_) -> ::Syntax_Node_ const *_Nonnull;
	auto ParseBlock_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseParameterList_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseMemberDeclaration_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseDeclaration_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseCompilationUnit_() -> ::Syntax_Node_ const *_Nonnull;
};

class Lexer_
{
public:
	p_bool op_equal(Lexer_ const * other) const { return this == other; }
	p_bool op_not_equal(Lexer_ const * other) const { return this != other; }
	auto analyze_(::Source_Text_ const *_Nonnull const source_) const -> ::Token_Stream_ *_Nonnull;
	auto construct() -> ::Lexer_* { return this; }
};

class Parser_
{
public:
	p_bool op_equal(Parser_ const * other) const { return this == other; }
	p_bool op_not_equal(Parser_ const * other) const { return this != other; }
	auto construct() -> ::Parser_*;
	auto ParsePackage_(::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const sources_) const -> ::Syntax_Node_ const *_Nonnull;
};

class Syntax_Node_
{
public:
	p_bool op_equal(Syntax_Node_ const * other) const { return this == other; }
	p_bool op_not_equal(Syntax_Node_ const * other) const { return this != other; }
	p_int kind_;
	p_bool is_missing_;
	::Source_Text_ const *_Nonnull source_;
	p_uint start_;
	p_uint byte_length_;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull children_;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull node_diagnostics_;
	auto construct(p_int const type_, ::Source_Text_ const *_Nonnull const source_, p_uint const start_, p_uint const length_) -> ::Syntax_Node_*;
	auto construct(p_int const type_, p_bool const isMissing_, ::Source_Text_ const *_Nonnull const source_, p_uint const start_, p_uint const length_) -> ::Syntax_Node_*;
	auto construct(p_int const type_, ::Syntax_Node_ const *_Nonnull const child_) -> ::Syntax_Node_*;
	auto construct(p_int const type_, ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull const children_) -> ::Syntax_Node_*;
	auto get_text_() const -> p_string;
	auto first_child_(p_int const type_) const -> ::Syntax_Node_ const *_Nullable;
	auto has_child_(p_int const type_) const -> p_bool;
	auto add_(::Diagnostic_ const *_Nonnull const diagnostic_) const -> void;
	auto all_diagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull;
	auto collect_diagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void;
	auto members_() const -> ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull;
	auto parameters_() const -> ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull;
	auto statements_() const -> ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull;
	auto access_modifier_() const -> ::Syntax_Node_ const *_Nullable;
};

class Syntax_Tree_
{
public:
	p_bool op_equal(Syntax_Tree_ const * other) const { return this == other; }
	p_bool op_not_equal(Syntax_Tree_ const * other) const { return this != other; }
	p_string path_;
	::Source_Text_ const *_Nonnull source_;
	::Syntax_Node_ const *_Nonnull root_;
	auto construct(p_string const path_, ::Source_Text_ const *_Nonnull const source_, ::Syntax_Node_ const *_Nonnull const root_) -> ::Syntax_Tree_*;
};

class Token_Stream_
{
public:
	p_bool op_equal(Token_Stream_ const * other) const { return this == other; }
	p_bool op_not_equal(Token_Stream_ const * other) const { return this != other; }
	::Source_Text_ const *_Nonnull source_;
private:
	p_uint position_;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull diagnostics_;
	p_bool endOfFile_;
public:
	auto construct(::Source_Text_ const *_Nonnull const source_) -> ::Token_Stream_*;
	auto GetNextToken_() -> ::Syntax_Node_ const *_Nullable;
private:
	auto EndOfFile_() -> ::Syntax_Node_ const *_Nullable;
	auto NewIdentifierOrKeyword_(p_uint const end_) -> ::Syntax_Node_ const *_Nonnull;
	auto NewOperator_(p_int const type_) -> ::Syntax_Node_ const *_Nonnull;
	auto NewOperator_(p_int const type_, p_uint const length_) -> ::Syntax_Node_ const *_Nonnull;
	auto NewToken_(p_int const type_, p_uint const end_) -> ::Syntax_Node_ const *_Nonnull;
	static auto IsIdentifierChar_(p_code_point const c_) -> p_bool;
	static auto IsNumberChar_(p_code_point const c_) -> p_bool;
};

class Token_Type_
{
public:
	p_bool op_equal(Token_Type_ const * other) const { return this == other; }
	p_bool op_not_equal(Token_Type_ const * other) const { return this != other; }
	auto construct() -> ::Token_Type_* { return this; }
};

class Diagnostic_
{
public:
	p_bool op_equal(Diagnostic_ const * other) const { return this == other; }
	p_bool op_not_equal(Diagnostic_ const * other) const { return this != other; }
	p_int Level_;
	p_int Phase_;
	::Source_Text_ const *_Nonnull source_;
	::Text_Span_ const *_Nonnull Span_;
	::Text_Position_ const *_Nonnull Position_;
	p_string Message_;
	auto construct(p_int const level_, p_int const phase_, ::Source_Text_ const *_Nonnull const source_, ::Text_Span_ const *_Nonnull const span_, p_string const message_) -> ::Diagnostic_*;
};

class Diagnostic_Info_
{
public:
	p_bool op_equal(Diagnostic_Info_ const * other) const { return this == other; }
	p_bool op_not_equal(Diagnostic_Info_ const * other) const { return this != other; }
	auto construct() -> ::Diagnostic_Info_* { return this; }
};

class Emitter_
{
public:
	p_bool op_equal(Emitter_ const * other) const { return this == other; }
	p_bool op_not_equal(Emitter_ const * other) const { return this != other; }
private:
	::Package_ const *_Nonnull package_;
	::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull resources_;
	::Source_File_Builder_ *_Nonnull type_declarations_;
	::Source_File_Builder_ *_Nonnull function_declarations_;
	::Source_File_Builder_ *_Nonnull class_declarations_;
	::Source_File_Builder_ *_Nonnull global_definitions_;
	::Source_File_Builder_ *_Nonnull definitions_;
	p_string main_function_name_;
	p_string main_function_return_type_;
	p_bool main_function_accepts_console_;
	p_bool main_function_accepts_args_;
public:
	auto construct(::Package_ const *_Nonnull const package_, ::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const resources_) -> ::Emitter_*;
	auto Emit_() -> p_string;
private:
	static auto convert_type_name_(::Semantic_Node_ const *_Nonnull const type_node_) -> p_string;
	static auto convert_type_name_(::Type_ const *_Nonnull const type_) -> p_string;
	static auto convert_reference_type_(p_bool const mutable_binding_, ::Type_ const *_Nonnull type_, p_bool const nullable_) -> p_string;
	static auto convert_type_(p_bool const mutable_binding_, ::Type_ const *_Nonnull type_, p_bool const optional_) -> p_string;
	static auto convert_type_(p_bool const mutable_binding_, ::Semantic_Node_ const *_Nonnull const type_node_) -> p_string;
	auto convert_parameter_list_(::Semantic_Node_ const *_Nonnull const parameters_, p_bool const is_main_function_) -> p_string;
	auto convert_parameter_list_(::Semantic_Node_ const *_Nonnull const parameters_) -> p_string;
	static auto convert_expression_(::Semantic_Node_ const *_Nonnull const syntax_, ::Source_File_Builder_ *_Nonnull const builder_) -> void;
	static auto convert_member_access_(::Semantic_Node_ const *_Nonnull const lhs_, ::Source_File_Builder_ *_Nonnull const builder_) -> void;
	auto emit_statement_(::Semantic_Node_ const *_Nonnull const statement_) -> void;
	auto emit_method_body_(::Semantic_Node_ const *_Nonnull const block_, p_bool const is_associated_function_) -> void;
	auto emit_constructor_body_(::Semantic_Node_ const *_Nonnull const block_, p_string const self_type_, p_bool const is_value_type_) -> void;
	auto emit_access_modifer_(p_int const current_access_level_, p_int const access_modifer_) -> p_int;
	auto emit_member_declaration_(::Semantic_Node_ const *_Nonnull const member_, p_string const class_name_, p_bool const is_value_type_, p_int const current_access_level_) -> p_int;
	auto emit_default_constructor_(p_string const type_name_, p_bool const is_value_type_, p_int const current_access_level_) -> void;
	auto emit_declaration_(::Semantic_Node_ const *_Nonnull const declaration_) -> void;
	auto emit_compilation_unit_(::Compilation_Unit_ const *_Nonnull const unit_) -> void;
	auto emit_preamble_() -> void;
	auto emit_entry_point_adapter_() -> void;
};

class Name_
{
public:
	p_bool op_equal(Name_ const * other) const { return this == other; }
	p_bool op_not_equal(Name_ const * other) const { return this != other; }
	::Package_Name_ const *_Nullable package_;
	p_int kind_;
	::System_::Collections_::List_<p_string> const *_Nonnull segments_;
	p_bool is_special_;
	auto construct_global_namespace() -> ::Name_*;
	auto construct_global_namespace(::Package_Name_ const *_Nonnull const package_) -> ::Name_*;
	auto construct(::Name_ const *_Nonnull const qualifier_, p_int const kind_, p_string const name_) -> ::Name_*;
	auto construct(::Name_ const *_Nonnull const qualifier_, p_int const kind_, p_string const name_, p_bool const is_special_) -> ::Name_*;
	auto construct_special(::Name_ const *_Nonnull const qualifier_, p_int const kind_, p_string const name_) -> ::Name_*;
private:
	auto construct(::Package_Name_ const *_Nullable const package_, p_int const kind_, ::System_::Collections_::List_<p_string> const *_Nonnull const segments_, p_bool const is_special_) -> ::Name_*;
public:
	auto unqualified_() const -> p_string;
	auto full_() const -> p_string;
	auto is_qualified_with_(::Name_ const *_Nonnull const qualifier_) const -> p_bool;
	auto qualifier_is_(::Name_ const *_Nonnull const qualifier_) const -> p_bool;
	auto names_(::Name_ const *_Nonnull const other_) const -> p_bool;
	auto is_package_qualified_() const -> p_bool;
	auto remove_package_() const -> ::Name_ const *_Nonnull;
};

class Package_Name_
{
public:
	p_bool op_equal(Package_Name_ const * other) const { return this == other; }
	p_bool op_not_equal(Package_Name_ const * other) const { return this != other; }
	p_string unqualified_;
	auto construct(p_string const name_) -> ::Package_Name_*;
	auto full_() const -> p_string;
};

class Symbol_
{
public:
	p_bool op_equal(Symbol_ const * other) const { return this == other; }
	p_bool op_not_equal(Symbol_ const * other) const { return this != other; }
	p_string name_;
	p_bool is_special_name_;
	p_int kind_;
	::Type_ const *_Nonnull of_type_;
	::Type_ const *_Nonnull declares_type_;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull declarations_;
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull children_;
	auto construct_identifier(p_string const name_) -> ::Symbol_*;
	auto construct_identifier(p_string const name_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_) -> ::Symbol_*;
	auto construct_identifier(p_string const name_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*;
	auto construct_package(p_string const name_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*;
	auto construct_declaring(::Type_ const *_Nonnull const declares_type_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*;
	auto construct_of_type(p_string const name_, ::Type_ const *_Nonnull const of_type_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*;
	auto get_(p_string const name_, p_int const kind_) const -> ::Symbol_ const *_Nullable;
};

class Type_
{
public:
	p_bool op_equal(Type_ const * other) const { return this == other; }
	p_bool op_not_equal(Type_ const * other) const { return this != other; }
	p_int kind_;
	::Name_ const *_Nonnull name_;
	::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull type_parameters_;
	p_bool is_primitive_;
	p_bool is_value_type_;
	p_bool is_potentially_mutable_;
	p_bool is_mutable_;
	auto construct(p_int const kind_, ::Name_ const *_Nonnull const name_, p_bool const is_mutable_) -> ::Type_*;
	auto construct_parameter(p_string const name_) -> ::Type_*;
	auto construct(p_int const kind_, ::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_, p_bool const is_mutable_) -> ::Type_*;
	auto construct_primitive(::Name_ const *_Nonnull const name_) -> ::Type_*;
	auto construct_primitive(::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_) -> ::Type_*;
	auto construct_namespace(::Name_ const *_Nonnull const name_) -> ::Type_*;
	auto construct_generic(::Type_ const *_Nonnull const definition_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_arguments_) -> ::Type_*;
private:
	auto construct(p_int const kind_, ::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_, p_bool const is_primitive_, p_bool const is_potentially_mutable_, p_bool const is_mutable_) -> ::Type_*;
public:
	auto make_mutable_() const -> ::Type_ const *_Nonnull;
	auto make_immutable_() const -> ::Type_ const *_Nonnull;
	auto remove_package_() const -> ::Type_ const *_Nonnull;
};

class Name_Subtable_
{
public:
	p_bool op_equal(Name_Subtable_ const * other) const { return this == other; }
	p_bool op_not_equal(Name_Subtable_ const * other) const { return this != other; }
	::Name_Table_ const *_Nonnull name_table_;
	::Name_Subtable_ const *_Nullable parent_;
	::Name_ const *_Nonnull name_;
	::Type_ const *_Nonnull type_;
private:
	::System_::Collections_::List_<::Name_Subtable_ *_Nonnull> *_Nonnull subtables_;
public:
	auto construct_global_namespace(::Name_Table_ const *_Nonnull const name_table_) -> ::Name_Subtable_*;
	auto construct_global_namespace(::Name_Table_ const *_Nonnull const name_table_, ::Package_Name_ const *_Nonnull const package_name_) -> ::Name_Subtable_*;
private:
	auto construct(::Name_Subtable_ const *_Nonnull const parent_, ::Name_ const *_Nonnull const name_, ::Type_ const *_Nonnull const type_) -> ::Name_Subtable_*;
public:
	auto add_(::Name_ const *_Nonnull const name_, ::Type_ const *_Nonnull const type_) -> void;
	auto find_(p_string const name_) const -> ::Name_Subtable_ *_Nullable;
	auto find_special_(p_string const name_) const -> ::Name_Subtable_ *_Nullable;
private:
	auto find_(p_string const name_, p_bool const is_special_) const -> ::Name_Subtable_ *_Nullable;
public:
	auto lookup_(p_string const name_) const -> ::Name_Subtable_ *_Nullable;
	auto lookup_special_(p_string const name_) const -> ::Name_Subtable_ *_Nullable;
public:
	auto lookup_(p_string const name_, p_bool const is_special_) const -> ::Name_Subtable_ *_Nullable;
public:
	auto get_(::Name_ const *_Nonnull const name_) const -> ::Name_Subtable_ const *_Nullable;
	auto bind_type_(::Type_ const *_Nonnull const type_) -> void;
};

class Name_Table_
{
public:
	p_bool op_equal(Name_Table_ const * other) const { return this == other; }
	p_bool op_not_equal(Name_Table_ const * other) const { return this != other; }
	::Name_Subtable_ *_Nonnull any_package_;
private:
	::System_::Collections_::List_<::Name_Subtable_ *_Nonnull> *_Nonnull packages_;
public:
	auto construct() -> ::Name_Table_*;
	auto add_(::Package_Name_ const *_Nonnull const package_name_) -> ::Name_ const *_Nonnull;
	auto add_(::Name_ const *_Nonnull const parent_, ::Symbol_ const *_Nonnull const symbol_) -> ::Name_ const *_Nonnull;
	auto add_(::Name_ const *_Nonnull const name_, ::Type_ const *_Nonnull const type_) -> void;
	auto get_(::Name_ const *_Nonnull const name_) const -> ::Name_Subtable_ const *_Nullable;
};

class Name_Table_Builder_
{
public:
	p_bool op_equal(Name_Table_Builder_ const * other) const { return this == other; }
	p_bool op_not_equal(Name_Table_Builder_ const * other) const { return this != other; }
	auto build_(::Package_Name_ const *_Nonnull const package_name_, ::Syntax_Node_ const *_Nonnull const package_syntax_, ::System_::Collections_::List_<::Package_Reference_> const *_Nonnull const references_) const -> ::Name_Table_ const *_Nonnull;
private:
	static auto add_referenced_(::Name_Table_ *_Nonnull const name_table_, ::System_::Collections_::List_<::Package_Reference_> const *_Nonnull const references_) -> void;
	static auto add_symbol_(::Name_Table_ *_Nonnull const name_table_, ::Name_ const *_Nonnull const parent_, ::Symbol_ const *_Nonnull const symbol_) -> void;
	static auto add_package_(::Name_Table_ *_Nonnull const name_table_, ::Package_Name_ const *_Nonnull const package_name_, ::Syntax_Node_ const *_Nonnull const package_syntax_) -> void;
	static auto add_compilation_unit_(::Name_Table_ *_Nonnull const name_table_, ::Name_ const *_Nonnull const global_namespace_, ::Syntax_Node_ const *_Nonnull const compilation_unit_) -> void;
	static auto add_syntax_(::Name_Table_ *_Nonnull const name_table_, ::Name_ const *_Nonnull const parent_, ::Syntax_Node_ const *_Nonnull const syntax_) -> void;
	static auto add_function_(::Name_Table_ *_Nonnull const name_table_, ::Name_ const *_Nonnull const name_, ::Syntax_Node_ const *_Nonnull const function_) -> void;
public:
	auto construct() -> ::Name_Table_Builder_* { return this; }
};

// Global Definitions
p_int const Success_ = p_int(0);
p_int const UsageError_ = p_int(64);
p_int const DataError_ = p_int(65);
p_int const SkippedTokens_ = p_int(1).op_negate();
p_int const EndOfFileToken_ = p_int(0);
p_int const LeftBrace_ = p_int(1);
p_int const RightBrace_ = p_int(2);
p_int const LeftParen_ = p_int(3);
p_int const RightParen_ = p_int(4);
p_int const Semicolon_ = p_int(5);
p_int const Comma_ = p_int(6);
p_int const Dot_ = p_int(7);
p_int const Colon_ = p_int(8);
p_int const LeftBracket_ = p_int(9);
p_int const RightBracket_ = p_int(10);
p_int const Question_ = p_int(11);
p_int const EqualsEquals_ = p_int(12);
p_int const Equals_ = p_int(13);
p_int const PlusEquals_ = p_int(14);
p_int const Plus_ = p_int(15);
p_int const Arrow_ = p_int(16);
p_int const MinusEquals_ = p_int(17);
p_int const Minus_ = p_int(18);
p_int const Slash_ = p_int(19);
p_int const EqualsSlashEquals_ = p_int(20);
p_int const LessThanEquals_ = p_int(21);
p_int const LessThan_ = p_int(22);
p_int const GreaterThanEquals_ = p_int(23);
p_int const GreaterThan_ = p_int(24);
p_int const StringLiteral_ = p_int(25);
p_int const CodePointLiteral_ = p_int(26);
p_int const Identifier_ = p_int(27);
p_int const Number_ = p_int(28);
p_int const NewKeyword_ = p_int(29);
p_int const NotOperator_ = p_int(30);
p_int const NullReservedWord_ = p_int(31);
p_int const SelfKeyword_ = p_int(32);
p_int const TrueKeyword_ = p_int(33);
p_int const FalseKeyword_ = p_int(34);
p_int const IdentifierName_ = p_int(35);
p_int const GenericName_ = p_int(36);
p_int const QualifiedName_ = p_int(37);
p_int const PackageQualifiedName_ = p_int(38);
p_int const MutableKeyword_ = p_int(39);
p_int const OptionalType_ = p_int(40);
p_int const PredefinedType_ = p_int(41);
p_int const CodePoint_ = p_int(42);
p_int const String_ = p_int(43);
p_int const Int_ = p_int(44);
p_int const Bool_ = p_int(45);
p_int const Void_ = p_int(46);
p_int const UnsignedInt_ = p_int(47);
p_int const ParameterList_ = p_int(48);
p_int const Parameter_ = p_int(49);
p_int const SelfParameter_ = p_int(50);
p_int const VarKeyword_ = p_int(51);
p_int const MutableType_ = p_int(52);
p_int const NewExpression_ = p_int(53);
p_int const ArgumentList_ = p_int(54);
p_int const NotExpression_ = p_int(55);
p_int const ParenthesizedExpression_ = p_int(56);
p_int const NoneLiteralExpression_ = p_int(57);
p_int const SelfExpression_ = p_int(58);
p_int const TrueLiteralExpression_ = p_int(59);
p_int const FalseLiteralExpression_ = p_int(60);
p_int const StringLiteralExpression_ = p_int(61);
p_int const CodePointLiteralExpression_ = p_int(62);
p_int const NumericLiteralExpression_ = p_int(63);
p_int const AssignmentExpression_ = p_int(64);
p_int const OrExpression_ = p_int(65);
p_int const AndExpression_ = p_int(66);
p_int const EqualExpression_ = p_int(67);
p_int const NotEqualExpression_ = p_int(68);
p_int const AndKeyword_ = p_int(69);
p_int const OrKeyword_ = p_int(70);
p_int const ComparisonExpression_ = p_int(71);
p_int const AddExpression_ = p_int(72);
p_int const SubtractExpression_ = p_int(73);
p_int const InvocationExpression_ = p_int(74);
p_int const MemberAccessExpression_ = p_int(75);
p_int const ElementAccessExpression_ = p_int(76);
p_int const NegateExpression_ = p_int(77);
p_int const ReturnKeyword_ = p_int(78);
p_int const ReturnStatement_ = p_int(79);
p_int const LoopKeyword_ = p_int(80);
p_int const LoopStatement_ = p_int(81);
p_int const Block_ = p_int(82);
p_int const WhileKeyword_ = p_int(83);
p_int const WhileStatement_ = p_int(84);
p_int const ForKeyword_ = p_int(85);
p_int const ForStatement_ = p_int(86);
p_int const LetKeyword_ = p_int(87);
p_int const VariableDeclaration_ = p_int(88);
p_int const LocalDeclarationStatement_ = p_int(89);
p_int const InKeyword_ = p_int(90);
p_int const DoKeyword_ = p_int(91);
p_int const DoWhileStatement_ = p_int(92);
p_int const IfKeyword_ = p_int(93);
p_int const ElseKeyword_ = p_int(94);
p_int const IfStatement_ = p_int(95);
p_int const ElseClause_ = p_int(96);
p_int const BreakKeyword_ = p_int(97);
p_int const BreakStatement_ = p_int(98);
p_int const ContinueKeyword_ = p_int(99);
p_int const ContinueStatement_ = p_int(100);
p_int const ExpressionStatement_ = p_int(101);
p_int const PublicKeyword_ = p_int(102);
p_int const ProtectedKeyword_ = p_int(103);
p_int const InternalKeyword_ = p_int(104);
p_int const PrivateKeyword_ = p_int(105);
p_int const ConstructorDeclaration_ = p_int(106);
p_int const FieldDeclaration_ = p_int(107);
p_int const MethodDeclaration_ = p_int(108);
p_int const GlobalDeclaration_ = p_int(109);
p_int const ClassKeyword_ = p_int(110);
p_int const ClassDeclaration_ = p_int(111);
p_int const EnumKeyword_ = p_int(112);
p_int const StructKeyword_ = p_int(113);
p_int const EnumDeclaration_ = p_int(114);
p_int const EnumMemberDeclaration_ = p_int(115);
p_int const FunctionDeclaration_ = p_int(116);
p_int const CompilationUnit_ = p_int(117);
p_int const PackageNode_ = p_int(118);
p_int const Percent_ = p_int(119);
p_int const RemainderExpression_ = p_int(120);
p_int const Pipe_ = p_int(121);
p_int const MagnitudeExpression_ = p_int(122);
p_int const Asterisk_ = p_int(123);
p_int const MultiplyExpression_ = p_int(124);
p_int const DivideExpression_ = p_int(125);
p_int const NoneKeyword_ = p_int(126);
p_int const StructDeclaration_ = p_int(127);
p_int const ImmutableType_ = p_int(128);
p_int const NamespaceDeclaration_ = p_int(129);
p_int const Lexing_ = p_int(1);
p_int const Parsing_ = p_int(2);
p_int const Analysis_ = p_int(3);
p_int const Info_ = p_int(1);
p_int const Warning_ = p_int(2);
p_int const RuntimeError_ = p_int(3);
p_int const CompilationError_ = p_int(4);
p_int const FatalCompilationError_ = p_int(5);
p_int const NamespaceName_ = p_int(1);
p_int const TypeName_ = p_int(2);
p_int const FunctionName_ = p_int(3);
p_int const TypeParameterName_ = p_int(4);
p_int const VariableName_ = p_int(5);
p_int const IdentifierSymbol_ = p_int(0);
p_int const PackageSymbol_ = p_int(1);
p_int const ReferenceType_ = p_int(1);
p_int const ValueType_ = p_int(2);
p_int const NamespaceType_ = p_int(3);
p_int const TypeParameterType_ = p_int(4);
p_int const FunctionType_ = p_int(5);

// Definitions

auto compile_(::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const sources_) -> ::Package_ const *_Nonnull
{
	::Parser_ const *_Nonnull const parser_ = (new ::Parser_())->construct();
	::Syntax_Node_ const *_Nonnull const package_syntax_ = parser_->ParsePackage_(sources_);
	::Semantic_Analyzer_ const *_Nonnull const semantic_analyzer_ = (new ::Semantic_Analyzer_())->construct();
	::Package_ const *_Nonnull const package_ = semantic_analyzer_->analyze_(package_syntax_);
	return package_;
}

auto write_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_) -> void
{
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(diagnostics_))
	{
		::Text_Position_ const *_Nonnull const position_ = diagnostic_->Position_;
		p_string severity_;
		if (diagnostic_->Level_->op_equal(Info_).value)
		{
			severity_ = p_string("Informational");
		}
		else if (diagnostic_->Level_->op_equal(Warning_).value)
		{
			severity_ = p_string("Warning");
		}
		else
		{
			severity_ = p_string("Error");
		}

		console_->WriteLine_(diagnostic_->source_->Path_->op_add(p_string(":"))->op_add(position_->Line_)->op_add(p_string(":"))->op_add(position_->Column_)->op_add(p_string(" "))->op_add(severity_)->op_add(p_string(":")));
		console_->WriteLine_(p_string("  ").op_add(diagnostic_->Message_));
	}
}

auto has_errors_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_) -> p_bool
{
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(diagnostics_))
	{
		if (diagnostic_->Level_->op_greater_than_or_equal(CompilationError_).value)
		{
			return p_bool(true);
		}
	}

	return p_bool(false);
}

auto Main_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Console_::Arguments_ const *_Nonnull const args_) -> p_int
{
	if (op_and(args_->op_magnitude()->op_equal(p_int(1)), [&] { return args_->op_Element(p_int(0))->op_equal(p_string("--unit-test")); }).value)
	{
		run_unit_tests_(console_);
		return p_int(0);
	}

	::System_::Collections_::List_<p_string> *_Nonnull const sourceFilePaths_ = (new ::System_::Collections_::List_<p_string>())->construct();
	::System_::Collections_::List_<p_string> *_Nonnull const resourceFilePaths_ = (new ::System_::Collections_::List_<p_string>())->construct();
	p_string outputFilePath_ = p_string("");
	p_bool verbose_ = p_bool(false);
	p_int argType_ = p_int(0);
	for (p_string const arg_ : *(args_))
	{
		if (argType_.op_equal(p_int(0)).value)
		{
			if (arg_.op_equal(p_string("-r")).value)
			{
				argType_ = p_int(1);
			}
			else if (arg_.op_equal(p_string("-o")).value)
			{
				argType_ = p_int(2);
			}
			else if (op_or(arg_.op_equal(p_string("-v")), [&] { return arg_.op_equal(p_string("--verbose")); }).value)
			{
				verbose_ = p_bool(true);
			}
			else
			{
				sourceFilePaths_->Add_(arg_);
			}
		}
		else if (argType_.op_equal(p_int(1)).value)
		{
			resourceFilePaths_->Add_(arg_);
			argType_ = p_int(0);
		}
		else if (argType_.op_equal(p_int(2)).value)
		{
			outputFilePath_ = arg_;
			argType_ = p_int(0);
		}
	}

	if (verbose_.value)
	{
		console_->WriteLine_(p_string("Adamant Compiler v0.1.0"));
	}

	if (op_or(sourceFilePaths_->op_magnitude()->op_equal(p_int(0)), [&] { return outputFilePath_.op_equal(p_string("")); }).value)
	{
		console_->WriteLine_(p_string("Args: <Input File(s)> -o <OutputFile> -r <Resource File>"));
		return UsageError_;
	}

	::System_::Collections_::List_<::Source_Text_ const *_Nonnull> *_Nonnull const resources_ = (new ::System_::Collections_::List_<::Source_Text_ const *_Nonnull>())->construct();
	if (resourceFilePaths_->op_magnitude()->op_greater_than(p_int(0)).value)
	{
		if (verbose_.value)
		{
			console_->WriteLine_(p_string("Reading Resources:"));
		}

		for (p_string const resourceFilePath_ : *(resourceFilePaths_))
		{
			if (verbose_.value)
			{
				console_->WriteLine_(p_string("  ").op_add(resourceFilePath_));
			}

			resources_->Add_(read_source_(resourceFilePath_));
		}
	}

	if (verbose_.value)
	{
		console_->WriteLine_(p_string("Compiling:"));
	}

	::System_::Collections_::List_<::Source_Text_ const *_Nonnull> *_Nonnull const sources_ = (new ::System_::Collections_::List_<::Source_Text_ const *_Nonnull>())->construct();
	for (p_string const sourceFilePath_ : *(sourceFilePaths_))
	{
		if (verbose_.value)
		{
			console_->WriteLine_(p_string("  ").op_add(sourceFilePath_));
		}

		sources_->Add_(read_source_(sourceFilePath_));
	}

	::Package_ const *_Nonnull const package_ = compile_(sources_);
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_ = package_->all_diagnostics_();
	write_(console_, diagnostics_);
	if (has_errors_(diagnostics_).value)
	{
		return DataError_;
	}

	::Emitter_ *_Nonnull emitter_ = (new ::Emitter_())->construct(package_, resources_);
	p_string const translated_ = emitter_->Emit_();
	if (verbose_.value)
	{
		console_->Write_(p_string("Output: "));
		console_->WriteLine_(outputFilePath_);
	}

	::System_::IO_::File_Writer_ *_Nonnull const outputFile_ = (new ::System_::IO_::File_Writer_())->construct(outputFilePath_);
	outputFile_->Write_(translated_);
	outputFile_->Close_();
	p_string outputDirPath_ = outputFilePath_;
	p_int index_ = outputDirPath_.LastIndexOf_(p_code_point('/'));
	if (index_.op_not_equal(p_int(1).op_negate()).value)
	{
		outputDirPath_ = outputDirPath_.Substring_(p_int(0), index_.op_add(p_int(1)));
	}

	index_ = outputDirPath_.LastIndexOf_(p_code_point('\\'));
	if (index_.op_not_equal(p_int(1).op_negate()).value)
	{
		outputDirPath_ = outputDirPath_.Substring_(p_int(0), index_.op_add(p_int(1)));
	}

	if (verbose_.value)
	{
		console_->Write_(p_string("Outputting RuntimeLibrary to: "));
		console_->WriteLine_(outputDirPath_);
	}

	::System_::IO_::File_Writer_ *_Nonnull resourceFile_ = (new ::System_::IO_::File_Writer_())->construct(outputDirPath_.op_add(p_string("RuntimeLibrary.h")));
	resourceFile_->Write_(resource_manager_->GetString_(p_string("RuntimeLibrary.h")));
	resourceFile_->Close_();
	resourceFile_ = (new ::System_::IO_::File_Writer_())->construct(outputDirPath_.op_add(p_string("RuntimeLibrary.cpp")));
	resourceFile_->Write_(resource_manager_->GetString_(p_string("RuntimeLibrary.cpp")));
	resourceFile_->Close_();
	return Success_;
}

auto read_source_(p_string const path_) -> ::Source_Text_ const *_Nonnull
{
	::System_::IO_::File_Reader_ *_Nonnull const file_ = (new ::System_::IO_::File_Reader_())->construct(path_);
	p_string const contents_ = file_->ReadToEndSync_();
	file_->Close_();
	return (new ::Source_Text_())->construct(p_string("<default>"), path_, contents_);
}

auto run_unit_tests_(::System_::Console_::Console_ *_Nonnull const console_) -> void
{
	console_->WriteLine_(p_string("Running Unit Tests..."));
	unit_test_Text_Position_();
	unit_test_Primitives_Package_Builder_();
	unit_test_Runtime_Library_Package_Builder_();
	unit_test_Name_();
	unit_test_Name_Subtable_();
	unit_test_Name_Table_Builder_();
	unit_test_Symbol_();
}

auto ::Line_Info_::construct(::Source_Text_ const *_Nonnull const source_, ::System_::Collections_::List_<p_int> const *_Nonnull const lineStarts_) -> ::Line_Info_*
{
	::Line_Info_* self = this;
	self->source_ = source_;
	self->lineStarts_ = lineStarts_;
	return self;
}

auto ::Line_Info_::Count_() const -> p_int
{
	auto self = this;
	return lineStarts_->op_magnitude();
}

auto ::Line_Info_::get_(p_int const lineNumber_) const -> ::Text_Line_ const *_Nonnull
{
	auto self = this;
	p_int const index_ = lineNumber_.op_subtract(p_int(1));
	p_int const start_ = lineStarts_->op_Element(index_);
	if (index_.op_equal(lineStarts_->op_magnitude()->op_subtract(p_int(1))).value)
	{
		return (new ::Text_Line_())->construct_spanning(source_, start_, source_->ByteLength_());
	}

	p_int const end_ = lineStarts_->op_Element(index_.op_add(p_int(1)));
	return (new ::Text_Line_())->construct_spanning(source_, start_, end_);
}

auto ::Line_Info_::LineNumber_(p_int const offset_) const -> p_int
{
	auto self = this;
	p_int left_ = p_int(0);
	p_int right_ = lineStarts_->op_magnitude()->op_subtract(p_int(1));
	while (left_.op_less_than_or_equal(right_).value)
	{
		p_int const mid_ = left_.op_add(right_.op_subtract(left_)->op_divide(p_int(2)));
		p_int const midLineStart_ = lineStarts_->op_Element(mid_);
		if (midLineStart_.op_less_than(offset_).value)
		{
			left_ = mid_.op_add(p_int(1));
		}
		else if (midLineStart_.op_greater_than(offset_).value)
		{
			right_ = mid_.op_subtract(p_int(1));
		}
		else
		{
			return mid_.op_add(p_int(1));
		}
	}

	return left_;
}

auto ::Source_Text_::construct(p_string const package_, p_string const path_, p_string const text_) -> ::Source_Text_*
{
	::Source_Text_* self = this;
	Package_ = package_;
	Path_ = path_;
	p_string name_ = path_;
	p_int index_ = name_.LastIndexOf_(p_code_point('/'));
	if (index_.op_not_equal(p_int(1).op_negate()).value)
	{
		name_ = name_.Substring_(index_.op_add(p_int(1)));
	}

	index_ = name_.LastIndexOf_(p_code_point('\\'));
	if (index_.op_not_equal(p_int(1).op_negate()).value)
	{
		name_ = name_.Substring_(index_.op_add(p_int(1)));
	}

	self->name_ = name_;
	Text_ = text_;
	Lines_ = (new ::Line_Info_())->construct(self, LineStarts_());
	return self;
}

auto ::Source_Text_::LineStarts_() const -> ::System_::Collections_::List_<p_int> const *_Nonnull
{
	auto self = this;
	p_int const length_ = ByteLength_();
	::System_::Collections_::List_<p_int> *_Nonnull const lineStarts_ = (new ::System_::Collections_::List_<p_int>())->construct();
	lineStarts_->Add_(p_int(0));
	p_int position_ = p_int(0);
	while (position_.op_less_than(length_).value)
	{
		p_code_point const c_ = Text_.op_Element(position_);
		position_.op_add_assign(p_int(1));
		if (op_and(c_.op_greater_than(p_code_point('\r')), [&] { return c_.op_less_than_or_equal(p_code_point('\x7F')); }).value)
		{
			continue;
		}

		if (c_.op_equal(p_code_point('\r')).value)
		{
			if (op_and(position_.op_less_than(length_), [&] { return Text_.op_Element(position_)->op_equal(p_code_point('\n')); }).value)
			{
				position_.op_add_assign(p_int(1));
			}
		}
		else if (op_or(op_or(op_or(c_.op_equal(p_code_point('\n')), [&] { return c_.op_equal(p_code_point('\x0B')); }), [&] { return c_.op_equal(p_code_point('\f')); }), [&] { return c_.op_equal(p_code_point('\x85')); }).value)
		{
		}
		else
		{
			continue;
		}

		lineStarts_->Add_(position_);
	}

	return lineStarts_;
}

auto ::Source_Text_::ByteLength_() const -> p_int
{
	auto self = this;
	return Text_.ByteLength_();
}

auto ::Source_Text_::PositionOfStart_(::Text_Span_ const *_Nonnull const span_) const -> ::Text_Position_ const *_Nonnull
{
	auto self = this;
	p_int const offset_ = span_->start_;
	p_int const lineNumber_ = Lines_->LineNumber_(offset_);
	p_int const lineStart_ = Lines_->get_(lineNumber_)->start_;
	p_int column_ = offset_.op_subtract(lineStart_)->op_add(p_int(1));
	p_int i_ = lineStart_;
	while (i_.op_less_than(offset_).value)
	{
		if (Text_.op_Element(i_)->op_equal(p_code_point('\t')).value)
		{
			column_.op_add_assign(p_int(3));
		}

		i_.op_add_assign(p_int(1));
	}

	return (new ::Text_Position_())->construct(offset_, lineNumber_, column_);
}

auto ::Text_Line_::construct(::Source_Text_ const *_Nonnull const source_, p_int const start_, p_int const length_) -> ::Text_Line_*
{
	::Text_Line_* self = this;
	self->source_ = source_;
	self->start_ = start_;
	byte_length_ = length_;
	return self;
}

auto ::Text_Line_::construct_spanning(::Source_Text_ const *_Nonnull const source_, p_int const start_, p_int const end_) -> ::Text_Line_*
{
	::Text_Line_* self = this;
	self->source_ = source_;
	self->start_ = start_;
	self->byte_length_ = end_.op_subtract(start_);
	return self;
}

auto ::Text_Line_::End_() const -> p_int
{
	auto self = this;
	return start_.op_add(byte_length_);
}

auto ::Text_Position_::construct(p_int const offset_, p_int const line_, p_int const column_) -> ::Text_Position_*
{
	::Text_Position_* self = this;
	Offset_ = offset_;
	Line_ = line_;
	Column_ = column_;
	return self;
}

auto unit_test_Text_Position_() -> void
{
	Text_Position_retains_given_offeset_line_and_column_();
}

auto Text_Position_retains_given_offeset_line_and_column_() -> void
{
	::Text_Position_ const *_Nonnull const position_ = (new ::Text_Position_())->construct(p_int(23), p_int(2), p_int(5));
	assert_(position_->Offset_->op_equal(p_int(23)), p_string(""));
	assert_(position_->Line_->op_equal(p_int(2)), p_string(""));
	assert_(position_->Column_->op_equal(p_int(5)), p_string(""));
}

auto ::Text_Span_::construct(p_int const start_, p_int const length_) -> ::Text_Span_*
{
	::Text_Span_* self = this;
	self->start_ = start_;
	byte_length_ = length_;
	return self;
}

auto ::Text_Span_::End_() const -> p_int
{
	auto self = this;
	return start_.op_add(byte_length_);
}

auto format_error_(p_string const message_) -> p_string
{
	return p_string("<$ ").op_add(message_)->op_add(p_string(" $>"));
}

auto ::Source_File_Builder_::construct() -> ::Source_File_Builder_*
{
	::Source_File_Builder_* self = this;
	code_ = (new ::System_::Text_::String_Builder_())->construct();
	indent_ = (new ::System_::Text_::String_Builder_())->construct();
	firstElement_ = p_bool(true);
	afterBlock_ = p_bool(true);
	return self;
}

auto ::Source_File_Builder_::Error_(p_string const message_) -> void
{
	auto self = this;
	code_->Append_(format_error_(message_));
}

auto ::Source_File_Builder_::BeginLine_(p_string const value_) -> void
{
	auto self = this;
	code_->Append_(indent_);
	code_->Append_(value_);
	firstElement_ = afterBlock_ = p_bool(false);
}

auto ::Source_File_Builder_::Write_(p_string const value_) -> void
{
	auto self = this;
	code_->Append_(value_);
	firstElement_ = afterBlock_ = p_bool(false);
}

auto ::Source_File_Builder_::EndLine_(p_string const value_) -> void
{
	auto self = this;
	code_->Append_(value_);
	code_->AppendLine_();
	firstElement_ = afterBlock_ = p_bool(false);
}

auto ::Source_File_Builder_::WriteLine_(p_string const value_) -> void
{
	auto self = this;
	code_->Append_(indent_);
	code_->Append_(value_);
	code_->AppendLine_();
	firstElement_ = afterBlock_ = p_bool(false);
}

auto ::Source_File_Builder_::BlankLine_() -> void
{
	auto self = this;
	code_->AppendLine_();
	firstElement_ = p_bool(true);
	afterBlock_ = p_bool(false);
}

auto ::Source_File_Builder_::ElementSeparatorLine_() -> void
{
	auto self = this;
	if (firstElement_.op_not().value)
	{
		code_->AppendLine_();
		firstElement_ = p_bool(true);
		afterBlock_ = p_bool(false);
	}
}

auto ::Source_File_Builder_::StatementSeparatorLine_() -> void
{
	auto self = this;
	if (afterBlock_.value)
	{
		code_->AppendLine_();
		firstElement_ = p_bool(true);
		afterBlock_ = p_bool(false);
	}
}

auto ::Source_File_Builder_::BeginBlock_() -> void
{
	auto self = this;
	WriteLine_(p_string("{"));
	indent_->Append_(p_string("\t"));
	firstElement_ = afterBlock_ = p_bool(false);
}

auto ::Source_File_Builder_::EndBlock_() -> void
{
	auto self = this;
	indent_->Remove_(p_int(0), p_int(1));
	WriteLine_(p_string("}"));
	afterBlock_ = p_bool(true);
}

auto ::Source_File_Builder_::EndBlockWithSemicolon_() -> void
{
	auto self = this;
	indent_->Remove_(p_int(0), p_int(1));
	WriteLine_(p_string("};"));
}

auto ::Source_File_Builder_::ToString_() const -> p_string
{
	auto self = this;
	return code_->ToString_();
}

auto ::Compilation_Unit_::construct(::Syntax_Node_ const *_Nonnull const syntax_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_) -> ::Compilation_Unit_*
{
	::Compilation_Unit_* self = this;
	self->syntax_ = syntax_;
	self->declarations_ = declarations_;
	return self;
}

auto ::Compilation_Unit_::collect_diagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void
{
	auto self = this;
	syntax_->collect_diagnostics_(diagnostics_);
	for (::Semantic_Node_ const *_Nonnull const declaration_ : *(declarations_))
	{
		declaration_->collect_diagnostics_(diagnostics_);
	}
}

auto ::Package_::construct(::Package_Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Package_Reference_> const *_Nonnull const references_, ::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull> const *_Nonnull const compilation_units_, ::Symbol_ const *_Nonnull const symbol_) -> ::Package_*
{
	::Package_* self = this;
	self->name_ = name_;
	self->references_ = references_;
	self->compilation_units_ = compilation_units_;
	self->symbol_ = symbol_;
	return self;
}

auto ::Package_::all_diagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	for (::Compilation_Unit_ const *_Nonnull const compilation_unit_ : *(compilation_units_))
	{
		compilation_unit_->collect_diagnostics_(diagnostics_);
	}

	return diagnostics_;
}

auto ::Package_Reference_::construct(::Package_ const *_Nonnull const package_) -> ::Package_Reference_
{
	::Package_Reference_ self;
	self->name_ = package_->name_->unqualified_;
	self->package_ = package_;
	return self;
}

auto ::Package_Reference_::construct(p_string const name_, ::Package_ const *_Nonnull const package_) -> ::Package_Reference_
{
	::Package_Reference_ self;
	self->name_ = name_;
	self->package_ = package_;
	return self;
}

auto ::Primitives_Package_Builder_::build_() const -> ::Package_ const *_Nonnull
{
	auto self = this;
	::Package_Name_ const *_Nonnull const name_ = (new ::Package_Name_())->construct(p_string("$primitives"));
	::System_::Collections_::List_<::Package_Reference_> const *_Nonnull const references_ = (new ::System_::Collections_::List_<::Package_Reference_>())->construct();
	::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull> const *_Nonnull const compilation_units_ = (new ::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull>())->construct();
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const primitive_symbols_ = build_primitive_symbols_(name_);
	assert_(primitive_symbols_->op_magnitude()->op_greater_than(p_int(0)), p_string("|primitive_symbols|=").op_add(primitive_symbols_->op_magnitude()));
	::Symbol_ const *_Nonnull const package_symbol_ = (new ::Symbol_())->construct_package(name_->unqualified_, primitive_symbols_);
	assert_(package_symbol_->children_->op_magnitude()->op_greater_than(p_int(0)), p_string("|package_symbol.children|=").op_add(package_symbol_->children_->op_magnitude()));
	return (new ::Package_())->construct(name_, references_, compilation_units_, package_symbol_);
}

auto ::Primitives_Package_Builder_::build_primitive_symbols_(::Package_Name_ const *_Nonnull const package_name_) const -> ::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull
{
	auto self = this;
	::Name_ const *_Nonnull const global_namespace_ = (new ::Name_())->construct_global_namespace(package_name_);
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	symbols_->Add_(build_adamant_language_namespace_(global_namespace_));
	symbols_->Add_(build_primitive_(p_string("void"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("never"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("bool"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("code_point"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("string"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("int8"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("int16"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("int"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("int64"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("int128"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("byte"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("uint16"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("uint"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("uint64"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("uint128"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("float32"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("float"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("float128"), global_namespace_));
	build_fixed_point_primitives_(symbols_, p_int(8), global_namespace_);
	build_fixed_point_primitives_(symbols_, p_int(16), global_namespace_);
	build_fixed_point_primitives_(symbols_, p_int(32), global_namespace_);
	build_fixed_point_primitives_(symbols_, p_int(64), global_namespace_);
	symbols_->Add_(build_primitive_(p_string("decimal32"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("decimal"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("decimal128"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("size"), global_namespace_));
	symbols_->Add_(build_primitive_(p_string("offset"), global_namespace_));
	return symbols_;
}

auto ::Primitives_Package_Builder_::build_adamant_language_namespace_(::Name_ const *_Nonnull const global_namespace_) -> ::Symbol_ const *_Nonnull
{
	::Name_ const *_Nonnull const adamant_namespace_ = (new ::Name_())->construct(global_namespace_, NamespaceName_, p_string("adamant"));
	::Name_ const *_Nonnull const language_namespace_ = (new ::Name_())->construct(adamant_namespace_, NamespaceName_, p_string("language"));
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const language_children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	language_children_->add_(build_optional_(language_namespace_));
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const adamant_children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	adamant_children_->add_((new ::Symbol_())->construct_identifier(language_namespace_->unqualified_(), language_children_));
	return (new ::Symbol_())->construct_identifier(adamant_namespace_->unqualified_(), adamant_children_);
}

auto ::Primitives_Package_Builder_::build_optional_(::Name_ const *_Nonnull const language_namespace_) -> ::Symbol_ const *_Nonnull
{
	::Name_ const *_Nonnull const optional_name_ = (new ::Name_())->construct(language_namespace_, TypeName_, p_string("optional"));
	::System_::Collections_::List_<::Type_ const *_Nonnull> *_Nonnull const type_parameters_ = (new ::System_::Collections_::List_<::Type_ const *_Nonnull>())->construct();
	type_parameters_->add_((new ::Type_())->construct(TypeParameterType_, (new ::Name_())->construct(optional_name_, TypeParameterName_, p_string("T")), p_bool(true)));
	::Type_ const *_Nonnull const type_ = (new ::Type_())->construct_primitive(optional_name_, type_parameters_);
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return (new ::Symbol_())->construct_declaring(type_, declarations_, children_);
}

auto ::Primitives_Package_Builder_::build_primitive_(p_string const name_, ::Name_ const *_Nonnull const namespace_) -> ::Symbol_ const *_Nonnull
{
	::Type_ const *_Nonnull const type_ = (new ::Type_())->construct_primitive((new ::Name_())->construct_special(namespace_, TypeName_, name_));
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return (new ::Symbol_())->construct_declaring(type_, declarations_, children_);
}

auto ::Primitives_Package_Builder_::build_fixed_point_primitives_(::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_, p_int const bits_, ::Name_ const *_Nonnull const namespace_) -> void
{
}

auto unit_test_Primitives_Package_Builder_() -> void
{
	Package_name_is_dollar_primitives_();
	Package_has_no_references_or_compilation_units_();
	Package_symbol_has_package_name_();
	Package_symbol_has_children_();
	Package_contains_the_string_type_();
	Package_contains_optional_type_();
}

auto Package_name_is_dollar_primitives_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	::Package_Name_ const *_Nonnull const name_ = package_->name_;
	assert_(name_->unqualified_->op_equal(p_string("$primitives")), p_string(""));
}

auto Package_has_no_references_or_compilation_units_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	assert_(package_->references_->op_magnitude()->op_equal(p_int(0)), p_string(""));
	assert_(package_->compilation_units_->op_magnitude()->op_equal(p_int(0)), p_string(""));
}

auto Package_symbol_has_package_name_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	::Symbol_ const *_Nonnull const symbol_ = package_->symbol_;
	assert_(symbol_->kind_->op_equal(PackageSymbol_), p_string(""));
	assert_(symbol_->name_->op_equal(package_->name_->unqualified_), p_string(""));
}

auto Package_symbol_has_children_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	assert_(package_->symbol_->children_->op_magnitude()->op_greater_than(p_int(0)), p_string(""));
}

auto Package_contains_the_string_type_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	::Symbol_ const *_Nonnull const string_symbol_ = package_->symbol_->get_(p_string("string"), IdentifierSymbol_);
	assert_(string_symbol_->op_not_equal(p_none), p_string(""));
}

auto Package_contains_optional_type_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	::Symbol_ const *_Nullable const adamant_symbol_ = package_->symbol_->get_(p_string("adamant"), IdentifierSymbol_);
	assert_(adamant_symbol_->op_not_equal(p_none), p_string(""));
	::Symbol_ const *_Nullable const langauge_symbol_ = adamant_symbol_->get_(p_string("language"), IdentifierSymbol_);
	assert_(langauge_symbol_->op_not_equal(p_none), p_string(""));
	::Symbol_ const *_Nullable const optional_symbol_ = langauge_symbol_->get_(p_string("optional"), IdentifierSymbol_);
	assert_(optional_symbol_->op_not_equal(p_none), p_string(""));
}

auto ::Runtime_Library_Package_Builder_::build_() const -> ::Package_ const *_Nonnull
{
	auto self = this;
	::Package_Name_ const *_Nonnull const name_ = (new ::Package_Name_())->construct(p_string("$runtime"));
	::System_::Collections_::List_<::Package_Reference_> const *_Nonnull const references_ = (new ::System_::Collections_::List_<::Package_Reference_>())->construct();
	::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull> const *_Nonnull const compilation_units_ = (new ::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull>())->construct();
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_ = build_symbols_(name_);
	assert_(symbols_->op_magnitude()->op_greater_than(p_int(0)), p_string("|symbols|=").op_add(symbols_->op_magnitude()));
	::Symbol_ const *_Nonnull const package_symbol_ = (new ::Symbol_())->construct_package(name_->unqualified_, symbols_);
	assert_(package_symbol_->children_->op_magnitude()->op_greater_than(p_int(0)), p_string("|package_symbol.children|=").op_add(package_symbol_->children_->op_magnitude()));
	return (new ::Package_())->construct(name_, references_, compilation_units_, package_symbol_);
}

auto ::Runtime_Library_Package_Builder_::build_symbols_(::Package_Name_ const *_Nonnull const package_name_) const -> ::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull
{
	auto self = this;
	::Name_ const *_Nonnull const global_namespace_ = (new ::Name_())->construct_global_namespace(package_name_);
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	symbols_->Add_(build_function_((new ::Name_())->construct(global_namespace_, FunctionName_, p_string("THROW_EXCEPTION"))));
	symbols_->Add_(build_function_((new ::Name_())->construct(global_namespace_, FunctionName_, p_string("NOT_IMPLEMENTED"))));
	symbols_->Add_(build_function_((new ::Name_())->construct(global_namespace_, FunctionName_, p_string("UNREACHABLE"))));
	symbols_->Add_(build_function_((new ::Name_())->construct(global_namespace_, FunctionName_, p_string("assert"))));
	symbols_->Add_(build_function_((new ::Name_())->construct(global_namespace_, FunctionName_, p_string("debug_write"))));
	symbols_->Add_(build_function_((new ::Name_())->construct(global_namespace_, FunctionName_, p_string("debug_write_line"))));
	symbols_->Add_(build_function_((new ::Name_())->construct(global_namespace_, VariableName_, p_string("resource_manager"))));
	::Name_ const *_Nonnull const system_namespace_ = (new ::Name_())->construct(global_namespace_, NamespaceName_, p_string("System"));
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const system_symbols_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	::Name_ const *_Nonnull const collections_namespace_ = (new ::Name_())->construct(system_namespace_, NamespaceName_, p_string("Collections"));
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const collections_symbols_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	::System_::Collections_::List_<::Type_ const *_Nonnull> *_Nonnull const list_type_parameters_ = (new ::System_::Collections_::List_<::Type_ const *_Nonnull>())->construct();
	list_type_parameters_->add_((new ::Type_())->construct_parameter(p_string("T")));
	collections_symbols_->Add_(build_generic_class_(collections_namespace_, p_string("List"), list_type_parameters_));
	system_symbols_->Add_(build_namespace_(collections_namespace_, collections_symbols_));
	::Name_ const *_Nonnull const console_namespace_ = (new ::Name_())->construct(system_namespace_, NamespaceName_, p_string("Console"));
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const console_symbols_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	console_symbols_->Add_(build_class_(console_namespace_, p_string("Console")));
	console_symbols_->Add_(build_class_(console_namespace_, p_string("Arguments")));
	system_symbols_->Add_(build_namespace_(console_namespace_, console_symbols_));
	::Name_ const *_Nonnull const io_namespace_ = (new ::Name_())->construct(system_namespace_, NamespaceName_, p_string("IO"));
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const io_symbols_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	io_symbols_->Add_(build_class_(io_namespace_, p_string("File_Reader")));
	io_symbols_->Add_(build_class_(io_namespace_, p_string("File_Writer")));
	system_symbols_->Add_(build_namespace_(io_namespace_, io_symbols_));
	::Name_ const *_Nonnull const text_namespace_ = (new ::Name_())->construct(system_namespace_, NamespaceName_, p_string("Text"));
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const text_symbols_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	text_symbols_->Add_(build_class_(text_namespace_, p_string("String_Builder")));
	system_symbols_->Add_(build_namespace_(text_namespace_, text_symbols_));
	symbols_->Add_(build_namespace_(system_namespace_, system_symbols_));
	return symbols_;
}

auto ::Runtime_Library_Package_Builder_::build_function_(::Name_ const *_Nonnull const name_) -> ::Symbol_ const *_Nonnull
{
	::Type_ const *_Nonnull const type_ = (new ::Type_())->construct(FunctionType_, name_, p_bool(false));
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return (new ::Symbol_())->construct_of_type(name_->unqualified_(), type_, declarations_, children_);
}

auto ::Runtime_Library_Package_Builder_::build_namespace_(::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_) -> ::Symbol_ const *_Nonnull
{
	::Type_ const *_Nonnull const type_ = (new ::Type_())->construct_namespace(name_);
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	return (new ::Symbol_())->construct_declaring(type_, declarations_, symbols_);
}

auto ::Runtime_Library_Package_Builder_::build_class_(::Name_ const *_Nonnull const namespace_, p_string const class_name_) -> ::Symbol_ const *_Nonnull
{
	::Type_ const *_Nonnull const type_ = (new ::Type_())->construct(ReferenceType_, (new ::Name_())->construct(namespace_, TypeName_, class_name_), p_bool(true));
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return (new ::Symbol_())->construct_declaring(type_, declarations_, children_);
}

auto ::Runtime_Library_Package_Builder_::build_generic_class_(::Name_ const *_Nonnull const namespace_, p_string const class_name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_) -> ::Symbol_ const *_Nonnull
{
	::Type_ const *_Nonnull const type_ = (new ::Type_())->construct(ReferenceType_, (new ::Name_())->construct(namespace_, TypeName_, class_name_), type_parameters_, p_bool(true));
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return (new ::Symbol_())->construct_declaring(type_, declarations_, children_);
}

auto unit_test_Runtime_Library_Package_Builder_() -> void
{
	Runtime_Library_Package_contains_System_package_();
	System_namespace_contains_Console_namespace_();
	Console_namespace_contains_Console_class_();
	System_namespace_contains_Collections_namespace_();
	Collections_namespace_contains_List_class_();
}

auto Runtime_Library_Package_contains_System_package_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	assert_(package_->symbol_->get_(p_string("System"), IdentifierSymbol_)->op_not_equal(p_none), p_string(""));
}

auto System_namespace_contains_Console_namespace_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	::Symbol_ const *_Nonnull const system_namespace_ = package_->symbol_->get_(p_string("System"), IdentifierSymbol_);
	assert_(system_namespace_->get_(p_string("Console"), IdentifierSymbol_)->op_not_equal(p_none), p_string(""));
}

auto Console_namespace_contains_Console_class_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	::Symbol_ const *_Nonnull const system_namespace_ = package_->symbol_->get_(p_string("System"), IdentifierSymbol_);
	::Symbol_ const *_Nonnull const console_namespace_ = system_namespace_->get_(p_string("Console"), IdentifierSymbol_);
	assert_(console_namespace_->get_(p_string("Console"), IdentifierSymbol_)->op_not_equal(p_none), p_string(""));
}

auto System_namespace_contains_Collections_namespace_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	::Symbol_ const *_Nonnull const system_namespace_ = package_->symbol_->get_(p_string("System"), IdentifierSymbol_);
	assert_(system_namespace_->get_(p_string("Collections"), IdentifierSymbol_)->op_not_equal(p_none), p_string(""));
}

auto Collections_namespace_contains_List_class_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	::Symbol_ const *_Nonnull const system_namespace_ = package_->symbol_->get_(p_string("System"), IdentifierSymbol_);
	::Symbol_ const *_Nonnull const console_namespace_ = system_namespace_->get_(p_string("Collections"), IdentifierSymbol_);
	assert_(console_namespace_->get_(p_string("List"), IdentifierSymbol_)->op_not_equal(p_none), p_string(""));
}

auto ::Semantic_Analyzer_::analyze_(::Syntax_Node_ const *_Nonnull const package_syntax_) -> ::Package_ const *_Nonnull
{
	assert_(package_syntax_->kind_->op_equal(PackageNode_), p_string("package_syntax.kind=").op_add(package_syntax_->kind_));
	::Package_Name_ const *_Nonnull const name_ = (new ::Package_Name_())->construct(p_string("default"));
	::Package_ const *_Nonnull const primitives_package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	::Package_ const *_Nonnull const runtime_package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	::System_::Collections_::List_<::Package_Reference_> *_Nonnull const references_ = (new ::System_::Collections_::List_<::Package_Reference_>())->construct();
	references_->add_(::Package_Reference_::construct(primitives_package_));
	references_->add_(::Package_Reference_::construct(runtime_package_));
	::Name_Table_Builder_ const *_Nonnull const name_table_builder_ = (new ::Name_Table_Builder_())->construct();
	::Name_Table_ const *_Nonnull const name_table_ = name_table_builder_->build_(name_, package_syntax_, references_);
	::Semantic_Tree_Builder_ const *_Nonnull const semantic_tree_builder_ = (new ::Semantic_Tree_Builder_())->construct();
	::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull> const *_Nonnull const compilation_units_ = semantic_tree_builder_->build_(package_syntax_, name_table_);
	::Symbol_Builder_ const *_Nonnull const symbol_builder_ = (new ::Symbol_Builder_())->construct();
	::Symbol_ const *_Nonnull const package_symbol_ = symbol_builder_->build_(name_, compilation_units_);
	::Package_ const *_Nonnull const package_ = (new ::Package_())->construct(name_, references_, compilation_units_, package_symbol_);
	return package_;
}

auto ::Semantic_Node_::construct_token(::Syntax_Node_ const *_Nonnull const syntax_) -> ::Semantic_Node_*
{
	::Semantic_Node_* self = this;
	assert_(syntax_->op_not_equal(p_none), p_string(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	self->node_diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	self->of_type_ = p_none;
	self->converted_type_ = p_none;
	self->declares_type_ = p_none;
	self->referenced_type_ = p_none;
	return self;
}

auto ::Semantic_Node_::construct_concrete(::Syntax_Node_ const *_Nonnull const syntax_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const children_) -> ::Semantic_Node_*
{
	::Semantic_Node_* self = this;
	assert_(syntax_->op_not_equal(p_none), p_string(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = children_;
	self->node_diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	self->of_type_ = p_none;
	self->converted_type_ = p_none;
	self->declares_type_ = p_none;
	self->referenced_type_ = p_none;
	return self;
}

auto ::Semantic_Node_::construct_of_type(::Type_ const *_Nonnull const of_type_, ::Syntax_Node_ const *_Nonnull const syntax_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const children_) -> ::Semantic_Node_*
{
	::Semantic_Node_* self = this;
	assert_(of_type_->op_not_equal(p_none), p_string(""));
	assert_(syntax_->op_not_equal(p_none), p_string(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = children_;
	self->node_diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	self->of_type_ = of_type_;
	self->converted_type_ = of_type_;
	self->declares_type_ = p_none;
	self->referenced_type_ = p_none;
	return self;
}

auto ::Semantic_Node_::construct_referencing_type(::Type_ const *_Nonnull const type_, ::Syntax_Node_ const *_Nonnull const syntax_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const children_) -> ::Semantic_Node_*
{
	::Semantic_Node_* self = this;
	assert_(type_->op_not_equal(p_none), p_string(""));
	assert_(syntax_->op_not_equal(p_none), p_string(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = children_;
	self->node_diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	self->of_type_ = p_none;
	self->converted_type_ = p_none;
	self->declares_type_ = p_none;
	self->referenced_type_ = type_;
	return self;
}

auto ::Semantic_Node_::get_text_span_() const -> ::Text_Span_ const *_Nonnull
{
	auto self = this;
	return (new ::Text_Span_())->construct(start_, byte_length_);
}

auto ::Semantic_Node_::get_text_() const -> p_string
{
	auto self = this;
	if (source_->op_equal(p_none).value)
	{
		return p_string("$No Source$");
	}

	return source_->Text_->Substring_(start_, byte_length_);
}

auto ::Semantic_Node_::first_child_(p_int const kind_) const -> ::Semantic_Node_ const *_Nullable
{
	auto self = this;
	for (::Semantic_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (child_->kind_->op_equal(kind_).value)
		{
			return child_;
		}
	}

	return p_none;
}

auto ::Semantic_Node_::children_of_kind_(p_int const kind_) const -> ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	for (::Semantic_Node_ const *_Nonnull const child_ : *(self->children_))
	{
		if (child_->kind_->op_equal(kind_).value)
		{
			children_->Add_(child_);
		}
	}

	return children_;
}

auto ::Semantic_Node_::members_() const -> ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const members_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	for (::Semantic_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (op_or(op_or(child_->kind_->op_equal(ConstructorDeclaration_), [&] { return child_->kind_->op_equal(FieldDeclaration_); }), [&] { return child_->kind_->op_equal(MethodDeclaration_); }).value)
		{
			members_->Add_(child_);
		}
	}

	return members_;
}

auto ::Semantic_Node_::statements_() const -> ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const statements_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	for (::Semantic_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (op_and(child_->kind_->op_not_equal(LeftBrace_), [&] { return child_->kind_->op_not_equal(RightBrace_); }).value)
		{
			statements_->Add_(child_);
		}
	}

	return statements_;
}

auto ::Semantic_Node_::parameters_() const -> ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const parameters_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	for (::Semantic_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (op_or(child_->kind_->op_equal(Parameter_), [&] { return child_->kind_->op_equal(SelfParameter_); }).value)
		{
			parameters_->Add_(child_);
		}
	}

	return parameters_;
}

auto ::Semantic_Node_::access_modifier_() const -> ::Semantic_Node_ const *_Nullable
{
	auto self = this;
	for (::Semantic_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (op_or(op_or(op_or(child_->kind_->op_equal(PublicKeyword_), [&] { return child_->kind_->op_equal(ProtectedKeyword_); }), [&] { return child_->kind_->op_equal(PrivateKeyword_); }), [&] { return child_->kind_->op_equal(InternalKeyword_); }).value)
		{
			return child_;
		}
	}

	return p_none;
}

auto ::Semantic_Node_::has_child_(p_int const kind_) const -> p_bool
{
	auto self = this;
	for (::Semantic_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (child_->kind_->op_equal(kind_).value)
		{
			return p_bool(true);
		}
	}

	return p_bool(false);
}

auto ::Semantic_Node_::add_(::Diagnostic_ const *_Nonnull const diagnostic_) -> void
{
	auto self = this;
	node_diagnostics_->Add_(diagnostic_);
}

auto ::Semantic_Node_::diagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	return self->node_diagnostics_;
}

auto ::Semantic_Node_::collect_diagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void
{
	auto self = this;
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(node_diagnostics_))
	{
		diagnostics_->add_(diagnostic_);
	}

	for (::Semantic_Node_ const *_Nonnull const child_ : *(children_))
	{
		child_->collect_diagnostics_(diagnostics_);
	}
}

auto ::Semantic_Tree_Builder_::construct() -> ::Semantic_Tree_Builder_*
{
	::Semantic_Tree_Builder_* self = this;
	::Package_Name_ const *_Nonnull const primitives_package_ = (new ::Package_Name_())->construct(p_string("$primitives"));
	::Name_ const *_Nonnull const global_namespace_ = (new ::Name_())->construct_global_namespace(primitives_package_);
	::Name_ const *_Nonnull const adamant_namespace_ = (new ::Name_())->construct(global_namespace_, NamespaceName_, p_string("adamant"));
	::Name_ const *_Nonnull const language_namespace_ = (new ::Name_())->construct(adamant_namespace_, NamespaceName_, p_string("language"));
	self->optional_type_name_ = (new ::Name_())->construct(language_namespace_, TypeName_, p_string("optional"));
	return self;
}

auto ::Semantic_Tree_Builder_::build_(::Syntax_Node_ const *_Nonnull const package_syntax_, ::Name_Table_ const *_Nonnull const name_table_) const -> ::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	assert_(package_syntax_->kind_->op_equal(PackageNode_), p_string("package_syntax.kind=").op_add(package_syntax_->kind_));
	assert_(name_table_->any_package_->lookup_special_(p_string("string"))->op_not_equal(p_none), p_string("name_table.any_package.name=").op_add(name_table_->any_package_->name_->full_()));
	::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull> *_Nonnull const compilation_units_ = (new ::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull>())->construct();
	for (::Syntax_Node_ const *_Nonnull const compilation_unit_syntax_ : *(package_syntax_->children_))
	{
		compilation_units_->add_(build_compilation_unit_(compilation_unit_syntax_, name_table_));
	}

	return compilation_units_;
}

auto ::Semantic_Tree_Builder_::build_compilation_unit_(::Syntax_Node_ const *_Nonnull const compilation_unit_syntax_, ::Name_Table_ const *_Nonnull const name_table_) const -> ::Compilation_Unit_ const *_Nonnull
{
	auto self = this;
	assert_(compilation_unit_syntax_->kind_->op_equal(CompilationUnit_), p_string("compilation_unit_syntax.kind=").op_add(compilation_unit_syntax_->kind_));
	::Name_Subtable_ const *_Nonnull const scope_ = p_none;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	for (::Syntax_Node_ const *_Nonnull const declaration_syntax_ : *(compilation_unit_syntax_->children_))
	{
		declarations_->add_(build_(declaration_syntax_, name_table_, name_table_->any_package_));
	}

	return (new ::Compilation_Unit_())->construct(compilation_unit_syntax_, declarations_);
}

auto ::Semantic_Tree_Builder_::build_(::Syntax_Node_ const *_Nonnull const syntax_, ::Name_Table_ const *_Nonnull const name_table_, ::Name_Subtable_ const *_Nonnull const scope_) const -> ::Semantic_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	if (op_or(syntax_->kind_->op_equal(FunctionDeclaration_), [&] { return syntax_->kind_->op_equal(MethodDeclaration_); }).value)
	{
		children_->add_(build_(syntax_->access_modifier_(), name_table_, scope_));
		::Syntax_Node_ const *_Nonnull const function_name_ = syntax_->first_child_(Identifier_);
		children_->add_(build_(function_name_, name_table_, scope_));
		::Name_Subtable_ *_Nonnull const function_scope_ = scope_->find_(function_name_->get_text_());
		assert_(function_scope_->op_not_equal(p_none), p_string("function_name.get_text()=").op_add(function_name_->get_text_()));
		::Syntax_Node_ const *_Nonnull const parameters_ = syntax_->first_child_(ParameterList_);
		children_->add_(build_parameters_(parameters_, name_table_, function_scope_));
		::Syntax_Node_ const *_Nonnull const return_type_ = syntax_->children_->op_Element(p_int(4));
		children_->add_(build_type_name_(return_type_, name_table_, scope_));
		::Type_ const *_Nonnull const function_type_ = (new ::Type_())->construct(FunctionType_, function_scope_->name_, p_bool(false));
		function_scope_->bind_type_(function_type_);
		::Syntax_Node_ const *_Nonnull const body_ = syntax_->first_child_(Block_);
		if (body_->op_not_equal(p_none).value)
		{
			children_->add_(build_(body_, name_table_, function_scope_));
		}

		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
	else if (op_or(syntax_->kind_->op_equal(ClassDeclaration_), [&] { return syntax_->kind_->op_equal(StructDeclaration_); }).value)
	{
		::Syntax_Node_ const *_Nonnull const type_name_ = syntax_->first_child_(Identifier_);
		children_->add_(build_(type_name_, name_table_, scope_));
		::Name_Subtable_ const *_Nonnull const type_scope_ = scope_->find_(type_name_->get_text_());
		assert_(type_scope_->op_not_equal(p_none), p_string("type_name.get_text()=").op_add(type_name_->get_text_()));
		for (::Syntax_Node_ const *_Nonnull const member_ : *(syntax_->members_()))
		{
			children_->add_(build_(member_, name_table_, type_scope_));
		}

		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
	else if (syntax_->kind_->op_equal(ConstructorDeclaration_).value)
	{
		children_->add_(build_(syntax_->access_modifier_(), name_table_, scope_));
		p_string full_name_ = p_string("new");
		::Syntax_Node_ const *_Nullable const constructor_name_ = syntax_->first_child_(Identifier_);
		if (constructor_name_->op_not_equal(p_none).value)
		{
			full_name_ = p_string("new_").op_add(constructor_name_->get_text_());
			children_->add_((new ::Semantic_Node_())->construct_token(constructor_name_));
		}

		::Name_Subtable_ const *_Nonnull const constructor_scope_ = scope_->find_special_(full_name_);
		assert_(constructor_scope_->op_not_equal(p_none), p_string("full_name=").op_add(full_name_));
		::Syntax_Node_ const *_Nonnull const parameters_ = syntax_->first_child_(ParameterList_);
		children_->add_(build_parameters_(parameters_, name_table_, constructor_scope_));
		::Syntax_Node_ const *_Nonnull const body_ = syntax_->first_child_(Block_);
		if (body_->op_not_equal(p_none).value)
		{
			children_->add_(build_(body_, name_table_, constructor_scope_));
		}

		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
	else if (syntax_->kind_->op_equal(IdentifierName_).value)
	{
		::Name_Subtable_ const *_Nonnull const name_scope_ = scope_->lookup_(syntax_->get_text_());
		if (name_scope_->op_equal(p_none).value)
		{
			::Semantic_Node_ *_Nonnull const node_ = (new ::Semantic_Node_())->construct_token(syntax_);
			if (syntax_->is_missing_->op_not().value)
			{
				add_resolution_error_(node_);
			}

			return node_;
		}
		else
		{
			p_int const place_ = syntax_->start_;
			if (name_scope_->type_->op_equal(p_none).value)
			{
				return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
			}
			else
			{
				return (new ::Semantic_Node_())->construct_of_type(name_scope_->type_, syntax_, children_);
			}
		}
	}
	else if (syntax_->kind_->op_equal(MemberAccessExpression_).value)
	{
		children_->add_(build_(syntax_->children_->op_Element(p_int(0)), name_table_, scope_));
		children_->add_((new ::Semantic_Node_())->construct_token(syntax_->children_->op_Element(p_int(2))));
		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
	else if (syntax_->kind_->op_equal(NewExpression_).value)
	{
		children_->add_(build_constructor_name_(syntax_->children_->op_Element(p_int(1)), name_table_, scope_));
		children_->add_(build_(syntax_->first_child_(ArgumentList_), name_table_, scope_));
		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
	else if (syntax_->kind_->op_equal(LocalDeclarationStatement_).value)
	{
		::Syntax_Node_ const *_Nonnull const variable_declaration_ = syntax_->first_child_(VariableDeclaration_);
		children_->add_(build_(variable_declaration_, name_table_, scope_));
		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
	else if (syntax_->kind_->op_equal(VariableDeclaration_).value)
	{
		::Syntax_Node_ const *_Nonnull const binding_syntax_ = syntax_->children_->op_Element(p_int(0));
		children_->add_((new ::Semantic_Node_())->construct_token(binding_syntax_));
		::Syntax_Node_ const *_Nonnull const identifier_ = syntax_->first_child_(Identifier_);
		children_->add_((new ::Semantic_Node_())->construct_token(identifier_));
		::Syntax_Node_ const *_Nonnull const type_syntax_ = syntax_->children_->op_Element(p_int(3));
		::Semantic_Node_ const *_Nonnull const type_node_ = build_type_name_(type_syntax_, name_table_, scope_);
		assert_(type_node_->referenced_type_->op_not_equal(p_none), type_node_->get_text_());
		::Name_Subtable_ *_Nonnull const variable_scope_ = scope_->lookup_(identifier_->get_text_());
		assert_(variable_scope_->op_not_equal(p_none), syntax_->get_text_());
		variable_scope_->bind_type_(type_node_->referenced_type_);
		children_->add_(type_node_);
		if (syntax_->children_->op_magnitude()->op_equal(p_int(6)).value)
		{
			::Syntax_Node_ const *_Nonnull const initalizer_ = syntax_->children_->op_Element(p_int(5));
			children_->add_(build_(initalizer_, name_table_, scope_));
		}

		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
	else if (op_or(syntax_->kind_->op_equal(TrueLiteralExpression_), [&] { return syntax_->kind_->op_equal(FalseLiteralExpression_); }).value)
	{
		return (new ::Semantic_Node_())->construct_of_type(scope_->lookup_special_(p_string("bool"))->type_, syntax_, children_);
	}
	else if (syntax_->kind_->op_equal(StringLiteralExpression_).value)
	{
		return (new ::Semantic_Node_())->construct_of_type(scope_->lookup_special_(p_string("string"))->type_, syntax_, children_);
	}
	else if (syntax_->kind_->op_equal(CodePointLiteralExpression_).value)
	{
		return (new ::Semantic_Node_())->construct_of_type(scope_->lookup_special_(p_string("code_point"))->type_, syntax_, children_);
	}
	else if (syntax_->kind_->op_equal(NumericLiteralExpression_).value)
	{
		return (new ::Semantic_Node_())->construct_of_type(scope_->lookup_special_(p_string("int"))->type_, syntax_, children_);
	}
	else if (syntax_->children_->op_magnitude()->op_equal(p_int(0)).value)
	{
		return (new ::Semantic_Node_())->construct_token(syntax_);
	}
	else
	{
		for (::Syntax_Node_ const *_Nonnull const child_syntax_ : *(syntax_->children_))
		{
			children_->add_(build_(child_syntax_, name_table_, scope_));
		}

		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
}

auto ::Semantic_Tree_Builder_::build_parameters_(::Syntax_Node_ const *_Nonnull const parameters_syntax_, ::Name_Table_ const *_Nonnull const name_table_, ::Name_Subtable_ const *_Nonnull const scope_) const -> ::Semantic_Node_ *_Nonnull
{
	auto self = this;
	assert_(parameters_syntax_->kind_->op_equal(ParameterList_), p_string("parameters_syntax.kind=").op_add(parameters_syntax_->kind_));
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const parameters_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	for (::Syntax_Node_ const *_Nonnull const parameter_ : *(parameters_syntax_->parameters_()))
	{
		::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
		if (parameter_->kind_->op_equal(Parameter_).value)
		{
			::Syntax_Node_ const *_Nullable const var_syntax_ = parameter_->first_child_(VarKeyword_);
			if (var_syntax_->op_not_equal(p_none).value)
			{
				children_->add_((new ::Semantic_Node_())->construct_token(var_syntax_));
			}

			::Syntax_Node_ const *_Nonnull const identifier_ = parameter_->first_child_(Identifier_);
			children_->add_((new ::Semantic_Node_())->construct_token(identifier_));
			::Syntax_Node_ const *_Nonnull const type_syntax_ = parameter_->children_->op_Element(parameter_->children_->op_magnitude()->op_subtract(p_int(1)));
			::Semantic_Node_ const *_Nonnull const type_node_ = build_type_name_(type_syntax_, name_table_, scope_);
			assert_(type_node_->referenced_type_->op_not_equal(p_none), parameter_->get_text_());
			children_->add_(type_node_);
			::Name_Subtable_ *_Nonnull const parameter_scope_ = scope_->lookup_(identifier_->get_text_());
			assert_(parameter_scope_->op_not_equal(p_none), identifier_->get_text_());
			parameter_scope_->bind_type_(type_node_->referenced_type_);
			parameters_->add_((new ::Semantic_Node_())->construct_of_type(type_node_->referenced_type_, parameter_, children_));
		}
		else if (parameter_->kind_->op_equal(SelfParameter_).value)
		{
			for (::Syntax_Node_ const *_Nonnull const child_syntax_ : *(parameter_->children_))
			{
				children_->add_((new ::Semantic_Node_())->construct_token(child_syntax_));
			}

			parameters_->add_((new ::Semantic_Node_())->construct_concrete(parameter_, children_));
		}
		else
		{
			NOT_IMPLEMENTED_(p_string("parameter.kind=").op_add(parameter_->kind_));
		}
	}

	return (new ::Semantic_Node_())->construct_concrete(parameters_syntax_, parameters_);
}

auto ::Semantic_Tree_Builder_::build_type_name_(::Syntax_Node_ const *_Nonnull const syntax_, ::Name_Table_ const *_Nonnull const name_table_, ::Name_Subtable_ const *_Nonnull const scope_) const -> ::Semantic_Node_ *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	if (syntax_->kind_->op_equal(PredefinedType_).value)
	{
		p_string const primitive_name_ = syntax_->children_->op_Element(p_int(0))->get_text_();
		::Name_Subtable_ const *_Nullable const primitive_entry_ = scope_->lookup_special_(primitive_name_);
		assert_(primitive_entry_->op_not_equal(p_none), p_string("No entry for primitive `").op_add(primitive_name_)->op_add(p_string("`")));
		return (new ::Semantic_Node_())->construct_referencing_type(primitive_entry_->type_, syntax_, children_);
	}
	else if (syntax_->kind_->op_equal(IdentifierName_).value)
	{
		if (syntax_->is_missing_.value)
		{
			return (new ::Semantic_Node_())->construct_token(syntax_);
		}

		p_string const name_ = syntax_->get_text_();
		::Name_Subtable_ const *_Nullable const entry_ = scope_->lookup_(name_);
		if (entry_->op_equal(p_none).value)
		{
			::Semantic_Node_ *_Nonnull const node_ = (new ::Semantic_Node_())->construct_token(syntax_);
			add_resolution_error_(node_);
			return node_;
		}
		else
		{
			return (new ::Semantic_Node_())->construct_referencing_type(entry_->type_, syntax_, children_);
		}
	}
	else if (syntax_->kind_->op_equal(QualifiedName_).value)
	{
		::Syntax_Node_ const *_Nonnull const qualifier_syntax_ = syntax_->children_->op_Element(p_int(0));
		::Semantic_Node_ *_Nonnull const qualifier_ = build_type_name_(qualifier_syntax_, name_table_, scope_);
		children_->add_(qualifier_);
		::Syntax_Node_ const *_Nonnull const qualified_syntax_ = syntax_->children_->op_Element(p_int(2));
		if (qualified_syntax_->kind_->op_equal(IdentifierName_).value)
		{
			::Syntax_Node_ const *_Nonnull const name_syntax_ = qualified_syntax_;
			if (qualifier_->referenced_type_->op_equal(p_none).value)
			{
				add_could_not_determine_type_error_(qualifier_);
				::Semantic_Node_ *_Nonnull const name_node_ = (new ::Semantic_Node_())->construct_token(name_syntax_);
				add_resolution_error_(name_node_, qualifier_);
				children_->add_(name_node_);
				return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
			}
			else
			{
				::Type_ const *_Nonnull const containing_type_ = qualifier_->referenced_type_;
				::Name_Subtable_ const *_Nonnull const containing_scope_ = name_table_->get_(containing_type_->name_);
				assert_(containing_scope_->op_not_equal(p_none), containing_type_->name_->full_());
				::Name_Subtable_ const *_Nonnull const referenced_scope_ = containing_scope_->find_(name_syntax_->get_text_());
				if (referenced_scope_->op_equal(p_none).value)
				{
					::Semantic_Node_ *_Nonnull const name_node_ = (new ::Semantic_Node_())->construct_token(name_syntax_);
					add_resolution_error_(name_node_, qualifier_);
					children_->add_(name_node_);
					return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
				}

				::Type_ const *_Nonnull const referenced_type_ = referenced_scope_->type_;
				::Semantic_Node_ const *_Nonnull const name_node_ = (new ::Semantic_Node_())->construct_referencing_type(referenced_type_, name_syntax_, (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct());
				children_->add_(name_node_);
				return (new ::Semantic_Node_())->construct_referencing_type(referenced_type_, syntax_, children_);
			}
		}
		else if (qualified_syntax_->kind_->op_equal(GenericName_).value)
		{
			::Syntax_Node_ const *_Nonnull const name_syntax_ = qualified_syntax_->first_child_(IdentifierName_);
			::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const generic_name_children_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
			if (qualifier_->referenced_type_->op_equal(p_none).value)
			{
				add_could_not_determine_type_error_(qualifier_);
				::Semantic_Node_ *_Nonnull const name_node_ = (new ::Semantic_Node_())->construct_token(name_syntax_);
				add_resolution_error_(name_node_, qualifier_);
				generic_name_children_->add_(name_node_);
				build_type_arguments_(qualified_syntax_, name_table_, scope_, generic_name_children_);
				::Semantic_Node_ *_Nonnull const qualified_name_ = (new ::Semantic_Node_())->construct_concrete(qualified_syntax_, generic_name_children_);
				children_->add_(qualified_name_);
				return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
			}
			else
			{
				::Type_ const *_Nonnull const containing_type_ = qualifier_->referenced_type_;
				::Name_Subtable_ const *_Nonnull const containing_scope_ = name_table_->get_(containing_type_->name_);
				assert_(containing_scope_->op_not_equal(p_none), containing_type_->name_->full_());
				::Name_Subtable_ const *_Nonnull const referenced_scope_ = containing_scope_->find_(name_syntax_->get_text_());
				if (referenced_scope_->op_equal(p_none).value)
				{
					::Semantic_Node_ *_Nonnull const name_node_ = (new ::Semantic_Node_())->construct_token(name_syntax_);
					add_resolution_error_(name_node_, qualifier_);
					generic_name_children_->add_(name_node_);
					build_type_arguments_(qualified_syntax_, name_table_, scope_, generic_name_children_);
					::Semantic_Node_ *_Nonnull const qualified_name_ = (new ::Semantic_Node_())->construct_concrete(qualified_syntax_, generic_name_children_);
					children_->add_(qualified_name_);
					return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
				}

				::Type_ const *_Nonnull const referenced_type_name_ = referenced_scope_->type_;
				::Semantic_Node_ const *_Nonnull const name_node_ = (new ::Semantic_Node_())->construct_referencing_type(referenced_type_name_, name_syntax_, (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct());
				generic_name_children_->add_(name_node_);
				::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_ = build_type_arguments_(qualified_syntax_, name_table_, scope_, generic_name_children_);
				::Type_ const *_Nonnull const referenced_type_ = (new ::Type_())->construct_generic(referenced_type_name_, type_parameters_);
				::Semantic_Node_ *_Nonnull const qualified_name_ = (new ::Semantic_Node_())->construct_referencing_type(referenced_type_, qualified_syntax_, generic_name_children_);
				children_->add_(qualified_name_);
				return (new ::Semantic_Node_())->construct_referencing_type(referenced_type_, syntax_, children_);
			}
		}
		else
		{
			UNREACHABLE_();
		}

		UNREACHABLE_();
	}
	else if (syntax_->kind_->op_equal(MutableType_).value)
	{
		::Semantic_Node_ *_Nonnull const inner_type_ = build_type_name_(syntax_->children_->op_Element(p_int(1)), name_table_, scope_);
		children_->add_(inner_type_);
		if (inner_type_->referenced_type_->op_equal(p_none).value)
		{
			add_could_not_determine_type_error_(inner_type_);
			return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
		}

		::Type_ const *_Nonnull const type_ = inner_type_->referenced_type_->make_mutable_();
		return (new ::Semantic_Node_())->construct_referencing_type(type_, syntax_, children_);
	}
	else if (syntax_->kind_->op_equal(ImmutableType_).value)
	{
		::Semantic_Node_ *_Nonnull const inner_type_ = build_type_name_(syntax_->children_->op_Element(p_int(0)), name_table_, scope_);
		children_->add_(inner_type_);
		if (inner_type_->referenced_type_->op_equal(p_none).value)
		{
			add_could_not_determine_type_error_(inner_type_);
			return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
		}

		::Type_ const *_Nonnull const type_ = inner_type_->referenced_type_->make_immutable_();
		return (new ::Semantic_Node_())->construct_referencing_type(type_, syntax_, children_);
	}
	else if (syntax_->kind_->op_equal(OptionalType_).value)
	{
		::Semantic_Node_ *_Nonnull const inner_type_ = build_type_name_(syntax_->children_->op_Element(p_int(0)), name_table_, scope_);
		children_->add_(inner_type_);
		if (inner_type_->referenced_type_->op_equal(p_none).value)
		{
			add_could_not_determine_type_error_(inner_type_);
			return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
		}

		::Name_Subtable_ const *_Nullable const optional_type_scope_ = name_table_->get_(optional_type_name_);
		assert_(optional_type_scope_->op_not_equal(p_none), p_string(""));
		::Type_ const *_Nonnull const optional_type_ = optional_type_scope_->type_;
		::System_::Collections_::List_<::Type_ const *_Nonnull> *_Nonnull const type_arguments_ = (new ::System_::Collections_::List_<::Type_ const *_Nonnull>())->construct();
		type_arguments_->add_(inner_type_->referenced_type_);
		::Type_ const *_Nonnull const type_ = (new ::Type_())->construct_generic(optional_type_, type_arguments_);
		return (new ::Semantic_Node_())->construct_referencing_type(type_, syntax_, children_);
	}
	else
	{
		p_int const place_ = syntax_->start_;
		NOT_IMPLEMENTED_(p_string("syntax.kind=").op_add(syntax_->kind_)->op_add(p_string(" at "))->op_add(place_));
	}
}

auto ::Semantic_Tree_Builder_::build_type_arguments_(::Syntax_Node_ const *_Nonnull const syntax_, ::Name_Table_ const *_Nonnull const name_table_, ::Name_Subtable_ const *_Nonnull const scope_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const children_) const -> ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Type_ const *_Nonnull> *_Nonnull const type_parameters_ = (new ::System_::Collections_::List_<::Type_ const *_Nonnull>())->construct();
	if (syntax_->kind_->op_equal(IdentifierName_).value)
	{
		return type_parameters_;
	}

	assert_(syntax_->kind_->op_equal(GenericName_), p_string("syntax.kind==").op_add(syntax_->kind_));
	p_bool in_type_arguments_ = p_bool(false);
	for (::Syntax_Node_ const *_Nonnull const type_argument_ : *(syntax_->children_))
	{
		if (in_type_arguments_.value)
		{
			if (type_argument_->kind_->op_not_equal(GreaterThan_).value)
			{
				::Semantic_Node_ const *_Nonnull const type_node_ = build_type_name_(type_argument_, name_table_, scope_);
				type_parameters_->add_(type_node_->referenced_type_);
				children_->add_(type_node_);
			}
		}
		else if (type_argument_->kind_->op_equal(LessThan_).value)
		{
			in_type_arguments_ = p_bool(true);
		}
	}

	return type_parameters_;
}

auto ::Semantic_Tree_Builder_::build_constructor_name_(::Syntax_Node_ const *_Nonnull const syntax_, ::Name_Table_ const *_Nonnull const name_table_, ::Name_Subtable_ const *_Nonnull const scope_) const -> ::Semantic_Node_ const *_Nonnull
{
	auto self = this;
	if (op_and(syntax_->kind_->op_equal(QualifiedName_), [&] { return syntax_->children_->op_Element(p_int(2))->kind_->op_equal(IdentifierName_); }).value)
	{
		::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
		::Semantic_Node_ const *_Nonnull const type_node_ = build_type_name_(syntax_->children_->op_Element(p_int(0)), name_table_, scope_);
		children_->add_(type_node_);
		::Syntax_Node_ const *_Nonnull const qualifier_ = syntax_->children_->op_Element(p_int(0));
		::Syntax_Node_ const *_Nonnull const name_ = syntax_->children_->op_Element(p_int(2));
		p_string const constructor_name_ = p_string("new_").op_add(name_->get_text_());
		::Type_ const *_Nonnull const referenced_type_ = type_node_->referenced_type_;
		assert_(referenced_type_->op_not_equal(p_none), p_string("no referenced type for `").op_add(type_node_->get_text_())->op_add(p_string("`")));
		::Name_Subtable_ const *_Nullable const constructor_scope_ = name_table_->get_(referenced_type_->name_)->lookup_special_(constructor_name_);
		if (constructor_scope_->op_not_equal(p_none).value)
		{
			children_->add_((new ::Semantic_Node_())->construct_token(name_));
			return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
		}
	}

	return build_type_name_(syntax_, name_table_, scope_);
}

auto ::Semantic_Tree_Builder_::add_resolution_error_(::Semantic_Node_ *_Nonnull const node_) -> void
{
	node_->add_((new ::Diagnostic_())->construct(FatalCompilationError_, Analysis_, node_->source_, node_->get_text_span_(), p_string("Could not resolve name `").op_add(node_->get_text_())->op_add(p_string("`"))));
}

auto ::Semantic_Tree_Builder_::add_resolution_error_(::Semantic_Node_ *_Nonnull const node_, ::Semantic_Node_ const *_Nonnull const qualifier_) -> void
{
	node_->add_((new ::Diagnostic_())->construct(FatalCompilationError_, Analysis_, node_->source_, node_->get_text_span_(), p_string("Could not resolve name `").op_add(node_->get_text_())->op_add(p_string("` because qualifier `"))->op_add(qualifier_->get_text_())->op_add(p_string("` could not be resolved."))));
}

auto ::Semantic_Tree_Builder_::add_could_not_determine_type_error_(::Semantic_Node_ *_Nonnull const node_) -> void
{
	node_->add_((new ::Diagnostic_())->construct(FatalCompilationError_, Analysis_, node_->source_, node_->get_text_span_(), p_string("Could not determine type for `").op_add(node_->get_text_())->op_add(p_string("`"))));
}

auto ::Symbol_Builder_::build_(::Package_Name_ const *_Nonnull const package_name_, ::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull> const *_Nonnull const compilation_units_) -> ::Symbol_ const *_Nonnull
{
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return (new ::Symbol_())->construct_package(package_name_->unqualified_, symbols_);
}

auto ::Compilation_Unit_Parser_::construct(::Token_Stream_ *_Nonnull const tokenStream_) -> ::Compilation_Unit_Parser_*
{
	::Compilation_Unit_Parser_* self = this;
	self->tokenStream_ = tokenStream_;
	self->compilationUnit_ = p_none;
	return self;
}

auto ::Compilation_Unit_Parser_::Parse_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	if (compilationUnit_->op_equal(p_none).value)
	{
		token_ = tokenStream_->GetNextToken_();
		compilationUnit_ = ParseCompilationUnit_();
	}

	return compilationUnit_;
}

auto ::Compilation_Unit_Parser_::AcceptToken_() -> ::Syntax_Node_ const *_Nullable
{
	auto self = this;
	::Syntax_Node_ const *_Nullable const node_ = token_;
	token_ = tokenStream_->GetNextToken_();
	return node_;
}

auto ::Compilation_Unit_Parser_::ExpectToken_(p_int const tokenType_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	if (token_->op_equal(p_none).value)
	{
		return new_syntax_node_missing_(tokenType_, tokenStream_->source_, tokenStream_->source_->ByteLength_());
	}

	if (op_or(token_->op_equal(p_none), [&] { return token_->kind_->op_not_equal(tokenType_); }).value)
	{
		return new_syntax_node_missing_(tokenType_, tokenStream_->source_, token_->start_);
	}

	::Syntax_Node_ const *_Nullable const node_ = token_;
	token_ = tokenStream_->GetNextToken_();
	return node_;
}

auto ::Compilation_Unit_Parser_::ParseTypeName_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	if (op_or(op_or(op_or(op_or(op_or(token_->kind_->op_equal(CodePoint_), [&] { return token_->kind_->op_equal(String_); }), [&] { return token_->kind_->op_equal(Int_); }), [&] { return token_->kind_->op_equal(Bool_); }), [&] { return token_->kind_->op_equal(Void_); }), [&] { return token_->kind_->op_equal(UnsignedInt_); }).value)
	{
		return (new ::Syntax_Node_())->construct(PredefinedType_, AcceptToken_());
	}
	else
	{
		::Syntax_Node_ const *_Nonnull type_ = (new ::Syntax_Node_())->construct(IdentifierName_, ExpectToken_(Identifier_));
		while (token_->kind_->op_equal(Dot_).value)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
			children_->Add_(type_);
			children_->Add_(ExpectToken_(Dot_));
			::Syntax_Node_ const *_Nonnull const identifier_ = ExpectToken_(Identifier_);
			if (token_->kind_->op_equal(LessThan_).value)
			{
				::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const genericNameChildren_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
				genericNameChildren_->Add_((new ::Syntax_Node_())->construct(IdentifierName_, identifier_));
				genericNameChildren_->Add_(ExpectToken_(LessThan_));
				genericNameChildren_->Add_(ParseType_());
				genericNameChildren_->Add_(ExpectToken_(GreaterThan_));
				children_->Add_((new ::Syntax_Node_())->construct(GenericName_, genericNameChildren_));
			}
			else
			{
				children_->Add_((new ::Syntax_Node_())->construct(IdentifierName_, identifier_));
			}

			type_ = (new ::Syntax_Node_())->construct(QualifiedName_, children_);
		}

		return type_;
	}
}

auto ::Compilation_Unit_Parser_::ParseNonOptionalType_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	if (token_->kind_->op_equal(MutableKeyword_).value)
	{
		children_->Add_(ExpectToken_(MutableKeyword_));
		children_->Add_(ParseTypeName_());
		return (new ::Syntax_Node_())->construct(MutableType_, children_);
	}
	else
	{
		children_->Add_(ParseTypeName_());
		return (new ::Syntax_Node_())->construct(ImmutableType_, children_);
	}
}

auto ::Compilation_Unit_Parser_::ParseType_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::Syntax_Node_ const *_Nonnull type_ = ParseNonOptionalType_();
	while (token_->kind_->op_equal(Question_).value)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
		children_->Add_(type_);
		children_->Add_(ExpectToken_(Question_));
		type_ = (new ::Syntax_Node_())->construct(ImmutableType_, (new ::Syntax_Node_())->construct(OptionalType_, children_));
	}

	return type_;
}

auto ::Compilation_Unit_Parser_::ParseAtom_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	if (token_->kind_->op_equal(NewKeyword_).value)
	{
		children_->Add_(ExpectToken_(NewKeyword_));
		children_->Add_(ParseTypeName_());
		children_->Add_(ParseCallArguments_());
		return (new ::Syntax_Node_())->construct(NewExpression_, children_);
	}

	if (token_->kind_->op_equal(NotOperator_).value)
	{
		children_->Add_(ExpectToken_(NotOperator_));
		children_->Add_(ParseExpression_(p_int(8)));
		return (new ::Syntax_Node_())->construct(NotExpression_, children_);
	}

	if (token_->kind_->op_equal(LeftParen_).value)
	{
		children_->Add_(ExpectToken_(LeftParen_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(RightParen_));
		return (new ::Syntax_Node_())->construct(ParenthesizedExpression_, children_);
	}

	if (token_->kind_->op_equal(Pipe_).value)
	{
		children_->Add_(ExpectToken_(Pipe_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(Pipe_));
		return (new ::Syntax_Node_())->construct(MagnitudeExpression_, children_);
	}

	if (token_->kind_->op_equal(Minus_).value)
	{
		children_->Add_(ExpectToken_(Minus_));
		children_->Add_(ParseExpression_(p_int(8)));
		return (new ::Syntax_Node_())->construct(NegateExpression_, children_);
	}

	if (token_->kind_->op_equal(NoneKeyword_).value)
	{
		children_->Add_(ExpectToken_(NoneKeyword_));
		return (new ::Syntax_Node_())->construct(NoneLiteralExpression_, children_);
	}

	if (token_->kind_->op_equal(SelfKeyword_).value)
	{
		children_->Add_(ExpectToken_(SelfKeyword_));
		return (new ::Syntax_Node_())->construct(SelfExpression_, children_);
	}

	if (token_->kind_->op_equal(TrueKeyword_).value)
	{
		children_->Add_(ExpectToken_(TrueKeyword_));
		return (new ::Syntax_Node_())->construct(TrueLiteralExpression_, children_);
	}

	if (token_->kind_->op_equal(FalseKeyword_).value)
	{
		children_->Add_(ExpectToken_(FalseKeyword_));
		return (new ::Syntax_Node_())->construct(FalseLiteralExpression_, children_);
	}

	if (token_->kind_->op_equal(Number_).value)
	{
		children_->Add_(ExpectToken_(Number_));
		return (new ::Syntax_Node_())->construct(NumericLiteralExpression_, children_);
	}

	if (token_->kind_->op_equal(Identifier_).value)
	{
		children_->Add_(ExpectToken_(Identifier_));
		return (new ::Syntax_Node_())->construct(IdentifierName_, children_);
	}

	if (token_->kind_->op_equal(StringLiteral_).value)
	{
		children_->Add_(ExpectToken_(StringLiteral_));
		return (new ::Syntax_Node_())->construct(StringLiteralExpression_, children_);
	}

	if (token_->kind_->op_equal(CodePointLiteral_).value)
	{
		children_->Add_(ExpectToken_(CodePointLiteral_));
		return (new ::Syntax_Node_())->construct(CodePointLiteralExpression_, children_);
	}

	return (new ::Syntax_Node_())->construct(IdentifierName_, ExpectToken_(Identifier_));
}

auto ::Compilation_Unit_Parser_::ParseCallArguments_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	children_->Add_(ExpectToken_(LeftParen_));
	if (token_->kind_->op_not_equal(RightParen_).value)
	{
		for (;;)
		{
			children_->Add_(ParseExpression_());
			if (token_->kind_->op_equal(Comma_).value)
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
	return (new ::Syntax_Node_())->construct(ArgumentList_, children_);
}

auto ::Compilation_Unit_Parser_::ParseExpression_(p_int const minPrecedence_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::Syntax_Node_ const *_Nonnull expression_ = ParseAtom_();
	for (;;)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
		children_->Add_(expression_);
		p_int precedence_;
		p_bool leftAssociative_;
		p_bool suffixOperator_ = p_bool(false);
		p_int expressionType_;
		if (op_and(op_or(op_or(token_->kind_->op_equal(Equals_), [&] { return token_->kind_->op_equal(PlusEquals_); }), [&] { return token_->kind_->op_equal(MinusEquals_); }), [&] { return minPrecedence_.op_less_than_or_equal(p_int(1)); }).value)
		{
			precedence_ = p_int(1);
			leftAssociative_ = p_bool(false);
			children_->Add_(AcceptToken_());
			expressionType_ = AssignmentExpression_;
		}
		else if (op_and(token_->kind_->op_equal(OrKeyword_), [&] { return minPrecedence_.op_less_than_or_equal(p_int(2)); }).value)
		{
			precedence_ = p_int(2);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(OrKeyword_));
			expressionType_ = OrExpression_;
		}
		else if (op_and(token_->kind_->op_equal(AndKeyword_), [&] { return minPrecedence_.op_less_than_or_equal(p_int(3)); }).value)
		{
			precedence_ = p_int(3);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(AndKeyword_));
			expressionType_ = AndExpression_;
		}
		else if (op_and(token_->kind_->op_equal(EqualsEquals_), [&] { return minPrecedence_.op_less_than_or_equal(p_int(4)); }).value)
		{
			precedence_ = p_int(4);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(EqualsEquals_));
			expressionType_ = EqualExpression_;
		}
		else if (op_and(token_->kind_->op_equal(EqualsSlashEquals_), [&] { return minPrecedence_.op_less_than_or_equal(p_int(4)); }).value)
		{
			precedence_ = p_int(4);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(EqualsSlashEquals_));
			expressionType_ = NotEqualExpression_;
		}
		else if (op_and(op_or(op_or(op_or(token_->kind_->op_equal(LessThan_), [&] { return token_->kind_->op_equal(LessThanEquals_); }), [&] { return token_->kind_->op_equal(GreaterThan_); }), [&] { return token_->kind_->op_equal(GreaterThanEquals_); }), [&] { return minPrecedence_.op_less_than_or_equal(p_int(5)); }).value)
		{
			precedence_ = p_int(5);
			leftAssociative_ = p_bool(true);
			children_->Add_(AcceptToken_());
			expressionType_ = ComparisonExpression_;
		}
		else if (op_and(token_->kind_->op_equal(Plus_), [&] { return minPrecedence_.op_less_than_or_equal(p_int(6)); }).value)
		{
			precedence_ = p_int(6);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Plus_));
			expressionType_ = AddExpression_;
		}
		else if (op_and(token_->kind_->op_equal(Minus_), [&] { return minPrecedence_.op_less_than_or_equal(p_int(6)); }).value)
		{
			precedence_ = p_int(6);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Minus_));
			expressionType_ = SubtractExpression_;
		}
		else if (op_and(token_->kind_->op_equal(Asterisk_), [&] { return minPrecedence_.op_less_than_or_equal(p_int(7)); }).value)
		{
			precedence_ = p_int(7);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Asterisk_));
			expressionType_ = MultiplyExpression_;
		}
		else if (op_and(token_->kind_->op_equal(Slash_), [&] { return minPrecedence_.op_less_than_or_equal(p_int(7)); }).value)
		{
			precedence_ = p_int(7);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Slash_));
			expressionType_ = DivideExpression_;
		}
		else if (op_and(token_->kind_->op_equal(Percent_), [&] { return minPrecedence_.op_less_than_or_equal(p_int(7)); }).value)
		{
			precedence_ = p_int(7);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Percent_));
			expressionType_ = RemainderExpression_;
		}
		else if (op_and(token_->kind_->op_equal(LeftParen_), [&] { return minPrecedence_.op_less_than_or_equal(p_int(9)); }).value)
		{
			precedence_ = p_int(9);
			leftAssociative_ = p_bool(true);
			suffixOperator_ = p_bool(true);
			children_->Add_(ParseCallArguments_());
			expressionType_ = InvocationExpression_;
		}
		else if (op_and(token_->kind_->op_equal(Dot_), [&] { return minPrecedence_.op_less_than_or_equal(p_int(9)); }).value)
		{
			precedence_ = p_int(9);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Dot_));
			expressionType_ = MemberAccessExpression_;
		}
		else if (op_and(token_->kind_->op_equal(LeftBracket_), [&] { return minPrecedence_.op_less_than_or_equal(p_int(9)); }).value)
		{
			precedence_ = p_int(9);
			leftAssociative_ = p_bool(true);
			suffixOperator_ = p_bool(true);
			children_->Add_(ExpectToken_(LeftBracket_));
			children_->Add_(ParseExpression_());
			children_->Add_(ExpectToken_(RightBracket_));
			expressionType_ = ElementAccessExpression_;
		}
		else
		{
			return expression_;
		}

		if (suffixOperator_.op_not().value)
		{
			if (leftAssociative_.value)
			{
				precedence_.op_add_assign(p_int(1));
			}

			children_->Add_(ParseExpression_(precedence_));
			expression_ = (new ::Syntax_Node_())->construct(expressionType_, children_);
		}
		else
		{
			expression_ = (new ::Syntax_Node_())->construct(expressionType_, children_);
		}
	}
}

auto ::Compilation_Unit_Parser_::ParseExpression_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	return ParseExpression_(p_int(1));
}

auto ::Compilation_Unit_Parser_::ParseStatement_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	if (token_->kind_->op_equal(ReturnKeyword_).value)
	{
		children_->Add_(ExpectToken_(ReturnKeyword_));
		if (token_->kind_->op_not_equal(Semicolon_).value)
		{
			children_->Add_(ParseExpression_());
		}

		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(ReturnStatement_, children_);
	}

	if (token_->kind_->op_equal(LoopKeyword_).value)
	{
		children_->Add_(ExpectToken_(LoopKeyword_));
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_())->construct(LoopStatement_, children_);
	}

	if (token_->kind_->op_equal(WhileKeyword_).value)
	{
		children_->Add_(ExpectToken_(WhileKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_())->construct(WhileStatement_, children_);
	}

	if (token_->kind_->op_equal(ForKeyword_).value)
	{
		children_->Add_(ExpectToken_(ForKeyword_));
		children_->Add_(ParseVariableDeclaration_(p_bool(false)));
		children_->Add_(ExpectToken_(InKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_())->construct(ForStatement_, children_);
	}

	if (token_->kind_->op_equal(DoKeyword_).value)
	{
		children_->Add_(ExpectToken_(DoKeyword_));
		children_->Add_(ParseBlock_());
		children_->Add_(ExpectToken_(WhileKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(DoWhileStatement_, children_);
	}

	if (token_->kind_->op_equal(IfKeyword_).value)
	{
		return ParseIfStatement_();
	}

	if (token_->kind_->op_equal(BreakKeyword_).value)
	{
		children_->Add_(ExpectToken_(BreakKeyword_));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(BreakStatement_, children_);
	}

	if (token_->kind_->op_equal(ContinueKeyword_).value)
	{
		children_->Add_(ExpectToken_(ContinueKeyword_));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(ContinueStatement_, children_);
	}

	if (op_or(token_->kind_->op_equal(VarKeyword_), [&] { return token_->kind_->op_equal(LetKeyword_); }).value)
	{
		children_->Add_(ParseVariableDeclaration_(p_bool(true)));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(LocalDeclarationStatement_, children_);
	}

	if (token_->kind_->op_equal(LeftBrace_).value)
	{
		return ParseBlock_();
	}

	children_->Add_(ParseExpression_());
	children_->Add_(ExpectToken_(Semicolon_));
	return (new ::Syntax_Node_())->construct(ExpressionStatement_, children_);
}

auto ::Compilation_Unit_Parser_::ParseIfStatement_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	children_->Add_(ExpectToken_(IfKeyword_));
	children_->Add_(ParseExpression_());
	children_->Add_(ParseBlock_());
	if (token_->kind_->op_equal(ElseKeyword_).value)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const elseChildren_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
		elseChildren_->Add_(ExpectToken_(ElseKeyword_));
		if (token_->kind_->op_equal(IfKeyword_).value)
		{
			elseChildren_->Add_(ParseIfStatement_());
		}
		else
		{
			elseChildren_->Add_(ParseBlock_());
		}

		children_->Add_((new ::Syntax_Node_())->construct(ElseClause_, elseChildren_));
	}

	return (new ::Syntax_Node_())->construct(IfStatement_, children_);
}

auto ::Compilation_Unit_Parser_::ParseVariableDeclaration_(p_bool const allowInitializer_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	if (op_and(token_->kind_->op_equal(LetKeyword_), [&] { return token_->kind_->op_not_equal(VarKeyword_); }).value)
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
	if (op_and(allowInitializer_, [&] { return token_->kind_->op_equal(Equals_); }).value)
	{
		children_->Add_(ExpectToken_(Equals_));
		children_->Add_(ParseExpression_());
	}

	return (new ::Syntax_Node_())->construct(VariableDeclaration_, children_);
}

auto ::Compilation_Unit_Parser_::ParseBlock_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	children_->Add_(ExpectToken_(LeftBrace_));
	while (op_and(token_->kind_->op_not_equal(RightBrace_), [&] { return token_->kind_->op_not_equal(EndOfFileToken_); }).value)
	{
		::Syntax_Node_ const *_Nonnull const startToken_ = token_;
		children_->Add_(ParseStatement_());
		if (token_->op_equal(startToken_).value)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const skipped_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
			while (op_and(op_and(token_->kind_->op_not_equal(LeftBrace_), [&] { return token_->kind_->op_not_equal(RightBrace_); }), [&] { return token_->kind_->op_not_equal(EndOfFileToken_); }).value)
			{
				p_int const currentTokenType_ = token_->kind_;
				skipped_->Add_(AcceptToken_());
				if (currentTokenType_.op_equal(Semicolon_).value)
				{
					break;
				}
			}

			children_->Add_(new_Syntax_Node_Skipped_(skipped_));
		}
	}

	children_->Add_(ExpectToken_(RightBrace_));
	return (new ::Syntax_Node_())->construct(Block_, children_);
}

auto ::Compilation_Unit_Parser_::ParseParameterList_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	children_->Add_(ExpectToken_(LeftParen_));
	if (token_->kind_->op_not_equal(RightParen_).value)
	{
		for (;;)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const parameterChildren_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
			if (op_or(token_->kind_->op_equal(MutableKeyword_), [&] { return token_->kind_->op_equal(SelfKeyword_); }).value)
			{
				if (token_->kind_->op_equal(MutableKeyword_).value)
				{
					parameterChildren_->Add_(ExpectToken_(MutableKeyword_));
				}

				parameterChildren_->Add_(ExpectToken_(SelfKeyword_));
				children_->Add_((new ::Syntax_Node_())->construct(SelfParameter_, parameterChildren_));
			}
			else
			{
				p_bool const mutableBinding_ = token_->kind_->op_equal(VarKeyword_);
				if (token_->kind_->op_equal(VarKeyword_).value)
				{
					parameterChildren_->Add_(ExpectToken_(VarKeyword_));
				}

				parameterChildren_->Add_(ExpectToken_(Identifier_));
				parameterChildren_->Add_(ExpectToken_(Colon_));
				::Syntax_Node_ const *_Nonnull const type_ = ParseType_();
				parameterChildren_->Add_(type_);
				children_->Add_((new ::Syntax_Node_())->construct(Parameter_, parameterChildren_));
			}

			if (token_->kind_->op_equal(Comma_).value)
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
	return (new ::Syntax_Node_())->construct(ParameterList_, children_);
}

auto ::Compilation_Unit_Parser_::ParseMemberDeclaration_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	if (op_or(op_or(op_or(token_->kind_->op_equal(PublicKeyword_), [&] { return token_->kind_->op_equal(ProtectedKeyword_); }), [&] { return token_->kind_->op_equal(InternalKeyword_); }), [&] { return token_->kind_->op_equal(PrivateKeyword_); }).value)
	{
		children_->Add_(AcceptToken_());
	}
	else
	{
		children_->Add_(ExpectToken_(PublicKeyword_));
	}

	if (token_->kind_->op_equal(NewKeyword_).value)
	{
		children_->Add_(ExpectToken_(NewKeyword_));
		if (token_->kind_->op_equal(Identifier_).value)
		{
			children_->Add_(ExpectToken_(Identifier_));
		}

		children_->Add_(ParseParameterList_());
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_())->construct(ConstructorDeclaration_, children_);
	}

	if (op_or(token_->kind_->op_equal(VarKeyword_), [&] { return token_->kind_->op_equal(LetKeyword_); }).value)
	{
		children_->Add_(ParseVariableDeclaration_(p_bool(false)));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(FieldDeclaration_, children_);
	}

	children_->Add_(ExpectToken_(Identifier_));
	children_->Add_(ParseParameterList_());
	children_->Add_(ExpectToken_(Arrow_));
	children_->Add_(ParseType_());
	children_->Add_(ParseBlock_());
	return (new ::Syntax_Node_())->construct(MethodDeclaration_, children_);
}

auto ::Compilation_Unit_Parser_::ParseDeclaration_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	if (op_or(op_or(op_or(token_->kind_->op_equal(PublicKeyword_), [&] { return token_->kind_->op_equal(ProtectedKeyword_); }), [&] { return token_->kind_->op_equal(InternalKeyword_); }), [&] { return token_->kind_->op_equal(PrivateKeyword_); }).value)
	{
		children_->Add_(AcceptToken_());
	}
	else
	{
		children_->Add_(ExpectToken_(PublicKeyword_));
	}

	if (op_or(token_->kind_->op_equal(VarKeyword_), [&] { return token_->kind_->op_equal(LetKeyword_); }).value)
	{
		children_->Add_(ParseVariableDeclaration_(p_bool(true)));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(GlobalDeclaration_, children_);
	}

	if (token_->kind_->op_equal(ClassKeyword_).value)
	{
		children_->Add_(ExpectToken_(ClassKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (op_and(token_->kind_->op_not_equal(RightBrace_), [&] { return token_->kind_->op_not_equal(EndOfFileToken_); }).value)
		{
			::Syntax_Node_ const *_Nonnull const startToken_ = token_;
			children_->Add_(ParseMemberDeclaration_());
			if (token_->op_equal(startToken_).value)
			{
				children_->Add_(new_Syntax_Node_Skipped_(AcceptToken_()));
			}
		}

		children_->Add_(ExpectToken_(RightBrace_));
		return (new ::Syntax_Node_())->construct(ClassDeclaration_, children_);
	}

	if (token_->kind_->op_equal(StructKeyword_).value)
	{
		children_->Add_(ExpectToken_(StructKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (op_and(token_->kind_->op_not_equal(RightBrace_), [&] { return token_->kind_->op_not_equal(EndOfFileToken_); }).value)
		{
			::Syntax_Node_ const *_Nonnull const startToken_ = token_;
			children_->Add_(ParseMemberDeclaration_());
			if (token_->op_equal(startToken_).value)
			{
				children_->Add_(new_Syntax_Node_Skipped_(AcceptToken_()));
			}
		}

		children_->Add_(ExpectToken_(RightBrace_));
		return (new ::Syntax_Node_())->construct(StructDeclaration_, children_);
	}

	if (token_->kind_->op_equal(EnumKeyword_).value)
	{
		children_->Add_(ExpectToken_(EnumKeyword_));
		children_->Add_(ExpectToken_(StructKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (op_and(token_->kind_->op_not_equal(RightBrace_), [&] { return token_->kind_->op_not_equal(EndOfFileToken_); }).value)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const memberChildren_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
			memberChildren_->Add_(ExpectToken_(Identifier_));
			if (token_->kind_->op_equal(Equals_).value)
			{
				memberChildren_->Add_(ExpectToken_(Equals_));
				memberChildren_->Add_(ExpectToken_(Number_));
			}

			if (token_->kind_->op_not_equal(RightBrace_).value)
			{
				memberChildren_->Add_(ExpectToken_(Comma_));
			}

			children_->Add_((new ::Syntax_Node_())->construct(EnumMemberDeclaration_, memberChildren_));
		}

		children_->Add_(ExpectToken_(RightBrace_));
		return (new ::Syntax_Node_())->construct(EnumDeclaration_, children_);
	}

	children_->Add_(ExpectToken_(Identifier_));
	children_->Add_(ParseParameterList_());
	children_->Add_(ExpectToken_(Arrow_));
	children_->Add_(ParseType_());
	children_->Add_(ParseBlock_());
	return (new ::Syntax_Node_())->construct(FunctionDeclaration_, children_);
}

auto ::Compilation_Unit_Parser_::ParseCompilationUnit_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	while (op_and(token_->op_not_equal(p_none), [&] { return token_->kind_->op_not_equal(EndOfFileToken_); }).value)
	{
		::Syntax_Node_ const *_Nonnull const startToken_ = token_;
		children_->Add_(ParseDeclaration_());
		if (token_->op_equal(startToken_).value)
		{
			children_->Add_(new_Syntax_Node_Skipped_(AcceptToken_()));
		}
	}

	children_->Add_(ExpectToken_(EndOfFileToken_));
	return (new ::Syntax_Node_())->construct(CompilationUnit_, children_);
}

auto ::Lexer_::analyze_(::Source_Text_ const *_Nonnull const source_) const -> ::Token_Stream_ *_Nonnull
{
	auto self = this;
	return (new ::Token_Stream_())->construct(source_);
}

auto ::Parser_::construct() -> ::Parser_*
{
	::Parser_* self = this;
	return self;
}

auto ::Parser_::ParsePackage_(::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const sources_) const -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	::Lexer_ const *_Nonnull const lexer_ = (new ::Lexer_())->construct();
	for (::Source_Text_ const *_Nonnull const source_ : *(sources_))
	{
		::Token_Stream_ *_Nonnull const tokenStream_ = lexer_->analyze_(source_);
		::Compilation_Unit_Parser_ *_Nonnull const compilationUnitParser_ = (new ::Compilation_Unit_Parser_())->construct(tokenStream_);
		children_->Add_(compilationUnitParser_->Parse_());
	}

	return (new ::Syntax_Node_())->construct(PackageNode_, children_);
}

auto ::Syntax_Node_::construct(p_int const type_, ::Source_Text_ const *_Nonnull const source_, p_uint const start_, p_uint const length_) -> ::Syntax_Node_*
{
	::Syntax_Node_* self = this;
	kind_ = type_;
	is_missing_ = p_bool(false);
	self->source_ = source_;
	self->start_ = start_;
	byte_length_ = length_;
	self->children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	node_diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	return self;
}

auto ::Syntax_Node_::construct(p_int const type_, p_bool const isMissing_, ::Source_Text_ const *_Nonnull const source_, p_uint const start_, p_uint const length_) -> ::Syntax_Node_*
{
	::Syntax_Node_* self = this;
	kind_ = type_;
	is_missing_ = isMissing_;
	self->source_ = source_;
	self->start_ = start_;
	byte_length_ = length_;
	self->children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	node_diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	return self;
}

auto ::Syntax_Node_::construct(p_int const type_, ::Syntax_Node_ const *_Nonnull const child_) -> ::Syntax_Node_*
{
	::Syntax_Node_* self = this;
	kind_ = type_;
	is_missing_ = child_->is_missing_;
	source_ = child_->source_;
	start_ = child_->start_;
	byte_length_ = child_->byte_length_;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	children_->Add_(child_);
	self->children_ = children_;
	node_diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	return self;
}

auto ::Syntax_Node_::construct(p_int const type_, ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull const children_) -> ::Syntax_Node_*
{
	::Syntax_Node_* self = this;
	kind_ = type_;
	is_missing_ = p_bool(false);
	source_ = children_->op_Element(p_int(0))->source_;
	start_ = children_->op_Element(p_int(0))->start_;
	::Syntax_Node_ const *_Nonnull const lastChild_ = children_->op_Element(children_->op_magnitude()->op_subtract(p_int(1)));
	byte_length_ = lastChild_->start_->op_subtract(start_)->op_add(lastChild_->byte_length_);
	self->children_ = children_;
	node_diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	return self;
}

auto ::Syntax_Node_::get_text_() const -> p_string
{
	auto self = this;
	return source_->Text_->Substring_(start_, byte_length_);
}

auto ::Syntax_Node_::first_child_(p_int const type_) const -> ::Syntax_Node_ const *_Nullable
{
	auto self = this;
	for (::Syntax_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (child_->kind_->op_equal(type_).value)
		{
			return child_;
		}
	}

	return p_none;
}

auto ::Syntax_Node_::has_child_(p_int const type_) const -> p_bool
{
	auto self = this;
	for (::Syntax_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (child_->kind_->op_equal(type_).value)
		{
			return p_bool(true);
		}
	}

	return p_bool(false);
}

auto ::Syntax_Node_::add_(::Diagnostic_ const *_Nonnull const diagnostic_) const -> void
{
	auto self = this;
	node_diagnostics_->Add_(diagnostic_);
}

auto ::Syntax_Node_::all_diagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	collect_diagnostics_(diagnostics_);
	return diagnostics_;
}

auto ::Syntax_Node_::collect_diagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void
{
	auto self = this;
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(node_diagnostics_))
	{
		diagnostics_->Add_(diagnostic_);
	}

	for (::Syntax_Node_ const *_Nonnull const child_ : *(children_))
	{
		child_->collect_diagnostics_(diagnostics_);
	}
}

auto ::Syntax_Node_::members_() const -> ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const members_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	for (::Syntax_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (op_or(op_or(child_->kind_->op_equal(ConstructorDeclaration_), [&] { return child_->kind_->op_equal(FieldDeclaration_); }), [&] { return child_->kind_->op_equal(MethodDeclaration_); }).value)
		{
			members_->Add_(child_);
		}
	}

	return members_;
}

auto ::Syntax_Node_::parameters_() const -> ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const parameters_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	for (::Syntax_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (op_or(child_->kind_->op_equal(Parameter_), [&] { return child_->kind_->op_equal(SelfParameter_); }).value)
		{
			parameters_->Add_(child_);
		}
	}

	return parameters_;
}

auto ::Syntax_Node_::statements_() const -> ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const statements_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	for (::Syntax_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (op_and(child_->kind_->op_not_equal(LeftBrace_), [&] { return child_->kind_->op_not_equal(RightBrace_); }).value)
		{
			statements_->Add_(child_);
		}
	}

	return statements_;
}

auto ::Syntax_Node_::access_modifier_() const -> ::Syntax_Node_ const *_Nullable
{
	auto self = this;
	for (::Syntax_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (op_or(op_or(op_or(child_->kind_->op_equal(PublicKeyword_), [&] { return child_->kind_->op_equal(ProtectedKeyword_); }), [&] { return child_->kind_->op_equal(InternalKeyword_); }), [&] { return child_->kind_->op_equal(PrivateKeyword_); }).value)
		{
			return child_;
		}
	}

	return p_none;
}

auto new_syntax_node_missing_(p_int const type_, ::Source_Text_ const *_Nonnull const source_, p_uint const start_) -> ::Syntax_Node_ const *_Nonnull
{
	::Syntax_Node_ *_Nonnull const node_ = (new ::Syntax_Node_())->construct(type_, p_bool(true), source_, start_, p_int(0));
	::Text_Span_ const *_Nonnull const span_ = (new ::Text_Span_())->construct(start_, p_int(0));
	node_->add_((new ::Diagnostic_())->construct(CompilationError_, Parsing_, source_, span_, p_string("Missing token of type ").op_add(type_)));
	return node_;
}

auto new_Syntax_Node_Skipped_(::Syntax_Node_ const *_Nonnull const skipped_node_) -> ::Syntax_Node_ const *_Nonnull
{
	::Syntax_Node_ *_Nonnull const node_ = (new ::Syntax_Node_())->construct(SkippedTokens_, skipped_node_);
	::Text_Span_ const *_Nonnull const span_ = (new ::Text_Span_())->construct(skipped_node_->start_, skipped_node_->byte_length_);
	node_->add_((new ::Diagnostic_())->construct(CompilationError_, Parsing_, skipped_node_->source_, span_, p_string("Skipped unexpected token of type ").op_add(skipped_node_->kind_)));
	return node_;
}

auto new_Syntax_Node_Skipped_(::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull const skipped_nodes_) -> ::Syntax_Node_ const *_Nonnull
{
	::Syntax_Node_ *_Nonnull const node_ = (new ::Syntax_Node_())->construct(SkippedTokens_, skipped_nodes_);
	::Text_Span_ const *_Nonnull const span_ = (new ::Text_Span_())->construct(node_->start_, node_->byte_length_);
	node_->add_((new ::Diagnostic_())->construct(CompilationError_, Parsing_, node_->source_, span_, p_string("Skipped ").op_add(skipped_nodes_->op_magnitude())->op_add(p_string(" unexpected token(s)"))));
	return node_;
}

auto ::Syntax_Tree_::construct(p_string const path_, ::Source_Text_ const *_Nonnull const source_, ::Syntax_Node_ const *_Nonnull const root_) -> ::Syntax_Tree_*
{
	::Syntax_Tree_* self = this;
	self->path_ = path_;
	self->source_ = source_;
	self->root_ = root_;
	return self;
}

auto ::Token_Stream_::construct(::Source_Text_ const *_Nonnull const source_) -> ::Token_Stream_*
{
	::Token_Stream_* self = this;
	self->source_ = source_;
	position_ = p_int(0);
	diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	endOfFile_ = p_bool(false);
	return self;
}

auto ::Token_Stream_::GetNextToken_() -> ::Syntax_Node_ const *_Nullable
{
	auto self = this;
	if (position_.op_greater_than_or_equal(source_->ByteLength_()).value)
	{
		return EndOfFile_();
	}

	p_uint end_ = p_int(1).op_negate();
	while (position_.op_less_than(source_->ByteLength_()).value)
	{
		p_code_point const curChar_ = source_->Text_->op_Element(position_);
		if (op_or(op_or(op_or(curChar_.op_equal(p_code_point(' ')), [&] { return curChar_.op_equal(p_code_point('\t')); }), [&] { return curChar_.op_equal(p_code_point('\n')); }), [&] { return curChar_.op_equal(p_code_point('\r')); }).value)
		{
			position_.op_add_assign(p_int(1));
			continue;
		}
		else if (curChar_.op_equal(p_code_point('{')).value)
		{
			return NewOperator_(LeftBrace_);
		}
		else if (curChar_.op_equal(p_code_point('}')).value)
		{
			return NewOperator_(RightBrace_);
		}
		else if (curChar_.op_equal(p_code_point('(')).value)
		{
			return NewOperator_(LeftParen_);
		}
		else if (curChar_.op_equal(p_code_point(')')).value)
		{
			return NewOperator_(RightParen_);
		}
		else if (curChar_.op_equal(p_code_point(';')).value)
		{
			return NewOperator_(Semicolon_);
		}
		else if (curChar_.op_equal(p_code_point(',')).value)
		{
			return NewOperator_(Comma_);
		}
		else if (curChar_.op_equal(p_code_point('.')).value)
		{
			return NewOperator_(Dot_);
		}
		else if (curChar_.op_equal(p_code_point(':')).value)
		{
			return NewOperator_(Colon_);
		}
		else if (curChar_.op_equal(p_code_point('[')).value)
		{
			return NewOperator_(LeftBracket_);
		}
		else if (curChar_.op_equal(p_code_point(']')).value)
		{
			return NewOperator_(RightBracket_);
		}
		else if (curChar_.op_equal(p_code_point('?')).value)
		{
			return NewOperator_(Question_);
		}
		else if (curChar_.op_equal(p_code_point('|')).value)
		{
			return NewOperator_(Pipe_);
		}
		else if (curChar_.op_equal(p_code_point('*')).value)
		{
			return NewOperator_(Asterisk_);
		}
		else if (curChar_.op_equal(p_code_point('=')).value)
		{
			if (op_and(position_.op_add(p_int(1))->op_less_than(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_.op_add(p_int(1)))->op_equal(p_code_point('=')); }).value)
			{
				return NewOperator_(EqualsEquals_, p_int(2));
			}

			if (op_and(op_and(position_.op_add(p_int(2))->op_less_than(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_.op_add(p_int(1)))->op_equal(p_code_point('/')); }), [&] { return source_->Text_->op_Element(position_.op_add(p_int(2)))->op_equal(p_code_point('=')); }).value)
			{
				return NewOperator_(EqualsSlashEquals_, p_int(3));
			}

			return NewOperator_(Equals_);
		}
		else if (curChar_.op_equal(p_code_point('+')).value)
		{
			if (op_and(position_.op_add(p_int(1))->op_less_than(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_.op_add(p_int(1)))->op_equal(p_code_point('=')); }).value)
			{
				return NewOperator_(PlusEquals_, p_int(2));
			}

			return NewOperator_(Plus_);
		}
		else if (curChar_.op_equal(p_code_point('-')).value)
		{
			if (op_and(position_.op_add(p_int(1))->op_less_than(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_.op_add(p_int(1)))->op_equal(p_code_point('>')); }).value)
			{
				return NewOperator_(Arrow_, p_int(2));
			}

			if (op_and(position_.op_add(p_int(1))->op_less_than(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_.op_add(p_int(1)))->op_equal(p_code_point('=')); }).value)
			{
				return NewOperator_(MinusEquals_, p_int(2));
			}

			return NewOperator_(Minus_);
		}
		else if (curChar_.op_equal(p_code_point('/')).value)
		{
			if (op_and(position_.op_add(p_int(1))->op_less_than(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_.op_add(p_int(1)))->op_equal(p_code_point('/')); }).value)
			{
				while (op_and(op_and(position_.op_less_than(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_)->op_not_equal(p_code_point('\r')); }), [&] { return source_->Text_->op_Element(position_)->op_not_equal(p_code_point('\n')); }).value)
				{
					position_.op_add_assign(p_int(1));
				}

				continue;
			}

			if (op_and(position_.op_add(p_int(1))->op_less_than(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_.op_add(p_int(1)))->op_equal(p_code_point('*')); }).value)
			{
				position_.op_add_assign(p_int(2));
				p_bool lastCharStar_ = p_bool(false);
				while (op_and(position_.op_less_than(source_->ByteLength_()), [&] { return op_and(lastCharStar_, [&] { return source_->Text_->op_Element(position_)->op_equal(p_code_point('/')); })->op_not(); }).value)
				{
					lastCharStar_ = source_->Text_->op_Element(position_)->op_equal(p_code_point('*'));
					position_.op_add_assign(p_int(1));
				}

				position_.op_add_assign(p_int(1));
				continue;
			}

			return NewOperator_(Slash_);
		}
		else if (curChar_.op_equal(p_code_point('%')).value)
		{
			return NewOperator_(Percent_);
		}
		else if (curChar_.op_equal(p_code_point('<')).value)
		{
			if (op_and(position_.op_add(p_int(1))->op_less_than(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_.op_add(p_int(1)))->op_equal(p_code_point('=')); }).value)
			{
				return NewOperator_(LessThanEquals_, p_int(2));
			}

			return NewOperator_(LessThan_);
		}
		else if (curChar_.op_equal(p_code_point('>')).value)
		{
			if (op_and(position_.op_add(p_int(1))->op_less_than(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_.op_add(p_int(1)))->op_equal(p_code_point('=')); }).value)
			{
				return NewOperator_(GreaterThanEquals_, p_int(2));
			}

			return NewOperator_(GreaterThan_);
		}
		else if (curChar_.op_equal(p_code_point('"')).value)
		{
			end_ = position_.op_add(p_int(1));
			p_bool escaped_ = p_bool(false);
			while (op_and(end_.op_less_than(source_->ByteLength_()), [&] { return op_or(source_->Text_->op_Element(end_)->op_not_equal(p_code_point('"')), [&] { return escaped_; }); }).value)
			{
				escaped_ = op_and(source_->Text_->op_Element(end_)->op_equal(p_code_point('\\')), [&] { return escaped_.op_not(); });
				end_.op_add_assign(p_int(1));
			}

			end_.op_add_assign(p_int(1));
			return NewToken_(StringLiteral_, end_);
		}
		else if (curChar_.op_equal(p_code_point('\'')).value)
		{
			end_ = position_.op_add(p_int(1));
			p_bool escaped_ = p_bool(false);
			while (op_and(end_.op_less_than(source_->ByteLength_()), [&] { return op_or(source_->Text_->op_Element(end_)->op_not_equal(p_code_point('\'')), [&] { return escaped_; }); }).value)
			{
				escaped_ = op_and(source_->Text_->op_Element(end_)->op_equal(p_code_point('\\')), [&] { return escaped_.op_not(); });
				end_.op_add_assign(p_int(1));
			}

			end_.op_add_assign(p_int(1));
			return NewToken_(CodePointLiteral_, end_);
		}
		else
		{
			if (IsIdentifierChar_(curChar_).value)
			{
				end_ = position_.op_add(p_int(1));
				while (IsIdentifierChar_(source_->Text_->op_Element(end_)).value)
				{
					end_.op_add_assign(p_int(1));
				}

				return NewIdentifierOrKeyword_(end_);
			}

			if (IsNumberChar_(curChar_).value)
			{
				end_ = position_.op_add(p_int(1));
				while (IsNumberChar_(source_->Text_->op_Element(end_)).value)
				{
					end_.op_add_assign(p_int(1));
				}

				return NewToken_(Number_, end_);
			}

			::Text_Span_ const *_Nonnull diagnosticSpan_ = (new ::Text_Span_())->construct(position_, p_int(1));
			diagnostics_->Add_((new ::Diagnostic_())->construct(CompilationError_, Lexing_, source_, diagnosticSpan_, p_string("Invalid character `").op_add(curChar_)->op_add(p_string("`"))));
			position_ = end_;
		}
	}

	return EndOfFile_();
}

auto ::Token_Stream_::EndOfFile_() -> ::Syntax_Node_ const *_Nullable
{
	auto self = this;
	if (endOfFile_.value)
	{
		return p_none;
	}

	endOfFile_ = p_bool(true);
	return NewToken_(EndOfFileToken_, position_);
}

auto ::Token_Stream_::NewIdentifierOrKeyword_(p_uint const end_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	p_uint const length_ = end_.op_subtract(position_);
	p_string const value_ = source_->Text_->Substring_(position_, length_);
	p_int type_;
	if (value_.op_equal(p_string("new")).value)
	{
		type_ = NewKeyword_;
	}
	else if (value_.op_equal(p_string("not")).value)
	{
		type_ = NotOperator_;
	}
	else if (value_.op_equal(p_string("null")).value)
	{
		type_ = NullReservedWord_;
	}
	else if (value_.op_equal(p_string("self")).value)
	{
		type_ = SelfKeyword_;
	}
	else if (value_.op_equal(p_string("true")).value)
	{
		type_ = TrueKeyword_;
	}
	else if (value_.op_equal(p_string("false")).value)
	{
		type_ = FalseKeyword_;
	}
	else if (value_.op_equal(p_string("mut")).value)
	{
		type_ = MutableKeyword_;
	}
	else if (value_.op_equal(p_string("code_point")).value)
	{
		type_ = CodePoint_;
	}
	else if (value_.op_equal(p_string("string")).value)
	{
		type_ = String_;
	}
	else if (value_.op_equal(p_string("int")).value)
	{
		type_ = Int_;
	}
	else if (value_.op_equal(p_string("bool")).value)
	{
		type_ = Bool_;
	}
	else if (value_.op_equal(p_string("void")).value)
	{
		type_ = Void_;
	}
	else if (value_.op_equal(p_string("uint")).value)
	{
		type_ = UnsignedInt_;
	}
	else if (value_.op_equal(p_string("var")).value)
	{
		type_ = VarKeyword_;
	}
	else if (value_.op_equal(p_string("and")).value)
	{
		type_ = AndKeyword_;
	}
	else if (value_.op_equal(p_string("or")).value)
	{
		type_ = OrKeyword_;
	}
	else if (value_.op_equal(p_string("return")).value)
	{
		type_ = ReturnKeyword_;
	}
	else if (value_.op_equal(p_string("loop")).value)
	{
		type_ = LoopKeyword_;
	}
	else if (value_.op_equal(p_string("while")).value)
	{
		type_ = WhileKeyword_;
	}
	else if (value_.op_equal(p_string("for")).value)
	{
		type_ = ForKeyword_;
	}
	else if (value_.op_equal(p_string("let")).value)
	{
		type_ = LetKeyword_;
	}
	else if (value_.op_equal(p_string("in")).value)
	{
		type_ = InKeyword_;
	}
	else if (value_.op_equal(p_string("do")).value)
	{
		type_ = DoKeyword_;
	}
	else if (value_.op_equal(p_string("if")).value)
	{
		type_ = IfKeyword_;
	}
	else if (value_.op_equal(p_string("else")).value)
	{
		type_ = ElseKeyword_;
	}
	else if (value_.op_equal(p_string("break")).value)
	{
		type_ = BreakKeyword_;
	}
	else if (value_.op_equal(p_string("continue")).value)
	{
		type_ = ContinueKeyword_;
	}
	else if (value_.op_equal(p_string("private")).value)
	{
		type_ = PrivateKeyword_;
	}
	else if (value_.op_equal(p_string("protected")).value)
	{
		type_ = ProtectedKeyword_;
	}
	else if (value_.op_equal(p_string("public")).value)
	{
		type_ = PublicKeyword_;
	}
	else if (value_.op_equal(p_string("internal")).value)
	{
		type_ = InternalKeyword_;
	}
	else if (value_.op_equal(p_string("class")).value)
	{
		type_ = ClassKeyword_;
	}
	else if (value_.op_equal(p_string("enum")).value)
	{
		type_ = EnumKeyword_;
	}
	else if (value_.op_equal(p_string("struct")).value)
	{
		type_ = StructKeyword_;
	}
	else if (value_.op_equal(p_string("none")).value)
	{
		type_ = NoneKeyword_;
	}
	else
	{
		type_ = Identifier_;
	}

	return NewToken_(type_, end_);
}

auto ::Token_Stream_::NewOperator_(p_int const type_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	return NewToken_(type_, position_.op_add(p_int(1)));
}

auto ::Token_Stream_::NewOperator_(p_int const type_, p_uint const length_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	return NewToken_(type_, position_.op_add(length_));
}

auto ::Token_Stream_::NewToken_(p_int const type_, p_uint const end_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::Syntax_Node_ *_Nonnull const token_ = (new ::Syntax_Node_())->construct(type_, source_, position_, end_.op_subtract(position_));
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(diagnostics_))
	{
		token_->add_(diagnostic_);
	}

	diagnostics_->Clear_();
	position_ = end_;
	return token_;
}

auto ::Token_Stream_::IsIdentifierChar_(p_code_point const c_) -> p_bool
{
	return op_or(op_or(op_and(c_.op_greater_than_or_equal(p_code_point('a')), [&] { return c_.op_less_than_or_equal(p_code_point('z')); }), [&] { return op_and(c_.op_greater_than_or_equal(p_code_point('A')), [&] { return c_.op_less_than_or_equal(p_code_point('Z')); }); }), [&] { return c_.op_equal(p_code_point('_')); });
}

auto ::Token_Stream_::IsNumberChar_(p_code_point const c_) -> p_bool
{
	return op_and(c_.op_greater_than_or_equal(p_code_point('0')), [&] { return c_.op_less_than_or_equal(p_code_point('9')); });
}

auto ::Diagnostic_::construct(p_int const level_, p_int const phase_, ::Source_Text_ const *_Nonnull const source_, ::Text_Span_ const *_Nonnull const span_, p_string const message_) -> ::Diagnostic_*
{
	::Diagnostic_* self = this;
	Level_ = level_;
	Phase_ = phase_;
	self->source_ = source_;
	Span_ = span_;
	Position_ = source_->PositionOfStart_(span_);
	Message_ = message_;
	return self;
}

auto ::Emitter_::construct(::Package_ const *_Nonnull const package_, ::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const resources_) -> ::Emitter_*
{
	::Emitter_* self = this;
	self->package_ = package_;
	self->resources_ = resources_;
	return self;
}

auto ::Emitter_::Emit_() -> p_string
{
	auto self = this;
	type_declarations_ = (new ::Source_File_Builder_())->construct();
	function_declarations_ = (new ::Source_File_Builder_())->construct();
	class_declarations_ = (new ::Source_File_Builder_())->construct();
	global_definitions_ = (new ::Source_File_Builder_())->construct();
	definitions_ = (new ::Source_File_Builder_())->construct();
	main_function_return_type_ = p_string("");
	main_function_accepts_console_ = p_bool(false);
	main_function_accepts_args_ = p_bool(false);
	emit_preamble_();
	for (::Compilation_Unit_ const *_Nonnull const compilation_unit_ : *(package_->compilation_units_))
	{
		emit_compilation_unit_(compilation_unit_);
	}

	emit_entry_point_adapter_();
	return type_declarations_->ToString_()->op_add(function_declarations_->ToString_())->op_add(class_declarations_->ToString_())->op_add(global_definitions_->ToString_())->op_add(definitions_->ToString_());
}

auto ::Emitter_::convert_type_name_(::Semantic_Node_ const *_Nonnull const type_node_) -> p_string
{
	assert_(type_node_->referenced_type_->op_not_equal(p_none), type_node_->get_text_());
	return convert_type_name_(type_node_->referenced_type_);
}

auto ::Emitter_::convert_type_name_(::Type_ const *_Nonnull const type_) -> p_string
{
	::System_::Text_::String_Builder_ *_Nonnull const cpp_type_ = (new ::System_::Text_::String_Builder_())->construct();
	if (type_->is_primitive_.value)
	{
		if (type_->name_->unqualified_()->op_equal(p_string("void")).value)
		{
			return p_string("void");
		}

		cpp_type_->Append_(p_string("p_"));
		cpp_type_->Append_(type_->name_->unqualified_());
	}
	else
	{
		for (p_string const segment_ : *(type_->name_->segments_))
		{
			cpp_type_->Append_(p_string("::"));
			cpp_type_->Append_(segment_);
			cpp_type_->Append_(p_string("_"));
		}
	}

	if (type_->type_parameters_->op_magnitude()->op_greater_than(p_int(0)).value)
	{
		cpp_type_->Append_(p_string("<"));
		p_bool first_ = p_bool(true);
		for (::Type_ const *_Nonnull const type_parameter_ : *(type_->type_parameters_))
		{
			if (first_.value)
			{
				first_ = p_bool(false);
			}
			else
			{
				cpp_type_->Append_(p_string(", "));
			}

			cpp_type_->Append_(convert_type_(p_bool(true), type_parameter_, p_bool(false)));
		}

		cpp_type_->Append_(p_string(">"));
	}

	return cpp_type_->ToString_();
}

auto ::Emitter_::convert_reference_type_(p_bool const mutable_binding_, ::Type_ const *_Nonnull type_, p_bool const nullable_) -> p_string
{
	p_string cpp_type_ = convert_type_name_(type_);
	if (type_->is_mutable_->op_not().value)
	{
		cpp_type_ = cpp_type_.op_add(p_string(" const"));
	}

	cpp_type_ = cpp_type_.op_add(p_string(" *"));
	if (nullable_.value)
	{
		cpp_type_ = cpp_type_.op_add(p_string("_Nullable"));
	}
	else
	{
		cpp_type_ = cpp_type_.op_add(p_string("_Nonnull"));
	}

	if (mutable_binding_.op_not().value)
	{
		cpp_type_ = cpp_type_.op_add(p_string(" const"));
	}

	return cpp_type_;
}

auto ::Emitter_::convert_type_(p_bool const mutable_binding_, ::Type_ const *_Nonnull type_, p_bool const optional_) -> p_string
{
	assert_(type_->op_not_equal(p_none), p_string(""));
	if (op_and(type_->is_primitive_, [&] { return type_->name_->unqualified_()->op_equal(p_string("optional")); }).value)
	{
		::Type_ const *_Nonnull const optional_type_ = type_->type_parameters_->op_Element(p_int(0));
		if (optional_type_->is_value_type_.value)
		{
			p_string cpp_type_ = p_string("p_optional<").op_add(convert_type_(p_bool(true), optional_type_, p_bool(true)))->op_add(p_string(">"));
			if (op_and(mutable_binding_.op_not(), [&] { return type_->is_mutable_->op_not(); }).value)
			{
				cpp_type_ = cpp_type_.op_add(p_string(" const"));
			}

			return cpp_type_;
		}
		else
		{
			return convert_type_(mutable_binding_, optional_type_, p_bool(true));
		}
	}
	else
	{
		if (type_->is_value_type_.value)
		{
			p_string cpp_type_ = convert_type_name_(type_);
			if (op_and(mutable_binding_.op_not(), [&] { return type_->is_mutable_->op_not(); }).value)
			{
				cpp_type_ = cpp_type_.op_add(p_string(" const"));
			}

			return cpp_type_;
		}
		else
		{
			return convert_reference_type_(mutable_binding_, type_, optional_);
		}
	}
}

auto ::Emitter_::convert_type_(p_bool const mutable_binding_, ::Semantic_Node_ const *_Nonnull const type_node_) -> p_string
{
	assert_(type_node_->referenced_type_->op_not_equal(p_none), type_node_->get_text_());
	return convert_type_(mutable_binding_, type_node_->referenced_type_, p_bool(false));
}

auto ::Emitter_::convert_parameter_list_(::Semantic_Node_ const *_Nonnull const parameters_, p_bool const is_main_function_) -> p_string
{
	auto self = this;
	assert_(parameters_->kind_->op_equal(ParameterList_), p_string("parameters.kind=").op_add(parameters_->kind_));
	::System_::Text_::String_Builder_ *_Nonnull const builder_ = (new ::System_::Text_::String_Builder_())->construct();
	builder_->Append_(p_string("("));
	p_bool first_parameter_ = p_bool(true);
	for (::Semantic_Node_ const *_Nonnull const parameter_ : *(parameters_->children_of_kind_(Parameter_)))
	{
		if (first_parameter_.op_not().value)
		{
			builder_->Append_(p_string(", "));
		}
		else
		{
			first_parameter_ = p_bool(false);
		}

		p_bool const mutable_binding_ = parameter_->has_child_(VarKeyword_);
		::Semantic_Node_ const *_Nonnull const type_node_ = parameter_->children_->op_Element(parameter_->children_->op_magnitude()->op_subtract(p_int(1)));
		builder_->Append_(convert_type_(mutable_binding_, type_node_));
		builder_->Append_(p_string(" "));
		builder_->Append_(parameter_->first_child_(Identifier_)->get_text_());
		builder_->Append_(p_string("_"));
		if (is_main_function_.value)
		{
			p_string type_string_;
			if (type_node_->kind_->op_equal(MutableType_).value)
			{
				type_string_ = type_node_->children_->op_Element(p_int(0))->get_text_();
			}
			else
			{
				type_string_ = type_node_->get_text_();
			}

			if (type_string_.op_equal(p_string("System.Console.Console")).value)
			{
				main_function_accepts_console_ = p_bool(true);
			}

			if (type_string_.op_equal(p_string("System.Console.Arguments")).value)
			{
				main_function_accepts_args_ = p_bool(true);
			}
		}
	}

	builder_->Append_(p_string(")"));
	return builder_->ToString_();
}

auto ::Emitter_::convert_parameter_list_(::Semantic_Node_ const *_Nonnull const parameters_) -> p_string
{
	auto self = this;
	return convert_parameter_list_(parameters_, p_bool(false));
}

auto ::Emitter_::convert_expression_(::Semantic_Node_ const *_Nonnull const syntax_, ::Source_File_Builder_ *_Nonnull const builder_) -> void
{
	if (syntax_->kind_->op_equal(NewExpression_).value)
	{
		p_string constructor_name_ = p_string("construct");
		::Semantic_Node_ const *_Nonnull type_node_ = syntax_->children_->op_Element(p_int(0));
		if (type_node_->kind_->op_equal(QualifiedName_).value)
		{
			::Semantic_Node_ const *_Nonnull const name_node_ = type_node_->children_->op_Element(p_int(1));
			if (op_and(name_node_->kind_->op_equal(IdentifierName_), [&] { return name_node_->referenced_type_->op_equal(p_none); }).value)
			{
				constructor_name_ = p_string("construct_").op_add(name_node_->get_text_());
				type_node_ = type_node_->children_->op_Element(p_int(0));
			}
		}

		::Type_ const *_Nonnull const type_ = type_node_->referenced_type_;
		assert_(type_->op_not_equal(p_none), type_node_->get_text_());
		if (type_->is_value_type_.value)
		{
			builder_->Write_(convert_type_name_(type_));
			builder_->Write_(p_string("::"));
			builder_->Write_(constructor_name_);
		}
		else
		{
			builder_->Write_(p_string("(new "));
			builder_->Write_(convert_type_name_(type_));
			builder_->Write_(p_string("())->"));
			builder_->Write_(constructor_name_);
		}

		::Semantic_Node_ const *_Nonnull const argumentList_ = syntax_->children_->op_Element(p_int(1));
		convert_expression_(argumentList_, builder_);
	}
	else if (syntax_->kind_->op_equal(ArgumentList_).value)
	{
		builder_->Write_(p_string("("));
		p_bool first_expression_ = p_bool(true);
		for (::Semantic_Node_ const *_Nonnull const arg_ : *(syntax_->children_))
		{
			if (op_and(op_and(arg_->kind_->op_not_equal(LeftParen_), [&] { return arg_->kind_->op_not_equal(RightParen_); }), [&] { return arg_->kind_->op_not_equal(Comma_); }).value)
			{
				if (first_expression_.value)
				{
					first_expression_ = p_bool(false);
				}
				else
				{
					builder_->Write_(p_string(", "));
				}

				convert_expression_(arg_, builder_);
			}
		}

		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_equal(NotExpression_).value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(1)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(1)), builder_);
		builder_->Write_(p_string("op_not()"));
	}
	else if (syntax_->kind_->op_equal(MagnitudeExpression_).value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(1)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(1)), builder_);
		builder_->Write_(p_string("op_magnitude()"));
	}
	else if (syntax_->kind_->op_equal(ParenthesizedExpression_).value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(1)), builder_);
	}
	else if (syntax_->kind_->op_equal(NegateExpression_).value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(1)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(1)), builder_);
		builder_->Write_(p_string("op_negate()"));
	}
	else if (syntax_->kind_->op_equal(NoneLiteralExpression_).value)
	{
		builder_->Write_(p_string("p_none"));
	}
	else if (syntax_->kind_->op_equal(SelfExpression_).value)
	{
		builder_->Write_(p_string("self"));
	}
	else if (syntax_->kind_->op_equal(NumericLiteralExpression_).value)
	{
		builder_->Write_(p_string("p_int(").op_add(syntax_->get_text_())->op_add(p_string(")")));
	}
	else if (op_or(syntax_->kind_->op_equal(TrueLiteralExpression_), [&] { return syntax_->kind_->op_equal(FalseLiteralExpression_); }).value)
	{
		builder_->Write_(p_string("p_bool(").op_add(syntax_->get_text_())->op_add(p_string(")")));
	}
	else if (syntax_->kind_->op_equal(CodePointLiteralExpression_).value)
	{
		builder_->Write_(p_string("p_code_point(").op_add(syntax_->get_text_())->op_add(p_string(")")));
	}
	else if (syntax_->kind_->op_equal(IdentifierName_).value)
	{
		builder_->Write_(syntax_->get_text_()->op_add(p_string("_")));
	}
	else if (syntax_->kind_->op_equal(StringLiteralExpression_).value)
	{
		builder_->Write_(p_string("p_string(").op_add(syntax_->get_text_())->op_add(p_string(")")));
	}
	else if (syntax_->kind_->op_equal(AssignmentExpression_).value)
	{
		p_int const operator_ = syntax_->children_->op_Element(p_int(1))->kind_;
		if (operator_.op_equal(Equals_).value)
		{
			convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
			builder_->Write_(p_string(" "));
			builder_->Write_(syntax_->children_->op_Element(p_int(1))->get_text_());
			builder_->Write_(p_string(" "));
			convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		}
		else
		{
			convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
			convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
			builder_->Write_(p_string("op_"));
			if (operator_.op_equal(PlusEquals_).value)
			{
				builder_->Write_(p_string("add_assign"));
			}
			else if (operator_.op_equal(MinusEquals_).value)
			{
				builder_->Write_(p_string("subtract_assign"));
			}
			else
			{
				builder_->Error_(p_string("Unsupported assignment operator ").op_add(operator_));
			}

			builder_->Write_(p_string("("));
			convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
			builder_->Write_(p_string(")"));
		}
	}
	else if (syntax_->kind_->op_equal(EqualExpression_).value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_equal("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_equal(NotEqualExpression_).value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_not_equal("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_equal(ComparisonExpression_).value)
	{
		p_int const operator_ = syntax_->children_->op_Element(p_int(1))->kind_;
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_"));
		if (operator_.op_equal(LessThan_).value)
		{
			builder_->Write_(p_string("less_than"));
		}
		else if (operator_.op_equal(LessThanEquals_).value)
		{
			builder_->Write_(p_string("less_than_or_equal"));
		}
		else if (operator_.op_equal(GreaterThan_).value)
		{
			builder_->Write_(p_string("greater_than"));
		}
		else if (operator_.op_equal(GreaterThanEquals_).value)
		{
			builder_->Write_(p_string("greater_than_or_equal"));
		}
		else
		{
			builder_->Error_(p_string("Unsupported comparison operator ").op_add(operator_));
		}

		builder_->Write_(p_string("("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_equal(AddExpression_).value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_add("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_equal(SubtractExpression_).value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_subtract("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_equal(MultiplyExpression_).value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_multiply("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_equal(DivideExpression_).value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_divide("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_equal(RemainderExpression_).value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_remainder("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_equal(OrExpression_).value)
	{
		builder_->Write_(p_string("op_or("));
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string(", [&] { return "));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string("; })"));
	}
	else if (syntax_->kind_->op_equal(AndExpression_).value)
	{
		builder_->Write_(p_string("op_and("));
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string(", [&] { return "));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string("; })"));
	}
	else if (syntax_->kind_->op_equal(InvocationExpression_).value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_expression_(syntax_->children_->op_Element(p_int(1)), builder_);
	}
	else if (syntax_->kind_->op_equal(MemberAccessExpression_).value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_expression_(syntax_->children_->op_Element(p_int(1)), builder_);
	}
	else if (syntax_->kind_->op_equal(ElementAccessExpression_).value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_Element("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else
	{
		builder_->Error_(p_string("Could not convert expression of type ").op_add(syntax_->kind_));
	}
}

auto ::Emitter_::convert_member_access_(::Semantic_Node_ const *_Nonnull const lhs_, ::Source_File_Builder_ *_Nonnull const builder_) -> void
{
	::Type_ const *_Nullable const type_ = lhs_->of_type_;
	if (op_and(op_and(type_->op_not_equal(p_none), [&] { return type_->is_value_type_; }), [&] { return op_and(op_and(type_->is_primitive_, [&] { return type_->name_->unqualified_()->op_equal(p_string("optional")); }), [&] { return type_->type_parameters_->op_Element(p_int(0))->is_value_type_->op_not(); })->op_not(); }).value)
	{
		builder_->Write_(p_string("."));
	}
	else
	{
		builder_->Write_(p_string("->"));
	}
}

auto ::Emitter_::emit_statement_(::Semantic_Node_ const *_Nonnull const statement_) -> void
{
	auto self = this;
	definitions_->StatementSeparatorLine_();
	if (statement_->kind_->op_equal(ReturnStatement_).value)
	{
		if (statement_->children_->op_magnitude()->op_equal(p_int(2)).value)
		{
			definitions_->WriteLine_(p_string("return;"));
		}
		else
		{
			definitions_->BeginLine_(p_string("return "));
			convert_expression_(statement_->children_->op_Element(p_int(1)), definitions_);
			definitions_->EndLine_(p_string(";"));
		}
	}
	else if (statement_->kind_->op_equal(LoopStatement_).value)
	{
		definitions_->WriteLine_(p_string("for (;;)"));
		emit_statement_(statement_->children_->op_Element(p_int(1)));
	}
	else if (statement_->kind_->op_equal(Block_).value)
	{
		definitions_->BeginBlock_();
		for (::Semantic_Node_ const *_Nonnull const block_statement_ : *(statement_->statements_()))
		{
			emit_statement_(block_statement_);
		}

		definitions_->EndBlock_();
	}
	else if (statement_->kind_->op_equal(WhileStatement_).value)
	{
		definitions_->BeginLine_(p_string("while ("));
		convert_expression_(statement_->children_->op_Element(p_int(1)), definitions_);
		definitions_->EndLine_(p_string(".value)"));
		emit_statement_(statement_->children_->op_Element(p_int(2)));
	}
	else if (statement_->kind_->op_equal(ForStatement_).value)
	{
		definitions_->BeginLine_(p_string("for ("));
		::Semantic_Node_ const *_Nonnull const variable_declaration_ = statement_->first_child_(VariableDeclaration_);
		p_bool const mutable_binding_ = variable_declaration_->has_child_(VarKeyword_);
		p_string const name_ = variable_declaration_->first_child_(Identifier_)->get_text_();
		::Semantic_Node_ const *_Nonnull const type_ = variable_declaration_->children_->op_Element(p_int(2));
		definitions_->Write_(convert_type_(mutable_binding_, type_)->op_add(p_string(" "))->op_add(name_)->op_add(p_string("_")));
		definitions_->Write_(p_string(" : *("));
		convert_expression_(statement_->children_->op_Element(p_int(3)), definitions_);
		definitions_->EndLine_(p_string("))"));
		emit_statement_(statement_->children_->op_Element(p_int(4)));
	}
	else if (statement_->kind_->op_equal(DoWhileStatement_).value)
	{
		definitions_->WriteLine_(p_string("do"));
		emit_statement_(statement_->children_->op_Element(p_int(1)));
		definitions_->BeginLine_(p_string("while ("));
		convert_expression_(statement_->children_->op_Element(p_int(3)), definitions_);
		definitions_->EndLine_(p_string(".value);"));
	}
	else if (statement_->kind_->op_equal(IfStatement_).value)
	{
		::Semantic_Node_ const *_Nullable if_statement_ = statement_;
		definitions_->BeginLine_(p_string(""));
		for (;;)
		{
			definitions_->Write_(p_string("if ("));
			convert_expression_(if_statement_->children_->op_Element(p_int(1)), definitions_);
			definitions_->EndLine_(p_string(".value)"));
			emit_statement_(if_statement_->children_->op_Element(p_int(2)));
			::Semantic_Node_ const *_Nullable const elseClause_ = if_statement_->first_child_(ElseClause_);
			if (elseClause_->op_not_equal(p_none).value)
			{
				if_statement_ = elseClause_->first_child_(IfStatement_);
				if (if_statement_->op_not_equal(p_none).value)
				{
					definitions_->BeginLine_(p_string("else "));
				}
				else
				{
					definitions_->WriteLine_(p_string("else"));
					emit_statement_(elseClause_->children_->op_Element(p_int(1)));
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	else if (statement_->kind_->op_equal(BreakStatement_).value)
	{
		definitions_->WriteLine_(p_string("break;"));
	}
	else if (statement_->kind_->op_equal(ContinueStatement_).value)
	{
		definitions_->WriteLine_(p_string("continue;"));
	}
	else if (statement_->kind_->op_equal(LocalDeclarationStatement_).value)
	{
		::Semantic_Node_ const *_Nonnull const variable_declaration_ = statement_->first_child_(VariableDeclaration_);
		p_string const variable_name_ = variable_declaration_->first_child_(Identifier_)->get_text_();
		::Semantic_Node_ const *_Nonnull const variable_type_ = variable_declaration_->children_->op_Element(p_int(2));
		p_bool const mutable_binding_ = variable_declaration_->has_child_(VarKeyword_);
		definitions_->BeginLine_(convert_type_(mutable_binding_, variable_type_));
		definitions_->Write_(p_string(" ").op_add(variable_name_)->op_add(p_string("_")));
		if (variable_declaration_->children_->op_magnitude()->op_greater_than(p_int(3)).value)
		{
			definitions_->Write_(p_string(" = "));
			convert_expression_(variable_declaration_->children_->op_Element(p_int(3)), definitions_);
		}

		definitions_->EndLine_(p_string(";"));
	}
	else if (statement_->kind_->op_equal(ExpressionStatement_).value)
	{
		definitions_->BeginLine_(p_string(""));
		convert_expression_(statement_->children_->op_Element(p_int(0)), definitions_);
		definitions_->EndLine_(p_string(";"));
	}
	else
	{
		NOT_IMPLEMENTED_(p_string("statement.kind=").op_add(statement_->kind_));
	}
}

auto ::Emitter_::emit_method_body_(::Semantic_Node_ const *_Nonnull const block_, p_bool const is_associated_function_) -> void
{
	auto self = this;
	definitions_->BeginBlock_();
	if (is_associated_function_.op_not().value)
	{
		definitions_->WriteLine_(p_string("auto self = this;"));
	}

	for (::Semantic_Node_ const *_Nonnull const statement_ : *(block_->statements_()))
	{
		emit_statement_(statement_);
	}

	definitions_->EndBlock_();
}

auto ::Emitter_::emit_constructor_body_(::Semantic_Node_ const *_Nonnull const block_, p_string const self_type_, p_bool const is_value_type_) -> void
{
	auto self = this;
	definitions_->BeginBlock_();
	if (is_value_type_.value)
	{
		definitions_->WriteLine_(self_type_.op_add(p_string(" self;")));
	}
	else
	{
		definitions_->WriteLine_(self_type_.op_add(p_string(" self = this;")));
	}

	for (::Semantic_Node_ const *_Nonnull const statement_ : *(block_->statements_()))
	{
		emit_statement_(statement_);
	}

	definitions_->WriteLine_(p_string("return self;"));
	definitions_->EndBlock_();
}

auto ::Emitter_::emit_access_modifer_(p_int const current_access_level_, p_int const access_modifer_) -> p_int
{
	auto self = this;
	if (access_modifer_.op_not_equal(current_access_level_).value)
	{
		if (op_or(access_modifer_.op_equal(PublicKeyword_), [&] { return access_modifer_.op_equal(InternalKeyword_); }).value)
		{
			class_declarations_->EndLine_(p_string("public:"));
			return PublicKeyword_;
		}
		else if (access_modifer_.op_equal(ProtectedKeyword_).value)
		{
			class_declarations_->EndLine_(p_string("public:"));
		}
		else if (access_modifer_.op_equal(PrivateKeyword_).value)
		{
			class_declarations_->EndLine_(p_string("private:"));
		}
		else
		{
			THROW_EXCEPTION_(p_string("Invalid access modifier in Emitter.emit_member_declaration(). kind is ").op_add(access_modifer_));
		}
	}

	return access_modifer_;
}

auto ::Emitter_::emit_member_declaration_(::Semantic_Node_ const *_Nonnull const member_, p_string const class_name_, p_bool const is_value_type_, p_int const current_access_level_) -> p_int
{
	auto self = this;
	p_int access_modifer_ = member_->access_modifier_()->kind_;
	access_modifer_ = emit_access_modifer_(current_access_level_, access_modifer_);
	if (member_->kind_->op_equal(ConstructorDeclaration_).value)
	{
		p_string const parameters_ = convert_parameter_list_(member_->first_child_(ParameterList_));
		p_string full_name_ = p_string("construct");
		::Semantic_Node_ const *_Nullable const constructor_name_ = member_->first_child_(Identifier_);
		if (constructor_name_->op_not_equal(p_none).value)
		{
			full_name_ = p_string("construct_").op_add(constructor_name_->get_text_());
		}

		p_string return_type_ = p_string("::").op_add(class_name_)->op_add(p_string("_"));
		if (is_value_type_.op_not().value)
		{
			return_type_ = return_type_.op_add(p_string("*"));
		}

		class_declarations_->BeginLine_(p_string(""));
		if (is_value_type_.value)
		{
			class_declarations_->Write_(p_string("static "));
		}

		class_declarations_->EndLine_(p_string("auto ").op_add(full_name_)->op_add(parameters_)->op_add(p_string(" -> "))->op_add(return_type_)->op_add(p_string(";")));
		definitions_->ElementSeparatorLine_();
		definitions_->WriteLine_(p_string("auto ::").op_add(class_name_)->op_add(p_string("_::"))->op_add(full_name_)->op_add(parameters_)->op_add(p_string(" -> "))->op_add(return_type_));
		emit_constructor_body_(member_->first_child_(Block_), return_type_, is_value_type_);
	}
	else if (member_->kind_->op_equal(FieldDeclaration_).value)
	{
		::Semantic_Node_ const *_Nonnull const variable_declaration_ = member_->first_child_(VariableDeclaration_);
		p_string const field_name_ = variable_declaration_->first_child_(Identifier_)->get_text_();
		::Semantic_Node_ const *_Nonnull const field_type_ = variable_declaration_->children_->op_Element(p_int(2));
		p_string const cpp_type_ = convert_type_(p_bool(true), field_type_);
		class_declarations_->WriteLine_(cpp_type_.op_add(p_string(" "))->op_add(field_name_)->op_add(p_string("_;")));
	}
	else if (member_->kind_->op_equal(MethodDeclaration_).value)
	{
		p_string const method_name_ = member_->first_child_(Identifier_)->get_text_();
		p_string const parameters_ = convert_parameter_list_(member_->first_child_(ParameterList_));
		::Semantic_Node_ const *_Nullable const self_parameter_ = member_->first_child_(ParameterList_)->first_child_(SelfParameter_);
		p_bool const is_associated_function_ = self_parameter_->op_equal(p_none);
		p_bool const mutable_self_ = op_and(is_associated_function_.op_not(), [&] { return self_parameter_->has_child_(MutableKeyword_); });
		::Semantic_Node_ const *_Nonnull const return_type_node_ = member_->children_->op_Element(p_int(3));
		p_string const cpp_type_ = convert_type_(p_bool(true), return_type_node_);
		p_string static_modifier_ = p_string("");
		if (is_associated_function_.value)
		{
			static_modifier_ = p_string("static ");
		}

		p_string constModifier_ = p_string("");
		if (op_and(mutable_self_.op_not(), [&] { return is_associated_function_.op_not(); }).value)
		{
			constModifier_ = p_string("const ");
		}

		class_declarations_->WriteLine_(static_modifier_.op_add(p_string("auto "))->op_add(method_name_)->op_add(p_string("_"))->op_add(parameters_)->op_add(p_string(" "))->op_add(constModifier_)->op_add(p_string("-> "))->op_add(cpp_type_)->op_add(p_string(";")));
		definitions_->ElementSeparatorLine_();
		definitions_->WriteLine_(p_string("auto ::").op_add(class_name_)->op_add(p_string("_::"))->op_add(method_name_)->op_add(p_string("_"))->op_add(parameters_)->op_add(p_string(" "))->op_add(constModifier_)->op_add(p_string("-> "))->op_add(cpp_type_));
		::Semantic_Node_ const *_Nonnull const block_ = member_->first_child_(Block_);
		emit_method_body_(block_, is_associated_function_);
	}
	else
	{
		definitions_->Error_(p_string("Could not emit member of type ").op_add(member_->kind_));
	}

	return access_modifer_;
}

auto ::Emitter_::emit_default_constructor_(p_string const type_name_, p_bool const is_value_type_, p_int const current_access_level_) -> void
{
	auto self = this;
	emit_access_modifer_(current_access_level_, PublicKeyword_);
	p_string return_type_ = p_string("::").op_add(type_name_)->op_add(p_string("_"));
	if (is_value_type_.op_not().value)
	{
		return_type_ = return_type_.op_add(p_string("*"));
	}

	class_declarations_->BeginLine_(p_string(""));
	if (is_value_type_.value)
	{
		class_declarations_->Write_(p_string("static "));
	}

	class_declarations_->Write_(p_string("auto construct() -> ").op_add(return_type_));
	if (is_value_type_.value)
	{
		class_declarations_->EndLine_(p_string(" { return ").op_add(type_name_)->op_add(p_string("_(); }")));
	}
	else
	{
		class_declarations_->EndLine_(p_string(" { return this; }"));
	}
}

auto ::Emitter_::emit_declaration_(::Semantic_Node_ const *_Nonnull const declaration_) -> void
{
	auto self = this;
	if (declaration_->kind_->op_equal(GlobalDeclaration_).value)
	{
		::Semantic_Node_ const *_Nonnull const variable_declaration_ = declaration_->first_child_(VariableDeclaration_);
		p_string const variable_name_ = variable_declaration_->first_child_(Identifier_)->get_text_();
		::Semantic_Node_ const *_Nonnull const variable_type_ = variable_declaration_->children_->op_Element(p_int(2));
		p_bool const mutable_binding_ = variable_declaration_->has_child_(VarKeyword_);
		p_string const cpp_type_ = convert_type_(mutable_binding_, variable_type_);
		global_definitions_->BeginLine_(cpp_type_);
		global_definitions_->Write_(p_string(" ").op_add(variable_name_)->op_add(p_string("_ = ")));
		::Semantic_Node_ const *_Nonnull const expression_ = variable_declaration_->children_->op_Element(p_int(3));
		convert_expression_(expression_, global_definitions_);
		global_definitions_->EndLine_(p_string(";"));
	}
	else if (declaration_->kind_->op_equal(ClassDeclaration_).value)
	{
		p_string const class_name_ = declaration_->first_child_(Identifier_)->get_text_();
		type_declarations_->WriteLine_(p_string("class ").op_add(class_name_)->op_add(p_string("_;")));
		class_declarations_->ElementSeparatorLine_();
		class_declarations_->WriteLine_(p_string("class ").op_add(class_name_)->op_add(p_string("_")));
		class_declarations_->BeginBlock_();
		class_declarations_->EndLine_(p_string("public:"));
		class_declarations_->WriteLine_(p_string("p_bool op_equal(").op_add(class_name_)->op_add(p_string("_ const * other) const { return this == other; }")));
		class_declarations_->WriteLine_(p_string("p_bool op_not_equal(").op_add(class_name_)->op_add(p_string("_ const * other) const { return this != other; }")));
		p_int current_access_level_ = PublicKeyword_;
		p_bool has_constructors_ = p_bool(false);
		for (::Semantic_Node_ const *_Nonnull const member_ : *(declaration_->members_()))
		{
			has_constructors_ = op_or(has_constructors_, [&] { return member_->kind_->op_equal(ConstructorDeclaration_); });
			current_access_level_ = emit_member_declaration_(member_, class_name_, p_bool(false), current_access_level_);
		}

		if (has_constructors_.op_not().value)
		{
			emit_default_constructor_(class_name_, p_bool(false), current_access_level_);
		}

		class_declarations_->EndBlockWithSemicolon_();
	}
	else if (declaration_->kind_->op_equal(StructDeclaration_).value)
	{
		p_string const struct_name_ = declaration_->first_child_(Identifier_)->get_text_();
		type_declarations_->WriteLine_(p_string("struct ").op_add(struct_name_)->op_add(p_string("_;")));
		class_declarations_->ElementSeparatorLine_();
		class_declarations_->WriteLine_(p_string("struct ").op_add(struct_name_)->op_add(p_string("_ final")));
		class_declarations_->BeginBlock_();
		class_declarations_->EndLine_(p_string("public:"));
		class_declarations_->WriteLine_(struct_name_.op_add(p_string("_ * operator->() { return this; }")));
		class_declarations_->WriteLine_(struct_name_.op_add(p_string("_ const * operator->() const { return this; }")));
		class_declarations_->WriteLine_(struct_name_.op_add(p_string("_ & operator* () { return *this; }")));
		class_declarations_->WriteLine_(struct_name_.op_add(p_string("_ const & operator* () const { return *this; }")));
		p_int current_access_level_ = PublicKeyword_;
		p_bool has_constructors_ = p_bool(false);
		for (::Semantic_Node_ const *_Nonnull const member_ : *(declaration_->members_()))
		{
			has_constructors_ = op_or(has_constructors_, [&] { return member_->kind_->op_equal(ConstructorDeclaration_); });
			current_access_level_ = emit_member_declaration_(member_, struct_name_, p_bool(true), current_access_level_);
		}

		if (has_constructors_.op_not().value)
		{
			emit_default_constructor_(struct_name_, p_bool(true), current_access_level_);
		}

		class_declarations_->EndBlockWithSemicolon_();
	}
	else if (declaration_->kind_->op_equal(EnumDeclaration_).value)
	{
		p_string const enum_name_ = declaration_->first_child_(Identifier_)->get_text_();
		type_declarations_->WriteLine_(p_string("enum class ").op_add(enum_name_)->op_add(p_string("_;")));
		class_declarations_->ElementSeparatorLine_();
		class_declarations_->WriteLine_(p_string("enum class ").op_add(enum_name_)->op_add(p_string("_")));
		class_declarations_->BeginBlock_();
		for (::Semantic_Node_ const *_Nonnull const member_ : *(declaration_->children_))
		{
			if (member_->kind_->op_equal(EnumMemberDeclaration_).value)
			{
				p_string const member_name_ = member_->children_->op_Element(p_int(0))->get_text_();
				class_declarations_->BeginLine_(member_name_.op_add(p_string("_")));
				::Semantic_Node_ const *_Nullable const member_value_ = member_->first_child_(Number_);
				if (member_value_->op_not_equal(p_none).value)
				{
					class_declarations_->Write_(p_string(" = "));
					class_declarations_->Write_(member_value_->get_text_());
				}

				class_declarations_->EndLine_(p_string(","));
			}
		}

		class_declarations_->EndBlockWithSemicolon_();
	}
	else if (declaration_->kind_->op_equal(FunctionDeclaration_).value)
	{
		p_string const name_ = declaration_->first_child_(Identifier_)->get_text_();
		p_bool const is_main_ = op_or(name_.op_equal(p_string("Main")), [&] { return name_.op_equal(p_string("main")); });
		if (is_main_.value)
		{
			main_function_name_ = name_;
		}

		p_string const parameters_ = convert_parameter_list_(declaration_->first_child_(ParameterList_), is_main_);
		::Semantic_Node_ const *_Nonnull const return_type_node_ = declaration_->children_->op_Element(p_int(3));
		p_string const cpp_type_ = convert_type_(p_bool(true), return_type_node_);
		function_declarations_->WriteLine_(p_string("auto ").op_add(name_)->op_add(p_string("_"))->op_add(parameters_)->op_add(p_string(" -> "))->op_add(cpp_type_)->op_add(p_string(";")));
		definitions_->ElementSeparatorLine_();
		definitions_->WriteLine_(p_string("auto ").op_add(name_)->op_add(p_string("_"))->op_add(parameters_)->op_add(p_string(" -> "))->op_add(cpp_type_));
		if (is_main_.value)
		{
			if (main_function_return_type_.op_not_equal(p_string("")).value)
			{
				definitions_->Error_(p_string("Multiple declarations of main"));
			}

			main_function_return_type_ = cpp_type_;
		}

		emit_statement_(declaration_->first_child_(Block_));
	}
	else if (declaration_->kind_->op_equal(EndOfFileToken_).value)
	{
	}
	else
	{
		definitions_->Error_(p_string("Could not emit declaration of type ").op_add(declaration_->kind_));
	}
}

auto ::Emitter_::emit_compilation_unit_(::Compilation_Unit_ const *_Nonnull const unit_) -> void
{
	auto self = this;
	for (::Semantic_Node_ const *_Nonnull const declaration_ : *(unit_->declarations_))
	{
		emit_declaration_(declaration_);
	}
}

auto ::Emitter_::emit_preamble_() -> void
{
	auto self = this;
	type_declarations_->WriteLine_(p_string("#include \"RuntimeLibrary.h\""));
	type_declarations_->BlankLine_();
	type_declarations_->WriteLine_(p_string("// Type Declarations"));
	function_declarations_->BlankLine_();
	function_declarations_->WriteLine_(p_string("// Function Declarations"));
	class_declarations_->BlankLine_();
	class_declarations_->WriteLine_(p_string("// Class Declarations"));
	global_definitions_->BlankLine_();
	global_definitions_->WriteLine_(p_string("// Global Definitions"));
	definitions_->BlankLine_();
	definitions_->WriteLine_(p_string("// Definitions"));
}

auto ::Emitter_::emit_entry_point_adapter_() -> void
{
	auto self = this;
	definitions_->ElementSeparatorLine_();
	definitions_->WriteLine_(p_string("// Entry Point Adapter"));
	definitions_->WriteLine_(p_string("std::int32_t main(int argc, char const *const * argv)"));
	definitions_->BeginBlock_();
	definitions_->WriteLine_(p_string("try"));
	definitions_->BeginBlock_();
	for (::Source_Text_ const *_Nonnull const resource_ : *(resources_))
	{
		definitions_->BeginLine_(p_string("resource_manager_->AddResource(p_string(\""));
		definitions_->Write_(resource_->name_);
		definitions_->Write_(p_string("\"), p_string(\""));
		definitions_->Write_(resource_->Text_->Replace_(p_string("\\"), p_string("\\\\"))->Replace_(p_string("\n"), p_string("\\n"))->Replace_(p_string("\r"), p_string("\\r"))->Replace_(p_string("\""), p_string("\\\"")));
		definitions_->EndLine_(p_string("\"));"));
	}

	if (resources_->op_magnitude()->op_greater_than(p_int(0)).value)
	{
		definitions_->EndLine_(p_string(""));
	}

	::System_::Text_::String_Builder_ *_Nonnull const args_ = (new ::System_::Text_::String_Builder_())->construct();
	if (main_function_accepts_console_.value)
	{
		args_->Append_(p_string("new ::System_::Console_::Console_()"));
	}

	if (main_function_accepts_args_.value)
	{
		if (main_function_accepts_console_.value)
		{
			args_->Append_(p_string(", "));
		}

		args_->Append_(p_string("new ::System_::Console_::Arguments_(argc, argv)"));
	}

	if (main_function_return_type_.op_equal(p_string("void")).value)
	{
		definitions_->WriteLine_(main_function_name_.op_add(p_string("_("))->op_add(args_->ToString_())->op_add(p_string(");")));
		definitions_->WriteLine_(p_string("return 0;"));
	}
	else
	{
		definitions_->WriteLine_(p_string("return ").op_add(main_function_name_)->op_add(p_string("_("))->op_add(args_->ToString_())->op_add(p_string(").value;")));
	}

	definitions_->EndBlock_();
	definitions_->WriteLine_(p_string("catch(std::exception &ex)"));
	definitions_->BeginBlock_();
	definitions_->WriteLine_(p_string("std::printf(\"Program exited due to error:\\n\");"));
	definitions_->WriteLine_(p_string("std::printf(\"%s\", ex.what());"));
	definitions_->WriteLine_(p_string("return 70;"));
	definitions_->EndBlock_();
	definitions_->EndBlock_();
}

auto ::Name_::construct_global_namespace() -> ::Name_*
{
	::Name_* self = this;
	self->package_ = p_none;
	self->kind_ = NamespaceName_;
	self->segments_ = (new ::System_::Collections_::List_<p_string>())->construct();
	self->is_special_ = p_bool(false);
	return self;
}

auto ::Name_::construct_global_namespace(::Package_Name_ const *_Nonnull const package_) -> ::Name_*
{
	::Name_* self = this;
	assert_(package_->op_not_equal(p_none), p_string(""));
	self->package_ = package_;
	self->kind_ = NamespaceName_;
	self->segments_ = (new ::System_::Collections_::List_<p_string>())->construct();
	self->is_special_ = p_bool(false);
	return self;
}

auto ::Name_::construct(::Name_ const *_Nonnull const qualifier_, p_int const kind_, p_string const name_) -> ::Name_*
{
	::Name_* self = this;
	assert_(qualifier_->op_not_equal(p_none), p_string(""));
	assert_(name_.ByteLength_()->op_greater_than(p_int(0)), p_string(""));
	self->package_ = qualifier_->package_;
	self->kind_ = kind_;
	::System_::Collections_::List_<p_string> *_Nonnull const segments_ = (new ::System_::Collections_::List_<p_string>())->construct();
	for (p_string const segment_ : *(qualifier_->segments_))
	{
		segments_->Add_(segment_);
	}

	segments_->Add_(name_);
	self->segments_ = segments_;
	self->is_special_ = p_bool(false);
	return self;
}

auto ::Name_::construct(::Name_ const *_Nonnull const qualifier_, p_int const kind_, p_string const name_, p_bool const is_special_) -> ::Name_*
{
	::Name_* self = this;
	assert_(qualifier_->op_not_equal(p_none), p_string(""));
	assert_(name_.ByteLength_()->op_greater_than(p_int(0)), p_string(""));
	self->package_ = qualifier_->package_;
	self->kind_ = kind_;
	::System_::Collections_::List_<p_string> *_Nonnull const segments_ = (new ::System_::Collections_::List_<p_string>())->construct();
	for (p_string const segment_ : *(qualifier_->segments_))
	{
		segments_->Add_(segment_);
	}

	segments_->Add_(name_);
	self->segments_ = segments_;
	self->is_special_ = is_special_;
	return self;
}

auto ::Name_::construct_special(::Name_ const *_Nonnull const qualifier_, p_int const kind_, p_string const name_) -> ::Name_*
{
	::Name_* self = this;
	assert_(qualifier_->op_not_equal(p_none), p_string(""));
	assert_(name_.ByteLength_()->op_greater_than(p_int(0)), p_string(""));
	self->package_ = qualifier_->package_;
	self->kind_ = kind_;
	::System_::Collections_::List_<p_string> *_Nonnull const segments_ = (new ::System_::Collections_::List_<p_string>())->construct();
	for (p_string const segment_ : *(qualifier_->segments_))
	{
		segments_->Add_(segment_);
	}

	segments_->Add_(name_);
	self->segments_ = segments_;
	self->is_special_ = p_bool(true);
	return self;
}

auto ::Name_::construct(::Package_Name_ const *_Nullable const package_, p_int const kind_, ::System_::Collections_::List_<p_string> const *_Nonnull const segments_, p_bool const is_special_) -> ::Name_*
{
	::Name_* self = this;
	self->package_ = package_;
	self->kind_ = kind_;
	self->segments_ = segments_;
	self->is_special_ = is_special_;
	return self;
}

auto ::Name_::unqualified_() const -> p_string
{
	auto self = this;
	if (segments_->op_magnitude()->op_equal(p_int(0)).value)
	{
		return p_string("");
	}

	return segments_->op_Element(segments_->op_magnitude()->op_subtract(p_int(1)));
}

auto ::Name_::full_() const -> p_string
{
	auto self = this;
	p_string name_ = p_string("");
	if (package_->op_not_equal(p_none).value)
	{
		name_ = package_->full_();
	}

	name_ = name_.op_add(p_string("::"));
	p_bool first_ = p_bool(true);
	for (p_string const segment_ : *(segments_))
	{
		if (first_.value)
		{
			first_ = p_bool(false);
			name_ = name_.op_add(segment_);
			continue;
		}

		name_ = name_.op_add(p_string("."))->op_add(segment_);
	}

	return name_;
}

auto ::Name_::is_qualified_with_(::Name_ const *_Nonnull const qualifier_) const -> p_bool
{
	auto self = this;
	if (op_or(op_and(op_and(package_->op_not_equal(p_none), [&] { return qualifier_->package_->op_not_equal(p_none); }), [&] { return package_->full_()->op_not_equal(qualifier_->package_->full_()); }), [&] { return segments_->op_magnitude()->op_less_than_or_equal(qualifier_->segments_->op_magnitude()); }).value)
	{
		return p_bool(false);
	}

	p_int i_ = p_int(0);
	for (p_string const segment_ : *(qualifier_->segments_))
	{
		if (segment_.op_not_equal(segments_->op_Element(i_)).value)
		{
			return p_bool(false);
		}

		i_.op_add_assign(p_int(1));
	}

	return p_bool(true);
}

auto ::Name_::qualifier_is_(::Name_ const *_Nonnull const qualifier_) const -> p_bool
{
	auto self = this;
	return op_and(qualifier_->segments_->op_magnitude()->op_add(p_int(1))->op_equal(segments_->op_magnitude()), [&] { return is_qualified_with_(qualifier_); });
}

auto ::Name_::names_(::Name_ const *_Nonnull const other_) const -> p_bool
{
	auto self = this;
	if (op_or(op_and(package_->op_not_equal(p_none), [&] { return op_or(other_->package_->op_equal(p_none), [&] { return package_->full_()->op_not_equal(other_->package_->full_()); }); }), [&] { return segments_->op_magnitude()->op_not_equal(other_->segments_->op_magnitude()); }).value)
	{
		return p_bool(false);
	}

	p_int i_ = p_int(0);
	for (p_string const segment_ : *(other_->segments_))
	{
		if (segment_.op_not_equal(segments_->op_Element(i_)).value)
		{
			return p_bool(false);
		}

		i_.op_add_assign(p_int(1));
	}

	return p_bool(true);
}

auto ::Name_::is_package_qualified_() const -> p_bool
{
	auto self = this;
	return package_->op_not_equal(p_none);
}

auto ::Name_::remove_package_() const -> ::Name_ const *_Nonnull
{
	auto self = this;
	if (package_->op_equal(p_none).value)
	{
		return self;
	}
	else
	{
		return (new ::Name_())->construct(p_none, kind_, segments_, is_special_);
	}
}

auto unit_test_Name_() -> void
{
	name_with_unspecified_package_names_name_with_package_();
	name_with_unspecified_package_names_itself_();
}

auto name_with_unspecified_package_names_name_with_package_() -> void
{
	::Name_ const *_Nonnull const name_without_package_ = (new ::Name_())->construct((new ::Name_())->construct_global_namespace(), NamespaceName_, p_string("system"));
	::Name_ const *_Nonnull const name_with_package_ = (new ::Name_())->construct((new ::Name_())->construct_global_namespace((new ::Package_Name_())->construct(p_string("package"))), NamespaceName_, p_string("system"));
	assert_(name_without_package_->names_(name_with_package_), p_string(""));
}

auto name_with_unspecified_package_names_itself_() -> void
{
	::Name_ const *_Nonnull const name_without_package_ = (new ::Name_())->construct((new ::Name_())->construct_global_namespace(), NamespaceName_, p_string("system"));
	assert_(name_without_package_->names_(name_without_package_), p_string(""));
}

auto ::Package_Name_::construct(p_string const name_) -> ::Package_Name_*
{
	::Package_Name_* self = this;
	assert_(name_.ByteLength_()->op_greater_than(p_int(0)), p_string(""));
	self->unqualified_ = name_;
	return self;
}

auto ::Package_Name_::full_() const -> p_string
{
	auto self = this;
	return unqualified_;
}

auto ::Symbol_::construct_identifier(p_string const name_) -> ::Symbol_*
{
	::Symbol_* self = this;
	assert_(name_.ByteLength_()->op_greater_than(p_int(0)), p_string(""));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = p_bool(false);
	self->of_type_ = p_none;
	self->declares_type_ = p_none;
	self->declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	self->children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return self;
}

auto ::Symbol_::construct_identifier(p_string const name_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_) -> ::Symbol_*
{
	::Symbol_* self = this;
	assert_(name_.ByteLength_()->op_greater_than(p_int(0)), p_string(""));
	assert_(declarations_->op_not_equal(p_none), p_string("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = p_bool(false);
	self->of_type_ = p_none;
	self->declares_type_ = p_none;
	self->declarations_ = declarations_;
	self->children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return self;
}

auto ::Symbol_::construct_identifier(p_string const name_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*
{
	::Symbol_* self = this;
	assert_(name_.ByteLength_()->op_greater_than(p_int(0)), p_string(""));
	assert_(children_->op_not_equal(p_none), p_string("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = p_bool(false);
	self->of_type_ = p_none;
	self->declares_type_ = p_none;
	self->declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	self->children_ = children_;
	return self;
}

auto ::Symbol_::construct_package(p_string const name_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*
{
	::Symbol_* self = this;
	assert_(name_.ByteLength_()->op_greater_than(p_int(0)), p_string(""));
	assert_(children_->op_not_equal(p_none), p_string("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = PackageSymbol_;
	self->is_special_name_ = p_bool(false);
	self->of_type_ = p_none;
	self->declares_type_ = p_none;
	self->declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	self->children_ = children_;
	return self;
}

auto ::Symbol_::construct_declaring(::Type_ const *_Nonnull const declares_type_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*
{
	::Symbol_* self = this;
	assert_(declares_type_->op_not_equal(p_none), p_string(""));
	assert_(declarations_->op_not_equal(p_none), p_string("name=").op_add(declares_type_->name_->unqualified_()));
	assert_(children_->op_not_equal(p_none), p_string("name=").op_add(declares_type_->name_->unqualified_()));
	self->name_ = declares_type_->name_->unqualified_();
	self->is_special_name_ = declares_type_->name_->is_special_;
	self->of_type_ = p_none;
	self->declares_type_ = declares_type_;
	self->declarations_ = declarations_;
	self->children_ = children_;
	return self;
}

auto ::Symbol_::construct_of_type(p_string const name_, ::Type_ const *_Nonnull const of_type_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*
{
	::Symbol_* self = this;
	assert_(of_type_->op_not_equal(p_none), p_string("name=").op_add(name_));
	assert_(declarations_->op_not_equal(p_none), p_string("name=").op_add(name_));
	assert_(children_->op_not_equal(p_none), p_string("name=").op_add(name_));
	self->name_ = name_;
	self->is_special_name_ = p_bool(false);
	self->of_type_ = of_type_;
	self->declares_type_ = p_none;
	self->declarations_ = declarations_;
	self->children_ = children_;
	return self;
}

auto ::Symbol_::get_(p_string const name_, p_int const kind_) const -> ::Symbol_ const *_Nullable
{
	auto self = this;
	for (::Symbol_ const *_Nonnull const child_ : *(children_))
	{
		if (op_and(child_->name_->op_equal(name_), [&] { return child_->kind_->op_equal(kind_); }).value)
		{
			return child_;
		}
	}

	return p_none;
}

auto unit_test_Symbol_() -> void
{
	Package_symbol_children_can_be_found_by_name_and_kind_();
}

auto Package_symbol_children_can_be_found_by_name_and_kind_() -> void
{
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	children_->add_((new ::Symbol_())->construct_identifier(p_string("child")));
	::Symbol_ const *_Nonnull const package_with_children_ = (new ::Symbol_())->construct_package(p_string("package"), children_);
	assert_(package_with_children_->get_(p_string("child"), IdentifierSymbol_)->op_not_equal(p_none), p_string(""));
}

auto ::Type_::construct(p_int const kind_, ::Name_ const *_Nonnull const name_, p_bool const is_mutable_) -> ::Type_*
{
	::Type_* self = this;
	assert_(name_->op_not_equal(p_none), p_string(""));
	self->kind_ = kind_;
	self->name_ = name_;
	self->type_parameters_ = (new ::System_::Collections_::List_<::Type_ const *_Nonnull>())->construct();
	self->is_primitive_ = p_bool(false);
	self->is_value_type_ = kind_.op_equal(ValueType_);
	self->is_potentially_mutable_ = is_mutable_;
	self->is_mutable_ = is_mutable_;
	return self;
}

auto ::Type_::construct_parameter(p_string const name_) -> ::Type_*
{
	::Type_* self = this;
	self->kind_ = TypeParameterType_;
	self->name_ = (new ::Name_())->construct((new ::Name_())->construct_global_namespace(), TypeParameterName_, name_);
	self->type_parameters_ = (new ::System_::Collections_::List_<::Type_ const *_Nonnull>())->construct();
	self->is_primitive_ = p_bool(false);
	self->is_value_type_ = p_bool(false);
	self->is_potentially_mutable_ = p_bool(true);
	self->is_mutable_ = p_bool(false);
	return self;
}

auto ::Type_::construct(p_int const kind_, ::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_, p_bool const is_mutable_) -> ::Type_*
{
	::Type_* self = this;
	self->kind_ = kind_;
	self->name_ = name_;
	self->type_parameters_ = type_parameters_;
	self->is_primitive_ = p_bool(false);
	self->is_value_type_ = kind_.op_equal(ValueType_);
	self->is_potentially_mutable_ = is_mutable_;
	self->is_mutable_ = is_mutable_;
	return self;
}

auto ::Type_::construct_primitive(::Name_ const *_Nonnull const name_) -> ::Type_*
{
	::Type_* self = this;
	self->kind_ = ValueType_;
	self->name_ = name_;
	self->type_parameters_ = (new ::System_::Collections_::List_<::Type_ const *_Nonnull>())->construct();
	self->is_primitive_ = p_bool(true);
	self->is_value_type_ = p_bool(true);
	self->is_potentially_mutable_ = p_bool(false);
	self->is_mutable_ = p_bool(false);
	return self;
}

auto ::Type_::construct_primitive(::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_) -> ::Type_*
{
	::Type_* self = this;
	self->kind_ = ValueType_;
	self->name_ = name_;
	self->type_parameters_ = type_parameters_;
	self->is_primitive_ = p_bool(true);
	self->is_value_type_ = p_bool(true);
	self->is_potentially_mutable_ = p_bool(false);
	self->is_mutable_ = p_bool(false);
	return self;
}

auto ::Type_::construct_namespace(::Name_ const *_Nonnull const name_) -> ::Type_*
{
	::Type_* self = this;
	self->kind_ = NamespaceType_;
	self->name_ = name_;
	self->is_primitive_ = p_bool(false);
	self->type_parameters_ = (new ::System_::Collections_::List_<::Type_ const *_Nonnull>())->construct();
	self->is_value_type_ = p_bool(true);
	self->is_potentially_mutable_ = p_bool(false);
	self->is_mutable_ = p_bool(false);
	return self;
}

auto ::Type_::construct_generic(::Type_ const *_Nonnull const definition_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_arguments_) -> ::Type_*
{
	::Type_* self = this;
	assert_(definition_->op_not_equal(p_none), p_string(""));
	assert_(type_arguments_->op_not_equal(p_none), definition_->name_->full_());
	assert_(definition_->type_parameters_->op_magnitude()->op_equal(type_arguments_->op_magnitude()), definition_->name_->full_()->op_add(p_string(" "))->op_add(definition_->type_parameters_->op_magnitude())->op_add(p_string(" given "))->op_add(type_arguments_->op_magnitude()));
	self->kind_ = definition_->kind_;
	self->name_ = definition_->name_;
	self->type_parameters_ = type_arguments_;
	self->is_primitive_ = definition_->is_primitive_;
	self->is_value_type_ = definition_->is_value_type_;
	self->is_potentially_mutable_ = definition_->is_potentially_mutable_;
	self->is_mutable_ = definition_->is_mutable_;
	return self;
}

auto ::Type_::construct(p_int const kind_, ::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_, p_bool const is_primitive_, p_bool const is_potentially_mutable_, p_bool const is_mutable_) -> ::Type_*
{
	::Type_* self = this;
	self->kind_ = kind_;
	self->name_ = name_;
	self->type_parameters_ = type_parameters_;
	self->is_primitive_ = is_primitive_;
	self->is_value_type_ = kind_.op_equal(ValueType_);
	self->is_potentially_mutable_ = is_potentially_mutable_;
	self->is_mutable_ = is_mutable_;
	return self;
}

auto ::Type_::make_mutable_() const -> ::Type_ const *_Nonnull
{
	auto self = this;
	assert_(is_potentially_mutable_, p_string("self.name=").op_add(name_->full_()));
	return (new ::Type_())->construct(kind_, name_, type_parameters_, is_primitive_, is_potentially_mutable_, p_bool(true));
}

auto ::Type_::make_immutable_() const -> ::Type_ const *_Nonnull
{
	auto self = this;
	return (new ::Type_())->construct(kind_, name_, type_parameters_, is_primitive_, is_potentially_mutable_, p_bool(false));
}

auto ::Type_::remove_package_() const -> ::Type_ const *_Nonnull
{
	auto self = this;
	assert_(kind_.op_equal(NamespaceType_), p_string("kind=").op_add(kind_));
	if (name_->is_package_qualified_().value)
	{
		return (new ::Type_())->construct(kind_, name_->remove_package_(), type_parameters_, is_primitive_, is_potentially_mutable_, is_mutable_);
	}
	else
	{
		return self;
	}
}

auto ::Name_Subtable_::construct_global_namespace(::Name_Table_ const *_Nonnull const name_table_) -> ::Name_Subtable_*
{
	::Name_Subtable_* self = this;
	self->name_table_ = name_table_;
	self->parent_ = p_none;
	self->name_ = (new ::Name_())->construct_global_namespace();
	self->type_ = (new ::Type_())->construct_namespace(self->name_);
	subtables_ = (new ::System_::Collections_::List_<::Name_Subtable_ *_Nonnull>())->construct();
	return self;
}

auto ::Name_Subtable_::construct_global_namespace(::Name_Table_ const *_Nonnull const name_table_, ::Package_Name_ const *_Nonnull const package_name_) -> ::Name_Subtable_*
{
	::Name_Subtable_* self = this;
	self->name_table_ = name_table_;
	self->parent_ = p_none;
	self->name_ = (new ::Name_())->construct_global_namespace(package_name_);
	self->type_ = (new ::Type_())->construct_namespace(self->name_);
	subtables_ = (new ::System_::Collections_::List_<::Name_Subtable_ *_Nonnull>())->construct();
	return self;
}

auto ::Name_Subtable_::construct(::Name_Subtable_ const *_Nonnull const parent_, ::Name_ const *_Nonnull const name_, ::Type_ const *_Nonnull const type_) -> ::Name_Subtable_*
{
	::Name_Subtable_* self = this;
	self->name_table_ = parent_->name_table_;
	self->parent_ = parent_;
	self->name_ = name_;
	self->type_ = type_;
	subtables_ = (new ::System_::Collections_::List_<::Name_Subtable_ *_Nonnull>())->construct();
	return self;
}

auto ::Name_Subtable_::add_(::Name_ const *_Nonnull const name_, ::Type_ const *_Nonnull const type_) -> void
{
	auto self = this;
	assert_(name_->is_qualified_with_(self->name_), p_string("\"").op_add(name_->full_())->op_add(p_string("\" is not a child of \""))->op_add(self->name_->full_())->op_add(p_string("\"")));
	if (name_->qualifier_is_(self->name_).value)
	{
		if (op_and(op_and(self->name_->package_->op_equal(p_none), [&] { return type_->op_not_equal(p_none); }), [&] { return type_->kind_->op_equal(NamespaceType_); }).value)
		{
			subtables_->add_((new ::Name_Subtable_())->construct(self, name_->remove_package_(), type_->remove_package_()));
		}
		else
		{
			subtables_->add_((new ::Name_Subtable_())->construct(self, name_, type_));
		}

		return;
	}

	for (::Name_Subtable_ *_Nonnull const subtable_ : *(subtables_))
	{
		if (name_->is_qualified_with_(subtable_->name_).value)
		{
			subtable_->add_(name_, type_);
			return;
		}
	}

	assert_(name_->segments_->op_magnitude()->op_equal(self->name_->segments_->op_magnitude()->op_add(p_int(1))), p_string("Can't add \"").op_add(name_->full_())->op_add(p_string("\" to \""))->op_add(self->name_->full_())->op_add(p_string("\"")));
}

auto ::Name_Subtable_::find_(p_string const name_) const -> ::Name_Subtable_ *_Nullable
{
	auto self = this;
	return find_(name_, p_bool(false));
}

auto ::Name_Subtable_::find_special_(p_string const name_) const -> ::Name_Subtable_ *_Nullable
{
	auto self = this;
	return find_(name_, p_bool(true));
}

auto ::Name_Subtable_::find_(p_string const name_, p_bool const is_special_) const -> ::Name_Subtable_ *_Nullable
{
	auto self = this;
	for (::Name_Subtable_ *_Nonnull const subtable_ : *(subtables_))
	{
		if (op_and(subtable_->name_->unqualified_()->op_equal(name_), [&] { return subtable_->name_->is_special_->op_equal(is_special_); }).value)
		{
			return subtable_;
		}
	}

	return p_none;
}

auto ::Name_Subtable_::lookup_(p_string const name_) const -> ::Name_Subtable_ *_Nullable
{
	auto self = this;
	return lookup_(name_, p_bool(false));
}

auto ::Name_Subtable_::lookup_special_(p_string const name_) const -> ::Name_Subtable_ *_Nullable
{
	auto self = this;
	return lookup_(name_, p_bool(true));
}

auto ::Name_Subtable_::lookup_(p_string const name_, p_bool const is_special_) const -> ::Name_Subtable_ *_Nullable
{
	auto self = this;
	::Name_Subtable_ *_Nullable subtable_ = find_(name_, is_special_);
	if (op_and(subtable_->op_equal(p_none), [&] { return parent_->op_not_equal(p_none); }).value)
	{
		subtable_ = parent_->lookup_(name_, is_special_);
	}

	return subtable_;
}

auto ::Name_Subtable_::get_(::Name_ const *_Nonnull const name_) const -> ::Name_Subtable_ const *_Nullable
{
	auto self = this;
	if (name_->names_(self->name_).value)
	{
		return self;
	}
	else if (name_->is_qualified_with_(self->name_)->op_not().value)
	{
		return p_none;
	}

	for (::Name_Subtable_ const *_Nonnull const subtable_ : *(subtables_))
	{
		::Name_Subtable_ const *_Nullable const value_ = subtable_->get_(name_);
		if (value_->op_not_equal(p_none).value)
		{
			return value_;
		}
	}

	return p_none;
}

auto ::Name_Subtable_::bind_type_(::Type_ const *_Nonnull const type_) -> void
{
	auto self = this;
	assert_(type_->op_not_equal(p_none), self->name_->full_());
	if (self->type_->op_not_equal(p_none).value)
	{
		assert_(self->type_->name_->full_()->op_equal(type_->name_->full_()), self->name_->full_()->op_add(p_string(" currently `"))->op_add(self->type_->name_->full_())->op_add(p_string("` trying to set to `"))->op_add(type_->name_->full_())->op_add(p_string("`")));
	}

	self->type_ = type_;
}

auto unit_test_Name_Subtable_() -> void
{
	global_namespace_contains_added_name_();
	namespace_contains_added_name_();
}

auto global_namespace_contains_added_name_() -> void
{
	::Name_Table_ const *_Nonnull const name_table_ = (new ::Name_Table_())->construct();
	::Name_Subtable_ *_Nonnull const global_namespace_ = (new ::Name_Subtable_())->construct_global_namespace(name_table_);
	::Name_ const *_Nonnull const test_name_ = (new ::Name_())->construct(global_namespace_->name_, TypeName_, p_string("test"));
	global_namespace_->add_(test_name_, p_none);
	assert_(global_namespace_->find_(p_string("test"))->op_not_equal(p_none), p_string(""));
	assert_(global_namespace_->get_(test_name_)->op_not_equal(p_none), p_string(""));
}

auto namespace_contains_added_name_() -> void
{
	::Name_Table_ const *_Nonnull const name_table_ = (new ::Name_Table_())->construct();
	::Name_Subtable_ *_Nonnull const global_namespace_ = (new ::Name_Subtable_())->construct_global_namespace(name_table_);
	::Name_ const *_Nonnull const namespace_name_ = (new ::Name_())->construct(global_namespace_->name_, NamespaceName_, p_string("namespace"));
	global_namespace_->add_(namespace_name_, p_none);
	global_namespace_->add_((new ::Name_())->construct(namespace_name_, TypeName_, p_string("test")), p_none);
	::Name_Subtable_ const *_Nonnull const namespace_ = global_namespace_->find_(p_string("namespace"));
	assert_(namespace_->find_(p_string("test"))->op_not_equal(p_none), p_string(""));
}

auto ::Name_Table_::construct() -> ::Name_Table_*
{
	::Name_Table_* self = this;
	self->any_package_ = (new ::Name_Subtable_())->construct_global_namespace(self);
	self->packages_ = (new ::System_::Collections_::List_<::Name_Subtable_ *_Nonnull>())->construct();
	return self;
}

auto ::Name_Table_::add_(::Package_Name_ const *_Nonnull const package_name_) -> ::Name_ const *_Nonnull
{
	auto self = this;
	::Name_Subtable_ *_Nonnull const subtable_ = (new ::Name_Subtable_())->construct_global_namespace(self, package_name_);
	packages_->add_(subtable_);
	return subtable_->name_;
}

auto ::Name_Table_::add_(::Name_ const *_Nonnull const parent_, ::Symbol_ const *_Nonnull const symbol_) -> ::Name_ const *_Nonnull
{
	auto self = this;
	::Name_ const *_Nonnull name_;
	if (symbol_->declares_type_->op_not_equal(p_none).value)
	{
		name_ = (new ::Name_())->construct(parent_, TypeName_, symbol_->name_, symbol_->is_special_name_);
		add_(name_, symbol_->declares_type_);
	}
	else
	{
		name_ = (new ::Name_())->construct(parent_, FunctionName_, symbol_->name_, symbol_->is_special_name_);
		add_(name_, symbol_->of_type_);
	}

	return name_;
}

auto ::Name_Table_::add_(::Name_ const *_Nonnull const name_, ::Type_ const *_Nonnull const type_) -> void
{
	auto self = this;
	any_package_->add_(name_, type_);
	for (::Name_Subtable_ *_Nonnull const package_ : *(packages_))
	{
		if (name_->is_qualified_with_(package_->name_).value)
		{
			package_->add_(name_, type_);
			return;
		}
	}

	THROW_EXCEPTION_(p_string("Can't add name \"").op_add(name_->full_())->op_add(p_string("\" because package doesn't exist in table.")));
}

auto ::Name_Table_::get_(::Name_ const *_Nonnull const name_) const -> ::Name_Subtable_ const *_Nullable
{
	auto self = this;
	if (name_->package_->op_equal(p_none).value)
	{
		return any_package_->get_(name_);
	}

	for (::Name_Subtable_ const *_Nonnull const package_ : *(packages_))
	{
		if (name_->is_qualified_with_(package_->name_).value)
		{
			return package_->get_(name_);
		}
	}

	return p_none;
}

auto ::Name_Table_Builder_::build_(::Package_Name_ const *_Nonnull const package_name_, ::Syntax_Node_ const *_Nonnull const package_syntax_, ::System_::Collections_::List_<::Package_Reference_> const *_Nonnull const references_) const -> ::Name_Table_ const *_Nonnull
{
	auto self = this;
	assert_(package_syntax_->kind_->op_equal(PackageNode_), p_string("package_syntax.kind=").op_add(package_syntax_->kind_));
	::Name_Table_ *_Nonnull const name_table_ = (new ::Name_Table_())->construct();
	add_referenced_(name_table_, references_);
	add_package_(name_table_, package_name_, package_syntax_);
	return name_table_;
}

auto ::Name_Table_Builder_::add_referenced_(::Name_Table_ *_Nonnull const name_table_, ::System_::Collections_::List_<::Package_Reference_> const *_Nonnull const references_) -> void
{
	for (::Package_Reference_ const reference_ : *(references_))
	{
		::Package_Name_ const *_Nonnull const reference_name_ = (new ::Package_Name_())->construct(reference_.name_);
		::Name_ const *_Nonnull const global_namespace_ = name_table_->add_(reference_name_);
		for (::Symbol_ const *_Nonnull const symbol_ : *(reference_.package_->symbol_->children_))
		{
			add_symbol_(name_table_, global_namespace_, symbol_);
		}
	}
}

auto ::Name_Table_Builder_::add_symbol_(::Name_Table_ *_Nonnull const name_table_, ::Name_ const *_Nonnull const parent_, ::Symbol_ const *_Nonnull const symbol_) -> void
{
	::Name_ const *_Nonnull const name_ = name_table_->add_(parent_, symbol_);
	for (::Symbol_ const *_Nonnull const child_ : *(symbol_->children_))
	{
		add_symbol_(name_table_, name_, child_);
	}
}

auto ::Name_Table_Builder_::add_package_(::Name_Table_ *_Nonnull const name_table_, ::Package_Name_ const *_Nonnull const package_name_, ::Syntax_Node_ const *_Nonnull const package_syntax_) -> void
{
	assert_(package_syntax_->kind_->op_equal(PackageNode_), p_string("package_syntax.kind=").op_add(package_syntax_->kind_));
	::Name_ const *_Nonnull const global_namespace_ = name_table_->add_(package_name_);
	for (::Syntax_Node_ const *_Nonnull const compilation_unit_ : *(package_syntax_->children_))
	{
		add_compilation_unit_(name_table_, global_namespace_, compilation_unit_);
	}
}

auto ::Name_Table_Builder_::add_compilation_unit_(::Name_Table_ *_Nonnull const name_table_, ::Name_ const *_Nonnull const global_namespace_, ::Syntax_Node_ const *_Nonnull const compilation_unit_) -> void
{
	assert_(compilation_unit_->kind_->op_equal(CompilationUnit_), p_string("compilation_unit.kind=").op_add(compilation_unit_->kind_));
	for (::Syntax_Node_ const *_Nonnull const declaration_ : *(compilation_unit_->children_))
	{
		add_syntax_(name_table_, global_namespace_, declaration_);
	}
}

auto ::Name_Table_Builder_::add_syntax_(::Name_Table_ *_Nonnull const name_table_, ::Name_ const *_Nonnull const parent_, ::Syntax_Node_ const *_Nonnull const syntax_) -> void
{
	if (op_or(syntax_->kind_->op_equal(FunctionDeclaration_), [&] { return syntax_->kind_->op_equal(MethodDeclaration_); }).value)
	{
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, FunctionName_, syntax_->first_child_(Identifier_)->get_text_());
		add_function_(name_table_, name_, syntax_);
	}
	else if (op_or(syntax_->kind_->op_equal(ClassDeclaration_), [&] { return syntax_->kind_->op_equal(StructDeclaration_); }).value)
	{
		p_string const unqualified_name_ = syntax_->first_child_(Identifier_)->get_text_();
		p_int type_kind_;
		if (syntax_->kind_->op_equal(ClassDeclaration_).value)
		{
			type_kind_ = ReferenceType_;
		}
		else
		{
			type_kind_ = ValueType_;
		}

		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, TypeName_, unqualified_name_);
		::Type_ const *_Nonnull const type_ = (new ::Type_())->construct(type_kind_, name_, p_bool(true));
		name_table_->add_(name_, type_);
		for (::Syntax_Node_ const *_Nonnull const member_ : *(syntax_->members_()))
		{
			add_syntax_(name_table_, name_, member_);
		}
	}
	else if (syntax_->kind_->op_equal(ConstructorDeclaration_).value)
	{
		p_string full_name_ = p_string("new");
		::Syntax_Node_ const *_Nullable const constructor_name_ = syntax_->first_child_(Identifier_);
		if (constructor_name_->op_not_equal(p_none).value)
		{
			full_name_ = p_string("new_").op_add(constructor_name_->get_text_());
		}

		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct_special(parent_, FunctionName_, full_name_);
		add_function_(name_table_, name_, syntax_);
		::Name_ const *_Nonnull const self_name_ = (new ::Name_())->construct_special(name_, VariableName_, p_string("self"));
		::Type_ const *_Nonnull const self_type_ = p_none;
		name_table_->add_(self_name_, self_type_);
	}
	else if (syntax_->kind_->op_equal(FieldDeclaration_).value)
	{
		p_string const unqualified_name_ = syntax_->first_child_(VariableDeclaration_)->first_child_(Identifier_)->get_text_();
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, TypeName_, unqualified_name_);
		::Type_ const *_Nullable const no_type_ = p_none;
		name_table_->add_(name_, no_type_);
	}
	else if (syntax_->kind_->op_equal(EnumDeclaration_).value)
	{
		p_string const unqualified_name_ = syntax_->first_child_(Identifier_)->get_text_();
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, TypeName_, unqualified_name_);
		::Type_ const *_Nonnull const type_ = (new ::Type_())->construct(ReferenceType_, name_, p_bool(true));
		name_table_->add_(name_, type_);
	}
	else if (syntax_->kind_->op_equal(GlobalDeclaration_).value)
	{
		p_string const unqualified_name_ = syntax_->first_child_(VariableDeclaration_)->first_child_(Identifier_)->get_text_();
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, TypeName_, unqualified_name_);
		::Type_ const *_Nullable const no_type_ = p_none;
		name_table_->add_(name_, no_type_);
	}
	else if (syntax_->kind_->op_equal(Block_).value)
	{
		for (::Syntax_Node_ const *_Nonnull const statement_ : *(syntax_->statements_()))
		{
			add_syntax_(name_table_, parent_, statement_);
		}
	}
	else if (op_or(op_or(syntax_->kind_->op_equal(LoopStatement_), [&] { return syntax_->kind_->op_equal(WhileStatement_); }), [&] { return syntax_->kind_->op_equal(DoWhileStatement_); }).value)
	{
		add_syntax_(name_table_, parent_, syntax_->first_child_(Block_));
	}
	else if (syntax_->kind_->op_equal(ForStatement_).value)
	{
		::Syntax_Node_ const *_Nonnull const identifier_ = syntax_->first_child_(VariableDeclaration_)->first_child_(Identifier_);
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, VariableName_, identifier_->get_text_());
		::Type_ const *_Nullable const no_type_ = p_none;
		name_table_->add_(name_, no_type_);
		add_syntax_(name_table_, parent_, syntax_->first_child_(Block_));
	}
	else if (syntax_->kind_->op_equal(IfStatement_).value)
	{
		add_syntax_(name_table_, parent_, syntax_->first_child_(Block_));
		::Syntax_Node_ const *_Nullable const else_clause_ = syntax_->first_child_(ElseClause_);
		if (else_clause_->op_not_equal(p_none).value)
		{
			add_syntax_(name_table_, parent_, else_clause_);
		}
	}
	else if (syntax_->kind_->op_equal(ElseClause_).value)
	{
		::Syntax_Node_ const *_Nullable const block_ = syntax_->first_child_(Block_);
		if (block_->op_not_equal(p_none).value)
		{
			add_syntax_(name_table_, parent_, block_);
		}
		else
		{
			add_syntax_(name_table_, parent_, syntax_->first_child_(IfStatement_));
		}
	}
	else if (syntax_->kind_->op_equal(LocalDeclarationStatement_).value)
	{
		::Syntax_Node_ const *_Nonnull const identifier_ = syntax_->first_child_(VariableDeclaration_)->first_child_(Identifier_);
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, VariableName_, identifier_->get_text_());
		::Type_ const *_Nullable const no_type_ = p_none;
		name_table_->add_(name_, no_type_);
	}
	else if (syntax_->kind_->op_equal(Parameter_).value)
	{
		::Syntax_Node_ const *_Nonnull const identifier_ = syntax_->first_child_(Identifier_);
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, VariableName_, identifier_->get_text_());
		::Type_ const *_Nullable const no_type_ = p_none;
		name_table_->add_(name_, no_type_);
	}
	else if (syntax_->kind_->op_equal(SelfParameter_).value)
	{
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct_special(parent_, VariableName_, p_string("self"));
		::Type_ const *_Nullable const no_type_ = p_none;
		name_table_->add_(name_, no_type_);
	}
	else if (op_or(op_or(op_or(op_or(syntax_->kind_->op_equal(ExpressionStatement_), [&] { return syntax_->kind_->op_equal(ReturnStatement_); }), [&] { return syntax_->kind_->op_equal(BreakStatement_); }), [&] { return syntax_->kind_->op_equal(ContinueStatement_); }), [&] { return syntax_->kind_->op_equal(EndOfFileToken_); }).value)
	{
	}
	else
	{
		NOT_IMPLEMENTED_(p_string("syntax.kind=").op_add(syntax_->kind_));
	}
}

auto ::Name_Table_Builder_::add_function_(::Name_Table_ *_Nonnull const name_table_, ::Name_ const *_Nonnull const name_, ::Syntax_Node_ const *_Nonnull const function_) -> void
{
	::Type_ const *_Nullable const no_type_ = p_none;
	name_table_->add_(name_, no_type_);
	::Syntax_Node_ const *_Nonnull const parameters_ = function_->first_child_(ParameterList_);
	for (::Syntax_Node_ const *_Nonnull const parameter_ : *(parameters_->parameters_()))
	{
		add_syntax_(name_table_, name_, parameter_);
	}

	::Syntax_Node_ const *_Nonnull const body_ = function_->first_child_(Block_);
	add_syntax_(name_table_, name_, body_);
}

auto unit_test_Name_Table_Builder_() -> void
{
	table_contains_referenced_child_names_();
	can_get_root_namespace_from_name_();
	can_get_Console_class_from_name_without_package_();
	can_get_Optional_class_from_name_with_package_();
}

auto table_contains_referenced_child_names_() -> void
{
	::Package_Name_ const *_Nonnull const name_ = (new ::Package_Name_())->construct(p_string("default"));
	::Package_ const *_Nonnull const runtime_package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	::System_::Collections_::List_<::Package_Reference_> *_Nonnull const references_ = (new ::System_::Collections_::List_<::Package_Reference_>())->construct();
	references_->add_(::Package_Reference_::construct(runtime_package_));
	::Name_Table_Builder_ const *_Nonnull const name_table_builder_ = (new ::Name_Table_Builder_())->construct();
	::Syntax_Node_ const *_Nonnull const package_syntax_ = (new ::Syntax_Node_())->construct(PackageNode_, p_none, p_int(0), p_int(0));
	::Name_Table_ const *_Nonnull const name_table_ = name_table_builder_->build_(name_, package_syntax_, references_);
	::Name_Subtable_ const *_Nonnull const namespace_ = name_table_->any_package_->find_(p_string("System"));
	assert_(namespace_->find_(p_string("Console"))->op_not_equal(p_none), p_string(""));
	::Name_ const *_Nonnull const system_namespace_name_ = (new ::Name_())->construct((new ::Name_())->construct_global_namespace(), NamespaceName_, p_string("System"));
	assert_(name_table_->get_(system_namespace_name_)->op_not_equal(p_none), p_string(""));
	::Name_ const *_Nonnull const console_namespace_name_ = (new ::Name_())->construct(system_namespace_name_, NamespaceName_, p_string("Console"));
	assert_(name_table_->get_(console_namespace_name_)->op_not_equal(p_none), p_string(""));
	::Name_ const *_Nonnull const console_class_name_ = (new ::Name_())->construct(console_namespace_name_, TypeName_, p_string("Console"));
	assert_(name_table_->get_(console_class_name_)->op_not_equal(p_none), p_string(""));
}

auto can_get_root_namespace_from_name_() -> void
{
	::Package_Name_ const *_Nonnull const name_ = (new ::Package_Name_())->construct(p_string("default"));
	::Package_ const *_Nonnull const runtime_package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	::System_::Collections_::List_<::Package_Reference_> *_Nonnull const references_ = (new ::System_::Collections_::List_<::Package_Reference_>())->construct();
	references_->add_(::Package_Reference_::construct(runtime_package_));
	::Name_Table_Builder_ const *_Nonnull const name_table_builder_ = (new ::Name_Table_Builder_())->construct();
	::Syntax_Node_ const *_Nonnull const package_syntax_ = (new ::Syntax_Node_())->construct(PackageNode_, p_none, p_int(0), p_int(0));
	::Name_Table_ const *_Nonnull const name_table_ = name_table_builder_->build_(name_, package_syntax_, references_);
	::Name_ const *_Nonnull const namespace_name_ = (new ::Name_())->construct((new ::Name_())->construct_global_namespace(), NamespaceName_, p_string("System"));
	assert_(name_table_->get_(namespace_name_)->op_not_equal(p_none), p_string(""));
}

auto can_get_Console_class_from_name_without_package_() -> void
{
	::Package_Name_ const *_Nonnull const name_ = (new ::Package_Name_())->construct(p_string("default"));
	::Package_ const *_Nonnull const runtime_package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	::System_::Collections_::List_<::Package_Reference_> *_Nonnull const references_ = (new ::System_::Collections_::List_<::Package_Reference_>())->construct();
	references_->add_(::Package_Reference_::construct(runtime_package_));
	::Name_Table_Builder_ const *_Nonnull const name_table_builder_ = (new ::Name_Table_Builder_())->construct();
	::Syntax_Node_ const *_Nonnull const package_syntax_ = (new ::Syntax_Node_())->construct(PackageNode_, p_none, p_int(0), p_int(0));
	::Name_Table_ const *_Nonnull const name_table_ = name_table_builder_->build_(name_, package_syntax_, references_);
	::Name_ const *_Nonnull const system_namespace_name_ = (new ::Name_())->construct((new ::Name_())->construct_global_namespace(), NamespaceName_, p_string("System"));
	::Name_ const *_Nonnull const console_namespace_name_ = (new ::Name_())->construct(system_namespace_name_, NamespaceName_, p_string("Console"));
	::Name_ const *_Nonnull const console_class_name_ = (new ::Name_())->construct(console_namespace_name_, TypeName_, p_string("Console"));
	assert_(name_table_->get_(console_class_name_)->op_not_equal(p_none), p_string(""));
}

auto can_get_Optional_class_from_name_with_package_() -> void
{
	::Package_Name_ const *_Nonnull const name_ = (new ::Package_Name_())->construct(p_string("default"));
	::Package_ const *_Nonnull const primitives_package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	::System_::Collections_::List_<::Package_Reference_> *_Nonnull const references_ = (new ::System_::Collections_::List_<::Package_Reference_>())->construct();
	references_->add_(::Package_Reference_::construct(primitives_package_));
	::Name_Table_Builder_ const *_Nonnull const name_table_builder_ = (new ::Name_Table_Builder_())->construct();
	::Syntax_Node_ const *_Nonnull const package_syntax_ = (new ::Syntax_Node_())->construct(PackageNode_, p_none, p_int(0), p_int(0));
	::Name_Table_ const *_Nonnull const name_table_ = name_table_builder_->build_(name_, package_syntax_, references_);
	::Package_Name_ const *_Nonnull const package_name_ = (new ::Package_Name_())->construct(p_string("$primitives"));
	::Name_ const *_Nonnull const adamant_namespace_name_ = (new ::Name_())->construct((new ::Name_())->construct_global_namespace(), NamespaceName_, p_string("adamant"));
	::Name_ const *_Nonnull const language_namespace_name_ = (new ::Name_())->construct(adamant_namespace_name_, NamespaceName_, p_string("language"));
	assert_(name_table_->get_(language_namespace_name_)->op_not_equal(p_none), p_string(""));
	::Name_ const *_Nonnull const optional_class_name_ = (new ::Name_())->construct(language_namespace_name_, TypeName_, p_string("optional"));
	assert_(name_table_->get_(optional_class_name_)->op_not_equal(p_none), p_string(""));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		resource_manager_->AddResource(p_string("RuntimeLibrary.cpp"), p_string("#include \"RuntimeLibrary.h\"\n#include <map>\n\n// -----------------------------------------------------------------------------\n// Primitive Types\n// -----------------------------------------------------------------------------\n\np_uint p_int::AsUInt_() const\n{\n	if(this->value < 0)\n		throw std::range_error(\"Can't convert negative number to unsigned\");\n\n	return this->value;\n}\n\nchar p_code_point::CharValue() const\n{\n	if(this->value > 0xFF)\n		throw std::range_error(\"Unicode char values not yet supported\");\n\n	return this->value;\n}\n\np_string p_string::construct(p_code_point c, p_int repeat)\n{\n	p_string self;\n	self.Length = repeat.value;\n	char* buffer = new char[repeat.value];\n	for (int i = 0; i < repeat.value; i++)\n		buffer[i] = c.CharValue();\n\n	self.Buffer = buffer;\n	return self;\n}\n\np_string::p_string(const char* s)\n	: Length(std::strlen(s)), Buffer(s)\n{\n}\n\np_string::p_string(int length, const char* s)\n	: Length(length), Buffer(s)\n{\n}\n\nchar const * p_string::cstr() const\n{\n	auto buffer = new char[Length + 1];\n	std::memcpy(buffer, Buffer, Length);\n	buffer[Length] = 0;\n	return buffer;\n}\n\np_string::p_string(p_int other)\n	: Length(0), Buffer(0)\n{\n	char* buffer = new char[12]; // -2,147,483,648 to 2,147,483,647 plus null terminator\n	int length = std::sprintf(buffer,\"%d\", other.value);\n	if(length <= 0) throw std::runtime_error(\"Could not convert int to string\");\n	Length = length;\n	Buffer = buffer;\n}\n\np_string::p_string(p_code_point other)\n	: Length(1), Buffer(new char[1] { other.CharValue() })\n{\n}\n\np_string p_string::Substring_(p_int start, p_int length) const\n{\n	return p_string(length.value, Buffer + start.value);\n}\n\np_string p_string::Replace_(p_string oldValue, p_string newValue) const\n{\n	p_string buffer = \"\";\n	int limit = Length - oldValue.Length + 1;\n	int lastIndex = 0;\n	for(int i=0; i < limit; i++)\n		if (Substring_(i, oldValue.Length).op_equal(oldValue).value)\n		{\n			buffer = buffer.op_add(Substring_(lastIndex, i-lastIndex)).op_add(newValue);\n			i += oldValue.Length; // skip over the value we just matched\n			lastIndex = i;\n			i--; // we need i-- to offset the i++ that is about to happen\n		}\n\n	buffer = buffer.op_add(Substring_(lastIndex, Length - lastIndex));\n	return buffer;\n}\n\np_int p_string::LastIndexOf_(p_code_point c) const\n{\n	for(int i = Length - 1; i >= 0; i--)\n		if(Buffer[i] == c.CharValue())\n			return i;\n\n	return -1; // TODO should return none\n}\n\np_int p_string::index_of_(p_code_point c) const\n{\n	for(int i = 0; i < Length; i++)\n		if(Buffer[i] == c.CharValue())\n			return i;\n\n	return -1;\n}\n\np_string p_string::op_add(p_string const & value) const\n{\n	int newLength = Length + value.Length;\n	char* chars = new char[newLength];\n	size_t offset = sizeof(char) * Length;\n	std::memcpy(chars, Buffer, offset);\n	std::memcpy(chars + offset, value.Buffer, value.Length);\n	return p_string(newLength, chars);\n}\n\np_bool p_string::op_equal(p_string const & other) const\n{\n	if (Length != other.Length)\n		return false;\n\n	for (int i = 0; i < Length; i++)\n		if (Buffer[i] != other.Buffer[i])\n			return false;\n\n	return true;\n}\n\nbool operator < (p_string const & lhs, p_string const & rhs)\n{\n    return std::strcmp(lhs.cstr(), rhs.cstr()) < 0;\n}\n\n// -----------------------------------------------------------------------------\n// Runtime Types\n// -----------------------------------------------------------------------------\n\nauto Borrows::take_mut(char const *_Nonnull kind) -> Borrows_Ref\n{\n	if(borrows == Writing)\n		throw std::runtime_error(std::string(\"Can't mutably take \") + kind + \" that is mutably borrowed\");\n	else if(borrows > 0)\n		throw std::runtime_error(std::string(\"Can't mutably take \") + kind + \" that is immutably borrowed\");\n\n	return Borrows_Ref::own();\n}\n\nauto Borrows::take(char const *_Nonnull kind) -> Borrows_Ref\n{\n	if(borrows == Writing)\n		throw std::runtime_error(std::string(\"Can't immutably take \") + kind + \" that is mutably borrowed\");\n	else if(borrows > 0)\n		throw std::runtime_error(std::string(\"Can't immutably take \") + kind + \" that is immutably borrowed\");\n\n	return Borrows_Ref::own();\n}\n\nauto Borrows::borrow_mut(char const *_Nonnull kind) -> Borrows_Ref\n{\n	if(borrows == Writing)\n		throw std::runtime_error(std::string(\"Can't mutably borrow \") + kind + \" that is mutably borrowed\");\n	else if(borrows > 0)\n		throw std::runtime_error(std::string(\"Can't mutably borrow \") + kind + \" that is immutably borrowed\");\n\n	borrows = Writing;\n	return Borrows_Ref(this);\n}\n\nauto Borrows::borrow(char const *_Nonnull kind) -> Borrows_Ref\n{\n	if(borrows == Writing)\n		throw std::runtime_error(std::string(\"Can't immutably borrow\") + kind + \" that is already mutably borrowed\");\n\n	borrows += 1;\n	return Borrows_Ref(this);\n}\n\nauto Borrows::destruct(char const *_Nonnull kind) -> void\n{\n	if(borrows == Writing)\n		throw std::runtime_error(std::string(\"Can't delete \") + kind + \" that is mutably borrowed\");\n	else if(borrows > 0)\n		throw std::runtime_error(std::string(\"Can't delete \") + kind + \" that is immutably borrowed\");\n}\n\n// -----------------------------------------------------------------------------\n// Standard Library\n// -----------------------------------------------------------------------------\n\nstd::map<p_string, p_string> resourceValues;\n\np_string const & ResourceManager::GetString_(p_string resourceName)\n{\n	return resourceValues.at(resourceName);\n}\nvoid ResourceManager::AddResource(p_string name, p_string value)\n{\n	resourceValues.insert(std::make_pair(name, value));\n}\n\nResourceManager *const resource_manager_ = new ResourceManager();\n\nvoid debug_write_(p_string value)\n{\n	std::fprintf(stderr, \"%.*s\", value.Length, value.Buffer);\n}\nvoid debug_write_line_(p_string value)\n{\n	std::fprintf(stderr, \"%.*s\\n\", value.Length, value.Buffer);\n}\nvoid debug_write_line_()\n{\n	std::fprintf(stderr, \"\\n\");\n}\n\nnamespace system_\n{\n	namespace Console_\n	{\n		void Console_::Write_(p_string value)\n		{\n			std::printf(\"%.*s\", value.Length, value.Buffer);\n		}\n\n		void Console_::WriteLine_(p_string value)\n		{\n			std::printf(\"%.*s\\n\", value.Length, value.Buffer);\n		}\n\n		void Console_::WriteLine_()\n		{\n			std::printf(\"\\n\");\n		}\n\n		Arguments_::Arguments_(int argc, char const *const * argv)\n			: Count(argc-1)\n		{\n			args = new p_string[Count];\n			for (int i = 0; i < Count; i++)\n				args[i] = p_string(argv[i+1]);\n		}\n	}\n\n	namespace IO_\n	{\n		File_Reader_* File_Reader_::construct(const p_string& fileName)\n		{\n			std::FILE* foo;\n			auto fname = fileName.cstr();\n			file = std::fopen(fname, \"rb\");\n			delete[] fname;\n			return this;\n		}\n\n		p_string File_Reader_::ReadToEndSync_()\n		{\n			std::fseek(file, 0, SEEK_END);\n			auto length = std::ftell(file);\n			std::fseek(file, 0, SEEK_SET);\n			auto buffer = new char[length];\n			length = std::fread(buffer, sizeof(char), length, file);\n			return p_string(length, buffer);\n		}\n\n		void File_Reader_::Close_()\n		{\n			std::fclose(file);\n		}\n\n		File_Writer_* File_Writer_::construct(const p_string& fileName)\n		{\n			auto fname = fileName.cstr();\n			file = std::fopen(fname, \"wb\"); // TODO check error\n			delete[] fname;\n			return this;\n		}\n\n		void File_Writer_::Write_(const p_string& value)\n		{\n			std::fwrite(value.Buffer, sizeof(char), value.Length, file);\n		}\n\n		void File_Writer_::Close_()\n		{\n			std::fclose(file);\n		}\n	}\n\n	namespace Text_\n	{\n		void String_Builder_::ensure_capacity(int needed)\n		{\n			int new_capacity = capacity == 0 ? 128 : capacity;\n			while(new_capacity < needed)\n			{\n				new_capacity *= 2;\n			}\n\n			if(new_capacity > capacity)\n			{\n				char* new_buffer = new char[new_capacity];\n				if(length > 0)\n					std::memcpy(new_buffer, buffer, length);\n\n				if(capacity > 0)\n					delete[] buffer;\n\n				buffer = new_buffer;\n				capacity = new_capacity;\n			}\n		}\n\n		String_Builder_* String_Builder_::construct(p_string const & value)\n		{\n			ensure_capacity(value.Length);\n			std::memcpy(buffer, value.Buffer, value.Length);\n			length = value.Length;\n			return this;\n		}\n\n		void String_Builder_::Append_(p_string const & value)\n		{\n			int new_length = length + value.Length;\n			ensure_capacity(new_length);\n			std::memcpy(buffer+length, value.Buffer, value.Length);\n			length = new_length;\n		}\n\n		void String_Builder_::Append_(String_Builder_ const * value)\n		{\n			int new_length = length + value->length;\n			ensure_capacity(new_length);\n			std::memcpy(buffer+length, value->buffer, value->length);\n			length = new_length;\n		}\n\n		void String_Builder_::AppendLine_(p_string const & value)\n		{\n			int new_length = length + value.Length + 1;\n			ensure_capacity(new_length);\n			std::memcpy(buffer+length, value.Buffer, value.Length);\n			buffer[new_length-1] = '\\n';\n			length = new_length;\n		}\n\n		void String_Builder_::AppendLine_()\n		{\n			int new_length = length + 1;\n			ensure_capacity(new_length);\n			buffer[new_length-1] = '\\n';\n			length = new_length;\n		}\n\n		void String_Builder_::Remove_(p_int start, p_int length)\n		{\n			if(start.value >= this->length)\n				throw std::runtime_error(\"String_Builder.Remove() start >= length\");\n\n			int end = start.value + length.value;\n			if(end > this->length) // greater than because end is one past the end of the remove\n				throw std::runtime_error(\"String_Builder.Remove() end > length\");\n\n			std::memmove(buffer+start.value, buffer+end, this->length-end);\n			this->length -= length.value;\n		}\n\n		void String_Builder_::Remove_(p_int start)\n		{\n			if(start.value >= length)\n				throw std::runtime_error(\"String_Builder.Remove() start >= length\");\n\n			length = start.value;\n		}\n\n		p_string String_Builder_::ToString_()\n		{\n			p_string result(length, buffer);\n			// give up ownership of buffer\n			buffer = 0;\n			length = 0;\n			capacity = 0;\n			return result;\n		}\n	}\n}\n"));
		resource_manager_->AddResource(p_string("RuntimeLibrary.h"), p_string("// On windows this disables warnings about using fopen_s instead of fopen\n// It must be defined before including the headers.\n#define _CRT_SECURE_NO_WARNINGS\n#include <cstring>\n#include <cstdio>\n#include <cstdint>\n#include <stdexcept>\n#include <string>\n\n\n// -----------------------------------------------------------------------------\n// Utility Types\n// -----------------------------------------------------------------------------\n// Utility types that help ensure proper use of C++\n\n// A base class for all structs that prevents the default special members\nstruct Struct_Base\n{\nprotected:\n	Struct_Base() noexcept {}\n	Struct_Base(Struct_Base const & other) = delete;\n};\n\n// A base class for all classes that prevents the default special members\n// and ensures a virutal destructor\nclass Class_Base\n{\nprotected:\n	Class_Base() noexcept {}\n	Class_Base(Class_Base const & other) = delete;\npublic:\n	virtual ~Class_Base() noexcept = default;\n};\n\ntemplate<typename T>\nstruct Optional final: Struct_Base\n{\nprivate:\n	bool has_value;\n	union\n	{\n		char dummy;\n		T value;\n	};\n\npublic:\n	Optional() : has_value(false) {}\n	Optional(T&& value) : has_value(true) { new (&value) T(std::move(value)); }\n\n	T & operator->()\n	{\n		if(!has_value) throw std::runtime_error(\"Access to empty Optional value\");\n		return &value;\n	}\n	T const & operator->() const\n	{\n		if(!has_value) throw std::runtime_error(\"Access to empty Optional value\");\n		return &value;\n	}\n	T & operator* ()\n	{\n		if(!has_value) throw std::runtime_error(\"Access to empty Optional value\");\n		return &value;\n	}\n	T const & operator* () const\n	{\n		if(!has_value) throw std::runtime_error(\"Access to empty Optional value\");\n		return &value;\n	}\n\n	~Optional()\n	{\n		if(has_value) (&value)->~T();\n	}\n};\n\n\n// -----------------------------------------------------------------------------\n// Runtime Types\n// -----------------------------------------------------------------------------\n// Types used to model the language semantics\n\nstruct Borrows;\n\n/// Reference to the borrows tracker of a value\nstruct Borrows_Ref final: Struct_Base\n{\nprivate:\n	Borrows *_Nullable borrows;\n\n	Borrows_Ref(Borrows *_Nullable borrows): borrows(borrows) {}\n	static auto own() -> Borrows_Ref { return Borrows_Ref(0); }\n\npublic:\n	Borrows_Ref(Borrows_Ref&& other): borrows(other.borrows) {}\n\n	friend struct Borrows;\n};\n\n/// Tracks borrows at runtime\nstruct Borrows final: Struct_Base\n{\nprivate:\n	const std::uint32_t Writing = UINT32_MAX;\n	std::uint32_t borrows = 0;\n\npublic:\n	Borrows() noexcept {}\n	auto take_mut(char const *_Nonnull kind) -> Borrows_Ref;\n	auto take(char const *_Nonnull kind) -> Borrows_Ref;\n	auto borrow_mut(char const *_Nonnull kind) -> Borrows_Ref;\n	auto borrow(char const *_Nonnull kind) -> Borrows_Ref;\n	auto destruct(char const *_Nonnull kind) -> void;\n};\n\ntemplate<typename T>\nstruct ref_mut;\n\ntemplate<typename T>\nstruct ref;\n\ntemplate<typename T>\nstruct ref_own final: Struct_Base\n{\nprivate:\n	T *_Nonnull value;\n	Borrows mutable borrows;\n\n	// Must be constructed through alloc()\n	ref_own(T *_Nonnull other): value(other) {}\n\npublic:\n	// no default constructor\n	ref_own() = delete;\n\n	// no copy constructor\n	ref_own(ref_own<T> const & other) = delete;\n\n	// default move constructor\n	ref_own(ref_own<T>&& other) noexcept = default;\n\n	// no copy assignment operator\n	ref_own<T>& operator=(ref_own<T> const& other) = delete;\n\n	// default move assignment operator\n	ref_own<T>& operator=(ref_own<T>&& other) noexcept = default;\n\n	// allocate a new owned object. NOT INITALIZED\n	// Note: this calls the default constructor because we have to setup the vtable\n	static auto alloc() -> ref_own<T> { return ref_own(new T()); }\n\n	auto take_mut() const -> ref_mut<T>\n	{\n		return ref_mut<T>(borrows.take_mut(\"owned reference\"), value);\n	}\n	auto take() const -> ref<T>\n	{\n		return ref<T>(borrows.take(\"owned reference\"), value);\n	}\n	auto borrow_mut() const -> ref_mut<T>\n	{\n		return ref_mut<T>(borrows.borrow_mut(\"owned reference\"), value);\n	}\n	auto borrow() const -> ref<T>\n	{\n		return ref<T>(borrows.borrow(\"owned reference\"), value);\n	}\n\n	~ref_own<T>()\n	{\n		borrows.destruct(\"owned reference\");\n		delete value;\n	}\n};\n\nenum Binding_State\n{\n	Uninitialized,\n	Initialized,\n	Moved\n};\n\ntemplate<typename T>\nstruct Binding final: Struct_Base\n{\nprivate:\n	Optional<T> value;\n	Binding_State binding_state = Binding_State::Uninitialized;\n	Borrows borrows;\n	// Take the value, potentially leaving in a bad state\n	auto steal_value() -> T;\n\npublic:\n	Binding() {}\n	Binding(T&& other): value(std::move(other)) {}\n	Binding(Binding<T>&& other): value(other.steal_value()) {}\n	// Move or copy (if implicitly copyable) value out of binding\n	auto move_value() -> T;\n};\n\ntemplate<typename T>\nauto Binding<T>::move_value() -> T\n{\n	if(binding_state == Binding_State::Uninitialized)\n		throw std::runtime_error(\"Can't access a binding before it is initialized\");\n	if(binding_state == Binding_State::Moved)\n		throw std::runtime_error(\"Can't access moved value\");\n\n	if(T::ImplicitCopy)\n	{\n		return T::copy(*value);\n	}\n	else\n	{\n		binding_state = Binding_State::Moved;\n		return std::move(value);\n	}\n}\n\ntemplate<typename T>\nstruct var final: Struct_Base\n{\npublic:\n	// default constructor\n	var() = default;\n\n	// var(T&& value): value(value) {}\n};\n\ntemplate<typename T>\nstruct let final: Struct_Base\n{\nprivate:\n	Binding<T> binding;\npublic:\n	let() {};\n	explicit let(let<T>& other): binding(other.move_value()) {}\n	let(T&& other): binding(std::move(other)) {}\n	auto move_value() -> T { return binding.move_value(); }\n\n	// let(let<T>&& other): binding<T>((T)other) {}\n	// let(let<T>& other): binding<T>((T)other) {}\n	// no copy constructor\n	// let(let<T> const & other): base(other.value()) {}\n\n	// // default move constructor\n	// let(let<T>&& other) noexcept = default;\n\n	// // no copy assignment operator\n	// let<T>& operator=(let<T> const& other) = delete;\n\n	// // default move assignment operator\n	// let<T>& operator=(let<T>&& other) noexcept = default;\n\n	// This is the strange syntax for a move conversion operator\n	operator T() && { return binding.move_value(); }\n\n	// template<typename U>\n	// auto op_equal(U other) const -> decltype(binding<T const>::get_value().op_equal(other)) { return binding<T const>::get_value().op_equal(other); }\n};\n\n/// a mutable borrow\ntemplate<typename T>\nstruct ref_mut final: Struct_Base\n{\nprivate:\n	std::uint32_t mutable *_Nullable borrows;\n	T *_Nonnull value;\n	ref_mut(std::uint32_t *_Nullable borrows, T *_Nonnull value): borrows(borrows), value(value) {}\n\npublic:\n	// no default constructor\n	ref_mut() = delete;\n\n	// no copy constructor\n	ref_mut(ref_mut<T> const & other) = delete;\n\n	// default move constructor\n	ref_mut(ref_mut<T>&& other) noexcept = default;\n\n	// no copy assignment operator\n	ref_mut<T>& operator=(ref_mut<T> const& other) = delete;\n\n	// default move assignment operator\n	ref_mut<T>& operator=(ref_mut<T>&& other) noexcept;\n\n	ref_mut(ref_own<T>&& other) { return other.take_mut(); }\n	ref_mut(ref_own<T>& other) { return other.borrow_mut(); }\n\n	friend struct ::ref_own<T>;\n};\n\n/// a non-mutable borrow\ntemplate<typename T>\nstruct ref: Struct_Base\n{\nprivate:\n	std::uint32_t mutable *_Nullable borrows;\n	T const *_Nonnull value;\n	ref(std::uint32_t *_Nullable borrows, T *_Nonnull value): borrows(borrows), value(value) {}\n\npublic:\n	ref(ref_own<T>&& other) { return other.take(); }\n	ref(ref_own<T>& other) { return other.borrow(); }\n\n	template<typename U>\n	auto op_equal(U other) const -> decltype(value->op_equal(other)) { return value->op_equal(other); }\n\n	friend struct ::ref_own<T>;\n};\n\n// -----------------------------------------------------------------------------\n// Logical Operators\n// -----------------------------------------------------------------------------\n// Use special templates taking closures to support short circuit evaluation\n\ntemplate<typename T, typename F>\nT op_and(T const & lhs, F rhs)\n{\n	return lhs.op_false().value ? lhs : lhs.op_and(rhs());\n}\n\ntemplate<typename T, typename F>\nT op_or(T const & lhs, F rhs)\n{\n	return lhs.op_true().value ? lhs : lhs.op_or(rhs());\n}\n\n// -----------------------------------------------------------------------------\n// Primitive Types\n// -----------------------------------------------------------------------------\n\nclass None\n{\npublic:\n	template<class T>\n	operator T*_Nullable() const { return static_cast<T*>(0); }\n};\nstatic const None p_none = None();\n\ntemplate<typename T>\nstruct p_optional final: Struct_Base\n{\nprivate:\n	bool hasValue;\n	union\n    {\n        T data;\n    };\n\npublic:\n	p_optional(T const & value) : data(value), hasValue(true) {}\n	p_optional(None const none) : hasValue(false) {}\n	T & operator->()\n	{\n		if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n		return data;\n	}\n	T const & operator->() const\n	{\n		if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n		return data;\n	}\n	T & operator* ()\n	{\n		if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n		return data;\n	}\n	T const & operator* () const\n	{\n		if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n		return data;\n	}\n};\n\nstruct p_bool\n{\npublic:\n	// Runtime Members\n	bool value;\n\n	p_bool() = default;\n	p_bool(bool value): value(value) {}\n	p_bool& operator=(p_bool const& value) = default;\n\n	p_bool *_Nonnull operator->() { return this; }\n	p_bool const *_Nonnull operator->() const { return this; }\n	p_bool & operator* () { return *this; }\n	p_bool const & operator* () const { return *this; }\n\n	// Adamant Members\n	static auto construct() -> p_bool { return p_bool(false); }\n	p_bool op_not() const { return !this->value; }\n	p_bool op_true() const { return this->value; }\n	p_bool op_false() const { return !this->value; }\n	p_bool op_and(p_bool other) const { return this->value & other.value; }\n	p_bool op_or(p_bool other) const { return this->value | other.value; }\n	p_bool op_equal(p_bool other) const { return this->value == other.value; }\n	p_bool op_not_equal(p_bool other) const { return this->value != other.value; }\n};\n\nstruct p_uint;\n\nstruct p_int\n{\npublic:\n	// Runtime Use Members\n	static const bool ImplicitCopy = true;\n	std::int32_t value;\n\n	p_int() = default;\n	p_int(std::int32_t value): value(value) {}\n\n	p_int *_Nonnull operator->() { return this; }\n	p_int const *_Nonnull operator->() const { return this; }\n	p_int & operator* () { return *this; }\n	p_int const & operator* () const { return *this; }\n\n	// Hack to support conversion of uint to int for now\n	p_int(p_uint value);\n\n	// Adamant Members\n	static auto construct() -> p_int { return 0; }\n	static auto copy(p_int const & other) -> p_int { return other; }\n	void op_add_assign(p_int other) { this->value += other.value; }\n	void op_subtract_assign(p_int other) { this->value -= other.value; }\n	p_bool op_equal(p_int other) const { return this->value == other.value; }\n	p_bool op_not_equal(p_int other) const { return this->value != other.value; }\n	p_bool op_less_than(p_int other) const { return this->value < other.value; }\n	p_bool op_less_than_or_equal(p_int other) const { return this->value <= other.value; }\n	p_bool op_greater_than(p_int other) const { return this->value > other.value; }\n	p_bool op_greater_than_or_equal(p_int other) const { return this->value >= other.value; }\n	p_int op_add(p_int other) const { return this->value + other.value; }\n	p_int op_subtract(p_int other) const { return this->value - other.value; }\n	p_int op_negate() const { return -this->value; }\n	p_int op_multiply(p_int other) const { return this->value * other.value; }\n	p_int op_divide(p_int other) const { return this->value / other.value; }\n	p_int op_remainder(p_int other) const { return this->value % other.value; }\n	p_int op_magnitude() const { if(this->value==INT32_MIN) throw std::overflow_error(\"Can't take |int.Min|\"); return this->value < 0 ? -this->value : this->value; }\n\n	// Hack because we don't support as correctly yet\n	p_uint AsUInt_() const;\n};\n\nstruct p_uint\n{\npublic:\n	// Runtime Use Members\n	std::uint32_t value;\n\n	p_uint() = default;\n	p_uint(std::uint32_t value): value(value) {}\n\n	p_uint *_Nonnull operator->() { return this; }\n	p_uint const *_Nonnull operator->() const { return this; }\n	p_uint & operator* () { return *this; }\n	p_uint const & operator* () const { return *this; }\n\n	// Hack to support conversion of int to uint for now\n	p_uint(p_int value): value(value.value) {}\n\n	// Adamant Members\n	static auto construct() -> p_uint { return 0; }\n	void op_add_assign(p_uint other) { this->value += other.value; }\n	void op_subtract_assign(p_uint other) { this->value -= other.value; }\n	p_bool op_equal(p_uint other) const { return this->value == other.value; }\n	p_bool op_not_equal(p_uint other) const { return this->value != other.value; }\n	p_bool op_less_than(p_uint other) const { return this->value < other.value; }\n	p_bool op_less_than_or_equal(p_uint other) const { return this->value <= other.value; }\n	p_bool op_greater_than(p_uint other) const { return this->value > other.value; }\n	p_bool op_greater_than_or_equal(p_uint other) const { return this->value >= other.value; }\n	p_uint op_add(p_uint other) const { return this->value + other.value; }\n	p_uint op_subtract(p_uint other) const { return this->value - other.value; }\n};\n\ninline p_int::p_int(p_uint value)\n	: value(value.value)\n{\n}\n\nstruct p_code_point\n{\nprivate:\n	std::uint32_t value;\n\npublic:\n	// Runtime Use Members\n	p_code_point() = default;\n	p_code_point(char value): value(value) {}\n	char CharValue() const;\n\n	p_code_point *_Nonnull operator->() { return this; }\n	p_code_point const *_Nonnull operator->() const { return this; }\n	p_code_point & operator* () { return *this; }\n	p_code_point const & operator* () const { return *this; }\n\n	// Adamant Members\n	static auto construct() -> p_code_point { return '\\0'; }\n	p_bool op_equal(p_code_point const & other) const { return this->value == other.value; }\n	p_bool op_not_equal(p_code_point const & other) const { return this->value != other.value; }\n	// TODO: Not sure code_point should support these operations\n	p_bool op_less_than(p_code_point other) const { return this->value < other.value; }\n	p_bool op_less_than_or_equal(p_code_point other) const { return this->value <= other.value; }\n	p_bool op_greater_than(p_code_point other) const { return this->value > other.value; }\n	p_bool op_greater_than_or_equal(p_code_point other) const { return this->value >= other.value; }\n\n};\n\nstruct p_string\n{\npublic:\n	// Runtime Use Members\n	char const *_Nonnull Buffer;\n	int Length;\n\n	p_string() = default;\n	p_string(char const *_Nonnull s);\n	p_string(int length, char const *_Nonnull s);\n	char const *_Nonnull cstr() const;\n	p_string const *_Nonnull operator->() const { return this; }\n	p_string const & operator* () const { return *this; }\n\n	typedef char const *_Nonnull const_iterator;\n	const_iterator begin() const { return &Buffer[0]; }\n	const_iterator end() const { return &Buffer[Length]; }\n\n	// Hack to support conversion of int and code_point to strings for now\n	p_string(p_int other);\n	p_string(p_code_point other);\n\n	// Adamant Members\n	static auto construct() -> p_string { p_string self; self.Length = 0; self.Buffer = 0; return self; }\n	static auto construct(p_string value) -> p_string { return value; }\n	static auto construct(p_code_point c, p_int repeat) -> p_string;\n	// TODO ByteLength should be a property\n	p_int ByteLength_() const { return this->Length; }\n\n	p_string Substring_(p_int start, p_int length) const;\n	p_string Substring_(p_int start) const { return Substring_(start, Length-start.value); }\n	p_string Replace_(p_string oldValue, p_string newValue) const;\n	p_int LastIndexOf_(p_code_point c) const;\n	p_int index_of_(p_code_point c) const;\n\n	p_code_point op_Element(p_int const index) const { return Buffer[index.value]; }\n	p_string op_add(p_string const & value) const;\n	p_bool op_equal(p_string const & other) const;\n	p_bool op_not_equal(p_string const & other) const { return !this->op_equal(other).value; }\n	p_bool op_less_than(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) < 0; }\n	p_bool op_less_than_or_equal(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) <= 0; }\n	p_bool op_greater_than(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) > 0; }\n	p_bool op_greater_than_or_equal(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) >= 0; }\n};\n\n// -----------------------------------------------------------------------------\n// Standard Library\n// -----------------------------------------------------------------------------\n// Parts of the standard library that are currently implemented in the runtime.\n\n// A placeholder function until we get proper exceptions implemented\n_Noreturn inline void THROW_EXCEPTION_(const p_string& value)\n{\n	throw std::runtime_error(value.cstr());\n}\n\n\ninline void assert(const p_bool condition, const p_string code, const p_string message, const p_string file, const std::int32_t line)\n{\n	if(!condition.value)\n		throw std::runtime_error(\n			p_string(\"Assertion failed: \").op_add(code).op_add(\", \").op_add(message)\n			.op_add(\", file \").op_add(file).op_add(\", line \").op_add(p_int(line)).cstr());\n}\n\n#define assert_(condition, message) assert(condition, #condition, message, __FILE__, __LINE__)\n\n\n_Noreturn inline void NOT_IMPLEMENTED(const p_string message, const p_string function, const p_string file, const std::int32_t line)\n{\n	throw std::runtime_error(\n		p_string(\"Function \").op_add(function)\n		.op_add(p_string(\" not yet implemented, \")).op_add(message).op_add(p_string(\", \")).op_add(file).op_add(p_string(\", line \")).op_add(p_int(line)).cstr());\n}\n\n#define NOT_IMPLEMENTED_(message) NOT_IMPLEMENTED(message, __func__, __FILE__, __LINE__)\n\n\n_Noreturn inline void UNREACHABLE(const p_string function, const p_string file, const std::int32_t line)\n{\n	throw std::runtime_error(\n		p_string(\"Reached \\\"UNREACHABLE\\\" statement in function \").op_add(function)\n		.op_add(p_string(\", \")).op_add(file).op_add(p_string(\", line \")).op_add(p_int(line)).cstr());\n}\n\n#define UNREACHABLE_() UNREACHABLE(__func__, __FILE__, __LINE__)\n\nclass ResourceManager\n{\npublic:\n	p_string const & GetString_(p_string resourceName);\n	void AddResource(p_string name, p_string value);\n};\n\nextern ResourceManager *_Nonnull const resource_manager_;\n\nvoid debug_write_(p_string value);\nvoid debug_write_line_(p_string value);\nvoid debug_write_line_();\n\nnamespace system_\n{\n	namespace Collections_\n	{\n		template<typename T>\n		class List_\n		{\n		private:\n			T *_Nonnull values;\n			int length;\n			int capacity;\n\n		public:\n			// Runtime Use Members\n			typedef T const *_Nonnull const_iterator;\n			const_iterator begin() const { return values; }\n			const_iterator end() const { return &values[length]; }\n\n			// Adamant Members\n			p_bool op_equal(List_<T> const *_Nonnull other) const { return this == other; }\n			p_bool op_not_equal(List_<T> const *_Nonnull other) const { return this != other; }\n\n			List_ *_Nonnull construct() { values = 0; length = 0; capacity = 0; return this; }\n			void Add_(T value) { add_(value); }\n			void Clear_() { clear_(); }\n			void add_(T value);\n			void clear_() { length = 0; }\n			p_int op_magnitude() const { return length; }\n			T const & op_Element(p_int const index) const;\n		};\n\n		template<typename T>\n		void List_<T>::add_(T value)\n		{\n			if(length >= capacity)\n			{\n				int newCapacity = capacity == 0 ? 16 : capacity * 2;\n				// Allocate uninitalized buffer (note `sizeof(char) == 1` always)\n				// Needed if T is a value type to avoid needing a default constructor\n				T* newValues = (T*)new char[newCapacity * sizeof(T)];\n				std::memcpy(newValues, values, length * sizeof(T));\n				values = newValues;\n				capacity = newCapacity;\n			}\n			values[length] = value;\n			length++;\n		}\n\n		template<typename T>\n		T const & List_<T>::op_Element(p_int const index) const\n		{\n			if(index.value < 0 || index.value >= length)\n				throw std::out_of_range(\"List index out of bounds\");\n			return values[index.value];\n		}\n	}\n\n	namespace Console_\n	{\n		class Console_\n		{\n		public:\n			void Write_(p_string value);\n			void WriteLine_(p_string value);\n			void WriteLine_();\n		};\n\n		class Arguments_\n		{\n		private:\n			p_string *_Nonnull args;\n		public:\n			// Runtime Use Members\n			typedef p_string const *_Nonnull const_iterator;\n\n			Arguments_(int argc, char const *_Nonnull const *_Nonnull argv);\n			const_iterator begin() const { return &args[0]; }\n			const_iterator end() const { return &args[Count]; }\n\n			const int Count;\n\n			// Adamant Members\n			p_int op_magnitude() const { return Count; }\n			p_string const & op_Element(p_int const index) const\n			{\n				if(index.value < 0 || index.value >= Count)\n					throw std::out_of_range(\"Argument index out of bounds\");\n				return args[index.value];\n			}\n		};\n	}\n\n	namespace IO_\n	{\n		class File_Reader_\n		{\n		private:\n			std::FILE *_Nonnull file;\n\n		public:\n			File_Reader_ *_Nonnull construct(const p_string& fileName);\n			p_string ReadToEndSync_();\n			void Close_();\n		};\n\n		class File_Writer_\n		{\n		private:\n			std::FILE *_Nonnull file;\n\n		public:\n			File_Writer_ *_Nonnull construct(const p_string& fileName);\n			void Write_(const p_string& value);\n			void Close_();\n		};\n	}\n\n	namespace Text_\n	{\n		class String_Builder_\n		{\n		private:\n			char *_Nullable buffer;\n			int capacity;\n			int length;\n			void ensure_capacity(int needed);\n		public:\n			// Runtime Use Members\n			String_Builder_(): buffer(0), capacity(0), length(0) { }\n\n			// Adamant Members\n			p_bool op_equal(String_Builder_ const *_Nonnull other) const { return this == other; }\n			p_bool op_not_equal(String_Builder_ const *_Nonnull other) const { return this != other; }\n\n			String_Builder_ *_Nonnull construct() { return this; }\n			String_Builder_ *_Nonnull construct(p_string const & value);\n			void Append_(p_string const & value);\n			void Append_(String_Builder_ const *_Nonnull value);\n			void AppendLine_(p_string const& value);\n			void AppendLine_();\n			void Remove_(p_int start, p_int length);\n			void Remove_(p_int start);\n			p_string ToString_();\n		};\n	}\n}\n\nnamespace System_ = system_;\n"));

		return Main_(new ::System_::Console_::Console_(), new ::System_::Console_::Arguments_(argc, argv)).value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
