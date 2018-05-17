#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Source_Text Source_Text;
typedef struct Text_Line Text_Line;
typedef struct Text_Lines Text_Lines;
typedef struct Text_Position Text_Position;
typedef struct Text_Span Text_Span;
typedef struct Source_File_Builder Source_File_Builder;
typedef struct Compilation_Unit Compilation_Unit;
typedef struct Package Package;
typedef struct Package_Reference Package_Reference;
typedef struct Semantic_Node Semantic_Node;
typedef struct Semantic_Tree_Builder Semantic_Tree_Builder;
typedef struct Compilation_Unit_Parser Compilation_Unit_Parser;
typedef struct Syntax_Node Syntax_Node;
typedef struct Token_Stream Token_Stream;
typedef struct Diagnostic Diagnostic;
typedef struct Emitter Emitter;
typedef struct Name Name;
typedef struct Package_Name Package_Name;
typedef struct Symbol Symbol;
typedef struct Type Type;
typedef struct Name_Subtable Name_Subtable;
typedef struct Name_Table Name_Table;

// Function Declarations
auto compile_(system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const sources_) -> Package const *_Nonnull;
auto write_(system__console__Console *_Nonnull const console_, system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull const diagnostics_) -> void;
auto has_errors_(system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull const diagnostics_) -> bit;
auto main_(system__console__Console *_Nonnull const console_, system__console__Arguments const *_Nonnull const args_) -> i32;
auto read_source_(str const path_) -> Source_Text const *_Nonnull;
auto run_unit_tests_(system__console__Console *_Nonnull const console_) -> void;
Source_Text *_Nonnull c_Source_Text(Source_Text *_Nonnull self, str const package_, str const path_, str const text_);
inline Source_Text *_Nonnull new_Source_Text(str const package_, str const path_, str const text_);
auto line_starts_(str const text_) -> system__collections__List<i32> const *_Nonnull;
auto source_byte_length_(Source_Text const *_Nonnull const source_) -> i32;
auto position_of_start_(Source_Text const *_Nonnull const source_, Text_Span const *_Nonnull const span_) -> Text_Position const *_Nonnull;
Text_Line *_Nonnull c_Text_Line(Text_Line *_Nonnull self, Source_Text const *_Nonnull const source_, i32 const start_, i32 const length_);
inline Text_Line *_Nonnull new_Text_Line(Source_Text const *_Nonnull const source_, i32 const start_, i32 const length_);
Text_Line *_Nonnull c_Text_Line__spanning(Text_Line *_Nonnull self, Source_Text const *_Nonnull const source_, i32 const start_, i32 const end_);
inline Text_Line *_Nonnull new_Text_Line__spanning(Source_Text const *_Nonnull const source_, i32 const start_, i32 const end_);
Text_Lines *_Nonnull c_Text_Lines(Text_Lines *_Nonnull self, Source_Text const *_Nonnull const source_, system__collections__List<i32> const *_Nonnull const start_of_line_);
inline Text_Lines *_Nonnull new_Text_Lines(Source_Text const *_Nonnull const source_, system__collections__List<i32> const *_Nonnull const start_of_line_);
auto line_count_(Text_Lines const *_Nonnull const lines_) -> i32;
auto get_line_(Text_Lines const *_Nonnull const lines_, i32 const line_number_) -> Text_Line const *_Nonnull;
auto line_containing_offset_(Text_Lines const *_Nonnull const lines_, i32 const character_offset_) -> i32;
Text_Position *_Nonnull c_Text_Position(Text_Position *_Nonnull self, i32 const character_offset_, i32 const line_, i32 const column_);
inline Text_Position *_Nonnull new_Text_Position(i32 const character_offset_, i32 const line_, i32 const column_);
auto unit_test_Text_Position_() -> void;
auto Text_Position_retains_given_offeset_line_and_column_() -> void;
Text_Span *_Nonnull c_Text_Span(Text_Span *_Nonnull self, i32 const start_, i32 const length_);
inline Text_Span *_Nonnull new_Text_Span(i32 const start_, i32 const length_);
auto format_error_(str const message_) -> str;
Source_File_Builder *_Nonnull c_Source_File_Builder(Source_File_Builder *_Nonnull self);
inline Source_File_Builder *_Nonnull new_Source_File_Builder();
auto error_(Source_File_Builder *_Nonnull const file_, str const message_) -> void;
auto begin_line_(Source_File_Builder *_Nonnull const file_, str const value_) -> void;
auto write_(Source_File_Builder *_Nonnull const file_, str const value_) -> void;
auto end_line_(Source_File_Builder *_Nonnull const file_, str const value_) -> void;
auto write_line_(Source_File_Builder *_Nonnull const file_, str const value_) -> void;
auto blank_line_(Source_File_Builder *_Nonnull const file_) -> void;
auto element_separator_line_(Source_File_Builder *_Nonnull const file_) -> void;
auto statement_separator_line_(Source_File_Builder *_Nonnull const file_) -> void;
auto begin_block_(Source_File_Builder *_Nonnull const file_) -> void;
auto end_block_(Source_File_Builder *_Nonnull const file_) -> void;
auto end_block_with_semicolon_(Source_File_Builder *_Nonnull const file_) -> void;
auto byte_length_(Source_File_Builder const *_Nonnull const file_) -> i32;
auto to_string_(Source_File_Builder *_Nonnull const file_) -> str;
Compilation_Unit *_Nonnull c_Compilation_Unit(Compilation_Unit *_Nonnull self, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_);
inline Compilation_Unit *_Nonnull new_Compilation_Unit(Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_);
auto collect_diagnostics_(Compilation_Unit const *_Nonnull const compilation_unit_, system__collections__List<Diagnostic const *_Nonnull> *_Nonnull const diagnostics_) -> void;
Package *_Nonnull c_Package(Package *_Nonnull self, Package_Name const *_Nonnull const name_, system__collections__List<Package_Reference> const *_Nonnull const references_, system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_, Symbol const *_Nonnull const symbol_);
inline Package *_Nonnull new_Package(Package_Name const *_Nonnull const name_, system__collections__List<Package_Reference> const *_Nonnull const references_, system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_, Symbol const *_Nonnull const symbol_);
auto all_diagnostics_(Package const *_Nonnull const package_) -> system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull;
Package_Reference c_Package_Reference(Package const *_Nonnull const package_);
inline Package_Reference new_Package_Reference(Package const *_Nonnull const package_);
Package_Reference c_Package_Reference(str const name_, Package const *_Nonnull const package_);
inline Package_Reference new_Package_Reference(str const name_, Package const *_Nonnull const package_);
auto build_primitives_package_() -> Package const *_Nonnull;
auto build_primitive_symbols_(Package_Name const *_Nonnull const package_name_) -> system__collections__List<Symbol const *_Nonnull> *_Nonnull;
auto build_adamant_language_namespace_symbol_(Name const *_Nonnull const global_namespace_) -> Symbol const *_Nonnull;
auto build_optional_type_symbol_(Name const *_Nonnull const language_namespace_) -> Symbol const *_Nonnull;
auto build_primitive_symbol_(str const name_, Name const *_Nonnull const namespace_) -> Symbol const *_Nonnull;
auto build_fixed_point_primitives_(system__collections__List<Symbol const *_Nonnull> *_Nonnull const symbols_, i32 const bits_, Name const *_Nonnull const namespace_) -> void;
auto unit_test_build_primitives_package_() -> void;
auto Package_name_is_dollar_primitives_() -> void;
auto Package_has_no_references_or_compilation_units_() -> void;
auto Package_symbol_has_package_name_() -> void;
auto Package_symbol_has_children_() -> void;
auto Package_contains_the_string_type_() -> void;
auto Package_contains_optional_type_() -> void;
auto build_runtime_library_package_() -> Package const *_Nonnull;
auto build_runtime_library_symbols_(Package_Name const *_Nonnull const package_name_) -> system__collections__List<Symbol const *_Nonnull> *_Nonnull;
auto build_function_symbol_(Name const *_Nonnull const name_) -> Symbol const *_Nonnull;
auto build_namespace_symbol_(Name const *_Nonnull const name_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const symbols_) -> Symbol const *_Nonnull;
auto build_class_symbol_(Name const *_Nonnull const namespace_, str const class_name_) -> Symbol const *_Nonnull;
auto build_class_symbol_(Name const *_Nonnull const namespace_, str const class_name_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_) -> Symbol const *_Nonnull;
auto build_generic_class_symbol_(Name const *_Nonnull const namespace_, str const class_name_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_) -> Symbol const *_Nonnull;
auto build_constructor_symbol_(str const name_) -> Symbol const *_Nonnull;
auto unit_test_build_runtime_library_package_() -> void;
auto Runtime_Library_Package_contains_system_package_() -> void;
auto System_namespace_contains_console_namespace_() -> void;
auto Console_namespace_contains_Console_class_() -> void;
auto System_namespace_contains_collections_namespace_() -> void;
auto Collections_namespace_contains_List_class_() -> void;
auto analyze_semantics_(Syntax_Node const *_Nonnull const package_syntax_) -> Package const *_Nonnull;
Semantic_Node *_Nonnull c_Semantic_Node__token(Semantic_Node *_Nonnull self, Syntax_Node const *_Nonnull const syntax_);
inline Semantic_Node *_Nonnull new_Semantic_Node__token(Syntax_Node const *_Nonnull const syntax_);
Semantic_Node *_Nonnull c_Semantic_Node__concrete(Semantic_Node *_Nonnull self, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_);
inline Semantic_Node *_Nonnull new_Semantic_Node__concrete(Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_);
Semantic_Node *_Nonnull c_Semantic_Node__of_type(Semantic_Node *_Nonnull self, Type const *_Nonnull const of_type_, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_);
inline Semantic_Node *_Nonnull new_Semantic_Node__of_type(Type const *_Nonnull const of_type_, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_);
Semantic_Node *_Nonnull c_Semantic_Node__declares_type(Semantic_Node *_Nonnull self, Type const *_Nonnull const type_, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_);
inline Semantic_Node *_Nonnull new_Semantic_Node__declares_type(Type const *_Nonnull const type_, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_);
Semantic_Node *_Nonnull c_Semantic_Node__referencing_type(Semantic_Node *_Nonnull self, Type const *_Nonnull const type_, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_);
inline Semantic_Node *_Nonnull new_Semantic_Node__referencing_type(Type const *_Nonnull const type_, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_);
auto get_text_span_(Semantic_Node const *_Nonnull const node_) -> Text_Span const *_Nonnull;
auto get_text_(Semantic_Node const *_Nonnull const node_) -> str;
auto first_child_(Semantic_Node const *_Nonnull const node_, i32 const kind_) -> Semantic_Node const *_Nullable;
auto children_of_kind_(Semantic_Node const *_Nonnull const node_, i32 const kind_) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull;
auto node_members_(Semantic_Node const *_Nonnull const node_) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull;
auto node_statements_(Semantic_Node const *_Nonnull const node_) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull;
auto node_parameters_(Semantic_Node const *_Nonnull const node_) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull;
auto node_access_modifier_(Semantic_Node const *_Nonnull const node_) -> Semantic_Node const *_Nullable;
auto node_has_child_(Semantic_Node const *_Nonnull const node_, i32 const kind_) -> bit;
auto add_diagnostic_(Semantic_Node *_Nonnull const node_, Diagnostic const *_Nonnull const diagnostic_) -> void;
auto diagnostics_(Semantic_Node const *_Nonnull const node_) -> system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull;
auto collect_diagnostics_(Semantic_Node const *_Nonnull const node_, system__collections__List<Diagnostic const *_Nonnull> *_Nonnull const diagnostics_) -> void;
Semantic_Tree_Builder *_Nonnull c_Semantic_Tree_Builder(Semantic_Tree_Builder *_Nonnull self);
inline Semantic_Tree_Builder *_Nonnull new_Semantic_Tree_Builder();
auto build_compilation_units_(Semantic_Tree_Builder const *_Nonnull const builder_, Syntax_Node const *_Nonnull const package_syntax_, Name_Table const *_Nonnull const name_table_) -> system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull;
auto build_compilation_unit_semantic_node_(Semantic_Tree_Builder const *_Nonnull const builder_, Syntax_Node const *_Nonnull const compilation_unit_syntax_, Name_Table const *_Nonnull const name_table_) -> Compilation_Unit const *_Nonnull;
auto build_semantic_node_(Semantic_Tree_Builder const *_Nonnull const builder_, Syntax_Node const *_Nonnull const syntax_, Name_Table const *_Nonnull const name_table_, Name_Subtable const *_Nonnull const scope_) -> Semantic_Node const *_Nonnull;
auto build_parameters_semantic_node_(Semantic_Tree_Builder const *_Nonnull const builder_, Syntax_Node const *_Nonnull const parameters_syntax_, Name_Table const *_Nonnull const name_table_, Name_Subtable const *_Nonnull const scope_) -> Semantic_Node *_Nonnull;
auto build_type_name_semantic_node_(Semantic_Tree_Builder const *_Nonnull const builder_, Syntax_Node const *_Nonnull const syntax_, Name_Table const *_Nonnull const name_table_, Name_Subtable const *_Nonnull const scope_) -> Semantic_Node *_Nonnull;
auto build_type_arguments_semantic_node_(Semantic_Tree_Builder const *_Nonnull const builder_, Syntax_Node const *_Nonnull const syntax_, Name_Table const *_Nonnull const name_table_, Name_Subtable const *_Nonnull const scope_, system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const children_) -> system__collections__List<Type const *_Nonnull> const *_Nonnull;
auto build_constructor_name_semantic_node_(Semantic_Tree_Builder const *_Nonnull const builder_, Syntax_Node const *_Nonnull const syntax_, Name_Table const *_Nonnull const name_table_, Name_Subtable const *_Nonnull const scope_) -> Semantic_Node const *_Nonnull;
auto add_resolution_error_(Semantic_Node *_Nonnull const node_) -> void;
auto add_resolution_error_(Semantic_Node *_Nonnull const node_, Semantic_Node const *_Nonnull const qualifier_) -> void;
auto add_could_not_determine_type_error_(Semantic_Node *_Nonnull const node_) -> void;
auto build_symbols_(Package_Name const *_Nonnull const package_name_, system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_) -> Symbol const *_Nonnull;
Compilation_Unit_Parser *_Nonnull c_Compilation_Unit_Parser(Compilation_Unit_Parser *_Nonnull self, Token_Stream *_Nonnull const token_stream_);
inline Compilation_Unit_Parser *_Nonnull new_Compilation_Unit_Parser(Token_Stream *_Nonnull const token_stream_);
auto parse_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull;
auto accept_token_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nullable;
auto expect_token_(Compilation_Unit_Parser *_Nonnull const parser_, i32 const tokenType_) -> Syntax_Node const *_Nonnull;
auto parse_type_name_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull;
auto parse_non_optional_type_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull;
auto parse_type_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull;
auto parse_atom_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull;
auto parse_call_arguments_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull;
auto parse_expression_(Compilation_Unit_Parser *_Nonnull const parser_, i32 const minPrecedence_) -> Syntax_Node const *_Nonnull;
auto parse_expression_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull;
auto parse_statement_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull;
auto parse_if_statement_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull;
auto parse_variable_declaration_(Compilation_Unit_Parser *_Nonnull const parser_, bit const allowInitializer_) -> Syntax_Node const *_Nonnull;
auto parse_block_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull;
auto parse_parameter_list_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull;
auto parse_member_declaration_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull;
auto parse_declaration_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull;
auto parse_compilation_unit_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull;
auto lexically_analyze_(Source_Text const *_Nonnull const source_) -> Token_Stream *_Nonnull;
auto parse_package_(system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const sources_) -> Syntax_Node const *_Nonnull;
Syntax_Node *_Nonnull c_Syntax_Node(Syntax_Node *_Nonnull self, i32 const type_, Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_);
inline Syntax_Node *_Nonnull new_Syntax_Node(i32 const type_, Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_);
Syntax_Node *_Nonnull c_Syntax_Node(Syntax_Node *_Nonnull self, i32 const type_, bit const isMissing_, Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_);
inline Syntax_Node *_Nonnull new_Syntax_Node(i32 const type_, bit const isMissing_, Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_);
Syntax_Node *_Nonnull c_Syntax_Node(Syntax_Node *_Nonnull self, i32 const type_, Syntax_Node const *_Nonnull const child_);
inline Syntax_Node *_Nonnull new_Syntax_Node(i32 const type_, Syntax_Node const *_Nonnull const child_);
Syntax_Node *_Nonnull c_Syntax_Node(Syntax_Node *_Nonnull self, i32 const type_, system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const children_);
inline Syntax_Node *_Nonnull new_Syntax_Node(i32 const type_, system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const children_);
Syntax_Node *_Nonnull c_Syntax_Node__missing(Syntax_Node *_Nonnull self, i32 const type_, Source_Text const *_Nonnull const source_, u32 const start_);
inline Syntax_Node *_Nonnull new_Syntax_Node__missing(i32 const type_, Source_Text const *_Nonnull const source_, u32 const start_);
Syntax_Node *_Nonnull c_Syntax_Node__skipped(Syntax_Node *_Nonnull self, Syntax_Node const *_Nonnull const skipped_node_);
inline Syntax_Node *_Nonnull new_Syntax_Node__skipped(Syntax_Node const *_Nonnull const skipped_node_);
Syntax_Node *_Nonnull c_Syntax_Node__skipped(Syntax_Node *_Nonnull self, system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const skipped_nodes_);
inline Syntax_Node *_Nonnull new_Syntax_Node__skipped(system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const skipped_nodes_);
auto get_text_(Syntax_Node const *_Nonnull const syntax_) -> str;
auto first_child_syntax_(Syntax_Node const *_Nonnull const syntax_, i32 const type_) -> Syntax_Node const *_Nullable;
auto has_child_(Syntax_Node const *_Nonnull const syntax_, i32 const type_) -> bit;
auto add_(Syntax_Node const *_Nonnull const syntax_, Diagnostic const *_Nonnull const diagnostic_) -> void;
auto all_diagnostics_(Syntax_Node const *_Nonnull const syntax_) -> system__collections__List<Diagnostic const *_Nonnull> *_Nonnull;
auto collect_syntax_diagnostics_(Syntax_Node const *_Nonnull const syntax_, system__collections__List<Diagnostic const *_Nonnull> *_Nonnull const diagnostics_) -> void;
auto members_(Syntax_Node const *_Nonnull const syntax_) -> system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull;
auto parameters_(Syntax_Node const *_Nonnull const syntax_) -> system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull;
auto statements_(Syntax_Node const *_Nonnull const syntax_) -> system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull;
auto access_modifier_(Syntax_Node const *_Nonnull const syntax_) -> Syntax_Node const *_Nullable;
Token_Stream *_Nonnull c_Token_Stream(Token_Stream *_Nonnull self, Source_Text const *_Nonnull const source_);
inline Token_Stream *_Nonnull new_Token_Stream(Source_Text const *_Nonnull const source_);
auto next_token_(Token_Stream *_Nonnull const tokens_) -> Syntax_Node const *_Nullable;
auto end_of_file_token_(Token_Stream *_Nonnull const tokens_) -> Syntax_Node const *_Nullable;
auto new_identifier_or_keyword_token_(Token_Stream *_Nonnull const tokens_, u32 const end_) -> Syntax_Node const *_Nonnull;
auto new_operator_token_(Token_Stream *_Nonnull const tokens_, i32 const type_) -> Syntax_Node const *_Nonnull;
auto new_operator_token_(Token_Stream *_Nonnull const tokens_, i32 const type_, u32 const length_) -> Syntax_Node const *_Nonnull;
auto new_token_(Token_Stream *_Nonnull const tokens_, i32 const type_, u32 const end_) -> Syntax_Node const *_Nonnull;
auto is_identifier_char_(cp const c_) -> bit;
auto is_number_char_(cp const c_) -> bit;
Diagnostic *_Nonnull c_Diagnostic(Diagnostic *_Nonnull self, i32 const level_, i32 const phase_, Source_Text const *_Nonnull const source_, Text_Span const *_Nonnull const span_, str const message_);
inline Diagnostic *_Nonnull new_Diagnostic(i32 const level_, i32 const phase_, Source_Text const *_Nonnull const source_, Text_Span const *_Nonnull const span_, str const message_);
Emitter *_Nonnull c_Emitter(Emitter *_Nonnull self, Package const *_Nonnull const package_, system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const resources_);
inline Emitter *_Nonnull new_Emitter(Package const *_Nonnull const package_, system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const resources_);
auto emit_(Emitter *_Nonnull const emitter_) -> str;
auto mangle_name_(Name const *_Nonnull const name_) -> str;
auto contains_multi_underscore_runs_(str const value_) -> bit;
auto convert_primitive_type_name_(Type const *_Nonnull const type_) -> str;
auto convert_type_name_(Semantic_Node const *_Nonnull const type_node_) -> system__text__String_Builder *_Nonnull;
auto convert_type_name_(Type const *_Nonnull const type_) -> system__text__String_Builder *_Nonnull;
auto convert_reference_type_(bit const mutable_binding_, Type const *_Nonnull type_, bit const nullable_) -> str;
auto convert_type_(bit const mutable_binding_, Type const *_Nonnull type_, bit const optional_) -> str;
auto convert_type_(bit const mutable_binding_, Semantic_Node const *_Nonnull const type_node_) -> str;
auto convert_parameter_list_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const parameters_, str const self_type_, bit const is_main_function_) -> str;
auto convert_method_parameter_list_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const parameters_, str const self_type_) -> str;
auto convert_parameter_list_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const parameters_, bit const is_main_function_) -> str;
auto convert_parameter_list_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const parameters_) -> str;
auto convert_expression_(Semantic_Node const *_Nonnull const syntax_, Source_File_Builder *_Nonnull const builder_) -> void;
auto convert_member_access_(Semantic_Node const *_Nonnull const lhs_, Source_File_Builder *_Nonnull const builder_) -> void;
auto emit_statement_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const statement_) -> void;
auto emit_method_body_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const block_, bit const is_associated_function_) -> void;
auto emit_constructor_body_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const block_, str const self_type_, bit const is_value_type_) -> void;
auto emit_member_declaration_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const member_, str const class_name_, bit const is_value_type_) -> void;
auto emit_default_constructor_(Emitter *_Nonnull const emitter_, str const type_name_, bit const is_value_type_) -> void;
auto emit_declaration_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const declaration_) -> void;
auto emit_compilation_unit_(Emitter *_Nonnull const emitter_, Compilation_Unit const *_Nonnull const unit_) -> void;
auto emit_preamble_(Emitter *_Nonnull const emitter_) -> void;
auto emit_entry_point_adapter_(Emitter *_Nonnull const emitter_) -> void;
Name *_Nonnull c_Name__global_namespace(Name *_Nonnull self);
inline Name *_Nonnull new_Name__global_namespace();
Name *_Nonnull c_Name__global_namespace(Name *_Nonnull self, Package_Name const *_Nonnull const package_);
inline Name *_Nonnull new_Name__global_namespace(Package_Name const *_Nonnull const package_);
Name *_Nonnull c_Name(Name *_Nonnull self, Name const *_Nonnull const qualifier_, i32 const kind_, str const name_);
inline Name *_Nonnull new_Name(Name const *_Nonnull const qualifier_, i32 const kind_, str const name_);
Name *_Nonnull c_Name(Name *_Nonnull self, Name const *_Nonnull const qualifier_, i32 const kind_, str const name_, bit const is_special_);
inline Name *_Nonnull new_Name(Name const *_Nonnull const qualifier_, i32 const kind_, str const name_, bit const is_special_);
Name *_Nonnull c_Name__special(Name *_Nonnull self, Name const *_Nonnull const qualifier_, i32 const kind_, str const name_);
inline Name *_Nonnull new_Name__special(Name const *_Nonnull const qualifier_, i32 const kind_, str const name_);
Name *_Nonnull c_Name(Name *_Nonnull self, Package_Name const *_Nullable const package_, i32 const kind_, system__collections__List<str> const *_Nonnull const segments_, bit const is_special_);
inline Name *_Nonnull new_Name(Package_Name const *_Nullable const package_, i32 const kind_, system__collections__List<str> const *_Nonnull const segments_, bit const is_special_);
auto unqualified_name_(Name const *_Nonnull const name_) -> str;
auto full_name_(Name const *_Nonnull const name_) -> str;
auto is_qualified_by_(Name const *_Nonnull const name_, Name const *_Nonnull const qualifier_) -> bit;
auto qualifier_is_(Name const *_Nonnull const name_, Name const *_Nonnull const qualifier_) -> bit;
auto names_(Name const *_Nonnull const name_, Name const *_Nonnull const other_) -> bit;
auto is_package_qualified_(Name const *_Nonnull const name_) -> bit;
auto remove_package_(Name const *_Nonnull const name_) -> Name const *_Nonnull;
auto unit_test_Name_() -> void;
auto name_with_unspecified_package_names_name_with_package_() -> void;
auto name_with_unspecified_package_names_itself_() -> void;
Package_Name *_Nonnull c_Package_Name(Package_Name *_Nonnull self, str const name_);
inline Package_Name *_Nonnull new_Package_Name(str const name_);
auto full_name_(Package_Name const *_Nonnull const package_name_) -> str;
Symbol *_Nonnull c_Symbol__identifier(Symbol *_Nonnull self, str const name_);
inline Symbol *_Nonnull new_Symbol__identifier(str const name_);
Symbol *_Nonnull c_Symbol__identifier(Symbol *_Nonnull self, str const name_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_);
inline Symbol *_Nonnull new_Symbol__identifier(str const name_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_);
Symbol *_Nonnull c_Symbol__identifier(Symbol *_Nonnull self, str const name_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_);
inline Symbol *_Nonnull new_Symbol__identifier(str const name_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_);
Symbol *_Nonnull c_Symbol__constructor(Symbol *_Nonnull self, str const name_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_);
inline Symbol *_Nonnull new_Symbol__constructor(str const name_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_);
Symbol *_Nonnull c_Symbol__package(Symbol *_Nonnull self, str const name_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_);
inline Symbol *_Nonnull new_Symbol__package(str const name_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_);
Symbol *_Nonnull c_Symbol__declaring(Symbol *_Nonnull self, Type const *_Nonnull const declares_type_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_);
inline Symbol *_Nonnull new_Symbol__declaring(Type const *_Nonnull const declares_type_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_);
Symbol *_Nonnull c_Symbol__of_type(Symbol *_Nonnull self, str const name_, Type const *_Nonnull const of_type_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_);
inline Symbol *_Nonnull new_Symbol__of_type(str const name_, Type const *_Nonnull const of_type_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_);
auto get_child_(Symbol const *_Nonnull const symbol_, str const name_, i32 const kind_) -> Symbol const *_Nullable;
auto unit_test_Symbol_() -> void;
auto Package_symbol_children_can_be_found_by_name_and_kind_() -> void;
Type *_Nonnull c_Type(Type *_Nonnull self, i32 const kind_, Name const *_Nonnull const name_, bit const is_mutable_);
inline Type *_Nonnull new_Type(i32 const kind_, Name const *_Nonnull const name_, bit const is_mutable_);
Type *_Nonnull c_Type__parameter(Type *_Nonnull self, str const name_);
inline Type *_Nonnull new_Type__parameter(str const name_);
Type *_Nonnull c_Type(Type *_Nonnull self, i32 const kind_, Name const *_Nonnull const name_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_mutable_);
inline Type *_Nonnull new_Type(i32 const kind_, Name const *_Nonnull const name_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_mutable_);
Type *_Nonnull c_Type__primitive(Type *_Nonnull self, Name const *_Nonnull const name_);
inline Type *_Nonnull new_Type__primitive(Name const *_Nonnull const name_);
Type *_Nonnull c_Type__primitive(Type *_Nonnull self, Name const *_Nonnull const name_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_);
inline Type *_Nonnull new_Type__primitive(Name const *_Nonnull const name_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_);
Type *_Nonnull c_Type__namespace(Type *_Nonnull self, Name const *_Nonnull const name_);
inline Type *_Nonnull new_Type__namespace(Name const *_Nonnull const name_);
Type *_Nonnull c_Type__generic(Type *_Nonnull self, Type const *_Nonnull const definition_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_arguments_);
inline Type *_Nonnull new_Type__generic(Type const *_Nonnull const definition_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_arguments_);
Type *_Nonnull c_Type(Type *_Nonnull self, i32 const kind_, Name const *_Nonnull const name_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_primitive_, bit const is_potentially_mutable_, bit const is_mutable_);
inline Type *_Nonnull new_Type(i32 const kind_, Name const *_Nonnull const name_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_primitive_, bit const is_potentially_mutable_, bit const is_mutable_);
auto make_mutable_type_(Type const *_Nonnull const type_) -> Type const *_Nonnull;
auto make_immutable_type_(Type const *_Nonnull const type_) -> Type const *_Nonnull;
auto remove_type_package_(Type const *_Nonnull const type_) -> Type const *_Nonnull;
Name_Subtable *_Nonnull c_Name_Subtable__global_namespace(Name_Subtable *_Nonnull self, Name_Table const *_Nonnull const name_table_);
inline Name_Subtable *_Nonnull new_Name_Subtable__global_namespace(Name_Table const *_Nonnull const name_table_);
Name_Subtable *_Nonnull c_Name_Subtable__global_namespace(Name_Subtable *_Nonnull self, Name_Table const *_Nonnull const name_table_, Package_Name const *_Nonnull const package_name_);
inline Name_Subtable *_Nonnull new_Name_Subtable__global_namespace(Name_Table const *_Nonnull const name_table_, Package_Name const *_Nonnull const package_name_);
Name_Subtable *_Nonnull c_Name_Subtable(Name_Subtable *_Nonnull self, Name_Subtable const *_Nonnull const parent_, Name const *_Nonnull const name_, Type const *_Nonnull const type_);
inline Name_Subtable *_Nonnull new_Name_Subtable(Name_Subtable const *_Nonnull const parent_, Name const *_Nonnull const name_, Type const *_Nonnull const type_);
auto add_subtable_(Name_Subtable *_Nonnull const scope_, Name const *_Nonnull const name_, Type const *_Nonnull const type_) -> void;
auto find_(Name_Subtable const *_Nonnull const scope_, str const name_) -> Name_Subtable *_Nullable;
auto find_special_(Name_Subtable const *_Nonnull const scope_, str const name_) -> Name_Subtable *_Nullable;
auto find_(Name_Subtable const *_Nonnull const scope_, str const name_, bit const is_special_) -> Name_Subtable *_Nullable;
auto lookup_(Name_Subtable const *_Nonnull const scope_, str const name_) -> Name_Subtable *_Nullable;
auto lookup_special_(Name_Subtable const *_Nonnull const scope_, str const name_) -> Name_Subtable *_Nullable;
auto lookup_(Name_Subtable const *_Nonnull const scope_, str const name_, bit const is_special_) -> Name_Subtable *_Nullable;
auto get_scope_(Name_Subtable const *_Nonnull const scope_, Name const *_Nonnull const name_) -> Name_Subtable const *_Nullable;
auto bind_type_(Name_Subtable *_Nonnull const scope_, Type const *_Nonnull const type_) -> void;
auto as_mut_(Name_Subtable const *_Nonnull const scope_) -> Name_Subtable *_Nonnull;
auto unit_test_Name_Subtable_() -> void;
auto global_namespace_contains_added_name_() -> void;
auto namespace_contains_added_name_() -> void;
Name_Table *_Nonnull c_Name_Table(Name_Table *_Nonnull self);
inline Name_Table *_Nonnull new_Name_Table();
auto add_package_(Name_Table *_Nonnull const name_table_, Package_Name const *_Nonnull const package_name_) -> Name const *_Nonnull;
auto add_name_(Name_Table *_Nonnull const name_table_, Name const *_Nonnull const parent_, Symbol const *_Nonnull const symbol_) -> Name const *_Nonnull;
auto add_name_(Name_Table *_Nonnull const name_table_, Name const *_Nonnull const name_, Type const *_Nonnull const type_) -> void;
auto get_name_(Name_Table const *_Nonnull const name_table_, Name const *_Nonnull const name_) -> Name_Subtable const *_Nullable;
auto build_name_table_(Package_Name const *_Nonnull const package_name_, Syntax_Node const *_Nonnull const package_syntax_, system__collections__List<Package_Reference> const *_Nonnull const references_) -> Name_Table const *_Nonnull;
auto add_referenced_(Name_Table *_Nonnull const name_table_, system__collections__List<Package_Reference> const *_Nonnull const references_) -> void;
auto add_symbol_(Name_Table *_Nonnull const name_table_, Name const *_Nonnull const parent_, Symbol const *_Nonnull const symbol_) -> void;
auto add_package_(Name_Table *_Nonnull const name_table_, Package_Name const *_Nonnull const package_name_, Syntax_Node const *_Nonnull const package_syntax_) -> void;
auto add_compilation_unit_(Name_Table *_Nonnull const name_table_, Name const *_Nonnull const global_namespace_, Syntax_Node const *_Nonnull const compilation_unit_) -> void;
auto add_syntax_(Name_Table *_Nonnull const name_table_, Name const *_Nonnull const parent_, Syntax_Node const *_Nonnull const syntax_) -> void;
auto add_function_(Name_Table *_Nonnull const name_table_, Name const *_Nonnull const name_, Syntax_Node const *_Nonnull const function_) -> void;
auto unit_test_Name_Table_Builder_() -> void;
auto table_contains_referenced_child_names_() -> void;
auto can_get_root_namespace_from_name_() -> void;
auto can_get_Console_class_from_name_without_package_() -> void;
auto can_get_Optional_class_from_name_with_package_() -> void;

// Class Declarations

struct Source_Text
{
	str package_;
	str path_;
	str name_;
	str text_;
	Text_Lines const *_Nonnull lines_;
};

struct Text_Line
{
	Source_Text const *_Nonnull source_;
	i32 start_;
	i32 byte_length_;
};

struct Text_Lines
{
	Source_Text const *_Nonnull source_;
	system__collections__List<i32> const *_Nonnull start_of_line_;
};

struct Text_Position
{
	i32 character_offset_;
	i32 line_;
	i32 column_;
};

struct Text_Span
{
	i32 start_;
	i32 byte_length_;
};

struct Source_File_Builder
{
	system__text__String_Builder *_Nonnull code_;
	system__text__String_Builder *_Nonnull indent_;
	bit firstElement_;
	bit afterBlock_;
};

struct Compilation_Unit
{
	Syntax_Node const *_Nonnull syntax_;
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull declarations_;
};

struct Package
{
	Package_Name const *_Nonnull name_;
	system__collections__List<Package_Reference> const *_Nonnull references_;
	system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull compilation_units_;
	Symbol const *_Nonnull symbol_;
};

struct Package_Reference
{
	Package_Reference * operator->() { return this; }
	Package_Reference const * operator->() const { return this; }
	Package_Reference & operator* () { return *this; }
	Package_Reference const & operator* () const { return *this; }
	str name_;
	Package const *_Nonnull package_;
};

struct Semantic_Node
{
	Syntax_Node const *_Nonnull syntax_;
	i32 kind_;
	bit is_missing_;
	Source_Text const *_Nonnull source_;
	u32 start_;
	u32 byte_length_;
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull children_;
	system__collections__List<Diagnostic const *_Nonnull> *_Nonnull node_diagnostics_;
	Type const *_Nullable of_type_;
	Type const *_Nullable converted_type_;
	Type const *_Nullable declares_type_;
	Type const *_Nullable referenced_type_;
};

struct Semantic_Tree_Builder
{
	Name const *_Nonnull optional_type_name_;
};

struct Compilation_Unit_Parser
{
	Token_Stream *_Nonnull token_stream_;
	Syntax_Node const *_Nullable token_;
	Syntax_Node const *_Nullable compilation_unit_;
};

struct Syntax_Node
{
	i32 kind_;
	bit is_missing_;
	Source_Text const *_Nonnull source_;
	u32 start_;
	u32 byte_length_;
	system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull children_;
	system__collections__List<Diagnostic const *_Nonnull> *_Nonnull node_diagnostics_;
};

struct Token_Stream
{
	Source_Text const *_Nonnull source_;
	u32 position_;
	system__collections__List<Diagnostic const *_Nonnull> *_Nonnull diagnostics_;
	bit end_of_file_;
};

struct Diagnostic
{
	i32 level_;
	i32 phase_;
	Source_Text const *_Nonnull source_;
	Text_Span const *_Nonnull span_;
	Text_Position const *_Nonnull position_;
	str message_;
};

struct Emitter
{
	Package const *_Nonnull package_;
	system__collections__List<Source_Text const *_Nonnull> const *_Nonnull resources_;
	Source_File_Builder *_Nonnull type_declarations_;
	Source_File_Builder *_Nonnull function_declarations_;
	Source_File_Builder *_Nonnull class_declarations_;
	Source_File_Builder *_Nonnull global_definitions_;
	Source_File_Builder *_Nonnull definitions_;
	str main_function_name_;
	str main_function_return_type_;
	bit main_function_accepts_console_;
	bit main_function_accepts_args_;
};

struct Name
{
	Package_Name const *_Nullable package_;
	i32 kind_;
	system__collections__List<str> const *_Nonnull segments_;
	bit is_special_;
};

struct Package_Name
{
	str unqualified_;
};

struct Symbol
{
	str name_;
	bit is_special_name_;
	i32 kind_;
	Type const *_Nonnull of_type_;
	Type const *_Nonnull declares_type_;
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull declarations_;
	system__collections__List<Symbol const *_Nonnull> const *_Nonnull children_;
};

struct Type
{
	i32 kind_;
	Name const *_Nonnull name_;
	system__collections__List<Type const *_Nonnull> const *_Nonnull type_parameters_;
	bit is_primitive_;
	bit is_value_type_;
	bit is_potentially_mutable_;
	bit is_mutable_;
};

struct Name_Subtable
{
	Name_Table const *_Nonnull name_table_;
	Name_Subtable const *_Nullable parent_;
	Name const *_Nonnull name_;
	Type const *_Nonnull type_;
	system__collections__List<Name_Subtable *_Nonnull> *_Nonnull subtables_;
};

struct Name_Table
{
	Name_Subtable *_Nonnull any_package_;
	system__collections__List<Name_Subtable *_Nonnull> *_Nonnull packages_;
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

auto compile_(system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const sources_) -> Package const *_Nonnull
{
	Syntax_Node const *_Nonnull const package_syntax_ = parse_package_(sources_);
	Package const *_Nonnull const package_ = analyze_semantics_(package_syntax_);
	return package_;
}

auto write_(system__console__Console *_Nonnull const console_, system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull const diagnostics_) -> void
{
	for (Diagnostic const *_Nonnull const diagnostic_ : *(diagnostics_))
	{
		Text_Position const *_Nonnull const position_ = diagnostic_->position_;
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

auto has_errors_(system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull const diagnostics_) -> bit
{
	for (Diagnostic const *_Nonnull const diagnostic_ : *(diagnostics_))
	{
		if (cond(diagnostic_->level_->op_greater_than_or_equal(CompilationError_)))
		{
			return bit_true;
		}
	}

	return bit_false;
}

auto main_(system__console__Console *_Nonnull const console_, system__console__Arguments const *_Nonnull const args_) -> i32
{
	if (cond(bit_op(bit_arg(equal_op(args_->op_magnitude(), i32(1))) && bit_arg(equal_op(args_->op_Element(i32(0)), str("--unit-test"))))))
	{
		run_unit_tests_(console_);
		return i32(0);
	}

	system__collections__List<str> *_Nonnull const sourceFilePaths_ = new_system__collections__List<str>();
	system__collections__List<str> *_Nonnull const resourceFilePaths_ = new_system__collections__List<str>();
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

	system__collections__List<Source_Text const *_Nonnull> *_Nonnull const resources_ = new_system__collections__List<Source_Text const *_Nonnull>();
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

	system__collections__List<Source_Text const *_Nonnull> *_Nonnull const sources_ = new_system__collections__List<Source_Text const *_Nonnull>();
	for (str const sourceFilePath_ : *(sourceFilePaths_))
	{
		if (cond(verbose_))
		{
			console_->WriteLine_(str("  ").op_add(sourceFilePath_));
		}

		sources_->add_(read_source_(sourceFilePath_));
	}

	Package const *_Nonnull const package_ = compile_(sources_);
	system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull const diagnostics_ = all_diagnostics_(package_);
	write_(console_, diagnostics_);
	if (cond(has_errors_(diagnostics_)))
	{
		return DataError_;
	}

	Emitter *_Nonnull emitter_ = new_Emitter(package_, resources_);
	str const translated_ = emit_(emitter_);
	if (cond(verbose_))
	{
		console_->Write_(str("Output: "));
		console_->WriteLine_(outputFilePath_);
	}

	system__io__File_Writer *_Nonnull const outputFile_ = new_system__io__File_Writer(outputFilePath_);
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

	system__io__File_Writer *_Nonnull resourceFile_ = new_system__io__File_Writer(outputDirPath_.op_add(str("RuntimeLibrary.hpp")));
	resourceFile_->Write_(resource_manager_->GetString_(str("RuntimeLibrary.hpp")));
	resourceFile_->Close_();
	resourceFile_ = new_system__io__File_Writer(outputDirPath_.op_add(str("RuntimeLibrary.cpp")));
	resourceFile_->Write_(resource_manager_->GetString_(str("RuntimeLibrary.cpp")));
	resourceFile_->Close_();
	return Success_;
}

auto read_source_(str const path_) -> Source_Text const *_Nonnull
{
	system__io__File_Reader *_Nonnull const file_ = new_system__io__File_Reader(path_);
	str const contents_ = file_->ReadToEndSync_();
	file_->Close_();
	return new_Source_Text(str("<default>"), path_, contents_);
}

auto run_unit_tests_(system__console__Console *_Nonnull const console_) -> void
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

Source_Text *_Nonnull c_Source_Text(Source_Text *_Nonnull self, str const package_, str const path_, str const text_)
{
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
	self->lines_ = new_Text_Lines(self, line_starts_(text_));
	return self;
}

inline Source_Text *_Nonnull new_Source_Text(str const package_, str const path_, str const text_)
{
	return c_Source_Text(new Source_Text(), package_, path_, text_);
}

auto line_starts_(str const text_) -> system__collections__List<i32> const *_Nonnull
{
	i32 const length_ = text_.ByteLength_();
	system__collections__List<i32> *_Nonnull const starting_positions_ = new_system__collections__List<i32>();
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

auto source_byte_length_(Source_Text const *_Nonnull const source_) -> i32
{
	return source_->text_.ByteLength_();
}

auto position_of_start_(Source_Text const *_Nonnull const source_, Text_Span const *_Nonnull const span_) -> Text_Position const *_Nonnull
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

	return new_Text_Position(char_offset_, line_number_, column_);
}

Text_Line *_Nonnull c_Text_Line(Text_Line *_Nonnull self, Source_Text const *_Nonnull const source_, i32 const start_, i32 const length_)
{
	self->source_ = source_;
	self->start_ = start_;
	self->byte_length_ = length_;
	return self;
}

inline Text_Line *_Nonnull new_Text_Line(Source_Text const *_Nonnull const source_, i32 const start_, i32 const length_)
{
	return c_Text_Line(new Text_Line(), source_, start_, length_);
}

Text_Line *_Nonnull c_Text_Line__spanning(Text_Line *_Nonnull self, Source_Text const *_Nonnull const source_, i32 const start_, i32 const end_)
{
	self->source_ = source_;
	self->start_ = start_;
	self->byte_length_ = end_.op_subtract(start_);
	return self;
}

inline Text_Line *_Nonnull new_Text_Line__spanning(Source_Text const *_Nonnull const source_, i32 const start_, i32 const end_)
{
	return c_Text_Line__spanning(new Text_Line(), source_, start_, end_);
}

Text_Lines *_Nonnull c_Text_Lines(Text_Lines *_Nonnull self, Source_Text const *_Nonnull const source_, system__collections__List<i32> const *_Nonnull const start_of_line_)
{
	self->source_ = source_;
	self->start_of_line_ = start_of_line_;
	return self;
}

inline Text_Lines *_Nonnull new_Text_Lines(Source_Text const *_Nonnull const source_, system__collections__List<i32> const *_Nonnull const start_of_line_)
{
	return c_Text_Lines(new Text_Lines(), source_, start_of_line_);
}

auto line_count_(Text_Lines const *_Nonnull const lines_) -> i32
{
	return lines_->start_of_line_->op_magnitude();
}

auto get_line_(Text_Lines const *_Nonnull const lines_, i32 const line_number_) -> Text_Line const *_Nonnull
{
	assert_(i32_greater_than(line_number_, i32(0)), str("line ").op_add(line_number_));
	assert_(i32_less_than_or_equal(line_number_, line_count_(lines_)), str("line ").op_add(line_number_));
	i32 const line_index_ = line_number_.op_subtract(i32(1));
	i32 const line_start_ = lines_->start_of_line_->op_Element(line_index_);
	if (cond(equal_op(line_index_, line_count_(lines_)->op_subtract(i32(1)))))
	{
		return new_Text_Line__spanning(lines_->source_, line_start_, source_byte_length_(lines_->source_));
	}

	i32 const line_end_ = lines_->start_of_line_->op_Element(line_index_.op_add(i32(1)));
	return new_Text_Line__spanning(lines_->source_, line_start_, line_end_);
}

auto line_containing_offset_(Text_Lines const *_Nonnull const lines_, i32 const character_offset_) -> i32
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

Text_Position *_Nonnull c_Text_Position(Text_Position *_Nonnull self, i32 const character_offset_, i32 const line_, i32 const column_)
{
	self->character_offset_ = character_offset_;
	self->line_ = line_;
	self->column_ = column_;
	return self;
}

inline Text_Position *_Nonnull new_Text_Position(i32 const character_offset_, i32 const line_, i32 const column_)
{
	return c_Text_Position(new Text_Position(), character_offset_, line_, column_);
}

auto unit_test_Text_Position_() -> void
{
	Text_Position_retains_given_offeset_line_and_column_();
}

auto Text_Position_retains_given_offeset_line_and_column_() -> void
{
	Text_Position const *_Nonnull const position_ = new_Text_Position(i32(23), i32(2), i32(5));
	assert_(equal_op(position_->character_offset_, i32(23)), str(""));
	assert_(equal_op(position_->line_, i32(2)), str(""));
	assert_(equal_op(position_->column_, i32(5)), str(""));
}

Text_Span *_Nonnull c_Text_Span(Text_Span *_Nonnull self, i32 const start_, i32 const length_)
{
	self->start_ = start_;
	self->byte_length_ = length_;
	return self;
}

inline Text_Span *_Nonnull new_Text_Span(i32 const start_, i32 const length_)
{
	return c_Text_Span(new Text_Span(), start_, length_);
}

auto format_error_(str const message_) -> str
{
	return str("<$ ").op_add(message_)->op_add(str(" $>"));
}

Source_File_Builder *_Nonnull c_Source_File_Builder(Source_File_Builder *_Nonnull self)
{
	self->code_ = new_system__text__String_Builder();
	self->indent_ = new_system__text__String_Builder();
	self->firstElement_ = bit_true;
	self->afterBlock_ = bit_true;
	return self;
}

inline Source_File_Builder *_Nonnull new_Source_File_Builder()
{
	return c_Source_File_Builder(new Source_File_Builder());
}

auto error_(Source_File_Builder *_Nonnull const file_, str const message_) -> void
{
	file_->code_->Append_(format_error_(message_));
}

auto begin_line_(Source_File_Builder *_Nonnull const file_, str const value_) -> void
{
	file_->code_->Append_(file_->indent_);
	file_->code_->Append_(value_);
	file_->firstElement_ = file_->afterBlock_ = bit_false;
}

auto write_(Source_File_Builder *_Nonnull const file_, str const value_) -> void
{
	file_->code_->Append_(value_);
	file_->firstElement_ = file_->afterBlock_ = bit_false;
}

auto end_line_(Source_File_Builder *_Nonnull const file_, str const value_) -> void
{
	file_->code_->Append_(value_);
	file_->code_->AppendLine_();
	file_->firstElement_ = file_->afterBlock_ = bit_false;
}

auto write_line_(Source_File_Builder *_Nonnull const file_, str const value_) -> void
{
	file_->code_->Append_(file_->indent_);
	file_->code_->Append_(value_);
	file_->code_->AppendLine_();
	file_->firstElement_ = file_->afterBlock_ = bit_false;
}

auto blank_line_(Source_File_Builder *_Nonnull const file_) -> void
{
	file_->code_->AppendLine_();
	file_->firstElement_ = bit_true;
	file_->afterBlock_ = bit_false;
}

auto element_separator_line_(Source_File_Builder *_Nonnull const file_) -> void
{
	if (cond(bit_not(file_->firstElement_)))
	{
		file_->code_->AppendLine_();
		file_->firstElement_ = bit_true;
		file_->afterBlock_ = bit_false;
	}
}

auto statement_separator_line_(Source_File_Builder *_Nonnull const file_) -> void
{
	if (cond(file_->afterBlock_))
	{
		file_->code_->AppendLine_();
		file_->firstElement_ = bit_true;
		file_->afterBlock_ = bit_false;
	}
}

auto begin_block_(Source_File_Builder *_Nonnull const file_) -> void
{
	write_line_(file_, str("{"));
	file_->indent_->Append_(str("\t"));
	file_->firstElement_ = file_->afterBlock_ = bit_false;
}

auto end_block_(Source_File_Builder *_Nonnull const file_) -> void
{
	file_->indent_->Remove_(i32(0), i32(1));
	write_line_(file_, str("}"));
	file_->afterBlock_ = bit_true;
}

auto end_block_with_semicolon_(Source_File_Builder *_Nonnull const file_) -> void
{
	file_->indent_->Remove_(i32(0), i32(1));
	write_line_(file_, str("};"));
}

auto byte_length_(Source_File_Builder const *_Nonnull const file_) -> i32
{
	return file_->code_->byte_length_();
}

auto to_string_(Source_File_Builder *_Nonnull const file_) -> str
{
	return file_->code_->ToString_();
}

Compilation_Unit *_Nonnull c_Compilation_Unit(Compilation_Unit *_Nonnull self, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_)
{
	self->syntax_ = syntax_;
	self->declarations_ = declarations_;
	return self;
}

inline Compilation_Unit *_Nonnull new_Compilation_Unit(Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_)
{
	return c_Compilation_Unit(new Compilation_Unit(), syntax_, declarations_);
}

auto collect_diagnostics_(Compilation_Unit const *_Nonnull const compilation_unit_, system__collections__List<Diagnostic const *_Nonnull> *_Nonnull const diagnostics_) -> void
{
	collect_syntax_diagnostics_(compilation_unit_->syntax_, diagnostics_);
	for (Semantic_Node const *_Nonnull const declaration_ : *(compilation_unit_->declarations_))
	{
		collect_diagnostics_(declaration_, diagnostics_);
	}
}

Package *_Nonnull c_Package(Package *_Nonnull self, Package_Name const *_Nonnull const name_, system__collections__List<Package_Reference> const *_Nonnull const references_, system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_, Symbol const *_Nonnull const symbol_)
{
	self->name_ = name_;
	self->references_ = references_;
	self->compilation_units_ = compilation_units_;
	self->symbol_ = symbol_;
	return self;
}

inline Package *_Nonnull new_Package(Package_Name const *_Nonnull const name_, system__collections__List<Package_Reference> const *_Nonnull const references_, system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_, Symbol const *_Nonnull const symbol_)
{
	return c_Package(new Package(), name_, references_, compilation_units_, symbol_);
}

auto all_diagnostics_(Package const *_Nonnull const package_) -> system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull
{
	system__collections__List<Diagnostic const *_Nonnull> *_Nonnull diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	for (Compilation_Unit const *_Nonnull const compilation_unit_ : *(package_->compilation_units_))
	{
		collect_diagnostics_(compilation_unit_, diagnostics_);
	}

	return diagnostics_;
}

Package_Reference c_Package_Reference(Package const *_Nonnull const package_)
{
	Package_Reference self;
	self->name_ = package_->name_->unqualified_;
	self->package_ = package_;
	return self;
}

inline Package_Reference new_Package_Reference(Package const *_Nonnull const package_)
{
	return c_Package_Reference(package_);
}

Package_Reference c_Package_Reference(str const name_, Package const *_Nonnull const package_)
{
	Package_Reference self;
	self->name_ = name_;
	self->package_ = package_;
	return self;
}

inline Package_Reference new_Package_Reference(str const name_, Package const *_Nonnull const package_)
{
	return c_Package_Reference(name_, package_);
}

auto build_primitives_package_() -> Package const *_Nonnull
{
	Package_Name const *_Nonnull const name_ = new_Package_Name(str("$primitives"));
	system__collections__List<Package_Reference> const *_Nonnull const references_ = new_system__collections__List<Package_Reference>();
	system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_ = new_system__collections__List<Compilation_Unit const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const primitive_symbols_ = build_primitive_symbols_(name_);
	assert_(primitive_symbols_->op_magnitude()->op_greater_than(i32(0)), str("|primitive_symbols|=").op_add(primitive_symbols_->op_magnitude()));
	Symbol const *_Nonnull const package_symbol_ = new_Symbol__package(name_->unqualified_, primitive_symbols_);
	assert_(package_symbol_->children_->op_magnitude()->op_greater_than(i32(0)), str("|package_symbol.children|=").op_add(package_symbol_->children_->op_magnitude()));
	return new_Package(name_, references_, compilation_units_, package_symbol_);
}

auto build_primitive_symbols_(Package_Name const *_Nonnull const package_name_) -> system__collections__List<Symbol const *_Nonnull> *_Nonnull
{
	Name const *_Nonnull const global_namespace_ = new_Name__global_namespace(package_name_);
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const symbols_ = new_system__collections__List<Symbol const *_Nonnull>();
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

auto build_adamant_language_namespace_symbol_(Name const *_Nonnull const global_namespace_) -> Symbol const *_Nonnull
{
	Name const *_Nonnull const adamant_namespace_ = new_Name(global_namespace_, NamespaceName_, str("adamant"));
	Name const *_Nonnull const language_namespace_ = new_Name(adamant_namespace_, NamespaceName_, str("language"));
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const language_children_ = new_system__collections__List<Symbol const *_Nonnull>();
	language_children_->add_(build_optional_type_symbol_(language_namespace_));
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const adamant_children_ = new_system__collections__List<Symbol const *_Nonnull>();
	adamant_children_->add_(new_Symbol__identifier(unqualified_name_(language_namespace_), language_children_));
	return new_Symbol__identifier(unqualified_name_(adamant_namespace_), adamant_children_);
}

auto build_optional_type_symbol_(Name const *_Nonnull const language_namespace_) -> Symbol const *_Nonnull
{
	Name const *_Nonnull const optional_name_ = new_Name(language_namespace_, TypeName_, str("optional"));
	system__collections__List<Type const *_Nonnull> *_Nonnull const type_parameters_ = new_system__collections__List<Type const *_Nonnull>();
	type_parameters_->add_(new_Type(TypeParameterType_, new_Name(optional_name_, TypeParameterName_, str("T")), bit_true));
	Type const *_Nonnull const type_ = new_Type__primitive(optional_name_, type_parameters_);
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const declarations_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Symbol const *_Nonnull>();
	return new_Symbol__declaring(type_, declarations_, children_);
}

auto build_primitive_symbol_(str const name_, Name const *_Nonnull const namespace_) -> Symbol const *_Nonnull
{
	Type const *_Nonnull const type_ = new_Type__primitive(new_Name__special(namespace_, TypeName_, name_));
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const declarations_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Symbol const *_Nonnull>();
	return new_Symbol__declaring(type_, declarations_, children_);
}

auto build_fixed_point_primitives_(system__collections__List<Symbol const *_Nonnull> *_Nonnull const symbols_, i32 const bits_, Name const *_Nonnull const namespace_) -> void
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
	Package const *_Nonnull const package_ = build_primitives_package_();
	Package_Name const *_Nonnull const name_ = package_->name_;
	assert_(equal_op(name_->unqualified_, str("$primitives")), str(""));
}

auto Package_has_no_references_or_compilation_units_() -> void
{
	Package const *_Nonnull const package_ = build_primitives_package_();
	assert_(equal_op(package_->references_->op_magnitude(), i32(0)), str(""));
	assert_(equal_op(package_->compilation_units_->op_magnitude(), i32(0)), str(""));
}

auto Package_symbol_has_package_name_() -> void
{
	Package const *_Nonnull const package_ = build_primitives_package_();
	Symbol const *_Nonnull const symbol_ = package_->symbol_;
	assert_(equal_op(symbol_->kind_, PackageSymbol_), str(""));
	assert_(equal_op(symbol_->name_, package_->name_->unqualified_), str(""));
}

auto Package_symbol_has_children_() -> void
{
	Package const *_Nonnull const package_ = build_primitives_package_();
	assert_(package_->symbol_->children_->op_magnitude()->op_greater_than(i32(0)), str(""));
}

auto Package_contains_the_string_type_() -> void
{
	Package const *_Nonnull const package_ = build_primitives_package_();
	Symbol const *_Nonnull const string_symbol_ = get_child_(package_->symbol_, str("string"), IdentifierSymbol_);
	assert_(not_equal_op(string_symbol_, none), str(""));
}

auto Package_contains_optional_type_() -> void
{
	Package const *_Nonnull const package_ = build_primitives_package_();
	Symbol const *_Nullable const adamant_symbol_ = get_child_(package_->symbol_, str("adamant"), IdentifierSymbol_);
	assert_(not_equal_op(adamant_symbol_, none), str(""));
	Symbol const *_Nullable const langauge_symbol_ = get_child_(adamant_symbol_, str("language"), IdentifierSymbol_);
	assert_(not_equal_op(langauge_symbol_, none), str(""));
	Symbol const *_Nullable const optional_symbol_ = get_child_(langauge_symbol_, str("optional"), IdentifierSymbol_);
	assert_(not_equal_op(optional_symbol_, none), str(""));
}

auto build_runtime_library_package_() -> Package const *_Nonnull
{
	Package_Name const *_Nonnull const name_ = new_Package_Name(str("$runtime"));
	system__collections__List<Package_Reference> const *_Nonnull const references_ = new_system__collections__List<Package_Reference>();
	system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_ = new_system__collections__List<Compilation_Unit const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const symbols_ = build_runtime_library_symbols_(name_);
	assert_(symbols_->op_magnitude()->op_greater_than(i32(0)), str("|symbols|=").op_add(symbols_->op_magnitude()));
	Symbol const *_Nonnull const package_symbol_ = new_Symbol__package(name_->unqualified_, symbols_);
	assert_(package_symbol_->children_->op_magnitude()->op_greater_than(i32(0)), str("|package_symbol.children|=").op_add(package_symbol_->children_->op_magnitude()));
	return new_Package(name_, references_, compilation_units_, package_symbol_);
}

auto build_runtime_library_symbols_(Package_Name const *_Nonnull const package_name_) -> system__collections__List<Symbol const *_Nonnull> *_Nonnull
{
	Name const *_Nonnull const global_namespace_ = new_Name__global_namespace(package_name_);
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const symbols_ = new_system__collections__List<Symbol const *_Nonnull>();
	symbols_->add_(build_function_symbol_(new_Name(global_namespace_, FunctionName_, str("THROW_EXCEPTION"))));
	symbols_->add_(build_function_symbol_(new_Name(global_namespace_, FunctionName_, str("NOT_IMPLEMENTED"))));
	symbols_->add_(build_function_symbol_(new_Name(global_namespace_, FunctionName_, str("UNREACHABLE"))));
	symbols_->add_(build_function_symbol_(new_Name(global_namespace_, FunctionName_, str("assert"))));
	symbols_->add_(build_function_symbol_(new_Name(global_namespace_, FunctionName_, str("debug_write"))));
	symbols_->add_(build_function_symbol_(new_Name(global_namespace_, FunctionName_, str("debug_write_line"))));
	symbols_->add_(build_function_symbol_(new_Name(global_namespace_, VariableName_, str("resource_manager"))));
	Name const *_Nonnull const system_namespace_ = new_Name(global_namespace_, NamespaceName_, str("system"));
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const system_symbols_ = new_system__collections__List<Symbol const *_Nonnull>();
	Name const *_Nonnull const collections_namespace_ = new_Name(system_namespace_, NamespaceName_, str("collections"));
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const collections_symbols_ = new_system__collections__List<Symbol const *_Nonnull>();
	system__collections__List<Type const *_Nonnull> *_Nonnull const list_type_parameters_ = new_system__collections__List<Type const *_Nonnull>();
	list_type_parameters_->add_(new_Type__parameter(str("T")));
	collections_symbols_->add_(build_generic_class_symbol_(collections_namespace_, str("List"), list_type_parameters_));
	system_symbols_->add_(build_namespace_symbol_(collections_namespace_, collections_symbols_));
	Name const *_Nonnull const console_namespace_ = new_Name(system_namespace_, NamespaceName_, str("console"));
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const console_symbols_ = new_system__collections__List<Symbol const *_Nonnull>();
	console_symbols_->add_(build_class_symbol_(console_namespace_, str("Console")));
	console_symbols_->add_(build_class_symbol_(console_namespace_, str("Arguments")));
	system_symbols_->add_(build_namespace_symbol_(console_namespace_, console_symbols_));
	Name const *_Nonnull const io_namespace_ = new_Name(system_namespace_, NamespaceName_, str("io"));
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const io_symbols_ = new_system__collections__List<Symbol const *_Nonnull>();
	io_symbols_->add_(build_class_symbol_(io_namespace_, str("File_Reader")));
	io_symbols_->add_(build_class_symbol_(io_namespace_, str("File_Writer")));
	system_symbols_->add_(build_namespace_symbol_(io_namespace_, io_symbols_));
	Name const *_Nonnull const text_namespace_ = new_Name(system_namespace_, NamespaceName_, str("text"));
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const text_symbols_ = new_system__collections__List<Symbol const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const string_builder_symbols_ = new_system__collections__List<Symbol const *_Nonnull>();
	string_builder_symbols_->add_(build_constructor_symbol_(str("with_capacity")));
	text_symbols_->add_(build_class_symbol_(text_namespace_, str("String_Builder"), string_builder_symbols_));
	system_symbols_->add_(build_namespace_symbol_(text_namespace_, text_symbols_));
	symbols_->add_(build_namespace_symbol_(system_namespace_, system_symbols_));
	return symbols_;
}

auto build_function_symbol_(Name const *_Nonnull const name_) -> Symbol const *_Nonnull
{
	Type const *_Nonnull const type_ = new_Type(FunctionType_, name_, bit_false);
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_ = new_system__collections__List<Symbol const *_Nonnull>();
	return new_Symbol__of_type(unqualified_name_(name_), type_, declarations_, children_);
}

auto build_namespace_symbol_(Name const *_Nonnull const name_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const symbols_) -> Symbol const *_Nonnull
{
	Type const *_Nonnull const type_ = new_Type__namespace(name_);
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	return new_Symbol__declaring(type_, declarations_, symbols_);
}

auto build_class_symbol_(Name const *_Nonnull const namespace_, str const class_name_) -> Symbol const *_Nonnull
{
	Type const *_Nonnull const type_ = new_Type(ReferenceType_, new_Name(namespace_, TypeName_, class_name_), bit_true);
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_ = new_system__collections__List<Symbol const *_Nonnull>();
	return new_Symbol__declaring(type_, declarations_, children_);
}

auto build_class_symbol_(Name const *_Nonnull const namespace_, str const class_name_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_) -> Symbol const *_Nonnull
{
	Type const *_Nonnull const type_ = new_Type(ReferenceType_, new_Name(namespace_, TypeName_, class_name_), bit_true);
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	return new_Symbol__declaring(type_, declarations_, children_);
}

auto build_generic_class_symbol_(Name const *_Nonnull const namespace_, str const class_name_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_) -> Symbol const *_Nonnull
{
	Type const *_Nonnull const type_ = new_Type(ReferenceType_, new_Name(namespace_, TypeName_, class_name_), type_parameters_, bit_true);
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_ = new_system__collections__List<Symbol const *_Nonnull>();
	return new_Symbol__declaring(type_, declarations_, children_);
}

auto build_constructor_symbol_(str const name_) -> Symbol const *_Nonnull
{
	str const constructor_name_ = str("new_").op_add(name_);
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	return new_Symbol__constructor(constructor_name_, declarations_);
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
	Package const *_Nonnull const package_ = build_runtime_library_package_();
	assert_(not_equal_op(get_child_(package_->symbol_, str("system"), IdentifierSymbol_), none), str(""));
}

auto System_namespace_contains_console_namespace_() -> void
{
	Package const *_Nonnull const package_ = build_runtime_library_package_();
	Symbol const *_Nonnull const system_namespace_ = get_child_(package_->symbol_, str("system"), IdentifierSymbol_);
	assert_(not_equal_op(get_child_(system_namespace_, str("console"), IdentifierSymbol_), none), str(""));
}

auto Console_namespace_contains_Console_class_() -> void
{
	Package const *_Nonnull const package_ = build_runtime_library_package_();
	Symbol const *_Nonnull const system_namespace_ = get_child_(package_->symbol_, str("system"), IdentifierSymbol_);
	Symbol const *_Nonnull const console_namespace_ = get_child_(system_namespace_, str("console"), IdentifierSymbol_);
	assert_(not_equal_op(get_child_(console_namespace_, str("Console"), IdentifierSymbol_), none), str(""));
}

auto System_namespace_contains_collections_namespace_() -> void
{
	Package const *_Nonnull const package_ = build_runtime_library_package_();
	Symbol const *_Nonnull const system_namespace_ = get_child_(package_->symbol_, str("system"), IdentifierSymbol_);
	assert_(not_equal_op(get_child_(system_namespace_, str("collections"), IdentifierSymbol_), none), str(""));
}

auto Collections_namespace_contains_List_class_() -> void
{
	Package const *_Nonnull const package_ = build_runtime_library_package_();
	Symbol const *_Nonnull const system_namespace_ = get_child_(package_->symbol_, str("system"), IdentifierSymbol_);
	Symbol const *_Nonnull const console_namespace_ = get_child_(system_namespace_, str("collections"), IdentifierSymbol_);
	assert_(not_equal_op(get_child_(console_namespace_, str("List"), IdentifierSymbol_), none), str(""));
}

auto analyze_semantics_(Syntax_Node const *_Nonnull const package_syntax_) -> Package const *_Nonnull
{
	assert_(equal_op(package_syntax_->kind_, PackageNode_), str("package_syntax.kind=").op_add(package_syntax_->kind_));
	Package_Name const *_Nonnull const name_ = new_Package_Name(str("default"));
	Package const *_Nonnull const primitives_package_ = build_primitives_package_();
	Package const *_Nonnull const runtime_package_ = build_runtime_library_package_();
	system__collections__List<Package_Reference> *_Nonnull const references_ = new_system__collections__List<Package_Reference>();
	references_->add_(new_Package_Reference(primitives_package_));
	references_->add_(new_Package_Reference(runtime_package_));
	Name_Table const *_Nonnull const name_table_ = build_name_table_(name_, package_syntax_, references_);
	Semantic_Tree_Builder const *_Nonnull const semantic_tree_builder_ = new_Semantic_Tree_Builder();
	system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_ = build_compilation_units_(semantic_tree_builder_, package_syntax_, name_table_);
	Symbol const *_Nonnull const package_symbol_ = build_symbols_(name_, compilation_units_);
	Package const *_Nonnull const package_ = new_Package(name_, references_, compilation_units_, package_symbol_);
	return package_;
}

Semantic_Node *_Nonnull c_Semantic_Node__token(Semantic_Node *_Nonnull self, Syntax_Node const *_Nonnull const syntax_)
{
	assert_(not_equal_op(syntax_, none), str(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	self->node_diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	self->of_type_ = none;
	self->converted_type_ = none;
	self->declares_type_ = none;
	self->referenced_type_ = none;
	return self;
}

inline Semantic_Node *_Nonnull new_Semantic_Node__token(Syntax_Node const *_Nonnull const syntax_)
{
	return c_Semantic_Node__token(new Semantic_Node(), syntax_);
}

Semantic_Node *_Nonnull c_Semantic_Node__concrete(Semantic_Node *_Nonnull self, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_)
{
	assert_(not_equal_op(syntax_, none), str(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = children_;
	self->node_diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	self->of_type_ = none;
	self->converted_type_ = none;
	self->declares_type_ = none;
	self->referenced_type_ = none;
	return self;
}

inline Semantic_Node *_Nonnull new_Semantic_Node__concrete(Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_)
{
	return c_Semantic_Node__concrete(new Semantic_Node(), syntax_, children_);
}

Semantic_Node *_Nonnull c_Semantic_Node__of_type(Semantic_Node *_Nonnull self, Type const *_Nonnull const of_type_, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_)
{
	assert_(not_equal_op(of_type_, none), str(""));
	assert_(not_equal_op(syntax_, none), str(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = children_;
	self->node_diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	self->of_type_ = of_type_;
	self->converted_type_ = of_type_;
	self->declares_type_ = none;
	self->referenced_type_ = none;
	return self;
}

inline Semantic_Node *_Nonnull new_Semantic_Node__of_type(Type const *_Nonnull const of_type_, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_)
{
	return c_Semantic_Node__of_type(new Semantic_Node(), of_type_, syntax_, children_);
}

Semantic_Node *_Nonnull c_Semantic_Node__declares_type(Semantic_Node *_Nonnull self, Type const *_Nonnull const type_, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_)
{
	assert_(not_equal_op(type_, none), str(""));
	assert_(not_equal_op(syntax_, none), str(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = children_;
	self->node_diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	self->of_type_ = none;
	self->converted_type_ = none;
	self->declares_type_ = type_;
	self->referenced_type_ = none;
	return self;
}

inline Semantic_Node *_Nonnull new_Semantic_Node__declares_type(Type const *_Nonnull const type_, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_)
{
	return c_Semantic_Node__declares_type(new Semantic_Node(), type_, syntax_, children_);
}

Semantic_Node *_Nonnull c_Semantic_Node__referencing_type(Semantic_Node *_Nonnull self, Type const *_Nonnull const type_, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_)
{
	assert_(not_equal_op(type_, none), str(""));
	assert_(not_equal_op(syntax_, none), str(""));
	self->syntax_ = syntax_;
	self->kind_ = syntax_->kind_;
	self->is_missing_ = syntax_->is_missing_;
	self->source_ = syntax_->source_;
	self->start_ = syntax_->start_;
	self->byte_length_ = syntax_->byte_length_;
	self->children_ = children_;
	self->node_diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	self->of_type_ = none;
	self->converted_type_ = none;
	self->declares_type_ = none;
	self->referenced_type_ = type_;
	return self;
}

inline Semantic_Node *_Nonnull new_Semantic_Node__referencing_type(Type const *_Nonnull const type_, Syntax_Node const *_Nonnull const syntax_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children_)
{
	return c_Semantic_Node__referencing_type(new Semantic_Node(), type_, syntax_, children_);
}

auto get_text_span_(Semantic_Node const *_Nonnull const node_) -> Text_Span const *_Nonnull
{
	return new_Text_Span(node_->start_, node_->byte_length_);
}

auto get_text_(Semantic_Node const *_Nonnull const node_) -> str
{
	if (cond(equal_op(node_->source_, none)))
	{
		return str("$No Source$");
	}

	return node_->source_->text_.Substring_(node_->start_, node_->byte_length_);
}

auto first_child_(Semantic_Node const *_Nonnull const node_, i32 const kind_) -> Semantic_Node const *_Nullable
{
	for (Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		if (cond(equal_op(child_->kind_, kind_)))
		{
			return child_;
		}
	}

	return none;
}

auto children_of_kind_(Semantic_Node const *_Nonnull const node_, i32 const kind_) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull
{
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	for (Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		if (cond(equal_op(child_->kind_, kind_)))
		{
			children_->add_(child_);
		}
	}

	return children_;
}

auto node_members_(Semantic_Node const *_Nonnull const node_) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull
{
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const members_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	for (Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		if (cond(bit_op(bit_arg(bit_op(bit_arg(equal_op(child_->kind_, ConstructorDeclaration_)) || bit_arg(equal_op(child_->kind_, FieldDeclaration_)))) || bit_arg(equal_op(child_->kind_, MethodDeclaration_)))))
		{
			members_->add_(child_);
		}
	}

	return members_;
}

auto node_statements_(Semantic_Node const *_Nonnull const node_) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull
{
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const statements_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	for (Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		if (cond(bit_op(bit_arg(not_equal_op(child_->kind_, LeftBrace_)) && bit_arg(not_equal_op(child_->kind_, RightBrace_)))))
		{
			statements_->add_(child_);
		}
	}

	return statements_;
}

auto node_parameters_(Semantic_Node const *_Nonnull const node_) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull
{
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const parameters_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	for (Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		if (cond(bit_op(bit_arg(equal_op(child_->kind_, Parameter_)) || bit_arg(equal_op(child_->kind_, SelfParameter_)))))
		{
			parameters_->add_(child_);
		}
	}

	return parameters_;
}

auto node_access_modifier_(Semantic_Node const *_Nonnull const node_) -> Semantic_Node const *_Nullable
{
	for (Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(child_->kind_, PublicKeyword_)) || bit_arg(equal_op(child_->kind_, ProtectedKeyword_)))) || bit_arg(equal_op(child_->kind_, PrivateKeyword_)))) || bit_arg(equal_op(child_->kind_, InternalKeyword_)))))
		{
			return child_;
		}
	}

	return none;
}

auto node_has_child_(Semantic_Node const *_Nonnull const node_, i32 const kind_) -> bit
{
	for (Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		if (cond(equal_op(child_->kind_, kind_)))
		{
			return bit_true;
		}
	}

	return bit_false;
}

auto add_diagnostic_(Semantic_Node *_Nonnull const node_, Diagnostic const *_Nonnull const diagnostic_) -> void
{
	node_->node_diagnostics_->add_(diagnostic_);
}

auto diagnostics_(Semantic_Node const *_Nonnull const node_) -> system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull
{
	return node_->node_diagnostics_;
}

auto collect_diagnostics_(Semantic_Node const *_Nonnull const node_, system__collections__List<Diagnostic const *_Nonnull> *_Nonnull const diagnostics_) -> void
{
	for (Diagnostic const *_Nonnull const diagnostic_ : *(node_->node_diagnostics_))
	{
		diagnostics_->add_(diagnostic_);
	}

	for (Semantic_Node const *_Nonnull const child_ : *(node_->children_))
	{
		collect_diagnostics_(child_, diagnostics_);
	}
}

Semantic_Tree_Builder *_Nonnull c_Semantic_Tree_Builder(Semantic_Tree_Builder *_Nonnull self)
{
	Package_Name const *_Nonnull const primitives_package_ = new_Package_Name(str("$primitives"));
	Name const *_Nonnull const global_namespace_ = new_Name__global_namespace(primitives_package_);
	Name const *_Nonnull const adamant_namespace_ = new_Name(global_namespace_, NamespaceName_, str("adamant"));
	Name const *_Nonnull const language_namespace_ = new_Name(adamant_namespace_, NamespaceName_, str("language"));
	self->optional_type_name_ = new_Name(language_namespace_, TypeName_, str("optional"));
	return self;
}

inline Semantic_Tree_Builder *_Nonnull new_Semantic_Tree_Builder()
{
	return c_Semantic_Tree_Builder(new Semantic_Tree_Builder());
}

auto build_compilation_units_(Semantic_Tree_Builder const *_Nonnull const builder_, Syntax_Node const *_Nonnull const package_syntax_, Name_Table const *_Nonnull const name_table_) -> system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull
{
	assert_(equal_op(package_syntax_->kind_, PackageNode_), str("package_syntax.kind=").op_add(package_syntax_->kind_));
	assert_(not_equal_op(lookup_special_(name_table_->any_package_, str("string")), none), str("name_table.any_package.name=").op_add(full_name_(name_table_->any_package_->name_)));
	system__collections__List<Compilation_Unit const *_Nonnull> *_Nonnull const compilation_units_ = new_system__collections__List<Compilation_Unit const *_Nonnull>();
	for (Syntax_Node const *_Nonnull const compilation_unit_syntax_ : *(package_syntax_->children_))
	{
		compilation_units_->add_(build_compilation_unit_semantic_node_(builder_, compilation_unit_syntax_, name_table_));
	}

	return compilation_units_;
}

auto build_compilation_unit_semantic_node_(Semantic_Tree_Builder const *_Nonnull const builder_, Syntax_Node const *_Nonnull const compilation_unit_syntax_, Name_Table const *_Nonnull const name_table_) -> Compilation_Unit const *_Nonnull
{
	assert_(equal_op(compilation_unit_syntax_->kind_, CompilationUnit_), str("compilation_unit_syntax.kind=").op_add(compilation_unit_syntax_->kind_));
	Name_Subtable const *_Nonnull const scope_ = none;
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const declarations_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	for (Syntax_Node const *_Nonnull const declaration_syntax_ : *(compilation_unit_syntax_->children_))
	{
		declarations_->add_(build_semantic_node_(builder_, declaration_syntax_, name_table_, name_table_->any_package_));
	}

	return new_Compilation_Unit(compilation_unit_syntax_, declarations_);
}

auto build_semantic_node_(Semantic_Tree_Builder const *_Nonnull const builder_, Syntax_Node const *_Nonnull const syntax_, Name_Table const *_Nonnull const name_table_, Name_Subtable const *_Nonnull const scope_) -> Semantic_Node const *_Nonnull
{
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, FunctionDeclaration_)) || bit_arg(equal_op(syntax_->kind_, MethodDeclaration_)))))
	{
		children_->add_(build_semantic_node_(builder_, access_modifier_(syntax_), name_table_, scope_));
		Syntax_Node const *_Nonnull const function_name_ = first_child_syntax_(syntax_, Identifier_);
		children_->add_(build_semantic_node_(builder_, function_name_, name_table_, scope_));
		Name_Subtable *_Nonnull const function_scope_ = find_(scope_, get_text_(function_name_));
		assert_(not_equal_op(function_scope_, none), str("get_text(function_name)=").op_add(get_text_(function_name_)));
		Syntax_Node const *_Nonnull const parameters_ = first_child_syntax_(syntax_, ParameterList_);
		children_->add_(build_parameters_semantic_node_(builder_, parameters_, name_table_, function_scope_));
		Syntax_Node const *_Nonnull const return_type_ = syntax_->children_->op_Element(i32(4));
		children_->add_(build_type_name_semantic_node_(builder_, return_type_, name_table_, scope_));
		Type const *_Nonnull const function_type_ = new_Type(FunctionType_, function_scope_->name_, bit_false);
		bind_type_(function_scope_, function_type_);
		Syntax_Node const *_Nonnull const body_ = first_child_syntax_(syntax_, Block_);
		if (cond(not_equal_op(body_, none)))
		{
			children_->add_(build_semantic_node_(builder_, body_, name_table_, function_scope_));
		}

		return new_Semantic_Node__concrete(syntax_, children_);
	}
	else if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, ClassDeclaration_)) || bit_arg(equal_op(syntax_->kind_, StructDeclaration_)))))
	{
		Syntax_Node const *_Nonnull const type_name_ = first_child_syntax_(syntax_, Identifier_);
		children_->add_(build_semantic_node_(builder_, type_name_, name_table_, scope_));
		Name_Subtable const *_Nonnull const type_scope_ = find_(scope_, get_text_(type_name_));
		assert_(not_equal_op(type_scope_, none), str("get_text(type_name)=").op_add(get_text_(type_name_)));
		for (Syntax_Node const *_Nonnull const member_ : *(members_(syntax_)))
		{
			children_->add_(build_semantic_node_(builder_, member_, name_table_, type_scope_));
		}

		return new_Semantic_Node__declares_type(type_scope_->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, ConstructorDeclaration_)))
	{
		children_->add_(build_semantic_node_(builder_, access_modifier_(syntax_), name_table_, scope_));
		str full_name_ = str("new");
		Syntax_Node const *_Nullable const constructor_name_ = first_child_syntax_(syntax_, Identifier_);
		if (cond(not_equal_op(constructor_name_, none)))
		{
			full_name_ = str("new_").op_add(get_text_(constructor_name_));
			children_->add_(new_Semantic_Node__token(constructor_name_));
		}

		Name_Subtable const *_Nonnull const constructor_scope_ = find_special_(scope_, full_name_);
		assert_(not_equal_op(constructor_scope_, none), str("full_name=").op_add(full_name_));
		Syntax_Node const *_Nonnull const parameters_ = first_child_syntax_(syntax_, ParameterList_);
		children_->add_(build_parameters_semantic_node_(builder_, parameters_, name_table_, constructor_scope_));
		Syntax_Node const *_Nonnull const body_ = first_child_syntax_(syntax_, Block_);
		if (cond(not_equal_op(body_, none)))
		{
			children_->add_(build_semantic_node_(builder_, body_, name_table_, constructor_scope_));
		}

		return new_Semantic_Node__concrete(syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, IdentifierName_)))
	{
		Name_Subtable const *_Nonnull const name_scope_ = lookup_(scope_, get_text_(syntax_));
		if (cond(equal_op(name_scope_, none)))
		{
			Semantic_Node *_Nonnull const node_ = new_Semantic_Node__token(syntax_);
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
				return new_Semantic_Node__concrete(syntax_, children_);
			}
			else
			{
				return new_Semantic_Node__of_type(name_scope_->type_, syntax_, children_);
			}
		}
	}
	else if (cond(equal_op(syntax_->kind_, MemberAccessExpression_)))
	{
		Semantic_Node const *_Nonnull const lhs_ = build_semantic_node_(builder_, syntax_->children_->op_Element(i32(0)), name_table_, scope_);
		children_->add_(lhs_);
		Semantic_Node *_Nonnull rhs_;
		Syntax_Node const *_Nonnull const member_name_ = syntax_->children_->op_Element(i32(2));
		if (cond(equal_op(lhs_->of_type_, none)))
		{
			rhs_ = new_Semantic_Node__token(member_name_);
		}
		else
		{
			Name_Subtable const *_Nonnull const access_scope_ = get_name_(name_table_, lhs_->of_type_->name_);
			Name_Subtable const *_Nonnull const member_scope_ = find_(access_scope_, get_text_(member_name_));
			if (cond(equal_op(member_scope_, none)))
			{
				rhs_ = new_Semantic_Node__token(member_name_);
			}
			else
			{
				system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const no_children_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
				if (cond(equal_op(member_scope_->type_, none)))
				{
					rhs_ = new_Semantic_Node__token(member_name_);
				}
				else
				{
					rhs_ = new_Semantic_Node__of_type(member_scope_->type_, member_name_, no_children_);
				}
			}
		}

		children_->add_(rhs_);
		if (cond(equal_op(rhs_->of_type_, none)))
		{
			return new_Semantic_Node__concrete(syntax_, children_);
		}
		else
		{
			return new_Semantic_Node__of_type(rhs_->of_type_, syntax_, children_);
		}
	}
	else if (cond(equal_op(syntax_->kind_, NewExpression_)))
	{
		children_->add_(build_constructor_name_semantic_node_(builder_, syntax_->children_->op_Element(i32(1)), name_table_, scope_));
		children_->add_(build_semantic_node_(builder_, first_child_syntax_(syntax_, ArgumentList_), name_table_, scope_));
		return new_Semantic_Node__concrete(syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, LocalDeclarationStatement_)))
	{
		Syntax_Node const *_Nonnull const variable_declaration_syntax_ = first_child_syntax_(syntax_, VariableDeclaration_);
		children_->add_(build_semantic_node_(builder_, variable_declaration_syntax_, name_table_, scope_));
		return new_Semantic_Node__concrete(syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, VariableDeclaration_)))
	{
		Syntax_Node const *_Nonnull const binding_syntax_ = syntax_->children_->op_Element(i32(0));
		children_->add_(new_Semantic_Node__token(binding_syntax_));
		Syntax_Node const *_Nonnull const identifier_ = first_child_syntax_(syntax_, Identifier_);
		children_->add_(new_Semantic_Node__token(identifier_));
		Syntax_Node const *_Nonnull const type_syntax_ = syntax_->children_->op_Element(i32(3));
		Semantic_Node const *_Nonnull const type_node_ = build_type_name_semantic_node_(builder_, type_syntax_, name_table_, scope_);
		assert_(not_equal_op(type_node_->referenced_type_, none), get_text_(type_node_));
		Name_Subtable *_Nonnull const variable_scope_ = lookup_(scope_, get_text_(identifier_));
		assert_(not_equal_op(variable_scope_, none), get_text_(syntax_));
		bind_type_(variable_scope_, type_node_->referenced_type_);
		bind_type_(as_mut_(get_name_(name_table_, variable_scope_->name_)), type_node_->referenced_type_);
		children_->add_(type_node_);
		if (cond(equal_op(syntax_->children_->op_magnitude(), i32(6))))
		{
			Syntax_Node const *_Nonnull const initalizer_ = syntax_->children_->op_Element(i32(5));
			children_->add_(build_semantic_node_(builder_, initalizer_, name_table_, scope_));
		}

		return new_Semantic_Node__concrete(syntax_, children_);
	}
	else if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, TrueLiteralExpression_)) || bit_arg(equal_op(syntax_->kind_, FalseLiteralExpression_)))))
	{
		return new_Semantic_Node__of_type(lookup_special_(scope_, str("bool"))->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, StringLiteralExpression_)))
	{
		return new_Semantic_Node__of_type(lookup_special_(scope_, str("string"))->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, CodePointLiteralExpression_)))
	{
		return new_Semantic_Node__of_type(lookup_special_(scope_, str("code_point"))->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, NumericLiteralExpression_)))
	{
		return new_Semantic_Node__of_type(lookup_special_(scope_, str("int"))->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->children_->op_magnitude(), i32(0))))
	{
		return new_Semantic_Node__token(syntax_);
	}
	else
	{
		for (Syntax_Node const *_Nonnull const child_syntax_ : *(syntax_->children_))
		{
			children_->add_(build_semantic_node_(builder_, child_syntax_, name_table_, scope_));
		}

		return new_Semantic_Node__concrete(syntax_, children_);
	}
}

auto build_parameters_semantic_node_(Semantic_Tree_Builder const *_Nonnull const builder_, Syntax_Node const *_Nonnull const parameters_syntax_, Name_Table const *_Nonnull const name_table_, Name_Subtable const *_Nonnull const scope_) -> Semantic_Node *_Nonnull
{
	assert_(equal_op(parameters_syntax_->kind_, ParameterList_), str("parameters_syntax.kind=").op_add(parameters_syntax_->kind_));
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const parameter_nodes_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	for (Syntax_Node const *_Nonnull const parameter_ : *(parameters_(parameters_syntax_)))
	{
		system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
		if (cond(equal_op(parameter_->kind_, Parameter_)))
		{
			Syntax_Node const *_Nullable const var_syntax_ = first_child_syntax_(parameter_, VarKeyword_);
			if (cond(not_equal_op(var_syntax_, none)))
			{
				children_->add_(new_Semantic_Node__token(var_syntax_));
			}

			Syntax_Node const *_Nonnull const identifier_ = first_child_syntax_(parameter_, Identifier_);
			children_->add_(new_Semantic_Node__token(identifier_));
			Syntax_Node const *_Nonnull const type_syntax_ = parameter_->children_->op_Element(parameter_->children_->op_magnitude()->op_subtract(i32(1)));
			Semantic_Node const *_Nonnull const type_node_ = build_type_name_semantic_node_(builder_, type_syntax_, name_table_, scope_);
			assert_(not_equal_op(type_node_->referenced_type_, none), get_text_(parameter_));
			children_->add_(type_node_);
			Name_Subtable *_Nonnull const parameter_scope_ = lookup_(scope_, get_text_(identifier_));
			assert_(not_equal_op(parameter_scope_, none), get_text_(identifier_));
			bind_type_(parameter_scope_, type_node_->referenced_type_);
			parameter_nodes_->add_(new_Semantic_Node__of_type(type_node_->referenced_type_, parameter_, children_));
		}
		else if (cond(equal_op(parameter_->kind_, SelfParameter_)))
		{
			for (Syntax_Node const *_Nonnull const child_syntax_ : *(parameter_->children_))
			{
				children_->add_(new_Semantic_Node__token(child_syntax_));
			}

			parameter_nodes_->add_(new_Semantic_Node__concrete(parameter_, children_));
		}
		else
		{
			NOT_IMPLEMENTED_(str("parameter.kind=").op_add(parameter_->kind_));
		}
	}

	return new_Semantic_Node__concrete(parameters_syntax_, parameter_nodes_);
}

auto build_type_name_semantic_node_(Semantic_Tree_Builder const *_Nonnull const builder_, Syntax_Node const *_Nonnull const syntax_, Name_Table const *_Nonnull const name_table_, Name_Subtable const *_Nonnull const scope_) -> Semantic_Node *_Nonnull
{
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	if (cond(equal_op(syntax_->kind_, PredefinedType_)))
	{
		str const primitive_name_ = get_text_(syntax_->children_->op_Element(i32(0)));
		Name_Subtable const *_Nullable const primitive_entry_ = lookup_special_(scope_, primitive_name_);
		assert_(not_equal_op(primitive_entry_, none), str("No entry for primitive `").op_add(primitive_name_)->op_add(str("`")));
		return new_Semantic_Node__referencing_type(primitive_entry_->type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, IdentifierName_)))
	{
		if (cond(syntax_->is_missing_))
		{
			return new_Semantic_Node__token(syntax_);
		}

		str const name_ = get_text_(syntax_);
		Name_Subtable const *_Nullable const entry_ = lookup_(scope_, name_);
		if (cond(equal_op(entry_, none)))
		{
			Semantic_Node *_Nonnull const node_ = new_Semantic_Node__token(syntax_);
			add_resolution_error_(node_);
			return node_;
		}
		else
		{
			return new_Semantic_Node__referencing_type(entry_->type_, syntax_, children_);
		}
	}
	else if (cond(equal_op(syntax_->kind_, QualifiedName_)))
	{
		Syntax_Node const *_Nonnull const qualifier_syntax_ = syntax_->children_->op_Element(i32(0));
		Semantic_Node *_Nonnull const qualifier_ = build_type_name_semantic_node_(builder_, qualifier_syntax_, name_table_, scope_);
		children_->add_(qualifier_);
		Syntax_Node const *_Nonnull const qualified_syntax_ = syntax_->children_->op_Element(i32(2));
		if (cond(equal_op(qualified_syntax_->kind_, IdentifierName_)))
		{
			Syntax_Node const *_Nonnull const name_syntax_ = qualified_syntax_;
			if (cond(equal_op(qualifier_->referenced_type_, none)))
			{
				add_could_not_determine_type_error_(qualifier_);
				Semantic_Node *_Nonnull const name_node_ = new_Semantic_Node__token(name_syntax_);
				add_resolution_error_(name_node_, qualifier_);
				children_->add_(name_node_);
				return new_Semantic_Node__concrete(syntax_, children_);
			}
			else
			{
				Type const *_Nonnull const containing_type_ = qualifier_->referenced_type_;
				Name_Subtable const *_Nonnull const containing_scope_ = get_name_(name_table_, containing_type_->name_);
				assert_(not_equal_op(containing_scope_, none), full_name_(containing_type_->name_));
				Name_Subtable const *_Nonnull const referenced_scope_ = find_(containing_scope_, get_text_(name_syntax_));
				if (cond(equal_op(referenced_scope_, none)))
				{
					Semantic_Node *_Nonnull const name_node_ = new_Semantic_Node__token(name_syntax_);
					add_resolution_error_(name_node_, qualifier_);
					children_->add_(name_node_);
					return new_Semantic_Node__concrete(syntax_, children_);
				}

				Type const *_Nonnull const referenced_type_ = referenced_scope_->type_;
				Semantic_Node const *_Nonnull const name_node_ = new_Semantic_Node__referencing_type(referenced_type_, name_syntax_, new_system__collections__List<Semantic_Node const *_Nonnull>());
				children_->add_(name_node_);
				return new_Semantic_Node__referencing_type(referenced_type_, syntax_, children_);
			}
		}
		else if (cond(equal_op(qualified_syntax_->kind_, GenericName_)))
		{
			Syntax_Node const *_Nonnull const name_syntax_ = first_child_syntax_(qualified_syntax_, IdentifierName_);
			system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const generic_name_children_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
			if (cond(equal_op(qualifier_->referenced_type_, none)))
			{
				add_could_not_determine_type_error_(qualifier_);
				Semantic_Node *_Nonnull const name_node_ = new_Semantic_Node__token(name_syntax_);
				add_resolution_error_(name_node_, qualifier_);
				generic_name_children_->add_(name_node_);
				build_type_arguments_semantic_node_(builder_, qualified_syntax_, name_table_, scope_, generic_name_children_);
				Semantic_Node *_Nonnull const qualified_name_ = new_Semantic_Node__concrete(qualified_syntax_, generic_name_children_);
				children_->add_(qualified_name_);
				return new_Semantic_Node__concrete(syntax_, children_);
			}
			else
			{
				Type const *_Nonnull const containing_type_ = qualifier_->referenced_type_;
				Name_Subtable const *_Nonnull const containing_scope_ = get_name_(name_table_, containing_type_->name_);
				assert_(not_equal_op(containing_scope_, none), full_name_(containing_type_->name_));
				Name_Subtable const *_Nonnull const referenced_scope_ = find_(containing_scope_, get_text_(name_syntax_));
				if (cond(equal_op(referenced_scope_, none)))
				{
					Semantic_Node *_Nonnull const name_node_ = new_Semantic_Node__token(name_syntax_);
					add_resolution_error_(name_node_, qualifier_);
					generic_name_children_->add_(name_node_);
					build_type_arguments_semantic_node_(builder_, qualified_syntax_, name_table_, scope_, generic_name_children_);
					Semantic_Node *_Nonnull const qualified_name_ = new_Semantic_Node__concrete(qualified_syntax_, generic_name_children_);
					children_->add_(qualified_name_);
					return new_Semantic_Node__concrete(syntax_, children_);
				}

				Type const *_Nonnull const referenced_type_name_ = referenced_scope_->type_;
				Semantic_Node const *_Nonnull const name_node_ = new_Semantic_Node__referencing_type(referenced_type_name_, name_syntax_, new_system__collections__List<Semantic_Node const *_Nonnull>());
				generic_name_children_->add_(name_node_);
				system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_ = build_type_arguments_semantic_node_(builder_, qualified_syntax_, name_table_, scope_, generic_name_children_);
				Type const *_Nonnull const referenced_type_ = new_Type__generic(referenced_type_name_, type_parameters_);
				Semantic_Node *_Nonnull const qualified_name_ = new_Semantic_Node__referencing_type(referenced_type_, qualified_syntax_, generic_name_children_);
				children_->add_(qualified_name_);
				return new_Semantic_Node__referencing_type(referenced_type_, syntax_, children_);
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
		Semantic_Node *_Nonnull const inner_type_ = build_type_name_semantic_node_(builder_, syntax_->children_->op_Element(i32(1)), name_table_, scope_);
		children_->add_(inner_type_);
		if (cond(equal_op(inner_type_->referenced_type_, none)))
		{
			add_could_not_determine_type_error_(inner_type_);
			return new_Semantic_Node__concrete(syntax_, children_);
		}

		Type const *_Nonnull const type_ = make_mutable_type_(inner_type_->referenced_type_);
		return new_Semantic_Node__referencing_type(type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, ImmutableType_)))
	{
		Semantic_Node *_Nonnull const inner_type_ = build_type_name_semantic_node_(builder_, syntax_->children_->op_Element(i32(0)), name_table_, scope_);
		children_->add_(inner_type_);
		if (cond(equal_op(inner_type_->referenced_type_, none)))
		{
			add_could_not_determine_type_error_(inner_type_);
			return new_Semantic_Node__concrete(syntax_, children_);
		}

		Type const *_Nonnull const type_ = make_immutable_type_(inner_type_->referenced_type_);
		return new_Semantic_Node__referencing_type(type_, syntax_, children_);
	}
	else if (cond(equal_op(syntax_->kind_, OptionalType_)))
	{
		Semantic_Node *_Nonnull const inner_type_ = build_type_name_semantic_node_(builder_, syntax_->children_->op_Element(i32(0)), name_table_, scope_);
		children_->add_(inner_type_);
		if (cond(equal_op(inner_type_->referenced_type_, none)))
		{
			add_could_not_determine_type_error_(inner_type_);
			return new_Semantic_Node__concrete(syntax_, children_);
		}

		Name_Subtable const *_Nullable const optional_type_scope_ = get_name_(name_table_, builder_->optional_type_name_);
		assert_(not_equal_op(optional_type_scope_, none), str(""));
		Type const *_Nonnull const optional_type_ = optional_type_scope_->type_;
		system__collections__List<Type const *_Nonnull> *_Nonnull const type_arguments_ = new_system__collections__List<Type const *_Nonnull>();
		type_arguments_->add_(inner_type_->referenced_type_);
		Type const *_Nonnull const type_ = new_Type__generic(optional_type_, type_arguments_);
		return new_Semantic_Node__referencing_type(type_, syntax_, children_);
	}
	else
	{
		i32 const place_ = syntax_->start_;
		NOT_IMPLEMENTED_(str("syntax.kind=").op_add(syntax_->kind_)->op_add(str(" at "))->op_add(place_));
	}
}

auto build_type_arguments_semantic_node_(Semantic_Tree_Builder const *_Nonnull const builder_, Syntax_Node const *_Nonnull const syntax_, Name_Table const *_Nonnull const name_table_, Name_Subtable const *_Nonnull const scope_, system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const children_) -> system__collections__List<Type const *_Nonnull> const *_Nonnull
{
	system__collections__List<Type const *_Nonnull> *_Nonnull const type_parameters_ = new_system__collections__List<Type const *_Nonnull>();
	if (cond(equal_op(syntax_->kind_, IdentifierName_)))
	{
		return type_parameters_;
	}

	assert_(equal_op(syntax_->kind_, GenericName_), str("syntax.kind==").op_add(syntax_->kind_));
	bit in_type_arguments_ = bit_false;
	for (Syntax_Node const *_Nonnull const type_argument_ : *(syntax_->children_))
	{
		if (cond(in_type_arguments_))
		{
			if (cond(not_equal_op(type_argument_->kind_, GreaterThan_)))
			{
				Semantic_Node const *_Nonnull const type_node_ = build_type_name_semantic_node_(builder_, type_argument_, name_table_, scope_);
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

auto build_constructor_name_semantic_node_(Semantic_Tree_Builder const *_Nonnull const builder_, Syntax_Node const *_Nonnull const syntax_, Name_Table const *_Nonnull const name_table_, Name_Subtable const *_Nonnull const scope_) -> Semantic_Node const *_Nonnull
{
	if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, QualifiedName_)) && bit_arg(equal_op(syntax_->children_->op_Element(i32(2))->kind_, IdentifierName_)))))
	{
		system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
		Semantic_Node const *_Nonnull const type_node_ = build_type_name_semantic_node_(builder_, syntax_->children_->op_Element(i32(0)), name_table_, scope_);
		children_->add_(type_node_);
		Syntax_Node const *_Nonnull const qualifier_ = syntax_->children_->op_Element(i32(0));
		Syntax_Node const *_Nonnull const name_ = syntax_->children_->op_Element(i32(2));
		str const constructor_name_ = str("new_").op_add(get_text_(name_));
		Type const *_Nonnull const referenced_type_ = type_node_->referenced_type_;
		assert_(not_equal_op(referenced_type_, none), str("no referenced type for `").op_add(get_text_(type_node_))->op_add(str("`")));
		Name_Subtable const *_Nullable const constructor_scope_ = lookup_special_(get_name_(name_table_, referenced_type_->name_), constructor_name_);
		if (cond(not_equal_op(constructor_scope_, none)))
		{
			children_->add_(new_Semantic_Node__token(name_));
			return new_Semantic_Node__concrete(syntax_, children_);
		}
	}

	return build_type_name_semantic_node_(builder_, syntax_, name_table_, scope_);
}

auto add_resolution_error_(Semantic_Node *_Nonnull const node_) -> void
{
	add_diagnostic_(node_, new_Diagnostic(FatalCompilationError_, Analysis_, node_->source_, get_text_span_(node_), str("Could not resolve name `").op_add(get_text_(node_))->op_add(str("`"))));
}

auto add_resolution_error_(Semantic_Node *_Nonnull const node_, Semantic_Node const *_Nonnull const qualifier_) -> void
{
	add_diagnostic_(node_, new_Diagnostic(FatalCompilationError_, Analysis_, node_->source_, get_text_span_(node_), str("Could not resolve name `").op_add(get_text_(node_))->op_add(str("` because qualifier `"))->op_add(get_text_(qualifier_))->op_add(str("` could not be resolved."))));
}

auto add_could_not_determine_type_error_(Semantic_Node *_Nonnull const node_) -> void
{
	add_diagnostic_(node_, new_Diagnostic(FatalCompilationError_, Analysis_, node_->source_, get_text_span_(node_), str("Could not determine type for `").op_add(get_text_(node_))->op_add(str("`"))));
}

auto build_symbols_(Package_Name const *_Nonnull const package_name_, system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units_) -> Symbol const *_Nonnull
{
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const symbols_ = new_system__collections__List<Symbol const *_Nonnull>();
	return new_Symbol__package(package_name_->unqualified_, symbols_);
}

Compilation_Unit_Parser *_Nonnull c_Compilation_Unit_Parser(Compilation_Unit_Parser *_Nonnull self, Token_Stream *_Nonnull const token_stream_)
{
	self->token_stream_ = token_stream_;
	self->compilation_unit_ = none;
	return self;
}

inline Compilation_Unit_Parser *_Nonnull new_Compilation_Unit_Parser(Token_Stream *_Nonnull const token_stream_)
{
	return c_Compilation_Unit_Parser(new Compilation_Unit_Parser(), token_stream_);
}

auto parse_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull
{
	if (cond(equal_op(parser_->compilation_unit_, none)))
	{
		parser_->token_ = next_token_(parser_->token_stream_);
		parser_->compilation_unit_ = parse_compilation_unit_(parser_);
	}

	return parser_->compilation_unit_;
}

auto accept_token_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nullable
{
	Syntax_Node const *_Nullable const node_ = parser_->token_;
	parser_->token_ = next_token_(parser_->token_stream_);
	return node_;
}

auto expect_token_(Compilation_Unit_Parser *_Nonnull const parser_, i32 const tokenType_) -> Syntax_Node const *_Nonnull
{
	if (cond(equal_op(parser_->token_, none)))
	{
		return new_Syntax_Node__missing(tokenType_, parser_->token_stream_->source_, source_byte_length_(parser_->token_stream_->source_));
	}

	if (cond(bit_op(bit_arg(equal_op(parser_->token_, none)) || bit_arg(not_equal_op(parser_->token_->kind_, tokenType_)))))
	{
		return new_Syntax_Node__missing(tokenType_, parser_->token_stream_->source_, parser_->token_->start_);
	}

	Syntax_Node const *_Nullable const node_ = parser_->token_;
	parser_->token_ = next_token_(parser_->token_stream_);
	return node_;
}

auto parse_type_name_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull
{
	if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(parser_->token_->kind_, CodePoint_)) || bit_arg(equal_op(parser_->token_->kind_, String_)))) || bit_arg(equal_op(parser_->token_->kind_, Int_)))) || bit_arg(equal_op(parser_->token_->kind_, Bool_)))) || bit_arg(equal_op(parser_->token_->kind_, Void_)))) || bit_arg(equal_op(parser_->token_->kind_, UnsignedInt_)))))
	{
		return new_Syntax_Node(PredefinedType_, accept_token_(parser_));
	}
	else
	{
		Syntax_Node const *_Nonnull type_ = new_Syntax_Node(IdentifierName_, expect_token_(parser_, Identifier_));
		while (cond(equal_op(parser_->token_->kind_, Dot_)))
		{
			system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
			children_->add_(type_);
			children_->add_(expect_token_(parser_, Dot_));
			Syntax_Node const *_Nonnull const identifier_ = expect_token_(parser_, Identifier_);
			if (cond(equal_op(parser_->token_->kind_, LessThan_)))
			{
				system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const genericNameChildren_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
				genericNameChildren_->add_(new_Syntax_Node(IdentifierName_, identifier_));
				genericNameChildren_->add_(expect_token_(parser_, LessThan_));
				genericNameChildren_->add_(parse_type_(parser_));
				genericNameChildren_->add_(expect_token_(parser_, GreaterThan_));
				children_->add_(new_Syntax_Node(GenericName_, genericNameChildren_));
			}
			else
			{
				children_->add_(new_Syntax_Node(IdentifierName_, identifier_));
			}

			type_ = new_Syntax_Node(QualifiedName_, children_);
		}

		return type_;
	}
}

auto parse_non_optional_type_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	if (cond(equal_op(parser_->token_->kind_, MutableKeyword_)))
	{
		children_->add_(expect_token_(parser_, MutableKeyword_));
		children_->add_(parse_type_name_(parser_));
		return new_Syntax_Node(MutableType_, children_);
	}
	else
	{
		children_->add_(parse_type_name_(parser_));
		return new_Syntax_Node(ImmutableType_, children_);
	}
}

auto parse_type_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull
{
	Syntax_Node const *_Nonnull type_ = parse_non_optional_type_(parser_);
	while (cond(equal_op(parser_->token_->kind_, Question_)))
	{
		system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
		children_->add_(type_);
		children_->add_(expect_token_(parser_, Question_));
		type_ = new_Syntax_Node(ImmutableType_, new_Syntax_Node(OptionalType_, children_));
	}

	return type_;
}

auto parse_atom_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	if (cond(equal_op(parser_->token_->kind_, NewKeyword_)))
	{
		children_->add_(expect_token_(parser_, NewKeyword_));
		children_->add_(parse_type_name_(parser_));
		children_->add_(parse_call_arguments_(parser_));
		return new_Syntax_Node(NewExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, NotOperator_)))
	{
		children_->add_(expect_token_(parser_, NotOperator_));
		children_->add_(parse_expression_(parser_, i32(8)));
		return new_Syntax_Node(NotExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, LeftParen_)))
	{
		children_->add_(expect_token_(parser_, LeftParen_));
		children_->add_(parse_expression_(parser_));
		children_->add_(expect_token_(parser_, RightParen_));
		return new_Syntax_Node(ParenthesizedExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, Pipe_)))
	{
		children_->add_(expect_token_(parser_, Pipe_));
		children_->add_(parse_expression_(parser_));
		children_->add_(expect_token_(parser_, Pipe_));
		return new_Syntax_Node(MagnitudeExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, Minus_)))
	{
		children_->add_(expect_token_(parser_, Minus_));
		children_->add_(parse_expression_(parser_, i32(8)));
		return new_Syntax_Node(NegateExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, NoneKeyword_)))
	{
		children_->add_(expect_token_(parser_, NoneKeyword_));
		return new_Syntax_Node(NoneLiteralExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, SelfKeyword_)))
	{
		children_->add_(expect_token_(parser_, SelfKeyword_));
		return new_Syntax_Node(SelfExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, TrueKeyword_)))
	{
		children_->add_(expect_token_(parser_, TrueKeyword_));
		return new_Syntax_Node(TrueLiteralExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, FalseKeyword_)))
	{
		children_->add_(expect_token_(parser_, FalseKeyword_));
		return new_Syntax_Node(FalseLiteralExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, Number_)))
	{
		children_->add_(expect_token_(parser_, Number_));
		return new_Syntax_Node(NumericLiteralExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, Identifier_)))
	{
		children_->add_(expect_token_(parser_, Identifier_));
		return new_Syntax_Node(IdentifierName_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, StringLiteral_)))
	{
		children_->add_(expect_token_(parser_, StringLiteral_));
		return new_Syntax_Node(StringLiteralExpression_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, CodePointLiteral_)))
	{
		children_->add_(expect_token_(parser_, CodePointLiteral_));
		return new_Syntax_Node(CodePointLiteralExpression_, children_);
	}

	return new_Syntax_Node(IdentifierName_, expect_token_(parser_, Identifier_));
}

auto parse_call_arguments_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
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
	return new_Syntax_Node(ArgumentList_, children_);
}

auto parse_expression_(Compilation_Unit_Parser *_Nonnull const parser_, i32 const minPrecedence_) -> Syntax_Node const *_Nonnull
{
	Syntax_Node const *_Nonnull expression_ = parse_atom_(parser_);
	for (;;)
	{
		system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
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
			expression_ = new_Syntax_Node(expressionType_, children_);
		}
		else
		{
			expression_ = new_Syntax_Node(expressionType_, children_);
		}
	}
}

auto parse_expression_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull
{
	return parse_expression_(parser_, i32(1));
}

auto parse_statement_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	if (cond(equal_op(parser_->token_->kind_, ReturnKeyword_)))
	{
		children_->add_(expect_token_(parser_, ReturnKeyword_));
		if (cond(not_equal_op(parser_->token_->kind_, Semicolon_)))
		{
			children_->add_(parse_expression_(parser_));
		}

		children_->add_(expect_token_(parser_, Semicolon_));
		return new_Syntax_Node(ReturnStatement_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, LoopKeyword_)))
	{
		children_->add_(expect_token_(parser_, LoopKeyword_));
		children_->add_(parse_block_(parser_));
		return new_Syntax_Node(LoopStatement_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, WhileKeyword_)))
	{
		children_->add_(expect_token_(parser_, WhileKeyword_));
		children_->add_(parse_expression_(parser_));
		children_->add_(parse_block_(parser_));
		return new_Syntax_Node(WhileStatement_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, ForKeyword_)))
	{
		children_->add_(expect_token_(parser_, ForKeyword_));
		children_->add_(parse_variable_declaration_(parser_, bit_false));
		children_->add_(expect_token_(parser_, InKeyword_));
		children_->add_(parse_expression_(parser_));
		children_->add_(parse_block_(parser_));
		return new_Syntax_Node(ForStatement_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, DoKeyword_)))
	{
		children_->add_(expect_token_(parser_, DoKeyword_));
		children_->add_(parse_block_(parser_));
		children_->add_(expect_token_(parser_, WhileKeyword_));
		children_->add_(parse_expression_(parser_));
		children_->add_(expect_token_(parser_, Semicolon_));
		return new_Syntax_Node(DoWhileStatement_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, IfKeyword_)))
	{
		return parse_if_statement_(parser_);
	}

	if (cond(equal_op(parser_->token_->kind_, BreakKeyword_)))
	{
		children_->add_(expect_token_(parser_, BreakKeyword_));
		children_->add_(expect_token_(parser_, Semicolon_));
		return new_Syntax_Node(BreakStatement_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, ContinueKeyword_)))
	{
		children_->add_(expect_token_(parser_, ContinueKeyword_));
		children_->add_(expect_token_(parser_, Semicolon_));
		return new_Syntax_Node(ContinueStatement_, children_);
	}

	if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, VarKeyword_)) || bit_arg(equal_op(parser_->token_->kind_, LetKeyword_)))))
	{
		children_->add_(parse_variable_declaration_(parser_, bit_true));
		children_->add_(expect_token_(parser_, Semicolon_));
		return new_Syntax_Node(LocalDeclarationStatement_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, LeftBrace_)))
	{
		return parse_block_(parser_);
	}

	children_->add_(parse_expression_(parser_));
	children_->add_(expect_token_(parser_, Semicolon_));
	return new_Syntax_Node(ExpressionStatement_, children_);
}

auto parse_if_statement_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	children_->add_(expect_token_(parser_, IfKeyword_));
	children_->add_(parse_expression_(parser_));
	children_->add_(parse_block_(parser_));
	if (cond(equal_op(parser_->token_->kind_, ElseKeyword_)))
	{
		system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const elseChildren_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
		elseChildren_->add_(expect_token_(parser_, ElseKeyword_));
		if (cond(equal_op(parser_->token_->kind_, IfKeyword_)))
		{
			elseChildren_->add_(parse_if_statement_(parser_));
		}
		else
		{
			elseChildren_->add_(parse_block_(parser_));
		}

		children_->add_(new_Syntax_Node(ElseClause_, elseChildren_));
	}

	return new_Syntax_Node(IfStatement_, children_);
}

auto parse_variable_declaration_(Compilation_Unit_Parser *_Nonnull const parser_, bit const allowInitializer_) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
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

	return new_Syntax_Node(VariableDeclaration_, children_);
}

auto parse_block_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	children_->add_(expect_token_(parser_, LeftBrace_));
	while (cond(bit_op(bit_arg(not_equal_op(parser_->token_->kind_, RightBrace_)) && bit_arg(not_equal_op(parser_->token_->kind_, EndOfFileToken_)))))
	{
		Syntax_Node const *_Nonnull const startToken_ = parser_->token_;
		children_->add_(parse_statement_(parser_));
		if (cond(equal_op(parser_->token_, startToken_)))
		{
			system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const skipped_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
			while (cond(bit_op(bit_arg(bit_op(bit_arg(not_equal_op(parser_->token_->kind_, LeftBrace_)) && bit_arg(not_equal_op(parser_->token_->kind_, RightBrace_)))) && bit_arg(not_equal_op(parser_->token_->kind_, EndOfFileToken_)))))
			{
				i32 const currentTokenType_ = parser_->token_->kind_;
				skipped_->add_(accept_token_(parser_));
				if (cond(equal_op(currentTokenType_, Semicolon_)))
				{
					break;
				}
			}

			children_->add_(new_Syntax_Node__skipped(skipped_));
		}
	}

	children_->add_(expect_token_(parser_, RightBrace_));
	return new_Syntax_Node(Block_, children_);
}

auto parse_parameter_list_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	children_->add_(expect_token_(parser_, LeftParen_));
	if (cond(not_equal_op(parser_->token_->kind_, RightParen_)))
	{
		for (;;)
		{
			system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const parameterChildren_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
			if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, MutableKeyword_)) || bit_arg(equal_op(parser_->token_->kind_, SelfKeyword_)))))
			{
				if (cond(equal_op(parser_->token_->kind_, MutableKeyword_)))
				{
					parameterChildren_->add_(expect_token_(parser_, MutableKeyword_));
				}

				parameterChildren_->add_(expect_token_(parser_, SelfKeyword_));
				children_->add_(new_Syntax_Node(SelfParameter_, parameterChildren_));
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
				Syntax_Node const *_Nonnull const type_ = parse_type_(parser_);
				parameterChildren_->add_(type_);
				children_->add_(new_Syntax_Node(Parameter_, parameterChildren_));
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
	return new_Syntax_Node(ParameterList_, children_);
}

auto parse_member_declaration_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
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
		return new_Syntax_Node(ConstructorDeclaration_, children_);
	}

	if (cond(bit_op(bit_arg(equal_op(parser_->token_->kind_, VarKeyword_)) || bit_arg(equal_op(parser_->token_->kind_, LetKeyword_)))))
	{
		children_->add_(parse_variable_declaration_(parser_, bit_false));
		children_->add_(expect_token_(parser_, Semicolon_));
		return new_Syntax_Node(FieldDeclaration_, children_);
	}

	children_->add_(expect_token_(parser_, Identifier_));
	children_->add_(parse_parameter_list_(parser_));
	children_->add_(expect_token_(parser_, Arrow_));
	children_->add_(parse_type_(parser_));
	children_->add_(parse_block_(parser_));
	return new_Syntax_Node(MethodDeclaration_, children_);
}

auto parse_declaration_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
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
		return new_Syntax_Node(GlobalDeclaration_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, ClassKeyword_)))
	{
		children_->add_(expect_token_(parser_, ClassKeyword_));
		children_->add_(expect_token_(parser_, Identifier_));
		children_->add_(expect_token_(parser_, LeftBrace_));
		while (cond(bit_op(bit_arg(not_equal_op(parser_->token_->kind_, RightBrace_)) && bit_arg(not_equal_op(parser_->token_->kind_, EndOfFileToken_)))))
		{
			Syntax_Node const *_Nonnull const startToken_ = parser_->token_;
			children_->add_(parse_member_declaration_(parser_));
			if (cond(equal_op(parser_->token_, startToken_)))
			{
				children_->add_(new_Syntax_Node__skipped(accept_token_(parser_)));
			}
		}

		children_->add_(expect_token_(parser_, RightBrace_));
		return new_Syntax_Node(ClassDeclaration_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, StructKeyword_)))
	{
		children_->add_(expect_token_(parser_, StructKeyword_));
		children_->add_(expect_token_(parser_, Identifier_));
		children_->add_(expect_token_(parser_, LeftBrace_));
		while (cond(bit_op(bit_arg(not_equal_op(parser_->token_->kind_, RightBrace_)) && bit_arg(not_equal_op(parser_->token_->kind_, EndOfFileToken_)))))
		{
			Syntax_Node const *_Nonnull const startToken_ = parser_->token_;
			children_->add_(parse_member_declaration_(parser_));
			if (cond(equal_op(parser_->token_, startToken_)))
			{
				children_->add_(new_Syntax_Node__skipped(accept_token_(parser_)));
			}
		}

		children_->add_(expect_token_(parser_, RightBrace_));
		return new_Syntax_Node(StructDeclaration_, children_);
	}

	if (cond(equal_op(parser_->token_->kind_, EnumKeyword_)))
	{
		children_->add_(expect_token_(parser_, EnumKeyword_));
		children_->add_(expect_token_(parser_, StructKeyword_));
		children_->add_(expect_token_(parser_, Identifier_));
		children_->add_(expect_token_(parser_, LeftBrace_));
		while (cond(bit_op(bit_arg(not_equal_op(parser_->token_->kind_, RightBrace_)) && bit_arg(not_equal_op(parser_->token_->kind_, EndOfFileToken_)))))
		{
			system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const memberChildren_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
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

			children_->add_(new_Syntax_Node(EnumMemberDeclaration_, memberChildren_));
		}

		children_->add_(expect_token_(parser_, RightBrace_));
		return new_Syntax_Node(EnumDeclaration_, children_);
	}

	children_->add_(expect_token_(parser_, Identifier_));
	children_->add_(parse_parameter_list_(parser_));
	children_->add_(expect_token_(parser_, Arrow_));
	children_->add_(parse_type_(parser_));
	children_->add_(parse_block_(parser_));
	return new_Syntax_Node(FunctionDeclaration_, children_);
}

auto parse_compilation_unit_(Compilation_Unit_Parser *_Nonnull const parser_) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	while (cond(bit_op(bit_arg(not_equal_op(parser_->token_, none)) && bit_arg(not_equal_op(parser_->token_->kind_, EndOfFileToken_)))))
	{
		Syntax_Node const *_Nonnull const startToken_ = parser_->token_;
		children_->add_(parse_declaration_(parser_));
		if (cond(equal_op(parser_->token_, startToken_)))
		{
			children_->add_(new_Syntax_Node__skipped(accept_token_(parser_)));
		}
	}

	children_->add_(expect_token_(parser_, EndOfFileToken_));
	return new_Syntax_Node(CompilationUnit_, children_);
}

auto lexically_analyze_(Source_Text const *_Nonnull const source_) -> Token_Stream *_Nonnull
{
	return new_Token_Stream(source_);
}

auto parse_package_(system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const sources_) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	for (Source_Text const *_Nonnull const source_ : *(sources_))
	{
		Token_Stream *_Nonnull const token_stream_ = lexically_analyze_(source_);
		Compilation_Unit_Parser *_Nonnull const compilation_unit_parser_ = new_Compilation_Unit_Parser(token_stream_);
		children_->add_(parse_(compilation_unit_parser_));
	}

	return new_Syntax_Node(PackageNode_, children_);
}

Syntax_Node *_Nonnull c_Syntax_Node(Syntax_Node *_Nonnull self, i32 const type_, Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_)
{
	self->kind_ = type_;
	self->is_missing_ = bit_false;
	self->source_ = source_;
	self->start_ = start_;
	self->byte_length_ = length_;
	self->children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	self->node_diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	return self;
}

inline Syntax_Node *_Nonnull new_Syntax_Node(i32 const type_, Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_)
{
	return c_Syntax_Node(new Syntax_Node(), type_, source_, start_, length_);
}

Syntax_Node *_Nonnull c_Syntax_Node(Syntax_Node *_Nonnull self, i32 const type_, bit const isMissing_, Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_)
{
	self->kind_ = type_;
	self->is_missing_ = isMissing_;
	self->source_ = source_;
	self->start_ = start_;
	self->byte_length_ = length_;
	self->children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	self->node_diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	return self;
}

inline Syntax_Node *_Nonnull new_Syntax_Node(i32 const type_, bit const isMissing_, Source_Text const *_Nonnull const source_, u32 const start_, u32 const length_)
{
	return c_Syntax_Node(new Syntax_Node(), type_, isMissing_, source_, start_, length_);
}

Syntax_Node *_Nonnull c_Syntax_Node(Syntax_Node *_Nonnull self, i32 const type_, Syntax_Node const *_Nonnull const child_)
{
	self->kind_ = type_;
	self->is_missing_ = child_->is_missing_;
	self->source_ = child_->source_;
	self->start_ = child_->start_;
	self->byte_length_ = child_->byte_length_;
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	children_->add_(child_);
	self->children_ = children_;
	self->node_diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	return self;
}

inline Syntax_Node *_Nonnull new_Syntax_Node(i32 const type_, Syntax_Node const *_Nonnull const child_)
{
	return c_Syntax_Node(new Syntax_Node(), type_, child_);
}

Syntax_Node *_Nonnull c_Syntax_Node(Syntax_Node *_Nonnull self, i32 const type_, system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const children_)
{
	self->kind_ = type_;
	self->is_missing_ = bit_false;
	self->source_ = children_->op_Element(i32(0))->source_;
	self->start_ = children_->op_Element(i32(0))->start_;
	Syntax_Node const *_Nonnull const lastChild_ = children_->op_Element(children_->op_magnitude()->op_subtract(i32(1)));
	self->byte_length_ = lastChild_->start_.op_subtract(self->start_)->op_add(lastChild_->byte_length_);
	self->children_ = children_;
	self->node_diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	return self;
}

inline Syntax_Node *_Nonnull new_Syntax_Node(i32 const type_, system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const children_)
{
	return c_Syntax_Node(new Syntax_Node(), type_, children_);
}

Syntax_Node *_Nonnull c_Syntax_Node__missing(Syntax_Node *_Nonnull self, i32 const type_, Source_Text const *_Nonnull const source_, u32 const start_)
{
	self->kind_ = type_;
	self->is_missing_ = bit_true;
	self->source_ = source_;
	self->start_ = start_;
	self->byte_length_ = i32(0);
	self->children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	self->node_diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	Text_Span const *_Nonnull const span_ = new_Text_Span(start_, i32(0));
	self->node_diagnostics_->add_(new_Diagnostic(CompilationError_, Parsing_, source_, span_, str("Missing token of type ").op_add(type_)));
	return self;
}

inline Syntax_Node *_Nonnull new_Syntax_Node__missing(i32 const type_, Source_Text const *_Nonnull const source_, u32 const start_)
{
	return c_Syntax_Node__missing(new Syntax_Node(), type_, source_, start_);
}

Syntax_Node *_Nonnull c_Syntax_Node__skipped(Syntax_Node *_Nonnull self, Syntax_Node const *_Nonnull const skipped_node_)
{
	self->kind_ = SkippedTokens_;
	self->is_missing_ = skipped_node_->is_missing_;
	self->source_ = skipped_node_->source_;
	self->start_ = skipped_node_->start_;
	self->byte_length_ = skipped_node_->byte_length_;
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	children_->add_(skipped_node_);
	self->children_ = children_;
	self->node_diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	Text_Span const *_Nonnull const span_ = new_Text_Span(skipped_node_->start_, skipped_node_->byte_length_);
	self->node_diagnostics_->add_(new_Diagnostic(CompilationError_, Parsing_, skipped_node_->source_, span_, str("Skipped unexpected token of type ").op_add(skipped_node_->kind_)));
	return self;
}

inline Syntax_Node *_Nonnull new_Syntax_Node__skipped(Syntax_Node const *_Nonnull const skipped_node_)
{
	return c_Syntax_Node__skipped(new Syntax_Node(), skipped_node_);
}

Syntax_Node *_Nonnull c_Syntax_Node__skipped(Syntax_Node *_Nonnull self, system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const skipped_nodes_)
{
	self->kind_ = SkippedTokens_;
	self->is_missing_ = bit_false;
	self->source_ = skipped_nodes_->op_Element(i32(0))->source_;
	self->start_ = skipped_nodes_->op_Element(i32(0))->start_;
	Syntax_Node const *_Nonnull const lastChild_ = skipped_nodes_->op_Element(skipped_nodes_->op_magnitude()->op_subtract(i32(1)));
	self->byte_length_ = lastChild_->start_.op_subtract(self->start_)->op_add(lastChild_->byte_length_);
	self->children_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	self->node_diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	Text_Span const *_Nonnull const span_ = new_Text_Span(self->start_, self->byte_length_);
	self->node_diagnostics_->add_(new_Diagnostic(CompilationError_, Parsing_, self->source_, span_, str("Skipped ").op_add(skipped_nodes_->op_magnitude())->op_add(str(" unexpected token(s)"))));
	return self;
}

inline Syntax_Node *_Nonnull new_Syntax_Node__skipped(system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const skipped_nodes_)
{
	return c_Syntax_Node__skipped(new Syntax_Node(), skipped_nodes_);
}

auto get_text_(Syntax_Node const *_Nonnull const syntax_) -> str
{
	return syntax_->source_->text_.Substring_(syntax_->start_, syntax_->byte_length_);
}

auto first_child_syntax_(Syntax_Node const *_Nonnull const syntax_, i32 const type_) -> Syntax_Node const *_Nullable
{
	for (Syntax_Node const *_Nonnull const child_ : *(syntax_->children_))
	{
		if (cond(equal_op(child_->kind_, type_)))
		{
			return child_;
		}
	}

	return none;
}

auto has_child_(Syntax_Node const *_Nonnull const syntax_, i32 const type_) -> bit
{
	for (Syntax_Node const *_Nonnull const child_ : *(syntax_->children_))
	{
		if (cond(equal_op(child_->kind_, type_)))
		{
			return bit_true;
		}
	}

	return bit_false;
}

auto add_(Syntax_Node const *_Nonnull const syntax_, Diagnostic const *_Nonnull const diagnostic_) -> void
{
	syntax_->node_diagnostics_->add_(diagnostic_);
}

auto all_diagnostics_(Syntax_Node const *_Nonnull const syntax_) -> system__collections__List<Diagnostic const *_Nonnull> *_Nonnull
{
	system__collections__List<Diagnostic const *_Nonnull> *_Nonnull diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	collect_syntax_diagnostics_(syntax_, diagnostics_);
	return diagnostics_;
}

auto collect_syntax_diagnostics_(Syntax_Node const *_Nonnull const syntax_, system__collections__List<Diagnostic const *_Nonnull> *_Nonnull const diagnostics_) -> void
{
	for (Diagnostic const *_Nonnull const diagnostic_ : *(syntax_->node_diagnostics_))
	{
		diagnostics_->add_(diagnostic_);
	}

	for (Syntax_Node const *_Nonnull const child_ : *(syntax_->children_))
	{
		collect_syntax_diagnostics_(child_, diagnostics_);
	}
}

auto members_(Syntax_Node const *_Nonnull const syntax_) -> system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const members_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	for (Syntax_Node const *_Nonnull const child_ : *(syntax_->children_))
	{
		if (cond(bit_op(bit_arg(bit_op(bit_arg(equal_op(child_->kind_, ConstructorDeclaration_)) || bit_arg(equal_op(child_->kind_, FieldDeclaration_)))) || bit_arg(equal_op(child_->kind_, MethodDeclaration_)))))
		{
			members_->add_(child_);
		}
	}

	return members_;
}

auto parameters_(Syntax_Node const *_Nonnull const syntax_) -> system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const parameters_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	for (Syntax_Node const *_Nonnull const child_ : *(syntax_->children_))
	{
		if (cond(bit_op(bit_arg(equal_op(child_->kind_, Parameter_)) || bit_arg(equal_op(child_->kind_, SelfParameter_)))))
		{
			parameters_->add_(child_);
		}
	}

	return parameters_;
}

auto statements_(Syntax_Node const *_Nonnull const syntax_) -> system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const statements_ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	for (Syntax_Node const *_Nonnull const child_ : *(syntax_->children_))
	{
		if (cond(bit_op(bit_arg(not_equal_op(child_->kind_, LeftBrace_)) && bit_arg(not_equal_op(child_->kind_, RightBrace_)))))
		{
			statements_->add_(child_);
		}
	}

	return statements_;
}

auto access_modifier_(Syntax_Node const *_Nonnull const syntax_) -> Syntax_Node const *_Nullable
{
	for (Syntax_Node const *_Nonnull const child_ : *(syntax_->children_))
	{
		if (cond(bit_op(bit_arg(bit_op(bit_arg(bit_op(bit_arg(equal_op(child_->kind_, PublicKeyword_)) || bit_arg(equal_op(child_->kind_, ProtectedKeyword_)))) || bit_arg(equal_op(child_->kind_, InternalKeyword_)))) || bit_arg(equal_op(child_->kind_, PrivateKeyword_)))))
		{
			return child_;
		}
	}

	return none;
}

Token_Stream *_Nonnull c_Token_Stream(Token_Stream *_Nonnull self, Source_Text const *_Nonnull const source_)
{
	self->source_ = source_;
	self->position_ = i32(0);
	self->diagnostics_ = new_system__collections__List<Diagnostic const *_Nonnull>();
	self->end_of_file_ = bit_false;
	return self;
}

inline Token_Stream *_Nonnull new_Token_Stream(Source_Text const *_Nonnull const source_)
{
	return c_Token_Stream(new Token_Stream(), source_);
}

auto next_token_(Token_Stream *_Nonnull const tokens_) -> Syntax_Node const *_Nullable
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

			Text_Span const *_Nonnull diagnosticSpan_ = new_Text_Span(tokens_->position_, i32(1));
			tokens_->diagnostics_->add_(new_Diagnostic(CompilationError_, Lexing_, tokens_->source_, diagnosticSpan_, str("Invalid character `").op_add(curChar_)->op_add(str("`"))));
			tokens_->position_ = end_;
		}
	}

	return end_of_file_token_(tokens_);
}

auto end_of_file_token_(Token_Stream *_Nonnull const tokens_) -> Syntax_Node const *_Nullable
{
	if (cond(tokens_->end_of_file_))
	{
		return none;
	}

	tokens_->end_of_file_ = bit_true;
	return new_token_(tokens_, EndOfFileToken_, tokens_->position_);
}

auto new_identifier_or_keyword_token_(Token_Stream *_Nonnull const tokens_, u32 const end_) -> Syntax_Node const *_Nonnull
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
			Text_Span const *_Nonnull diagnosticSpan_ = new_Text_Span(tokens_->position_, end_.op_subtract(tokens_->position_));
			tokens_->diagnostics_->add_(new_Diagnostic(CompilationError_, Lexing_, tokens_->source_, diagnosticSpan_, str("Identifiers ending with underscore are reserved `").op_add(value_)->op_add(str("`"))));
		}
	}

	return new_token_(tokens_, type_, end_);
}

auto new_operator_token_(Token_Stream *_Nonnull const tokens_, i32 const type_) -> Syntax_Node const *_Nonnull
{
	return new_token_(tokens_, type_, tokens_->position_.op_add(i32(1)));
}

auto new_operator_token_(Token_Stream *_Nonnull const tokens_, i32 const type_, u32 const length_) -> Syntax_Node const *_Nonnull
{
	return new_token_(tokens_, type_, tokens_->position_.op_add(length_));
}

auto new_token_(Token_Stream *_Nonnull const tokens_, i32 const type_, u32 const end_) -> Syntax_Node const *_Nonnull
{
	Syntax_Node *_Nonnull const token_ = new_Syntax_Node(type_, tokens_->source_, tokens_->position_, end_.op_subtract(tokens_->position_));
	for (Diagnostic const *_Nonnull const diagnostic_ : *(tokens_->diagnostics_))
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

Diagnostic *_Nonnull c_Diagnostic(Diagnostic *_Nonnull self, i32 const level_, i32 const phase_, Source_Text const *_Nonnull const source_, Text_Span const *_Nonnull const span_, str const message_)
{
	self->level_ = level_;
	self->phase_ = phase_;
	self->source_ = source_;
	self->span_ = span_;
	self->position_ = position_of_start_(source_, span_);
	self->message_ = message_;
	return self;
}

inline Diagnostic *_Nonnull new_Diagnostic(i32 const level_, i32 const phase_, Source_Text const *_Nonnull const source_, Text_Span const *_Nonnull const span_, str const message_)
{
	return c_Diagnostic(new Diagnostic(), level_, phase_, source_, span_, message_);
}

Emitter *_Nonnull c_Emitter(Emitter *_Nonnull self, Package const *_Nonnull const package_, system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const resources_)
{
	self->package_ = package_;
	self->resources_ = resources_;
	return self;
}

inline Emitter *_Nonnull new_Emitter(Package const *_Nonnull const package_, system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const resources_)
{
	return c_Emitter(new Emitter(), package_, resources_);
}

auto emit_(Emitter *_Nonnull const emitter_) -> str
{
	emitter_->type_declarations_ = new_Source_File_Builder();
	emitter_->function_declarations_ = new_Source_File_Builder();
	emitter_->class_declarations_ = new_Source_File_Builder();
	emitter_->global_definitions_ = new_Source_File_Builder();
	emitter_->definitions_ = new_Source_File_Builder();
	emitter_->main_function_return_type_ = str("");
	emitter_->main_function_accepts_console_ = bit_false;
	emitter_->main_function_accepts_args_ = bit_false;
	emit_preamble_(emitter_);
	for (Compilation_Unit const *_Nonnull const compilation_unit_ : *(emitter_->package_->compilation_units_))
	{
		emit_compilation_unit_(emitter_, compilation_unit_);
	}

	emit_entry_point_adapter_(emitter_);
	i32 const total_size_ = byte_length_(emitter_->type_declarations_)->op_add(byte_length_(emitter_->function_declarations_))->op_add(byte_length_(emitter_->class_declarations_))->op_add(byte_length_(emitter_->global_definitions_))->op_add(byte_length_(emitter_->definitions_));
	system__text__String_Builder *_Nonnull const cpp_code_ = new_system__text__String_Builder();
	cpp_code_->Append_(to_string_(emitter_->type_declarations_));
	cpp_code_->Append_(to_string_(emitter_->function_declarations_));
	cpp_code_->Append_(to_string_(emitter_->class_declarations_));
	cpp_code_->Append_(to_string_(emitter_->global_definitions_));
	cpp_code_->Append_(to_string_(emitter_->definitions_));
	return cpp_code_->ToString_();
}

auto mangle_name_(Name const *_Nonnull const name_) -> str
{
	system__text__String_Builder *_Nonnull const builder_ = new_system__text__String_Builder();
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

auto convert_primitive_type_name_(Type const *_Nonnull const type_) -> str
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
	else
	{
		return name_;
	}
}

auto convert_type_name_(Semantic_Node const *_Nonnull const type_node_) -> system__text__String_Builder *_Nonnull
{
	assert_(not_equal_op(type_node_->referenced_type_, none), get_text_(type_node_));
	return convert_type_name_(type_node_->referenced_type_);
}

auto convert_type_name_(Type const *_Nonnull const type_) -> system__text__String_Builder *_Nonnull
{
	system__text__String_Builder *_Nonnull const cpp_type_ = new_system__text__String_Builder();
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
		for (Type const *_Nonnull const type_parameter_ : *(type_->type_parameters_))
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

auto convert_reference_type_(bit const mutable_binding_, Type const *_Nonnull type_, bit const nullable_) -> str
{
	system__text__String_Builder *_Nonnull const cpp_type_ = convert_type_name_(type_);
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

auto convert_type_(bit const mutable_binding_, Type const *_Nonnull type_, bit const optional_) -> str
{
	assert_(not_equal_op(type_, none), str(""));
	if (cond(bit_op(bit_arg(type_->is_primitive_) && bit_arg(equal_op(unqualified_name_(type_->name_), str("optional"))))))
	{
		Type const *_Nonnull const optional_type_ = type_->type_parameters_->op_Element(i32(0));
		if (cond(optional_type_->is_value_type_))
		{
			system__text__String_Builder *_Nonnull const cpp_type_ = new_system__text__String_Builder(str("p_optional<"));
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
			system__text__String_Builder *_Nonnull const cpp_type_ = convert_type_name_(type_);
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

auto convert_type_(bit const mutable_binding_, Semantic_Node const *_Nonnull const type_node_) -> str
{
	assert_(not_equal_op(type_node_->referenced_type_, none), get_text_(type_node_));
	return convert_type_(mutable_binding_, type_node_->referenced_type_, bit_false);
}

auto convert_parameter_list_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const parameters_, str const self_type_, bit const is_main_function_) -> str
{
	assert_(equal_op(parameters_->kind_, ParameterList_), str("parameters.kind=").op_add(parameters_->kind_));
	system__text__String_Builder *_Nonnull const builder_ = new_system__text__String_Builder();
	builder_->Append_(str("("));
	if (cond(self_type_.ByteLength_()->op_greater_than(i32(0))))
	{
		builder_->Append_(self_type_);
		builder_->Append_(str(" self"));
	}

	bit first_parameter_ = equal_op(self_type_.ByteLength_(), i32(0));
	for (Semantic_Node const *_Nonnull const parameter_ : *(children_of_kind_(parameters_, Parameter_)))
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
		Semantic_Node const *_Nonnull const type_node_ = parameter_->children_->op_Element(parameter_->children_->op_magnitude()->op_subtract(i32(1)));
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

auto convert_method_parameter_list_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const parameters_, str const self_type_) -> str
{
	return convert_parameter_list_(emitter_, parameters_, self_type_, bit_false);
}

auto convert_parameter_list_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const parameters_, bit const is_main_function_) -> str
{
	return convert_parameter_list_(emitter_, parameters_, str(""), is_main_function_);
}

auto convert_parameter_list_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const parameters_) -> str
{
	return convert_parameter_list_(emitter_, parameters_, str(""), bit_false);
}

auto convert_expression_(Semantic_Node const *_Nonnull const syntax_, Source_File_Builder *_Nonnull const builder_) -> void
{
	if (cond(equal_op(syntax_->kind_, NewExpression_)))
	{
		str constructor_name_ = str("");
		Semantic_Node const *_Nonnull type_node_ = syntax_->children_->op_Element(i32(0));
		if (cond(equal_op(type_node_->kind_, QualifiedName_)))
		{
			Semantic_Node const *_Nonnull const name_node_ = type_node_->children_->op_Element(i32(1));
			if (cond(bit_op(bit_arg(equal_op(name_node_->kind_, IdentifierName_)) && bit_arg(equal_op(name_node_->referenced_type_, none)))))
			{
				constructor_name_ = str("__").op_add(get_text_(name_node_));
				type_node_ = type_node_->children_->op_Element(i32(0));
			}
		}

		Type const *_Nonnull const type_ = type_node_->referenced_type_;
		assert_(not_equal_op(type_, none), get_text_(type_node_));
		write_(builder_, str("new_"));
		write_(builder_, convert_type_name_(type_)->ToString_());
		write_(builder_, constructor_name_);
		Semantic_Node const *_Nonnull const argumentList_ = syntax_->children_->op_Element(i32(1));
		convert_expression_(argumentList_, builder_);
	}
	else if (cond(equal_op(syntax_->kind_, ArgumentList_)))
	{
		write_(builder_, str("("));
		bit first_expression_ = bit_true;
		for (Semantic_Node const *_Nonnull const arg_ : *(syntax_->children_))
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
		write_(builder_, str("bit__op__not("));
		convert_expression_(syntax_->children_->op_Element(i32(1)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, MagnitudeExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(1)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(1)), builder_);
		write_(builder_, str("op__magnitude()"));
	}
	else if (cond(equal_op(syntax_->kind_, ParenthesizedExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(1)), builder_);
	}
	else if (cond(equal_op(syntax_->kind_, NegateExpression_)))
	{
		write_(builder_, str("i32__op__negate("));
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
		write_(builder_, str("bit__").op_add(get_text_(syntax_)));
	}
	else if (cond(equal_op(syntax_->kind_, CodePointLiteralExpression_)))
	{
		write_(builder_, str("code_point(").op_add(get_text_(syntax_))->op_add(str(")")));
	}
	else if (cond(equal_op(syntax_->kind_, IdentifierName_)))
	{
		write_(builder_, get_text_(syntax_)->op_add(str("_")));
	}
	else if (cond(equal_op(syntax_->kind_, StringLiteralExpression_)))
	{
		write_(builder_, str("string(").op_add(get_text_(syntax_))->op_add(str(")")));
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
			write_(builder_, str("op__"));
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
		Type const *_Nonnull const type_ = syntax_->children_->op_Element(i32(0))->of_type_;
		if (cond(not_equal_op(type_, none)))
		{
			write_(builder_, convert_primitive_type_name_(type_));
			if (cond(equal_op(operator_, LessThan_)))
			{
				write_(builder_, str("__op__less_than"));
			}
			else if (cond(equal_op(operator_, LessThanEquals_)))
			{
				write_(builder_, str("__op__less_than_or_equal"));
			}
			else if (cond(equal_op(operator_, GreaterThan_)))
			{
				write_(builder_, str("__op__greater_than"));
			}
			else if (cond(equal_op(operator_, GreaterThanEquals_)))
			{
				write_(builder_, str("__op__greater_than_or_equal"));
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
			write_(builder_, str("op__"));
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
		write_(builder_, str("op__add("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, SubtractExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str("op__subtract("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, MultiplyExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str("op__multiply("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, DivideExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str("op__divide("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, RemainderExpression_)))
	{
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		convert_member_access_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str("op__remainder("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str(")"));
	}
	else if (cond(equal_op(syntax_->kind_, OrExpression_)))
	{
		write_(builder_, str("bit__op(bit__arg("));
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str(") || bit__arg("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str("))"));
	}
	else if (cond(equal_op(syntax_->kind_, AndExpression_)))
	{
		write_(builder_, str("bit__op(bit__arg("));
		convert_expression_(syntax_->children_->op_Element(i32(0)), builder_);
		write_(builder_, str(") && bit__arg("));
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
		write_(builder_, str("op__Element("));
		convert_expression_(syntax_->children_->op_Element(i32(2)), builder_);
		write_(builder_, str(")"));
	}
	else
	{
		error_(builder_, str("Could not convert expression of type ").op_add(syntax_->kind_));
	}
}

auto convert_member_access_(Semantic_Node const *_Nonnull const lhs_, Source_File_Builder *_Nonnull const builder_) -> void
{
	Type const *_Nullable const type_ = lhs_->of_type_;
	if (cond(bit_op(bit_arg(bit_op(bit_arg(not_equal_op(type_, none)) && bit_arg(type_->is_value_type_))) && bit_arg(bit_not(bit_op(bit_arg(bit_op(bit_arg(type_->is_primitive_) && bit_arg(equal_op(unqualified_name_(type_->name_), str("optional"))))) && bit_arg(bit_not(type_->type_parameters_->op_Element(i32(0))->is_value_type_))))))))
	{
		write_(builder_, str("."));
	}
	else
	{
		write_(builder_, str("->"));
	}
}

auto emit_statement_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const statement_) -> void
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
		for (Semantic_Node const *_Nonnull const block_statement_ : *(node_statements_(statement_)))
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
		Semantic_Node const *_Nonnull const variable_declaration_ = first_child_(statement_, VariableDeclaration_);
		bit const mutable_binding_ = node_has_child_(variable_declaration_, VarKeyword_);
		str const name_ = get_text_(first_child_(variable_declaration_, Identifier_));
		Semantic_Node const *_Nonnull const type_ = variable_declaration_->children_->op_Element(i32(2));
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
		Semantic_Node const *_Nullable if_statement_ = statement_;
		begin_line_(emitter_->definitions_, str(""));
		for (;;)
		{
			write_(emitter_->definitions_, str("if (cond("));
			convert_expression_(if_statement_->children_->op_Element(i32(1)), emitter_->definitions_);
			end_line_(emitter_->definitions_, str("))"));
			emit_statement_(emitter_, if_statement_->children_->op_Element(i32(2)));
			Semantic_Node const *_Nullable const elseClause_ = first_child_(if_statement_, ElseClause_);
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
		Semantic_Node const *_Nonnull const variable_declaration_ = first_child_(statement_, VariableDeclaration_);
		str const variable_name_ = get_text_(first_child_(variable_declaration_, Identifier_));
		Semantic_Node const *_Nonnull const variable_type_ = variable_declaration_->children_->op_Element(i32(2));
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

auto emit_method_body_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const block_, bit const is_associated_function_) -> void
{
	begin_block_(emitter_->definitions_);
	if (cond(bit_not(is_associated_function_)))
	{
		write_line_(emitter_->definitions_, str("auto self = this;"));
	}

	for (Semantic_Node const *_Nonnull const statement_ : *(node_statements_(block_)))
	{
		emit_statement_(emitter_, statement_);
	}

	end_block_(emitter_->definitions_);
}

auto emit_constructor_body_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const block_, str const self_type_, bit const is_value_type_) -> void
{
	begin_block_(emitter_->definitions_);
	if (cond(is_value_type_))
	{
		write_line_(emitter_->definitions_, self_type_.op_add(str(" self;")));
	}

	for (Semantic_Node const *_Nonnull const statement_ : *(node_statements_(block_)))
	{
		emit_statement_(emitter_, statement_);
	}

	write_line_(emitter_->definitions_, str("return self;"));
	end_block_(emitter_->definitions_);
}

auto emit_member_declaration_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const member_, str const class_name_, bit const is_value_type_) -> void
{
	if (cond(equal_op(member_->kind_, ConstructorDeclaration_)))
	{
		str new_function_name_ = str("new_").op_add(class_name_);
		str constructor_full_name_ = str("c_").op_add(class_name_);
		Semantic_Node const *_Nullable const constructor_name_node_ = first_child_(member_, Identifier_);
		if (cond(not_equal_op(constructor_name_node_, none)))
		{
			str const constructor_name_ = get_text_(constructor_name_node_);
			new_function_name_ = new_function_name_.op_add(str("__"))->op_add(constructor_name_);
			constructor_full_name_ = constructor_full_name_.op_add(str("__"))->op_add(constructor_name_);
		}

		str return_type_ = class_name_;
		if (cond(bit_not(is_value_type_)))
		{
			return_type_ = return_type_.op_add(str(" *_Nonnull"));
		}

		Semantic_Node const *_Nonnull const parameters_node_ = first_child_(member_, ParameterList_);
		str constructor_parameters_;
		if (cond(bit_not(is_value_type_)))
		{
			constructor_parameters_ = convert_method_parameter_list_(emitter_, parameters_node_, return_type_);
		}
		else
		{
			constructor_parameters_ = convert_parameter_list_(emitter_, parameters_node_);
		}

		str constructor_signature_ = return_type_.op_add(str(" "))->op_add(constructor_full_name_)->op_add(constructor_parameters_);
		write_line_(emitter_->function_declarations_, constructor_signature_.op_add(str(";")));
		element_separator_line_(emitter_->definitions_);
		write_line_(emitter_->definitions_, constructor_signature_);
		emit_constructor_body_(emitter_, first_child_(member_, Block_), return_type_, is_value_type_);
		str const new_function_signature_ = str("inline ").op_add(return_type_)->op_add(str(" "))->op_add(new_function_name_)->op_add(convert_parameter_list_(emitter_, parameters_node_));
		write_line_(emitter_->function_declarations_, new_function_signature_.op_add(str(";")));
		element_separator_line_(emitter_->definitions_);
		write_line_(emitter_->definitions_, new_function_signature_);
		begin_block_(emitter_->definitions_);
		if (cond(bit_not(is_value_type_)))
		{
			begin_line_(emitter_->definitions_, str("return ").op_add(constructor_full_name_)->op_add(str("(new "))->op_add(class_name_)->op_add(str("()")));
		}
		else
		{
			begin_line_(emitter_->definitions_, str("return ").op_add(constructor_full_name_)->op_add(str("(")));
		}

		bit first_parameter_ = is_value_type_;
		for (Semantic_Node const *_Nonnull const parameter_ : *(first_child_(member_, ParameterList_)->children_))
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
		Semantic_Node const *_Nonnull const variable_declaration_ = first_child_(member_, VariableDeclaration_);
		str const field_name_ = get_text_(first_child_(variable_declaration_, Identifier_));
		Semantic_Node const *_Nonnull const field_type_ = variable_declaration_->children_->op_Element(i32(2));
		str const cpp_type_ = convert_type_(bit_true, field_type_);
		write_line_(emitter_->class_declarations_, cpp_type_.op_add(str(" "))->op_add(field_name_)->op_add(str("_;")));
	}
	else if (cond(equal_op(member_->kind_, MethodDeclaration_)))
	{
		str const method_name_ = get_text_(first_child_(member_, Identifier_));
		str const parameters_ = convert_parameter_list_(emitter_, first_child_(member_, ParameterList_));
		Semantic_Node const *_Nullable const self_parameter_ = first_child_(first_child_(member_, ParameterList_), SelfParameter_);
		bit const is_associated_function_ = equal_op(self_parameter_, none);
		bit const mutable_self_ = bit_op(bit_arg(bit_not(is_associated_function_)) && bit_arg(node_has_child_(self_parameter_, MutableKeyword_)));
		Semantic_Node const *_Nonnull const return_type_node_ = member_->children_->op_Element(i32(3));
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
		Semantic_Node const *_Nonnull const block_ = first_child_(member_, Block_);
		emit_method_body_(emitter_, block_, is_associated_function_);
	}
	else
	{
		error_(emitter_->definitions_, str("Could not emit member of type ").op_add(member_->kind_));
	}
}

auto emit_default_constructor_(Emitter *_Nonnull const emitter_, str const type_name_, bit const is_value_type_) -> void
{
	str const default_constructor_name_ = str("c_").op_add(type_name_);
	str return_type_ = type_name_;
	if (cond(bit_not(is_value_type_)))
	{
		return_type_ = return_type_.op_add(str(" *_Nonnull"));
	}

	str constructor_signature_ = return_type_.op_add(str(" "))->op_add(default_constructor_name_)->op_add(str("("));
	if (cond(bit_not(is_value_type_)))
	{
		constructor_signature_ = constructor_signature_.op_add(return_type_)->op_add(str(" self"));
	}

	constructor_signature_ = constructor_signature_.op_add(str(")"));
	write_line_(emitter_->function_declarations_, constructor_signature_.op_add(str(";")));
	element_separator_line_(emitter_->definitions_);
	begin_line_(emitter_->definitions_, constructor_signature_);
	if (cond(is_value_type_))
	{
		end_line_(emitter_->definitions_, str(" { return {}; }"));
	}
	else
	{
		end_line_(emitter_->definitions_, str(" { return self; }"));
	}

	str const new_function_signature_ = str("inline ").op_add(return_type_)->op_add(str(" new_"))->op_add(type_name_)->op_add(str("()"));
	write_line_(emitter_->function_declarations_, new_function_signature_.op_add(str(";")));
	element_separator_line_(emitter_->definitions_);
	write_line_(emitter_->definitions_, new_function_signature_);
	begin_block_(emitter_->definitions_);
	if (cond(bit_not(is_value_type_)))
	{
		write_line_(emitter_->definitions_, str("return ").op_add(default_constructor_name_)->op_add(str("(new "))->op_add(type_name_)->op_add(str("());")));
	}
	else
	{
		write_line_(emitter_->definitions_, str("return ").op_add(default_constructor_name_)->op_add(str("();")));
	}

	end_block_(emitter_->definitions_);
}

auto emit_declaration_(Emitter *_Nonnull const emitter_, Semantic_Node const *_Nonnull const declaration_) -> void
{
	if (cond(equal_op(declaration_->kind_, GlobalDeclaration_)))
	{
		Semantic_Node const *_Nonnull const variable_declaration_ = first_child_(declaration_, VariableDeclaration_);
		str const variable_name_ = get_text_(first_child_(variable_declaration_, Identifier_));
		Semantic_Node const *_Nonnull const variable_type_ = variable_declaration_->children_->op_Element(i32(2));
		bit const mutable_binding_ = node_has_child_(variable_declaration_, VarKeyword_);
		str const cpp_type_ = convert_type_(mutable_binding_, variable_type_);
		begin_line_(emitter_->global_definitions_, cpp_type_);
		write_(emitter_->global_definitions_, str(" ").op_add(variable_name_)->op_add(str("_ = ")));
		Semantic_Node const *_Nonnull const expression_ = variable_declaration_->children_->op_Element(i32(3));
		convert_expression_(expression_, emitter_->global_definitions_);
		end_line_(emitter_->global_definitions_, str(";"));
	}
	else if (cond(equal_op(declaration_->kind_, ClassDeclaration_)))
	{
		Type const *_Nonnull const declared_type_ = declaration_->declares_type_;
		assert_(not_equal_op(declared_type_, none), get_text_(first_child_(declaration_, Identifier_)));
		str const class_name_ = mangle_name_(declared_type_->name_);
		write_line_(emitter_->type_declarations_, str("typedef struct ").op_add(class_name_)->op_add(str(" "))->op_add(class_name_)->op_add(str(";")));
		element_separator_line_(emitter_->class_declarations_);
		write_line_(emitter_->class_declarations_, str("struct ").op_add(class_name_));
		begin_block_(emitter_->class_declarations_);
		bit has_constructors_ = bit_false;
		for (Semantic_Node const *_Nonnull const member_ : *(node_members_(declaration_)))
		{
			has_constructors_ = bit_op(bit_arg(has_constructors_) || bit_arg(equal_op(member_->kind_, ConstructorDeclaration_)));
			emit_member_declaration_(emitter_, member_, class_name_, bit_false);
		}

		if (cond(bit_not(has_constructors_)))
		{
			emit_default_constructor_(emitter_, class_name_, bit_false);
		}

		end_block_with_semicolon_(emitter_->class_declarations_);
	}
	else if (cond(equal_op(declaration_->kind_, StructDeclaration_)))
	{
		Type const *_Nonnull const declared_type_ = declaration_->declares_type_;
		assert_(not_equal_op(declared_type_, none), get_text_(first_child_(declaration_, Identifier_)));
		str const struct_name_ = mangle_name_(declared_type_->name_);
		write_line_(emitter_->type_declarations_, str("typedef struct ").op_add(struct_name_)->op_add(str(" "))->op_add(struct_name_)->op_add(str(";")));
		element_separator_line_(emitter_->class_declarations_);
		write_line_(emitter_->class_declarations_, str("struct ").op_add(struct_name_));
		begin_block_(emitter_->class_declarations_);
		write_line_(emitter_->class_declarations_, struct_name_.op_add(str(" * operator->() { return this; }")));
		write_line_(emitter_->class_declarations_, struct_name_.op_add(str(" const * operator->() const { return this; }")));
		write_line_(emitter_->class_declarations_, struct_name_.op_add(str(" & operator* () { return *this; }")));
		write_line_(emitter_->class_declarations_, struct_name_.op_add(str(" const & operator* () const { return *this; }")));
		bit has_constructors_ = bit_false;
		for (Semantic_Node const *_Nonnull const member_ : *(node_members_(declaration_)))
		{
			has_constructors_ = bit_op(bit_arg(has_constructors_) || bit_arg(equal_op(member_->kind_, ConstructorDeclaration_)));
			emit_member_declaration_(emitter_, member_, struct_name_, bit_true);
		}

		if (cond(bit_not(has_constructors_)))
		{
			emit_default_constructor_(emitter_, struct_name_, bit_true);
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
		for (Semantic_Node const *_Nonnull const member_ : *(declaration_->children_))
		{
			if (cond(equal_op(member_->kind_, EnumMemberDeclaration_)))
			{
				str const member_name_ = get_text_(member_->children_->op_Element(i32(0)));
				begin_line_(emitter_->class_declarations_, member_name_.op_add(str("_")));
				Semantic_Node const *_Nullable const member_value_ = first_child_(member_, Number_);
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
		Semantic_Node const *_Nonnull const return_type_node_ = declaration_->children_->op_Element(i32(3));
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

auto emit_compilation_unit_(Emitter *_Nonnull const emitter_, Compilation_Unit const *_Nonnull const unit_) -> void
{
	for (Semantic_Node const *_Nonnull const declaration_ : *(unit_->declarations_))
	{
		emit_declaration_(emitter_, declaration_);
	}
}

auto emit_preamble_(Emitter *_Nonnull const emitter_) -> void
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

auto emit_entry_point_adapter_(Emitter *_Nonnull const emitter_) -> void
{
	element_separator_line_(emitter_->definitions_);
	write_line_(emitter_->definitions_, str("// Entry Point Adapter"));
	write_line_(emitter_->definitions_, str("std::int32_t main(int argc, char const *const * argv)"));
	begin_block_(emitter_->definitions_);
	write_line_(emitter_->definitions_, str("try"));
	begin_block_(emitter_->definitions_);
	for (Source_Text const *_Nonnull const resource_ : *(emitter_->resources_))
	{
		begin_line_(emitter_->definitions_, str("resource_manager_->AddResource(string(\""));
		write_(emitter_->definitions_, resource_->name_);
		write_(emitter_->definitions_, str("\"), string(\""));
		write_(emitter_->definitions_, resource_->text_.Replace_(str("\\"), str("\\\\"))->Replace_(str("\n"), str("\\n"))->Replace_(str("\r"), str("\\r"))->Replace_(str("\""), str("\\\"")));
		end_line_(emitter_->definitions_, str("\"));"));
	}

	if (cond(emitter_->resources_->op_magnitude()->op_greater_than(i32(0))))
	{
		end_line_(emitter_->definitions_, str(""));
	}

	system__text__String_Builder *_Nonnull const args_ = new_system__text__String_Builder();
	if (cond(emitter_->main_function_accepts_console_))
	{
		args_->Append_(str("new system__console__Console()"));
	}

	if (cond(emitter_->main_function_accepts_args_))
	{
		if (cond(emitter_->main_function_accepts_console_))
		{
			args_->Append_(str(", "));
		}

		args_->Append_(str("new system__console__Arguments(argc, argv)"));
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

Name *_Nonnull c_Name__global_namespace(Name *_Nonnull self)
{
	self->package_ = none;
	self->kind_ = NamespaceName_;
	self->segments_ = new_system__collections__List<str>();
	self->is_special_ = bit_false;
	return self;
}

inline Name *_Nonnull new_Name__global_namespace()
{
	return c_Name__global_namespace(new Name());
}

Name *_Nonnull c_Name__global_namespace(Name *_Nonnull self, Package_Name const *_Nonnull const package_)
{
	assert_(not_equal_op(package_, none), str(""));
	self->package_ = package_;
	self->kind_ = NamespaceName_;
	self->segments_ = new_system__collections__List<str>();
	self->is_special_ = bit_false;
	return self;
}

inline Name *_Nonnull new_Name__global_namespace(Package_Name const *_Nonnull const package_)
{
	return c_Name__global_namespace(new Name(), package_);
}

Name *_Nonnull c_Name(Name *_Nonnull self, Name const *_Nonnull const qualifier_, i32 const kind_, str const name_)
{
	assert_(not_equal_op(qualifier_, none), str(""));
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	self->package_ = qualifier_->package_;
	self->kind_ = kind_;
	system__collections__List<str> *_Nonnull const segments_ = new_system__collections__List<str>();
	for (str const segment_ : *(qualifier_->segments_))
	{
		segments_->add_(segment_);
	}

	segments_->add_(name_);
	self->segments_ = segments_;
	self->is_special_ = bit_false;
	return self;
}

inline Name *_Nonnull new_Name(Name const *_Nonnull const qualifier_, i32 const kind_, str const name_)
{
	return c_Name(new Name(), qualifier_, kind_, name_);
}

Name *_Nonnull c_Name(Name *_Nonnull self, Name const *_Nonnull const qualifier_, i32 const kind_, str const name_, bit const is_special_)
{
	assert_(not_equal_op(qualifier_, none), str(""));
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	self->package_ = qualifier_->package_;
	self->kind_ = kind_;
	system__collections__List<str> *_Nonnull const segments_ = new_system__collections__List<str>();
	for (str const segment_ : *(qualifier_->segments_))
	{
		segments_->add_(segment_);
	}

	segments_->add_(name_);
	self->segments_ = segments_;
	self->is_special_ = is_special_;
	return self;
}

inline Name *_Nonnull new_Name(Name const *_Nonnull const qualifier_, i32 const kind_, str const name_, bit const is_special_)
{
	return c_Name(new Name(), qualifier_, kind_, name_, is_special_);
}

Name *_Nonnull c_Name__special(Name *_Nonnull self, Name const *_Nonnull const qualifier_, i32 const kind_, str const name_)
{
	assert_(not_equal_op(qualifier_, none), str(""));
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	self->package_ = qualifier_->package_;
	self->kind_ = kind_;
	system__collections__List<str> *_Nonnull const segments_ = new_system__collections__List<str>();
	for (str const segment_ : *(qualifier_->segments_))
	{
		segments_->add_(segment_);
	}

	segments_->add_(name_);
	self->segments_ = segments_;
	self->is_special_ = bit_true;
	return self;
}

inline Name *_Nonnull new_Name__special(Name const *_Nonnull const qualifier_, i32 const kind_, str const name_)
{
	return c_Name__special(new Name(), qualifier_, kind_, name_);
}

Name *_Nonnull c_Name(Name *_Nonnull self, Package_Name const *_Nullable const package_, i32 const kind_, system__collections__List<str> const *_Nonnull const segments_, bit const is_special_)
{
	self->package_ = package_;
	self->kind_ = kind_;
	self->segments_ = segments_;
	self->is_special_ = is_special_;
	return self;
}

inline Name *_Nonnull new_Name(Package_Name const *_Nullable const package_, i32 const kind_, system__collections__List<str> const *_Nonnull const segments_, bit const is_special_)
{
	return c_Name(new Name(), package_, kind_, segments_, is_special_);
}

auto unqualified_name_(Name const *_Nonnull const name_) -> str
{
	if (cond(equal_op(name_->segments_->op_magnitude(), i32(0))))
	{
		return str("");
	}

	return name_->segments_->op_Element(name_->segments_->op_magnitude()->op_subtract(i32(1)));
}

auto full_name_(Name const *_Nonnull const name_) -> str
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

auto is_qualified_by_(Name const *_Nonnull const name_, Name const *_Nonnull const qualifier_) -> bit
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

auto qualifier_is_(Name const *_Nonnull const name_, Name const *_Nonnull const qualifier_) -> bit
{
	return bit_op(bit_arg(equal_op(qualifier_->segments_->op_magnitude()->op_add(i32(1)), name_->segments_->op_magnitude())) && bit_arg(is_qualified_by_(name_, qualifier_)));
}

auto names_(Name const *_Nonnull const name_, Name const *_Nonnull const other_) -> bit
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

auto is_package_qualified_(Name const *_Nonnull const name_) -> bit
{
	return not_equal_op(name_->package_, none);
}

auto remove_package_(Name const *_Nonnull const name_) -> Name const *_Nonnull
{
	if (cond(equal_op(name_->package_, none)))
	{
		return name_;
	}
	else
	{
		return new_Name(none, name_->kind_, name_->segments_, name_->is_special_);
	}
}

auto unit_test_Name_() -> void
{
	name_with_unspecified_package_names_name_with_package_();
	name_with_unspecified_package_names_itself_();
}

auto name_with_unspecified_package_names_name_with_package_() -> void
{
	Name const *_Nonnull const name_without_package_ = new_Name(new_Name__global_namespace(), NamespaceName_, str("system"));
	Name const *_Nonnull const name_with_package_ = new_Name(new_Name__global_namespace(new_Package_Name(str("package"))), NamespaceName_, str("system"));
	assert_(names_(name_without_package_, name_with_package_), str(""));
}

auto name_with_unspecified_package_names_itself_() -> void
{
	Name const *_Nonnull const name_without_package_ = new_Name(new_Name__global_namespace(), NamespaceName_, str("system"));
	assert_(names_(name_without_package_, name_without_package_), str(""));
}

Package_Name *_Nonnull c_Package_Name(Package_Name *_Nonnull self, str const name_)
{
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	self->unqualified_ = name_;
	return self;
}

inline Package_Name *_Nonnull new_Package_Name(str const name_)
{
	return c_Package_Name(new Package_Name(), name_);
}

auto full_name_(Package_Name const *_Nonnull const package_name_) -> str
{
	return package_name_->unqualified_;
}

Symbol *_Nonnull c_Symbol__identifier(Symbol *_Nonnull self, str const name_)
{
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = bit_false;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	self->children_ = new_system__collections__List<Symbol const *_Nonnull>();
	return self;
}

inline Symbol *_Nonnull new_Symbol__identifier(str const name_)
{
	return c_Symbol__identifier(new Symbol(), name_);
}

Symbol *_Nonnull c_Symbol__identifier(Symbol *_Nonnull self, str const name_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_)
{
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	assert_(not_equal_op(declarations_, none), str("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = bit_false;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = declarations_;
	self->children_ = new_system__collections__List<Symbol const *_Nonnull>();
	return self;
}

inline Symbol *_Nonnull new_Symbol__identifier(str const name_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_)
{
	return c_Symbol__identifier(new Symbol(), name_, declarations_);
}

Symbol *_Nonnull c_Symbol__identifier(Symbol *_Nonnull self, str const name_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_)
{
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	assert_(not_equal_op(children_, none), str("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = bit_false;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	self->children_ = children_;
	return self;
}

inline Symbol *_Nonnull new_Symbol__identifier(str const name_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_)
{
	return c_Symbol__identifier(new Symbol(), name_, children_);
}

Symbol *_Nonnull c_Symbol__constructor(Symbol *_Nonnull self, str const name_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_)
{
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	assert_(not_equal_op(declarations_, none), str("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = IdentifierSymbol_;
	self->is_special_name_ = bit_true;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = declarations_;
	self->children_ = new_system__collections__List<Symbol const *_Nonnull>();
	return self;
}

inline Symbol *_Nonnull new_Symbol__constructor(str const name_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_)
{
	return c_Symbol__constructor(new Symbol(), name_, declarations_);
}

Symbol *_Nonnull c_Symbol__package(Symbol *_Nonnull self, str const name_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_)
{
	assert_(name_.ByteLength_()->op_greater_than(i32(0)), str(""));
	assert_(not_equal_op(children_, none), str("name=").op_add(name_));
	self->name_ = name_;
	self->kind_ = PackageSymbol_;
	self->is_special_name_ = bit_false;
	self->of_type_ = none;
	self->declares_type_ = none;
	self->declarations_ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	self->children_ = children_;
	return self;
}

inline Symbol *_Nonnull new_Symbol__package(str const name_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_)
{
	return c_Symbol__package(new Symbol(), name_, children_);
}

Symbol *_Nonnull c_Symbol__declaring(Symbol *_Nonnull self, Type const *_Nonnull const declares_type_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_)
{
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

inline Symbol *_Nonnull new_Symbol__declaring(Type const *_Nonnull const declares_type_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_)
{
	return c_Symbol__declaring(new Symbol(), declares_type_, declarations_, children_);
}

Symbol *_Nonnull c_Symbol__of_type(Symbol *_Nonnull self, str const name_, Type const *_Nonnull const of_type_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_)
{
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

inline Symbol *_Nonnull new_Symbol__of_type(str const name_, Type const *_Nonnull const of_type_, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations_, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children_)
{
	return c_Symbol__of_type(new Symbol(), name_, of_type_, declarations_, children_);
}

auto get_child_(Symbol const *_Nonnull const symbol_, str const name_, i32 const kind_) -> Symbol const *_Nullable
{
	for (Symbol const *_Nonnull const child_ : *(symbol_->children_))
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
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const children_ = new_system__collections__List<Symbol const *_Nonnull>();
	children_->add_(new_Symbol__identifier(str("child")));
	Symbol const *_Nonnull const package_with_children_ = new_Symbol__package(str("package"), children_);
	assert_(not_equal_op(get_child_(package_with_children_, str("child"), IdentifierSymbol_), none), str(""));
}

Type *_Nonnull c_Type(Type *_Nonnull self, i32 const kind_, Name const *_Nonnull const name_, bit const is_mutable_)
{
	assert_(not_equal_op(name_, none), str(""));
	self->kind_ = kind_;
	self->name_ = name_;
	self->type_parameters_ = new_system__collections__List<Type const *_Nonnull>();
	self->is_primitive_ = bit_false;
	self->is_value_type_ = equal_op(kind_, ValueType_);
	self->is_potentially_mutable_ = is_mutable_;
	self->is_mutable_ = is_mutable_;
	return self;
}

inline Type *_Nonnull new_Type(i32 const kind_, Name const *_Nonnull const name_, bit const is_mutable_)
{
	return c_Type(new Type(), kind_, name_, is_mutable_);
}

Type *_Nonnull c_Type__parameter(Type *_Nonnull self, str const name_)
{
	self->kind_ = TypeParameterType_;
	self->name_ = new_Name(new_Name__global_namespace(), TypeParameterName_, name_);
	self->type_parameters_ = new_system__collections__List<Type const *_Nonnull>();
	self->is_primitive_ = bit_false;
	self->is_value_type_ = bit_false;
	self->is_potentially_mutable_ = bit_true;
	self->is_mutable_ = bit_false;
	return self;
}

inline Type *_Nonnull new_Type__parameter(str const name_)
{
	return c_Type__parameter(new Type(), name_);
}

Type *_Nonnull c_Type(Type *_Nonnull self, i32 const kind_, Name const *_Nonnull const name_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_mutable_)
{
	self->kind_ = kind_;
	self->name_ = name_;
	self->type_parameters_ = type_parameters_;
	self->is_primitive_ = bit_false;
	self->is_value_type_ = equal_op(kind_, ValueType_);
	self->is_potentially_mutable_ = is_mutable_;
	self->is_mutable_ = is_mutable_;
	return self;
}

inline Type *_Nonnull new_Type(i32 const kind_, Name const *_Nonnull const name_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_mutable_)
{
	return c_Type(new Type(), kind_, name_, type_parameters_, is_mutable_);
}

Type *_Nonnull c_Type__primitive(Type *_Nonnull self, Name const *_Nonnull const name_)
{
	self->kind_ = ValueType_;
	self->name_ = name_;
	self->type_parameters_ = new_system__collections__List<Type const *_Nonnull>();
	self->is_primitive_ = bit_true;
	self->is_value_type_ = bit_true;
	self->is_potentially_mutable_ = bit_false;
	self->is_mutable_ = bit_false;
	return self;
}

inline Type *_Nonnull new_Type__primitive(Name const *_Nonnull const name_)
{
	return c_Type__primitive(new Type(), name_);
}

Type *_Nonnull c_Type__primitive(Type *_Nonnull self, Name const *_Nonnull const name_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_)
{
	self->kind_ = ValueType_;
	self->name_ = name_;
	self->type_parameters_ = type_parameters_;
	self->is_primitive_ = bit_true;
	self->is_value_type_ = bit_true;
	self->is_potentially_mutable_ = bit_false;
	self->is_mutable_ = bit_false;
	return self;
}

inline Type *_Nonnull new_Type__primitive(Name const *_Nonnull const name_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_)
{
	return c_Type__primitive(new Type(), name_, type_parameters_);
}

Type *_Nonnull c_Type__namespace(Type *_Nonnull self, Name const *_Nonnull const name_)
{
	self->kind_ = NamespaceType_;
	self->name_ = name_;
	self->is_primitive_ = bit_false;
	self->type_parameters_ = new_system__collections__List<Type const *_Nonnull>();
	self->is_value_type_ = bit_true;
	self->is_potentially_mutable_ = bit_false;
	self->is_mutable_ = bit_false;
	return self;
}

inline Type *_Nonnull new_Type__namespace(Name const *_Nonnull const name_)
{
	return c_Type__namespace(new Type(), name_);
}

Type *_Nonnull c_Type__generic(Type *_Nonnull self, Type const *_Nonnull const definition_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_arguments_)
{
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

inline Type *_Nonnull new_Type__generic(Type const *_Nonnull const definition_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_arguments_)
{
	return c_Type__generic(new Type(), definition_, type_arguments_);
}

Type *_Nonnull c_Type(Type *_Nonnull self, i32 const kind_, Name const *_Nonnull const name_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_primitive_, bit const is_potentially_mutable_, bit const is_mutable_)
{
	self->kind_ = kind_;
	self->name_ = name_;
	self->type_parameters_ = type_parameters_;
	self->is_primitive_ = is_primitive_;
	self->is_value_type_ = equal_op(kind_, ValueType_);
	self->is_potentially_mutable_ = is_potentially_mutable_;
	self->is_mutable_ = is_mutable_;
	return self;
}

inline Type *_Nonnull new_Type(i32 const kind_, Name const *_Nonnull const name_, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters_, bit const is_primitive_, bit const is_potentially_mutable_, bit const is_mutable_)
{
	return c_Type(new Type(), kind_, name_, type_parameters_, is_primitive_, is_potentially_mutable_, is_mutable_);
}

auto make_mutable_type_(Type const *_Nonnull const type_) -> Type const *_Nonnull
{
	assert_(type_->is_potentially_mutable_, str("self.name=").op_add(full_name_(type_->name_)));
	return new_Type(type_->kind_, type_->name_, type_->type_parameters_, type_->is_primitive_, type_->is_potentially_mutable_, bit_true);
}

auto make_immutable_type_(Type const *_Nonnull const type_) -> Type const *_Nonnull
{
	return new_Type(type_->kind_, type_->name_, type_->type_parameters_, type_->is_primitive_, type_->is_potentially_mutable_, bit_false);
}

auto remove_type_package_(Type const *_Nonnull const type_) -> Type const *_Nonnull
{
	assert_(equal_op(type_->kind_, NamespaceType_), str("kind=").op_add(type_->kind_));
	if (cond(is_package_qualified_(type_->name_)))
	{
		return new_Type(type_->kind_, remove_package_(type_->name_), type_->type_parameters_, type_->is_primitive_, type_->is_potentially_mutable_, type_->is_mutable_);
	}
	else
	{
		return type_;
	}
}

Name_Subtable *_Nonnull c_Name_Subtable__global_namespace(Name_Subtable *_Nonnull self, Name_Table const *_Nonnull const name_table_)
{
	self->name_table_ = name_table_;
	self->parent_ = none;
	self->name_ = new_Name__global_namespace();
	self->type_ = new_Type__namespace(self->name_);
	self->subtables_ = new_system__collections__List<Name_Subtable *_Nonnull>();
	return self;
}

inline Name_Subtable *_Nonnull new_Name_Subtable__global_namespace(Name_Table const *_Nonnull const name_table_)
{
	return c_Name_Subtable__global_namespace(new Name_Subtable(), name_table_);
}

Name_Subtable *_Nonnull c_Name_Subtable__global_namespace(Name_Subtable *_Nonnull self, Name_Table const *_Nonnull const name_table_, Package_Name const *_Nonnull const package_name_)
{
	self->name_table_ = name_table_;
	self->parent_ = none;
	self->name_ = new_Name__global_namespace(package_name_);
	self->type_ = new_Type__namespace(self->name_);
	self->subtables_ = new_system__collections__List<Name_Subtable *_Nonnull>();
	return self;
}

inline Name_Subtable *_Nonnull new_Name_Subtable__global_namespace(Name_Table const *_Nonnull const name_table_, Package_Name const *_Nonnull const package_name_)
{
	return c_Name_Subtable__global_namespace(new Name_Subtable(), name_table_, package_name_);
}

Name_Subtable *_Nonnull c_Name_Subtable(Name_Subtable *_Nonnull self, Name_Subtable const *_Nonnull const parent_, Name const *_Nonnull const name_, Type const *_Nonnull const type_)
{
	self->name_table_ = parent_->name_table_;
	self->parent_ = parent_;
	self->name_ = name_;
	self->type_ = type_;
	self->subtables_ = new_system__collections__List<Name_Subtable *_Nonnull>();
	return self;
}

inline Name_Subtable *_Nonnull new_Name_Subtable(Name_Subtable const *_Nonnull const parent_, Name const *_Nonnull const name_, Type const *_Nonnull const type_)
{
	return c_Name_Subtable(new Name_Subtable(), parent_, name_, type_);
}

auto add_subtable_(Name_Subtable *_Nonnull const scope_, Name const *_Nonnull const name_, Type const *_Nonnull const type_) -> void
{
	assert_(is_qualified_by_(name_, scope_->name_), str("\"").op_add(full_name_(name_))->op_add(str("\" is not a child of \""))->op_add(full_name_(scope_->name_))->op_add(str("\"")));
	if (cond(qualifier_is_(name_, scope_->name_)))
	{
		if (cond(bit_op(bit_arg(bit_op(bit_arg(equal_op(scope_->name_->package_, none)) && bit_arg(not_equal_op(type_, none)))) && bit_arg(equal_op(type_->kind_, NamespaceType_)))))
		{
			scope_->subtables_->add_(new_Name_Subtable(scope_, remove_package_(name_), remove_type_package_(type_)));
		}
		else
		{
			scope_->subtables_->add_(new_Name_Subtable(scope_, name_, type_));
		}

		return;
	}

	for (Name_Subtable *_Nonnull const subtable_ : *(scope_->subtables_))
	{
		if (cond(is_qualified_by_(name_, subtable_->name_)))
		{
			add_subtable_(subtable_, name_, type_);
			return;
		}
	}

	assert_(equal_op(name_->segments_->op_magnitude(), scope_->name_->segments_->op_magnitude()->op_add(i32(1))), str("Can't add \"").op_add(full_name_(name_))->op_add(str("\" to \""))->op_add(full_name_(scope_->name_))->op_add(str("\"")));
}

auto find_(Name_Subtable const *_Nonnull const scope_, str const name_) -> Name_Subtable *_Nullable
{
	return find_(scope_, name_, bit_false);
}

auto find_special_(Name_Subtable const *_Nonnull const scope_, str const name_) -> Name_Subtable *_Nullable
{
	return find_(scope_, name_, bit_true);
}

auto find_(Name_Subtable const *_Nonnull const scope_, str const name_, bit const is_special_) -> Name_Subtable *_Nullable
{
	for (Name_Subtable *_Nonnull const subtable_ : *(scope_->subtables_))
	{
		if (cond(bit_op(bit_arg(equal_op(unqualified_name_(subtable_->name_), name_)) && bit_arg(equal_op(subtable_->name_->is_special_, is_special_)))))
		{
			return subtable_;
		}
	}

	return none;
}

auto lookup_(Name_Subtable const *_Nonnull const scope_, str const name_) -> Name_Subtable *_Nullable
{
	return lookup_(scope_, name_, bit_false);
}

auto lookup_special_(Name_Subtable const *_Nonnull const scope_, str const name_) -> Name_Subtable *_Nullable
{
	return lookup_(scope_, name_, bit_true);
}

auto lookup_(Name_Subtable const *_Nonnull const scope_, str const name_, bit const is_special_) -> Name_Subtable *_Nullable
{
	Name_Subtable *_Nullable subtable_ = find_(scope_, name_, is_special_);
	if (cond(bit_op(bit_arg(equal_op(subtable_, none)) && bit_arg(not_equal_op(scope_->parent_, none)))))
	{
		subtable_ = lookup_(scope_->parent_, name_, is_special_);
	}

	return subtable_;
}

auto get_scope_(Name_Subtable const *_Nonnull const scope_, Name const *_Nonnull const name_) -> Name_Subtable const *_Nullable
{
	if (cond(names_(name_, scope_->name_)))
	{
		return scope_;
	}
	else if (cond(bit_not(is_qualified_by_(name_, scope_->name_))))
	{
		return none;
	}

	for (Name_Subtable const *_Nonnull const subtable_ : *(scope_->subtables_))
	{
		Name_Subtable const *_Nullable const value_ = get_scope_(subtable_, name_);
		if (cond(not_equal_op(value_, none)))
		{
			return value_;
		}
	}

	return none;
}

auto bind_type_(Name_Subtable *_Nonnull const scope_, Type const *_Nonnull const type_) -> void
{
	assert_(not_equal_op(type_, none), full_name_(scope_->name_));
	if (cond(not_equal_op(scope_->type_, none)))
	{
		assert_(equal_op(full_name_(scope_->type_->name_), full_name_(type_->name_)), full_name_(scope_->name_)->op_add(str(" currently `"))->op_add(full_name_(scope_->type_->name_))->op_add(str("` trying to set to `"))->op_add(full_name_(type_->name_))->op_add(str("`")));
	}

	scope_->type_ = type_;
}

auto as_mut_(Name_Subtable const *_Nonnull const scope_) -> Name_Subtable *_Nonnull
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
	Name_Table const *_Nonnull const name_table_ = new_Name_Table();
	Name_Subtable *_Nonnull const global_namespace_ = new_Name_Subtable__global_namespace(name_table_);
	Name const *_Nonnull const test_name_ = new_Name(global_namespace_->name_, TypeName_, str("test"));
	add_subtable_(global_namespace_, test_name_, none);
	assert_(not_equal_op(find_(global_namespace_, str("test")), none), str(""));
	assert_(not_equal_op(get_scope_(global_namespace_, test_name_), none), str(""));
}

auto namespace_contains_added_name_() -> void
{
	Name_Table const *_Nonnull const name_table_ = new_Name_Table();
	Name_Subtable *_Nonnull const global_namespace_ = new_Name_Subtable__global_namespace(name_table_);
	Name const *_Nonnull const namespace_name_ = new_Name(global_namespace_->name_, NamespaceName_, str("namespace"));
	add_subtable_(global_namespace_, namespace_name_, none);
	add_subtable_(global_namespace_, new_Name(namespace_name_, TypeName_, str("test")), none);
	Name_Subtable const *_Nonnull const namespace_ = find_(global_namespace_, str("namespace"));
	assert_(not_equal_op(find_(namespace_, str("test")), none), str(""));
}

Name_Table *_Nonnull c_Name_Table(Name_Table *_Nonnull self)
{
	self->any_package_ = new_Name_Subtable__global_namespace(self);
	self->packages_ = new_system__collections__List<Name_Subtable *_Nonnull>();
	return self;
}

inline Name_Table *_Nonnull new_Name_Table()
{
	return c_Name_Table(new Name_Table());
}

auto add_package_(Name_Table *_Nonnull const name_table_, Package_Name const *_Nonnull const package_name_) -> Name const *_Nonnull
{
	Name_Subtable *_Nonnull const subtable_ = new_Name_Subtable__global_namespace(name_table_, package_name_);
	name_table_->packages_->add_(subtable_);
	return subtable_->name_;
}

auto add_name_(Name_Table *_Nonnull const name_table_, Name const *_Nonnull const parent_, Symbol const *_Nonnull const symbol_) -> Name const *_Nonnull
{
	Name const *_Nonnull name_;
	if (cond(not_equal_op(symbol_->declares_type_, none)))
	{
		name_ = new_Name(parent_, TypeName_, symbol_->name_, symbol_->is_special_name_);
		add_name_(name_table_, name_, symbol_->declares_type_);
	}
	else
	{
		name_ = new_Name(parent_, FunctionName_, symbol_->name_, symbol_->is_special_name_);
		add_name_(name_table_, name_, symbol_->of_type_);
	}

	return name_;
}

auto add_name_(Name_Table *_Nonnull const name_table_, Name const *_Nonnull const name_, Type const *_Nonnull const type_) -> void
{
	add_subtable_(name_table_->any_package_, name_, type_);
	for (Name_Subtable *_Nonnull const package_ : *(name_table_->packages_))
	{
		if (cond(is_qualified_by_(name_, package_->name_)))
		{
			add_subtable_(package_, name_, type_);
			return;
		}
	}

	THROW_EXCEPTION_(str("Can't add name \"").op_add(full_name_(name_))->op_add(str("\" because package doesn't exist in table.")));
}

auto get_name_(Name_Table const *_Nonnull const name_table_, Name const *_Nonnull const name_) -> Name_Subtable const *_Nullable
{
	if (cond(equal_op(name_->package_, none)))
	{
		return get_scope_(name_table_->any_package_, name_);
	}

	for (Name_Subtable const *_Nonnull const package_ : *(name_table_->packages_))
	{
		if (cond(is_qualified_by_(name_, package_->name_)))
		{
			return get_scope_(package_, name_);
		}
	}

	return none;
}

auto build_name_table_(Package_Name const *_Nonnull const package_name_, Syntax_Node const *_Nonnull const package_syntax_, system__collections__List<Package_Reference> const *_Nonnull const references_) -> Name_Table const *_Nonnull
{
	assert_(equal_op(package_syntax_->kind_, PackageNode_), str("package_syntax.kind=").op_add(package_syntax_->kind_));
	Name_Table *_Nonnull const name_table_ = new_Name_Table();
	add_referenced_(name_table_, references_);
	add_package_(name_table_, package_name_, package_syntax_);
	return name_table_;
}

auto add_referenced_(Name_Table *_Nonnull const name_table_, system__collections__List<Package_Reference> const *_Nonnull const references_) -> void
{
	for (Package_Reference const reference_ : *(references_))
	{
		Package_Name const *_Nonnull const reference_name_ = new_Package_Name(reference_.name_);
		Name const *_Nonnull const global_namespace_ = add_package_(name_table_, reference_name_);
		for (Symbol const *_Nonnull const symbol_ : *(reference_.package_->symbol_->children_))
		{
			add_symbol_(name_table_, global_namespace_, symbol_);
		}
	}
}

auto add_symbol_(Name_Table *_Nonnull const name_table_, Name const *_Nonnull const parent_, Symbol const *_Nonnull const symbol_) -> void
{
	Name const *_Nonnull const name_ = add_name_(name_table_, parent_, symbol_);
	for (Symbol const *_Nonnull const child_ : *(symbol_->children_))
	{
		add_symbol_(name_table_, name_, child_);
	}
}

auto add_package_(Name_Table *_Nonnull const name_table_, Package_Name const *_Nonnull const package_name_, Syntax_Node const *_Nonnull const package_syntax_) -> void
{
	assert_(equal_op(package_syntax_->kind_, PackageNode_), str("package_syntax.kind=").op_add(package_syntax_->kind_));
	Name const *_Nonnull const global_namespace_ = add_package_(name_table_, package_name_);
	for (Syntax_Node const *_Nonnull const compilation_unit_ : *(package_syntax_->children_))
	{
		add_compilation_unit_(name_table_, global_namespace_, compilation_unit_);
	}
}

auto add_compilation_unit_(Name_Table *_Nonnull const name_table_, Name const *_Nonnull const global_namespace_, Syntax_Node const *_Nonnull const compilation_unit_) -> void
{
	assert_(equal_op(compilation_unit_->kind_, CompilationUnit_), str("compilation_unit.kind=").op_add(compilation_unit_->kind_));
	for (Syntax_Node const *_Nonnull const declaration_ : *(compilation_unit_->children_))
	{
		add_syntax_(name_table_, global_namespace_, declaration_);
	}
}

auto add_syntax_(Name_Table *_Nonnull const name_table_, Name const *_Nonnull const parent_, Syntax_Node const *_Nonnull const syntax_) -> void
{
	if (cond(bit_op(bit_arg(equal_op(syntax_->kind_, FunctionDeclaration_)) || bit_arg(equal_op(syntax_->kind_, MethodDeclaration_)))))
	{
		Name const *_Nonnull const name_ = new_Name(parent_, FunctionName_, get_text_(first_child_syntax_(syntax_, Identifier_)));
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

		Name const *_Nonnull const name_ = new_Name(parent_, TypeName_, unqualified_name_);
		Type const *_Nonnull const type_ = new_Type(type_kind_, name_, bit_true);
		add_name_(name_table_, name_, type_);
		for (Syntax_Node const *_Nonnull const member_ : *(members_(syntax_)))
		{
			add_syntax_(name_table_, name_, member_);
		}
	}
	else if (cond(equal_op(syntax_->kind_, ConstructorDeclaration_)))
	{
		str full_name_ = str("new");
		Syntax_Node const *_Nullable const constructor_name_ = first_child_syntax_(syntax_, Identifier_);
		if (cond(not_equal_op(constructor_name_, none)))
		{
			full_name_ = str("new_").op_add(get_text_(constructor_name_));
		}

		Name const *_Nonnull const name_ = new_Name__special(parent_, FunctionName_, full_name_);
		add_function_(name_table_, name_, syntax_);
		Name const *_Nonnull const self_name_ = new_Name__special(name_, VariableName_, str("self"));
		Type const *_Nonnull const self_type_ = none;
		add_name_(name_table_, self_name_, self_type_);
	}
	else if (cond(equal_op(syntax_->kind_, FieldDeclaration_)))
	{
		str const unqualified_name_ = get_text_(first_child_syntax_(first_child_syntax_(syntax_, VariableDeclaration_), Identifier_));
		Name const *_Nonnull const name_ = new_Name(parent_, TypeName_, unqualified_name_);
		Type const *_Nullable const no_type_ = none;
		add_name_(name_table_, name_, no_type_);
	}
	else if (cond(equal_op(syntax_->kind_, EnumDeclaration_)))
	{
		str const unqualified_name_ = get_text_(first_child_syntax_(syntax_, Identifier_));
		Name const *_Nonnull const name_ = new_Name(parent_, TypeName_, unqualified_name_);
		Type const *_Nonnull const type_ = new_Type(ReferenceType_, name_, bit_true);
		add_name_(name_table_, name_, type_);
	}
	else if (cond(equal_op(syntax_->kind_, GlobalDeclaration_)))
	{
		str const unqualified_name_ = get_text_(first_child_syntax_(first_child_syntax_(syntax_, VariableDeclaration_), Identifier_));
		Name const *_Nonnull const name_ = new_Name(parent_, TypeName_, unqualified_name_);
		Type const *_Nullable const no_type_ = none;
		add_name_(name_table_, name_, no_type_);
	}
	else if (cond(equal_op(syntax_->kind_, Block_)))
	{
		for (Syntax_Node const *_Nonnull const statement_ : *(statements_(syntax_)))
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
		Syntax_Node const *_Nonnull const identifier_ = first_child_syntax_(first_child_syntax_(syntax_, VariableDeclaration_), Identifier_);
		Name const *_Nonnull const name_ = new_Name(parent_, VariableName_, get_text_(identifier_));
		Type const *_Nullable const no_type_ = none;
		add_name_(name_table_, name_, no_type_);
		add_syntax_(name_table_, parent_, first_child_syntax_(syntax_, Block_));
	}
	else if (cond(equal_op(syntax_->kind_, IfStatement_)))
	{
		add_syntax_(name_table_, parent_, first_child_syntax_(syntax_, Block_));
		Syntax_Node const *_Nullable const else_clause_ = first_child_syntax_(syntax_, ElseClause_);
		if (cond(not_equal_op(else_clause_, none)))
		{
			add_syntax_(name_table_, parent_, else_clause_);
		}
	}
	else if (cond(equal_op(syntax_->kind_, ElseClause_)))
	{
		Syntax_Node const *_Nullable const block_ = first_child_syntax_(syntax_, Block_);
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
		Syntax_Node const *_Nonnull const identifier_ = first_child_syntax_(first_child_syntax_(syntax_, VariableDeclaration_), Identifier_);
		Name const *_Nonnull const name_ = new_Name(parent_, VariableName_, get_text_(identifier_));
		Type const *_Nullable const no_type_ = none;
		add_name_(name_table_, name_, no_type_);
	}
	else if (cond(equal_op(syntax_->kind_, Parameter_)))
	{
		Syntax_Node const *_Nonnull const identifier_ = first_child_syntax_(syntax_, Identifier_);
		Name const *_Nonnull const name_ = new_Name(parent_, VariableName_, get_text_(identifier_));
		Type const *_Nullable const no_type_ = none;
		add_name_(name_table_, name_, no_type_);
	}
	else if (cond(equal_op(syntax_->kind_, SelfParameter_)))
	{
		Name const *_Nonnull const name_ = new_Name__special(parent_, VariableName_, str("self"));
		Type const *_Nullable const no_type_ = none;
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

auto add_function_(Name_Table *_Nonnull const name_table_, Name const *_Nonnull const name_, Syntax_Node const *_Nonnull const function_) -> void
{
	Type const *_Nullable const no_type_ = none;
	add_name_(name_table_, name_, no_type_);
	Syntax_Node const *_Nonnull const parameters_syntax_ = first_child_syntax_(function_, ParameterList_);
	for (Syntax_Node const *_Nonnull const parameter_ : *(parameters_(parameters_syntax_)))
	{
		add_syntax_(name_table_, name_, parameter_);
	}

	Syntax_Node const *_Nonnull const body_ = first_child_syntax_(function_, Block_);
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
	Package_Name const *_Nonnull const name_ = new_Package_Name(str("default"));
	Package const *_Nonnull const runtime_package_ = build_runtime_library_package_();
	system__collections__List<Package_Reference> *_Nonnull const references_ = new_system__collections__List<Package_Reference>();
	references_->add_(new_Package_Reference(runtime_package_));
	Syntax_Node const *_Nonnull const package_syntax_ = new_Syntax_Node(PackageNode_, none, i32(0), i32(0));
	Name_Table const *_Nonnull const name_table_ = build_name_table_(name_, package_syntax_, references_);
	Name_Subtable const *_Nonnull const namespace_ = find_(name_table_->any_package_, str("system"));
	assert_(not_equal_op(find_(namespace_, str("console")), none), str(""));
	Name const *_Nonnull const system_namespace_name_ = new_Name(new_Name__global_namespace(), NamespaceName_, str("system"));
	assert_(not_equal_op(get_name_(name_table_, system_namespace_name_), none), str(""));
	Name const *_Nonnull const console_namespace_name_ = new_Name(system_namespace_name_, NamespaceName_, str("console"));
	assert_(not_equal_op(get_name_(name_table_, console_namespace_name_), none), str(""));
	Name const *_Nonnull const console_class_name_ = new_Name(console_namespace_name_, TypeName_, str("Console"));
	assert_(not_equal_op(get_name_(name_table_, console_class_name_), none), str(""));
}

auto can_get_root_namespace_from_name_() -> void
{
	Package_Name const *_Nonnull const name_ = new_Package_Name(str("default"));
	Package const *_Nonnull const runtime_package_ = build_runtime_library_package_();
	system__collections__List<Package_Reference> *_Nonnull const references_ = new_system__collections__List<Package_Reference>();
	references_->add_(new_Package_Reference(runtime_package_));
	Syntax_Node const *_Nonnull const package_syntax_ = new_Syntax_Node(PackageNode_, none, i32(0), i32(0));
	Name_Table const *_Nonnull const name_table_ = build_name_table_(name_, package_syntax_, references_);
	Name const *_Nonnull const namespace_name_ = new_Name(new_Name__global_namespace(), NamespaceName_, str("system"));
	assert_(not_equal_op(get_name_(name_table_, namespace_name_), none), str(""));
}

auto can_get_Console_class_from_name_without_package_() -> void
{
	Package_Name const *_Nonnull const name_ = new_Package_Name(str("default"));
	Package const *_Nonnull const runtime_package_ = build_runtime_library_package_();
	system__collections__List<Package_Reference> *_Nonnull const references_ = new_system__collections__List<Package_Reference>();
	references_->add_(new_Package_Reference(runtime_package_));
	Syntax_Node const *_Nonnull const package_syntax_ = new_Syntax_Node(PackageNode_, none, i32(0), i32(0));
	Name_Table const *_Nonnull const name_table_ = build_name_table_(name_, package_syntax_, references_);
	Name const *_Nonnull const system_namespace_name_ = new_Name(new_Name__global_namespace(), NamespaceName_, str("system"));
	Name const *_Nonnull const console_namespace_name_ = new_Name(system_namespace_name_, NamespaceName_, str("console"));
	Name const *_Nonnull const console_class_name_ = new_Name(console_namespace_name_, TypeName_, str("Console"));
	assert_(not_equal_op(get_name_(name_table_, console_class_name_), none), str(""));
}

auto can_get_Optional_class_from_name_with_package_() -> void
{
	Package_Name const *_Nonnull const name_ = new_Package_Name(str("default"));
	Package const *_Nonnull const primitives_package_ = build_primitives_package_();
	system__collections__List<Package_Reference> *_Nonnull const references_ = new_system__collections__List<Package_Reference>();
	references_->add_(new_Package_Reference(primitives_package_));
	Syntax_Node const *_Nonnull const package_syntax_ = new_Syntax_Node(PackageNode_, none, i32(0), i32(0));
	Name_Table const *_Nonnull const name_table_ = build_name_table_(name_, package_syntax_, references_);
	Package_Name const *_Nonnull const package_name_ = new_Package_Name(str("$primitives"));
	Name const *_Nonnull const adamant_namespace_name_ = new_Name(new_Name__global_namespace(), NamespaceName_, str("adamant"));
	Name const *_Nonnull const language_namespace_name_ = new_Name(adamant_namespace_name_, NamespaceName_, str("language"));
	assert_(not_equal_op(get_name_(name_table_, language_namespace_name_), none), str(""));
	Name const *_Nonnull const optional_class_name_ = new_Name(language_namespace_name_, TypeName_, str("optional"));
	assert_(not_equal_op(get_name_(name_table_, optional_class_name_), none), str(""));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		resource_manager_->AddResource(str("RuntimeLibrary.cpp"), str("#include \"RuntimeLibrary.hpp\"\n#include <map>\n\n// -----------------------------------------------------------------------------\n// Primitive Types\n// -----------------------------------------------------------------------------\n\nu32 i32::as_uint_() const\n{\n    if(this->value < 0)\n        throw std::range_error(\"Can't convert negative number to unsigned\");\n\n    return u32(this->value);\n}\n\nchar code_point__to_char(code_point v)\n{\n    if(v.value > 0xFF)\n        throw std::range_error(\"Unicode char values not yet supported\");\n\n    return v.value;\n}\n\nstring string::construct(code_point c, i32 repeat)\n{\n    string self;\n    self.Length = repeat.value;\n    char* buffer = new char[repeat.value];\n    for (int i = 0; i < repeat.value; i++)\n        buffer[i] = code_point__to_char(c);\n\n    self.Buffer = buffer;\n    return self;\n}\n\nstring::string(const char* s)\n    : Length(std::strlen(s)), Buffer(s)\n{\n}\n\nstring::string(int length, const char* s)\n    : Length(length), Buffer(s)\n{\n}\n\nchar const * string::cstr() const\n{\n    auto buffer = new char[Length + 1];\n    std::memcpy(buffer, Buffer, Length);\n    buffer[Length] = 0;\n    return buffer;\n}\n\nstring::string(i32 other)\n    : Length(0), Buffer(0)\n{\n    char* buffer = new char[12]; // -2,147,483,648 to 2,147,483,647 plus null terminator\n    int length = std::sprintf(buffer,\"%d\", other.value);\n    if(length <= 0) throw std::runtime_error(\"Could not convert int to string\");\n    Length = length;\n    Buffer = buffer;\n}\n\nstring::string(code_point other)\n    : Length(1), Buffer(new char[1] { code_point__to_char(other) })\n{\n}\n\nstring::string(bit other)\n    : string(other.value ? \"true\" : \"false\")\n{\n}\n\nstring string::Substring_(i32 start, i32 length) const\n{\n    return string(length.value, Buffer + start.value);\n}\n\nstring string::Replace_(string oldValue, string newValue) const\n{\n    system__text__String_Builder builder = system__text__String_Builder(); // TODO initialize capacity\n    int limit = Length - oldValue.Length + 1;\n    int lastIndex = 0;\n    // TODO the Substring calls in here are leaking memory\n    for(int i=0; i < limit; i++)\n        if (cond(equal_op(Substring_(i32(i), i32(oldValue.Length)), oldValue)))\n        {\n            builder.Append_(Substring_(i32(lastIndex), i32(i-lastIndex)));\n            builder.Append_(newValue);\n            i += oldValue.Length; // skip over the value we just matched\n            lastIndex = i;\n            i--; // we need i-- to offset the i++ that is about to happen\n        }\n\n    builder.Append_(Substring_(i32(lastIndex), i32(Length - lastIndex)));\n    return builder.ToString_();\n}\n\ni32 string::LastIndexOf_(code_point c) const\n{\n    for(int i = Length - 1; i >= 0; i--)\n        if(Buffer[i] == code_point__to_char(c))\n            return i32(i);\n\n    return i32(-1); // TODO should return none\n}\n\ni32 string::index_of_(code_point c) const\n{\n    for(int i = 0; i < Length; i++)\n        if(Buffer[i] == code_point__to_char(c))\n            return i32(i);\n\n    return i32(-1);\n}\n\nstring string::op__add(string const & value) const\n{\n    int newLength = Length + value.Length;\n    char* chars = new char[newLength];\n    size_t offset = sizeof(char) * Length;\n    std::memcpy(chars, Buffer, offset);\n    std::memcpy(chars + offset, value.Buffer, value.Length);\n    return string(newLength, chars);\n}\n\nauto equal_op(string lhs, string rhs) -> bit\n{\n    if (lhs.Length != rhs.Length)\n        return bit__false;\n\n    for (int i = 0; i < lhs.Length; i++)\n        if (lhs.Buffer[i] != rhs.Buffer[i])\n            return bit__false;\n\n    return bit__true;\n}\n\nbit string__op__less_than(string lhs, string rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) < 0;\n    delete[] left;\n    delete[] right;\n    return bit_from(result);\n}\nbit string__op__less_than_or_equal(string lhs, string rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) <= 0;\n    delete[] left;\n    delete[] right;\n    return bit_from(result);\n}\nbit string__op__greater_than(string lhs, string rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) > 0;\n    delete[] left;\n    delete[] right;\n    return bit_from(result);\n}\nbit string__op__greater_than_or_equal(string lhs, string rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) >= 0;\n    delete[] left;\n    delete[] right;\n    return bit_from(result);\n}\n\nbool operator < (string const & lhs, string const & rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) < 0;\n    delete[] left;\n    delete[] right;\n    return result;\n}\n\n// -----------------------------------------------------------------------------\n// Standard Library\n// -----------------------------------------------------------------------------\n\nstd::map<string, string> resourceValues;\n\nstring const & ResourceManager::GetString_(string resourceName)\n{\n    return resourceValues.at(resourceName);\n}\nvoid ResourceManager::AddResource(string name, string value)\n{\n    resourceValues.insert(std::make_pair(name, value));\n}\n\nResourceManager *const resource_manager_ = new ResourceManager();\n\nvoid debug_write_(string value)\n{\n    std::fprintf(stderr, \"%.*s\", value.Length, value.Buffer);\n}\nvoid debug_write_line_(string value)\n{\n    std::fprintf(stderr, \"%.*s\\n\", value.Length, value.Buffer);\n}\nvoid debug_write_line_()\n{\n    std::fprintf(stderr, \"\\n\");\n}\n\nvoid system__console__Console::Write_(string value)\n{\n    std::printf(\"%.*s\", value.Length, value.Buffer);\n}\n\nvoid system__console__Console::WriteLine_(string value)\n{\n    std::printf(\"%.*s\\n\", value.Length, value.Buffer);\n}\n\nvoid system__console__Console::WriteLine_()\n{\n    std::printf(\"\\n\");\n}\n\nsystem__console__Arguments::system__console__Arguments(int argc, char const *const * argv)\n    : Count(argc-1)\n{\n    args = new string[Count];\n    for (int i = 0; i < Count; i++)\n        args[i] = string(argv[i+1]);\n}\n\nsystem__io__File_Reader *_Nonnull system__io__File_Reader::construct(const string& fileName)\n{\n    std::FILE* foo;\n    auto fname = fileName.cstr();\n    file = std::fopen(fname, \"rb\");\n    delete[] fname;\n    return this;\n}\n\nstring system__io__File_Reader::ReadToEndSync_()\n{\n    std::fseek(file, 0, SEEK_END);\n    auto length = std::ftell(file);\n    std::fseek(file, 0, SEEK_SET);\n    auto buffer = new char[length];\n    length = std::fread(buffer, sizeof(char), length, file);\n    return string(length, buffer);\n}\n\nvoid system__io__File_Reader::Close_()\n{\n    std::fclose(file);\n}\n\nsystem__io__File_Writer *_Nonnull system__io__File_Writer::construct(const string& fileName)\n{\n    auto fname = fileName.cstr();\n    file = std::fopen(fname, \"wb\"); // TODO check error\n    delete[] fname;\n    return this;\n}\n\nvoid system__io__File_Writer::Write_(const string& value)\n{\n    std::fwrite(value.Buffer, sizeof(char), value.Length, file);\n}\n\nvoid system__io__File_Writer::Close_()\n{\n    std::fclose(file);\n}\n\nvoid system__text__String_Builder::ensure_capacity(int needed)\n{\n    int new_capacity = capacity == 0 ? 128 : capacity;\n    while(new_capacity < needed)\n    {\n        new_capacity *= 2;\n    }\n\n    if(new_capacity > capacity)\n    {\n        char* new_buffer = new char[new_capacity];\n        if(length > 0)\n            std::memcpy(new_buffer, buffer, length);\n\n        if(capacity > 0)\n            delete[] buffer;\n\n        buffer = new_buffer;\n        capacity = new_capacity;\n    }\n}\n\nsystem__text__String_Builder *_Nonnull system__text__String_Builder::construct(string const & value)\n{\n    ensure_capacity(value.Length);\n    std::memcpy(buffer, value.Buffer, value.Length);\n    length = value.Length;\n    return this;\n}\n\nsystem__text__String_Builder *_Nonnull system__text__String_Builder::construct_with_capacity(i32 capacity)\n{\n    ensure_capacity(capacity.value);\n    return this;\n}\n\nvoid system__text__String_Builder::Append_(string const & value)\n{\n    int new_length = length + value.Length;\n    ensure_capacity(new_length);\n    std::memcpy(buffer+length, value.Buffer, value.Length);\n    length = new_length;\n}\n\nvoid system__text__String_Builder::Append_(system__text__String_Builder const *_Nonnull value)\n{\n    int new_length = length + value->length;\n    ensure_capacity(new_length);\n    std::memcpy(buffer+length, value->buffer, value->length);\n    length = new_length;\n}\n\nvoid system__text__String_Builder::AppendLine_(string const & value)\n{\n    int new_length = length + value.Length + 1;\n    ensure_capacity(new_length);\n    std::memcpy(buffer+length, value.Buffer, value.Length);\n    buffer[new_length-1] = '\\n';\n    length = new_length;\n}\n\nvoid system__text__String_Builder::AppendLine_()\n{\n    int new_length = length + 1;\n    ensure_capacity(new_length);\n    buffer[new_length-1] = '\\n';\n    length = new_length;\n}\n\nvoid system__text__String_Builder::Remove_(i32 start, i32 length)\n{\n    if(start.value >= this->length)\n        throw std::runtime_error(\"String_Builder.Remove() start >= length\");\n\n    int end = start.value + length.value;\n    if(end > this->length) // greater than because end is one past the end of the remove\n        throw std::runtime_error(\"String_Builder.Remove() end > length\");\n\n    std::memmove(buffer+start.value, buffer+end, this->length-end);\n    this->length -= length.value;\n}\n\nvoid system__text__String_Builder::Remove_(i32 start)\n{\n    if(start.value >= length)\n        throw std::runtime_error(\"String_Builder.Remove() start >= length\");\n\n    length = start.value;\n}\n\nstring system__text__String_Builder::ToString_()\n{\n    string result(length, buffer);\n    // give up ownership of buffer\n    buffer = 0;\n    length = 0;\n    capacity = 0;\n    return result;\n}\n"));
		resource_manager_->AddResource(str("RuntimeLibrary.hpp"), str("// On windows this disables warnings about using fopen_s instead of fopen\n// It must be defined before including the headers.\n#define _CRT_SECURE_NO_WARNINGS\n#include <cstring>\n#include <cstdio>\n#include <cstdint>\n#include <stdexcept>\n#include <string>\n\n// -----------------------------------------------------------------------------\n// Primitive Types\n// -----------------------------------------------------------------------------\n\n// `bool`\nstruct bit\n{\n    bool value;\n};\n\n// `true`\nstatic const bit bit__true = { true };\n// `false`\nstatic const bit bit__false = { false };\n\n// Function used in conditions to make them take `bit`\ninline bool cond(bit cond) { return cond.value; }\n\n// Used by runtime for converting to bit\ninline bit bit_from(bool v) { return bit { v }; }\n\n// Wrap a bit operation that is bool based\ninline bit bit__op(bool v) { return bit { v }; }\n// Convert the arguments of a logical operation to bool\ninline bool bit__arg(bit v) { return v.value; }\ninline bit bit__op__not(bit v) { return bit { !v.value }; }\n\n// `never`\nstruct never\n{\n};\n\n// `never?`\nstruct o_never\n{\n    // TODO get rid of this conversion operator when compiler emits conversions\n    template<class T>\n    operator T*_Nullable() const { return static_cast<T*>(0); }\n};\n\nstatic const o_never none;\n\ntemplate<typename T>\nstruct p_optional final\n{\nprivate:\n    bool hasValue;\n    union\n    {\n        T data;\n    };\n\npublic:\n    // TODO make this constructor explicit\n    p_optional(T const & value) : data(value), hasValue(true) {}\n    // TODO get rid of this conversion operator when compiler emits conversions\n    p_optional(o_never none) : hasValue(false) {}\n    auto has_value() const -> bit { return bit_from(hasValue); }\n    auto value() const -> T { return data; }\n\n    T & operator->()\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n    T const & operator->() const\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n    T & operator* ()\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n    T const & operator* () const\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n};\n\nstruct u32;\n\n// `int`\nstruct i32\n{\n    // Runtime Use Members\n    std::int32_t value;\n\n    explicit i32() = default;\n    explicit i32(std::int32_t value): value(value) {}\n\n    i32 *_Nonnull operator->() { return this; }\n    i32 const *_Nonnull operator->() const { return this; }\n    i32 & operator* () { return *this; }\n    i32 const & operator* () const { return *this; }\n\n    // Hack to support conversion of uint to int for now\n    i32(u32 value);\n\n    // Adamant Members\n    static auto construct() -> i32 { return i32(0); }\n    static auto copy(i32 const & other) -> i32 { return other; }\n    void op__add_assign(i32 other) { this->value += other.value; }\n    void op__subtract_assign(i32 other) { this->value -= other.value; }\n    bit op__less_than(i32 other) const { return bit_from(this->value < other.value); }\n    bit op__less_than_or_equal(i32 other) const { return bit_from(this->value <= other.value); }\n    bit op__greater_than(i32 other) const { return bit_from(this->value > other.value); }\n    bit op__greater_than_or_equal(i32 other) const { return bit_from(this->value >= other.value); }\n    i32 op__add(i32 other) const { return i32(this->value + other.value); }\n    i32 op__subtract(i32 other) const { return i32(this->value - other.value); }\n    i32 op__multiply(i32 other) const { return i32(this->value * other.value); }\n    i32 op__divide(i32 other) const { return i32(this->value / other.value); }\n    i32 op__remainder(i32 other) const { return i32(this->value % other.value); }\n    i32 op__magnitude() const { if(this->value==INT32_MIN) throw std::overflow_error(\"Can't take |int.Min|\"); return i32(this->value < 0 ? -this->value : this->value); }\n\n    // Hack because we don't support as correctly yet\n    u32 as_uint_() const;\n};\n\ninline i32 i32__op__negate(i32 v) { return i32(-v.value); }\ninline bit i32__op__less_than(i32 lhs, i32 rhs) { return bit_from(lhs.value < rhs.value); }\ninline bit i32__op__less_than_or_equal(i32 lhs, i32 rhs) { return bit_from(lhs.value <= rhs.value); }\ninline bit i32__op__greater_than(i32 lhs, i32 rhs) { return bit_from(lhs.value > rhs.value); }\ninline bit i32__op__greater_than_or_equal(i32 lhs, i32 rhs) { return bit_from(lhs.value >= rhs.value); }\n\n// `uint`\nstruct u32\n{\n    // Runtime Use Members\n    std::uint32_t value;\n\n    explicit u32() = default;\n    explicit u32(std::uint32_t value): value(value) {}\n\n    u32 *_Nonnull operator->() { return this; }\n    u32 const *_Nonnull operator->() const { return this; }\n    u32 & operator* () { return *this; }\n    u32 const & operator* () const { return *this; }\n\n    // Hack to support conversion of int to uint for now\n    u32(i32 value): value(value.value) {}\n\n    // Adamant Members\n    static auto construct() -> u32 { return u32(0); }\n    void op__add_assign(u32 other) { this->value += other.value; }\n    void op__subtract_assign(u32 other) { this->value -= other.value; }\n    bit op__less_than(u32 other) const { return bit_from(this->value < other.value); }\n    bit op__less_than_or_equal(u32 other) const { return bit_from(this->value <= other.value); }\n    bit op__greater_than(u32 other) const { return bit_from(this->value > other.value); }\n    bit op__greater_than_or_equal(u32 other) const { return bit_from(this->value >= other.value); }\n    u32 op__add(u32 other) const { return u32(this->value + other.value); }\n    u32 op__subtract(u32 other) const { return u32(this->value - other.value); }\n};\n\ninline bit u32__op__less_than(u32 lhs, u32 rhs) { return bit_from(lhs.value < rhs.value); }\ninline bit u32__op__less_than_or_equal(u32 lhs, u32 rhs) { return bit_from(lhs.value <= rhs.value); }\ninline bit u32__op__greater_than(u32 lhs, u32 rhs) { return bit_from(lhs.value > rhs.value); }\ninline bit u32__op__greater_than_or_equal(u32 lhs, u32 rhs) { return bit_from(lhs.value >= rhs.value); }\n\ninline i32::i32(u32 value)\n    : value(value.value)\n{\n}\n\nstruct code_point\n{\n    std::uint32_t value;\n\n    // Runtime Use Members\n    explicit code_point() = default;\n    explicit code_point(char value): value(value) {}\n\n    code_point *_Nonnull operator->() { return this; }\n    code_point const *_Nonnull operator->() const { return this; }\n    code_point & operator* () { return *this; }\n    code_point const & operator* () const { return *this; }\n\n    // Adamant Members\n    static auto construct() -> code_point { return code_point('\\0'); }\n};\n\nchar code_point__to_char(code_point v);\n\n// TODO: Not sure code_point should support comparision operations\ninline bit code_point__op__less_than(code_point lhs, code_point rhs) { return bit_from(lhs.value < rhs.value); }\ninline bit code_point__op__less_than_or_equal(code_point lhs, code_point rhs) { return bit_from(lhs.value <= rhs.value); }\ninline bit code_point__op__greater_than(code_point lhs, code_point rhs) { return bit_from(lhs.value > rhs.value); }\ninline bit code_point__op__greater_than_or_equal(code_point lhs, code_point rhs) { return bit_from(lhs.value >= rhs.value); }\n\nstruct string\n{\n    // Runtime Use Members\n    char const *_Nonnull Buffer;\n    int Length;\n\n    explicit string() = default;\n    explicit string(char const *_Nonnull s);\n    explicit string(int length, char const *_Nonnull s);\n    char const *_Nonnull cstr() const;\n    string const *_Nonnull operator->() const { return this; }\n    string const & operator* () const { return *this; }\n\n    typedef char const *_Nonnull const_iterator;\n    const_iterator begin() const { return &Buffer[0]; }\n    const_iterator end() const { return &Buffer[Length]; }\n\n    // Hack to support conversion of int and code_point to strings for now\n    string(i32 other);\n    string(code_point other);\n    explicit string(bit other);\n\n    // Adamant Members\n    static auto construct() -> string { string self; self.Length = 0; self.Buffer = 0; return self; }\n    static auto construct(string value) -> string { return value; }\n    static auto construct(code_point c, i32 repeat) -> string;\n    // TODO ByteLength should be a property\n    i32 ByteLength_() const { return i32(Length); }\n\n    string Substring_(i32 start, i32 length) const;\n    string Substring_(i32 start) const { return Substring_(start, i32(Length-start.value)); }\n    string Replace_(string oldValue, string newValue) const;\n    i32 LastIndexOf_(code_point c) const;\n    i32 index_of_(code_point c) const;\n\n    // TODO check index bounds\n    code_point op__Element(i32 const index) const { return code_point(Buffer[index.value]); }\n    string op__add(string const & value) const;\n    string op__add(bit value) const { return this->op__add(string(value)); }\n};\n\nbit string__op__less_than(string lhs, string rhs);\nbit string__op__less_than_or_equal(string lhs, string rhs);\nbit string__op__greater_than(string lhs, string rhs);\nbit string__op__greater_than_or_equal(string lhs, string rhs);\n\ninline string new_string()\n{\n    return string::construct();\n}\ninline string new_string(string value)\n{\n    return string::construct(value);\n}\ninline string new_string(code_point c, i32 repeat)\n{\n    return string::construct(c, repeat);\n}\n\n// -----------------------------------------------------------------------------\n// Operators\n// -----------------------------------------------------------------------------\n\ninline auto equal_op(bit lhs, bit rhs) -> bit\n{\n    return bit_from(lhs.value == rhs.value);\n}\ninline auto equal_op(p_optional<bit> lhs, p_optional<bit> rhs) -> bit\n{\n    if(lhs.has_value().value)\n        return bit__op(bit__arg(rhs.has_value()) && bit__arg(equal_op(lhs.value(), rhs.value())));\n    else\n        return bit__op__not(rhs.has_value());\n}\n\ninline auto equal_op(i32 lhs, i32 rhs) -> bit\n{\n    return bit_from(lhs.value == rhs.value);\n}\ninline auto equal_op(p_optional<i32> lhs, p_optional<i32> rhs) -> bit\n{\n    if(lhs.has_value().value)\n        return bit__op(bit__arg(rhs.has_value()) && bit__arg(equal_op(lhs.value(), rhs.value())));\n    else\n        return bit__op__not(rhs.has_value());\n}\n\ninline auto equal_op(o_never lhs, o_never rhs) -> bit\n{\n    return bit__true;\n}\n\ninline auto equal_op(code_point lhs, code_point rhs) -> bit\n{\n    return bit_from(lhs.value == rhs.value);\n}\n\nauto equal_op(string lhs, string rhs) -> bit;\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto equal_op(T const *_Nullable lhs, o_never rhs) -> bit\n{\n    return bit_from(lhs == 0);\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto equal_op(o_never lhs, T const *_Nullable rhs) -> bit\n{\n    return bit_from(0 == rhs);\n}\n\n// TODO Get rid of this ability\ntemplate<typename T>\ninline auto equal_op(T const *_Nullable lhs, T const *_Nullable const & rhs) -> bit\n{\n    return bit_from(lhs == 0);\n}\n\ninline auto not_equal_op(i32 lhs, i32 rhs) -> bit\n{\n    return bit_from(lhs.value != rhs.value);\n}\ninline auto not_equal_op(p_optional<i32> lhs, p_optional<i32> rhs) -> bit\n{\n    if(lhs.has_value().value)\n        return bit__op(bit__arg(bit__op__not(rhs.has_value())) || bit__arg(not_equal_op(lhs.value(), rhs.value())));\n    else\n        return rhs.has_value();\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto not_equal_op(T lhs, T  rhs) -> bit\n{\n    return bit__op__not(equal_op(lhs, rhs));\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto not_equal_op(T const *_Nullable lhs, o_never rhs) -> bit\n{\n    return bit_from(lhs != 0);\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto not_equal_op(o_never lhs, T const *_Nullable rhs) -> bit\n{\n    return bit_from(0 != rhs);\n}\n\n// -----------------------------------------------------------------------------\n// Standard Library\n// -----------------------------------------------------------------------------\n// Parts of the standard library that are currently implemented in the runtime.\n\n// A placeholder function until we get proper exceptions implemented\n_Noreturn inline void THROW_EXCEPTION_(const string& value)\n{\n    throw std::runtime_error(value.cstr());\n}\n\n\ninline void assert(const bit condition, char const *_Nonnull code, const string message, char const *_Nonnull file, const std::int32_t line)\n{\n    if(!condition.value)\n        throw std::runtime_error(\n            string(\"Assertion failed: \").op__add(string(code)).op__add(string(\", \")).op__add(message)\n            .op__add(string(\", file \")).op__add(string(file)).op__add(string(\", line \")).op__add(i32(line)).cstr());\n}\n\n#define assert_(condition, message) assert(condition, #condition, message, __FILE__, __LINE__)\n\n\n_Noreturn inline void NOT_IMPLEMENTED(const string message, char const *_Nonnull function, char const *_Nonnull file, const std::int32_t line)\n{\n    throw std::runtime_error(\n        string(\"Function \").op__add(string(function))\n        .op__add(string(\" not yet implemented, \")).op__add(message).op__add(string(\", \")).op__add(string(file)).op__add(string(\", line \")).op__add(i32(line)).cstr());\n}\n\n#define NOT_IMPLEMENTED_(message) NOT_IMPLEMENTED(message, __func__, __FILE__, __LINE__)\n\n\n_Noreturn inline void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const std::int32_t line)\n{\n    throw std::runtime_error(\n        string(\"Reached \\\"UNREACHABLE\\\" statement in function \").op__add(string(function))\n        .op__add(string(\", \")).op__add(string(file)).op__add(string(\", line \")).op__add(i32(line)).cstr());\n}\n\n#define UNREACHABLE_() UNREACHABLE(__func__, __FILE__, __LINE__)\n\nclass ResourceManager\n{\npublic:\n    string const & GetString_(string resourceName);\n    void AddResource(string name, string value);\n};\n\nextern ResourceManager *_Nonnull const resource_manager_;\n\nvoid debug_write_(string value);\nvoid debug_write_line_(string value);\nvoid debug_write_line_();\n\ntemplate<typename T>\nclass system__collections__List\n{\nprivate:\n    T *_Nonnull values;\n    int length;\n    int capacity;\n\npublic:\n    // Runtime Use Members\n    typedef T const *_Nonnull const_iterator;\n    const_iterator begin() const { return values; }\n    const_iterator end() const { return &values[length]; }\n\n    // Adamant Members\n    system__collections__List *_Nonnull construct() { values = 0; length = 0; capacity = 0; return this; }\n    void add_(T value);\n    void clear_() { length = 0; }\n    i32 op__magnitude() const { return i32(length); }\n    T const & op__Element(i32 const index) const;\n};\n\ntemplate<typename T>\nvoid system__collections__List<T>::add_(T value)\n{\n    if(length >= capacity)\n    {\n        int newCapacity = capacity == 0 ? 16 : capacity * 2;\n        // Allocate uninitalized buffer (note `sizeof(char) == 1` always)\n        // Needed if T is a value type to avoid needing a default constructor\n        T* newValues = (T*)new char[newCapacity * sizeof(T)];\n        std::memcpy(newValues, values, length * sizeof(T));\n        values = newValues;\n        capacity = newCapacity;\n    }\n    values[length] = value;\n    length++;\n}\n\ntemplate<typename T>\nT const & system__collections__List<T>::op__Element(i32 const index) const\n{\n    if(index.value < 0 || index.value >= length)\n        throw std::out_of_range(\"List index out of bounds\");\n    return values[index.value];\n}\n\ntemplate<typename T>\nsystem__collections__List<T> *_Nonnull new_system__collections__List()\n{\n    return (new system__collections__List<T>())->construct();\n}\n\nclass system__console__Console\n{\npublic:\n    void Write_(string value);\n    void WriteLine_(string value);\n    void WriteLine_();\n};\n\nclass system__console__Arguments\n{\nprivate:\n    string *_Nonnull args;\npublic:\n    // Runtime Use Members\n    typedef string const *_Nonnull const_iterator;\n\n    system__console__Arguments(int argc, char const *_Nonnull const *_Nonnull argv);\n    const_iterator begin() const { return &args[0]; }\n    const_iterator end() const { return &args[Count]; }\n\n    const int Count;\n\n    // Adamant Members\n    i32 op__magnitude() const { return i32(Count); }\n    string const & op__Element(i32 const index) const\n    {\n        if(index.value < 0 || index.value >= Count)\n            throw std::out_of_range(\"Argument index out of bounds\");\n        return args[index.value];\n    }\n};\n\nclass system__io__File_Reader\n{\nprivate:\n    std::FILE *_Nonnull file;\n\npublic:\n    system__io__File_Reader *_Nonnull construct(const string& fileName);\n    string ReadToEndSync_();\n    void Close_();\n};\n\ninline system__io__File_Reader *_Nonnull new_system__io__File_Reader(const string& fileName)\n{\n    return (new system__io__File_Reader())->construct(fileName);\n}\n\nclass system__io__File_Writer\n{\nprivate:\n    std::FILE *_Nonnull file;\n\npublic:\n    system__io__File_Writer *_Nonnull construct(const string& fileName);\n    void Write_(const string& value);\n    void Close_();\n};\n\ninline system__io__File_Writer *_Nonnull new_system__io__File_Writer(const string& fileName)\n{\n    return (new system__io__File_Writer())->construct(fileName);\n}\n\nclass system__text__String_Builder\n{\nprivate:\n    char *_Nullable buffer;\n    int capacity;\n    int length;\n    void ensure_capacity(int needed);\npublic:\n    // Runtime Use Members\n    system__text__String_Builder(): buffer(0), capacity(0), length(0) { }\n\n    // Adamant Members\n    system__text__String_Builder *_Nonnull construct() { return this; }\n    system__text__String_Builder *_Nonnull construct(string const & value);\n    system__text__String_Builder *_Nonnull construct_with_capacity(i32 capacity);\n    // TODO byte_length_ should be a property\n    i32 byte_length_() const { return i32(length); }\n    void Append_(string const & value);\n    void Append_(system__text__String_Builder const *_Nonnull value);\n    void AppendLine_(string const& value);\n    void AppendLine_();\n    void Remove_(i32 start, i32 length);\n    void Remove_(i32 start);\n    string ToString_();\n};\n\ninline system__text__String_Builder *_Nonnull new_system__text__String_Builder()\n{\n    return (new system__text__String_Builder())->construct();\n}\n\ninline system__text__String_Builder *_Nonnull new_system__text__String_Builder(string const & value)\n{\n    return (new system__text__String_Builder())->construct(value);\n}\n\ninline system__text__String_Builder *_Nonnull new_system__text__String_Builder__with_capacity(i32 capacity)\n{\n    return (new system__text__String_Builder())->construct_with_capacity(capacity);\n}\n"));

		return main_(new system__console__Console(), new system__console__Arguments(argc, argv)).value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
