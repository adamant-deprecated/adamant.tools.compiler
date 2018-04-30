#include "RuntimeLibrary.hpp"

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
class Token_Stream_;
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
auto has_errors_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_) -> bit;
auto Main_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Console_::Arguments_ const *_Nonnull const args_) -> i32;
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
auto new_syntax_node_missing_(i32 const type_, ::Source_Text_ const *_Nonnull const source_, u32 const start_) -> ::Syntax_Node_ const *_Nonnull;
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
private:
	::Source_Text_ const *_Nonnull source_;
	::System_::Collections_::List_<i32> const *_Nonnull lineStarts_;
public:
	auto construct(::Source_Text_ const *_Nonnull const source_, ::System_::Collections_::List_<i32> const *_Nonnull const lineStarts_) -> ::Line_Info_*;
	auto Count_() const -> i32;
	auto get_(i32 const lineNumber_) const -> ::Text_Line_ const *_Nonnull;
	auto LineNumber_(i32 const offset_) const -> i32;
};

class Location_
{
public:
	auto construct() -> ::Location_* { return this; }
};

class Source_Text_
{
public:
	p_string Package_;
	p_string Path_;
	p_string name_;
	p_string Text_;
	::Line_Info_ const *_Nonnull Lines_;
	auto construct(p_string const package_, p_string const path_, p_string const text_) -> ::Source_Text_*;
private:
	auto LineStarts_() const -> ::System_::Collections_::List_<i32> const *_Nonnull;
public:
	auto ByteLength_() const -> i32;
	auto PositionOfStart_(::Text_Span_ const *_Nonnull const span_) const -> ::Text_Position_ const *_Nonnull;
};

class Text_Line_
{
public:
	::Source_Text_ const *_Nonnull source_;
	i32 start_;
	i32 byte_length_;
	auto construct(::Source_Text_ const *_Nonnull const source_, i32 const start_, i32 const length_) -> ::Text_Line_*;
	auto construct_spanning(::Source_Text_ const *_Nonnull const source_, i32 const start_, i32 const end_) -> ::Text_Line_*;
	auto End_() const -> i32;
};

class Text_Position_
{
public:
	i32 Offset_;
	i32 Line_;
	i32 Column_;
	auto construct(i32 const offset_, i32 const line_, i32 const column_) -> ::Text_Position_*;
};

class Text_Span_
{
public:
	i32 start_;
	i32 byte_length_;
	auto construct(i32 const start_, i32 const length_) -> ::Text_Span_*;
	auto End_() const -> i32;
};

class Source_File_Builder_
{
public:
private:
	::System_::Text_::String_Builder_ *_Nonnull code_;
	::System_::Text_::String_Builder_ *_Nonnull indent_;
	bit firstElement_;
	bit afterBlock_;
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
	auto byte_length_() const -> i32;
	auto ToString_() -> p_string;
};

class Compilation_Unit_
{
public:
	::Syntax_Node_ const *_Nonnull syntax_;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull declarations_;
	auto construct(::Syntax_Node_ const *_Nonnull const syntax_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_) -> ::Compilation_Unit_*;
	auto collect_diagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void;
};

class Package_
{
public:
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
	auto build_() const -> ::Package_ const *_Nonnull;
private:
	auto build_primitive_symbols_(::Package_Name_ const *_Nonnull const package_name_) const -> ::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull;
	static auto build_adamant_language_namespace_(::Name_ const *_Nonnull const global_namespace_) -> ::Symbol_ const *_Nonnull;
	static auto build_optional_(::Name_ const *_Nonnull const language_namespace_) -> ::Symbol_ const *_Nonnull;
	static auto build_primitive_(p_string const name_, ::Name_ const *_Nonnull const namespace_) -> ::Symbol_ const *_Nonnull;
	static auto build_fixed_point_primitives_(::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_, i32 const bits_, ::Name_ const *_Nonnull const namespace_) -> void;
public:
	auto construct() -> ::Primitives_Package_Builder_* { return this; }
};

class Runtime_Library_Package_Builder_
{
public:
	auto build_() const -> ::Package_ const *_Nonnull;
private:
	auto build_symbols_(::Package_Name_ const *_Nonnull const package_name_) const -> ::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull;
	static auto build_function_(::Name_ const *_Nonnull const name_) -> ::Symbol_ const *_Nonnull;
	static auto build_namespace_(::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const symbols_) -> ::Symbol_ const *_Nonnull;
	static auto build_class_(::Name_ const *_Nonnull const namespace_, p_string const class_name_) -> ::Symbol_ const *_Nonnull;
	static auto build_class_(::Name_ const *_Nonnull const namespace_, p_string const class_name_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_ const *_Nonnull;
	static auto build_generic_class_(::Name_ const *_Nonnull const namespace_, p_string const class_name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_) -> ::Symbol_ const *_Nonnull;
	static auto build_constructor_(p_string const name_) -> ::Symbol_ const *_Nonnull;
public:
	auto construct() -> ::Runtime_Library_Package_Builder_* { return this; }
};

class Semantic_Analyzer_
{
public:
	static auto analyze_(::Syntax_Node_ const *_Nonnull const package_syntax_) -> ::Package_ const *_Nonnull;
	auto construct() -> ::Semantic_Analyzer_* { return this; }
};

class Semantic_Node_
{
public:
	::Syntax_Node_ const *_Nonnull syntax_;
	i32 kind_;
	bit is_missing_;
	::Source_Text_ const *_Nonnull source_;
	u32 start_;
	u32 byte_length_;
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
	auto first_child_(i32 const kind_) const -> ::Semantic_Node_ const *_Nullable;
	auto children_of_kind_(i32 const kind_) const -> ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull;
	auto members_() const -> ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull;
	auto statements_() const -> ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull;
	auto parameters_() const -> ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull;
	auto access_modifier_() const -> ::Semantic_Node_ const *_Nullable;
	auto has_child_(i32 const kind_) const -> bit;
	auto add_(::Diagnostic_ const *_Nonnull const diagnostic_) -> void;
	auto diagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull;
public:
	auto collect_diagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void;
};

class Semantic_Tree_Builder_
{
public:
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
	static auto build_(::Package_Name_ const *_Nonnull const package_name_, ::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull> const *_Nonnull const compilation_units_) -> ::Symbol_ const *_Nonnull;
	auto construct() -> ::Symbol_Builder_* { return this; }
};

class Compilation_Unit_Parser_
{
public:
private:
	::Token_Stream_ *_Nonnull tokenStream_;
	::Syntax_Node_ const *_Nullable token_;
	::Syntax_Node_ const *_Nullable compilationUnit_;
public:
	auto construct(::Token_Stream_ *_Nonnull const tokenStream_) -> ::Compilation_Unit_Parser_*;
	auto Parse_() -> ::Syntax_Node_ const *_Nonnull;
private:
	auto AcceptToken_() -> ::Syntax_Node_ const *_Nullable;
	auto ExpectToken_(i32 const tokenType_) -> ::Syntax_Node_ const *_Nonnull;
	auto ParseTypeName_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseNonOptionalType_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseType_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseAtom_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseCallArguments_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseExpression_(i32 const minPrecedence_) -> ::Syntax_Node_ const *_Nonnull;
	auto ParseExpression_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseStatement_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseIfStatement_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseVariableDeclaration_(bit const allowInitializer_) -> ::Syntax_Node_ const *_Nonnull;
	auto ParseBlock_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseParameterList_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseMemberDeclaration_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseDeclaration_() -> ::Syntax_Node_ const *_Nonnull;
	auto ParseCompilationUnit_() -> ::Syntax_Node_ const *_Nonnull;
};

class Lexer_
{
public:
	auto analyze_(::Source_Text_ const *_Nonnull const source_) const -> ::Token_Stream_ *_Nonnull;
	auto construct() -> ::Lexer_* { return this; }
};

class Parser_
{
public:
	auto construct() -> ::Parser_*;
	auto ParsePackage_(::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const sources_) const -> ::Syntax_Node_ const *_Nonnull;
};

class Syntax_Node_
{
public:
	i32 kind_;
	bit is_missing_;
	::Source_Text_ const *_Nonnull source_;
	u32 start_;
	u32 byte_length_;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull children_;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull node_diagnostics_;
	auto construct(i32 const type_, ::Source_Text_ const *_Nonnull const source_, u32 const start_, u32 const length_) -> ::Syntax_Node_*;
	auto construct(i32 const type_, bit const isMissing_, ::Source_Text_ const *_Nonnull const source_, u32 const start_, u32 const length_) -> ::Syntax_Node_*;
	auto construct(i32 const type_, ::Syntax_Node_ const *_Nonnull const child_) -> ::Syntax_Node_*;
	auto construct(i32 const type_, ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull const children_) -> ::Syntax_Node_*;
	auto get_text_() const -> p_string;
	auto first_child_(i32 const type_) const -> ::Syntax_Node_ const *_Nullable;
	auto has_child_(i32 const type_) const -> bit;
	auto add_(::Diagnostic_ const *_Nonnull const diagnostic_) const -> void;
	auto all_diagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull;
	auto collect_diagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void;
	auto members_() const -> ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull;
	auto parameters_() const -> ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull;
	auto statements_() const -> ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull;
	auto access_modifier_() const -> ::Syntax_Node_ const *_Nullable;
};

class Token_Stream_
{
public:
	::Source_Text_ const *_Nonnull source_;
private:
	u32 position_;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull diagnostics_;
	bit endOfFile_;
public:
	auto construct(::Source_Text_ const *_Nonnull const source_) -> ::Token_Stream_*;
	auto GetNextToken_() -> ::Syntax_Node_ const *_Nullable;
private:
	auto EndOfFile_() -> ::Syntax_Node_ const *_Nullable;
	auto NewIdentifierOrKeyword_(u32 const end_) -> ::Syntax_Node_ const *_Nonnull;
	auto NewOperator_(i32 const type_) -> ::Syntax_Node_ const *_Nonnull;
	auto NewOperator_(i32 const type_, u32 const length_) -> ::Syntax_Node_ const *_Nonnull;
	auto NewToken_(i32 const type_, u32 const end_) -> ::Syntax_Node_ const *_Nonnull;
	static auto IsIdentifierChar_(p_code_point const c_) -> bit;
	static auto IsNumberChar_(p_code_point const c_) -> bit;
};

class Diagnostic_
{
public:
	i32 Level_;
	i32 Phase_;
	::Source_Text_ const *_Nonnull source_;
	::Text_Span_ const *_Nonnull Span_;
	::Text_Position_ const *_Nonnull Position_;
	p_string Message_;
	auto construct(i32 const level_, i32 const phase_, ::Source_Text_ const *_Nonnull const source_, ::Text_Span_ const *_Nonnull const span_, p_string const message_) -> ::Diagnostic_*;
};

class Diagnostic_Info_
{
public:
	auto construct() -> ::Diagnostic_Info_* { return this; }
};

class Emitter_
{
public:
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
	bit main_function_accepts_console_;
	bit main_function_accepts_args_;
public:
	auto construct(::Package_ const *_Nonnull const package_, ::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const resources_) -> ::Emitter_*;
	auto Emit_() -> p_string;
private:
	static auto convert_type_name_(::Semantic_Node_ const *_Nonnull const type_node_) -> ::System_::Text_::String_Builder_ *_Nonnull;
	static auto convert_type_name_(::Type_ const *_Nonnull const type_) -> ::System_::Text_::String_Builder_ *_Nonnull;
	static auto convert_reference_type_(bit const mutable_binding_, ::Type_ const *_Nonnull type_, bit const nullable_) -> p_string;
	static auto convert_type_(bit const mutable_binding_, ::Type_ const *_Nonnull type_, bit const optional_) -> p_string;
	static auto convert_type_(bit const mutable_binding_, ::Semantic_Node_ const *_Nonnull const type_node_) -> p_string;
	auto convert_parameter_list_(::Semantic_Node_ const *_Nonnull const parameters_, bit const is_main_function_) -> p_string;
	auto convert_parameter_list_(::Semantic_Node_ const *_Nonnull const parameters_) -> p_string;
	static auto convert_expression_(::Semantic_Node_ const *_Nonnull const syntax_, ::Source_File_Builder_ *_Nonnull const builder_) -> void;
	static auto convert_member_access_(::Semantic_Node_ const *_Nonnull const lhs_, ::Source_File_Builder_ *_Nonnull const builder_) -> void;
	auto emit_statement_(::Semantic_Node_ const *_Nonnull const statement_) -> void;
	auto emit_method_body_(::Semantic_Node_ const *_Nonnull const block_, bit const is_associated_function_) -> void;
	auto emit_constructor_body_(::Semantic_Node_ const *_Nonnull const block_, p_string const self_type_, bit const is_value_type_) -> void;
	auto emit_access_modifer_(i32 const current_access_level_, i32 const access_modifer_) -> i32;
	auto emit_member_declaration_(::Semantic_Node_ const *_Nonnull const member_, p_string const class_name_, bit const is_value_type_, i32 const current_access_level_) -> i32;
	auto emit_default_constructor_(p_string const type_name_, bit const is_value_type_, i32 const current_access_level_) -> void;
	auto emit_declaration_(::Semantic_Node_ const *_Nonnull const declaration_) -> void;
	auto emit_compilation_unit_(::Compilation_Unit_ const *_Nonnull const unit_) -> void;
	auto emit_preamble_() -> void;
	auto emit_entry_point_adapter_() -> void;
};

class Name_
{
public:
	::Package_Name_ const *_Nullable package_;
	i32 kind_;
	::System_::Collections_::List_<p_string> const *_Nonnull segments_;
	bit is_special_;
	auto construct_global_namespace() -> ::Name_*;
	auto construct_global_namespace(::Package_Name_ const *_Nonnull const package_) -> ::Name_*;
	auto construct(::Name_ const *_Nonnull const qualifier_, i32 const kind_, p_string const name_) -> ::Name_*;
	auto construct(::Name_ const *_Nonnull const qualifier_, i32 const kind_, p_string const name_, bit const is_special_) -> ::Name_*;
	auto construct_special(::Name_ const *_Nonnull const qualifier_, i32 const kind_, p_string const name_) -> ::Name_*;
private:
	auto construct(::Package_Name_ const *_Nullable const package_, i32 const kind_, ::System_::Collections_::List_<p_string> const *_Nonnull const segments_, bit const is_special_) -> ::Name_*;
public:
	auto unqualified_() const -> p_string;
	auto full_() const -> p_string;
	auto is_qualified_with_(::Name_ const *_Nonnull const qualifier_) const -> bit;
	auto qualifier_is_(::Name_ const *_Nonnull const qualifier_) const -> bit;
	auto names_(::Name_ const *_Nonnull const other_) const -> bit;
	auto is_package_qualified_() const -> bit;
	auto remove_package_() const -> ::Name_ const *_Nonnull;
};

class Package_Name_
{
public:
	p_string unqualified_;
	auto construct(p_string const name_) -> ::Package_Name_*;
	auto full_() const -> p_string;
};

class Symbol_
{
public:
	p_string name_;
	bit is_special_name_;
	i32 kind_;
	::Type_ const *_Nonnull of_type_;
	::Type_ const *_Nonnull declares_type_;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull declarations_;
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull children_;
	auto construct_identifier(p_string const name_) -> ::Symbol_*;
	auto construct_identifier(p_string const name_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_) -> ::Symbol_*;
	auto construct_identifier(p_string const name_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*;
	auto construct_constructor(p_string const name_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_) -> ::Symbol_*;
	auto construct_package(p_string const name_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*;
	auto construct_declaring(::Type_ const *_Nonnull const declares_type_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*;
	auto construct_of_type(p_string const name_, ::Type_ const *_Nonnull const of_type_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*;
	auto get_(p_string const name_, i32 const kind_) const -> ::Symbol_ const *_Nullable;
};

class Type_
{
public:
	i32 kind_;
	::Name_ const *_Nonnull name_;
	::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull type_parameters_;
	bit is_primitive_;
	bit is_value_type_;
	bit is_potentially_mutable_;
	bit is_mutable_;
	auto construct(i32 const kind_, ::Name_ const *_Nonnull const name_, bit const is_mutable_) -> ::Type_*;
	auto construct_parameter(p_string const name_) -> ::Type_*;
	auto construct(i32 const kind_, ::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_mutable_) -> ::Type_*;
	auto construct_primitive(::Name_ const *_Nonnull const name_) -> ::Type_*;
	auto construct_primitive(::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_) -> ::Type_*;
	auto construct_namespace(::Name_ const *_Nonnull const name_) -> ::Type_*;
	auto construct_generic(::Type_ const *_Nonnull const definition_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_arguments_) -> ::Type_*;
private:
	auto construct(i32 const kind_, ::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_primitive_, bit const is_potentially_mutable_, bit const is_mutable_) -> ::Type_*;
public:
	auto make_mutable_() const -> ::Type_ const *_Nonnull;
	auto make_immutable_() const -> ::Type_ const *_Nonnull;
	auto remove_package_() const -> ::Type_ const *_Nonnull;
};

class Name_Subtable_
{
public:
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
	auto find_(p_string const name_, bit const is_special_) const -> ::Name_Subtable_ *_Nullable;
public:
	auto lookup_(p_string const name_) const -> ::Name_Subtable_ *_Nullable;
	auto lookup_special_(p_string const name_) const -> ::Name_Subtable_ *_Nullable;
public:
	auto lookup_(p_string const name_, bit const is_special_) const -> ::Name_Subtable_ *_Nullable;
public:
	auto get_(::Name_ const *_Nonnull const name_) const -> ::Name_Subtable_ const *_Nullable;
	auto bind_type_(::Type_ const *_Nonnull const type_) -> void;
};

class Name_Table_
{
public:
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
i32 const Success_ = i32(0);
i32 const UsageError_ = i32(64);
i32 const DataError_ = i32(65);
i32 const SkippedTokens_ = i32(1).op_negate();
i32 const EndOfFileToken_ = i32(0);
i32 const LeftBrace_ = i32(1);
i32 const RightBrace_ = i32(2);
i32 const LeftParen_ = i32(3);
i32 const RightParen_ = i32(4);
i32 const Semicolon_ = i32(5);
i32 const Comma_ = i32(6);
i32 const Dot_ = i32(7);
i32 const Colon_ = i32(8);
i32 const LeftBracket_ = i32(9);
i32 const RightBracket_ = i32(10);
i32 const Question_ = i32(11);
i32 const EqualsEquals_ = i32(12);
i32 const Equals_ = i32(13);
i32 const PlusEquals_ = i32(14);
i32 const Plus_ = i32(15);
i32 const Arrow_ = i32(16);
i32 const MinusEquals_ = i32(17);
i32 const Minus_ = i32(18);
i32 const Slash_ = i32(19);
i32 const EqualsSlashEquals_ = i32(20);
i32 const LessThanEquals_ = i32(21);
i32 const LessThan_ = i32(22);
i32 const GreaterThanEquals_ = i32(23);
i32 const GreaterThan_ = i32(24);
i32 const StringLiteral_ = i32(25);
i32 const CodePointLiteral_ = i32(26);
i32 const Identifier_ = i32(27);
i32 const Number_ = i32(28);
i32 const NewKeyword_ = i32(29);
i32 const NotOperator_ = i32(30);
i32 const NullReservedWord_ = i32(31);
i32 const SelfKeyword_ = i32(32);
i32 const TrueKeyword_ = i32(33);
i32 const FalseKeyword_ = i32(34);
i32 const IdentifierName_ = i32(35);
i32 const GenericName_ = i32(36);
i32 const QualifiedName_ = i32(37);
i32 const PackageQualifiedName_ = i32(38);
i32 const MutableKeyword_ = i32(39);
i32 const OptionalType_ = i32(40);
i32 const PredefinedType_ = i32(41);
i32 const CodePoint_ = i32(42);
i32 const String_ = i32(43);
i32 const Int_ = i32(44);
i32 const Bool_ = i32(45);
i32 const Void_ = i32(46);
i32 const UnsignedInt_ = i32(47);
i32 const ParameterList_ = i32(48);
i32 const Parameter_ = i32(49);
i32 const SelfParameter_ = i32(50);
i32 const VarKeyword_ = i32(51);
i32 const MutableType_ = i32(52);
i32 const NewExpression_ = i32(53);
i32 const ArgumentList_ = i32(54);
i32 const NotExpression_ = i32(55);
i32 const ParenthesizedExpression_ = i32(56);
i32 const NoneLiteralExpression_ = i32(57);
i32 const SelfExpression_ = i32(58);
i32 const TrueLiteralExpression_ = i32(59);
i32 const FalseLiteralExpression_ = i32(60);
i32 const StringLiteralExpression_ = i32(61);
i32 const CodePointLiteralExpression_ = i32(62);
i32 const NumericLiteralExpression_ = i32(63);
i32 const AssignmentExpression_ = i32(64);
i32 const OrExpression_ = i32(65);
i32 const AndExpression_ = i32(66);
i32 const EqualExpression_ = i32(67);
i32 const NotEqualExpression_ = i32(68);
i32 const AndKeyword_ = i32(69);
i32 const OrKeyword_ = i32(70);
i32 const ComparisonExpression_ = i32(71);
i32 const AddExpression_ = i32(72);
i32 const SubtractExpression_ = i32(73);
i32 const InvocationExpression_ = i32(74);
i32 const MemberAccessExpression_ = i32(75);
i32 const ElementAccessExpression_ = i32(76);
i32 const NegateExpression_ = i32(77);
i32 const ReturnKeyword_ = i32(78);
i32 const ReturnStatement_ = i32(79);
i32 const LoopKeyword_ = i32(80);
i32 const LoopStatement_ = i32(81);
i32 const Block_ = i32(82);
i32 const WhileKeyword_ = i32(83);
i32 const WhileStatement_ = i32(84);
i32 const ForKeyword_ = i32(85);
i32 const ForStatement_ = i32(86);
i32 const LetKeyword_ = i32(87);
i32 const VariableDeclaration_ = i32(88);
i32 const LocalDeclarationStatement_ = i32(89);
i32 const InKeyword_ = i32(90);
i32 const DoKeyword_ = i32(91);
i32 const DoWhileStatement_ = i32(92);
i32 const IfKeyword_ = i32(93);
i32 const ElseKeyword_ = i32(94);
i32 const IfStatement_ = i32(95);
i32 const ElseClause_ = i32(96);
i32 const BreakKeyword_ = i32(97);
i32 const BreakStatement_ = i32(98);
i32 const ContinueKeyword_ = i32(99);
i32 const ContinueStatement_ = i32(100);
i32 const ExpressionStatement_ = i32(101);
i32 const PublicKeyword_ = i32(102);
i32 const ProtectedKeyword_ = i32(103);
i32 const InternalKeyword_ = i32(104);
i32 const PrivateKeyword_ = i32(105);
i32 const ConstructorDeclaration_ = i32(106);
i32 const FieldDeclaration_ = i32(107);
i32 const MethodDeclaration_ = i32(108);
i32 const GlobalDeclaration_ = i32(109);
i32 const ClassKeyword_ = i32(110);
i32 const ClassDeclaration_ = i32(111);
i32 const EnumKeyword_ = i32(112);
i32 const StructKeyword_ = i32(113);
i32 const EnumDeclaration_ = i32(114);
i32 const EnumMemberDeclaration_ = i32(115);
i32 const FunctionDeclaration_ = i32(116);
i32 const CompilationUnit_ = i32(117);
i32 const PackageNode_ = i32(118);
i32 const Percent_ = i32(119);
i32 const RemainderExpression_ = i32(120);
i32 const Pipe_ = i32(121);
i32 const MagnitudeExpression_ = i32(122);
i32 const Asterisk_ = i32(123);
i32 const MultiplyExpression_ = i32(124);
i32 const DivideExpression_ = i32(125);
i32 const NoneKeyword_ = i32(126);
i32 const StructDeclaration_ = i32(127);
i32 const ImmutableType_ = i32(128);
i32 const NamespaceDeclaration_ = i32(129);
i32 const Lexing_ = i32(1);
i32 const Parsing_ = i32(2);
i32 const Analysis_ = i32(3);
i32 const Info_ = i32(1);
i32 const Warning_ = i32(2);
i32 const RuntimeError_ = i32(3);
i32 const CompilationError_ = i32(4);
i32 const FatalCompilationError_ = i32(5);
i32 const NamespaceName_ = i32(1);
i32 const TypeName_ = i32(2);
i32 const FunctionName_ = i32(3);
i32 const TypeParameterName_ = i32(4);
i32 const VariableName_ = i32(5);
i32 const IdentifierSymbol_ = i32(0);
i32 const PackageSymbol_ = i32(1);
i32 const ReferenceType_ = i32(1);
i32 const ValueType_ = i32(2);
i32 const NamespaceType_ = i32(3);
i32 const TypeParameterType_ = i32(4);
i32 const FunctionType_ = i32(5);

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
		if (cond(equal_op(diagnostic_->Level_, Info_)))
		{
			severity_ = p_string("Informational");
		}
		else if (cond(equal_op(diagnostic_->Level_, Warning_)))
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

auto has_errors_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_) -> bit
{
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(diagnostics_))
	{
		if (cond(diagnostic_->Level_->op_greater_than_or_equal(CompilationError_)))
		{
			return bit_true;
		}
	}

	return bit_false;
}

auto Main_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Console_::Arguments_ const *_Nonnull const args_) -> i32
{
	if (cond(bit_op(bit_arg(equal_op(args_->op_magnitude(), i32(1))) && bit_arg(equal_op(args_->op_Element(i32(0)), p_string("--unit-test"))))))
	{
		run_unit_tests_(console_);
		return i32(0);
	}

	::System_::Collections_::List_<p_string> *_Nonnull const sourceFilePaths_ = (new ::System_::Collections_::List_<p_string>())->construct();
	::System_::Collections_::List_<p_string> *_Nonnull const resourceFilePaths_ = (new ::System_::Collections_::List_<p_string>())->construct();
	p_string outputFilePath_ = p_string("");
	bit verbose_ = bit_false;
	i32 argType_ = i32(0);
	for (p_string const arg_ : *(args_))
	{
		if (cond(equal_op(argType_, i32(0))))
		{
			if (cond(equal_op(arg_, p_string("-r"))))
			{
				argType_ = i32(1);
			}
			else if (cond(equal_op(arg_, p_string("-o"))))
			{
				argType_ = i32(2);
			}
			else if (cond(bit_op(bit_arg(equal_op(arg_, p_string("-v"))) || bit_arg(equal_op(arg_, p_string("--verbose"))))))
			{
				verbose_ = bit_true;
			}
			else
			{
				sourceFilePaths_->Add_(arg_);
			}
		}
		else if (cond(equal_op(argType_, i32(1))))
		{
			resourceFilePaths_->Add_(arg_);
			argType_ = i32(0);
		}
		else if (cond(equal_op(argType_, i32(2))))
		{
			outputFilePath_ = arg_;
			argType_ = i32(0);
		}
	}

	if (cond(verbose_))
	{
		console_->WriteLine_(p_string("Adamant Compiler v0.1.0"));
	}

	if (cond(bit_op(bit_arg(equal_op(sourceFilePaths_->op_magnitude(), i32(0))) || bit_arg(equal_op(outputFilePath_, p_string(""))))))
	{
		console_->WriteLine_(p_string("Args: <Input File(s)> -o <OutputFile> -r <Resource File>"));
		return UsageError_;
	}

	::System_::Collections_::List_<::Source_Text_ const *_Nonnull> *_Nonnull const resources_ = (new ::System_::Collections_::List_<::Source_Text_ const *_Nonnull>())->construct();
	if (cond(resourceFilePaths_->op_magnitude()->op_greater_than(i32(0))))
	{
		if (cond(verbose_))
		{
			console_->WriteLine_(p_string("Reading Resources:"));
		}

		for (p_string const resourceFilePath_ : *(resourceFilePaths_))
		{
			if (cond(verbose_))
			{
				console_->WriteLine_(p_string("  ").op_add(resourceFilePath_));
			}

			resources_->Add_(read_source_(resourceFilePath_));
		}
	}

	if (cond(verbose_))
	{
		console_->WriteLine_(p_string("Compiling:"));
	}

	::System_::Collections_::List_<::Source_Text_ const *_Nonnull> *_Nonnull const sources_ = (new ::System_::Collections_::List_<::Source_Text_ const *_Nonnull>())->construct();
	for (p_string const sourceFilePath_ : *(sourceFilePaths_))
	{
		if (cond(verbose_))
		{
			console_->WriteLine_(p_string("  ").op_add(sourceFilePath_));
		}

		sources_->Add_(read_source_(sourceFilePath_));
	}

	::Package_ const *_Nonnull const package_ = compile_(sources_);
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_ = package_->all_diagnostics_();
	write_(console_, diagnostics_);
	if (cond(has_errors_(diagnostics_)))
	{
		return DataError_;
	}

	::Emitter_ *_Nonnull emitter_ = (new ::Emitter_())->construct(package_, resources_);
	p_string const translated_ = emitter_->Emit_();
	if (cond(verbose_))
	{
		console_->Write_(p_string("Output: "));
		console_->WriteLine_(outputFilePath_);
	}

	::System_::IO_::File_Writer_ *_Nonnull const outputFile_ = (new ::System_::IO_::File_Writer_())->construct(outputFilePath_);
	outputFile_->Write_(translated_);
	outputFile_->Close_();
	p_string outputDirPath_ = outputFilePath_;
	i32 index_ = outputDirPath_.LastIndexOf_(p_code_point('/'));
	if (cond(not_equal_op(index_, i32(1).op_negate())))
	{
		outputDirPath_ = outputDirPath_.Substring_(i32(0), index_.op_add(i32(1)));
	}

	index_ = outputDirPath_.LastIndexOf_(p_code_point('\\'));
	if (cond(not_equal_op(index_, i32(1).op_negate())))
	{
		outputDirPath_ = outputDirPath_.Substring_(i32(0), index_.op_add(i32(1)));
	}

	if (cond(verbose_))
	{
		console_->Write_(p_string("Outputting RuntimeLibrary to: "));
		console_->WriteLine_(outputDirPath_);
	}

	::System_::IO_::File_Writer_ *_Nonnull resourceFile_ = (new ::System_::IO_::File_Writer_())->construct(outputDirPath_.op_add(p_string("RuntimeLibrary.hpp")));
	resourceFile_->Write_(resource_manager_->GetString_(p_string("RuntimeLibrary.hpp")));
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

auto ::Line_Info_::construct(::Source_Text_ const *_Nonnull const source_, ::System_::Collections_::List_<i32> const *_Nonnull const lineStarts_) -> ::Line_Info_*
{
	::Line_Info_* self = this;
	self->source_ = source_;
	self->lineStarts_ = lineStarts_;
	return self;
}

auto ::Line_Info_::Count_() const -> i32
{
	auto self = this;
	return lineStarts_->op_magnitude();
}

auto ::Line_Info_::get_(i32 const lineNumber_) const -> ::Text_Line_ const *_Nonnull
{
	auto self = this;
	i32 const index_ = lineNumber_.op_subtract(i32(1));
	i32 const start_ = lineStarts_->op_Element(index_);
	if (cond(equal_op(index_, lineStarts_->op_magnitude()->op_subtract(i32(1)))))
	{
		return (new ::Text_Line_())->construct_spanning(source_, start_, source_->ByteLength_());
	}

	i32 const end_ = lineStarts_->op_Element(index_.op_add(i32(1)));
	return (new ::Text_Line_())->construct_spanning(source_, start_, end_);
}

auto ::Line_Info_::LineNumber_(i32 const offset_) const -> i32
{
	auto self = this;
	i32 left_ = i32(0);
	i32 right_ = lineStarts_->op_magnitude()->op_subtract(i32(1));
	while (cond(left_.op_less_than_or_equal(right_)))
	{
		i32 const mid_ = left_.op_add(right_.op_subtract(left_)->op_divide(i32(2)));
		i32 const midLineStart_ = lineStarts_->op_Element(mid_);
		if (cond(midLineStart_.op_less_than(offset_)))
		{
			left_ = mid_.op_add(i32(1));
		}
		else if (cond(midLineStart_.op_greater_than(offset_)))
		{
			right_ = mid_.op_subtract(i32(1));
		}
		else
		{
			return mid_.op_add(i32(1));
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
	i32 index_ = name_.LastIndexOf_(p_code_point('/'));
	if (cond(not_equal_op(index_, i32(1).op_negate())))
	{
		name_ = name_.Substring_(index_.op_add(i32(1)));
	}

	index_ = name_.LastIndexOf_(p_code_point('\\'));
	if (cond(not_equal_op(index_, i32(1).op_negate())))
	{
		name_ = name_.Substring_(index_.op_add(i32(1)));
	}

	self->name_ = name_;
	Text_ = text_;
	Lines_ = (new ::Line_Info_())->construct(self, LineStarts_());
	return self;
}

auto ::Source_Text_::LineStarts_() const -> ::System_::Collections_::List_<i32> const *_Nonnull
{
	auto self = this;
	i32 const length_ = ByteLength_();
	::System_::Collections_::List_<i32> *_Nonnull const lineStarts_ = (new ::System_::Collections_::List_<i32>())->construct();
	lineStarts_->Add_(i32(0));
	i32 position_ = i32(0);
	while (cond(position_.op_less_than(length_)))
	{
		p_code_point const c_ = Text_.op_Element(position_);
		position_.op_add_assign(i32(1));
		if (cond(bit_op(bit_arg(c_.op_greater_than(p_code_point('\r'))) && bit_arg(c_.op_less_than_or_equal(p_code_point('\x7F'))))))
		{
			continue;
		}

		if (cond(equal_op(c_, p_code_point('\r'))))
		{
			if (cond(bit_op(bit_arg(position_.op_less_than(length_)) && bit_arg(equal_op(Text_.op_Element(position_), p_code_point('\n'))))))
			{
				position_.op_add_assign(i32(1));
			}
		}
		else if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(c_, p_code_point('\n'))) || bit_arg(equal_op(c_, p_code_point('\x0B'))))) || bit_arg(equal_op(c_, p_code_point('\f'))))) || bit_arg(equal_op(c_, p_code_point('\x85'))))))
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

auto ::Source_Text_::ByteLength_() const -> i32
{
	auto self = this;
	return Text_.ByteLength_();
}

auto ::Source_Text_::PositionOfStart_(::Text_Span_ const *_Nonnull const span_) const -> ::Text_Position_ const *_Nonnull
{
	auto self = this;
	i32 const offset_ = span_->start_;
	i32 const lineNumber_ = Lines_->LineNumber_(offset_);
	i32 const lineStart_ = Lines_->get_(lineNumber_)->start_;
	i32 column_ = offset_.op_subtract(lineStart_)->op_add(i32(1));
	i32 i_ = lineStart_;
	while (cond(i_.op_less_than(offset_)))
	{
		if (cond(equal_op(Text_.op_Element(i_), p_code_point('\t'))))
		{
			column_.op_add_assign(i32(3));
		}

		i_.op_add_assign(i32(1));
	}

	return (new ::Text_Position_())->construct(offset_, lineNumber_, column_);
}

auto ::Text_Line_::construct(::Source_Text_ const *_Nonnull const source_, i32 const start_, i32 const length_) -> ::Text_Line_*
{
	::Text_Line_* self = this;
	self->source_ = source_;
	self->start_ = start_;
	byte_length_ = length_;
	return self;
}

auto ::Text_Line_::construct_spanning(::Source_Text_ const *_Nonnull const source_, i32 const start_, i32 const end_) -> ::Text_Line_*
{
	::Text_Line_* self = this;
	self->source_ = source_;
	self->start_ = start_;
	self->byte_length_ = end_.op_subtract(start_);
	return self;
}

auto ::Text_Line_::End_() const -> i32
{
	auto self = this;
	return start_.op_add(byte_length_);
}

auto ::Text_Position_::construct(i32 const offset_, i32 const line_, i32 const column_) -> ::Text_Position_*
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
	::Text_Position_ const *_Nonnull const position_ = (new ::Text_Position_())->construct(i32(23), i32(2), i32(5));
	assert_(equal_op(position_->Offset_, i32(23)), p_string(""));
	assert_(equal_op(position_->Line_, i32(2)), p_string(""));
	assert_(equal_op(position_->Column_, i32(5)), p_string(""));
}

auto ::Text_Span_::construct(i32 const start_, i32 const length_) -> ::Text_Span_*
{
	::Text_Span_* self = this;
	self->start_ = start_;
	byte_length_ = length_;
	return self;
}

auto ::Text_Span_::End_() const -> i32
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
	firstElement_ = bit_true;
	afterBlock_ = bit_true;
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
	firstElement_ = afterBlock_ = bit_false;
}

auto ::Source_File_Builder_::Write_(p_string const value_) -> void
{
	auto self = this;
	code_->Append_(value_);
	firstElement_ = afterBlock_ = bit_false;
}

auto ::Source_File_Builder_::EndLine_(p_string const value_) -> void
{
	auto self = this;
	code_->Append_(value_);
	code_->AppendLine_();
	firstElement_ = afterBlock_ = bit_false;
}

auto ::Source_File_Builder_::WriteLine_(p_string const value_) -> void
{
	auto self = this;
	code_->Append_(indent_);
	code_->Append_(value_);
	code_->AppendLine_();
	firstElement_ = afterBlock_ = bit_false;
}

auto ::Source_File_Builder_::BlankLine_() -> void
{
	auto self = this;
	code_->AppendLine_();
	firstElement_ = bit_true;
	afterBlock_ = bit_false;
}

auto ::Source_File_Builder_::ElementSeparatorLine_() -> void
{
	auto self = this;
	if (cond(bit_not(firstElement_)))
	{
		code_->AppendLine_();
		firstElement_ = bit_true;
		afterBlock_ = bit_false;
	}
}

auto ::Source_File_Builder_::StatementSeparatorLine_() -> void
{
	auto self = this;
	if (cond(afterBlock_))
	{
		code_->AppendLine_();
		firstElement_ = bit_true;
		afterBlock_ = bit_false;
	}
}

auto ::Source_File_Builder_::BeginBlock_() -> void
{
	auto self = this;
	WriteLine_(p_string("{"));
	indent_->Append_(p_string("\t"));
	firstElement_ = afterBlock_ = bit_false;
}

auto ::Source_File_Builder_::EndBlock_() -> void
{
	auto self = this;
	indent_->Remove_(i32(0), i32(1));
	WriteLine_(p_string("}"));
	afterBlock_ = bit_true;
}

auto ::Source_File_Builder_::EndBlockWithSemicolon_() -> void
{
	auto self = this;
	indent_->Remove_(i32(0), i32(1));
	WriteLine_(p_string("};"));
}

auto ::Source_File_Builder_::byte_length_() const -> i32
{
	auto self = this;
	return code_->byte_length_();
}

auto ::Source_File_Builder_::ToString_() -> p_string
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
	assert_(primitive_symbols_->op_magnitude()->op_greater_than(i32(0)), p_string("|primitive_symbols|=").op_add(primitive_symbols_->op_magnitude()));
	::Symbol_ const *_Nonnull const package_symbol_ = (new ::Symbol_())->construct_package(name_->unqualified_, primitive_symbols_);
	assert_(package_symbol_->children_->op_magnitude()->op_greater_than(i32(0)), p_string("|package_symbol.children|=").op_add(package_symbol_->children_->op_magnitude()));
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
	build_fixed_point_primitives_(symbols_, i32(8), global_namespace_);
	build_fixed_point_primitives_(symbols_, i32(16), global_namespace_);
	build_fixed_point_primitives_(symbols_, i32(32), global_namespace_);
	build_fixed_point_primitives_(symbols_, i32(64), global_namespace_);
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
	type_parameters_->add_((new ::Type_())->construct(TypeParameterType_, (new ::Name_())->construct(optional_name_, TypeParameterName_, p_string("T")), bit_true));
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

auto ::Primitives_Package_Builder_::build_fixed_point_primitives_(::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_, i32 const bits_, ::Name_ const *_Nonnull const namespace_) -> void
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
	assert_(equal_op(name_->unqualified_, p_string("$primitives")), p_string(""));
}

auto Package_has_no_references_or_compilation_units_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	assert_(equal_op(package_->references_->op_magnitude(), i32(0)), p_string(""));
	assert_(equal_op(package_->compilation_units_->op_magnitude(), i32(0)), p_string(""));
}

auto Package_symbol_has_package_name_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	::Symbol_ const *_Nonnull const symbol_ = package_->symbol_;
	assert_(equal_op(symbol_->kind_, PackageSymbol_), p_string(""));
	assert_(equal_op(symbol_->name_, package_->name_->unqualified_), p_string(""));
}

auto Package_symbol_has_children_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	assert_(package_->symbol_->children_->op_magnitude()->op_greater_than(i32(0)), p_string(""));
}

auto Package_contains_the_string_type_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	::Symbol_ const *_Nonnull const string_symbol_ = package_->symbol_->get_(p_string("string"), IdentifierSymbol_);
	assert_(not_equal_op(string_symbol_, none), p_string(""));
}

auto Package_contains_optional_type_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	::Symbol_ const *_Nullable const adamant_symbol_ = package_->symbol_->get_(p_string("adamant"), IdentifierSymbol_);
	assert_(not_equal_op(adamant_symbol_, none), p_string(""));
	::Symbol_ const *_Nullable const langauge_symbol_ = adamant_symbol_->get_(p_string("language"), IdentifierSymbol_);
	assert_(not_equal_op(langauge_symbol_, none), p_string(""));
	::Symbol_ const *_Nullable const optional_symbol_ = langauge_symbol_->get_(p_string("optional"), IdentifierSymbol_);
	assert_(not_equal_op(optional_symbol_, none), p_string(""));
}

auto ::Runtime_Library_Package_Builder_::build_() const -> ::Package_ const *_Nonnull
{
	auto self = this;
	::Package_Name_ const *_Nonnull const name_ = (new ::Package_Name_())->construct(p_string("$runtime"));
	::System_::Collections_::List_<::Package_Reference_> const *_Nonnull const references_ = (new ::System_::Collections_::List_<::Package_Reference_>())->construct();
	::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull> const *_Nonnull const compilation_units_ = (new ::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull>())->construct();
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_ = build_symbols_(name_);
	assert_(symbols_->op_magnitude()->op_greater_than(i32(0)), p_string("|symbols|=").op_add(symbols_->op_magnitude()));
	::Symbol_ const *_Nonnull const package_symbol_ = (new ::Symbol_())->construct_package(name_->unqualified_, symbols_);
	assert_(package_symbol_->children_->op_magnitude()->op_greater_than(i32(0)), p_string("|package_symbol.children|=").op_add(package_symbol_->children_->op_magnitude()));
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
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const string_builder_symbols_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	string_builder_symbols_->Add_(build_constructor_(p_string("with_capacity")));
	text_symbols_->Add_(build_class_(text_namespace_, p_string("String_Builder"), string_builder_symbols_));
	system_symbols_->Add_(build_namespace_(text_namespace_, text_symbols_));
	symbols_->Add_(build_namespace_(system_namespace_, system_symbols_));
	return symbols_;
}

auto ::Runtime_Library_Package_Builder_::build_function_(::Name_ const *_Nonnull const name_) -> ::Symbol_ const *_Nonnull
{
	::Type_ const *_Nonnull const type_ = (new ::Type_())->construct(FunctionType_, name_, bit_false);
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return (new ::Symbol_())->construct_of_type(name_->unqualified_(), type_, declarations_, children_);
}

auto ::Runtime_Library_Package_Builder_::build_namespace_(::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const symbols_) -> ::Symbol_ const *_Nonnull
{
	::Type_ const *_Nonnull const type_ = (new ::Type_())->construct_namespace(name_);
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	return (new ::Symbol_())->construct_declaring(type_, declarations_, symbols_);
}

auto ::Runtime_Library_Package_Builder_::build_class_(::Name_ const *_Nonnull const namespace_, p_string const class_name_) -> ::Symbol_ const *_Nonnull
{
	::Type_ const *_Nonnull const type_ = (new ::Type_())->construct(ReferenceType_, (new ::Name_())->construct(namespace_, TypeName_, class_name_), bit_true);
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return (new ::Symbol_())->construct_declaring(type_, declarations_, children_);
}

auto ::Runtime_Library_Package_Builder_::build_class_(::Name_ const *_Nonnull const namespace_, p_string const class_name_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_ const *_Nonnull
{
	::Type_ const *_Nonnull const type_ = (new ::Type_())->construct(ReferenceType_, (new ::Name_())->construct(namespace_, TypeName_, class_name_), bit_true);
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	return (new ::Symbol_())->construct_declaring(type_, declarations_, children_);
}

auto ::Runtime_Library_Package_Builder_::build_generic_class_(::Name_ const *_Nonnull const namespace_, p_string const class_name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_) -> ::Symbol_ const *_Nonnull
{
	::Type_ const *_Nonnull const type_ = (new ::Type_())->construct(ReferenceType_, (new ::Name_())->construct(namespace_, TypeName_, class_name_), type_parameters_, bit_true);
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return (new ::Symbol_())->construct_declaring(type_, declarations_, children_);
}

auto ::Runtime_Library_Package_Builder_::build_constructor_(p_string const name_) -> ::Symbol_ const *_Nonnull
{
	p_string const constructor_name_ = p_string("new_").op_add(name_);
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	return (new ::Symbol_())->construct_constructor(constructor_name_, declarations_);
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
	assert_(not_equal_op(package_->symbol_->get_(p_string("System"), IdentifierSymbol_), none), p_string(""));
}

auto System_namespace_contains_Console_namespace_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	::Symbol_ const *_Nonnull const system_namespace_ = package_->symbol_->get_(p_string("System"), IdentifierSymbol_);
	assert_(not_equal_op(system_namespace_->get_(p_string("Console"), IdentifierSymbol_), none), p_string(""));
}

auto Console_namespace_contains_Console_class_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	::Symbol_ const *_Nonnull const system_namespace_ = package_->symbol_->get_(p_string("System"), IdentifierSymbol_);
	::Symbol_ const *_Nonnull const console_namespace_ = system_namespace_->get_(p_string("Console"), IdentifierSymbol_);
	assert_(not_equal_op(console_namespace_->get_(p_string("Console"), IdentifierSymbol_), none), p_string(""));
}

auto System_namespace_contains_Collections_namespace_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	::Symbol_ const *_Nonnull const system_namespace_ = package_->symbol_->get_(p_string("System"), IdentifierSymbol_);
	assert_(not_equal_op(system_namespace_->get_(p_string("Collections"), IdentifierSymbol_), none), p_string(""));
}

auto Collections_namespace_contains_List_class_() -> void
{
	::Package_ const *_Nonnull const package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	::Symbol_ const *_Nonnull const system_namespace_ = package_->symbol_->get_(p_string("System"), IdentifierSymbol_);
	::Symbol_ const *_Nonnull const console_namespace_ = system_namespace_->get_(p_string("Collections"), IdentifierSymbol_);
	assert_(not_equal_op(console_namespace_->get_(p_string("List"), IdentifierSymbol_), none), p_string(""));
}

auto ::Semantic_Analyzer_::analyze_(::Syntax_Node_ const *_Nonnull const package_syntax_) -> ::Package_ const *_Nonnull
{
	assert_(equal_op(package_syntax_->kind_, PackageNode_), p_string("package_syntax.kind=").op_add(package_syntax_->kind_));
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
	assert_(not_equal_op(syntax_, none), p_string(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	self->node_diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	self->of_type_ = none;
	self->converted_type_ = none;
	self->declares_type_ = none;
	self->referenced_type_ = none;
	return self;
}

auto ::Semantic_Node_::construct_concrete(::Syntax_Node_ const *_Nonnull const syntax_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const children_) -> ::Semantic_Node_*
{
	::Semantic_Node_* self = this;
	assert_(not_equal_op(syntax_, none), p_string(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = children_;
	self->node_diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	self->of_type_ = none;
	self->converted_type_ = none;
	self->declares_type_ = none;
	self->referenced_type_ = none;
	return self;
}

auto ::Semantic_Node_::construct_of_type(::Type_ const *_Nonnull const of_type_, ::Syntax_Node_ const *_Nonnull const syntax_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const children_) -> ::Semantic_Node_*
{
	::Semantic_Node_* self = this;
	assert_(not_equal_op(of_type_, none), p_string(""));
	assert_(not_equal_op(syntax_, none), p_string(""));
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
	self->declares_type_ = none;
	self->referenced_type_ = none;
	return self;
}

auto ::Semantic_Node_::construct_referencing_type(::Type_ const *_Nonnull const type_, ::Syntax_Node_ const *_Nonnull const syntax_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const children_) -> ::Semantic_Node_*
{
	::Semantic_Node_* self = this;
	assert_(not_equal_op(type_, none), p_string(""));
	assert_(not_equal_op(syntax_, none), p_string(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = children_;
	self->node_diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	self->of_type_ = none;
	self->converted_type_ = none;
	self->declares_type_ = none;
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
	if (cond(equal_op(source_, none)))
	{
		return p_string("$No Source$");
	}

	return source_->Text_->Substring_(start_, byte_length_);
}

auto ::Semantic_Node_::first_child_(i32 const kind_) const -> ::Semantic_Node_ const *_Nullable
{
	auto self = this;
	for (::Semantic_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (cond(equal_op(child_->kind_, kind_)))
		{
			return child_;
		}
	}

	return none;
}

auto ::Semantic_Node_::children_of_kind_(i32 const kind_) const -> ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	for (::Semantic_Node_ const *_Nonnull const child_ : *(self->children_))
	{
		if (cond(equal_op(child_->kind_, kind_)))
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
		if (cond(bit_op(bit_arg(bit_op(bit_arg(equal_op(child_->kind_, ConstructorDeclaration_)) || bit_arg(equal_op(child_->kind_, FieldDeclaration_)))) || bit_arg(equal_op(child_->kind_, MethodDeclaration_)))))
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
		if (cond(bit_op(bit_arg(not_equal_op(child_->kind_, LeftBrace_)) && bit_arg(not_equal_op(child_->kind_, RightBrace_)))))
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
		if (cond(bit_op(bit_arg(equal_op(child_->kind_, Parameter_)) || bit_arg(equal_op(child_->kind_, SelfParameter_)))))
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
		if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(child_->kind_, PublicKeyword_)) || bit_arg(equal_op(child_->kind_, ProtectedKeyword_)))) || bit_arg(equal_op(child_->kind_, PrivateKeyword_)))) || bit_arg(equal_op(child_->kind_, InternalKeyword_)))))
		{
			return child_;
		}
	}

	return none;
}

auto ::Semantic_Node_::has_child_(i32 const kind_) const -> bit
{
	auto self = this;
	for (::Semantic_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (cond(equal_op(child_->kind_, kind_)))
		{
			return bit_true;
		}
	}

	return bit_false;
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
	assert_(equal_op(package_syntax_->kind_, PackageNode_), p_string("package_syntax.kind=").op_add(package_syntax_->kind_));
	assert_(not_equal_op(name_table_->any_package_->lookup_special_(p_string("string")), none), p_string("name_table.any_package.name=").op_add(name_table_->any_package_->name_->full_()));
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
	assert_(equal_op(compilation_unit_syntax_->kind_, CompilationUnit_), p_string("compilation_unit_syntax.kind=").op_add(compilation_unit_syntax_->kind_));
	::Name_Subtable_ const *_Nonnull const scope_ = none;
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
	if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, FunctionDeclaration_)) || bit_arg(equal_op(syntax_->kind_, MethodDeclaration_)))))
	{
		children_->add_(build_(syntax_->access_modifier_(), name_table_, scope_));
		::Syntax_Node_ const *_Nonnull const function_name_ = syntax_->first_child_(Identifier_);
		children_->add_(build_(function_name_, name_table_, scope_));
		::Name_Subtable_ *_Nonnull const function_scope_ = scope_->find_(function_name_->get_text_());
		assert_(not_equal_op(function_scope_, none), p_string("function_name.get_text()=").op_add(function_name_->get_text_()));
		::Syntax_Node_ const *_Nonnull const parameters_ = syntax_->first_child_(ParameterList_);
		children_->add_(build_parameters_(parameters_, name_table_, function_scope_));
		::Syntax_Node_ const *_Nonnull const return_type_ = syntax_->children_->op_Element(i32(4));
		children_->add_(build_type_name_(return_type_, name_table_, scope_));
		::Type_ const *_Nonnull const function_type_ = (new ::Type_())->construct(FunctionType_, function_scope_->name_, bit_false);
		function_scope_->bind_type_(function_type_);
		::Syntax_Node_ const *_Nonnull const body_ = syntax_->first_child_(Block_);
		if (cond(not_equal_op(body_, none)))
		{
			children_->add_(build_(body_, name_table_, function_scope_));
		}

		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
	else if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, ClassDeclaration_)) || bit_arg(equal_op(syntax_->kind_, StructDeclaration_)))))
	{
		::Syntax_Node_ const *_Nonnull const type_name_ = syntax_->first_child_(Identifier_);
		children_->add_(build_(type_name_, name_table_, scope_));
		::Name_Subtable_ const *_Nonnull const type_scope_ = scope_->find_(type_name_->get_text_());
		assert_(not_equal_op(type_scope_, none), p_string("type_name.get_text()=").op_add(type_name_->get_text_()));
		for (::Syntax_Node_ const *_Nonnull const member_ : *(syntax_->members_()))
		{
			children_->add_(build_(member_, name_table_, type_scope_));
		}

		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, ConstructorDeclaration_)))
	{
		children_->add_(build_(syntax_->access_modifier_(), name_table_, scope_));
		p_string full_name_ = p_string("new");
		::Syntax_Node_ const *_Nullable const constructor_name_ = syntax_->first_child_(Identifier_);
		if (cond(not_equal_op(constructor_name_, none)))
		{
			full_name_ = p_string("new_").op_add(constructor_name_->get_text_());
			children_->add_((new ::Semantic_Node_())->construct_token(constructor_name_));
		}

		::Name_Subtable_ const *_Nonnull const constructor_scope_ = scope_->find_special_(full_name_);
		assert_(not_equal_op(constructor_scope_, none), p_string("full_name=").op_add(full_name_));
		::Syntax_Node_ const *_Nonnull const parameters_ = syntax_->first_child_(ParameterList_);
		children_->add_(build_parameters_(parameters_, name_table_, constructor_scope_));
		::Syntax_Node_ const *_Nonnull const body_ = syntax_->first_child_(Block_);
		if (cond(not_equal_op(body_, none)))
		{
			children_->add_(build_(body_, name_table_, constructor_scope_));
		}

		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, IdentifierName_)))
	{
		::Name_Subtable_ const *_Nonnull const name_scope_ = scope_->lookup_(syntax_->get_text_());
		if (cond(equal_op(name_scope_, none)))
		{
			::Semantic_Node_ *_Nonnull const node_ = (new ::Semantic_Node_())->construct_token(syntax_);
			if (cond(bit_not(syntax_->is_missing_)))
			{
				add_resolution_error_(node_);
			}

			return node_;
		}
		else
		{
			i32 const place_ = syntax_->start_;
			if (cond(equal_op(name_scope_->type_, none)))
			{
				return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
			}
			else
			{
				return (new ::Semantic_Node_())->construct_of_type(name_scope_->type_, syntax_, children_);
			}
		}
	}
	else if (cond(equal_op(syntax_->kind_, MemberAccessExpression_)))
	{
		children_->add_(build_(syntax_->children_->op_Element(i32(0)), name_table_, scope_));
		children_->add_((new ::Semantic_Node_())->construct_token(syntax_->children_->op_Element(i32(2))));
		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, NewExpression_)))
	{
		children_->add_(build_constructor_name_(syntax_->children_->op_Element(i32(1)), name_table_, scope_));
		children_->add_(build_(syntax_->first_child_(ArgumentList_), name_table_, scope_));
		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, LocalDeclarationStatement_)))
	{
		::Syntax_Node_ const *_Nonnull const variable_declaration_ = syntax_->first_child_(VariableDeclaration_);
		children_->add_(build_(variable_declaration_, name_table_, scope_));
		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, VariableDeclaration_)))
	{
		::Syntax_Node_ const *_Nonnull const binding_syntax_ = syntax_->children_->op_Element(i32(0));
		children_->add_((new ::Semantic_Node_())->construct_token(binding_syntax_));
		::Syntax_Node_ const *_Nonnull const identifier_ = syntax_->first_child_(Identifier_);
		children_->add_((new ::Semantic_Node_())->construct_token(identifier_));
		::Syntax_Node_ const *_Nonnull const type_syntax_ = syntax_->children_->op_Element(i32(3));
		::Semantic_Node_ const *_Nonnull const type_node_ = build_type_name_(type_syntax_, name_table_, scope_);
		assert_(not_equal_op(type_node_->referenced_type_, none), type_node_->get_text_());
		::Name_Subtable_ *_Nonnull const variable_scope_ = scope_->lookup_(identifier_->get_text_());
		assert_(not_equal_op(variable_scope_, none), syntax_->get_text_());
		variable_scope_->bind_type_(type_node_->referenced_type_);
		children_->add_(type_node_);
		if (cond(equal_op(syntax_->children_->op_magnitude(), i32(6))))
		{
			::Syntax_Node_ const *_Nonnull const initalizer_ = syntax_->children_->op_Element(i32(5));
			children_->add_(build_(initalizer_, name_table_, scope_));
		}

		return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
	}
	else if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, TrueLiteralExpression_)) || bit_arg(equal_op(syntax_->kind_, FalseLiteralExpression_)))))
	{
		return (new ::Semantic_Node_())->construct_of_type(scope_->lookup_special_(p_string("bool"))->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, StringLiteralExpression_)))
	{
		return (new ::Semantic_Node_())->construct_of_type(scope_->lookup_special_(p_string("string"))->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, CodePointLiteralExpression_)))
	{
		return (new ::Semantic_Node_())->construct_of_type(scope_->lookup_special_(p_string("code_point"))->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, NumericLiteralExpression_)))
	{
		return (new ::Semantic_Node_())->construct_of_type(scope_->lookup_special_(p_string("int"))->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->children_->op_magnitude(), i32(0))))
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
	assert_(equal_op(parameters_syntax_->kind_, ParameterList_), p_string("parameters_syntax.kind=").op_add(parameters_syntax_->kind_));
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const parameters_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	for (::Syntax_Node_ const *_Nonnull const parameter_ : *(parameters_syntax_->parameters_()))
	{
		::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
		if (cond(equal_op(parameter_->kind_, Parameter_)))
		{
			::Syntax_Node_ const *_Nullable const var_syntax_ = parameter_->first_child_(VarKeyword_);
			if (cond(not_equal_op(var_syntax_, none)))
			{
				children_->add_((new ::Semantic_Node_())->construct_token(var_syntax_));
			}

			::Syntax_Node_ const *_Nonnull const identifier_ = parameter_->first_child_(Identifier_);
			children_->add_((new ::Semantic_Node_())->construct_token(identifier_));
			::Syntax_Node_ const *_Nonnull const type_syntax_ = parameter_->children_->op_Element(parameter_->children_->op_magnitude()->op_subtract(i32(1)));
			::Semantic_Node_ const *_Nonnull const type_node_ = build_type_name_(type_syntax_, name_table_, scope_);
			assert_(not_equal_op(type_node_->referenced_type_, none), parameter_->get_text_());
			children_->add_(type_node_);
			::Name_Subtable_ *_Nonnull const parameter_scope_ = scope_->lookup_(identifier_->get_text_());
			assert_(not_equal_op(parameter_scope_, none), identifier_->get_text_());
			parameter_scope_->bind_type_(type_node_->referenced_type_);
			parameters_->add_((new ::Semantic_Node_())->construct_of_type(type_node_->referenced_type_, parameter_, children_));
		}
		else if (cond(equal_op(parameter_->kind_, SelfParameter_)))
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
	if (cond(equal_op(syntax_->kind_, PredefinedType_)))
	{
		p_string const primitive_name_ = syntax_->children_->op_Element(i32(0))->get_text_();
		::Name_Subtable_ const *_Nullable const primitive_entry_ = scope_->lookup_special_(primitive_name_);
		assert_(not_equal_op(primitive_entry_, none), p_string("No entry for primitive `").op_add(primitive_name_)->op_add(p_string("`")));
		return (new ::Semantic_Node_())->construct_referencing_type(primitive_entry_->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, IdentifierName_)))
	{
		if (cond(syntax_->is_missing_))
		{
			return (new ::Semantic_Node_())->construct_token(syntax_);
		}

		p_string const name_ = syntax_->get_text_();
		::Name_Subtable_ const *_Nullable const entry_ = scope_->lookup_(name_);
		if (cond(equal_op(entry_, none)))
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
	else if (cond(equal_op(syntax_->kind_, QualifiedName_)))
	{
		::Syntax_Node_ const *_Nonnull const qualifier_syntax_ = syntax_->children_->op_Element(i32(0));
		::Semantic_Node_ *_Nonnull const qualifier_ = build_type_name_(qualifier_syntax_, name_table_, scope_);
		children_->add_(qualifier_);
		::Syntax_Node_ const *_Nonnull const qualified_syntax_ = syntax_->children_->op_Element(i32(2));
		if (cond(equal_op(qualified_syntax_->kind_, IdentifierName_)))
		{
			::Syntax_Node_ const *_Nonnull const name_syntax_ = qualified_syntax_;
			if (cond(equal_op(qualifier_->referenced_type_, none)))
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
				assert_(not_equal_op(containing_scope_, none), containing_type_->name_->full_());
				::Name_Subtable_ const *_Nonnull const referenced_scope_ = containing_scope_->find_(name_syntax_->get_text_());
				if (cond(equal_op(referenced_scope_, none)))
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
		else if (cond(equal_op(qualified_syntax_->kind_, GenericName_)))
		{
			::Syntax_Node_ const *_Nonnull const name_syntax_ = qualified_syntax_->first_child_(IdentifierName_);
			::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const generic_name_children_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
			if (cond(equal_op(qualifier_->referenced_type_, none)))
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
				assert_(not_equal_op(containing_scope_, none), containing_type_->name_->full_());
				::Name_Subtable_ const *_Nonnull const referenced_scope_ = containing_scope_->find_(name_syntax_->get_text_());
				if (cond(equal_op(referenced_scope_, none)))
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
	else if (cond(equal_op(syntax_->kind_, MutableType_)))
	{
		::Semantic_Node_ *_Nonnull const inner_type_ = build_type_name_(syntax_->children_->op_Element(i32(1)), name_table_, scope_);
		children_->add_(inner_type_);
		if (cond(equal_op(inner_type_->referenced_type_, none)))
		{
			add_could_not_determine_type_error_(inner_type_);
			return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
		}

		::Type_ const *_Nonnull const type_ = inner_type_->referenced_type_->make_mutable_();
		return (new ::Semantic_Node_())->construct_referencing_type(type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, ImmutableType_)))
	{
		::Semantic_Node_ *_Nonnull const inner_type_ = build_type_name_(syntax_->children_->op_Element(i32(0)), name_table_, scope_);
		children_->add_(inner_type_);
		if (cond(equal_op(inner_type_->referenced_type_, none)))
		{
			add_could_not_determine_type_error_(inner_type_);
			return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
		}

		::Type_ const *_Nonnull const type_ = inner_type_->referenced_type_->make_immutable_();
		return (new ::Semantic_Node_())->construct_referencing_type(type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, OptionalType_)))
	{
		::Semantic_Node_ *_Nonnull const inner_type_ = build_type_name_(syntax_->children_->op_Element(i32(0)), name_table_, scope_);
		children_->add_(inner_type_);
		if (cond(equal_op(inner_type_->referenced_type_, none)))
		{
			add_could_not_determine_type_error_(inner_type_);
			return (new ::Semantic_Node_())->construct_concrete(syntax_, children_);
		}

		::Name_Subtable_ const *_Nullable const optional_type_scope_ = name_table_->get_(optional_type_name_);
		assert_(not_equal_op(optional_type_scope_, none), p_string(""));
		::Type_ const *_Nonnull const optional_type_ = optional_type_scope_->type_;
		::System_::Collections_::List_<::Type_ const *_Nonnull> *_Nonnull const type_arguments_ = (new ::System_::Collections_::List_<::Type_ const *_Nonnull>())->construct();
		type_arguments_->add_(inner_type_->referenced_type_);
		::Type_ const *_Nonnull const type_ = (new ::Type_())->construct_generic(optional_type_, type_arguments_);
		return (new ::Semantic_Node_())->construct_referencing_type(type_, syntax_, children_);
	}
	else
	{
		i32 const place_ = syntax_->start_;
		NOT_IMPLEMENTED_(p_string("syntax.kind=").op_add(syntax_->kind_)->op_add(p_string(" at "))->op_add(place_));
	}
}

auto ::Semantic_Tree_Builder_::build_type_arguments_(::Syntax_Node_ const *_Nonnull const syntax_, ::Name_Table_ const *_Nonnull const name_table_, ::Name_Subtable_ const *_Nonnull const scope_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const children_) const -> ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Type_ const *_Nonnull> *_Nonnull const type_parameters_ = (new ::System_::Collections_::List_<::Type_ const *_Nonnull>())->construct();
	if (cond(equal_op(syntax_->kind_, IdentifierName_)))
	{
		return type_parameters_;
	}

	assert_(equal_op(syntax_->kind_, GenericName_), p_string("syntax.kind==").op_add(syntax_->kind_));
	bit in_type_arguments_ = bit_false;
	for (::Syntax_Node_ const *_Nonnull const type_argument_ : *(syntax_->children_))
	{
		if (cond(in_type_arguments_))
		{
			if (cond(not_equal_op(type_argument_->kind_, GreaterThan_)))
			{
				::Semantic_Node_ const *_Nonnull const type_node_ = build_type_name_(type_argument_, name_table_, scope_);
				type_parameters_->add_(type_node_->referenced_type_);
				children_->add_(type_node_);
			}
		}
		else if (cond(equal_op(type_argument_->kind_, LessThan_)))
		{
			in_type_arguments_ = bit_true;
		}
	}

	return type_parameters_;
}

auto ::Semantic_Tree_Builder_::build_constructor_name_(::Syntax_Node_ const *_Nonnull const syntax_, ::Name_Table_ const *_Nonnull const name_table_, ::Name_Subtable_ const *_Nonnull const scope_) const -> ::Semantic_Node_ const *_Nonnull
{
	auto self = this;
	if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, QualifiedName_)) && bit_arg(equal_op(syntax_->children_->op_Element(i32(2))->kind_, IdentifierName_)))))
	{
		::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
		::Semantic_Node_ const *_Nonnull const type_node_ = build_type_name_(syntax_->children_->op_Element(i32(0)), name_table_, scope_);
		children_->add_(type_node_);
		::Syntax_Node_ const *_Nonnull const qualifier_ = syntax_->children_->op_Element(i32(0));
		::Syntax_Node_ const *_Nonnull const name_ = syntax_->children_->op_Element(i32(2));
		p_string const constructor_name_ = p_string("new_").op_add(name_->get_text_());
		::Type_ const *_Nonnull const referenced_type_ = type_node_->referenced_type_;
		assert_(not_equal_op(referenced_type_, none), p_string("no referenced type for `").op_add(type_node_->get_text_())->op_add(p_string("`")));
		::Name_Subtable_ const *_Nullable const constructor_scope_ = name_table_->get_(referenced_type_->name_)->lookup_special_(constructor_name_);
		if (cond(not_equal_op(constructor_scope_, none)))
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
	self->compilationUnit_ = none;
	return self;
}

auto ::Compilation_Unit_Parser_::Parse_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	if (cond(equal_op(compilationUnit_, none)))
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

auto ::Compilation_Unit_Parser_::ExpectToken_(i32 const tokenType_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	if (cond(equal_op(token_, none)))
	{
		return new_syntax_node_missing_(tokenType_, tokenStream_->source_, tokenStream_->source_->ByteLength_());
	}

	if (cond(bit_op(bit_arg(equal_op(token_, none)) || bit_arg(not_equal_op(token_->kind_, tokenType_)))))
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
	if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(token_->kind_, CodePoint_)) || bit_arg(equal_op(token_->kind_, String_)))) || bit_arg(equal_op(token_->kind_, Int_)))) || bit_arg(equal_op(token_->kind_, Bool_)))) || bit_arg(equal_op(token_->kind_, Void_)))) || bit_arg(equal_op(token_->kind_, UnsignedInt_)))))
	{
		return (new ::Syntax_Node_())->construct(PredefinedType_, AcceptToken_());
	}
	else
	{
		::Syntax_Node_ const *_Nonnull type_ = (new ::Syntax_Node_())->construct(IdentifierName_, ExpectToken_(Identifier_));
		while (cond(equal_op(token_->kind_, Dot_)))
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
			children_->Add_(type_);
			children_->Add_(ExpectToken_(Dot_));
			::Syntax_Node_ const *_Nonnull const identifier_ = ExpectToken_(Identifier_);
			if (cond(equal_op(token_->kind_, LessThan_)))
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
	if (cond(equal_op(token_->kind_, MutableKeyword_)))
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
	while (cond(equal_op(token_->kind_, Question_)))
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
	if (cond(equal_op(token_->kind_, NewKeyword_)))
	{
		children_->Add_(ExpectToken_(NewKeyword_));
		children_->Add_(ParseTypeName_());
		children_->Add_(ParseCallArguments_());
		return (new ::Syntax_Node_())->construct(NewExpression_, children_);
	}

	if (cond(equal_op(token_->kind_, NotOperator_)))
	{
		children_->Add_(ExpectToken_(NotOperator_));
		children_->Add_(ParseExpression_(i32(8)));
		return (new ::Syntax_Node_())->construct(NotExpression_, children_);
	}

	if (cond(equal_op(token_->kind_, LeftParen_)))
	{
		children_->Add_(ExpectToken_(LeftParen_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(RightParen_));
		return (new ::Syntax_Node_())->construct(ParenthesizedExpression_, children_);
	}

	if (cond(equal_op(token_->kind_, Pipe_)))
	{
		children_->Add_(ExpectToken_(Pipe_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(Pipe_));
		return (new ::Syntax_Node_())->construct(MagnitudeExpression_, children_);
	}

	if (cond(equal_op(token_->kind_, Minus_)))
	{
		children_->Add_(ExpectToken_(Minus_));
		children_->Add_(ParseExpression_(i32(8)));
		return (new ::Syntax_Node_())->construct(NegateExpression_, children_);
	}

	if (cond(equal_op(token_->kind_, NoneKeyword_)))
	{
		children_->Add_(ExpectToken_(NoneKeyword_));
		return (new ::Syntax_Node_())->construct(NoneLiteralExpression_, children_);
	}

	if (cond(equal_op(token_->kind_, SelfKeyword_)))
	{
		children_->Add_(ExpectToken_(SelfKeyword_));
		return (new ::Syntax_Node_())->construct(SelfExpression_, children_);
	}

	if (cond(equal_op(token_->kind_, TrueKeyword_)))
	{
		children_->Add_(ExpectToken_(TrueKeyword_));
		return (new ::Syntax_Node_())->construct(TrueLiteralExpression_, children_);
	}

	if (cond(equal_op(token_->kind_, FalseKeyword_)))
	{
		children_->Add_(ExpectToken_(FalseKeyword_));
		return (new ::Syntax_Node_())->construct(FalseLiteralExpression_, children_);
	}

	if (cond(equal_op(token_->kind_, Number_)))
	{
		children_->Add_(ExpectToken_(Number_));
		return (new ::Syntax_Node_())->construct(NumericLiteralExpression_, children_);
	}

	if (cond(equal_op(token_->kind_, Identifier_)))
	{
		children_->Add_(ExpectToken_(Identifier_));
		return (new ::Syntax_Node_())->construct(IdentifierName_, children_);
	}

	if (cond(equal_op(token_->kind_, StringLiteral_)))
	{
		children_->Add_(ExpectToken_(StringLiteral_));
		return (new ::Syntax_Node_())->construct(StringLiteralExpression_, children_);
	}

	if (cond(equal_op(token_->kind_, CodePointLiteral_)))
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
	if (cond(not_equal_op(token_->kind_, RightParen_)))
	{
		for (;;)
		{
			children_->Add_(ParseExpression_());
			if (cond(equal_op(token_->kind_, Comma_)))
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

auto ::Compilation_Unit_Parser_::ParseExpression_(i32 const minPrecedence_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::Syntax_Node_ const *_Nonnull expression_ = ParseAtom_();
	for (;;)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
		children_->Add_(expression_);
		i32 precedence_;
		bit leftAssociative_;
		bit suffixOperator_ = bit_false;
		i32 expressionType_;
		if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(token_->kind_, Equals_)) || bit_arg(equal_op(token_->kind_, PlusEquals_)))) || bit_arg(equal_op(token_->kind_, MinusEquals_)))) && bit_arg(minPrecedence_.op_less_than_or_equal(i32(1))))))
		{
			precedence_ = i32(1);
			leftAssociative_ = bit_false;
			children_->Add_(AcceptToken_());
			expressionType_ = AssignmentExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(token_->kind_, OrKeyword_)) && bit_arg(minPrecedence_.op_less_than_or_equal(i32(2))))))
		{
			precedence_ = i32(2);
			leftAssociative_ = bit_true;
			children_->Add_(ExpectToken_(OrKeyword_));
			expressionType_ = OrExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(token_->kind_, AndKeyword_)) && bit_arg(minPrecedence_.op_less_than_or_equal(i32(3))))))
		{
			precedence_ = i32(3);
			leftAssociative_ = bit_true;
			children_->Add_(ExpectToken_(AndKeyword_));
			expressionType_ = AndExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(token_->kind_, EqualsEquals_)) && bit_arg(minPrecedence_.op_less_than_or_equal(i32(4))))))
		{
			precedence_ = i32(4);
			leftAssociative_ = bit_true;
			children_->Add_(ExpectToken_(EqualsEquals_));
			expressionType_ = EqualExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(token_->kind_, EqualsSlashEquals_)) && bit_arg(minPrecedence_.op_less_than_or_equal(i32(4))))))
		{
			precedence_ = i32(4);
			leftAssociative_ = bit_true;
			children_->Add_(ExpectToken_(EqualsSlashEquals_));
			expressionType_ = NotEqualExpression_;
		}
		else if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(token_->kind_, LessThan_)) || bit_arg(equal_op(token_->kind_, LessThanEquals_)))) || bit_arg(equal_op(token_->kind_, GreaterThan_)))) || bit_arg(equal_op(token_->kind_, GreaterThanEquals_)))) && bit_arg(minPrecedence_.op_less_than_or_equal(i32(5))))))
		{
			precedence_ = i32(5);
			leftAssociative_ = bit_true;
			children_->Add_(AcceptToken_());
			expressionType_ = ComparisonExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(token_->kind_, Plus_)) && bit_arg(minPrecedence_.op_less_than_or_equal(i32(6))))))
		{
			precedence_ = i32(6);
			leftAssociative_ = bit_true;
			children_->Add_(ExpectToken_(Plus_));
			expressionType_ = AddExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(token_->kind_, Minus_)) && bit_arg(minPrecedence_.op_less_than_or_equal(i32(6))))))
		{
			precedence_ = i32(6);
			leftAssociative_ = bit_true;
			children_->Add_(ExpectToken_(Minus_));
			expressionType_ = SubtractExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(token_->kind_, Asterisk_)) && bit_arg(minPrecedence_.op_less_than_or_equal(i32(7))))))
		{
			precedence_ = i32(7);
			leftAssociative_ = bit_true;
			children_->Add_(ExpectToken_(Asterisk_));
			expressionType_ = MultiplyExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(token_->kind_, Slash_)) && bit_arg(minPrecedence_.op_less_than_or_equal(i32(7))))))
		{
			precedence_ = i32(7);
			leftAssociative_ = bit_true;
			children_->Add_(ExpectToken_(Slash_));
			expressionType_ = DivideExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(token_->kind_, Percent_)) && bit_arg(minPrecedence_.op_less_than_or_equal(i32(7))))))
		{
			precedence_ = i32(7);
			leftAssociative_ = bit_true;
			children_->Add_(ExpectToken_(Percent_));
			expressionType_ = RemainderExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(token_->kind_, LeftParen_)) && bit_arg(minPrecedence_.op_less_than_or_equal(i32(9))))))
		{
			precedence_ = i32(9);
			leftAssociative_ = bit_true;
			suffixOperator_ = bit_true;
			children_->Add_(ParseCallArguments_());
			expressionType_ = InvocationExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(token_->kind_, Dot_)) && bit_arg(minPrecedence_.op_less_than_or_equal(i32(9))))))
		{
			precedence_ = i32(9);
			leftAssociative_ = bit_true;
			children_->Add_(ExpectToken_(Dot_));
			expressionType_ = MemberAccessExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(token_->kind_, LeftBracket_)) && bit_arg(minPrecedence_.op_less_than_or_equal(i32(9))))))
		{
			precedence_ = i32(9);
			leftAssociative_ = bit_true;
			suffixOperator_ = bit_true;
			children_->Add_(ExpectToken_(LeftBracket_));
			children_->Add_(ParseExpression_());
			children_->Add_(ExpectToken_(RightBracket_));
			expressionType_ = ElementAccessExpression_;
		}
		else
		{
			return expression_;
		}

		if (cond(bit_not(suffixOperator_)))
		{
			if (cond(leftAssociative_))
			{
				precedence_.op_add_assign(i32(1));
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
	return ParseExpression_(i32(1));
}

auto ::Compilation_Unit_Parser_::ParseStatement_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	if (cond(equal_op(token_->kind_, ReturnKeyword_)))
	{
		children_->Add_(ExpectToken_(ReturnKeyword_));
		if (cond(not_equal_op(token_->kind_, Semicolon_)))
		{
			children_->Add_(ParseExpression_());
		}

		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(ReturnStatement_, children_);
	}

	if (cond(equal_op(token_->kind_, LoopKeyword_)))
	{
		children_->Add_(ExpectToken_(LoopKeyword_));
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_())->construct(LoopStatement_, children_);
	}

	if (cond(equal_op(token_->kind_, WhileKeyword_)))
	{
		children_->Add_(ExpectToken_(WhileKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_())->construct(WhileStatement_, children_);
	}

	if (cond(equal_op(token_->kind_, ForKeyword_)))
	{
		children_->Add_(ExpectToken_(ForKeyword_));
		children_->Add_(ParseVariableDeclaration_(bit_false));
		children_->Add_(ExpectToken_(InKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_())->construct(ForStatement_, children_);
	}

	if (cond(equal_op(token_->kind_, DoKeyword_)))
	{
		children_->Add_(ExpectToken_(DoKeyword_));
		children_->Add_(ParseBlock_());
		children_->Add_(ExpectToken_(WhileKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(DoWhileStatement_, children_);
	}

	if (cond(equal_op(token_->kind_, IfKeyword_)))
	{
		return ParseIfStatement_();
	}

	if (cond(equal_op(token_->kind_, BreakKeyword_)))
	{
		children_->Add_(ExpectToken_(BreakKeyword_));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(BreakStatement_, children_);
	}

	if (cond(equal_op(token_->kind_, ContinueKeyword_)))
	{
		children_->Add_(ExpectToken_(ContinueKeyword_));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(ContinueStatement_, children_);
	}

	if (cond(bit_op(bit_arg(equal_op(token_->kind_, VarKeyword_)) || bit_arg(equal_op(token_->kind_, LetKeyword_)))))
	{
		children_->Add_(ParseVariableDeclaration_(bit_true));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(LocalDeclarationStatement_, children_);
	}

	if (cond(equal_op(token_->kind_, LeftBrace_)))
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
	if (cond(equal_op(token_->kind_, ElseKeyword_)))
	{
		::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const elseChildren_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
		elseChildren_->Add_(ExpectToken_(ElseKeyword_));
		if (cond(equal_op(token_->kind_, IfKeyword_)))
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

auto ::Compilation_Unit_Parser_::ParseVariableDeclaration_(bit const allowInitializer_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	if (cond(bit_op(bit_arg(equal_op(token_->kind_, LetKeyword_)) && bit_arg(not_equal_op(token_->kind_, VarKeyword_)))))
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
	if (cond(bit_op(bit_arg(allowInitializer_) && bit_arg(equal_op(token_->kind_, Equals_)))))
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
	while (cond(bit_op(bit_arg(not_equal_op(token_->kind_, RightBrace_)) && bit_arg(not_equal_op(token_->kind_, EndOfFileToken_)))))
	{
		::Syntax_Node_ const *_Nonnull const startToken_ = token_;
		children_->Add_(ParseStatement_());
		if (cond(equal_op(token_, startToken_)))
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const skipped_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
			while (cond(bit_op(bit_arg(bit_op(bit_arg(not_equal_op(token_->kind_, LeftBrace_)) && bit_arg(not_equal_op(token_->kind_, RightBrace_)))) && bit_arg(not_equal_op(token_->kind_, EndOfFileToken_)))))
			{
				i32 const currentTokenType_ = token_->kind_;
				skipped_->Add_(AcceptToken_());
				if (cond(equal_op(currentTokenType_, Semicolon_)))
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
	if (cond(not_equal_op(token_->kind_, RightParen_)))
	{
		for (;;)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const parameterChildren_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
			if (cond(bit_op(bit_arg(equal_op(token_->kind_, MutableKeyword_)) || bit_arg(equal_op(token_->kind_, SelfKeyword_)))))
			{
				if (cond(equal_op(token_->kind_, MutableKeyword_)))
				{
					parameterChildren_->Add_(ExpectToken_(MutableKeyword_));
				}

				parameterChildren_->Add_(ExpectToken_(SelfKeyword_));
				children_->Add_((new ::Syntax_Node_())->construct(SelfParameter_, parameterChildren_));
			}
			else
			{
				bit const mutableBinding_ = equal_op(token_->kind_, VarKeyword_);
				if (cond(equal_op(token_->kind_, VarKeyword_)))
				{
					parameterChildren_->Add_(ExpectToken_(VarKeyword_));
				}

				parameterChildren_->Add_(ExpectToken_(Identifier_));
				parameterChildren_->Add_(ExpectToken_(Colon_));
				::Syntax_Node_ const *_Nonnull const type_ = ParseType_();
				parameterChildren_->Add_(type_);
				children_->Add_((new ::Syntax_Node_())->construct(Parameter_, parameterChildren_));
			}

			if (cond(equal_op(token_->kind_, Comma_)))
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
	if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(token_->kind_, PublicKeyword_)) || bit_arg(equal_op(token_->kind_, ProtectedKeyword_)))) || bit_arg(equal_op(token_->kind_, InternalKeyword_)))) || bit_arg(equal_op(token_->kind_, PrivateKeyword_)))))
	{
		children_->Add_(AcceptToken_());
	}
	else
	{
		children_->Add_(ExpectToken_(PublicKeyword_));
	}

	if (cond(equal_op(token_->kind_, NewKeyword_)))
	{
		children_->Add_(ExpectToken_(NewKeyword_));
		if (cond(equal_op(token_->kind_, Identifier_)))
		{
			children_->Add_(ExpectToken_(Identifier_));
		}

		children_->Add_(ParseParameterList_());
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_())->construct(ConstructorDeclaration_, children_);
	}

	if (cond(bit_op(bit_arg(equal_op(token_->kind_, VarKeyword_)) || bit_arg(equal_op(token_->kind_, LetKeyword_)))))
	{
		children_->Add_(ParseVariableDeclaration_(bit_false));
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
	if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(token_->kind_, PublicKeyword_)) || bit_arg(equal_op(token_->kind_, ProtectedKeyword_)))) || bit_arg(equal_op(token_->kind_, InternalKeyword_)))) || bit_arg(equal_op(token_->kind_, PrivateKeyword_)))))
	{
		children_->Add_(AcceptToken_());
	}
	else
	{
		children_->Add_(ExpectToken_(PublicKeyword_));
	}

	if (cond(bit_op(bit_arg(equal_op(token_->kind_, VarKeyword_)) || bit_arg(equal_op(token_->kind_, LetKeyword_)))))
	{
		children_->Add_(ParseVariableDeclaration_(bit_true));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(GlobalDeclaration_, children_);
	}

	if (cond(equal_op(token_->kind_, ClassKeyword_)))
	{
		children_->Add_(ExpectToken_(ClassKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (cond(bit_op(bit_arg(not_equal_op(token_->kind_, RightBrace_)) && bit_arg(not_equal_op(token_->kind_, EndOfFileToken_)))))
		{
			::Syntax_Node_ const *_Nonnull const startToken_ = token_;
			children_->Add_(ParseMemberDeclaration_());
			if (cond(equal_op(token_, startToken_)))
			{
				children_->Add_(new_Syntax_Node_Skipped_(AcceptToken_()));
			}
		}

		children_->Add_(ExpectToken_(RightBrace_));
		return (new ::Syntax_Node_())->construct(ClassDeclaration_, children_);
	}

	if (cond(equal_op(token_->kind_, StructKeyword_)))
	{
		children_->Add_(ExpectToken_(StructKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (cond(bit_op(bit_arg(not_equal_op(token_->kind_, RightBrace_)) && bit_arg(not_equal_op(token_->kind_, EndOfFileToken_)))))
		{
			::Syntax_Node_ const *_Nonnull const startToken_ = token_;
			children_->Add_(ParseMemberDeclaration_());
			if (cond(equal_op(token_, startToken_)))
			{
				children_->Add_(new_Syntax_Node_Skipped_(AcceptToken_()));
			}
		}

		children_->Add_(ExpectToken_(RightBrace_));
		return (new ::Syntax_Node_())->construct(StructDeclaration_, children_);
	}

	if (cond(equal_op(token_->kind_, EnumKeyword_)))
	{
		children_->Add_(ExpectToken_(EnumKeyword_));
		children_->Add_(ExpectToken_(StructKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (cond(bit_op(bit_arg(not_equal_op(token_->kind_, RightBrace_)) && bit_arg(not_equal_op(token_->kind_, EndOfFileToken_)))))
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const memberChildren_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
			memberChildren_->Add_(ExpectToken_(Identifier_));
			if (cond(equal_op(token_->kind_, Equals_)))
			{
				memberChildren_->Add_(ExpectToken_(Equals_));
				memberChildren_->Add_(ExpectToken_(Number_));
			}

			if (cond(not_equal_op(token_->kind_, RightBrace_)))
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
	while (cond(bit_op(bit_arg(not_equal_op(token_, none)) && bit_arg(not_equal_op(token_->kind_, EndOfFileToken_)))))
	{
		::Syntax_Node_ const *_Nonnull const startToken_ = token_;
		children_->Add_(ParseDeclaration_());
		if (cond(equal_op(token_, startToken_)))
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

auto ::Syntax_Node_::construct(i32 const type_, ::Source_Text_ const *_Nonnull const source_, u32 const start_, u32 const length_) -> ::Syntax_Node_*
{
	::Syntax_Node_* self = this;
	kind_ = type_;
	is_missing_ = bit_false;
	self->source_ = source_;
	self->start_ = start_;
	byte_length_ = length_;
	self->children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
	node_diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	return self;
}

auto ::Syntax_Node_::construct(i32 const type_, bit const isMissing_, ::Source_Text_ const *_Nonnull const source_, u32 const start_, u32 const length_) -> ::Syntax_Node_*
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

auto ::Syntax_Node_::construct(i32 const type_, ::Syntax_Node_ const *_Nonnull const child_) -> ::Syntax_Node_*
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

auto ::Syntax_Node_::construct(i32 const type_, ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull const children_) -> ::Syntax_Node_*
{
	::Syntax_Node_* self = this;
	kind_ = type_;
	is_missing_ = bit_false;
	source_ = children_->op_Element(i32(0))->source_;
	start_ = children_->op_Element(i32(0))->start_;
	::Syntax_Node_ const *_Nonnull const lastChild_ = children_->op_Element(children_->op_magnitude()->op_subtract(i32(1)));
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

auto ::Syntax_Node_::first_child_(i32 const type_) const -> ::Syntax_Node_ const *_Nullable
{
	auto self = this;
	for (::Syntax_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (cond(equal_op(child_->kind_, type_)))
		{
			return child_;
		}
	}

	return none;
}

auto ::Syntax_Node_::has_child_(i32 const type_) const -> bit
{
	auto self = this;
	for (::Syntax_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (cond(equal_op(child_->kind_, type_)))
		{
			return bit_true;
		}
	}

	return bit_false;
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
		if (cond(bit_op(bit_arg(bit_op(bit_arg(equal_op(child_->kind_, ConstructorDeclaration_)) || bit_arg(equal_op(child_->kind_, FieldDeclaration_)))) || bit_arg(equal_op(child_->kind_, MethodDeclaration_)))))
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
		if (cond(bit_op(bit_arg(equal_op(child_->kind_, Parameter_)) || bit_arg(equal_op(child_->kind_, SelfParameter_)))))
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
		if (cond(bit_op(bit_arg(not_equal_op(child_->kind_, LeftBrace_)) && bit_arg(not_equal_op(child_->kind_, RightBrace_)))))
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
		if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(child_->kind_, PublicKeyword_)) || bit_arg(equal_op(child_->kind_, ProtectedKeyword_)))) || bit_arg(equal_op(child_->kind_, InternalKeyword_)))) || bit_arg(equal_op(child_->kind_, PrivateKeyword_)))))
		{
			return child_;
		}
	}

	return none;
}

auto new_syntax_node_missing_(i32 const type_, ::Source_Text_ const *_Nonnull const source_, u32 const start_) -> ::Syntax_Node_ const *_Nonnull
{
	::Syntax_Node_ *_Nonnull const node_ = (new ::Syntax_Node_())->construct(type_, bit_true, source_, start_, i32(0));
	::Text_Span_ const *_Nonnull const span_ = (new ::Text_Span_())->construct(start_, i32(0));
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

auto ::Token_Stream_::construct(::Source_Text_ const *_Nonnull const source_) -> ::Token_Stream_*
{
	::Token_Stream_* self = this;
	self->source_ = source_;
	position_ = i32(0);
	diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	endOfFile_ = bit_false;
	return self;
}

auto ::Token_Stream_::GetNextToken_() -> ::Syntax_Node_ const *_Nullable
{
	auto self = this;
	if (cond(position_.op_greater_than_or_equal(source_->ByteLength_())))
	{
		return EndOfFile_();
	}

	u32 end_ = i32(1).op_negate();
	while (cond(position_.op_less_than(source_->ByteLength_())))
	{
		p_code_point const curChar_ = source_->Text_->op_Element(position_);
		if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(curChar_, p_code_point(' '))) || bit_arg(equal_op(curChar_, p_code_point('\t'))))) || bit_arg(equal_op(curChar_, p_code_point('\n'))))) || bit_arg(equal_op(curChar_, p_code_point('\r'))))))
		{
			position_.op_add_assign(i32(1));
			continue;
		}
		else if (cond(equal_op(curChar_, p_code_point('{'))))
		{
			return NewOperator_(LeftBrace_);
		}
		else if (cond(equal_op(curChar_, p_code_point('}'))))
		{
			return NewOperator_(RightBrace_);
		}
		else if (cond(equal_op(curChar_, p_code_point('('))))
		{
			return NewOperator_(LeftParen_);
		}
		else if (cond(equal_op(curChar_, p_code_point(')'))))
		{
			return NewOperator_(RightParen_);
		}
		else if (cond(equal_op(curChar_, p_code_point(';'))))
		{
			return NewOperator_(Semicolon_);
		}
		else if (cond(equal_op(curChar_, p_code_point(','))))
		{
			return NewOperator_(Comma_);
		}
		else if (cond(equal_op(curChar_, p_code_point('.'))))
		{
			return NewOperator_(Dot_);
		}
		else if (cond(equal_op(curChar_, p_code_point(':'))))
		{
			return NewOperator_(Colon_);
		}
		else if (cond(equal_op(curChar_, p_code_point('['))))
		{
			return NewOperator_(LeftBracket_);
		}
		else if (cond(equal_op(curChar_, p_code_point(']'))))
		{
			return NewOperator_(RightBracket_);
		}
		else if (cond(equal_op(curChar_, p_code_point('?'))))
		{
			return NewOperator_(Question_);
		}
		else if (cond(equal_op(curChar_, p_code_point('|'))))
		{
			return NewOperator_(Pipe_);
		}
		else if (cond(equal_op(curChar_, p_code_point('*'))))
		{
			return NewOperator_(Asterisk_);
		}
		else if (cond(equal_op(curChar_, p_code_point('='))))
		{
			if (cond(bit_op(bit_arg(position_.op_add(i32(1))->op_less_than(source_->ByteLength_())) && bit_arg(equal_op(source_->Text_->op_Element(position_.op_add(i32(1))), p_code_point('='))))))
			{
				return NewOperator_(EqualsEquals_, i32(2));
			}

			if (cond(bit_op(bit_arg(bit_op(bit_arg(position_.op_add(i32(2))->op_less_than(source_->ByteLength_())) && bit_arg(equal_op(source_->Text_->op_Element(position_.op_add(i32(1))), p_code_point('/'))))) && bit_arg(equal_op(source_->Text_->op_Element(position_.op_add(i32(2))), p_code_point('='))))))
			{
				return NewOperator_(EqualsSlashEquals_, i32(3));
			}

			return NewOperator_(Equals_);
		}
		else if (cond(equal_op(curChar_, p_code_point('+'))))
		{
			if (cond(bit_op(bit_arg(position_.op_add(i32(1))->op_less_than(source_->ByteLength_())) && bit_arg(equal_op(source_->Text_->op_Element(position_.op_add(i32(1))), p_code_point('='))))))
			{
				return NewOperator_(PlusEquals_, i32(2));
			}

			return NewOperator_(Plus_);
		}
		else if (cond(equal_op(curChar_, p_code_point('-'))))
		{
			if (cond(bit_op(bit_arg(position_.op_add(i32(1))->op_less_than(source_->ByteLength_())) && bit_arg(equal_op(source_->Text_->op_Element(position_.op_add(i32(1))), p_code_point('>'))))))
			{
				return NewOperator_(Arrow_, i32(2));
			}

			if (cond(bit_op(bit_arg(position_.op_add(i32(1))->op_less_than(source_->ByteLength_())) && bit_arg(equal_op(source_->Text_->op_Element(position_.op_add(i32(1))), p_code_point('='))))))
			{
				return NewOperator_(MinusEquals_, i32(2));
			}

			return NewOperator_(Minus_);
		}
		else if (cond(equal_op(curChar_, p_code_point('/'))))
		{
			if (cond(bit_op(bit_arg(position_.op_add(i32(1))->op_less_than(source_->ByteLength_())) && bit_arg(equal_op(source_->Text_->op_Element(position_.op_add(i32(1))), p_code_point('/'))))))
			{
				while (cond(bit_op(bit_arg(bit_op(bit_arg(position_.op_less_than(source_->ByteLength_())) && bit_arg(not_equal_op(source_->Text_->op_Element(position_), p_code_point('\r'))))) && bit_arg(not_equal_op(source_->Text_->op_Element(position_), p_code_point('\n'))))))
				{
					position_.op_add_assign(i32(1));
				}

				continue;
			}

			if (cond(bit_op(bit_arg(position_.op_add(i32(1))->op_less_than(source_->ByteLength_())) && bit_arg(equal_op(source_->Text_->op_Element(position_.op_add(i32(1))), p_code_point('*'))))))
			{
				position_.op_add_assign(i32(2));
				bit lastCharStar_ = bit_false;
				while (cond(bit_op(bit_arg(position_.op_less_than(source_->ByteLength_())) && bit_arg(bit_not(bit_op(bit_arg(lastCharStar_) && bit_arg(equal_op(source_->Text_->op_Element(position_), p_code_point('/')))))))))
				{
					lastCharStar_ = equal_op(source_->Text_->op_Element(position_), p_code_point('*'));
					position_.op_add_assign(i32(1));
				}

				position_.op_add_assign(i32(1));
				continue;
			}

			return NewOperator_(Slash_);
		}
		else if (cond(equal_op(curChar_, p_code_point('%'))))
		{
			return NewOperator_(Percent_);
		}
		else if (cond(equal_op(curChar_, p_code_point('<'))))
		{
			if (cond(bit_op(bit_arg(position_.op_add(i32(1))->op_less_than(source_->ByteLength_())) && bit_arg(equal_op(source_->Text_->op_Element(position_.op_add(i32(1))), p_code_point('='))))))
			{
				return NewOperator_(LessThanEquals_, i32(2));
			}

			return NewOperator_(LessThan_);
		}
		else if (cond(equal_op(curChar_, p_code_point('>'))))
		{
			if (cond(bit_op(bit_arg(position_.op_add(i32(1))->op_less_than(source_->ByteLength_())) && bit_arg(equal_op(source_->Text_->op_Element(position_.op_add(i32(1))), p_code_point('='))))))
			{
				return NewOperator_(GreaterThanEquals_, i32(2));
			}

			return NewOperator_(GreaterThan_);
		}
		else if (cond(equal_op(curChar_, p_code_point('"'))))
		{
			end_ = position_.op_add(i32(1));
			bit escaped_ = bit_false;
			while (cond(bit_op(bit_arg(end_.op_less_than(source_->ByteLength_())) && bit_arg(bit_op(bit_arg(not_equal_op(source_->Text_->op_Element(end_), p_code_point('"'))) || bit_arg(escaped_))))))
			{
				escaped_ = bit_op(bit_arg(equal_op(source_->Text_->op_Element(end_), p_code_point('\\'))) && bit_arg(bit_not(escaped_)));
				end_.op_add_assign(i32(1));
			}

			end_.op_add_assign(i32(1));
			return NewToken_(StringLiteral_, end_);
		}
		else if (cond(equal_op(curChar_, p_code_point('\''))))
		{
			end_ = position_.op_add(i32(1));
			bit escaped_ = bit_false;
			while (cond(bit_op(bit_arg(end_.op_less_than(source_->ByteLength_())) && bit_arg(bit_op(bit_arg(not_equal_op(source_->Text_->op_Element(end_), p_code_point('\''))) || bit_arg(escaped_))))))
			{
				escaped_ = bit_op(bit_arg(equal_op(source_->Text_->op_Element(end_), p_code_point('\\'))) && bit_arg(bit_not(escaped_)));
				end_.op_add_assign(i32(1));
			}

			end_.op_add_assign(i32(1));
			return NewToken_(CodePointLiteral_, end_);
		}
		else
		{
			if (cond(IsIdentifierChar_(curChar_)))
			{
				end_ = position_.op_add(i32(1));
				while (cond(IsIdentifierChar_(source_->Text_->op_Element(end_))))
				{
					end_.op_add_assign(i32(1));
				}

				return NewIdentifierOrKeyword_(end_);
			}

			if (cond(IsNumberChar_(curChar_)))
			{
				end_ = position_.op_add(i32(1));
				while (cond(IsNumberChar_(source_->Text_->op_Element(end_))))
				{
					end_.op_add_assign(i32(1));
				}

				return NewToken_(Number_, end_);
			}

			::Text_Span_ const *_Nonnull diagnosticSpan_ = (new ::Text_Span_())->construct(position_, i32(1));
			diagnostics_->Add_((new ::Diagnostic_())->construct(CompilationError_, Lexing_, source_, diagnosticSpan_, p_string("Invalid character `").op_add(curChar_)->op_add(p_string("`"))));
			position_ = end_;
		}
	}

	return EndOfFile_();
}

auto ::Token_Stream_::EndOfFile_() -> ::Syntax_Node_ const *_Nullable
{
	auto self = this;
	if (cond(endOfFile_))
	{
		return none;
	}

	endOfFile_ = bit_true;
	return NewToken_(EndOfFileToken_, position_);
}

auto ::Token_Stream_::NewIdentifierOrKeyword_(u32 const end_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	u32 const length_ = end_.op_subtract(position_);
	p_string const value_ = source_->Text_->Substring_(position_, length_);
	i32 type_;
	if (cond(equal_op(value_, p_string("new"))))
	{
		type_ = NewKeyword_;
	}
	else if (cond(equal_op(value_, p_string("not"))))
	{
		type_ = NotOperator_;
	}
	else if (cond(equal_op(value_, p_string("null"))))
	{
		type_ = NullReservedWord_;
	}
	else if (cond(equal_op(value_, p_string("self"))))
	{
		type_ = SelfKeyword_;
	}
	else if (cond(equal_op(value_, p_string("true"))))
	{
		type_ = TrueKeyword_;
	}
	else if (cond(equal_op(value_, p_string("false"))))
	{
		type_ = FalseKeyword_;
	}
	else if (cond(equal_op(value_, p_string("mut"))))
	{
		type_ = MutableKeyword_;
	}
	else if (cond(equal_op(value_, p_string("code_point"))))
	{
		type_ = CodePoint_;
	}
	else if (cond(equal_op(value_, p_string("string"))))
	{
		type_ = String_;
	}
	else if (cond(equal_op(value_, p_string("int"))))
	{
		type_ = Int_;
	}
	else if (cond(equal_op(value_, p_string("bool"))))
	{
		type_ = Bool_;
	}
	else if (cond(equal_op(value_, p_string("void"))))
	{
		type_ = Void_;
	}
	else if (cond(equal_op(value_, p_string("uint"))))
	{
		type_ = UnsignedInt_;
	}
	else if (cond(equal_op(value_, p_string("var"))))
	{
		type_ = VarKeyword_;
	}
	else if (cond(equal_op(value_, p_string("and"))))
	{
		type_ = AndKeyword_;
	}
	else if (cond(equal_op(value_, p_string("or"))))
	{
		type_ = OrKeyword_;
	}
	else if (cond(equal_op(value_, p_string("return"))))
	{
		type_ = ReturnKeyword_;
	}
	else if (cond(equal_op(value_, p_string("loop"))))
	{
		type_ = LoopKeyword_;
	}
	else if (cond(equal_op(value_, p_string("while"))))
	{
		type_ = WhileKeyword_;
	}
	else if (cond(equal_op(value_, p_string("for"))))
	{
		type_ = ForKeyword_;
	}
	else if (cond(equal_op(value_, p_string("let"))))
	{
		type_ = LetKeyword_;
	}
	else if (cond(equal_op(value_, p_string("in"))))
	{
		type_ = InKeyword_;
	}
	else if (cond(equal_op(value_, p_string("do"))))
	{
		type_ = DoKeyword_;
	}
	else if (cond(equal_op(value_, p_string("if"))))
	{
		type_ = IfKeyword_;
	}
	else if (cond(equal_op(value_, p_string("else"))))
	{
		type_ = ElseKeyword_;
	}
	else if (cond(equal_op(value_, p_string("break"))))
	{
		type_ = BreakKeyword_;
	}
	else if (cond(equal_op(value_, p_string("continue"))))
	{
		type_ = ContinueKeyword_;
	}
	else if (cond(equal_op(value_, p_string("private"))))
	{
		type_ = PrivateKeyword_;
	}
	else if (cond(equal_op(value_, p_string("protected"))))
	{
		type_ = ProtectedKeyword_;
	}
	else if (cond(equal_op(value_, p_string("public"))))
	{
		type_ = PublicKeyword_;
	}
	else if (cond(equal_op(value_, p_string("internal"))))
	{
		type_ = InternalKeyword_;
	}
	else if (cond(equal_op(value_, p_string("class"))))
	{
		type_ = ClassKeyword_;
	}
	else if (cond(equal_op(value_, p_string("enum"))))
	{
		type_ = EnumKeyword_;
	}
	else if (cond(equal_op(value_, p_string("struct"))))
	{
		type_ = StructKeyword_;
	}
	else if (cond(equal_op(value_, p_string("none"))))
	{
		type_ = NoneKeyword_;
	}
	else
	{
		type_ = Identifier_;
	}

	return NewToken_(type_, end_);
}

auto ::Token_Stream_::NewOperator_(i32 const type_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	return NewToken_(type_, position_.op_add(i32(1)));
}

auto ::Token_Stream_::NewOperator_(i32 const type_, u32 const length_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	return NewToken_(type_, position_.op_add(length_));
}

auto ::Token_Stream_::NewToken_(i32 const type_, u32 const end_) -> ::Syntax_Node_ const *_Nonnull
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

auto ::Token_Stream_::IsIdentifierChar_(p_code_point const c_) -> bit
{
	return bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(c_.op_greater_than_or_equal(p_code_point('a'))) && bit_arg(c_.op_less_than_or_equal(p_code_point('z'))))) || bit_arg(bit_op(bit_arg(c_.op_greater_than_or_equal(p_code_point('A'))) && bit_arg(c_.op_less_than_or_equal(p_code_point('Z'))))))) || bit_arg(equal_op(c_, p_code_point('_'))));
}

auto ::Token_Stream_::IsNumberChar_(p_code_point const c_) -> bit
{
	return bit_op(bit_arg(c_.op_greater_than_or_equal(p_code_point('0'))) && bit_arg(c_.op_less_than_or_equal(p_code_point('9'))));
}

auto ::Diagnostic_::construct(i32 const level_, i32 const phase_, ::Source_Text_ const *_Nonnull const source_, ::Text_Span_ const *_Nonnull const span_, p_string const message_) -> ::Diagnostic_*
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
	main_function_accepts_console_ = bit_false;
	main_function_accepts_args_ = bit_false;
	emit_preamble_();
	for (::Compilation_Unit_ const *_Nonnull const compilation_unit_ : *(package_->compilation_units_))
	{
		emit_compilation_unit_(compilation_unit_);
	}

	emit_entry_point_adapter_();
	i32 const total_size_ = type_declarations_->byte_length_()->op_add(function_declarations_->byte_length_())->op_add(class_declarations_->byte_length_())->op_add(global_definitions_->byte_length_())->op_add(definitions_->byte_length_());
	::System_::Text_::String_Builder_ *_Nonnull const cpp_code_ = (new ::System_::Text_::String_Builder_())->construct();
	cpp_code_->Append_(type_declarations_->ToString_());
	cpp_code_->Append_(function_declarations_->ToString_());
	cpp_code_->Append_(class_declarations_->ToString_());
	cpp_code_->Append_(global_definitions_->ToString_());
	cpp_code_->Append_(definitions_->ToString_());
	return cpp_code_->ToString_();
}

auto ::Emitter_::convert_type_name_(::Semantic_Node_ const *_Nonnull const type_node_) -> ::System_::Text_::String_Builder_ *_Nonnull
{
	assert_(not_equal_op(type_node_->referenced_type_, none), type_node_->get_text_());
	return convert_type_name_(type_node_->referenced_type_);
}

auto ::Emitter_::convert_type_name_(::Type_ const *_Nonnull const type_) -> ::System_::Text_::String_Builder_ *_Nonnull
{
	::System_::Text_::String_Builder_ *_Nonnull const cpp_type_ = (new ::System_::Text_::String_Builder_())->construct();
	if (cond(type_->is_primitive_))
	{
		if (cond(equal_op(type_->name_->unqualified_(), p_string("bool"))))
		{
			cpp_type_->Append_(p_string("bit"));
		}
		else if (cond(equal_op(type_->name_->unqualified_(), p_string("int"))))
		{
			cpp_type_->Append_(p_string("i32"));
		}
		else if (cond(equal_op(type_->name_->unqualified_(), p_string("uint"))))
		{
			cpp_type_->Append_(p_string("u32"));
		}
		else if (cond(equal_op(type_->name_->unqualified_(), p_string("code_point"))))
		{
			cpp_type_->Append_(p_string("cp"));
		}
		else if (cond(equal_op(type_->name_->unqualified_(), p_string("string"))))
		{
			cpp_type_->Append_(p_string("str"));
		}
		else if (cond(equal_op(type_->name_->unqualified_(), p_string("void"))))
		{
			cpp_type_->Append_(p_string("void"));
		}
		else
		{
			NOT_IMPLEMENTED_(type_->name_->unqualified_());
		}
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

	if (cond(type_->type_parameters_->op_magnitude()->op_greater_than(i32(0))))
	{
		cpp_type_->Append_(p_string("<"));
		bit first_ = bit_true;
		for (::Type_ const *_Nonnull const type_parameter_ : *(type_->type_parameters_))
		{
			if (cond(first_))
			{
				first_ = bit_false;
			}
			else
			{
				cpp_type_->Append_(p_string(", "));
			}

			cpp_type_->Append_(convert_type_(bit_true, type_parameter_, bit_false));
		}

		cpp_type_->Append_(p_string(">"));
	}

	return cpp_type_;
}

auto ::Emitter_::convert_reference_type_(bit const mutable_binding_, ::Type_ const *_Nonnull type_, bit const nullable_) -> p_string
{
	::System_::Text_::String_Builder_ *_Nonnull const cpp_type_ = convert_type_name_(type_);
	if (cond(bit_not(type_->is_mutable_)))
	{
		cpp_type_->Append_(p_string(" const"));
	}

	cpp_type_->Append_(p_string(" *"));
	if (cond(nullable_))
	{
		cpp_type_->Append_(p_string("_Nullable"));
	}
	else
	{
		cpp_type_->Append_(p_string("_Nonnull"));
	}

	if (cond(bit_not(mutable_binding_)))
	{
		cpp_type_->Append_(p_string(" const"));
	}

	return cpp_type_->ToString_();
}

auto ::Emitter_::convert_type_(bit const mutable_binding_, ::Type_ const *_Nonnull type_, bit const optional_) -> p_string
{
	assert_(not_equal_op(type_, none), p_string(""));
	if (cond(bit_op(bit_arg(type_->is_primitive_) && bit_arg(equal_op(type_->name_->unqualified_(), p_string("optional"))))))
	{
		::Type_ const *_Nonnull const optional_type_ = type_->type_parameters_->op_Element(i32(0));
		if (cond(optional_type_->is_value_type_))
		{
			::System_::Text_::String_Builder_ *_Nonnull const cpp_type_ = (new ::System_::Text_::String_Builder_())->construct(p_string("p_optional<"));
			cpp_type_->Append_(convert_type_(bit_true, optional_type_, bit_true));
			cpp_type_->Append_(p_string(">"));
			if (cond(bit_op(bit_arg(bit_not(mutable_binding_)) && bit_arg(bit_not(type_->is_mutable_)))))
			{
				cpp_type_->Append_(p_string(" const"));
			}

			return cpp_type_->ToString_();
		}
		else
		{
			return convert_type_(mutable_binding_, optional_type_, bit_true);
		}
	}
	else
	{
		if (cond(type_->is_value_type_))
		{
			::System_::Text_::String_Builder_ *_Nonnull const cpp_type_ = convert_type_name_(type_);
			if (cond(bit_op(bit_arg(bit_not(mutable_binding_)) && bit_arg(bit_not(type_->is_mutable_)))))
			{
				cpp_type_->Append_(p_string(" const"));
			}

			return cpp_type_->ToString_();
		}
		else
		{
			return convert_reference_type_(mutable_binding_, type_, optional_);
		}
	}
}

auto ::Emitter_::convert_type_(bit const mutable_binding_, ::Semantic_Node_ const *_Nonnull const type_node_) -> p_string
{
	assert_(not_equal_op(type_node_->referenced_type_, none), type_node_->get_text_());
	return convert_type_(mutable_binding_, type_node_->referenced_type_, bit_false);
}

auto ::Emitter_::convert_parameter_list_(::Semantic_Node_ const *_Nonnull const parameters_, bit const is_main_function_) -> p_string
{
	auto self = this;
	assert_(equal_op(parameters_->kind_, ParameterList_), p_string("parameters.kind=").op_add(parameters_->kind_));
	::System_::Text_::String_Builder_ *_Nonnull const builder_ = (new ::System_::Text_::String_Builder_())->construct();
	builder_->Append_(p_string("("));
	bit first_parameter_ = bit_true;
	for (::Semantic_Node_ const *_Nonnull const parameter_ : *(parameters_->children_of_kind_(Parameter_)))
	{
		if (cond(bit_not(first_parameter_)))
		{
			builder_->Append_(p_string(", "));
		}
		else
		{
			first_parameter_ = bit_false;
		}

		bit const mutable_binding_ = parameter_->has_child_(VarKeyword_);
		::Semantic_Node_ const *_Nonnull const type_node_ = parameter_->children_->op_Element(parameter_->children_->op_magnitude()->op_subtract(i32(1)));
		builder_->Append_(convert_type_(mutable_binding_, type_node_));
		builder_->Append_(p_string(" "));
		builder_->Append_(parameter_->first_child_(Identifier_)->get_text_());
		builder_->Append_(p_string("_"));
		if (cond(is_main_function_))
		{
			p_string type_string_;
			if (cond(equal_op(type_node_->kind_, MutableType_)))
			{
				type_string_ = type_node_->children_->op_Element(i32(0))->get_text_();
			}
			else
			{
				type_string_ = type_node_->get_text_();
			}

			if (cond(equal_op(type_string_, p_string("System.Console.Console"))))
			{
				main_function_accepts_console_ = bit_true;
			}

			if (cond(equal_op(type_string_, p_string("System.Console.Arguments"))))
			{
				main_function_accepts_args_ = bit_true;
			}
		}
	}

	builder_->Append_(p_string(")"));
	return builder_->ToString_();
}

auto ::Emitter_::convert_parameter_list_(::Semantic_Node_ const *_Nonnull const parameters_) -> p_string
{
	auto self = this;
	return convert_parameter_list_(parameters_, bit_false);
}

auto ::Emitter_::convert_expression_(::Semantic_Node_ const *_Nonnull const syntax_, ::Source_File_Builder_ *_Nonnull const builder_) -> void
{
	if (cond(equal_op(syntax_->kind_, NewExpression_)))
	{
		p_string constructor_name_ = p_string("construct");
		::Semantic_Node_ const *_Nonnull type_node_ = syntax_->children_->op_Element(i32(0));
		if (cond(equal_op(type_node_->kind_, QualifiedName_)))
		{
			::Semantic_Node_ const *_Nonnull const name_node_ = type_node_->children_->op_Element(i32(1));
			if (cond(bit_op(bit_arg(equal_op(name_node_->kind_, IdentifierName_)) && bit_arg(equal_op(name_node_->referenced_type_, none)))))
			{
				constructor_name_ = p_string("construct_").op_add(name_node_->get_text_());
				type_node_ = type_node_->children_->op_Element(i32(0));
			}
		}

		::Type_ const *_Nonnull const type_ = type_node_->referenced_type_;
		assert_(not_equal_op(type_, none), type_node_->get_text_());
		if (cond(type_->is_value_type_))
		{
			builder_->Write_(convert_type_name_(type_)->ToString_());
			builder_->Write_(p_string("::"));
			builder_->Write_(constructor_name_);
		}
		else
		{
			builder_->Write_(p_string("(new "));
			builder_->Write_(convert_type_name_(type_)->ToString_());
			builder_->Write_(p_string("())->"));
			builder_->Write_(constructor_name_);
		}

		::Semantic_Node_ const *_Nonnull const argumentList_ = syntax_->children_->op_Element(i32(1));
		convert_expression_(argumentList_, builder_);
	}
	else if (cond(equal_op(syntax_->kind_, ArgumentList_)))
	{
		builder_->Write_(p_string("("));
		bit first_expression_ = bit_true;
		for (::Semantic_Node_ const *_Nonnull const arg_ : *(syntax_->children_))
		{
			if (cond(bit_op(bit_arg(bit_op(bit_arg(not_equal_op(arg_->kind_, LeftParen_)) && bit_arg(not_equal_op(arg_->kind_, RightParen_)))) && bit_arg(not_equal_op(arg_->kind_, Comma_)))))
			{
				if (cond(first_expression_))
				{
					first_expression_ = bit_false;
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
	else if (cond(equal_op(syntax_->kind_, NotExpression_)))
	{
		builder_->Write_(p_string("bit_not("));
		convert_expression_(syntax_->children_->op_Element(i32(1)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (cond(equal_op(syntax_->kind_, MagnitudeExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(1)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(1)), builder_);
		builder_->Write_(p_string("op_magnitude()"));
	}
	else if (cond(equal_op(syntax_->kind_, ParenthesizedExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(1)), builder_);
	}
	else if (cond(equal_op(syntax_->kind_, NegateExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(1)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(1)), builder_);
		builder_->Write_(p_string("op_negate()"));
	}
	else if (cond(equal_op(syntax_->kind_, NoneLiteralExpression_)))
	{
		builder_->Write_(p_string("none"));
	}
	else if (cond(equal_op(syntax_->kind_, SelfExpression_)))
	{
		builder_->Write_(p_string("self"));
	}
	else if (cond(equal_op(syntax_->kind_, NumericLiteralExpression_)))
	{
		builder_->Write_(p_string("i32(").op_add(syntax_->get_text_())->op_add(p_string(")")));
	}
	else if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, TrueLiteralExpression_)) || bit_arg(equal_op(syntax_->kind_, FalseLiteralExpression_)))))
	{
		builder_->Write_(p_string("bit_").op_add(syntax_->get_text_()));
	}
	else if (cond(equal_op(syntax_->kind_, CodePointLiteralExpression_)))
	{
		builder_->Write_(p_string("cp(").op_add(syntax_->get_text_())->op_add(p_string(")")));
	}
	else if (cond(equal_op(syntax_->kind_, IdentifierName_)))
	{
		builder_->Write_(syntax_->get_text_()->op_add(p_string("_")));
	}
	else if (cond(equal_op(syntax_->kind_, StringLiteralExpression_)))
	{
		builder_->Write_(p_string("str(").op_add(syntax_->get_text_())->op_add(p_string(")")));
	}
	else if (cond(equal_op(syntax_->kind_, AssignmentExpression_)))
	{
		i32 const operator_ = syntax_->children_->op_Element(i32(1))->kind_;
		if (cond(equal_op(operator_, Equals_)))
		{
			convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
			builder_->Write_(p_string(" "));
			builder_->Write_(syntax_->children_->op_Element(i32(1))->get_text_());
			builder_->Write_(p_string(" "));
			convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		}
		else
		{
			convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
			convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
			builder_->Write_(p_string("op_"));
			if (cond(equal_op(operator_, PlusEquals_)))
			{
				builder_->Write_(p_string("add_assign"));
			}
			else if (cond(equal_op(operator_, MinusEquals_)))
			{
				builder_->Write_(p_string("subtract_assign"));
			}
			else
			{
				builder_->Error_(p_string("Unsupported assignment operator ").op_add(operator_));
			}

			builder_->Write_(p_string("("));
			convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
			builder_->Write_(p_string(")"));
		}
	}
	else if (cond(equal_op(syntax_->kind_, EqualExpression_)))
	{
		builder_->Write_(p_string("equal_op("));
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		builder_->Write_(p_string(", "));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (cond(equal_op(syntax_->kind_, NotEqualExpression_)))
	{
		builder_->Write_(p_string("not_equal_op("));
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		builder_->Write_(p_string(", "));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (cond(equal_op(syntax_->kind_, ComparisonExpression_)))
	{
		i32 const operator_ = syntax_->children_->op_Element(i32(1))->kind_;
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		builder_->Write_(p_string("op_"));
		if (cond(equal_op(operator_, LessThan_)))
		{
			builder_->Write_(p_string("less_than"));
		}
		else if (cond(equal_op(operator_, LessThanEquals_)))
		{
			builder_->Write_(p_string("less_than_or_equal"));
		}
		else if (cond(equal_op(operator_, GreaterThan_)))
		{
			builder_->Write_(p_string("greater_than"));
		}
		else if (cond(equal_op(operator_, GreaterThanEquals_)))
		{
			builder_->Write_(p_string("greater_than_or_equal"));
		}
		else
		{
			builder_->Error_(p_string("Unsupported comparison operator ").op_add(operator_));
		}

		builder_->Write_(p_string("("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (cond(equal_op(syntax_->kind_, AddExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		builder_->Write_(p_string("op_add("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (cond(equal_op(syntax_->kind_, SubtractExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		builder_->Write_(p_string("op_subtract("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (cond(equal_op(syntax_->kind_, MultiplyExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		builder_->Write_(p_string("op_multiply("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (cond(equal_op(syntax_->kind_, DivideExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		builder_->Write_(p_string("op_divide("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (cond(equal_op(syntax_->kind_, RemainderExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		builder_->Write_(p_string("op_remainder("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (cond(equal_op(syntax_->kind_, OrExpression_)))
	{
		builder_->Write_(p_string("bit_op(bit_arg("));
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		builder_->Write_(p_string(") || bit_arg("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		builder_->Write_(p_string("))"));
	}
	else if (cond(equal_op(syntax_->kind_, AndExpression_)))
	{
		builder_->Write_(p_string("bit_op(bit_arg("));
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		builder_->Write_(p_string(") && bit_arg("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		builder_->Write_(p_string("))"));
	}
	else if (cond(equal_op(syntax_->kind_, InvocationExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_expression_(syntax_->children_->op_Element(i32(1)), builder_);
	}
	else if (cond(equal_op(syntax_->kind_, MemberAccessExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_expression_(syntax_->children_->op_Element(i32(1)), builder_);
	}
	else if (cond(equal_op(syntax_->kind_, ElementAccessExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		builder_->Write_(p_string("op_Element("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
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
	if (cond(bit_op(bit_arg(bit_op(bit_arg(not_equal_op(type_, none)) && bit_arg(type_->is_value_type_))) && bit_arg(bit_not(bit_op(bit_arg(bit_op(bit_arg(type_->is_primitive_) && bit_arg(equal_op(type_->name_->unqualified_(), p_string("optional"))))) && bit_arg(bit_not(type_->type_parameters_->op_Element(i32(0))->is_value_type_))))))))
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
	if (cond(equal_op(statement_->kind_, ReturnStatement_)))
	{
		if (cond(equal_op(statement_->children_->op_magnitude(), i32(2))))
		{
			definitions_->WriteLine_(p_string("return;"));
		}
		else
		{
			definitions_->BeginLine_(p_string("return "));
			convert_expression_(statement_->children_->op_Element(i32(1)), definitions_);
			definitions_->EndLine_(p_string(";"));
		}
	}
	else if (cond(equal_op(statement_->kind_, LoopStatement_)))
	{
		definitions_->WriteLine_(p_string("for (;;)"));
		emit_statement_(statement_->children_->op_Element(i32(1)));
	}
	else if (cond(equal_op(statement_->kind_, Block_)))
	{
		definitions_->BeginBlock_();
		for (::Semantic_Node_ const *_Nonnull const block_statement_ : *(statement_->statements_()))
		{
			emit_statement_(block_statement_);
		}

		definitions_->EndBlock_();
	}
	else if (cond(equal_op(statement_->kind_, WhileStatement_)))
	{
		definitions_->BeginLine_(p_string("while (cond("));
		convert_expression_(statement_->children_->op_Element(i32(1)), definitions_);
		definitions_->EndLine_(p_string("))"));
		emit_statement_(statement_->children_->op_Element(i32(2)));
	}
	else if (cond(equal_op(statement_->kind_, ForStatement_)))
	{
		definitions_->BeginLine_(p_string("for ("));
		::Semantic_Node_ const *_Nonnull const variable_declaration_ = statement_->first_child_(VariableDeclaration_);
		bit const mutable_binding_ = variable_declaration_->has_child_(VarKeyword_);
		p_string const name_ = variable_declaration_->first_child_(Identifier_)->get_text_();
		::Semantic_Node_ const *_Nonnull const type_ = variable_declaration_->children_->op_Element(i32(2));
		definitions_->Write_(convert_type_(mutable_binding_, type_)->op_add(p_string(" "))->op_add(name_)->op_add(p_string("_")));
		definitions_->Write_(p_string(" : *("));
		convert_expression_(statement_->children_->op_Element(i32(3)), definitions_);
		definitions_->EndLine_(p_string("))"));
		emit_statement_(statement_->children_->op_Element(i32(4)));
	}
	else if (cond(equal_op(statement_->kind_, DoWhileStatement_)))
	{
		definitions_->WriteLine_(p_string("do"));
		emit_statement_(statement_->children_->op_Element(i32(1)));
		definitions_->BeginLine_(p_string("while (cond("));
		convert_expression_(statement_->children_->op_Element(i32(3)), definitions_);
		definitions_->EndLine_(p_string("));"));
	}
	else if (cond(equal_op(statement_->kind_, IfStatement_)))
	{
		::Semantic_Node_ const *_Nullable if_statement_ = statement_;
		definitions_->BeginLine_(p_string(""));
		for (;;)
		{
			definitions_->Write_(p_string("if (cond("));
			convert_expression_(if_statement_->children_->op_Element(i32(1)), definitions_);
			definitions_->EndLine_(p_string("))"));
			emit_statement_(if_statement_->children_->op_Element(i32(2)));
			::Semantic_Node_ const *_Nullable const elseClause_ = if_statement_->first_child_(ElseClause_);
			if (cond(not_equal_op(elseClause_, none)))
			{
				if_statement_ = elseClause_->first_child_(IfStatement_);
				if (cond(not_equal_op(if_statement_, none)))
				{
					definitions_->BeginLine_(p_string("else "));
				}
				else
				{
					definitions_->WriteLine_(p_string("else"));
					emit_statement_(elseClause_->children_->op_Element(i32(1)));
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	else if (cond(equal_op(statement_->kind_, BreakStatement_)))
	{
		definitions_->WriteLine_(p_string("break;"));
	}
	else if (cond(equal_op(statement_->kind_, ContinueStatement_)))
	{
		definitions_->WriteLine_(p_string("continue;"));
	}
	else if (cond(equal_op(statement_->kind_, LocalDeclarationStatement_)))
	{
		::Semantic_Node_ const *_Nonnull const variable_declaration_ = statement_->first_child_(VariableDeclaration_);
		p_string const variable_name_ = variable_declaration_->first_child_(Identifier_)->get_text_();
		::Semantic_Node_ const *_Nonnull const variable_type_ = variable_declaration_->children_->op_Element(i32(2));
		bit const mutable_binding_ = variable_declaration_->has_child_(VarKeyword_);
		definitions_->BeginLine_(convert_type_(mutable_binding_, variable_type_));
		definitions_->Write_(p_string(" ").op_add(variable_name_)->op_add(p_string("_")));
		if (cond(variable_declaration_->children_->op_magnitude()->op_greater_than(i32(3))))
		{
			definitions_->Write_(p_string(" = "));
			convert_expression_(variable_declaration_->children_->op_Element(i32(3)), definitions_);
		}

		definitions_->EndLine_(p_string(";"));
	}
	else if (cond(equal_op(statement_->kind_, ExpressionStatement_)))
	{
		definitions_->BeginLine_(p_string(""));
		convert_expression_(statement_->children_->op_Element(i32(0)), definitions_);
		definitions_->EndLine_(p_string(";"));
	}
	else
	{
		NOT_IMPLEMENTED_(p_string("statement.kind=").op_add(statement_->kind_));
	}
}

auto ::Emitter_::emit_method_body_(::Semantic_Node_ const *_Nonnull const block_, bit const is_associated_function_) -> void
{
	auto self = this;
	definitions_->BeginBlock_();
	if (cond(bit_not(is_associated_function_)))
	{
		definitions_->WriteLine_(p_string("auto self = this;"));
	}

	for (::Semantic_Node_ const *_Nonnull const statement_ : *(block_->statements_()))
	{
		emit_statement_(statement_);
	}

	definitions_->EndBlock_();
}

auto ::Emitter_::emit_constructor_body_(::Semantic_Node_ const *_Nonnull const block_, p_string const self_type_, bit const is_value_type_) -> void
{
	auto self = this;
	definitions_->BeginBlock_();
	if (cond(is_value_type_))
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

auto ::Emitter_::emit_access_modifer_(i32 const current_access_level_, i32 const access_modifer_) -> i32
{
	auto self = this;
	if (cond(not_equal_op(access_modifer_, current_access_level_)))
	{
		if (cond(bit_op(bit_arg(equal_op(access_modifer_, PublicKeyword_)) || bit_arg(equal_op(access_modifer_, InternalKeyword_)))))
		{
			class_declarations_->EndLine_(p_string("public:"));
			return PublicKeyword_;
		}
		else if (cond(equal_op(access_modifer_, ProtectedKeyword_)))
		{
			class_declarations_->EndLine_(p_string("public:"));
		}
		else if (cond(equal_op(access_modifer_, PrivateKeyword_)))
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

auto ::Emitter_::emit_member_declaration_(::Semantic_Node_ const *_Nonnull const member_, p_string const class_name_, bit const is_value_type_, i32 const current_access_level_) -> i32
{
	auto self = this;
	i32 access_modifer_ = member_->access_modifier_()->kind_;
	access_modifer_ = emit_access_modifer_(current_access_level_, access_modifer_);
	if (cond(equal_op(member_->kind_, ConstructorDeclaration_)))
	{
		p_string const parameters_ = convert_parameter_list_(member_->first_child_(ParameterList_));
		p_string full_name_ = p_string("construct");
		::Semantic_Node_ const *_Nullable const constructor_name_ = member_->first_child_(Identifier_);
		if (cond(not_equal_op(constructor_name_, none)))
		{
			full_name_ = p_string("construct_").op_add(constructor_name_->get_text_());
		}

		p_string return_type_ = p_string("::").op_add(class_name_)->op_add(p_string("_"));
		if (cond(bit_not(is_value_type_)))
		{
			return_type_ = return_type_.op_add(p_string("*"));
		}

		class_declarations_->BeginLine_(p_string(""));
		if (cond(is_value_type_))
		{
			class_declarations_->Write_(p_string("static "));
		}

		class_declarations_->EndLine_(p_string("auto ").op_add(full_name_)->op_add(parameters_)->op_add(p_string(" -> "))->op_add(return_type_)->op_add(p_string(";")));
		definitions_->ElementSeparatorLine_();
		definitions_->WriteLine_(p_string("auto ::").op_add(class_name_)->op_add(p_string("_::"))->op_add(full_name_)->op_add(parameters_)->op_add(p_string(" -> "))->op_add(return_type_));
		emit_constructor_body_(member_->first_child_(Block_), return_type_, is_value_type_);
	}
	else if (cond(equal_op(member_->kind_, FieldDeclaration_)))
	{
		::Semantic_Node_ const *_Nonnull const variable_declaration_ = member_->first_child_(VariableDeclaration_);
		p_string const field_name_ = variable_declaration_->first_child_(Identifier_)->get_text_();
		::Semantic_Node_ const *_Nonnull const field_type_ = variable_declaration_->children_->op_Element(i32(2));
		p_string const cpp_type_ = convert_type_(bit_true, field_type_);
		class_declarations_->WriteLine_(cpp_type_.op_add(p_string(" "))->op_add(field_name_)->op_add(p_string("_;")));
	}
	else if (cond(equal_op(member_->kind_, MethodDeclaration_)))
	{
		p_string const method_name_ = member_->first_child_(Identifier_)->get_text_();
		p_string const parameters_ = convert_parameter_list_(member_->first_child_(ParameterList_));
		::Semantic_Node_ const *_Nullable const self_parameter_ = member_->first_child_(ParameterList_)->first_child_(SelfParameter_);
		bit const is_associated_function_ = equal_op(self_parameter_, none);
		bit const mutable_self_ = bit_op(bit_arg(bit_not(is_associated_function_)) && bit_arg(self_parameter_->has_child_(MutableKeyword_)));
		::Semantic_Node_ const *_Nonnull const return_type_node_ = member_->children_->op_Element(i32(3));
		p_string const cpp_type_ = convert_type_(bit_true, return_type_node_);
		p_string static_modifier_ = p_string("");
		if (cond(is_associated_function_))
		{
			static_modifier_ = p_string("static ");
		}

		p_string constModifier_ = p_string("");
		if (cond(bit_op(bit_arg(bit_not(mutable_self_)) && bit_arg(bit_not(is_associated_function_)))))
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

auto ::Emitter_::emit_default_constructor_(p_string const type_name_, bit const is_value_type_, i32 const current_access_level_) -> void
{
	auto self = this;
	emit_access_modifer_(current_access_level_, PublicKeyword_);
	p_string return_type_ = p_string("::").op_add(type_name_)->op_add(p_string("_"));
	if (cond(bit_not(is_value_type_)))
	{
		return_type_ = return_type_.op_add(p_string("*"));
	}

	class_declarations_->BeginLine_(p_string(""));
	if (cond(is_value_type_))
	{
		class_declarations_->Write_(p_string("static "));
	}

	class_declarations_->Write_(p_string("auto construct() -> ").op_add(return_type_));
	if (cond(is_value_type_))
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
	if (cond(equal_op(declaration_->kind_, GlobalDeclaration_)))
	{
		::Semantic_Node_ const *_Nonnull const variable_declaration_ = declaration_->first_child_(VariableDeclaration_);
		p_string const variable_name_ = variable_declaration_->first_child_(Identifier_)->get_text_();
		::Semantic_Node_ const *_Nonnull const variable_type_ = variable_declaration_->children_->op_Element(i32(2));
		bit const mutable_binding_ = variable_declaration_->has_child_(VarKeyword_);
		p_string const cpp_type_ = convert_type_(mutable_binding_, variable_type_);
		global_definitions_->BeginLine_(cpp_type_);
		global_definitions_->Write_(p_string(" ").op_add(variable_name_)->op_add(p_string("_ = ")));
		::Semantic_Node_ const *_Nonnull const expression_ = variable_declaration_->children_->op_Element(i32(3));
		convert_expression_(expression_, global_definitions_);
		global_definitions_->EndLine_(p_string(";"));
	}
	else if (cond(equal_op(declaration_->kind_, ClassDeclaration_)))
	{
		p_string const class_name_ = declaration_->first_child_(Identifier_)->get_text_();
		type_declarations_->WriteLine_(p_string("class ").op_add(class_name_)->op_add(p_string("_;")));
		class_declarations_->ElementSeparatorLine_();
		class_declarations_->WriteLine_(p_string("class ").op_add(class_name_)->op_add(p_string("_")));
		class_declarations_->BeginBlock_();
		class_declarations_->EndLine_(p_string("public:"));
		i32 current_access_level_ = PublicKeyword_;
		bit has_constructors_ = bit_false;
		for (::Semantic_Node_ const *_Nonnull const member_ : *(declaration_->members_()))
		{
			has_constructors_ = bit_op(bit_arg(has_constructors_) || bit_arg(equal_op(member_->kind_, ConstructorDeclaration_)));
			current_access_level_ = emit_member_declaration_(member_, class_name_, bit_false, current_access_level_);
		}

		if (cond(bit_not(has_constructors_)))
		{
			emit_default_constructor_(class_name_, bit_false, current_access_level_);
		}

		class_declarations_->EndBlockWithSemicolon_();
	}
	else if (cond(equal_op(declaration_->kind_, StructDeclaration_)))
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
		i32 current_access_level_ = PublicKeyword_;
		bit has_constructors_ = bit_false;
		for (::Semantic_Node_ const *_Nonnull const member_ : *(declaration_->members_()))
		{
			has_constructors_ = bit_op(bit_arg(has_constructors_) || bit_arg(equal_op(member_->kind_, ConstructorDeclaration_)));
			current_access_level_ = emit_member_declaration_(member_, struct_name_, bit_true, current_access_level_);
		}

		if (cond(bit_not(has_constructors_)))
		{
			emit_default_constructor_(struct_name_, bit_true, current_access_level_);
		}

		class_declarations_->EndBlockWithSemicolon_();
	}
	else if (cond(equal_op(declaration_->kind_, EnumDeclaration_)))
	{
		p_string const enum_name_ = declaration_->first_child_(Identifier_)->get_text_();
		type_declarations_->WriteLine_(p_string("enum class ").op_add(enum_name_)->op_add(p_string("_;")));
		class_declarations_->ElementSeparatorLine_();
		class_declarations_->WriteLine_(p_string("enum class ").op_add(enum_name_)->op_add(p_string("_")));
		class_declarations_->BeginBlock_();
		for (::Semantic_Node_ const *_Nonnull const member_ : *(declaration_->children_))
		{
			if (cond(equal_op(member_->kind_, EnumMemberDeclaration_)))
			{
				p_string const member_name_ = member_->children_->op_Element(i32(0))->get_text_();
				class_declarations_->BeginLine_(member_name_.op_add(p_string("_")));
				::Semantic_Node_ const *_Nullable const member_value_ = member_->first_child_(Number_);
				if (cond(not_equal_op(member_value_, none)))
				{
					class_declarations_->Write_(p_string(" = "));
					class_declarations_->Write_(member_value_->get_text_());
				}

				class_declarations_->EndLine_(p_string(","));
			}
		}

		class_declarations_->EndBlockWithSemicolon_();
	}
	else if (cond(equal_op(declaration_->kind_, FunctionDeclaration_)))
	{
		p_string const name_ = declaration_->first_child_(Identifier_)->get_text_();
		bit const is_main_ = bit_op(bit_arg(equal_op(name_, p_string("Main"))) || bit_arg(equal_op(name_, p_string("main"))));
		if (cond(is_main_))
		{
			main_function_name_ = name_;
		}

		p_string const parameters_ = convert_parameter_list_(declaration_->first_child_(ParameterList_), is_main_);
		::Semantic_Node_ const *_Nonnull const return_type_node_ = declaration_->children_->op_Element(i32(3));
		p_string const cpp_type_ = convert_type_(bit_true, return_type_node_);
		function_declarations_->WriteLine_(p_string("auto ").op_add(name_)->op_add(p_string("_"))->op_add(parameters_)->op_add(p_string(" -> "))->op_add(cpp_type_)->op_add(p_string(";")));
		definitions_->ElementSeparatorLine_();
		definitions_->WriteLine_(p_string("auto ").op_add(name_)->op_add(p_string("_"))->op_add(parameters_)->op_add(p_string(" -> "))->op_add(cpp_type_));
		if (cond(is_main_))
		{
			if (cond(not_equal_op(main_function_return_type_, p_string(""))))
			{
				definitions_->Error_(p_string("Multiple declarations of main"));
			}

			main_function_return_type_ = cpp_type_;
		}

		emit_statement_(declaration_->first_child_(Block_));
	}
	else if (cond(equal_op(declaration_->kind_, EndOfFileToken_)))
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
	type_declarations_->WriteLine_(p_string("#include \"RuntimeLibrary.hpp\""));
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
		definitions_->BeginLine_(p_string("resource_manager_->AddResource(str(\""));
		definitions_->Write_(resource_->name_);
		definitions_->Write_(p_string("\"), str(\""));
		definitions_->Write_(resource_->Text_->Replace_(p_string("\\"), p_string("\\\\"))->Replace_(p_string("\n"), p_string("\\n"))->Replace_(p_string("\r"), p_string("\\r"))->Replace_(p_string("\""), p_string("\\\"")));
		definitions_->EndLine_(p_string("\"));"));
	}

	if (cond(resources_->op_magnitude()->op_greater_than(i32(0))))
	{
		definitions_->EndLine_(p_string(""));
	}

	::System_::Text_::String_Builder_ *_Nonnull const args_ = (new ::System_::Text_::String_Builder_())->construct();
	if (cond(main_function_accepts_console_))
	{
		args_->Append_(p_string("new ::System_::Console_::Console_()"));
	}

	if (cond(main_function_accepts_args_))
	{
		if (cond(main_function_accepts_console_))
		{
			args_->Append_(p_string(", "));
		}

		args_->Append_(p_string("new ::System_::Console_::Arguments_(argc, argv)"));
	}

	if (cond(equal_op(main_function_return_type_, p_string("void"))))
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
	self->package_ = none;
	self->kind_ = NamespaceName_;
	self->segments_ = (new ::System_::Collections_::List_<p_string>())->construct();
	self->is_special_ = bit_false;
	return self;
}

auto ::Name_::construct_global_namespace(::Package_Name_ const *_Nonnull const package_) -> ::Name_*
{
	::Name_* self = this;
	assert_(not_equal_op(package_, none), p_string(""));
	self->package_ = package_;
	self->kind_ = NamespaceName_;
	self->segments_ = (new ::System_::Collections_::List_<p_string>())->construct();
	self->is_special_ = bit_false;
	return self;
}

auto ::Name_::construct(::Name_ const *_Nonnull const qualifier_, i32 const kind_, p_string const name_) -> ::Name_*
{
	::Name_* self = this;
	assert_(not_equal_op(qualifier_, none), p_string(""));
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), p_string(""));
	self->package_ = qualifier_->package_;
	self->kind_ = kind_;
	::System_::Collections_::List_<p_string> *_Nonnull const segments_ = (new ::System_::Collections_::List_<p_string>())->construct();
	for (p_string const segment_ : *(qualifier_->segments_))
	{
		segments_->Add_(segment_);
	}

	segments_->Add_(name_);
	self->segments_ = segments_;
	self->is_special_ = bit_false;
	return self;
}

auto ::Name_::construct(::Name_ const *_Nonnull const qualifier_, i32 const kind_, p_string const name_, bit const is_special_) -> ::Name_*
{
	::Name_* self = this;
	assert_(not_equal_op(qualifier_, none), p_string(""));
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), p_string(""));
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

auto ::Name_::construct_special(::Name_ const *_Nonnull const qualifier_, i32 const kind_, p_string const name_) -> ::Name_*
{
	::Name_* self = this;
	assert_(not_equal_op(qualifier_, none), p_string(""));
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), p_string(""));
	self->package_ = qualifier_->package_;
	self->kind_ = kind_;
	::System_::Collections_::List_<p_string> *_Nonnull const segments_ = (new ::System_::Collections_::List_<p_string>())->construct();
	for (p_string const segment_ : *(qualifier_->segments_))
	{
		segments_->Add_(segment_);
	}

	segments_->Add_(name_);
	self->segments_ = segments_;
	self->is_special_ = bit_true;
	return self;
}

auto ::Name_::construct(::Package_Name_ const *_Nullable const package_, i32 const kind_, ::System_::Collections_::List_<p_string> const *_Nonnull const segments_, bit const is_special_) -> ::Name_*
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
	if (cond(equal_op(segments_->op_magnitude(), i32(0))))
	{
		return p_string("");
	}

	return segments_->op_Element(segments_->op_magnitude()->op_subtract(i32(1)));
}

auto ::Name_::full_() const -> p_string
{
	auto self = this;
	p_string name_ = p_string("");
	if (cond(not_equal_op(package_, none)))
	{
		name_ = package_->full_();
	}

	name_ = name_.op_add(p_string("::"));
	bit first_ = bit_true;
	for (p_string const segment_ : *(segments_))
	{
		if (cond(first_))
		{
			first_ = bit_false;
			name_ = name_.op_add(segment_);
			continue;
		}

		name_ = name_.op_add(p_string("."))->op_add(segment_);
	}

	return name_;
}

auto ::Name_::is_qualified_with_(::Name_ const *_Nonnull const qualifier_) const -> bit
{
	auto self = this;
	if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(not_equal_op(package_, none)) && bit_arg(not_equal_op(qualifier_->package_, none)))) && bit_arg(not_equal_op(package_->full_(), qualifier_->package_->full_())))) || bit_arg(segments_->op_magnitude()->op_less_than_or_equal(qualifier_->segments_->op_magnitude())))))
	{
		return bit_false;
	}

	i32 i_ = i32(0);
	for (p_string const segment_ : *(qualifier_->segments_))
	{
		if (cond(not_equal_op(segment_, segments_->op_Element(i_))))
		{
			return bit_false;
		}

		i_.op_add_assign(i32(1));
	}

	return bit_true;
}

auto ::Name_::qualifier_is_(::Name_ const *_Nonnull const qualifier_) const -> bit
{
	auto self = this;
	return bit_op(bit_arg(equal_op(qualifier_->segments_->op_magnitude()->op_add(i32(1)), segments_->op_magnitude())) && bit_arg(is_qualified_with_(qualifier_)));
}

auto ::Name_::names_(::Name_ const *_Nonnull const other_) const -> bit
{
	auto self = this;
	if (cond(bit_op(bit_arg(bit_op(bit_arg(not_equal_op(package_, none)) && bit_arg(bit_op(bit_arg(equal_op(other_->package_, none)) || bit_arg(not_equal_op(package_->full_(), other_->package_->full_())))))) || bit_arg(not_equal_op(segments_->op_magnitude(), other_->segments_->op_magnitude())))))
	{
		return bit_false;
	}

	i32 i_ = i32(0);
	for (p_string const segment_ : *(other_->segments_))
	{
		if (cond(not_equal_op(segment_, segments_->op_Element(i_))))
		{
			return bit_false;
		}

		i_.op_add_assign(i32(1));
	}

	return bit_true;
}

auto ::Name_::is_package_qualified_() const -> bit
{
	auto self = this;
	return not_equal_op(package_, none);
}

auto ::Name_::remove_package_() const -> ::Name_ const *_Nonnull
{
	auto self = this;
	if (cond(equal_op(package_, none)))
	{
		return self;
	}
	else
	{
		return (new ::Name_())->construct(none, kind_, segments_, is_special_);
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
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), p_string(""));
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
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), p_string(""));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = bit_false;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	self->children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return self;
}

auto ::Symbol_::construct_identifier(p_string const name_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_) -> ::Symbol_*
{
	::Symbol_* self = this;
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), p_string(""));
	assert_(not_equal_op(declarations_, none), p_string("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = bit_false;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = declarations_;
	self->children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return self;
}

auto ::Symbol_::construct_identifier(p_string const name_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*
{
	::Symbol_* self = this;
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), p_string(""));
	assert_(not_equal_op(children_, none), p_string("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = bit_false;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	self->children_ = children_;
	return self;
}

auto ::Symbol_::construct_constructor(p_string const name_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_) -> ::Symbol_*
{
	::Symbol_* self = this;
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), p_string(""));
	assert_(not_equal_op(declarations_, none), p_string("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = bit_true;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = declarations_;
	self->children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return self;
}

auto ::Symbol_::construct_package(p_string const name_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*
{
	::Symbol_* self = this;
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), p_string(""));
	assert_(not_equal_op(children_, none), p_string("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = PackageSymbol_;
	self->is_special_name_ = bit_false;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	self->children_ = children_;
	return self;
}

auto ::Symbol_::construct_declaring(::Type_ const *_Nonnull const declares_type_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*
{
	::Symbol_* self = this;
	assert_(not_equal_op(declares_type_, none), p_string(""));
	assert_(not_equal_op(declarations_, none), p_string("name=").op_add(declares_type_->name_->unqualified_()));
	assert_(not_equal_op(children_, none), p_string("name=").op_add(declares_type_->name_->unqualified_()));
	self->name_ = declares_type_->name_->unqualified_();
	self->is_special_name_ = declares_type_->name_->is_special_;
	self->of_type_ = none;
	self->declares_type_ = declares_type_;
	self->declarations_ = declarations_;
	self->children_ = children_;
	return self;
}

auto ::Symbol_::construct_of_type(p_string const name_, ::Type_ const *_Nonnull const of_type_, ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> const *_Nonnull const declarations_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const children_) -> ::Symbol_*
{
	::Symbol_* self = this;
	assert_(not_equal_op(of_type_, none), p_string("name=").op_add(name_));
	assert_(not_equal_op(declarations_, none), p_string("name=").op_add(name_));
	assert_(not_equal_op(children_, none), p_string("name=").op_add(name_));
	self->name_ = name_;
	self->is_special_name_ = bit_false;
	self->of_type_ = of_type_;
	self->declares_type_ = none;
	self->declarations_ = declarations_;
	self->children_ = children_;
	return self;
}

auto ::Symbol_::get_(p_string const name_, i32 const kind_) const -> ::Symbol_ const *_Nullable
{
	auto self = this;
	for (::Symbol_ const *_Nonnull const child_ : *(children_))
	{
		if (cond(bit_op(bit_arg(equal_op(child_->name_, name_)) && bit_arg(equal_op(child_->kind_, kind_)))))
		{
			return child_;
		}
	}

	return none;
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
	assert_(not_equal_op(package_with_children_->get_(p_string("child"), IdentifierSymbol_), none), p_string(""));
}

auto ::Type_::construct(i32 const kind_, ::Name_ const *_Nonnull const name_, bit const is_mutable_) -> ::Type_*
{
	::Type_* self = this;
	assert_(not_equal_op(name_, none), p_string(""));
	self->kind_ = kind_;
	self->name_ = name_;
	self->type_parameters_ = (new ::System_::Collections_::List_<::Type_ const *_Nonnull>())->construct();
	self->is_primitive_ = bit_false;
	self->is_value_type_ = equal_op(kind_, ValueType_);
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
	self->is_primitive_ = bit_false;
	self->is_value_type_ = bit_false;
	self->is_potentially_mutable_ = bit_true;
	self->is_mutable_ = bit_false;
	return self;
}

auto ::Type_::construct(i32 const kind_, ::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_mutable_) -> ::Type_*
{
	::Type_* self = this;
	self->kind_ = kind_;
	self->name_ = name_;
	self->type_parameters_ = type_parameters_;
	self->is_primitive_ = bit_false;
	self->is_value_type_ = equal_op(kind_, ValueType_);
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
	self->is_primitive_ = bit_true;
	self->is_value_type_ = bit_true;
	self->is_potentially_mutable_ = bit_false;
	self->is_mutable_ = bit_false;
	return self;
}

auto ::Type_::construct_primitive(::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_) -> ::Type_*
{
	::Type_* self = this;
	self->kind_ = ValueType_;
	self->name_ = name_;
	self->type_parameters_ = type_parameters_;
	self->is_primitive_ = bit_true;
	self->is_value_type_ = bit_true;
	self->is_potentially_mutable_ = bit_false;
	self->is_mutable_ = bit_false;
	return self;
}

auto ::Type_::construct_namespace(::Name_ const *_Nonnull const name_) -> ::Type_*
{
	::Type_* self = this;
	self->kind_ = NamespaceType_;
	self->name_ = name_;
	self->is_primitive_ = bit_false;
	self->type_parameters_ = (new ::System_::Collections_::List_<::Type_ const *_Nonnull>())->construct();
	self->is_value_type_ = bit_true;
	self->is_potentially_mutable_ = bit_false;
	self->is_mutable_ = bit_false;
	return self;
}

auto ::Type_::construct_generic(::Type_ const *_Nonnull const definition_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_arguments_) -> ::Type_*
{
	::Type_* self = this;
	assert_(not_equal_op(definition_, none), p_string(""));
	assert_(not_equal_op(type_arguments_, none), definition_->name_->full_());
	assert_(equal_op(definition_->type_parameters_->op_magnitude(), type_arguments_->op_magnitude()), definition_->name_->full_()->op_add(p_string(" "))->op_add(definition_->type_parameters_->op_magnitude())->op_add(p_string(" given "))->op_add(type_arguments_->op_magnitude()));
	self->kind_ = definition_->kind_;
	self->name_ = definition_->name_;
	self->type_parameters_ = type_arguments_;
	self->is_primitive_ = definition_->is_primitive_;
	self->is_value_type_ = definition_->is_value_type_;
	self->is_potentially_mutable_ = definition_->is_potentially_mutable_;
	self->is_mutable_ = definition_->is_mutable_;
	return self;
}

auto ::Type_::construct(i32 const kind_, ::Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Type_ const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_primitive_, bit const is_potentially_mutable_, bit const is_mutable_) -> ::Type_*
{
	::Type_* self = this;
	self->kind_ = kind_;
	self->name_ = name_;
	self->type_parameters_ = type_parameters_;
	self->is_primitive_ = is_primitive_;
	self->is_value_type_ = equal_op(kind_, ValueType_);
	self->is_potentially_mutable_ = is_potentially_mutable_;
	self->is_mutable_ = is_mutable_;
	return self;
}

auto ::Type_::make_mutable_() const -> ::Type_ const *_Nonnull
{
	auto self = this;
	assert_(is_potentially_mutable_, p_string("self.name=").op_add(name_->full_()));
	return (new ::Type_())->construct(kind_, name_, type_parameters_, is_primitive_, is_potentially_mutable_, bit_true);
}

auto ::Type_::make_immutable_() const -> ::Type_ const *_Nonnull
{
	auto self = this;
	return (new ::Type_())->construct(kind_, name_, type_parameters_, is_primitive_, is_potentially_mutable_, bit_false);
}

auto ::Type_::remove_package_() const -> ::Type_ const *_Nonnull
{
	auto self = this;
	assert_(equal_op(kind_, NamespaceType_), p_string("kind=").op_add(kind_));
	if (cond(name_->is_package_qualified_()))
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
	self->parent_ = none;
	self->name_ = (new ::Name_())->construct_global_namespace();
	self->type_ = (new ::Type_())->construct_namespace(self->name_);
	subtables_ = (new ::System_::Collections_::List_<::Name_Subtable_ *_Nonnull>())->construct();
	return self;
}

auto ::Name_Subtable_::construct_global_namespace(::Name_Table_ const *_Nonnull const name_table_, ::Package_Name_ const *_Nonnull const package_name_) -> ::Name_Subtable_*
{
	::Name_Subtable_* self = this;
	self->name_table_ = name_table_;
	self->parent_ = none;
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
	if (cond(name_->qualifier_is_(self->name_)))
	{
		if (cond(bit_op(bit_arg(bit_op(bit_arg(equal_op(self->name_->package_, none)) && bit_arg(not_equal_op(type_, none)))) && bit_arg(equal_op(type_->kind_, NamespaceType_)))))
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
		if (cond(name_->is_qualified_with_(subtable_->name_)))
		{
			subtable_->add_(name_, type_);
			return;
		}
	}

	assert_(equal_op(name_->segments_->op_magnitude(), self->name_->segments_->op_magnitude()->op_add(i32(1))), p_string("Can't add \"").op_add(name_->full_())->op_add(p_string("\" to \""))->op_add(self->name_->full_())->op_add(p_string("\"")));
}

auto ::Name_Subtable_::find_(p_string const name_) const -> ::Name_Subtable_ *_Nullable
{
	auto self = this;
	return find_(name_, bit_false);
}

auto ::Name_Subtable_::find_special_(p_string const name_) const -> ::Name_Subtable_ *_Nullable
{
	auto self = this;
	return find_(name_, bit_true);
}

auto ::Name_Subtable_::find_(p_string const name_, bit const is_special_) const -> ::Name_Subtable_ *_Nullable
{
	auto self = this;
	for (::Name_Subtable_ *_Nonnull const subtable_ : *(subtables_))
	{
		if (cond(bit_op(bit_arg(equal_op(subtable_->name_->unqualified_(), name_)) && bit_arg(equal_op(subtable_->name_->is_special_, is_special_)))))
		{
			return subtable_;
		}
	}

	return none;
}

auto ::Name_Subtable_::lookup_(p_string const name_) const -> ::Name_Subtable_ *_Nullable
{
	auto self = this;
	return lookup_(name_, bit_false);
}

auto ::Name_Subtable_::lookup_special_(p_string const name_) const -> ::Name_Subtable_ *_Nullable
{
	auto self = this;
	return lookup_(name_, bit_true);
}

auto ::Name_Subtable_::lookup_(p_string const name_, bit const is_special_) const -> ::Name_Subtable_ *_Nullable
{
	auto self = this;
	::Name_Subtable_ *_Nullable subtable_ = find_(name_, is_special_);
	if (cond(bit_op(bit_arg(equal_op(subtable_, none)) && bit_arg(not_equal_op(parent_, none)))))
	{
		subtable_ = parent_->lookup_(name_, is_special_);
	}

	return subtable_;
}

auto ::Name_Subtable_::get_(::Name_ const *_Nonnull const name_) const -> ::Name_Subtable_ const *_Nullable
{
	auto self = this;
	if (cond(name_->names_(self->name_)))
	{
		return self;
	}
	else if (cond(bit_not(name_->is_qualified_with_(self->name_))))
	{
		return none;
	}

	for (::Name_Subtable_ const *_Nonnull const subtable_ : *(subtables_))
	{
		::Name_Subtable_ const *_Nullable const value_ = subtable_->get_(name_);
		if (cond(not_equal_op(value_, none)))
		{
			return value_;
		}
	}

	return none;
}

auto ::Name_Subtable_::bind_type_(::Type_ const *_Nonnull const type_) -> void
{
	auto self = this;
	assert_(not_equal_op(type_, none), self->name_->full_());
	if (cond(not_equal_op(self->type_, none)))
	{
		assert_(equal_op(self->type_->name_->full_(), type_->name_->full_()), self->name_->full_()->op_add(p_string(" currently `"))->op_add(self->type_->name_->full_())->op_add(p_string("` trying to set to `"))->op_add(type_->name_->full_())->op_add(p_string("`")));
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
	global_namespace_->add_(test_name_, none);
	assert_(not_equal_op(global_namespace_->find_(p_string("test")), none), p_string(""));
	assert_(not_equal_op(global_namespace_->get_(test_name_), none), p_string(""));
}

auto namespace_contains_added_name_() -> void
{
	::Name_Table_ const *_Nonnull const name_table_ = (new ::Name_Table_())->construct();
	::Name_Subtable_ *_Nonnull const global_namespace_ = (new ::Name_Subtable_())->construct_global_namespace(name_table_);
	::Name_ const *_Nonnull const namespace_name_ = (new ::Name_())->construct(global_namespace_->name_, NamespaceName_, p_string("namespace"));
	global_namespace_->add_(namespace_name_, none);
	global_namespace_->add_((new ::Name_())->construct(namespace_name_, TypeName_, p_string("test")), none);
	::Name_Subtable_ const *_Nonnull const namespace_ = global_namespace_->find_(p_string("namespace"));
	assert_(not_equal_op(namespace_->find_(p_string("test")), none), p_string(""));
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
	if (cond(not_equal_op(symbol_->declares_type_, none)))
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
		if (cond(name_->is_qualified_with_(package_->name_)))
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
	if (cond(equal_op(name_->package_, none)))
	{
		return any_package_->get_(name_);
	}

	for (::Name_Subtable_ const *_Nonnull const package_ : *(packages_))
	{
		if (cond(name_->is_qualified_with_(package_->name_)))
		{
			return package_->get_(name_);
		}
	}

	return none;
}

auto ::Name_Table_Builder_::build_(::Package_Name_ const *_Nonnull const package_name_, ::Syntax_Node_ const *_Nonnull const package_syntax_, ::System_::Collections_::List_<::Package_Reference_> const *_Nonnull const references_) const -> ::Name_Table_ const *_Nonnull
{
	auto self = this;
	assert_(equal_op(package_syntax_->kind_, PackageNode_), p_string("package_syntax.kind=").op_add(package_syntax_->kind_));
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
	assert_(equal_op(package_syntax_->kind_, PackageNode_), p_string("package_syntax.kind=").op_add(package_syntax_->kind_));
	::Name_ const *_Nonnull const global_namespace_ = name_table_->add_(package_name_);
	for (::Syntax_Node_ const *_Nonnull const compilation_unit_ : *(package_syntax_->children_))
	{
		add_compilation_unit_(name_table_, global_namespace_, compilation_unit_);
	}
}

auto ::Name_Table_Builder_::add_compilation_unit_(::Name_Table_ *_Nonnull const name_table_, ::Name_ const *_Nonnull const global_namespace_, ::Syntax_Node_ const *_Nonnull const compilation_unit_) -> void
{
	assert_(equal_op(compilation_unit_->kind_, CompilationUnit_), p_string("compilation_unit.kind=").op_add(compilation_unit_->kind_));
	for (::Syntax_Node_ const *_Nonnull const declaration_ : *(compilation_unit_->children_))
	{
		add_syntax_(name_table_, global_namespace_, declaration_);
	}
}

auto ::Name_Table_Builder_::add_syntax_(::Name_Table_ *_Nonnull const name_table_, ::Name_ const *_Nonnull const parent_, ::Syntax_Node_ const *_Nonnull const syntax_) -> void
{
	if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, FunctionDeclaration_)) || bit_arg(equal_op(syntax_->kind_, MethodDeclaration_)))))
	{
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, FunctionName_, syntax_->first_child_(Identifier_)->get_text_());
		add_function_(name_table_, name_, syntax_);
	}
	else if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, ClassDeclaration_)) || bit_arg(equal_op(syntax_->kind_, StructDeclaration_)))))
	{
		p_string const unqualified_name_ = syntax_->first_child_(Identifier_)->get_text_();
		i32 type_kind_;
		if (cond(equal_op(syntax_->kind_, ClassDeclaration_)))
		{
			type_kind_ = ReferenceType_;
		}
		else
		{
			type_kind_ = ValueType_;
		}

		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, TypeName_, unqualified_name_);
		::Type_ const *_Nonnull const type_ = (new ::Type_())->construct(type_kind_, name_, bit_true);
		name_table_->add_(name_, type_);
		for (::Syntax_Node_ const *_Nonnull const member_ : *(syntax_->members_()))
		{
			add_syntax_(name_table_, name_, member_);
		}
	}
	else if (cond(equal_op(syntax_->kind_, ConstructorDeclaration_)))
	{
		p_string full_name_ = p_string("new");
		::Syntax_Node_ const *_Nullable const constructor_name_ = syntax_->first_child_(Identifier_);
		if (cond(not_equal_op(constructor_name_, none)))
		{
			full_name_ = p_string("new_").op_add(constructor_name_->get_text_());
		}

		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct_special(parent_, FunctionName_, full_name_);
		add_function_(name_table_, name_, syntax_);
		::Name_ const *_Nonnull const self_name_ = (new ::Name_())->construct_special(name_, VariableName_, p_string("self"));
		::Type_ const *_Nonnull const self_type_ = none;
		name_table_->add_(self_name_, self_type_);
	}
	else if (cond(equal_op(syntax_->kind_, FieldDeclaration_)))
	{
		p_string const unqualified_name_ = syntax_->first_child_(VariableDeclaration_)->first_child_(Identifier_)->get_text_();
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, TypeName_, unqualified_name_);
		::Type_ const *_Nullable const no_type_ = none;
		name_table_->add_(name_, no_type_);
	}
	else if (cond(equal_op(syntax_->kind_, EnumDeclaration_)))
	{
		p_string const unqualified_name_ = syntax_->first_child_(Identifier_)->get_text_();
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, TypeName_, unqualified_name_);
		::Type_ const *_Nonnull const type_ = (new ::Type_())->construct(ReferenceType_, name_, bit_true);
		name_table_->add_(name_, type_);
	}
	else if (cond(equal_op(syntax_->kind_, GlobalDeclaration_)))
	{
		p_string const unqualified_name_ = syntax_->first_child_(VariableDeclaration_)->first_child_(Identifier_)->get_text_();
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, TypeName_, unqualified_name_);
		::Type_ const *_Nullable const no_type_ = none;
		name_table_->add_(name_, no_type_);
	}
	else if (cond(equal_op(syntax_->kind_, Block_)))
	{
		for (::Syntax_Node_ const *_Nonnull const statement_ : *(syntax_->statements_()))
		{
			add_syntax_(name_table_, parent_, statement_);
		}
	}
	else if (cond(bit_op(bit_arg(bit_op(bit_arg(equal_op(syntax_->kind_, LoopStatement_)) || bit_arg(equal_op(syntax_->kind_, WhileStatement_)))) || bit_arg(equal_op(syntax_->kind_, DoWhileStatement_)))))
	{
		add_syntax_(name_table_, parent_, syntax_->first_child_(Block_));
	}
	else if (cond(equal_op(syntax_->kind_, ForStatement_)))
	{
		::Syntax_Node_ const *_Nonnull const identifier_ = syntax_->first_child_(VariableDeclaration_)->first_child_(Identifier_);
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, VariableName_, identifier_->get_text_());
		::Type_ const *_Nullable const no_type_ = none;
		name_table_->add_(name_, no_type_);
		add_syntax_(name_table_, parent_, syntax_->first_child_(Block_));
	}
	else if (cond(equal_op(syntax_->kind_, IfStatement_)))
	{
		add_syntax_(name_table_, parent_, syntax_->first_child_(Block_));
		::Syntax_Node_ const *_Nullable const else_clause_ = syntax_->first_child_(ElseClause_);
		if (cond(not_equal_op(else_clause_, none)))
		{
			add_syntax_(name_table_, parent_, else_clause_);
		}
	}
	else if (cond(equal_op(syntax_->kind_, ElseClause_)))
	{
		::Syntax_Node_ const *_Nullable const block_ = syntax_->first_child_(Block_);
		if (cond(not_equal_op(block_, none)))
		{
			add_syntax_(name_table_, parent_, block_);
		}
		else
		{
			add_syntax_(name_table_, parent_, syntax_->first_child_(IfStatement_));
		}
	}
	else if (cond(equal_op(syntax_->kind_, LocalDeclarationStatement_)))
	{
		::Syntax_Node_ const *_Nonnull const identifier_ = syntax_->first_child_(VariableDeclaration_)->first_child_(Identifier_);
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, VariableName_, identifier_->get_text_());
		::Type_ const *_Nullable const no_type_ = none;
		name_table_->add_(name_, no_type_);
	}
	else if (cond(equal_op(syntax_->kind_, Parameter_)))
	{
		::Syntax_Node_ const *_Nonnull const identifier_ = syntax_->first_child_(Identifier_);
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct(parent_, VariableName_, identifier_->get_text_());
		::Type_ const *_Nullable const no_type_ = none;
		name_table_->add_(name_, no_type_);
	}
	else if (cond(equal_op(syntax_->kind_, SelfParameter_)))
	{
		::Name_ const *_Nonnull const name_ = (new ::Name_())->construct_special(parent_, VariableName_, p_string("self"));
		::Type_ const *_Nullable const no_type_ = none;
		name_table_->add_(name_, no_type_);
	}
	else if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(syntax_->kind_, ExpressionStatement_)) || bit_arg(equal_op(syntax_->kind_, ReturnStatement_)))) || bit_arg(equal_op(syntax_->kind_, BreakStatement_)))) || bit_arg(equal_op(syntax_->kind_, ContinueStatement_)))) || bit_arg(equal_op(syntax_->kind_, EndOfFileToken_)))))
	{
	}
	else
	{
		NOT_IMPLEMENTED_(p_string("syntax.kind=").op_add(syntax_->kind_));
	}
}

auto ::Name_Table_Builder_::add_function_(::Name_Table_ *_Nonnull const name_table_, ::Name_ const *_Nonnull const name_, ::Syntax_Node_ const *_Nonnull const function_) -> void
{
	::Type_ const *_Nullable const no_type_ = none;
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
	::Syntax_Node_ const *_Nonnull const package_syntax_ = (new ::Syntax_Node_())->construct(PackageNode_, none, i32(0), i32(0));
	::Name_Table_ const *_Nonnull const name_table_ = name_table_builder_->build_(name_, package_syntax_, references_);
	::Name_Subtable_ const *_Nonnull const namespace_ = name_table_->any_package_->find_(p_string("System"));
	assert_(not_equal_op(namespace_->find_(p_string("Console")), none), p_string(""));
	::Name_ const *_Nonnull const system_namespace_name_ = (new ::Name_())->construct((new ::Name_())->construct_global_namespace(), NamespaceName_, p_string("System"));
	assert_(not_equal_op(name_table_->get_(system_namespace_name_), none), p_string(""));
	::Name_ const *_Nonnull const console_namespace_name_ = (new ::Name_())->construct(system_namespace_name_, NamespaceName_, p_string("Console"));
	assert_(not_equal_op(name_table_->get_(console_namespace_name_), none), p_string(""));
	::Name_ const *_Nonnull const console_class_name_ = (new ::Name_())->construct(console_namespace_name_, TypeName_, p_string("Console"));
	assert_(not_equal_op(name_table_->get_(console_class_name_), none), p_string(""));
}

auto can_get_root_namespace_from_name_() -> void
{
	::Package_Name_ const *_Nonnull const name_ = (new ::Package_Name_())->construct(p_string("default"));
	::Package_ const *_Nonnull const runtime_package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	::System_::Collections_::List_<::Package_Reference_> *_Nonnull const references_ = (new ::System_::Collections_::List_<::Package_Reference_>())->construct();
	references_->add_(::Package_Reference_::construct(runtime_package_));
	::Name_Table_Builder_ const *_Nonnull const name_table_builder_ = (new ::Name_Table_Builder_())->construct();
	::Syntax_Node_ const *_Nonnull const package_syntax_ = (new ::Syntax_Node_())->construct(PackageNode_, none, i32(0), i32(0));
	::Name_Table_ const *_Nonnull const name_table_ = name_table_builder_->build_(name_, package_syntax_, references_);
	::Name_ const *_Nonnull const namespace_name_ = (new ::Name_())->construct((new ::Name_())->construct_global_namespace(), NamespaceName_, p_string("System"));
	assert_(not_equal_op(name_table_->get_(namespace_name_), none), p_string(""));
}

auto can_get_Console_class_from_name_without_package_() -> void
{
	::Package_Name_ const *_Nonnull const name_ = (new ::Package_Name_())->construct(p_string("default"));
	::Package_ const *_Nonnull const runtime_package_ = (new ::Runtime_Library_Package_Builder_())->construct()->build_();
	::System_::Collections_::List_<::Package_Reference_> *_Nonnull const references_ = (new ::System_::Collections_::List_<::Package_Reference_>())->construct();
	references_->add_(::Package_Reference_::construct(runtime_package_));
	::Name_Table_Builder_ const *_Nonnull const name_table_builder_ = (new ::Name_Table_Builder_())->construct();
	::Syntax_Node_ const *_Nonnull const package_syntax_ = (new ::Syntax_Node_())->construct(PackageNode_, none, i32(0), i32(0));
	::Name_Table_ const *_Nonnull const name_table_ = name_table_builder_->build_(name_, package_syntax_, references_);
	::Name_ const *_Nonnull const system_namespace_name_ = (new ::Name_())->construct((new ::Name_())->construct_global_namespace(), NamespaceName_, p_string("System"));
	::Name_ const *_Nonnull const console_namespace_name_ = (new ::Name_())->construct(system_namespace_name_, NamespaceName_, p_string("Console"));
	::Name_ const *_Nonnull const console_class_name_ = (new ::Name_())->construct(console_namespace_name_, TypeName_, p_string("Console"));
	assert_(not_equal_op(name_table_->get_(console_class_name_), none), p_string(""));
}

auto can_get_Optional_class_from_name_with_package_() -> void
{
	::Package_Name_ const *_Nonnull const name_ = (new ::Package_Name_())->construct(p_string("default"));
	::Package_ const *_Nonnull const primitives_package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	::System_::Collections_::List_<::Package_Reference_> *_Nonnull const references_ = (new ::System_::Collections_::List_<::Package_Reference_>())->construct();
	references_->add_(::Package_Reference_::construct(primitives_package_));
	::Name_Table_Builder_ const *_Nonnull const name_table_builder_ = (new ::Name_Table_Builder_())->construct();
	::Syntax_Node_ const *_Nonnull const package_syntax_ = (new ::Syntax_Node_())->construct(PackageNode_, none, i32(0), i32(0));
	::Name_Table_ const *_Nonnull const name_table_ = name_table_builder_->build_(name_, package_syntax_, references_);
	::Package_Name_ const *_Nonnull const package_name_ = (new ::Package_Name_())->construct(p_string("$primitives"));
	::Name_ const *_Nonnull const adamant_namespace_name_ = (new ::Name_())->construct((new ::Name_())->construct_global_namespace(), NamespaceName_, p_string("adamant"));
	::Name_ const *_Nonnull const language_namespace_name_ = (new ::Name_())->construct(adamant_namespace_name_, NamespaceName_, p_string("language"));
	assert_(not_equal_op(name_table_->get_(language_namespace_name_), none), p_string(""));
	::Name_ const *_Nonnull const optional_class_name_ = (new ::Name_())->construct(language_namespace_name_, TypeName_, p_string("optional"));
	assert_(not_equal_op(name_table_->get_(optional_class_name_), none), p_string(""));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		resource_manager_->AddResource(p_string("RuntimeLibrary.cpp"), p_string("#include \"RuntimeLibrary.hpp\"\n#include <map>\n\n// -----------------------------------------------------------------------------\n// Primitive Types\n// -----------------------------------------------------------------------------\n\nu32 i32::AsUInt_() const\n{\n    if(this->value < 0)\n        throw std::range_error(\"Can't convert negative number to unsigned\");\n\n    return u32(this->value);\n}\n\nchar cp_to_char(cp v)\n{\n    if(v.value > 0xFF)\n        throw std::range_error(\"Unicode char values not yet supported\");\n\n    return v.value;\n}\n\nstr str::construct(cp c, i32 repeat)\n{\n    str self;\n    self.Length = repeat.value;\n    char* buffer = new char[repeat.value];\n    for (int i = 0; i < repeat.value; i++)\n        buffer[i] = cp_to_char(c);\n\n    self.Buffer = buffer;\n    return self;\n}\n\nstr::str(const char* s)\n    : Length(std::strlen(s)), Buffer(s)\n{\n}\n\nstr::str(int length, const char* s)\n    : Length(length), Buffer(s)\n{\n}\n\nchar const * str::cstr() const\n{\n    auto buffer = new char[Length + 1];\n    std::memcpy(buffer, Buffer, Length);\n    buffer[Length] = 0;\n    return buffer;\n}\n\nstr::str(i32 other)\n    : Length(0), Buffer(0)\n{\n    char* buffer = new char[12]; // -2,147,483,648 to 2,147,483,647 plus null terminator\n    int length = std::sprintf(buffer,\"%d\", other.value);\n    if(length <= 0) throw std::runtime_error(\"Could not convert int to string\");\n    Length = length;\n    Buffer = buffer;\n}\n\nstr::str(cp other)\n    : Length(1), Buffer(new char[1] { cp_to_char(other) })\n{\n}\n\nstr::str(bit other)\n    : str(other.value ? \"true\" : \"false\")\n{\n}\n\nstr str::Substring_(i32 start, i32 length) const\n{\n    return str(length.value, Buffer + start.value);\n}\n\nstr str::Replace_(str oldValue, str newValue) const\n{\n    system_::Text_::String_Builder_ builder = system_::Text_::String_Builder_(); // TODO initialize capacity\n    int limit = Length - oldValue.Length + 1;\n    int lastIndex = 0;\n    // TODO the Substring calls in here are leaking memory\n    for(int i=0; i < limit; i++)\n        if (cond(equal_op(Substring_(i32(i), i32(oldValue.Length)), oldValue)))\n        {\n            builder.Append_(Substring_(i32(lastIndex), i32(i-lastIndex)));\n            builder.Append_(newValue);\n            i += oldValue.Length; // skip over the value we just matched\n            lastIndex = i;\n            i--; // we need i-- to offset the i++ that is about to happen\n        }\n\n    builder.Append_(Substring_(i32(lastIndex), i32(Length - lastIndex)));\n    return builder.ToString_();\n}\n\ni32 str::LastIndexOf_(cp c) const\n{\n    for(int i = Length - 1; i >= 0; i--)\n        if(Buffer[i] == cp_to_char(c))\n            return i32(i);\n\n    return i32(-1); // TODO should return none\n}\n\ni32 str::index_of_(cp c) const\n{\n    for(int i = 0; i < Length; i++)\n        if(Buffer[i] == cp_to_char(c))\n            return i32(i);\n\n    return i32(-1);\n}\n\nstr str::op_add(str const & value) const\n{\n    int newLength = Length + value.Length;\n    char* chars = new char[newLength];\n    size_t offset = sizeof(char) * Length;\n    std::memcpy(chars, Buffer, offset);\n    std::memcpy(chars + offset, value.Buffer, value.Length);\n    return str(newLength, chars);\n}\n\nauto equal_op(str lhs, str rhs) -> bit\n{\n    if (lhs.Length != rhs.Length)\n        return bit_false;\n\n    for (int i = 0; i < lhs.Length; i++)\n        if (lhs.Buffer[i] != rhs.Buffer[i])\n            return bit_false;\n\n    return bit_true;\n}\n\nbit str::op_less_than(str other) const\n{\n    char const* left = this->cstr();\n    char const* right = other.cstr();\n    bool result = std::strcmp(left, right) < 0;\n    delete[] left;\n    delete[] right;\n    return bit_from(result);\n}\n\nbit str::op_less_than_or_equal(str other) const\n{\n    char const* left = this->cstr();\n    char const* right = other.cstr();\n    bool result = std::strcmp(left, right) <= 0;\n    delete[] left;\n    delete[] right;\n    return bit_from(result);\n}\n\nbit str::op_greater_than(str other) const\n{\n    char const* left = this->cstr();\n    char const* right = other.cstr();\n    bool result = std::strcmp(left, right) > 0;\n    delete[] left;\n    delete[] right;\n    return bit_from(result);\n}\n\nbit str::op_greater_than_or_equal(str other) const\n{\n    char const* left = this->cstr();\n    char const* right = other.cstr();\n    bool result = std::strcmp(left, right) >= 0;\n    delete[] left;\n    delete[] right;\n    return bit_from(result);\n}\n\nbool operator < (str const & lhs, str const & rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) < 0;\n    delete[] left;\n    delete[] right;\n    return result;\n}\n\n// -----------------------------------------------------------------------------\n// Standard Library\n// -----------------------------------------------------------------------------\n\nstd::map<str, str> resourceValues;\n\nstr const & ResourceManager::GetString_(str resourceName)\n{\n    return resourceValues.at(resourceName);\n}\nvoid ResourceManager::AddResource(str name, str value)\n{\n    resourceValues.insert(std::make_pair(name, value));\n}\n\nResourceManager *const resource_manager_ = new ResourceManager();\n\nvoid debug_write_(str value)\n{\n    std::fprintf(stderr, \"%.*s\", value.Length, value.Buffer);\n}\nvoid debug_write_line_(str value)\n{\n    std::fprintf(stderr, \"%.*s\\n\", value.Length, value.Buffer);\n}\nvoid debug_write_line_()\n{\n    std::fprintf(stderr, \"\\n\");\n}\n\nnamespace system_\n{\n    namespace Console_\n    {\n        void Console_::Write_(str value)\n        {\n            std::printf(\"%.*s\", value.Length, value.Buffer);\n        }\n\n        void Console_::WriteLine_(str value)\n        {\n            std::printf(\"%.*s\\n\", value.Length, value.Buffer);\n        }\n\n        void Console_::WriteLine_()\n        {\n            std::printf(\"\\n\");\n        }\n\n        Arguments_::Arguments_(int argc, char const *const * argv)\n            : Count(argc-1)\n        {\n            args = new str[Count];\n            for (int i = 0; i < Count; i++)\n                args[i] = str(argv[i+1]);\n        }\n    }\n\n    namespace IO_\n    {\n        File_Reader_* File_Reader_::construct(const str& fileName)\n        {\n            std::FILE* foo;\n            auto fname = fileName.cstr();\n            file = std::fopen(fname, \"rb\");\n            delete[] fname;\n            return this;\n        }\n\n        str File_Reader_::ReadToEndSync_()\n        {\n            std::fseek(file, 0, SEEK_END);\n            auto length = std::ftell(file);\n            std::fseek(file, 0, SEEK_SET);\n            auto buffer = new char[length];\n            length = std::fread(buffer, sizeof(char), length, file);\n            return str(length, buffer);\n        }\n\n        void File_Reader_::Close_()\n        {\n            std::fclose(file);\n        }\n\n        File_Writer_* File_Writer_::construct(const str& fileName)\n        {\n            auto fname = fileName.cstr();\n            file = std::fopen(fname, \"wb\"); // TODO check error\n            delete[] fname;\n            return this;\n        }\n\n        void File_Writer_::Write_(const str& value)\n        {\n            std::fwrite(value.Buffer, sizeof(char), value.Length, file);\n        }\n\n        void File_Writer_::Close_()\n        {\n            std::fclose(file);\n        }\n    }\n\n    namespace Text_\n    {\n        void String_Builder_::ensure_capacity(int needed)\n        {\n            int new_capacity = capacity == 0 ? 128 : capacity;\n            while(new_capacity < needed)\n            {\n                new_capacity *= 2;\n            }\n\n            if(new_capacity > capacity)\n            {\n                char* new_buffer = new char[new_capacity];\n                if(length > 0)\n                    std::memcpy(new_buffer, buffer, length);\n\n                if(capacity > 0)\n                    delete[] buffer;\n\n                buffer = new_buffer;\n                capacity = new_capacity;\n            }\n        }\n\n        String_Builder_* String_Builder_::construct(str const & value)\n        {\n            ensure_capacity(value.Length);\n            std::memcpy(buffer, value.Buffer, value.Length);\n            length = value.Length;\n            return this;\n        }\n\n        String_Builder_ *_Nonnull String_Builder_::construct_with_capacity(i32 capacity)\n        {\n            ensure_capacity(capacity.value);\n            return this;\n        }\n\n        void String_Builder_::Append_(str const & value)\n        {\n            int new_length = length + value.Length;\n            ensure_capacity(new_length);\n            std::memcpy(buffer+length, value.Buffer, value.Length);\n            length = new_length;\n        }\n\n        void String_Builder_::Append_(String_Builder_ const * value)\n        {\n            int new_length = length + value->length;\n            ensure_capacity(new_length);\n            std::memcpy(buffer+length, value->buffer, value->length);\n            length = new_length;\n        }\n\n        void String_Builder_::AppendLine_(str const & value)\n        {\n            int new_length = length + value.Length + 1;\n            ensure_capacity(new_length);\n            std::memcpy(buffer+length, value.Buffer, value.Length);\n            buffer[new_length-1] = '\\n';\n            length = new_length;\n        }\n\n        void String_Builder_::AppendLine_()\n        {\n            int new_length = length + 1;\n            ensure_capacity(new_length);\n            buffer[new_length-1] = '\\n';\n            length = new_length;\n        }\n\n        void String_Builder_::Remove_(i32 start, i32 length)\n        {\n            if(start.value >= this->length)\n                throw std::runtime_error(\"String_Builder.Remove() start >= length\");\n\n            int end = start.value + length.value;\n            if(end > this->length) // greater than because end is one past the end of the remove\n                throw std::runtime_error(\"String_Builder.Remove() end > length\");\n\n            std::memmove(buffer+start.value, buffer+end, this->length-end);\n            this->length -= length.value;\n        }\n\n        void String_Builder_::Remove_(i32 start)\n        {\n            if(start.value >= length)\n                throw std::runtime_error(\"String_Builder.Remove() start >= length\");\n\n            length = start.value;\n        }\n\n        str String_Builder_::ToString_()\n        {\n            str result(length, buffer);\n            // give up ownership of buffer\n            buffer = 0;\n            length = 0;\n            capacity = 0;\n            return result;\n        }\n    }\n}\n"));
		resource_manager_->AddResource(p_string("RuntimeLibrary.hpp"), p_string("// On windows this disables warnings about using fopen_s instead of fopen\n// It must be defined before including the headers.\n#define _CRT_SECURE_NO_WARNINGS\n#include <cstring>\n#include <cstdio>\n#include <cstdint>\n#include <stdexcept>\n#include <string>\n\n// -----------------------------------------------------------------------------\n// Primitive Types\n// -----------------------------------------------------------------------------\n\n// `bool`\nstruct bit\n{\n    bool value;\n};\n\n// `true`\nstatic const bit bit_true = { true };\n// `false`\nstatic const bit bit_false = { false };\n\n// Function used in conditions to make them take `bit`\ninline bool cond(bit cond) { return cond.value; }\n\n// Used by runtime for converting to bit\ninline bit bit_from(bool v) { return bit { v }; }\n\n// Wrap a bit operation that is bool based\ninline bit bit_op(bool v) { return bit { v }; }\n// Convert the arguments of a logical operation to bool\ninline bool bit_arg(bit v) { return v.value; }\ninline bit bit_not(bit v) { return bit { !v.value }; }\n\n// `never`\nstruct never\n{\n};\n\n// `never?`\nstruct o_never\n{\n    // TODO get rid of this conversion operator when compiler emits conversions\n    template<class T>\n    operator T*_Nullable() const { return static_cast<T*>(0); }\n};\n\nstatic const o_never none;\n\ntemplate<typename T>\nstruct p_optional final\n{\nprivate:\n    bool hasValue;\n    union\n    {\n        T data;\n    };\n\npublic:\n    // TODO make this constructor explicit\n    p_optional(T const & value) : data(value), hasValue(true) {}\n    // TODO get rid of this conversion operator when compiler emits conversions\n    p_optional(o_never none) : hasValue(false) {}\n    auto has_value() const -> bit { return bit_from(hasValue); }\n    auto value() const -> T { return data; }\n\n    T & operator->()\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n    T const & operator->() const\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n    T & operator* ()\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n    T const & operator* () const\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n};\n\nstruct u32;\n\n// `int`\nstruct i32\n{\n    // Runtime Use Members\n    std::int32_t value;\n\n    explicit i32() = default;\n    explicit i32(std::int32_t value): value(value) {}\n\n    i32 *_Nonnull operator->() { return this; }\n    i32 const *_Nonnull operator->() const { return this; }\n    i32 & operator* () { return *this; }\n    i32 const & operator* () const { return *this; }\n\n    // Hack to support conversion of uint to int for now\n    i32(u32 value);\n\n    // Adamant Members\n    static auto construct() -> i32 { return i32(0); }\n    static auto copy(i32 const & other) -> i32 { return other; }\n    void op_add_assign(i32 other) { this->value += other.value; }\n    void op_subtract_assign(i32 other) { this->value -= other.value; }\n    bit op_less_than(i32 other) const { return bit_from(this->value < other.value); }\n    bit op_less_than_or_equal(i32 other) const { return bit_from(this->value <= other.value); }\n    bit op_greater_than(i32 other) const { return bit_from(this->value > other.value); }\n    bit op_greater_than_or_equal(i32 other) const { return bit_from(this->value >= other.value); }\n    i32 op_add(i32 other) const { return i32(this->value + other.value); }\n    i32 op_subtract(i32 other) const { return i32(this->value - other.value); }\n    i32 op_negate() const { return i32(-this->value); }\n    i32 op_multiply(i32 other) const { return i32(this->value * other.value); }\n    i32 op_divide(i32 other) const { return i32(this->value / other.value); }\n    i32 op_remainder(i32 other) const { return i32(this->value % other.value); }\n    i32 op_magnitude() const { if(this->value==INT32_MIN) throw std::overflow_error(\"Can't take |int.Min|\"); return i32(this->value < 0 ? -this->value : this->value); }\n\n    // Hack because we don't support as correctly yet\n    u32 AsUInt_() const;\n};\n\n// `uint`\nstruct u32\n{\n    // Runtime Use Members\n    std::uint32_t value;\n\n    explicit u32() = default;\n    explicit u32(std::uint32_t value): value(value) {}\n\n    u32 *_Nonnull operator->() { return this; }\n    u32 const *_Nonnull operator->() const { return this; }\n    u32 & operator* () { return *this; }\n    u32 const & operator* () const { return *this; }\n\n    // Hack to support conversion of int to uint for now\n    u32(i32 value): value(value.value) {}\n\n    // Adamant Members\n    static auto construct() -> u32 { return u32(0); }\n    void op_add_assign(u32 other) { this->value += other.value; }\n    void op_subtract_assign(u32 other) { this->value -= other.value; }\n    bit op_less_than(u32 other) const { return bit_from(this->value < other.value); }\n    bit op_less_than_or_equal(u32 other) const { return bit_from(this->value <= other.value); }\n    bit op_greater_than(u32 other) const { return bit_from(this->value > other.value); }\n    bit op_greater_than_or_equal(u32 other) const { return bit_from(this->value >= other.value); }\n    u32 op_add(u32 other) const { return u32(this->value + other.value); }\n    u32 op_subtract(u32 other) const { return u32(this->value - other.value); }\n};\n\ninline i32::i32(u32 value)\n    : value(value.value)\n{\n}\n\nstruct cp\n{\n    std::uint32_t value;\n\n    // Runtime Use Members\n    explicit cp() = default;\n    explicit cp(char value): value(value) {}\n\n    cp *_Nonnull operator->() { return this; }\n    cp const *_Nonnull operator->() const { return this; }\n    cp & operator* () { return *this; }\n    cp const & operator* () const { return *this; }\n\n    // Adamant Members\n    static auto construct() -> cp { return cp('\\0'); }\n    // TODO: Not sure code_point should support these operations\n    bit op_less_than(cp other) const { return bit_from(this->value < other.value); }\n    bit op_less_than_or_equal(cp other) const { return bit_from(this->value <= other.value); }\n    bit op_greater_than(cp other) const { return bit_from(this->value > other.value); }\n    bit op_greater_than_or_equal(cp other) const { return bit_from(this->value >= other.value); }\n};\n\nchar cp_to_char(cp v);\n\nstruct str\n{\npublic:\n    // Runtime Use Members\n    char const *_Nonnull Buffer;\n    int Length;\n\n    explicit str() = default;\n    explicit str(char const *_Nonnull s);\n    explicit str(int length, char const *_Nonnull s);\n    char const *_Nonnull cstr() const;\n    str const *_Nonnull operator->() const { return this; }\n    str const & operator* () const { return *this; }\n\n    typedef char const *_Nonnull const_iterator;\n    const_iterator begin() const { return &Buffer[0]; }\n    const_iterator end() const { return &Buffer[Length]; }\n\n    // Hack to support conversion of int and code_point to strings for now\n    str(i32 other);\n    str(cp other);\n    explicit str(bit other);\n\n    // Adamant Members\n    static auto construct() -> str { str self; self.Length = 0; self.Buffer = 0; return self; }\n    static auto construct(str value) -> str { return value; }\n    static auto construct(cp c, i32 repeat) -> str;\n    // TODO ByteLength should be a property\n    i32 ByteLength_() const { return i32(Length); }\n\n    str Substring_(i32 start, i32 length) const;\n    str Substring_(i32 start) const { return Substring_(start, i32(Length-start.value)); }\n    str Replace_(str oldValue, str newValue) const;\n    i32 LastIndexOf_(cp c) const;\n    i32 index_of_(cp c) const;\n\n    // TODO check index bounds\n    cp op_Element(i32 const index) const { return cp(Buffer[index.value]); }\n    str op_add(str const & value) const;\n    str op_add(bit value) const { return this->op_add(str(value)); }\n    bit op_less_than(str other) const;\n    bit op_less_than_or_equal(str other) const;\n    bit op_greater_than(str other) const;\n    bit op_greater_than_or_equal(str other) const;\n};\n\n// -----------------------------------------------------------------------------\n// Operators\n// -----------------------------------------------------------------------------\n\ninline auto equal_op(bit lhs, bit rhs) -> bit\n{\n    return bit_from(lhs.value == rhs.value);\n}\ninline auto equal_op(p_optional<bit> lhs, p_optional<bit> rhs) -> bit\n{\n    if(lhs.has_value().value)\n        return bit_op(bit_arg(rhs.has_value()) && bit_arg(equal_op(lhs.value(), rhs.value())));\n    else\n        return bit_not(rhs.has_value());\n}\n\ninline auto equal_op(i32 lhs, i32 rhs) -> bit\n{\n    return bit_from(lhs.value == rhs.value);\n}\ninline auto equal_op(p_optional<i32> lhs, p_optional<i32> rhs) -> bit\n{\n    if(lhs.has_value().value)\n        return bit_op(bit_arg(rhs.has_value()) && bit_arg(equal_op(lhs.value(), rhs.value())));\n    else\n        return bit_not(rhs.has_value());\n}\n\ninline auto equal_op(o_never lhs, o_never rhs) -> bit\n{\n    return bit_true;\n}\n\ninline auto equal_op(cp lhs, cp rhs) -> bit\n{\n    return bit_from(lhs.value == rhs.value);\n}\n\nauto equal_op(str lhs, str rhs) -> bit;\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto equal_op(T const *_Nullable lhs, o_never rhs) -> bit\n{\n    return bit_from(lhs == 0);\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto equal_op(o_never lhs, T const *_Nullable rhs) -> bit\n{\n    return bit_from(0 == rhs);\n}\n\n// TODO Get rid of this ability\ntemplate<typename T>\ninline auto equal_op(T const *_Nullable lhs, T const *_Nullable const & rhs) -> bit\n{\n    return bit_from(lhs == 0);\n}\n\ninline auto not_equal_op(i32 lhs, i32 rhs) -> bit\n{\n    return bit_from(lhs.value != rhs.value);\n}\ninline auto not_equal_op(p_optional<i32> lhs, p_optional<i32> rhs) -> bit\n{\n    if(lhs.has_value().value)\n        return bit_op(bit_arg(bit_not(rhs.has_value())) || bit_arg(not_equal_op(lhs.value(), rhs.value())));\n    else\n        return rhs.has_value();\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto not_equal_op(T lhs, T  rhs) -> bit\n{\n    return bit_not(equal_op(lhs, rhs));\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto not_equal_op(T const *_Nullable lhs, o_never rhs) -> bit\n{\n    return bit_from(lhs != 0);\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto not_equal_op(o_never lhs, T const *_Nullable rhs) -> bit\n{\n    return bit_from(0 != rhs);\n}\n\n// -----------------------------------------------------------------------------\n// Standard Library\n// -----------------------------------------------------------------------------\n// Parts of the standard library that are currently implemented in the runtime.\n\n// A placeholder function until we get proper exceptions implemented\n_Noreturn inline void THROW_EXCEPTION_(const str& value)\n{\n    throw std::runtime_error(value.cstr());\n}\n\n\ninline void assert(const bit condition, char const *_Nonnull code, const str message, char const *_Nonnull file, const std::int32_t line)\n{\n    if(!condition.value)\n        throw std::runtime_error(\n            str(\"Assertion failed: \").op_add(str(code)).op_add(str(\", \")).op_add(message)\n            .op_add(str(\", file \")).op_add(str(file)).op_add(str(\", line \")).op_add(i32(line)).cstr());\n}\n\n#define assert_(condition, message) assert(condition, #condition, message, __FILE__, __LINE__)\n\n\n_Noreturn inline void NOT_IMPLEMENTED(const str message, char const *_Nonnull function, char const *_Nonnull file, const std::int32_t line)\n{\n    throw std::runtime_error(\n        str(\"Function \").op_add(str(function))\n        .op_add(str(\" not yet implemented, \")).op_add(message).op_add(str(\", \")).op_add(str(file)).op_add(str(\", line \")).op_add(i32(line)).cstr());\n}\n\n#define NOT_IMPLEMENTED_(message) NOT_IMPLEMENTED(message, __func__, __FILE__, __LINE__)\n\n\n_Noreturn inline void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const std::int32_t line)\n{\n    throw std::runtime_error(\n        str(\"Reached \\\"UNREACHABLE\\\" statement in function \").op_add(str(function))\n        .op_add(str(\", \")).op_add(str(file)).op_add(str(\", line \")).op_add(i32(line)).cstr());\n}\n\n#define UNREACHABLE_() UNREACHABLE(__func__, __FILE__, __LINE__)\n\nclass ResourceManager\n{\npublic:\n    str const & GetString_(str resourceName);\n    void AddResource(str name, str value);\n};\n\nextern ResourceManager *_Nonnull const resource_manager_;\n\nvoid debug_write_(str value);\nvoid debug_write_line_(str value);\nvoid debug_write_line_();\n\nnamespace system_\n{\n    namespace Collections_\n    {\n        template<typename T>\n        class List_\n        {\n        private:\n            T *_Nonnull values;\n            int length;\n            int capacity;\n\n        public:\n            // Runtime Use Members\n            typedef T const *_Nonnull const_iterator;\n            const_iterator begin() const { return values; }\n            const_iterator end() const { return &values[length]; }\n\n            // Adamant Members\n            List_ *_Nonnull construct() { values = 0; length = 0; capacity = 0; return this; }\n            void Add_(T value) { add_(value); }\n            void Clear_() { clear_(); }\n            void add_(T value);\n            void clear_() { length = 0; }\n            i32 op_magnitude() const { return i32(length); }\n            T const & op_Element(i32 const index) const;\n        };\n\n        template<typename T>\n        void List_<T>::add_(T value)\n        {\n            if(length >= capacity)\n            {\n                int newCapacity = capacity == 0 ? 16 : capacity * 2;\n                // Allocate uninitalized buffer (note `sizeof(char) == 1` always)\n                // Needed if T is a value type to avoid needing a default constructor\n                T* newValues = (T*)new char[newCapacity * sizeof(T)];\n                std::memcpy(newValues, values, length * sizeof(T));\n                values = newValues;\n                capacity = newCapacity;\n            }\n            values[length] = value;\n            length++;\n        }\n\n        template<typename T>\n        T const & List_<T>::op_Element(i32 const index) const\n        {\n            if(index.value < 0 || index.value >= length)\n                throw std::out_of_range(\"List index out of bounds\");\n            return values[index.value];\n        }\n    }\n\n    namespace Console_\n    {\n        class Console_\n        {\n        public:\n            void Write_(str value);\n            void WriteLine_(str value);\n            void WriteLine_();\n        };\n\n        class Arguments_\n        {\n        private:\n            str *_Nonnull args;\n        public:\n            // Runtime Use Members\n            typedef str const *_Nonnull const_iterator;\n\n            Arguments_(int argc, char const *_Nonnull const *_Nonnull argv);\n            const_iterator begin() const { return &args[0]; }\n            const_iterator end() const { return &args[Count]; }\n\n            const int Count;\n\n            // Adamant Members\n            i32 op_magnitude() const { return i32(Count); }\n            str const & op_Element(i32 const index) const\n            {\n                if(index.value < 0 || index.value >= Count)\n                    throw std::out_of_range(\"Argument index out of bounds\");\n                return args[index.value];\n            }\n        };\n    }\n\n    namespace IO_\n    {\n        class File_Reader_\n        {\n        private:\n            std::FILE *_Nonnull file;\n\n        public:\n            File_Reader_ *_Nonnull construct(const str& fileName);\n            str ReadToEndSync_();\n            void Close_();\n        };\n\n        class File_Writer_\n        {\n        private:\n            std::FILE *_Nonnull file;\n\n        public:\n            File_Writer_ *_Nonnull construct(const str& fileName);\n            void Write_(const str& value);\n            void Close_();\n        };\n    }\n\n    namespace Text_\n    {\n        class String_Builder_\n        {\n        private:\n            char *_Nullable buffer;\n            int capacity;\n            int length;\n            void ensure_capacity(int needed);\n        public:\n            // Runtime Use Members\n            String_Builder_(): buffer(0), capacity(0), length(0) { }\n\n            // Adamant Members\n            String_Builder_ *_Nonnull construct() { return this; }\n            String_Builder_ *_Nonnull construct(str const & value);\n            String_Builder_ *_Nonnull construct_with_capacity(i32 capacity);\n            // TODO byte_length_ should be a property\n            i32 byte_length_() const { return i32(length); }\n            void Append_(str const & value);\n            void Append_(String_Builder_ const *_Nonnull value);\n            void AppendLine_(str const& value);\n            void AppendLine_();\n            void Remove_(i32 start, i32 length);\n            void Remove_(i32 start);\n            str ToString_();\n        };\n    }\n}\n\nnamespace System_ = system_;\n"));

		return Main_(new ::System_::Console_::Console_(), new ::System_::Console_::Arguments_(argc, argv)).value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
