#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Source_Text;
class t_Text_Line;
class t_Text_Lines;
class t_Text_Position;
class t_Text_Span;
class t_Source_File_Builder;
class t_Compilation_Unit;
class t_Package;
struct t_Package_Reference;
class t_Semantic_Node;
class t_Semantic_Tree_Builder;
class t_Compilation_Unit_Parser;
class t_Syntax_Node;
class t_Token_Stream;
class t_Diagnostic;
class t_Emitter;
class t_Name;
class t_Package_Name;
class t_Symbol;
class t_Type;
class t_Name_Subtable;
class t_Name_Table;

// Function Declarations
auto compile_(t_system__collections__List<t_Source_Text const *_Nonnull> const *_Nonnull const sources_) -> t_Package const *_Nonnull;
auto write_(t_system__console__Console *_Nonnull const console_, t_system__collections__List<t_Diagnostic const *_Nonnull> const *_Nonnull const diagnostics_) -> void;
auto has_errors_(t_system__collections__List<t_Diagnostic const *_Nonnull> const *_Nonnull const diagnostics_) -> bit;
auto main_(t_system__console__Console *_Nonnull const console_, t_system__console__Arguments const *_Nonnull const args_) -> i32;
auto read_source_(str const path_) -> t_Source_Text const *_Nonnull;
auto run_unit_tests_(t_system__console__Console *_Nonnull const console_) -> void;
inline t_Source_Text *_Nonnull new_t_Source_Text(str const package_, str const path_, str const text_);
auto line_starts_(str const text_) -> t_system__collections__List<i32> const *_Nonnull;
auto source_byte_length_(t_Source_Text const *_Nonnull const source_) -> i32;
auto position_of_start_(t_Source_Text const *_Nonnull const source_, t_Text_Span const *_Nonnull const span_) -> t_Text_Position const *_Nonnull;
inline t_Text_Line *_Nonnull new_t_Text_Line(t_Source_Text const *_Nonnull const source_, i32 const start_, i32 const length_);
inline t_Text_Line *_Nonnull new_t_Text_Line__spanning(t_Source_Text const *_Nonnull const source_, i32 const start_, i32 const end_);
inline t_Text_Lines *_Nonnull new_t_Text_Lines(t_Source_Text const *_Nonnull const source_, t_system__collections__List<i32> const *_Nonnull const start_of_line_);
auto line_count_(t_Text_Lines const *_Nonnull const lines_) -> i32;
auto get_line_(t_Text_Lines const *_Nonnull const lines_, i32 const line_number_) -> t_Text_Line const *_Nonnull;
auto line_containing_offset_(t_Text_Lines const *_Nonnull const lines_, i32 const character_offset_) -> i32;
inline t_Text_Position *_Nonnull new_t_Text_Position(i32 const character_offset_, i32 const line_, i32 const column_);
auto unit_test_Text_Position_() -> void;
auto Text_Position_retains_given_offeset_line_and_column_() -> void;
inline t_Text_Span *_Nonnull new_t_Text_Span(i32 const start_, i32 const length_);
auto format_error_(str const message_) -> str;
inline t_Source_File_Builder *_Nonnull new_t_Source_File_Builder();
auto error_(t_Source_File_Builder *_Nonnull const file_, str const message_) -> void;
auto begin_line_(t_Source_File_Builder *_Nonnull const file_, str const value_) -> void;
auto write_(t_Source_File_Builder *_Nonnull const file_, str const value_) -> void;
auto end_line_(t_Source_File_Builder *_Nonnull const file_, str const value_) -> void;
auto write_line_(t_Source_File_Builder *_Nonnull const file_, str const value_) -> void;
auto blank_line_(t_Source_File_Builder *_Nonnull const file_) -> void;
auto element_separator_line_(t_Source_File_Builder *_Nonnull const file_) -> void;
auto statement_separator_line_(t_Source_File_Builder *_Nonnull const file_) -> void;
auto begin_block_(t_Source_File_Builder *_Nonnull const file_) -> void;
auto end_block_(t_Source_File_Builder *_Nonnull const file_) -> void;
auto end_block_with_semicolon_(t_Source_File_Builder *_Nonnull const file_) -> void;
auto byte_length_(t_Source_File_Builder const *_Nonnull const file_) -> i32;
auto to_string_(t_Source_File_Builder *_Nonnull const file_) -> str;
inline t_Compilation_Unit *_Nonnull new_t_Compilation_Unit(t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_);
auto collect_diagnostics_(t_Compilation_Unit const *_Nonnull const compilation_unit_, t_system__collections__List<t_Diagnostic const *_Nonnull> *_Nonnull const diagnostics_) -> void;
inline t_Package *_Nonnull new_t_Package(t_Package_Name const *_Nonnull const name_, t_system__collections__List<t_Package_Reference> const *_Nonnull const references_, t_system__collections__List<t_Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_, t_Symbol const *_Nonnull const symbol_);
auto all_diagnostics_(t_Package const *_Nonnull const package_) -> t_system__collections__List<t_Diagnostic const *_Nonnull> const *_Nonnull;
inline t_Package_Reference new_t_Package_Reference(t_Package const *_Nonnull const package_);
inline t_Package_Reference new_t_Package_Reference(str const name_, t_Package const *_Nonnull const package_);
auto build_primitives_package_() -> t_Package const *_Nonnull;
auto build_primitive_symbols_(t_Package_Name const *_Nonnull const package_name_) -> t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull;
auto build_adamant_language_namespace_symbol_(t_Name const *_Nonnull const global_namespace_) -> t_Symbol const *_Nonnull;
auto build_optional_type_symbol_(t_Name const *_Nonnull const language_namespace_) -> t_Symbol const *_Nonnull;
auto build_primitive_symbol_(str const name_, t_Name const *_Nonnull const namespace_) -> t_Symbol const *_Nonnull;
auto build_fixed_point_primitives_(t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const symbols_, i32 const bits_, t_Name const *_Nonnull const namespace_) -> void;
auto unit_test_build_primitives_package_() -> void;
auto Package_name_is_dollar_primitives_() -> void;
auto Package_has_no_references_or_compilation_units_() -> void;
auto Package_symbol_has_package_name_() -> void;
auto Package_symbol_has_children_() -> void;
auto Package_contains_the_string_type_() -> void;
auto Package_contains_optional_type_() -> void;
auto build_runtime_library_package_() -> t_Package const *_Nonnull;
auto build_runtime_library_symbols_(t_Package_Name const *_Nonnull const package_name_) -> t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull;
auto build_function_symbol_(t_Name const *_Nonnull const name_) -> t_Symbol const *_Nonnull;
auto build_namespace_symbol_(t_Name const *_Nonnull const name_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const symbols_) -> t_Symbol const *_Nonnull;
auto build_class_symbol_(t_Name const *_Nonnull const namespace_, str const class_name_) -> t_Symbol const *_Nonnull;
auto build_class_symbol_(t_Name const *_Nonnull const namespace_, str const class_name_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_) -> t_Symbol const *_Nonnull;
auto build_generic_class_symbol_(t_Name const *_Nonnull const namespace_, str const class_name_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_) -> t_Symbol const *_Nonnull;
auto build_constructor_symbol_(str const name_) -> t_Symbol const *_Nonnull;
auto unit_test_build_runtime_library_package_() -> void;
auto Runtime_Library_Package_contains_system_package_() -> void;
auto System_namespace_contains_console_namespace_() -> void;
auto Console_namespace_contains_Console_class_() -> void;
auto System_namespace_contains_collections_namespace_() -> void;
auto Collections_namespace_contains_List_class_() -> void;
auto analyze_semantics_(t_Syntax_Node const *_Nonnull const package_syntax_) -> t_Package const *_Nonnull;
inline t_Semantic_Node *_Nonnull new_t_Semantic_Node__token(t_Syntax_Node const *_Nonnull const syntax_);
inline t_Semantic_Node *_Nonnull new_t_Semantic_Node__concrete(t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_);
inline t_Semantic_Node *_Nonnull new_t_Semantic_Node__of_type(t_Type const *_Nonnull const of_type_, t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_);
inline t_Semantic_Node *_Nonnull new_t_Semantic_Node__declares_type(t_Type const *_Nonnull const type_, t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_);
inline t_Semantic_Node *_Nonnull new_t_Semantic_Node__referencing_type(t_Type const *_Nonnull const type_, t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_);
auto get_text_span_(t_Semantic_Node const *_Nonnull const node_) -> t_Text_Span const *_Nonnull;
auto get_text_(t_Semantic_Node const *_Nonnull const node_) -> str;
auto first_child_(t_Semantic_Node const *_Nonnull const node_, i32 const kind_) -> t_Semantic_Node const *_Nullable;
auto children_of_kind_(t_Semantic_Node const *_Nonnull const node_, i32 const kind_) -> t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull;
auto node_members_(t_Semantic_Node const *_Nonnull const node_) -> t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull;
auto node_statements_(t_Semantic_Node const *_Nonnull const node_) -> t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull;
auto node_parameters_(t_Semantic_Node const *_Nonnull const node_) -> t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull;
auto node_access_modifier_(t_Semantic_Node const *_Nonnull const node_) -> t_Semantic_Node const *_Nullable;
auto node_has_child_(t_Semantic_Node const *_Nonnull const node_, i32 const kind_) -> bit;
auto add_diagnostic_(t_Semantic_Node *_Nonnull const node_, t_Diagnostic const *_Nonnull const diagnostic_) -> void;
auto diagnostics_(t_Semantic_Node const *_Nonnull const node_) -> t_system__collections__List<t_Diagnostic const *_Nonnull> const *_Nonnull;
auto collect_diagnostics_(t_Semantic_Node const *_Nonnull const node_, t_system__collections__List<t_Diagnostic const *_Nonnull> *_Nonnull const diagnostics_) -> void;
inline t_Semantic_Tree_Builder *_Nonnull new_t_Semantic_Tree_Builder();
auto build_compilation_units_(t_Semantic_Tree_Builder const *_Nonnull const builder_, t_Syntax_Node const *_Nonnull const package_syntax_, t_Name_Table const *_Nonnull const name_table_) -> t_system__collections__List<t_Compilation_Unit const *_Nonnull> const *_Nonnull;
auto build_compilation_unit_semantic_node_(t_Semantic_Tree_Builder const *_Nonnull const builder_, t_Syntax_Node const *_Nonnull const compilation_unit_syntax_, t_Name_Table const *_Nonnull const name_table_) -> t_Compilation_Unit const *_Nonnull;
auto build_semantic_node_(t_Semantic_Tree_Builder const *_Nonnull const builder_, t_Syntax_Node const *_Nonnull const syntax_, t_Name_Table const *_Nonnull const name_table_, t_Name_Subtable const *_Nonnull const scope_) -> t_Semantic_Node const *_Nonnull;
auto build_parameters_semantic_node_(t_Semantic_Tree_Builder const *_Nonnull const builder_, t_Syntax_Node const *_Nonnull const parameters_syntax_, t_Name_Table const *_Nonnull const name_table_, t_Name_Subtable const *_Nonnull const scope_) -> t_Semantic_Node *_Nonnull;
auto build_type_name_semantic_node_(t_Semantic_Tree_Builder const *_Nonnull const builder_, t_Syntax_Node const *_Nonnull const syntax_, t_Name_Table const *_Nonnull const name_table_, t_Name_Subtable const *_Nonnull const scope_) -> t_Semantic_Node *_Nonnull;
auto build_type_arguments_semantic_node_(t_Semantic_Tree_Builder const *_Nonnull const builder_, t_Syntax_Node const *_Nonnull const syntax_, t_Name_Table const *_Nonnull const name_table_, t_Name_Subtable const *_Nonnull const scope_, t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const children_) -> t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull;
auto build_constructor_name_semantic_node_(t_Semantic_Tree_Builder const *_Nonnull const builder_, t_Syntax_Node const *_Nonnull const syntax_, t_Name_Table const *_Nonnull const name_table_, t_Name_Subtable const *_Nonnull const scope_) -> t_Semantic_Node const *_Nonnull;
auto add_resolution_error_(t_Semantic_Node *_Nonnull const node_) -> void;
auto add_resolution_error_(t_Semantic_Node *_Nonnull const node_, t_Semantic_Node const *_Nonnull const qualifier_) -> void;
auto add_could_not_determine_type_error_(t_Semantic_Node *_Nonnull const node_) -> void;
auto build_symbols_(t_Package_Name const *_Nonnull const package_name_, t_system__collections__List<t_Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_) -> t_Symbol const *_Nonnull;
inline t_Compilation_Unit_Parser *_Nonnull new_t_Compilation_Unit_Parser(t_Token_Stream *_Nonnull const token_stream_);
auto parse_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull;
auto accept_token_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nullable;
auto expect_token_(t_Compilation_Unit_Parser *_Nonnull const parser_, i32 const tokenType_) -> t_Syntax_Node const *_Nonnull;
auto parse_type_name_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull;
auto parse_non_optional_type_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull;
auto parse_type_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull;
auto parse_atom_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull;
auto parse_call_arguments_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull;
auto parse_expression_(t_Compilation_Unit_Parser *_Nonnull const parser_, i32 const minPrecedence_) -> t_Syntax_Node const *_Nonnull;
auto parse_expression_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull;
auto parse_statement_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull;
auto parse_if_statement_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull;
auto parse_variable_declaration_(t_Compilation_Unit_Parser *_Nonnull const parser_, bit const allowInitializer_) -> t_Syntax_Node const *_Nonnull;
auto parse_block_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull;
auto parse_parameter_list_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull;
auto parse_member_declaration_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull;
auto parse_declaration_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull;
auto parse_compilation_unit_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull;
auto lexically_analyze_(t_Source_Text const *_Nonnull const source_) -> t_Token_Stream *_Nonnull;
auto parse_package_(t_system__collections__List<t_Source_Text const *_Nonnull> const *_Nonnull const sources_) -> t_Syntax_Node const *_Nonnull;
inline t_Syntax_Node *_Nonnull new_t_Syntax_Node(i32 const type_, t_Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_);
inline t_Syntax_Node *_Nonnull new_t_Syntax_Node(i32 const type_, bit const isMissing_, t_Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_);
inline t_Syntax_Node *_Nonnull new_t_Syntax_Node(i32 const type_, t_Syntax_Node const *_Nonnull const child_);
inline t_Syntax_Node *_Nonnull new_t_Syntax_Node(i32 const type_, t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull const children_);
inline t_Syntax_Node *_Nonnull new_t_Syntax_Node__missing(i32 const type_, t_Source_Text const *_Nonnull const source_, u32 const start_);
inline t_Syntax_Node *_Nonnull new_t_Syntax_Node__skipped(t_Syntax_Node const *_Nonnull const skipped_node_);
inline t_Syntax_Node *_Nonnull new_t_Syntax_Node__skipped(t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull const skipped_nodes_);
auto get_text_(t_Syntax_Node const *_Nonnull const syntax_) -> str;
auto first_child_syntax_(t_Syntax_Node const *_Nonnull const syntax_, i32 const type_) -> t_Syntax_Node const *_Nullable;
auto has_child_(t_Syntax_Node const *_Nonnull const syntax_, i32 const type_) -> bit;
auto add_(t_Syntax_Node const *_Nonnull const syntax_, t_Diagnostic const *_Nonnull const diagnostic_) -> void;
auto all_diagnostics_(t_Syntax_Node const *_Nonnull const syntax_) -> t_system__collections__List<t_Diagnostic const *_Nonnull> *_Nonnull;
auto collect_syntax_diagnostics_(t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Diagnostic const *_Nonnull> *_Nonnull const diagnostics_) -> void;
auto members_(t_Syntax_Node const *_Nonnull const syntax_) -> t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull;
auto parameters_(t_Syntax_Node const *_Nonnull const syntax_) -> t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull;
auto statements_(t_Syntax_Node const *_Nonnull const syntax_) -> t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull;
auto access_modifier_(t_Syntax_Node const *_Nonnull const syntax_) -> t_Syntax_Node const *_Nullable;
inline t_Token_Stream *_Nonnull new_t_Token_Stream(t_Source_Text const *_Nonnull const source_);
auto next_token_(t_Token_Stream *_Nonnull const tokens_) -> t_Syntax_Node const *_Nullable;
auto end_of_file_token_(t_Token_Stream *_Nonnull const tokens_) -> t_Syntax_Node const *_Nullable;
auto new_identifier_or_keyword_token_(t_Token_Stream *_Nonnull const tokens_, u32 const end_) -> t_Syntax_Node const *_Nonnull;
auto new_operator_token_(t_Token_Stream *_Nonnull const tokens_, i32 const type_) -> t_Syntax_Node const *_Nonnull;
auto new_operator_token_(t_Token_Stream *_Nonnull const tokens_, i32 const type_, u32 const length_) -> t_Syntax_Node const *_Nonnull;
auto new_token_(t_Token_Stream *_Nonnull const tokens_, i32 const type_, u32 const end_) -> t_Syntax_Node const *_Nonnull;
auto is_identifier_char_(cp const c_) -> bit;
auto is_number_char_(cp const c_) -> bit;
inline t_Diagnostic *_Nonnull new_t_Diagnostic(i32 const level_, i32 const phase_, t_Source_Text const *_Nonnull const source_, t_Text_Span const *_Nonnull const span_, str const message_);
inline t_Emitter *_Nonnull new_t_Emitter(t_Package const *_Nonnull const package_, t_system__collections__List<t_Source_Text const *_Nonnull> const *_Nonnull const resources_);
auto emit_(t_Emitter *_Nonnull const emitter_) -> str;
auto mangle_name_(t_Name const *_Nonnull const name_) -> str;
auto contains_multi_underscore_runs_(str const value_) -> bit;
auto convert_primitive_type_name_(t_Type const *_Nonnull const type_) -> str;
auto convert_type_name_(t_Semantic_Node const *_Nonnull const type_node_) -> t_system__text__String_Builder *_Nonnull;
auto convert_type_name_(t_Type const *_Nonnull const type_) -> t_system__text__String_Builder *_Nonnull;
auto convert_reference_type_(bit const mutable_binding_, t_Type const *_Nonnull type_, bit const nullable_) -> str;
auto convert_type_(bit const mutable_binding_, t_Type const *_Nonnull type_, bit const optional_) -> str;
auto convert_type_(bit const mutable_binding_, t_Semantic_Node const *_Nonnull const type_node_) -> str;
auto convert_parameter_list_(t_Emitter *_Nonnull const emitter_, t_Semantic_Node const *_Nonnull const parameters_, bit const is_main_function_) -> str;
auto convert_parameter_list_(t_Emitter *_Nonnull const emitter_, t_Semantic_Node const *_Nonnull const parameters_) -> str;
auto convert_expression_(t_Semantic_Node const *_Nonnull const syntax_, t_Source_File_Builder *_Nonnull const builder_) -> void;
auto convert_member_access_(t_Semantic_Node const *_Nonnull const lhs_, t_Source_File_Builder *_Nonnull const builder_) -> void;
auto emit_statement_(t_Emitter *_Nonnull const emitter_, t_Semantic_Node const *_Nonnull const statement_) -> void;
auto emit_method_body_(t_Emitter *_Nonnull const emitter_, t_Semantic_Node const *_Nonnull const block_, bit const is_associated_function_) -> void;
auto emit_constructor_body_(t_Emitter *_Nonnull const emitter_, t_Semantic_Node const *_Nonnull const block_, str const self_type_, bit const is_value_type_) -> void;
auto emit_access_modifer_(t_Emitter *_Nonnull const emitter_, i32 const current_access_level_, i32 const access_modifer_) -> i32;
auto emit_member_declaration_(t_Emitter *_Nonnull const emitter_, t_Semantic_Node const *_Nonnull const member_, str const class_name_, bit const is_value_type_, i32 const current_access_level_) -> i32;
auto emit_default_constructor_(t_Emitter *_Nonnull const emitter_, str const type_name_, bit const is_value_type_, i32 const current_access_level_) -> void;
auto emit_declaration_(t_Emitter *_Nonnull const emitter_, t_Semantic_Node const *_Nonnull const declaration_) -> void;
auto emit_compilation_unit_(t_Emitter *_Nonnull const emitter_, t_Compilation_Unit const *_Nonnull const unit_) -> void;
auto emit_preamble_(t_Emitter *_Nonnull const emitter_) -> void;
auto emit_entry_point_adapter_(t_Emitter *_Nonnull const emitter_) -> void;
inline t_Name *_Nonnull new_t_Name__global_namespace();
inline t_Name *_Nonnull new_t_Name__global_namespace(t_Package_Name const *_Nonnull const package_);
inline t_Name *_Nonnull new_t_Name(t_Name const *_Nonnull const qualifier_, i32 const kind_, str const name_);
inline t_Name *_Nonnull new_t_Name(t_Name const *_Nonnull const qualifier_, i32 const kind_, str const name_, bit const is_special_);
inline t_Name *_Nonnull new_t_Name__special(t_Name const *_Nonnull const qualifier_, i32 const kind_, str const name_);
inline t_Name *_Nonnull new_t_Name(t_Package_Name const *_Nullable const package_, i32 const kind_, t_system__collections__List<str> const *_Nonnull const segments_, bit const is_special_);
auto unqualified_name_(t_Name const *_Nonnull const name_) -> str;
auto full_name_(t_Name const *_Nonnull const name_) -> str;
auto is_qualified_by_(t_Name const *_Nonnull const name_, t_Name const *_Nonnull const qualifier_) -> bit;
auto qualifier_is_(t_Name const *_Nonnull const name_, t_Name const *_Nonnull const qualifier_) -> bit;
auto names_(t_Name const *_Nonnull const name_, t_Name const *_Nonnull const other_) -> bit;
auto is_package_qualified_(t_Name const *_Nonnull const name_) -> bit;
auto remove_package_(t_Name const *_Nonnull const name_) -> t_Name const *_Nonnull;
auto unit_test_Name_() -> void;
auto name_with_unspecified_package_names_name_with_package_() -> void;
auto name_with_unspecified_package_names_itself_() -> void;
inline t_Package_Name *_Nonnull new_t_Package_Name(str const name_);
auto full_name_(t_Package_Name const *_Nonnull const package_name_) -> str;
inline t_Symbol *_Nonnull new_t_Symbol__identifier(str const name_);
inline t_Symbol *_Nonnull new_t_Symbol__identifier(str const name_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_);
inline t_Symbol *_Nonnull new_t_Symbol__identifier(str const name_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_);
inline t_Symbol *_Nonnull new_t_Symbol__constructor(str const name_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_);
inline t_Symbol *_Nonnull new_t_Symbol__package(str const name_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_);
inline t_Symbol *_Nonnull new_t_Symbol__declaring(t_Type const *_Nonnull const declares_type_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_);
inline t_Symbol *_Nonnull new_t_Symbol__of_type(str const name_, t_Type const *_Nonnull const of_type_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_);
auto get_child_(t_Symbol const *_Nonnull const symbol_, str const name_, i32 const kind_) -> t_Symbol const *_Nullable;
auto unit_test_Symbol_() -> void;
auto Package_symbol_children_can_be_found_by_name_and_kind_() -> void;
inline t_Type *_Nonnull new_t_Type(i32 const kind_, t_Name const *_Nonnull const name_, bit const is_mutable_);
inline t_Type *_Nonnull new_t_Type__parameter(str const name_);
inline t_Type *_Nonnull new_t_Type(i32 const kind_, t_Name const *_Nonnull const name_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_mutable_);
inline t_Type *_Nonnull new_t_Type__primitive(t_Name const *_Nonnull const name_);
inline t_Type *_Nonnull new_t_Type__primitive(t_Name const *_Nonnull const name_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_);
inline t_Type *_Nonnull new_t_Type__namespace(t_Name const *_Nonnull const name_);
inline t_Type *_Nonnull new_t_Type__generic(t_Type const *_Nonnull const definition_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_arguments_);
inline t_Type *_Nonnull new_t_Type(i32 const kind_, t_Name const *_Nonnull const name_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_primitive_, bit const is_potentially_mutable_, bit const is_mutable_);
auto make_mutable_type_(t_Type const *_Nonnull const type_) -> t_Type const *_Nonnull;
auto make_immutable_type_(t_Type const *_Nonnull const type_) -> t_Type const *_Nonnull;
auto remove_type_package_(t_Type const *_Nonnull const type_) -> t_Type const *_Nonnull;
inline t_Name_Subtable *_Nonnull new_t_Name_Subtable__global_namespace(t_Name_Table const *_Nonnull const name_table_);
inline t_Name_Subtable *_Nonnull new_t_Name_Subtable__global_namespace(t_Name_Table const *_Nonnull const name_table_, t_Package_Name const *_Nonnull const package_name_);
inline t_Name_Subtable *_Nonnull new_t_Name_Subtable(t_Name_Subtable const *_Nonnull const parent_, t_Name const *_Nonnull const name_, t_Type const *_Nonnull const type_);
auto add_subtable_(t_Name_Subtable *_Nonnull const scope_, t_Name const *_Nonnull const name_, t_Type const *_Nonnull const type_) -> void;
auto find_(t_Name_Subtable const *_Nonnull const scope_, str const name_) -> t_Name_Subtable *_Nullable;
auto find_special_(t_Name_Subtable const *_Nonnull const scope_, str const name_) -> t_Name_Subtable *_Nullable;
auto find_(t_Name_Subtable const *_Nonnull const scope_, str const name_, bit const is_special_) -> t_Name_Subtable *_Nullable;
auto lookup_(t_Name_Subtable const *_Nonnull const scope_, str const name_) -> t_Name_Subtable *_Nullable;
auto lookup_special_(t_Name_Subtable const *_Nonnull const scope_, str const name_) -> t_Name_Subtable *_Nullable;
auto lookup_(t_Name_Subtable const *_Nonnull const scope_, str const name_, bit const is_special_) -> t_Name_Subtable *_Nullable;
auto get_scope_(t_Name_Subtable const *_Nonnull const scope_, t_Name const *_Nonnull const name_) -> t_Name_Subtable const *_Nullable;
auto bind_type_(t_Name_Subtable *_Nonnull const scope_, t_Type const *_Nonnull const type_) -> void;
auto as_mut_(t_Name_Subtable const *_Nonnull const scope_) -> t_Name_Subtable *_Nonnull;
auto unit_test_Name_Subtable_() -> void;
auto global_namespace_contains_added_name_() -> void;
auto namespace_contains_added_name_() -> void;
inline t_Name_Table *_Nonnull new_t_Name_Table();
auto add_package_(t_Name_Table *_Nonnull const name_table_, t_Package_Name const *_Nonnull const package_name_) -> t_Name const *_Nonnull;
auto add_name_(t_Name_Table *_Nonnull const name_table_, t_Name const *_Nonnull const parent_, t_Symbol const *_Nonnull const symbol_) -> t_Name const *_Nonnull;
auto add_name_(t_Name_Table *_Nonnull const name_table_, t_Name const *_Nonnull const name_, t_Type const *_Nonnull const type_) -> void;
auto get_name_(t_Name_Table const *_Nonnull const name_table_, t_Name const *_Nonnull const name_) -> t_Name_Subtable const *_Nullable;
auto build_name_table_(t_Package_Name const *_Nonnull const package_name_, t_Syntax_Node const *_Nonnull const package_syntax_, t_system__collections__List<t_Package_Reference> const *_Nonnull const references_) -> t_Name_Table const *_Nonnull;
auto add_referenced_(t_Name_Table *_Nonnull const name_table_, t_system__collections__List<t_Package_Reference> const *_Nonnull const references_) -> void;
auto add_symbol_(t_Name_Table *_Nonnull const name_table_, t_Name const *_Nonnull const parent_, t_Symbol const *_Nonnull const symbol_) -> void;
auto add_package_(t_Name_Table *_Nonnull const name_table_, t_Package_Name const *_Nonnull const package_name_, t_Syntax_Node const *_Nonnull const package_syntax_) -> void;
auto add_compilation_unit_(t_Name_Table *_Nonnull const name_table_, t_Name const *_Nonnull const global_namespace_, t_Syntax_Node const *_Nonnull const compilation_unit_) -> void;
auto add_syntax_(t_Name_Table *_Nonnull const name_table_, t_Name const *_Nonnull const parent_, t_Syntax_Node const *_Nonnull const syntax_) -> void;
auto add_function_(t_Name_Table *_Nonnull const name_table_, t_Name const *_Nonnull const name_, t_Syntax_Node const *_Nonnull const function_) -> void;
auto unit_test_Name_Table_Builder_() -> void;
auto table_contains_referenced_child_names_() -> void;
auto can_get_root_namespace_from_name_() -> void;
auto can_get_Console_class_from_name_without_package_() -> void;
auto can_get_Optional_class_from_name_with_package_() -> void;

// Class Declarations

class t_Source_Text
{
public:
	str package_;
	str path_;
	str name_;
	str text_;
	t_Text_Lines const *_Nonnull lines_;
	auto construct(str const package_, str const path_, str const text_) -> t_Source_Text *_Nonnull;
};

class t_Text_Line
{
public:
	t_Source_Text const *_Nonnull source_;
	i32 start_;
	i32 byte_length_;
	auto construct(t_Source_Text const *_Nonnull const source_, i32 const start_, i32 const length_) -> t_Text_Line *_Nonnull;
	auto construct_spanning(t_Source_Text const *_Nonnull const source_, i32 const start_, i32 const end_) -> t_Text_Line *_Nonnull;
};

class t_Text_Lines
{
public:
	t_Source_Text const *_Nonnull source_;
	t_system__collections__List<i32> const *_Nonnull start_of_line_;
	auto construct(t_Source_Text const *_Nonnull const source_, t_system__collections__List<i32> const *_Nonnull const start_of_line_) -> t_Text_Lines *_Nonnull;
};

class t_Text_Position
{
public:
	i32 character_offset_;
	i32 line_;
	i32 column_;
	auto construct(i32 const character_offset_, i32 const line_, i32 const column_) -> t_Text_Position *_Nonnull;
};

class t_Text_Span
{
public:
	i32 start_;
	i32 byte_length_;
	auto construct(i32 const start_, i32 const length_) -> t_Text_Span *_Nonnull;
};

class t_Source_File_Builder
{
public:
	t_system__text__String_Builder *_Nonnull code_;
	t_system__text__String_Builder *_Nonnull indent_;
	bit firstElement_;
	bit afterBlock_;
	auto construct() -> t_Source_File_Builder *_Nonnull;
};

class t_Compilation_Unit
{
public:
	t_Syntax_Node const *_Nonnull syntax_;
	t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull declarations_;
	auto construct(t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_) -> t_Compilation_Unit *_Nonnull;
};

class t_Package
{
public:
	t_Package_Name const *_Nonnull name_;
	t_system__collections__List<t_Package_Reference> const *_Nonnull references_;
	t_system__collections__List<t_Compilation_Unit const *_Nonnull> const *_Nonnull compilation_units_;
	t_Symbol const *_Nonnull symbol_;
	auto construct(t_Package_Name const *_Nonnull const name_, t_system__collections__List<t_Package_Reference> const *_Nonnull const references_, t_system__collections__List<t_Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_, t_Symbol const *_Nonnull const symbol_) -> t_Package *_Nonnull;
};

struct t_Package_Reference final
{
public:
	t_Package_Reference * operator->() { return this; }
	t_Package_Reference const * operator->() const { return this; }
	t_Package_Reference & operator* () { return *this; }
	t_Package_Reference const & operator* () const { return *this; }
	str name_;
	t_Package const *_Nonnull package_;
	static auto construct(t_Package const *_Nonnull const package_) -> t_Package_Reference;
	static auto construct(str const name_, t_Package const *_Nonnull const package_) -> t_Package_Reference;
};

class t_Semantic_Node
{
public:
	t_Syntax_Node const *_Nonnull syntax_;
	i32 kind_;
	bit is_missing_;
	t_Source_Text const *_Nonnull source_;
	u32 start_;
	u32 byte_length_;
	t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull children_;
	t_system__collections__List<t_Diagnostic const *_Nonnull> *_Nonnull node_diagnostics_;
	t_Type const *_Nullable of_type_;
	t_Type const *_Nullable converted_type_;
	t_Type const *_Nullable declares_type_;
	t_Type const *_Nullable referenced_type_;
	auto construct_token(t_Syntax_Node const *_Nonnull const syntax_) -> t_Semantic_Node *_Nonnull;
	auto construct_concrete(t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_) -> t_Semantic_Node *_Nonnull;
	auto construct_of_type(t_Type const *_Nonnull const of_type_, t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_) -> t_Semantic_Node *_Nonnull;
	auto construct_declares_type(t_Type const *_Nonnull const type_, t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_) -> t_Semantic_Node *_Nonnull;
	auto construct_referencing_type(t_Type const *_Nonnull const type_, t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_) -> t_Semantic_Node *_Nonnull;
};

class t_Semantic_Tree_Builder
{
public:
	t_Name const *_Nonnull optional_type_name_;
	auto construct() -> t_Semantic_Tree_Builder *_Nonnull;
};

class t_Compilation_Unit_Parser
{
public:
	t_Token_Stream *_Nonnull token_stream_;
	t_Syntax_Node const *_Nullable token_;
	t_Syntax_Node const *_Nullable compilation_unit_;
	auto construct(t_Token_Stream *_Nonnull const token_stream_) -> t_Compilation_Unit_Parser *_Nonnull;
};

class t_Syntax_Node
{
public:
	i32 kind_;
	bit is_missing_;
	t_Source_Text const *_Nonnull source_;
	u32 start_;
	u32 byte_length_;
	t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull children_;
	t_system__collections__List<t_Diagnostic const *_Nonnull> *_Nonnull node_diagnostics_;
	auto construct(i32 const type_, t_Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_) -> t_Syntax_Node *_Nonnull;
	auto construct(i32 const type_, bit const isMissing_, t_Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_) -> t_Syntax_Node *_Nonnull;
	auto construct(i32 const type_, t_Syntax_Node const *_Nonnull const child_) -> t_Syntax_Node *_Nonnull;
	auto construct(i32 const type_, t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull const children_) -> t_Syntax_Node *_Nonnull;
	auto construct_missing(i32 const type_, t_Source_Text const *_Nonnull const source_, u32 const start_) -> t_Syntax_Node *_Nonnull;
	auto construct_skipped(t_Syntax_Node const *_Nonnull const skipped_node_) -> t_Syntax_Node *_Nonnull;
	auto construct_skipped(t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull const skipped_nodes_) -> t_Syntax_Node *_Nonnull;
};

class t_Token_Stream
{
public:
	t_Source_Text const *_Nonnull source_;
	u32 position_;
	t_system__collections__List<t_Diagnostic const *_Nonnull> *_Nonnull diagnostics_;
	bit end_of_file_;
	auto construct(t_Source_Text const *_Nonnull const source_) -> t_Token_Stream *_Nonnull;
};

class t_Diagnostic
{
public:
	i32 level_;
	i32 phase_;
	t_Source_Text const *_Nonnull source_;
	t_Text_Span const *_Nonnull span_;
	t_Text_Position const *_Nonnull position_;
	str message_;
	auto construct(i32 const level_, i32 const phase_, t_Source_Text const *_Nonnull const source_, t_Text_Span const *_Nonnull const span_, str const message_) -> t_Diagnostic *_Nonnull;
};

class t_Emitter
{
public:
	t_Package const *_Nonnull package_;
	t_system__collections__List<t_Source_Text const *_Nonnull> const *_Nonnull resources_;
	t_Source_File_Builder *_Nonnull type_declarations_;
	t_Source_File_Builder *_Nonnull function_declarations_;
	t_Source_File_Builder *_Nonnull class_declarations_;
	t_Source_File_Builder *_Nonnull global_definitions_;
	t_Source_File_Builder *_Nonnull definitions_;
	str main_function_name_;
	str main_function_return_type_;
	bit main_function_accepts_console_;
	bit main_function_accepts_args_;
	auto construct(t_Package const *_Nonnull const package_, t_system__collections__List<t_Source_Text const *_Nonnull> const *_Nonnull const resources_) -> t_Emitter *_Nonnull;
};

class t_Name
{
public:
	t_Package_Name const *_Nullable package_;
	i32 kind_;
	t_system__collections__List<str> const *_Nonnull segments_;
	bit is_special_;
	auto construct_global_namespace() -> t_Name *_Nonnull;
	auto construct_global_namespace(t_Package_Name const *_Nonnull const package_) -> t_Name *_Nonnull;
	auto construct(t_Name const *_Nonnull const qualifier_, i32 const kind_, str const name_) -> t_Name *_Nonnull;
	auto construct(t_Name const *_Nonnull const qualifier_, i32 const kind_, str const name_, bit const is_special_) -> t_Name *_Nonnull;
	auto construct_special(t_Name const *_Nonnull const qualifier_, i32 const kind_, str const name_) -> t_Name *_Nonnull;
	auto construct(t_Package_Name const *_Nullable const package_, i32 const kind_, t_system__collections__List<str> const *_Nonnull const segments_, bit const is_special_) -> t_Name *_Nonnull;
};

class t_Package_Name
{
public:
	str unqualified_;
	auto construct(str const name_) -> t_Package_Name *_Nonnull;
};

class t_Symbol
{
public:
	str name_;
	bit is_special_name_;
	i32 kind_;
	t_Type const *_Nonnull of_type_;
	t_Type const *_Nonnull declares_type_;
	t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull declarations_;
	t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull children_;
	auto construct_identifier(str const name_) -> t_Symbol *_Nonnull;
	auto construct_identifier(str const name_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_) -> t_Symbol *_Nonnull;
	auto construct_identifier(str const name_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_) -> t_Symbol *_Nonnull;
	auto construct_constructor(str const name_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_) -> t_Symbol *_Nonnull;
	auto construct_package(str const name_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_) -> t_Symbol *_Nonnull;
	auto construct_declaring(t_Type const *_Nonnull const declares_type_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_) -> t_Symbol *_Nonnull;
	auto construct_of_type(str const name_, t_Type const *_Nonnull const of_type_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_) -> t_Symbol *_Nonnull;
};

class t_Type
{
public:
	i32 kind_;
	t_Name const *_Nonnull name_;
	t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull type_parameters_;
	bit is_primitive_;
	bit is_value_type_;
	bit is_potentially_mutable_;
	bit is_mutable_;
	auto construct(i32 const kind_, t_Name const *_Nonnull const name_, bit const is_mutable_) -> t_Type *_Nonnull;
	auto construct_parameter(str const name_) -> t_Type *_Nonnull;
	auto construct(i32 const kind_, t_Name const *_Nonnull const name_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_mutable_) -> t_Type *_Nonnull;
	auto construct_primitive(t_Name const *_Nonnull const name_) -> t_Type *_Nonnull;
	auto construct_primitive(t_Name const *_Nonnull const name_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_) -> t_Type *_Nonnull;
	auto construct_namespace(t_Name const *_Nonnull const name_) -> t_Type *_Nonnull;
	auto construct_generic(t_Type const *_Nonnull const definition_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_arguments_) -> t_Type *_Nonnull;
	auto construct(i32 const kind_, t_Name const *_Nonnull const name_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_primitive_, bit const is_potentially_mutable_, bit const is_mutable_) -> t_Type *_Nonnull;
};

class t_Name_Subtable
{
public:
	t_Name_Table const *_Nonnull name_table_;
	t_Name_Subtable const *_Nullable parent_;
	t_Name const *_Nonnull name_;
	t_Type const *_Nonnull type_;
	t_system__collections__List<t_Name_Subtable *_Nonnull> *_Nonnull subtables_;
	auto construct_global_namespace(t_Name_Table const *_Nonnull const name_table_) -> t_Name_Subtable *_Nonnull;
	auto construct_global_namespace(t_Name_Table const *_Nonnull const name_table_, t_Package_Name const *_Nonnull const package_name_) -> t_Name_Subtable *_Nonnull;
	auto construct(t_Name_Subtable const *_Nonnull const parent_, t_Name const *_Nonnull const name_, t_Type const *_Nonnull const type_) -> t_Name_Subtable *_Nonnull;
};

class t_Name_Table
{
public:
	t_Name_Subtable *_Nonnull any_package_;
	t_system__collections__List<t_Name_Subtable *_Nonnull> *_Nonnull packages_;
	auto construct() -> t_Name_Table *_Nonnull;
};

// Global Definitions
i32 const Success_ = i32(0);
i32 const UsageError_ = i32(64);
i32 const DataError_ = i32(65);
i32 const SkippedTokens_ = i32_negate(i32(1));
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

auto compile_(t_system__collections__List<t_Source_Text const *_Nonnull> const *_Nonnull const sources_) -> t_Package const *_Nonnull
{
	t_Syntax_Node const *_Nonnull const package_syntax_ = parse_package_(sources_);
	t_Package const *_Nonnull const package_ = analyze_semantics_(package_syntax_);
	return package_;
}

auto write_(t_system__console__Console *_Nonnull const console_, t_system__collections__List<t_Diagnostic const *_Nonnull> const *_Nonnull const diagnostics_) -> void
{
	for (t_Diagnostic const *_Nonnull const diagnostic_ : *(diagnostics_))
	{
		t_Text_Position const *_Nonnull const position_ = diagnostic_->position_;
		str severity_;
		if (cond(equal_op(diagnostic_->level_, Info_)))
		{
			severity_ = str("Informational");
		}
		else if (cond(equal_op(diagnostic_->level_, Warning_)))
		{
			severity_ = str("Warning");
		}
		else
		{
			severity_ = str("Error");
		}

		console_->WriteLine_(diagnostic_->source_->path_->op_add(str(":"))->op_add(position_->line_)->op_add(str(":"))->op_add(position_->column_)->op_add(str(" "))->op_add(severity_)->op_add(str(":")));
		console_->WriteLine_(str("  ").op_add(diagnostic_->message_));
	}
}

auto has_errors_(t_system__collections__List<t_Diagnostic const *_Nonnull> const *_Nonnull const diagnostics_) -> bit
{
	for (t_Diagnostic const *_Nonnull const diagnostic_ : *(diagnostics_))
	{
		if (cond(diagnostic_->level_->op_greater_than_or_equal(CompilationError_)))
		{
			return bit_true;
		}
	}

	return bit_false;
}

auto main_(t_system__console__Console *_Nonnull const console_, t_system__console__Arguments const *_Nonnull const args_) -> i32
{
	if (cond(bit_op(bit_arg(equal_op(args_->op_magnitude(), i32(1))) && bit_arg(equal_op(args_->op_Element(i32(0)), str("--unit-test"))))))
	{
		run_unit_tests_(console_);
		return i32(0);
	}

	t_system__collections__List<str> *_Nonnull const sourceFilePaths_ = new_t_system__collections__List<str>();
	t_system__collections__List<str> *_Nonnull const resourceFilePaths_ = new_t_system__collections__List<str>();
	str outputFilePath_ = str("");
	bit verbose_ = bit_false;
	i32 argType_ = i32(0);
	for (str const arg_ : *(args_))
	{
		if (cond(equal_op(argType_, i32(0))))
		{
			if (cond(equal_op(arg_, str("-r"))))
			{
				argType_ = i32(1);
			}
			else if (cond(equal_op(arg_, str("-o"))))
			{
				argType_ = i32(2);
			}
			else if (cond(bit_op(bit_arg(equal_op(arg_, str("-v"))) || bit_arg(equal_op(arg_, str("--verbose"))))))
			{
				verbose_ = bit_true;
			}
			else
			{
				sourceFilePaths_->add_(arg_);
			}
		}
		else if (cond(equal_op(argType_, i32(1))))
		{
			resourceFilePaths_->add_(arg_);
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
		console_->WriteLine_(str("Adamant Compiler v0.1.0"));
	}

	if (cond(bit_op(bit_arg(equal_op(sourceFilePaths_->op_magnitude(), i32(0))) || bit_arg(equal_op(outputFilePath_, str(""))))))
	{
		console_->WriteLine_(str("Args: <Input File(s)> -o <OutputFile> -r <Resource File>"));
		return UsageError_;
	}

	t_system__collections__List<t_Source_Text const *_Nonnull> *_Nonnull const resources_ = new_t_system__collections__List<t_Source_Text const *_Nonnull>();
	if (cond(resourceFilePaths_->op_magnitude()->op_greater_than(i32(0))))
	{
		if (cond(verbose_))
		{
			console_->WriteLine_(str("Reading Resources:"));
		}

		for (str const resourceFilePath_ : *(resourceFilePaths_))
		{
			if (cond(verbose_))
			{
				console_->WriteLine_(str("  ").op_add(resourceFilePath_));
			}

			resources_->add_(read_source_(resourceFilePath_));
		}
	}

	if (cond(verbose_))
	{
		console_->WriteLine_(str("Compiling:"));
	}

	t_system__collections__List<t_Source_Text const *_Nonnull> *_Nonnull const sources_ = new_t_system__collections__List<t_Source_Text const *_Nonnull>();
	for (str const sourceFilePath_ : *(sourceFilePaths_))
	{
		if (cond(verbose_))
		{
			console_->WriteLine_(str("  ").op_add(sourceFilePath_));
		}

		sources_->add_(read_source_(sourceFilePath_));
	}

	t_Package const *_Nonnull const package_ = compile_(sources_);
	t_system__collections__List<t_Diagnostic const *_Nonnull> const *_Nonnull const diagnostics_ = all_diagnostics_(package_);
	write_(console_, diagnostics_);
	if (cond(has_errors_(diagnostics_)))
	{
		return DataError_;
	}

	t_Emitter *_Nonnull emitter_ = new_t_Emitter(package_, resources_);
	str const translated_ = emit_(emitter_);
	if (cond(verbose_))
	{
		console_->Write_(str("Output: "));
		console_->WriteLine_(outputFilePath_);
	}

	t_system__io__File_Writer *_Nonnull const outputFile_ = new_t_system__io__File_Writer(outputFilePath_);
	outputFile_->Write_(translated_);
	outputFile_->Close_();
	str outputDirPath_ = outputFilePath_;
	i32 index_ = outputDirPath_.LastIndexOf_(cp('/'));
	if (cond(not_equal_op(index_, i32_negate(i32(1)))))
	{
		outputDirPath_ = outputDirPath_.Substring_(i32(0), index_.op_add(i32(1)));
	}

	index_ = outputDirPath_.LastIndexOf_(cp('\\'));
	if (cond(not_equal_op(index_, i32_negate(i32(1)))))
	{
		outputDirPath_ = outputDirPath_.Substring_(i32(0), index_.op_add(i32(1)));
	}

	if (cond(verbose_))
	{
		console_->Write_(str("Outputting RuntimeLibrary to: "));
		console_->WriteLine_(outputDirPath_);
	}

	t_system__io__File_Writer *_Nonnull resourceFile_ = new_t_system__io__File_Writer(outputDirPath_.op_add(str("RuntimeLibrary.hpp")));
	resourceFile_->Write_(resource_manager_->GetString_(str("RuntimeLibrary.hpp")));
	resourceFile_->Close_();
	resourceFile_ = new_t_system__io__File_Writer(outputDirPath_.op_add(str("RuntimeLibrary.cpp")));
	resourceFile_->Write_(resource_manager_->GetString_(str("RuntimeLibrary.cpp")));
	resourceFile_->Close_();
	return Success_;
}

auto read_source_(str const path_) -> t_Source_Text const *_Nonnull
{
	t_system__io__File_Reader *_Nonnull const file_ = new_t_system__io__File_Reader(path_);
	str const contents_ = file_->ReadToEndSync_();
	file_->Close_();
	return new_t_Source_Text(str("<default>"), path_, contents_);
}

auto run_unit_tests_(t_system__console__Console *_Nonnull const console_) -> void
{
	console_->WriteLine_(str("Running Unit Tests..."));
	unit_test_Text_Position_();
	unit_test_build_primitives_package_();
	unit_test_build_runtime_library_package_();
	unit_test_Name_();
	unit_test_Name_Subtable_();
	unit_test_Name_Table_Builder_();
	unit_test_Symbol_();
}

auto t_Source_Text::construct(str const package_, str const path_, str const text_) -> t_Source_Text *_Nonnull
{
	t_Source_Text *_Nonnull self = this;
	self->package_ = package_;
	self->path_ = path_;
	str name_ = path_;
	i32 index_ = name_.LastIndexOf_(cp('/'));
	if (cond(not_equal_op(index_, i32_negate(i32(1)))))
	{
		name_ = name_.Substring_(index_.op_add(i32(1)));
	}

	index_ = name_.LastIndexOf_(cp('\\'));
	if (cond(not_equal_op(index_, i32_negate(i32(1)))))
	{
		name_ = name_.Substring_(index_.op_add(i32(1)));
	}

	self->name_ = name_;
	self->text_ = text_;
	self->lines_ = new_t_Text_Lines(self, line_starts_(text_));
	return self;
}

inline t_Source_Text *_Nonnull new_t_Source_Text(str const package_, str const path_, str const text_)
{
	return (new t_Source_Text())->construct(package_, path_, text_);
}

auto line_starts_(str const text_) -> t_system__collections__List<i32> const *_Nonnull
{
	i32 const length_ = text_.ByteLength_();
	t_system__collections__List<i32> *_Nonnull const starting_positions_ = new_t_system__collections__List<i32>();
	starting_positions_->add_(i32(0));
	i32 position_ = i32(0);
	while (cond(i32_less_than(position_, length_)))
	{
		cp const c_ = text_.op_Element(position_);
		position_.op_add_assign(i32(1));
		if (cond(bit_op(bit_arg(cp_greater_than(c_, cp('\r'))) && bit_arg(cp_less_than_or_equal(c_, cp('\x7F'))))))
		{
			continue;
		}

		if (cond(equal_op(c_, cp('\r'))))
		{
			if (cond(bit_op(bit_arg(i32_less_than(position_, length_)) && bit_arg(equal_op(text_.op_Element(position_), cp('\n'))))))
			{
				position_.op_add_assign(i32(1));
			}
		}
		else if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(c_, cp('\n'))) || bit_arg(equal_op(c_, cp('\x0B'))))) || bit_arg(equal_op(c_, cp('\f'))))) || bit_arg(equal_op(c_, cp('\x85'))))))
		{
		}
		else
		{
			continue;
		}

		starting_positions_->add_(position_);
	}

	return starting_positions_;
}

auto source_byte_length_(t_Source_Text const *_Nonnull const source_) -> i32
{
	return source_->text_.ByteLength_();
}

auto position_of_start_(t_Source_Text const *_Nonnull const source_, t_Text_Span const *_Nonnull const span_) -> t_Text_Position const *_Nonnull
{
	i32 const char_offset_ = span_->start_;
	i32 const line_number_ = line_containing_offset_(source_->lines_, char_offset_);
	i32 const line_start_ = get_line_(source_->lines_, line_number_)->start_;
	i32 column_ = char_offset_.op_subtract(line_start_)->op_add(i32(1));
	i32 i_ = line_start_;
	while (cond(i32_less_than(i_, char_offset_)))
	{
		if (cond(equal_op(source_->text_.op_Element(i_), cp('\t'))))
		{
			column_.op_add_assign(i32(3));
		}

		i_.op_add_assign(i32(1));
	}

	return new_t_Text_Position(char_offset_, line_number_, column_);
}

auto t_Text_Line::construct(t_Source_Text const *_Nonnull const source_, i32 const start_, i32 const length_) -> t_Text_Line *_Nonnull
{
	t_Text_Line *_Nonnull self = this;
	self->source_ = source_;
	self->start_ = start_;
	byte_length_ = length_;
	return self;
}

inline t_Text_Line *_Nonnull new_t_Text_Line(t_Source_Text const *_Nonnull const source_, i32 const start_, i32 const length_)
{
	return (new t_Text_Line())->construct(source_, start_, length_);
}

auto t_Text_Line::construct_spanning(t_Source_Text const *_Nonnull const source_, i32 const start_, i32 const end_) -> t_Text_Line *_Nonnull
{
	t_Text_Line *_Nonnull self = this;
	self->source_ = source_;
	self->start_ = start_;
	self->byte_length_ = end_.op_subtract(start_);
	return self;
}

inline t_Text_Line *_Nonnull new_t_Text_Line__spanning(t_Source_Text const *_Nonnull const source_, i32 const start_, i32 const end_)
{
	return (new t_Text_Line())->construct_spanning(source_, start_, end_);
}

auto t_Text_Lines::construct(t_Source_Text const *_Nonnull const source_, t_system__collections__List<i32> const *_Nonnull const start_of_line_) -> t_Text_Lines *_Nonnull
{
	t_Text_Lines *_Nonnull self = this;
	self->source_ = source_;
	self->start_of_line_ = start_of_line_;
	return self;
}

inline t_Text_Lines *_Nonnull new_t_Text_Lines(t_Source_Text const *_Nonnull const source_, t_system__collections__List<i32> const *_Nonnull const start_of_line_)
{
	return (new t_Text_Lines())->construct(source_, start_of_line_);
}

auto line_count_(t_Text_Lines const *_Nonnull const lines_) -> i32
{
	return lines_->start_of_line_->op_magnitude();
}

auto get_line_(t_Text_Lines const *_Nonnull const lines_, i32 const line_number_) -> t_Text_Line const *_Nonnull
{
	assert_(i32_greater_than(line_number_, i32(0)), str("line ").op_add(line_number_));
	assert_(i32_less_than_or_equal(line_number_, line_count_(lines_)), str("line ").op_add(line_number_));
	i32 const line_index_ = line_number_.op_subtract(i32(1));
	i32 const line_start_ = lines_->start_of_line_->op_Element(line_index_);
	if (cond(equal_op(line_index_, line_count_(lines_)->op_subtract(i32(1)))))
	{
		return new_t_Text_Line__spanning(lines_->source_, line_start_, source_byte_length_(lines_->source_));
	}

	i32 const line_end_ = lines_->start_of_line_->op_Element(line_index_.op_add(i32(1)));
	return new_t_Text_Line__spanning(lines_->source_, line_start_, line_end_);
}

auto line_containing_offset_(t_Text_Lines const *_Nonnull const lines_, i32 const character_offset_) -> i32
{
	assert_(i32_greater_than_or_equal(character_offset_, i32(0)), str("offset ").op_add(character_offset_));
	assert_(i32_less_than_or_equal(character_offset_, source_byte_length_(lines_->source_)), str("offset ").op_add(character_offset_)->op_add(str(" source length "))->op_add(source_byte_length_(lines_->source_)));
	i32 left_ = i32(0);
	i32 right_ = line_count_(lines_)->op_subtract(i32(1));
	while (cond(i32_less_than_or_equal(left_, right_)))
	{
		i32 const mid_ = left_.op_add(right_.op_subtract(left_)->op_divide(i32(2)));
		i32 const mid_line_start_ = lines_->start_of_line_->op_Element(mid_);
		if (cond(i32_less_than(mid_line_start_, character_offset_)))
		{
			left_ = mid_.op_add(i32(1));
		}
		else if (cond(i32_greater_than(mid_line_start_, character_offset_)))
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

auto t_Text_Position::construct(i32 const character_offset_, i32 const line_, i32 const column_) -> t_Text_Position *_Nonnull
{
	t_Text_Position *_Nonnull self = this;
	self->character_offset_ = character_offset_;
	self->line_ = line_;
	self->column_ = column_;
	return self;
}

inline t_Text_Position *_Nonnull new_t_Text_Position(i32 const character_offset_, i32 const line_, i32 const column_)
{
	return (new t_Text_Position())->construct(character_offset_, line_, column_);
}

auto unit_test_Text_Position_() -> void
{
	Text_Position_retains_given_offeset_line_and_column_();
}

auto Text_Position_retains_given_offeset_line_and_column_() -> void
{
	t_Text_Position const *_Nonnull const position_ = new_t_Text_Position(i32(23), i32(2), i32(5));
	assert_(equal_op(position_->character_offset_, i32(23)), str(""));
	assert_(equal_op(position_->line_, i32(2)), str(""));
	assert_(equal_op(position_->column_, i32(5)), str(""));
}

auto t_Text_Span::construct(i32 const start_, i32 const length_) -> t_Text_Span *_Nonnull
{
	t_Text_Span *_Nonnull self = this;
	self->start_ = start_;
	self->byte_length_ = length_;
	return self;
}

inline t_Text_Span *_Nonnull new_t_Text_Span(i32 const start_, i32 const length_)
{
	return (new t_Text_Span())->construct(start_, length_);
}

auto format_error_(str const message_) -> str
{
	return str("<$ ").op_add(message_)->op_add(str(" $>"));
}

auto t_Source_File_Builder::construct() -> t_Source_File_Builder *_Nonnull
{
	t_Source_File_Builder *_Nonnull self = this;
	code_ = new_t_system__text__String_Builder();
	indent_ = new_t_system__text__String_Builder();
	firstElement_ = bit_true;
	afterBlock_ = bit_true;
	return self;
}

inline t_Source_File_Builder *_Nonnull new_t_Source_File_Builder()
{
	return (new t_Source_File_Builder())->construct();
}

auto error_(t_Source_File_Builder *_Nonnull const file_, str const message_) -> void
{
	file_->code_->Append_(format_error_(message_));
}

auto begin_line_(t_Source_File_Builder *_Nonnull const file_, str const value_) -> void
{
	file_->code_->Append_(file_->indent_);
	file_->code_->Append_(value_);
	file_->firstElement_ = file_->afterBlock_ = bit_false;
}

auto write_(t_Source_File_Builder *_Nonnull const file_, str const value_) -> void
{
	file_->code_->Append_(value_);
	file_->firstElement_ = file_->afterBlock_ = bit_false;
}

auto end_line_(t_Source_File_Builder *_Nonnull const file_, str const value_) -> void
{
	file_->code_->Append_(value_);
	file_->code_->AppendLine_();
	file_->firstElement_ = file_->afterBlock_ = bit_false;
}

auto write_line_(t_Source_File_Builder *_Nonnull const file_, str const value_) -> void
{
	file_->code_->Append_(file_->indent_);
	file_->code_->Append_(value_);
	file_->code_->AppendLine_();
	file_->firstElement_ = file_->afterBlock_ = bit_false;
}

auto blank_line_(t_Source_File_Builder *_Nonnull const file_) -> void
{
	file_->code_->AppendLine_();
	file_->firstElement_ = bit_true;
	file_->afterBlock_ = bit_false;
}

auto element_separator_line_(t_Source_File_Builder *_Nonnull const file_) -> void
{
	if (cond(bit_not(file_->firstElement_)))
	{
		file_->code_->AppendLine_();
		file_->firstElement_ = bit_true;
		file_->afterBlock_ = bit_false;
	}
}

auto statement_separator_line_(t_Source_File_Builder *_Nonnull const file_) -> void
{
	if (cond(file_->afterBlock_))
	{
		file_->code_->AppendLine_();
		file_->firstElement_ = bit_true;
		file_->afterBlock_ = bit_false;
	}
}

auto begin_block_(t_Source_File_Builder *_Nonnull const file_) -> void
{
	write_line_(file_, str("{"));
	file_->indent_->Append_(str("\t"));
	file_->firstElement_ = file_->afterBlock_ = bit_false;
}

auto end_block_(t_Source_File_Builder *_Nonnull const file_) -> void
{
	file_->indent_->Remove_(i32(0), i32(1));
	write_line_(file_, str("}"));
	file_->afterBlock_ = bit_true;
}

auto end_block_with_semicolon_(t_Source_File_Builder *_Nonnull const file_) -> void
{
	file_->indent_->Remove_(i32(0), i32(1));
	write_line_(file_, str("};"));
}

auto byte_length_(t_Source_File_Builder const *_Nonnull const file_) -> i32
{
	return file_->code_->byte_length_();
}

auto to_string_(t_Source_File_Builder *_Nonnull const file_) -> str
{
	return file_->code_->ToString_();
}

auto t_Compilation_Unit::construct(t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_) -> t_Compilation_Unit *_Nonnull
{
	t_Compilation_Unit *_Nonnull self = this;
	self->syntax_ = syntax_;
	self->declarations_ = declarations_;
	return self;
}

inline t_Compilation_Unit *_Nonnull new_t_Compilation_Unit(t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_)
{
	return (new t_Compilation_Unit())->construct(syntax_, declarations_);
}

auto collect_diagnostics_(t_Compilation_Unit const *_Nonnull const compilation_unit_, t_system__collections__List<t_Diagnostic const *_Nonnull> *_Nonnull const diagnostics_) -> void
{
	collect_syntax_diagnostics_(compilation_unit_->syntax_, diagnostics_);
	for (t_Semantic_Node const *_Nonnull const declaration_ : *(compilation_unit_->declarations_))
	{
		collect_diagnostics_(declaration_, diagnostics_);
	}
}

auto t_Package::construct(t_Package_Name const *_Nonnull const name_, t_system__collections__List<t_Package_Reference> const *_Nonnull const references_, t_system__collections__List<t_Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_, t_Symbol const *_Nonnull const symbol_) -> t_Package *_Nonnull
{
	t_Package *_Nonnull self = this;
	self->name_ = name_;
	self->references_ = references_;
	self->compilation_units_ = compilation_units_;
	self->symbol_ = symbol_;
	return self;
}

inline t_Package *_Nonnull new_t_Package(t_Package_Name const *_Nonnull const name_, t_system__collections__List<t_Package_Reference> const *_Nonnull const references_, t_system__collections__List<t_Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_, t_Symbol const *_Nonnull const symbol_)
{
	return (new t_Package())->construct(name_, references_, compilation_units_, symbol_);
}

auto all_diagnostics_(t_Package const *_Nonnull const package_) -> t_system__collections__List<t_Diagnostic const *_Nonnull> const *_Nonnull
{
	t_system__collections__List<t_Diagnostic const *_Nonnull> *_Nonnull diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	for (t_Compilation_Unit const *_Nonnull const compilation_unit_ : *(package_->compilation_units_))
	{
		collect_diagnostics_(compilation_unit_, diagnostics_);
	}

	return diagnostics_;
}

auto t_Package_Reference::construct(t_Package const *_Nonnull const package_) -> t_Package_Reference
{
	t_Package_Reference self;
	self->name_ = package_->name_->unqualified_;
	self->package_ = package_;
	return self;
}

inline t_Package_Reference new_t_Package_Reference(t_Package const *_Nonnull const package_)
{
	return t_Package_Reference::construct(package_);
}

auto t_Package_Reference::construct(str const name_, t_Package const *_Nonnull const package_) -> t_Package_Reference
{
	t_Package_Reference self;
	self->name_ = name_;
	self->package_ = package_;
	return self;
}

inline t_Package_Reference new_t_Package_Reference(str const name_, t_Package const *_Nonnull const package_)
{
	return t_Package_Reference::construct(name_, package_);
}

auto build_primitives_package_() -> t_Package const *_Nonnull
{
	t_Package_Name const *_Nonnull const name_ = new_t_Package_Name(str("$primitives"));
	t_system__collections__List<t_Package_Reference> const *_Nonnull const references_ = new_t_system__collections__List<t_Package_Reference>();
	t_system__collections__List<t_Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_ = new_t_system__collections__List<t_Compilation_Unit const *_Nonnull>();
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const primitive_symbols_ = build_primitive_symbols_(name_);
	assert_(primitive_symbols_->op_magnitude()->op_greater_than(i32(0)), str("|primitive_symbols|=").op_add(primitive_symbols_->op_magnitude()));
	t_Symbol const *_Nonnull const package_symbol_ = new_t_Symbol__package(name_->unqualified_, primitive_symbols_);
	assert_(package_symbol_->children_->op_magnitude()->op_greater_than(i32(0)), str("|package_symbol.children|=").op_add(package_symbol_->children_->op_magnitude()));
	return new_t_Package(name_, references_, compilation_units_, package_symbol_);
}

auto build_primitive_symbols_(t_Package_Name const *_Nonnull const package_name_) -> t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull
{
	t_Name const *_Nonnull const global_namespace_ = new_t_Name__global_namespace(package_name_);
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const symbols_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	symbols_->add_(build_adamant_language_namespace_symbol_(global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("void"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("never"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("bool"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("code_point"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("string"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("int8"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("int16"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("int"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("int64"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("int128"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("byte"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("uint16"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("uint"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("uint64"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("uint128"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("float32"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("float"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("float128"), global_namespace_));
	build_fixed_point_primitives_(symbols_, i32(8), global_namespace_);
	build_fixed_point_primitives_(symbols_, i32(16), global_namespace_);
	build_fixed_point_primitives_(symbols_, i32(32), global_namespace_);
	build_fixed_point_primitives_(symbols_, i32(64), global_namespace_);
	symbols_->add_(build_primitive_symbol_(str("decimal32"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("decimal"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("decimal128"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("size"), global_namespace_));
	symbols_->add_(build_primitive_symbol_(str("offset"), global_namespace_));
	return symbols_;
}

auto build_adamant_language_namespace_symbol_(t_Name const *_Nonnull const global_namespace_) -> t_Symbol const *_Nonnull
{
	t_Name const *_Nonnull const adamant_namespace_ = new_t_Name(global_namespace_, NamespaceName_, str("adamant"));
	t_Name const *_Nonnull const language_namespace_ = new_t_Name(adamant_namespace_, NamespaceName_, str("language"));
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const language_children_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	language_children_->add_(build_optional_type_symbol_(language_namespace_));
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const adamant_children_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	adamant_children_->add_(new_t_Symbol__identifier(unqualified_name_(language_namespace_), language_children_));
	return new_t_Symbol__identifier(unqualified_name_(adamant_namespace_), adamant_children_);
}

auto build_optional_type_symbol_(t_Name const *_Nonnull const language_namespace_) -> t_Symbol const *_Nonnull
{
	t_Name const *_Nonnull const optional_name_ = new_t_Name(language_namespace_, TypeName_, str("optional"));
	t_system__collections__List<t_Type const *_Nonnull> *_Nonnull const type_parameters_ = new_t_system__collections__List<t_Type const *_Nonnull>();
	type_parameters_->add_(new_t_Type(TypeParameterType_, new_t_Name(optional_name_, TypeParameterName_, str("T")), bit_true));
	t_Type const *_Nonnull const type_ = new_t_Type__primitive(optional_name_, type_parameters_);
	t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const declarations_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	return new_t_Symbol__declaring(type_, declarations_, children_);
}

auto build_primitive_symbol_(str const name_, t_Name const *_Nonnull const namespace_) -> t_Symbol const *_Nonnull
{
	t_Type const *_Nonnull const type_ = new_t_Type__primitive(new_t_Name__special(namespace_, TypeName_, name_));
	t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const declarations_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	return new_t_Symbol__declaring(type_, declarations_, children_);
}

auto build_fixed_point_primitives_(t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const symbols_, i32 const bits_, t_Name const *_Nonnull const namespace_) -> void
{
}

auto unit_test_build_primitives_package_() -> void
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
	t_Package const *_Nonnull const package_ = build_primitives_package_();
	t_Package_Name const *_Nonnull const name_ = package_->name_;
	assert_(equal_op(name_->unqualified_, str("$primitives")), str(""));
}

auto Package_has_no_references_or_compilation_units_() -> void
{
	t_Package const *_Nonnull const package_ = build_primitives_package_();
	assert_(equal_op(package_->references_->op_magnitude(), i32(0)), str(""));
	assert_(equal_op(package_->compilation_units_->op_magnitude(), i32(0)), str(""));
}

auto Package_symbol_has_package_name_() -> void
{
	t_Package const *_Nonnull const package_ = build_primitives_package_();
	t_Symbol const *_Nonnull const symbol_ = package_->symbol_;
	assert_(equal_op(symbol_->kind_, PackageSymbol_), str(""));
	assert_(equal_op(symbol_->name_, package_->name_->unqualified_), str(""));
}

auto Package_symbol_has_children_() -> void
{
	t_Package const *_Nonnull const package_ = build_primitives_package_();
	assert_(package_->symbol_->children_->op_magnitude()->op_greater_than(i32(0)), str(""));
}

auto Package_contains_the_string_type_() -> void
{
	t_Package const *_Nonnull const package_ = build_primitives_package_();
	t_Symbol const *_Nonnull const string_symbol_ = get_child_(package_->symbol_, str("string"), IdentifierSymbol_);
	assert_(not_equal_op(string_symbol_, none), str(""));
}

auto Package_contains_optional_type_() -> void
{
	t_Package const *_Nonnull const package_ = build_primitives_package_();
	t_Symbol const *_Nullable const adamant_symbol_ = get_child_(package_->symbol_, str("adamant"), IdentifierSymbol_);
	assert_(not_equal_op(adamant_symbol_, none), str(""));
	t_Symbol const *_Nullable const langauge_symbol_ = get_child_(adamant_symbol_, str("language"), IdentifierSymbol_);
	assert_(not_equal_op(langauge_symbol_, none), str(""));
	t_Symbol const *_Nullable const optional_symbol_ = get_child_(langauge_symbol_, str("optional"), IdentifierSymbol_);
	assert_(not_equal_op(optional_symbol_, none), str(""));
}

auto build_runtime_library_package_() -> t_Package const *_Nonnull
{
	t_Package_Name const *_Nonnull const name_ = new_t_Package_Name(str("$runtime"));
	t_system__collections__List<t_Package_Reference> const *_Nonnull const references_ = new_t_system__collections__List<t_Package_Reference>();
	t_system__collections__List<t_Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_ = new_t_system__collections__List<t_Compilation_Unit const *_Nonnull>();
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const symbols_ = build_runtime_library_symbols_(name_);
	assert_(symbols_->op_magnitude()->op_greater_than(i32(0)), str("|symbols|=").op_add(symbols_->op_magnitude()));
	t_Symbol const *_Nonnull const package_symbol_ = new_t_Symbol__package(name_->unqualified_, symbols_);
	assert_(package_symbol_->children_->op_magnitude()->op_greater_than(i32(0)), str("|package_symbol.children|=").op_add(package_symbol_->children_->op_magnitude()));
	return new_t_Package(name_, references_, compilation_units_, package_symbol_);
}

auto build_runtime_library_symbols_(t_Package_Name const *_Nonnull const package_name_) -> t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull
{
	t_Name const *_Nonnull const global_namespace_ = new_t_Name__global_namespace(package_name_);
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const symbols_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	symbols_->add_(build_function_symbol_(new_t_Name(global_namespace_, FunctionName_, str("THROW_EXCEPTION"))));
	symbols_->add_(build_function_symbol_(new_t_Name(global_namespace_, FunctionName_, str("NOT_IMPLEMENTED"))));
	symbols_->add_(build_function_symbol_(new_t_Name(global_namespace_, FunctionName_, str("UNREACHABLE"))));
	symbols_->add_(build_function_symbol_(new_t_Name(global_namespace_, FunctionName_, str("assert"))));
	symbols_->add_(build_function_symbol_(new_t_Name(global_namespace_, FunctionName_, str("debug_write"))));
	symbols_->add_(build_function_symbol_(new_t_Name(global_namespace_, FunctionName_, str("debug_write_line"))));
	symbols_->add_(build_function_symbol_(new_t_Name(global_namespace_, VariableName_, str("resource_manager"))));
	t_Name const *_Nonnull const system_namespace_ = new_t_Name(global_namespace_, NamespaceName_, str("system"));
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const system_symbols_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	t_Name const *_Nonnull const collections_namespace_ = new_t_Name(system_namespace_, NamespaceName_, str("collections"));
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const collections_symbols_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	t_system__collections__List<t_Type const *_Nonnull> *_Nonnull const list_type_parameters_ = new_t_system__collections__List<t_Type const *_Nonnull>();
	list_type_parameters_->add_(new_t_Type__parameter(str("T")));
	collections_symbols_->add_(build_generic_class_symbol_(collections_namespace_, str("List"), list_type_parameters_));
	system_symbols_->add_(build_namespace_symbol_(collections_namespace_, collections_symbols_));
	t_Name const *_Nonnull const console_namespace_ = new_t_Name(system_namespace_, NamespaceName_, str("console"));
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const console_symbols_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	console_symbols_->add_(build_class_symbol_(console_namespace_, str("Console")));
	console_symbols_->add_(build_class_symbol_(console_namespace_, str("Arguments")));
	system_symbols_->add_(build_namespace_symbol_(console_namespace_, console_symbols_));
	t_Name const *_Nonnull const io_namespace_ = new_t_Name(system_namespace_, NamespaceName_, str("io"));
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const io_symbols_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	io_symbols_->add_(build_class_symbol_(io_namespace_, str("File_Reader")));
	io_symbols_->add_(build_class_symbol_(io_namespace_, str("File_Writer")));
	system_symbols_->add_(build_namespace_symbol_(io_namespace_, io_symbols_));
	t_Name const *_Nonnull const text_namespace_ = new_t_Name(system_namespace_, NamespaceName_, str("text"));
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const text_symbols_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const string_builder_symbols_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	string_builder_symbols_->add_(build_constructor_symbol_(str("with_capacity")));
	text_symbols_->add_(build_class_symbol_(text_namespace_, str("String_Builder"), string_builder_symbols_));
	system_symbols_->add_(build_namespace_symbol_(text_namespace_, text_symbols_));
	symbols_->add_(build_namespace_symbol_(system_namespace_, system_symbols_));
	return symbols_;
}

auto build_function_symbol_(t_Name const *_Nonnull const name_) -> t_Symbol const *_Nonnull
{
	t_Type const *_Nonnull const type_ = new_t_Type(FunctionType_, name_, bit_false);
	t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	return new_t_Symbol__of_type(unqualified_name_(name_), type_, declarations_, children_);
}

auto build_namespace_symbol_(t_Name const *_Nonnull const name_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const symbols_) -> t_Symbol const *_Nonnull
{
	t_Type const *_Nonnull const type_ = new_t_Type__namespace(name_);
	t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	return new_t_Symbol__declaring(type_, declarations_, symbols_);
}

auto build_class_symbol_(t_Name const *_Nonnull const namespace_, str const class_name_) -> t_Symbol const *_Nonnull
{
	t_Type const *_Nonnull const type_ = new_t_Type(ReferenceType_, new_t_Name(namespace_, TypeName_, class_name_), bit_true);
	t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	return new_t_Symbol__declaring(type_, declarations_, children_);
}

auto build_class_symbol_(t_Name const *_Nonnull const namespace_, str const class_name_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_) -> t_Symbol const *_Nonnull
{
	t_Type const *_Nonnull const type_ = new_t_Type(ReferenceType_, new_t_Name(namespace_, TypeName_, class_name_), bit_true);
	t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	return new_t_Symbol__declaring(type_, declarations_, children_);
}

auto build_generic_class_symbol_(t_Name const *_Nonnull const namespace_, str const class_name_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_) -> t_Symbol const *_Nonnull
{
	t_Type const *_Nonnull const type_ = new_t_Type(ReferenceType_, new_t_Name(namespace_, TypeName_, class_name_), type_parameters_, bit_true);
	t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	return new_t_Symbol__declaring(type_, declarations_, children_);
}

auto build_constructor_symbol_(str const name_) -> t_Symbol const *_Nonnull
{
	str const constructor_name_ = str("new_").op_add(name_);
	t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	return new_t_Symbol__constructor(constructor_name_, declarations_);
}

auto unit_test_build_runtime_library_package_() -> void
{
	Runtime_Library_Package_contains_system_package_();
	System_namespace_contains_console_namespace_();
	Console_namespace_contains_Console_class_();
	System_namespace_contains_collections_namespace_();
	Collections_namespace_contains_List_class_();
}

auto Runtime_Library_Package_contains_system_package_() -> void
{
	t_Package const *_Nonnull const package_ = build_runtime_library_package_();
	assert_(not_equal_op(get_child_(package_->symbol_, str("system"), IdentifierSymbol_), none), str(""));
}

auto System_namespace_contains_console_namespace_() -> void
{
	t_Package const *_Nonnull const package_ = build_runtime_library_package_();
	t_Symbol const *_Nonnull const system_namespace_ = get_child_(package_->symbol_, str("system"), IdentifierSymbol_);
	assert_(not_equal_op(get_child_(system_namespace_, str("console"), IdentifierSymbol_), none), str(""));
}

auto Console_namespace_contains_Console_class_() -> void
{
	t_Package const *_Nonnull const package_ = build_runtime_library_package_();
	t_Symbol const *_Nonnull const system_namespace_ = get_child_(package_->symbol_, str("system"), IdentifierSymbol_);
	t_Symbol const *_Nonnull const console_namespace_ = get_child_(system_namespace_, str("console"), IdentifierSymbol_);
	assert_(not_equal_op(get_child_(console_namespace_, str("Console"), IdentifierSymbol_), none), str(""));
}

auto System_namespace_contains_collections_namespace_() -> void
{
	t_Package const *_Nonnull const package_ = build_runtime_library_package_();
	t_Symbol const *_Nonnull const system_namespace_ = get_child_(package_->symbol_, str("system"), IdentifierSymbol_);
	assert_(not_equal_op(get_child_(system_namespace_, str("collections"), IdentifierSymbol_), none), str(""));
}

auto Collections_namespace_contains_List_class_() -> void
{
	t_Package const *_Nonnull const package_ = build_runtime_library_package_();
	t_Symbol const *_Nonnull const system_namespace_ = get_child_(package_->symbol_, str("system"), IdentifierSymbol_);
	t_Symbol const *_Nonnull const console_namespace_ = get_child_(system_namespace_, str("collections"), IdentifierSymbol_);
	assert_(not_equal_op(get_child_(console_namespace_, str("List"), IdentifierSymbol_), none), str(""));
}

auto analyze_semantics_(t_Syntax_Node const *_Nonnull const package_syntax_) -> t_Package const *_Nonnull
{
	assert_(equal_op(package_syntax_->kind_, PackageNode_), str("package_syntax.kind=").op_add(package_syntax_->kind_));
	t_Package_Name const *_Nonnull const name_ = new_t_Package_Name(str("default"));
	t_Package const *_Nonnull const primitives_package_ = build_primitives_package_();
	t_Package const *_Nonnull const runtime_package_ = build_runtime_library_package_();
	t_system__collections__List<t_Package_Reference> *_Nonnull const references_ = new_t_system__collections__List<t_Package_Reference>();
	references_->add_(new_t_Package_Reference(primitives_package_));
	references_->add_(new_t_Package_Reference(runtime_package_));
	t_Name_Table const *_Nonnull const name_table_ = build_name_table_(name_, package_syntax_, references_);
	t_Semantic_Tree_Builder const *_Nonnull const semantic_tree_builder_ = new_t_Semantic_Tree_Builder();
	t_system__collections__List<t_Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_ = build_compilation_units_(semantic_tree_builder_, package_syntax_, name_table_);
	t_Symbol const *_Nonnull const package_symbol_ = build_symbols_(name_, compilation_units_);
	t_Package const *_Nonnull const package_ = new_t_Package(name_, references_, compilation_units_, package_symbol_);
	return package_;
}

auto t_Semantic_Node::construct_token(t_Syntax_Node const *_Nonnull const syntax_) -> t_Semantic_Node *_Nonnull
{
	t_Semantic_Node *_Nonnull self = this;
	assert_(not_equal_op(syntax_, none), str(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	self->node_diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	self->of_type_ = none;
	self->converted_type_ = none;
	self->declares_type_ = none;
	self->referenced_type_ = none;
	return self;
}

inline t_Semantic_Node *_Nonnull new_t_Semantic_Node__token(t_Syntax_Node const *_Nonnull const syntax_)
{
	return (new t_Semantic_Node())->construct_token(syntax_);
}

auto t_Semantic_Node::construct_concrete(t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_) -> t_Semantic_Node *_Nonnull
{
	t_Semantic_Node *_Nonnull self = this;
	assert_(not_equal_op(syntax_, none), str(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = children_;
	self->node_diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	self->of_type_ = none;
	self->converted_type_ = none;
	self->declares_type_ = none;
	self->referenced_type_ = none;
	return self;
}

inline t_Semantic_Node *_Nonnull new_t_Semantic_Node__concrete(t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_)
{
	return (new t_Semantic_Node())->construct_concrete(syntax_, children_);
}

auto t_Semantic_Node::construct_of_type(t_Type const *_Nonnull const of_type_, t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_) -> t_Semantic_Node *_Nonnull
{
	t_Semantic_Node *_Nonnull self = this;
	assert_(not_equal_op(of_type_, none), str(""));
	assert_(not_equal_op(syntax_, none), str(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = children_;
	self->node_diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	self->of_type_ = of_type_;
	self->converted_type_ = of_type_;
	self->declares_type_ = none;
	self->referenced_type_ = none;
	return self;
}

inline t_Semantic_Node *_Nonnull new_t_Semantic_Node__of_type(t_Type const *_Nonnull const of_type_, t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_)
{
	return (new t_Semantic_Node())->construct_of_type(of_type_, syntax_, children_);
}

auto t_Semantic_Node::construct_declares_type(t_Type const *_Nonnull const type_, t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_) -> t_Semantic_Node *_Nonnull
{
	t_Semantic_Node *_Nonnull self = this;
	assert_(not_equal_op(type_, none), str(""));
	assert_(not_equal_op(syntax_, none), str(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = children_;
	self->node_diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	self->of_type_ = of_type_;
	self->converted_type_ = none;
	self->declares_type_ = type_;
	self->referenced_type_ = none;
	return self;
}

inline t_Semantic_Node *_Nonnull new_t_Semantic_Node__declares_type(t_Type const *_Nonnull const type_, t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_)
{
	return (new t_Semantic_Node())->construct_declares_type(type_, syntax_, children_);
}

auto t_Semantic_Node::construct_referencing_type(t_Type const *_Nonnull const type_, t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_) -> t_Semantic_Node *_Nonnull
{
	t_Semantic_Node *_Nonnull self = this;
	assert_(not_equal_op(type_, none), str(""));
	assert_(not_equal_op(syntax_, none), str(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = children_;
	self->node_diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	self->of_type_ = none;
	self->converted_type_ = none;
	self->declares_type_ = none;
	self->referenced_type_ = type_;
	return self;
}

inline t_Semantic_Node *_Nonnull new_t_Semantic_Node__referencing_type(t_Type const *_Nonnull const type_, t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const children_)
{
	return (new t_Semantic_Node())->construct_referencing_type(type_, syntax_, children_);
}

auto get_text_span_(t_Semantic_Node const *_Nonnull const node_) -> t_Text_Span const *_Nonnull
{
	return new_t_Text_Span(node_->start_, node_->byte_length_);
}

auto get_text_(t_Semantic_Node const *_Nonnull const node_) -> str
{
	if (cond(equal_op(node_->source_, none)))
	{
		return str("$No Source$");
	}

	return node_->source_->text_.Substring_(node_->start_, node_->byte_length_);
}

auto first_child_(t_Semantic_Node const *_Nonnull const node_, i32 const kind_) -> t_Semantic_Node const *_Nullable
{
	for (t_Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		if (cond(equal_op(child_->kind_, kind_)))
		{
			return child_;
		}
	}

	return none;
}

auto children_of_kind_(t_Semantic_Node const *_Nonnull const node_, i32 const kind_) -> t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull
{
	t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	for (t_Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		if (cond(equal_op(child_->kind_, kind_)))
		{
			children_->add_(child_);
		}
	}

	return children_;
}

auto node_members_(t_Semantic_Node const *_Nonnull const node_) -> t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull
{
	t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const members_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	for (t_Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		if (cond(bit_op(bit_arg(bit_op(bit_arg(equal_op(child_->kind_, ConstructorDeclaration_)) || bit_arg(equal_op(child_->kind_, FieldDeclaration_)))) || bit_arg(equal_op(child_->kind_, MethodDeclaration_)))))
		{
			members_->add_(child_);
		}
	}

	return members_;
}

auto node_statements_(t_Semantic_Node const *_Nonnull const node_) -> t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull
{
	t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const statements_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	for (t_Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		if (cond(bit_op(bit_arg(not_equal_op(child_->kind_, LeftBrace_)) && bit_arg(not_equal_op(child_->kind_, RightBrace_)))))
		{
			statements_->add_(child_);
		}
	}

	return statements_;
}

auto node_parameters_(t_Semantic_Node const *_Nonnull const node_) -> t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull
{
	t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const parameters_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	for (t_Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		if (cond(bit_op(bit_arg(equal_op(child_->kind_, Parameter_)) || bit_arg(equal_op(child_->kind_, SelfParameter_)))))
		{
			parameters_->add_(child_);
		}
	}

	return parameters_;
}

auto node_access_modifier_(t_Semantic_Node const *_Nonnull const node_) -> t_Semantic_Node const *_Nullable
{
	for (t_Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(child_->kind_, PublicKeyword_)) || bit_arg(equal_op(child_->kind_, ProtectedKeyword_)))) || bit_arg(equal_op(child_->kind_, PrivateKeyword_)))) || bit_arg(equal_op(child_->kind_, InternalKeyword_)))))
		{
			return child_;
		}
	}

	return none;
}

auto node_has_child_(t_Semantic_Node const *_Nonnull const node_, i32 const kind_) -> bit
{
	for (t_Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		if (cond(equal_op(child_->kind_, kind_)))
		{
			return bit_true;
		}
	}

	return bit_false;
}

auto add_diagnostic_(t_Semantic_Node *_Nonnull const node_, t_Diagnostic const *_Nonnull const diagnostic_) -> void
{
	node_->node_diagnostics_->add_(diagnostic_);
}

auto diagnostics_(t_Semantic_Node const *_Nonnull const node_) -> t_system__collections__List<t_Diagnostic const *_Nonnull> const *_Nonnull
{
	return node_->node_diagnostics_;
}

auto collect_diagnostics_(t_Semantic_Node const *_Nonnull const node_, t_system__collections__List<t_Diagnostic const *_Nonnull> *_Nonnull const diagnostics_) -> void
{
	for (t_Diagnostic const *_Nonnull const diagnostic_ : *(node_->node_diagnostics_))
	{
		diagnostics_->add_(diagnostic_);
	}

	for (t_Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		collect_diagnostics_(child_, diagnostics_);
	}
}

auto t_Semantic_Tree_Builder::construct() -> t_Semantic_Tree_Builder *_Nonnull
{
	t_Semantic_Tree_Builder *_Nonnull self = this;
	t_Package_Name const *_Nonnull const primitives_package_ = new_t_Package_Name(str("$primitives"));
	t_Name const *_Nonnull const global_namespace_ = new_t_Name__global_namespace(primitives_package_);
	t_Name const *_Nonnull const adamant_namespace_ = new_t_Name(global_namespace_, NamespaceName_, str("adamant"));
	t_Name const *_Nonnull const language_namespace_ = new_t_Name(adamant_namespace_, NamespaceName_, str("language"));
	self->optional_type_name_ = new_t_Name(language_namespace_, TypeName_, str("optional"));
	return self;
}

inline t_Semantic_Tree_Builder *_Nonnull new_t_Semantic_Tree_Builder()
{
	return (new t_Semantic_Tree_Builder())->construct();
}

auto build_compilation_units_(t_Semantic_Tree_Builder const *_Nonnull const builder_, t_Syntax_Node const *_Nonnull const package_syntax_, t_Name_Table const *_Nonnull const name_table_) -> t_system__collections__List<t_Compilation_Unit const *_Nonnull> const *_Nonnull
{
	assert_(equal_op(package_syntax_->kind_, PackageNode_), str("package_syntax.kind=").op_add(package_syntax_->kind_));
	assert_(not_equal_op(lookup_special_(name_table_->any_package_, str("string")), none), str("name_table.any_package.name=").op_add(full_name_(name_table_->any_package_->name_)));
	t_system__collections__List<t_Compilation_Unit const *_Nonnull> *_Nonnull const compilation_units_ = new_t_system__collections__List<t_Compilation_Unit const *_Nonnull>();
	for (t_Syntax_Node const *_Nonnull const compilation_unit_syntax_ : *(package_syntax_->children_))
	{
		compilation_units_->add_(build_compilation_unit_semantic_node_(builder_, compilation_unit_syntax_, name_table_));
	}

	return compilation_units_;
}

auto build_compilation_unit_semantic_node_(t_Semantic_Tree_Builder const *_Nonnull const builder_, t_Syntax_Node const *_Nonnull const compilation_unit_syntax_, t_Name_Table const *_Nonnull const name_table_) -> t_Compilation_Unit const *_Nonnull
{
	assert_(equal_op(compilation_unit_syntax_->kind_, CompilationUnit_), str("compilation_unit_syntax.kind=").op_add(compilation_unit_syntax_->kind_));
	t_Name_Subtable const *_Nonnull const scope_ = none;
	t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const declarations_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	for (t_Syntax_Node const *_Nonnull const declaration_syntax_ : *(compilation_unit_syntax_->children_))
	{
		declarations_->add_(build_semantic_node_(builder_, declaration_syntax_, name_table_, name_table_->any_package_));
	}

	return new_t_Compilation_Unit(compilation_unit_syntax_, declarations_);
}

auto build_semantic_node_(t_Semantic_Tree_Builder const *_Nonnull const builder_, t_Syntax_Node const *_Nonnull const syntax_, t_Name_Table const *_Nonnull const name_table_, t_Name_Subtable const *_Nonnull const scope_) -> t_Semantic_Node const *_Nonnull
{
	t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, FunctionDeclaration_)) || bit_arg(equal_op(syntax_->kind_, MethodDeclaration_)))))
	{
		children_->add_(build_semantic_node_(builder_, access_modifier_(syntax_), name_table_, scope_));
		t_Syntax_Node const *_Nonnull const function_name_ = first_child_syntax_(syntax_, Identifier_);
		children_->add_(build_semantic_node_(builder_, function_name_, name_table_, scope_));
		t_Name_Subtable *_Nonnull const function_scope_ = find_(scope_, get_text_(function_name_));
		assert_(not_equal_op(function_scope_, none), str("get_text(function_name)=").op_add(get_text_(function_name_)));
		t_Syntax_Node const *_Nonnull const parameters_ = first_child_syntax_(syntax_, ParameterList_);
		children_->add_(build_parameters_semantic_node_(builder_, parameters_, name_table_, function_scope_));
		t_Syntax_Node const *_Nonnull const return_type_ = syntax_->children_->op_Element(i32(4));
		children_->add_(build_type_name_semantic_node_(builder_, return_type_, name_table_, scope_));
		t_Type const *_Nonnull const function_type_ = new_t_Type(FunctionType_, function_scope_->name_, bit_false);
		bind_type_(function_scope_, function_type_);
		t_Syntax_Node const *_Nonnull const body_ = first_child_syntax_(syntax_, Block_);
		if (cond(not_equal_op(body_, none)))
		{
			children_->add_(build_semantic_node_(builder_, body_, name_table_, function_scope_));
		}

		return new_t_Semantic_Node__concrete(syntax_, children_);
	}
	else if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, ClassDeclaration_)) || bit_arg(equal_op(syntax_->kind_, StructDeclaration_)))))
	{
		t_Syntax_Node const *_Nonnull const type_name_ = first_child_syntax_(syntax_, Identifier_);
		children_->add_(build_semantic_node_(builder_, type_name_, name_table_, scope_));
		t_Name_Subtable const *_Nonnull const type_scope_ = find_(scope_, get_text_(type_name_));
		assert_(not_equal_op(type_scope_, none), str("get_text(type_name)=").op_add(get_text_(type_name_)));
		for (t_Syntax_Node const *_Nonnull const member_ : *(members_(syntax_)))
		{
			children_->add_(build_semantic_node_(builder_, member_, name_table_, type_scope_));
		}

		return new_t_Semantic_Node__declares_type(type_scope_->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, ConstructorDeclaration_)))
	{
		children_->add_(build_semantic_node_(builder_, access_modifier_(syntax_), name_table_, scope_));
		str full_name_ = str("new");
		t_Syntax_Node const *_Nullable const constructor_name_ = first_child_syntax_(syntax_, Identifier_);
		if (cond(not_equal_op(constructor_name_, none)))
		{
			full_name_ = str("new_").op_add(get_text_(constructor_name_));
			children_->add_(new_t_Semantic_Node__token(constructor_name_));
		}

		t_Name_Subtable const *_Nonnull const constructor_scope_ = find_special_(scope_, full_name_);
		assert_(not_equal_op(constructor_scope_, none), str("full_name=").op_add(full_name_));
		t_Syntax_Node const *_Nonnull const parameters_ = first_child_syntax_(syntax_, ParameterList_);
		children_->add_(build_parameters_semantic_node_(builder_, parameters_, name_table_, constructor_scope_));
		t_Syntax_Node const *_Nonnull const body_ = first_child_syntax_(syntax_, Block_);
		if (cond(not_equal_op(body_, none)))
		{
			children_->add_(build_semantic_node_(builder_, body_, name_table_, constructor_scope_));
		}

		return new_t_Semantic_Node__concrete(syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, IdentifierName_)))
	{
		t_Name_Subtable const *_Nonnull const name_scope_ = lookup_(scope_, get_text_(syntax_));
		if (cond(equal_op(name_scope_, none)))
		{
			t_Semantic_Node *_Nonnull const node_ = new_t_Semantic_Node__token(syntax_);
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
				return new_t_Semantic_Node__concrete(syntax_, children_);
			}
			else
			{
				return new_t_Semantic_Node__of_type(name_scope_->type_, syntax_, children_);
			}
		}
	}
	else if (cond(equal_op(syntax_->kind_, MemberAccessExpression_)))
	{
		t_Semantic_Node const *_Nonnull const lhs_ = build_semantic_node_(builder_, syntax_->children_->op_Element(i32(0)), name_table_, scope_);
		children_->add_(lhs_);
		t_Semantic_Node *_Nonnull rhs_;
		t_Syntax_Node const *_Nonnull const member_name_ = syntax_->children_->op_Element(i32(2));
		if (cond(equal_op(lhs_->of_type_, none)))
		{
			rhs_ = new_t_Semantic_Node__token(member_name_);
		}
		else
		{
			t_Name_Subtable const *_Nonnull const access_scope_ = get_name_(name_table_, lhs_->of_type_->name_);
			t_Name_Subtable const *_Nonnull const member_scope_ = find_(access_scope_, get_text_(member_name_));
			if (cond(equal_op(member_scope_, none)))
			{
				rhs_ = new_t_Semantic_Node__token(member_name_);
			}
			else
			{
				t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const no_children_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
				if (cond(equal_op(member_scope_->type_, none)))
				{
					rhs_ = new_t_Semantic_Node__token(member_name_);
				}
				else
				{
					rhs_ = new_t_Semantic_Node__of_type(member_scope_->type_, member_name_, no_children_);
				}
			}
		}

		children_->add_(rhs_);
		if (cond(equal_op(rhs_->of_type_, none)))
		{
			return new_t_Semantic_Node__concrete(syntax_, children_);
		}
		else
		{
			return new_t_Semantic_Node__of_type(rhs_->of_type_, syntax_, children_);
		}
	}
	else if (cond(equal_op(syntax_->kind_, NewExpression_)))
	{
		children_->add_(build_constructor_name_semantic_node_(builder_, syntax_->children_->op_Element(i32(1)), name_table_, scope_));
		children_->add_(build_semantic_node_(builder_, first_child_syntax_(syntax_, ArgumentList_), name_table_, scope_));
		return new_t_Semantic_Node__concrete(syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, LocalDeclarationStatement_)))
	{
		t_Syntax_Node const *_Nonnull const variable_declaration_syntax_ = first_child_syntax_(syntax_, VariableDeclaration_);
		children_->add_(build_semantic_node_(builder_, variable_declaration_syntax_, name_table_, scope_));
		return new_t_Semantic_Node__concrete(syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, VariableDeclaration_)))
	{
		t_Syntax_Node const *_Nonnull const binding_syntax_ = syntax_->children_->op_Element(i32(0));
		children_->add_(new_t_Semantic_Node__token(binding_syntax_));
		t_Syntax_Node const *_Nonnull const identifier_ = first_child_syntax_(syntax_, Identifier_);
		children_->add_(new_t_Semantic_Node__token(identifier_));
		t_Syntax_Node const *_Nonnull const type_syntax_ = syntax_->children_->op_Element(i32(3));
		t_Semantic_Node const *_Nonnull const type_node_ = build_type_name_semantic_node_(builder_, type_syntax_, name_table_, scope_);
		assert_(not_equal_op(type_node_->referenced_type_, none), get_text_(type_node_));
		t_Name_Subtable *_Nonnull const variable_scope_ = lookup_(scope_, get_text_(identifier_));
		assert_(not_equal_op(variable_scope_, none), get_text_(syntax_));
		bind_type_(variable_scope_, type_node_->referenced_type_);
		bind_type_(as_mut_(get_name_(name_table_, variable_scope_->name_)), type_node_->referenced_type_);
		children_->add_(type_node_);
		if (cond(equal_op(syntax_->children_->op_magnitude(), i32(6))))
		{
			t_Syntax_Node const *_Nonnull const initalizer_ = syntax_->children_->op_Element(i32(5));
			children_->add_(build_semantic_node_(builder_, initalizer_, name_table_, scope_));
		}

		return new_t_Semantic_Node__concrete(syntax_, children_);
	}
	else if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, TrueLiteralExpression_)) || bit_arg(equal_op(syntax_->kind_, FalseLiteralExpression_)))))
	{
		return new_t_Semantic_Node__of_type(lookup_special_(scope_, str("bool"))->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, StringLiteralExpression_)))
	{
		return new_t_Semantic_Node__of_type(lookup_special_(scope_, str("string"))->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, CodePointLiteralExpression_)))
	{
		return new_t_Semantic_Node__of_type(lookup_special_(scope_, str("code_point"))->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, NumericLiteralExpression_)))
	{
		return new_t_Semantic_Node__of_type(lookup_special_(scope_, str("int"))->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->children_->op_magnitude(), i32(0))))
	{
		return new_t_Semantic_Node__token(syntax_);
	}
	else
	{
		for (t_Syntax_Node const *_Nonnull const child_syntax_ : *(syntax_->children_))
		{
			children_->add_(build_semantic_node_(builder_, child_syntax_, name_table_, scope_));
		}

		return new_t_Semantic_Node__concrete(syntax_, children_);
	}
}

auto build_parameters_semantic_node_(t_Semantic_Tree_Builder const *_Nonnull const builder_, t_Syntax_Node const *_Nonnull const parameters_syntax_, t_Name_Table const *_Nonnull const name_table_, t_Name_Subtable const *_Nonnull const scope_) -> t_Semantic_Node *_Nonnull
{
	assert_(equal_op(parameters_syntax_->kind_, ParameterList_), str("parameters_syntax.kind=").op_add(parameters_syntax_->kind_));
	t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const parameter_nodes_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	for (t_Syntax_Node const *_Nonnull const parameter_ : *(parameters_(parameters_syntax_)))
	{
		t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
		if (cond(equal_op(parameter_->kind_, Parameter_)))
		{
			t_Syntax_Node const *_Nullable const var_syntax_ = first_child_syntax_(parameter_, VarKeyword_);
			if (cond(not_equal_op(var_syntax_, none)))
			{
				children_->add_(new_t_Semantic_Node__token(var_syntax_));
			}

			t_Syntax_Node const *_Nonnull const identifier_ = first_child_syntax_(parameter_, Identifier_);
			children_->add_(new_t_Semantic_Node__token(identifier_));
			t_Syntax_Node const *_Nonnull const type_syntax_ = parameter_->children_->op_Element(parameter_->children_->op_magnitude()->op_subtract(i32(1)));
			t_Semantic_Node const *_Nonnull const type_node_ = build_type_name_semantic_node_(builder_, type_syntax_, name_table_, scope_);
			assert_(not_equal_op(type_node_->referenced_type_, none), get_text_(parameter_));
			children_->add_(type_node_);
			t_Name_Subtable *_Nonnull const parameter_scope_ = lookup_(scope_, get_text_(identifier_));
			assert_(not_equal_op(parameter_scope_, none), get_text_(identifier_));
			bind_type_(parameter_scope_, type_node_->referenced_type_);
			parameter_nodes_->add_(new_t_Semantic_Node__of_type(type_node_->referenced_type_, parameter_, children_));
		}
		else if (cond(equal_op(parameter_->kind_, SelfParameter_)))
		{
			for (t_Syntax_Node const *_Nonnull const child_syntax_ : *(parameter_->children_))
			{
				children_->add_(new_t_Semantic_Node__token(child_syntax_));
			}

			parameter_nodes_->add_(new_t_Semantic_Node__concrete(parameter_, children_));
		}
		else
		{
			NOT_IMPLEMENTED_(str("parameter.kind=").op_add(parameter_->kind_));
		}
	}

	return new_t_Semantic_Node__concrete(parameters_syntax_, parameter_nodes_);
}

auto build_type_name_semantic_node_(t_Semantic_Tree_Builder const *_Nonnull const builder_, t_Syntax_Node const *_Nonnull const syntax_, t_Name_Table const *_Nonnull const name_table_, t_Name_Subtable const *_Nonnull const scope_) -> t_Semantic_Node *_Nonnull
{
	t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	if (cond(equal_op(syntax_->kind_, PredefinedType_)))
	{
		str const primitive_name_ = get_text_(syntax_->children_->op_Element(i32(0)));
		t_Name_Subtable const *_Nullable const primitive_entry_ = lookup_special_(scope_, primitive_name_);
		assert_(not_equal_op(primitive_entry_, none), str("No entry for primitive `").op_add(primitive_name_)->op_add(str("`")));
		return new_t_Semantic_Node__referencing_type(primitive_entry_->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, IdentifierName_)))
	{
		if (cond(syntax_->is_missing_))
		{
			return new_t_Semantic_Node__token(syntax_);
		}

		str const name_ = get_text_(syntax_);
		t_Name_Subtable const *_Nullable const entry_ = lookup_(scope_, name_);
		if (cond(equal_op(entry_, none)))
		{
			t_Semantic_Node *_Nonnull const node_ = new_t_Semantic_Node__token(syntax_);
			add_resolution_error_(node_);
			return node_;
		}
		else
		{
			return new_t_Semantic_Node__referencing_type(entry_->type_, syntax_, children_);
		}
	}
	else if (cond(equal_op(syntax_->kind_, QualifiedName_)))
	{
		t_Syntax_Node const *_Nonnull const qualifier_syntax_ = syntax_->children_->op_Element(i32(0));
		t_Semantic_Node *_Nonnull const qualifier_ = build_type_name_semantic_node_(builder_, qualifier_syntax_, name_table_, scope_);
		children_->add_(qualifier_);
		t_Syntax_Node const *_Nonnull const qualified_syntax_ = syntax_->children_->op_Element(i32(2));
		if (cond(equal_op(qualified_syntax_->kind_, IdentifierName_)))
		{
			t_Syntax_Node const *_Nonnull const name_syntax_ = qualified_syntax_;
			if (cond(equal_op(qualifier_->referenced_type_, none)))
			{
				add_could_not_determine_type_error_(qualifier_);
				t_Semantic_Node *_Nonnull const name_node_ = new_t_Semantic_Node__token(name_syntax_);
				add_resolution_error_(name_node_, qualifier_);
				children_->add_(name_node_);
				return new_t_Semantic_Node__concrete(syntax_, children_);
			}
			else
			{
				t_Type const *_Nonnull const containing_type_ = qualifier_->referenced_type_;
				t_Name_Subtable const *_Nonnull const containing_scope_ = get_name_(name_table_, containing_type_->name_);
				assert_(not_equal_op(containing_scope_, none), full_name_(containing_type_->name_));
				t_Name_Subtable const *_Nonnull const referenced_scope_ = find_(containing_scope_, get_text_(name_syntax_));
				if (cond(equal_op(referenced_scope_, none)))
				{
					t_Semantic_Node *_Nonnull const name_node_ = new_t_Semantic_Node__token(name_syntax_);
					add_resolution_error_(name_node_, qualifier_);
					children_->add_(name_node_);
					return new_t_Semantic_Node__concrete(syntax_, children_);
				}

				t_Type const *_Nonnull const referenced_type_ = referenced_scope_->type_;
				t_Semantic_Node const *_Nonnull const name_node_ = new_t_Semantic_Node__referencing_type(referenced_type_, name_syntax_, new_t_system__collections__List<t_Semantic_Node const *_Nonnull>());
				children_->add_(name_node_);
				return new_t_Semantic_Node__referencing_type(referenced_type_, syntax_, children_);
			}
		}
		else if (cond(equal_op(qualified_syntax_->kind_, GenericName_)))
		{
			t_Syntax_Node const *_Nonnull const name_syntax_ = first_child_syntax_(qualified_syntax_, IdentifierName_);
			t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const generic_name_children_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
			if (cond(equal_op(qualifier_->referenced_type_, none)))
			{
				add_could_not_determine_type_error_(qualifier_);
				t_Semantic_Node *_Nonnull const name_node_ = new_t_Semantic_Node__token(name_syntax_);
				add_resolution_error_(name_node_, qualifier_);
				generic_name_children_->add_(name_node_);
				build_type_arguments_semantic_node_(builder_, qualified_syntax_, name_table_, scope_, generic_name_children_);
				t_Semantic_Node *_Nonnull const qualified_name_ = new_t_Semantic_Node__concrete(qualified_syntax_, generic_name_children_);
				children_->add_(qualified_name_);
				return new_t_Semantic_Node__concrete(syntax_, children_);
			}
			else
			{
				t_Type const *_Nonnull const containing_type_ = qualifier_->referenced_type_;
				t_Name_Subtable const *_Nonnull const containing_scope_ = get_name_(name_table_, containing_type_->name_);
				assert_(not_equal_op(containing_scope_, none), full_name_(containing_type_->name_));
				t_Name_Subtable const *_Nonnull const referenced_scope_ = find_(containing_scope_, get_text_(name_syntax_));
				if (cond(equal_op(referenced_scope_, none)))
				{
					t_Semantic_Node *_Nonnull const name_node_ = new_t_Semantic_Node__token(name_syntax_);
					add_resolution_error_(name_node_, qualifier_);
					generic_name_children_->add_(name_node_);
					build_type_arguments_semantic_node_(builder_, qualified_syntax_, name_table_, scope_, generic_name_children_);
					t_Semantic_Node *_Nonnull const qualified_name_ = new_t_Semantic_Node__concrete(qualified_syntax_, generic_name_children_);
					children_->add_(qualified_name_);
					return new_t_Semantic_Node__concrete(syntax_, children_);
				}

				t_Type const *_Nonnull const referenced_type_name_ = referenced_scope_->type_;
				t_Semantic_Node const *_Nonnull const name_node_ = new_t_Semantic_Node__referencing_type(referenced_type_name_, name_syntax_, new_t_system__collections__List<t_Semantic_Node const *_Nonnull>());
				generic_name_children_->add_(name_node_);
				t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_ = build_type_arguments_semantic_node_(builder_, qualified_syntax_, name_table_, scope_, generic_name_children_);
				t_Type const *_Nonnull const referenced_type_ = new_t_Type__generic(referenced_type_name_, type_parameters_);
				t_Semantic_Node *_Nonnull const qualified_name_ = new_t_Semantic_Node__referencing_type(referenced_type_, qualified_syntax_, generic_name_children_);
				children_->add_(qualified_name_);
				return new_t_Semantic_Node__referencing_type(referenced_type_, syntax_, children_);
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
		t_Semantic_Node *_Nonnull const inner_type_ = build_type_name_semantic_node_(builder_, syntax_->children_->op_Element(i32(1)), name_table_, scope_);
		children_->add_(inner_type_);
		if (cond(equal_op(inner_type_->referenced_type_, none)))
		{
			add_could_not_determine_type_error_(inner_type_);
			return new_t_Semantic_Node__concrete(syntax_, children_);
		}

		t_Type const *_Nonnull const type_ = make_mutable_type_(inner_type_->referenced_type_);
		return new_t_Semantic_Node__referencing_type(type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, ImmutableType_)))
	{
		t_Semantic_Node *_Nonnull const inner_type_ = build_type_name_semantic_node_(builder_, syntax_->children_->op_Element(i32(0)), name_table_, scope_);
		children_->add_(inner_type_);
		if (cond(equal_op(inner_type_->referenced_type_, none)))
		{
			add_could_not_determine_type_error_(inner_type_);
			return new_t_Semantic_Node__concrete(syntax_, children_);
		}

		t_Type const *_Nonnull const type_ = make_immutable_type_(inner_type_->referenced_type_);
		return new_t_Semantic_Node__referencing_type(type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, OptionalType_)))
	{
		t_Semantic_Node *_Nonnull const inner_type_ = build_type_name_semantic_node_(builder_, syntax_->children_->op_Element(i32(0)), name_table_, scope_);
		children_->add_(inner_type_);
		if (cond(equal_op(inner_type_->referenced_type_, none)))
		{
			add_could_not_determine_type_error_(inner_type_);
			return new_t_Semantic_Node__concrete(syntax_, children_);
		}

		t_Name_Subtable const *_Nullable const optional_type_scope_ = get_name_(name_table_, builder_->optional_type_name_);
		assert_(not_equal_op(optional_type_scope_, none), str(""));
		t_Type const *_Nonnull const optional_type_ = optional_type_scope_->type_;
		t_system__collections__List<t_Type const *_Nonnull> *_Nonnull const type_arguments_ = new_t_system__collections__List<t_Type const *_Nonnull>();
		type_arguments_->add_(inner_type_->referenced_type_);
		t_Type const *_Nonnull const type_ = new_t_Type__generic(optional_type_, type_arguments_);
		return new_t_Semantic_Node__referencing_type(type_, syntax_, children_);
	}
	else
	{
		i32 const place_ = syntax_->start_;
		NOT_IMPLEMENTED_(str("syntax.kind=").op_add(syntax_->kind_)->op_add(str(" at "))->op_add(place_));
	}
}

auto build_type_arguments_semantic_node_(t_Semantic_Tree_Builder const *_Nonnull const builder_, t_Syntax_Node const *_Nonnull const syntax_, t_Name_Table const *_Nonnull const name_table_, t_Name_Subtable const *_Nonnull const scope_, t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const children_) -> t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull
{
	t_system__collections__List<t_Type const *_Nonnull> *_Nonnull const type_parameters_ = new_t_system__collections__List<t_Type const *_Nonnull>();
	if (cond(equal_op(syntax_->kind_, IdentifierName_)))
	{
		return type_parameters_;
	}

	assert_(equal_op(syntax_->kind_, GenericName_), str("syntax.kind==").op_add(syntax_->kind_));
	bit in_type_arguments_ = bit_false;
	for (t_Syntax_Node const *_Nonnull const type_argument_ : *(syntax_->children_))
	{
		if (cond(in_type_arguments_))
		{
			if (cond(not_equal_op(type_argument_->kind_, GreaterThan_)))
			{
				t_Semantic_Node const *_Nonnull const type_node_ = build_type_name_semantic_node_(builder_, type_argument_, name_table_, scope_);
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

auto build_constructor_name_semantic_node_(t_Semantic_Tree_Builder const *_Nonnull const builder_, t_Syntax_Node const *_Nonnull const syntax_, t_Name_Table const *_Nonnull const name_table_, t_Name_Subtable const *_Nonnull const scope_) -> t_Semantic_Node const *_Nonnull
{
	if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, QualifiedName_)) && bit_arg(equal_op(syntax_->children_->op_Element(i32(2))->kind_, IdentifierName_)))))
	{
		t_system__collections__List<t_Semantic_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
		t_Semantic_Node const *_Nonnull const type_node_ = build_type_name_semantic_node_(builder_, syntax_->children_->op_Element(i32(0)), name_table_, scope_);
		children_->add_(type_node_);
		t_Syntax_Node const *_Nonnull const qualifier_ = syntax_->children_->op_Element(i32(0));
		t_Syntax_Node const *_Nonnull const name_ = syntax_->children_->op_Element(i32(2));
		str const constructor_name_ = str("new_").op_add(get_text_(name_));
		t_Type const *_Nonnull const referenced_type_ = type_node_->referenced_type_;
		assert_(not_equal_op(referenced_type_, none), str("no referenced type for `").op_add(get_text_(type_node_))->op_add(str("`")));
		t_Name_Subtable const *_Nullable const constructor_scope_ = lookup_special_(get_name_(name_table_, referenced_type_->name_), constructor_name_);
		if (cond(not_equal_op(constructor_scope_, none)))
		{
			children_->add_(new_t_Semantic_Node__token(name_));
			return new_t_Semantic_Node__concrete(syntax_, children_);
		}
	}

	return build_type_name_semantic_node_(builder_, syntax_, name_table_, scope_);
}

auto add_resolution_error_(t_Semantic_Node *_Nonnull const node_) -> void
{
	add_diagnostic_(node_, new_t_Diagnostic(FatalCompilationError_, Analysis_, node_->source_, get_text_span_(node_), str("Could not resolve name `").op_add(get_text_(node_))->op_add(str("`"))));
}

auto add_resolution_error_(t_Semantic_Node *_Nonnull const node_, t_Semantic_Node const *_Nonnull const qualifier_) -> void
{
	add_diagnostic_(node_, new_t_Diagnostic(FatalCompilationError_, Analysis_, node_->source_, get_text_span_(node_), str("Could not resolve name `").op_add(get_text_(node_))->op_add(str("` because qualifier `"))->op_add(get_text_(qualifier_))->op_add(str("` could not be resolved."))));
}

auto add_could_not_determine_type_error_(t_Semantic_Node *_Nonnull const node_) -> void
{
	add_diagnostic_(node_, new_t_Diagnostic(FatalCompilationError_, Analysis_, node_->source_, get_text_span_(node_), str("Could not determine type for `").op_add(get_text_(node_))->op_add(str("`"))));
}

auto build_symbols_(t_Package_Name const *_Nonnull const package_name_, t_system__collections__List<t_Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_) -> t_Symbol const *_Nonnull
{
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const symbols_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	return new_t_Symbol__package(package_name_->unqualified_, symbols_);
}

auto t_Compilation_Unit_Parser::construct(t_Token_Stream *_Nonnull const token_stream_) -> t_Compilation_Unit_Parser *_Nonnull
{
	t_Compilation_Unit_Parser *_Nonnull self = this;
	self->token_stream_ = token_stream_;
	self->compilation_unit_ = none;
	return self;
}

inline t_Compilation_Unit_Parser *_Nonnull new_t_Compilation_Unit_Parser(t_Token_Stream *_Nonnull const token_stream_)
{
	return (new t_Compilation_Unit_Parser())->construct(token_stream_);
}

auto parse_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull
{
	if (cond(equal_op(parser_->compilation_unit_, none)))
	{
		parser_->token_ = next_token_(parser_->token_stream_);
		parser_->compilation_unit_ = parse_compilation_unit_(parser_);
	}

	return parser_->compilation_unit_;
}

auto accept_token_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nullable
{
	t_Syntax_Node const *_Nullable const node_ = parser_->token_;
	parser_->token_ = next_token_(parser_->token_stream_);
	return node_;
}

auto expect_token_(t_Compilation_Unit_Parser *_Nonnull const parser_, i32 const tokenType_) -> t_Syntax_Node const *_Nonnull
{
	if (cond(equal_op(parser_->token_, none)))
	{
		return new_t_Syntax_Node__missing(tokenType_, parser_->token_stream_->source_, source_byte_length_(parser_->token_stream_->source_));
	}

	if (cond(bit_op(bit_arg(equal_op(parser_->token_, none)) || bit_arg(not_equal_op(parser_->token_->kind_, tokenType_)))))
	{
		return new_t_Syntax_Node__missing(tokenType_, parser_->token_stream_->source_, parser_->token_->start_);
	}

	t_Syntax_Node const *_Nullable const node_ = parser_->token_;
	parser_->token_ = next_token_(parser_->token_stream_);
	return node_;
}

auto parse_type_name_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull
{
	if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(parser_->token_->kind_, CodePoint_)) || bit_arg(equal_op(parser_->token_->kind_, String_)))) || bit_arg(equal_op(parser_->token_->kind_, Int_)))) || bit_arg(equal_op(parser_->token_->kind_, Bool_)))) || bit_arg(equal_op(parser_->token_->kind_, Void_)))) || bit_arg(equal_op(parser_->token_->kind_, UnsignedInt_)))))
	{
		return new_t_Syntax_Node(PredefinedType_, accept_token_(parser_));
	}
	else
	{
		t_Syntax_Node const *_Nonnull type_ = new_t_Syntax_Node(IdentifierName_, expect_token_(parser_, Identifier_));
		while (cond(equal_op(parser_->token_->kind_, Dot_)))
		{
			t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
			children_->add_(type_);
			children_->add_(expect_token_(parser_, Dot_));
			t_Syntax_Node const *_Nonnull const identifier_ = expect_token_(parser_, Identifier_);
			if (cond(equal_op(parser_->token_->kind_, LessThan_)))
			{
				t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const genericNameChildren_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
				genericNameChildren_->add_(new_t_Syntax_Node(IdentifierName_, identifier_));
				genericNameChildren_->add_(expect_token_(parser_, LessThan_));
				genericNameChildren_->add_(parse_type_(parser_));
				genericNameChildren_->add_(expect_token_(parser_, GreaterThan_));
				children_->add_(new_t_Syntax_Node(GenericName_, genericNameChildren_));
			}
			else
			{
				children_->add_(new_t_Syntax_Node(IdentifierName_, identifier_));
			}

			type_ = new_t_Syntax_Node(QualifiedName_, children_);
		}

		return type_;
	}
}

auto parse_non_optional_type_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	if (cond(equal_op(parser_->token_->kind_, MutableKeyword_)))
	{
		children_->add_(expect_token_(parser_, MutableKeyword_));
		children_->add_(parse_type_name_(parser_));
		return new_t_Syntax_Node(MutableType_, children_);
	}
	else
	{
		children_->add_(parse_type_name_(parser_));
		return new_t_Syntax_Node(ImmutableType_, children_);
	}
}

auto parse_type_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull
{
	t_Syntax_Node const *_Nonnull type_ = parse_non_optional_type_(parser_);
	while (cond(equal_op(parser_->token_->kind_, Question_)))
	{
		t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
		children_->add_(type_);
		children_->add_(expect_token_(parser_, Question_));
		type_ = new_t_Syntax_Node(ImmutableType_, new_t_Syntax_Node(OptionalType_, children_));
	}

	return type_;
}

auto parse_atom_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	if (cond(equal_op(parser_->token_->kind_, NewKeyword_)))
	{
		children_->add_(expect_token_(parser_, NewKeyword_));
		children_->add_(parse_type_name_(parser_));
		children_->add_(parse_call_arguments_(parser_));
		return new_t_Syntax_Node(NewExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, NotOperator_)))
	{
		children_->add_(expect_token_(parser_, NotOperator_));
		children_->add_(parse_expression_(parser_, i32(8)));
		return new_t_Syntax_Node(NotExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, LeftParen_)))
	{
		children_->add_(expect_token_(parser_, LeftParen_));
		children_->add_(parse_expression_(parser_));
		children_->add_(expect_token_(parser_, RightParen_));
		return new_t_Syntax_Node(ParenthesizedExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, Pipe_)))
	{
		children_->add_(expect_token_(parser_, Pipe_));
		children_->add_(parse_expression_(parser_));
		children_->add_(expect_token_(parser_, Pipe_));
		return new_t_Syntax_Node(MagnitudeExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, Minus_)))
	{
		children_->add_(expect_token_(parser_, Minus_));
		children_->add_(parse_expression_(parser_, i32(8)));
		return new_t_Syntax_Node(NegateExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, NoneKeyword_)))
	{
		children_->add_(expect_token_(parser_, NoneKeyword_));
		return new_t_Syntax_Node(NoneLiteralExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, SelfKeyword_)))
	{
		children_->add_(expect_token_(parser_, SelfKeyword_));
		return new_t_Syntax_Node(SelfExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, TrueKeyword_)))
	{
		children_->add_(expect_token_(parser_, TrueKeyword_));
		return new_t_Syntax_Node(TrueLiteralExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, FalseKeyword_)))
	{
		children_->add_(expect_token_(parser_, FalseKeyword_));
		return new_t_Syntax_Node(FalseLiteralExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, Number_)))
	{
		children_->add_(expect_token_(parser_, Number_));
		return new_t_Syntax_Node(NumericLiteralExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, Identifier_)))
	{
		children_->add_(expect_token_(parser_, Identifier_));
		return new_t_Syntax_Node(IdentifierName_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, StringLiteral_)))
	{
		children_->add_(expect_token_(parser_, StringLiteral_));
		return new_t_Syntax_Node(StringLiteralExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, CodePointLiteral_)))
	{
		children_->add_(expect_token_(parser_, CodePointLiteral_));
		return new_t_Syntax_Node(CodePointLiteralExpression_, children_);
	}

	return new_t_Syntax_Node(IdentifierName_, expect_token_(parser_, Identifier_));
}

auto parse_call_arguments_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	children_->add_(expect_token_(parser_, LeftParen_));
	if (cond(not_equal_op(parser_->token_->kind_, RightParen_)))
	{
		for (;;)
		{
			children_->add_(parse_expression_(parser_));
			if (cond(equal_op(parser_->token_->kind_, Comma_)))
			{
				children_->add_(expect_token_(parser_, Comma_));
			}
			else
			{
				break;
			}
		}
	}

	children_->add_(expect_token_(parser_, RightParen_));
	return new_t_Syntax_Node(ArgumentList_, children_);
}

auto parse_expression_(t_Compilation_Unit_Parser *_Nonnull const parser_, i32 const minPrecedence_) -> t_Syntax_Node const *_Nonnull
{
	t_Syntax_Node const *_Nonnull expression_ = parse_atom_(parser_);
	for (;;)
	{
		t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
		children_->add_(expression_);
		i32 precedence_;
		bit leftAssociative_;
		bit suffixOperator_ = bit_false;
		i32 expressionType_;
		if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(parser_->token_->kind_, Equals_)) || bit_arg(equal_op(parser_->token_->kind_, PlusEquals_)))) || bit_arg(equal_op(parser_->token_->kind_, MinusEquals_)))) && bit_arg(i32_less_than_or_equal(minPrecedence_, i32(1))))))
		{
			precedence_ = i32(1);
			leftAssociative_ = bit_false;
			children_->add_(accept_token_(parser_));
			expressionType_ = AssignmentExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, OrKeyword_)) && bit_arg(i32_less_than_or_equal(minPrecedence_, i32(2))))))
		{
			precedence_ = i32(2);
			leftAssociative_ = bit_true;
			children_->add_(expect_token_(parser_, OrKeyword_));
			expressionType_ = OrExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, AndKeyword_)) && bit_arg(i32_less_than_or_equal(minPrecedence_, i32(3))))))
		{
			precedence_ = i32(3);
			leftAssociative_ = bit_true;
			children_->add_(expect_token_(parser_, AndKeyword_));
			expressionType_ = AndExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, EqualsEquals_)) && bit_arg(i32_less_than_or_equal(minPrecedence_, i32(4))))))
		{
			precedence_ = i32(4);
			leftAssociative_ = bit_true;
			children_->add_(expect_token_(parser_, EqualsEquals_));
			expressionType_ = EqualExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, EqualsSlashEquals_)) && bit_arg(i32_less_than_or_equal(minPrecedence_, i32(4))))))
		{
			precedence_ = i32(4);
			leftAssociative_ = bit_true;
			children_->add_(expect_token_(parser_, EqualsSlashEquals_));
			expressionType_ = NotEqualExpression_;
		}
		else if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(parser_->token_->kind_, LessThan_)) || bit_arg(equal_op(parser_->token_->kind_, LessThanEquals_)))) || bit_arg(equal_op(parser_->token_->kind_, GreaterThan_)))) || bit_arg(equal_op(parser_->token_->kind_, GreaterThanEquals_)))) && bit_arg(i32_less_than_or_equal(minPrecedence_, i32(5))))))
		{
			precedence_ = i32(5);
			leftAssociative_ = bit_true;
			children_->add_(accept_token_(parser_));
			expressionType_ = ComparisonExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, Plus_)) && bit_arg(i32_less_than_or_equal(minPrecedence_, i32(6))))))
		{
			precedence_ = i32(6);
			leftAssociative_ = bit_true;
			children_->add_(expect_token_(parser_, Plus_));
			expressionType_ = AddExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, Minus_)) && bit_arg(i32_less_than_or_equal(minPrecedence_, i32(6))))))
		{
			precedence_ = i32(6);
			leftAssociative_ = bit_true;
			children_->add_(expect_token_(parser_, Minus_));
			expressionType_ = SubtractExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, Asterisk_)) && bit_arg(i32_less_than_or_equal(minPrecedence_, i32(7))))))
		{
			precedence_ = i32(7);
			leftAssociative_ = bit_true;
			children_->add_(expect_token_(parser_, Asterisk_));
			expressionType_ = MultiplyExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, Slash_)) && bit_arg(i32_less_than_or_equal(minPrecedence_, i32(7))))))
		{
			precedence_ = i32(7);
			leftAssociative_ = bit_true;
			children_->add_(expect_token_(parser_, Slash_));
			expressionType_ = DivideExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, Percent_)) && bit_arg(i32_less_than_or_equal(minPrecedence_, i32(7))))))
		{
			precedence_ = i32(7);
			leftAssociative_ = bit_true;
			children_->add_(expect_token_(parser_, Percent_));
			expressionType_ = RemainderExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, LeftParen_)) && bit_arg(i32_less_than_or_equal(minPrecedence_, i32(9))))))
		{
			precedence_ = i32(9);
			leftAssociative_ = bit_true;
			suffixOperator_ = bit_true;
			children_->add_(parse_call_arguments_(parser_));
			expressionType_ = InvocationExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, Dot_)) && bit_arg(i32_less_than_or_equal(minPrecedence_, i32(9))))))
		{
			precedence_ = i32(9);
			leftAssociative_ = bit_true;
			children_->add_(expect_token_(parser_, Dot_));
			expressionType_ = MemberAccessExpression_;
		}
		else if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, LeftBracket_)) && bit_arg(i32_less_than_or_equal(minPrecedence_, i32(9))))))
		{
			precedence_ = i32(9);
			leftAssociative_ = bit_true;
			suffixOperator_ = bit_true;
			children_->add_(expect_token_(parser_, LeftBracket_));
			children_->add_(parse_expression_(parser_));
			children_->add_(expect_token_(parser_, RightBracket_));
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

			children_->add_(parse_expression_(parser_, precedence_));
			expression_ = new_t_Syntax_Node(expressionType_, children_);
		}
		else
		{
			expression_ = new_t_Syntax_Node(expressionType_, children_);
		}
	}
}

auto parse_expression_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull
{
	return parse_expression_(parser_, i32(1));
}

auto parse_statement_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	if (cond(equal_op(parser_->token_->kind_, ReturnKeyword_)))
	{
		children_->add_(expect_token_(parser_, ReturnKeyword_));
		if (cond(not_equal_op(parser_->token_->kind_, Semicolon_)))
		{
			children_->add_(parse_expression_(parser_));
		}

		children_->add_(expect_token_(parser_, Semicolon_));
		return new_t_Syntax_Node(ReturnStatement_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, LoopKeyword_)))
	{
		children_->add_(expect_token_(parser_, LoopKeyword_));
		children_->add_(parse_block_(parser_));
		return new_t_Syntax_Node(LoopStatement_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, WhileKeyword_)))
	{
		children_->add_(expect_token_(parser_, WhileKeyword_));
		children_->add_(parse_expression_(parser_));
		children_->add_(parse_block_(parser_));
		return new_t_Syntax_Node(WhileStatement_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, ForKeyword_)))
	{
		children_->add_(expect_token_(parser_, ForKeyword_));
		children_->add_(parse_variable_declaration_(parser_, bit_false));
		children_->add_(expect_token_(parser_, InKeyword_));
		children_->add_(parse_expression_(parser_));
		children_->add_(parse_block_(parser_));
		return new_t_Syntax_Node(ForStatement_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, DoKeyword_)))
	{
		children_->add_(expect_token_(parser_, DoKeyword_));
		children_->add_(parse_block_(parser_));
		children_->add_(expect_token_(parser_, WhileKeyword_));
		children_->add_(parse_expression_(parser_));
		children_->add_(expect_token_(parser_, Semicolon_));
		return new_t_Syntax_Node(DoWhileStatement_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, IfKeyword_)))
	{
		return parse_if_statement_(parser_);
	}

	if (cond(equal_op(parser_->token_->kind_, BreakKeyword_)))
	{
		children_->add_(expect_token_(parser_, BreakKeyword_));
		children_->add_(expect_token_(parser_, Semicolon_));
		return new_t_Syntax_Node(BreakStatement_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, ContinueKeyword_)))
	{
		children_->add_(expect_token_(parser_, ContinueKeyword_));
		children_->add_(expect_token_(parser_, Semicolon_));
		return new_t_Syntax_Node(ContinueStatement_, children_);
	}

	if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, VarKeyword_)) || bit_arg(equal_op(parser_->token_->kind_, LetKeyword_)))))
	{
		children_->add_(parse_variable_declaration_(parser_, bit_true));
		children_->add_(expect_token_(parser_, Semicolon_));
		return new_t_Syntax_Node(LocalDeclarationStatement_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, LeftBrace_)))
	{
		return parse_block_(parser_);
	}

	children_->add_(parse_expression_(parser_));
	children_->add_(expect_token_(parser_, Semicolon_));
	return new_t_Syntax_Node(ExpressionStatement_, children_);
}

auto parse_if_statement_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	children_->add_(expect_token_(parser_, IfKeyword_));
	children_->add_(parse_expression_(parser_));
	children_->add_(parse_block_(parser_));
	if (cond(equal_op(parser_->token_->kind_, ElseKeyword_)))
	{
		t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const elseChildren_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
		elseChildren_->add_(expect_token_(parser_, ElseKeyword_));
		if (cond(equal_op(parser_->token_->kind_, IfKeyword_)))
		{
			elseChildren_->add_(parse_if_statement_(parser_));
		}
		else
		{
			elseChildren_->add_(parse_block_(parser_));
		}

		children_->add_(new_t_Syntax_Node(ElseClause_, elseChildren_));
	}

	return new_t_Syntax_Node(IfStatement_, children_);
}

auto parse_variable_declaration_(t_Compilation_Unit_Parser *_Nonnull const parser_, bit const allowInitializer_) -> t_Syntax_Node const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, LetKeyword_)) && bit_arg(not_equal_op(parser_->token_->kind_, VarKeyword_)))))
	{
		children_->add_(expect_token_(parser_, LetKeyword_));
	}
	else
	{
		children_->add_(expect_token_(parser_, VarKeyword_));
	}

	children_->add_(expect_token_(parser_, Identifier_));
	children_->add_(expect_token_(parser_, Colon_));
	children_->add_(parse_type_(parser_));
	if (cond(bit_op(bit_arg(allowInitializer_) && bit_arg(equal_op(parser_->token_->kind_, Equals_)))))
	{
		children_->add_(expect_token_(parser_, Equals_));
		children_->add_(parse_expression_(parser_));
	}

	return new_t_Syntax_Node(VariableDeclaration_, children_);
}

auto parse_block_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	children_->add_(expect_token_(parser_, LeftBrace_));
	while (cond(bit_op(bit_arg(not_equal_op(parser_->token_->kind_, RightBrace_)) && bit_arg(not_equal_op(parser_->token_->kind_, EndOfFileToken_)))))
	{
		t_Syntax_Node const *_Nonnull const startToken_ = parser_->token_;
		children_->add_(parse_statement_(parser_));
		if (cond(equal_op(parser_->token_, startToken_)))
		{
			t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const skipped_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
			while (cond(bit_op(bit_arg(bit_op(bit_arg(not_equal_op(parser_->token_->kind_, LeftBrace_)) && bit_arg(not_equal_op(parser_->token_->kind_, RightBrace_)))) && bit_arg(not_equal_op(parser_->token_->kind_, EndOfFileToken_)))))
			{
				i32 const currentTokenType_ = parser_->token_->kind_;
				skipped_->add_(accept_token_(parser_));
				if (cond(equal_op(currentTokenType_, Semicolon_)))
				{
					break;
				}
			}

			children_->add_(new_t_Syntax_Node__skipped(skipped_));
		}
	}

	children_->add_(expect_token_(parser_, RightBrace_));
	return new_t_Syntax_Node(Block_, children_);
}

auto parse_parameter_list_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	children_->add_(expect_token_(parser_, LeftParen_));
	if (cond(not_equal_op(parser_->token_->kind_, RightParen_)))
	{
		for (;;)
		{
			t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const parameterChildren_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
			if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, MutableKeyword_)) || bit_arg(equal_op(parser_->token_->kind_, SelfKeyword_)))))
			{
				if (cond(equal_op(parser_->token_->kind_, MutableKeyword_)))
				{
					parameterChildren_->add_(expect_token_(parser_, MutableKeyword_));
				}

				parameterChildren_->add_(expect_token_(parser_, SelfKeyword_));
				children_->add_(new_t_Syntax_Node(SelfParameter_, parameterChildren_));
			}
			else
			{
				bit const mutableBinding_ = equal_op(parser_->token_->kind_, VarKeyword_);
				if (cond(equal_op(parser_->token_->kind_, VarKeyword_)))
				{
					parameterChildren_->add_(expect_token_(parser_, VarKeyword_));
				}

				parameterChildren_->add_(expect_token_(parser_, Identifier_));
				parameterChildren_->add_(expect_token_(parser_, Colon_));
				t_Syntax_Node const *_Nonnull const type_ = parse_type_(parser_);
				parameterChildren_->add_(type_);
				children_->add_(new_t_Syntax_Node(Parameter_, parameterChildren_));
			}

			if (cond(equal_op(parser_->token_->kind_, Comma_)))
			{
				children_->add_(expect_token_(parser_, Comma_));
			}
			else
			{
				break;
			}
		}
	}

	children_->add_(expect_token_(parser_, RightParen_));
	return new_t_Syntax_Node(ParameterList_, children_);
}

auto parse_member_declaration_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(parser_->token_->kind_, PublicKeyword_)) || bit_arg(equal_op(parser_->token_->kind_, ProtectedKeyword_)))) || bit_arg(equal_op(parser_->token_->kind_, InternalKeyword_)))) || bit_arg(equal_op(parser_->token_->kind_, PrivateKeyword_)))))
	{
		children_->add_(accept_token_(parser_));
	}
	else
	{
		children_->add_(expect_token_(parser_, PublicKeyword_));
	}

	if (cond(equal_op(parser_->token_->kind_, NewKeyword_)))
	{
		children_->add_(expect_token_(parser_, NewKeyword_));
		if (cond(equal_op(parser_->token_->kind_, Identifier_)))
		{
			children_->add_(expect_token_(parser_, Identifier_));
		}

		children_->add_(parse_parameter_list_(parser_));
		children_->add_(parse_block_(parser_));
		return new_t_Syntax_Node(ConstructorDeclaration_, children_);
	}

	if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, VarKeyword_)) || bit_arg(equal_op(parser_->token_->kind_, LetKeyword_)))))
	{
		children_->add_(parse_variable_declaration_(parser_, bit_false));
		children_->add_(expect_token_(parser_, Semicolon_));
		return new_t_Syntax_Node(FieldDeclaration_, children_);
	}

	children_->add_(expect_token_(parser_, Identifier_));
	children_->add_(parse_parameter_list_(parser_));
	children_->add_(expect_token_(parser_, Arrow_));
	children_->add_(parse_type_(parser_));
	children_->add_(parse_block_(parser_));
	return new_t_Syntax_Node(MethodDeclaration_, children_);
}

auto parse_declaration_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(parser_->token_->kind_, PublicKeyword_)) || bit_arg(equal_op(parser_->token_->kind_, ProtectedKeyword_)))) || bit_arg(equal_op(parser_->token_->kind_, InternalKeyword_)))) || bit_arg(equal_op(parser_->token_->kind_, PrivateKeyword_)))))
	{
		children_->add_(accept_token_(parser_));
	}
	else
	{
		children_->add_(expect_token_(parser_, PublicKeyword_));
	}

	if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, VarKeyword_)) || bit_arg(equal_op(parser_->token_->kind_, LetKeyword_)))))
	{
		children_->add_(parse_variable_declaration_(parser_, bit_true));
		children_->add_(expect_token_(parser_, Semicolon_));
		return new_t_Syntax_Node(GlobalDeclaration_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, ClassKeyword_)))
	{
		children_->add_(expect_token_(parser_, ClassKeyword_));
		children_->add_(expect_token_(parser_, Identifier_));
		children_->add_(expect_token_(parser_, LeftBrace_));
		while (cond(bit_op(bit_arg(not_equal_op(parser_->token_->kind_, RightBrace_)) && bit_arg(not_equal_op(parser_->token_->kind_, EndOfFileToken_)))))
		{
			t_Syntax_Node const *_Nonnull const startToken_ = parser_->token_;
			children_->add_(parse_member_declaration_(parser_));
			if (cond(equal_op(parser_->token_, startToken_)))
			{
				children_->add_(new_t_Syntax_Node__skipped(accept_token_(parser_)));
			}
		}

		children_->add_(expect_token_(parser_, RightBrace_));
		return new_t_Syntax_Node(ClassDeclaration_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, StructKeyword_)))
	{
		children_->add_(expect_token_(parser_, StructKeyword_));
		children_->add_(expect_token_(parser_, Identifier_));
		children_->add_(expect_token_(parser_, LeftBrace_));
		while (cond(bit_op(bit_arg(not_equal_op(parser_->token_->kind_, RightBrace_)) && bit_arg(not_equal_op(parser_->token_->kind_, EndOfFileToken_)))))
		{
			t_Syntax_Node const *_Nonnull const startToken_ = parser_->token_;
			children_->add_(parse_member_declaration_(parser_));
			if (cond(equal_op(parser_->token_, startToken_)))
			{
				children_->add_(new_t_Syntax_Node__skipped(accept_token_(parser_)));
			}
		}

		children_->add_(expect_token_(parser_, RightBrace_));
		return new_t_Syntax_Node(StructDeclaration_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, EnumKeyword_)))
	{
		children_->add_(expect_token_(parser_, EnumKeyword_));
		children_->add_(expect_token_(parser_, StructKeyword_));
		children_->add_(expect_token_(parser_, Identifier_));
		children_->add_(expect_token_(parser_, LeftBrace_));
		while (cond(bit_op(bit_arg(not_equal_op(parser_->token_->kind_, RightBrace_)) && bit_arg(not_equal_op(parser_->token_->kind_, EndOfFileToken_)))))
		{
			t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const memberChildren_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
			memberChildren_->add_(expect_token_(parser_, Identifier_));
			if (cond(equal_op(parser_->token_->kind_, Equals_)))
			{
				memberChildren_->add_(expect_token_(parser_, Equals_));
				memberChildren_->add_(expect_token_(parser_, Number_));
			}

			if (cond(not_equal_op(parser_->token_->kind_, RightBrace_)))
			{
				memberChildren_->add_(expect_token_(parser_, Comma_));
			}

			children_->add_(new_t_Syntax_Node(EnumMemberDeclaration_, memberChildren_));
		}

		children_->add_(expect_token_(parser_, RightBrace_));
		return new_t_Syntax_Node(EnumDeclaration_, children_);
	}

	children_->add_(expect_token_(parser_, Identifier_));
	children_->add_(parse_parameter_list_(parser_));
	children_->add_(expect_token_(parser_, Arrow_));
	children_->add_(parse_type_(parser_));
	children_->add_(parse_block_(parser_));
	return new_t_Syntax_Node(FunctionDeclaration_, children_);
}

auto parse_compilation_unit_(t_Compilation_Unit_Parser *_Nonnull const parser_) -> t_Syntax_Node const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	while (cond(bit_op(bit_arg(not_equal_op(parser_->token_, none)) && bit_arg(not_equal_op(parser_->token_->kind_, EndOfFileToken_)))))
	{
		t_Syntax_Node const *_Nonnull const startToken_ = parser_->token_;
		children_->add_(parse_declaration_(parser_));
		if (cond(equal_op(parser_->token_, startToken_)))
		{
			children_->add_(new_t_Syntax_Node__skipped(accept_token_(parser_)));
		}
	}

	children_->add_(expect_token_(parser_, EndOfFileToken_));
	return new_t_Syntax_Node(CompilationUnit_, children_);
}

auto lexically_analyze_(t_Source_Text const *_Nonnull const source_) -> t_Token_Stream *_Nonnull
{
	return new_t_Token_Stream(source_);
}

auto parse_package_(t_system__collections__List<t_Source_Text const *_Nonnull> const *_Nonnull const sources_) -> t_Syntax_Node const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	for (t_Source_Text const *_Nonnull const source_ : *(sources_))
	{
		t_Token_Stream *_Nonnull const token_stream_ = lexically_analyze_(source_);
		t_Compilation_Unit_Parser *_Nonnull const compilation_unit_parser_ = new_t_Compilation_Unit_Parser(token_stream_);
		children_->add_(parse_(compilation_unit_parser_));
	}

	return new_t_Syntax_Node(PackageNode_, children_);
}

auto t_Syntax_Node::construct(i32 const type_, t_Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_) -> t_Syntax_Node *_Nonnull
{
	t_Syntax_Node *_Nonnull self = this;
	self->kind_ = type_;
	self->is_missing_ = bit_false;
	self->source_ = source_;
	self->start_ = start_;
	self->byte_length_ = length_;
	self->children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	self->node_diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	return self;
}

inline t_Syntax_Node *_Nonnull new_t_Syntax_Node(i32 const type_, t_Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_)
{
	return (new t_Syntax_Node())->construct(type_, source_, start_, length_);
}

auto t_Syntax_Node::construct(i32 const type_, bit const isMissing_, t_Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_) -> t_Syntax_Node *_Nonnull
{
	t_Syntax_Node *_Nonnull self = this;
	self->kind_ = type_;
	self->is_missing_ = isMissing_;
	self->source_ = source_;
	self->start_ = start_;
	self->byte_length_ = length_;
	self->children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	self->node_diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	return self;
}

inline t_Syntax_Node *_Nonnull new_t_Syntax_Node(i32 const type_, bit const isMissing_, t_Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_)
{
	return (new t_Syntax_Node())->construct(type_, isMissing_, source_, start_, length_);
}

auto t_Syntax_Node::construct(i32 const type_, t_Syntax_Node const *_Nonnull const child_) -> t_Syntax_Node *_Nonnull
{
	t_Syntax_Node *_Nonnull self = this;
	self->kind_ = type_;
	self->is_missing_ = child_->is_missing_;
	self->source_ = child_->source_;
	self->start_ = child_->start_;
	self->byte_length_ = child_->byte_length_;
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	children_->add_(child_);
	self->children_ = children_;
	self->node_diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	return self;
}

inline t_Syntax_Node *_Nonnull new_t_Syntax_Node(i32 const type_, t_Syntax_Node const *_Nonnull const child_)
{
	return (new t_Syntax_Node())->construct(type_, child_);
}

auto t_Syntax_Node::construct(i32 const type_, t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull const children_) -> t_Syntax_Node *_Nonnull
{
	t_Syntax_Node *_Nonnull self = this;
	self->kind_ = type_;
	self->is_missing_ = bit_false;
	self->source_ = children_->op_Element(i32(0))->source_;
	self->start_ = children_->op_Element(i32(0))->start_;
	t_Syntax_Node const *_Nonnull const lastChild_ = children_->op_Element(children_->op_magnitude()->op_subtract(i32(1)));
	self->byte_length_ = lastChild_->start_.op_subtract(start_)->op_add(lastChild_->byte_length_);
	self->children_ = children_;
	self->node_diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	return self;
}

inline t_Syntax_Node *_Nonnull new_t_Syntax_Node(i32 const type_, t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull const children_)
{
	return (new t_Syntax_Node())->construct(type_, children_);
}

auto t_Syntax_Node::construct_missing(i32 const type_, t_Source_Text const *_Nonnull const source_, u32 const start_) -> t_Syntax_Node *_Nonnull
{
	t_Syntax_Node *_Nonnull self = this;
	self->kind_ = type_;
	self->is_missing_ = bit_true;
	self->source_ = source_;
	self->start_ = start_;
	self->byte_length_ = i32(0);
	self->children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	self->node_diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	t_Text_Span const *_Nonnull const span_ = new_t_Text_Span(start_, i32(0));
	self->node_diagnostics_->add_(new_t_Diagnostic(CompilationError_, Parsing_, source_, span_, str("Missing token of type ").op_add(type_)));
	return self;
}

inline t_Syntax_Node *_Nonnull new_t_Syntax_Node__missing(i32 const type_, t_Source_Text const *_Nonnull const source_, u32 const start_)
{
	return (new t_Syntax_Node())->construct_missing(type_, source_, start_);
}

auto t_Syntax_Node::construct_skipped(t_Syntax_Node const *_Nonnull const skipped_node_) -> t_Syntax_Node *_Nonnull
{
	t_Syntax_Node *_Nonnull self = this;
	self->kind_ = SkippedTokens_;
	self->is_missing_ = skipped_node_->is_missing_;
	self->source_ = skipped_node_->source_;
	self->start_ = skipped_node_->start_;
	self->byte_length_ = skipped_node_->byte_length_;
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	children_->add_(skipped_node_);
	self->children_ = children_;
	self->node_diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	t_Text_Span const *_Nonnull const span_ = new_t_Text_Span(skipped_node_->start_, skipped_node_->byte_length_);
	self->node_diagnostics_->add_(new_t_Diagnostic(CompilationError_, Parsing_, skipped_node_->source_, span_, str("Skipped unexpected token of type ").op_add(skipped_node_->kind_)));
	return self;
}

inline t_Syntax_Node *_Nonnull new_t_Syntax_Node__skipped(t_Syntax_Node const *_Nonnull const skipped_node_)
{
	return (new t_Syntax_Node())->construct_skipped(skipped_node_);
}

auto t_Syntax_Node::construct_skipped(t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull const skipped_nodes_) -> t_Syntax_Node *_Nonnull
{
	t_Syntax_Node *_Nonnull self = this;
	self->kind_ = SkippedTokens_;
	self->is_missing_ = bit_false;
	self->source_ = skipped_nodes_->op_Element(i32(0))->source_;
	self->start_ = skipped_nodes_->op_Element(i32(0))->start_;
	t_Syntax_Node const *_Nonnull const lastChild_ = skipped_nodes_->op_Element(skipped_nodes_->op_magnitude()->op_subtract(i32(1)));
	self->byte_length_ = lastChild_->start_.op_subtract(start_)->op_add(lastChild_->byte_length_);
	self->children_ = children_;
	self->node_diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	t_Text_Span const *_Nonnull const span_ = new_t_Text_Span(self->start_, self->byte_length_);
	self->node_diagnostics_->add_(new_t_Diagnostic(CompilationError_, Parsing_, self->source_, span_, str("Skipped ").op_add(skipped_nodes_->op_magnitude())->op_add(str(" unexpected token(s)"))));
	return self;
}

inline t_Syntax_Node *_Nonnull new_t_Syntax_Node__skipped(t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull const skipped_nodes_)
{
	return (new t_Syntax_Node())->construct_skipped(skipped_nodes_);
}

auto get_text_(t_Syntax_Node const *_Nonnull const syntax_) -> str
{
	return syntax_->source_->text_.Substring_(syntax_->start_, syntax_->byte_length_);
}

auto first_child_syntax_(t_Syntax_Node const *_Nonnull const syntax_, i32 const type_) -> t_Syntax_Node const *_Nullable
{
	for (t_Syntax_Node const *_Nonnull const child_ : *(syntax_->children_))
	{
		if (cond(equal_op(child_->kind_, type_)))
		{
			return child_;
		}
	}

	return none;
}

auto has_child_(t_Syntax_Node const *_Nonnull const syntax_, i32 const type_) -> bit
{
	for (t_Syntax_Node const *_Nonnull const child_ : *(syntax_->children_))
	{
		if (cond(equal_op(child_->kind_, type_)))
		{
			return bit_true;
		}
	}

	return bit_false;
}

auto add_(t_Syntax_Node const *_Nonnull const syntax_, t_Diagnostic const *_Nonnull const diagnostic_) -> void
{
	syntax_->node_diagnostics_->add_(diagnostic_);
}

auto all_diagnostics_(t_Syntax_Node const *_Nonnull const syntax_) -> t_system__collections__List<t_Diagnostic const *_Nonnull> *_Nonnull
{
	t_system__collections__List<t_Diagnostic const *_Nonnull> *_Nonnull diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	collect_syntax_diagnostics_(syntax_, diagnostics_);
	return diagnostics_;
}

auto collect_syntax_diagnostics_(t_Syntax_Node const *_Nonnull const syntax_, t_system__collections__List<t_Diagnostic const *_Nonnull> *_Nonnull const diagnostics_) -> void
{
	for (t_Diagnostic const *_Nonnull const diagnostic_ : *(syntax_->node_diagnostics_))
	{
		diagnostics_->add_(diagnostic_);
	}

	for (t_Syntax_Node const *_Nonnull const child_ : *(syntax_->children_))
	{
		collect_syntax_diagnostics_(child_, diagnostics_);
	}
}

auto members_(t_Syntax_Node const *_Nonnull const syntax_) -> t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const members_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	for (t_Syntax_Node const *_Nonnull const child_ : *(syntax_->children_))
	{
		if (cond(bit_op(bit_arg(bit_op(bit_arg(equal_op(child_->kind_, ConstructorDeclaration_)) || bit_arg(equal_op(child_->kind_, FieldDeclaration_)))) || bit_arg(equal_op(child_->kind_, MethodDeclaration_)))))
		{
			members_->add_(child_);
		}
	}

	return members_;
}

auto parameters_(t_Syntax_Node const *_Nonnull const syntax_) -> t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const parameters_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	for (t_Syntax_Node const *_Nonnull const child_ : *(syntax_->children_))
	{
		if (cond(bit_op(bit_arg(equal_op(child_->kind_, Parameter_)) || bit_arg(equal_op(child_->kind_, SelfParameter_)))))
		{
			parameters_->add_(child_);
		}
	}

	return parameters_;
}

auto statements_(t_Syntax_Node const *_Nonnull const syntax_) -> t_system__collections__List<t_Syntax_Node const *_Nonnull> const *_Nonnull
{
	t_system__collections__List<t_Syntax_Node const *_Nonnull> *_Nonnull const statements_ = new_t_system__collections__List<t_Syntax_Node const *_Nonnull>();
	for (t_Syntax_Node const *_Nonnull const child_ : *(syntax_->children_))
	{
		if (cond(bit_op(bit_arg(not_equal_op(child_->kind_, LeftBrace_)) && bit_arg(not_equal_op(child_->kind_, RightBrace_)))))
		{
			statements_->add_(child_);
		}
	}

	return statements_;
}

auto access_modifier_(t_Syntax_Node const *_Nonnull const syntax_) -> t_Syntax_Node const *_Nullable
{
	for (t_Syntax_Node const *_Nonnull const child_ : *(syntax_->children_))
	{
		if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(child_->kind_, PublicKeyword_)) || bit_arg(equal_op(child_->kind_, ProtectedKeyword_)))) || bit_arg(equal_op(child_->kind_, InternalKeyword_)))) || bit_arg(equal_op(child_->kind_, PrivateKeyword_)))))
		{
			return child_;
		}
	}

	return none;
}

auto t_Token_Stream::construct(t_Source_Text const *_Nonnull const source_) -> t_Token_Stream *_Nonnull
{
	t_Token_Stream *_Nonnull self = this;
	self->source_ = source_;
	self->position_ = i32(0);
	self->diagnostics_ = new_t_system__collections__List<t_Diagnostic const *_Nonnull>();
	self->end_of_file_ = bit_false;
	return self;
}

inline t_Token_Stream *_Nonnull new_t_Token_Stream(t_Source_Text const *_Nonnull const source_)
{
	return (new t_Token_Stream())->construct(source_);
}

auto next_token_(t_Token_Stream *_Nonnull const tokens_) -> t_Syntax_Node const *_Nullable
{
	if (cond(u32_greater_than_or_equal(tokens_->position_, source_byte_length_(tokens_->source_))))
	{
		return end_of_file_token_(tokens_);
	}

	u32 end_ = i32_negate(i32(1));
	while (cond(u32_less_than(tokens_->position_, source_byte_length_(tokens_->source_))))
	{
		cp const curChar_ = tokens_->source_->text_.op_Element(tokens_->position_);
		if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(curChar_, cp(' '))) || bit_arg(equal_op(curChar_, cp('\t'))))) || bit_arg(equal_op(curChar_, cp('\n'))))) || bit_arg(equal_op(curChar_, cp('\r'))))))
		{
			tokens_->position_.op_add_assign(i32(1));
			continue;
		}
		else if (cond(equal_op(curChar_, cp('{'))))
		{
			return new_operator_token_(tokens_, LeftBrace_);
		}
		else if (cond(equal_op(curChar_, cp('}'))))
		{
			return new_operator_token_(tokens_, RightBrace_);
		}
		else if (cond(equal_op(curChar_, cp('('))))
		{
			return new_operator_token_(tokens_, LeftParen_);
		}
		else if (cond(equal_op(curChar_, cp(')'))))
		{
			return new_operator_token_(tokens_, RightParen_);
		}
		else if (cond(equal_op(curChar_, cp(';'))))
		{
			return new_operator_token_(tokens_, Semicolon_);
		}
		else if (cond(equal_op(curChar_, cp(','))))
		{
			return new_operator_token_(tokens_, Comma_);
		}
		else if (cond(equal_op(curChar_, cp('.'))))
		{
			return new_operator_token_(tokens_, Dot_);
		}
		else if (cond(equal_op(curChar_, cp(':'))))
		{
			return new_operator_token_(tokens_, Colon_);
		}
		else if (cond(equal_op(curChar_, cp('['))))
		{
			return new_operator_token_(tokens_, LeftBracket_);
		}
		else if (cond(equal_op(curChar_, cp(']'))))
		{
			return new_operator_token_(tokens_, RightBracket_);
		}
		else if (cond(equal_op(curChar_, cp('?'))))
		{
			return new_operator_token_(tokens_, Question_);
		}
		else if (cond(equal_op(curChar_, cp('|'))))
		{
			return new_operator_token_(tokens_, Pipe_);
		}
		else if (cond(equal_op(curChar_, cp('*'))))
		{
			return new_operator_token_(tokens_, Asterisk_);
		}
		else if (cond(equal_op(curChar_, cp('='))))
		{
			if (cond(bit_op(bit_arg(tokens_->position_.op_add(i32(1))->op_less_than(source_byte_length_(tokens_->source_))) && bit_arg(equal_op(tokens_->source_->text_.op_Element(tokens_->position_.op_add(i32(1))), cp('='))))))
			{
				return new_operator_token_(tokens_, EqualsEquals_, i32(2));
			}

			if (cond(bit_op(bit_arg(bit_op(bit_arg(tokens_->position_.op_add(i32(2))->op_less_than(source_byte_length_(tokens_->source_))) && bit_arg(equal_op(tokens_->source_->text_.op_Element(tokens_->position_.op_add(i32(1))), cp('/'))))) && bit_arg(equal_op(tokens_->source_->text_.op_Element(tokens_->position_.op_add(i32(2))), cp('='))))))
			{
				return new_operator_token_(tokens_, EqualsSlashEquals_, i32(3));
			}

			return new_operator_token_(tokens_, Equals_);
		}
		else if (cond(equal_op(curChar_, cp('+'))))
		{
			if (cond(bit_op(bit_arg(tokens_->position_.op_add(i32(1))->op_less_than(source_byte_length_(tokens_->source_))) && bit_arg(equal_op(tokens_->source_->text_.op_Element(tokens_->position_.op_add(i32(1))), cp('='))))))
			{
				return new_operator_token_(tokens_, PlusEquals_, i32(2));
			}

			return new_operator_token_(tokens_, Plus_);
		}
		else if (cond(equal_op(curChar_, cp('-'))))
		{
			if (cond(bit_op(bit_arg(tokens_->position_.op_add(i32(1))->op_less_than(source_byte_length_(tokens_->source_))) && bit_arg(equal_op(tokens_->source_->text_.op_Element(tokens_->position_.op_add(i32(1))), cp('>'))))))
			{
				return new_operator_token_(tokens_, Arrow_, i32(2));
			}

			if (cond(bit_op(bit_arg(tokens_->position_.op_add(i32(1))->op_less_than(source_byte_length_(tokens_->source_))) && bit_arg(equal_op(tokens_->source_->text_.op_Element(tokens_->position_.op_add(i32(1))), cp('='))))))
			{
				return new_operator_token_(tokens_, MinusEquals_, i32(2));
			}

			return new_operator_token_(tokens_, Minus_);
		}
		else if (cond(equal_op(curChar_, cp('/'))))
		{
			if (cond(bit_op(bit_arg(tokens_->position_.op_add(i32(1))->op_less_than(source_byte_length_(tokens_->source_))) && bit_arg(equal_op(tokens_->source_->text_.op_Element(tokens_->position_.op_add(i32(1))), cp('/'))))))
			{
				while (cond(bit_op(bit_arg(bit_op(bit_arg(u32_less_than(tokens_->position_, source_byte_length_(tokens_->source_))) && bit_arg(not_equal_op(tokens_->source_->text_.op_Element(tokens_->position_), cp('\r'))))) && bit_arg(not_equal_op(tokens_->source_->text_.op_Element(tokens_->position_), cp('\n'))))))
				{
					tokens_->position_.op_add_assign(i32(1));
				}

				continue;
			}

			if (cond(bit_op(bit_arg(tokens_->position_.op_add(i32(1))->op_less_than(source_byte_length_(tokens_->source_))) && bit_arg(equal_op(tokens_->source_->text_.op_Element(tokens_->position_.op_add(i32(1))), cp('*'))))))
			{
				tokens_->position_.op_add_assign(i32(2));
				bit lastCharStar_ = bit_false;
				while (cond(bit_op(bit_arg(u32_less_than(tokens_->position_, source_byte_length_(tokens_->source_))) && bit_arg(bit_not(bit_op(bit_arg(lastCharStar_) && bit_arg(equal_op(tokens_->source_->text_.op_Element(tokens_->position_), cp('/')))))))))
				{
					lastCharStar_ = equal_op(tokens_->source_->text_.op_Element(tokens_->position_), cp('*'));
					tokens_->position_.op_add_assign(i32(1));
				}

				tokens_->position_.op_add_assign(i32(1));
				continue;
			}

			return new_operator_token_(tokens_, Slash_);
		}
		else if (cond(equal_op(curChar_, cp('%'))))
		{
			return new_operator_token_(tokens_, Percent_);
		}
		else if (cond(equal_op(curChar_, cp('<'))))
		{
			if (cond(bit_op(bit_arg(tokens_->position_.op_add(i32(1))->op_less_than(source_byte_length_(tokens_->source_))) && bit_arg(equal_op(tokens_->source_->text_.op_Element(tokens_->position_.op_add(i32(1))), cp('='))))))
			{
				return new_operator_token_(tokens_, LessThanEquals_, i32(2));
			}

			return new_operator_token_(tokens_, LessThan_);
		}
		else if (cond(equal_op(curChar_, cp('>'))))
		{
			if (cond(bit_op(bit_arg(tokens_->position_.op_add(i32(1))->op_less_than(source_byte_length_(tokens_->source_))) && bit_arg(equal_op(tokens_->source_->text_.op_Element(tokens_->position_.op_add(i32(1))), cp('='))))))
			{
				return new_operator_token_(tokens_, GreaterThanEquals_, i32(2));
			}

			return new_operator_token_(tokens_, GreaterThan_);
		}
		else if (cond(equal_op(curChar_, cp('"'))))
		{
			end_ = tokens_->position_.op_add(i32(1));
			bit escaped_ = bit_false;
			while (cond(bit_op(bit_arg(u32_less_than(end_, source_byte_length_(tokens_->source_))) && bit_arg(bit_op(bit_arg(not_equal_op(tokens_->source_->text_.op_Element(end_), cp('"'))) || bit_arg(escaped_))))))
			{
				escaped_ = bit_op(bit_arg(equal_op(tokens_->source_->text_.op_Element(end_), cp('\\'))) && bit_arg(bit_not(escaped_)));
				end_.op_add_assign(i32(1));
			}

			end_.op_add_assign(i32(1));
			return new_token_(tokens_, StringLiteral_, end_);
		}
		else if (cond(equal_op(curChar_, cp('\''))))
		{
			end_ = tokens_->position_.op_add(i32(1));
			bit escaped_ = bit_false;
			while (cond(bit_op(bit_arg(u32_less_than(end_, source_byte_length_(tokens_->source_))) && bit_arg(bit_op(bit_arg(not_equal_op(tokens_->source_->text_.op_Element(end_), cp('\''))) || bit_arg(escaped_))))))
			{
				escaped_ = bit_op(bit_arg(equal_op(tokens_->source_->text_.op_Element(end_), cp('\\'))) && bit_arg(bit_not(escaped_)));
				end_.op_add_assign(i32(1));
			}

			end_.op_add_assign(i32(1));
			return new_token_(tokens_, CodePointLiteral_, end_);
		}
		else
		{
			if (cond(is_identifier_char_(curChar_)))
			{
				end_ = tokens_->position_.op_add(i32(1));
				while (cond(is_identifier_char_(tokens_->source_->text_.op_Element(end_))))
				{
					end_.op_add_assign(i32(1));
				}

				return new_identifier_or_keyword_token_(tokens_, end_);
			}

			if (cond(is_number_char_(curChar_)))
			{
				end_ = tokens_->position_.op_add(i32(1));
				while (cond(is_number_char_(tokens_->source_->text_.op_Element(end_))))
				{
					end_.op_add_assign(i32(1));
				}

				return new_token_(tokens_, Number_, end_);
			}

			t_Text_Span const *_Nonnull diagnosticSpan_ = new_t_Text_Span(tokens_->position_, i32(1));
			tokens_->diagnostics_->add_(new_t_Diagnostic(CompilationError_, Lexing_, tokens_->source_, diagnosticSpan_, str("Invalid character `").op_add(curChar_)->op_add(str("`"))));
			tokens_->position_ = end_;
		}
	}

	return end_of_file_token_(tokens_);
}

auto end_of_file_token_(t_Token_Stream *_Nonnull const tokens_) -> t_Syntax_Node const *_Nullable
{
	if (cond(tokens_->end_of_file_))
	{
		return none;
	}

	tokens_->end_of_file_ = bit_true;
	return new_token_(tokens_, EndOfFileToken_, tokens_->position_);
}

auto new_identifier_or_keyword_token_(t_Token_Stream *_Nonnull const tokens_, u32 const end_) -> t_Syntax_Node const *_Nonnull
{
	u32 const length_ = end_.op_subtract(tokens_->position_);
	str const value_ = tokens_->source_->text_.Substring_(tokens_->position_, length_);
	i32 type_;
	if (cond(equal_op(value_, str("new"))))
	{
		type_ = NewKeyword_;
	}
	else if (cond(equal_op(value_, str("not"))))
	{
		type_ = NotOperator_;
	}
	else if (cond(equal_op(value_, str("null"))))
	{
		type_ = NullReservedWord_;
	}
	else if (cond(equal_op(value_, str("self"))))
	{
		type_ = SelfKeyword_;
	}
	else if (cond(equal_op(value_, str("true"))))
	{
		type_ = TrueKeyword_;
	}
	else if (cond(equal_op(value_, str("false"))))
	{
		type_ = FalseKeyword_;
	}
	else if (cond(equal_op(value_, str("mut"))))
	{
		type_ = MutableKeyword_;
	}
	else if (cond(equal_op(value_, str("code_point"))))
	{
		type_ = CodePoint_;
	}
	else if (cond(equal_op(value_, str("string"))))
	{
		type_ = String_;
	}
	else if (cond(equal_op(value_, str("int"))))
	{
		type_ = Int_;
	}
	else if (cond(equal_op(value_, str("bool"))))
	{
		type_ = Bool_;
	}
	else if (cond(equal_op(value_, str("void"))))
	{
		type_ = Void_;
	}
	else if (cond(equal_op(value_, str("uint"))))
	{
		type_ = UnsignedInt_;
	}
	else if (cond(equal_op(value_, str("var"))))
	{
		type_ = VarKeyword_;
	}
	else if (cond(equal_op(value_, str("and"))))
	{
		type_ = AndKeyword_;
	}
	else if (cond(equal_op(value_, str("or"))))
	{
		type_ = OrKeyword_;
	}
	else if (cond(equal_op(value_, str("return"))))
	{
		type_ = ReturnKeyword_;
	}
	else if (cond(equal_op(value_, str("loop"))))
	{
		type_ = LoopKeyword_;
	}
	else if (cond(equal_op(value_, str("while"))))
	{
		type_ = WhileKeyword_;
	}
	else if (cond(equal_op(value_, str("for"))))
	{
		type_ = ForKeyword_;
	}
	else if (cond(equal_op(value_, str("let"))))
	{
		type_ = LetKeyword_;
	}
	else if (cond(equal_op(value_, str("in"))))
	{
		type_ = InKeyword_;
	}
	else if (cond(equal_op(value_, str("do"))))
	{
		type_ = DoKeyword_;
	}
	else if (cond(equal_op(value_, str("if"))))
	{
		type_ = IfKeyword_;
	}
	else if (cond(equal_op(value_, str("else"))))
	{
		type_ = ElseKeyword_;
	}
	else if (cond(equal_op(value_, str("break"))))
	{
		type_ = BreakKeyword_;
	}
	else if (cond(equal_op(value_, str("continue"))))
	{
		type_ = ContinueKeyword_;
	}
	else if (cond(equal_op(value_, str("private"))))
	{
		type_ = PrivateKeyword_;
	}
	else if (cond(equal_op(value_, str("protected"))))
	{
		type_ = ProtectedKeyword_;
	}
	else if (cond(equal_op(value_, str("public"))))
	{
		type_ = PublicKeyword_;
	}
	else if (cond(equal_op(value_, str("internal"))))
	{
		type_ = InternalKeyword_;
	}
	else if (cond(equal_op(value_, str("class"))))
	{
		type_ = ClassKeyword_;
	}
	else if (cond(equal_op(value_, str("enum"))))
	{
		type_ = EnumKeyword_;
	}
	else if (cond(equal_op(value_, str("struct"))))
	{
		type_ = StructKeyword_;
	}
	else if (cond(equal_op(value_, str("none"))))
	{
		type_ = NoneKeyword_;
	}
	else
	{
		type_ = Identifier_;
		if (cond(bit_op(bit_arg(value_.ByteLength_()->op_greater_than(i32(1))) && bit_arg(equal_op(value_.op_Element(value_.ByteLength_()->op_subtract(i32(1))), cp('_'))))))
		{
			t_Text_Span const *_Nonnull diagnosticSpan_ = new_t_Text_Span(tokens_->position_, end_.op_subtract(tokens_->position_));
			tokens_->diagnostics_->add_(new_t_Diagnostic(CompilationError_, Lexing_, tokens_->source_, diagnosticSpan_, str("Identifiers ending with underscore are reserved `").op_add(value_)->op_add(str("`"))));
		}
	}

	return new_token_(tokens_, type_, end_);
}

auto new_operator_token_(t_Token_Stream *_Nonnull const tokens_, i32 const type_) -> t_Syntax_Node const *_Nonnull
{
	return new_token_(tokens_, type_, tokens_->position_.op_add(i32(1)));
}

auto new_operator_token_(t_Token_Stream *_Nonnull const tokens_, i32 const type_, u32 const length_) -> t_Syntax_Node const *_Nonnull
{
	return new_token_(tokens_, type_, tokens_->position_.op_add(length_));
}

auto new_token_(t_Token_Stream *_Nonnull const tokens_, i32 const type_, u32 const end_) -> t_Syntax_Node const *_Nonnull
{
	t_Syntax_Node *_Nonnull const token_ = new_t_Syntax_Node(type_, tokens_->source_, tokens_->position_, end_.op_subtract(tokens_->position_));
	for (t_Diagnostic const *_Nonnull const diagnostic_ : *(tokens_->diagnostics_))
	{
		add_(token_, diagnostic_);
	}

	tokens_->diagnostics_->clear_();
	tokens_->position_ = end_;
	return token_;
}

auto is_identifier_char_(cp const c_) -> bit
{
	return bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(cp_greater_than_or_equal(c_, cp('a'))) && bit_arg(cp_less_than_or_equal(c_, cp('z'))))) || bit_arg(bit_op(bit_arg(cp_greater_than_or_equal(c_, cp('A'))) && bit_arg(cp_less_than_or_equal(c_, cp('Z'))))))) || bit_arg(equal_op(c_, cp('_'))));
}

auto is_number_char_(cp const c_) -> bit
{
	return bit_op(bit_arg(cp_greater_than_or_equal(c_, cp('0'))) && bit_arg(cp_less_than_or_equal(c_, cp('9'))));
}

auto t_Diagnostic::construct(i32 const level_, i32 const phase_, t_Source_Text const *_Nonnull const source_, t_Text_Span const *_Nonnull const span_, str const message_) -> t_Diagnostic *_Nonnull
{
	t_Diagnostic *_Nonnull self = this;
	self->level_ = level_;
	self->phase_ = phase_;
	self->source_ = source_;
	self->span_ = span_;
	self->position_ = position_of_start_(source_, span_);
	self->message_ = message_;
	return self;
}

inline t_Diagnostic *_Nonnull new_t_Diagnostic(i32 const level_, i32 const phase_, t_Source_Text const *_Nonnull const source_, t_Text_Span const *_Nonnull const span_, str const message_)
{
	return (new t_Diagnostic())->construct(level_, phase_, source_, span_, message_);
}

auto t_Emitter::construct(t_Package const *_Nonnull const package_, t_system__collections__List<t_Source_Text const *_Nonnull> const *_Nonnull const resources_) -> t_Emitter *_Nonnull
{
	t_Emitter *_Nonnull self = this;
	self->package_ = package_;
	self->resources_ = resources_;
	return self;
}

inline t_Emitter *_Nonnull new_t_Emitter(t_Package const *_Nonnull const package_, t_system__collections__List<t_Source_Text const *_Nonnull> const *_Nonnull const resources_)
{
	return (new t_Emitter())->construct(package_, resources_);
}

auto emit_(t_Emitter *_Nonnull const emitter_) -> str
{
	emitter_->type_declarations_ = new_t_Source_File_Builder();
	emitter_->function_declarations_ = new_t_Source_File_Builder();
	emitter_->class_declarations_ = new_t_Source_File_Builder();
	emitter_->global_definitions_ = new_t_Source_File_Builder();
	emitter_->definitions_ = new_t_Source_File_Builder();
	emitter_->main_function_return_type_ = str("");
	emitter_->main_function_accepts_console_ = bit_false;
	emitter_->main_function_accepts_args_ = bit_false;
	emit_preamble_(emitter_);
	for (t_Compilation_Unit const *_Nonnull const compilation_unit_ : *(emitter_->package_->compilation_units_))
	{
		emit_compilation_unit_(emitter_, compilation_unit_);
	}

	emit_entry_point_adapter_(emitter_);
	i32 const total_size_ = byte_length_(emitter_->type_declarations_)->op_add(byte_length_(emitter_->function_declarations_))->op_add(byte_length_(emitter_->class_declarations_))->op_add(byte_length_(emitter_->global_definitions_))->op_add(byte_length_(emitter_->definitions_));
	t_system__text__String_Builder *_Nonnull const cpp_code_ = new_t_system__text__String_Builder();
	cpp_code_->Append_(to_string_(emitter_->type_declarations_));
	cpp_code_->Append_(to_string_(emitter_->function_declarations_));
	cpp_code_->Append_(to_string_(emitter_->class_declarations_));
	cpp_code_->Append_(to_string_(emitter_->global_definitions_));
	cpp_code_->Append_(to_string_(emitter_->definitions_));
	return cpp_code_->ToString_();
}

auto mangle_name_(t_Name const *_Nonnull const name_) -> str
{
	t_system__text__String_Builder *_Nonnull const builder_ = new_t_system__text__String_Builder();
	if (cond(equal_op(name_->kind_, TypeName_)))
	{
		builder_->Append_(str("t_"));
	}
	else if (cond(equal_op(name_->kind_, FunctionName_)))
	{
		builder_->Append_(str("f_"));
	}
	else if (cond(equal_op(name_->kind_, VariableName_)))
	{
		builder_->Append_(str("v_"));
	}

	bit first_segment_ = bit_true;
	for (str const segment_ : *(name_->segments_))
	{
		if (cond(first_segment_))
		{
			first_segment_ = bit_false;
		}
		else
		{
			builder_->Append_(str("__"));
		}

		if (cond(bit_not(contains_multi_underscore_runs_(segment_))))
		{
			builder_->Append_(segment_);
		}
		else
		{
			i32 underscores_ = i32(0);
			i32 i_ = i32(0);
			while (cond(i32_less_than(i_, segment_.ByteLength_())))
			{
				if (cond(equal_op(segment_.op_Element(i_), cp('_'))))
				{
					underscores_.op_add_assign(i32(1));
				}
				else if (cond(i32_greater_than(underscores_, i32(0))))
				{
					if (cond(i32_greater_than_or_equal(underscores_, i32(2))))
					{
						builder_->Append_(str("_"));
					}

					underscores_ = i32(0);
				}

				builder_->Append_(new_str(segment_.op_Element(i_), i32(1)));
				i_.op_add_assign(i32(1));
			}
		}
	}

	return builder_->ToString_();
}

auto contains_multi_underscore_runs_(str const value_) -> bit
{
	i32 i_ = i32(0);
	bit last_char_underscore_ = bit_false;
	while (cond(i32_less_than(i_, value_.ByteLength_())))
	{
		if (cond(equal_op(value_.op_Element(i_), cp('_'))))
		{
			if (cond(last_char_underscore_))
			{
				return bit_true;
			}

			last_char_underscore_ = bit_true;
		}
		else
		{
			last_char_underscore_ = bit_false;
		}

		i_.op_add_assign(i32(1));
	}

	return bit_false;
}

auto convert_primitive_type_name_(t_Type const *_Nonnull const type_) -> str
{
	str const name_ = unqualified_name_(type_->name_);
	assert_(type_->is_primitive_, name_);
	if (cond(equal_op(name_, str("bool"))))
	{
		return str("bit");
	}
	else if (cond(equal_op(name_, str("int"))))
	{
		return str("i32");
	}
	else if (cond(equal_op(name_, str("uint"))))
	{
		return str("u32");
	}
	else if (cond(equal_op(name_, str("code_point"))))
	{
		return str("cp");
	}
	else if (cond(equal_op(name_, str("string"))))
	{
		return str("str");
	}
	else if (cond(equal_op(name_, str("void"))))
	{
		return str("void");
	}
	else
	{
		NOT_IMPLEMENTED_(unqualified_name_(type_->name_));
	}
}

auto convert_type_name_(t_Semantic_Node const *_Nonnull const type_node_) -> t_system__text__String_Builder *_Nonnull
{
	assert_(not_equal_op(type_node_->referenced_type_, none), get_text_(type_node_));
	return convert_type_name_(type_node_->referenced_type_);
}

auto convert_type_name_(t_Type const *_Nonnull const type_) -> t_system__text__String_Builder *_Nonnull
{
	t_system__text__String_Builder *_Nonnull const cpp_type_ = new_t_system__text__String_Builder();
	if (cond(type_->is_primitive_))
	{
		cpp_type_->Append_(convert_primitive_type_name_(type_));
	}
	else
	{
		cpp_type_->Append_(mangle_name_(type_->name_));
	}

	if (cond(type_->type_parameters_->op_magnitude()->op_greater_than(i32(0))))
	{
		cpp_type_->Append_(str("<"));
		bit first_ = bit_true;
		for (t_Type const *_Nonnull const type_parameter_ : *(type_->type_parameters_))
		{
			if (cond(first_))
			{
				first_ = bit_false;
			}
			else
			{
				cpp_type_->Append_(str(", "));
			}

			cpp_type_->Append_(convert_type_(bit_true, type_parameter_, bit_false));
		}

		cpp_type_->Append_(str(">"));
	}

	return cpp_type_;
}

auto convert_reference_type_(bit const mutable_binding_, t_Type const *_Nonnull type_, bit const nullable_) -> str
{
	t_system__text__String_Builder *_Nonnull const cpp_type_ = convert_type_name_(type_);
	if (cond(bit_not(type_->is_mutable_)))
	{
		cpp_type_->Append_(str(" const"));
	}

	cpp_type_->Append_(str(" *"));
	if (cond(nullable_))
	{
		cpp_type_->Append_(str("_Nullable"));
	}
	else
	{
		cpp_type_->Append_(str("_Nonnull"));
	}

	if (cond(bit_not(mutable_binding_)))
	{
		cpp_type_->Append_(str(" const"));
	}

	return cpp_type_->ToString_();
}

auto convert_type_(bit const mutable_binding_, t_Type const *_Nonnull type_, bit const optional_) -> str
{
	assert_(not_equal_op(type_, none), str(""));
	if (cond(bit_op(bit_arg(type_->is_primitive_) && bit_arg(equal_op(unqualified_name_(type_->name_), str("optional"))))))
	{
		t_Type const *_Nonnull const optional_type_ = type_->type_parameters_->op_Element(i32(0));
		if (cond(optional_type_->is_value_type_))
		{
			t_system__text__String_Builder *_Nonnull const cpp_type_ = new_t_system__text__String_Builder(str("p_optional<"));
			cpp_type_->Append_(convert_type_(bit_true, optional_type_, bit_true));
			cpp_type_->Append_(str(">"));
			if (cond(bit_op(bit_arg(bit_not(mutable_binding_)) && bit_arg(bit_not(type_->is_mutable_)))))
			{
				cpp_type_->Append_(str(" const"));
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
			t_system__text__String_Builder *_Nonnull const cpp_type_ = convert_type_name_(type_);
			if (cond(bit_op(bit_arg(bit_not(mutable_binding_)) && bit_arg(bit_not(type_->is_mutable_)))))
			{
				cpp_type_->Append_(str(" const"));
			}

			return cpp_type_->ToString_();
		}
		else
		{
			return convert_reference_type_(mutable_binding_, type_, optional_);
		}
	}
}

auto convert_type_(bit const mutable_binding_, t_Semantic_Node const *_Nonnull const type_node_) -> str
{
	assert_(not_equal_op(type_node_->referenced_type_, none), get_text_(type_node_));
	return convert_type_(mutable_binding_, type_node_->referenced_type_, bit_false);
}

auto convert_parameter_list_(t_Emitter *_Nonnull const emitter_, t_Semantic_Node const *_Nonnull const parameters_, bit const is_main_function_) -> str
{
	assert_(equal_op(parameters_->kind_, ParameterList_), str("parameters.kind=").op_add(parameters_->kind_));
	t_system__text__String_Builder *_Nonnull const builder_ = new_t_system__text__String_Builder();
	builder_->Append_(str("("));
	bit first_parameter_ = bit_true;
	for (t_Semantic_Node const *_Nonnull const parameter_ : *(children_of_kind_(parameters_, Parameter_)))
	{
		if (cond(bit_not(first_parameter_)))
		{
			builder_->Append_(str(", "));
		}
		else
		{
			first_parameter_ = bit_false;
		}

		bit const mutable_binding_ = node_has_child_(parameter_, VarKeyword_);
		t_Semantic_Node const *_Nonnull const type_node_ = parameter_->children_->op_Element(parameter_->children_->op_magnitude()->op_subtract(i32(1)));
		builder_->Append_(convert_type_(mutable_binding_, type_node_));
		builder_->Append_(str(" "));
		builder_->Append_(get_text_(first_child_(parameter_, Identifier_)));
		builder_->Append_(str("_"));
		if (cond(is_main_function_))
		{
			str type_string_;
			if (cond(equal_op(type_node_->kind_, MutableType_)))
			{
				type_string_ = get_text_(type_node_->children_->op_Element(i32(0)));
			}
			else
			{
				type_string_ = get_text_(type_node_);
			}

			if (cond(equal_op(type_string_, str("system.console.Console"))))
			{
				emitter_->main_function_accepts_console_ = bit_true;
			}

			if (cond(equal_op(type_string_, str("system.console.Arguments"))))
			{
				emitter_->main_function_accepts_args_ = bit_true;
			}
		}
	}

	builder_->Append_(str(")"));
	return builder_->ToString_();
}

auto convert_parameter_list_(t_Emitter *_Nonnull const emitter_, t_Semantic_Node const *_Nonnull const parameters_) -> str
{
	return convert_parameter_list_(emitter_, parameters_, bit_false);
}

auto convert_expression_(t_Semantic_Node const *_Nonnull const syntax_, t_Source_File_Builder *_Nonnull const builder_) -> void
{
	if (cond(equal_op(syntax_->kind_, NewExpression_)))
	{
		str constructor_name_ = str("");
		t_Semantic_Node const *_Nonnull type_node_ = syntax_->children_->op_Element(i32(0));
		if (cond(equal_op(type_node_->kind_, QualifiedName_)))
		{
			t_Semantic_Node const *_Nonnull const name_node_ = type_node_->children_->op_Element(i32(1));
			if (cond(bit_op(bit_arg(equal_op(name_node_->kind_, IdentifierName_)) && bit_arg(equal_op(name_node_->referenced_type_, none)))))
			{
				constructor_name_ = str("__").op_add(get_text_(name_node_));
				type_node_ = type_node_->children_->op_Element(i32(0));
			}
		}

		t_Type const *_Nonnull const type_ = type_node_->referenced_type_;
		assert_(not_equal_op(type_, none), get_text_(type_node_));
		write_(builder_, str("new_"));
		write_(builder_, convert_type_name_(type_)->ToString_());
		write_(builder_, constructor_name_);
		t_Semantic_Node const *_Nonnull const argumentList_ = syntax_->children_->op_Element(i32(1));
		convert_expression_(argumentList_, builder_);
	}
	else if (cond(equal_op(syntax_->kind_, ArgumentList_)))
	{
		write_(builder_, str("("));
		bit first_expression_ = bit_true;
		for (t_Semantic_Node const *_Nonnull const arg_ : *(syntax_->children_))
		{
			if (cond(bit_op(bit_arg(bit_op(bit_arg(not_equal_op(arg_->kind_, LeftParen_)) && bit_arg(not_equal_op(arg_->kind_, RightParen_)))) && bit_arg(not_equal_op(arg_->kind_, Comma_)))))
			{
				if (cond(first_expression_))
				{
					first_expression_ = bit_false;
				}
				else
				{
					write_(builder_, str(", "));
				}

				convert_expression_(arg_, builder_);
			}
		}

		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, NotExpression_)))
	{
		write_(builder_, str("bit_not("));
		convert_expression_(syntax_->children_->op_Element(i32(1)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, MagnitudeExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(1)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(1)), builder_);
		write_(builder_, str("op_magnitude()"));
	}
	else if (cond(equal_op(syntax_->kind_, ParenthesizedExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(1)), builder_);
	}
	else if (cond(equal_op(syntax_->kind_, NegateExpression_)))
	{
		write_(builder_, str("i32_negate("));
		convert_expression_(syntax_->children_->op_Element(i32(1)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, NoneLiteralExpression_)))
	{
		write_(builder_, str("none"));
	}
	else if (cond(equal_op(syntax_->kind_, SelfExpression_)))
	{
		write_(builder_, str("self"));
	}
	else if (cond(equal_op(syntax_->kind_, NumericLiteralExpression_)))
	{
		write_(builder_, str("i32(").op_add(get_text_(syntax_))->op_add(str(")")));
	}
	else if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, TrueLiteralExpression_)) || bit_arg(equal_op(syntax_->kind_, FalseLiteralExpression_)))))
	{
		write_(builder_, str("bit_").op_add(get_text_(syntax_)));
	}
	else if (cond(equal_op(syntax_->kind_, CodePointLiteralExpression_)))
	{
		write_(builder_, str("cp(").op_add(get_text_(syntax_))->op_add(str(")")));
	}
	else if (cond(equal_op(syntax_->kind_, IdentifierName_)))
	{
		write_(builder_, get_text_(syntax_)->op_add(str("_")));
	}
	else if (cond(equal_op(syntax_->kind_, StringLiteralExpression_)))
	{
		write_(builder_, str("str(").op_add(get_text_(syntax_))->op_add(str(")")));
	}
	else if (cond(equal_op(syntax_->kind_, AssignmentExpression_)))
	{
		i32 const operator_ = syntax_->children_->op_Element(i32(1))->kind_;
		if (cond(equal_op(operator_, Equals_)))
		{
			convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
			write_(builder_, str(" "));
			write_(builder_, get_text_(syntax_->children_->op_Element(i32(1))));
			write_(builder_, str(" "));
			convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		}
		else
		{
			convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
			convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
			write_(builder_, str("op_"));
			if (cond(equal_op(operator_, PlusEquals_)))
			{
				write_(builder_, str("add_assign"));
			}
			else if (cond(equal_op(operator_, MinusEquals_)))
			{
				write_(builder_, str("subtract_assign"));
			}
			else
			{
				error_(builder_, str("Unsupported assignment operator ").op_add(operator_));
			}

			write_(builder_, str("("));
			convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
			write_(builder_, str(")"));
		}
	}
	else if (cond(equal_op(syntax_->kind_, EqualExpression_)))
	{
		write_(builder_, str("equal_op("));
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str(", "));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, NotEqualExpression_)))
	{
		write_(builder_, str("not_equal_op("));
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str(", "));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, ComparisonExpression_)))
	{
		i32 const operator_ = syntax_->children_->op_Element(i32(1))->kind_;
		t_Type const *_Nonnull const type_ = syntax_->children_->op_Element(i32(0))->of_type_;
		if (cond(not_equal_op(type_, none)))
		{
			write_(builder_, convert_primitive_type_name_(type_));
			if (cond(equal_op(operator_, LessThan_)))
			{
				write_(builder_, str("_less_than"));
			}
			else if (cond(equal_op(operator_, LessThanEquals_)))
			{
				write_(builder_, str("_less_than_or_equal"));
			}
			else if (cond(equal_op(operator_, GreaterThan_)))
			{
				write_(builder_, str("_greater_than"));
			}
			else if (cond(equal_op(operator_, GreaterThanEquals_)))
			{
				write_(builder_, str("_greater_than_or_equal"));
			}
			else
			{
				error_(builder_, str("Unsupported comparison operator ").op_add(operator_));
			}

			write_(builder_, str("("));
			convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
			write_(builder_, str(", "));
			convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
			write_(builder_, str(")"));
		}
		else
		{
			convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
			convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
			write_(builder_, str("op_"));
			if (cond(equal_op(operator_, LessThan_)))
			{
				write_(builder_, str("less_than"));
			}
			else if (cond(equal_op(operator_, LessThanEquals_)))
			{
				write_(builder_, str("less_than_or_equal"));
			}
			else if (cond(equal_op(operator_, GreaterThan_)))
			{
				write_(builder_, str("greater_than"));
			}
			else if (cond(equal_op(operator_, GreaterThanEquals_)))
			{
				write_(builder_, str("greater_than_or_equal"));
			}
			else
			{
				error_(builder_, str("Unsupported comparison operator ").op_add(operator_));
			}

			write_(builder_, str("("));
			convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
			write_(builder_, str(")"));
		}
	}
	else if (cond(equal_op(syntax_->kind_, AddExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str("op_add("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, SubtractExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str("op_subtract("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, MultiplyExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str("op_multiply("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, DivideExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str("op_divide("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, RemainderExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str("op_remainder("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, OrExpression_)))
	{
		write_(builder_, str("bit_op(bit_arg("));
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str(") || bit_arg("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str("))"));
	}
	else if (cond(equal_op(syntax_->kind_, AndExpression_)))
	{
		write_(builder_, str("bit_op(bit_arg("));
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str(") && bit_arg("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str("))"));
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
		write_(builder_, str("op_Element("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str(")"));
	}
	else
	{
		error_(builder_, str("Could not convert expression of type ").op_add(syntax_->kind_));
	}
}

auto convert_member_access_(t_Semantic_Node const *_Nonnull const lhs_, t_Source_File_Builder *_Nonnull const builder_) -> void
{
	t_Type const *_Nullable const type_ = lhs_->of_type_;
	if (cond(bit_op(bit_arg(bit_op(bit_arg(not_equal_op(type_, none)) && bit_arg(type_->is_value_type_))) && bit_arg(bit_not(bit_op(bit_arg(bit_op(bit_arg(type_->is_primitive_) && bit_arg(equal_op(unqualified_name_(type_->name_), str("optional"))))) && bit_arg(bit_not(type_->type_parameters_->op_Element(i32(0))->is_value_type_))))))))
	{
		write_(builder_, str("."));
	}
	else
	{
		write_(builder_, str("->"));
	}
}

auto emit_statement_(t_Emitter *_Nonnull const emitter_, t_Semantic_Node const *_Nonnull const statement_) -> void
{
	statement_separator_line_(emitter_->definitions_);
	if (cond(equal_op(statement_->kind_, ReturnStatement_)))
	{
		if (cond(equal_op(statement_->children_->op_magnitude(), i32(2))))
		{
			write_line_(emitter_->definitions_, str("return;"));
		}
		else
		{
			begin_line_(emitter_->definitions_, str("return "));
			convert_expression_(statement_->children_->op_Element(i32(1)), emitter_->definitions_);
			end_line_(emitter_->definitions_, str(";"));
		}
	}
	else if (cond(equal_op(statement_->kind_, LoopStatement_)))
	{
		write_line_(emitter_->definitions_, str("for (;;)"));
		emit_statement_(emitter_, statement_->children_->op_Element(i32(1)));
	}
	else if (cond(equal_op(statement_->kind_, Block_)))
	{
		begin_block_(emitter_->definitions_);
		for (t_Semantic_Node const *_Nonnull const block_statement_ : *(node_statements_(statement_)))
		{
			emit_statement_(emitter_, block_statement_);
		}

		end_block_(emitter_->definitions_);
	}
	else if (cond(equal_op(statement_->kind_, WhileStatement_)))
	{
		begin_line_(emitter_->definitions_, str("while (cond("));
		convert_expression_(statement_->children_->op_Element(i32(1)), emitter_->definitions_);
		end_line_(emitter_->definitions_, str("))"));
		emit_statement_(emitter_, statement_->children_->op_Element(i32(2)));
	}
	else if (cond(equal_op(statement_->kind_, ForStatement_)))
	{
		begin_line_(emitter_->definitions_, str("for ("));
		t_Semantic_Node const *_Nonnull const variable_declaration_ = first_child_(statement_, VariableDeclaration_);
		bit const mutable_binding_ = node_has_child_(variable_declaration_, VarKeyword_);
		str const name_ = get_text_(first_child_(variable_declaration_, Identifier_));
		t_Semantic_Node const *_Nonnull const type_ = variable_declaration_->children_->op_Element(i32(2));
		write_(emitter_->definitions_, convert_type_(mutable_binding_, type_)->op_add(str(" "))->op_add(name_)->op_add(str("_")));
		write_(emitter_->definitions_, str(" : *("));
		convert_expression_(statement_->children_->op_Element(i32(3)), emitter_->definitions_);
		end_line_(emitter_->definitions_, str("))"));
		emit_statement_(emitter_, statement_->children_->op_Element(i32(4)));
	}
	else if (cond(equal_op(statement_->kind_, DoWhileStatement_)))
	{
		write_line_(emitter_->definitions_, str("do"));
		emit_statement_(emitter_, statement_->children_->op_Element(i32(1)));
		begin_line_(emitter_->definitions_, str("while (cond("));
		convert_expression_(statement_->children_->op_Element(i32(3)), emitter_->definitions_);
		end_line_(emitter_->definitions_, str("));"));
	}
	else if (cond(equal_op(statement_->kind_, IfStatement_)))
	{
		t_Semantic_Node const *_Nullable if_statement_ = statement_;
		begin_line_(emitter_->definitions_, str(""));
		for (;;)
		{
			write_(emitter_->definitions_, str("if (cond("));
			convert_expression_(if_statement_->children_->op_Element(i32(1)), emitter_->definitions_);
			end_line_(emitter_->definitions_, str("))"));
			emit_statement_(emitter_, if_statement_->children_->op_Element(i32(2)));
			t_Semantic_Node const *_Nullable const elseClause_ = first_child_(if_statement_, ElseClause_);
			if (cond(not_equal_op(elseClause_, none)))
			{
				if_statement_ = first_child_(elseClause_, IfStatement_);
				if (cond(not_equal_op(if_statement_, none)))
				{
					begin_line_(emitter_->definitions_, str("else "));
				}
				else
				{
					write_line_(emitter_->definitions_, str("else"));
					emit_statement_(emitter_, elseClause_->children_->op_Element(i32(1)));
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
		write_line_(emitter_->definitions_, str("break;"));
	}
	else if (cond(equal_op(statement_->kind_, ContinueStatement_)))
	{
		write_line_(emitter_->definitions_, str("continue;"));
	}
	else if (cond(equal_op(statement_->kind_, LocalDeclarationStatement_)))
	{
		t_Semantic_Node const *_Nonnull const variable_declaration_ = first_child_(statement_, VariableDeclaration_);
		str const variable_name_ = get_text_(first_child_(variable_declaration_, Identifier_));
		t_Semantic_Node const *_Nonnull const variable_type_ = variable_declaration_->children_->op_Element(i32(2));
		bit const mutable_binding_ = node_has_child_(variable_declaration_, VarKeyword_);
		begin_line_(emitter_->definitions_, convert_type_(mutable_binding_, variable_type_));
		write_(emitter_->definitions_, str(" ").op_add(variable_name_)->op_add(str("_")));
		if (cond(variable_declaration_->children_->op_magnitude()->op_greater_than(i32(3))))
		{
			write_(emitter_->definitions_, str(" = "));
			convert_expression_(variable_declaration_->children_->op_Element(i32(3)), emitter_->definitions_);
		}

		end_line_(emitter_->definitions_, str(";"));
	}
	else if (cond(equal_op(statement_->kind_, ExpressionStatement_)))
	{
		begin_line_(emitter_->definitions_, str(""));
		convert_expression_(statement_->children_->op_Element(i32(0)), emitter_->definitions_);
		end_line_(emitter_->definitions_, str(";"));
	}
	else
	{
		NOT_IMPLEMENTED_(str("statement.kind=").op_add(statement_->kind_));
	}
}

auto emit_method_body_(t_Emitter *_Nonnull const emitter_, t_Semantic_Node const *_Nonnull const block_, bit const is_associated_function_) -> void
{
	begin_block_(emitter_->definitions_);
	if (cond(bit_not(is_associated_function_)))
	{
		write_line_(emitter_->definitions_, str("auto self = this;"));
	}

	for (t_Semantic_Node const *_Nonnull const statement_ : *(node_statements_(block_)))
	{
		emit_statement_(emitter_, statement_);
	}

	end_block_(emitter_->definitions_);
}

auto emit_constructor_body_(t_Emitter *_Nonnull const emitter_, t_Semantic_Node const *_Nonnull const block_, str const self_type_, bit const is_value_type_) -> void
{
	begin_block_(emitter_->definitions_);
	if (cond(is_value_type_))
	{
		write_line_(emitter_->definitions_, self_type_.op_add(str(" self;")));
	}
	else
	{
		write_line_(emitter_->definitions_, self_type_.op_add(str(" self = this;")));
	}

	for (t_Semantic_Node const *_Nonnull const statement_ : *(node_statements_(block_)))
	{
		emit_statement_(emitter_, statement_);
	}

	write_line_(emitter_->definitions_, str("return self;"));
	end_block_(emitter_->definitions_);
}

auto emit_access_modifer_(t_Emitter *_Nonnull const emitter_, i32 const current_access_level_, i32 const access_modifer_) -> i32
{
	if (cond(not_equal_op(access_modifer_, current_access_level_)))
	{
		if (cond(bit_op(bit_arg(equal_op(access_modifer_, PublicKeyword_)) || bit_arg(equal_op(access_modifer_, InternalKeyword_)))))
		{
			end_line_(emitter_->class_declarations_, str("public:"));
			return PublicKeyword_;
		}
		else if (cond(equal_op(access_modifer_, ProtectedKeyword_)))
		{
			end_line_(emitter_->class_declarations_, str("public:"));
		}
		else if (cond(equal_op(access_modifer_, PrivateKeyword_)))
		{
			end_line_(emitter_->class_declarations_, str("private:"));
		}
		else
		{
			THROW_EXCEPTION_(str("Invalid access modifier in Emitter.emit_member_declaration(). kind is ").op_add(access_modifer_));
		}
	}

	return access_modifer_;
}

auto emit_member_declaration_(t_Emitter *_Nonnull const emitter_, t_Semantic_Node const *_Nonnull const member_, str const class_name_, bit const is_value_type_, i32 const current_access_level_) -> i32
{
	i32 access_modifer_ = node_access_modifier_(member_)->kind_;
	if (cond(equal_op(member_->kind_, ConstructorDeclaration_)))
	{
		access_modifer_ = PublicKeyword_;
	}

	access_modifer_ = emit_access_modifer_(emitter_, current_access_level_, access_modifer_);
	if (cond(equal_op(member_->kind_, ConstructorDeclaration_)))
	{
		str const parameters_ = convert_parameter_list_(emitter_, first_child_(member_, ParameterList_));
		str new_function_name_ = str("new_").op_add(class_name_);
		str constructor_full_name_ = str("construct");
		t_Semantic_Node const *_Nullable const constructor_name_node_ = first_child_(member_, Identifier_);
		if (cond(not_equal_op(constructor_name_node_, none)))
		{
			str const constructor_name_ = get_text_(constructor_name_node_);
			new_function_name_ = new_function_name_.op_add(str("__"))->op_add(constructor_name_);
			constructor_full_name_ = str("construct_").op_add(constructor_name_);
		}

		str return_type_ = class_name_;
		if (cond(bit_not(is_value_type_)))
		{
			return_type_ = return_type_.op_add(str(" *_Nonnull"));
		}

		begin_line_(emitter_->class_declarations_, str(""));
		if (cond(is_value_type_))
		{
			write_(emitter_->class_declarations_, str("static "));
		}

		end_line_(emitter_->class_declarations_, str("auto ").op_add(constructor_full_name_)->op_add(parameters_)->op_add(str(" -> "))->op_add(return_type_)->op_add(str(";")));
		element_separator_line_(emitter_->definitions_);
		write_line_(emitter_->definitions_, str("auto ").op_add(class_name_)->op_add(str("::"))->op_add(constructor_full_name_)->op_add(parameters_)->op_add(str(" -> "))->op_add(return_type_));
		emit_constructor_body_(emitter_, first_child_(member_, Block_), return_type_, is_value_type_);
		write_line_(emitter_->function_declarations_, str("inline ").op_add(return_type_)->op_add(str(" "))->op_add(new_function_name_)->op_add(parameters_)->op_add(str(";")));
		element_separator_line_(emitter_->definitions_);
		write_line_(emitter_->definitions_, str("inline ").op_add(return_type_)->op_add(str(" "))->op_add(new_function_name_)->op_add(parameters_));
		begin_block_(emitter_->definitions_);
		if (cond(bit_not(is_value_type_)))
		{
			begin_line_(emitter_->definitions_, str("return (new ").op_add(class_name_)->op_add(str("())->"))->op_add(constructor_full_name_)->op_add(str("(")));
		}
		else
		{
			begin_line_(emitter_->definitions_, str("return ").op_add(class_name_)->op_add(str("::"))->op_add(constructor_full_name_)->op_add(str("(")));
		}

		bit first_parameter_ = bit_true;
		for (t_Semantic_Node const *_Nonnull const parameter_ : *(first_child_(member_, ParameterList_)->children_))
		{
			if (cond(bit_not(first_parameter_)))
			{
				write_(emitter_->definitions_, str(", "));
			}
			else
			{
				first_parameter_ = bit_false;
			}

			write_(emitter_->definitions_, get_text_(first_child_(parameter_, Identifier_))->op_add(str("_")));
		}

		end_line_(emitter_->definitions_, str(");"));
		end_block_(emitter_->definitions_);
	}
	else if (cond(equal_op(member_->kind_, FieldDeclaration_)))
	{
		t_Semantic_Node const *_Nonnull const variable_declaration_ = first_child_(member_, VariableDeclaration_);
		str const field_name_ = get_text_(first_child_(variable_declaration_, Identifier_));
		t_Semantic_Node const *_Nonnull const field_type_ = variable_declaration_->children_->op_Element(i32(2));
		str const cpp_type_ = convert_type_(bit_true, field_type_);
		write_line_(emitter_->class_declarations_, cpp_type_.op_add(str(" "))->op_add(field_name_)->op_add(str("_;")));
	}
	else if (cond(equal_op(member_->kind_, MethodDeclaration_)))
	{
		str const method_name_ = get_text_(first_child_(member_, Identifier_));
		str const parameters_ = convert_parameter_list_(emitter_, first_child_(member_, ParameterList_));
		t_Semantic_Node const *_Nullable const self_parameter_ = first_child_(first_child_(member_, ParameterList_), SelfParameter_);
		bit const is_associated_function_ = equal_op(self_parameter_, none);
		bit const mutable_self_ = bit_op(bit_arg(bit_not(is_associated_function_)) && bit_arg(node_has_child_(self_parameter_, MutableKeyword_)));
		t_Semantic_Node const *_Nonnull const return_type_node_ = member_->children_->op_Element(i32(3));
		str const cpp_type_ = convert_type_(bit_true, return_type_node_);
		str static_modifier_ = str("");
		if (cond(is_associated_function_))
		{
			static_modifier_ = str("static ");
		}

		str constModifier_ = str("");
		if (cond(bit_op(bit_arg(bit_not(mutable_self_)) && bit_arg(bit_not(is_associated_function_)))))
		{
			constModifier_ = str("const ");
		}

		write_line_(emitter_->class_declarations_, static_modifier_.op_add(str("auto "))->op_add(method_name_)->op_add(str("_"))->op_add(parameters_)->op_add(str(" "))->op_add(constModifier_)->op_add(str("-> "))->op_add(cpp_type_)->op_add(str(";")));
		element_separator_line_(emitter_->definitions_);
		write_line_(emitter_->definitions_, str("auto ::").op_add(class_name_)->op_add(str("::"))->op_add(method_name_)->op_add(str("_"))->op_add(parameters_)->op_add(str(" "))->op_add(constModifier_)->op_add(str("-> "))->op_add(cpp_type_));
		t_Semantic_Node const *_Nonnull const block_ = first_child_(member_, Block_);
		emit_method_body_(emitter_, block_, is_associated_function_);
	}
	else
	{
		error_(emitter_->definitions_, str("Could not emit member of type ").op_add(member_->kind_));
	}

	return access_modifer_;
}

auto emit_default_constructor_(t_Emitter *_Nonnull const emitter_, str const type_name_, bit const is_value_type_, i32 const current_access_level_) -> void
{
	emit_access_modifer_(emitter_, current_access_level_, PublicKeyword_);
	str return_type_ = type_name_;
	if (cond(bit_not(is_value_type_)))
	{
		return_type_ = return_type_.op_add(str(" *_Nonnull"));
	}

	begin_line_(emitter_->class_declarations_, str(""));
	if (cond(is_value_type_))
	{
		write_(emitter_->class_declarations_, str("static "));
	}

	write_(emitter_->class_declarations_, str("auto construct() -> ").op_add(return_type_));
	if (cond(is_value_type_))
	{
		end_line_(emitter_->class_declarations_, str(" { return ").op_add(type_name_)->op_add(str("(); }")));
	}
	else
	{
		end_line_(emitter_->class_declarations_, str(" { return this; }"));
	}

	write_line_(emitter_->function_declarations_, str("inline ").op_add(return_type_)->op_add(str(" new_"))->op_add(type_name_)->op_add(str("();")));
	element_separator_line_(emitter_->definitions_);
	write_line_(emitter_->definitions_, str("inline ").op_add(return_type_)->op_add(str(" new_"))->op_add(type_name_)->op_add(str("()")));
	begin_block_(emitter_->definitions_);
	if (cond(bit_not(is_value_type_)))
	{
		write_line_(emitter_->definitions_, str("return (new ").op_add(type_name_)->op_add(str("())->construct();")));
	}
	else
	{
		write_line_(emitter_->definitions_, str("return ").op_add(type_name_)->op_add(str("::construct();")));
	}

	end_block_(emitter_->definitions_);
}

auto emit_declaration_(t_Emitter *_Nonnull const emitter_, t_Semantic_Node const *_Nonnull const declaration_) -> void
{
	if (cond(equal_op(declaration_->kind_, GlobalDeclaration_)))
	{
		t_Semantic_Node const *_Nonnull const variable_declaration_ = first_child_(declaration_, VariableDeclaration_);
		str const variable_name_ = get_text_(first_child_(variable_declaration_, Identifier_));
		t_Semantic_Node const *_Nonnull const variable_type_ = variable_declaration_->children_->op_Element(i32(2));
		bit const mutable_binding_ = node_has_child_(variable_declaration_, VarKeyword_);
		str const cpp_type_ = convert_type_(mutable_binding_, variable_type_);
		begin_line_(emitter_->global_definitions_, cpp_type_);
		write_(emitter_->global_definitions_, str(" ").op_add(variable_name_)->op_add(str("_ = ")));
		t_Semantic_Node const *_Nonnull const expression_ = variable_declaration_->children_->op_Element(i32(3));
		convert_expression_(expression_, emitter_->global_definitions_);
		end_line_(emitter_->global_definitions_, str(";"));
	}
	else if (cond(equal_op(declaration_->kind_, ClassDeclaration_)))
	{
		t_Type const *_Nonnull const declared_type_ = declaration_->declares_type_;
		assert_(not_equal_op(declared_type_, none), get_text_(first_child_(declaration_, Identifier_)));
		str const class_name_ = mangle_name_(declared_type_->name_);
		write_line_(emitter_->type_declarations_, str("class ").op_add(class_name_)->op_add(str(";")));
		element_separator_line_(emitter_->class_declarations_);
		write_line_(emitter_->class_declarations_, str("class ").op_add(class_name_));
		begin_block_(emitter_->class_declarations_);
		end_line_(emitter_->class_declarations_, str("public:"));
		i32 current_access_level_ = PublicKeyword_;
		bit has_constructors_ = bit_false;
		for (t_Semantic_Node const *_Nonnull const member_ : *(node_members_(declaration_)))
		{
			has_constructors_ = bit_op(bit_arg(has_constructors_) || bit_arg(equal_op(member_->kind_, ConstructorDeclaration_)));
			current_access_level_ = emit_member_declaration_(emitter_, member_, class_name_, bit_false, current_access_level_);
		}

		if (cond(bit_not(has_constructors_)))
		{
			emit_default_constructor_(emitter_, class_name_, bit_false, current_access_level_);
		}

		end_block_with_semicolon_(emitter_->class_declarations_);
	}
	else if (cond(equal_op(declaration_->kind_, StructDeclaration_)))
	{
		t_Type const *_Nonnull const declared_type_ = declaration_->declares_type_;
		assert_(not_equal_op(declared_type_, none), get_text_(first_child_(declaration_, Identifier_)));
		str const struct_name_ = mangle_name_(declared_type_->name_);
		write_line_(emitter_->type_declarations_, str("struct ").op_add(struct_name_)->op_add(str(";")));
		element_separator_line_(emitter_->class_declarations_);
		write_line_(emitter_->class_declarations_, str("struct ").op_add(struct_name_)->op_add(str(" final")));
		begin_block_(emitter_->class_declarations_);
		end_line_(emitter_->class_declarations_, str("public:"));
		write_line_(emitter_->class_declarations_, struct_name_.op_add(str(" * operator->() { return this; }")));
		write_line_(emitter_->class_declarations_, struct_name_.op_add(str(" const * operator->() const { return this; }")));
		write_line_(emitter_->class_declarations_, struct_name_.op_add(str(" & operator* () { return *this; }")));
		write_line_(emitter_->class_declarations_, struct_name_.op_add(str(" const & operator* () const { return *this; }")));
		i32 current_access_level_ = PublicKeyword_;
		bit has_constructors_ = bit_false;
		for (t_Semantic_Node const *_Nonnull const member_ : *(node_members_(declaration_)))
		{
			has_constructors_ = bit_op(bit_arg(has_constructors_) || bit_arg(equal_op(member_->kind_, ConstructorDeclaration_)));
			current_access_level_ = emit_member_declaration_(emitter_, member_, struct_name_, bit_true, current_access_level_);
		}

		if (cond(bit_not(has_constructors_)))
		{
			emit_default_constructor_(emitter_, struct_name_, bit_true, current_access_level_);
		}

		end_block_with_semicolon_(emitter_->class_declarations_);
	}
	else if (cond(equal_op(declaration_->kind_, EnumDeclaration_)))
	{
		str const enum_name_ = get_text_(first_child_(declaration_, Identifier_));
		write_line_(emitter_->type_declarations_, str("enum class ").op_add(enum_name_)->op_add(str("_;")));
		element_separator_line_(emitter_->class_declarations_);
		write_line_(emitter_->class_declarations_, str("enum class ").op_add(enum_name_)->op_add(str("_")));
		begin_block_(emitter_->class_declarations_);
		for (t_Semantic_Node const *_Nonnull const member_ : *(declaration_->children_))
		{
			if (cond(equal_op(member_->kind_, EnumMemberDeclaration_)))
			{
				str const member_name_ = get_text_(member_->children_->op_Element(i32(0)));
				begin_line_(emitter_->class_declarations_, member_name_.op_add(str("_")));
				t_Semantic_Node const *_Nullable const member_value_ = first_child_(member_, Number_);
				if (cond(not_equal_op(member_value_, none)))
				{
					write_(emitter_->class_declarations_, str(" = "));
					write_(emitter_->class_declarations_, get_text_(member_value_));
				}

				end_line_(emitter_->class_declarations_, str(","));
			}
		}

		end_block_with_semicolon_(emitter_->class_declarations_);
	}
	else if (cond(equal_op(declaration_->kind_, FunctionDeclaration_)))
	{
		str const name_ = get_text_(first_child_(declaration_, Identifier_));
		bit const is_main_ = equal_op(name_, str("main"));
		if (cond(is_main_))
		{
			emitter_->main_function_name_ = name_;
		}

		str const parameters_ = convert_parameter_list_(emitter_, first_child_(declaration_, ParameterList_), is_main_);
		t_Semantic_Node const *_Nonnull const return_type_node_ = declaration_->children_->op_Element(i32(3));
		str const cpp_type_ = convert_type_(bit_true, return_type_node_);
		write_line_(emitter_->function_declarations_, str("auto ").op_add(name_)->op_add(str("_"))->op_add(parameters_)->op_add(str(" -> "))->op_add(cpp_type_)->op_add(str(";")));
		element_separator_line_(emitter_->definitions_);
		write_line_(emitter_->definitions_, str("auto ").op_add(name_)->op_add(str("_"))->op_add(parameters_)->op_add(str(" -> "))->op_add(cpp_type_));
		if (cond(is_main_))
		{
			if (cond(not_equal_op(emitter_->main_function_return_type_, str(""))))
			{
				error_(emitter_->definitions_, str("Multiple declarations of main"));
			}

			emitter_->main_function_return_type_ = cpp_type_;
		}

		emit_statement_(emitter_, first_child_(declaration_, Block_));
	}
	else if (cond(equal_op(declaration_->kind_, EndOfFileToken_)))
	{
	}
	else
	{
		error_(emitter_->definitions_, str("Could not emit declaration of type ").op_add(declaration_->kind_));
	}
}

auto emit_compilation_unit_(t_Emitter *_Nonnull const emitter_, t_Compilation_Unit const *_Nonnull const unit_) -> void
{
	for (t_Semantic_Node const *_Nonnull const declaration_ : *(unit_->declarations_))
	{
		emit_declaration_(emitter_, declaration_);
	}
}

auto emit_preamble_(t_Emitter *_Nonnull const emitter_) -> void
{
	write_line_(emitter_->type_declarations_, str("#include \"RuntimeLibrary.hpp\""));
	blank_line_(emitter_->type_declarations_);
	write_line_(emitter_->type_declarations_, str("// Type Declarations"));
	blank_line_(emitter_->function_declarations_);
	write_line_(emitter_->function_declarations_, str("// Function Declarations"));
	blank_line_(emitter_->class_declarations_);
	write_line_(emitter_->class_declarations_, str("// Class Declarations"));
	blank_line_(emitter_->global_definitions_);
	write_line_(emitter_->global_definitions_, str("// Global Definitions"));
	blank_line_(emitter_->definitions_);
	write_line_(emitter_->definitions_, str("// Definitions"));
}

auto emit_entry_point_adapter_(t_Emitter *_Nonnull const emitter_) -> void
{
	element_separator_line_(emitter_->definitions_);
	write_line_(emitter_->definitions_, str("// Entry Point Adapter"));
	write_line_(emitter_->definitions_, str("std::int32_t main(int argc, char const *const * argv)"));
	begin_block_(emitter_->definitions_);
	write_line_(emitter_->definitions_, str("try"));
	begin_block_(emitter_->definitions_);
	for (t_Source_Text const *_Nonnull const resource_ : *(emitter_->resources_))
	{
		begin_line_(emitter_->definitions_, str("resource_manager_->AddResource(str(\""));
		write_(emitter_->definitions_, resource_->name_);
		write_(emitter_->definitions_, str("\"), str(\""));
		write_(emitter_->definitions_, resource_->text_.Replace_(str("\\"), str("\\\\"))->Replace_(str("\n"), str("\\n"))->Replace_(str("\r"), str("\\r"))->Replace_(str("\""), str("\\\"")));
		end_line_(emitter_->definitions_, str("\"));"));
	}

	if (cond(emitter_->resources_->op_magnitude()->op_greater_than(i32(0))))
	{
		end_line_(emitter_->definitions_, str(""));
	}

	t_system__text__String_Builder *_Nonnull const args_ = new_t_system__text__String_Builder();
	if (cond(emitter_->main_function_accepts_console_))
	{
		args_->Append_(str("new t_system__console__Console()"));
	}

	if (cond(emitter_->main_function_accepts_args_))
	{
		if (cond(emitter_->main_function_accepts_console_))
		{
			args_->Append_(str(", "));
		}

		args_->Append_(str("new t_system__console__Arguments(argc, argv)"));
	}

	if (cond(equal_op(emitter_->main_function_return_type_, str("void"))))
	{
		write_line_(emitter_->definitions_, emitter_->main_function_name_.op_add(str("_("))->op_add(args_->ToString_())->op_add(str(");")));
		write_line_(emitter_->definitions_, str("return 0;"));
	}
	else
	{
		write_line_(emitter_->definitions_, str("return ").op_add(emitter_->main_function_name_)->op_add(str("_("))->op_add(args_->ToString_())->op_add(str(").value;")));
	}

	end_block_(emitter_->definitions_);
	write_line_(emitter_->definitions_, str("catch(std::exception &ex)"));
	begin_block_(emitter_->definitions_);
	write_line_(emitter_->definitions_, str("std::printf(\"Program exited due to error:\\n\");"));
	write_line_(emitter_->definitions_, str("std::printf(\"%s\", ex.what());"));
	write_line_(emitter_->definitions_, str("return 70;"));
	end_block_(emitter_->definitions_);
	end_block_(emitter_->definitions_);
}

auto t_Name::construct_global_namespace() -> t_Name *_Nonnull
{
	t_Name *_Nonnull self = this;
	self->package_ = none;
	self->kind_ = NamespaceName_;
	self->segments_ = new_t_system__collections__List<str>();
	self->is_special_ = bit_false;
	return self;
}

inline t_Name *_Nonnull new_t_Name__global_namespace()
{
	return (new t_Name())->construct_global_namespace();
}

auto t_Name::construct_global_namespace(t_Package_Name const *_Nonnull const package_) -> t_Name *_Nonnull
{
	t_Name *_Nonnull self = this;
	assert_(not_equal_op(package_, none), str(""));
	self->package_ = package_;
	self->kind_ = NamespaceName_;
	self->segments_ = new_t_system__collections__List<str>();
	self->is_special_ = bit_false;
	return self;
}

inline t_Name *_Nonnull new_t_Name__global_namespace(t_Package_Name const *_Nonnull const package_)
{
	return (new t_Name())->construct_global_namespace(package_);
}

auto t_Name::construct(t_Name const *_Nonnull const qualifier_, i32 const kind_, str const name_) -> t_Name *_Nonnull
{
	t_Name *_Nonnull self = this;
	assert_(not_equal_op(qualifier_, none), str(""));
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	self->package_ = qualifier_->package_;
	self->kind_ = kind_;
	t_system__collections__List<str> *_Nonnull const segments_ = new_t_system__collections__List<str>();
	for (str const segment_ : *(qualifier_->segments_))
	{
		segments_->add_(segment_);
	}

	segments_->add_(name_);
	self->segments_ = segments_;
	self->is_special_ = bit_false;
	return self;
}

inline t_Name *_Nonnull new_t_Name(t_Name const *_Nonnull const qualifier_, i32 const kind_, str const name_)
{
	return (new t_Name())->construct(qualifier_, kind_, name_);
}

auto t_Name::construct(t_Name const *_Nonnull const qualifier_, i32 const kind_, str const name_, bit const is_special_) -> t_Name *_Nonnull
{
	t_Name *_Nonnull self = this;
	assert_(not_equal_op(qualifier_, none), str(""));
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	self->package_ = qualifier_->package_;
	self->kind_ = kind_;
	t_system__collections__List<str> *_Nonnull const segments_ = new_t_system__collections__List<str>();
	for (str const segment_ : *(qualifier_->segments_))
	{
		segments_->add_(segment_);
	}

	segments_->add_(name_);
	self->segments_ = segments_;
	self->is_special_ = is_special_;
	return self;
}

inline t_Name *_Nonnull new_t_Name(t_Name const *_Nonnull const qualifier_, i32 const kind_, str const name_, bit const is_special_)
{
	return (new t_Name())->construct(qualifier_, kind_, name_, is_special_);
}

auto t_Name::construct_special(t_Name const *_Nonnull const qualifier_, i32 const kind_, str const name_) -> t_Name *_Nonnull
{
	t_Name *_Nonnull self = this;
	assert_(not_equal_op(qualifier_, none), str(""));
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	self->package_ = qualifier_->package_;
	self->kind_ = kind_;
	t_system__collections__List<str> *_Nonnull const segments_ = new_t_system__collections__List<str>();
	for (str const segment_ : *(qualifier_->segments_))
	{
		segments_->add_(segment_);
	}

	segments_->add_(name_);
	self->segments_ = segments_;
	self->is_special_ = bit_true;
	return self;
}

inline t_Name *_Nonnull new_t_Name__special(t_Name const *_Nonnull const qualifier_, i32 const kind_, str const name_)
{
	return (new t_Name())->construct_special(qualifier_, kind_, name_);
}

auto t_Name::construct(t_Package_Name const *_Nullable const package_, i32 const kind_, t_system__collections__List<str> const *_Nonnull const segments_, bit const is_special_) -> t_Name *_Nonnull
{
	t_Name *_Nonnull self = this;
	self->package_ = package_;
	self->kind_ = kind_;
	self->segments_ = segments_;
	self->is_special_ = is_special_;
	return self;
}

inline t_Name *_Nonnull new_t_Name(t_Package_Name const *_Nullable const package_, i32 const kind_, t_system__collections__List<str> const *_Nonnull const segments_, bit const is_special_)
{
	return (new t_Name())->construct(package_, kind_, segments_, is_special_);
}

auto unqualified_name_(t_Name const *_Nonnull const name_) -> str
{
	if (cond(equal_op(name_->segments_->op_magnitude(), i32(0))))
	{
		return str("");
	}

	return name_->segments_->op_Element(name_->segments_->op_magnitude()->op_subtract(i32(1)));
}

auto full_name_(t_Name const *_Nonnull const name_) -> str
{
	str result_ = str("");
	if (cond(not_equal_op(name_->package_, none)))
	{
		result_ = full_name_(name_->package_);
	}

	result_ = result_.op_add(str("::"));
	bit first_ = bit_true;
	for (str const segment_ : *(name_->segments_))
	{
		if (cond(first_))
		{
			first_ = bit_false;
			result_ = result_.op_add(segment_);
			continue;
		}

		result_ = result_.op_add(str("."))->op_add(segment_);
	}

	return result_;
}

auto is_qualified_by_(t_Name const *_Nonnull const name_, t_Name const *_Nonnull const qualifier_) -> bit
{
	if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(not_equal_op(name_->package_, none)) && bit_arg(not_equal_op(qualifier_->package_, none)))) && bit_arg(not_equal_op(full_name_(name_->package_), full_name_(qualifier_->package_))))) || bit_arg(name_->segments_->op_magnitude()->op_less_than_or_equal(qualifier_->segments_->op_magnitude())))))
	{
		return bit_false;
	}

	i32 i_ = i32(0);
	for (str const segment_ : *(qualifier_->segments_))
	{
		if (cond(not_equal_op(segment_, name_->segments_->op_Element(i_))))
		{
			return bit_false;
		}

		i_.op_add_assign(i32(1));
	}

	return bit_true;
}

auto qualifier_is_(t_Name const *_Nonnull const name_, t_Name const *_Nonnull const qualifier_) -> bit
{
	return bit_op(bit_arg(equal_op(qualifier_->segments_->op_magnitude()->op_add(i32(1)), name_->segments_->op_magnitude())) && bit_arg(is_qualified_by_(name_, qualifier_)));
}

auto names_(t_Name const *_Nonnull const name_, t_Name const *_Nonnull const other_) -> bit
{
	if (cond(bit_op(bit_arg(bit_op(bit_arg(not_equal_op(name_->package_, none)) && bit_arg(bit_op(bit_arg(equal_op(other_->package_, none)) || bit_arg(not_equal_op(full_name_(name_->package_), full_name_(other_->package_))))))) || bit_arg(not_equal_op(name_->segments_->op_magnitude(), other_->segments_->op_magnitude())))))
	{
		return bit_false;
	}

	i32 i_ = i32(0);
	for (str const segment_ : *(other_->segments_))
	{
		if (cond(not_equal_op(segment_, name_->segments_->op_Element(i_))))
		{
			return bit_false;
		}

		i_.op_add_assign(i32(1));
	}

	return bit_true;
}

auto is_package_qualified_(t_Name const *_Nonnull const name_) -> bit
{
	return not_equal_op(name_->package_, none);
}

auto remove_package_(t_Name const *_Nonnull const name_) -> t_Name const *_Nonnull
{
	if (cond(equal_op(name_->package_, none)))
	{
		return name_;
	}
	else
	{
		return new_t_Name(none, name_->kind_, name_->segments_, name_->is_special_);
	}
}

auto unit_test_Name_() -> void
{
	name_with_unspecified_package_names_name_with_package_();
	name_with_unspecified_package_names_itself_();
}

auto name_with_unspecified_package_names_name_with_package_() -> void
{
	t_Name const *_Nonnull const name_without_package_ = new_t_Name(new_t_Name__global_namespace(), NamespaceName_, str("system"));
	t_Name const *_Nonnull const name_with_package_ = new_t_Name(new_t_Name__global_namespace(new_t_Package_Name(str("package"))), NamespaceName_, str("system"));
	assert_(names_(name_without_package_, name_with_package_), str(""));
}

auto name_with_unspecified_package_names_itself_() -> void
{
	t_Name const *_Nonnull const name_without_package_ = new_t_Name(new_t_Name__global_namespace(), NamespaceName_, str("system"));
	assert_(names_(name_without_package_, name_without_package_), str(""));
}

auto t_Package_Name::construct(str const name_) -> t_Package_Name *_Nonnull
{
	t_Package_Name *_Nonnull self = this;
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	self->unqualified_ = name_;
	return self;
}

inline t_Package_Name *_Nonnull new_t_Package_Name(str const name_)
{
	return (new t_Package_Name())->construct(name_);
}

auto full_name_(t_Package_Name const *_Nonnull const package_name_) -> str
{
	return package_name_->unqualified_;
}

auto t_Symbol::construct_identifier(str const name_) -> t_Symbol *_Nonnull
{
	t_Symbol *_Nonnull self = this;
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = bit_false;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	self->children_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	return self;
}

inline t_Symbol *_Nonnull new_t_Symbol__identifier(str const name_)
{
	return (new t_Symbol())->construct_identifier(name_);
}

auto t_Symbol::construct_identifier(str const name_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_) -> t_Symbol *_Nonnull
{
	t_Symbol *_Nonnull self = this;
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	assert_(not_equal_op(declarations_, none), str("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = bit_false;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = declarations_;
	self->children_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	return self;
}

inline t_Symbol *_Nonnull new_t_Symbol__identifier(str const name_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_)
{
	return (new t_Symbol())->construct_identifier(name_, declarations_);
}

auto t_Symbol::construct_identifier(str const name_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_) -> t_Symbol *_Nonnull
{
	t_Symbol *_Nonnull self = this;
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	assert_(not_equal_op(children_, none), str("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = bit_false;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	self->children_ = children_;
	return self;
}

inline t_Symbol *_Nonnull new_t_Symbol__identifier(str const name_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_)
{
	return (new t_Symbol())->construct_identifier(name_, children_);
}

auto t_Symbol::construct_constructor(str const name_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_) -> t_Symbol *_Nonnull
{
	t_Symbol *_Nonnull self = this;
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	assert_(not_equal_op(declarations_, none), str("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = bit_true;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = declarations_;
	self->children_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	return self;
}

inline t_Symbol *_Nonnull new_t_Symbol__constructor(str const name_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_)
{
	return (new t_Symbol())->construct_constructor(name_, declarations_);
}

auto t_Symbol::construct_package(str const name_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_) -> t_Symbol *_Nonnull
{
	t_Symbol *_Nonnull self = this;
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	assert_(not_equal_op(children_, none), str("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = PackageSymbol_;
	self->is_special_name_ = bit_false;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = new_t_system__collections__List<t_Semantic_Node const *_Nonnull>();
	self->children_ = children_;
	return self;
}

inline t_Symbol *_Nonnull new_t_Symbol__package(str const name_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_)
{
	return (new t_Symbol())->construct_package(name_, children_);
}

auto t_Symbol::construct_declaring(t_Type const *_Nonnull const declares_type_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_) -> t_Symbol *_Nonnull
{
	t_Symbol *_Nonnull self = this;
	assert_(not_equal_op(declares_type_, none), str(""));
	assert_(not_equal_op(declarations_, none), str("name=").op_add(unqualified_name_(declares_type_->name_)));
	assert_(not_equal_op(children_, none), str("name=").op_add(unqualified_name_(declares_type_->name_)));
	self->name_ = unqualified_name_(declares_type_->name_);
	self->is_special_name_ = declares_type_->name_->is_special_;
	self->of_type_ = none;
	self->declares_type_ = declares_type_;
	self->declarations_ = declarations_;
	self->children_ = children_;
	return self;
}

inline t_Symbol *_Nonnull new_t_Symbol__declaring(t_Type const *_Nonnull const declares_type_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_)
{
	return (new t_Symbol())->construct_declaring(declares_type_, declarations_, children_);
}

auto t_Symbol::construct_of_type(str const name_, t_Type const *_Nonnull const of_type_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_) -> t_Symbol *_Nonnull
{
	t_Symbol *_Nonnull self = this;
	assert_(not_equal_op(of_type_, none), str("name=").op_add(name_));
	assert_(not_equal_op(declarations_, none), str("name=").op_add(name_));
	assert_(not_equal_op(children_, none), str("name=").op_add(name_));
	self->name_ = name_;
	self->is_special_name_ = bit_false;
	self->of_type_ = of_type_;
	self->declares_type_ = none;
	self->declarations_ = declarations_;
	self->children_ = children_;
	return self;
}

inline t_Symbol *_Nonnull new_t_Symbol__of_type(str const name_, t_Type const *_Nonnull const of_type_, t_system__collections__List<t_Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, t_system__collections__List<t_Symbol const *_Nonnull> const *_Nonnull const children_)
{
	return (new t_Symbol())->construct_of_type(name_, of_type_, declarations_, children_);
}

auto get_child_(t_Symbol const *_Nonnull const symbol_, str const name_, i32 const kind_) -> t_Symbol const *_Nullable
{
	for (t_Symbol const *_Nonnull const child_ : *(symbol_->children_))
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
	t_system__collections__List<t_Symbol const *_Nonnull> *_Nonnull const children_ = new_t_system__collections__List<t_Symbol const *_Nonnull>();
	children_->add_(new_t_Symbol__identifier(str("child")));
	t_Symbol const *_Nonnull const package_with_children_ = new_t_Symbol__package(str("package"), children_);
	assert_(not_equal_op(get_child_(package_with_children_, str("child"), IdentifierSymbol_), none), str(""));
}

auto t_Type::construct(i32 const kind_, t_Name const *_Nonnull const name_, bit const is_mutable_) -> t_Type *_Nonnull
{
	t_Type *_Nonnull self = this;
	assert_(not_equal_op(name_, none), str(""));
	self->kind_ = kind_;
	self->name_ = name_;
	self->type_parameters_ = new_t_system__collections__List<t_Type const *_Nonnull>();
	self->is_primitive_ = bit_false;
	self->is_value_type_ = equal_op(kind_, ValueType_);
	self->is_potentially_mutable_ = is_mutable_;
	self->is_mutable_ = is_mutable_;
	return self;
}

inline t_Type *_Nonnull new_t_Type(i32 const kind_, t_Name const *_Nonnull const name_, bit const is_mutable_)
{
	return (new t_Type())->construct(kind_, name_, is_mutable_);
}

auto t_Type::construct_parameter(str const name_) -> t_Type *_Nonnull
{
	t_Type *_Nonnull self = this;
	self->kind_ = TypeParameterType_;
	self->name_ = new_t_Name(new_t_Name__global_namespace(), TypeParameterName_, name_);
	self->type_parameters_ = new_t_system__collections__List<t_Type const *_Nonnull>();
	self->is_primitive_ = bit_false;
	self->is_value_type_ = bit_false;
	self->is_potentially_mutable_ = bit_true;
	self->is_mutable_ = bit_false;
	return self;
}

inline t_Type *_Nonnull new_t_Type__parameter(str const name_)
{
	return (new t_Type())->construct_parameter(name_);
}

auto t_Type::construct(i32 const kind_, t_Name const *_Nonnull const name_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_mutable_) -> t_Type *_Nonnull
{
	t_Type *_Nonnull self = this;
	self->kind_ = kind_;
	self->name_ = name_;
	self->type_parameters_ = type_parameters_;
	self->is_primitive_ = bit_false;
	self->is_value_type_ = equal_op(kind_, ValueType_);
	self->is_potentially_mutable_ = is_mutable_;
	self->is_mutable_ = is_mutable_;
	return self;
}

inline t_Type *_Nonnull new_t_Type(i32 const kind_, t_Name const *_Nonnull const name_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_mutable_)
{
	return (new t_Type())->construct(kind_, name_, type_parameters_, is_mutable_);
}

auto t_Type::construct_primitive(t_Name const *_Nonnull const name_) -> t_Type *_Nonnull
{
	t_Type *_Nonnull self = this;
	self->kind_ = ValueType_;
	self->name_ = name_;
	self->type_parameters_ = new_t_system__collections__List<t_Type const *_Nonnull>();
	self->is_primitive_ = bit_true;
	self->is_value_type_ = bit_true;
	self->is_potentially_mutable_ = bit_false;
	self->is_mutable_ = bit_false;
	return self;
}

inline t_Type *_Nonnull new_t_Type__primitive(t_Name const *_Nonnull const name_)
{
	return (new t_Type())->construct_primitive(name_);
}

auto t_Type::construct_primitive(t_Name const *_Nonnull const name_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_) -> t_Type *_Nonnull
{
	t_Type *_Nonnull self = this;
	self->kind_ = ValueType_;
	self->name_ = name_;
	self->type_parameters_ = type_parameters_;
	self->is_primitive_ = bit_true;
	self->is_value_type_ = bit_true;
	self->is_potentially_mutable_ = bit_false;
	self->is_mutable_ = bit_false;
	return self;
}

inline t_Type *_Nonnull new_t_Type__primitive(t_Name const *_Nonnull const name_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_)
{
	return (new t_Type())->construct_primitive(name_, type_parameters_);
}

auto t_Type::construct_namespace(t_Name const *_Nonnull const name_) -> t_Type *_Nonnull
{
	t_Type *_Nonnull self = this;
	self->kind_ = NamespaceType_;
	self->name_ = name_;
	self->is_primitive_ = bit_false;
	self->type_parameters_ = new_t_system__collections__List<t_Type const *_Nonnull>();
	self->is_value_type_ = bit_true;
	self->is_potentially_mutable_ = bit_false;
	self->is_mutable_ = bit_false;
	return self;
}

inline t_Type *_Nonnull new_t_Type__namespace(t_Name const *_Nonnull const name_)
{
	return (new t_Type())->construct_namespace(name_);
}

auto t_Type::construct_generic(t_Type const *_Nonnull const definition_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_arguments_) -> t_Type *_Nonnull
{
	t_Type *_Nonnull self = this;
	assert_(not_equal_op(definition_, none), str(""));
	assert_(not_equal_op(type_arguments_, none), full_name_(definition_->name_));
	assert_(equal_op(definition_->type_parameters_->op_magnitude(), type_arguments_->op_magnitude()), full_name_(definition_->name_)->op_add(str(" "))->op_add(definition_->type_parameters_->op_magnitude())->op_add(str(" given "))->op_add(type_arguments_->op_magnitude()));
	self->kind_ = definition_->kind_;
	self->name_ = definition_->name_;
	self->type_parameters_ = type_arguments_;
	self->is_primitive_ = definition_->is_primitive_;
	self->is_value_type_ = definition_->is_value_type_;
	self->is_potentially_mutable_ = definition_->is_potentially_mutable_;
	self->is_mutable_ = definition_->is_mutable_;
	return self;
}

inline t_Type *_Nonnull new_t_Type__generic(t_Type const *_Nonnull const definition_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_arguments_)
{
	return (new t_Type())->construct_generic(definition_, type_arguments_);
}

auto t_Type::construct(i32 const kind_, t_Name const *_Nonnull const name_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_primitive_, bit const is_potentially_mutable_, bit const is_mutable_) -> t_Type *_Nonnull
{
	t_Type *_Nonnull self = this;
	self->kind_ = kind_;
	self->name_ = name_;
	self->type_parameters_ = type_parameters_;
	self->is_primitive_ = is_primitive_;
	self->is_value_type_ = equal_op(kind_, ValueType_);
	self->is_potentially_mutable_ = is_potentially_mutable_;
	self->is_mutable_ = is_mutable_;
	return self;
}

inline t_Type *_Nonnull new_t_Type(i32 const kind_, t_Name const *_Nonnull const name_, t_system__collections__List<t_Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_primitive_, bit const is_potentially_mutable_, bit const is_mutable_)
{
	return (new t_Type())->construct(kind_, name_, type_parameters_, is_primitive_, is_potentially_mutable_, is_mutable_);
}

auto make_mutable_type_(t_Type const *_Nonnull const type_) -> t_Type const *_Nonnull
{
	assert_(type_->is_potentially_mutable_, str("self.name=").op_add(full_name_(type_->name_)));
	return new_t_Type(type_->kind_, type_->name_, type_->type_parameters_, type_->is_primitive_, type_->is_potentially_mutable_, bit_true);
}

auto make_immutable_type_(t_Type const *_Nonnull const type_) -> t_Type const *_Nonnull
{
	return new_t_Type(type_->kind_, type_->name_, type_->type_parameters_, type_->is_primitive_, type_->is_potentially_mutable_, bit_false);
}

auto remove_type_package_(t_Type const *_Nonnull const type_) -> t_Type const *_Nonnull
{
	assert_(equal_op(type_->kind_, NamespaceType_), str("kind=").op_add(type_->kind_));
	if (cond(is_package_qualified_(type_->name_)))
	{
		return new_t_Type(type_->kind_, remove_package_(type_->name_), type_->type_parameters_, type_->is_primitive_, type_->is_potentially_mutable_, type_->is_mutable_);
	}
	else
	{
		return type_;
	}
}

auto t_Name_Subtable::construct_global_namespace(t_Name_Table const *_Nonnull const name_table_) -> t_Name_Subtable *_Nonnull
{
	t_Name_Subtable *_Nonnull self = this;
	self->name_table_ = name_table_;
	self->parent_ = none;
	self->name_ = new_t_Name__global_namespace();
	self->type_ = new_t_Type__namespace(self->name_);
	subtables_ = new_t_system__collections__List<t_Name_Subtable *_Nonnull>();
	return self;
}

inline t_Name_Subtable *_Nonnull new_t_Name_Subtable__global_namespace(t_Name_Table const *_Nonnull const name_table_)
{
	return (new t_Name_Subtable())->construct_global_namespace(name_table_);
}

auto t_Name_Subtable::construct_global_namespace(t_Name_Table const *_Nonnull const name_table_, t_Package_Name const *_Nonnull const package_name_) -> t_Name_Subtable *_Nonnull
{
	t_Name_Subtable *_Nonnull self = this;
	self->name_table_ = name_table_;
	self->parent_ = none;
	self->name_ = new_t_Name__global_namespace(package_name_);
	self->type_ = new_t_Type__namespace(self->name_);
	subtables_ = new_t_system__collections__List<t_Name_Subtable *_Nonnull>();
	return self;
}

inline t_Name_Subtable *_Nonnull new_t_Name_Subtable__global_namespace(t_Name_Table const *_Nonnull const name_table_, t_Package_Name const *_Nonnull const package_name_)
{
	return (new t_Name_Subtable())->construct_global_namespace(name_table_, package_name_);
}

auto t_Name_Subtable::construct(t_Name_Subtable const *_Nonnull const parent_, t_Name const *_Nonnull const name_, t_Type const *_Nonnull const type_) -> t_Name_Subtable *_Nonnull
{
	t_Name_Subtable *_Nonnull self = this;
	self->name_table_ = parent_->name_table_;
	self->parent_ = parent_;
	self->name_ = name_;
	self->type_ = type_;
	subtables_ = new_t_system__collections__List<t_Name_Subtable *_Nonnull>();
	return self;
}

inline t_Name_Subtable *_Nonnull new_t_Name_Subtable(t_Name_Subtable const *_Nonnull const parent_, t_Name const *_Nonnull const name_, t_Type const *_Nonnull const type_)
{
	return (new t_Name_Subtable())->construct(parent_, name_, type_);
}

auto add_subtable_(t_Name_Subtable *_Nonnull const scope_, t_Name const *_Nonnull const name_, t_Type const *_Nonnull const type_) -> void
{
	assert_(is_qualified_by_(name_, scope_->name_), str("\"").op_add(full_name_(name_))->op_add(str("\" is not a child of \""))->op_add(full_name_(scope_->name_))->op_add(str("\"")));
	if (cond(qualifier_is_(name_, scope_->name_)))
	{
		if (cond(bit_op(bit_arg(bit_op(bit_arg(equal_op(scope_->name_->package_, none)) && bit_arg(not_equal_op(type_, none)))) && bit_arg(equal_op(type_->kind_, NamespaceType_)))))
		{
			scope_->subtables_->add_(new_t_Name_Subtable(scope_, remove_package_(name_), remove_type_package_(type_)));
		}
		else
		{
			scope_->subtables_->add_(new_t_Name_Subtable(scope_, name_, type_));
		}

		return;
	}

	for (t_Name_Subtable *_Nonnull const subtable_ : *(scope_->subtables_))
	{
		if (cond(is_qualified_by_(name_, subtable_->name_)))
		{
			add_subtable_(subtable_, name_, type_);
			return;
		}
	}

	assert_(equal_op(name_->segments_->op_magnitude(), scope_->name_->segments_->op_magnitude()->op_add(i32(1))), str("Can't add \"").op_add(full_name_(name_))->op_add(str("\" to \""))->op_add(full_name_(scope_->name_))->op_add(str("\"")));
}

auto find_(t_Name_Subtable const *_Nonnull const scope_, str const name_) -> t_Name_Subtable *_Nullable
{
	return find_(scope_, name_, bit_false);
}

auto find_special_(t_Name_Subtable const *_Nonnull const scope_, str const name_) -> t_Name_Subtable *_Nullable
{
	return find_(scope_, name_, bit_true);
}

auto find_(t_Name_Subtable const *_Nonnull const scope_, str const name_, bit const is_special_) -> t_Name_Subtable *_Nullable
{
	for (t_Name_Subtable *_Nonnull const subtable_ : *(scope_->subtables_))
	{
		if (cond(bit_op(bit_arg(equal_op(unqualified_name_(subtable_->name_), name_)) && bit_arg(equal_op(subtable_->name_->is_special_, is_special_)))))
		{
			return subtable_;
		}
	}

	return none;
}

auto lookup_(t_Name_Subtable const *_Nonnull const scope_, str const name_) -> t_Name_Subtable *_Nullable
{
	return lookup_(scope_, name_, bit_false);
}

auto lookup_special_(t_Name_Subtable const *_Nonnull const scope_, str const name_) -> t_Name_Subtable *_Nullable
{
	return lookup_(scope_, name_, bit_true);
}

auto lookup_(t_Name_Subtable const *_Nonnull const scope_, str const name_, bit const is_special_) -> t_Name_Subtable *_Nullable
{
	t_Name_Subtable *_Nullable subtable_ = find_(scope_, name_, is_special_);
	if (cond(bit_op(bit_arg(equal_op(subtable_, none)) && bit_arg(not_equal_op(scope_->parent_, none)))))
	{
		subtable_ = lookup_(scope_->parent_, name_, is_special_);
	}

	return subtable_;
}

auto get_scope_(t_Name_Subtable const *_Nonnull const scope_, t_Name const *_Nonnull const name_) -> t_Name_Subtable const *_Nullable
{
	if (cond(names_(name_, scope_->name_)))
	{
		return scope_;
	}
	else if (cond(bit_not(is_qualified_by_(name_, scope_->name_))))
	{
		return none;
	}

	for (t_Name_Subtable const *_Nonnull const subtable_ : *(scope_->subtables_))
	{
		t_Name_Subtable const *_Nullable const value_ = get_scope_(subtable_, name_);
		if (cond(not_equal_op(value_, none)))
		{
			return value_;
		}
	}

	return none;
}

auto bind_type_(t_Name_Subtable *_Nonnull const scope_, t_Type const *_Nonnull const type_) -> void
{
	assert_(not_equal_op(type_, none), full_name_(scope_->name_));
	if (cond(not_equal_op(scope_->type_, none)))
	{
		assert_(equal_op(full_name_(scope_->type_->name_), full_name_(type_->name_)), full_name_(scope_->name_)->op_add(str(" currently `"))->op_add(full_name_(scope_->type_->name_))->op_add(str("` trying to set to `"))->op_add(full_name_(type_->name_))->op_add(str("`")));
	}

	scope_->type_ = type_;
}

auto as_mut_(t_Name_Subtable const *_Nonnull const scope_) -> t_Name_Subtable *_Nonnull
{
	return find_(scope_->parent_, unqualified_name_(scope_->name_), scope_->name_->is_special_);
}

auto unit_test_Name_Subtable_() -> void
{
	global_namespace_contains_added_name_();
	namespace_contains_added_name_();
}

auto global_namespace_contains_added_name_() -> void
{
	t_Name_Table const *_Nonnull const name_table_ = new_t_Name_Table();
	t_Name_Subtable *_Nonnull const global_namespace_ = new_t_Name_Subtable__global_namespace(name_table_);
	t_Name const *_Nonnull const test_name_ = new_t_Name(global_namespace_->name_, TypeName_, str("test"));
	add_subtable_(global_namespace_, test_name_, none);
	assert_(not_equal_op(find_(global_namespace_, str("test")), none), str(""));
	assert_(not_equal_op(get_scope_(global_namespace_, test_name_), none), str(""));
}

auto namespace_contains_added_name_() -> void
{
	t_Name_Table const *_Nonnull const name_table_ = new_t_Name_Table();
	t_Name_Subtable *_Nonnull const global_namespace_ = new_t_Name_Subtable__global_namespace(name_table_);
	t_Name const *_Nonnull const namespace_name_ = new_t_Name(global_namespace_->name_, NamespaceName_, str("namespace"));
	add_subtable_(global_namespace_, namespace_name_, none);
	add_subtable_(global_namespace_, new_t_Name(namespace_name_, TypeName_, str("test")), none);
	t_Name_Subtable const *_Nonnull const namespace_ = find_(global_namespace_, str("namespace"));
	assert_(not_equal_op(find_(namespace_, str("test")), none), str(""));
}

auto t_Name_Table::construct() -> t_Name_Table *_Nonnull
{
	t_Name_Table *_Nonnull self = this;
	self->any_package_ = new_t_Name_Subtable__global_namespace(self);
	self->packages_ = new_t_system__collections__List<t_Name_Subtable *_Nonnull>();
	return self;
}

inline t_Name_Table *_Nonnull new_t_Name_Table()
{
	return (new t_Name_Table())->construct();
}

auto add_package_(t_Name_Table *_Nonnull const name_table_, t_Package_Name const *_Nonnull const package_name_) -> t_Name const *_Nonnull
{
	t_Name_Subtable *_Nonnull const subtable_ = new_t_Name_Subtable__global_namespace(name_table_, package_name_);
	name_table_->packages_->add_(subtable_);
	return subtable_->name_;
}

auto add_name_(t_Name_Table *_Nonnull const name_table_, t_Name const *_Nonnull const parent_, t_Symbol const *_Nonnull const symbol_) -> t_Name const *_Nonnull
{
	t_Name const *_Nonnull name_;
	if (cond(not_equal_op(symbol_->declares_type_, none)))
	{
		name_ = new_t_Name(parent_, TypeName_, symbol_->name_, symbol_->is_special_name_);
		add_name_(name_table_, name_, symbol_->declares_type_);
	}
	else
	{
		name_ = new_t_Name(parent_, FunctionName_, symbol_->name_, symbol_->is_special_name_);
		add_name_(name_table_, name_, symbol_->of_type_);
	}

	return name_;
}

auto add_name_(t_Name_Table *_Nonnull const name_table_, t_Name const *_Nonnull const name_, t_Type const *_Nonnull const type_) -> void
{
	add_subtable_(name_table_->any_package_, name_, type_);
	for (t_Name_Subtable *_Nonnull const package_ : *(name_table_->packages_))
	{
		if (cond(is_qualified_by_(name_, package_->name_)))
		{
			add_subtable_(package_, name_, type_);
			return;
		}
	}

	THROW_EXCEPTION_(str("Can't add name \"").op_add(full_name_(name_))->op_add(str("\" because package doesn't exist in table.")));
}

auto get_name_(t_Name_Table const *_Nonnull const name_table_, t_Name const *_Nonnull const name_) -> t_Name_Subtable const *_Nullable
{
	if (cond(equal_op(name_->package_, none)))
	{
		return get_scope_(name_table_->any_package_, name_);
	}

	for (t_Name_Subtable const *_Nonnull const package_ : *(name_table_->packages_))
	{
		if (cond(is_qualified_by_(name_, package_->name_)))
		{
			return get_scope_(package_, name_);
		}
	}

	return none;
}

auto build_name_table_(t_Package_Name const *_Nonnull const package_name_, t_Syntax_Node const *_Nonnull const package_syntax_, t_system__collections__List<t_Package_Reference> const *_Nonnull const references_) -> t_Name_Table const *_Nonnull
{
	assert_(equal_op(package_syntax_->kind_, PackageNode_), str("package_syntax.kind=").op_add(package_syntax_->kind_));
	t_Name_Table *_Nonnull const name_table_ = new_t_Name_Table();
	add_referenced_(name_table_, references_);
	add_package_(name_table_, package_name_, package_syntax_);
	return name_table_;
}

auto add_referenced_(t_Name_Table *_Nonnull const name_table_, t_system__collections__List<t_Package_Reference> const *_Nonnull const references_) -> void
{
	for (t_Package_Reference const reference_ : *(references_))
	{
		t_Package_Name const *_Nonnull const reference_name_ = new_t_Package_Name(reference_.name_);
		t_Name const *_Nonnull const global_namespace_ = add_package_(name_table_, reference_name_);
		for (t_Symbol const *_Nonnull const symbol_ : *(reference_.package_->symbol_->children_))
		{
			add_symbol_(name_table_, global_namespace_, symbol_);
		}
	}
}

auto add_symbol_(t_Name_Table *_Nonnull const name_table_, t_Name const *_Nonnull const parent_, t_Symbol const *_Nonnull const symbol_) -> void
{
	t_Name const *_Nonnull const name_ = add_name_(name_table_, parent_, symbol_);
	for (t_Symbol const *_Nonnull const child_ : *(symbol_->children_))
	{
		add_symbol_(name_table_, name_, child_);
	}
}

auto add_package_(t_Name_Table *_Nonnull const name_table_, t_Package_Name const *_Nonnull const package_name_, t_Syntax_Node const *_Nonnull const package_syntax_) -> void
{
	assert_(equal_op(package_syntax_->kind_, PackageNode_), str("package_syntax.kind=").op_add(package_syntax_->kind_));
	t_Name const *_Nonnull const global_namespace_ = add_package_(name_table_, package_name_);
	for (t_Syntax_Node const *_Nonnull const compilation_unit_ : *(package_syntax_->children_))
	{
		add_compilation_unit_(name_table_, global_namespace_, compilation_unit_);
	}
}

auto add_compilation_unit_(t_Name_Table *_Nonnull const name_table_, t_Name const *_Nonnull const global_namespace_, t_Syntax_Node const *_Nonnull const compilation_unit_) -> void
{
	assert_(equal_op(compilation_unit_->kind_, CompilationUnit_), str("compilation_unit.kind=").op_add(compilation_unit_->kind_));
	for (t_Syntax_Node const *_Nonnull const declaration_ : *(compilation_unit_->children_))
	{
		add_syntax_(name_table_, global_namespace_, declaration_);
	}
}

auto add_syntax_(t_Name_Table *_Nonnull const name_table_, t_Name const *_Nonnull const parent_, t_Syntax_Node const *_Nonnull const syntax_) -> void
{
	if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, FunctionDeclaration_)) || bit_arg(equal_op(syntax_->kind_, MethodDeclaration_)))))
	{
		t_Name const *_Nonnull const name_ = new_t_Name(parent_, FunctionName_, get_text_(first_child_syntax_(syntax_, Identifier_)));
		add_function_(name_table_, name_, syntax_);
	}
	else if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, ClassDeclaration_)) || bit_arg(equal_op(syntax_->kind_, StructDeclaration_)))))
	{
		str const unqualified_name_ = get_text_(first_child_syntax_(syntax_, Identifier_));
		i32 type_kind_;
		if (cond(equal_op(syntax_->kind_, ClassDeclaration_)))
		{
			type_kind_ = ReferenceType_;
		}
		else
		{
			type_kind_ = ValueType_;
		}

		t_Name const *_Nonnull const name_ = new_t_Name(parent_, TypeName_, unqualified_name_);
		t_Type const *_Nonnull const type_ = new_t_Type(type_kind_, name_, bit_true);
		add_name_(name_table_, name_, type_);
		for (t_Syntax_Node const *_Nonnull const member_ : *(members_(syntax_)))
		{
			add_syntax_(name_table_, name_, member_);
		}
	}
	else if (cond(equal_op(syntax_->kind_, ConstructorDeclaration_)))
	{
		str full_name_ = str("new");
		t_Syntax_Node const *_Nullable const constructor_name_ = first_child_syntax_(syntax_, Identifier_);
		if (cond(not_equal_op(constructor_name_, none)))
		{
			full_name_ = str("new_").op_add(get_text_(constructor_name_));
		}

		t_Name const *_Nonnull const name_ = new_t_Name__special(parent_, FunctionName_, full_name_);
		add_function_(name_table_, name_, syntax_);
		t_Name const *_Nonnull const self_name_ = new_t_Name__special(name_, VariableName_, str("self"));
		t_Type const *_Nonnull const self_type_ = none;
		add_name_(name_table_, self_name_, self_type_);
	}
	else if (cond(equal_op(syntax_->kind_, FieldDeclaration_)))
	{
		str const unqualified_name_ = get_text_(first_child_syntax_(first_child_syntax_(syntax_, VariableDeclaration_), Identifier_));
		t_Name const *_Nonnull const name_ = new_t_Name(parent_, TypeName_, unqualified_name_);
		t_Type const *_Nullable const no_type_ = none;
		add_name_(name_table_, name_, no_type_);
	}
	else if (cond(equal_op(syntax_->kind_, EnumDeclaration_)))
	{
		str const unqualified_name_ = get_text_(first_child_syntax_(syntax_, Identifier_));
		t_Name const *_Nonnull const name_ = new_t_Name(parent_, TypeName_, unqualified_name_);
		t_Type const *_Nonnull const type_ = new_t_Type(ReferenceType_, name_, bit_true);
		add_name_(name_table_, name_, type_);
	}
	else if (cond(equal_op(syntax_->kind_, GlobalDeclaration_)))
	{
		str const unqualified_name_ = get_text_(first_child_syntax_(first_child_syntax_(syntax_, VariableDeclaration_), Identifier_));
		t_Name const *_Nonnull const name_ = new_t_Name(parent_, TypeName_, unqualified_name_);
		t_Type const *_Nullable const no_type_ = none;
		add_name_(name_table_, name_, no_type_);
	}
	else if (cond(equal_op(syntax_->kind_, Block_)))
	{
		for (t_Syntax_Node const *_Nonnull const statement_ : *(statements_(syntax_)))
		{
			add_syntax_(name_table_, parent_, statement_);
		}
	}
	else if (cond(bit_op(bit_arg(bit_op(bit_arg(equal_op(syntax_->kind_, LoopStatement_)) || bit_arg(equal_op(syntax_->kind_, WhileStatement_)))) || bit_arg(equal_op(syntax_->kind_, DoWhileStatement_)))))
	{
		add_syntax_(name_table_, parent_, first_child_syntax_(syntax_, Block_));
	}
	else if (cond(equal_op(syntax_->kind_, ForStatement_)))
	{
		t_Syntax_Node const *_Nonnull const identifier_ = first_child_syntax_(first_child_syntax_(syntax_, VariableDeclaration_), Identifier_);
		t_Name const *_Nonnull const name_ = new_t_Name(parent_, VariableName_, get_text_(identifier_));
		t_Type const *_Nullable const no_type_ = none;
		add_name_(name_table_, name_, no_type_);
		add_syntax_(name_table_, parent_, first_child_syntax_(syntax_, Block_));
	}
	else if (cond(equal_op(syntax_->kind_, IfStatement_)))
	{
		add_syntax_(name_table_, parent_, first_child_syntax_(syntax_, Block_));
		t_Syntax_Node const *_Nullable const else_clause_ = first_child_syntax_(syntax_, ElseClause_);
		if (cond(not_equal_op(else_clause_, none)))
		{
			add_syntax_(name_table_, parent_, else_clause_);
		}
	}
	else if (cond(equal_op(syntax_->kind_, ElseClause_)))
	{
		t_Syntax_Node const *_Nullable const block_ = first_child_syntax_(syntax_, Block_);
		if (cond(not_equal_op(block_, none)))
		{
			add_syntax_(name_table_, parent_, block_);
		}
		else
		{
			add_syntax_(name_table_, parent_, first_child_syntax_(syntax_, IfStatement_));
		}
	}
	else if (cond(equal_op(syntax_->kind_, LocalDeclarationStatement_)))
	{
		t_Syntax_Node const *_Nonnull const identifier_ = first_child_syntax_(first_child_syntax_(syntax_, VariableDeclaration_), Identifier_);
		t_Name const *_Nonnull const name_ = new_t_Name(parent_, VariableName_, get_text_(identifier_));
		t_Type const *_Nullable const no_type_ = none;
		add_name_(name_table_, name_, no_type_);
	}
	else if (cond(equal_op(syntax_->kind_, Parameter_)))
	{
		t_Syntax_Node const *_Nonnull const identifier_ = first_child_syntax_(syntax_, Identifier_);
		t_Name const *_Nonnull const name_ = new_t_Name(parent_, VariableName_, get_text_(identifier_));
		t_Type const *_Nullable const no_type_ = none;
		add_name_(name_table_, name_, no_type_);
	}
	else if (cond(equal_op(syntax_->kind_, SelfParameter_)))
	{
		t_Name const *_Nonnull const name_ = new_t_Name__special(parent_, VariableName_, str("self"));
		t_Type const *_Nullable const no_type_ = none;
		add_name_(name_table_, name_, no_type_);
	}
	else if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(syntax_->kind_, ExpressionStatement_)) || bit_arg(equal_op(syntax_->kind_, ReturnStatement_)))) || bit_arg(equal_op(syntax_->kind_, BreakStatement_)))) || bit_arg(equal_op(syntax_->kind_, ContinueStatement_)))) || bit_arg(equal_op(syntax_->kind_, EndOfFileToken_)))))
	{
	}
	else
	{
		NOT_IMPLEMENTED_(str("syntax.kind=").op_add(syntax_->kind_));
	}
}

auto add_function_(t_Name_Table *_Nonnull const name_table_, t_Name const *_Nonnull const name_, t_Syntax_Node const *_Nonnull const function_) -> void
{
	t_Type const *_Nullable const no_type_ = none;
	add_name_(name_table_, name_, no_type_);
	t_Syntax_Node const *_Nonnull const parameters_syntax_ = first_child_syntax_(function_, ParameterList_);
	for (t_Syntax_Node const *_Nonnull const parameter_ : *(parameters_(parameters_syntax_)))
	{
		add_syntax_(name_table_, name_, parameter_);
	}

	t_Syntax_Node const *_Nonnull const body_ = first_child_syntax_(function_, Block_);
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
	t_Package_Name const *_Nonnull const name_ = new_t_Package_Name(str("default"));
	t_Package const *_Nonnull const runtime_package_ = build_runtime_library_package_();
	t_system__collections__List<t_Package_Reference> *_Nonnull const references_ = new_t_system__collections__List<t_Package_Reference>();
	references_->add_(new_t_Package_Reference(runtime_package_));
	t_Syntax_Node const *_Nonnull const package_syntax_ = new_t_Syntax_Node(PackageNode_, none, i32(0), i32(0));
	t_Name_Table const *_Nonnull const name_table_ = build_name_table_(name_, package_syntax_, references_);
	t_Name_Subtable const *_Nonnull const namespace_ = find_(name_table_->any_package_, str("system"));
	assert_(not_equal_op(find_(namespace_, str("console")), none), str(""));
	t_Name const *_Nonnull const system_namespace_name_ = new_t_Name(new_t_Name__global_namespace(), NamespaceName_, str("system"));
	assert_(not_equal_op(get_name_(name_table_, system_namespace_name_), none), str(""));
	t_Name const *_Nonnull const console_namespace_name_ = new_t_Name(system_namespace_name_, NamespaceName_, str("console"));
	assert_(not_equal_op(get_name_(name_table_, console_namespace_name_), none), str(""));
	t_Name const *_Nonnull const console_class_name_ = new_t_Name(console_namespace_name_, TypeName_, str("Console"));
	assert_(not_equal_op(get_name_(name_table_, console_class_name_), none), str(""));
}

auto can_get_root_namespace_from_name_() -> void
{
	t_Package_Name const *_Nonnull const name_ = new_t_Package_Name(str("default"));
	t_Package const *_Nonnull const runtime_package_ = build_runtime_library_package_();
	t_system__collections__List<t_Package_Reference> *_Nonnull const references_ = new_t_system__collections__List<t_Package_Reference>();
	references_->add_(new_t_Package_Reference(runtime_package_));
	t_Syntax_Node const *_Nonnull const package_syntax_ = new_t_Syntax_Node(PackageNode_, none, i32(0), i32(0));
	t_Name_Table const *_Nonnull const name_table_ = build_name_table_(name_, package_syntax_, references_);
	t_Name const *_Nonnull const namespace_name_ = new_t_Name(new_t_Name__global_namespace(), NamespaceName_, str("system"));
	assert_(not_equal_op(get_name_(name_table_, namespace_name_), none), str(""));
}

auto can_get_Console_class_from_name_without_package_() -> void
{
	t_Package_Name const *_Nonnull const name_ = new_t_Package_Name(str("default"));
	t_Package const *_Nonnull const runtime_package_ = build_runtime_library_package_();
	t_system__collections__List<t_Package_Reference> *_Nonnull const references_ = new_t_system__collections__List<t_Package_Reference>();
	references_->add_(new_t_Package_Reference(runtime_package_));
	t_Syntax_Node const *_Nonnull const package_syntax_ = new_t_Syntax_Node(PackageNode_, none, i32(0), i32(0));
	t_Name_Table const *_Nonnull const name_table_ = build_name_table_(name_, package_syntax_, references_);
	t_Name const *_Nonnull const system_namespace_name_ = new_t_Name(new_t_Name__global_namespace(), NamespaceName_, str("system"));
	t_Name const *_Nonnull const console_namespace_name_ = new_t_Name(system_namespace_name_, NamespaceName_, str("console"));
	t_Name const *_Nonnull const console_class_name_ = new_t_Name(console_namespace_name_, TypeName_, str("Console"));
	assert_(not_equal_op(get_name_(name_table_, console_class_name_), none), str(""));
}

auto can_get_Optional_class_from_name_with_package_() -> void
{
	t_Package_Name const *_Nonnull const name_ = new_t_Package_Name(str("default"));
	t_Package const *_Nonnull const primitives_package_ = build_primitives_package_();
	t_system__collections__List<t_Package_Reference> *_Nonnull const references_ = new_t_system__collections__List<t_Package_Reference>();
	references_->add_(new_t_Package_Reference(primitives_package_));
	t_Syntax_Node const *_Nonnull const package_syntax_ = new_t_Syntax_Node(PackageNode_, none, i32(0), i32(0));
	t_Name_Table const *_Nonnull const name_table_ = build_name_table_(name_, package_syntax_, references_);
	t_Package_Name const *_Nonnull const package_name_ = new_t_Package_Name(str("$primitives"));
	t_Name const *_Nonnull const adamant_namespace_name_ = new_t_Name(new_t_Name__global_namespace(), NamespaceName_, str("adamant"));
	t_Name const *_Nonnull const language_namespace_name_ = new_t_Name(adamant_namespace_name_, NamespaceName_, str("language"));
	assert_(not_equal_op(get_name_(name_table_, language_namespace_name_), none), str(""));
	t_Name const *_Nonnull const optional_class_name_ = new_t_Name(language_namespace_name_, TypeName_, str("optional"));
	assert_(not_equal_op(get_name_(name_table_, optional_class_name_), none), str(""));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		resource_manager_->AddResource(str("RuntimeLibrary.cpp"), str("#include \"RuntimeLibrary.hpp\"\n#include <map>\n\n// -----------------------------------------------------------------------------\n// Primitive Types\n// -----------------------------------------------------------------------------\n\nu32 i32::as_uint_() const\n{\n    if(this->value < 0)\n        throw std::range_error(\"Can't convert negative number to unsigned\");\n\n    return u32(this->value);\n}\n\nchar cp_to_char(cp v)\n{\n    if(v.value > 0xFF)\n        throw std::range_error(\"Unicode char values not yet supported\");\n\n    return v.value;\n}\n\nstr str::construct(cp c, i32 repeat)\n{\n    str self;\n    self.Length = repeat.value;\n    char* buffer = new char[repeat.value];\n    for (int i = 0; i < repeat.value; i++)\n        buffer[i] = cp_to_char(c);\n\n    self.Buffer = buffer;\n    return self;\n}\n\nstr::str(const char* s)\n    : Length(std::strlen(s)), Buffer(s)\n{\n}\n\nstr::str(int length, const char* s)\n    : Length(length), Buffer(s)\n{\n}\n\nchar const * str::cstr() const\n{\n    auto buffer = new char[Length + 1];\n    std::memcpy(buffer, Buffer, Length);\n    buffer[Length] = 0;\n    return buffer;\n}\n\nstr::str(i32 other)\n    : Length(0), Buffer(0)\n{\n    char* buffer = new char[12]; // -2,147,483,648 to 2,147,483,647 plus null terminator\n    int length = std::sprintf(buffer,\"%d\", other.value);\n    if(length <= 0) throw std::runtime_error(\"Could not convert int to string\");\n    Length = length;\n    Buffer = buffer;\n}\n\nstr::str(cp other)\n    : Length(1), Buffer(new char[1] { cp_to_char(other) })\n{\n}\n\nstr::str(bit other)\n    : str(other.value ? \"true\" : \"false\")\n{\n}\n\nstr str::Substring_(i32 start, i32 length) const\n{\n    return str(length.value, Buffer + start.value);\n}\n\nstr str::Replace_(str oldValue, str newValue) const\n{\n    t_system__text__String_Builder builder = t_system__text__String_Builder(); // TODO initialize capacity\n    int limit = Length - oldValue.Length + 1;\n    int lastIndex = 0;\n    // TODO the Substring calls in here are leaking memory\n    for(int i=0; i < limit; i++)\n        if (cond(equal_op(Substring_(i32(i), i32(oldValue.Length)), oldValue)))\n        {\n            builder.Append_(Substring_(i32(lastIndex), i32(i-lastIndex)));\n            builder.Append_(newValue);\n            i += oldValue.Length; // skip over the value we just matched\n            lastIndex = i;\n            i--; // we need i-- to offset the i++ that is about to happen\n        }\n\n    builder.Append_(Substring_(i32(lastIndex), i32(Length - lastIndex)));\n    return builder.ToString_();\n}\n\ni32 str::LastIndexOf_(cp c) const\n{\n    for(int i = Length - 1; i >= 0; i--)\n        if(Buffer[i] == cp_to_char(c))\n            return i32(i);\n\n    return i32(-1); // TODO should return none\n}\n\ni32 str::index_of_(cp c) const\n{\n    for(int i = 0; i < Length; i++)\n        if(Buffer[i] == cp_to_char(c))\n            return i32(i);\n\n    return i32(-1);\n}\n\nstr str::op_add(str const & value) const\n{\n    int newLength = Length + value.Length;\n    char* chars = new char[newLength];\n    size_t offset = sizeof(char) * Length;\n    std::memcpy(chars, Buffer, offset);\n    std::memcpy(chars + offset, value.Buffer, value.Length);\n    return str(newLength, chars);\n}\n\nauto equal_op(str lhs, str rhs) -> bit\n{\n    if (lhs.Length != rhs.Length)\n        return bit_false;\n\n    for (int i = 0; i < lhs.Length; i++)\n        if (lhs.Buffer[i] != rhs.Buffer[i])\n            return bit_false;\n\n    return bit_true;\n}\n\nbit str_less_than(str lhs, str rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) < 0;\n    delete[] left;\n    delete[] right;\n    return bit_from(result);\n}\nbit str_less_than_or_equal(str lhs, str rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) <= 0;\n    delete[] left;\n    delete[] right;\n    return bit_from(result);\n}\nbit str_greater_than(str lhs, str rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) > 0;\n    delete[] left;\n    delete[] right;\n    return bit_from(result);\n}\nbit str_greater_than_or_equal(str lhs, str rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) >= 0;\n    delete[] left;\n    delete[] right;\n    return bit_from(result);\n}\n\nbool operator < (str const & lhs, str const & rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) < 0;\n    delete[] left;\n    delete[] right;\n    return result;\n}\n\n// -----------------------------------------------------------------------------\n// Standard Library\n// -----------------------------------------------------------------------------\n\nstd::map<str, str> resourceValues;\n\nstr const & ResourceManager::GetString_(str resourceName)\n{\n    return resourceValues.at(resourceName);\n}\nvoid ResourceManager::AddResource(str name, str value)\n{\n    resourceValues.insert(std::make_pair(name, value));\n}\n\nResourceManager *const resource_manager_ = new ResourceManager();\n\nvoid debug_write_(str value)\n{\n    std::fprintf(stderr, \"%.*s\", value.Length, value.Buffer);\n}\nvoid debug_write_line_(str value)\n{\n    std::fprintf(stderr, \"%.*s\\n\", value.Length, value.Buffer);\n}\nvoid debug_write_line_()\n{\n    std::fprintf(stderr, \"\\n\");\n}\n\nvoid t_system__console__Console::Write_(str value)\n{\n    std::printf(\"%.*s\", value.Length, value.Buffer);\n}\n\nvoid t_system__console__Console::WriteLine_(str value)\n{\n    std::printf(\"%.*s\\n\", value.Length, value.Buffer);\n}\n\nvoid t_system__console__Console::WriteLine_()\n{\n    std::printf(\"\\n\");\n}\n\nt_system__console__Arguments::t_system__console__Arguments(int argc, char const *const * argv)\n    : Count(argc-1)\n{\n    args = new str[Count];\n    for (int i = 0; i < Count; i++)\n        args[i] = str(argv[i+1]);\n}\n\nt_system__io__File_Reader *_Nonnull t_system__io__File_Reader::construct(const str& fileName)\n{\n    std::FILE* foo;\n    auto fname = fileName.cstr();\n    file = std::fopen(fname, \"rb\");\n    delete[] fname;\n    return this;\n}\n\nstr t_system__io__File_Reader::ReadToEndSync_()\n{\n    std::fseek(file, 0, SEEK_END);\n    auto length = std::ftell(file);\n    std::fseek(file, 0, SEEK_SET);\n    auto buffer = new char[length];\n    length = std::fread(buffer, sizeof(char), length, file);\n    return str(length, buffer);\n}\n\nvoid t_system__io__File_Reader::Close_()\n{\n    std::fclose(file);\n}\n\nt_system__io__File_Writer *_Nonnull t_system__io__File_Writer::construct(const str& fileName)\n{\n    auto fname = fileName.cstr();\n    file = std::fopen(fname, \"wb\"); // TODO check error\n    delete[] fname;\n    return this;\n}\n\nvoid t_system__io__File_Writer::Write_(const str& value)\n{\n    std::fwrite(value.Buffer, sizeof(char), value.Length, file);\n}\n\nvoid t_system__io__File_Writer::Close_()\n{\n    std::fclose(file);\n}\n\nvoid t_system__text__String_Builder::ensure_capacity(int needed)\n{\n    int new_capacity = capacity == 0 ? 128 : capacity;\n    while(new_capacity < needed)\n    {\n        new_capacity *= 2;\n    }\n\n    if(new_capacity > capacity)\n    {\n        char* new_buffer = new char[new_capacity];\n        if(length > 0)\n            std::memcpy(new_buffer, buffer, length);\n\n        if(capacity > 0)\n            delete[] buffer;\n\n        buffer = new_buffer;\n        capacity = new_capacity;\n    }\n}\n\nt_system__text__String_Builder *_Nonnull t_system__text__String_Builder::construct(str const & value)\n{\n    ensure_capacity(value.Length);\n    std::memcpy(buffer, value.Buffer, value.Length);\n    length = value.Length;\n    return this;\n}\n\nt_system__text__String_Builder *_Nonnull t_system__text__String_Builder::construct_with_capacity(i32 capacity)\n{\n    ensure_capacity(capacity.value);\n    return this;\n}\n\nvoid t_system__text__String_Builder::Append_(str const & value)\n{\n    int new_length = length + value.Length;\n    ensure_capacity(new_length);\n    std::memcpy(buffer+length, value.Buffer, value.Length);\n    length = new_length;\n}\n\nvoid t_system__text__String_Builder::Append_(t_system__text__String_Builder const *_Nonnull value)\n{\n    int new_length = length + value->length;\n    ensure_capacity(new_length);\n    std::memcpy(buffer+length, value->buffer, value->length);\n    length = new_length;\n}\n\nvoid t_system__text__String_Builder::AppendLine_(str const & value)\n{\n    int new_length = length + value.Length + 1;\n    ensure_capacity(new_length);\n    std::memcpy(buffer+length, value.Buffer, value.Length);\n    buffer[new_length-1] = '\\n';\n    length = new_length;\n}\n\nvoid t_system__text__String_Builder::AppendLine_()\n{\n    int new_length = length + 1;\n    ensure_capacity(new_length);\n    buffer[new_length-1] = '\\n';\n    length = new_length;\n}\n\nvoid t_system__text__String_Builder::Remove_(i32 start, i32 length)\n{\n    if(start.value >= this->length)\n        throw std::runtime_error(\"String_Builder.Remove() start >= length\");\n\n    int end = start.value + length.value;\n    if(end > this->length) // greater than because end is one past the end of the remove\n        throw std::runtime_error(\"String_Builder.Remove() end > length\");\n\n    std::memmove(buffer+start.value, buffer+end, this->length-end);\n    this->length -= length.value;\n}\n\nvoid t_system__text__String_Builder::Remove_(i32 start)\n{\n    if(start.value >= length)\n        throw std::runtime_error(\"String_Builder.Remove() start >= length\");\n\n    length = start.value;\n}\n\nstr t_system__text__String_Builder::ToString_()\n{\n    str result(length, buffer);\n    // give up ownership of buffer\n    buffer = 0;\n    length = 0;\n    capacity = 0;\n    return result;\n}\n"));
		resource_manager_->AddResource(str("RuntimeLibrary.hpp"), str("// On windows this disables warnings about using fopen_s instead of fopen\n// It must be defined before including the headers.\n#define _CRT_SECURE_NO_WARNINGS\n#include <cstring>\n#include <cstdio>\n#include <cstdint>\n#include <stdexcept>\n#include <string>\n\n// -----------------------------------------------------------------------------\n// Primitive Types\n// -----------------------------------------------------------------------------\n\n// `bool`\nstruct bit\n{\n    bool value;\n};\n\n// `true`\nstatic const bit bit_true = { true };\n// `false`\nstatic const bit bit_false = { false };\n\n// Function used in conditions to make them take `bit`\ninline bool cond(bit cond) { return cond.value; }\n\n// Used by runtime for converting to bit\ninline bit bit_from(bool v) { return bit { v }; }\n\n// Wrap a bit operation that is bool based\ninline bit bit_op(bool v) { return bit { v }; }\n// Convert the arguments of a logical operation to bool\ninline bool bit_arg(bit v) { return v.value; }\ninline bit bit_not(bit v) { return bit { !v.value }; }\n\n// `never`\nstruct never\n{\n};\n\n// `never?`\nstruct o_never\n{\n    // TODO get rid of this conversion operator when compiler emits conversions\n    template<class T>\n    operator T*_Nullable() const { return static_cast<T*>(0); }\n};\n\nstatic const o_never none;\n\ntemplate<typename T>\nstruct p_optional final\n{\nprivate:\n    bool hasValue;\n    union\n    {\n        T data;\n    };\n\npublic:\n    // TODO make this constructor explicit\n    p_optional(T const & value) : data(value), hasValue(true) {}\n    // TODO get rid of this conversion operator when compiler emits conversions\n    p_optional(o_never none) : hasValue(false) {}\n    auto has_value() const -> bit { return bit_from(hasValue); }\n    auto value() const -> T { return data; }\n\n    T & operator->()\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n    T const & operator->() const\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n    T & operator* ()\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n    T const & operator* () const\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n};\n\nstruct u32;\n\n// `int`\nstruct i32\n{\n    // Runtime Use Members\n    std::int32_t value;\n\n    explicit i32() = default;\n    explicit i32(std::int32_t value): value(value) {}\n\n    i32 *_Nonnull operator->() { return this; }\n    i32 const *_Nonnull operator->() const { return this; }\n    i32 & operator* () { return *this; }\n    i32 const & operator* () const { return *this; }\n\n    // Hack to support conversion of uint to int for now\n    i32(u32 value);\n\n    // Adamant Members\n    static auto construct() -> i32 { return i32(0); }\n    static auto copy(i32 const & other) -> i32 { return other; }\n    void op_add_assign(i32 other) { this->value += other.value; }\n    void op_subtract_assign(i32 other) { this->value -= other.value; }\n    bit op_less_than(i32 other) const { return bit_from(this->value < other.value); }\n    bit op_less_than_or_equal(i32 other) const { return bit_from(this->value <= other.value); }\n    bit op_greater_than(i32 other) const { return bit_from(this->value > other.value); }\n    bit op_greater_than_or_equal(i32 other) const { return bit_from(this->value >= other.value); }\n    i32 op_add(i32 other) const { return i32(this->value + other.value); }\n    i32 op_subtract(i32 other) const { return i32(this->value - other.value); }\n    i32 op_multiply(i32 other) const { return i32(this->value * other.value); }\n    i32 op_divide(i32 other) const { return i32(this->value / other.value); }\n    i32 op_remainder(i32 other) const { return i32(this->value % other.value); }\n    i32 op_magnitude() const { if(this->value==INT32_MIN) throw std::overflow_error(\"Can't take |int.Min|\"); return i32(this->value < 0 ? -this->value : this->value); }\n\n    // Hack because we don't support as correctly yet\n    u32 as_uint_() const;\n};\n\ninline i32 i32_negate(i32 v) { return i32(-v.value); }\ninline bit i32_less_than(i32 lhs, i32 rhs) { return bit_from(lhs.value < rhs.value); }\ninline bit i32_less_than_or_equal(i32 lhs, i32 rhs) { return bit_from(lhs.value <= rhs.value); }\ninline bit i32_greater_than(i32 lhs, i32 rhs) { return bit_from(lhs.value > rhs.value); }\ninline bit i32_greater_than_or_equal(i32 lhs, i32 rhs) { return bit_from(lhs.value >= rhs.value); }\n\n// `uint`\nstruct u32\n{\n    // Runtime Use Members\n    std::uint32_t value;\n\n    explicit u32() = default;\n    explicit u32(std::uint32_t value): value(value) {}\n\n    u32 *_Nonnull operator->() { return this; }\n    u32 const *_Nonnull operator->() const { return this; }\n    u32 & operator* () { return *this; }\n    u32 const & operator* () const { return *this; }\n\n    // Hack to support conversion of int to uint for now\n    u32(i32 value): value(value.value) {}\n\n    // Adamant Members\n    static auto construct() -> u32 { return u32(0); }\n    void op_add_assign(u32 other) { this->value += other.value; }\n    void op_subtract_assign(u32 other) { this->value -= other.value; }\n    bit op_less_than(u32 other) const { return bit_from(this->value < other.value); }\n    bit op_less_than_or_equal(u32 other) const { return bit_from(this->value <= other.value); }\n    bit op_greater_than(u32 other) const { return bit_from(this->value > other.value); }\n    bit op_greater_than_or_equal(u32 other) const { return bit_from(this->value >= other.value); }\n    u32 op_add(u32 other) const { return u32(this->value + other.value); }\n    u32 op_subtract(u32 other) const { return u32(this->value - other.value); }\n};\n\ninline bit u32_less_than(u32 lhs, u32 rhs) { return bit_from(lhs.value < rhs.value); }\ninline bit u32_less_than_or_equal(u32 lhs, u32 rhs) { return bit_from(lhs.value <= rhs.value); }\ninline bit u32_greater_than(u32 lhs, u32 rhs) { return bit_from(lhs.value > rhs.value); }\ninline bit u32_greater_than_or_equal(u32 lhs, u32 rhs) { return bit_from(lhs.value >= rhs.value); }\n\ninline i32::i32(u32 value)\n    : value(value.value)\n{\n}\n\nstruct cp\n{\n    std::uint32_t value;\n\n    // Runtime Use Members\n    explicit cp() = default;\n    explicit cp(char value): value(value) {}\n\n    cp *_Nonnull operator->() { return this; }\n    cp const *_Nonnull operator->() const { return this; }\n    cp & operator* () { return *this; }\n    cp const & operator* () const { return *this; }\n\n    // Adamant Members\n    static auto construct() -> cp { return cp('\\0'); }\n};\n\nchar cp_to_char(cp v);\n\n// TODO: Not sure code_point should support comparision operations\ninline bit cp_less_than(cp lhs, cp rhs) { return bit_from(lhs.value < rhs.value); }\ninline bit cp_less_than_or_equal(cp lhs, cp rhs) { return bit_from(lhs.value <= rhs.value); }\ninline bit cp_greater_than(cp lhs, cp rhs) { return bit_from(lhs.value > rhs.value); }\ninline bit cp_greater_than_or_equal(cp lhs, cp rhs) { return bit_from(lhs.value >= rhs.value); }\n\nstruct str\n{\n    // Runtime Use Members\n    char const *_Nonnull Buffer;\n    int Length;\n\n    explicit str() = default;\n    explicit str(char const *_Nonnull s);\n    explicit str(int length, char const *_Nonnull s);\n    char const *_Nonnull cstr() const;\n    str const *_Nonnull operator->() const { return this; }\n    str const & operator* () const { return *this; }\n\n    typedef char const *_Nonnull const_iterator;\n    const_iterator begin() const { return &Buffer[0]; }\n    const_iterator end() const { return &Buffer[Length]; }\n\n    // Hack to support conversion of int and code_point to strings for now\n    str(i32 other);\n    str(cp other);\n    explicit str(bit other);\n\n    // Adamant Members\n    static auto construct() -> str { str self; self.Length = 0; self.Buffer = 0; return self; }\n    static auto construct(str value) -> str { return value; }\n    static auto construct(cp c, i32 repeat) -> str;\n    // TODO ByteLength should be a property\n    i32 ByteLength_() const { return i32(Length); }\n\n    str Substring_(i32 start, i32 length) const;\n    str Substring_(i32 start) const { return Substring_(start, i32(Length-start.value)); }\n    str Replace_(str oldValue, str newValue) const;\n    i32 LastIndexOf_(cp c) const;\n    i32 index_of_(cp c) const;\n\n    // TODO check index bounds\n    cp op_Element(i32 const index) const { return cp(Buffer[index.value]); }\n    str op_add(str const & value) const;\n    str op_add(bit value) const { return this->op_add(str(value)); }\n};\n\nbit str_less_than(str lhs, str rhs);\nbit str_less_than_or_equal(str lhs, str rhs);\nbit str_greater_than(str lhs, str rhs);\nbit str_greater_than_or_equal(str lhs, str rhs);\n\ninline str new_str()\n{\n    return str::construct();\n}\ninline str new_str(str value)\n{\n    return str::construct(value);\n}\ninline str new_str(cp c, i32 repeat)\n{\n    return str::construct(c, repeat);\n}\n\n// -----------------------------------------------------------------------------\n// Operators\n// -----------------------------------------------------------------------------\n\ninline auto equal_op(bit lhs, bit rhs) -> bit\n{\n    return bit_from(lhs.value == rhs.value);\n}\ninline auto equal_op(p_optional<bit> lhs, p_optional<bit> rhs) -> bit\n{\n    if(lhs.has_value().value)\n        return bit_op(bit_arg(rhs.has_value()) && bit_arg(equal_op(lhs.value(), rhs.value())));\n    else\n        return bit_not(rhs.has_value());\n}\n\ninline auto equal_op(i32 lhs, i32 rhs) -> bit\n{\n    return bit_from(lhs.value == rhs.value);\n}\ninline auto equal_op(p_optional<i32> lhs, p_optional<i32> rhs) -> bit\n{\n    if(lhs.has_value().value)\n        return bit_op(bit_arg(rhs.has_value()) && bit_arg(equal_op(lhs.value(), rhs.value())));\n    else\n        return bit_not(rhs.has_value());\n}\n\ninline auto equal_op(o_never lhs, o_never rhs) -> bit\n{\n    return bit_true;\n}\n\ninline auto equal_op(cp lhs, cp rhs) -> bit\n{\n    return bit_from(lhs.value == rhs.value);\n}\n\nauto equal_op(str lhs, str rhs) -> bit;\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto equal_op(T const *_Nullable lhs, o_never rhs) -> bit\n{\n    return bit_from(lhs == 0);\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto equal_op(o_never lhs, T const *_Nullable rhs) -> bit\n{\n    return bit_from(0 == rhs);\n}\n\n// TODO Get rid of this ability\ntemplate<typename T>\ninline auto equal_op(T const *_Nullable lhs, T const *_Nullable const & rhs) -> bit\n{\n    return bit_from(lhs == 0);\n}\n\ninline auto not_equal_op(i32 lhs, i32 rhs) -> bit\n{\n    return bit_from(lhs.value != rhs.value);\n}\ninline auto not_equal_op(p_optional<i32> lhs, p_optional<i32> rhs) -> bit\n{\n    if(lhs.has_value().value)\n        return bit_op(bit_arg(bit_not(rhs.has_value())) || bit_arg(not_equal_op(lhs.value(), rhs.value())));\n    else\n        return rhs.has_value();\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto not_equal_op(T lhs, T  rhs) -> bit\n{\n    return bit_not(equal_op(lhs, rhs));\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto not_equal_op(T const *_Nullable lhs, o_never rhs) -> bit\n{\n    return bit_from(lhs != 0);\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto not_equal_op(o_never lhs, T const *_Nullable rhs) -> bit\n{\n    return bit_from(0 != rhs);\n}\n\n// -----------------------------------------------------------------------------\n// Standard Library\n// -----------------------------------------------------------------------------\n// Parts of the standard library that are currently implemented in the runtime.\n\n// A placeholder function until we get proper exceptions implemented\n_Noreturn inline void THROW_EXCEPTION_(const str& value)\n{\n    throw std::runtime_error(value.cstr());\n}\n\n\ninline void assert(const bit condition, char const *_Nonnull code, const str message, char const *_Nonnull file, const std::int32_t line)\n{\n    if(!condition.value)\n        throw std::runtime_error(\n            str(\"Assertion failed: \").op_add(str(code)).op_add(str(\", \")).op_add(message)\n            .op_add(str(\", file \")).op_add(str(file)).op_add(str(\", line \")).op_add(i32(line)).cstr());\n}\n\n#define assert_(condition, message) assert(condition, #condition, message, __FILE__, __LINE__)\n\n\n_Noreturn inline void NOT_IMPLEMENTED(const str message, char const *_Nonnull function, char const *_Nonnull file, const std::int32_t line)\n{\n    throw std::runtime_error(\n        str(\"Function \").op_add(str(function))\n        .op_add(str(\" not yet implemented, \")).op_add(message).op_add(str(\", \")).op_add(str(file)).op_add(str(\", line \")).op_add(i32(line)).cstr());\n}\n\n#define NOT_IMPLEMENTED_(message) NOT_IMPLEMENTED(message, __func__, __FILE__, __LINE__)\n\n\n_Noreturn inline void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const std::int32_t line)\n{\n    throw std::runtime_error(\n        str(\"Reached \\\"UNREACHABLE\\\" statement in function \").op_add(str(function))\n        .op_add(str(\", \")).op_add(str(file)).op_add(str(\", line \")).op_add(i32(line)).cstr());\n}\n\n#define UNREACHABLE_() UNREACHABLE(__func__, __FILE__, __LINE__)\n\nclass ResourceManager\n{\npublic:\n    str const & GetString_(str resourceName);\n    void AddResource(str name, str value);\n};\n\nextern ResourceManager *_Nonnull const resource_manager_;\n\nvoid debug_write_(str value);\nvoid debug_write_line_(str value);\nvoid debug_write_line_();\n\ntemplate<typename T>\nclass t_system__collections__List\n{\nprivate:\n    T *_Nonnull values;\n    int length;\n    int capacity;\n\npublic:\n    // Runtime Use Members\n    typedef T const *_Nonnull const_iterator;\n    const_iterator begin() const { return values; }\n    const_iterator end() const { return &values[length]; }\n\n    // Adamant Members\n    t_system__collections__List *_Nonnull construct() { values = 0; length = 0; capacity = 0; return this; }\n    void add_(T value);\n    void clear_() { length = 0; }\n    i32 op_magnitude() const { return i32(length); }\n    T const & op_Element(i32 const index) const;\n};\n\ntemplate<typename T>\nvoid t_system__collections__List<T>::add_(T value)\n{\n    if(length >= capacity)\n    {\n        int newCapacity = capacity == 0 ? 16 : capacity * 2;\n        // Allocate uninitalized buffer (note `sizeof(char) == 1` always)\n        // Needed if T is a value type to avoid needing a default constructor\n        T* newValues = (T*)new char[newCapacity * sizeof(T)];\n        std::memcpy(newValues, values, length * sizeof(T));\n        values = newValues;\n        capacity = newCapacity;\n    }\n    values[length] = value;\n    length++;\n}\n\ntemplate<typename T>\nT const & t_system__collections__List<T>::op_Element(i32 const index) const\n{\n    if(index.value < 0 || index.value >= length)\n        throw std::out_of_range(\"List index out of bounds\");\n    return values[index.value];\n}\n\ntemplate<typename T>\nt_system__collections__List<T> *_Nonnull new_t_system__collections__List()\n{\n    return (new t_system__collections__List<T>())->construct();\n}\n\nclass t_system__console__Console\n{\npublic:\n    void Write_(str value);\n    void WriteLine_(str value);\n    void WriteLine_();\n};\n\nclass t_system__console__Arguments\n{\nprivate:\n    str *_Nonnull args;\npublic:\n    // Runtime Use Members\n    typedef str const *_Nonnull const_iterator;\n\n    t_system__console__Arguments(int argc, char const *_Nonnull const *_Nonnull argv);\n    const_iterator begin() const { return &args[0]; }\n    const_iterator end() const { return &args[Count]; }\n\n    const int Count;\n\n    // Adamant Members\n    i32 op_magnitude() const { return i32(Count); }\n    str const & op_Element(i32 const index) const\n    {\n        if(index.value < 0 || index.value >= Count)\n            throw std::out_of_range(\"Argument index out of bounds\");\n        return args[index.value];\n    }\n};\n\nclass t_system__io__File_Reader\n{\nprivate:\n    std::FILE *_Nonnull file;\n\npublic:\n    t_system__io__File_Reader *_Nonnull construct(const str& fileName);\n    str ReadToEndSync_();\n    void Close_();\n};\n\ninline t_system__io__File_Reader *_Nonnull new_t_system__io__File_Reader(const str& fileName)\n{\n    return (new t_system__io__File_Reader())->construct(fileName);\n}\n\nclass t_system__io__File_Writer\n{\nprivate:\n    std::FILE *_Nonnull file;\n\npublic:\n    t_system__io__File_Writer *_Nonnull construct(const str& fileName);\n    void Write_(const str& value);\n    void Close_();\n};\n\ninline t_system__io__File_Writer *_Nonnull new_t_system__io__File_Writer(const str& fileName)\n{\n    return (new t_system__io__File_Writer())->construct(fileName);\n}\n\nclass t_system__text__String_Builder\n{\nprivate:\n    char *_Nullable buffer;\n    int capacity;\n    int length;\n    void ensure_capacity(int needed);\npublic:\n    // Runtime Use Members\n    t_system__text__String_Builder(): buffer(0), capacity(0), length(0) { }\n\n    // Adamant Members\n    t_system__text__String_Builder *_Nonnull construct() { return this; }\n    t_system__text__String_Builder *_Nonnull construct(str const & value);\n    t_system__text__String_Builder *_Nonnull construct_with_capacity(i32 capacity);\n    // TODO byte_length_ should be a property\n    i32 byte_length_() const { return i32(length); }\n    void Append_(str const & value);\n    void Append_(t_system__text__String_Builder const *_Nonnull value);\n    void AppendLine_(str const& value);\n    void AppendLine_();\n    void Remove_(i32 start, i32 length);\n    void Remove_(i32 start);\n    str ToString_();\n};\n\ninline t_system__text__String_Builder *_Nonnull new_t_system__text__String_Builder()\n{\n    return (new t_system__text__String_Builder())->construct();\n}\n\ninline t_system__text__String_Builder *_Nonnull new_t_system__text__String_Builder(str const & value)\n{\n    return (new t_system__text__String_Builder())->construct(value);\n}\n\ninline t_system__text__String_Builder *_Nonnull new_t_system__text__String_Builder__with_capacity(i32 capacity)\n{\n    return (new t_system__text__String_Builder())->construct_with_capacity(capacity);\n}\n"));

		return main_(new t_system__console__Console(), new t_system__console__Arguments(argc, argv)).value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
