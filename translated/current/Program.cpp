#include "RuntimeLibrary.h"

// Type Declarations
class Line_Info_;
class Source_Text_;
class Text_Line_;
class Text_Position_;
class Text_Span_;
class Source_File_Builder_;
class Binding_Scope_;
class Compilation_Unit_;
class Package_;
struct Package_Reference_;
class Primitives_Package_Builder_;
class Runtime_Library_Package_Builder_;
class Semantic_Analyzer_;
class Semantic_Binder_;
class Semantic_Builder_;
class Semantic_Node_;
class Compilation_Unit_Parser_;
class Lexer_;
class Parser_;
class Syntax_Node_;
class Syntax_Tree_;
class Token_Stream_;
class Token_Type_;
class Diagnostic_;
class Emitter_;
class Namespace_Name_;
class Package_Name_;
class Symbol_;
class Type_;

// Function Declarations
auto compile_(::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const sources_) -> ::Package_ const *_Nonnull;
auto write_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_) -> void;
auto has_errors_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_) -> p_bool;
auto Main_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Console_::Arguments_ const *_Nonnull const args_) -> p_int;
auto read_source_(p_string const path_) -> ::Source_Text_ const *_Nonnull;
auto format_error_(p_string const message_) -> p_string;
auto new_syntax_node_missing_(p_int const type_, ::Source_Text_ const *_Nonnull const source_, p_uint const start_) -> ::Syntax_Node_ const *_Nonnull;
auto new_Syntax_Node_Skipped_(::Syntax_Node_ const *_Nonnull const skipped_) -> ::Syntax_Node_ const *_Nonnull;
auto new_Syntax_Node_Skipped_(::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull const skipped_) -> ::Syntax_Node_ const *_Nonnull;
auto global_namespace_() -> ::Namespace_Name_ const *_Nonnull;

// Class Declarations

class Line_Info_
{
public:
	p_bool op_Equal(Line_Info_ const * other) const { return this == other; }
	p_bool op_NotEqual(Line_Info_ const * other) const { return this != other; }
private:
	::Source_Text_ const *_Nonnull source_;
	::System_::Collections_::List_<p_int> const *_Nonnull lineStarts_;
public:
	auto construct(::Source_Text_ const *_Nonnull const source_, ::System_::Collections_::List_<p_int> const *_Nonnull const lineStarts_) -> ::Line_Info_*;
	auto Count_() const -> p_int;
	auto get_(p_int const lineNumber_) const -> ::Text_Line_ const *_Nonnull;
	auto LineNumber_(p_int const offset_) const -> p_int;
};

class Source_Text_
{
public:
	p_bool op_Equal(Source_Text_ const * other) const { return this == other; }
	p_bool op_NotEqual(Source_Text_ const * other) const { return this != other; }
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
	p_bool op_Equal(Text_Line_ const * other) const { return this == other; }
	p_bool op_NotEqual(Text_Line_ const * other) const { return this != other; }
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
	p_bool op_Equal(Text_Position_ const * other) const { return this == other; }
	p_bool op_NotEqual(Text_Position_ const * other) const { return this != other; }
	p_int Offset_;
	p_int Line_;
	p_int Column_;
	auto construct(p_int const offset_, p_int const line_, p_int const column_) -> ::Text_Position_*;
};

class Text_Span_
{
public:
	p_bool op_Equal(Text_Span_ const * other) const { return this == other; }
	p_bool op_NotEqual(Text_Span_ const * other) const { return this != other; }
	p_int start_;
	p_int byte_length_;
	auto construct(p_int const start_, p_int const length_) -> ::Text_Span_*;
	auto End_() const -> p_int;
};

class Source_File_Builder_
{
public:
	p_bool op_Equal(Source_File_Builder_ const * other) const { return this == other; }
	p_bool op_NotEqual(Source_File_Builder_ const * other) const { return this != other; }
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

class Binding_Scope_
{
public:
	p_bool op_Equal(Binding_Scope_ const * other) const { return this == other; }
	p_bool op_NotEqual(Binding_Scope_ const * other) const { return this != other; }
private:
	::Binding_Scope_ const *_Nullable containing_scope_;
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull symbols_;
public:
	auto construct(::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const symbols_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const primitives_) -> ::Binding_Scope_*;
	auto construct(::Binding_Scope_ const *_Nonnull const containing_scope_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const symbols_) -> ::Binding_Scope_*;
	auto lookup_(p_string const name_) const -> ::Symbol_ const *_Nullable;
	auto lookup_special_(p_string const name_) const -> ::Symbol_ const *_Nullable;
	auto lookup_package_(p_string const name_) const -> ::Symbol_ const *_Nullable;
	auto lookup_(p_string const name_, p_int const kind_) const -> ::Symbol_ const *_Nullable;
};

class Compilation_Unit_
{
public:
	p_bool op_Equal(Compilation_Unit_ const * other) const { return this == other; }
	p_bool op_NotEqual(Compilation_Unit_ const * other) const { return this != other; }
	auto construct() -> ::Compilation_Unit_* { return this; }
};

class Package_
{
public:
	p_bool op_Equal(Package_ const * other) const { return this == other; }
	p_bool op_NotEqual(Package_ const * other) const { return this != other; }
	::Package_Name_ const *_Nonnull name_;
	::System_::Collections_::List_<::Package_Reference_> const *_Nonnull references_;
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull compilation_units_;
	::Symbol_ const *_Nonnull symbol_;
	auto construct(::Package_Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Package_Reference_> const *_Nonnull const references_, ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull const compilation_units_, ::Symbol_ const *_Nonnull const symbol_) -> ::Package_*;
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
	p_bool op_Equal(Primitives_Package_Builder_ const * other) const { return this == other; }
	p_bool op_NotEqual(Primitives_Package_Builder_ const * other) const { return this != other; }
	auto build_() const -> ::Package_ const *_Nonnull;
private:
	auto build_primitive_symbols_(::Package_Name_ const *_Nonnull const package_) const -> ::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull;
	static auto build_primitive_(p_string const name_, ::Package_Name_ const *_Nonnull const package_, ::Namespace_Name_ const *_Nonnull const namespace_) -> ::Symbol_ const *_Nonnull;
	static auto build_fixed_point_primitives_(::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_, p_int const bits_, ::Package_Name_ const *_Nonnull const package_, ::Namespace_Name_ const *_Nonnull const namespace_) -> void;
public:
	auto construct() -> ::Primitives_Package_Builder_* { return this; }
};

class Runtime_Library_Package_Builder_
{
public:
	p_bool op_Equal(Runtime_Library_Package_Builder_ const * other) const { return this == other; }
	p_bool op_NotEqual(Runtime_Library_Package_Builder_ const * other) const { return this != other; }
	auto construct() -> ::Runtime_Library_Package_Builder_* { return this; }
};

class Semantic_Analyzer_
{
public:
	p_bool op_Equal(Semantic_Analyzer_ const * other) const { return this == other; }
	p_bool op_NotEqual(Semantic_Analyzer_ const * other) const { return this != other; }
	static auto analyze_(::Syntax_Node_ const *_Nonnull const package_syntax_) -> ::Package_ const *_Nonnull;
	auto construct() -> ::Semantic_Analyzer_* { return this; }
};

class Semantic_Binder_
{
public:
	p_bool op_Equal(Semantic_Binder_ const * other) const { return this == other; }
	p_bool op_NotEqual(Semantic_Binder_ const * other) const { return this != other; }
	auto bind_(::Package_ const *_Nonnull const package_) const -> void;
private:
	auto bind_(::Semantic_Node_ *_Nonnull const node_, ::Binding_Scope_ const *_Nonnull const scope_) const -> void;
	auto bind_type_name_(::Semantic_Node_ *_Nonnull const node_, ::Binding_Scope_ const *_Nonnull const scope_) const -> void;
	auto bind_constructor_name_(::Semantic_Node_ *_Nonnull const node_, ::Binding_Scope_ const *_Nonnull const scope_) const -> void;
	static auto add_resolution_error_(::Semantic_Node_ const *_Nonnull const node_) -> void;
public:
	auto construct() -> ::Semantic_Binder_* { return this; }
};

class Semantic_Builder_
{
public:
	p_bool op_Equal(Semantic_Builder_ const * other) const { return this == other; }
	p_bool op_NotEqual(Semantic_Builder_ const * other) const { return this != other; }
	auto build_symbols_(::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull const compilation_units_) const -> ::Symbol_ const *_Nonnull;
private:
	auto build_symbols_(::Symbol_ const *_Nonnull const parent_, ::Semantic_Node_ *_Nonnull const node_) const -> void;
	auto build_function_symbols_(::Symbol_ const *_Nonnull const parent_, ::Semantic_Node_ *_Nonnull const function_, ::Symbol_ const *_Nonnull const symbol_) const -> void;
	auto build_runtime_library_symbols_(::Symbol_ const *_Nonnull const package_) const -> void;
	static auto build_resource_manager_(::Symbol_ const *_Nonnull const parent_) -> void;
	static auto build_(::Symbol_ const *_Nonnull const parent_, p_string const name_, p_int const declaration_kind_) -> ::Symbol_ *_Nonnull;
	static auto build_function_(::Symbol_ const *_Nonnull const parent_, p_string const name_) -> void;
public:
	auto construct() -> ::Semantic_Builder_* { return this; }
};

class Semantic_Node_
{
public:
	p_bool op_Equal(Semantic_Node_ const * other) const { return this == other; }
	p_bool op_NotEqual(Semantic_Node_ const * other) const { return this != other; }
	::Syntax_Node_ const *_Nonnull syntax_;
	p_int kind_;
	p_bool is_missing_;
	::Source_Text_ const *_Nonnull source_;
	p_uint start_;
	p_uint byte_length_;
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull children_;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull node_diagnostics_;
	::Symbol_ const *_Nullable symbol_;
	::Type_ const *_Nullable type_;
	auto construct(::Syntax_Node_ const *_Nonnull const syntax_) -> ::Semantic_Node_*;
	auto get_text_span_() const -> ::Text_Span_ const *_Nonnull;
	auto get_text_() const -> p_string;
	auto bind_symbol_(::Symbol_ const *_Nonnull const symbol_) -> void;
	auto bind_type_(::Type_ const *_Nonnull const type_) -> void;
	auto first_child_(p_int const kind_) const -> ::Semantic_Node_ *_Nullable;
	auto children_of_kind_(p_int const kind_) const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull;
	auto members_() const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull;
	auto statements_() const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull;
	auto parameters_() const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull;
	auto has_child_(p_int const kind_) const -> p_bool;
	auto add_(::Diagnostic_ const *_Nonnull const diagnostic_) const -> void;
	auto all_diagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull;
public:
	auto collection_diagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void;
public:
	auto is_value_type_() const -> p_bool;
};

class Compilation_Unit_Parser_
{
public:
	p_bool op_Equal(Compilation_Unit_Parser_ const * other) const { return this == other; }
	p_bool op_NotEqual(Compilation_Unit_Parser_ const * other) const { return this != other; }
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
	p_bool op_Equal(Lexer_ const * other) const { return this == other; }
	p_bool op_NotEqual(Lexer_ const * other) const { return this != other; }
	auto analyze_(::Source_Text_ const *_Nonnull const source_) const -> ::Token_Stream_ *_Nonnull;
	auto construct() -> ::Lexer_* { return this; }
};

class Parser_
{
public:
	p_bool op_Equal(Parser_ const * other) const { return this == other; }
	p_bool op_NotEqual(Parser_ const * other) const { return this != other; }
	auto construct() -> ::Parser_*;
	auto ParsePackage_(::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const sources_) const -> ::Syntax_Node_ const *_Nonnull;
};

class Syntax_Node_
{
public:
	p_bool op_Equal(Syntax_Node_ const * other) const { return this == other; }
	p_bool op_NotEqual(Syntax_Node_ const * other) const { return this != other; }
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
	auto all_diagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull;
public:
	auto collection_diagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void;
};

class Syntax_Tree_
{
public:
	p_bool op_Equal(Syntax_Tree_ const * other) const { return this == other; }
	p_bool op_NotEqual(Syntax_Tree_ const * other) const { return this != other; }
	p_string path_;
	::Source_Text_ const *_Nonnull source_;
	::Syntax_Node_ const *_Nonnull root_;
	auto construct(p_string const path_, ::Source_Text_ const *_Nonnull const source_, ::Syntax_Node_ const *_Nonnull const root_) -> ::Syntax_Tree_*;
};

class Token_Stream_
{
public:
	p_bool op_Equal(Token_Stream_ const * other) const { return this == other; }
	p_bool op_NotEqual(Token_Stream_ const * other) const { return this != other; }
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
	p_bool op_Equal(Token_Type_ const * other) const { return this == other; }
	p_bool op_NotEqual(Token_Type_ const * other) const { return this != other; }
	auto construct() -> ::Token_Type_* { return this; }
};

class Diagnostic_
{
public:
	p_bool op_Equal(Diagnostic_ const * other) const { return this == other; }
	p_bool op_NotEqual(Diagnostic_ const * other) const { return this != other; }
	p_int Level_;
	p_int Phase_;
	::Source_Text_ const *_Nonnull source_;
	::Text_Span_ const *_Nonnull Span_;
	::Text_Position_ const *_Nonnull Position_;
	p_string Message_;
	auto construct(p_int const level_, p_int const phase_, ::Source_Text_ const *_Nonnull const source_, ::Text_Span_ const *_Nonnull const span_, p_string const message_) -> ::Diagnostic_*;
};

class Emitter_
{
public:
	p_bool op_Equal(Emitter_ const * other) const { return this == other; }
	p_bool op_NotEqual(Emitter_ const * other) const { return this != other; }
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
	static auto convert_type_name_(::Semantic_Node_ const *_Nonnull const type_) -> p_string;
	static auto convert_reference_type_(p_bool const mutable_binding_, ::Semantic_Node_ const *_Nonnull type_, p_bool const nullable_, p_bool const mutable_value_) -> p_string;
	static auto convert_type_(p_bool const mutable_binding_, ::Semantic_Node_ const *_Nonnull type_, p_bool const optional_) -> p_string;
	static auto convert_type_(p_bool const mutable_binding_, ::Semantic_Node_ const *_Nonnull const type_) -> p_string;
	auto convert_parameter_list_(::Semantic_Node_ const *_Nonnull const parameter_list_, p_bool const is_main_function_) -> p_string;
	auto convert_parameter_list_(::Semantic_Node_ const *_Nonnull const parameter_list_) -> p_string;
	static auto convert_expression_(::Semantic_Node_ const *_Nonnull const syntax_, ::Source_File_Builder_ *_Nonnull const builder_) -> void;
	static auto convert_member_access_(::Semantic_Node_ const *_Nonnull const lhs_, ::Source_File_Builder_ *_Nonnull const builder_) -> void;
	auto emit_statement_(::Semantic_Node_ const *_Nonnull const statement_) -> void;
	auto emit_method_body_(::Semantic_Node_ const *_Nonnull const block_, p_bool const is_associated_function_) -> void;
	auto emit_constructor_body_(::Semantic_Node_ const *_Nonnull const block_, p_string const self_type_, p_bool const is_value_type_) -> void;
	auto emit_access_modifer_(p_int const current_access_level_, p_int const access_modifer_) -> p_int;
	auto emit_member_declaration_(::Semantic_Node_ const *_Nonnull const member_, p_string const class_name_, p_bool const is_value_type_, p_int const current_access_level_) -> p_int;
	auto emit_default_constructor_(p_string const type_name_, p_bool const is_value_type_, p_int const current_access_level_) -> void;
	auto emit_declaration_(::Semantic_Node_ const *_Nonnull const declaration_) -> void;
	auto emit_compilation_unit_(::Semantic_Node_ const *_Nonnull const unit_) -> void;
	auto emit_preamble_() -> void;
	auto emit_entry_point_adapter_() -> void;
};

class Namespace_Name_
{
public:
	p_bool op_Equal(Namespace_Name_ const * other) const { return this == other; }
	p_bool op_NotEqual(Namespace_Name_ const * other) const { return this != other; }
	::System_::Collections_::List_<p_string> const *_Nonnull segments_;
	auto construct(::System_::Collections_::List_<p_string> const *_Nonnull const segments_) -> ::Namespace_Name_*;
};

class Package_Name_
{
public:
	p_bool op_Equal(Package_Name_ const * other) const { return this == other; }
	p_bool op_NotEqual(Package_Name_ const * other) const { return this != other; }
	p_string text_;
	auto construct(p_string const text_) -> ::Package_Name_*;
};

class Symbol_
{
public:
	p_bool op_Equal(Symbol_ const * other) const { return this == other; }
	p_bool op_NotEqual(Symbol_ const * other) const { return this != other; }
	p_string name_;
	p_int kind_;
	p_bool is_primitive_;
	::Type_ const *_Nonnull type_;
	::Type_ const *_Nonnull declares_type_;
	::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull> *_Nonnull declarations_;
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull children_;
	auto construct(p_string const name_) -> ::Symbol_*;
	auto construct(p_string const name_, p_int const kind_) -> ::Symbol_*;
	auto construct(p_string const name_, p_int const kind_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const children_) -> ::Symbol_*;
	auto construct_primitive(p_string const name_, ::Type_ const *_Nonnull const declares_type_) -> ::Symbol_*;
	auto get_(p_string const name_, p_int const kind_) const -> ::Symbol_ const *_Nullable;
	auto declares_value_type_() const -> p_bool;
	auto get_type_() const -> ::Type_ const *_Nullable;
};

class Type_
{
public:
	p_bool op_Equal(Type_ const * other) const { return this == other; }
	p_bool op_NotEqual(Type_ const * other) const { return this != other; }
	p_int kind_;
	::Package_Name_ const *_Nonnull package_;
	::Namespace_Name_ const *_Nonnull namespace_;
	p_string name_;
	p_bool is_primitive_;
	p_bool is_value_type_;
	p_bool immutable_;
	auto construct(::Symbol_ const *_Nonnull const symbol_) -> ::Type_*;
	auto construct(::Package_Name_ const *_Nonnull const package_, ::Namespace_Name_ const *_Nonnull const namespace_, p_int const kind_, p_string const name_, p_bool const is_primitive_, p_bool const is_value_type_, p_bool const immutable_) -> ::Type_*;
	auto make_mutable_() const -> ::Type_ const *_Nonnull;
	auto make_immutable_() const -> ::Type_ const *_Nonnull;
};

// Global Definitions
p_int const Success_ = p_int(0);
p_int const UsageError_ = p_int(64);
p_int const DataError_ = p_int(65);
p_int const SkippedTokens_ = p_int(1).op_Negate();
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
p_int const IdentifierSymbol_ = p_int(0);
p_int const PackageSymbol_ = p_int(1);
p_int const SpecialSymbol_ = p_int(2);
p_int const ReferenceType_ = p_int(1);
p_int const ValueType_ = p_int(2);
p_int const NamespaceType_ = p_int(3);

// Definitions

auto compile_(::System_::Collections_::List_<::Source_Text_ const *_Nonnull> const *_Nonnull const sources_) -> ::Package_ const *_Nonnull
{
	::Parser_ const *_Nonnull const parser_ = (new ::Parser_())->construct();
	::Syntax_Node_ const *_Nonnull const packageSyntax_ = parser_->ParsePackage_(sources_);
	::Semantic_Analyzer_ const *_Nonnull const semanticAnalyzer_ = (new ::Semantic_Analyzer_())->construct();
	::Package_ const *_Nonnull const package_ = semanticAnalyzer_->analyze_(packageSyntax_);
	return package_;
}

auto write_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_) -> void
{
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(diagnostics_))
	{
		::Text_Position_ const *_Nonnull const position_ = diagnostic_->Position_;
		p_string severity_;
		if (diagnostic_->Level_->op_Equal(Info_).Value)
		{
			severity_ = p_string("Informational");
		}
		else if (diagnostic_->Level_->op_Equal(Warning_).Value)
		{
			severity_ = p_string("Warning");
		}
		else
		{
			severity_ = p_string("Error");
		}

		console_->WriteLine_(diagnostic_->source_->Path_->op_Add(p_string(":"))->op_Add(position_->Line_)->op_Add(p_string(":"))->op_Add(position_->Column_)->op_Add(p_string(" "))->op_Add(severity_)->op_Add(p_string(":")));
		console_->WriteLine_(p_string("  ").op_Add(diagnostic_->Message_));
	}
}

auto has_errors_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_) -> p_bool
{
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(diagnostics_))
	{
		if (diagnostic_->Level_->op_GreaterThanOrEqual(CompilationError_).Value)
		{
			return p_bool(true);
		}
	}

	return p_bool(false);
}

auto Main_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Console_::Arguments_ const *_Nonnull const args_) -> p_int
{
	::System_::Collections_::List_<p_string> *_Nonnull const sourceFilePaths_ = (new ::System_::Collections_::List_<p_string>())->construct();
	::System_::Collections_::List_<p_string> *_Nonnull const resourceFilePaths_ = (new ::System_::Collections_::List_<p_string>())->construct();
	p_string outputFilePath_ = p_string("");
	p_bool verbose_ = p_bool(false);
	p_int argType_ = p_int(0);
	for (p_string const arg_ : *(args_))
	{
		if (argType_.op_Equal(p_int(0)).Value)
		{
			if (arg_->op_Equal(p_string("-r")).Value)
			{
				argType_ = p_int(1);
			}
			else if (arg_->op_Equal(p_string("-o")).Value)
			{
				argType_ = p_int(2);
			}
			else if (LogicalOr(arg_->op_Equal(p_string("-v")), [&] { return arg_->op_Equal(p_string("--verbose")); }).Value)
			{
				verbose_ = p_bool(true);
			}
			else
			{
				sourceFilePaths_->Add_(arg_);
			}
		}
		else if (argType_.op_Equal(p_int(1)).Value)
		{
			resourceFilePaths_->Add_(arg_);
			argType_ = p_int(0);
		}
		else if (argType_.op_Equal(p_int(2)).Value)
		{
			outputFilePath_ = arg_;
			argType_ = p_int(0);
		}
	}

	if (verbose_.Value)
	{
		console_->WriteLine_(p_string("Adamant Compiler v0.1.0"));
	}

	if (LogicalOr(sourceFilePaths_->op_Magnitude()->op_Equal(p_int(0)), [&] { return outputFilePath_.op_Equal(p_string("")); }).Value)
	{
		console_->WriteLine_(p_string("Args: <Input File(s)> -o <OutputFile> -r <Resource File>"));
		return UsageError_;
	}

	::System_::Collections_::List_<::Source_Text_ const *_Nonnull> *_Nonnull const resources_ = (new ::System_::Collections_::List_<::Source_Text_ const *_Nonnull>())->construct();
	if (resourceFilePaths_->op_Magnitude()->op_GreaterThan(p_int(0)).Value)
	{
		if (verbose_.Value)
		{
			console_->WriteLine_(p_string("Reading Resources:"));
		}

		for (p_string const resourceFilePath_ : *(resourceFilePaths_))
		{
			if (verbose_.Value)
			{
				console_->WriteLine_(p_string("  ").op_Add(resourceFilePath_));
			}

			resources_->Add_(read_source_(resourceFilePath_));
		}
	}

	if (verbose_.Value)
	{
		console_->WriteLine_(p_string("Compiling:"));
	}

	::System_::Collections_::List_<::Source_Text_ const *_Nonnull> *_Nonnull const sources_ = (new ::System_::Collections_::List_<::Source_Text_ const *_Nonnull>())->construct();
	for (p_string const sourceFilePath_ : *(sourceFilePaths_))
	{
		if (verbose_.Value)
		{
			console_->WriteLine_(p_string("  ").op_Add(sourceFilePath_));
		}

		sources_->Add_(read_source_(sourceFilePath_));
	}

	::Package_ const *_Nonnull const package_ = compile_(sources_);
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull const diagnostics_ = package_->all_diagnostics_();
	write_(console_, diagnostics_);
	if (has_errors_(diagnostics_).Value)
	{
		return DataError_;
	}

	::Emitter_ *_Nonnull emitter_ = (new ::Emitter_())->construct(package_, resources_);
	p_string const translated_ = emitter_->Emit_();
	if (verbose_.Value)
	{
		console_->Write_(p_string("Output: "));
		console_->WriteLine_(outputFilePath_);
	}

	::System_::IO_::File_Writer_ *_Nonnull const outputFile_ = (new ::System_::IO_::File_Writer_())->construct(outputFilePath_);
	outputFile_->Write_(translated_);
	outputFile_->Close_();
	p_string outputDirPath_ = outputFilePath_;
	p_int index_ = outputDirPath_.LastIndexOf_(p_code_point('/'));
	if (index_.op_NotEqual(p_int(1).op_Negate()).Value)
	{
		outputDirPath_ = outputDirPath_.Substring_(p_int(0), index_.op_Add(p_int(1)));
	}

	index_ = outputDirPath_.LastIndexOf_(p_code_point('\\'));
	if (index_.op_NotEqual(p_int(1).op_Negate()).Value)
	{
		outputDirPath_ = outputDirPath_.Substring_(p_int(0), index_.op_Add(p_int(1)));
	}

	if (verbose_.Value)
	{
		console_->Write_(p_string("Outputting RuntimeLibrary to: "));
		console_->WriteLine_(outputDirPath_);
	}

	::System_::IO_::File_Writer_ *_Nonnull resourceFile_ = (new ::System_::IO_::File_Writer_())->construct(outputDirPath_.op_Add(p_string("RuntimeLibrary.h")));
	resourceFile_->Write_(resource_manager_->GetString_(p_string("RuntimeLibrary.h")));
	resourceFile_->Close_();
	resourceFile_ = (new ::System_::IO_::File_Writer_())->construct(outputDirPath_.op_Add(p_string("RuntimeLibrary.cpp")));
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
	return lineStarts_->op_Magnitude();
}

auto ::Line_Info_::get_(p_int const lineNumber_) const -> ::Text_Line_ const *_Nonnull
{
	auto self = this;
	p_int const index_ = lineNumber_->op_Subtract(p_int(1));
	p_int const start_ = lineStarts_->op_Element(index_);
	if (index_.op_Equal(lineStarts_->op_Magnitude()->op_Subtract(p_int(1))).Value)
	{
		return (new ::Text_Line_())->construct_spanning(source_, start_, source_->ByteLength_());
	}

	p_int const end_ = lineStarts_->op_Element(index_.op_Add(p_int(1)));
	return (new ::Text_Line_())->construct_spanning(source_, start_, end_);
}

auto ::Line_Info_::LineNumber_(p_int const offset_) const -> p_int
{
	auto self = this;
	p_int left_ = p_int(0);
	p_int right_ = lineStarts_->op_Magnitude()->op_Subtract(p_int(1));
	while (left_.op_LessThanOrEqual(right_).Value)
	{
		p_int const mid_ = left_.op_Add(right_.op_Subtract(left_)->op_Divide(p_int(2)));
		p_int const midLineStart_ = lineStarts_->op_Element(mid_);
		if (midLineStart_.op_LessThan(offset_).Value)
		{
			left_ = mid_.op_Add(p_int(1));
		}
		else if (midLineStart_.op_GreaterThan(offset_).Value)
		{
			right_ = mid_.op_Subtract(p_int(1));
		}
		else
		{
			return mid_.op_Add(p_int(1));
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
	if (index_.op_NotEqual(p_int(1).op_Negate()).Value)
	{
		name_ = name_.Substring_(index_.op_Add(p_int(1)));
	}

	index_ = name_.LastIndexOf_(p_code_point('\\'));
	if (index_.op_NotEqual(p_int(1).op_Negate()).Value)
	{
		name_ = name_.Substring_(index_.op_Add(p_int(1)));
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
	while (position_.op_LessThan(length_).Value)
	{
		p_code_point const c_ = Text_->op_Element(position_);
		position_.op_AddAssign(p_int(1));
		if (LogicalAnd(c_.op_GreaterThan(p_code_point('\r')), [&] { return c_.op_LessThanOrEqual(p_code_point('\x7F')); }).Value)
		{
			continue;
		}

		if (c_.op_Equal(p_code_point('\r')).Value)
		{
			if (LogicalAnd(position_.op_LessThan(length_), [&] { return Text_->op_Element(position_)->op_Equal(p_code_point('\n')); }).Value)
			{
				position_.op_AddAssign(p_int(1));
			}
		}
		else if (LogicalOr(LogicalOr(LogicalOr(c_.op_Equal(p_code_point('\n')), [&] { return c_.op_Equal(p_code_point('\x0B')); }), [&] { return c_.op_Equal(p_code_point('\f')); }), [&] { return c_.op_Equal(p_code_point('\x85')); }).Value)
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
	return Text_->ByteLength_();
}

auto ::Source_Text_::PositionOfStart_(::Text_Span_ const *_Nonnull const span_) const -> ::Text_Position_ const *_Nonnull
{
	auto self = this;
	p_int const offset_ = span_->start_;
	p_int const lineNumber_ = Lines_->LineNumber_(offset_);
	p_int const lineStart_ = Lines_->get_(lineNumber_)->start_;
	p_int column_ = offset_.op_Subtract(lineStart_)->op_Add(p_int(1));
	p_int i_ = lineStart_;
	while (i_.op_LessThan(offset_).Value)
	{
		if (Text_->op_Element(i_)->op_Equal(p_code_point('\t')).Value)
		{
			column_.op_AddAssign(p_int(3));
		}

		i_.op_AddAssign(p_int(1));
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
	self->byte_length_ = end_->op_Subtract(start_);
	return self;
}

auto ::Text_Line_::End_() const -> p_int
{
	auto self = this;
	return start_->op_Add(byte_length_);
}

auto ::Text_Position_::construct(p_int const offset_, p_int const line_, p_int const column_) -> ::Text_Position_*
{
	::Text_Position_* self = this;
	Offset_ = offset_;
	Line_ = line_;
	Column_ = column_;
	return self;
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
	return start_->op_Add(byte_length_);
}

auto format_error_(p_string const message_) -> p_string
{
	return p_string("<$ ").op_Add(message_)->op_Add(p_string(" $>"));
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
	if (firstElement_->op_Not().Value)
	{
		code_->AppendLine_();
		firstElement_ = p_bool(true);
		afterBlock_ = p_bool(false);
	}
}

auto ::Source_File_Builder_::StatementSeparatorLine_() -> void
{
	auto self = this;
	if (afterBlock_.Value)
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

auto ::Binding_Scope_::construct(::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const symbols_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const primitives_) -> ::Binding_Scope_*
{
	::Binding_Scope_* self = this;
	self->containing_scope_ = ::None;
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const scope_symbols_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	for (::Symbol_ const *_Nonnull const s_ : *(symbols_))
	{
		scope_symbols_->Add_(s_);
	}

	for (::Symbol_ const *_Nonnull const s_ : *(primitives_))
	{
		scope_symbols_->Add_(s_);
	}

	self->symbols_ = scope_symbols_;
	return self;
}

auto ::Binding_Scope_::construct(::Binding_Scope_ const *_Nonnull const containing_scope_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const symbols_) -> ::Binding_Scope_*
{
	::Binding_Scope_* self = this;
	self->containing_scope_ = containing_scope_;
	self->symbols_ = symbols_;
	return self;
}

auto ::Binding_Scope_::lookup_(p_string const name_) const -> ::Symbol_ const *_Nullable
{
	auto self = this;
	return lookup_(name_, IdentifierSymbol_);
}

auto ::Binding_Scope_::lookup_special_(p_string const name_) const -> ::Symbol_ const *_Nullable
{
	auto self = this;
	return lookup_(name_, SpecialSymbol_);
}

auto ::Binding_Scope_::lookup_package_(p_string const name_) const -> ::Symbol_ const *_Nullable
{
	auto self = this;
	return lookup_(name_, PackageSymbol_);
}

auto ::Binding_Scope_::lookup_(p_string const name_, p_int const kind_) const -> ::Symbol_ const *_Nullable
{
	auto self = this;
	for (::Symbol_ const *_Nonnull const symbol_ : *(symbols_))
	{
		if (LogicalAnd(symbol_->name_->op_Equal(name_), [&] { return symbol_->kind_->op_Equal(kind_); }).Value)
		{
			return symbol_;
		}
	}

	if (containing_scope_->op_NotEqual(::None).Value)
	{
		return containing_scope_->lookup_(name_, kind_);
	}

	return ::None;
}

auto ::Package_::construct(::Package_Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Package_Reference_> const *_Nonnull const references_, ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull const compilation_units_, ::Symbol_ const *_Nonnull const symbol_) -> ::Package_*
{
	::Package_* self = this;
	self->name_ = name_;
	self->references_ = references_;
	self->compilation_units_ = compilation_units_;
	self->symbol_ = symbol_;
	return self;
}

auto ::Package_::construct(::Package_Name_ const *_Nonnull const name_, ::System_::Collections_::List_<::Package_Reference_> const *_Nonnull const references_, ::System_::Collections_::List_<::Compilation_Unit_ const *_Nonnull> const *_Nonnull const compilation_units_, ::Symbol_ const *_Nonnull const symbol_) -> ::Package_*
{
	::Package_* self = this;
	self->name_ = name_;
	self->references_ = references_;
	self->compilation_units_ = ::None;
	self->symbol_ = symbol_;
	return self;
}

auto ::Package_::all_diagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	for (::Semantic_Node_ const *_Nonnull const compilation_unit_ : *(compilation_units_))
	{
		for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(compilation_unit_->all_diagnostics_()))
		{
			diagnostics_->Add_(diagnostic_);
		}
	}

	return diagnostics_;
}

auto ::Package_Reference_::construct(::Package_ const *_Nonnull const package_) -> ::Package_Reference_
{
	::Package_Reference_ self;
	self->name_ = package_->name_->text_;
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
	assert_(primitive_symbols_->op_Magnitude()->op_GreaterThan(p_int(0)), p_string("|primitive_symbols=").op_Add(primitive_symbols_->op_Magnitude()));
	::Symbol_ const *_Nonnull const package_symbol_ = (new ::Symbol_())->construct(name_->text_, PackageSymbol_, primitive_symbols_);
	assert_(package_symbol_->children_->op_Magnitude()->op_GreaterThan(p_int(0)), p_string("|package_symbol.children|=").op_Add(package_symbol_->children_->op_Magnitude()));
	return (new ::Package_())->construct(name_, references_, compilation_units_, package_symbol_);
}

auto ::Primitives_Package_Builder_::build_primitive_symbols_(::Package_Name_ const *_Nonnull const package_) const -> ::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull
{
	auto self = this;
	::Namespace_Name_ const *_Nonnull const global_ = global_namespace_();
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	symbols_->Add_(build_primitive_(p_string("void"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("never"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("bool"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("code_point"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("string"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("int8"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("int16"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("int"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("int64"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("int128"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("byte"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("uint16"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("uint"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("uint64"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("uint128"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("float32"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("float"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("float128"), package_, global_));
	build_fixed_point_primitives_(symbols_, p_int(8), package_, global_);
	build_fixed_point_primitives_(symbols_, p_int(16), package_, global_);
	build_fixed_point_primitives_(symbols_, p_int(32), package_, global_);
	build_fixed_point_primitives_(symbols_, p_int(64), package_, global_);
	symbols_->Add_(build_primitive_(p_string("decimal32"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("decimal"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("decimal128"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("size"), package_, global_));
	symbols_->Add_(build_primitive_(p_string("offset"), package_, global_));
	return symbols_;
}

auto ::Primitives_Package_Builder_::build_primitive_(p_string const name_, ::Package_Name_ const *_Nonnull const package_, ::Namespace_Name_ const *_Nonnull const namespace_) -> ::Symbol_ const *_Nonnull
{
	::Type_ const *_Nonnull const type_ = (new ::Type_())->construct(package_, namespace_, ValueType_, name_, p_bool(true), p_bool(true), p_bool(true));
	return (new ::Symbol_())->construct_primitive(name_, type_);
}

auto ::Primitives_Package_Builder_::build_fixed_point_primitives_(::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const symbols_, p_int const bits_, ::Package_Name_ const *_Nonnull const package_, ::Namespace_Name_ const *_Nonnull const namespace_) -> void
{
}

auto ::Semantic_Analyzer_::analyze_(::Syntax_Node_ const *_Nonnull const package_syntax_) -> ::Package_ const *_Nonnull
{
	if (package_syntax_->kind_->op_NotEqual(PackageNode_).Value)
	{
		THROW_EXCEPTION_(p_string("`Semantic_Analyzer.analyze(...)` called with node of type ").op_Add(package_syntax_->kind_));
	}

	::Package_Name_ const *_Nonnull const name_ = (new ::Package_Name_())->construct(p_string("default"));
	::Package_ const *_Nonnull const primitives_package_ = (new ::Primitives_Package_Builder_())->construct()->build_();
	::System_::Collections_::List_<::Package_Reference_> *_Nonnull const references_ = (new ::System_::Collections_::List_<::Package_Reference_>())->construct();
	references_->add_(::Package_Reference_::construct(primitives_package_));
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull const compilation_units_ = (new ::Semantic_Node_())->construct(package_syntax_)->children_;
	::Semantic_Builder_ const *_Nonnull const semantic_builder_ = (new ::Semantic_Builder_())->construct();
	::Symbol_ const *_Nonnull const package_symbol_ = semantic_builder_->build_symbols_(compilation_units_);
	::Package_ *_Nonnull const package_ = (new ::Package_())->construct(name_, references_, compilation_units_, package_symbol_);
	::Semantic_Binder_ const *_Nonnull const semantic_binder_ = (new ::Semantic_Binder_())->construct();
	semantic_binder_->bind_(package_);
	return package_;
}

auto ::Semantic_Binder_::bind_(::Package_ const *_Nonnull const package_) const -> void
{
	auto self = this;
	assert_(package_->references_->op_Magnitude()->op_GreaterThan(p_int(0)), p_string("package=").op_Add(package_->name_->text_));
	::Package_ const *_Nonnull const primitive_package_ = package_->references_->op_Element(p_int(0))->package_;
	assert_(primitive_package_->name_->text_->op_Equal(p_string("$primitives")), p_string("package name='").op_Add(primitive_package_->name_->text_)->op_Add(p_string("'")));
	::System_::Collections_::List_<::Symbol_ const *_Nonnull> const *_Nonnull const primitives_ = primitive_package_->symbol_->children_;
	assert_(primitives_->op_Magnitude()->op_GreaterThan(p_int(0)), p_string("|primitives|=").op_Add(primitives_->op_Magnitude()));
	::Binding_Scope_ const *_Nonnull const global_scope_ = (new ::Binding_Scope_())->construct(package_->symbol_->children_, primitives_);
	for (::Semantic_Node_ *_Nonnull const compilation_unit_ : *(package_->compilation_units_))
	{
		bind_(compilation_unit_, global_scope_);
	}
}

auto ::Semantic_Binder_::bind_(::Semantic_Node_ *_Nonnull const node_, ::Binding_Scope_ const *_Nonnull const scope_) const -> void
{
	auto self = this;
	if (node_->kind_->op_Equal(CompilationUnit_).Value)
	{
		for (::Semantic_Node_ *_Nonnull const child_ : *(node_->children_))
		{
			bind_(child_, scope_);
		}
	}
	else if (LogicalOr(node_->kind_->op_Equal(FunctionDeclaration_), [&] { return node_->kind_->op_Equal(MethodDeclaration_); }).Value)
	{
		::Semantic_Node_ *_Nonnull const parameters_ = node_->first_child_(ParameterList_);
		bind_(parameters_, scope_);
		::Semantic_Node_ *_Nonnull const return_type_ = node_->children_->op_Element(p_int(4));
		bind_type_name_(return_type_, scope_);
		::Binding_Scope_ const *_Nonnull const function_scope_ = (new ::Binding_Scope_())->construct(scope_, node_->symbol_->children_);
		::Semantic_Node_ *_Nonnull const body_ = node_->first_child_(Block_);
		bind_(body_, function_scope_);
	}
	else if (node_->kind_->op_Equal(ParameterList_).Value)
	{
		for (::Semantic_Node_ *_Nonnull const parameter_ : *(node_->children_of_kind_(Parameter_)))
		{
			bind_(parameter_, scope_);
		}
	}
	else if (node_->kind_->op_Equal(Parameter_).Value)
	{
		::Semantic_Node_ *_Nonnull const type_ = node_->children_->op_Element(node_->children_->op_Magnitude()->op_Subtract(p_int(1)));
		bind_type_name_(type_, scope_);
	}
	else if (LogicalOr(node_->kind_->op_Equal(ClassDeclaration_), [&] { return node_->kind_->op_Equal(StructDeclaration_); }).Value)
	{
		::Binding_Scope_ const *_Nonnull const type_scope_ = (new ::Binding_Scope_())->construct(scope_, node_->symbol_->children_);
		for (::Semantic_Node_ *_Nonnull const member_ : *(node_->members_()))
		{
			bind_(member_, type_scope_);
		}
	}
	else if (LogicalOr(node_->kind_->op_Equal(FieldDeclaration_), [&] { return node_->kind_->op_Equal(GlobalDeclaration_); }).Value)
	{
		::Semantic_Node_ *_Nonnull const variable_declaration_ = node_->first_child_(VariableDeclaration_);
		bind_(variable_declaration_, scope_);
	}
	else if (node_->kind_->op_Equal(ConstructorDeclaration_).Value)
	{
		::Semantic_Node_ *_Nonnull const parameters_ = node_->first_child_(ParameterList_);
		bind_(parameters_, scope_);
		::Binding_Scope_ const *_Nonnull const constructor_scope_ = (new ::Binding_Scope_())->construct(scope_, node_->symbol_->children_);
		::Semantic_Node_ *_Nonnull const body_ = node_->first_child_(Block_);
		bind_(body_, constructor_scope_);
	}
	else if (node_->kind_->op_Equal(VariableDeclaration_).Value)
	{
		::Semantic_Node_ *_Nonnull const identifier_ = node_->first_child_(Identifier_);
		assert_(identifier_->op_NotEqual(::None), p_string("for '").op_Add(node_->get_text_())->op_Add(p_string("'")));
		::Semantic_Node_ *_Nonnull const type_name_ = node_->children_->op_Element(p_int(3));
		bind_type_name_(type_name_, scope_);
		if (node_->children_->op_Magnitude()->op_Equal(p_int(6)).Value)
		{
			::Semantic_Node_ *_Nonnull const initalizer_ = node_->children_->op_Element(p_int(5));
			bind_(initalizer_, scope_);
		}

		identifier_->bind_type_(type_name_->type_);
		node_->bind_type_(type_name_->type_);
	}
	else if (node_->kind_->op_Equal(EnumDeclaration_).Value)
	{
	}
	else if (node_->kind_->op_Equal(Block_).Value)
	{
		for (::Semantic_Node_ *_Nonnull const statement_ : *(node_->statements_()))
		{
			bind_(statement_, scope_);
		}
	}
	else if (node_->kind_->op_Equal(LoopStatement_).Value)
	{
		bind_(node_->first_child_(Block_), scope_);
	}
	else if (node_->kind_->op_Equal(WhileStatement_).Value)
	{
		bind_(node_->children_->op_Element(p_int(1)), scope_);
		bind_(node_->first_child_(Block_), scope_);
	}
	else if (node_->kind_->op_Equal(DoWhileStatement_).Value)
	{
		bind_(node_->first_child_(Block_), scope_);
		bind_(node_->children_->op_Element(p_int(3)), scope_);
	}
	else if (node_->kind_->op_Equal(ForStatement_).Value)
	{
		bind_(node_->first_child_(VariableDeclaration_), scope_);
		bind_(node_->first_child_(Block_), scope_);
	}
	else if (node_->kind_->op_Equal(LocalDeclarationStatement_).Value)
	{
		::Semantic_Node_ *_Nonnull const variable_declaration_ = node_->first_child_(VariableDeclaration_);
		bind_(variable_declaration_, scope_);
		node_->bind_type_(variable_declaration_->type_);
	}
	else if (node_->kind_->op_Equal(IfStatement_).Value)
	{
		bind_(node_->children_->op_Element(p_int(1)), scope_);
		bind_(node_->first_child_(Block_), scope_);
		::Semantic_Node_ *_Nullable const else_clause_ = node_->first_child_(ElseClause_);
		if (else_clause_->op_NotEqual(::None).Value)
		{
			bind_(else_clause_, scope_);
		}
	}
	else if (node_->kind_->op_Equal(ElseClause_).Value)
	{
		::Semantic_Node_ *_Nullable const block_ = node_->first_child_(Block_);
		if (block_->op_NotEqual(::None).Value)
		{
			bind_(block_, scope_);
		}
		else
		{
			bind_(node_->first_child_(IfStatement_), scope_);
		}
	}
	else if (node_->kind_->op_Equal(ExpressionStatement_).Value)
	{
		bind_(node_->children_->op_Element(p_int(0)), scope_);
	}
	else if (node_->kind_->op_Equal(ReturnStatement_).Value)
	{
		::Semantic_Node_ *_Nonnull const child_ = node_->children_->op_Element(p_int(1));
		if (child_->kind_->op_NotEqual(Semicolon_).Value)
		{
			bind_(child_, scope_);
		}
	}
	else if (node_->kind_->op_Equal(NewExpression_).Value)
	{
		bind_constructor_name_(node_->children_->op_Element(p_int(1)), scope_);
		bind_(node_->children_->op_Element(p_int(2)), scope_);
	}
	else if (LogicalOr(LogicalOr(LogicalOr(node_->kind_->op_Equal(NotExpression_), [&] { return node_->kind_->op_Equal(ParenthesizedExpression_); }), [&] { return node_->kind_->op_Equal(MagnitudeExpression_); }), [&] { return node_->kind_->op_Equal(NegateExpression_); }).Value)
	{
		bind_(node_->children_->op_Element(p_int(1)), scope_);
	}
	else if (LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(node_->kind_->op_Equal(AssignmentExpression_), [&] { return node_->kind_->op_Equal(AndExpression_); }), [&] { return node_->kind_->op_Equal(OrExpression_); }), [&] { return node_->kind_->op_Equal(EqualExpression_); }), [&] { return node_->kind_->op_Equal(NotEqualExpression_); }), [&] { return node_->kind_->op_Equal(ComparisonExpression_); }), [&] { return node_->kind_->op_Equal(AddExpression_); }), [&] { return node_->kind_->op_Equal(SubtractExpression_); }), [&] { return node_->kind_->op_Equal(ElementAccessExpression_); }), [&] { return node_->kind_->op_Equal(RemainderExpression_); }), [&] { return node_->kind_->op_Equal(MultiplyExpression_); }), [&] { return node_->kind_->op_Equal(DivideExpression_); }).Value)
	{
		bind_(node_->children_->op_Element(p_int(0)), scope_);
		bind_(node_->children_->op_Element(p_int(2)), scope_);
	}
	else if (node_->kind_->op_Equal(MemberAccessExpression_).Value)
	{
		bind_(node_->children_->op_Element(p_int(0)), scope_);
	}
	else if (node_->kind_->op_Equal(InvocationExpression_).Value)
	{
		bind_(node_->children_->op_Element(p_int(0)), scope_);
		bind_(node_->children_->op_Element(p_int(1)), scope_);
	}
	else if (node_->kind_->op_Equal(ArgumentList_).Value)
	{
		for (::Semantic_Node_ *_Nonnull const child_ : *(node_->children_))
		{
			if (LogicalAnd(LogicalAnd(child_->kind_->op_NotEqual(LeftParen_), [&] { return child_->kind_->op_NotEqual(Comma_); }), [&] { return child_->kind_->op_NotEqual(RightParen_); }).Value)
			{
				bind_(child_, scope_);
			}
		}
	}
	else if (node_->kind_->op_Equal(IdentifierName_).Value)
	{
		if (node_->is_missing_.Value)
		{
			return;
		}

		p_string const name_ = node_->get_text_();
		::Symbol_ const *_Nonnull const symbol_ = scope_->lookup_(name_);
		if (symbol_->op_Equal(::None).Value)
		{
			add_resolution_error_(node_);
		}
		else
		{
			node_->bind_symbol_(symbol_);
			::Type_ const *_Nullable const type_ = symbol_->get_type_();
			if (type_->op_NotEqual(::None).Value)
			{
				node_->bind_type_(type_);
			}
		}
	}
	else if (LogicalOr(node_->kind_->op_Equal(TrueLiteralExpression_), [&] { return node_->kind_->op_Equal(FalseLiteralExpression_); }).Value)
	{
		node_->bind_type_(scope_->lookup_special_(p_string("bool"))->get_type_());
	}
	else if (node_->kind_->op_Equal(StringLiteralExpression_).Value)
	{
		node_->bind_type_(scope_->lookup_special_(p_string("string"))->get_type_());
	}
	else if (node_->kind_->op_Equal(CodePointLiteralExpression_).Value)
	{
		node_->bind_type_(scope_->lookup_special_(p_string("code_point"))->get_type_());
	}
	else if (node_->kind_->op_Equal(NumericLiteralExpression_).Value)
	{
		node_->bind_type_(scope_->lookup_special_(p_string("int"))->get_type_());
	}
	else if (node_->kind_->op_Equal(SelfExpression_).Value)
	{
	}
	else if (LogicalOr(LogicalOr(LogicalOr(node_->kind_->op_Equal(BreakStatement_), [&] { return node_->kind_->op_Equal(ContinueStatement_); }), [&] { return node_->kind_->op_Equal(NoneLiteralExpression_); }), [&] { return node_->kind_->op_Equal(EndOfFileToken_); }).Value)
	{
	}
	else
	{
		THROW_EXCEPTION_(p_string("`Semantic_Binder.bind()` unimplemented node type ").op_Add(node_->kind_));
	}
}

auto ::Semantic_Binder_::bind_type_name_(::Semantic_Node_ *_Nonnull const node_, ::Binding_Scope_ const *_Nonnull const scope_) const -> void
{
	auto self = this;
	if (node_->kind_->op_Equal(PredefinedType_).Value)
	{
		p_string const primitive_name_ = node_->children_->op_Element(p_int(0))->get_text_();
		::Symbol_ const *_Nonnull const symbol_ = scope_->lookup_special_(primitive_name_);
		if (symbol_->op_Equal(::None).Value)
		{
			THROW_EXCEPTION_(p_string("`Semantic_Binder.bind_type_name()` no symbol for primitive type ").op_Add(primitive_name_));
		}

		node_->bind_symbol_(symbol_);
		node_->bind_type_((new ::Type_())->construct(symbol_));
	}
	else if (node_->kind_->op_Equal(MutableType_).Value)
	{
		::Semantic_Node_ *_Nonnull const inner_type_node_ = node_->children_->op_Element(p_int(1));
		bind_type_name_(inner_type_node_, scope_);
		if (inner_type_node_->type_->op_Equal(::None).Value)
		{
			THROW_EXCEPTION_(p_string("`Semantic_Binder.bind_type_name()` no inner type for `").op_Add(node_->get_text_())->op_Add(p_string("` of kind `MutableType`")));
		}

		node_->bind_type_(inner_type_node_->type_->make_mutable_());
	}
	else if (node_->kind_->op_Equal(ImmutableType_).Value)
	{
		::Semantic_Node_ *_Nonnull const inner_type_node_ = node_->children_->op_Element(p_int(0));
		bind_type_name_(inner_type_node_, scope_);
		if (inner_type_node_->type_->op_Equal(::None).Value)
		{
			THROW_EXCEPTION_(p_string("`Semantic_Binder.bind_type_name()` no inner type for `").op_Add(node_->get_text_())->op_Add(p_string("` of kind `ImmutableType`")));
		}

		node_->bind_type_(inner_type_node_->type_->make_immutable_());
	}
	else if (node_->kind_->op_Equal(OptionalType_).Value)
	{
		::Semantic_Node_ *_Nonnull const inner_type_node_ = node_->children_->op_Element(p_int(0));
		bind_type_name_(inner_type_node_, scope_);
		if (inner_type_node_->type_->op_Equal(::None).Value)
		{
			THROW_EXCEPTION_(p_string("`Semantic_Binder.bind_type_name()` not inner type for `").op_Add(node_->get_text_())->op_Add(p_string("` of kind `OptionalType`")));
		}

		node_->bind_type_(inner_type_node_->type_->make_immutable_());
	}
	else if (node_->kind_->op_Equal(QualifiedName_).Value)
	{
		::Semantic_Node_ *_Nonnull const qualifier_ = node_->children_->op_Element(p_int(0));
		bind_type_name_(qualifier_, scope_);
		::Semantic_Node_ *_Nonnull const name_ = node_->children_->op_Element(p_int(2));
		if (LogicalOr(qualifier_->symbol_->op_Equal(::None), [&] { return qualifier_->type_->op_Equal(::None); }).Value)
		{
			add_resolution_error_(name_);
		}
		else if (name_->kind_->op_Equal(IdentifierName_).Value)
		{
			::Symbol_ const *_Nonnull const symbol_ = qualifier_->symbol_->get_(name_->get_text_(), IdentifierSymbol_);
			if (symbol_->op_Equal(::None).Value)
			{
				add_resolution_error_(name_);
			}
			else
			{
				name_->bind_symbol_(symbol_);
				name_->bind_type_(symbol_->get_type_());
				node_->bind_type_(symbol_->get_type_());
				node_->bind_symbol_(symbol_);
			}
		}
		else if (name_->kind_->op_Equal(GenericName_).Value)
		{
			::Semantic_Node_ *_Nonnull const identifer_name_ = name_->first_child_(IdentifierName_);
			::Symbol_ const *_Nonnull const symbol_ = qualifier_->symbol_->get_(identifer_name_->get_text_(), IdentifierSymbol_);
			if (symbol_->op_Equal(::None).Value)
			{
				add_resolution_error_(name_);
				return;
			}

			identifer_name_->bind_symbol_(symbol_);
			identifer_name_->bind_type_(symbol_->get_type_());
			node_->bind_symbol_(symbol_);
			p_bool type_arg_ = p_bool(false);
			for (::Semantic_Node_ *_Nonnull const type_argument_ : *(name_->children_))
			{
				if (type_arg_.Value)
				{
					if (type_argument_->kind_->op_NotEqual(GreaterThan_).Value)
					{
						bind_type_name_(type_argument_, scope_);
					}
				}
				else if (type_argument_->kind_->op_Equal(LessThan_).Value)
				{
					type_arg_ = p_bool(true);
				}
			}

			node_->bind_type_(symbol_->get_type_());
		}
		else
		{
			THROW_EXCEPTION_(p_string("Unreachable: `Semantic_Binder.bind(..)` name.kind = ").op_Add(name_->kind_));
		}
	}
	else if (node_->kind_->op_Equal(IdentifierName_).Value)
	{
		if (node_->is_missing_.Value)
		{
			return;
		}

		p_string const name_ = node_->get_text_();
		::Symbol_ const *_Nonnull const symbol_ = scope_->lookup_(name_);
		if (symbol_->op_Equal(::None).Value)
		{
			add_resolution_error_(node_);
		}
		else
		{
			node_->bind_symbol_(symbol_);
			node_->bind_type_((new ::Type_())->construct(symbol_));
		}
	}
	else
	{
		THROW_EXCEPTION_(p_string("`Semantic_Binder.bind_type_name()` unimplemented node type ").op_Add(node_->kind_));
	}
}

auto ::Semantic_Binder_::bind_constructor_name_(::Semantic_Node_ *_Nonnull const node_, ::Binding_Scope_ const *_Nonnull const scope_) const -> void
{
	auto self = this;
	if (LogicalAnd(node_->kind_->op_Equal(QualifiedName_), [&] { return node_->children_->op_Element(p_int(2))->kind_->op_Equal(IdentifierName_); }).Value)
	{
		bind_type_name_(node_->children_->op_Element(p_int(0)), scope_);
		::Semantic_Node_ *_Nonnull const qualifier_ = node_->children_->op_Element(p_int(0));
		::Semantic_Node_ *_Nonnull const name_ = node_->children_->op_Element(p_int(2));
		p_string const constructor_name_ = p_string("new_").op_Add(name_->get_text_());
		::Symbol_ const *_Nullable const constructor_symbol_ = qualifier_->symbol_->get_(constructor_name_, SpecialSymbol_);
		if (constructor_symbol_->op_NotEqual(::None).Value)
		{
			name_->bind_symbol_(constructor_symbol_);
		}
		else
		{
			::Symbol_ const *_Nonnull const symbol_ = qualifier_->symbol_->get_(name_->get_text_(), IdentifierSymbol_);
			if (symbol_->op_Equal(::None).Value)
			{
				add_resolution_error_(name_);
			}
			else
			{
				name_->bind_symbol_(symbol_);
				name_->bind_type_(symbol_->get_type_());
				node_->bind_type_(symbol_->get_type_());
				node_->bind_symbol_(symbol_);
			}
		}
	}
	else
	{
		bind_type_name_(node_, scope_);
	}
}

auto ::Semantic_Binder_::add_resolution_error_(::Semantic_Node_ const *_Nonnull const node_) -> void
{
	node_->add_((new ::Diagnostic_())->construct(FatalCompilationError_, Analysis_, node_->source_, node_->get_text_span_(), p_string("Could not resolve name `").op_Add(node_->get_text_())->op_Add(p_string("`"))));
}

auto ::Semantic_Builder_::build_symbols_(::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull const compilation_units_) const -> ::Symbol_ const *_Nonnull
{
	auto self = this;
	::Symbol_ *_Nonnull const package_symbol_ = (new ::Symbol_())->construct(p_string("default"), PackageSymbol_);
	for (::Semantic_Node_ *_Nonnull const compilation_unit_ : *(compilation_units_))
	{
		if (compilation_unit_->kind_->op_NotEqual(CompilationUnit_).Value)
		{
			THROW_EXCEPTION_(p_string("`Semantic_Builder.build_symbols(...)` called with node of type ").op_Add(compilation_unit_->kind_));
		}

		build_symbols_(package_symbol_, compilation_unit_);
	}

	build_runtime_library_symbols_(package_symbol_);
	return package_symbol_;
}

auto ::Semantic_Builder_::build_symbols_(::Symbol_ const *_Nonnull const parent_, ::Semantic_Node_ *_Nonnull const node_) const -> void
{
	auto self = this;
	if (node_->kind_->op_Equal(CompilationUnit_).Value)
	{
		for (::Semantic_Node_ *_Nonnull const declaration_ : *(node_->children_))
		{
			build_symbols_(parent_, declaration_);
		}
	}
	else if (LogicalOr(node_->kind_->op_Equal(FunctionDeclaration_), [&] { return node_->kind_->op_Equal(MethodDeclaration_); }).Value)
	{
		p_string const name_ = node_->first_child_(Identifier_)->get_text_();
		::Symbol_ const *_Nonnull const symbol_ = (new ::Symbol_())->construct(name_);
		build_function_symbols_(parent_, node_, symbol_);
	}
	else if (LogicalOr(node_->kind_->op_Equal(ClassDeclaration_), [&] { return node_->kind_->op_Equal(StructDeclaration_); }).Value)
	{
		p_string const name_ = node_->first_child_(Identifier_)->get_text_();
		::Symbol_ const *_Nonnull const symbol_ = (new ::Symbol_())->construct(name_);
		symbol_->declarations_->Add_(node_);
		for (::Semantic_Node_ *_Nonnull const member_ : *(node_->members_()))
		{
			build_symbols_(symbol_, member_);
		}

		parent_->children_->Add_(symbol_);
		node_->bind_symbol_(symbol_);
	}
	else if (node_->kind_->op_Equal(ConstructorDeclaration_).Value)
	{
		p_string full_name_ = p_string("new");
		::Semantic_Node_ const *_Nullable const constructor_name_ = node_->first_child_(Identifier_);
		if (constructor_name_->op_NotEqual(::None).Value)
		{
			full_name_ = p_string("new_").op_Add(constructor_name_->get_text_());
		}

		::Symbol_ const *_Nonnull const constructor_symbol_ = (new ::Symbol_())->construct(full_name_, SpecialSymbol_);
		constructor_symbol_->declarations_->Add_(node_);
		parent_->children_->Add_(constructor_symbol_);
		::Symbol_ const *_Nonnull const self_symbol_ = (new ::Symbol_())->construct(p_string("self"), SpecialSymbol_);
		constructor_symbol_->children_->Add_(self_symbol_);
		build_function_symbols_(parent_, node_, constructor_symbol_);
	}
	else if (node_->kind_->op_Equal(FieldDeclaration_).Value)
	{
		p_string const name_ = node_->first_child_(VariableDeclaration_)->first_child_(Identifier_)->get_text_();
		::Symbol_ const *_Nonnull const field_symbol_ = (new ::Symbol_())->construct(name_);
		field_symbol_->declarations_->Add_(node_);
		parent_->children_->Add_(field_symbol_);
		node_->bind_symbol_(field_symbol_);
	}
	else if (node_->kind_->op_Equal(EnumDeclaration_).Value)
	{
		p_string const name_ = node_->first_child_(Identifier_)->get_text_();
		::Symbol_ const *_Nonnull const enum_symbol_ = (new ::Symbol_())->construct(name_);
		enum_symbol_->declarations_->Add_(node_);
		parent_->children_->Add_(enum_symbol_);
		node_->bind_symbol_(enum_symbol_);
	}
	else if (node_->kind_->op_Equal(GlobalDeclaration_).Value)
	{
		p_string const name_ = node_->first_child_(VariableDeclaration_)->first_child_(Identifier_)->get_text_();
		::Symbol_ const *_Nonnull const global_declaration_symbol_ = (new ::Symbol_())->construct(name_);
		global_declaration_symbol_->declarations_->Add_(node_);
		parent_->children_->Add_(global_declaration_symbol_);
		node_->bind_symbol_(global_declaration_symbol_);
	}
	else if (node_->kind_->op_Equal(Block_).Value)
	{
		for (::Semantic_Node_ *_Nonnull const statement_ : *(node_->statements_()))
		{
			build_symbols_(parent_, statement_);
		}
	}
	else if (LogicalOr(LogicalOr(node_->kind_->op_Equal(LoopStatement_), [&] { return node_->kind_->op_Equal(WhileStatement_); }), [&] { return node_->kind_->op_Equal(DoWhileStatement_); }).Value)
	{
		build_symbols_(parent_, node_->first_child_(Block_));
	}
	else if (node_->kind_->op_Equal(ForStatement_).Value)
	{
		p_string const name_ = node_->first_child_(VariableDeclaration_)->first_child_(Identifier_)->get_text_();
		::Symbol_ const *_Nonnull const for_symbol_ = (new ::Symbol_())->construct(name_);
		for_symbol_->declarations_->Add_(node_);
		parent_->children_->Add_(for_symbol_);
		node_->bind_symbol_(for_symbol_);
		build_symbols_(parent_, node_->first_child_(Block_));
	}
	else if (node_->kind_->op_Equal(LocalDeclarationStatement_).Value)
	{
		::Semantic_Node_ *_Nonnull const identifier_ = node_->first_child_(VariableDeclaration_)->first_child_(Identifier_);
		::Symbol_ const *_Nonnull const symbol_ = (new ::Symbol_())->construct(identifier_->get_text_());
		symbol_->declarations_->Add_(node_);
		identifier_->bind_symbol_(symbol_);
		parent_->children_->Add_(symbol_);
	}
	else if (node_->kind_->op_Equal(IfStatement_).Value)
	{
		build_symbols_(parent_, node_->first_child_(Block_));
		::Semantic_Node_ *_Nullable const else_clause_ = node_->first_child_(ElseClause_);
		if (else_clause_->op_NotEqual(::None).Value)
		{
			build_symbols_(parent_, else_clause_);
		}
	}
	else if (node_->kind_->op_Equal(ElseClause_).Value)
	{
		::Semantic_Node_ *_Nullable const block_ = node_->first_child_(Block_);
		if (block_->op_NotEqual(::None).Value)
		{
			build_symbols_(parent_, block_);
		}
		else
		{
			build_symbols_(parent_, node_->first_child_(IfStatement_));
		}
	}
	else if (node_->kind_->op_Equal(Parameter_).Value)
	{
		p_string const name_ = node_->first_child_(Identifier_)->get_text_();
		::Symbol_ const *_Nonnull const symbol_ = (new ::Symbol_())->construct(name_);
		symbol_->declarations_->Add_(node_);
		parent_->children_->Add_(symbol_);
	}
	else if (node_->kind_->op_Equal(SelfParameter_).Value)
	{
		::Symbol_ const *_Nonnull const symbol_ = (new ::Symbol_())->construct(p_string("self"), SpecialSymbol_);
		symbol_->declarations_->Add_(node_);
		parent_->children_->Add_(symbol_);
	}
	else if (LogicalOr(LogicalOr(LogicalOr(LogicalOr(node_->kind_->op_Equal(ExpressionStatement_), [&] { return node_->kind_->op_Equal(ReturnStatement_); }), [&] { return node_->kind_->op_Equal(BreakStatement_); }), [&] { return node_->kind_->op_Equal(ContinueStatement_); }), [&] { return node_->kind_->op_Equal(EndOfFileToken_); }).Value)
	{
	}
	else
	{
		THROW_EXCEPTION_(p_string("`Semantic_Builder.Build()` unimplemented node type ").op_Add(node_->kind_));
	}
}

auto ::Semantic_Builder_::build_function_symbols_(::Symbol_ const *_Nonnull const parent_, ::Semantic_Node_ *_Nonnull const function_, ::Symbol_ const *_Nonnull const symbol_) const -> void
{
	auto self = this;
	symbol_->declarations_->Add_(function_);
	::Semantic_Node_ *_Nonnull const parameters_ = function_->first_child_(ParameterList_);
	for (::Semantic_Node_ *_Nonnull const parameter_ : *(parameters_->parameters_()))
	{
		build_symbols_(symbol_, parameter_);
	}

	::Semantic_Node_ *_Nonnull const body_ = function_->first_child_(Block_);
	build_symbols_(symbol_, body_);
	parent_->children_->Add_(symbol_);
	function_->bind_symbol_(symbol_);
}

auto ::Semantic_Builder_::build_runtime_library_symbols_(::Symbol_ const *_Nonnull const package_) const -> void
{
	auto self = this;
	build_resource_manager_(package_);
	build_function_(package_, p_string("THROW_EXCEPTION"));
	build_function_(package_, p_string("NOT_IMPLEMENTED"));
	build_function_(package_, p_string("UNREACHABLE"));
	build_function_(package_, p_string("assert"));
	::Symbol_ *_Nonnull const system_ = build_(package_, p_string("System"), NamespaceDeclaration_);
	::Symbol_ *_Nonnull const collections_ = build_(system_, p_string("Collections"), NamespaceDeclaration_);
	build_(collections_, p_string("List"), ClassDeclaration_);
	::Symbol_ const *_Nonnull const console_ = build_(system_, p_string("Console"), NamespaceDeclaration_);
	build_(console_, p_string("Console"), ClassDeclaration_);
	build_(console_, p_string("Arguments"), ClassDeclaration_);
	::Symbol_ const *_Nonnull const io_ = build_(system_, p_string("IO"), NamespaceDeclaration_);
	build_(io_, p_string("File_Reader"), ClassDeclaration_);
	build_(io_, p_string("File_Writer"), ClassDeclaration_);
	::Symbol_ const *_Nonnull const text_ = build_(system_, p_string("Text"), NamespaceDeclaration_);
	build_(text_, p_string("String_Builder"), ClassDeclaration_);
}

auto ::Semantic_Builder_::build_resource_manager_(::Symbol_ const *_Nonnull const parent_) -> void
{
	::Symbol_ const *_Nonnull const class_symbol_ = build_(parent_, p_string("Resource_Manager"), ClassDeclaration_);
	::Semantic_Node_ *_Nonnull const fake_declaration_ = (new ::Semantic_Node_())->construct((new ::Syntax_Node_())->construct(GlobalDeclaration_, p_bool(true), ::None, p_int(0), p_int(0)));
	::Symbol_ *_Nonnull const symbol_ = (new ::Symbol_())->construct(p_string("resource_manager"));
	symbol_->declarations_->Add_(fake_declaration_);
	fake_declaration_->bind_symbol_(symbol_);
	fake_declaration_->bind_type_((new ::Type_())->construct(class_symbol_));
	parent_->children_->Add_(symbol_);
}

auto ::Semantic_Builder_::build_(::Symbol_ const *_Nonnull const parent_, p_string const name_, p_int const declaration_kind_) -> ::Symbol_ *_Nonnull
{
	::Semantic_Node_ *_Nonnull const fake_declaration_ = (new ::Semantic_Node_())->construct((new ::Syntax_Node_())->construct(declaration_kind_, p_bool(true), ::None, p_int(0), p_int(0)));
	::Symbol_ *_Nonnull const symbol_ = (new ::Symbol_())->construct(name_);
	symbol_->declarations_->Add_(fake_declaration_);
	fake_declaration_->bind_symbol_(symbol_);
	fake_declaration_->bind_type_((new ::Type_())->construct(symbol_));
	parent_->children_->Add_(symbol_);
	return symbol_;
}

auto ::Semantic_Builder_::build_function_(::Symbol_ const *_Nonnull const parent_, p_string const name_) -> void
{
	::Semantic_Node_ *_Nonnull const fake_declaration_ = (new ::Semantic_Node_())->construct((new ::Syntax_Node_())->construct(FunctionDeclaration_, p_bool(true), ::None, p_int(0), p_int(0)));
	::Symbol_ *_Nonnull const symbol_ = (new ::Symbol_())->construct(name_);
	symbol_->declarations_->Add_(fake_declaration_);
	fake_declaration_->bind_symbol_(symbol_);
	parent_->children_->Add_(symbol_);
}

auto ::Semantic_Node_::construct(::Syntax_Node_ const *_Nonnull const syntax_) -> ::Semantic_Node_*
{
	::Semantic_Node_* self = this;
	assert_(syntax_->op_NotEqual(::None), p_string(""));
	self->syntax_ = syntax_;
	kind_ = syntax_->kind_;
	is_missing_ = syntax_->is_missing_;
	source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	byte_length_ = syntax_->byte_length_;
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull>())->construct();
	for (::Syntax_Node_ const *_Nonnull const child_syntax_ : *(syntax_->children_))
	{
		children_->Add_((new ::Semantic_Node_())->construct(child_syntax_));
	}

	self->children_ = children_;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(syntax_->node_diagnostics_))
	{
		diagnostics_->Add_(diagnostic_);
	}

	self->node_diagnostics_ = diagnostics_;
	symbol_ = ::None;
	type_ = ::None;
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
	if (source_->op_Equal(::None).Value)
	{
		return p_string("$No Source$");
	}

	return source_->Text_->Substring_(start_, byte_length_);
}

auto ::Semantic_Node_::bind_symbol_(::Symbol_ const *_Nonnull const symbol_) -> void
{
	auto self = this;
	if (self->symbol_->op_NotEqual(::None).Value)
	{
		THROW_EXCEPTION_(p_string("`Semantic_Node.bind_symbol(..)` called on node that already has a symbol on `").op_Add(get_text_())->op_Add(p_string("`")));
	}

	if (symbol_->op_Equal(::None).Value)
	{
		THROW_EXCEPTION_(p_string("`Semantic_Node.bind_symbol(..)` called without a symbol on `").op_Add(get_text_())->op_Add(p_string("`")));
	}

	self->symbol_ = symbol_;
}

auto ::Semantic_Node_::bind_type_(::Type_ const *_Nonnull const type_) -> void
{
	auto self = this;
	if (self->type_->op_NotEqual(::None).Value)
	{
		THROW_EXCEPTION_(p_string("`Semantic_Node.bind_type(..)` called on node that already has a type. Node: `").op_Add(get_text_())->op_Add(p_string("` of kind "))->op_Add(kind_));
	}

	assert_(type_->op_NotEqual(::None), p_string("Node: `").op_Add(get_text_())->op_Add(p_string("` of kind "))->op_Add(kind_));
	self->type_ = type_;
}

auto ::Semantic_Node_::first_child_(p_int const kind_) const -> ::Semantic_Node_ *_Nullable
{
	auto self = this;
	for (::Semantic_Node_ *_Nonnull const child_ : *(children_))
	{
		if (child_->kind_->op_Equal(kind_).Value)
		{
			return child_;
		}
	}

	return ::None;
}

auto ::Semantic_Node_::children_of_kind_(p_int const kind_) const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull>())->construct();
	for (::Semantic_Node_ *_Nonnull const child_ : *(self->children_))
	{
		if (child_->kind_->op_Equal(kind_).Value)
		{
			children_->Add_(child_);
		}
	}

	return children_;
}

auto ::Semantic_Node_::members_() const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> *_Nonnull const members_ = (new ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull>())->construct();
	for (::Semantic_Node_ *_Nonnull const child_ : *(children_))
	{
		if (LogicalOr(LogicalOr(child_->kind_->op_Equal(ConstructorDeclaration_), [&] { return child_->kind_->op_Equal(FieldDeclaration_); }), [&] { return child_->kind_->op_Equal(MethodDeclaration_); }).Value)
		{
			members_->Add_(child_);
		}
	}

	return members_;
}

auto ::Semantic_Node_::statements_() const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> *_Nonnull const statements_ = (new ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull>())->construct();
	for (::Semantic_Node_ *_Nonnull const child_ : *(children_))
	{
		if (LogicalAnd(child_->kind_->op_NotEqual(LeftBrace_), [&] { return child_->kind_->op_NotEqual(RightBrace_); }).Value)
		{
			statements_->Add_(child_);
		}
	}

	return statements_;
}

auto ::Semantic_Node_::parameters_() const -> ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Semantic_Node_ *_Nonnull> *_Nonnull const parameters_ = (new ::System_::Collections_::List_<::Semantic_Node_ *_Nonnull>())->construct();
	for (::Semantic_Node_ *_Nonnull const child_ : *(children_))
	{
		if (LogicalOr(child_->kind_->op_Equal(Parameter_), [&] { return child_->kind_->op_Equal(SelfParameter_); }).Value)
		{
			parameters_->Add_(child_);
		}
	}

	return parameters_;
}

auto ::Semantic_Node_::has_child_(p_int const kind_) const -> p_bool
{
	auto self = this;
	for (::Semantic_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (child_->kind_->op_Equal(kind_).Value)
		{
			return p_bool(true);
		}
	}

	return p_bool(false);
}

auto ::Semantic_Node_::add_(::Diagnostic_ const *_Nonnull const diagnostic_) const -> void
{
	auto self = this;
	node_diagnostics_->Add_(diagnostic_);
}

auto ::Semantic_Node_::all_diagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	collection_diagnostics_(diagnostics_);
	return diagnostics_;
}

auto ::Semantic_Node_::collection_diagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void
{
	auto self = this;
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(node_diagnostics_))
	{
		diagnostics_->Add_(diagnostic_);
	}

	for (::Semantic_Node_ const *_Nonnull const child_ : *(children_))
	{
		child_->collection_diagnostics_(diagnostics_);
	}
}

auto ::Semantic_Node_::is_value_type_() const -> p_bool
{
	auto self = this;
	if (LogicalOr(kind_->op_Equal(PredefinedType_), [&] { return kind_->op_Equal(OptionalType_); }).Value)
	{
		return p_bool(true);
	}

	if (kind_->op_Equal(QualifiedName_).Value)
	{
		return self->children_->op_Element(p_int(2))->is_value_type_();
	}

	if (kind_->op_Equal(GenericName_).Value)
	{
		return first_child_(IdentifierName_)->is_value_type_();
	}

	if (kind_->op_Equal(IdentifierName_).Value)
	{
		if (symbol_->op_Equal(::None).Value)
		{
			THROW_EXCEPTION_(p_string("No symbol on identifier name `").op_Add(get_text_())->op_Add(p_string("`")));
		}

		return symbol_->declares_value_type_();
	}

	if (kind_->op_Equal(MutableType_).Value)
	{
		return children_->op_Element(p_int(1))->is_value_type_();
	}

	if (kind_->op_Equal(ImmutableType_).Value)
	{
		return children_->op_Element(p_int(0))->is_value_type_();
	}

	THROW_EXCEPTION_(p_string("is_value_type() unable to determine if value type. Syntax node type ").op_Add(kind_));
	return p_bool(true);
}

auto ::Compilation_Unit_Parser_::construct(::Token_Stream_ *_Nonnull const tokenStream_) -> ::Compilation_Unit_Parser_*
{
	::Compilation_Unit_Parser_* self = this;
	self->tokenStream_ = tokenStream_;
	self->compilationUnit_ = ::None;
	return self;
}

auto ::Compilation_Unit_Parser_::Parse_() -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	if (compilationUnit_->op_Equal(::None).Value)
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
	if (token_->op_Equal(::None).Value)
	{
		return new_syntax_node_missing_(tokenType_, tokenStream_->source_, tokenStream_->source_->ByteLength_());
	}

	if (LogicalOr(token_->op_Equal(::None), [&] { return token_->kind_->op_NotEqual(tokenType_); }).Value)
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
	if (LogicalOr(LogicalOr(LogicalOr(LogicalOr(LogicalOr(token_->kind_->op_Equal(CodePoint_), [&] { return token_->kind_->op_Equal(String_); }), [&] { return token_->kind_->op_Equal(Int_); }), [&] { return token_->kind_->op_Equal(Bool_); }), [&] { return token_->kind_->op_Equal(Void_); }), [&] { return token_->kind_->op_Equal(UnsignedInt_); }).Value)
	{
		return (new ::Syntax_Node_())->construct(PredefinedType_, AcceptToken_());
	}
	else
	{
		::Syntax_Node_ const *_Nonnull type_ = (new ::Syntax_Node_())->construct(IdentifierName_, ExpectToken_(Identifier_));
		while (token_->kind_->op_Equal(Dot_).Value)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const children_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
			children_->Add_(type_);
			children_->Add_(ExpectToken_(Dot_));
			::Syntax_Node_ const *_Nonnull const identifier_ = ExpectToken_(Identifier_);
			if (token_->kind_->op_Equal(LessThan_).Value)
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
	if (token_->kind_->op_Equal(MutableKeyword_).Value)
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
	while (token_->kind_->op_Equal(Question_).Value)
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
	if (token_->kind_->op_Equal(NewKeyword_).Value)
	{
		children_->Add_(ExpectToken_(NewKeyword_));
		children_->Add_(ParseTypeName_());
		children_->Add_(ParseCallArguments_());
		return (new ::Syntax_Node_())->construct(NewExpression_, children_);
	}

	if (token_->kind_->op_Equal(NotOperator_).Value)
	{
		children_->Add_(ExpectToken_(NotOperator_));
		children_->Add_(ParseExpression_(p_int(8)));
		return (new ::Syntax_Node_())->construct(NotExpression_, children_);
	}

	if (token_->kind_->op_Equal(LeftParen_).Value)
	{
		children_->Add_(ExpectToken_(LeftParen_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(RightParen_));
		return (new ::Syntax_Node_())->construct(ParenthesizedExpression_, children_);
	}

	if (token_->kind_->op_Equal(Pipe_).Value)
	{
		children_->Add_(ExpectToken_(Pipe_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(Pipe_));
		return (new ::Syntax_Node_())->construct(MagnitudeExpression_, children_);
	}

	if (token_->kind_->op_Equal(Minus_).Value)
	{
		children_->Add_(ExpectToken_(Minus_));
		children_->Add_(ParseExpression_(p_int(8)));
		return (new ::Syntax_Node_())->construct(NegateExpression_, children_);
	}

	if (token_->kind_->op_Equal(NoneKeyword_).Value)
	{
		children_->Add_(ExpectToken_(NoneKeyword_));
		return (new ::Syntax_Node_())->construct(NoneLiteralExpression_, children_);
	}

	if (token_->kind_->op_Equal(SelfKeyword_).Value)
	{
		children_->Add_(ExpectToken_(SelfKeyword_));
		return (new ::Syntax_Node_())->construct(SelfExpression_, children_);
	}

	if (token_->kind_->op_Equal(TrueKeyword_).Value)
	{
		children_->Add_(ExpectToken_(TrueKeyword_));
		return (new ::Syntax_Node_())->construct(TrueLiteralExpression_, children_);
	}

	if (token_->kind_->op_Equal(FalseKeyword_).Value)
	{
		children_->Add_(ExpectToken_(FalseKeyword_));
		return (new ::Syntax_Node_())->construct(FalseLiteralExpression_, children_);
	}

	if (token_->kind_->op_Equal(Number_).Value)
	{
		children_->Add_(ExpectToken_(Number_));
		return (new ::Syntax_Node_())->construct(NumericLiteralExpression_, children_);
	}

	if (token_->kind_->op_Equal(Identifier_).Value)
	{
		children_->Add_(ExpectToken_(Identifier_));
		return (new ::Syntax_Node_())->construct(IdentifierName_, children_);
	}

	if (token_->kind_->op_Equal(StringLiteral_).Value)
	{
		children_->Add_(ExpectToken_(StringLiteral_));
		return (new ::Syntax_Node_())->construct(StringLiteralExpression_, children_);
	}

	if (token_->kind_->op_Equal(CodePointLiteral_).Value)
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
	if (token_->kind_->op_NotEqual(RightParen_).Value)
	{
		for (;;)
		{
			children_->Add_(ParseExpression_());
			if (token_->kind_->op_Equal(Comma_).Value)
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
		if (LogicalAnd(LogicalOr(LogicalOr(token_->kind_->op_Equal(Equals_), [&] { return token_->kind_->op_Equal(PlusEquals_); }), [&] { return token_->kind_->op_Equal(MinusEquals_); }), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(1)); }).Value)
		{
			precedence_ = p_int(1);
			leftAssociative_ = p_bool(false);
			children_->Add_(AcceptToken_());
			expressionType_ = AssignmentExpression_;
		}
		else if (LogicalAnd(token_->kind_->op_Equal(OrKeyword_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(2)); }).Value)
		{
			precedence_ = p_int(2);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(OrKeyword_));
			expressionType_ = OrExpression_;
		}
		else if (LogicalAnd(token_->kind_->op_Equal(AndKeyword_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(3)); }).Value)
		{
			precedence_ = p_int(3);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(AndKeyword_));
			expressionType_ = AndExpression_;
		}
		else if (LogicalAnd(token_->kind_->op_Equal(EqualsEquals_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(4)); }).Value)
		{
			precedence_ = p_int(4);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(EqualsEquals_));
			expressionType_ = EqualExpression_;
		}
		else if (LogicalAnd(token_->kind_->op_Equal(EqualsSlashEquals_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(4)); }).Value)
		{
			precedence_ = p_int(4);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(EqualsSlashEquals_));
			expressionType_ = NotEqualExpression_;
		}
		else if (LogicalAnd(LogicalOr(LogicalOr(LogicalOr(token_->kind_->op_Equal(LessThan_), [&] { return token_->kind_->op_Equal(LessThanEquals_); }), [&] { return token_->kind_->op_Equal(GreaterThan_); }), [&] { return token_->kind_->op_Equal(GreaterThanEquals_); }), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(5)); }).Value)
		{
			precedence_ = p_int(5);
			leftAssociative_ = p_bool(true);
			children_->Add_(AcceptToken_());
			expressionType_ = ComparisonExpression_;
		}
		else if (LogicalAnd(token_->kind_->op_Equal(Plus_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(6)); }).Value)
		{
			precedence_ = p_int(6);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Plus_));
			expressionType_ = AddExpression_;
		}
		else if (LogicalAnd(token_->kind_->op_Equal(Minus_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(6)); }).Value)
		{
			precedence_ = p_int(6);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Minus_));
			expressionType_ = SubtractExpression_;
		}
		else if (LogicalAnd(token_->kind_->op_Equal(Asterisk_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(7)); }).Value)
		{
			precedence_ = p_int(7);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Asterisk_));
			expressionType_ = MultiplyExpression_;
		}
		else if (LogicalAnd(token_->kind_->op_Equal(Slash_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(7)); }).Value)
		{
			precedence_ = p_int(7);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Slash_));
			expressionType_ = DivideExpression_;
		}
		else if (LogicalAnd(token_->kind_->op_Equal(Percent_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(7)); }).Value)
		{
			precedence_ = p_int(7);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Percent_));
			expressionType_ = RemainderExpression_;
		}
		else if (LogicalAnd(token_->kind_->op_Equal(LeftParen_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(9)); }).Value)
		{
			precedence_ = p_int(9);
			leftAssociative_ = p_bool(true);
			suffixOperator_ = p_bool(true);
			children_->Add_(ParseCallArguments_());
			expressionType_ = InvocationExpression_;
		}
		else if (LogicalAnd(token_->kind_->op_Equal(Dot_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(9)); }).Value)
		{
			precedence_ = p_int(9);
			leftAssociative_ = p_bool(true);
			children_->Add_(ExpectToken_(Dot_));
			expressionType_ = MemberAccessExpression_;
		}
		else if (LogicalAnd(token_->kind_->op_Equal(LeftBracket_), [&] { return minPrecedence_->op_LessThanOrEqual(p_int(9)); }).Value)
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

		if (suffixOperator_.op_Not().Value)
		{
			if (leftAssociative_.Value)
			{
				precedence_.op_AddAssign(p_int(1));
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
	if (token_->kind_->op_Equal(ReturnKeyword_).Value)
	{
		children_->Add_(ExpectToken_(ReturnKeyword_));
		if (token_->kind_->op_NotEqual(Semicolon_).Value)
		{
			children_->Add_(ParseExpression_());
		}

		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(ReturnStatement_, children_);
	}

	if (token_->kind_->op_Equal(LoopKeyword_).Value)
	{
		children_->Add_(ExpectToken_(LoopKeyword_));
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_())->construct(LoopStatement_, children_);
	}

	if (token_->kind_->op_Equal(WhileKeyword_).Value)
	{
		children_->Add_(ExpectToken_(WhileKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_())->construct(WhileStatement_, children_);
	}

	if (token_->kind_->op_Equal(ForKeyword_).Value)
	{
		children_->Add_(ExpectToken_(ForKeyword_));
		children_->Add_(ParseVariableDeclaration_(p_bool(false)));
		children_->Add_(ExpectToken_(InKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_())->construct(ForStatement_, children_);
	}

	if (token_->kind_->op_Equal(DoKeyword_).Value)
	{
		children_->Add_(ExpectToken_(DoKeyword_));
		children_->Add_(ParseBlock_());
		children_->Add_(ExpectToken_(WhileKeyword_));
		children_->Add_(ParseExpression_());
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(DoWhileStatement_, children_);
	}

	if (token_->kind_->op_Equal(IfKeyword_).Value)
	{
		return ParseIfStatement_();
	}

	if (token_->kind_->op_Equal(BreakKeyword_).Value)
	{
		children_->Add_(ExpectToken_(BreakKeyword_));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(BreakStatement_, children_);
	}

	if (token_->kind_->op_Equal(ContinueKeyword_).Value)
	{
		children_->Add_(ExpectToken_(ContinueKeyword_));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(ContinueStatement_, children_);
	}

	if (LogicalOr(token_->kind_->op_Equal(VarKeyword_), [&] { return token_->kind_->op_Equal(LetKeyword_); }).Value)
	{
		children_->Add_(ParseVariableDeclaration_(p_bool(true)));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(LocalDeclarationStatement_, children_);
	}

	if (token_->kind_->op_Equal(LeftBrace_).Value)
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
	if (token_->kind_->op_Equal(ElseKeyword_).Value)
	{
		::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const elseChildren_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
		elseChildren_->Add_(ExpectToken_(ElseKeyword_));
		if (token_->kind_->op_Equal(IfKeyword_).Value)
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
	if (LogicalAnd(token_->kind_->op_Equal(LetKeyword_), [&] { return token_->kind_->op_NotEqual(VarKeyword_); }).Value)
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
	if (LogicalAnd(allowInitializer_, [&] { return token_->kind_->op_Equal(Equals_); }).Value)
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
	while (LogicalAnd(token_->kind_->op_NotEqual(RightBrace_), [&] { return token_->kind_->op_NotEqual(EndOfFileToken_); }).Value)
	{
		::Syntax_Node_ const *_Nonnull const startToken_ = token_;
		children_->Add_(ParseStatement_());
		if (token_->op_Equal(startToken_).Value)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const skipped_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
			while (LogicalAnd(LogicalAnd(token_->kind_->op_NotEqual(LeftBrace_), [&] { return token_->kind_->op_NotEqual(RightBrace_); }), [&] { return token_->kind_->op_NotEqual(EndOfFileToken_); }).Value)
			{
				p_int const currentTokenType_ = token_->kind_;
				skipped_->Add_(AcceptToken_());
				if (currentTokenType_.op_Equal(Semicolon_).Value)
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
	if (token_->kind_->op_NotEqual(RightParen_).Value)
	{
		for (;;)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const parameterChildren_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
			if (LogicalOr(token_->kind_->op_Equal(MutableKeyword_), [&] { return token_->kind_->op_Equal(SelfKeyword_); }).Value)
			{
				if (token_->kind_->op_Equal(MutableKeyword_).Value)
				{
					parameterChildren_->Add_(ExpectToken_(MutableKeyword_));
				}

				parameterChildren_->Add_(ExpectToken_(SelfKeyword_));
				children_->Add_((new ::Syntax_Node_())->construct(SelfParameter_, parameterChildren_));
			}
			else
			{
				p_bool const mutableBinding_ = token_->kind_->op_Equal(VarKeyword_);
				if (token_->kind_->op_Equal(VarKeyword_).Value)
				{
					parameterChildren_->Add_(ExpectToken_(VarKeyword_));
				}

				parameterChildren_->Add_(ExpectToken_(Identifier_));
				parameterChildren_->Add_(ExpectToken_(Colon_));
				::Syntax_Node_ const *_Nonnull const type_ = ParseType_();
				parameterChildren_->Add_(type_);
				children_->Add_((new ::Syntax_Node_())->construct(Parameter_, parameterChildren_));
			}

			if (token_->kind_->op_Equal(Comma_).Value)
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
	if (LogicalOr(LogicalOr(LogicalOr(token_->kind_->op_Equal(PublicKeyword_), [&] { return token_->kind_->op_Equal(ProtectedKeyword_); }), [&] { return token_->kind_->op_Equal(InternalKeyword_); }), [&] { return token_->kind_->op_Equal(PrivateKeyword_); }).Value)
	{
		children_->Add_(AcceptToken_());
	}
	else
	{
		children_->Add_(ExpectToken_(PublicKeyword_));
	}

	if (token_->kind_->op_Equal(NewKeyword_).Value)
	{
		children_->Add_(ExpectToken_(NewKeyword_));
		if (token_->kind_->op_Equal(Identifier_).Value)
		{
			children_->Add_(ExpectToken_(Identifier_));
		}

		children_->Add_(ParseParameterList_());
		children_->Add_(ParseBlock_());
		return (new ::Syntax_Node_())->construct(ConstructorDeclaration_, children_);
	}

	if (LogicalOr(token_->kind_->op_Equal(VarKeyword_), [&] { return token_->kind_->op_Equal(LetKeyword_); }).Value)
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
	if (LogicalOr(LogicalOr(LogicalOr(token_->kind_->op_Equal(PublicKeyword_), [&] { return token_->kind_->op_Equal(ProtectedKeyword_); }), [&] { return token_->kind_->op_Equal(InternalKeyword_); }), [&] { return token_->kind_->op_Equal(PrivateKeyword_); }).Value)
	{
		children_->Add_(AcceptToken_());
	}
	else
	{
		children_->Add_(ExpectToken_(PublicKeyword_));
	}

	if (LogicalOr(token_->kind_->op_Equal(VarKeyword_), [&] { return token_->kind_->op_Equal(LetKeyword_); }).Value)
	{
		children_->Add_(ParseVariableDeclaration_(p_bool(true)));
		children_->Add_(ExpectToken_(Semicolon_));
		return (new ::Syntax_Node_())->construct(GlobalDeclaration_, children_);
	}

	if (token_->kind_->op_Equal(ClassKeyword_).Value)
	{
		children_->Add_(ExpectToken_(ClassKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (LogicalAnd(token_->kind_->op_NotEqual(RightBrace_), [&] { return token_->kind_->op_NotEqual(EndOfFileToken_); }).Value)
		{
			::Syntax_Node_ const *_Nonnull const startToken_ = token_;
			children_->Add_(ParseMemberDeclaration_());
			if (token_->op_Equal(startToken_).Value)
			{
				children_->Add_(new_Syntax_Node_Skipped_(AcceptToken_()));
			}
		}

		children_->Add_(ExpectToken_(RightBrace_));
		return (new ::Syntax_Node_())->construct(ClassDeclaration_, children_);
	}

	if (token_->kind_->op_Equal(StructKeyword_).Value)
	{
		children_->Add_(ExpectToken_(StructKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (LogicalAnd(token_->kind_->op_NotEqual(RightBrace_), [&] { return token_->kind_->op_NotEqual(EndOfFileToken_); }).Value)
		{
			::Syntax_Node_ const *_Nonnull const startToken_ = token_;
			children_->Add_(ParseMemberDeclaration_());
			if (token_->op_Equal(startToken_).Value)
			{
				children_->Add_(new_Syntax_Node_Skipped_(AcceptToken_()));
			}
		}

		children_->Add_(ExpectToken_(RightBrace_));
		return (new ::Syntax_Node_())->construct(StructDeclaration_, children_);
	}

	if (token_->kind_->op_Equal(EnumKeyword_).Value)
	{
		children_->Add_(ExpectToken_(EnumKeyword_));
		children_->Add_(ExpectToken_(StructKeyword_));
		children_->Add_(ExpectToken_(Identifier_));
		children_->Add_(ExpectToken_(LeftBrace_));
		while (LogicalAnd(token_->kind_->op_NotEqual(RightBrace_), [&] { return token_->kind_->op_NotEqual(EndOfFileToken_); }).Value)
		{
			::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> *_Nonnull const memberChildren_ = (new ::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull>())->construct();
			memberChildren_->Add_(ExpectToken_(Identifier_));
			if (token_->kind_->op_Equal(Equals_).Value)
			{
				memberChildren_->Add_(ExpectToken_(Equals_));
				memberChildren_->Add_(ExpectToken_(Number_));
			}

			if (token_->kind_->op_NotEqual(RightBrace_).Value)
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
	while (LogicalAnd(token_->op_NotEqual(::None), [&] { return token_->kind_->op_NotEqual(EndOfFileToken_); }).Value)
	{
		::Syntax_Node_ const *_Nonnull const startToken_ = token_;
		children_->Add_(ParseDeclaration_());
		if (token_->op_Equal(startToken_).Value)
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
	::Syntax_Node_ const *_Nonnull const lastChild_ = children_->op_Element(children_->op_Magnitude()->op_Subtract(p_int(1)));
	byte_length_ = lastChild_->start_->op_Subtract(start_)->op_Add(lastChild_->byte_length_);
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
		if (child_->kind_->op_Equal(type_).Value)
		{
			return child_;
		}
	}

	return ::None;
}

auto ::Syntax_Node_::has_child_(p_int const type_) const -> p_bool
{
	auto self = this;
	for (::Syntax_Node_ const *_Nonnull const child_ : *(children_))
	{
		if (child_->kind_->op_Equal(type_).Value)
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

auto ::Syntax_Node_::all_diagnostics_() const -> ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> const *_Nonnull
{
	auto self = this;
	::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull diagnostics_ = (new ::System_::Collections_::List_<::Diagnostic_ const *_Nonnull>())->construct();
	collection_diagnostics_(diagnostics_);
	return diagnostics_;
}

auto ::Syntax_Node_::collection_diagnostics_(::System_::Collections_::List_<::Diagnostic_ const *_Nonnull> *_Nonnull const diagnostics_) const -> void
{
	auto self = this;
	for (::Diagnostic_ const *_Nonnull const diagnostic_ : *(node_diagnostics_))
	{
		diagnostics_->Add_(diagnostic_);
	}

	for (::Syntax_Node_ const *_Nonnull const child_ : *(children_))
	{
		child_->collection_diagnostics_(diagnostics_);
	}
}

auto new_syntax_node_missing_(p_int const type_, ::Source_Text_ const *_Nonnull const source_, p_uint const start_) -> ::Syntax_Node_ const *_Nonnull
{
	::Syntax_Node_ *_Nonnull const node_ = (new ::Syntax_Node_())->construct(type_, p_bool(true), source_, start_, p_int(0));
	::Text_Span_ const *_Nonnull const span_ = (new ::Text_Span_())->construct(start_, p_int(0));
	node_->add_((new ::Diagnostic_())->construct(CompilationError_, Parsing_, source_, span_, p_string("Missing token of type ").op_Add(type_)));
	return node_;
}

auto new_Syntax_Node_Skipped_(::Syntax_Node_ const *_Nonnull const skipped_) -> ::Syntax_Node_ const *_Nonnull
{
	::Syntax_Node_ *_Nonnull const node_ = (new ::Syntax_Node_())->construct(SkippedTokens_, skipped_);
	::Text_Span_ const *_Nonnull const span_ = (new ::Text_Span_())->construct(skipped_->start_, skipped_->byte_length_);
	node_->add_((new ::Diagnostic_())->construct(CompilationError_, Parsing_, skipped_->source_, span_, p_string("Skipped unexpected token of type ").op_Add(skipped_->kind_)));
	return node_;
}

auto new_Syntax_Node_Skipped_(::System_::Collections_::List_<::Syntax_Node_ const *_Nonnull> const *_Nonnull const skipped_) -> ::Syntax_Node_ const *_Nonnull
{
	::Syntax_Node_ *_Nonnull const node_ = (new ::Syntax_Node_())->construct(SkippedTokens_, skipped_);
	::Text_Span_ const *_Nonnull const span_ = (new ::Text_Span_())->construct(node_->start_, node_->byte_length_);
	node_->add_((new ::Diagnostic_())->construct(CompilationError_, Parsing_, node_->source_, span_, p_string("Skipped ").op_Add(skipped_->op_Magnitude())->op_Add(p_string(" unexpected token(s)"))));
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
	if (position_->op_GreaterThanOrEqual(source_->ByteLength_()).Value)
	{
		return EndOfFile_();
	}

	p_uint end_ = p_int(1).op_Negate();
	while (position_->op_LessThan(source_->ByteLength_()).Value)
	{
		p_code_point const curChar_ = source_->Text_->op_Element(position_);
		if (LogicalOr(LogicalOr(LogicalOr(curChar_.op_Equal(p_code_point(' ')), [&] { return curChar_.op_Equal(p_code_point('\t')); }), [&] { return curChar_.op_Equal(p_code_point('\n')); }), [&] { return curChar_.op_Equal(p_code_point('\r')); }).Value)
		{
			position_->op_AddAssign(p_int(1));
			continue;
		}
		else if (curChar_.op_Equal(p_code_point('{')).Value)
		{
			return NewOperator_(LeftBrace_);
		}
		else if (curChar_.op_Equal(p_code_point('}')).Value)
		{
			return NewOperator_(RightBrace_);
		}
		else if (curChar_.op_Equal(p_code_point('(')).Value)
		{
			return NewOperator_(LeftParen_);
		}
		else if (curChar_.op_Equal(p_code_point(')')).Value)
		{
			return NewOperator_(RightParen_);
		}
		else if (curChar_.op_Equal(p_code_point(';')).Value)
		{
			return NewOperator_(Semicolon_);
		}
		else if (curChar_.op_Equal(p_code_point(',')).Value)
		{
			return NewOperator_(Comma_);
		}
		else if (curChar_.op_Equal(p_code_point('.')).Value)
		{
			return NewOperator_(Dot_);
		}
		else if (curChar_.op_Equal(p_code_point(':')).Value)
		{
			return NewOperator_(Colon_);
		}
		else if (curChar_.op_Equal(p_code_point('[')).Value)
		{
			return NewOperator_(LeftBracket_);
		}
		else if (curChar_.op_Equal(p_code_point(']')).Value)
		{
			return NewOperator_(RightBracket_);
		}
		else if (curChar_.op_Equal(p_code_point('?')).Value)
		{
			return NewOperator_(Question_);
		}
		else if (curChar_.op_Equal(p_code_point('|')).Value)
		{
			return NewOperator_(Pipe_);
		}
		else if (curChar_.op_Equal(p_code_point('*')).Value)
		{
			return NewOperator_(Asterisk_);
		}
		else if (curChar_.op_Equal(p_code_point('=')).Value)
		{
			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(EqualsEquals_, p_int(2));
			}

			if (LogicalAnd(LogicalAnd(position_->op_Add(p_int(2))->op_LessThan(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('/')); }), [&] { return source_->Text_->op_Element(position_->op_Add(p_int(2)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(EqualsSlashEquals_, p_int(3));
			}

			return NewOperator_(Equals_);
		}
		else if (curChar_.op_Equal(p_code_point('+')).Value)
		{
			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(PlusEquals_, p_int(2));
			}

			return NewOperator_(Plus_);
		}
		else if (curChar_.op_Equal(p_code_point('-')).Value)
		{
			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('>')); }).Value)
			{
				return NewOperator_(Arrow_, p_int(2));
			}

			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(MinusEquals_, p_int(2));
			}

			return NewOperator_(Minus_);
		}
		else if (curChar_.op_Equal(p_code_point('/')).Value)
		{
			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('/')); }).Value)
			{
				while (LogicalAnd(LogicalAnd(position_->op_LessThan(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_)->op_NotEqual(p_code_point('\r')); }), [&] { return source_->Text_->op_Element(position_)->op_NotEqual(p_code_point('\n')); }).Value)
				{
					position_->op_AddAssign(p_int(1));
				}

				continue;
			}

			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('*')); }).Value)
			{
				position_->op_AddAssign(p_int(2));
				p_bool lastCharStar_ = p_bool(false);
				while (LogicalAnd(position_->op_LessThan(source_->ByteLength_()), [&] { return LogicalAnd(lastCharStar_, [&] { return source_->Text_->op_Element(position_)->op_Equal(p_code_point('/')); })->op_Not(); }).Value)
				{
					lastCharStar_ = source_->Text_->op_Element(position_)->op_Equal(p_code_point('*'));
					position_->op_AddAssign(p_int(1));
				}

				position_->op_AddAssign(p_int(1));
				continue;
			}

			return NewOperator_(Slash_);
		}
		else if (curChar_.op_Equal(p_code_point('%')).Value)
		{
			return NewOperator_(Percent_);
		}
		else if (curChar_.op_Equal(p_code_point('<')).Value)
		{
			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(LessThanEquals_, p_int(2));
			}

			return NewOperator_(LessThan_);
		}
		else if (curChar_.op_Equal(p_code_point('>')).Value)
		{
			if (LogicalAnd(position_->op_Add(p_int(1))->op_LessThan(source_->ByteLength_()), [&] { return source_->Text_->op_Element(position_->op_Add(p_int(1)))->op_Equal(p_code_point('=')); }).Value)
			{
				return NewOperator_(GreaterThanEquals_, p_int(2));
			}

			return NewOperator_(GreaterThan_);
		}
		else if (curChar_.op_Equal(p_code_point('"')).Value)
		{
			end_ = position_->op_Add(p_int(1));
			p_bool escaped_ = p_bool(false);
			while (LogicalAnd(end_.op_LessThan(source_->ByteLength_()), [&] { return LogicalOr(source_->Text_->op_Element(end_)->op_NotEqual(p_code_point('"')), [&] { return escaped_; }); }).Value)
			{
				escaped_ = LogicalAnd(source_->Text_->op_Element(end_)->op_Equal(p_code_point('\\')), [&] { return escaped_.op_Not(); });
				end_.op_AddAssign(p_int(1));
			}

			end_.op_AddAssign(p_int(1));
			return NewToken_(StringLiteral_, end_);
		}
		else if (curChar_.op_Equal(p_code_point('\'')).Value)
		{
			end_ = position_->op_Add(p_int(1));
			p_bool escaped_ = p_bool(false);
			while (LogicalAnd(end_.op_LessThan(source_->ByteLength_()), [&] { return LogicalOr(source_->Text_->op_Element(end_)->op_NotEqual(p_code_point('\'')), [&] { return escaped_; }); }).Value)
			{
				escaped_ = LogicalAnd(source_->Text_->op_Element(end_)->op_Equal(p_code_point('\\')), [&] { return escaped_.op_Not(); });
				end_.op_AddAssign(p_int(1));
			}

			end_.op_AddAssign(p_int(1));
			return NewToken_(CodePointLiteral_, end_);
		}
		else
		{
			if (IsIdentifierChar_(curChar_).Value)
			{
				end_ = position_->op_Add(p_int(1));
				while (IsIdentifierChar_(source_->Text_->op_Element(end_)).Value)
				{
					end_.op_AddAssign(p_int(1));
				}

				return NewIdentifierOrKeyword_(end_);
			}

			if (IsNumberChar_(curChar_).Value)
			{
				end_ = position_->op_Add(p_int(1));
				while (IsNumberChar_(source_->Text_->op_Element(end_)).Value)
				{
					end_.op_AddAssign(p_int(1));
				}

				return NewToken_(Number_, end_);
			}

			::Text_Span_ const *_Nonnull diagnosticSpan_ = (new ::Text_Span_())->construct(position_, p_int(1));
			diagnostics_->Add_((new ::Diagnostic_())->construct(CompilationError_, Lexing_, source_, diagnosticSpan_, p_string("Invalid character `").op_Add(curChar_)->op_Add(p_string("`"))));
			position_ = end_;
		}
	}

	return EndOfFile_();
}

auto ::Token_Stream_::EndOfFile_() -> ::Syntax_Node_ const *_Nullable
{
	auto self = this;
	if (endOfFile_.Value)
	{
		return ::None;
	}

	endOfFile_ = p_bool(true);
	return NewToken_(EndOfFileToken_, position_);
}

auto ::Token_Stream_::NewIdentifierOrKeyword_(p_uint const end_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	p_uint const length_ = end_->op_Subtract(position_);
	p_string const value_ = source_->Text_->Substring_(position_, length_);
	p_int type_;
	if (value_.op_Equal(p_string("new")).Value)
	{
		type_ = NewKeyword_;
	}
	else if (value_.op_Equal(p_string("not")).Value)
	{
		type_ = NotOperator_;
	}
	else if (value_.op_Equal(p_string("null")).Value)
	{
		type_ = NullReservedWord_;
	}
	else if (value_.op_Equal(p_string("self")).Value)
	{
		type_ = SelfKeyword_;
	}
	else if (value_.op_Equal(p_string("true")).Value)
	{
		type_ = TrueKeyword_;
	}
	else if (value_.op_Equal(p_string("false")).Value)
	{
		type_ = FalseKeyword_;
	}
	else if (value_.op_Equal(p_string("mut")).Value)
	{
		type_ = MutableKeyword_;
	}
	else if (value_.op_Equal(p_string("code_point")).Value)
	{
		type_ = CodePoint_;
	}
	else if (value_.op_Equal(p_string("string")).Value)
	{
		type_ = String_;
	}
	else if (value_.op_Equal(p_string("int")).Value)
	{
		type_ = Int_;
	}
	else if (value_.op_Equal(p_string("bool")).Value)
	{
		type_ = Bool_;
	}
	else if (value_.op_Equal(p_string("void")).Value)
	{
		type_ = Void_;
	}
	else if (value_.op_Equal(p_string("uint")).Value)
	{
		type_ = UnsignedInt_;
	}
	else if (value_.op_Equal(p_string("var")).Value)
	{
		type_ = VarKeyword_;
	}
	else if (value_.op_Equal(p_string("and")).Value)
	{
		type_ = AndKeyword_;
	}
	else if (value_.op_Equal(p_string("or")).Value)
	{
		type_ = OrKeyword_;
	}
	else if (value_.op_Equal(p_string("return")).Value)
	{
		type_ = ReturnKeyword_;
	}
	else if (value_.op_Equal(p_string("loop")).Value)
	{
		type_ = LoopKeyword_;
	}
	else if (value_.op_Equal(p_string("while")).Value)
	{
		type_ = WhileKeyword_;
	}
	else if (value_.op_Equal(p_string("for")).Value)
	{
		type_ = ForKeyword_;
	}
	else if (value_.op_Equal(p_string("let")).Value)
	{
		type_ = LetKeyword_;
	}
	else if (value_.op_Equal(p_string("in")).Value)
	{
		type_ = InKeyword_;
	}
	else if (value_.op_Equal(p_string("do")).Value)
	{
		type_ = DoKeyword_;
	}
	else if (value_.op_Equal(p_string("if")).Value)
	{
		type_ = IfKeyword_;
	}
	else if (value_.op_Equal(p_string("else")).Value)
	{
		type_ = ElseKeyword_;
	}
	else if (value_.op_Equal(p_string("break")).Value)
	{
		type_ = BreakKeyword_;
	}
	else if (value_.op_Equal(p_string("continue")).Value)
	{
		type_ = ContinueKeyword_;
	}
	else if (value_.op_Equal(p_string("private")).Value)
	{
		type_ = PrivateKeyword_;
	}
	else if (value_.op_Equal(p_string("protected")).Value)
	{
		type_ = ProtectedKeyword_;
	}
	else if (value_.op_Equal(p_string("public")).Value)
	{
		type_ = PublicKeyword_;
	}
	else if (value_.op_Equal(p_string("internal")).Value)
	{
		type_ = InternalKeyword_;
	}
	else if (value_.op_Equal(p_string("class")).Value)
	{
		type_ = ClassKeyword_;
	}
	else if (value_.op_Equal(p_string("enum")).Value)
	{
		type_ = EnumKeyword_;
	}
	else if (value_.op_Equal(p_string("struct")).Value)
	{
		type_ = StructKeyword_;
	}
	else if (value_.op_Equal(p_string("none")).Value)
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
	return NewToken_(type_, position_->op_Add(p_int(1)));
}

auto ::Token_Stream_::NewOperator_(p_int const type_, p_uint const length_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	return NewToken_(type_, position_->op_Add(length_));
}

auto ::Token_Stream_::NewToken_(p_int const type_, p_uint const end_) -> ::Syntax_Node_ const *_Nonnull
{
	auto self = this;
	::Syntax_Node_ *_Nonnull const token_ = (new ::Syntax_Node_())->construct(type_, source_, position_, end_->op_Subtract(position_));
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
	return LogicalOr(LogicalOr(LogicalAnd(c_->op_GreaterThanOrEqual(p_code_point('a')), [&] { return c_->op_LessThanOrEqual(p_code_point('z')); }), [&] { return LogicalAnd(c_->op_GreaterThanOrEqual(p_code_point('A')), [&] { return c_->op_LessThanOrEqual(p_code_point('Z')); }); }), [&] { return c_->op_Equal(p_code_point('_')); });
}

auto ::Token_Stream_::IsNumberChar_(p_code_point const c_) -> p_bool
{
	return LogicalAnd(c_->op_GreaterThanOrEqual(p_code_point('0')), [&] { return c_->op_LessThanOrEqual(p_code_point('9')); });
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
	for (::Semantic_Node_ const *_Nonnull const compilation_unit_ : *(package_->compilation_units_))
	{
		emit_compilation_unit_(compilation_unit_);
	}

	emit_entry_point_adapter_();
	return type_declarations_->ToString_()->op_Add(function_declarations_->ToString_())->op_Add(class_declarations_->ToString_())->op_Add(global_definitions_->ToString_())->op_Add(definitions_->ToString_());
}

auto ::Emitter_::convert_type_name_(::Semantic_Node_ const *_Nonnull const type_) -> p_string
{
	if (type_->kind_->op_Equal(PredefinedType_).Value)
	{
		::Semantic_Node_ const *_Nonnull const keyword_ = type_->children_->op_Element(p_int(0));
		if (keyword_->kind_->op_Equal(Void_).Value)
		{
			return keyword_->get_text_();
		}

		return p_string("p_").op_Add(keyword_->get_text_());
	}

	if (type_->kind_->op_Equal(IdentifierName_).Value)
	{
		return p_string("::").op_Add(type_->get_text_())->op_Add(p_string("_"));
	}

	if (type_->kind_->op_Equal(QualifiedName_).Value)
	{
		return convert_type_name_(type_->children_->op_Element(p_int(0)))->op_Add(convert_type_name_(type_->children_->op_Element(p_int(2))));
	}

	if (type_->kind_->op_Equal(GenericName_).Value)
	{
		return convert_type_name_(type_->children_->op_Element(p_int(0)))->op_Add(p_string("<"))->op_Add(convert_type_(p_bool(true), type_->children_->op_Element(p_int(2))))->op_Add(p_string(">"));
	}

	return format_error_(p_string("Unexpected Token of type ").op_Add(type_->kind_)->op_Add(p_string(" found in convert_type_name(), `"))->op_Add(type_->get_text_())->op_Add(p_string("`")));
}

auto ::Emitter_::convert_reference_type_(p_bool const mutable_binding_, ::Semantic_Node_ const *_Nonnull type_, p_bool const nullable_, p_bool const mutable_value_) -> p_string
{
	p_string cpp_type_ = convert_type_name_(type_);
	if (mutable_value_->op_Not().Value)
	{
		cpp_type_ = cpp_type_.op_Add(p_string(" const"));
	}

	cpp_type_ = cpp_type_.op_Add(p_string(" *"));
	if (nullable_.Value)
	{
		cpp_type_ = cpp_type_.op_Add(p_string("_Nullable"));
	}
	else
	{
		cpp_type_ = cpp_type_.op_Add(p_string("_Nonnull"));
	}

	if (mutable_binding_->op_Not().Value)
	{
		cpp_type_ = cpp_type_.op_Add(p_string(" const"));
	}

	return cpp_type_;
}

auto ::Emitter_::convert_type_(p_bool const mutable_binding_, ::Semantic_Node_ const *_Nonnull type_, p_bool const optional_) -> p_string
{
	assert_(type_->op_NotEqual(::None), p_string(""));
	p_bool const mutable_value_ = type_->kind_->op_Equal(MutableType_);
	if (mutable_value_.Value)
	{
		type_ = type_->children_->op_Element(p_int(1));
	}
	else if (type_->kind_->op_Equal(ImmutableType_).Value)
	{
		type_ = type_->children_->op_Element(p_int(0));
	}
	else
	{
		return format_error_(p_string("Expected mutable or immutable type in convert_type(). Found token `").op_Add(type_->get_text_())->op_Add(p_string("` of type "))->op_Add(type_->kind_));
	}

	if (type_->kind_->op_Equal(OptionalType_).Value)
	{
		::Semantic_Node_ const *_Nonnull const optional_type_ = type_->children_->op_Element(p_int(0));
		assert_(LogicalOr(optional_type_->kind_->op_Equal(MutableType_), [&] { return optional_type_->kind_->op_Equal(ImmutableType_); }), p_string("optional_type.kind=").op_Add(optional_type_->kind_));
		if (optional_type_->is_value_type_().Value)
		{
			return p_string("p_optional<").op_Add(convert_type_(p_bool(true), optional_type_, p_bool(true)))->op_Add(p_string("> const"));
		}
		else
		{
			return convert_type_(mutable_binding_, optional_type_, p_bool(true));
		}
	}
	else
	{
		if (type_->is_value_type_().Value)
		{
			p_string cpp_type_ = convert_type_name_(type_);
			if (LogicalAnd(mutable_binding_->op_Not(), [&] { return mutable_value_.op_Not(); }).Value)
			{
				cpp_type_ = cpp_type_.op_Add(p_string(" const"));
			}

			return cpp_type_;
		}
		else
		{
			return convert_reference_type_(mutable_binding_, type_, optional_, mutable_value_);
		}
	}
}

auto ::Emitter_::convert_type_(p_bool const mutable_binding_, ::Semantic_Node_ const *_Nonnull const type_) -> p_string
{
	return convert_type_(mutable_binding_, type_, p_bool(false));
}

auto ::Emitter_::convert_parameter_list_(::Semantic_Node_ const *_Nonnull const parameter_list_, p_bool const is_main_function_) -> p_string
{
	auto self = this;
	assert_(parameter_list_->kind_->op_Equal(ParameterList_), p_string("parameter_list.kind=").op_Add(parameter_list_->kind_));
	::System_::Text_::String_Builder_ *_Nonnull const builder_ = (new ::System_::Text_::String_Builder_())->construct();
	builder_->Append_(p_string("("));
	p_bool first_parameter_ = p_bool(true);
	for (::Semantic_Node_ const *_Nonnull const parameter_ : *(parameter_list_->children_of_kind_(Parameter_)))
	{
		if (first_parameter_.op_Not().Value)
		{
			builder_->Append_(p_string(", "));
		}
		else
		{
			first_parameter_ = p_bool(false);
		}

		p_bool const mutable_binding_ = parameter_->has_child_(VarKeyword_);
		::Semantic_Node_ const *_Nonnull const type_ = parameter_->children_->op_Element(parameter_->children_->op_Magnitude()->op_Subtract(p_int(1)));
		builder_->Append_(convert_type_(mutable_binding_, type_));
		builder_->Append_(p_string(" "));
		builder_->Append_(parameter_->first_child_(Identifier_)->get_text_());
		builder_->Append_(p_string("_"));
		if (is_main_function_.Value)
		{
			p_string type_string_;
			if (type_->kind_->op_Equal(MutableType_).Value)
			{
				type_string_ = type_->children_->op_Element(p_int(1))->get_text_();
			}
			else
			{
				type_string_ = type_->get_text_();
			}

			if (type_string_.op_Equal(p_string("System.Console.Console")).Value)
			{
				main_function_accepts_console_ = p_bool(true);
			}

			if (type_string_.op_Equal(p_string("System.Console.Arguments")).Value)
			{
				main_function_accepts_args_ = p_bool(true);
			}
		}
	}

	builder_->Append_(p_string(")"));
	return builder_->ToString_();
}

auto ::Emitter_::convert_parameter_list_(::Semantic_Node_ const *_Nonnull const parameter_list_) -> p_string
{
	auto self = this;
	return convert_parameter_list_(parameter_list_, p_bool(false));
}

auto ::Emitter_::convert_expression_(::Semantic_Node_ const *_Nonnull const syntax_, ::Source_File_Builder_ *_Nonnull const builder_) -> void
{
	if (syntax_->kind_->op_Equal(NewExpression_).Value)
	{
		p_string constructor_name_ = p_string("construct");
		::Semantic_Node_ const *_Nonnull type_ = syntax_->children_->op_Element(p_int(1));
		if (type_->kind_->op_Equal(QualifiedName_).Value)
		{
			::Semantic_Node_ const *_Nonnull const name_ = type_->children_->op_Element(p_int(2));
			if (LogicalAnd(LogicalAnd(name_->kind_->op_Equal(IdentifierName_), [&] { return name_->symbol_->kind_->op_Equal(SpecialSymbol_); }), [&] { return name_->symbol_->is_primitive_->op_Not(); }).Value)
			{
				constructor_name_ = p_string("construct_").op_Add(name_->get_text_());
				type_ = type_->children_->op_Element(p_int(0));
			}
		}

		if (type_->is_value_type_().Value)
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

		::Semantic_Node_ const *_Nonnull const argumentList_ = syntax_->children_->op_Element(p_int(2));
		convert_expression_(argumentList_, builder_);
	}
	else if (syntax_->kind_->op_Equal(ArgumentList_).Value)
	{
		builder_->Write_(p_string("("));
		p_bool first_expression_ = p_bool(true);
		for (::Semantic_Node_ const *_Nonnull const arg_ : *(syntax_->children_))
		{
			if (LogicalAnd(LogicalAnd(arg_->kind_->op_NotEqual(LeftParen_), [&] { return arg_->kind_->op_NotEqual(RightParen_); }), [&] { return arg_->kind_->op_NotEqual(Comma_); }).Value)
			{
				if (first_expression_.Value)
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
	else if (syntax_->kind_->op_Equal(NotExpression_).Value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(1)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(1)), builder_);
		builder_->Write_(p_string("op_Not()"));
	}
	else if (syntax_->kind_->op_Equal(MagnitudeExpression_).Value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(1)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(1)), builder_);
		builder_->Write_(p_string("op_Magnitude()"));
	}
	else if (syntax_->kind_->op_Equal(ParenthesizedExpression_).Value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(1)), builder_);
	}
	else if (syntax_->kind_->op_Equal(NegateExpression_).Value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(1)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(1)), builder_);
		builder_->Write_(p_string("op_Negate()"));
	}
	else if (syntax_->kind_->op_Equal(NoneLiteralExpression_).Value)
	{
		builder_->Write_(p_string("::None"));
	}
	else if (syntax_->kind_->op_Equal(SelfExpression_).Value)
	{
		builder_->Write_(p_string("self"));
	}
	else if (syntax_->kind_->op_Equal(NumericLiteralExpression_).Value)
	{
		builder_->Write_(p_string("p_int(").op_Add(syntax_->get_text_())->op_Add(p_string(")")));
	}
	else if (LogicalOr(syntax_->kind_->op_Equal(TrueLiteralExpression_), [&] { return syntax_->kind_->op_Equal(FalseLiteralExpression_); }).Value)
	{
		builder_->Write_(p_string("p_bool(").op_Add(syntax_->get_text_())->op_Add(p_string(")")));
	}
	else if (syntax_->kind_->op_Equal(CodePointLiteralExpression_).Value)
	{
		builder_->Write_(p_string("p_code_point(").op_Add(syntax_->get_text_())->op_Add(p_string(")")));
	}
	else if (syntax_->kind_->op_Equal(IdentifierName_).Value)
	{
		builder_->Write_(syntax_->get_text_()->op_Add(p_string("_")));
	}
	else if (syntax_->kind_->op_Equal(StringLiteralExpression_).Value)
	{
		builder_->Write_(p_string("p_string(").op_Add(syntax_->get_text_())->op_Add(p_string(")")));
	}
	else if (syntax_->kind_->op_Equal(AssignmentExpression_).Value)
	{
		p_int const operator_ = syntax_->children_->op_Element(p_int(1))->kind_;
		if (operator_.op_Equal(Equals_).Value)
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
			if (operator_.op_Equal(PlusEquals_).Value)
			{
				builder_->Write_(p_string("AddAssign"));
			}
			else if (operator_.op_Equal(MinusEquals_).Value)
			{
				builder_->Write_(p_string("SubtractAssign"));
			}
			else
			{
				builder_->Error_(p_string("Unsupported assignment operator ").op_Add(operator_));
			}

			builder_->Write_(p_string("("));
			convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
			builder_->Write_(p_string(")"));
		}
	}
	else if (syntax_->kind_->op_Equal(EqualExpression_).Value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_Equal("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_Equal(NotEqualExpression_).Value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_NotEqual("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_Equal(ComparisonExpression_).Value)
	{
		p_int const operator_ = syntax_->children_->op_Element(p_int(1))->kind_;
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_"));
		if (operator_.op_Equal(LessThan_).Value)
		{
			builder_->Write_(p_string("LessThan"));
		}
		else if (operator_.op_Equal(LessThanEquals_).Value)
		{
			builder_->Write_(p_string("LessThanOrEqual"));
		}
		else if (operator_.op_Equal(GreaterThan_).Value)
		{
			builder_->Write_(p_string("GreaterThan"));
		}
		else if (operator_.op_Equal(GreaterThanEquals_).Value)
		{
			builder_->Write_(p_string("GreaterThanOrEqual"));
		}
		else
		{
			builder_->Error_(p_string("Unsupported comparison operator ").op_Add(operator_));
		}

		builder_->Write_(p_string("("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_Equal(AddExpression_).Value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_Add("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_Equal(SubtractExpression_).Value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_Subtract("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_Equal(MultiplyExpression_).Value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_Multiply("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_Equal(DivideExpression_).Value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_Divide("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_Equal(RemainderExpression_).Value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_Remainder("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else if (syntax_->kind_->op_Equal(OrExpression_).Value)
	{
		builder_->Write_(p_string("LogicalOr("));
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string(", [&] { return "));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string("; })"));
	}
	else if (syntax_->kind_->op_Equal(AndExpression_).Value)
	{
		builder_->Write_(p_string("LogicalAnd("));
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string(", [&] { return "));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string("; })"));
	}
	else if (syntax_->kind_->op_Equal(InvocationExpression_).Value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_expression_(syntax_->children_->op_Element(p_int(1)), builder_);
	}
	else if (syntax_->kind_->op_Equal(MemberAccessExpression_).Value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
	}
	else if (syntax_->kind_->op_Equal(ElementAccessExpression_).Value)
	{
		convert_expression_(syntax_->children_->op_Element(p_int(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(p_int(0)), builder_);
		builder_->Write_(p_string("op_Element("));
		convert_expression_(syntax_->children_->op_Element(p_int(2)), builder_);
		builder_->Write_(p_string(")"));
	}
	else
	{
		builder_->Error_(p_string("Could not convert expression of type ").op_Add(syntax_->kind_));
	}
}

auto ::Emitter_::convert_member_access_(::Semantic_Node_ const *_Nonnull const lhs_, ::Source_File_Builder_ *_Nonnull const builder_) -> void
{
	::Type_ const *_Nullable const type_ = lhs_->type_;
	if (LogicalAnd(type_->op_NotEqual(::None), [&] { return type_->is_value_type_; }).Value)
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
	if (statement_->kind_->op_Equal(ReturnStatement_).Value)
	{
		if (statement_->children_->op_Magnitude()->op_Equal(p_int(2)).Value)
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
	else if (statement_->kind_->op_Equal(LoopStatement_).Value)
	{
		definitions_->WriteLine_(p_string("for (;;)"));
		emit_statement_(statement_->children_->op_Element(p_int(1)));
	}
	else if (statement_->kind_->op_Equal(Block_).Value)
	{
		definitions_->BeginBlock_();
		for (::Semantic_Node_ const *_Nonnull const block_statement_ : *(statement_->statements_()))
		{
			emit_statement_(block_statement_);
		}

		definitions_->EndBlock_();
	}
	else if (statement_->kind_->op_Equal(WhileStatement_).Value)
	{
		definitions_->BeginLine_(p_string("while ("));
		convert_expression_(statement_->children_->op_Element(p_int(1)), definitions_);
		definitions_->EndLine_(p_string(".Value)"));
		emit_statement_(statement_->children_->op_Element(p_int(2)));
	}
	else if (statement_->kind_->op_Equal(ForStatement_).Value)
	{
		definitions_->BeginLine_(p_string("for ("));
		::Semantic_Node_ const *_Nonnull const variable_declaration_ = statement_->children_->op_Element(p_int(1));
		p_bool const mutable_binding_ = variable_declaration_->has_child_(VarKeyword_);
		p_string const name_ = variable_declaration_->first_child_(Identifier_)->get_text_();
		::Semantic_Node_ const *_Nonnull const type_ = variable_declaration_->children_->op_Element(p_int(3));
		definitions_->Write_(convert_type_(mutable_binding_, type_)->op_Add(p_string(" "))->op_Add(name_)->op_Add(p_string("_")));
		definitions_->Write_(p_string(" : *("));
		convert_expression_(statement_->children_->op_Element(p_int(3)), definitions_);
		definitions_->EndLine_(p_string("))"));
		emit_statement_(statement_->children_->op_Element(p_int(4)));
	}
	else if (statement_->kind_->op_Equal(DoWhileStatement_).Value)
	{
		definitions_->WriteLine_(p_string("do"));
		emit_statement_(statement_->children_->op_Element(p_int(1)));
		definitions_->BeginLine_(p_string("while ("));
		convert_expression_(statement_->children_->op_Element(p_int(3)), definitions_);
		definitions_->EndLine_(p_string(".Value);"));
	}
	else if (statement_->kind_->op_Equal(IfStatement_).Value)
	{
		::Semantic_Node_ const *_Nullable if_statement_ = statement_;
		definitions_->BeginLine_(p_string(""));
		for (;;)
		{
			definitions_->Write_(p_string("if ("));
			convert_expression_(if_statement_->children_->op_Element(p_int(1)), definitions_);
			definitions_->EndLine_(p_string(".Value)"));
			emit_statement_(if_statement_->children_->op_Element(p_int(2)));
			::Semantic_Node_ const *_Nullable const elseClause_ = if_statement_->first_child_(ElseClause_);
			if (elseClause_->op_NotEqual(::None).Value)
			{
				if_statement_ = elseClause_->first_child_(IfStatement_);
				if (if_statement_->op_NotEqual(::None).Value)
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
	else if (statement_->kind_->op_Equal(BreakStatement_).Value)
	{
		definitions_->WriteLine_(p_string("break;"));
	}
	else if (statement_->kind_->op_Equal(ContinueStatement_).Value)
	{
		definitions_->WriteLine_(p_string("continue;"));
	}
	else if (statement_->kind_->op_Equal(LocalDeclarationStatement_).Value)
	{
		::Semantic_Node_ const *_Nonnull const variable_declaration_ = statement_->children_->op_Element(p_int(0));
		p_string const variable_name_ = variable_declaration_->first_child_(Identifier_)->get_text_();
		::Semantic_Node_ const *_Nonnull const variable_type_ = variable_declaration_->children_->op_Element(p_int(3));
		p_bool const mutable_binding_ = variable_declaration_->has_child_(VarKeyword_);
		definitions_->BeginLine_(convert_type_(mutable_binding_, variable_type_));
		definitions_->Write_(p_string(" ").op_Add(variable_name_)->op_Add(p_string("_")));
		if (variable_declaration_->has_child_(Equals_).Value)
		{
			definitions_->Write_(p_string(" = "));
			convert_expression_(variable_declaration_->children_->op_Element(p_int(5)), definitions_);
		}

		definitions_->EndLine_(p_string(";"));
	}
	else if (statement_->kind_->op_Equal(ExpressionStatement_).Value)
	{
		definitions_->BeginLine_(p_string(""));
		convert_expression_(statement_->children_->op_Element(p_int(0)), definitions_);
		definitions_->EndLine_(p_string(";"));
	}
	else
	{
		NOT_IMPLEMENTED_(p_string("statement.kind=").op_Add(statement_->kind_));
	}
}

auto ::Emitter_::emit_method_body_(::Semantic_Node_ const *_Nonnull const block_, p_bool const is_associated_function_) -> void
{
	auto self = this;
	definitions_->BeginBlock_();
	if (is_associated_function_->op_Not().Value)
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
	if (is_value_type_.Value)
	{
		definitions_->WriteLine_(self_type_->op_Add(p_string(" self;")));
	}
	else
	{
		definitions_->WriteLine_(self_type_->op_Add(p_string(" self = this;")));
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
	if (access_modifer_->op_NotEqual(current_access_level_).Value)
	{
		if (LogicalOr(access_modifer_->op_Equal(PublicKeyword_), [&] { return access_modifer_->op_Equal(InternalKeyword_); }).Value)
		{
			class_declarations_->EndLine_(p_string("public:"));
			return PublicKeyword_;
		}
		else if (access_modifer_->op_Equal(ProtectedKeyword_).Value)
		{
			class_declarations_->EndLine_(p_string("public:"));
		}
		else if (access_modifer_->op_Equal(PrivateKeyword_).Value)
		{
			class_declarations_->EndLine_(p_string("private:"));
		}
		else
		{
			THROW_EXCEPTION_(p_string("Invalid access modifier in Emitter.emit_member_declaration(). kind is ").op_Add(access_modifer_));
		}
	}

	return access_modifer_;
}

auto ::Emitter_::emit_member_declaration_(::Semantic_Node_ const *_Nonnull const member_, p_string const class_name_, p_bool const is_value_type_, p_int const current_access_level_) -> p_int
{
	auto self = this;
	p_int access_modifer_ = member_->children_->op_Element(p_int(0))->kind_;
	access_modifer_ = emit_access_modifer_(current_access_level_, access_modifer_);
	if (member_->kind_->op_Equal(ConstructorDeclaration_).Value)
	{
		p_string const parameters_ = convert_parameter_list_(member_->first_child_(ParameterList_));
		p_string full_name_ = p_string("construct");
		::Semantic_Node_ const *_Nullable const constructor_name_ = member_->first_child_(Identifier_);
		if (constructor_name_->op_NotEqual(::None).Value)
		{
			full_name_ = p_string("construct_").op_Add(constructor_name_->get_text_());
		}

		p_string return_type_ = p_string("::").op_Add(class_name_)->op_Add(p_string("_"));
		if (is_value_type_->op_Not().Value)
		{
			return_type_ = return_type_.op_Add(p_string("*"));
		}

		class_declarations_->BeginLine_(p_string(""));
		if (is_value_type_.Value)
		{
			class_declarations_->Write_(p_string("static "));
		}

		class_declarations_->EndLine_(p_string("auto ").op_Add(full_name_)->op_Add(parameters_)->op_Add(p_string(" -> "))->op_Add(return_type_)->op_Add(p_string(";")));
		definitions_->ElementSeparatorLine_();
		definitions_->WriteLine_(p_string("auto ::").op_Add(class_name_)->op_Add(p_string("_::"))->op_Add(full_name_)->op_Add(parameters_)->op_Add(p_string(" -> "))->op_Add(return_type_));
		emit_constructor_body_(member_->first_child_(Block_), return_type_, is_value_type_);
	}
	else if (member_->kind_->op_Equal(FieldDeclaration_).Value)
	{
		::Semantic_Node_ const *_Nonnull const variable_declaration_ = member_->first_child_(VariableDeclaration_);
		p_string const field_name_ = variable_declaration_->children_->op_Element(p_int(1))->get_text_();
		::Semantic_Node_ const *_Nonnull const field_type_ = variable_declaration_->children_->op_Element(p_int(3));
		p_string const cpp_type_ = convert_type_(p_bool(true), field_type_);
		class_declarations_->WriteLine_(cpp_type_.op_Add(p_string(" "))->op_Add(field_name_)->op_Add(p_string("_;")));
	}
	else if (member_->kind_->op_Equal(MethodDeclaration_).Value)
	{
		p_string const method_name_ = member_->children_->op_Element(p_int(1))->get_text_();
		::Semantic_Node_ const *_Nonnull const parameter_list_ = member_->children_->op_Element(p_int(2));
		p_string const parameters_ = convert_parameter_list_(parameter_list_);
		::Semantic_Node_ const *_Nullable const self_parameter_ = parameter_list_->first_child_(SelfParameter_);
		p_bool const is_associated_function_ = self_parameter_->op_Equal(::None);
		p_bool const mutable_self_ = LogicalAnd(is_associated_function_.op_Not(), [&] { return self_parameter_->has_child_(MutableKeyword_); });
		::Semantic_Node_ const *_Nonnull const return_type_ = member_->children_->op_Element(p_int(4));
		p_string const cpp_type_ = convert_type_(p_bool(true), return_type_);
		p_string static_modifier_ = p_string("");
		if (is_associated_function_.Value)
		{
			static_modifier_ = p_string("static ");
		}

		p_string constModifier_ = p_string("");
		if (LogicalAnd(mutable_self_.op_Not(), [&] { return is_associated_function_.op_Not(); }).Value)
		{
			constModifier_ = p_string("const ");
		}

		class_declarations_->WriteLine_(static_modifier_.op_Add(p_string("auto "))->op_Add(method_name_)->op_Add(p_string("_"))->op_Add(parameters_)->op_Add(p_string(" "))->op_Add(constModifier_)->op_Add(p_string("-> "))->op_Add(cpp_type_)->op_Add(p_string(";")));
		definitions_->ElementSeparatorLine_();
		definitions_->WriteLine_(p_string("auto ::").op_Add(class_name_)->op_Add(p_string("_::"))->op_Add(method_name_)->op_Add(p_string("_"))->op_Add(parameters_)->op_Add(p_string(" "))->op_Add(constModifier_)->op_Add(p_string("-> "))->op_Add(cpp_type_));
		::Semantic_Node_ const *_Nonnull const block_ = member_->children_->op_Element(p_int(5));
		emit_method_body_(block_, is_associated_function_);
	}
	else
	{
		definitions_->Error_(p_string("Could not emit member of type ").op_Add(member_->kind_));
	}

	return access_modifer_;
}

auto ::Emitter_::emit_default_constructor_(p_string const type_name_, p_bool const is_value_type_, p_int const current_access_level_) -> void
{
	auto self = this;
	emit_access_modifer_(current_access_level_, PublicKeyword_);
	p_string return_type_ = p_string("::").op_Add(type_name_)->op_Add(p_string("_"));
	if (is_value_type_->op_Not().Value)
	{
		return_type_ = return_type_.op_Add(p_string("*"));
	}

	class_declarations_->BeginLine_(p_string(""));
	if (is_value_type_.Value)
	{
		class_declarations_->Write_(p_string("static "));
	}

	class_declarations_->Write_(p_string("auto construct() -> ").op_Add(return_type_));
	if (is_value_type_.Value)
	{
		class_declarations_->EndLine_(p_string(" { return ").op_Add(type_name_)->op_Add(p_string("_(); }")));
	}
	else
	{
		class_declarations_->EndLine_(p_string(" { return this; }"));
	}
}

auto ::Emitter_::emit_declaration_(::Semantic_Node_ const *_Nonnull const declaration_) -> void
{
	auto self = this;
	if (declaration_->kind_->op_Equal(GlobalDeclaration_).Value)
	{
		::Semantic_Node_ const *_Nonnull const variable_declaration_ = declaration_->children_->op_Element(p_int(1));
		p_string const variable_name_ = variable_declaration_->children_->op_Element(p_int(1))->get_text_();
		::Semantic_Node_ const *_Nonnull const variable_type_ = variable_declaration_->children_->op_Element(p_int(3));
		p_bool const mutable_binding_ = variable_declaration_->has_child_(VarKeyword_);
		p_string const cpp_type_ = convert_type_(mutable_binding_, variable_type_);
		global_definitions_->BeginLine_(cpp_type_);
		global_definitions_->Write_(p_string(" ").op_Add(variable_name_)->op_Add(p_string("_ = ")));
		::Semantic_Node_ const *_Nonnull const expression_ = variable_declaration_->children_->op_Element(p_int(5));
		convert_expression_(expression_, global_definitions_);
		global_definitions_->EndLine_(p_string(";"));
	}
	else if (declaration_->kind_->op_Equal(ClassDeclaration_).Value)
	{
		p_string const class_name_ = declaration_->children_->op_Element(p_int(2))->get_text_();
		type_declarations_->WriteLine_(p_string("class ").op_Add(class_name_)->op_Add(p_string("_;")));
		class_declarations_->ElementSeparatorLine_();
		class_declarations_->WriteLine_(p_string("class ").op_Add(class_name_)->op_Add(p_string("_")));
		class_declarations_->BeginBlock_();
		class_declarations_->EndLine_(p_string("public:"));
		class_declarations_->WriteLine_(p_string("p_bool op_Equal(").op_Add(class_name_)->op_Add(p_string("_ const * other) const { return this == other; }")));
		class_declarations_->WriteLine_(p_string("p_bool op_NotEqual(").op_Add(class_name_)->op_Add(p_string("_ const * other) const { return this != other; }")));
		p_int current_access_level_ = PublicKeyword_;
		p_bool has_constructors_ = p_bool(false);
		for (::Semantic_Node_ const *_Nonnull const member_ : *(declaration_->members_()))
		{
			has_constructors_ = LogicalOr(has_constructors_, [&] { return member_->kind_->op_Equal(ConstructorDeclaration_); });
			current_access_level_ = emit_member_declaration_(member_, class_name_, p_bool(false), current_access_level_);
		}

		if (has_constructors_.op_Not().Value)
		{
			emit_default_constructor_(class_name_, p_bool(false), current_access_level_);
		}

		class_declarations_->EndBlockWithSemicolon_();
	}
	else if (declaration_->kind_->op_Equal(StructDeclaration_).Value)
	{
		p_string const struct_name_ = declaration_->children_->op_Element(p_int(2))->get_text_();
		type_declarations_->WriteLine_(p_string("struct ").op_Add(struct_name_)->op_Add(p_string("_;")));
		class_declarations_->ElementSeparatorLine_();
		class_declarations_->WriteLine_(p_string("struct ").op_Add(struct_name_)->op_Add(p_string("_ final")));
		class_declarations_->BeginBlock_();
		class_declarations_->EndLine_(p_string("public:"));
		class_declarations_->WriteLine_(struct_name_.op_Add(p_string("_ * operator->() { return this; }")));
		class_declarations_->WriteLine_(struct_name_.op_Add(p_string("_ const * operator->() const { return this; }")));
		class_declarations_->WriteLine_(struct_name_.op_Add(p_string("_ & operator* () { return *this; }")));
		class_declarations_->WriteLine_(struct_name_.op_Add(p_string("_ const & operator* () const { return *this; }")));
		p_int current_access_level_ = PublicKeyword_;
		p_bool has_constructors_ = p_bool(false);
		for (::Semantic_Node_ const *_Nonnull const member_ : *(declaration_->members_()))
		{
			has_constructors_ = LogicalOr(has_constructors_, [&] { return member_->kind_->op_Equal(ConstructorDeclaration_); });
			current_access_level_ = emit_member_declaration_(member_, struct_name_, p_bool(true), current_access_level_);
		}

		if (has_constructors_.op_Not().Value)
		{
			emit_default_constructor_(struct_name_, p_bool(true), current_access_level_);
		}

		class_declarations_->EndBlockWithSemicolon_();
	}
	else if (declaration_->kind_->op_Equal(EnumDeclaration_).Value)
	{
		p_string const enum_name_ = declaration_->children_->op_Element(p_int(3))->get_text_();
		type_declarations_->WriteLine_(p_string("enum class ").op_Add(enum_name_)->op_Add(p_string("_;")));
		class_declarations_->ElementSeparatorLine_();
		class_declarations_->WriteLine_(p_string("enum class ").op_Add(enum_name_)->op_Add(p_string("_")));
		class_declarations_->BeginBlock_();
		for (::Semantic_Node_ const *_Nonnull const member_ : *(declaration_->children_))
		{
			if (member_->kind_->op_Equal(EnumMemberDeclaration_).Value)
			{
				p_string const member_name_ = member_->children_->op_Element(p_int(0))->get_text_();
				class_declarations_->BeginLine_(member_name_.op_Add(p_string("_")));
				::Semantic_Node_ const *_Nullable const member_value_ = member_->first_child_(Number_);
				if (member_value_->op_NotEqual(::None).Value)
				{
					class_declarations_->Write_(p_string(" = "));
					class_declarations_->Write_(member_value_->get_text_());
				}

				class_declarations_->EndLine_(p_string(","));
			}
		}

		class_declarations_->EndBlockWithSemicolon_();
	}
	else if (declaration_->kind_->op_Equal(FunctionDeclaration_).Value)
	{
		p_string const name_ = declaration_->children_->op_Element(p_int(1))->get_text_();
		p_bool const is_main_ = LogicalOr(name_.op_Equal(p_string("Main")), [&] { return name_.op_Equal(p_string("main")); });
		if (is_main_.Value)
		{
			main_function_name_ = name_;
		}

		p_string const parameters_ = convert_parameter_list_(declaration_->children_->op_Element(p_int(2)), is_main_);
		::Semantic_Node_ const *_Nonnull const return_type_ = declaration_->children_->op_Element(p_int(4));
		p_string const cpp_type_ = convert_type_(p_bool(true), return_type_);
		function_declarations_->WriteLine_(p_string("auto ").op_Add(name_)->op_Add(p_string("_"))->op_Add(parameters_)->op_Add(p_string(" -> "))->op_Add(cpp_type_)->op_Add(p_string(";")));
		definitions_->ElementSeparatorLine_();
		definitions_->WriteLine_(p_string("auto ").op_Add(name_)->op_Add(p_string("_"))->op_Add(parameters_)->op_Add(p_string(" -> "))->op_Add(cpp_type_));
		if (is_main_.Value)
		{
			if (main_function_return_type_->op_NotEqual(p_string("")).Value)
			{
				definitions_->Error_(p_string("Multiple declarations of main"));
			}

			main_function_return_type_ = cpp_type_;
		}

		emit_statement_(declaration_->children_->op_Element(p_int(5)));
	}
	else if (declaration_->kind_->op_Equal(EndOfFileToken_).Value)
	{
	}
	else
	{
		definitions_->Error_(p_string("Could not emit declaration of type ").op_Add(declaration_->kind_));
	}
}

auto ::Emitter_::emit_compilation_unit_(::Semantic_Node_ const *_Nonnull const unit_) -> void
{
	auto self = this;
	for (::Semantic_Node_ const *_Nonnull const declaration_ : *(unit_->children_))
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

	if (resources_->op_Magnitude()->op_GreaterThan(p_int(0)).Value)
	{
		definitions_->EndLine_(p_string(""));
	}

	::System_::Text_::String_Builder_ *_Nonnull const args_ = (new ::System_::Text_::String_Builder_())->construct();
	if (main_function_accepts_console_.Value)
	{
		args_->Append_(p_string("new ::System_::Console_::Console_()"));
	}

	if (main_function_accepts_args_.Value)
	{
		if (main_function_accepts_console_.Value)
		{
			args_->Append_(p_string(", "));
		}

		args_->Append_(p_string("new ::System_::Console_::Arguments_(argc, argv)"));
	}

	if (main_function_return_type_->op_Equal(p_string("void")).Value)
	{
		definitions_->WriteLine_(main_function_name_->op_Add(p_string("_("))->op_Add(args_->ToString_())->op_Add(p_string(");")));
		definitions_->WriteLine_(p_string("return 0;"));
	}
	else
	{
		definitions_->WriteLine_(p_string("return ").op_Add(main_function_name_)->op_Add(p_string("_("))->op_Add(args_->ToString_())->op_Add(p_string(").Value;")));
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

auto ::Namespace_Name_::construct(::System_::Collections_::List_<p_string> const *_Nonnull const segments_) -> ::Namespace_Name_*
{
	::Namespace_Name_* self = this;
	self->segments_ = segments_;
	return self;
}

auto global_namespace_() -> ::Namespace_Name_ const *_Nonnull
{
	return (new ::Namespace_Name_())->construct((new ::System_::Collections_::List_<p_string>())->construct());
}

auto ::Package_Name_::construct(p_string const text_) -> ::Package_Name_*
{
	::Package_Name_* self = this;
	self->text_ = text_;
	return self;
}

auto ::Symbol_::construct(p_string const name_) -> ::Symbol_*
{
	::Symbol_* self = this;
	self->name_ = name_;
	kind_ = IdentifierSymbol_;
	declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	is_primitive_ = p_bool(false);
	return self;
}

auto ::Symbol_::construct(p_string const name_, p_int const kind_) -> ::Symbol_*
{
	::Symbol_* self = this;
	self->name_ = name_;
	self->kind_ = kind_;
	declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	is_primitive_ = p_bool(false);
	return self;
}

auto ::Symbol_::construct(p_string const name_, p_int const kind_, ::System_::Collections_::List_<::Symbol_ const *_Nonnull> *_Nonnull const children_) -> ::Symbol_*
{
	::Symbol_* self = this;
	self->name_ = name_;
	self->kind_ = kind_;
	declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	self->children_ = children_;
	is_primitive_ = p_bool(false);
	return self;
}

auto ::Symbol_::construct_primitive(p_string const name_, ::Type_ const *_Nonnull const declares_type_) -> ::Symbol_*
{
	::Symbol_* self = this;
	assert_(name_->ByteLength_()->op_GreaterThan(p_int(0)), p_string(""));
	assert_(declares_type_->op_NotEqual(::None), p_string("name=").op_Add(name_));
	assert_(declares_type_->is_primitive_, p_string("name=").op_Add(name_));
	self->name_ = name_;
	self->kind_ = SpecialSymbol_;
	self->is_primitive_ = p_bool(true);
	self->type_ = ::None;
	self->declares_type_ = declares_type_;
	self->declarations_ = (new ::System_::Collections_::List_<::Semantic_Node_ const *_Nonnull>())->construct();
	self->children_ = (new ::System_::Collections_::List_<::Symbol_ const *_Nonnull>())->construct();
	return self;
}

auto ::Symbol_::get_(p_string const name_, p_int const kind_) const -> ::Symbol_ const *_Nullable
{
	auto self = this;
	for (::Symbol_ const *_Nonnull const child_ : *(children_))
	{
		if (LogicalAnd(child_->name_->op_Equal(name_), [&] { return child_->kind_->op_Equal(kind_); }).Value)
		{
			return child_;
		}
	}

	return ::None;
}

auto ::Symbol_::declares_value_type_() const -> p_bool
{
	auto self = this;
	if (kind_->op_Equal(IdentifierSymbol_).Value)
	{
		if (declarations_->op_Magnitude()->op_Equal(p_int(0)).Value)
		{
			THROW_EXCEPTION_(p_string("Symbol.is_value_type() could not determine if IdentifierSymbol `").op_Add(name_)->op_Add(p_string("` is a value type. No declarations.")));
		}

		::Semantic_Node_ const *_Nonnull const declaration_ = declarations_->op_Element(p_int(0));
		if (LogicalOr(declaration_->kind_->op_Equal(ClassDeclaration_), [&] { return declaration_->kind_->op_Equal(NamespaceDeclaration_); }).Value)
		{
			return p_bool(false);
		}
		else if (declaration_->kind_->op_Equal(StructDeclaration_).Value)
		{
			return p_bool(true);
		}
		else
		{
			THROW_EXCEPTION_(p_string("Could not determine if IdentifierSymbol `").op_Add(name_)->op_Add(p_string("` is a value type. Declaration of type "))->op_Add(declaration_->kind_));
		}
	}
	else if (kind_->op_Equal(SpecialSymbol_).Value)
	{
		return p_bool(true);
	}
	else
	{
		THROW_EXCEPTION_(p_string("Symbol.is_value_type() is not defined for Symbol_Kind ").op_Add(kind_));
	}
}

auto ::Symbol_::get_type_() const -> ::Type_ const *_Nullable
{
	auto self = this;
	if (kind_->op_Equal(SpecialSymbol_).Value)
	{
		return (new ::Type_())->construct(self);
	}

	if (declarations_->op_Magnitude()->op_GreaterThan(p_int(0)).Value)
	{
		::Semantic_Node_ const *_Nonnull const declaration_ = declarations_->op_Element(p_int(0));
		assert_(declaration_->op_NotEqual(::None), p_string("for '").op_Add(name_)->op_Add(p_string("'")));
		return declaration_->type_;
	}

	return ::None;
}

auto ::Type_::construct(::Symbol_ const *_Nonnull const symbol_) -> ::Type_*
{
	::Type_* self = this;
	assert_(symbol_->op_NotEqual(::None), p_string(""));
	package_ = ::None;
	namespace_ = ::None;
	name_ = symbol_->name_;
	is_primitive_ = symbol_->is_primitive_;
	is_value_type_ = symbol_->declares_value_type_();
	if (is_value_type_.Value)
	{
		kind_ = ValueType_;
	}
	else
	{
		kind_ = ReferenceType_;
	}

	immutable_ = p_bool(true);
	return self;
}

auto ::Type_::construct(::Package_Name_ const *_Nonnull const package_, ::Namespace_Name_ const *_Nonnull const namespace_, p_int const kind_, p_string const name_, p_bool const is_primitive_, p_bool const is_value_type_, p_bool const immutable_) -> ::Type_*
{
	::Type_* self = this;
	self->package_ = package_;
	self->namespace_ = namespace_;
	self->kind_ = kind_;
	self->name_ = name_;
	self->is_primitive_ = is_primitive_;
	self->is_value_type_ = is_value_type_;
	self->immutable_ = immutable_;
	return self;
}

auto ::Type_::make_mutable_() const -> ::Type_ const *_Nonnull
{
	auto self = this;
	return (new ::Type_())->construct(package_, namespace_, kind_, name_, is_primitive_, is_value_type_, p_bool(false));
}

auto ::Type_::make_immutable_() const -> ::Type_ const *_Nonnull
{
	auto self = this;
	return (new ::Type_())->construct(package_, namespace_, kind_, name_, is_primitive_, is_value_type_, p_bool(true));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		resource_manager_->AddResource(p_string("RuntimeLibrary.cpp"), p_string("#include \"RuntimeLibrary.h\"\n#include <map>\n\np_uint p_int::AsUInt_() const\n{\n	if(this->Value < 0)\n		throw std::range_error(\"Can't convert negative number to unsigned\");\n\n	return this->Value;\n}\n\nchar p_code_point::CharValue() const\n{\n	if(this->Value > 0xFF)\n		throw std::range_error(\"Unicode char values not yet supported\");\n\n	return this->Value;\n}\n\np_string p_string::construct(p_code_point c, p_int repeat)\n{\n	p_string self;\n	self.Length = repeat.Value;\n	char* buffer = new char[repeat.Value];\n	for (int i = 0; i < repeat.Value; i++)\n		buffer[i] = c.CharValue();\n\n	self.Buffer = buffer;\n	return self;\n}\n\np_string::p_string(const char* s)\n	: Length(std::strlen(s)), Buffer(s)\n{\n}\n\np_string::p_string(int length, const char* s)\n	: Length(length), Buffer(s)\n{\n}\n\nchar const * p_string::cstr() const\n{\n	auto buffer = new char[Length + 1];\n	std::memcpy(buffer, Buffer, Length);\n	buffer[Length] = 0;\n	return buffer;\n}\n\np_string::p_string(p_int other)\n	: Length(0), Buffer(0)\n{\n	char* buffer = new char[12]; // -2,147,483,648 to 2,147,483,647 plus null terminator\n	int length = std::sprintf(buffer,\"%d\", other.Value);\n	if(length <= 0) throw std::runtime_error(\"Could not convert int to string\");\n	Length = length;\n	Buffer = buffer;\n}\n\np_string::p_string(p_code_point other)\n	: Length(1), Buffer(new char[1] { other.CharValue() })\n{\n}\n\np_string p_string::Substring_(p_int start, p_int length) const\n{\n	return p_string(length.Value, Buffer + start.Value);\n}\n\np_string p_string::Replace_(p_string oldValue, p_string newValue) const\n{\n	p_string buffer = \"\";\n	int limit = Length - oldValue.Length + 1;\n	int lastIndex = 0;\n	for(int i=0; i < limit; i++)\n		if (Substring_(i, oldValue.Length).op_Equal(oldValue).Value)\n		{\n			buffer = buffer.op_Add(Substring_(lastIndex, i-lastIndex)).op_Add(newValue);\n			i += oldValue.Length; // skip over the value we just matched\n			lastIndex = i;\n			i--; // we need i-- to offset the i++ that is about to happen\n		}\n\n	buffer = buffer.op_Add(Substring_(lastIndex, Length - lastIndex));\n	return buffer;\n}\n\np_int p_string::LastIndexOf_(p_code_point c) const\n{\n	for(int i = Length - 1; i >= 0; i--)\n		if(Buffer[i] == c.CharValue())\n			return i;\n\n	return -1; // TODO should return none\n}\n\np_int p_string::index_of_(p_code_point c) const\n{\n	for(int i = 0; i < Length; i++)\n		if(Buffer[i] == c.CharValue())\n			return i;\n\n	return -1;\n}\n\np_string p_string::op_Add(p_string const & value) const\n{\n	int newLength = Length + value.Length;\n	char* chars = new char[newLength];\n	size_t offset = sizeof(char) * Length;\n	std::memcpy(chars, Buffer, offset);\n	std::memcpy(chars + offset, value.Buffer, value.Length);\n	return p_string(newLength, chars);\n}\n\np_bool p_string::op_Equal(p_string const & other) const\n{\n	if (Length != other.Length)\n		return false;\n\n	for (int i = 0; i < Length; i++)\n		if (Buffer[i] != other.Buffer[i])\n			return false;\n\n	return true;\n}\n\nbool operator < (p_string const & lhs, p_string const & rhs)\n{\n    return std::strcmp(lhs.cstr(), rhs.cstr()) < 0;\n}\n\nstd::map<p_string, p_string> resourceValues;\n\np_string const & ResourceManager::GetString_(p_string resourceName)\n{\n	return resourceValues.at(resourceName);\n}\nvoid ResourceManager::AddResource(p_string name, p_string value)\n{\n	resourceValues.insert(std::make_pair(name, value));\n}\n\nResourceManager *const resource_manager_ = new ResourceManager();\n\nnamespace system_\n{\n	namespace Console_\n	{\n		void Console_::Write_(p_string value)\n		{\n			std::printf(\"%.*s\", value.Length, value.Buffer);\n		}\n\n		void Console_::WriteLine_(p_string value)\n		{\n			std::printf(\"%.*s\\n\", value.Length, value.Buffer);\n		}\n\n		void Console_::WriteLine_()\n		{\n			std::printf(\"\\n\");\n		}\n\n		Arguments_::Arguments_(int argc, char const *const * argv)\n			: Count(argc-1)\n		{\n			args = new p_string[Count];\n			for (int i = 0; i < Count; i++)\n				args[i] = p_string(argv[i+1]);\n		}\n	}\n\n	namespace IO_\n	{\n		File_Reader_* File_Reader_::construct(const p_string& fileName)\n		{\n			std::FILE* foo;\n			auto fname = fileName.cstr();\n			file = std::fopen(fname, \"rb\");\n			delete[] fname;\n			return this;\n		}\n\n		p_string File_Reader_::ReadToEndSync_()\n		{\n			std::fseek(file, 0, SEEK_END);\n			auto length = std::ftell(file);\n			std::fseek(file, 0, SEEK_SET);\n			auto buffer = new char[length];\n			length = std::fread(buffer, sizeof(char), length, file);\n			return p_string(length, buffer);\n		}\n\n		void File_Reader_::Close_()\n		{\n			std::fclose(file);\n		}\n\n		File_Writer_* File_Writer_::construct(const p_string& fileName)\n		{\n			auto fname = fileName.cstr();\n			file = std::fopen(fname, \"wb\"); // TODO check error\n			delete[] fname;\n			return this;\n		}\n\n		void File_Writer_::Write_(const p_string& value)\n		{\n			std::fwrite(value.Buffer, sizeof(char), value.Length, file);\n		}\n\n		void File_Writer_::Close_()\n		{\n			std::fclose(file);\n		}\n	}\n\n	namespace Text_\n	{\n		String_Builder_* String_Builder_::construct(p_string const & value)\n		{\n			buffer = value;\n			return this;\n		}\n\n		void String_Builder_::Append_(p_string const & value)\n		{\n			buffer = buffer.op_Add(value);\n		}\n\n		void String_Builder_::Append_(String_Builder_ const * value)\n		{\n			buffer = buffer.op_Add(value->buffer);\n		}\n\n		void String_Builder_::AppendLine_(p_string const & value)\n		{\n			buffer = buffer.op_Add(value).op_Add(p_string(\"\\n\"));\n		}\n\n		void String_Builder_::AppendLine_()\n		{\n			buffer = buffer.op_Add(p_string(\"\\n\"));\n		}\n\n		void String_Builder_::Remove_(p_int start, p_int length)\n		{\n			buffer = buffer.Substring_(0, start).op_Add(buffer.Substring_(start.Value+length.Value));\n		}\n\n		void String_Builder_::Remove_(p_int start)\n		{\n			String_Builder_::Remove_(start, buffer.Length-start.Value);\n		}\n	}\n}\n"));
		resource_manager_->AddResource(p_string("RuntimeLibrary.h"), p_string("// On windows this disables warnings about using fopen_s instead of fopen\n// It must be defined before including the headers.\n#define _CRT_SECURE_NO_WARNINGS\n#include <cstring>\n#include <cstdio>\n#include <cstdint>\n#include <stdexcept>\n\ntemplate<typename T, typename F>\nT LogicalAnd(T const & lhs, F rhs)\n{\n	return lhs.op_False().Value ? lhs : lhs.op_And(rhs());\n}\n\ntemplate<typename T, typename F>\nT LogicalOr(T const & lhs, F rhs)\n{\n	return lhs.op_True().Value ? lhs : lhs.op_Or(rhs());\n}\n\nstruct p_bool\n{\npublic:\n	// Runtime Use Members\n	bool Value;\n\n	p_bool() = default;\n	p_bool(bool value): Value(value) {}\n\n	p_bool * operator->() { return this; }\n	p_bool const * operator->() const { return this; }\n	p_bool & operator* () { return *this; }\n	p_bool const & operator* () const { return *this; }\n\n	// Adamant Members\n	static auto construct() -> p_bool { return p_bool(false); }\n	p_bool op_Not() const { return !this->Value; }\n	p_bool op_True() const { return this->Value; }\n	p_bool op_False() const { return !this->Value; }\n	p_bool op_And(p_bool other) const { return this->Value & other.Value; }\n	p_bool op_Or(p_bool other) const { return this->Value | other.Value; }\n};\n\nstruct p_uint;\n\nstruct p_int\n{\npublic:\n	// Runtime Use Members\n	std::int32_t Value;\n\n	p_int() = default;\n	p_int(std::int32_t value): Value(value) {}\n\n	p_int * operator->() { return this; }\n	p_int const * operator->() const { return this; }\n	p_int & operator* () { return *this; }\n	p_int const & operator* () const { return *this; }\n\n	// Hack to support conversion of uint to int for now\n	p_int(p_uint value);\n\n	// Adamant Members\n	static auto construct() -> p_int { return 0; }\n	void op_AddAssign(p_int other) { this->Value += other.Value; }\n	void op_SubtractAssign(p_int other) { this->Value -= other.Value; }\n	p_bool op_Equal(p_int other) const { return this->Value == other.Value; }\n	p_bool op_NotEqual(p_int other) const { return this->Value != other.Value; }\n	p_bool op_LessThan(p_int other) const { return this->Value < other.Value; }\n	p_bool op_LessThanOrEqual(p_int other) const { return this->Value <= other.Value; }\n	p_bool op_GreaterThan(p_int other) const { return this->Value > other.Value; }\n	p_bool op_GreaterThanOrEqual(p_int other) const { return this->Value >= other.Value; }\n	p_int op_Add(p_int other) const { return this->Value + other.Value; }\n	p_int op_Subtract(p_int other) const { return this->Value - other.Value; }\n	p_int op_Negate() const { return -this->Value; }\n	p_int op_Multiply(p_int other) const { return this->Value * other.Value; }\n	p_int op_Divide(p_int other) const { return this->Value / other.Value; }\n	p_int op_Remainder(p_int other) const { return this->Value % other.Value; }\n	p_int op_Magnitude() const { if(this->Value==INT32_MIN) throw std::overflow_error(\"Can't take |int.Min|\"); return this->Value < 0 ? -this->Value : this->Value; }\n\n	// Hack because we don't support as correctly yet\n	p_uint AsUInt_() const;\n};\n\nstruct p_uint\n{\npublic:\n	// Runtime Use Members\n	std::uint32_t Value;\n\n	p_uint() = default;\n	p_uint(std::uint32_t value): Value(value) {}\n\n	p_uint * operator->() { return this; }\n	p_uint const * operator->() const { return this; }\n	p_uint & operator* () { return *this; }\n	p_uint const & operator* () const { return *this; }\n\n	// Hack to support conversion of int to uint for now\n	p_uint(p_int value): Value(value.Value) {}\n\n	// Adamant Members\n	static auto construct() -> p_uint { return 0; }\n	void op_AddAssign(p_uint other) { this->Value += other.Value; }\n	void op_SubtractAssign(p_uint other) { this->Value -= other.Value; }\n	p_bool op_Equal(p_uint other) const { return this->Value == other.Value; }\n	p_bool op_NotEqual(p_uint other) const { return this->Value != other.Value; }\n	p_bool op_LessThan(p_uint other) const { return this->Value < other.Value; }\n	p_bool op_LessThanOrEqual(p_uint other) const { return this->Value <= other.Value; }\n	p_bool op_GreaterThan(p_uint other) const { return this->Value > other.Value; }\n	p_bool op_GreaterThanOrEqual(p_uint other) const { return this->Value >= other.Value; }\n	p_uint op_Add(p_uint other) const { return this->Value + other.Value; }\n	p_uint op_Subtract(p_uint other) const { return this->Value - other.Value; }\n};\n\ninline p_int::p_int(p_uint value)\n	: Value(value.Value)\n{\n}\n\nstruct p_code_point\n{\nprivate:\n	std::uint32_t Value;\n\npublic:\n	// Runtime Use Members\n	p_code_point() = default;\n	p_code_point(char value): Value(value) {}\n	char CharValue() const;\n\n	p_code_point * operator->() { return this; }\n	p_code_point const * operator->() const { return this; }\n	p_code_point & operator* () { return *this; }\n	p_code_point const & operator* () const { return *this; }\n\n	// Adamant Members\n	static auto construct() -> p_code_point { return '\\0'; }\n	p_bool op_Equal(p_code_point const & other) const { return this->Value == other.Value; }\n	p_bool op_NotEqual(p_code_point const & other) const { return this->Value != other.Value; }\n	// TODO: Not sure code_point should support these operations\n	p_bool op_LessThan(p_code_point other) const { return this->Value < other.Value; }\n	p_bool op_LessThanOrEqual(p_code_point other) const { return this->Value <= other.Value; }\n	p_bool op_GreaterThan(p_code_point other) const { return this->Value > other.Value; }\n	p_bool op_GreaterThanOrEqual(p_code_point other) const { return this->Value >= other.Value; }\n\n};\n\nstruct p_string\n{\npublic:\n	// Runtime Use Members\n	char const * Buffer;\n	int Length;\n\n	p_string() = default;\n	p_string(char const * s);\n	p_string(int length, char const * s);\n	char const * cstr() const;\n	p_string const * operator->() const { return this; }\n	p_string const & operator* () const { return *this; }\n\n	typedef char const * const_iterator;\n	const_iterator begin() const { return &Buffer[0]; }\n	const_iterator end() const { return &Buffer[Length]; }\n\n	// Hack to support conversion of int and code_point to strings for now\n	p_string(p_int other);\n	p_string(p_code_point other);\n\n	// Adamant Members\n	static auto construct() -> p_string { p_string self; self.Length = 0; self.Buffer = 0; return self; }\n	static auto construct(p_string value) -> p_string { return value; }\n	static auto construct(p_code_point c, p_int repeat) -> p_string;\n	// TODO ByteLength should be a property\n	p_int ByteLength_() const { return this->Length; }\n\n	p_string Substring_(p_int start, p_int length) const;\n	p_string Substring_(p_int start) const { return Substring_(start, Length-start.Value); }\n	p_string Replace_(p_string oldValue, p_string newValue) const;\n	p_int LastIndexOf_(p_code_point c) const;\n	p_int index_of_(p_code_point c) const;\n\n	p_code_point op_Element(p_int const index) const { return Buffer[index.Value]; }\n	p_string op_Add(p_string const & value) const;\n	p_bool op_Equal(p_string const & other) const;\n	p_bool op_NotEqual(p_string const & other) const { return !this->op_Equal(other).Value; }\n	p_bool op_LessThan(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) < 0; }\n	p_bool op_LessThanOrEqual(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) <= 0; }\n	p_bool op_GreaterThan(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) > 0; }\n	p_bool op_GreaterThanOrEqual(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) >= 0; }\n};\n\nclass ResourceManager\n{\npublic:\n	p_string const & GetString_(p_string resourceName);\n	void AddResource(p_string name, p_string value);\n};\n\nextern ResourceManager *const resource_manager_;\n\nclass NoneType\n{\npublic:\n	template<class T>\n	operator T*() const { return static_cast<T*>(0); }\n};\nstatic const NoneType None = NoneType();\n\ntemplate<typename T>\nstruct p_optional\n{\nprivate:\n	bool hasValue;\n	union\n    {\n        T data;\n    };\n\npublic:\n	p_optional(T const & value) : data(value), hasValue(true) {}\n	p_optional(::NoneType const & none) : hasValue(false) {}\n	T & operator->()\n	{\n		if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n		return data;\n	}\n	T const & operator->() const\n	{\n		if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n		return data;\n	}\n	T & operator* ()\n	{\n		if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n		return data;\n	}\n	T const & operator* () const\n	{\n		if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n		return data;\n	}\n};\n\n// A placeholder function until we get proper exceptions implemented\n_Noreturn inline void THROW_EXCEPTION_(const p_string& value)\n{\n	throw std::runtime_error(value.cstr());\n}\n\ninline void assert(const p_bool condition, const p_string code, const p_string message, const p_string file, const std::int32_t line)\n{\n	if(!condition.Value)\n		throw std::runtime_error(\n			p_string(\"Assertion failed: \").op_Add(code).op_Add(\", \").op_Add(message)\n			.op_Add(\", file \").op_Add(file).op_Add(\", line \").op_Add(p_int(line)).cstr());\n}\n\n#define assert_(condition, message) assert(condition, #condition, message, __FILE__, __LINE__)\n\n_Noreturn inline void NOT_IMPLEMENTED(const p_string message, const p_string function, const p_string file, const std::int32_t line)\n{\n	throw std::runtime_error(\n		p_string(\"Function \").op_Add(function)\n		.op_Add(p_string(\" not yet implemented, \")).op_Add(message).op_Add(p_string(\", \")).op_Add(file).op_Add(p_string(\", line \")).op_Add(p_int(line)).cstr());\n}\n\n#define NOT_IMPLEMENTED_(message) NOT_IMPLEMENTED(message, __func__, __FILE__, __LINE__)\n\n\n_Noreturn inline void UNREACHABLE(const p_string function, const p_string file, const std::int32_t line)\n{\n	throw std::runtime_error(\n		p_string(\"Reached \\\"UNREACHABLE\\\" statement in function \").op_Add(function)\n		.op_Add(p_string(\", \")).op_Add(file).op_Add(p_string(\", line \")).op_Add(p_int(line)).cstr());\n}\n\n#define UNREACHABLE_() UNREACHABLE(__func__, __FILE__, __LINE__)\n\nnamespace system_\n{\n	namespace Collections_\n	{\n		template<typename T>\n		class List_\n		{\n		private:\n			T* values;\n			int length;\n			int capacity;\n\n		public:\n			// Runtime Use Members\n			typedef T const * const_iterator;\n			const_iterator begin() const { return values; }\n			const_iterator end() const { return &values[length]; }\n\n			// Adamant Members\n			p_bool op_Equal(List_<T> const * other) const { return this == other; }\n			p_bool op_NotEqual(List_<T> const * other) const { return this != other; }\n\n			List_* construct() { values = 0; length = 0; capacity = 0; return this; }\n			void Add_(T value) { add_(value); }\n			void Clear_() { clear_(); }\n			void add_(T value);\n			void clear_() { length = 0; }\n			p_int op_Magnitude() const { return length; }\n			T const & op_Element(p_int const index) const;\n		};\n\n		template<typename T>\n		void List_<T>::add_(T value)\n		{\n			if(length >= capacity)\n			{\n				int newCapacity = capacity == 0 ? 16 : capacity * 2;\n				// Allocate uninitalized buffer (note `sizeof(char) == 1` always)\n				// Needed if T is a value type to avoid needing a default constructor\n				T* newValues = (T*)new char[newCapacity * sizeof(T)];\n				std::memcpy(newValues, values, length * sizeof(T));\n				values = newValues;\n				capacity = newCapacity;\n			}\n			values[length] = value;\n			length++;\n		}\n\n		template<typename T>\n		T const & List_<T>::op_Element(p_int const index) const\n		{\n			if(index.Value < 0 || index.Value >= length)\n				throw std::out_of_range(\"List index out of bounds\");\n			return values[index.Value];\n		}\n	}\n\n	namespace Console_\n	{\n		class Console_\n		{\n		public:\n			void Write_(p_string value);\n			void WriteLine_(p_string value);\n			void WriteLine_();\n		};\n\n		class Arguments_\n		{\n		private:\n			p_string* args;\n		public:\n			// Runtime Use Members\n			typedef p_string const * const_iterator;\n\n			Arguments_(int argc, char const *const * argv);\n			const_iterator begin() const { return &args[0]; }\n			const_iterator end() const { return &args[Count]; }\n\n			const int Count;\n\n			// Adamant Members\n\n			p_int op_Magnitude() const { return Count; }\n			p_string const & Get_(int const index) const { return args[index]; }\n		};\n	}\n\n	namespace IO_\n	{\n		class File_Reader_\n		{\n		private:\n			std::FILE* file;\n\n		public:\n			File_Reader_* construct(const p_string& fileName);\n			p_string ReadToEndSync_();\n			void Close_();\n		};\n\n		class File_Writer_\n		{\n		private:\n			std::FILE* file;\n\n		public:\n			File_Writer_* construct(const p_string& fileName);\n			void Write_(const p_string& value);\n			void Close_();\n		};\n	}\n\n	namespace Text_\n	{\n		class String_Builder_\n		{\n		private:\n			p_string buffer;\n		public:\n			// Runtime Use Members\n			String_Builder_() = default;\n\n			// Adamant Members\n			p_bool op_Equal(String_Builder_ const * other) const { return this == other; }\n			p_bool op_NotEqual(String_Builder_ const * other) const { return this != other; }\n\n			String_Builder_* construct() { buffer = p_string(\"\"); return this; }\n			String_Builder_* construct(p_string const & value);\n			void Append_(p_string const & value);\n			void Append_(String_Builder_ const * value);\n			void AppendLine_(p_string const& value);\n			void AppendLine_();\n			void Remove_(p_int start, p_int length);\n			void Remove_(p_int start);\n			p_string ToString_() const { return buffer; }\n		};\n	}\n}\n\nnamespace System_ = system_;\n"));

		return Main_(new ::System_::Console_::Console_(), new ::System_::Console_::Arguments_(argc, argv)).Value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
