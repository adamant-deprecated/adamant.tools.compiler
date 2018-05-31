#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Source_Text__0 Source_Text__0;
typedef struct Text_Line__0 Text_Line__0;
typedef struct Text_Lines__0 Text_Lines__0;
typedef struct Text_Position__0 Text_Position__0;
typedef struct Text_Span__0 Text_Span__0;
typedef struct Source_File_Builder__0 Source_File_Builder__0;
typedef struct Compilation_Unit__0 Compilation_Unit__0;
typedef struct Package__0 Package__0;
typedef struct Package_Reference__0 Package_Reference__0;
typedef struct Semantic_Node__0 Semantic_Node__0;
typedef struct Semantic_Tree_Builder__0 Semantic_Tree_Builder__0;
typedef struct Compilation_Unit_Parser__0 Compilation_Unit_Parser__0;
typedef struct Syntax_Node__0 Syntax_Node__0;
typedef struct Token_Stream__0 Token_Stream__0;
typedef struct Diagnostic__0 Diagnostic__0;
typedef struct Emitter__0 Emitter__0;
typedef struct Name__0 Name__0;
typedef struct Package_Name__0 Package_Name__0;
typedef struct Symbol__0 Symbol__0;
typedef struct Type__0 Type__0;
typedef struct Name_Subtable__0 Name_Subtable__0;
typedef struct Name_Table__0 Name_Table__0;

// Function Declarations
Package__0 const *_Nonnull compile__1(system__collections__List__1<Source_Text__0 const *_Nonnull> const *_Nonnull const sources__);
void write__2(system__console__Console__0 *_Nonnull const console__, system__collections__List__1<Diagnostic__0 const *_Nonnull> const *_Nonnull const diagnostics__);
BOOL has_errors__1(system__collections__List__1<Diagnostic__0 const *_Nonnull> const *_Nonnull const diagnostics__);
int32 main__2(system__console__Console__0 *_Nonnull const console__, system__console__Arguments__0 const *_Nonnull const args__);
Source_Text__0 const *_Nonnull read_source__1(string const path__);
void run_unit_tests__1(system__console__Console__0 *_Nonnull const console__);
Source_Text__0 *_Nonnull Source_Text__0__0new__3(Source_Text__0 *_Nonnull self, string const package__, string const path__, string const text__);
Ints__0 const *_Nonnull line_starts__1(string const text__);
int32 source_byte_length__1(Source_Text__0 const *_Nonnull const source__);
Text_Position__0 const *_Nonnull position_of_start__2(Source_Text__0 const *_Nonnull const source__, Text_Span__0 const *_Nonnull const span__);
Text_Line__0 *_Nonnull Text_Line__0__0new__3(Text_Line__0 *_Nonnull self, Source_Text__0 const *_Nonnull const source__, int32 const start__, int32 const length__);
Text_Line__0 *_Nonnull Text_Line__0__0new__spanning__3(Text_Line__0 *_Nonnull self, Source_Text__0 const *_Nonnull const source__, int32 const start__, int32 const end__);
Text_Lines__0 *_Nonnull Text_Lines__0__0new__2(Text_Lines__0 *_Nonnull self, Source_Text__0 const *_Nonnull const source__, Ints__0 const *_Nonnull const start_of_line__);
int32 line_count__1(Text_Lines__0 const *_Nonnull const lines__);
Text_Line__0 const *_Nonnull get_line__2(Text_Lines__0 const *_Nonnull const lines__, int32 const line_number__);
int32 line_containing_offset__2(Text_Lines__0 const *_Nonnull const lines__, int32 const character_offset__);
Text_Position__0 *_Nonnull Text_Position__0__0new__3(Text_Position__0 *_Nonnull self, int32 const character_offset__, int32 const line__, int32 const column__);
void unit_test_Text_Position__0();
void Text_Position_retains_given_offeset_line_and_column__0();
Text_Span__0 *_Nonnull Text_Span__0__0new__2(Text_Span__0 *_Nonnull self, int32 const start__, int32 const length__);
string format_error__1(string const message__);
Source_File_Builder__0 *_Nonnull Source_File_Builder__0__0new__0(Source_File_Builder__0 *_Nonnull self);
void error__2(Source_File_Builder__0 *_Nonnull const file__, string const message__);
void begin_line__2(Source_File_Builder__0 *_Nonnull const file__, string const value__);
void write__2(Source_File_Builder__0 *_Nonnull const file__, string const value__);
void end_line__2(Source_File_Builder__0 *_Nonnull const file__, string const value__);
void write_line__2(Source_File_Builder__0 *_Nonnull const file__, string const value__);
void blank_line__1(Source_File_Builder__0 *_Nonnull const file__);
void element_separator_line__1(Source_File_Builder__0 *_Nonnull const file__);
void statement_separator_line__1(Source_File_Builder__0 *_Nonnull const file__);
void begin_block__1(Source_File_Builder__0 *_Nonnull const file__);
void end_block__1(Source_File_Builder__0 *_Nonnull const file__);
void end_block_with_semicolon__1(Source_File_Builder__0 *_Nonnull const file__);
int32 byte_length__1(Source_File_Builder__0 const *_Nonnull const file__);
string to_string__1(Source_File_Builder__0 *_Nonnull const file__);
Compilation_Unit__0 *_Nonnull Compilation_Unit__0__0new__2(Compilation_Unit__0 *_Nonnull self, Syntax_Node__0 const *_Nonnull const syntax__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__);
void collect_diagnostics__2(Compilation_Unit__0 const *_Nonnull const compilation_unit__, system__collections__List__1<Diagnostic__0 const *_Nonnull> *_Nonnull const diagnostics__);
Package__0 *_Nonnull Package__0__0new__4(Package__0 *_Nonnull self, Package_Name__0 const *_Nonnull const name__, system__collections__List__1<Package_Reference__0 const *_Nonnull> const *_Nonnull const references__, system__collections__List__1<Compilation_Unit__0 const *_Nonnull> const *_Nonnull const compilation_units__, Symbol__0 const *_Nonnull const symbol__);
system__collections__List__1<Diagnostic__0 const *_Nonnull> const *_Nonnull all_diagnostics__1(Package__0 const *_Nonnull const package__);
Package_Reference__0 *_Nonnull Package_Reference__0__0new__1(Package_Reference__0 *_Nonnull self, Package__0 const *_Nonnull const package__);
Package_Reference__0 *_Nonnull Package_Reference__0__0new__2(Package_Reference__0 *_Nonnull self, string const name__, Package__0 const *_Nonnull const package__);
Package__0 const *_Nonnull build_primitives_package__0();
system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull build_primitive_symbols__1(Package_Name__0 const *_Nonnull const package_name__);
Symbol__0 const *_Nonnull build_adamant_language_namespace_symbol__1(Name__0 const *_Nonnull const global_namespace__);
Symbol__0 const *_Nonnull build_optional_type_symbol__1(Name__0 const *_Nonnull const language_namespace__);
Symbol__0 const *_Nonnull build_primitive_symbol__2(string const name__, Name__0 const *_Nonnull const namespace__);
void build_fixed_point_primitives__3(system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const symbols__, int32 const bits__, Name__0 const *_Nonnull const namespace__);
void unit_test_build_primitives_package__0();
void Package_name_is_dollar_primitives__0();
void Package_has_no_references_or_compilation_units__0();
void Package_symbol_has_package_name__0();
void Package_symbol_has_children__0();
void Package_contains_the_string_type__0();
void Package_contains_optional_type__0();
Package__0 const *_Nonnull build_runtime_library_package__0();
system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull build_runtime_library_symbols__1(Package_Name__0 const *_Nonnull const package_name__);
Symbol__0 const *_Nonnull build_function_symbol__1(Name__0 const *_Nonnull const name__);
Symbol__0 const *_Nonnull build_namespace_symbol__2(Name__0 const *_Nonnull const name__, system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const symbols__);
Symbol__0 const *_Nonnull build_class_symbol__2(Name__0 const *_Nonnull const namespace__, string const class_name__);
Symbol__0 const *_Nonnull build_class_symbol__3(Name__0 const *_Nonnull const namespace__, string const class_name__, system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const children__);
Symbol__0 const *_Nonnull build_generic_class_symbol__3(Name__0 const *_Nonnull const namespace__, string const class_name__, system__collections__List__1<Type__0 const *_Nonnull> const *_Nonnull const type_parameters__);
Symbol__0 const *_Nonnull build_constructor_symbol__1(string const name__);
void unit_test_build_runtime_library_package__0();
void Runtime_Library_Package_contains_system_package__0();
void System_namespace_contains_console_namespace__0();
void Console_namespace_contains_Console_class__0();
void System_namespace_contains_collections_namespace__0();
void Collections_namespace_contains_List_class__0();
Package__0 const *_Nonnull analyze_semantics__1(Syntax_Node__0 const *_Nonnull const package_syntax__);
Semantic_Node__0 *_Nonnull Semantic_Node__0__0new__token__1(Semantic_Node__0 *_Nonnull self, Syntax_Node__0 const *_Nonnull const syntax__);
Semantic_Node__0 *_Nonnull Semantic_Node__0__0new__concrete__2(Semantic_Node__0 *_Nonnull self, Syntax_Node__0 const *_Nonnull const syntax__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const children__);
Semantic_Node__0 *_Nonnull Semantic_Node__0__0new__of_type__3(Semantic_Node__0 *_Nonnull self, Type__0 const *_Nonnull const of_type__, Syntax_Node__0 const *_Nonnull const syntax__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const children__);
Semantic_Node__0 *_Nonnull Semantic_Node__0__0new__declares_type__3(Semantic_Node__0 *_Nonnull self, Type__0 const *_Nonnull const type__, Syntax_Node__0 const *_Nonnull const syntax__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const children__);
Semantic_Node__0 *_Nonnull Semantic_Node__0__0new__referencing_type__3(Semantic_Node__0 *_Nonnull self, Type__0 const *_Nonnull const type__, Syntax_Node__0 const *_Nonnull const syntax__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const children__);
Text_Span__0 const *_Nonnull get_text_span__1(Semantic_Node__0 const *_Nonnull const node__);
string get_text__1(Semantic_Node__0 const *_Nonnull const node__);
Semantic_Node__0 const *_Nullable first_child__2(Semantic_Node__0 const *_Nonnull const node__, int32 const kind__);
system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull children_of_kind__2(Semantic_Node__0 const *_Nonnull const node__, int32 const kind__);
system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull node_members__1(Semantic_Node__0 const *_Nonnull const node__);
system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull node_statements__1(Semantic_Node__0 const *_Nonnull const node__);
system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull node_parameters__1(Semantic_Node__0 const *_Nonnull const node__);
int32 node_argument_count__1(Semantic_Node__0 const *_Nonnull const node__);
Semantic_Node__0 const *_Nullable node_access_modifier__1(Semantic_Node__0 const *_Nonnull const node__);
BOOL node_has_child__2(Semantic_Node__0 const *_Nonnull const node__, int32 const kind__);
void add_diagnostic__2(Semantic_Node__0 *_Nonnull const node__, Diagnostic__0 const *_Nonnull const diagnostic__);
system__collections__List__1<Diagnostic__0 const *_Nonnull> const *_Nonnull diagnostics__1(Semantic_Node__0 const *_Nonnull const node__);
void collect_diagnostics__2(Semantic_Node__0 const *_Nonnull const node__, system__collections__List__1<Diagnostic__0 const *_Nonnull> *_Nonnull const diagnostics__);
Semantic_Tree_Builder__0 *_Nonnull Semantic_Tree_Builder__0__0new__0(Semantic_Tree_Builder__0 *_Nonnull self);
system__collections__List__1<Compilation_Unit__0 const *_Nonnull> const *_Nonnull build_compilation_units__3(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Syntax_Node__0 const *_Nonnull const package_syntax__, Name_Table__0 const *_Nonnull const name_table__);
Compilation_Unit__0 const *_Nonnull build_compilation_unit_semantic_node__3(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Syntax_Node__0 const *_Nonnull const compilation_unit_syntax__, Name_Table__0 const *_Nonnull const name_table__);
Semantic_Node__0 const *_Nonnull build_semantic_node__4(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Syntax_Node__0 const *_Nonnull const syntax__, Name_Table__0 const *_Nonnull const name_table__, Name_Subtable__0 const *_Nonnull const scope__);
Semantic_Node__0 *_Nonnull build_parameters_semantic_node__4(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Syntax_Node__0 const *_Nonnull const parameters_syntax__, Name_Table__0 const *_Nonnull const name_table__, Name_Subtable__0 const *_Nonnull const scope__);
Semantic_Node__0 *_Nonnull build_type_name_semantic_node__4(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Syntax_Node__0 const *_Nonnull const syntax__, Name_Table__0 const *_Nonnull const name_table__, Name_Subtable__0 const *_Nonnull const scope__);
Type__0 const *_Nonnull build_optional_type__3(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Name_Table__0 const *_Nonnull const name_table__, Type__0 const *_Nonnull const base_type__);
system__collections__List__1<Type__0 const *_Nonnull> const *_Nonnull build_type_arguments_semantic_node__5(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Syntax_Node__0 const *_Nonnull const syntax__, Name_Table__0 const *_Nonnull const name_table__, Name_Subtable__0 const *_Nonnull const scope__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const children__);
Semantic_Node__0 const *_Nonnull build_constructor_name_semantic_node__4(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Syntax_Node__0 const *_Nonnull const syntax__, Name_Table__0 const *_Nonnull const name_table__, Name_Subtable__0 const *_Nonnull const scope__);
void add_resolution_error__1(Semantic_Node__0 *_Nonnull const node__);
void add_resolution_error__2(Semantic_Node__0 *_Nonnull const node__, Semantic_Node__0 const *_Nonnull const qualifier__);
void add_could_not_determine_type_error__1(Semantic_Node__0 *_Nonnull const node__);
Symbol__0 const *_Nonnull build_symbols__2(Package_Name__0 const *_Nonnull const package_name__, system__collections__List__1<Compilation_Unit__0 const *_Nonnull> const *_Nonnull const compilation_units__);
Compilation_Unit_Parser__0 *_Nonnull Compilation_Unit_Parser__0__0new__1(Compilation_Unit_Parser__0 *_Nonnull self, Token_Stream__0 *_Nonnull const token_stream__);
Syntax_Node__0 const *_Nonnull parse__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Syntax_Node__0 const *_Nullable accept_token__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Syntax_Node__0 const *_Nonnull expect_token__2(Compilation_Unit_Parser__0 *_Nonnull const parser__, int32 const tokenType__);
Syntax_Node__0 const *_Nonnull parse_type_name__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Syntax_Node__0 const *_Nonnull parse_non_optional_type__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Syntax_Node__0 const *_Nonnull parse_type__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Syntax_Node__0 const *_Nonnull parse_atom__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Syntax_Node__0 const *_Nonnull parse_call_arguments__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Syntax_Node__0 const *_Nonnull parse_expression__2(Compilation_Unit_Parser__0 *_Nonnull const parser__, int32 const minPrecedence__);
Syntax_Node__0 const *_Nonnull parse_expression__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Syntax_Node__0 const *_Nonnull parse_statement__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Syntax_Node__0 const *_Nonnull parse_if_statement__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Syntax_Node__0 const *_Nonnull parse_variable_declaration__2(Compilation_Unit_Parser__0 *_Nonnull const parser__, BOOL const allowInitializer__);
Syntax_Node__0 const *_Nonnull parse_block__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Syntax_Node__0 const *_Nonnull parse_parameter_list__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Syntax_Node__0 const *_Nonnull parse_member_declaration__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Syntax_Node__0 const *_Nonnull parse_declaration__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Syntax_Node__0 const *_Nonnull parse_compilation_unit__1(Compilation_Unit_Parser__0 *_Nonnull const parser__);
Token_Stream__0 *_Nonnull lexically_analyze__1(Source_Text__0 const *_Nonnull const source__);
Syntax_Node__0 const *_Nonnull parse_package__1(system__collections__List__1<Source_Text__0 const *_Nonnull> const *_Nonnull const sources__);
Syntax_Node__0 *_Nonnull Syntax_Node__0__0new__4(Syntax_Node__0 *_Nonnull self, int32 const type__, Source_Text__0 const *_Nonnull const source__, int32 const start__, int32 const length__);
Syntax_Node__0 *_Nonnull Syntax_Node__0__0new__5(Syntax_Node__0 *_Nonnull self, int32 const type__, BOOL const isMissing__, Source_Text__0 const *_Nonnull const source__, int32 const start__, int32 const length__);
Syntax_Node__0 *_Nonnull Syntax_Node__0__0new__2(Syntax_Node__0 *_Nonnull self, int32 const type__, Syntax_Node__0 const *_Nonnull const child__);
Syntax_Node__0 *_Nonnull Syntax_Node__0__0new__2(Syntax_Node__0 *_Nonnull self, int32 const type__, system__collections__List__1<Syntax_Node__0 const *_Nonnull> const *_Nonnull const children__);
Syntax_Node__0 *_Nonnull Syntax_Node__0__0new__missing__3(Syntax_Node__0 *_Nonnull self, int32 const type__, Source_Text__0 const *_Nonnull const source__, int32 const start__);
Syntax_Node__0 *_Nonnull Syntax_Node__0__0new__skipped__1(Syntax_Node__0 *_Nonnull self, Syntax_Node__0 const *_Nonnull const skipped_node__);
Syntax_Node__0 *_Nonnull Syntax_Node__0__0new__skipped__1(Syntax_Node__0 *_Nonnull self, system__collections__List__1<Syntax_Node__0 const *_Nonnull> const *_Nonnull const skipped_nodes__);
string get_text__1(Syntax_Node__0 const *_Nonnull const syntax__);
Syntax_Node__0 const *_Nullable first_child_syntax__2(Syntax_Node__0 const *_Nonnull const syntax__, int32 const type__);
BOOL has_child__2(Syntax_Node__0 const *_Nonnull const syntax__, int32 const type__);
void add__2(Syntax_Node__0 const *_Nonnull const syntax__, Diagnostic__0 const *_Nonnull const diagnostic__);
system__collections__List__1<Diagnostic__0 const *_Nonnull> *_Nonnull all_diagnostics__1(Syntax_Node__0 const *_Nonnull const syntax__);
void collect_syntax_diagnostics__2(Syntax_Node__0 const *_Nonnull const syntax__, system__collections__List__1<Diagnostic__0 const *_Nonnull> *_Nonnull const diagnostics__);
system__collections__List__1<Syntax_Node__0 const *_Nonnull> const *_Nonnull members__1(Syntax_Node__0 const *_Nonnull const syntax__);
system__collections__List__1<Syntax_Node__0 const *_Nonnull> const *_Nonnull parameters__1(Syntax_Node__0 const *_Nonnull const syntax__);
system__collections__List__1<Syntax_Node__0 const *_Nonnull> const *_Nonnull statements__1(Syntax_Node__0 const *_Nonnull const syntax__);
Syntax_Node__0 const *_Nullable access_modifier__1(Syntax_Node__0 const *_Nonnull const syntax__);
Token_Stream__0 *_Nonnull Token_Stream__0__0new__1(Token_Stream__0 *_Nonnull self, Source_Text__0 const *_Nonnull const source__);
Syntax_Node__0 const *_Nullable next_token__1(Token_Stream__0 *_Nonnull const tokens__);
Syntax_Node__0 const *_Nullable end_of_file_token__1(Token_Stream__0 *_Nonnull const tokens__);
Syntax_Node__0 const *_Nonnull new_identifier_or_keyword_token__2(Token_Stream__0 *_Nonnull const tokens__, int32 const end__);
Syntax_Node__0 const *_Nonnull new_operator_token__2(Token_Stream__0 *_Nonnull const tokens__, int32 const type__);
Syntax_Node__0 const *_Nonnull new_operator_token__3(Token_Stream__0 *_Nonnull const tokens__, int32 const type__, int32 const length__);
Syntax_Node__0 const *_Nonnull new_token__3(Token_Stream__0 *_Nonnull const tokens__, int32 const type__, int32 const end__);
BOOL is_identifier_char__1(code_point const c__);
BOOL is_number_char__1(code_point const c__);
Diagnostic__0 *_Nonnull Diagnostic__0__0new__5(Diagnostic__0 *_Nonnull self, int32 const level__, int32 const phase__, Source_Text__0 const *_Nonnull const source__, Text_Span__0 const *_Nonnull const span__, string const message__);
Emitter__0 *_Nonnull Emitter__0__0new__2(Emitter__0 *_Nonnull self, Package__0 const *_Nonnull const package__, system__collections__List__1<Source_Text__0 const *_Nonnull> const *_Nonnull const resources__);
string emit__1(Emitter__0 *_Nonnull const emitter__);
string mangle_name__1(Type__0 const *_Nonnull const type__);
string mangle_function_name__2(string const name__, int32 const parameter_count__);
string mangle_field_name__1(string const name__);
BOOL contains_multi_underscore_runs__1(string const value__);
void append_fixing_underscores__2(system__text__String_Builder__0 *_Nonnull const builder__, string const value__);
string convert_primitive_type_name__1(Type__0 const *_Nonnull const type__);
system__text__String_Builder__0 *_Nonnull convert_type_name__1(Semantic_Node__0 const *_Nonnull const type_node__);
system__text__String_Builder__0 *_Nonnull convert_type_name__1(Type__0 const *_Nonnull const type__);
system__text__String_Builder__0 *_Nonnull convert_type_name__2(Type__0 const *_Nonnull const type__, BOOL const include_type_parameters__);
void convert_type_parameters__2(system__text__String_Builder__0 *_Nonnull const builder__, Type__0 const *_Nonnull const type__);
string convert_reference_type__3(BOOL const mutable_binding__, Type__0 const *_Nonnull type__, BOOL const nullable__);
string convert_type__3(BOOL const mutable_binding__, Type__0 const *_Nonnull type__, BOOL const optional__);
string convert_type__2(BOOL const mutable_binding__, Semantic_Node__0 const *_Nonnull const type_node__);
string convert_parameter_list__4(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const parameters__, string const self_type__, BOOL const is_main_function__);
string convert_method_parameter_list__3(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const parameters__, string const self_type__);
string convert_parameter_list__3(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const parameters__, BOOL const is_main_function__);
string convert_parameter_list__2(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const parameters__);
void convert_expression__2(Semantic_Node__0 const *_Nonnull const syntax__, Source_File_Builder__0 *_Nonnull const builder__);
int32 literal_length__1(string const value__);
code_point code_point_literal_value__1(string const value__);
void convert_reference_type_constructor_arguments__3(Semantic_Node__0 const *_Nonnull const syntax__, Source_File_Builder__0 *_Nonnull const builder__, string const type_name__);
void convert_member_access__2(Semantic_Node__0 const *_Nonnull const lhs__, Source_File_Builder__0 *_Nonnull const builder__);
void emit_statement__2(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const statement__);
void emit_method_body__3(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const block__, BOOL const is_associated_function__);
void emit_constructor_body__4(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const block__, string const self_type__, BOOL const is_value_type__);
void emit_member_declaration__4(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const member__, string const class_name__, BOOL const is_value_type__);
void emit_default_constructor__3(Emitter__0 *_Nonnull const emitter__, string const type_name__, BOOL const is_value_type__);
void emit_declaration__2(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const declaration__);
void emit_compilation_unit__2(Emitter__0 *_Nonnull const emitter__, Compilation_Unit__0 const *_Nonnull const unit__);
void emit_preamble__1(Emitter__0 *_Nonnull const emitter__);
void emit_entry_point_adapter__1(Emitter__0 *_Nonnull const emitter__);
Name__0 *_Nonnull Name__0__0new__global_namespace__0(Name__0 *_Nonnull self);
Name__0 *_Nonnull Name__0__0new__global_namespace__1(Name__0 *_Nonnull self, Package_Name__0 const *_Nonnull const package__);
Name__0 *_Nonnull Name__0__0new__3(Name__0 *_Nonnull self, Name__0 const *_Nonnull const qualifier__, int32 const kind__, string const name__);
Name__0 *_Nonnull Name__0__0new__4(Name__0 *_Nonnull self, Name__0 const *_Nonnull const qualifier__, int32 const kind__, string const name__, BOOL const is_special__);
Name__0 *_Nonnull Name__0__0new__special__3(Name__0 *_Nonnull self, Name__0 const *_Nonnull const qualifier__, int32 const kind__, string const name__);
Name__0 *_Nonnull Name__0__0new__4(Name__0 *_Nonnull self, Package_Name__0 const *_Nullable const package__, int32 const kind__, Strings__0 const *_Nonnull const segments__, BOOL const is_special__);
string unqualified_name__1(Name__0 const *_Nonnull const name__);
string full_name__1(Name__0 const *_Nonnull const name__);
BOOL is_qualified_by__2(Name__0 const *_Nonnull const name__, Name__0 const *_Nonnull const qualifier__);
BOOL qualifier_is__2(Name__0 const *_Nonnull const name__, Name__0 const *_Nonnull const qualifier__);
BOOL names__2(Name__0 const *_Nonnull const name__, Name__0 const *_Nonnull const other__);
BOOL is_package_qualified__1(Name__0 const *_Nonnull const name__);
Name__0 const *_Nonnull remove_package__1(Name__0 const *_Nonnull const name__);
void unit_test_Name__0();
void name_with_unspecified_package_names_name_with_package__0();
void name_with_unspecified_package_names_itself__0();
Package_Name__0 *_Nonnull Package_Name__0__0new__1(Package_Name__0 *_Nonnull self, string const name__);
string full_name__1(Package_Name__0 const *_Nonnull const package_name__);
Symbol__0 *_Nonnull Symbol__0__0new__identifier__1(Symbol__0 *_Nonnull self, string const name__);
Symbol__0 *_Nonnull Symbol__0__0new__identifier__2(Symbol__0 *_Nonnull self, string const name__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__);
Symbol__0 *_Nonnull Symbol__0__0new__identifier__2(Symbol__0 *_Nonnull self, string const name__, system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const children__);
Symbol__0 *_Nonnull Symbol__0__0new__constructor__2(Symbol__0 *_Nonnull self, string const name__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__);
Symbol__0 *_Nonnull Symbol__0__0new__package__2(Symbol__0 *_Nonnull self, string const name__, system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const children__);
Symbol__0 *_Nonnull Symbol__0__0new__declaring__3(Symbol__0 *_Nonnull self, Type__0 const *_Nonnull const declares_type__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__, system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const children__);
Symbol__0 *_Nonnull Symbol__0__0new__of_type__4(Symbol__0 *_Nonnull self, string const name__, Type__0 const *_Nonnull const of_type__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__, system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const children__);
Symbol__0 const *_Nullable get_child__3(Symbol__0 const *_Nonnull const symbol__, string const name__, int32 const kind__);
void unit_test_Symbol__0();
void Package_symbol_children_can_be_found_by_name_and_kind__0();
Type__0 *_Nonnull Type__0__0new__3(Type__0 *_Nonnull self, int32 const kind__, Name__0 const *_Nonnull const name__, BOOL const is_mutable__);
Type__0 *_Nonnull Type__0__0new__parameter__1(Type__0 *_Nonnull self, string const name__);
Type__0 *_Nonnull Type__0__0new__4(Type__0 *_Nonnull self, int32 const kind__, Name__0 const *_Nonnull const name__, system__collections__List__1<Type__0 const *_Nonnull> const *_Nonnull const type_parameters__, BOOL const is_mutable__);
Type__0 *_Nonnull Type__0__0new__primitive__1(Type__0 *_Nonnull self, Name__0 const *_Nonnull const name__);
Type__0 *_Nonnull Type__0__0new__primitive__2(Type__0 *_Nonnull self, Name__0 const *_Nonnull const name__, system__collections__List__1<Type__0 const *_Nonnull> const *_Nonnull const type_parameters__);
Type__0 *_Nonnull Type__0__0new__namespace__1(Type__0 *_Nonnull self, Name__0 const *_Nonnull const name__);
Type__0 *_Nonnull Type__0__0new__generic__2(Type__0 *_Nonnull self, Type__0 const *_Nonnull const definition__, system__collections__List__1<Type__0 const *_Nonnull> const *_Nonnull const type_arguments__);
Type__0 *_Nonnull Type__0__0new__6(Type__0 *_Nonnull self, int32 const kind__, Name__0 const *_Nonnull const name__, system__collections__List__1<Type__0 const *_Nonnull> const *_Nonnull const type_parameters__, BOOL const is_primitive__, BOOL const is_potentially_mutable__, BOOL const is_mutable__);
Type__0 const *_Nonnull make_mutable_type__1(Type__0 const *_Nonnull const type__);
Type__0 const *_Nonnull make_immutable_type__1(Type__0 const *_Nonnull const type__);
Type__0 const *_Nonnull remove_type_package__1(Type__0 const *_Nonnull const type__);
Name_Subtable__0 *_Nonnull Name_Subtable__0__0new__global_namespace__1(Name_Subtable__0 *_Nonnull self, Name_Table__0 const *_Nonnull const name_table__);
Name_Subtable__0 *_Nonnull Name_Subtable__0__0new__global_namespace__2(Name_Subtable__0 *_Nonnull self, Name_Table__0 const *_Nonnull const name_table__, Package_Name__0 const *_Nonnull const package_name__);
Name_Subtable__0 *_Nonnull Name_Subtable__0__0new__3(Name_Subtable__0 *_Nonnull self, Name_Subtable__0 const *_Nonnull const parent__, Name__0 const *_Nonnull const name__, Type__0 const *_Nonnull const type__);
void add_subtable__3(Name_Subtable__0 *_Nonnull const scope__, Name__0 const *_Nonnull const name__, Type__0 const *_Nonnull const type__);
Name_Subtable__0 *_Nullable find__2(Name_Subtable__0 const *_Nonnull const scope__, string const name__);
Name_Subtable__0 *_Nullable find_special__2(Name_Subtable__0 const *_Nonnull const scope__, string const name__);
Name_Subtable__0 *_Nullable find__3(Name_Subtable__0 const *_Nonnull const scope__, string const name__, BOOL const is_special__);
Name_Subtable__0 *_Nullable lookup__2(Name_Subtable__0 const *_Nonnull const scope__, string const name__);
Name_Subtable__0 *_Nullable lookup_special__2(Name_Subtable__0 const *_Nonnull const scope__, string const name__);
Name_Subtable__0 *_Nullable lookup__3(Name_Subtable__0 const *_Nonnull const scope__, string const name__, BOOL const is_special__);
Name_Subtable__0 const *_Nullable get_scope__2(Name_Subtable__0 const *_Nonnull const scope__, Name__0 const *_Nonnull const name__);
void bind_type__2(Name_Subtable__0 *_Nonnull const scope__, Type__0 const *_Nonnull const type__);
Name_Subtable__0 *_Nonnull as_mut__1(Name_Subtable__0 const *_Nonnull const scope__);
void unit_test_Name_Subtable__0();
void global_namespace_contains_added_name__0();
void namespace_contains_added_name__0();
Name_Table__0 *_Nonnull Name_Table__0__0new__0(Name_Table__0 *_Nonnull self);
Name__0 const *_Nonnull add_package__2(Name_Table__0 *_Nonnull const name_table__, Package_Name__0 const *_Nonnull const package_name__);
Name__0 const *_Nonnull add_name__3(Name_Table__0 *_Nonnull const name_table__, Name__0 const *_Nonnull const parent__, Symbol__0 const *_Nonnull const symbol__);
void add_name__3(Name_Table__0 *_Nonnull const name_table__, Name__0 const *_Nonnull const name__, Type__0 const *_Nonnull const type__);
Name_Subtable__0 const *_Nullable get_name__2(Name_Table__0 const *_Nonnull const name_table__, Name__0 const *_Nonnull const name__);
Name_Table__0 const *_Nonnull build_name_table__3(Package_Name__0 const *_Nonnull const package_name__, Syntax_Node__0 const *_Nonnull const package_syntax__, system__collections__List__1<Package_Reference__0 const *_Nonnull> const *_Nonnull const references__);
void add_referenced__2(Name_Table__0 *_Nonnull const name_table__, system__collections__List__1<Package_Reference__0 const *_Nonnull> const *_Nonnull const references__);
void add_symbol__3(Name_Table__0 *_Nonnull const name_table__, Name__0 const *_Nonnull const parent__, Symbol__0 const *_Nonnull const symbol__);
void add_package__3(Name_Table__0 *_Nonnull const name_table__, Package_Name__0 const *_Nonnull const package_name__, Syntax_Node__0 const *_Nonnull const package_syntax__);
void add_compilation_unit__3(Name_Table__0 *_Nonnull const name_table__, Name__0 const *_Nonnull const global_namespace__, Syntax_Node__0 const *_Nonnull const compilation_unit__);
void add_syntax__3(Name_Table__0 *_Nonnull const name_table__, Name__0 const *_Nonnull const parent__, Syntax_Node__0 const *_Nonnull const syntax__);
void add_function__3(Name_Table__0 *_Nonnull const name_table__, Name__0 const *_Nonnull const name__, Syntax_Node__0 const *_Nonnull const function__);
void unit_test_Name_Table_Builder__0();
void table_contains_referenced_child_names__0();
void can_get_root_namespace_from_name__0();
void can_get_Console_class_from_name_without_package__0();
void can_get_Optional_class_from_name_with_package__0();

// Class Declarations

struct Source_Text__0
{
	string package__;
	string path__;
	string name__;
	string text__;
	Text_Lines__0 const *_Nonnull lines__;
};

struct Text_Line__0
{
	Source_Text__0 const *_Nonnull source__;
	int32 start__;
	int32 byte_length__;
};

struct Text_Lines__0
{
	Source_Text__0 const *_Nonnull source__;
	Ints__0 const *_Nonnull start_of_line__;
};

struct Text_Position__0
{
	int32 character_offset__;
	int32 line__;
	int32 column__;
};

struct Text_Span__0
{
	int32 start__;
	int32 byte_length__;
};

struct Source_File_Builder__0
{
	system__text__String_Builder__0 *_Nonnull code__;
	system__text__String_Builder__0 *_Nonnull indent__;
	BOOL firstElement__;
	BOOL afterBlock__;
};

struct Compilation_Unit__0
{
	Syntax_Node__0 const *_Nonnull syntax__;
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull declarations__;
};

struct Package__0
{
	Package_Name__0 const *_Nonnull name__;
	system__collections__List__1<Package_Reference__0 const *_Nonnull> const *_Nonnull references__;
	system__collections__List__1<Compilation_Unit__0 const *_Nonnull> const *_Nonnull compilation_units__;
	Symbol__0 const *_Nonnull symbol__;
};

struct Package_Reference__0
{
	string name__;
	Package__0 const *_Nonnull package__;
};

struct Semantic_Node__0
{
	Syntax_Node__0 const *_Nonnull syntax__;
	int32 kind__;
	BOOL is_missing__;
	Source_Text__0 const *_Nonnull source__;
	int32 start__;
	int32 byte_length__;
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull children__;
	system__collections__List__1<Diagnostic__0 const *_Nonnull> *_Nonnull node_diagnostics__;
	Type__0 const *_Nullable of_type__;
	Type__0 const *_Nullable converted_type__;
	Type__0 const *_Nullable declares_type__;
	Type__0 const *_Nullable referenced_type__;
};

struct Semantic_Tree_Builder__0
{
	Name__0 const *_Nonnull optional_type_name__;
};

struct Compilation_Unit_Parser__0
{
	Token_Stream__0 *_Nonnull token_stream__;
	Syntax_Node__0 const *_Nullable token__;
	Syntax_Node__0 const *_Nullable compilation_unit__;
};

struct Syntax_Node__0
{
	int32 kind__;
	BOOL is_missing__;
	Source_Text__0 const *_Nonnull source__;
	int32 start__;
	int32 byte_length__;
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> const *_Nonnull children__;
	system__collections__List__1<Diagnostic__0 const *_Nonnull> *_Nonnull node_diagnostics__;
};

struct Token_Stream__0
{
	Source_Text__0 const *_Nonnull source__;
	int32 position__;
	system__collections__List__1<Diagnostic__0 const *_Nonnull> *_Nonnull diagnostics__;
	BOOL end_of_file__;
};

struct Diagnostic__0
{
	int32 level__;
	int32 phase__;
	Source_Text__0 const *_Nonnull source__;
	Text_Span__0 const *_Nonnull span__;
	Text_Position__0 const *_Nonnull position__;
	string message__;
};

struct Emitter__0
{
	Package__0 const *_Nonnull package__;
	system__collections__List__1<Source_Text__0 const *_Nonnull> const *_Nonnull resources__;
	Source_File_Builder__0 *_Nonnull type_declarations__;
	Source_File_Builder__0 *_Nonnull function_declarations__;
	Source_File_Builder__0 *_Nonnull class_declarations__;
	Source_File_Builder__0 *_Nonnull global_definitions__;
	Source_File_Builder__0 *_Nonnull definitions__;
	string main_function_name__;
	string main_function_return_type__;
	BOOL main_function_accepts_console__;
	BOOL main_function_accepts_args__;
};

struct Name__0
{
	Package_Name__0 const *_Nullable package__;
	int32 kind__;
	Strings__0 const *_Nonnull segments__;
	BOOL is_special__;
};

struct Package_Name__0
{
	string unqualified__;
};

struct Symbol__0
{
	string name__;
	BOOL is_special_name__;
	int32 kind__;
	Type__0 const *_Nonnull of_type__;
	Type__0 const *_Nonnull declares_type__;
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull declarations__;
	system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull children__;
};

struct Type__0
{
	int32 kind__;
	Name__0 const *_Nonnull name__;
	system__collections__List__1<Type__0 const *_Nonnull> const *_Nonnull type_parameters__;
	BOOL is_primitive__;
	BOOL is_value_type__;
	BOOL is_potentially_mutable__;
	BOOL is_mutable__;
};

struct Name_Subtable__0
{
	Name_Table__0 const *_Nonnull name_table__;
	Name_Subtable__0 const *_Nullable parent__;
	Name__0 const *_Nonnull name__;
	Type__0 const *_Nonnull type__;
	system__collections__List__1<Name_Subtable__0 *_Nonnull> *_Nonnull subtables__;
};

struct Name_Table__0
{
	Name_Subtable__0 *_Nonnull any_package__;
	system__collections__List__1<Name_Subtable__0 *_Nonnull> *_Nonnull packages__;
};

// Global Definitions
int32 const Success__ = ((int32){0});
int32 const UsageError__ = ((int32){64});
int32 const DataError__ = ((int32){65});
int32 const SkippedTokens__ = int32__0op__neg(((int32){1}));
int32 const EndOfFileToken__ = ((int32){0});
int32 const LeftBrace__ = ((int32){1});
int32 const RightBrace__ = ((int32){2});
int32 const LeftParen__ = ((int32){3});
int32 const RightParen__ = ((int32){4});
int32 const Semicolon__ = ((int32){5});
int32 const Comma__ = ((int32){6});
int32 const Dot__ = ((int32){7});
int32 const Colon__ = ((int32){8});
int32 const LeftBracket__ = ((int32){9});
int32 const RightBracket__ = ((int32){10});
int32 const Question__ = ((int32){11});
int32 const EqualsEquals__ = ((int32){12});
int32 const Equals__ = ((int32){13});
int32 const PlusEquals__ = ((int32){14});
int32 const Plus__ = ((int32){15});
int32 const Arrow__ = ((int32){16});
int32 const MinusEquals__ = ((int32){17});
int32 const Minus__ = ((int32){18});
int32 const Slash__ = ((int32){19});
int32 const EqualsSlashEquals__ = ((int32){20});
int32 const LessThanEquals__ = ((int32){21});
int32 const LessThan__ = ((int32){22});
int32 const GreaterThanEquals__ = ((int32){23});
int32 const GreaterThan__ = ((int32){24});
int32 const StringLiteral__ = ((int32){25});
int32 const CodePointLiteral__ = ((int32){26});
int32 const Identifier__ = ((int32){27});
int32 const Number__ = ((int32){28});
int32 const NewKeyword__ = ((int32){29});
int32 const NotOperator__ = ((int32){30});
int32 const NullReservedWord__ = ((int32){31});
int32 const SelfKeyword__ = ((int32){32});
int32 const TrueKeyword__ = ((int32){33});
int32 const FalseKeyword__ = ((int32){34});
int32 const IdentifierName__ = ((int32){35});
int32 const GenericName__ = ((int32){36});
int32 const QualifiedName__ = ((int32){37});
int32 const PackageQualifiedName__ = ((int32){38});
int32 const MutableKeyword__ = ((int32){39});
int32 const OptionalType__ = ((int32){40});
int32 const PredefinedType__ = ((int32){41});
int32 const CodePoint__ = ((int32){42});
int32 const String__ = ((int32){43});
int32 const Int__ = ((int32){44});
int32 const Bool__ = ((int32){45});
int32 const Void__ = ((int32){46});
int32 const UnsignedInt__ = ((int32){47});
int32 const ParameterList__ = ((int32){48});
int32 const Parameter__ = ((int32){49});
int32 const SelfParameter__ = ((int32){50});
int32 const VarKeyword__ = ((int32){51});
int32 const MutableType__ = ((int32){52});
int32 const NewExpression__ = ((int32){53});
int32 const ArgumentList__ = ((int32){54});
int32 const NotExpression__ = ((int32){55});
int32 const ParenthesizedExpression__ = ((int32){56});
int32 const NoneLiteralExpression__ = ((int32){57});
int32 const SelfExpression__ = ((int32){58});
int32 const TrueLiteralExpression__ = ((int32){59});
int32 const FalseLiteralExpression__ = ((int32){60});
int32 const StringLiteralExpression__ = ((int32){61});
int32 const CodePointLiteralExpression__ = ((int32){62});
int32 const NumericLiteralExpression__ = ((int32){63});
int32 const AssignmentExpression__ = ((int32){64});
int32 const OrExpression__ = ((int32){65});
int32 const AndExpression__ = ((int32){66});
int32 const EqualExpression__ = ((int32){67});
int32 const NotEqualExpression__ = ((int32){68});
int32 const AndKeyword__ = ((int32){69});
int32 const OrKeyword__ = ((int32){70});
int32 const ComparisonExpression__ = ((int32){71});
int32 const AddExpression__ = ((int32){72});
int32 const SubtractExpression__ = ((int32){73});
int32 const InvocationExpression__ = ((int32){74});
int32 const MemberAccessExpression__ = ((int32){75});
int32 const ElementAccessExpression__ = ((int32){76});
int32 const NegateExpression__ = ((int32){77});
int32 const ReturnKeyword__ = ((int32){78});
int32 const ReturnStatement__ = ((int32){79});
int32 const LoopKeyword__ = ((int32){80});
int32 const LoopStatement__ = ((int32){81});
int32 const Block__ = ((int32){82});
int32 const WhileKeyword__ = ((int32){83});
int32 const WhileStatement__ = ((int32){84});
int32 const ForKeyword__ = ((int32){85});
int32 const ForStatement__ = ((int32){86});
int32 const LetKeyword__ = ((int32){87});
int32 const VariableDeclaration__ = ((int32){88});
int32 const LocalDeclarationStatement__ = ((int32){89});
int32 const InKeyword__ = ((int32){90});
int32 const DoKeyword__ = ((int32){91});
int32 const DoWhileStatement__ = ((int32){92});
int32 const IfKeyword__ = ((int32){93});
int32 const ElseKeyword__ = ((int32){94});
int32 const IfStatement__ = ((int32){95});
int32 const ElseClause__ = ((int32){96});
int32 const BreakKeyword__ = ((int32){97});
int32 const BreakStatement__ = ((int32){98});
int32 const ContinueKeyword__ = ((int32){99});
int32 const ContinueStatement__ = ((int32){100});
int32 const ExpressionStatement__ = ((int32){101});
int32 const PublicKeyword__ = ((int32){102});
int32 const ProtectedKeyword__ = ((int32){103});
int32 const InternalKeyword__ = ((int32){104});
int32 const PrivateKeyword__ = ((int32){105});
int32 const ConstructorDeclaration__ = ((int32){106});
int32 const FieldDeclaration__ = ((int32){107});
int32 const MethodDeclaration__ = ((int32){108});
int32 const GlobalDeclaration__ = ((int32){109});
int32 const ClassKeyword__ = ((int32){110});
int32 const ClassDeclaration__ = ((int32){111});
int32 const EnumKeyword__ = ((int32){112});
int32 const StructKeyword__ = ((int32){113});
int32 const EnumDeclaration__ = ((int32){114});
int32 const EnumMemberDeclaration__ = ((int32){115});
int32 const FunctionDeclaration__ = ((int32){116});
int32 const CompilationUnit__ = ((int32){117});
int32 const PackageNode__ = ((int32){118});
int32 const Percent__ = ((int32){119});
int32 const RemainderExpression__ = ((int32){120});
int32 const Pipe__ = ((int32){121});
int32 const MagnitudeExpression__ = ((int32){122});
int32 const Asterisk__ = ((int32){123});
int32 const MultiplyExpression__ = ((int32){124});
int32 const DivideExpression__ = ((int32){125});
int32 const NoneKeyword__ = ((int32){126});
int32 const StructDeclaration__ = ((int32){127});
int32 const ImmutableType__ = ((int32){128});
int32 const NamespaceDeclaration__ = ((int32){129});
int32 const Lexing__ = ((int32){1});
int32 const Parsing__ = ((int32){2});
int32 const Analysis__ = ((int32){3});
int32 const Info__ = ((int32){1});
int32 const Warning__ = ((int32){2});
int32 const RuntimeError__ = ((int32){3});
int32 const CompilationError__ = ((int32){4});
int32 const FatalCompilationError__ = ((int32){5});
int32 const NamespaceName__ = ((int32){1});
int32 const TypeName__ = ((int32){2});
int32 const FunctionName__ = ((int32){3});
int32 const TypeParameterName__ = ((int32){4});
int32 const VariableName__ = ((int32){5});
int32 const IdentifierSymbol__ = ((int32){0});
int32 const PackageSymbol__ = ((int32){1});
int32 const ReferenceType__ = ((int32){1});
int32 const ValueType__ = ((int32){2});
int32 const NamespaceType__ = ((int32){3});
int32 const TypeParameterType__ = ((int32){4});
int32 const FunctionType__ = ((int32){5});

// Definitions

Package__0 const *_Nonnull compile__1(system__collections__List__1<Source_Text__0 const *_Nonnull> const *_Nonnull const sources__)
{
	Syntax_Node__0 const *_Nonnull const package_syntax__ = parse_package__1(sources__);
	Package__0 const *_Nonnull const package__ = analyze_semantics__1(package_syntax__);
	return package__;
}

void write__2(system__console__Console__0 *_Nonnull const console__, system__collections__List__1<Diagnostic__0 const *_Nonnull> const *_Nonnull const diagnostics__)
{
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(diagnostics__); void_ptr__0next(&iter);)
	{
		Diagnostic__0 const *_Nonnull const diagnostic__ = void_ptr__0current(&iter);
		Text_Position__0 const *_Nonnull const position__ = diagnostic__->position__;
		string severity__;
		if (cond(int32__0op__equal(diagnostic__->level__, Info__)))
		{
			severity__ = ((string){13,(uint8_t const*)"Informational"});
		}
		else if (cond(int32__0op__equal(diagnostic__->level__, Warning__)))
		{
			severity__ = ((string){7,(uint8_t const*)"Warning"});
		}
		else
		{
			severity__ = ((string){5,(uint8_t const*)"Error"});
		}

		console__->WriteLine__1(string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(diagnostic__->source__->path__, ((string){1,(uint8_t const*)":"})), int_to_string__1(position__->line__)), ((string){1,(uint8_t const*)":"})), int_to_string__1(position__->column__)), ((string){1,(uint8_t const*)" "})), severity__), ((string){1,(uint8_t const*)":"})));
		console__->WriteLine__1(string__0op__add(((string){2,(uint8_t const*)"  "}), diagnostic__->message__));
	}
}

BOOL has_errors__1(system__collections__List__1<Diagnostic__0 const *_Nonnull> const *_Nonnull const diagnostics__)
{
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(diagnostics__); void_ptr__0next(&iter);)
	{
		Diagnostic__0 const *_Nonnull const diagnostic__ = void_ptr__0current(&iter);
		if (cond(int32__0op__gte(diagnostic__->level__, CompilationError__)))
		{
			return TRUE;
		}
	}

	return FALSE;
}

int32 main__2(system__console__Console__0 *_Nonnull const console__, system__console__Arguments__0 const *_Nonnull const args__)
{
	if (cond(bool_op(bool_arg(int32__0op__equal(args__->op__magnitude(), ((int32){1}))) && bool_arg(string__0op__equal(system__console__Arguments__0__0op__element(args__, ((int32){0})), ((string){11,(uint8_t const*)"--unit-test"}))))))
	{
		run_unit_tests__1(console__);
		return ((int32){0});
	}

	Strings__0 *_Nonnull const sourceFilePaths__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	Strings__0 *_Nonnull const resourceFilePaths__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	string outputFilePath__ = ((string){0,(uint8_t const*)""});
	BOOL verbose__ = FALSE;
	int32 argType__ = ((int32){0});
	for (string__0iter iter = system__console__Arguments__0__0iterate(args__); string__0next(&iter);)
	{
		string const arg__ = string__0current(&iter);
		if (cond(int32__0op__equal(argType__, ((int32){0}))))
		{
			if (cond(string__0op__equal(arg__, ((string){2,(uint8_t const*)"-r"}))))
			{
				argType__ = ((int32){1});
			}
			else if (cond(string__0op__equal(arg__, ((string){2,(uint8_t const*)"-o"}))))
			{
				argType__ = ((int32){2});
			}
			else if (cond(bool_op(bool_arg(string__0op__equal(arg__, ((string){2,(uint8_t const*)"-v"}))) || bool_arg(string__0op__equal(arg__, ((string){9,(uint8_t const*)"--verbose"}))))))
			{
				verbose__ = TRUE;
			}
			else
			{
				add_string__2(sourceFilePaths__, arg__);
			}
		}
		else if (cond(int32__0op__equal(argType__, ((int32){1}))))
		{
			add_string__2(resourceFilePaths__, arg__);
			argType__ = ((int32){0});
		}
		else if (cond(int32__0op__equal(argType__, ((int32){2}))))
		{
			outputFilePath__ = arg__;
			argType__ = ((int32){0});
		}
	}

	if (cond(verbose__))
	{
		console__->WriteLine__1(((string){23,(uint8_t const*)"Adamant Compiler v0.1.0"}));
	}

	if (cond(bool_op(bool_arg(int32__0op__equal(sourceFilePaths__->count__, ((int32){0}))) || bool_arg(string__0op__equal(outputFilePath__, ((string){0,(uint8_t const*)""}))))))
	{
		console__->WriteLine__1(((string){56,(uint8_t const*)"Args: <Input File(s)> -o <OutputFile> -r <Resource File>"}));
		return UsageError__;
	}

	system__collections__List__1<Source_Text__0 const *_Nonnull> *_Nonnull const resources__ = system__collections__List__1__0new__0<Source_Text__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Source_Text__0 const *_Nonnull>)));
	if (cond(int32__0op__gt(resourceFilePaths__->count__, ((int32){0}))))
	{
		if (cond(verbose__))
		{
			console__->WriteLine__1(((string){18,(uint8_t const*)"Reading Resources:"}));
		}

		for (string__0iter iter = Strings__0__0iterate(resourceFilePaths__); string__0next(&iter);)
		{
			string const resourceFilePath__ = string__0current(&iter);
			if (cond(verbose__))
			{
				console__->WriteLine__1(string__0op__add(((string){2,(uint8_t const*)"  "}), resourceFilePath__));
			}

			resources__->add__1(read_source__1(resourceFilePath__));
		}
	}

	if (cond(verbose__))
	{
		console__->WriteLine__1(((string){10,(uint8_t const*)"Compiling:"}));
	}

	system__collections__List__1<Source_Text__0 const *_Nonnull> *_Nonnull const sources__ = system__collections__List__1__0new__0<Source_Text__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Source_Text__0 const *_Nonnull>)));
	for (string__0iter iter = Strings__0__0iterate(sourceFilePaths__); string__0next(&iter);)
	{
		string const sourceFilePath__ = string__0current(&iter);
		if (cond(verbose__))
		{
			console__->WriteLine__1(string__0op__add(((string){2,(uint8_t const*)"  "}), sourceFilePath__));
		}

		sources__->add__1(read_source__1(sourceFilePath__));
	}

	Package__0 const *_Nonnull const package__ = compile__1(sources__);
	system__collections__List__1<Diagnostic__0 const *_Nonnull> const *_Nonnull const diagnostics__ = all_diagnostics__1(package__);
	write__2(console__, diagnostics__);
	if (cond(has_errors__1(diagnostics__)))
	{
		return DataError__;
	}

	Emitter__0 *_Nonnull emitter__ = Emitter__0__0new__2(allocate(sizeof(Emitter__0)), package__, resources__);
	string const translated__ = emit__1(emitter__);
	if (cond(verbose__))
	{
		console__->Write__1(((string){8,(uint8_t const*)"Output: "}));
		console__->WriteLine__1(outputFilePath__);
	}

	system__io__File_Writer__0 *_Nonnull const outputFile__ = system__io__File_Writer__0__0new__1(allocate(sizeof(system__io__File_Writer__0)), outputFilePath__);
	outputFile__->Write__1(translated__);
	outputFile__->Close__0();
	string outputDirPath__ = outputFilePath__;
	int32 index__ = string_last_index_of__2(outputDirPath__, ((code_point){/*/*/0x2F}));
	if (cond(int32__0op__not_equal(index__, int32__0op__neg(((int32){1})))))
	{
		outputDirPath__ = substring__3(outputDirPath__, ((int32){0}), int32__0op__add(index__, ((int32){1})));
	}

	index__ = string_last_index_of__2(outputDirPath__, ((code_point){/*\\*/0x5C}));
	if (cond(int32__0op__not_equal(index__, int32__0op__neg(((int32){1})))))
	{
		outputDirPath__ = substring__3(outputDirPath__, ((int32){0}), int32__0op__add(index__, ((int32){1})));
	}

	if (cond(verbose__))
	{
		console__->Write__1(((string){30,(uint8_t const*)"Outputting RuntimeLibrary to: "}));
		console__->WriteLine__1(outputDirPath__);
	}

	system__io__File_Writer__0 *_Nonnull resourceFile__ = system__io__File_Writer__0__0new__1(allocate(sizeof(system__io__File_Writer__0)), string__0op__add(outputDirPath__, ((string){18,(uint8_t const*)"RuntimeLibrary.hpp"})));
	resourceFile__->Write__1(get_resource__1(((string){18,(uint8_t const*)"RuntimeLibrary.hpp"})));
	resourceFile__->Close__0();
	resourceFile__ = system__io__File_Writer__0__0new__1(allocate(sizeof(system__io__File_Writer__0)), string__0op__add(outputDirPath__, ((string){18,(uint8_t const*)"RuntimeLibrary.cpp"})));
	resourceFile__->Write__1(get_resource__1(((string){18,(uint8_t const*)"RuntimeLibrary.cpp"})));
	resourceFile__->Close__0();
	return Success__;
}

Source_Text__0 const *_Nonnull read_source__1(string const path__)
{
	system__io__File_Reader__0 *_Nonnull const file__ = system__io__File_Reader__0__0new__1(allocate(sizeof(system__io__File_Reader__0)), path__);
	string const contents__ = file__->ReadToEndSync__0();
	file__->Close__0();
	return Source_Text__0__0new__3(allocate(sizeof(Source_Text__0)), ((string){9,(uint8_t const*)"<default>"}), path__, contents__);
}

void run_unit_tests__1(system__console__Console__0 *_Nonnull const console__)
{
	console__->WriteLine__1(((string){21,(uint8_t const*)"Running Unit Tests..."}));
	unit_test_Text_Position__0();
	unit_test_build_primitives_package__0();
	unit_test_build_runtime_library_package__0();
	unit_test_Name__0();
	unit_test_Name_Subtable__0();
	unit_test_Name_Table_Builder__0();
	unit_test_Symbol__0();
}

Source_Text__0 *_Nonnull Source_Text__0__0new__3(Source_Text__0 *_Nonnull self, string const package__, string const path__, string const text__)
{
	self->package__ = package__;
	self->path__ = path__;
	string name__ = path__;
	int32 index__ = string_last_index_of__2(name__, ((code_point){/*/*/0x2F}));
	if (cond(int32__0op__not_equal(index__, int32__0op__neg(((int32){1})))))
	{
		name__ = substring__2(name__, int32__0op__add(index__, ((int32){1})));
	}

	index__ = string_last_index_of__2(name__, ((code_point){/*\\*/0x5C}));
	if (cond(int32__0op__not_equal(index__, int32__0op__neg(((int32){1})))))
	{
		name__ = substring__2(name__, int32__0op__add(index__, ((int32){1})));
	}

	self->name__ = name__;
	self->text__ = text__;
	self->lines__ = Text_Lines__0__0new__2(allocate(sizeof(Text_Lines__0)), self, line_starts__1(text__));
	return self;
}

Ints__0 const *_Nonnull line_starts__1(string const text__)
{
	int32 const length__ = string_byte_length__1(text__);
	Ints__0 *_Nonnull const starting_positions__ = Ints__0__0new__0(allocate(sizeof(Ints__0)));
	add_int__2(starting_positions__, ((int32){0}));
	int32 position__ = ((int32){0});
	while (cond(int32__0op__lt(position__, length__)))
	{
		code_point const c__ = string__0__0op__element(text__, position__);
		op__add_assign(&(position__), ((int32){1}));
		if (cond(bool_op(bool_arg(code_point__0op__gt(c__, ((code_point){/*\r*/0xD}))) && bool_arg(code_point__0op__lte(c__, ((code_point){/*\x7F*/0x7F}))))))
		{
			continue;
		}

		if (cond(code_point__0op__equal(c__, ((code_point){/*\r*/0xD}))))
		{
			if (cond(bool_op(bool_arg(int32__0op__lt(position__, length__)) && bool_arg(code_point__0op__equal(string__0__0op__element(text__, position__), ((code_point){/*\n*/0xA}))))))
			{
				op__add_assign(&(position__), ((int32){1}));
			}
		}
		else if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(code_point__0op__equal(c__, ((code_point){/*\n*/0xA}))) || bool_arg(code_point__0op__equal(c__, ((code_point){/*\x0B*/0xB}))))) || bool_arg(code_point__0op__equal(c__, ((code_point){/*\f*/0xC}))))) || bool_arg(code_point__0op__equal(c__, ((code_point){/*\x85*/0x85}))))))
		{
		}
		else
		{
			continue;
		}

		add_int__2(starting_positions__, position__);
	}

	return starting_positions__;
}

int32 source_byte_length__1(Source_Text__0 const *_Nonnull const source__)
{
	return string_byte_length__1(source__->text__);
}

Text_Position__0 const *_Nonnull position_of_start__2(Source_Text__0 const *_Nonnull const source__, Text_Span__0 const *_Nonnull const span__)
{
	int32 const char_offset__ = span__->start__;
	int32 const line_number__ = line_containing_offset__2(source__->lines__, char_offset__);
	int32 const line_start__ = get_line__2(source__->lines__, line_number__)->start__;
	int32 column__ = int32__0op__add(int32__0op__sub(char_offset__, line_start__), ((int32){1}));
	int32 i__ = line_start__;
	while (cond(int32__0op__lt(i__, char_offset__)))
	{
		if (cond(code_point__0op__equal(string__0__0op__element(source__->text__, i__), ((code_point){/*\t*/0x9}))))
		{
			op__add_assign(&(column__), ((int32){3}));
		}

		op__add_assign(&(i__), ((int32){1}));
	}

	return Text_Position__0__0new__3(allocate(sizeof(Text_Position__0)), char_offset__, line_number__, column__);
}

Text_Line__0 *_Nonnull Text_Line__0__0new__3(Text_Line__0 *_Nonnull self, Source_Text__0 const *_Nonnull const source__, int32 const start__, int32 const length__)
{
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = length__;
	return self;
}

Text_Line__0 *_Nonnull Text_Line__0__0new__spanning__3(Text_Line__0 *_Nonnull self, Source_Text__0 const *_Nonnull const source__, int32 const start__, int32 const end__)
{
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = int32__0op__sub(end__, start__);
	return self;
}

Text_Lines__0 *_Nonnull Text_Lines__0__0new__2(Text_Lines__0 *_Nonnull self, Source_Text__0 const *_Nonnull const source__, Ints__0 const *_Nonnull const start_of_line__)
{
	self->source__ = source__;
	self->start_of_line__ = start_of_line__;
	return self;
}

int32 line_count__1(Text_Lines__0 const *_Nonnull const lines__)
{
	return lines__->start_of_line__->count__;
}

Text_Line__0 const *_Nonnull get_line__2(Text_Lines__0 const *_Nonnull const lines__, int32 const line_number__)
{
	assert__2(int32__0op__gt(line_number__, ((int32){0})), string__0op__add(((string){5,(uint8_t const*)"line "}), int_to_string__1(line_number__)));
	assert__2(int32__0op__lte(line_number__, line_count__1(lines__)), string__0op__add(((string){5,(uint8_t const*)"line "}), int_to_string__1(line_number__)));
	int32 const line_index__ = int32__0op__sub(line_number__, ((int32){1}));
	int32 const line_start__ = Ints__0__0op__element(lines__->start_of_line__, line_index__);
	if (cond(int32__0op__equal(line_index__, int32__0op__sub(line_count__1(lines__), ((int32){1})))))
	{
		return Text_Line__0__0new__spanning__3(allocate(sizeof(Text_Line__0)), lines__->source__, line_start__, source_byte_length__1(lines__->source__));
	}

	int32 const line_end__ = Ints__0__0op__element(lines__->start_of_line__, int32__0op__add(line_index__, ((int32){1})));
	return Text_Line__0__0new__spanning__3(allocate(sizeof(Text_Line__0)), lines__->source__, line_start__, line_end__);
}

int32 line_containing_offset__2(Text_Lines__0 const *_Nonnull const lines__, int32 const character_offset__)
{
	assert__2(int32__0op__gte(character_offset__, ((int32){0})), string__0op__add(((string){7,(uint8_t const*)"offset "}), int_to_string__1(character_offset__)));
	assert__2(int32__0op__lte(character_offset__, source_byte_length__1(lines__->source__)), string__0op__add(string__0op__add(string__0op__add(((string){7,(uint8_t const*)"offset "}), int_to_string__1(character_offset__)), ((string){15,(uint8_t const*)" source length "})), int_to_string__1(source_byte_length__1(lines__->source__))));
	int32 left__ = ((int32){0});
	int32 right__ = int32__0op__sub(line_count__1(lines__), ((int32){1}));
	while (cond(int32__0op__lte(left__, right__)))
	{
		int32 const mid__ = int32__0op__add(left__, int32__0op__div(int32__0op__sub(right__, left__), ((int32){2})));
		int32 const mid_line_start__ = Ints__0__0op__element(lines__->start_of_line__, mid__);
		if (cond(int32__0op__lt(mid_line_start__, character_offset__)))
		{
			left__ = int32__0op__add(mid__, ((int32){1}));
		}
		else if (cond(int32__0op__gt(mid_line_start__, character_offset__)))
		{
			right__ = int32__0op__sub(mid__, ((int32){1}));
		}
		else
		{
			return int32__0op__add(mid__, ((int32){1}));
		}
	}

	return left__;
}

Text_Position__0 *_Nonnull Text_Position__0__0new__3(Text_Position__0 *_Nonnull self, int32 const character_offset__, int32 const line__, int32 const column__)
{
	self->character_offset__ = character_offset__;
	self->line__ = line__;
	self->column__ = column__;
	return self;
}

void unit_test_Text_Position__0()
{
	Text_Position_retains_given_offeset_line_and_column__0();
}

void Text_Position_retains_given_offeset_line_and_column__0()
{
	Text_Position__0 const *_Nonnull const position__ = Text_Position__0__0new__3(allocate(sizeof(Text_Position__0)), ((int32){23}), ((int32){2}), ((int32){5}));
	assert__1(int32__0op__equal(position__->character_offset__, ((int32){23})));
	assert__1(int32__0op__equal(position__->line__, ((int32){2})));
	assert__1(int32__0op__equal(position__->column__, ((int32){5})));
}

Text_Span__0 *_Nonnull Text_Span__0__0new__2(Text_Span__0 *_Nonnull self, int32 const start__, int32 const length__)
{
	self->start__ = start__;
	self->byte_length__ = length__;
	return self;
}

string format_error__1(string const message__)
{
	return string__0op__add(string__0op__add(((string){3,(uint8_t const*)"<$ "}), message__), ((string){3,(uint8_t const*)" $>"}));
}

Source_File_Builder__0 *_Nonnull Source_File_Builder__0__0new__0(Source_File_Builder__0 *_Nonnull self)
{
	self->code__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	self->indent__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	self->firstElement__ = TRUE;
	self->afterBlock__ = TRUE;
	return self;
}

void error__2(Source_File_Builder__0 *_Nonnull const file__, string const message__)
{
	file__->code__->Append__1(format_error__1(message__));
}

void begin_line__2(Source_File_Builder__0 *_Nonnull const file__, string const value__)
{
	file__->code__->Append__1(file__->indent__);
	file__->code__->Append__1(value__);
	file__->firstElement__ = file__->afterBlock__ = FALSE;
}

void write__2(Source_File_Builder__0 *_Nonnull const file__, string const value__)
{
	file__->code__->Append__1(value__);
	file__->firstElement__ = file__->afterBlock__ = FALSE;
}

void end_line__2(Source_File_Builder__0 *_Nonnull const file__, string const value__)
{
	file__->code__->Append__1(value__);
	file__->code__->AppendLine__0();
	file__->firstElement__ = file__->afterBlock__ = FALSE;
}

void write_line__2(Source_File_Builder__0 *_Nonnull const file__, string const value__)
{
	file__->code__->Append__1(file__->indent__);
	file__->code__->Append__1(value__);
	file__->code__->AppendLine__0();
	file__->firstElement__ = file__->afterBlock__ = FALSE;
}

void blank_line__1(Source_File_Builder__0 *_Nonnull const file__)
{
	file__->code__->AppendLine__0();
	file__->firstElement__ = TRUE;
	file__->afterBlock__ = FALSE;
}

void element_separator_line__1(Source_File_Builder__0 *_Nonnull const file__)
{
	if (cond(BOOL__0op__not(file__->firstElement__)))
	{
		file__->code__->AppendLine__0();
		file__->firstElement__ = TRUE;
		file__->afterBlock__ = FALSE;
	}
}

void statement_separator_line__1(Source_File_Builder__0 *_Nonnull const file__)
{
	if (cond(file__->afterBlock__))
	{
		file__->code__->AppendLine__0();
		file__->firstElement__ = TRUE;
		file__->afterBlock__ = FALSE;
	}
}

void begin_block__1(Source_File_Builder__0 *_Nonnull const file__)
{
	write_line__2(file__, ((string){1,(uint8_t const*)"{"}));
	file__->indent__->Append__1(((string){1,(uint8_t const*)"\t"}));
	file__->firstElement__ = file__->afterBlock__ = FALSE;
}

void end_block__1(Source_File_Builder__0 *_Nonnull const file__)
{
	file__->indent__->Remove__2(((int32){0}), ((int32){1}));
	write_line__2(file__, ((string){1,(uint8_t const*)"}"}));
	file__->afterBlock__ = TRUE;
}

void end_block_with_semicolon__1(Source_File_Builder__0 *_Nonnull const file__)
{
	file__->indent__->Remove__2(((int32){0}), ((int32){1}));
	write_line__2(file__, ((string){2,(uint8_t const*)"};"}));
}

int32 byte_length__1(Source_File_Builder__0 const *_Nonnull const file__)
{
	return file__->code__->byte_length__0();
}

string to_string__1(Source_File_Builder__0 *_Nonnull const file__)
{
	return file__->code__->ToString__0();
}

Compilation_Unit__0 *_Nonnull Compilation_Unit__0__0new__2(Compilation_Unit__0 *_Nonnull self, Syntax_Node__0 const *_Nonnull const syntax__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__)
{
	self->syntax__ = syntax__;
	self->declarations__ = declarations__;
	return self;
}

void collect_diagnostics__2(Compilation_Unit__0 const *_Nonnull const compilation_unit__, system__collections__List__1<Diagnostic__0 const *_Nonnull> *_Nonnull const diagnostics__)
{
	collect_syntax_diagnostics__2(compilation_unit__->syntax__, diagnostics__);
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(compilation_unit__->declarations__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const declaration__ = void_ptr__0current(&iter);
		collect_diagnostics__2(declaration__, diagnostics__);
	}
}

Package__0 *_Nonnull Package__0__0new__4(Package__0 *_Nonnull self, Package_Name__0 const *_Nonnull const name__, system__collections__List__1<Package_Reference__0 const *_Nonnull> const *_Nonnull const references__, system__collections__List__1<Compilation_Unit__0 const *_Nonnull> const *_Nonnull const compilation_units__, Symbol__0 const *_Nonnull const symbol__)
{
	self->name__ = name__;
	self->references__ = references__;
	self->compilation_units__ = compilation_units__;
	self->symbol__ = symbol__;
	return self;
}

system__collections__List__1<Diagnostic__0 const *_Nonnull> const *_Nonnull all_diagnostics__1(Package__0 const *_Nonnull const package__)
{
	system__collections__List__1<Diagnostic__0 const *_Nonnull> *_Nonnull diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(package__->compilation_units__); void_ptr__0next(&iter);)
	{
		Compilation_Unit__0 const *_Nonnull const compilation_unit__ = void_ptr__0current(&iter);
		collect_diagnostics__2(compilation_unit__, diagnostics__);
	}

	return diagnostics__;
}

Package_Reference__0 *_Nonnull Package_Reference__0__0new__1(Package_Reference__0 *_Nonnull self, Package__0 const *_Nonnull const package__)
{
	self->name__ = package__->name__->unqualified__;
	self->package__ = package__;
	return self;
}

Package_Reference__0 *_Nonnull Package_Reference__0__0new__2(Package_Reference__0 *_Nonnull self, string const name__, Package__0 const *_Nonnull const package__)
{
	self->name__ = name__;
	self->package__ = package__;
	return self;
}

Package__0 const *_Nonnull build_primitives_package__0()
{
	Package_Name__0 const *_Nonnull const name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){11,(uint8_t const*)"$primitives"}));
	system__collections__List__1<Package_Reference__0 const *_Nonnull> const *_Nonnull const references__ = system__collections__List__1__0new__0<Package_Reference__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Package_Reference__0 const *_Nonnull>)));
	system__collections__List__1<Compilation_Unit__0 const *_Nonnull> const *_Nonnull const compilation_units__ = system__collections__List__1__0new__0<Compilation_Unit__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Compilation_Unit__0 const *_Nonnull>)));
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const primitive_symbols__ = build_primitive_symbols__1(name__);
	assert__2(int32__0op__gt(primitive_symbols__->count__, ((int32){0})), string__0op__add(((string){24,(uint8_t const*)"primitive_symbols.count="}), int_to_string__1(primitive_symbols__->count__)));
	Symbol__0 const *_Nonnull const package_symbol__ = Symbol__0__0new__package__2(allocate(sizeof(Symbol__0)), name__->unqualified__, primitive_symbols__);
	assert__2(int32__0op__gt(package_symbol__->children__->count__, ((int32){0})), string__0op__add(((string){30,(uint8_t const*)"package_symbol.children.count="}), int_to_string__1(package_symbol__->children__->count__)));
	return Package__0__0new__4(allocate(sizeof(Package__0)), name__, references__, compilation_units__, package_symbol__);
}

system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull build_primitive_symbols__1(Package_Name__0 const *_Nonnull const package_name__)
{
	Name__0 const *_Nonnull const global_namespace__ = Name__0__0new__global_namespace__1(allocate(sizeof(Name__0)), package_name__);
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const symbols__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	symbols__->add__1(build_adamant_language_namespace_symbol__1(global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){4,(uint8_t const*)"void"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){5,(uint8_t const*)"never"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){4,(uint8_t const*)"bool"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){10,(uint8_t const*)"code_point"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){6,(uint8_t const*)"string"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){4,(uint8_t const*)"int8"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){5,(uint8_t const*)"int16"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){3,(uint8_t const*)"int"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){5,(uint8_t const*)"int64"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){6,(uint8_t const*)"int128"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){4,(uint8_t const*)"byte"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){6,(uint8_t const*)"uint16"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){4,(uint8_t const*)"uint"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){6,(uint8_t const*)"uint64"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){7,(uint8_t const*)"uint128"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){7,(uint8_t const*)"float32"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){5,(uint8_t const*)"float"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){8,(uint8_t const*)"float128"}), global_namespace__));
	build_fixed_point_primitives__3(symbols__, ((int32){8}), global_namespace__);
	build_fixed_point_primitives__3(symbols__, ((int32){16}), global_namespace__);
	build_fixed_point_primitives__3(symbols__, ((int32){32}), global_namespace__);
	build_fixed_point_primitives__3(symbols__, ((int32){64}), global_namespace__);
	symbols__->add__1(build_primitive_symbol__2(((string){9,(uint8_t const*)"decimal32"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){7,(uint8_t const*)"decimal"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){10,(uint8_t const*)"decimal128"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){4,(uint8_t const*)"size"}), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(((string){6,(uint8_t const*)"offset"}), global_namespace__));
	return symbols__;
}

Symbol__0 const *_Nonnull build_adamant_language_namespace_symbol__1(Name__0 const *_Nonnull const global_namespace__)
{
	Name__0 const *_Nonnull const adamant_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, NamespaceName__, ((string){7,(uint8_t const*)"adamant"}));
	Name__0 const *_Nonnull const language_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), adamant_namespace__, NamespaceName__, ((string){8,(uint8_t const*)"language"}));
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const language_children__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	language_children__->add__1(build_optional_type_symbol__1(language_namespace__));
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const adamant_children__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	adamant_children__->add__1(Symbol__0__0new__identifier__2(allocate(sizeof(Symbol__0)), unqualified_name__1(language_namespace__), language_children__));
	return Symbol__0__0new__identifier__2(allocate(sizeof(Symbol__0)), unqualified_name__1(adamant_namespace__), adamant_children__);
}

Symbol__0 const *_Nonnull build_optional_type_symbol__1(Name__0 const *_Nonnull const language_namespace__)
{
	Name__0 const *_Nonnull const optional_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), language_namespace__, TypeName__, ((string){8,(uint8_t const*)"optional"}));
	system__collections__List__1<Type__0 const *_Nonnull> *_Nonnull const type_parameters__ = system__collections__List__1__0new__0<Type__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Type__0 const *_Nonnull>)));
	type_parameters__->add__1(Type__0__0new__3(allocate(sizeof(Type__0)), TypeParameterType__, Name__0__0new__3(allocate(sizeof(Name__0)), optional_name__, TypeParameterName__, ((string){1,(uint8_t const*)"T"})), TRUE));
	Type__0 const *_Nonnull const type__ = Type__0__0new__primitive__2(allocate(sizeof(Type__0)), optional_name__, type_parameters__);
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const declarations__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	return Symbol__0__0new__declaring__3(allocate(sizeof(Symbol__0)), type__, declarations__, children__);
}

Symbol__0 const *_Nonnull build_primitive_symbol__2(string const name__, Name__0 const *_Nonnull const namespace__)
{
	Type__0 const *_Nonnull const type__ = Type__0__0new__primitive__1(allocate(sizeof(Type__0)), Name__0__0new__special__3(allocate(sizeof(Name__0)), namespace__, TypeName__, name__));
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const declarations__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	return Symbol__0__0new__declaring__3(allocate(sizeof(Symbol__0)), type__, declarations__, children__);
}

void build_fixed_point_primitives__3(system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const symbols__, int32 const bits__, Name__0 const *_Nonnull const namespace__)
{
}

void unit_test_build_primitives_package__0()
{
	Package_name_is_dollar_primitives__0();
	Package_has_no_references_or_compilation_units__0();
	Package_symbol_has_package_name__0();
	Package_symbol_has_children__0();
	Package_contains_the_string_type__0();
	Package_contains_optional_type__0();
}

void Package_name_is_dollar_primitives__0()
{
	Package__0 const *_Nonnull const package__ = build_primitives_package__0();
	Package_Name__0 const *_Nonnull const name__ = package__->name__;
	assert__1(string__0op__equal(name__->unqualified__, ((string){11,(uint8_t const*)"$primitives"})));
}

void Package_has_no_references_or_compilation_units__0()
{
	Package__0 const *_Nonnull const package__ = build_primitives_package__0();
	assert__1(int32__0op__equal(package__->references__->count__, ((int32){0})));
	assert__1(int32__0op__equal(package__->compilation_units__->count__, ((int32){0})));
}

void Package_symbol_has_package_name__0()
{
	Package__0 const *_Nonnull const package__ = build_primitives_package__0();
	Symbol__0 const *_Nonnull const symbol__ = package__->symbol__;
	assert__1(int32__0op__equal(symbol__->kind__, PackageSymbol__));
	string const symbol_name__ = symbol__->name__;
	assert__1(string__0op__equal(symbol_name__, package__->name__->unqualified__));
}

void Package_symbol_has_children__0()
{
	Package__0 const *_Nonnull const package__ = build_primitives_package__0();
	assert__1(int32__0op__gt(package__->symbol__->children__->count__, ((int32){0})));
}

void Package_contains_the_string_type__0()
{
	Package__0 const *_Nonnull const package__ = build_primitives_package__0();
	Symbol__0 const *_Nonnull const string_symbol__ = get_child__3(package__->symbol__, ((string){6,(uint8_t const*)"string"}), IdentifierSymbol__);
	assert__1(void_ptr__0op__not_equal(string_symbol__, none));
}

void Package_contains_optional_type__0()
{
	Package__0 const *_Nonnull const package__ = build_primitives_package__0();
	Symbol__0 const *_Nullable const adamant_symbol__ = get_child__3(package__->symbol__, ((string){7,(uint8_t const*)"adamant"}), IdentifierSymbol__);
	assert__1(void_ptr__0op__not_equal(adamant_symbol__, none));
	Symbol__0 const *_Nullable const langauge_symbol__ = get_child__3(adamant_symbol__, ((string){8,(uint8_t const*)"language"}), IdentifierSymbol__);
	assert__1(void_ptr__0op__not_equal(langauge_symbol__, none));
	Symbol__0 const *_Nullable const optional_symbol__ = get_child__3(langauge_symbol__, ((string){8,(uint8_t const*)"optional"}), IdentifierSymbol__);
	assert__1(void_ptr__0op__not_equal(optional_symbol__, none));
}

Package__0 const *_Nonnull build_runtime_library_package__0()
{
	Package_Name__0 const *_Nonnull const name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){8,(uint8_t const*)"$runtime"}));
	system__collections__List__1<Package_Reference__0 const *_Nonnull> const *_Nonnull const references__ = system__collections__List__1__0new__0<Package_Reference__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Package_Reference__0 const *_Nonnull>)));
	system__collections__List__1<Compilation_Unit__0 const *_Nonnull> const *_Nonnull const compilation_units__ = system__collections__List__1__0new__0<Compilation_Unit__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Compilation_Unit__0 const *_Nonnull>)));
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const symbols__ = build_runtime_library_symbols__1(name__);
	assert__2(int32__0op__gt(symbols__->count__, ((int32){0})), string__0op__add(((string){14,(uint8_t const*)"symbols.count="}), int_to_string__1(symbols__->count__)));
	Symbol__0 const *_Nonnull const package_symbol__ = Symbol__0__0new__package__2(allocate(sizeof(Symbol__0)), name__->unqualified__, symbols__);
	assert__2(int32__0op__gt(package_symbol__->children__->count__, ((int32){0})), string__0op__add(((string){30,(uint8_t const*)"package_symbol.children.count="}), int_to_string__1(package_symbol__->children__->count__)));
	return Package__0__0new__4(allocate(sizeof(Package__0)), name__, references__, compilation_units__, package_symbol__);
}

system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull build_runtime_library_symbols__1(Package_Name__0 const *_Nonnull const package_name__)
{
	Name__0 const *_Nonnull const global_namespace__ = Name__0__0new__global_namespace__1(allocate(sizeof(Name__0)), package_name__);
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const symbols__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){8,(uint8_t const*)"allocate"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){4,(uint8_t const*)"free"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){14,(uint8_t const*)"bool_to_string"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){13,(uint8_t const*)"int_to_string"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){17,(uint8_t const*)"int_to_hex_string"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){17,(uint8_t const*)"hex_string_to_int"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){17,(uint8_t const*)"int_to_code_point"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){20,(uint8_t const*)"code_point_to_string"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){18,(uint8_t const*)"string_byte_length"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){9,(uint8_t const*)"substring"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){14,(uint8_t const*)"string_replace"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){15,(uint8_t const*)"string_index_of"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){20,(uint8_t const*)"string_last_index_of"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){17,(uint8_t const*)"code_point_as_int"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){15,(uint8_t const*)"NOT_IMPLEMENTED"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){11,(uint8_t const*)"UNREACHABLE"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){6,(uint8_t const*)"assert"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){11,(uint8_t const*)"debug_write"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){16,(uint8_t const*)"debug_write_line"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){12,(uint8_t const*)"get_resource"}))));
	symbols__->add__1(build_class_symbol__2(global_namespace__, ((string){7,(uint8_t const*)"Strings"})));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){13,(uint8_t const*)"clear_strings"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){10,(uint8_t const*)"add_string"}))));
	symbols__->add__1(build_class_symbol__2(global_namespace__, ((string){4,(uint8_t const*)"Ints"})));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){10,(uint8_t const*)"clear_ints"}))));
	symbols__->add__1(build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){7,(uint8_t const*)"add_int"}))));
	Name__0 const *_Nonnull const system_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, NamespaceName__, ((string){6,(uint8_t const*)"system"}));
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const system_symbols__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	Name__0 const *_Nonnull const collections_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), system_namespace__, NamespaceName__, ((string){11,(uint8_t const*)"collections"}));
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const collections_symbols__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	system__collections__List__1<Type__0 const *_Nonnull> *_Nonnull const list_type_parameters__ = system__collections__List__1__0new__0<Type__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Type__0 const *_Nonnull>)));
	list_type_parameters__->add__1(Type__0__0new__parameter__1(allocate(sizeof(Type__0)), ((string){1,(uint8_t const*)"T"})));
	collections_symbols__->add__1(build_generic_class_symbol__3(collections_namespace__, ((string){4,(uint8_t const*)"List"}), list_type_parameters__));
	system_symbols__->add__1(build_namespace_symbol__2(collections_namespace__, collections_symbols__));
	Name__0 const *_Nonnull const console_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), system_namespace__, NamespaceName__, ((string){7,(uint8_t const*)"console"}));
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const console_symbols__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	console_symbols__->add__1(build_class_symbol__2(console_namespace__, ((string){7,(uint8_t const*)"Console"})));
	console_symbols__->add__1(build_class_symbol__2(console_namespace__, ((string){9,(uint8_t const*)"Arguments"})));
	system_symbols__->add__1(build_namespace_symbol__2(console_namespace__, console_symbols__));
	Name__0 const *_Nonnull const io_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), system_namespace__, NamespaceName__, ((string){2,(uint8_t const*)"io"}));
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const io_symbols__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	io_symbols__->add__1(build_class_symbol__2(io_namespace__, ((string){11,(uint8_t const*)"File_Reader"})));
	io_symbols__->add__1(build_class_symbol__2(io_namespace__, ((string){11,(uint8_t const*)"File_Writer"})));
	system_symbols__->add__1(build_namespace_symbol__2(io_namespace__, io_symbols__));
	Name__0 const *_Nonnull const text_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), system_namespace__, NamespaceName__, ((string){4,(uint8_t const*)"text"}));
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const text_symbols__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const string_builder_symbols__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	string_builder_symbols__->add__1(build_constructor_symbol__1(((string){13,(uint8_t const*)"with_capacity"})));
	text_symbols__->add__1(build_class_symbol__3(text_namespace__, ((string){14,(uint8_t const*)"String_Builder"}), string_builder_symbols__));
	system_symbols__->add__1(build_namespace_symbol__2(text_namespace__, text_symbols__));
	symbols__->add__1(build_namespace_symbol__2(system_namespace__, system_symbols__));
	return symbols__;
}

Symbol__0 const *_Nonnull build_function_symbol__1(Name__0 const *_Nonnull const name__)
{
	Type__0 const *_Nonnull const type__ = Type__0__0new__3(allocate(sizeof(Type__0)), FunctionType__, name__, FALSE);
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const children__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	return Symbol__0__0new__of_type__4(allocate(sizeof(Symbol__0)), unqualified_name__1(name__), type__, declarations__, children__);
}

Symbol__0 const *_Nonnull build_namespace_symbol__2(Name__0 const *_Nonnull const name__, system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const symbols__)
{
	Type__0 const *_Nonnull const type__ = Type__0__0new__namespace__1(allocate(sizeof(Type__0)), name__);
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	return Symbol__0__0new__declaring__3(allocate(sizeof(Symbol__0)), type__, declarations__, symbols__);
}

Symbol__0 const *_Nonnull build_class_symbol__2(Name__0 const *_Nonnull const namespace__, string const class_name__)
{
	Type__0 const *_Nonnull const type__ = Type__0__0new__3(allocate(sizeof(Type__0)), ReferenceType__, Name__0__0new__3(allocate(sizeof(Name__0)), namespace__, TypeName__, class_name__), TRUE);
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const children__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	return Symbol__0__0new__declaring__3(allocate(sizeof(Symbol__0)), type__, declarations__, children__);
}

Symbol__0 const *_Nonnull build_class_symbol__3(Name__0 const *_Nonnull const namespace__, string const class_name__, system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const children__)
{
	Type__0 const *_Nonnull const type__ = Type__0__0new__3(allocate(sizeof(Type__0)), ReferenceType__, Name__0__0new__3(allocate(sizeof(Name__0)), namespace__, TypeName__, class_name__), TRUE);
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	return Symbol__0__0new__declaring__3(allocate(sizeof(Symbol__0)), type__, declarations__, children__);
}

Symbol__0 const *_Nonnull build_generic_class_symbol__3(Name__0 const *_Nonnull const namespace__, string const class_name__, system__collections__List__1<Type__0 const *_Nonnull> const *_Nonnull const type_parameters__)
{
	Type__0 const *_Nonnull const type__ = Type__0__0new__4(allocate(sizeof(Type__0)), ReferenceType__, Name__0__0new__3(allocate(sizeof(Name__0)), namespace__, TypeName__, class_name__), type_parameters__, TRUE);
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const children__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	return Symbol__0__0new__declaring__3(allocate(sizeof(Symbol__0)), type__, declarations__, children__);
}

Symbol__0 const *_Nonnull build_constructor_symbol__1(string const name__)
{
	string const constructor_name__ = string__0op__add(((string){4,(uint8_t const*)"new_"}), name__);
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	return Symbol__0__0new__constructor__2(allocate(sizeof(Symbol__0)), constructor_name__, declarations__);
}

void unit_test_build_runtime_library_package__0()
{
	Runtime_Library_Package_contains_system_package__0();
	System_namespace_contains_console_namespace__0();
	Console_namespace_contains_Console_class__0();
	System_namespace_contains_collections_namespace__0();
	Collections_namespace_contains_List_class__0();
}

void Runtime_Library_Package_contains_system_package__0()
{
	Package__0 const *_Nonnull const package__ = build_runtime_library_package__0();
	assert__1(never__0op__not_equal(get_child__3(package__->symbol__, ((string){6,(uint8_t const*)"system"}), IdentifierSymbol__), none));
}

void System_namespace_contains_console_namespace__0()
{
	Package__0 const *_Nonnull const package__ = build_runtime_library_package__0();
	Symbol__0 const *_Nonnull const system_namespace__ = get_child__3(package__->symbol__, ((string){6,(uint8_t const*)"system"}), IdentifierSymbol__);
	assert__1(never__0op__not_equal(get_child__3(system_namespace__, ((string){7,(uint8_t const*)"console"}), IdentifierSymbol__), none));
}

void Console_namespace_contains_Console_class__0()
{
	Package__0 const *_Nonnull const package__ = build_runtime_library_package__0();
	Symbol__0 const *_Nonnull const system_namespace__ = get_child__3(package__->symbol__, ((string){6,(uint8_t const*)"system"}), IdentifierSymbol__);
	Symbol__0 const *_Nonnull const console_namespace__ = get_child__3(system_namespace__, ((string){7,(uint8_t const*)"console"}), IdentifierSymbol__);
	assert__1(never__0op__not_equal(get_child__3(console_namespace__, ((string){7,(uint8_t const*)"Console"}), IdentifierSymbol__), none));
}

void System_namespace_contains_collections_namespace__0()
{
	Package__0 const *_Nonnull const package__ = build_runtime_library_package__0();
	Symbol__0 const *_Nonnull const system_namespace__ = get_child__3(package__->symbol__, ((string){6,(uint8_t const*)"system"}), IdentifierSymbol__);
	assert__1(never__0op__not_equal(get_child__3(system_namespace__, ((string){11,(uint8_t const*)"collections"}), IdentifierSymbol__), none));
}

void Collections_namespace_contains_List_class__0()
{
	Package__0 const *_Nonnull const package__ = build_runtime_library_package__0();
	Symbol__0 const *_Nonnull const system_namespace__ = get_child__3(package__->symbol__, ((string){6,(uint8_t const*)"system"}), IdentifierSymbol__);
	Symbol__0 const *_Nonnull const console_namespace__ = get_child__3(system_namespace__, ((string){11,(uint8_t const*)"collections"}), IdentifierSymbol__);
	assert__1(never__0op__not_equal(get_child__3(console_namespace__, ((string){4,(uint8_t const*)"List"}), IdentifierSymbol__), none));
}

Package__0 const *_Nonnull analyze_semantics__1(Syntax_Node__0 const *_Nonnull const package_syntax__)
{
	assert__2(int32__0op__equal(package_syntax__->kind__, PackageNode__), string__0op__add(((string){20,(uint8_t const*)"package_syntax.kind="}), int_to_string__1(package_syntax__->kind__)));
	Package_Name__0 const *_Nonnull const name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){7,(uint8_t const*)"default"}));
	Package__0 const *_Nonnull const primitives_package__ = build_primitives_package__0();
	Package__0 const *_Nonnull const runtime_package__ = build_runtime_library_package__0();
	system__collections__List__1<Package_Reference__0 const *_Nonnull> *_Nonnull const references__ = system__collections__List__1__0new__0<Package_Reference__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Package_Reference__0 const *_Nonnull>)));
	references__->add__1(Package_Reference__0__0new__1(allocate(sizeof(Package_Reference__0)), primitives_package__));
	references__->add__1(Package_Reference__0__0new__1(allocate(sizeof(Package_Reference__0)), runtime_package__));
	Name_Table__0 const *_Nonnull const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Semantic_Tree_Builder__0 const *_Nonnull const semantic_tree_builder__ = Semantic_Tree_Builder__0__0new__0(allocate(sizeof(Semantic_Tree_Builder__0)));
	system__collections__List__1<Compilation_Unit__0 const *_Nonnull> const *_Nonnull const compilation_units__ = build_compilation_units__3(semantic_tree_builder__, package_syntax__, name_table__);
	Symbol__0 const *_Nonnull const package_symbol__ = build_symbols__2(name__, compilation_units__);
	Package__0 const *_Nonnull const package__ = Package__0__0new__4(allocate(sizeof(Package__0)), name__, references__, compilation_units__, package_symbol__);
	return package__;
}

Semantic_Node__0 *_Nonnull Semantic_Node__0__0new__token__1(Semantic_Node__0 *_Nonnull self, Syntax_Node__0 const *_Nonnull const syntax__)
{
	assert__1(void_ptr__0op__not_equal(syntax__, none));
	self->syntax__ = syntax__;
	self->kind__ = syntax__->kind__;
	self->is_missing__ = syntax__->is_missing__;
	self->source__ = syntax__->source__;
	self->start__ = syntax__->start__;
	self->byte_length__ = syntax__->byte_length__;
	self->children__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	self->node_diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	self->of_type__ = none;
	self->converted_type__ = none;
	self->declares_type__ = none;
	self->referenced_type__ = none;
	return self;
}

Semantic_Node__0 *_Nonnull Semantic_Node__0__0new__concrete__2(Semantic_Node__0 *_Nonnull self, Syntax_Node__0 const *_Nonnull const syntax__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const children__)
{
	assert__1(void_ptr__0op__not_equal(syntax__, none));
	self->syntax__ = syntax__;
	self->kind__ = syntax__->kind__;
	self->is_missing__ = syntax__->is_missing__;
	self->source__ = syntax__->source__;
	self->start__ = syntax__->start__;
	self->byte_length__ = syntax__->byte_length__;
	self->children__ = children__;
	self->node_diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	self->of_type__ = none;
	self->converted_type__ = none;
	self->declares_type__ = none;
	self->referenced_type__ = none;
	return self;
}

Semantic_Node__0 *_Nonnull Semantic_Node__0__0new__of_type__3(Semantic_Node__0 *_Nonnull self, Type__0 const *_Nonnull const of_type__, Syntax_Node__0 const *_Nonnull const syntax__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const children__)
{
	assert__1(void_ptr__0op__not_equal(of_type__, none));
	assert__1(void_ptr__0op__not_equal(syntax__, none));
	self->syntax__ = syntax__;
	self->kind__ = syntax__->kind__;
	self->is_missing__ = syntax__->is_missing__;
	self->source__ = syntax__->source__;
	self->start__ = syntax__->start__;
	self->byte_length__ = syntax__->byte_length__;
	self->children__ = children__;
	self->node_diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	self->of_type__ = of_type__;
	self->converted_type__ = of_type__;
	self->declares_type__ = none;
	self->referenced_type__ = none;
	return self;
}

Semantic_Node__0 *_Nonnull Semantic_Node__0__0new__declares_type__3(Semantic_Node__0 *_Nonnull self, Type__0 const *_Nonnull const type__, Syntax_Node__0 const *_Nonnull const syntax__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const children__)
{
	assert__1(void_ptr__0op__not_equal(type__, none));
	assert__1(void_ptr__0op__not_equal(syntax__, none));
	self->syntax__ = syntax__;
	self->kind__ = syntax__->kind__;
	self->is_missing__ = syntax__->is_missing__;
	self->source__ = syntax__->source__;
	self->start__ = syntax__->start__;
	self->byte_length__ = syntax__->byte_length__;
	self->children__ = children__;
	self->node_diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	self->of_type__ = none;
	self->converted_type__ = none;
	self->declares_type__ = type__;
	self->referenced_type__ = none;
	return self;
}

Semantic_Node__0 *_Nonnull Semantic_Node__0__0new__referencing_type__3(Semantic_Node__0 *_Nonnull self, Type__0 const *_Nonnull const type__, Syntax_Node__0 const *_Nonnull const syntax__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const children__)
{
	assert__1(void_ptr__0op__not_equal(type__, none));
	assert__1(void_ptr__0op__not_equal(syntax__, none));
	self->syntax__ = syntax__;
	self->kind__ = syntax__->kind__;
	self->is_missing__ = syntax__->is_missing__;
	self->source__ = syntax__->source__;
	self->start__ = syntax__->start__;
	self->byte_length__ = syntax__->byte_length__;
	self->children__ = children__;
	self->node_diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	self->of_type__ = none;
	self->converted_type__ = none;
	self->declares_type__ = none;
	self->referenced_type__ = type__;
	return self;
}

Text_Span__0 const *_Nonnull get_text_span__1(Semantic_Node__0 const *_Nonnull const node__)
{
	return Text_Span__0__0new__2(allocate(sizeof(Text_Span__0)), node__->start__, node__->byte_length__);
}

string get_text__1(Semantic_Node__0 const *_Nonnull const node__)
{
	if (cond(void_ptr__0op__equal(node__->source__, none)))
	{
		return ((string){11,(uint8_t const*)"$No Source$"});
	}

	return substring__3(node__->source__->text__, node__->start__, node__->byte_length__);
}

Semantic_Node__0 const *_Nullable first_child__2(Semantic_Node__0 const *_Nonnull const node__, int32 const kind__)
{
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(int32__0op__equal(child__->kind__, kind__)))
		{
			return child__;
		}
	}

	return none;
}

system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull children_of_kind__2(Semantic_Node__0 const *_Nonnull const node__, int32 const kind__)
{
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(int32__0op__equal(child__->kind__, kind__)))
		{
			children__->add__1(child__);
		}
	}

	return children__;
}

system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull node_members__1(Semantic_Node__0 const *_Nonnull const node__)
{
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const members__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(child__->kind__, ConstructorDeclaration__)) || bool_arg(int32__0op__equal(child__->kind__, FieldDeclaration__)))) || bool_arg(int32__0op__equal(child__->kind__, MethodDeclaration__)))))
		{
			members__->add__1(child__);
		}
	}

	return members__;
}

system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull node_statements__1(Semantic_Node__0 const *_Nonnull const node__)
{
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const statements__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(int32__0op__not_equal(child__->kind__, LeftBrace__)) && bool_arg(int32__0op__not_equal(child__->kind__, RightBrace__)))))
		{
			statements__->add__1(child__);
		}
	}

	return statements__;
}

system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull node_parameters__1(Semantic_Node__0 const *_Nonnull const node__)
{
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const parameters__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(int32__0op__equal(child__->kind__, Parameter__)) || bool_arg(int32__0op__equal(child__->kind__, SelfParameter__)))))
		{
			parameters__->add__1(child__);
		}
	}

	return parameters__;
}

int32 node_argument_count__1(Semantic_Node__0 const *_Nonnull const node__)
{
	int32 count__ = ((int32){0});
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(child__->kind__, LeftParen__)) || bool_arg(int32__0op__equal(child__->kind__, RightParen__)))) || bool_arg(int32__0op__equal(child__->kind__, Comma__)))))
		{
			continue;
		}

		op__add_assign(&(count__), ((int32){1}));
	}

	return count__;
}

Semantic_Node__0 const *_Nullable node_access_modifier__1(Semantic_Node__0 const *_Nonnull const node__)
{
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(child__->kind__, PublicKeyword__)) || bool_arg(int32__0op__equal(child__->kind__, ProtectedKeyword__)))) || bool_arg(int32__0op__equal(child__->kind__, PrivateKeyword__)))) || bool_arg(int32__0op__equal(child__->kind__, InternalKeyword__)))))
		{
			return child__;
		}
	}

	return none;
}

BOOL node_has_child__2(Semantic_Node__0 const *_Nonnull const node__, int32 const kind__)
{
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(int32__0op__equal(child__->kind__, kind__)))
		{
			return TRUE;
		}
	}

	return FALSE;
}

void add_diagnostic__2(Semantic_Node__0 *_Nonnull const node__, Diagnostic__0 const *_Nonnull const diagnostic__)
{
	node__->node_diagnostics__->add__1(diagnostic__);
}

system__collections__List__1<Diagnostic__0 const *_Nonnull> const *_Nonnull diagnostics__1(Semantic_Node__0 const *_Nonnull const node__)
{
	return node__->node_diagnostics__;
}

void collect_diagnostics__2(Semantic_Node__0 const *_Nonnull const node__, system__collections__List__1<Diagnostic__0 const *_Nonnull> *_Nonnull const diagnostics__)
{
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(node__->node_diagnostics__); void_ptr__0next(&iter);)
	{
		Diagnostic__0 const *_Nonnull const diagnostic__ = void_ptr__0current(&iter);
		diagnostics__->add__1(diagnostic__);
	}

	for (void_ptr__0iter iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		collect_diagnostics__2(child__, diagnostics__);
	}
}

Semantic_Tree_Builder__0 *_Nonnull Semantic_Tree_Builder__0__0new__0(Semantic_Tree_Builder__0 *_Nonnull self)
{
	Package_Name__0 const *_Nonnull const primitives_package__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){11,(uint8_t const*)"$primitives"}));
	Name__0 const *_Nonnull const global_namespace__ = Name__0__0new__global_namespace__1(allocate(sizeof(Name__0)), primitives_package__);
	Name__0 const *_Nonnull const adamant_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, NamespaceName__, ((string){7,(uint8_t const*)"adamant"}));
	Name__0 const *_Nonnull const language_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), adamant_namespace__, NamespaceName__, ((string){8,(uint8_t const*)"language"}));
	self->optional_type_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), language_namespace__, TypeName__, ((string){8,(uint8_t const*)"optional"}));
	return self;
}

system__collections__List__1<Compilation_Unit__0 const *_Nonnull> const *_Nonnull build_compilation_units__3(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Syntax_Node__0 const *_Nonnull const package_syntax__, Name_Table__0 const *_Nonnull const name_table__)
{
	assert__2(int32__0op__equal(package_syntax__->kind__, PackageNode__), string__0op__add(((string){20,(uint8_t const*)"package_syntax.kind="}), int_to_string__1(package_syntax__->kind__)));
	assert__2(never__0op__not_equal(lookup_special__2(name_table__->any_package__, ((string){6,(uint8_t const*)"string"})), none), string__0op__add(((string){28,(uint8_t const*)"name_table.any_package.name="}), full_name__1(name_table__->any_package__->name__)));
	system__collections__List__1<Compilation_Unit__0 const *_Nonnull> *_Nonnull const compilation_units__ = system__collections__List__1__0new__0<Compilation_Unit__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Compilation_Unit__0 const *_Nonnull>)));
	for (void_ptr__0iter iter = void_ptr__0iterate(package_syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const *_Nonnull const compilation_unit_syntax__ = void_ptr__0current(&iter);
		compilation_units__->add__1(build_compilation_unit_semantic_node__3(builder__, compilation_unit_syntax__, name_table__));
	}

	return compilation_units__;
}

Compilation_Unit__0 const *_Nonnull build_compilation_unit_semantic_node__3(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Syntax_Node__0 const *_Nonnull const compilation_unit_syntax__, Name_Table__0 const *_Nonnull const name_table__)
{
	assert__2(int32__0op__equal(compilation_unit_syntax__->kind__, CompilationUnit__), string__0op__add(((string){29,(uint8_t const*)"compilation_unit_syntax.kind="}), int_to_string__1(compilation_unit_syntax__->kind__)));
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const declarations__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	for (void_ptr__0iter iter = void_ptr__0iterate(compilation_unit_syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const *_Nonnull const declaration_syntax__ = void_ptr__0current(&iter);
		declarations__->add__1(build_semantic_node__4(builder__, declaration_syntax__, name_table__, name_table__->any_package__));
	}

	return Compilation_Unit__0__0new__2(allocate(sizeof(Compilation_Unit__0)), compilation_unit_syntax__, declarations__);
}

Semantic_Node__0 const *_Nonnull build_semantic_node__4(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Syntax_Node__0 const *_Nonnull const syntax__, Name_Table__0 const *_Nonnull const name_table__, Name_Subtable__0 const *_Nonnull const scope__)
{
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	if (cond(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, FunctionDeclaration__)) || bool_arg(int32__0op__equal(syntax__->kind__, MethodDeclaration__)))))
	{
		children__->add__1(build_semantic_node__4(builder__, access_modifier__1(syntax__), name_table__, scope__));
		Syntax_Node__0 const *_Nonnull const function_name__ = first_child_syntax__2(syntax__, Identifier__);
		children__->add__1(build_semantic_node__4(builder__, function_name__, name_table__, scope__));
		Name_Subtable__0 *_Nonnull const function_scope__ = find__2(scope__, get_text__1(function_name__));
		assert__2(void_ptr__0op__not_equal(function_scope__, none), string__0op__add(((string){24,(uint8_t const*)"get_text(function_name)="}), get_text__1(function_name__)));
		Syntax_Node__0 const *_Nonnull const parameters__ = first_child_syntax__2(syntax__, ParameterList__);
		children__->add__1(build_parameters_semantic_node__4(builder__, parameters__, name_table__, function_scope__));
		Syntax_Node__0 const *_Nonnull const return_type__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){4}));
		children__->add__1(build_type_name_semantic_node__4(builder__, return_type__, name_table__, scope__));
		Type__0 const *_Nonnull const function_type__ = Type__0__0new__3(allocate(sizeof(Type__0)), FunctionType__, function_scope__->name__, FALSE);
		bind_type__2(function_scope__, function_type__);
		Syntax_Node__0 const *_Nonnull const body__ = first_child_syntax__2(syntax__, Block__);
		if (cond(void_ptr__0op__not_equal(body__, none)))
		{
			children__->add__1(build_semantic_node__4(builder__, body__, name_table__, function_scope__));
		}

		return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
	}
	else if (cond(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, ClassDeclaration__)) || bool_arg(int32__0op__equal(syntax__->kind__, StructDeclaration__)))))
	{
		Syntax_Node__0 const *_Nonnull const type_name__ = first_child_syntax__2(syntax__, Identifier__);
		children__->add__1(build_semantic_node__4(builder__, type_name__, name_table__, scope__));
		Name_Subtable__0 const *_Nonnull const type_scope__ = find__2(scope__, get_text__1(type_name__));
		assert__2(void_ptr__0op__not_equal(type_scope__, none), string__0op__add(((string){20,(uint8_t const*)"get_text(type_name)="}), get_text__1(type_name__)));
		for (void_ptr__0iter iter = void_ptr__0iterate(members__1(syntax__)); void_ptr__0next(&iter);)
		{
			Syntax_Node__0 const *_Nonnull const member__ = void_ptr__0current(&iter);
			children__->add__1(build_semantic_node__4(builder__, member__, name_table__, type_scope__));
		}

		return Semantic_Node__0__0new__declares_type__3(allocate(sizeof(Semantic_Node__0)), type_scope__->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ConstructorDeclaration__)))
	{
		children__->add__1(build_semantic_node__4(builder__, access_modifier__1(syntax__), name_table__, scope__));
		string full_name__ = ((string){3,(uint8_t const*)"new"});
		Syntax_Node__0 const *_Nullable const constructor_name__ = first_child_syntax__2(syntax__, Identifier__);
		if (cond(void_ptr__0op__not_equal(constructor_name__, none)))
		{
			full_name__ = string__0op__add(((string){4,(uint8_t const*)"new_"}), get_text__1(constructor_name__));
			children__->add__1(Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), constructor_name__));
		}

		Name_Subtable__0 const *_Nonnull const constructor_scope__ = find_special__2(scope__, full_name__);
		assert__2(void_ptr__0op__not_equal(constructor_scope__, none), string__0op__add(((string){10,(uint8_t const*)"full_name="}), full_name__));
		Syntax_Node__0 const *_Nonnull const parameters__ = first_child_syntax__2(syntax__, ParameterList__);
		children__->add__1(build_parameters_semantic_node__4(builder__, parameters__, name_table__, constructor_scope__));
		Syntax_Node__0 const *_Nonnull const body__ = first_child_syntax__2(syntax__, Block__);
		if (cond(void_ptr__0op__not_equal(body__, none)))
		{
			children__->add__1(build_semantic_node__4(builder__, body__, name_table__, constructor_scope__));
		}

		return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, IdentifierName__)))
	{
		Name_Subtable__0 const *_Nonnull const name_scope__ = lookup__2(scope__, get_text__1(syntax__));
		if (cond(void_ptr__0op__equal(name_scope__, none)))
		{
			Semantic_Node__0 *_Nonnull const node__ = Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), syntax__);
			if (cond(BOOL__0op__not(syntax__->is_missing__)))
			{
				add_resolution_error__1(node__);
			}

			return node__;
		}
		else
		{
			if (cond(never__0op__equal(name_scope__->type__, none)))
			{
				return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
			}
			else
			{
				return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), name_scope__->type__, syntax__, children__);
			}
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, MemberAccessExpression__)))
	{
		Semantic_Node__0 const *_Nonnull const lhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		children__->add__1(lhs__);
		Semantic_Node__0 *_Nonnull rhs__;
		Syntax_Node__0 const *_Nonnull const member_name__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){2}));
		if (cond(void_ptr__0op__equal(lhs__->of_type__, none)))
		{
			rhs__ = Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), member_name__);
		}
		else
		{
			Name_Subtable__0 const *_Nonnull const access_scope__ = get_name__2(name_table__, lhs__->of_type__->name__);
			Name_Subtable__0 const *_Nonnull const member_scope__ = find__2(access_scope__, get_text__1(member_name__));
			if (cond(void_ptr__0op__equal(member_scope__, none)))
			{
				rhs__ = Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), member_name__);
			}
			else
			{
				system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const no_children__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
				if (cond(never__0op__equal(member_scope__->type__, none)))
				{
					rhs__ = Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), member_name__);
				}
				else
				{
					rhs__ = Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), member_scope__->type__, member_name__, no_children__);
				}
			}
		}

		children__->add__1(rhs__);
		if (cond(void_ptr__0op__equal(rhs__->of_type__, none)))
		{
			return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
		}
		else
		{
			return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), rhs__->of_type__, syntax__, children__);
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NewExpression__)))
	{
		children__->add__1(build_constructor_name_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), name_table__, scope__));
		children__->add__1(build_semantic_node__4(builder__, first_child_syntax__2(syntax__, ArgumentList__), name_table__, scope__));
		return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, LocalDeclarationStatement__)))
	{
		Syntax_Node__0 const *_Nonnull const variable_declaration_syntax__ = first_child_syntax__2(syntax__, VariableDeclaration__);
		children__->add__1(build_semantic_node__4(builder__, variable_declaration_syntax__, name_table__, scope__));
		return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, VariableDeclaration__)))
	{
		Syntax_Node__0 const *_Nonnull const binding_syntax__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		children__->add__1(Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), binding_syntax__));
		Syntax_Node__0 const *_Nonnull const identifier__ = first_child_syntax__2(syntax__, Identifier__);
		children__->add__1(Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), identifier__));
		Syntax_Node__0 const *_Nonnull const type_syntax__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){3}));
		Semantic_Node__0 const *_Nonnull const type_node__ = build_type_name_semantic_node__4(builder__, type_syntax__, name_table__, scope__);
		assert__2(void_ptr__0op__not_equal(type_node__->referenced_type__, none), get_text__1(type_node__));
		Name_Subtable__0 *_Nonnull const variable_scope__ = lookup__2(scope__, get_text__1(identifier__));
		assert__2(void_ptr__0op__not_equal(variable_scope__, none), get_text__1(syntax__));
		bind_type__2(variable_scope__, type_node__->referenced_type__);
		bind_type__2(as_mut__1(get_name__2(name_table__, variable_scope__->name__)), type_node__->referenced_type__);
		children__->add__1(type_node__);
		if (cond(int32__0op__equal(syntax__->children__->count__, ((int32){6}))))
		{
			Syntax_Node__0 const *_Nonnull const initalizer__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){5}));
			children__->add__1(build_semantic_node__4(builder__, initalizer__, name_table__, scope__));
		}

		return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
	}
	else if (cond(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, TrueLiteralExpression__)) || bool_arg(int32__0op__equal(syntax__->kind__, FalseLiteralExpression__)))))
	{
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){4,(uint8_t const*)"bool"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, StringLiteralExpression__)))
	{
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){6,(uint8_t const*)"string"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, CodePointLiteralExpression__)))
	{
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){10,(uint8_t const*)"code_point"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NumericLiteralExpression__)))
	{
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){3,(uint8_t const*)"int"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NoneLiteralExpression__)))
	{
		Type__0 const *_Nonnull const type__ = build_optional_type__3(builder__, name_table__, lookup_special__2(scope__, ((string){5,(uint8_t const*)"never"}))->type__);
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, SelfExpression__)))
	{
		children__->add__1(Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), first_child_syntax__2(syntax__, SelfKeyword__)));
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){4,(uint8_t const*)"self"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NegateExpression__)))
	{
		children__->add__1(build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), name_table__, scope__));
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){3,(uint8_t const*)"int"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, MagnitudeExpression__)))
	{
		children__->add__1(build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), name_table__, scope__));
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){3,(uint8_t const*)"int"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, AddExpression__)))
	{
		Semantic_Node__0 const *_Nonnull const lhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		Semantic_Node__0 const *_Nonnull const rhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), name_table__, scope__);
		children__->add__1(lhs__);
		children__->add__1(rhs__);
		Type__0 const *_Nonnull type__ = lhs__->of_type__;
		if (cond(void_ptr__0op__equal(type__, none)))
		{
			type__ = rhs__->of_type__;
		}

		if (cond(void_ptr__0op__equal(type__, none)))
		{
			type__ = lookup_special__2(scope__, ((string){3,(uint8_t const*)"int"}))->type__;
		}

		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, SubtractExpression__)))
	{
		children__->add__1(build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__));
		children__->add__1(build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), name_table__, scope__));
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){3,(uint8_t const*)"int"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->children__->count__, ((int32){0}))))
	{
		return Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), syntax__);
	}
	else
	{
		for (void_ptr__0iter iter = void_ptr__0iterate(syntax__->children__); void_ptr__0next(&iter);)
		{
			Syntax_Node__0 const *_Nonnull const child_syntax__ = void_ptr__0current(&iter);
			children__->add__1(build_semantic_node__4(builder__, child_syntax__, name_table__, scope__));
		}

		return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
	}
}

Semantic_Node__0 *_Nonnull build_parameters_semantic_node__4(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Syntax_Node__0 const *_Nonnull const parameters_syntax__, Name_Table__0 const *_Nonnull const name_table__, Name_Subtable__0 const *_Nonnull const scope__)
{
	assert__2(int32__0op__equal(parameters_syntax__->kind__, ParameterList__), string__0op__add(((string){23,(uint8_t const*)"parameters_syntax.kind="}), int_to_string__1(parameters_syntax__->kind__)));
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const parameter_nodes__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	for (void_ptr__0iter iter = void_ptr__0iterate(parameters__1(parameters_syntax__)); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const *_Nonnull const parameter__ = void_ptr__0current(&iter);
		system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
		if (cond(int32__0op__equal(parameter__->kind__, Parameter__)))
		{
			Syntax_Node__0 const *_Nullable const var_syntax__ = first_child_syntax__2(parameter__, VarKeyword__);
			if (cond(void_ptr__0op__not_equal(var_syntax__, none)))
			{
				children__->add__1(Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), var_syntax__));
			}

			Syntax_Node__0 const *_Nonnull const identifier__ = first_child_syntax__2(parameter__, Identifier__);
			children__->add__1(Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), identifier__));
			Syntax_Node__0 const *_Nonnull const type_syntax__ = system__collections__List__1__0op__element(parameter__->children__, int32__0op__sub(parameter__->children__->count__, ((int32){1})));
			Semantic_Node__0 const *_Nonnull const type_node__ = build_type_name_semantic_node__4(builder__, type_syntax__, name_table__, scope__);
			assert__2(void_ptr__0op__not_equal(type_node__->referenced_type__, none), get_text__1(parameter__));
			children__->add__1(type_node__);
			Name_Subtable__0 *_Nonnull const parameter_scope__ = lookup__2(scope__, get_text__1(identifier__));
			assert__2(void_ptr__0op__not_equal(parameter_scope__, none), get_text__1(identifier__));
			bind_type__2(parameter_scope__, type_node__->referenced_type__);
			parameter_nodes__->add__1(Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), type_node__->referenced_type__, parameter__, children__));
		}
		else if (cond(int32__0op__equal(parameter__->kind__, SelfParameter__)))
		{
			for (void_ptr__0iter iter = void_ptr__0iterate(parameter__->children__); void_ptr__0next(&iter);)
			{
				Syntax_Node__0 const *_Nonnull const child_syntax__ = void_ptr__0current(&iter);
				children__->add__1(Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), child_syntax__));
			}

			parameter_nodes__->add__1(Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), parameter__, children__));
		}
		else
		{
			NOT_IMPLEMENTED__1(string__0op__add(((string){15,(uint8_t const*)"parameter.kind="}), int_to_string__1(parameter__->kind__)));
		}
	}

	return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), parameters_syntax__, parameter_nodes__);
}

Semantic_Node__0 *_Nonnull build_type_name_semantic_node__4(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Syntax_Node__0 const *_Nonnull const syntax__, Name_Table__0 const *_Nonnull const name_table__, Name_Subtable__0 const *_Nonnull const scope__)
{
	system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	if (cond(int32__0op__equal(syntax__->kind__, PredefinedType__)))
	{
		string const primitive_name__ = get_text__1(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})));
		Name_Subtable__0 const *_Nullable const primitive_entry__ = lookup_special__2(scope__, primitive_name__);
		assert__2(void_ptr__0op__not_equal(primitive_entry__, none), string__0op__add(string__0op__add(((string){24,(uint8_t const*)"No entry for primitive `"}), primitive_name__), ((string){1,(uint8_t const*)"`"})));
		return Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), primitive_entry__->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, IdentifierName__)))
	{
		if (cond(syntax__->is_missing__))
		{
			return Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), syntax__);
		}

		string const name__ = get_text__1(syntax__);
		Name_Subtable__0 const *_Nullable const entry__ = lookup__2(scope__, name__);
		if (cond(void_ptr__0op__equal(entry__, none)))
		{
			Semantic_Node__0 *_Nonnull const node__ = Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), syntax__);
			add_resolution_error__1(node__);
			return node__;
		}
		else
		{
			return Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), entry__->type__, syntax__, children__);
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, QualifiedName__)))
	{
		Syntax_Node__0 const *_Nonnull const qualifier_syntax__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		Semantic_Node__0 *_Nonnull const qualifier__ = build_type_name_semantic_node__4(builder__, qualifier_syntax__, name_table__, scope__);
		children__->add__1(qualifier__);
		Syntax_Node__0 const *_Nonnull const qualified_syntax__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){2}));
		if (cond(int32__0op__equal(qualified_syntax__->kind__, IdentifierName__)))
		{
			Syntax_Node__0 const *_Nonnull const name_syntax__ = qualified_syntax__;
			if (cond(void_ptr__0op__equal(qualifier__->referenced_type__, none)))
			{
				add_could_not_determine_type_error__1(qualifier__);
				Semantic_Node__0 *_Nonnull const name_node__ = Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), name_syntax__);
				add_resolution_error__2(name_node__, qualifier__);
				children__->add__1(name_node__);
				return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
			}
			else
			{
				Type__0 const *_Nonnull const containing_type__ = qualifier__->referenced_type__;
				Name_Subtable__0 const *_Nonnull const containing_scope__ = get_name__2(name_table__, containing_type__->name__);
				assert__2(void_ptr__0op__not_equal(containing_scope__, none), full_name__1(containing_type__->name__));
				Name_Subtable__0 const *_Nonnull const referenced_scope__ = find__2(containing_scope__, get_text__1(name_syntax__));
				if (cond(void_ptr__0op__equal(referenced_scope__, none)))
				{
					Semantic_Node__0 *_Nonnull const name_node__ = Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), name_syntax__);
					add_resolution_error__2(name_node__, qualifier__);
					children__->add__1(name_node__);
					return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
				}

				Type__0 const *_Nonnull const referenced_type__ = referenced_scope__->type__;
				Semantic_Node__0 const *_Nonnull const name_node__ = Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), referenced_type__, name_syntax__, system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>))));
				children__->add__1(name_node__);
				return Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), referenced_type__, syntax__, children__);
			}
		}
		else if (cond(int32__0op__equal(qualified_syntax__->kind__, GenericName__)))
		{
			Syntax_Node__0 const *_Nonnull const name_syntax__ = first_child_syntax__2(qualified_syntax__, IdentifierName__);
			system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const generic_name_children__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
			if (cond(void_ptr__0op__equal(qualifier__->referenced_type__, none)))
			{
				add_could_not_determine_type_error__1(qualifier__);
				Semantic_Node__0 *_Nonnull const name_node__ = Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), name_syntax__);
				add_resolution_error__2(name_node__, qualifier__);
				generic_name_children__->add__1(name_node__);
				build_type_arguments_semantic_node__5(builder__, qualified_syntax__, name_table__, scope__, generic_name_children__);
				Semantic_Node__0 *_Nonnull const qualified_name__ = Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), qualified_syntax__, generic_name_children__);
				children__->add__1(qualified_name__);
				return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
			}
			else
			{
				Type__0 const *_Nonnull const containing_type__ = qualifier__->referenced_type__;
				Name_Subtable__0 const *_Nonnull const containing_scope__ = get_name__2(name_table__, containing_type__->name__);
				assert__2(void_ptr__0op__not_equal(containing_scope__, none), full_name__1(containing_type__->name__));
				Name_Subtable__0 const *_Nonnull const referenced_scope__ = find__2(containing_scope__, get_text__1(name_syntax__));
				if (cond(void_ptr__0op__equal(referenced_scope__, none)))
				{
					Semantic_Node__0 *_Nonnull const name_node__ = Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), name_syntax__);
					add_resolution_error__2(name_node__, qualifier__);
					generic_name_children__->add__1(name_node__);
					build_type_arguments_semantic_node__5(builder__, qualified_syntax__, name_table__, scope__, generic_name_children__);
					Semantic_Node__0 *_Nonnull const qualified_name__ = Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), qualified_syntax__, generic_name_children__);
					children__->add__1(qualified_name__);
					return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
				}

				Type__0 const *_Nonnull const referenced_type_name__ = referenced_scope__->type__;
				Semantic_Node__0 const *_Nonnull const name_node__ = Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), referenced_type_name__, name_syntax__, system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>))));
				generic_name_children__->add__1(name_node__);
				system__collections__List__1<Type__0 const *_Nonnull> const *_Nonnull const type_parameters__ = build_type_arguments_semantic_node__5(builder__, qualified_syntax__, name_table__, scope__, generic_name_children__);
				Type__0 const *_Nonnull const referenced_type__ = Type__0__0new__generic__2(allocate(sizeof(Type__0)), referenced_type_name__, type_parameters__);
				Semantic_Node__0 *_Nonnull const qualified_name__ = Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), referenced_type__, qualified_syntax__, generic_name_children__);
				children__->add__1(qualified_name__);
				return Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), referenced_type__, syntax__, children__);
			}
		}
		else
		{
			UNREACHABLE__0();
		}

		UNREACHABLE__0();
	}
	else if (cond(int32__0op__equal(syntax__->kind__, MutableType__)))
	{
		Semantic_Node__0 *_Nonnull const inner_type__ = build_type_name_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), name_table__, scope__);
		children__->add__1(inner_type__);
		if (cond(void_ptr__0op__equal(inner_type__->referenced_type__, none)))
		{
			add_could_not_determine_type_error__1(inner_type__);
			return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
		}

		Type__0 const *_Nonnull const type__ = make_mutable_type__1(inner_type__->referenced_type__);
		return Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ImmutableType__)))
	{
		Semantic_Node__0 *_Nonnull const inner_type__ = build_type_name_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		children__->add__1(inner_type__);
		if (cond(void_ptr__0op__equal(inner_type__->referenced_type__, none)))
		{
			add_could_not_determine_type_error__1(inner_type__);
			return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
		}

		Type__0 const *_Nonnull const type__ = make_immutable_type__1(inner_type__->referenced_type__);
		return Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, OptionalType__)))
	{
		Semantic_Node__0 *_Nonnull const inner_type__ = build_type_name_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		children__->add__1(inner_type__);
		if (cond(void_ptr__0op__equal(inner_type__->referenced_type__, none)))
		{
			add_could_not_determine_type_error__1(inner_type__);
			return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
		}

		Type__0 const *_Nonnull const type__ = build_optional_type__3(builder__, name_table__, inner_type__->referenced_type__);
		return Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), type__, syntax__, children__);
	}
	else
	{
		int32 const place__ = syntax__->start__;
		NOT_IMPLEMENTED__1(string__0op__add(string__0op__add(string__0op__add(((string){12,(uint8_t const*)"syntax.kind="}), int_to_string__1(syntax__->kind__)), ((string){4,(uint8_t const*)" at "})), int_to_string__1(place__)));
	}
}

Type__0 const *_Nonnull build_optional_type__3(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Name_Table__0 const *_Nonnull const name_table__, Type__0 const *_Nonnull const base_type__)
{
	Name_Subtable__0 const *_Nullable const optional_type_scope__ = get_name__2(name_table__, builder__->optional_type_name__);
	assert__1(void_ptr__0op__not_equal(optional_type_scope__, none));
	Type__0 const *_Nonnull const optional_type__ = optional_type_scope__->type__;
	system__collections__List__1<Type__0 const *_Nonnull> *_Nonnull const type_arguments__ = system__collections__List__1__0new__0<Type__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Type__0 const *_Nonnull>)));
	type_arguments__->add__1(base_type__);
	Type__0 const *_Nonnull const type__ = Type__0__0new__generic__2(allocate(sizeof(Type__0)), optional_type__, type_arguments__);
	return type__;
}

system__collections__List__1<Type__0 const *_Nonnull> const *_Nonnull build_type_arguments_semantic_node__5(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Syntax_Node__0 const *_Nonnull const syntax__, Name_Table__0 const *_Nonnull const name_table__, Name_Subtable__0 const *_Nonnull const scope__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const children__)
{
	system__collections__List__1<Type__0 const *_Nonnull> *_Nonnull const type_parameters__ = system__collections__List__1__0new__0<Type__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Type__0 const *_Nonnull>)));
	if (cond(int32__0op__equal(syntax__->kind__, IdentifierName__)))
	{
		return type_parameters__;
	}

	assert__2(int32__0op__equal(syntax__->kind__, GenericName__), string__0op__add(((string){13,(uint8_t const*)"syntax.kind=="}), int_to_string__1(syntax__->kind__)));
	BOOL in_type_arguments__ = FALSE;
	for (void_ptr__0iter iter = void_ptr__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const *_Nonnull const type_argument__ = void_ptr__0current(&iter);
		if (cond(in_type_arguments__))
		{
			if (cond(int32__0op__not_equal(type_argument__->kind__, GreaterThan__)))
			{
				Semantic_Node__0 const *_Nonnull const type_node__ = build_type_name_semantic_node__4(builder__, type_argument__, name_table__, scope__);
				type_parameters__->add__1(type_node__->referenced_type__);
				children__->add__1(type_node__);
			}
		}
		else if (cond(int32__0op__equal(type_argument__->kind__, LessThan__)))
		{
			in_type_arguments__ = TRUE;
		}
	}

	return type_parameters__;
}

Semantic_Node__0 const *_Nonnull build_constructor_name_semantic_node__4(Semantic_Tree_Builder__0 const *_Nonnull const builder__, Syntax_Node__0 const *_Nonnull const syntax__, Name_Table__0 const *_Nonnull const name_table__, Name_Subtable__0 const *_Nonnull const scope__)
{
	if (cond(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, QualifiedName__)) && bool_arg(int32__0op__equal(system__collections__List__1__0op__element(syntax__->children__, ((int32){2}))->kind__, IdentifierName__)))))
	{
		system__collections__List__1<Semantic_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
		Syntax_Node__0 const *_Nonnull const qualifier__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		Semantic_Node__0 const *_Nonnull const type_node__ = build_type_name_semantic_node__4(builder__, qualifier__, name_table__, scope__);
		children__->add__1(type_node__);
		Syntax_Node__0 const *_Nonnull const name__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){2}));
		string const constructor_name__ = string__0op__add(((string){4,(uint8_t const*)"new_"}), get_text__1(name__));
		Type__0 const *_Nonnull const referenced_type__ = type_node__->referenced_type__;
		assert__2(void_ptr__0op__not_equal(referenced_type__, none), string__0op__add(string__0op__add(((string){24,(uint8_t const*)"no referenced type for `"}), get_text__1(type_node__)), ((string){1,(uint8_t const*)"`"})));
		Name_Subtable__0 const *_Nullable const constructor_scope__ = lookup_special__2(get_name__2(name_table__, referenced_type__->name__), constructor_name__);
		if (cond(void_ptr__0op__not_equal(constructor_scope__, none)))
		{
			children__->add__1(Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), name__));
			return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
		}
	}

	return build_type_name_semantic_node__4(builder__, syntax__, name_table__, scope__);
}

void add_resolution_error__1(Semantic_Node__0 *_Nonnull const node__)
{
	add_diagnostic__2(node__, Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), FatalCompilationError__, Analysis__, node__->source__, get_text_span__1(node__), string__0op__add(string__0op__add(((string){24,(uint8_t const*)"Could not resolve name `"}), get_text__1(node__)), ((string){1,(uint8_t const*)"`"}))));
}

void add_resolution_error__2(Semantic_Node__0 *_Nonnull const node__, Semantic_Node__0 const *_Nonnull const qualifier__)
{
	add_diagnostic__2(node__, Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), FatalCompilationError__, Analysis__, node__->source__, get_text_span__1(node__), string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){24,(uint8_t const*)"Could not resolve name `"}), get_text__1(node__)), ((string){21,(uint8_t const*)"` because qualifier `"})), get_text__1(qualifier__)), ((string){24,(uint8_t const*)"` could not be resolved."}))));
}

void add_could_not_determine_type_error__1(Semantic_Node__0 *_Nonnull const node__)
{
	add_diagnostic__2(node__, Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), FatalCompilationError__, Analysis__, node__->source__, get_text_span__1(node__), string__0op__add(string__0op__add(((string){30,(uint8_t const*)"Could not determine type for `"}), get_text__1(node__)), ((string){1,(uint8_t const*)"`"}))));
}

Symbol__0 const *_Nonnull build_symbols__2(Package_Name__0 const *_Nonnull const package_name__, system__collections__List__1<Compilation_Unit__0 const *_Nonnull> const *_Nonnull const compilation_units__)
{
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const symbols__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	return Symbol__0__0new__package__2(allocate(sizeof(Symbol__0)), package_name__->unqualified__, symbols__);
}

Compilation_Unit_Parser__0 *_Nonnull Compilation_Unit_Parser__0__0new__1(Compilation_Unit_Parser__0 *_Nonnull self, Token_Stream__0 *_Nonnull const token_stream__)
{
	self->token_stream__ = token_stream__;
	self->compilation_unit__ = none;
	return self;
}

Syntax_Node__0 const *_Nonnull parse__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	if (cond(void_ptr__0op__equal(parser__->compilation_unit__, none)))
	{
		parser__->token__ = next_token__1(parser__->token_stream__);
		parser__->compilation_unit__ = parse_compilation_unit__1(parser__);
	}

	return parser__->compilation_unit__;
}

Syntax_Node__0 const *_Nullable accept_token__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	Syntax_Node__0 const *_Nullable const node__ = parser__->token__;
	parser__->token__ = next_token__1(parser__->token_stream__);
	return node__;
}

Syntax_Node__0 const *_Nonnull expect_token__2(Compilation_Unit_Parser__0 *_Nonnull const parser__, int32 const tokenType__)
{
	if (cond(void_ptr__0op__equal(parser__->token__, none)))
	{
		return Syntax_Node__0__0new__missing__3(allocate(sizeof(Syntax_Node__0)), tokenType__, parser__->token_stream__->source__, source_byte_length__1(parser__->token_stream__->source__));
	}

	if (cond(bool_op(bool_arg(void_ptr__0op__equal(parser__->token__, none)) || bool_arg(int32__0op__not_equal(parser__->token__->kind__, tokenType__)))))
	{
		return Syntax_Node__0__0new__missing__3(allocate(sizeof(Syntax_Node__0)), tokenType__, parser__->token_stream__->source__, parser__->token__->start__);
	}

	Syntax_Node__0 const *_Nullable const node__ = parser__->token__;
	parser__->token__ = next_token__1(parser__->token_stream__);
	return node__;
}

Syntax_Node__0 const *_Nonnull parse_type_name__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, CodePoint__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, String__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, Int__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, Bool__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, Void__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, UnsignedInt__)))))
	{
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), PredefinedType__, accept_token__1(parser__));
	}
	else
	{
		Syntax_Node__0 const *_Nonnull type__ = Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), IdentifierName__, expect_token__2(parser__, Identifier__));
		while (cond(int32__0op__equal(parser__->token__->kind__, Dot__)))
		{
			system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
			children__->add__1(type__);
			children__->add__1(expect_token__2(parser__, Dot__));
			Syntax_Node__0 const *_Nonnull const identifier__ = expect_token__2(parser__, Identifier__);
			if (cond(int32__0op__equal(parser__->token__->kind__, LessThan__)))
			{
				system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const genericNameChildren__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
				genericNameChildren__->add__1(Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), IdentifierName__, identifier__));
				genericNameChildren__->add__1(expect_token__2(parser__, LessThan__));
				genericNameChildren__->add__1(parse_type__1(parser__));
				genericNameChildren__->add__1(expect_token__2(parser__, GreaterThan__));
				children__->add__1(Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), GenericName__, genericNameChildren__));
			}
			else
			{
				children__->add__1(Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), IdentifierName__, identifier__));
			}

			type__ = Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), QualifiedName__, children__);
		}

		return type__;
	}
}

Syntax_Node__0 const *_Nonnull parse_non_optional_type__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	if (cond(int32__0op__equal(parser__->token__->kind__, MutableKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, MutableKeyword__));
		children__->add__1(parse_type_name__1(parser__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), MutableType__, children__);
	}
	else
	{
		children__->add__1(parse_type_name__1(parser__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), ImmutableType__, children__);
	}
}

Syntax_Node__0 const *_Nonnull parse_type__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	Syntax_Node__0 const *_Nonnull type__ = parse_non_optional_type__1(parser__);
	while (cond(int32__0op__equal(parser__->token__->kind__, Question__)))
	{
		system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
		children__->add__1(type__);
		children__->add__1(expect_token__2(parser__, Question__));
		type__ = Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), ImmutableType__, Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), OptionalType__, children__));
	}

	return type__;
}

Syntax_Node__0 const *_Nonnull parse_atom__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	if (cond(int32__0op__equal(parser__->token__->kind__, NewKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, NewKeyword__));
		children__->add__1(parse_type_name__1(parser__));
		children__->add__1(parse_call_arguments__1(parser__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), NewExpression__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, NotOperator__)))
	{
		children__->add__1(expect_token__2(parser__, NotOperator__));
		children__->add__1(parse_expression__2(parser__, ((int32){8})));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), NotExpression__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, LeftParen__)))
	{
		children__->add__1(expect_token__2(parser__, LeftParen__));
		children__->add__1(parse_expression__1(parser__));
		children__->add__1(expect_token__2(parser__, RightParen__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), ParenthesizedExpression__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, Pipe__)))
	{
		children__->add__1(expect_token__2(parser__, Pipe__));
		children__->add__1(parse_expression__1(parser__));
		children__->add__1(expect_token__2(parser__, Pipe__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), MagnitudeExpression__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, Minus__)))
	{
		children__->add__1(expect_token__2(parser__, Minus__));
		children__->add__1(parse_expression__2(parser__, ((int32){8})));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), NegateExpression__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, NoneKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, NoneKeyword__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), NoneLiteralExpression__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, SelfKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, SelfKeyword__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), SelfExpression__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, TrueKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, TrueKeyword__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), TrueLiteralExpression__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, FalseKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, FalseKeyword__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), FalseLiteralExpression__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, Number__)))
	{
		children__->add__1(expect_token__2(parser__, Number__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), NumericLiteralExpression__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, Identifier__)))
	{
		children__->add__1(expect_token__2(parser__, Identifier__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), IdentifierName__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, StringLiteral__)))
	{
		children__->add__1(expect_token__2(parser__, StringLiteral__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), StringLiteralExpression__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, CodePointLiteral__)))
	{
		children__->add__1(expect_token__2(parser__, CodePointLiteral__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), CodePointLiteralExpression__, children__);
	}

	return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), IdentifierName__, expect_token__2(parser__, Identifier__));
}

Syntax_Node__0 const *_Nonnull parse_call_arguments__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	children__->add__1(expect_token__2(parser__, LeftParen__));
	if (cond(int32__0op__not_equal(parser__->token__->kind__, RightParen__)))
	{
		for (;;)
		{
			children__->add__1(parse_expression__1(parser__));
			if (cond(int32__0op__equal(parser__->token__->kind__, Comma__)))
			{
				children__->add__1(expect_token__2(parser__, Comma__));
			}
			else
			{
				break;
			}
		}
	}

	children__->add__1(expect_token__2(parser__, RightParen__));
	return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), ArgumentList__, children__);
}

Syntax_Node__0 const *_Nonnull parse_expression__2(Compilation_Unit_Parser__0 *_Nonnull const parser__, int32 const minPrecedence__)
{
	Syntax_Node__0 const *_Nonnull expression__ = parse_atom__1(parser__);
	for (;;)
	{
		system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
		children__->add__1(expression__);
		int32 precedence__;
		BOOL leftAssociative__;
		BOOL suffixOperator__ = FALSE;
		int32 expressionType__;
		if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, Equals__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, PlusEquals__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, MinusEquals__)))) && bool_arg(int32__0op__lte(minPrecedence__, ((int32){1}))))))
		{
			precedence__ = ((int32){1});
			leftAssociative__ = FALSE;
			children__->add__1(accept_token__1(parser__));
			expressionType__ = AssignmentExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, OrKeyword__)) && bool_arg(int32__0op__lte(minPrecedence__, ((int32){2}))))))
		{
			precedence__ = ((int32){2});
			leftAssociative__ = TRUE;
			children__->add__1(expect_token__2(parser__, OrKeyword__));
			expressionType__ = OrExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, AndKeyword__)) && bool_arg(int32__0op__lte(minPrecedence__, ((int32){3}))))))
		{
			precedence__ = ((int32){3});
			leftAssociative__ = TRUE;
			children__->add__1(expect_token__2(parser__, AndKeyword__));
			expressionType__ = AndExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, EqualsEquals__)) && bool_arg(int32__0op__lte(minPrecedence__, ((int32){4}))))))
		{
			precedence__ = ((int32){4});
			leftAssociative__ = TRUE;
			children__->add__1(expect_token__2(parser__, EqualsEquals__));
			expressionType__ = EqualExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, EqualsSlashEquals__)) && bool_arg(int32__0op__lte(minPrecedence__, ((int32){4}))))))
		{
			precedence__ = ((int32){4});
			leftAssociative__ = TRUE;
			children__->add__1(expect_token__2(parser__, EqualsSlashEquals__));
			expressionType__ = NotEqualExpression__;
		}
		else if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, LessThan__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, LessThanEquals__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, GreaterThan__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, GreaterThanEquals__)))) && bool_arg(int32__0op__lte(minPrecedence__, ((int32){5}))))))
		{
			precedence__ = ((int32){5});
			leftAssociative__ = TRUE;
			children__->add__1(accept_token__1(parser__));
			expressionType__ = ComparisonExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, Plus__)) && bool_arg(int32__0op__lte(minPrecedence__, ((int32){6}))))))
		{
			precedence__ = ((int32){6});
			leftAssociative__ = TRUE;
			children__->add__1(expect_token__2(parser__, Plus__));
			expressionType__ = AddExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, Minus__)) && bool_arg(int32__0op__lte(minPrecedence__, ((int32){6}))))))
		{
			precedence__ = ((int32){6});
			leftAssociative__ = TRUE;
			children__->add__1(expect_token__2(parser__, Minus__));
			expressionType__ = SubtractExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, Asterisk__)) && bool_arg(int32__0op__lte(minPrecedence__, ((int32){7}))))))
		{
			precedence__ = ((int32){7});
			leftAssociative__ = TRUE;
			children__->add__1(expect_token__2(parser__, Asterisk__));
			expressionType__ = MultiplyExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, Slash__)) && bool_arg(int32__0op__lte(minPrecedence__, ((int32){7}))))))
		{
			precedence__ = ((int32){7});
			leftAssociative__ = TRUE;
			children__->add__1(expect_token__2(parser__, Slash__));
			expressionType__ = DivideExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, Percent__)) && bool_arg(int32__0op__lte(minPrecedence__, ((int32){7}))))))
		{
			precedence__ = ((int32){7});
			leftAssociative__ = TRUE;
			children__->add__1(expect_token__2(parser__, Percent__));
			expressionType__ = RemainderExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, LeftParen__)) && bool_arg(int32__0op__lte(minPrecedence__, ((int32){9}))))))
		{
			precedence__ = ((int32){9});
			leftAssociative__ = TRUE;
			suffixOperator__ = TRUE;
			children__->add__1(parse_call_arguments__1(parser__));
			expressionType__ = InvocationExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, Dot__)) && bool_arg(int32__0op__lte(minPrecedence__, ((int32){9}))))))
		{
			precedence__ = ((int32){9});
			leftAssociative__ = TRUE;
			children__->add__1(expect_token__2(parser__, Dot__));
			expressionType__ = MemberAccessExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, LeftBracket__)) && bool_arg(int32__0op__lte(minPrecedence__, ((int32){9}))))))
		{
			precedence__ = ((int32){9});
			leftAssociative__ = TRUE;
			suffixOperator__ = TRUE;
			children__->add__1(expect_token__2(parser__, LeftBracket__));
			children__->add__1(parse_expression__1(parser__));
			children__->add__1(expect_token__2(parser__, RightBracket__));
			expressionType__ = ElementAccessExpression__;
		}
		else
		{
			return expression__;
		}

		if (cond(BOOL__0op__not(suffixOperator__)))
		{
			if (cond(leftAssociative__))
			{
				op__add_assign(&(precedence__), ((int32){1}));
			}

			children__->add__1(parse_expression__2(parser__, precedence__));
			expression__ = Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), expressionType__, children__);
		}
		else
		{
			expression__ = Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), expressionType__, children__);
		}
	}
}

Syntax_Node__0 const *_Nonnull parse_expression__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	return parse_expression__2(parser__, ((int32){1}));
}

Syntax_Node__0 const *_Nonnull parse_statement__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	if (cond(int32__0op__equal(parser__->token__->kind__, ReturnKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, ReturnKeyword__));
		if (cond(int32__0op__not_equal(parser__->token__->kind__, Semicolon__)))
		{
			children__->add__1(parse_expression__1(parser__));
		}

		children__->add__1(expect_token__2(parser__, Semicolon__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), ReturnStatement__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, LoopKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, LoopKeyword__));
		children__->add__1(parse_block__1(parser__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), LoopStatement__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, WhileKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, WhileKeyword__));
		children__->add__1(parse_expression__1(parser__));
		children__->add__1(parse_block__1(parser__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), WhileStatement__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, ForKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, ForKeyword__));
		children__->add__1(parse_variable_declaration__2(parser__, FALSE));
		children__->add__1(expect_token__2(parser__, InKeyword__));
		children__->add__1(parse_expression__1(parser__));
		children__->add__1(parse_block__1(parser__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), ForStatement__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, DoKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, DoKeyword__));
		children__->add__1(parse_block__1(parser__));
		children__->add__1(expect_token__2(parser__, WhileKeyword__));
		children__->add__1(parse_expression__1(parser__));
		children__->add__1(expect_token__2(parser__, Semicolon__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), DoWhileStatement__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, IfKeyword__)))
	{
		return parse_if_statement__1(parser__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, BreakKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, BreakKeyword__));
		children__->add__1(expect_token__2(parser__, Semicolon__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), BreakStatement__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, ContinueKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, ContinueKeyword__));
		children__->add__1(expect_token__2(parser__, Semicolon__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), ContinueStatement__, children__);
	}

	if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, VarKeyword__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, LetKeyword__)))))
	{
		children__->add__1(parse_variable_declaration__2(parser__, TRUE));
		children__->add__1(expect_token__2(parser__, Semicolon__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), LocalDeclarationStatement__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, LeftBrace__)))
	{
		return parse_block__1(parser__);
	}

	children__->add__1(parse_expression__1(parser__));
	children__->add__1(expect_token__2(parser__, Semicolon__));
	return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), ExpressionStatement__, children__);
}

Syntax_Node__0 const *_Nonnull parse_if_statement__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	children__->add__1(expect_token__2(parser__, IfKeyword__));
	children__->add__1(parse_expression__1(parser__));
	children__->add__1(parse_block__1(parser__));
	if (cond(int32__0op__equal(parser__->token__->kind__, ElseKeyword__)))
	{
		system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const elseChildren__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
		elseChildren__->add__1(expect_token__2(parser__, ElseKeyword__));
		if (cond(int32__0op__equal(parser__->token__->kind__, IfKeyword__)))
		{
			elseChildren__->add__1(parse_if_statement__1(parser__));
		}
		else
		{
			elseChildren__->add__1(parse_block__1(parser__));
		}

		children__->add__1(Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), ElseClause__, elseChildren__));
	}

	return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), IfStatement__, children__);
}

Syntax_Node__0 const *_Nonnull parse_variable_declaration__2(Compilation_Unit_Parser__0 *_Nonnull const parser__, BOOL const allowInitializer__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, LetKeyword__)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, VarKeyword__)))))
	{
		children__->add__1(expect_token__2(parser__, LetKeyword__));
	}
	else
	{
		children__->add__1(expect_token__2(parser__, VarKeyword__));
	}

	children__->add__1(expect_token__2(parser__, Identifier__));
	children__->add__1(expect_token__2(parser__, Colon__));
	children__->add__1(parse_type__1(parser__));
	if (cond(bool_op(bool_arg(allowInitializer__) && bool_arg(int32__0op__equal(parser__->token__->kind__, Equals__)))))
	{
		children__->add__1(expect_token__2(parser__, Equals__));
		children__->add__1(parse_expression__1(parser__));
	}

	return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), VariableDeclaration__, children__);
}

Syntax_Node__0 const *_Nonnull parse_block__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	children__->add__1(expect_token__2(parser__, LeftBrace__));
	while (cond(bool_op(bool_arg(int32__0op__not_equal(parser__->token__->kind__, RightBrace__)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, EndOfFileToken__)))))
	{
		Syntax_Node__0 const *_Nonnull const startToken__ = parser__->token__;
		children__->add__1(parse_statement__1(parser__));
		if (cond(void_ptr__0op__equal(parser__->token__, startToken__)))
		{
			system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const skipped__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
			while (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__not_equal(parser__->token__->kind__, LeftBrace__)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, RightBrace__)))) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, EndOfFileToken__)))))
			{
				int32 const currentTokenType__ = parser__->token__->kind__;
				skipped__->add__1(accept_token__1(parser__));
				if (cond(int32__0op__equal(currentTokenType__, Semicolon__)))
				{
					break;
				}
			}

			children__->add__1(Syntax_Node__0__0new__skipped__1(allocate(sizeof(Syntax_Node__0)), skipped__));
		}
	}

	children__->add__1(expect_token__2(parser__, RightBrace__));
	return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), Block__, children__);
}

Syntax_Node__0 const *_Nonnull parse_parameter_list__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	children__->add__1(expect_token__2(parser__, LeftParen__));
	if (cond(int32__0op__not_equal(parser__->token__->kind__, RightParen__)))
	{
		for (;;)
		{
			system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const parameterChildren__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
			if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, MutableKeyword__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, SelfKeyword__)))))
			{
				if (cond(int32__0op__equal(parser__->token__->kind__, MutableKeyword__)))
				{
					parameterChildren__->add__1(expect_token__2(parser__, MutableKeyword__));
				}

				parameterChildren__->add__1(expect_token__2(parser__, SelfKeyword__));
				children__->add__1(Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), SelfParameter__, parameterChildren__));
			}
			else
			{
				BOOL const mutableBinding__ = int32__0op__equal(parser__->token__->kind__, VarKeyword__);
				if (cond(int32__0op__equal(parser__->token__->kind__, VarKeyword__)))
				{
					parameterChildren__->add__1(expect_token__2(parser__, VarKeyword__));
				}

				parameterChildren__->add__1(expect_token__2(parser__, Identifier__));
				parameterChildren__->add__1(expect_token__2(parser__, Colon__));
				Syntax_Node__0 const *_Nonnull const type__ = parse_type__1(parser__);
				parameterChildren__->add__1(type__);
				children__->add__1(Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), Parameter__, parameterChildren__));
			}

			if (cond(int32__0op__equal(parser__->token__->kind__, Comma__)))
			{
				children__->add__1(expect_token__2(parser__, Comma__));
			}
			else
			{
				break;
			}
		}
	}

	children__->add__1(expect_token__2(parser__, RightParen__));
	return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), ParameterList__, children__);
}

Syntax_Node__0 const *_Nonnull parse_member_declaration__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, PublicKeyword__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, ProtectedKeyword__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, InternalKeyword__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, PrivateKeyword__)))))
	{
		children__->add__1(accept_token__1(parser__));
	}
	else
	{
		children__->add__1(expect_token__2(parser__, PublicKeyword__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, NewKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, NewKeyword__));
		if (cond(int32__0op__equal(parser__->token__->kind__, Identifier__)))
		{
			children__->add__1(expect_token__2(parser__, Identifier__));
		}

		children__->add__1(parse_parameter_list__1(parser__));
		children__->add__1(parse_block__1(parser__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), ConstructorDeclaration__, children__);
	}

	if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, VarKeyword__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, LetKeyword__)))))
	{
		children__->add__1(parse_variable_declaration__2(parser__, FALSE));
		children__->add__1(expect_token__2(parser__, Semicolon__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), FieldDeclaration__, children__);
	}

	children__->add__1(expect_token__2(parser__, Identifier__));
	children__->add__1(parse_parameter_list__1(parser__));
	children__->add__1(expect_token__2(parser__, Arrow__));
	children__->add__1(parse_type__1(parser__));
	children__->add__1(parse_block__1(parser__));
	return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), MethodDeclaration__, children__);
}

Syntax_Node__0 const *_Nonnull parse_declaration__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, PublicKeyword__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, ProtectedKeyword__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, InternalKeyword__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, PrivateKeyword__)))))
	{
		children__->add__1(accept_token__1(parser__));
	}
	else
	{
		children__->add__1(expect_token__2(parser__, PublicKeyword__));
	}

	if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, VarKeyword__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, LetKeyword__)))))
	{
		children__->add__1(parse_variable_declaration__2(parser__, TRUE));
		children__->add__1(expect_token__2(parser__, Semicolon__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), GlobalDeclaration__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, ClassKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, ClassKeyword__));
		children__->add__1(expect_token__2(parser__, Identifier__));
		children__->add__1(expect_token__2(parser__, LeftBrace__));
		while (cond(bool_op(bool_arg(int32__0op__not_equal(parser__->token__->kind__, RightBrace__)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, EndOfFileToken__)))))
		{
			Syntax_Node__0 const *_Nonnull const startToken__ = parser__->token__;
			children__->add__1(parse_member_declaration__1(parser__));
			if (cond(void_ptr__0op__equal(parser__->token__, startToken__)))
			{
				children__->add__1(Syntax_Node__0__0new__skipped__1(allocate(sizeof(Syntax_Node__0)), accept_token__1(parser__)));
			}
		}

		children__->add__1(expect_token__2(parser__, RightBrace__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), ClassDeclaration__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, StructKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, StructKeyword__));
		children__->add__1(expect_token__2(parser__, Identifier__));
		children__->add__1(expect_token__2(parser__, LeftBrace__));
		while (cond(bool_op(bool_arg(int32__0op__not_equal(parser__->token__->kind__, RightBrace__)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, EndOfFileToken__)))))
		{
			Syntax_Node__0 const *_Nonnull const startToken__ = parser__->token__;
			children__->add__1(parse_member_declaration__1(parser__));
			if (cond(void_ptr__0op__equal(parser__->token__, startToken__)))
			{
				children__->add__1(Syntax_Node__0__0new__skipped__1(allocate(sizeof(Syntax_Node__0)), accept_token__1(parser__)));
			}
		}

		children__->add__1(expect_token__2(parser__, RightBrace__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), StructDeclaration__, children__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, EnumKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, EnumKeyword__));
		children__->add__1(expect_token__2(parser__, StructKeyword__));
		children__->add__1(expect_token__2(parser__, Identifier__));
		children__->add__1(expect_token__2(parser__, LeftBrace__));
		while (cond(bool_op(bool_arg(int32__0op__not_equal(parser__->token__->kind__, RightBrace__)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, EndOfFileToken__)))))
		{
			system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const memberChildren__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
			memberChildren__->add__1(expect_token__2(parser__, Identifier__));
			if (cond(int32__0op__equal(parser__->token__->kind__, Equals__)))
			{
				memberChildren__->add__1(expect_token__2(parser__, Equals__));
				memberChildren__->add__1(expect_token__2(parser__, Number__));
			}

			if (cond(int32__0op__not_equal(parser__->token__->kind__, RightBrace__)))
			{
				memberChildren__->add__1(expect_token__2(parser__, Comma__));
			}

			children__->add__1(Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), EnumMemberDeclaration__, memberChildren__));
		}

		children__->add__1(expect_token__2(parser__, RightBrace__));
		return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), EnumDeclaration__, children__);
	}

	children__->add__1(expect_token__2(parser__, Identifier__));
	children__->add__1(parse_parameter_list__1(parser__));
	children__->add__1(expect_token__2(parser__, Arrow__));
	children__->add__1(parse_type__1(parser__));
	children__->add__1(parse_block__1(parser__));
	return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), FunctionDeclaration__, children__);
}

Syntax_Node__0 const *_Nonnull parse_compilation_unit__1(Compilation_Unit_Parser__0 *_Nonnull const parser__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	while (cond(bool_op(bool_arg(void_ptr__0op__not_equal(parser__->token__, none)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, EndOfFileToken__)))))
	{
		Syntax_Node__0 const *_Nonnull const startToken__ = parser__->token__;
		children__->add__1(parse_declaration__1(parser__));
		if (cond(void_ptr__0op__equal(parser__->token__, startToken__)))
		{
			children__->add__1(Syntax_Node__0__0new__skipped__1(allocate(sizeof(Syntax_Node__0)), accept_token__1(parser__)));
		}
	}

	children__->add__1(expect_token__2(parser__, EndOfFileToken__));
	return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), CompilationUnit__, children__);
}

Token_Stream__0 *_Nonnull lexically_analyze__1(Source_Text__0 const *_Nonnull const source__)
{
	return Token_Stream__0__0new__1(allocate(sizeof(Token_Stream__0)), source__);
}

Syntax_Node__0 const *_Nonnull parse_package__1(system__collections__List__1<Source_Text__0 const *_Nonnull> const *_Nonnull const sources__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(sources__); void_ptr__0next(&iter);)
	{
		Source_Text__0 const *_Nonnull const source__ = void_ptr__0current(&iter);
		Token_Stream__0 *_Nonnull const token_stream__ = lexically_analyze__1(source__);
		Compilation_Unit_Parser__0 *_Nonnull const compilation_unit_parser__ = Compilation_Unit_Parser__0__0new__1(allocate(sizeof(Compilation_Unit_Parser__0)), token_stream__);
		children__->add__1(parse__1(compilation_unit_parser__));
	}

	return Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), PackageNode__, children__);
}

Syntax_Node__0 *_Nonnull Syntax_Node__0__0new__4(Syntax_Node__0 *_Nonnull self, int32 const type__, Source_Text__0 const *_Nonnull const source__, int32 const start__, int32 const length__)
{
	self->kind__ = type__;
	self->is_missing__ = FALSE;
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = length__;
	self->children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	self->node_diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	return self;
}

Syntax_Node__0 *_Nonnull Syntax_Node__0__0new__5(Syntax_Node__0 *_Nonnull self, int32 const type__, BOOL const isMissing__, Source_Text__0 const *_Nonnull const source__, int32 const start__, int32 const length__)
{
	self->kind__ = type__;
	self->is_missing__ = isMissing__;
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = length__;
	self->children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	self->node_diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	return self;
}

Syntax_Node__0 *_Nonnull Syntax_Node__0__0new__2(Syntax_Node__0 *_Nonnull self, int32 const type__, Syntax_Node__0 const *_Nonnull const child__)
{
	self->kind__ = type__;
	self->is_missing__ = child__->is_missing__;
	self->source__ = child__->source__;
	self->start__ = child__->start__;
	self->byte_length__ = child__->byte_length__;
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	children__->add__1(child__);
	self->children__ = children__;
	self->node_diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	return self;
}

Syntax_Node__0 *_Nonnull Syntax_Node__0__0new__2(Syntax_Node__0 *_Nonnull self, int32 const type__, system__collections__List__1<Syntax_Node__0 const *_Nonnull> const *_Nonnull const children__)
{
	self->kind__ = type__;
	self->is_missing__ = FALSE;
	self->source__ = system__collections__List__1__0op__element(children__, ((int32){0}))->source__;
	self->start__ = system__collections__List__1__0op__element(children__, ((int32){0}))->start__;
	Syntax_Node__0 const *_Nonnull const lastChild__ = system__collections__List__1__0op__element(children__, int32__0op__sub(children__->count__, ((int32){1})));
	self->byte_length__ = int32__0op__add(int32__0op__sub(lastChild__->start__, self->start__), lastChild__->byte_length__);
	self->children__ = children__;
	self->node_diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	return self;
}

Syntax_Node__0 *_Nonnull Syntax_Node__0__0new__missing__3(Syntax_Node__0 *_Nonnull self, int32 const type__, Source_Text__0 const *_Nonnull const source__, int32 const start__)
{
	self->kind__ = type__;
	self->is_missing__ = TRUE;
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = ((int32){0});
	self->children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	self->node_diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	Text_Span__0 const *_Nonnull const span__ = Text_Span__0__0new__2(allocate(sizeof(Text_Span__0)), start__, ((int32){0}));
	self->node_diagnostics__->add__1(Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), CompilationError__, Parsing__, source__, span__, string__0op__add(((string){22,(uint8_t const*)"Missing token of type "}), int_to_string__1(type__))));
	return self;
}

Syntax_Node__0 *_Nonnull Syntax_Node__0__0new__skipped__1(Syntax_Node__0 *_Nonnull self, Syntax_Node__0 const *_Nonnull const skipped_node__)
{
	self->kind__ = SkippedTokens__;
	self->is_missing__ = skipped_node__->is_missing__;
	self->source__ = skipped_node__->source__;
	self->start__ = skipped_node__->start__;
	self->byte_length__ = skipped_node__->byte_length__;
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	children__->add__1(skipped_node__);
	self->children__ = children__;
	self->node_diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	Text_Span__0 const *_Nonnull const span__ = Text_Span__0__0new__2(allocate(sizeof(Text_Span__0)), skipped_node__->start__, skipped_node__->byte_length__);
	self->node_diagnostics__->add__1(Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), CompilationError__, Parsing__, skipped_node__->source__, span__, string__0op__add(((string){33,(uint8_t const*)"Skipped unexpected token of type "}), int_to_string__1(skipped_node__->kind__))));
	return self;
}

Syntax_Node__0 *_Nonnull Syntax_Node__0__0new__skipped__1(Syntax_Node__0 *_Nonnull self, system__collections__List__1<Syntax_Node__0 const *_Nonnull> const *_Nonnull const skipped_nodes__)
{
	self->kind__ = SkippedTokens__;
	self->is_missing__ = FALSE;
	self->source__ = system__collections__List__1__0op__element(skipped_nodes__, ((int32){0}))->source__;
	self->start__ = system__collections__List__1__0op__element(skipped_nodes__, ((int32){0}))->start__;
	Syntax_Node__0 const *_Nonnull const lastChild__ = system__collections__List__1__0op__element(skipped_nodes__, int32__0op__sub(skipped_nodes__->count__, ((int32){1})));
	self->byte_length__ = int32__0op__add(int32__0op__sub(lastChild__->start__, self->start__), lastChild__->byte_length__);
	self->children__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	self->node_diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	Text_Span__0 const *_Nonnull const span__ = Text_Span__0__0new__2(allocate(sizeof(Text_Span__0)), self->start__, self->byte_length__);
	self->node_diagnostics__->add__1(Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), CompilationError__, Parsing__, self->source__, span__, string__0op__add(string__0op__add(((string){8,(uint8_t const*)"Skipped "}), int_to_string__1(skipped_nodes__->count__)), ((string){20,(uint8_t const*)" unexpected token(s)"}))));
	return self;
}

string get_text__1(Syntax_Node__0 const *_Nonnull const syntax__)
{
	return substring__3(syntax__->source__->text__, syntax__->start__, syntax__->byte_length__);
}

Syntax_Node__0 const *_Nullable first_child_syntax__2(Syntax_Node__0 const *_Nonnull const syntax__, int32 const type__)
{
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(int32__0op__equal(child__->kind__, type__)))
		{
			return child__;
		}
	}

	return none;
}

BOOL has_child__2(Syntax_Node__0 const *_Nonnull const syntax__, int32 const type__)
{
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(int32__0op__equal(child__->kind__, type__)))
		{
			return TRUE;
		}
	}

	return FALSE;
}

void add__2(Syntax_Node__0 const *_Nonnull const syntax__, Diagnostic__0 const *_Nonnull const diagnostic__)
{
	syntax__->node_diagnostics__->add__1(diagnostic__);
}

system__collections__List__1<Diagnostic__0 const *_Nonnull> *_Nonnull all_diagnostics__1(Syntax_Node__0 const *_Nonnull const syntax__)
{
	system__collections__List__1<Diagnostic__0 const *_Nonnull> *_Nonnull diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	collect_syntax_diagnostics__2(syntax__, diagnostics__);
	return diagnostics__;
}

void collect_syntax_diagnostics__2(Syntax_Node__0 const *_Nonnull const syntax__, system__collections__List__1<Diagnostic__0 const *_Nonnull> *_Nonnull const diagnostics__)
{
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(syntax__->node_diagnostics__); void_ptr__0next(&iter);)
	{
		Diagnostic__0 const *_Nonnull const diagnostic__ = void_ptr__0current(&iter);
		diagnostics__->add__1(diagnostic__);
	}

	for (void_ptr__0iter iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		collect_syntax_diagnostics__2(child__, diagnostics__);
	}
}

system__collections__List__1<Syntax_Node__0 const *_Nonnull> const *_Nonnull members__1(Syntax_Node__0 const *_Nonnull const syntax__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const members__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(child__->kind__, ConstructorDeclaration__)) || bool_arg(int32__0op__equal(child__->kind__, FieldDeclaration__)))) || bool_arg(int32__0op__equal(child__->kind__, MethodDeclaration__)))))
		{
			members__->add__1(child__);
		}
	}

	return members__;
}

system__collections__List__1<Syntax_Node__0 const *_Nonnull> const *_Nonnull parameters__1(Syntax_Node__0 const *_Nonnull const syntax__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const parameters__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(int32__0op__equal(child__->kind__, Parameter__)) || bool_arg(int32__0op__equal(child__->kind__, SelfParameter__)))))
		{
			parameters__->add__1(child__);
		}
	}

	return parameters__;
}

system__collections__List__1<Syntax_Node__0 const *_Nonnull> const *_Nonnull statements__1(Syntax_Node__0 const *_Nonnull const syntax__)
{
	system__collections__List__1<Syntax_Node__0 const *_Nonnull> *_Nonnull const statements__ = system__collections__List__1__0new__0<Syntax_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Syntax_Node__0 const *_Nonnull>)));
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(int32__0op__not_equal(child__->kind__, LeftBrace__)) && bool_arg(int32__0op__not_equal(child__->kind__, RightBrace__)))))
		{
			statements__->add__1(child__);
		}
	}

	return statements__;
}

Syntax_Node__0 const *_Nullable access_modifier__1(Syntax_Node__0 const *_Nonnull const syntax__)
{
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(child__->kind__, PublicKeyword__)) || bool_arg(int32__0op__equal(child__->kind__, ProtectedKeyword__)))) || bool_arg(int32__0op__equal(child__->kind__, InternalKeyword__)))) || bool_arg(int32__0op__equal(child__->kind__, PrivateKeyword__)))))
		{
			return child__;
		}
	}

	return none;
}

Token_Stream__0 *_Nonnull Token_Stream__0__0new__1(Token_Stream__0 *_Nonnull self, Source_Text__0 const *_Nonnull const source__)
{
	self->source__ = source__;
	self->position__ = ((int32){0});
	self->diagnostics__ = system__collections__List__1__0new__0<Diagnostic__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Diagnostic__0 const *_Nonnull>)));
	self->end_of_file__ = FALSE;
	return self;
}

Syntax_Node__0 const *_Nullable next_token__1(Token_Stream__0 *_Nonnull const tokens__)
{
	if (cond(int32__0op__gte(tokens__->position__, source_byte_length__1(tokens__->source__))))
	{
		return end_of_file_token__1(tokens__);
	}

	int32 end__ = int32__0op__neg(((int32){1}));
	while (cond(int32__0op__lt(tokens__->position__, source_byte_length__1(tokens__->source__))))
	{
		code_point const curChar__ = string__0__0op__element(tokens__->source__->text__, tokens__->position__);
		if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(code_point__0op__equal(curChar__, ((code_point){/* */0x20}))) || bool_arg(code_point__0op__equal(curChar__, ((code_point){/*\t*/0x9}))))) || bool_arg(code_point__0op__equal(curChar__, ((code_point){/*\n*/0xA}))))) || bool_arg(code_point__0op__equal(curChar__, ((code_point){/*\r*/0xD}))))))
		{
			op__add_assign(&(tokens__->position__), ((int32){1}));
			continue;
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*{*/0x7B}))))
		{
			return new_operator_token__2(tokens__, LeftBrace__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*}*/0x7D}))))
		{
			return new_operator_token__2(tokens__, RightBrace__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*(*/0x28}))))
		{
			return new_operator_token__2(tokens__, LeftParen__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*)*/0x29}))))
		{
			return new_operator_token__2(tokens__, RightParen__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*;*/0x3B}))))
		{
			return new_operator_token__2(tokens__, Semicolon__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*,*/0x2C}))))
		{
			return new_operator_token__2(tokens__, Comma__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*.*/0x2E}))))
		{
			return new_operator_token__2(tokens__, Dot__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*:*/0x3A}))))
		{
			return new_operator_token__2(tokens__, Colon__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*[*/0x5B}))))
		{
			return new_operator_token__2(tokens__, LeftBracket__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*]*/0x5D}))))
		{
			return new_operator_token__2(tokens__, RightBracket__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*?*/0x3F}))))
		{
			return new_operator_token__2(tokens__, Question__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*|*/0x7C}))))
		{
			return new_operator_token__2(tokens__, Pipe__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/***/0x2A}))))
		{
			return new_operator_token__2(tokens__, Asterisk__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*=*/0x3D}))))
		{
			if (cond(bool_op(bool_arg(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){1})), source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){1}))), ((code_point){/*=*/0x3D}))))))
			{
				return new_operator_token__3(tokens__, EqualsEquals__, ((int32){2}));
			}

			if (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){2})), source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){1}))), ((code_point){/*/*/0x2F}))))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){2}))), ((code_point){/*=*/0x3D}))))))
			{
				return new_operator_token__3(tokens__, EqualsSlashEquals__, ((int32){3}));
			}

			return new_operator_token__2(tokens__, Equals__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*+*/0x2B}))))
		{
			if (cond(bool_op(bool_arg(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){1})), source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){1}))), ((code_point){/*=*/0x3D}))))))
			{
				return new_operator_token__3(tokens__, PlusEquals__, ((int32){2}));
			}

			return new_operator_token__2(tokens__, Plus__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*-*/0x2D}))))
		{
			if (cond(bool_op(bool_arg(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){1})), source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){1}))), ((code_point){/*>*/0x3E}))))))
			{
				return new_operator_token__3(tokens__, Arrow__, ((int32){2}));
			}

			if (cond(bool_op(bool_arg(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){1})), source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){1}))), ((code_point){/*=*/0x3D}))))))
			{
				return new_operator_token__3(tokens__, MinusEquals__, ((int32){2}));
			}

			return new_operator_token__2(tokens__, Minus__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*/*/0x2F}))))
		{
			if (cond(bool_op(bool_arg(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){1})), source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){1}))), ((code_point){/*/*/0x2F}))))))
			{
				while (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__lt(tokens__->position__, source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__not_equal(string__0__0op__element(tokens__->source__->text__, tokens__->position__), ((code_point){/*\r*/0xD}))))) && bool_arg(code_point__0op__not_equal(string__0__0op__element(tokens__->source__->text__, tokens__->position__), ((code_point){/*\n*/0xA}))))))
				{
					op__add_assign(&(tokens__->position__), ((int32){1}));
				}

				continue;
			}

			if (cond(bool_op(bool_arg(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){1})), source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){1}))), ((code_point){/***/0x2A}))))))
			{
				op__add_assign(&(tokens__->position__), ((int32){2}));
				BOOL lastCharStar__ = FALSE;
				while (cond(bool_op(bool_arg(int32__0op__lt(tokens__->position__, source_byte_length__1(tokens__->source__))) && bool_arg(BOOL__0op__not(bool_op(bool_arg(lastCharStar__) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, tokens__->position__), ((code_point){/*/*/0x2F})))))))))
				{
					lastCharStar__ = code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, tokens__->position__), ((code_point){/***/0x2A}));
					op__add_assign(&(tokens__->position__), ((int32){1}));
				}

				op__add_assign(&(tokens__->position__), ((int32){1}));
				continue;
			}

			return new_operator_token__2(tokens__, Slash__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*%*/0x25}))))
		{
			return new_operator_token__2(tokens__, Percent__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*<*/0x3C}))))
		{
			if (cond(bool_op(bool_arg(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){1})), source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){1}))), ((code_point){/*=*/0x3D}))))))
			{
				return new_operator_token__3(tokens__, LessThanEquals__, ((int32){2}));
			}

			return new_operator_token__2(tokens__, LessThan__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*>*/0x3E}))))
		{
			if (cond(bool_op(bool_arg(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){1})), source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){1}))), ((code_point){/*=*/0x3D}))))))
			{
				return new_operator_token__3(tokens__, GreaterThanEquals__, ((int32){2}));
			}

			return new_operator_token__2(tokens__, GreaterThan__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*"*/0x22}))))
		{
			end__ = int32__0op__add(tokens__->position__, ((int32){1}));
			BOOL escaped__ = FALSE;
			while (cond(bool_op(bool_arg(int32__0op__lt(end__, source_byte_length__1(tokens__->source__))) && bool_arg(bool_op(bool_arg(code_point__0op__not_equal(string__0__0op__element(tokens__->source__->text__, end__), ((code_point){/*"*/0x22}))) || bool_arg(escaped__))))))
			{
				escaped__ = bool_op(bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, end__), ((code_point){/*\\*/0x5C}))) && bool_arg(BOOL__0op__not(escaped__)));
				op__add_assign(&(end__), ((int32){1}));
			}

			op__add_assign(&(end__), ((int32){1}));
			return new_token__3(tokens__, StringLiteral__, end__);
		}
		else if (cond(code_point__0op__equal(curChar__, ((code_point){/*\'*/0x27}))))
		{
			end__ = int32__0op__add(tokens__->position__, ((int32){1}));
			BOOL escaped__ = FALSE;
			while (cond(bool_op(bool_arg(int32__0op__lt(end__, source_byte_length__1(tokens__->source__))) && bool_arg(bool_op(bool_arg(code_point__0op__not_equal(string__0__0op__element(tokens__->source__->text__, end__), ((code_point){/*\'*/0x27}))) || bool_arg(escaped__))))))
			{
				escaped__ = bool_op(bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, end__), ((code_point){/*\\*/0x5C}))) && bool_arg(BOOL__0op__not(escaped__)));
				op__add_assign(&(end__), ((int32){1}));
			}

			op__add_assign(&(end__), ((int32){1}));
			return new_token__3(tokens__, CodePointLiteral__, end__);
		}
		else
		{
			if (cond(is_identifier_char__1(curChar__)))
			{
				end__ = int32__0op__add(tokens__->position__, ((int32){1}));
				while (cond(is_identifier_char__1(string__0__0op__element(tokens__->source__->text__, end__))))
				{
					op__add_assign(&(end__), ((int32){1}));
				}

				return new_identifier_or_keyword_token__2(tokens__, end__);
			}

			if (cond(is_number_char__1(curChar__)))
			{
				end__ = int32__0op__add(tokens__->position__, ((int32){1}));
				while (cond(is_number_char__1(string__0__0op__element(tokens__->source__->text__, end__))))
				{
					op__add_assign(&(end__), ((int32){1}));
				}

				return new_token__3(tokens__, Number__, end__);
			}

			Text_Span__0 const *_Nonnull diagnosticSpan__ = Text_Span__0__0new__2(allocate(sizeof(Text_Span__0)), tokens__->position__, ((int32){1}));
			tokens__->diagnostics__->add__1(Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), CompilationError__, Lexing__, tokens__->source__, diagnosticSpan__, string__0op__add(string__0op__add(((string){19,(uint8_t const*)"Invalid character `"}), code_point_to_string__1(curChar__)), ((string){1,(uint8_t const*)"`"}))));
			tokens__->position__ = end__;
		}
	}

	return end_of_file_token__1(tokens__);
}

Syntax_Node__0 const *_Nullable end_of_file_token__1(Token_Stream__0 *_Nonnull const tokens__)
{
	if (cond(tokens__->end_of_file__))
	{
		return none;
	}

	tokens__->end_of_file__ = TRUE;
	return new_token__3(tokens__, EndOfFileToken__, tokens__->position__);
}

Syntax_Node__0 const *_Nonnull new_identifier_or_keyword_token__2(Token_Stream__0 *_Nonnull const tokens__, int32 const end__)
{
	int32 const length__ = int32__0op__sub(end__, tokens__->position__);
	string const value__ = substring__3(tokens__->source__->text__, tokens__->position__, length__);
	int32 type__;
	if (cond(string__0op__equal(value__, ((string){3,(uint8_t const*)"new"}))))
	{
		type__ = NewKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){3,(uint8_t const*)"not"}))))
	{
		type__ = NotOperator__;
	}
	else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"null"}))))
	{
		type__ = NullReservedWord__;
	}
	else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"self"}))))
	{
		type__ = SelfKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"true"}))))
	{
		type__ = TrueKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){5,(uint8_t const*)"false"}))))
	{
		type__ = FalseKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){3,(uint8_t const*)"mut"}))))
	{
		type__ = MutableKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){10,(uint8_t const*)"code_point"}))))
	{
		type__ = CodePoint__;
	}
	else if (cond(string__0op__equal(value__, ((string){6,(uint8_t const*)"string"}))))
	{
		type__ = String__;
	}
	else if (cond(string__0op__equal(value__, ((string){3,(uint8_t const*)"int"}))))
	{
		type__ = Int__;
	}
	else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"bool"}))))
	{
		type__ = Bool__;
	}
	else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"void"}))))
	{
		type__ = Void__;
	}
	else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"uint"}))))
	{
		type__ = UnsignedInt__;
	}
	else if (cond(string__0op__equal(value__, ((string){3,(uint8_t const*)"var"}))))
	{
		type__ = VarKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){3,(uint8_t const*)"and"}))))
	{
		type__ = AndKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){2,(uint8_t const*)"or"}))))
	{
		type__ = OrKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){6,(uint8_t const*)"return"}))))
	{
		type__ = ReturnKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"loop"}))))
	{
		type__ = LoopKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){5,(uint8_t const*)"while"}))))
	{
		type__ = WhileKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){3,(uint8_t const*)"for"}))))
	{
		type__ = ForKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){3,(uint8_t const*)"let"}))))
	{
		type__ = LetKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){2,(uint8_t const*)"in"}))))
	{
		type__ = InKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){2,(uint8_t const*)"do"}))))
	{
		type__ = DoKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){2,(uint8_t const*)"if"}))))
	{
		type__ = IfKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"else"}))))
	{
		type__ = ElseKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){5,(uint8_t const*)"break"}))))
	{
		type__ = BreakKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){8,(uint8_t const*)"continue"}))))
	{
		type__ = ContinueKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){7,(uint8_t const*)"private"}))))
	{
		type__ = PrivateKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){9,(uint8_t const*)"protected"}))))
	{
		type__ = ProtectedKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){6,(uint8_t const*)"public"}))))
	{
		type__ = PublicKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){8,(uint8_t const*)"internal"}))))
	{
		type__ = InternalKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){5,(uint8_t const*)"class"}))))
	{
		type__ = ClassKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"enum"}))))
	{
		type__ = EnumKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){6,(uint8_t const*)"struct"}))))
	{
		type__ = StructKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"none"}))))
	{
		type__ = NoneKeyword__;
	}
	else
	{
		type__ = Identifier__;
		if (cond(bool_op(bool_arg(int32__0op__gt(string_byte_length__1(value__), ((int32){1}))) && bool_arg(code_point__0op__equal(string__0__0op__element(value__, int32__0op__sub(string_byte_length__1(value__), ((int32){1}))), ((code_point){/*_*/0x5F}))))))
		{
			Text_Span__0 const *_Nonnull diagnosticSpan__ = Text_Span__0__0new__2(allocate(sizeof(Text_Span__0)), tokens__->position__, int32__0op__sub(end__, tokens__->position__));
			tokens__->diagnostics__->add__1(Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), CompilationError__, Lexing__, tokens__->source__, diagnosticSpan__, string__0op__add(string__0op__add(((string){49,(uint8_t const*)"Identifiers ending with underscore are reserved `"}), value__), ((string){1,(uint8_t const*)"`"}))));
		}
	}

	return new_token__3(tokens__, type__, end__);
}

Syntax_Node__0 const *_Nonnull new_operator_token__2(Token_Stream__0 *_Nonnull const tokens__, int32 const type__)
{
	return new_token__3(tokens__, type__, int32__0op__add(tokens__->position__, ((int32){1})));
}

Syntax_Node__0 const *_Nonnull new_operator_token__3(Token_Stream__0 *_Nonnull const tokens__, int32 const type__, int32 const length__)
{
	return new_token__3(tokens__, type__, int32__0op__add(tokens__->position__, length__));
}

Syntax_Node__0 const *_Nonnull new_token__3(Token_Stream__0 *_Nonnull const tokens__, int32 const type__, int32 const end__)
{
	Syntax_Node__0 *_Nonnull const token__ = Syntax_Node__0__0new__4(allocate(sizeof(Syntax_Node__0)), type__, tokens__->source__, tokens__->position__, int32__0op__sub(end__, tokens__->position__));
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(tokens__->diagnostics__); void_ptr__0next(&iter);)
	{
		Diagnostic__0 const *_Nonnull const diagnostic__ = void_ptr__0current(&iter);
		add__2(token__, diagnostic__);
	}

	tokens__->diagnostics__->clear__0();
	tokens__->position__ = end__;
	return token__;
}

BOOL is_identifier_char__1(code_point const c__)
{
	return bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(code_point__0op__gte(c__, ((code_point){/*a*/0x61}))) && bool_arg(code_point__0op__lte(c__, ((code_point){/*z*/0x7A}))))) || bool_arg(bool_op(bool_arg(code_point__0op__gte(c__, ((code_point){/*A*/0x41}))) && bool_arg(code_point__0op__lte(c__, ((code_point){/*Z*/0x5A}))))))) || bool_arg(code_point__0op__equal(c__, ((code_point){/*_*/0x5F}))));
}

BOOL is_number_char__1(code_point const c__)
{
	return bool_op(bool_arg(code_point__0op__gte(c__, ((code_point){/*0*/0x30}))) && bool_arg(code_point__0op__lte(c__, ((code_point){/*9*/0x39}))));
}

Diagnostic__0 *_Nonnull Diagnostic__0__0new__5(Diagnostic__0 *_Nonnull self, int32 const level__, int32 const phase__, Source_Text__0 const *_Nonnull const source__, Text_Span__0 const *_Nonnull const span__, string const message__)
{
	self->level__ = level__;
	self->phase__ = phase__;
	self->source__ = source__;
	self->span__ = span__;
	self->position__ = position_of_start__2(source__, span__);
	self->message__ = message__;
	return self;
}

Emitter__0 *_Nonnull Emitter__0__0new__2(Emitter__0 *_Nonnull self, Package__0 const *_Nonnull const package__, system__collections__List__1<Source_Text__0 const *_Nonnull> const *_Nonnull const resources__)
{
	self->package__ = package__;
	self->resources__ = resources__;
	return self;
}

string emit__1(Emitter__0 *_Nonnull const emitter__)
{
	emitter__->type_declarations__ = Source_File_Builder__0__0new__0(allocate(sizeof(Source_File_Builder__0)));
	emitter__->function_declarations__ = Source_File_Builder__0__0new__0(allocate(sizeof(Source_File_Builder__0)));
	emitter__->class_declarations__ = Source_File_Builder__0__0new__0(allocate(sizeof(Source_File_Builder__0)));
	emitter__->global_definitions__ = Source_File_Builder__0__0new__0(allocate(sizeof(Source_File_Builder__0)));
	emitter__->definitions__ = Source_File_Builder__0__0new__0(allocate(sizeof(Source_File_Builder__0)));
	emitter__->main_function_return_type__ = ((string){0,(uint8_t const*)""});
	emitter__->main_function_accepts_console__ = FALSE;
	emitter__->main_function_accepts_args__ = FALSE;
	emit_preamble__1(emitter__);
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(emitter__->package__->compilation_units__); void_ptr__0next(&iter);)
	{
		Compilation_Unit__0 const *_Nonnull const compilation_unit__ = void_ptr__0current(&iter);
		emit_compilation_unit__2(emitter__, compilation_unit__);
	}

	emit_entry_point_adapter__1(emitter__);
	int32 const total_size__ = int32__0op__add(int32__0op__add(int32__0op__add(int32__0op__add(int32__0op__add(((int32){0}), byte_length__1(emitter__->type_declarations__)), byte_length__1(emitter__->function_declarations__)), byte_length__1(emitter__->class_declarations__)), byte_length__1(emitter__->global_definitions__)), byte_length__1(emitter__->definitions__));
	system__text__String_Builder__0 *_Nonnull const cpp_code__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	cpp_code__->Append__1(to_string__1(emitter__->type_declarations__));
	cpp_code__->Append__1(to_string__1(emitter__->function_declarations__));
	cpp_code__->Append__1(to_string__1(emitter__->class_declarations__));
	cpp_code__->Append__1(to_string__1(emitter__->global_definitions__));
	cpp_code__->Append__1(to_string__1(emitter__->definitions__));
	return cpp_code__->ToString__0();
}

string mangle_name__1(Type__0 const *_Nonnull const type__)
{
	system__text__String_Builder__0 *_Nonnull const builder__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	BOOL first_segment__ = TRUE;
	for (string__0iter iter = string__0iterate(type__->name__->segments__); string__0next(&iter);)
	{
		string const segment__ = string__0current(&iter);
		if (cond(first_segment__))
		{
			first_segment__ = FALSE;
		}
		else
		{
			builder__->Append__1(((string){2,(uint8_t const*)"__"}));
		}

		if (cond(BOOL__0op__not(contains_multi_underscore_runs__1(segment__))))
		{
			builder__->Append__1(segment__);
		}
		else
		{
			append_fixing_underscores__2(builder__, segment__);
		}
	}

	builder__->Append__1(((string){2,(uint8_t const*)"__"}));
	builder__->Append__1(int_to_string__1(type__->type_parameters__->count__));
	return builder__->ToString__0();
}

string mangle_function_name__2(string const name__, int32 const parameter_count__)
{
	system__text__String_Builder__0 *_Nonnull const builder__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	if (cond(BOOL__0op__not(contains_multi_underscore_runs__1(name__))))
	{
		builder__->Append__1(name__);
	}
	else
	{
		append_fixing_underscores__2(builder__, name__);
	}

	builder__->Append__1(((string){2,(uint8_t const*)"__"}));
	builder__->Append__1(int_to_string__1(parameter_count__));
	return builder__->ToString__0();
}

string mangle_field_name__1(string const name__)
{
	if (cond(BOOL__0op__not(contains_multi_underscore_runs__1(name__))))
	{
		return string__0op__add(name__, ((string){2,(uint8_t const*)"__"}));
	}
	else
	{
		system__text__String_Builder__0 *_Nonnull const builder__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
		append_fixing_underscores__2(builder__, name__);
		builder__->Append__1(((string){2,(uint8_t const*)"__"}));
		return builder__->ToString__0();
	}
}

BOOL contains_multi_underscore_runs__1(string const value__)
{
	int32 i__ = ((int32){0});
	BOOL last_char_underscore__ = FALSE;
	while (cond(int32__0op__lt(i__, string_byte_length__1(value__))))
	{
		if (cond(code_point__0op__equal(string__0__0op__element(value__, i__), ((code_point){/*_*/0x5F}))))
		{
			if (cond(last_char_underscore__))
			{
				return TRUE;
			}

			last_char_underscore__ = TRUE;
		}
		else
		{
			last_char_underscore__ = FALSE;
		}

		op__add_assign(&(i__), ((int32){1}));
	}

	return FALSE;
}

void append_fixing_underscores__2(system__text__String_Builder__0 *_Nonnull const builder__, string const value__)
{
	int32 underscores__ = ((int32){0});
	int32 i__ = ((int32){0});
	while (cond(int32__0op__lt(i__, string_byte_length__1(value__))))
	{
		if (cond(code_point__0op__equal(string__0__0op__element(value__, i__), ((code_point){/*_*/0x5F}))))
		{
			op__add_assign(&(underscores__), ((int32){1}));
		}
		else if (cond(int32__0op__gt(underscores__, ((int32){0}))))
		{
			if (cond(int32__0op__gte(underscores__, ((int32){2}))))
			{
				builder__->Append__1(((string){1,(uint8_t const*)"_"}));
			}

			underscores__ = ((int32){0});
		}

		builder__->Append__1(string__0new__2(string__0__0op__element(value__, i__), ((int32){1})));
		op__add_assign(&(i__), ((int32){1}));
	}
}

string convert_primitive_type_name__1(Type__0 const *_Nonnull const type__)
{
	string const name__ = unqualified_name__1(type__->name__);
	assert__2(type__->is_primitive__, name__);
	if (cond(string__0op__equal(name__, ((string){4,(uint8_t const*)"bool"}))))
	{
		return ((string){4,(uint8_t const*)"BOOL"});
	}
	else if (cond(string__0op__equal(name__, ((string){3,(uint8_t const*)"int"}))))
	{
		return ((string){5,(uint8_t const*)"int32"});
	}
	else if (cond(string__0op__equal(name__, ((string){4,(uint8_t const*)"uint"}))))
	{
		return ((string){6,(uint8_t const*)"uint32"});
	}
	else
	{
		return name__;
	}
}

system__text__String_Builder__0 *_Nonnull convert_type_name__1(Semantic_Node__0 const *_Nonnull const type_node__)
{
	assert__2(void_ptr__0op__not_equal(type_node__->referenced_type__, none), get_text__1(type_node__));
	return convert_type_name__1(type_node__->referenced_type__);
}

system__text__String_Builder__0 *_Nonnull convert_type_name__1(Type__0 const *_Nonnull const type__)
{
	return convert_type_name__2(type__, TRUE);
}

system__text__String_Builder__0 *_Nonnull convert_type_name__2(Type__0 const *_Nonnull const type__, BOOL const include_type_parameters__)
{
	system__text__String_Builder__0 *_Nonnull const cpp_type__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	if (cond(type__->is_primitive__))
	{
		cpp_type__->Append__1(convert_primitive_type_name__1(type__));
	}
	else
	{
		cpp_type__->Append__1(mangle_name__1(type__));
	}

	if (cond(bool_op(bool_arg(int32__0op__gt(type__->type_parameters__->count__, ((int32){0}))) && bool_arg(include_type_parameters__))))
	{
		convert_type_parameters__2(cpp_type__, type__);
	}

	return cpp_type__;
}

void convert_type_parameters__2(system__text__String_Builder__0 *_Nonnull const builder__, Type__0 const *_Nonnull const type__)
{
	builder__->Append__1(((string){1,(uint8_t const*)"<"}));
	BOOL first__ = TRUE;
	for (void_ptr__0iter iter = void_ptr__0iterate(type__->type_parameters__); void_ptr__0next(&iter);)
	{
		Type__0 const *_Nonnull const type_parameter__ = void_ptr__0current(&iter);
		if (cond(first__))
		{
			first__ = FALSE;
		}
		else
		{
			builder__->Append__1(((string){2,(uint8_t const*)", "}));
		}

		builder__->Append__1(convert_type__3(TRUE, type_parameter__, FALSE));
	}

	builder__->Append__1(((string){1,(uint8_t const*)">"}));
}

string convert_reference_type__3(BOOL const mutable_binding__, Type__0 const *_Nonnull type__, BOOL const nullable__)
{
	system__text__String_Builder__0 *_Nonnull const cpp_type__ = convert_type_name__1(type__);
	if (cond(BOOL__0op__not(type__->is_mutable__)))
	{
		cpp_type__->Append__1(((string){6,(uint8_t const*)" const"}));
	}

	cpp_type__->Append__1(((string){2,(uint8_t const*)" *"}));
	if (cond(nullable__))
	{
		cpp_type__->Append__1(((string){9,(uint8_t const*)"_Nullable"}));
	}
	else
	{
		cpp_type__->Append__1(((string){8,(uint8_t const*)"_Nonnull"}));
	}

	if (cond(BOOL__0op__not(mutable_binding__)))
	{
		cpp_type__->Append__1(((string){6,(uint8_t const*)" const"}));
	}

	return cpp_type__->ToString__0();
}

string convert_type__3(BOOL const mutable_binding__, Type__0 const *_Nonnull type__, BOOL const optional__)
{
	assert__1(void_ptr__0op__not_equal(type__, none));
	if (cond(bool_op(bool_arg(type__->is_primitive__) && bool_arg(string__0op__equal(unqualified_name__1(type__->name__), ((string){8,(uint8_t const*)"optional"}))))))
	{
		Type__0 const *_Nonnull const optional_type__ = system__collections__List__1__0op__element(type__->type_parameters__, ((int32){0}));
		if (cond(optional_type__->is_value_type__))
		{
			system__text__String_Builder__0 *_Nonnull const cpp_type__ = system__text__String_Builder__0__0new__1(allocate(sizeof(system__text__String_Builder__0)), ((string){11,(uint8_t const*)"p_optional<"}));
			cpp_type__->Append__1(convert_type__3(TRUE, optional_type__, TRUE));
			cpp_type__->Append__1(((string){1,(uint8_t const*)">"}));
			if (cond(bool_op(bool_arg(BOOL__0op__not(mutable_binding__)) && bool_arg(BOOL__0op__not(type__->is_mutable__)))))
			{
				cpp_type__->Append__1(((string){6,(uint8_t const*)" const"}));
			}

			return cpp_type__->ToString__0();
		}
		else
		{
			return convert_type__3(mutable_binding__, optional_type__, TRUE);
		}
	}
	else
	{
		if (cond(type__->is_value_type__))
		{
			system__text__String_Builder__0 *_Nonnull const cpp_type__ = convert_type_name__1(type__);
			if (cond(bool_op(bool_arg(BOOL__0op__not(mutable_binding__)) && bool_arg(BOOL__0op__not(type__->is_mutable__)))))
			{
				cpp_type__->Append__1(((string){6,(uint8_t const*)" const"}));
			}

			return cpp_type__->ToString__0();
		}
		else
		{
			return convert_reference_type__3(mutable_binding__, type__, optional__);
		}
	}
}

string convert_type__2(BOOL const mutable_binding__, Semantic_Node__0 const *_Nonnull const type_node__)
{
	assert__2(void_ptr__0op__not_equal(type_node__->referenced_type__, none), get_text__1(type_node__));
	return convert_type__3(mutable_binding__, type_node__->referenced_type__, FALSE);
}

string convert_parameter_list__4(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const parameters__, string const self_type__, BOOL const is_main_function__)
{
	assert__2(int32__0op__equal(parameters__->kind__, ParameterList__), string__0op__add(((string){16,(uint8_t const*)"parameters.kind="}), int_to_string__1(parameters__->kind__)));
	system__text__String_Builder__0 *_Nonnull const builder__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	builder__->Append__1(((string){1,(uint8_t const*)"("}));
	if (cond(int32__0op__gt(string_byte_length__1(self_type__), ((int32){0}))))
	{
		builder__->Append__1(self_type__);
		builder__->Append__1(((string){5,(uint8_t const*)" self"}));
	}

	BOOL first_parameter__ = int32__0op__equal(string_byte_length__1(self_type__), ((int32){0}));
	for (void_ptr__0iter iter = void_ptr__0iterate(children_of_kind__2(parameters__, Parameter__)); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const parameter__ = void_ptr__0current(&iter);
		if (cond(BOOL__0op__not(first_parameter__)))
		{
			builder__->Append__1(((string){2,(uint8_t const*)", "}));
		}
		else
		{
			first_parameter__ = FALSE;
		}

		BOOL const mutable_binding__ = node_has_child__2(parameter__, VarKeyword__);
		Semantic_Node__0 const *_Nonnull const type_node__ = system__collections__List__1__0op__element(parameter__->children__, int32__0op__sub(parameter__->children__->count__, ((int32){1})));
		builder__->Append__1(convert_type__2(mutable_binding__, type_node__));
		builder__->Append__1(((string){1,(uint8_t const*)" "}));
		builder__->Append__1(mangle_field_name__1(get_text__1(first_child__2(parameter__, Identifier__))));
		if (cond(is_main_function__))
		{
			string type_string__;
			if (cond(int32__0op__equal(type_node__->kind__, MutableType__)))
			{
				type_string__ = get_text__1(system__collections__List__1__0op__element(type_node__->children__, ((int32){0})));
			}
			else
			{
				type_string__ = get_text__1(type_node__);
			}

			if (cond(string__0op__equal(type_string__, ((string){22,(uint8_t const*)"system.console.Console"}))))
			{
				emitter__->main_function_accepts_console__ = TRUE;
			}

			if (cond(string__0op__equal(type_string__, ((string){24,(uint8_t const*)"system.console.Arguments"}))))
			{
				emitter__->main_function_accepts_args__ = TRUE;
			}
		}
	}

	builder__->Append__1(((string){1,(uint8_t const*)")"}));
	return builder__->ToString__0();
}

string convert_method_parameter_list__3(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const parameters__, string const self_type__)
{
	return convert_parameter_list__4(emitter__, parameters__, self_type__, FALSE);
}

string convert_parameter_list__3(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const parameters__, BOOL const is_main_function__)
{
	return convert_parameter_list__4(emitter__, parameters__, ((string){0,(uint8_t const*)""}), is_main_function__);
}

string convert_parameter_list__2(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const parameters__)
{
	return convert_parameter_list__4(emitter__, parameters__, ((string){0,(uint8_t const*)""}), FALSE);
}

void convert_expression__2(Semantic_Node__0 const *_Nonnull const syntax__, Source_File_Builder__0 *_Nonnull const builder__)
{
	if (cond(int32__0op__equal(syntax__->kind__, NewExpression__)))
	{
		string constructor_name__ = ((string){0,(uint8_t const*)""});
		Semantic_Node__0 const *_Nonnull type_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		if (cond(int32__0op__equal(type_node__->kind__, QualifiedName__)))
		{
			Semantic_Node__0 const *_Nonnull const name_node__ = system__collections__List__1__0op__element(type_node__->children__, ((int32){1}));
			if (cond(bool_op(bool_arg(int32__0op__equal(name_node__->kind__, IdentifierName__)) && bool_arg(void_ptr__0op__equal(name_node__->referenced_type__, none)))))
			{
				constructor_name__ = string__0op__add(((string){2,(uint8_t const*)"__"}), get_text__1(name_node__));
				type_node__ = system__collections__List__1__0op__element(type_node__->children__, ((int32){0}));
			}
		}

		Type__0 const *_Nonnull const type__ = type_node__->referenced_type__;
		assert__2(void_ptr__0op__not_equal(type__, none), get_text__1(type_node__));
		write__2(builder__, convert_type_name__2(type__, FALSE)->ToString__0());
		write__2(builder__, ((string){6,(uint8_t const*)"__0new"}));
		write__2(builder__, constructor_name__);
		write__2(builder__, ((string){2,(uint8_t const*)"__"}));
		Semantic_Node__0 const *_Nonnull const argument_list__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}));
		write__2(builder__, int_to_string__1(node_argument_count__1(argument_list__)));
		if (cond(int32__0op__gt(type__->type_parameters__->count__, ((int32){0}))))
		{
			system__text__String_Builder__0 *_Nonnull const params__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
			convert_type_parameters__2(params__, type__);
			write__2(builder__, params__->ToString__0());
		}

		if (cond(type__->is_value_type__))
		{
			convert_expression__2(argument_list__, builder__);
		}
		else
		{
			convert_reference_type_constructor_arguments__3(argument_list__, builder__, convert_type_name__1(type__)->ToString__0());
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ArgumentList__)))
	{
		write__2(builder__, ((string){1,(uint8_t const*)"("}));
		BOOL first_expression__ = TRUE;
		for (void_ptr__0iter iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
		{
			Semantic_Node__0 const *_Nonnull const arg__ = void_ptr__0current(&iter);
			if (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__not_equal(arg__->kind__, LeftParen__)) && bool_arg(int32__0op__not_equal(arg__->kind__, RightParen__)))) && bool_arg(int32__0op__not_equal(arg__->kind__, Comma__)))))
			{
				if (cond(first_expression__))
				{
					first_expression__ = FALSE;
				}
				else
				{
					write__2(builder__, ((string){2,(uint8_t const*)", "}));
				}

				convert_expression__2(arg__, builder__);
			}
		}

		write__2(builder__, ((string){1,(uint8_t const*)")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NotExpression__)))
	{
		write__2(builder__, ((string){15,(uint8_t const*)"BOOL__0op__not("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), builder__);
		write__2(builder__, ((string){1,(uint8_t const*)")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, MagnitudeExpression__)))
	{
		Semantic_Node__0 const *_Nonnull const expression_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		convert_expression__2(expression_node__, builder__);
		convert_member_access__2(expression_node__, builder__);
		write__2(builder__, ((string){15,(uint8_t const*)"op__magnitude()"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ParenthesizedExpression__)))
	{
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), builder__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NegateExpression__)))
	{
		write__2(builder__, ((string){16,(uint8_t const*)"int32__0op__neg("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){1,(uint8_t const*)")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NoneLiteralExpression__)))
	{
		write__2(builder__, ((string){4,(uint8_t const*)"none"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, SelfExpression__)))
	{
		write__2(builder__, ((string){4,(uint8_t const*)"self"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NumericLiteralExpression__)))
	{
		write__2(builder__, string__0op__add(string__0op__add(((string){9,(uint8_t const*)"((int32){"}), get_text__1(syntax__)), ((string){2,(uint8_t const*)"})"})));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, TrueLiteralExpression__)))
	{
		write__2(builder__, ((string){4,(uint8_t const*)"TRUE"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, FalseLiteralExpression__)))
	{
		write__2(builder__, ((string){5,(uint8_t const*)"FALSE"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, CodePointLiteralExpression__)))
	{
		string const raw_value__ = get_text__1(syntax__);
		code_point const code_point_value__ = code_point_literal_value__1(raw_value__);
		write__2(builder__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){16,(uint8_t const*)"((code_point){/*"}), substring__3(raw_value__, ((int32){1}), int32__0op__sub(string_byte_length__1(raw_value__), ((int32){2})))), ((string){4,(uint8_t const*)"*/0x"})), int_to_hex_string__1(code_point_as_int__1(code_point_value__))), ((string){2,(uint8_t const*)"})"})));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, IdentifierName__)))
	{
		write__2(builder__, mangle_field_name__1(get_text__1(syntax__)));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, StringLiteralExpression__)))
	{
		string const value__ = get_text__1(syntax__);
		write__2(builder__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){10,(uint8_t const*)"((string){"}), int_to_string__1(literal_length__1(value__))), ((string){17,(uint8_t const*)",(uint8_t const*)"})), value__), ((string){2,(uint8_t const*)"})"})));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, AssignmentExpression__)))
	{
		int32 const operator__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}))->kind__;
		if (cond(int32__0op__equal(operator__, Equals__)))
		{
			convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
			write__2(builder__, ((string){1,(uint8_t const*)" "}));
			write__2(builder__, get_text__1(system__collections__List__1__0op__element(syntax__->children__, ((int32){1}))));
			write__2(builder__, ((string){1,(uint8_t const*)" "}));
			convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), builder__);
		}
		else
		{
			write__2(builder__, ((string){4,(uint8_t const*)"op__"}));
			if (cond(int32__0op__equal(operator__, PlusEquals__)))
			{
				write__2(builder__, ((string){10,(uint8_t const*)"add_assign"}));
			}
			else if (cond(int32__0op__equal(operator__, MinusEquals__)))
			{
				write__2(builder__, ((string){10,(uint8_t const*)"sub_assign"}));
			}
			else
			{
				error__2(builder__, string__0op__add(((string){32,(uint8_t const*)"Unsupported assignment operator "}), int_to_string__1(operator__)));
			}

			write__2(builder__, ((string){3,(uint8_t const*)"(&("}));
			convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
			write__2(builder__, ((string){3,(uint8_t const*)"), "}));
			convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), builder__);
			write__2(builder__, ((string){1,(uint8_t const*)")"}));
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, EqualExpression__)))
	{
		Semantic_Node__0 const *_Nonnull const lhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		Semantic_Node__0 const *_Nonnull const rhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){2}));
		Type__0 const *_Nonnull type__ = lhs_node__->of_type__;
		if (cond(void_ptr__0op__equal(type__, none)))
		{
			type__ = rhs_node__->of_type__;
		}

		if (cond(void_ptr__0op__not_equal(type__, none)))
		{
			if (cond(bool_op(bool_arg(type__->is_primitive__) && bool_arg(string__0op__equal(unqualified_name__1(type__->name__), ((string){8,(uint8_t const*)"optional"}))))))
			{
				type__ = system__collections__List__1__0op__element(type__->type_parameters__, ((int32){0}));
			}

			if (cond(type__->is_primitive__))
			{
				write__2(builder__, convert_primitive_type_name__1(type__));
			}
			else
			{
				write__2(builder__, ((string){8,(uint8_t const*)"void_ptr"}));
			}

			write__2(builder__, ((string){13,(uint8_t const*)"__0op__equal("}));
		}
		else
		{
			write__2(builder__, ((string){18,(uint8_t const*)"int32__0op__equal("}));
		}

		convert_expression__2(lhs_node__, builder__);
		write__2(builder__, ((string){2,(uint8_t const*)", "}));
		convert_expression__2(rhs_node__, builder__);
		write__2(builder__, ((string){1,(uint8_t const*)")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NotEqualExpression__)))
	{
		Semantic_Node__0 const *_Nonnull const lhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		Semantic_Node__0 const *_Nonnull const rhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){2}));
		Type__0 const *_Nonnull type__ = lhs_node__->of_type__;
		if (cond(void_ptr__0op__equal(type__, none)))
		{
			type__ = rhs_node__->of_type__;
		}

		if (cond(void_ptr__0op__not_equal(type__, none)))
		{
			if (cond(bool_op(bool_arg(type__->is_primitive__) && bool_arg(string__0op__equal(unqualified_name__1(type__->name__), ((string){8,(uint8_t const*)"optional"}))))))
			{
				type__ = system__collections__List__1__0op__element(type__->type_parameters__, ((int32){0}));
			}

			if (cond(type__->is_primitive__))
			{
				write__2(builder__, convert_primitive_type_name__1(type__));
			}
			else
			{
				write__2(builder__, ((string){8,(uint8_t const*)"void_ptr"}));
			}

			write__2(builder__, ((string){17,(uint8_t const*)"__0op__not_equal("}));
		}
		else
		{
			write__2(builder__, ((string){22,(uint8_t const*)"int32__0op__not_equal("}));
		}

		convert_expression__2(lhs_node__, builder__);
		write__2(builder__, ((string){2,(uint8_t const*)", "}));
		convert_expression__2(rhs_node__, builder__);
		write__2(builder__, ((string){1,(uint8_t const*)")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ComparisonExpression__)))
	{
		int32 const operator__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}))->kind__;
		Type__0 const *_Nonnull const type__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}))->of_type__;
		if (cond(void_ptr__0op__not_equal(type__, none)))
		{
			write__2(builder__, convert_primitive_type_name__1(type__));
		}
		else
		{
			write__2(builder__, ((string){5,(uint8_t const*)"int32"}));
		}

		if (cond(int32__0op__equal(operator__, LessThan__)))
		{
			write__2(builder__, ((string){9,(uint8_t const*)"__0op__lt"}));
		}
		else if (cond(int32__0op__equal(operator__, LessThanEquals__)))
		{
			write__2(builder__, ((string){10,(uint8_t const*)"__0op__lte"}));
		}
		else if (cond(int32__0op__equal(operator__, GreaterThan__)))
		{
			write__2(builder__, ((string){9,(uint8_t const*)"__0op__gt"}));
		}
		else if (cond(int32__0op__equal(operator__, GreaterThanEquals__)))
		{
			write__2(builder__, ((string){10,(uint8_t const*)"__0op__gte"}));
		}
		else
		{
			error__2(builder__, string__0op__add(((string){32,(uint8_t const*)"Unsupported comparison operator "}), int_to_string__1(operator__)));
		}

		write__2(builder__, ((string){1,(uint8_t const*)"("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){2,(uint8_t const*)", "}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), builder__);
		write__2(builder__, ((string){1,(uint8_t const*)")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, AddExpression__)))
	{
		Semantic_Node__0 const *_Nonnull const lhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		Semantic_Node__0 const *_Nonnull const rhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}));
		Type__0 const *_Nonnull type__ = lhs_node__->of_type__;
		if (cond(void_ptr__0op__equal(type__, none)))
		{
			void_ptr__0op__equal(type__, rhs_node__->of_type__);
		}

		if (cond(void_ptr__0op__not_equal(type__, none)))
		{
			write__2(builder__, convert_primitive_type_name__1(type__));
		}
		else
		{
			write__2(builder__, ((string){6,(uint8_t const*)"string"}));
		}

		write__2(builder__, ((string){11,(uint8_t const*)"__0op__add("}));
		convert_expression__2(lhs_node__, builder__);
		write__2(builder__, ((string){2,(uint8_t const*)", "}));
		convert_expression__2(rhs_node__, builder__);
		write__2(builder__, ((string){1,(uint8_t const*)")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, SubtractExpression__)))
	{
		Semantic_Node__0 const *_Nonnull const lhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		Semantic_Node__0 const *_Nonnull const rhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}));
		write__2(builder__, ((string){16,(uint8_t const*)"int32__0op__sub("}));
		convert_expression__2(lhs_node__, builder__);
		write__2(builder__, ((string){2,(uint8_t const*)", "}));
		convert_expression__2(rhs_node__, builder__);
		write__2(builder__, ((string){1,(uint8_t const*)")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, MultiplyExpression__)))
	{
		write__2(builder__, ((string){16,(uint8_t const*)"int32__0op__mul("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){2,(uint8_t const*)", "}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), builder__);
		write__2(builder__, ((string){1,(uint8_t const*)")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, DivideExpression__)))
	{
		write__2(builder__, ((string){16,(uint8_t const*)"int32__0op__div("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){2,(uint8_t const*)", "}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), builder__);
		write__2(builder__, ((string){1,(uint8_t const*)")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, RemainderExpression__)))
	{
		write__2(builder__, ((string){22,(uint8_t const*)"int32__0op__remainder("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){2,(uint8_t const*)", "}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), builder__);
		write__2(builder__, ((string){1,(uint8_t const*)")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, OrExpression__)))
	{
		write__2(builder__, ((string){17,(uint8_t const*)"bool_op(bool_arg("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){14,(uint8_t const*)") || bool_arg("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), builder__);
		write__2(builder__, ((string){2,(uint8_t const*)"))"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, AndExpression__)))
	{
		write__2(builder__, ((string){17,(uint8_t const*)"bool_op(bool_arg("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){14,(uint8_t const*)") && bool_arg("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), builder__);
		write__2(builder__, ((string){2,(uint8_t const*)"))"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, InvocationExpression__)))
	{
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		Semantic_Node__0 const *_Nonnull const parameters_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}));
		write__2(builder__, int_to_string__1(node_argument_count__1(parameters_node__)));
		convert_expression__2(parameters_node__, builder__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, MemberAccessExpression__)))
	{
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		convert_member_access__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), builder__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ElementAccessExpression__)))
	{
		Type__0 const *_Nonnull type__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}))->of_type__;
		if (cond(void_ptr__0op__not_equal(type__, none)))
		{
			write__2(builder__, mangle_name__1(type__));
			write__2(builder__, ((string){3,(uint8_t const*)"__0"}));
		}
		else
		{
			write__2(builder__, ((string){31,(uint8_t const*)"system__collections__List__1__0"}));
		}

		write__2(builder__, ((string){12,(uint8_t const*)"op__element("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){2,(uint8_t const*)", "}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), builder__);
		write__2(builder__, ((string){1,(uint8_t const*)")"}));
	}
	else
	{
		error__2(builder__, string__0op__add(((string){37,(uint8_t const*)"Could not convert expression of type "}), int_to_string__1(syntax__->kind__)));
	}
}

int32 literal_length__1(string const value__)
{
	int32 length__ = int32__0op__sub(string_byte_length__1(value__), ((int32){2}));
	BOOL escaped__ = FALSE;
	int32 i__ = ((int32){0});
	while (cond(int32__0op__lt(i__, string_byte_length__1(value__))))
	{
		if (cond(bool_op(bool_arg(code_point__0op__equal(string__0__0op__element(value__, i__), ((code_point){/*\\*/0x5C}))) && bool_arg(BOOL__0op__not(escaped__)))))
		{
			escaped__ = TRUE;
			op__sub_assign(&(length__), ((int32){1}));
		}
		else
		{
			escaped__ = FALSE;
		}

		op__add_assign(&(i__), ((int32){1}));
	}

	return length__;
}

code_point code_point_literal_value__1(string const value__)
{
	int32 const length__ = string_byte_length__1(value__);
	if (cond(int32__0op__equal(length__, ((int32){3}))))
	{
		return string__0__0op__element(value__, ((int32){1}));
	}
	else if (cond(int32__0op__equal(length__, ((int32){4}))))
	{
		if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"'\\\"'"}))))
		{
			return ((code_point){/*\"*/0x22});
		}
		else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"'\\\\'"}))))
		{
			return ((code_point){/*\\*/0x5C});
		}
		else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"'\\''"}))))
		{
			return ((code_point){/*\'*/0x27});
		}
		else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"'\\n'"}))))
		{
			return ((code_point){/*\n*/0xA});
		}
		else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"'\\r'"}))))
		{
			return ((code_point){/*\r*/0xD});
		}
		else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"'\\0'"}))))
		{
			return ((code_point){/*\0*/0x0});
		}
		else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"'\\b'"}))))
		{
			return ((code_point){/*\b*/0x8});
		}
		else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"'\\f'"}))))
		{
			return ((code_point){/*\f*/0xC});
		}
		else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"'\\t'"}))))
		{
			return ((code_point){/*\t*/0x9});
		}
		else if (cond(string__0op__equal(value__, ((string){4,(uint8_t const*)"'\\b'"}))))
		{
			return ((code_point){/*\b*/0x8});
		}
		else
		{
			assert__2(FALSE, string__0op__add(((string){39,(uint8_t const*)"Unsupported code_point escape sequence "}), value__));
		}
	}
	else if (cond(int32__0op__equal(length__, ((int32){6}))))
	{
		if (cond(string__0op__not_equal(substring__3(value__, ((int32){0}), ((int32){3})), ((string){3,(uint8_t const*)"'\\x"}))))
		{
			assert__2(FALSE, string__0op__add(((string){39,(uint8_t const*)"Unsupported code_point escape sequence "}), value__));
		}
		else
		{
			return int_to_code_point__1(hex_string_to_int__1(substring__3(value__, ((int32){3}), ((int32){2}))));
		}
	}
	else
	{
		assert__2(FALSE, string__0op__add(((string){39,(uint8_t const*)"Unsupported code_point escape sequence "}), value__));
	}

	UNREACHABLE__0();
}

void convert_reference_type_constructor_arguments__3(Semantic_Node__0 const *_Nonnull const syntax__, Source_File_Builder__0 *_Nonnull const builder__, string const type_name__)
{
	assert__1(int32__0op__equal(syntax__->kind__, ArgumentList__));
	write__2(builder__, ((string){17,(uint8_t const*)"(allocate(sizeof("}));
	write__2(builder__, type_name__);
	write__2(builder__, ((string){2,(uint8_t const*)"))"}));
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const arg__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__not_equal(arg__->kind__, LeftParen__)) && bool_arg(int32__0op__not_equal(arg__->kind__, RightParen__)))) && bool_arg(int32__0op__not_equal(arg__->kind__, Comma__)))))
		{
			write__2(builder__, ((string){2,(uint8_t const*)", "}));
			convert_expression__2(arg__, builder__);
		}
	}

	write__2(builder__, ((string){1,(uint8_t const*)")"}));
}

void convert_member_access__2(Semantic_Node__0 const *_Nonnull const lhs__, Source_File_Builder__0 *_Nonnull const builder__)
{
	Type__0 const *_Nullable const type__ = lhs__->of_type__;
	if (cond(bool_op(bool_arg(bool_op(bool_arg(void_ptr__0op__not_equal(type__, none)) && bool_arg(type__->is_value_type__))) && bool_arg(BOOL__0op__not(bool_op(bool_arg(bool_op(bool_arg(type__->is_primitive__) && bool_arg(string__0op__equal(unqualified_name__1(type__->name__), ((string){8,(uint8_t const*)"optional"}))))) && bool_arg(BOOL__0op__not(system__collections__List__1__0op__element(type__->type_parameters__, ((int32){0}))->is_value_type__))))))))
	{
		write__2(builder__, ((string){1,(uint8_t const*)"."}));
	}
	else
	{
		write__2(builder__, ((string){2,(uint8_t const*)"->"}));
	}
}

void emit_statement__2(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const statement__)
{
	statement_separator_line__1(emitter__->definitions__);
	if (cond(int32__0op__equal(statement__->kind__, ReturnStatement__)))
	{
		if (cond(int32__0op__equal(statement__->children__->count__, ((int32){2}))))
		{
			write_line__2(emitter__->definitions__, ((string){7,(uint8_t const*)"return;"}));
		}
		else
		{
			begin_line__2(emitter__->definitions__, ((string){7,(uint8_t const*)"return "}));
			convert_expression__2(system__collections__List__1__0op__element(statement__->children__, ((int32){1})), emitter__->definitions__);
			end_line__2(emitter__->definitions__, ((string){1,(uint8_t const*)";"}));
		}
	}
	else if (cond(int32__0op__equal(statement__->kind__, LoopStatement__)))
	{
		write_line__2(emitter__->definitions__, ((string){8,(uint8_t const*)"for (;;)"}));
		emit_statement__2(emitter__, system__collections__List__1__0op__element(statement__->children__, ((int32){1})));
	}
	else if (cond(int32__0op__equal(statement__->kind__, Block__)))
	{
		begin_block__1(emitter__->definitions__);
		for (void_ptr__0iter iter = void_ptr__0iterate(node_statements__1(statement__)); void_ptr__0next(&iter);)
		{
			Semantic_Node__0 const *_Nonnull const block_statement__ = void_ptr__0current(&iter);
			emit_statement__2(emitter__, block_statement__);
		}

		end_block__1(emitter__->definitions__);
	}
	else if (cond(int32__0op__equal(statement__->kind__, WhileStatement__)))
	{
		begin_line__2(emitter__->definitions__, ((string){12,(uint8_t const*)"while (cond("}));
		convert_expression__2(system__collections__List__1__0op__element(statement__->children__, ((int32){1})), emitter__->definitions__);
		end_line__2(emitter__->definitions__, ((string){2,(uint8_t const*)"))"}));
		emit_statement__2(emitter__, system__collections__List__1__0op__element(statement__->children__, ((int32){2})));
	}
	else if (cond(int32__0op__equal(statement__->kind__, ForStatement__)))
	{
		Semantic_Node__0 const *_Nonnull const variable_declaration__ = first_child__2(statement__, VariableDeclaration__);
		BOOL const mutable_binding__ = node_has_child__2(variable_declaration__, VarKeyword__);
		string const variable_name__ = get_text__1(first_child__2(variable_declaration__, Identifier__));
		Semantic_Node__0 const *_Nonnull const variable_type_node__ = system__collections__List__1__0op__element(variable_declaration__->children__, ((int32){2}));
		Semantic_Node__0 const *_Nonnull const iterator_expression__ = system__collections__List__1__0op__element(statement__->children__, ((int32){3}));
		Type__0 const *_Nonnull const iterator_over_type__ = variable_type_node__->referenced_type__;
		assert__2(void_ptr__0op__not_equal(iterator_over_type__, none), get_text__1(variable_type_node__));
		string iterator_type__;
		if (cond(iterator_over_type__->is_primitive__))
		{
			iterator_type__ = convert_primitive_type_name__1(iterator_over_type__);
		}
		else
		{
			iterator_type__ = ((string){8,(uint8_t const*)"void_ptr"});
		}

		Type__0 const *_Nonnull const collection_type__ = iterator_expression__->of_type__;
		string iteratable_type__;
		if (cond(void_ptr__0op__not_equal(collection_type__, none)))
		{
			iteratable_type__ = mangle_name__1(collection_type__);
		}
		else
		{
			iteratable_type__ = iterator_type__;
		}

		begin_line__2(emitter__->definitions__, ((string){5,(uint8_t const*)"for ("}));
		write__2(emitter__->definitions__, iterator_type__);
		write__2(emitter__->definitions__, ((string){15,(uint8_t const*)"__0iter iter = "}));
		write__2(emitter__->definitions__, iteratable_type__);
		write__2(emitter__->definitions__, ((string){11,(uint8_t const*)"__0iterate("}));
		convert_expression__2(iterator_expression__, emitter__->definitions__);
		write__2(emitter__->definitions__, ((string){3,(uint8_t const*)"); "}));
		write__2(emitter__->definitions__, iterator_type__);
		end_line__2(emitter__->definitions__, ((string){16,(uint8_t const*)"__0next(&iter);)"}));
		begin_block__1(emitter__->definitions__);
		begin_line__2(emitter__->definitions__, ((string){0,(uint8_t const*)""}));
		write__2(emitter__->definitions__, convert_type__2(mutable_binding__, variable_type_node__));
		write__2(emitter__->definitions__, ((string){1,(uint8_t const*)" "}));
		write__2(emitter__->definitions__, mangle_field_name__1(variable_name__));
		write__2(emitter__->definitions__, ((string){3,(uint8_t const*)" = "}));
		write__2(emitter__->definitions__, iterator_type__);
		end_line__2(emitter__->definitions__, ((string){18,(uint8_t const*)"__0current(&iter);"}));
		Semantic_Node__0 const *_Nonnull const for_loop_body__ = system__collections__List__1__0op__element(statement__->children__, ((int32){4}));
		for (void_ptr__0iter iter = void_ptr__0iterate(node_statements__1(for_loop_body__)); void_ptr__0next(&iter);)
		{
			Semantic_Node__0 const *_Nonnull const block_statement__ = void_ptr__0current(&iter);
			emit_statement__2(emitter__, block_statement__);
		}

		end_block__1(emitter__->definitions__);
	}
	else if (cond(int32__0op__equal(statement__->kind__, DoWhileStatement__)))
	{
		write_line__2(emitter__->definitions__, ((string){2,(uint8_t const*)"do"}));
		emit_statement__2(emitter__, system__collections__List__1__0op__element(statement__->children__, ((int32){1})));
		begin_line__2(emitter__->definitions__, ((string){12,(uint8_t const*)"while (cond("}));
		convert_expression__2(system__collections__List__1__0op__element(statement__->children__, ((int32){3})), emitter__->definitions__);
		end_line__2(emitter__->definitions__, ((string){3,(uint8_t const*)"));"}));
	}
	else if (cond(int32__0op__equal(statement__->kind__, IfStatement__)))
	{
		Semantic_Node__0 const *_Nullable if_statement__ = statement__;
		begin_line__2(emitter__->definitions__, ((string){0,(uint8_t const*)""}));
		for (;;)
		{
			write__2(emitter__->definitions__, ((string){9,(uint8_t const*)"if (cond("}));
			convert_expression__2(system__collections__List__1__0op__element(if_statement__->children__, ((int32){1})), emitter__->definitions__);
			end_line__2(emitter__->definitions__, ((string){2,(uint8_t const*)"))"}));
			emit_statement__2(emitter__, system__collections__List__1__0op__element(if_statement__->children__, ((int32){2})));
			Semantic_Node__0 const *_Nullable const elseClause__ = first_child__2(if_statement__, ElseClause__);
			if (cond(void_ptr__0op__not_equal(elseClause__, none)))
			{
				if_statement__ = first_child__2(elseClause__, IfStatement__);
				if (cond(void_ptr__0op__not_equal(if_statement__, none)))
				{
					begin_line__2(emitter__->definitions__, ((string){5,(uint8_t const*)"else "}));
				}
				else
				{
					write_line__2(emitter__->definitions__, ((string){4,(uint8_t const*)"else"}));
					emit_statement__2(emitter__, system__collections__List__1__0op__element(elseClause__->children__, ((int32){1})));
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	else if (cond(int32__0op__equal(statement__->kind__, BreakStatement__)))
	{
		write_line__2(emitter__->definitions__, ((string){6,(uint8_t const*)"break;"}));
	}
	else if (cond(int32__0op__equal(statement__->kind__, ContinueStatement__)))
	{
		write_line__2(emitter__->definitions__, ((string){9,(uint8_t const*)"continue;"}));
	}
	else if (cond(int32__0op__equal(statement__->kind__, LocalDeclarationStatement__)))
	{
		Semantic_Node__0 const *_Nonnull const variable_declaration__ = first_child__2(statement__, VariableDeclaration__);
		string const variable_name__ = get_text__1(first_child__2(variable_declaration__, Identifier__));
		Semantic_Node__0 const *_Nonnull const variable_type__ = system__collections__List__1__0op__element(variable_declaration__->children__, ((int32){2}));
		BOOL const mutable_binding__ = node_has_child__2(variable_declaration__, VarKeyword__);
		begin_line__2(emitter__->definitions__, convert_type__2(mutable_binding__, variable_type__));
		write__2(emitter__->definitions__, string__0op__add(((string){1,(uint8_t const*)" "}), mangle_field_name__1(variable_name__)));
		if (cond(int32__0op__gt(variable_declaration__->children__->count__, ((int32){3}))))
		{
			write__2(emitter__->definitions__, ((string){3,(uint8_t const*)" = "}));
			convert_expression__2(system__collections__List__1__0op__element(variable_declaration__->children__, ((int32){3})), emitter__->definitions__);
		}

		end_line__2(emitter__->definitions__, ((string){1,(uint8_t const*)";"}));
	}
	else if (cond(int32__0op__equal(statement__->kind__, ExpressionStatement__)))
	{
		begin_line__2(emitter__->definitions__, ((string){0,(uint8_t const*)""}));
		convert_expression__2(system__collections__List__1__0op__element(statement__->children__, ((int32){0})), emitter__->definitions__);
		end_line__2(emitter__->definitions__, ((string){1,(uint8_t const*)";"}));
	}
	else
	{
		NOT_IMPLEMENTED__1(string__0op__add(((string){15,(uint8_t const*)"statement.kind="}), int_to_string__1(statement__->kind__)));
	}
}

void emit_method_body__3(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const block__, BOOL const is_associated_function__)
{
	begin_block__1(emitter__->definitions__);
	if (cond(BOOL__0op__not(is_associated_function__)))
	{
		write_line__2(emitter__->definitions__, ((string){17,(uint8_t const*)"auto self = this;"}));
	}

	for (void_ptr__0iter iter = void_ptr__0iterate(node_statements__1(block__)); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const statement__ = void_ptr__0current(&iter);
		emit_statement__2(emitter__, statement__);
	}

	end_block__1(emitter__->definitions__);
}

void emit_constructor_body__4(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const block__, string const self_type__, BOOL const is_value_type__)
{
	begin_block__1(emitter__->definitions__);
	if (cond(is_value_type__))
	{
		write_line__2(emitter__->definitions__, string__0op__add(self_type__, ((string){6,(uint8_t const*)" self;"})));
	}

	for (void_ptr__0iter iter = void_ptr__0iterate(node_statements__1(block__)); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const statement__ = void_ptr__0current(&iter);
		emit_statement__2(emitter__, statement__);
	}

	write_line__2(emitter__->definitions__, ((string){12,(uint8_t const*)"return self;"}));
	end_block__1(emitter__->definitions__);
}

void emit_member_declaration__4(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const member__, string const class_name__, BOOL const is_value_type__)
{
	if (cond(int32__0op__equal(member__->kind__, ConstructorDeclaration__)))
	{
		Semantic_Node__0 const *_Nonnull const parameters_node__ = first_child__2(member__, ParameterList__);
		string new_function_name__ = string__0op__add(((string){4,(uint8_t const*)"new_"}), class_name__);
		string constructor_full_name__ = string__0op__add(class_name__, ((string){8,(uint8_t const*)"__0new__"}));
		Semantic_Node__0 const *_Nullable const constructor_name_node__ = first_child__2(member__, Identifier__);
		if (cond(void_ptr__0op__not_equal(constructor_name_node__, none)))
		{
			string const constructor_name__ = get_text__1(constructor_name_node__);
			new_function_name__ = string__0op__add(string__0op__add(new_function_name__, ((string){2,(uint8_t const*)"__"})), constructor_name__);
			constructor_full_name__ = string__0op__add(string__0op__add(constructor_full_name__, constructor_name__), ((string){2,(uint8_t const*)"__"}));
		}

		constructor_full_name__ = string__0op__add(constructor_full_name__, int_to_string__1(parameters_node__->children__->count__));
		string return_type__ = class_name__;
		if (cond(BOOL__0op__not(is_value_type__)))
		{
			return_type__ = string__0op__add(return_type__, ((string){10,(uint8_t const*)" *_Nonnull"}));
		}

		string constructor_parameters__;
		if (cond(BOOL__0op__not(is_value_type__)))
		{
			constructor_parameters__ = convert_method_parameter_list__3(emitter__, parameters_node__, return_type__);
		}
		else
		{
			constructor_parameters__ = convert_parameter_list__2(emitter__, parameters_node__);
		}

		string constructor_signature__ = string__0op__add(string__0op__add(string__0op__add(return_type__, ((string){1,(uint8_t const*)" "})), constructor_full_name__), constructor_parameters__);
		write_line__2(emitter__->function_declarations__, string__0op__add(constructor_signature__, ((string){1,(uint8_t const*)";"})));
		element_separator_line__1(emitter__->definitions__);
		write_line__2(emitter__->definitions__, constructor_signature__);
		emit_constructor_body__4(emitter__, first_child__2(member__, Block__), return_type__, is_value_type__);
	}
	else if (cond(int32__0op__equal(member__->kind__, FieldDeclaration__)))
	{
		Semantic_Node__0 const *_Nonnull const variable_declaration__ = first_child__2(member__, VariableDeclaration__);
		string const field_name__ = get_text__1(first_child__2(variable_declaration__, Identifier__));
		Semantic_Node__0 const *_Nonnull const field_type__ = system__collections__List__1__0op__element(variable_declaration__->children__, ((int32){2}));
		string const cpp_type__ = convert_type__2(TRUE, field_type__);
		write_line__2(emitter__->class_declarations__, string__0op__add(string__0op__add(string__0op__add(cpp_type__, ((string){1,(uint8_t const*)" "})), mangle_field_name__1(field_name__)), ((string){1,(uint8_t const*)";"})));
	}
	else if (cond(int32__0op__equal(member__->kind__, MethodDeclaration__)))
	{
		Semantic_Node__0 const *_Nonnull const parameters_node__ = first_child__2(member__, ParameterList__);
		Semantic_Node__0 const *_Nullable const self_parameter__ = first_child__2(parameters_node__, SelfParameter__);
		int32 parameter_count__ = parameters_node__->children__->count__;
		if (cond(void_ptr__0op__not_equal(self_parameter__, none)))
		{
			op__sub_assign(&(parameter_count__), ((int32){1}));
		}

		string const method_name__ = mangle_function_name__2(get_text__1(first_child__2(member__, Identifier__)), parameter_count__);
		string const parameters__ = convert_parameter_list__2(emitter__, parameters_node__);
		BOOL const is_associated_function__ = void_ptr__0op__equal(self_parameter__, none);
		BOOL const mutable_self__ = bool_op(bool_arg(BOOL__0op__not(is_associated_function__)) && bool_arg(node_has_child__2(self_parameter__, MutableKeyword__)));
		Semantic_Node__0 const *_Nonnull const return_type_node__ = system__collections__List__1__0op__element(member__->children__, ((int32){3}));
		string const cpp_type__ = convert_type__2(TRUE, return_type_node__);
		string static_modifier__ = ((string){0,(uint8_t const*)""});
		if (cond(is_associated_function__))
		{
			static_modifier__ = ((string){7,(uint8_t const*)"static "});
		}

		string constModifier__ = ((string){0,(uint8_t const*)""});
		if (cond(bool_op(bool_arg(BOOL__0op__not(mutable_self__)) && bool_arg(BOOL__0op__not(is_associated_function__)))))
		{
			constModifier__ = ((string){6,(uint8_t const*)" const"});
		}

		write_line__2(emitter__->class_declarations__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(static_modifier__, cpp_type__), ((string){1,(uint8_t const*)" "})), method_name__), parameters__), constModifier__), ((string){1,(uint8_t const*)";"})));
		element_separator_line__1(emitter__->definitions__);
		write_line__2(emitter__->definitions__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(cpp_type__, ((string){1,(uint8_t const*)" "})), class_name__), ((string){2,(uint8_t const*)"::"})), method_name__), parameters__), constModifier__));
		Semantic_Node__0 const *_Nonnull const block__ = first_child__2(member__, Block__);
		emit_method_body__3(emitter__, block__, is_associated_function__);
	}
	else
	{
		error__2(emitter__->definitions__, string__0op__add(((string){30,(uint8_t const*)"Could not emit member of type "}), int_to_string__1(member__->kind__)));
	}
}

void emit_default_constructor__3(Emitter__0 *_Nonnull const emitter__, string const type_name__, BOOL const is_value_type__)
{
	string const default_constructor_name__ = string__0op__add(type_name__, ((string){9,(uint8_t const*)"__0new__0"}));
	string return_type__ = type_name__;
	if (cond(BOOL__0op__not(is_value_type__)))
	{
		return_type__ = string__0op__add(return_type__, ((string){10,(uint8_t const*)" *_Nonnull"}));
	}

	string constructor_signature__ = string__0op__add(string__0op__add(string__0op__add(return_type__, ((string){1,(uint8_t const*)" "})), default_constructor_name__), ((string){1,(uint8_t const*)"("}));
	if (cond(BOOL__0op__not(is_value_type__)))
	{
		constructor_signature__ = string__0op__add(string__0op__add(constructor_signature__, return_type__), ((string){5,(uint8_t const*)" self"}));
	}

	constructor_signature__ = string__0op__add(constructor_signature__, ((string){1,(uint8_t const*)")"}));
	write_line__2(emitter__->function_declarations__, string__0op__add(constructor_signature__, ((string){1,(uint8_t const*)";"})));
	element_separator_line__1(emitter__->definitions__);
	begin_line__2(emitter__->definitions__, constructor_signature__);
	if (cond(is_value_type__))
	{
		end_line__2(emitter__->definitions__, ((string){15,(uint8_t const*)" { return {}; }"}));
	}
	else
	{
		end_line__2(emitter__->definitions__, ((string){17,(uint8_t const*)" { return self; }"}));
	}
}

void emit_declaration__2(Emitter__0 *_Nonnull const emitter__, Semantic_Node__0 const *_Nonnull const declaration__)
{
	if (cond(int32__0op__equal(declaration__->kind__, GlobalDeclaration__)))
	{
		Semantic_Node__0 const *_Nonnull const variable_declaration__ = first_child__2(declaration__, VariableDeclaration__);
		string const variable_name__ = get_text__1(first_child__2(variable_declaration__, Identifier__));
		Semantic_Node__0 const *_Nonnull const variable_type__ = system__collections__List__1__0op__element(variable_declaration__->children__, ((int32){2}));
		BOOL const mutable_binding__ = node_has_child__2(variable_declaration__, VarKeyword__);
		string const cpp_type__ = convert_type__2(mutable_binding__, variable_type__);
		begin_line__2(emitter__->global_definitions__, cpp_type__);
		write__2(emitter__->global_definitions__, string__0op__add(string__0op__add(((string){1,(uint8_t const*)" "}), mangle_field_name__1(variable_name__)), ((string){3,(uint8_t const*)" = "})));
		Semantic_Node__0 const *_Nonnull const expression__ = system__collections__List__1__0op__element(variable_declaration__->children__, ((int32){3}));
		convert_expression__2(expression__, emitter__->global_definitions__);
		end_line__2(emitter__->global_definitions__, ((string){1,(uint8_t const*)";"}));
	}
	else if (cond(int32__0op__equal(declaration__->kind__, ClassDeclaration__)))
	{
		Type__0 const *_Nonnull const declared_type__ = declaration__->declares_type__;
		assert__2(void_ptr__0op__not_equal(declared_type__, none), get_text__1(first_child__2(declaration__, Identifier__)));
		string const class_name__ = mangle_name__1(declared_type__);
		write_line__2(emitter__->type_declarations__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){15,(uint8_t const*)"typedef struct "}), class_name__), ((string){1,(uint8_t const*)" "})), class_name__), ((string){1,(uint8_t const*)";"})));
		element_separator_line__1(emitter__->class_declarations__);
		write_line__2(emitter__->class_declarations__, string__0op__add(((string){7,(uint8_t const*)"struct "}), class_name__));
		begin_block__1(emitter__->class_declarations__);
		BOOL has_constructors__ = FALSE;
		for (void_ptr__0iter iter = void_ptr__0iterate(node_members__1(declaration__)); void_ptr__0next(&iter);)
		{
			Semantic_Node__0 const *_Nonnull const member__ = void_ptr__0current(&iter);
			has_constructors__ = bool_op(bool_arg(has_constructors__) || bool_arg(int32__0op__equal(member__->kind__, ConstructorDeclaration__)));
			emit_member_declaration__4(emitter__, member__, class_name__, FALSE);
		}

		if (cond(BOOL__0op__not(has_constructors__)))
		{
			emit_default_constructor__3(emitter__, class_name__, FALSE);
		}

		end_block_with_semicolon__1(emitter__->class_declarations__);
	}
	else if (cond(int32__0op__equal(declaration__->kind__, StructDeclaration__)))
	{
		Type__0 const *_Nonnull const declared_type__ = declaration__->declares_type__;
		assert__2(void_ptr__0op__not_equal(declared_type__, none), get_text__1(first_child__2(declaration__, Identifier__)));
		string const struct_name__ = mangle_name__1(declared_type__);
		write_line__2(emitter__->type_declarations__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){15,(uint8_t const*)"typedef struct "}), struct_name__), ((string){1,(uint8_t const*)" "})), struct_name__), ((string){1,(uint8_t const*)";"})));
		element_separator_line__1(emitter__->class_declarations__);
		write_line__2(emitter__->class_declarations__, string__0op__add(((string){7,(uint8_t const*)"struct "}), struct_name__));
		begin_block__1(emitter__->class_declarations__);
		BOOL has_constructors__ = FALSE;
		for (void_ptr__0iter iter = void_ptr__0iterate(node_members__1(declaration__)); void_ptr__0next(&iter);)
		{
			Semantic_Node__0 const *_Nonnull const member__ = void_ptr__0current(&iter);
			has_constructors__ = bool_op(bool_arg(has_constructors__) || bool_arg(int32__0op__equal(member__->kind__, ConstructorDeclaration__)));
			emit_member_declaration__4(emitter__, member__, struct_name__, TRUE);
		}

		if (cond(BOOL__0op__not(has_constructors__)))
		{
			emit_default_constructor__3(emitter__, struct_name__, TRUE);
		}

		end_block_with_semicolon__1(emitter__->class_declarations__);
	}
	else if (cond(int32__0op__equal(declaration__->kind__, EnumDeclaration__)))
	{
		string const enum_name__ = get_text__1(first_child__2(declaration__, Identifier__));
		write_line__2(emitter__->type_declarations__, string__0op__add(string__0op__add(((string){11,(uint8_t const*)"enum class "}), enum_name__), ((string){2,(uint8_t const*)"_;"})));
		element_separator_line__1(emitter__->class_declarations__);
		write_line__2(emitter__->class_declarations__, string__0op__add(string__0op__add(((string){11,(uint8_t const*)"enum class "}), enum_name__), ((string){1,(uint8_t const*)"_"})));
		begin_block__1(emitter__->class_declarations__);
		for (void_ptr__0iter iter = system__collections__List__1__0iterate(declaration__->children__); void_ptr__0next(&iter);)
		{
			Semantic_Node__0 const *_Nonnull const member__ = void_ptr__0current(&iter);
			if (cond(int32__0op__equal(member__->kind__, EnumMemberDeclaration__)))
			{
				string const member_name__ = get_text__1(system__collections__List__1__0op__element(member__->children__, ((int32){0})));
				begin_line__2(emitter__->class_declarations__, string__0op__add(member_name__, ((string){1,(uint8_t const*)"_"})));
				Semantic_Node__0 const *_Nullable const member_value__ = first_child__2(member__, Number__);
				if (cond(void_ptr__0op__not_equal(member_value__, none)))
				{
					write__2(emitter__->class_declarations__, ((string){3,(uint8_t const*)" = "}));
					write__2(emitter__->class_declarations__, get_text__1(member_value__));
				}

				end_line__2(emitter__->class_declarations__, ((string){1,(uint8_t const*)","}));
			}
		}

		end_block_with_semicolon__1(emitter__->class_declarations__);
	}
	else if (cond(int32__0op__equal(declaration__->kind__, FunctionDeclaration__)))
	{
		Semantic_Node__0 const *_Nonnull const parameters_node__ = first_child__2(declaration__, ParameterList__);
		string name__ = get_text__1(first_child__2(declaration__, Identifier__));
		BOOL const is_main__ = string__0op__equal(name__, ((string){4,(uint8_t const*)"main"}));
		name__ = mangle_function_name__2(name__, parameters_node__->children__->count__);
		if (cond(is_main__))
		{
			emitter__->main_function_name__ = name__;
		}

		string const parameters__ = convert_parameter_list__3(emitter__, parameters_node__, is_main__);
		Semantic_Node__0 const *_Nonnull const return_type_node__ = system__collections__List__1__0op__element(declaration__->children__, ((int32){3}));
		string const cpp_type__ = convert_type__2(TRUE, return_type_node__);
		write_line__2(emitter__->function_declarations__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(cpp_type__, ((string){1,(uint8_t const*)" "})), name__), parameters__), ((string){1,(uint8_t const*)";"})));
		element_separator_line__1(emitter__->definitions__);
		write_line__2(emitter__->definitions__, string__0op__add(string__0op__add(string__0op__add(cpp_type__, ((string){1,(uint8_t const*)" "})), name__), parameters__));
		if (cond(is_main__))
		{
			if (cond(string__0op__not_equal(emitter__->main_function_return_type__, ((string){0,(uint8_t const*)""}))))
			{
				error__2(emitter__->definitions__, ((string){29,(uint8_t const*)"Multiple declarations of main"}));
			}

			emitter__->main_function_return_type__ = cpp_type__;
		}

		emit_statement__2(emitter__, first_child__2(declaration__, Block__));
	}
	else if (cond(int32__0op__equal(declaration__->kind__, EndOfFileToken__)))
	{
	}
	else
	{
		error__2(emitter__->definitions__, string__0op__add(((string){35,(uint8_t const*)"Could not emit declaration of type "}), int_to_string__1(declaration__->kind__)));
	}
}

void emit_compilation_unit__2(Emitter__0 *_Nonnull const emitter__, Compilation_Unit__0 const *_Nonnull const unit__)
{
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(unit__->declarations__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const *_Nonnull const declaration__ = void_ptr__0current(&iter);
		emit_declaration__2(emitter__, declaration__);
	}
}

void emit_preamble__1(Emitter__0 *_Nonnull const emitter__)
{
	write_line__2(emitter__->type_declarations__, ((string){29,(uint8_t const*)"#include \"RuntimeLibrary.hpp\""}));
	blank_line__1(emitter__->type_declarations__);
	write_line__2(emitter__->type_declarations__, ((string){20,(uint8_t const*)"// Type Declarations"}));
	blank_line__1(emitter__->function_declarations__);
	write_line__2(emitter__->function_declarations__, ((string){24,(uint8_t const*)"// Function Declarations"}));
	blank_line__1(emitter__->class_declarations__);
	write_line__2(emitter__->class_declarations__, ((string){21,(uint8_t const*)"// Class Declarations"}));
	blank_line__1(emitter__->global_definitions__);
	write_line__2(emitter__->global_definitions__, ((string){21,(uint8_t const*)"// Global Definitions"}));
	blank_line__1(emitter__->definitions__);
	write_line__2(emitter__->definitions__, ((string){14,(uint8_t const*)"// Definitions"}));
}

void emit_entry_point_adapter__1(Emitter__0 *_Nonnull const emitter__)
{
	element_separator_line__1(emitter__->definitions__);
	write_line__2(emitter__->definitions__, ((string){22,(uint8_t const*)"// Entry Point Adapter"}));
	write_line__2(emitter__->definitions__, ((string){48,(uint8_t const*)"int32_t main(int argc, char const *const * argv)"}));
	begin_block__1(emitter__->definitions__);
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(emitter__->resources__); void_ptr__0next(&iter);)
	{
		Source_Text__0 const *_Nonnull const resource__ = void_ptr__0current(&iter);
		string const resource_name__ = string__0op__add(string__0op__add(((string){1,(uint8_t const*)"\""}), resource__->name__), ((string){1,(uint8_t const*)"\""}));
		string resource_text__ = resource__->text__;
		resource_text__ = string_replace__3(resource_text__, ((string){1,(uint8_t const*)"\\"}), ((string){2,(uint8_t const*)"\\\\"}));
		resource_text__ = string_replace__3(resource_text__, ((string){1,(uint8_t const*)"\n"}), ((string){2,(uint8_t const*)"\\n"}));
		resource_text__ = string_replace__3(resource_text__, ((string){1,(uint8_t const*)"\r"}), ((string){2,(uint8_t const*)"\\r"}));
		resource_text__ = string_replace__3(resource_text__, ((string){1,(uint8_t const*)"\""}), ((string){2,(uint8_t const*)"\\\""}));
		resource_text__ = string__0op__add(string__0op__add(((string){1,(uint8_t const*)"\""}), resource_text__), ((string){1,(uint8_t const*)"\""}));
		begin_line__2(emitter__->definitions__, string__0op__add(string__0op__add(((string){22,(uint8_t const*)"add_resource((string){"}), int_to_string__1(literal_length__1(resource_name__))), ((string){17,(uint8_t const*)",(uint8_t const*)"})));
		write__2(emitter__->definitions__, resource_name__);
		write__2(emitter__->definitions__, string__0op__add(string__0op__add(((string){12,(uint8_t const*)"}, (string){"}), int_to_string__1(literal_length__1(resource_text__))), ((string){17,(uint8_t const*)",(uint8_t const*)"})));
		write__2(emitter__->definitions__, resource_text__);
		end_line__2(emitter__->definitions__, ((string){3,(uint8_t const*)"});"}));
	}

	if (cond(int32__0op__gt(emitter__->resources__->count__, ((int32){0}))))
	{
		end_line__2(emitter__->definitions__, ((string){0,(uint8_t const*)""}));
	}

	system__text__String_Builder__0 *_Nonnull const args__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	if (cond(emitter__->main_function_accepts_console__))
	{
		args__->Append__1(((string){33,(uint8_t const*)"new system__console__Console__0()"}));
	}

	if (cond(emitter__->main_function_accepts_args__))
	{
		if (cond(emitter__->main_function_accepts_console__))
		{
			args__->Append__1(((string){2,(uint8_t const*)", "}));
		}

		args__->Append__1(((string){45,(uint8_t const*)"new system__console__Arguments__0(argc, argv)"}));
	}

	if (cond(string__0op__equal(emitter__->main_function_return_type__, ((string){4,(uint8_t const*)"void"}))))
	{
		write_line__2(emitter__->definitions__, string__0op__add(string__0op__add(string__0op__add(emitter__->main_function_name__, ((string){1,(uint8_t const*)"("})), args__->ToString__0()), ((string){2,(uint8_t const*)");"})));
		write_line__2(emitter__->definitions__, ((string){9,(uint8_t const*)"return 0;"}));
	}
	else
	{
		write_line__2(emitter__->definitions__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){7,(uint8_t const*)"return "}), emitter__->main_function_name__), ((string){1,(uint8_t const*)"("})), args__->ToString__0()), ((string){8,(uint8_t const*)").value;"})));
	}

	end_block__1(emitter__->definitions__);
}

Name__0 *_Nonnull Name__0__0new__global_namespace__0(Name__0 *_Nonnull self)
{
	self->package__ = none;
	self->kind__ = NamespaceName__;
	self->segments__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	self->is_special__ = FALSE;
	return self;
}

Name__0 *_Nonnull Name__0__0new__global_namespace__1(Name__0 *_Nonnull self, Package_Name__0 const *_Nonnull const package__)
{
	assert__1(void_ptr__0op__not_equal(package__, none));
	self->package__ = package__;
	self->kind__ = NamespaceName__;
	self->segments__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	self->is_special__ = FALSE;
	return self;
}

Name__0 *_Nonnull Name__0__0new__3(Name__0 *_Nonnull self, Name__0 const *_Nonnull const qualifier__, int32 const kind__, string const name__)
{
	assert__1(void_ptr__0op__not_equal(qualifier__, none));
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	self->package__ = qualifier__->package__;
	self->kind__ = kind__;
	Strings__0 *_Nonnull const segments__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	for (string__0iter iter = Strings__0__0iterate(qualifier__->segments__); string__0next(&iter);)
	{
		string const segment__ = string__0current(&iter);
		add_string__2(segments__, segment__);
	}

	add_string__2(segments__, name__);
	self->segments__ = segments__;
	self->is_special__ = FALSE;
	return self;
}

Name__0 *_Nonnull Name__0__0new__4(Name__0 *_Nonnull self, Name__0 const *_Nonnull const qualifier__, int32 const kind__, string const name__, BOOL const is_special__)
{
	assert__1(void_ptr__0op__not_equal(qualifier__, none));
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	self->package__ = qualifier__->package__;
	self->kind__ = kind__;
	Strings__0 *_Nonnull const segments__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	for (string__0iter iter = Strings__0__0iterate(qualifier__->segments__); string__0next(&iter);)
	{
		string const segment__ = string__0current(&iter);
		add_string__2(segments__, segment__);
	}

	add_string__2(segments__, name__);
	self->segments__ = segments__;
	self->is_special__ = is_special__;
	return self;
}

Name__0 *_Nonnull Name__0__0new__special__3(Name__0 *_Nonnull self, Name__0 const *_Nonnull const qualifier__, int32 const kind__, string const name__)
{
	assert__1(void_ptr__0op__not_equal(qualifier__, none));
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	self->package__ = qualifier__->package__;
	self->kind__ = kind__;
	Strings__0 *_Nonnull const segments__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	for (string__0iter iter = Strings__0__0iterate(qualifier__->segments__); string__0next(&iter);)
	{
		string const segment__ = string__0current(&iter);
		add_string__2(segments__, segment__);
	}

	add_string__2(segments__, name__);
	self->segments__ = segments__;
	self->is_special__ = TRUE;
	return self;
}

Name__0 *_Nonnull Name__0__0new__4(Name__0 *_Nonnull self, Package_Name__0 const *_Nullable const package__, int32 const kind__, Strings__0 const *_Nonnull const segments__, BOOL const is_special__)
{
	self->package__ = package__;
	self->kind__ = kind__;
	self->segments__ = segments__;
	self->is_special__ = is_special__;
	return self;
}

string unqualified_name__1(Name__0 const *_Nonnull const name__)
{
	if (cond(int32__0op__equal(name__->segments__->count__, ((int32){0}))))
	{
		return ((string){0,(uint8_t const*)""});
	}

	return Strings__0__0op__element(name__->segments__, int32__0op__sub(name__->segments__->count__, ((int32){1})));
}

string full_name__1(Name__0 const *_Nonnull const name__)
{
	string result__ = ((string){0,(uint8_t const*)""});
	if (cond(void_ptr__0op__not_equal(name__->package__, none)))
	{
		result__ = full_name__1(name__->package__);
	}

	result__ = string__0op__add(result__, ((string){2,(uint8_t const*)"::"}));
	BOOL first__ = TRUE;
	for (string__0iter iter = Strings__0__0iterate(name__->segments__); string__0next(&iter);)
	{
		string const segment__ = string__0current(&iter);
		if (cond(first__))
		{
			first__ = FALSE;
			result__ = string__0op__add(result__, segment__);
			continue;
		}

		result__ = string__0op__add(string__0op__add(result__, ((string){1,(uint8_t const*)"."})), segment__);
	}

	return result__;
}

BOOL is_qualified_by__2(Name__0 const *_Nonnull const name__, Name__0 const *_Nonnull const qualifier__)
{
	if (cond(int32__0op__lte(name__->segments__->count__, qualifier__->segments__->count__)))
	{
		return FALSE;
	}

	if (cond(bool_op(bool_arg(void_ptr__0op__not_equal(name__->package__, none)) && bool_arg(void_ptr__0op__not_equal(qualifier__->package__, none)))))
	{
		string const full_package_name__ = full_name__1(name__->package__);
		if (cond(string__0op__not_equal(full_package_name__, full_name__1(qualifier__->package__))))
		{
			return FALSE;
		}
	}

	int32 i__ = ((int32){0});
	for (string__0iter iter = Strings__0__0iterate(qualifier__->segments__); string__0next(&iter);)
	{
		string const segment__ = string__0current(&iter);
		if (cond(string__0op__not_equal(segment__, Strings__0__0op__element(name__->segments__, i__))))
		{
			return FALSE;
		}

		op__add_assign(&(i__), ((int32){1}));
	}

	return TRUE;
}

BOOL qualifier_is__2(Name__0 const *_Nonnull const name__, Name__0 const *_Nonnull const qualifier__)
{
	return bool_op(bool_arg(int32__0op__equal(int32__0op__add(((int32){1}), qualifier__->segments__->count__), name__->segments__->count__)) && bool_arg(is_qualified_by__2(name__, qualifier__)));
}

BOOL names__2(Name__0 const *_Nonnull const name__, Name__0 const *_Nonnull const other__)
{
	if (cond(int32__0op__not_equal(name__->segments__->count__, other__->segments__->count__)))
	{
		return FALSE;
	}

	if (cond(void_ptr__0op__not_equal(name__->package__, none)))
	{
		string const full_package_name__ = full_name__1(name__->package__);
		if (cond(bool_op(bool_arg(void_ptr__0op__equal(other__->package__, none)) || bool_arg(string__0op__not_equal(full_package_name__, full_name__1(other__->package__))))))
		{
			return FALSE;
		}
	}

	int32 i__ = ((int32){0});
	for (string__0iter iter = Strings__0__0iterate(other__->segments__); string__0next(&iter);)
	{
		string const segment__ = string__0current(&iter);
		if (cond(string__0op__not_equal(segment__, Strings__0__0op__element(name__->segments__, i__))))
		{
			return FALSE;
		}

		op__add_assign(&(i__), ((int32){1}));
	}

	return TRUE;
}

BOOL is_package_qualified__1(Name__0 const *_Nonnull const name__)
{
	return void_ptr__0op__not_equal(name__->package__, none);
}

Name__0 const *_Nonnull remove_package__1(Name__0 const *_Nonnull const name__)
{
	if (cond(void_ptr__0op__equal(name__->package__, none)))
	{
		return name__;
	}
	else
	{
		return Name__0__0new__4(allocate(sizeof(Name__0)), none, name__->kind__, name__->segments__, name__->is_special__);
	}
}

void unit_test_Name__0()
{
	name_with_unspecified_package_names_name_with_package__0();
	name_with_unspecified_package_names_itself__0();
}

void name_with_unspecified_package_names_name_with_package__0()
{
	Name__0 const *_Nonnull const name_without_package__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__0(allocate(sizeof(Name__0))), NamespaceName__, ((string){6,(uint8_t const*)"system"}));
	Name__0 const *_Nonnull const name_with_package__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__1(allocate(sizeof(Name__0)), Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){7,(uint8_t const*)"package"}))), NamespaceName__, ((string){6,(uint8_t const*)"system"}));
	assert__1(names__2(name_without_package__, name_with_package__));
}

void name_with_unspecified_package_names_itself__0()
{
	Name__0 const *_Nonnull const name_without_package__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__0(allocate(sizeof(Name__0))), NamespaceName__, ((string){6,(uint8_t const*)"system"}));
	assert__1(names__2(name_without_package__, name_without_package__));
}

Package_Name__0 *_Nonnull Package_Name__0__0new__1(Package_Name__0 *_Nonnull self, string const name__)
{
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	self->unqualified__ = name__;
	return self;
}

string full_name__1(Package_Name__0 const *_Nonnull const package_name__)
{
	return package_name__->unqualified__;
}

Symbol__0 *_Nonnull Symbol__0__0new__identifier__1(Symbol__0 *_Nonnull self, string const name__)
{
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	self->name__ = name__;
	self->kind__ = IdentifierSymbol__;
	self->is_special_name__ = FALSE;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->declarations__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	self->children__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	return self;
}

Symbol__0 *_Nonnull Symbol__0__0new__identifier__2(Symbol__0 *_Nonnull self, string const name__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__)
{
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	assert__2(void_ptr__0op__not_equal(declarations__, none), string__0op__add(((string){5,(uint8_t const*)"name="}), name__));
	self->name__ = name__;
	self->kind__ = IdentifierSymbol__;
	self->is_special_name__ = FALSE;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->declarations__ = declarations__;
	self->children__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	return self;
}

Symbol__0 *_Nonnull Symbol__0__0new__identifier__2(Symbol__0 *_Nonnull self, string const name__, system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const children__)
{
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	assert__2(void_ptr__0op__not_equal(children__, none), string__0op__add(((string){5,(uint8_t const*)"name="}), name__));
	self->name__ = name__;
	self->kind__ = IdentifierSymbol__;
	self->is_special_name__ = FALSE;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->declarations__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	self->children__ = children__;
	return self;
}

Symbol__0 *_Nonnull Symbol__0__0new__constructor__2(Symbol__0 *_Nonnull self, string const name__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__)
{
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	assert__2(void_ptr__0op__not_equal(declarations__, none), string__0op__add(((string){5,(uint8_t const*)"name="}), name__));
	self->name__ = name__;
	self->kind__ = IdentifierSymbol__;
	self->is_special_name__ = TRUE;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->declarations__ = declarations__;
	self->children__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	return self;
}

Symbol__0 *_Nonnull Symbol__0__0new__package__2(Symbol__0 *_Nonnull self, string const name__, system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const children__)
{
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	assert__2(void_ptr__0op__not_equal(children__, none), string__0op__add(((string){5,(uint8_t const*)"name="}), name__));
	self->name__ = name__;
	self->kind__ = PackageSymbol__;
	self->is_special_name__ = FALSE;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->declarations__ = system__collections__List__1__0new__0<Semantic_Node__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Semantic_Node__0 const *_Nonnull>)));
	self->children__ = children__;
	return self;
}

Symbol__0 *_Nonnull Symbol__0__0new__declaring__3(Symbol__0 *_Nonnull self, Type__0 const *_Nonnull const declares_type__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__, system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const children__)
{
	assert__1(void_ptr__0op__not_equal(declares_type__, none));
	assert__2(void_ptr__0op__not_equal(declarations__, none), string__0op__add(((string){5,(uint8_t const*)"name="}), unqualified_name__1(declares_type__->name__)));
	assert__2(void_ptr__0op__not_equal(children__, none), string__0op__add(((string){5,(uint8_t const*)"name="}), unqualified_name__1(declares_type__->name__)));
	self->name__ = unqualified_name__1(declares_type__->name__);
	self->is_special_name__ = declares_type__->name__->is_special__;
	self->of_type__ = none;
	self->declares_type__ = declares_type__;
	self->declarations__ = declarations__;
	self->children__ = children__;
	return self;
}

Symbol__0 *_Nonnull Symbol__0__0new__of_type__4(Symbol__0 *_Nonnull self, string const name__, Type__0 const *_Nonnull const of_type__, system__collections__List__1<Semantic_Node__0 const *_Nonnull> const *_Nonnull const declarations__, system__collections__List__1<Symbol__0 const *_Nonnull> const *_Nonnull const children__)
{
	assert__2(void_ptr__0op__not_equal(of_type__, none), string__0op__add(((string){5,(uint8_t const*)"name="}), name__));
	assert__2(void_ptr__0op__not_equal(declarations__, none), string__0op__add(((string){5,(uint8_t const*)"name="}), name__));
	assert__2(void_ptr__0op__not_equal(children__, none), string__0op__add(((string){5,(uint8_t const*)"name="}), name__));
	self->name__ = name__;
	self->is_special_name__ = FALSE;
	self->of_type__ = of_type__;
	self->declares_type__ = none;
	self->declarations__ = declarations__;
	self->children__ = children__;
	return self;
}

Symbol__0 const *_Nullable get_child__3(Symbol__0 const *_Nonnull const symbol__, string const name__, int32 const kind__)
{
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(symbol__->children__); void_ptr__0next(&iter);)
	{
		Symbol__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(string__0op__equal(child__->name__, name__)) && bool_arg(int32__0op__equal(child__->kind__, kind__)))))
		{
			return child__;
		}
	}

	return none;
}

void unit_test_Symbol__0()
{
	Package_symbol_children_can_be_found_by_name_and_kind__0();
}

void Package_symbol_children_can_be_found_by_name_and_kind__0()
{
	system__collections__List__1<Symbol__0 const *_Nonnull> *_Nonnull const children__ = system__collections__List__1__0new__0<Symbol__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Symbol__0 const *_Nonnull>)));
	children__->add__1(Symbol__0__0new__identifier__1(allocate(sizeof(Symbol__0)), ((string){5,(uint8_t const*)"child"})));
	Symbol__0 const *_Nonnull const package_with_children__ = Symbol__0__0new__package__2(allocate(sizeof(Symbol__0)), ((string){7,(uint8_t const*)"package"}), children__);
	assert__1(never__0op__not_equal(get_child__3(package_with_children__, ((string){5,(uint8_t const*)"child"}), IdentifierSymbol__), none));
}

Type__0 *_Nonnull Type__0__0new__3(Type__0 *_Nonnull self, int32 const kind__, Name__0 const *_Nonnull const name__, BOOL const is_mutable__)
{
	assert__1(void_ptr__0op__not_equal(name__, none));
	self->kind__ = kind__;
	self->name__ = name__;
	self->type_parameters__ = system__collections__List__1__0new__0<Type__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Type__0 const *_Nonnull>)));
	self->is_primitive__ = FALSE;
	self->is_value_type__ = int32__0op__equal(kind__, ValueType__);
	self->is_potentially_mutable__ = is_mutable__;
	self->is_mutable__ = is_mutable__;
	return self;
}

Type__0 *_Nonnull Type__0__0new__parameter__1(Type__0 *_Nonnull self, string const name__)
{
	self->kind__ = TypeParameterType__;
	self->name__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__0(allocate(sizeof(Name__0))), TypeParameterName__, name__);
	self->type_parameters__ = system__collections__List__1__0new__0<Type__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Type__0 const *_Nonnull>)));
	self->is_primitive__ = FALSE;
	self->is_value_type__ = FALSE;
	self->is_potentially_mutable__ = TRUE;
	self->is_mutable__ = FALSE;
	return self;
}

Type__0 *_Nonnull Type__0__0new__4(Type__0 *_Nonnull self, int32 const kind__, Name__0 const *_Nonnull const name__, system__collections__List__1<Type__0 const *_Nonnull> const *_Nonnull const type_parameters__, BOOL const is_mutable__)
{
	self->kind__ = kind__;
	self->name__ = name__;
	self->type_parameters__ = type_parameters__;
	self->is_primitive__ = FALSE;
	self->is_value_type__ = int32__0op__equal(kind__, ValueType__);
	self->is_potentially_mutable__ = is_mutable__;
	self->is_mutable__ = is_mutable__;
	return self;
}

Type__0 *_Nonnull Type__0__0new__primitive__1(Type__0 *_Nonnull self, Name__0 const *_Nonnull const name__)
{
	self->kind__ = ValueType__;
	self->name__ = name__;
	self->type_parameters__ = system__collections__List__1__0new__0<Type__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Type__0 const *_Nonnull>)));
	self->is_primitive__ = TRUE;
	self->is_value_type__ = TRUE;
	self->is_potentially_mutable__ = FALSE;
	self->is_mutable__ = FALSE;
	return self;
}

Type__0 *_Nonnull Type__0__0new__primitive__2(Type__0 *_Nonnull self, Name__0 const *_Nonnull const name__, system__collections__List__1<Type__0 const *_Nonnull> const *_Nonnull const type_parameters__)
{
	self->kind__ = ValueType__;
	self->name__ = name__;
	self->type_parameters__ = type_parameters__;
	self->is_primitive__ = TRUE;
	self->is_value_type__ = TRUE;
	self->is_potentially_mutable__ = FALSE;
	self->is_mutable__ = FALSE;
	return self;
}

Type__0 *_Nonnull Type__0__0new__namespace__1(Type__0 *_Nonnull self, Name__0 const *_Nonnull const name__)
{
	self->kind__ = NamespaceType__;
	self->name__ = name__;
	self->is_primitive__ = FALSE;
	self->type_parameters__ = system__collections__List__1__0new__0<Type__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Type__0 const *_Nonnull>)));
	self->is_value_type__ = TRUE;
	self->is_potentially_mutable__ = FALSE;
	self->is_mutable__ = FALSE;
	return self;
}

Type__0 *_Nonnull Type__0__0new__generic__2(Type__0 *_Nonnull self, Type__0 const *_Nonnull const definition__, system__collections__List__1<Type__0 const *_Nonnull> const *_Nonnull const type_arguments__)
{
	assert__1(void_ptr__0op__not_equal(definition__, none));
	assert__2(void_ptr__0op__not_equal(type_arguments__, none), full_name__1(definition__->name__));
	assert__2(int32__0op__equal(definition__->type_parameters__->count__, type_arguments__->count__), string__0op__add(string__0op__add(string__0op__add(string__0op__add(full_name__1(definition__->name__), ((string){1,(uint8_t const*)" "})), int_to_string__1(definition__->type_parameters__->count__)), ((string){7,(uint8_t const*)" given "})), int_to_string__1(type_arguments__->count__)));
	self->kind__ = definition__->kind__;
	self->name__ = definition__->name__;
	self->type_parameters__ = type_arguments__;
	self->is_primitive__ = definition__->is_primitive__;
	self->is_value_type__ = definition__->is_value_type__;
	self->is_potentially_mutable__ = definition__->is_potentially_mutable__;
	self->is_mutable__ = definition__->is_mutable__;
	return self;
}

Type__0 *_Nonnull Type__0__0new__6(Type__0 *_Nonnull self, int32 const kind__, Name__0 const *_Nonnull const name__, system__collections__List__1<Type__0 const *_Nonnull> const *_Nonnull const type_parameters__, BOOL const is_primitive__, BOOL const is_potentially_mutable__, BOOL const is_mutable__)
{
	self->kind__ = kind__;
	self->name__ = name__;
	self->type_parameters__ = type_parameters__;
	self->is_primitive__ = is_primitive__;
	self->is_value_type__ = int32__0op__equal(kind__, ValueType__);
	self->is_potentially_mutable__ = is_potentially_mutable__;
	self->is_mutable__ = is_mutable__;
	return self;
}

Type__0 const *_Nonnull make_mutable_type__1(Type__0 const *_Nonnull const type__)
{
	assert__2(type__->is_potentially_mutable__, string__0op__add(((string){10,(uint8_t const*)"self.name="}), full_name__1(type__->name__)));
	return Type__0__0new__6(allocate(sizeof(Type__0)), type__->kind__, type__->name__, type__->type_parameters__, type__->is_primitive__, type__->is_potentially_mutable__, TRUE);
}

Type__0 const *_Nonnull make_immutable_type__1(Type__0 const *_Nonnull const type__)
{
	return Type__0__0new__6(allocate(sizeof(Type__0)), type__->kind__, type__->name__, type__->type_parameters__, type__->is_primitive__, type__->is_potentially_mutable__, FALSE);
}

Type__0 const *_Nonnull remove_type_package__1(Type__0 const *_Nonnull const type__)
{
	assert__2(int32__0op__equal(type__->kind__, NamespaceType__), string__0op__add(((string){5,(uint8_t const*)"kind="}), int_to_string__1(type__->kind__)));
	if (cond(is_package_qualified__1(type__->name__)))
	{
		return Type__0__0new__6(allocate(sizeof(Type__0)), type__->kind__, remove_package__1(type__->name__), type__->type_parameters__, type__->is_primitive__, type__->is_potentially_mutable__, type__->is_mutable__);
	}
	else
	{
		return type__;
	}
}

Name_Subtable__0 *_Nonnull Name_Subtable__0__0new__global_namespace__1(Name_Subtable__0 *_Nonnull self, Name_Table__0 const *_Nonnull const name_table__)
{
	self->name_table__ = name_table__;
	self->parent__ = none;
	self->name__ = Name__0__0new__global_namespace__0(allocate(sizeof(Name__0)));
	self->type__ = Type__0__0new__namespace__1(allocate(sizeof(Type__0)), self->name__);
	self->subtables__ = system__collections__List__1__0new__0<Name_Subtable__0 *_Nonnull>(allocate(sizeof(system__collections__List__1<Name_Subtable__0 *_Nonnull>)));
	return self;
}

Name_Subtable__0 *_Nonnull Name_Subtable__0__0new__global_namespace__2(Name_Subtable__0 *_Nonnull self, Name_Table__0 const *_Nonnull const name_table__, Package_Name__0 const *_Nonnull const package_name__)
{
	self->name_table__ = name_table__;
	self->parent__ = none;
	self->name__ = Name__0__0new__global_namespace__1(allocate(sizeof(Name__0)), package_name__);
	self->type__ = Type__0__0new__namespace__1(allocate(sizeof(Type__0)), self->name__);
	self->subtables__ = system__collections__List__1__0new__0<Name_Subtable__0 *_Nonnull>(allocate(sizeof(system__collections__List__1<Name_Subtable__0 *_Nonnull>)));
	return self;
}

Name_Subtable__0 *_Nonnull Name_Subtable__0__0new__3(Name_Subtable__0 *_Nonnull self, Name_Subtable__0 const *_Nonnull const parent__, Name__0 const *_Nonnull const name__, Type__0 const *_Nonnull const type__)
{
	self->name_table__ = parent__->name_table__;
	self->parent__ = parent__;
	self->name__ = name__;
	self->type__ = type__;
	self->subtables__ = system__collections__List__1__0new__0<Name_Subtable__0 *_Nonnull>(allocate(sizeof(system__collections__List__1<Name_Subtable__0 *_Nonnull>)));
	return self;
}

void add_subtable__3(Name_Subtable__0 *_Nonnull const scope__, Name__0 const *_Nonnull const name__, Type__0 const *_Nonnull const type__)
{
	assert__2(is_qualified_by__2(name__, scope__->name__), string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){1,(uint8_t const*)"\""}), full_name__1(name__)), ((string){21,(uint8_t const*)"\" is not a child of \""})), full_name__1(scope__->name__)), ((string){1,(uint8_t const*)"\""})));
	if (cond(qualifier_is__2(name__, scope__->name__)))
	{
		if (cond(bool_op(bool_arg(bool_op(bool_arg(void_ptr__0op__equal(scope__->name__->package__, none)) && bool_arg(void_ptr__0op__not_equal(type__, none)))) && bool_arg(int32__0op__equal(type__->kind__, NamespaceType__)))))
		{
			scope__->subtables__->add__1(Name_Subtable__0__0new__3(allocate(sizeof(Name_Subtable__0)), scope__, remove_package__1(name__), remove_type_package__1(type__)));
		}
		else
		{
			scope__->subtables__->add__1(Name_Subtable__0__0new__3(allocate(sizeof(Name_Subtable__0)), scope__, name__, type__));
		}

		return;
	}

	for (void_ptr__0iter iter = system__collections__List__1__0iterate(scope__->subtables__); void_ptr__0next(&iter);)
	{
		Name_Subtable__0 *_Nonnull const subtable__ = void_ptr__0current(&iter);
		if (cond(is_qualified_by__2(name__, subtable__->name__)))
		{
			add_subtable__3(subtable__, name__, type__);
			return;
		}
	}

	assert__2(int32__0op__equal(name__->segments__->count__, int32__0op__add(((int32){1}), scope__->name__->segments__->count__)), string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){11,(uint8_t const*)"Can't add \""}), full_name__1(name__)), ((string){6,(uint8_t const*)"\" to \""})), full_name__1(scope__->name__)), ((string){1,(uint8_t const*)"\""})));
}

Name_Subtable__0 *_Nullable find__2(Name_Subtable__0 const *_Nonnull const scope__, string const name__)
{
	return find__3(scope__, name__, FALSE);
}

Name_Subtable__0 *_Nullable find_special__2(Name_Subtable__0 const *_Nonnull const scope__, string const name__)
{
	return find__3(scope__, name__, TRUE);
}

Name_Subtable__0 *_Nullable find__3(Name_Subtable__0 const *_Nonnull const scope__, string const name__, BOOL const is_special__)
{
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(scope__->subtables__); void_ptr__0next(&iter);)
	{
		Name_Subtable__0 *_Nonnull const subtable__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(string__0op__equal(unqualified_name__1(subtable__->name__), name__)) && bool_arg(BOOL__0op__equal(subtable__->name__->is_special__, is_special__)))))
		{
			return subtable__;
		}
	}

	return none;
}

Name_Subtable__0 *_Nullable lookup__2(Name_Subtable__0 const *_Nonnull const scope__, string const name__)
{
	return lookup__3(scope__, name__, FALSE);
}

Name_Subtable__0 *_Nullable lookup_special__2(Name_Subtable__0 const *_Nonnull const scope__, string const name__)
{
	return lookup__3(scope__, name__, TRUE);
}

Name_Subtable__0 *_Nullable lookup__3(Name_Subtable__0 const *_Nonnull const scope__, string const name__, BOOL const is_special__)
{
	Name_Subtable__0 *_Nullable subtable__ = find__3(scope__, name__, is_special__);
	if (cond(bool_op(bool_arg(void_ptr__0op__equal(subtable__, none)) && bool_arg(void_ptr__0op__not_equal(scope__->parent__, none)))))
	{
		subtable__ = lookup__3(scope__->parent__, name__, is_special__);
	}

	return subtable__;
}

Name_Subtable__0 const *_Nullable get_scope__2(Name_Subtable__0 const *_Nonnull const scope__, Name__0 const *_Nonnull const name__)
{
	if (cond(names__2(name__, scope__->name__)))
	{
		return scope__;
	}
	else if (cond(BOOL__0op__not(is_qualified_by__2(name__, scope__->name__))))
	{
		return none;
	}

	for (void_ptr__0iter iter = system__collections__List__1__0iterate(scope__->subtables__); void_ptr__0next(&iter);)
	{
		Name_Subtable__0 const *_Nonnull const subtable__ = void_ptr__0current(&iter);
		Name_Subtable__0 const *_Nullable const value__ = get_scope__2(subtable__, name__);
		if (cond(void_ptr__0op__not_equal(value__, none)))
		{
			return value__;
		}
	}

	return none;
}

void bind_type__2(Name_Subtable__0 *_Nonnull const scope__, Type__0 const *_Nonnull const type__)
{
	assert__2(void_ptr__0op__not_equal(type__, none), full_name__1(scope__->name__));
	if (cond(void_ptr__0op__not_equal(scope__->type__, none)))
	{
		string const scope_type_name__ = full_name__1(scope__->type__->name__);
		assert__2(string__0op__equal(scope_type_name__, full_name__1(type__->name__)), string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(full_name__1(scope__->name__), ((string){12,(uint8_t const*)" currently `"})), scope_type_name__), ((string){20,(uint8_t const*)"` trying to set to `"})), full_name__1(type__->name__)), ((string){1,(uint8_t const*)"`"})));
	}

	scope__->type__ = type__;
}

Name_Subtable__0 *_Nonnull as_mut__1(Name_Subtable__0 const *_Nonnull const scope__)
{
	return find__3(scope__->parent__, unqualified_name__1(scope__->name__), scope__->name__->is_special__);
}

void unit_test_Name_Subtable__0()
{
	global_namespace_contains_added_name__0();
	namespace_contains_added_name__0();
}

void global_namespace_contains_added_name__0()
{
	Name_Table__0 const *_Nonnull const name_table__ = Name_Table__0__0new__0(allocate(sizeof(Name_Table__0)));
	Name_Subtable__0 *_Nonnull const global_namespace__ = Name_Subtable__0__0new__global_namespace__1(allocate(sizeof(Name_Subtable__0)), name_table__);
	Name__0 const *_Nonnull const test_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__->name__, TypeName__, ((string){4,(uint8_t const*)"test"}));
	add_subtable__3(global_namespace__, test_name__, none);
	assert__1(never__0op__not_equal(find__2(global_namespace__, ((string){4,(uint8_t const*)"test"})), none));
	assert__1(never__0op__not_equal(get_scope__2(global_namespace__, test_name__), none));
}

void namespace_contains_added_name__0()
{
	Name_Table__0 const *_Nonnull const name_table__ = Name_Table__0__0new__0(allocate(sizeof(Name_Table__0)));
	Name_Subtable__0 *_Nonnull const global_namespace__ = Name_Subtable__0__0new__global_namespace__1(allocate(sizeof(Name_Subtable__0)), name_table__);
	Name__0 const *_Nonnull const namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__->name__, NamespaceName__, ((string){9,(uint8_t const*)"namespace"}));
	add_subtable__3(global_namespace__, namespace_name__, none);
	add_subtable__3(global_namespace__, Name__0__0new__3(allocate(sizeof(Name__0)), namespace_name__, TypeName__, ((string){4,(uint8_t const*)"test"})), none);
	Name_Subtable__0 const *_Nonnull const namespace__ = find__2(global_namespace__, ((string){9,(uint8_t const*)"namespace"}));
	assert__1(never__0op__not_equal(find__2(namespace__, ((string){4,(uint8_t const*)"test"})), none));
}

Name_Table__0 *_Nonnull Name_Table__0__0new__0(Name_Table__0 *_Nonnull self)
{
	self->any_package__ = Name_Subtable__0__0new__global_namespace__1(allocate(sizeof(Name_Subtable__0)), self);
	self->packages__ = system__collections__List__1__0new__0<Name_Subtable__0 *_Nonnull>(allocate(sizeof(system__collections__List__1<Name_Subtable__0 *_Nonnull>)));
	return self;
}

Name__0 const *_Nonnull add_package__2(Name_Table__0 *_Nonnull const name_table__, Package_Name__0 const *_Nonnull const package_name__)
{
	Name_Subtable__0 *_Nonnull const subtable__ = Name_Subtable__0__0new__global_namespace__2(allocate(sizeof(Name_Subtable__0)), name_table__, package_name__);
	name_table__->packages__->add__1(subtable__);
	return subtable__->name__;
}

Name__0 const *_Nonnull add_name__3(Name_Table__0 *_Nonnull const name_table__, Name__0 const *_Nonnull const parent__, Symbol__0 const *_Nonnull const symbol__)
{
	Name__0 const *_Nonnull name__;
	if (cond(void_ptr__0op__not_equal(symbol__->declares_type__, none)))
	{
		name__ = Name__0__0new__4(allocate(sizeof(Name__0)), parent__, TypeName__, symbol__->name__, symbol__->is_special_name__);
		add_name__3(name_table__, name__, symbol__->declares_type__);
	}
	else
	{
		name__ = Name__0__0new__4(allocate(sizeof(Name__0)), parent__, FunctionName__, symbol__->name__, symbol__->is_special_name__);
		add_name__3(name_table__, name__, symbol__->of_type__);
	}

	return name__;
}

void add_name__3(Name_Table__0 *_Nonnull const name_table__, Name__0 const *_Nonnull const name__, Type__0 const *_Nonnull const type__)
{
	add_subtable__3(name_table__->any_package__, name__, type__);
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(name_table__->packages__); void_ptr__0next(&iter);)
	{
		Name_Subtable__0 *_Nonnull const package__ = void_ptr__0current(&iter);
		if (cond(is_qualified_by__2(name__, package__->name__)))
		{
			add_subtable__3(package__, name__, type__);
			return;
		}
	}

	assert__2(FALSE, string__0op__add(string__0op__add(((string){16,(uint8_t const*)"Can't add name \""}), full_name__1(name__)), ((string){41,(uint8_t const*)"\" because package doesn't exist in table."})));
}

Name_Subtable__0 const *_Nullable get_name__2(Name_Table__0 const *_Nonnull const name_table__, Name__0 const *_Nonnull const name__)
{
	if (cond(void_ptr__0op__equal(name__->package__, none)))
	{
		return get_scope__2(name_table__->any_package__, name__);
	}

	for (void_ptr__0iter iter = system__collections__List__1__0iterate(name_table__->packages__); void_ptr__0next(&iter);)
	{
		Name_Subtable__0 const *_Nonnull const package__ = void_ptr__0current(&iter);
		if (cond(is_qualified_by__2(name__, package__->name__)))
		{
			return get_scope__2(package__, name__);
		}
	}

	return none;
}

Name_Table__0 const *_Nonnull build_name_table__3(Package_Name__0 const *_Nonnull const package_name__, Syntax_Node__0 const *_Nonnull const package_syntax__, system__collections__List__1<Package_Reference__0 const *_Nonnull> const *_Nonnull const references__)
{
	assert__2(int32__0op__equal(package_syntax__->kind__, PackageNode__), string__0op__add(((string){20,(uint8_t const*)"package_syntax.kind="}), int_to_string__1(package_syntax__->kind__)));
	Name_Table__0 *_Nonnull const name_table__ = Name_Table__0__0new__0(allocate(sizeof(Name_Table__0)));
	add_referenced__2(name_table__, references__);
	add_package__3(name_table__, package_name__, package_syntax__);
	return name_table__;
}

void add_referenced__2(Name_Table__0 *_Nonnull const name_table__, system__collections__List__1<Package_Reference__0 const *_Nonnull> const *_Nonnull const references__)
{
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(references__); void_ptr__0next(&iter);)
	{
		Package_Reference__0 const *_Nonnull const reference__ = void_ptr__0current(&iter);
		Package_Name__0 const *_Nonnull const reference_name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), reference__->name__);
		Name__0 const *_Nonnull const global_namespace__ = add_package__2(name_table__, reference_name__);
		for (void_ptr__0iter iter = system__collections__List__1__0iterate(reference__->package__->symbol__->children__); void_ptr__0next(&iter);)
		{
			Symbol__0 const *_Nonnull const symbol__ = void_ptr__0current(&iter);
			add_symbol__3(name_table__, global_namespace__, symbol__);
		}
	}
}

void add_symbol__3(Name_Table__0 *_Nonnull const name_table__, Name__0 const *_Nonnull const parent__, Symbol__0 const *_Nonnull const symbol__)
{
	Name__0 const *_Nonnull const name__ = add_name__3(name_table__, parent__, symbol__);
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(symbol__->children__); void_ptr__0next(&iter);)
	{
		Symbol__0 const *_Nonnull const child__ = void_ptr__0current(&iter);
		add_symbol__3(name_table__, name__, child__);
	}
}

void add_package__3(Name_Table__0 *_Nonnull const name_table__, Package_Name__0 const *_Nonnull const package_name__, Syntax_Node__0 const *_Nonnull const package_syntax__)
{
	assert__2(int32__0op__equal(package_syntax__->kind__, PackageNode__), string__0op__add(((string){20,(uint8_t const*)"package_syntax.kind="}), int_to_string__1(package_syntax__->kind__)));
	Name__0 const *_Nonnull const global_namespace__ = add_package__2(name_table__, package_name__);
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(package_syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const *_Nonnull const compilation_unit__ = void_ptr__0current(&iter);
		add_compilation_unit__3(name_table__, global_namespace__, compilation_unit__);
	}
}

void add_compilation_unit__3(Name_Table__0 *_Nonnull const name_table__, Name__0 const *_Nonnull const global_namespace__, Syntax_Node__0 const *_Nonnull const compilation_unit__)
{
	assert__2(int32__0op__equal(compilation_unit__->kind__, CompilationUnit__), string__0op__add(((string){22,(uint8_t const*)"compilation_unit.kind="}), int_to_string__1(compilation_unit__->kind__)));
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(compilation_unit__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const *_Nonnull const declaration__ = void_ptr__0current(&iter);
		add_syntax__3(name_table__, global_namespace__, declaration__);
	}
}

void add_syntax__3(Name_Table__0 *_Nonnull const name_table__, Name__0 const *_Nonnull const parent__, Syntax_Node__0 const *_Nonnull const syntax__)
{
	if (cond(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, FunctionDeclaration__)) || bool_arg(int32__0op__equal(syntax__->kind__, MethodDeclaration__)))))
	{
		Name__0 const *_Nonnull const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, FunctionName__, get_text__1(first_child_syntax__2(syntax__, Identifier__)));
		add_function__3(name_table__, name__, syntax__);
	}
	else if (cond(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, ClassDeclaration__)) || bool_arg(int32__0op__equal(syntax__->kind__, StructDeclaration__)))))
	{
		string const unqualified_name__ = get_text__1(first_child_syntax__2(syntax__, Identifier__));
		int32 type_kind__;
		if (cond(int32__0op__equal(syntax__->kind__, ClassDeclaration__)))
		{
			type_kind__ = ReferenceType__;
		}
		else
		{
			type_kind__ = ValueType__;
		}

		Name__0 const *_Nonnull const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, TypeName__, unqualified_name__);
		Type__0 const *_Nonnull const type__ = Type__0__0new__3(allocate(sizeof(Type__0)), type_kind__, name__, TRUE);
		add_name__3(name_table__, name__, type__);
		for (void_ptr__0iter iter = void_ptr__0iterate(members__1(syntax__)); void_ptr__0next(&iter);)
		{
			Syntax_Node__0 const *_Nonnull const member__ = void_ptr__0current(&iter);
			add_syntax__3(name_table__, name__, member__);
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ConstructorDeclaration__)))
	{
		string full_name__ = ((string){3,(uint8_t const*)"new"});
		Syntax_Node__0 const *_Nullable const constructor_name__ = first_child_syntax__2(syntax__, Identifier__);
		if (cond(void_ptr__0op__not_equal(constructor_name__, none)))
		{
			full_name__ = string__0op__add(((string){4,(uint8_t const*)"new_"}), get_text__1(constructor_name__));
		}

		Name__0 const *_Nonnull const name__ = Name__0__0new__special__3(allocate(sizeof(Name__0)), parent__, FunctionName__, full_name__);
		add_function__3(name_table__, name__, syntax__);
		Name__0 const *_Nonnull const self_name__ = Name__0__0new__special__3(allocate(sizeof(Name__0)), name__, VariableName__, ((string){4,(uint8_t const*)"self"}));
		Type__0 const *_Nonnull const self_type__ = get_name__2(name_table__, parent__)->type__;
		assert__1(void_ptr__0op__not_equal(self_type__, none));
		add_name__3(name_table__, self_name__, self_type__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, FieldDeclaration__)))
	{
		string const unqualified_name__ = get_text__1(first_child_syntax__2(first_child_syntax__2(syntax__, VariableDeclaration__), Identifier__));
		Name__0 const *_Nonnull const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, TypeName__, unqualified_name__);
		Type__0 const *_Nullable const no_type__ = none;
		add_name__3(name_table__, name__, no_type__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, EnumDeclaration__)))
	{
		string const unqualified_name__ = get_text__1(first_child_syntax__2(syntax__, Identifier__));
		Name__0 const *_Nonnull const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, TypeName__, unqualified_name__);
		Type__0 const *_Nonnull const type__ = Type__0__0new__3(allocate(sizeof(Type__0)), ReferenceType__, name__, TRUE);
		add_name__3(name_table__, name__, type__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, GlobalDeclaration__)))
	{
		string const unqualified_name__ = get_text__1(first_child_syntax__2(first_child_syntax__2(syntax__, VariableDeclaration__), Identifier__));
		Name__0 const *_Nonnull const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, TypeName__, unqualified_name__);
		Type__0 const *_Nullable const no_type__ = none;
		add_name__3(name_table__, name__, no_type__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, Block__)))
	{
		for (void_ptr__0iter iter = void_ptr__0iterate(statements__1(syntax__)); void_ptr__0next(&iter);)
		{
			Syntax_Node__0 const *_Nonnull const statement__ = void_ptr__0current(&iter);
			add_syntax__3(name_table__, parent__, statement__);
		}
	}
	else if (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, LoopStatement__)) || bool_arg(int32__0op__equal(syntax__->kind__, WhileStatement__)))) || bool_arg(int32__0op__equal(syntax__->kind__, DoWhileStatement__)))))
	{
		add_syntax__3(name_table__, parent__, first_child_syntax__2(syntax__, Block__));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ForStatement__)))
	{
		Syntax_Node__0 const *_Nonnull const identifier__ = first_child_syntax__2(first_child_syntax__2(syntax__, VariableDeclaration__), Identifier__);
		Name__0 const *_Nonnull const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, VariableName__, get_text__1(identifier__));
		Type__0 const *_Nullable const no_type__ = none;
		add_name__3(name_table__, name__, no_type__);
		add_syntax__3(name_table__, parent__, first_child_syntax__2(syntax__, Block__));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, IfStatement__)))
	{
		add_syntax__3(name_table__, parent__, first_child_syntax__2(syntax__, Block__));
		Syntax_Node__0 const *_Nullable const else_clause__ = first_child_syntax__2(syntax__, ElseClause__);
		if (cond(void_ptr__0op__not_equal(else_clause__, none)))
		{
			add_syntax__3(name_table__, parent__, else_clause__);
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ElseClause__)))
	{
		Syntax_Node__0 const *_Nullable const block__ = first_child_syntax__2(syntax__, Block__);
		if (cond(void_ptr__0op__not_equal(block__, none)))
		{
			add_syntax__3(name_table__, parent__, block__);
		}
		else
		{
			add_syntax__3(name_table__, parent__, first_child_syntax__2(syntax__, IfStatement__));
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, LocalDeclarationStatement__)))
	{
		Syntax_Node__0 const *_Nonnull const identifier__ = first_child_syntax__2(first_child_syntax__2(syntax__, VariableDeclaration__), Identifier__);
		Name__0 const *_Nonnull const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, VariableName__, get_text__1(identifier__));
		Type__0 const *_Nullable const no_type__ = none;
		add_name__3(name_table__, name__, no_type__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, Parameter__)))
	{
		Syntax_Node__0 const *_Nonnull const identifier__ = first_child_syntax__2(syntax__, Identifier__);
		Name__0 const *_Nonnull const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, VariableName__, get_text__1(identifier__));
		Type__0 const *_Nullable const no_type__ = none;
		add_name__3(name_table__, name__, no_type__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, SelfParameter__)))
	{
		Name__0 const *_Nonnull const name__ = Name__0__0new__special__3(allocate(sizeof(Name__0)), parent__, VariableName__, ((string){4,(uint8_t const*)"self"}));
		Type__0 const *_Nonnull const self_type__ = get_name__2(name_table__, parent__)->parent__->type__;
		assert__1(void_ptr__0op__not_equal(self_type__, none));
		add_name__3(name_table__, name__, self_type__);
	}
	else if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, ExpressionStatement__)) || bool_arg(int32__0op__equal(syntax__->kind__, ReturnStatement__)))) || bool_arg(int32__0op__equal(syntax__->kind__, BreakStatement__)))) || bool_arg(int32__0op__equal(syntax__->kind__, ContinueStatement__)))) || bool_arg(int32__0op__equal(syntax__->kind__, EndOfFileToken__)))))
	{
	}
	else
	{
		NOT_IMPLEMENTED__1(string__0op__add(((string){12,(uint8_t const*)"syntax.kind="}), int_to_string__1(syntax__->kind__)));
	}
}

void add_function__3(Name_Table__0 *_Nonnull const name_table__, Name__0 const *_Nonnull const name__, Syntax_Node__0 const *_Nonnull const function__)
{
	Type__0 const *_Nullable const no_type__ = none;
	add_name__3(name_table__, name__, no_type__);
	Syntax_Node__0 const *_Nonnull const parameters_syntax__ = first_child_syntax__2(function__, ParameterList__);
	for (void_ptr__0iter iter = void_ptr__0iterate(parameters__1(parameters_syntax__)); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const *_Nonnull const parameter__ = void_ptr__0current(&iter);
		add_syntax__3(name_table__, name__, parameter__);
	}

	Syntax_Node__0 const *_Nonnull const body__ = first_child_syntax__2(function__, Block__);
	add_syntax__3(name_table__, name__, body__);
}

void unit_test_Name_Table_Builder__0()
{
	table_contains_referenced_child_names__0();
	can_get_root_namespace_from_name__0();
	can_get_Console_class_from_name_without_package__0();
	can_get_Optional_class_from_name_with_package__0();
}

void table_contains_referenced_child_names__0()
{
	Package_Name__0 const *_Nonnull const name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){7,(uint8_t const*)"default"}));
	Package__0 const *_Nonnull const runtime_package__ = build_runtime_library_package__0();
	system__collections__List__1<Package_Reference__0 const *_Nonnull> *_Nonnull const references__ = system__collections__List__1__0new__0<Package_Reference__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Package_Reference__0 const *_Nonnull>)));
	references__->add__1(Package_Reference__0__0new__1(allocate(sizeof(Package_Reference__0)), runtime_package__));
	Syntax_Node__0 const *_Nonnull const package_syntax__ = Syntax_Node__0__0new__4(allocate(sizeof(Syntax_Node__0)), PackageNode__, none, ((int32){0}), ((int32){0}));
	Name_Table__0 const *_Nonnull const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Name_Subtable__0 const *_Nonnull const namespace__ = find__2(name_table__->any_package__, ((string){6,(uint8_t const*)"system"}));
	assert__1(never__0op__not_equal(find__2(namespace__, ((string){7,(uint8_t const*)"console"})), none));
	Name__0 const *_Nonnull const system_namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__0(allocate(sizeof(Name__0))), NamespaceName__, ((string){6,(uint8_t const*)"system"}));
	assert__1(never__0op__not_equal(get_name__2(name_table__, system_namespace_name__), none));
	Name__0 const *_Nonnull const console_namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), system_namespace_name__, NamespaceName__, ((string){7,(uint8_t const*)"console"}));
	assert__1(never__0op__not_equal(get_name__2(name_table__, console_namespace_name__), none));
	Name__0 const *_Nonnull const console_class_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), console_namespace_name__, TypeName__, ((string){7,(uint8_t const*)"Console"}));
	assert__1(never__0op__not_equal(get_name__2(name_table__, console_class_name__), none));
}

void can_get_root_namespace_from_name__0()
{
	Package_Name__0 const *_Nonnull const name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){7,(uint8_t const*)"default"}));
	Package__0 const *_Nonnull const runtime_package__ = build_runtime_library_package__0();
	system__collections__List__1<Package_Reference__0 const *_Nonnull> *_Nonnull const references__ = system__collections__List__1__0new__0<Package_Reference__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Package_Reference__0 const *_Nonnull>)));
	references__->add__1(Package_Reference__0__0new__1(allocate(sizeof(Package_Reference__0)), runtime_package__));
	Syntax_Node__0 const *_Nonnull const package_syntax__ = Syntax_Node__0__0new__4(allocate(sizeof(Syntax_Node__0)), PackageNode__, none, ((int32){0}), ((int32){0}));
	Name_Table__0 const *_Nonnull const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Name__0 const *_Nonnull const namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__0(allocate(sizeof(Name__0))), NamespaceName__, ((string){6,(uint8_t const*)"system"}));
	assert__1(never__0op__not_equal(get_name__2(name_table__, namespace_name__), none));
}

void can_get_Console_class_from_name_without_package__0()
{
	Package_Name__0 const *_Nonnull const name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){7,(uint8_t const*)"default"}));
	Package__0 const *_Nonnull const runtime_package__ = build_runtime_library_package__0();
	system__collections__List__1<Package_Reference__0 const *_Nonnull> *_Nonnull const references__ = system__collections__List__1__0new__0<Package_Reference__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Package_Reference__0 const *_Nonnull>)));
	references__->add__1(Package_Reference__0__0new__1(allocate(sizeof(Package_Reference__0)), runtime_package__));
	Syntax_Node__0 const *_Nonnull const package_syntax__ = Syntax_Node__0__0new__4(allocate(sizeof(Syntax_Node__0)), PackageNode__, none, ((int32){0}), ((int32){0}));
	Name_Table__0 const *_Nonnull const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Name__0 const *_Nonnull const system_namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__0(allocate(sizeof(Name__0))), NamespaceName__, ((string){6,(uint8_t const*)"system"}));
	Name__0 const *_Nonnull const console_namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), system_namespace_name__, NamespaceName__, ((string){7,(uint8_t const*)"console"}));
	Name__0 const *_Nonnull const console_class_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), console_namespace_name__, TypeName__, ((string){7,(uint8_t const*)"Console"}));
	assert__1(never__0op__not_equal(get_name__2(name_table__, console_class_name__), none));
}

void can_get_Optional_class_from_name_with_package__0()
{
	Package_Name__0 const *_Nonnull const name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){7,(uint8_t const*)"default"}));
	Package__0 const *_Nonnull const primitives_package__ = build_primitives_package__0();
	system__collections__List__1<Package_Reference__0 const *_Nonnull> *_Nonnull const references__ = system__collections__List__1__0new__0<Package_Reference__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Package_Reference__0 const *_Nonnull>)));
	references__->add__1(Package_Reference__0__0new__1(allocate(sizeof(Package_Reference__0)), primitives_package__));
	Syntax_Node__0 const *_Nonnull const package_syntax__ = Syntax_Node__0__0new__4(allocate(sizeof(Syntax_Node__0)), PackageNode__, none, ((int32){0}), ((int32){0}));
	Name_Table__0 const *_Nonnull const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Package_Name__0 const *_Nonnull const package_name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){11,(uint8_t const*)"$primitives"}));
	Name__0 const *_Nonnull const adamant_namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__0(allocate(sizeof(Name__0))), NamespaceName__, ((string){7,(uint8_t const*)"adamant"}));
	Name__0 const *_Nonnull const language_namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), adamant_namespace_name__, NamespaceName__, ((string){8,(uint8_t const*)"language"}));
	assert__1(never__0op__not_equal(get_name__2(name_table__, language_namespace_name__), none));
	Name__0 const *_Nonnull const optional_class_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), language_namespace_name__, TypeName__, ((string){8,(uint8_t const*)"optional"}));
	assert__1(never__0op__not_equal(get_name__2(name_table__, optional_class_name__), none));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	add_resource((string){18,(uint8_t const*)"RuntimeLibrary.cpp"}, (string){16956,(uint8_t const*)"#include \"RuntimeLibrary.hpp\"\n\n// -----------------------------------------------------------------------------\n// Static Checks\n// -----------------------------------------------------------------------------\n\n// Because we assume we can cast from char* to uint8_t* they need to be the same size\nstatic_assert(sizeof(char) == sizeof(uint8_t), \"chars must be 8 bits\");\n\n// Because we assume we can cast from uint8_t* to byte* they need to be the same size\nstatic_assert(sizeof(uint8_t) == sizeof(byte), \"bytes must be 8 bits\");\n\n// Testing that the style we use for literals can be used as a const\n// const code_point test_code_point = ((code_point){0xFF});\n// TODO: C allows string literals that are one byte shorter than the array so no null terminator\n// TODO: C also has UTF-8 literals u8\"hello\"\n// const string test_string = ((string){5,(uint8_t const[]){0x34,0x7F,0x45,0xaf,0x69}});\n\n// -----------------------------------------------------------------------------\n// Library Utils\n// -----------------------------------------------------------------------------\n\nvoid lib_assert1(const _Bool condition, char const *_Nonnull code)\n{\n    if(!condition)\n    {\n        printf(\"Assertion failed: %s\", code);\n        exit(70);\n    }\n}\n\nvoid lib_assert2(const _Bool condition, char const *_Nonnull code, char const *_Nonnull message)\n{\n    if(!condition)\n    {\n        printf(\"Assertion failed: %s, %s\", code, message);\n        exit(70);\n    }\n}\n\ninline int32 int32_from(int32_t v) { return (int32){ v }; }\n\n// TODO change this to something like byte_from\nuint8_t code_point__to_char(code_point v)\n{\n    lib_assert(v.value <= 0xFF);\n    return v.value;\n}\n\nchar const * cstr_from(string value)\n{\n    int32_t length = value.byte_length.value;\n    char* buffer = new char[length + 1];\n    memcpy(buffer, value.Buffer, length);\n    buffer[length] = 0;\n    return buffer;\n}\n\nstring string_from_cstr(char const* s)\n{\n    return (string){(int32_t)strlen(s), (uint8_t const*)s};\n}\n\n// -----------------------------------------------------------------------------\n// Primitive Types\n// -----------------------------------------------------------------------------\n\nstring bool_to_string__1(BOOL b)\n{\n    if(cond(b))\n        return (string){4,(uint8_t const*)\"true\"};\n    else\n        return (string){5,(uint8_t const*)\"false\"};\n}\n\nstring int_to_string__1(int32 i)\n{\n    uint8_t* buffer = new uint8_t[12]; // -2,147,483,648 plus null terminator\n    int length = sprintf((char*)buffer, \"%d\", i.value);\n    lib_assert(length > 0);\n    return (string){length, buffer};\n}\nstring int_to_hex_string__1(int32 i)\n{\n    lib_assert(i.value >= 0);\n    uint8_t* buffer = new uint8_t[9]; // FF_FF_FF_FF plus null terminator\n    int length = sprintf((char*)buffer, \"%X\", i.value);\n    lib_assert(length > 0);\n    return (string){length, buffer};\n}\n\nint32 hex_string_to_int__1(string s)\n{\n    char const* cstr = cstr_from(s);\n    int32_t i = strtoul(cstr, NULL, 16);\n    delete[] cstr;\n    return (int32){i};\n}\n\ncode_point int_to_code_point__1(int32 i)\n{\n    lib_assert(i.value >= 0);\n    return (code_point){(uint32_t)i.value};\n}\n\nstring code_point_to_string__1(code_point c)\n{\n    return (string){1, new uint8_t[1] { code_point__to_char(c) }};\n}\n\nstring string__0new__0()\n{\n    return (string){0, 0};\n}\n\nstring string__0new__1(string value)\n{\n    return value;\n}\n\nstring string__0new__2(code_point c, int32 repeat)\n{\n    uint8_t* buffer = new uint8_t[repeat.value];\n    uint8_t ch = code_point__to_char(c);\n    for (int i = 0; i < repeat.value; i++)\n        buffer[i] = ch;\n\n    return (string){repeat, buffer};\n}\n\nstring string__0op__add(string lhs, string rhs)\n{\n    int new_length = lhs.byte_length.value + rhs.byte_length.value;\n    uint8_t* chars = new uint8_t[new_length];\n    size_t offset = sizeof(uint8_t) * lhs.byte_length.value;\n    memcpy(chars, lhs.Buffer, offset);\n    memcpy(chars + offset, rhs.Buffer, rhs.byte_length.value);\n    return (string){new_length, chars};\n}\n\nBOOL string__0op__equal(string lhs, string rhs)\n{\n    if (lhs.byte_length.value != rhs.byte_length.value)\n        return FALSE;\n\n    for (int i = 0; i < lhs.byte_length.value; i++)\n        if (lhs.Buffer[i] != rhs.Buffer[i])\n            return FALSE;\n\n    return TRUE;\n}\n\nBOOL string__0op__lt(string lhs, string rhs)\n{\n    char const* left = cstr_from(lhs);\n    char const* right = cstr_from(rhs);\n    _Bool result = strcmp(left, right) < 0;\n    delete[] left;\n    delete[] right;\n    return bool_from(result);\n}\nBOOL string__0op__lte(string lhs, string rhs)\n{\n    char const* left = cstr_from(lhs);\n    char const* right = cstr_from(rhs);\n    _Bool result = strcmp(left, right) <= 0;\n    delete[] left;\n    delete[] right;\n    return bool_from(result);\n}\nBOOL string__0op__gt(string lhs, string rhs)\n{\n    char const* left = cstr_from(lhs);\n    char const* right = cstr_from(rhs);\n    BOOL result = bool_from(strcmp(left, right) > 0);\n    delete[] left;\n    delete[] right;\n    return result;\n}\nBOOL string__0op__gte(string lhs, string rhs)\n{\n    char const* left = cstr_from(lhs);\n    char const* right = cstr_from(rhs);\n    BOOL result = bool_from(strcmp(left, right) >= 0);\n    delete[] left;\n    delete[] right;\n    return result;\n}\n\nstring substring__3(string s, int32 start, int32 length)\n{\n    // You can ask for a zero length substring at the end of the string\n    lib_assert(start.value <= s.byte_length.value);\n    lib_assert(start.value+length.value <= s.byte_length.value);\n    return (string){length, s.Buffer + start.value};\n}\nstring string_replace__3(string s, string old_value, string new_value)\n{\n    // We make one one the stack then manually call the constructor\n    system__text__String_Builder__0 builder;\n    system__text__String_Builder__0__0new__with_capacity__1(&builder, s.byte_length);\n    int limit = s.byte_length.value - old_value.byte_length.value + 1;\n    int last_index = 0;\n    for(int i=0; i < limit; i++)\n        if(cond(string__0op__equal(substring__3(s, int32_from(i), old_value.byte_length), old_value)))\n        {\n            builder.Append__1(substring__3(s, int32_from(last_index), int32_from(i-last_index)));\n            builder.Append__1(new_value);\n            i += old_value.byte_length.value; // skip over the value we just matched\n            last_index = i;\n            i--; // we need i-- to offset the i++ that is about to happen\n        }\n\n    builder.Append__1(substring__3(s, int32_from(last_index), int32_from(s.byte_length.value - last_index)));\n    return builder.ToString__0();\n}\nint32 string_index_of__2(string s, code_point c)\n{\n    uint8_t value = code_point__to_char(c);\n    for(int i = 0; i < s.byte_length.value; i++)\n        if(s.Buffer[i] == value)\n            return int32_from(i);\n\n    // TODO we should return `int?` and return `none` in this case\n    return int32_from(-1);\n}\nint32 string_last_index_of__2(string s, code_point c)\n{\n    uint8_t value = code_point__to_char(c);\n    for(int i = s.byte_length.value - 1; i >= 0; i--)\n        if(s.Buffer[i] == value)\n            return int32_from(i);\n\n    // TODO we should return `int?` and return `none` in this case\n    return int32_from(-1);\n}\n\n// Operator used when we put strings into a map for resource manager\n_Bool operator < (string const & lhs, string const & rhs)\n{\n    char const* left = cstr_from(lhs);\n    char const* right = cstr_from(rhs);\n    _Bool result = strcmp(left, right) < 0;\n    delete[] left;\n    delete[] right;\n    return result;\n}\n\n// -----------------------------------------------------------------------------\n// Standard Library\n// -----------------------------------------------------------------------------\n\nvoid assert1(const BOOL condition, char const *_Nonnull code, char const *_Nonnull file, const int32_t line)\n{\n    if(!condition.value)\n    {\n        printf(\"Assertion failed: %s, file %s, line %i\", code, file, line);\n        exit(70);\n    }\n}\n\nvoid assert2(const BOOL condition, char const *_Nonnull code, const string message, char const *_Nonnull file, const int32_t line)\n{\n    if(!condition.value)\n    {\n        printf(\"Assertion failed: %s, %s, file %s, line %i\", code, cstr_from(message), file, line);\n        exit(70);\n    }\n}\n\n_Noreturn void NOT_IMPLEMENTED0(char const *_Nonnull function, char const *_Nonnull file, const int32_t line)\n{\n    printf(\"Function %s not yet implemented, %s, line %i\", function, file, line);\n    exit(70);\n}\n\n_Noreturn void NOT_IMPLEMENTED1(const string message, char const *_Nonnull function, char const *_Nonnull file, const int32_t line)\n{\n    printf(\"Function %s not yet implemented, %s, %s, line %i\", function, cstr_from(message), file, line);\n    exit(70);\n}\n\n_Noreturn void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const int32_t line)\n{\n    printf(\"Reached \\\"UNREACHABLE\\\" statement in function %s, %s, line %i\", function, file, line);\n    exit(70);\n}\n\nint32_t resource_count = 0;\nstring resource_name[1024];\nstring resource_value[1024];\n\nvoid add_resource(string name, string value)\n{\n    lib_assert_msg(resource_count < 1024, \"only 1024 resources are currently supported\");\n    resource_name[resource_count] = name;\n    resource_value[resource_count] = value;\n    resource_count += 1;\n}\n\nstring get_resource__1(string name)\n{\n    for(int32_t i=0; i < resource_count; i++)\n        if(cond(string__0op__equal(resource_name[i], name)))\n            return resource_value[i];\n\n    lib_assert_msg(false, cstr_from(name));\n    UNREACHABLE__0();\n}\n\nvoid debug_write__1(string value)\n{\n    fprintf(stderr, \"%.*s\", value.byte_length.value, value.Buffer);\n}\nvoid debug_write_line__1(string value)\n{\n    fprintf(stderr, \"%.*s\\n\", value.byte_length.value, value.Buffer);\n}\nvoid debug_write_line__0()\n{\n    fprintf(stderr, \"\\n\");\n}\n\nbool string__0next(string__0iter*_Nonnull iter)\n{\n    iter->current++;\n    if(iter->current >= iter->count)\n    {\n        iter->current = iter->count; // prevent current from further increase\n        return false;\n    }\n    return true;\n}\n\nStrings__0 *_Nonnull Strings__0__0new__0(Strings__0 *_Nonnull self)\n{\n    self->values = NULL;\n    self->count__ = {0};\n    self->capacity__ = {0};\n    return self;\n}\n\nvoid add_string__2(Strings__0 *_Nonnull strings, string value)\n{\n    if(strings->count__.value >= strings->capacity__.value)\n    {\n        int32_t new_capacity = strings->capacity__.value == 0 ? 16 : strings->capacity__.value * 2;\n        // Allocate uninitalized buffer (note `sizeof(char) == 1` always)\n        // Needed if T is a value type to avoid needing a default constructor\n        string* new_values = (string*)new char[new_capacity * sizeof(string)];\n        memcpy(new_values, strings->values, strings->count__.value * sizeof(string));\n        if(strings->capacity__.value != 0)\n            delete[] strings->values; // delete the old array\n        strings->values = new_values;\n        strings->capacity__ = {new_capacity};\n    }\n    strings->values[strings->count__.value] = value;\n    strings->count__.value++;\n}\n\nbool int__0next(int__0iter*_Nonnull iter)\n{\n    iter->current++;\n    if(iter->current >= iter->count)\n    {\n        iter->current = iter->count; // prevent current from further increase\n        return false;\n    }\n    return true;\n}\n\nInts__0 *_Nonnull Ints__0__0new__0(Ints__0 *_Nonnull self)\n{\n    self->values = NULL;\n    self->count__ = {0};\n    self->capacity__ = {0};\n    return self;\n}\n\nvoid add_int__2(Ints__0 *_Nonnull ints, int32 value)\n{\n    if(ints->count__.value >= ints->capacity__.value)\n    {\n        int32_t new_capacity = ints->capacity__.value == 0 ? 16 : ints->capacity__.value * 2;\n        // Allocate uninitalized buffer (note `sizeof(char) == 1` always)\n        // Needed if T is a value type to avoid needing a default constructor\n        int32* new_values = (int32*)new char[new_capacity * sizeof(int32)];\n        memcpy(new_values, ints->values, ints->count__.value * sizeof(int32));\n        if(ints->capacity__.value != 0)\n            delete[] ints->values; // delete the old array\n        ints->values = new_values;\n        ints->capacity__ = {new_capacity};\n    }\n    ints->values[ints->count__.value] = value;\n    ints->count__.value++;\n}\n\nbool void_ptr__0next(void_ptr__0iter*_Nonnull iter)\n{\n    iter->current++;\n    if(iter->current >= iter->count)\n    {\n        iter->current = iter->count; // prevent current from further increase\n        return false;\n    }\n    return true;\n}\n\nvoid system__console__Console__0::Write__1(string value)\n{\n    printf(\"%.*s\", value.byte_length.value, value.Buffer);\n}\n\nvoid system__console__Console__0::WriteLine__1(string value)\n{\n    printf(\"%.*s\\n\", value.byte_length.value, value.Buffer);\n}\n\nvoid system__console__Console__0::WriteLine__0()\n{\n    printf(\"\\n\");\n}\n\nsystem__console__Arguments__0::system__console__Arguments__0(int argc, char const *const * argv)\n    : Count(argc-1)\n{\n    values = new string[Count];\n    for (int i = 0; i < Count; i++)\n        values[i] = string_from_cstr(argv[i+1]);\n}\n\nsystem__io__File_Reader__0 *_Nonnull system__io__File_Reader__0__0new__1(system__io__File_Reader__0 *_Nonnull self, const string& fileName)\n{\n    char const *_Nonnull fname = cstr_from(fileName);\n    self->file= fopen(fname, \"rb\"); // TODO check for error\n    delete[] fname;\n    return self;\n}\n\nstring system__io__File_Reader__0::ReadToEndSync__0()\n{\n    fseek(file, 0, SEEK_END);\n    auto length = ftell(file);\n    fseek(file, 0, SEEK_SET);\n    auto buffer = new uint8_t[length];\n    length = fread(buffer, sizeof(uint8_t), length, file);\n    return (string){(int32_t)length, buffer};\n}\n\nvoid system__io__File_Reader__0::Close__0()\n{\n    fclose(file);\n}\n\nsystem__io__File_Writer__0 *_Nonnull system__io__File_Writer__0__0new__1(system__io__File_Writer__0 *_Nonnull self, const string& fileName)\n{\n    char const *_Nonnull fname = cstr_from(fileName);\n    self->file = fopen(fname, \"wb\"); // TODO check error\n    delete[] fname;\n    return self;\n}\n\nvoid system__io__File_Writer__0::Write__1(const string& value)\n{\n    fwrite(value.Buffer, sizeof(char), value.byte_length.value, file);\n}\n\nvoid system__io__File_Writer__0::Close__0()\n{\n    fclose(file);\n}\n\nvoid system__text__String_Builder__0::ensure_capacity(int needed)\n{\n    int new_capacity = capacity == 0 ? 128 : capacity;\n    while(new_capacity < needed)\n    {\n        new_capacity *= 2;\n    }\n\n    if(new_capacity > capacity)\n    {\n        uint8_t* new_buffer = new uint8_t[new_capacity];\n        if(length > 0)\n            memcpy(new_buffer, buffer, length*sizeof(uint8_t));\n\n        if(capacity > 0)\n            delete[] buffer;\n\n        buffer = new_buffer;\n        capacity = new_capacity;\n    }\n}\n\nsystem__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__1(system__text__String_Builder__0 *_Nonnull self, string const & value)\n{\n    system__text__String_Builder__0__0new__0(self);\n    self->ensure_capacity(value.byte_length.value);\n    memcpy(self->buffer, value.Buffer, value.byte_length.value);\n    self->length = value.byte_length.value;\n    return self;\n}\n\nsystem__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__with_capacity__1(system__text__String_Builder__0 *_Nonnull self, int32 capacity)\n{\n    system__text__String_Builder__0__0new__0(self);\n    self->ensure_capacity(capacity.value);\n    return self;\n}\n\nvoid system__text__String_Builder__0::Append__1(string const & value)\n{\n    int new_length = length + value.byte_length.value;\n    ensure_capacity(new_length);\n    memcpy(buffer+length, value.Buffer, value.byte_length.value);\n    length = new_length;\n}\n\nvoid system__text__String_Builder__0::Append__1(system__text__String_Builder__0 const *_Nonnull value)\n{\n    int new_length = length + value->length;\n    ensure_capacity(new_length);\n    memcpy(buffer+length, value->buffer, value->length);\n    length = new_length;\n}\n\nvoid system__text__String_Builder__0::AppendLine__1(string const & value)\n{\n    int new_length = length + value.byte_length.value + 1;\n    ensure_capacity(new_length);\n    memcpy(buffer+length, value.Buffer, value.byte_length.value);\n    buffer[new_length-1] = '\\n';\n    length = new_length;\n}\n\nvoid system__text__String_Builder__0::AppendLine__0()\n{\n    int new_length = length + 1;\n    ensure_capacity(new_length);\n    buffer[new_length-1] = '\\n';\n    length = new_length;\n}\n\nvoid system__text__String_Builder__0::Remove__2(int32 start, int32 length)\n{\n    lib_assert(start.value < this->length);\n\n    int end = start.value + length.value;\n    lib_assert(end <= this->length); // less than or equal because end is one past the end of the remove\n\n    memmove(buffer+start.value, buffer+end, this->length-end);\n    this->length -= length.value;\n}\n\nvoid system__text__String_Builder__0::Remove__1(int32 start)\n{\n    lib_assert(start.value < length);\n    length = start.value;\n}\n\nstring system__text__String_Builder__0::ToString__0()\n{\n    string result = {length, buffer};\n    // give up ownership of buffer\n    buffer = 0;\n    length = 0;\n    capacity = 0;\n    return result;\n}\n"});
	add_resource((string){18,(uint8_t const*)"RuntimeLibrary.hpp"}, (string){17552,(uint8_t const*)"// On windows this disables warnings about using fopen_s instead of fopen\n// It must be defined before including the headers.\n#define _CRT_SECURE_NO_WARNINGS\n\n#include <stdlib.h>\n#include <string.h>\n#include <stdio.h>\n#include <stdint.h>\n\n// TODO C: Consider using *_s versions of standard lib functions\n\n// -----------------------------------------------------------------------------\n// C++ Compatibility\n// -----------------------------------------------------------------------------\n// This section defines things that make C++ behave more like C so we can make\n// the transition to C.\n#ifdef __cplusplus\n\n// Use `_Bool` as the native bool type\n#define _Bool bool\n\n// This type is used to emulate C style void pointers in C++. That is, they\n// implictly convert to/from other pointer types.\nclass void_ptr\n{\nprivate:\n    void *_Nullable ptr;\npublic:\n    template<class T>\n    void_ptr(T *_Nullable value) : ptr((void *_Nullable)value) {}\n    template<class T>\n    operator T *_Nullable() const { return (T *)ptr; }\n\n    _Bool operator==(void_ptr rhs) const { return ptr == rhs.ptr; }\n    template<class T>\n    _Bool operator==(T *_Nullable rhs) const { return ptr == rhs; }\n\n    _Bool operator!=(void_ptr rhs) const { return ptr != rhs.ptr; }\n    template<class T>\n    _Bool operator!=(T *_Nullable rhs) const { return ptr != rhs; }\n};\n\n#else\n\n#define void_ptr void*_Nullable\n\n#endif\n\n// -----------------------------------------------------------------------------\n// Library Utils\n// -----------------------------------------------------------------------------\n\n#define lib_assert(condition) lib_assert1(condition, #condition)\nvoid lib_assert1(const _Bool condition, char const *_Nonnull code);\n#define lib_assert_msg(condition, message) lib_assert2(condition, #condition, message)\nvoid lib_assert2(const _Bool condition, char const *_Nonnull code, char const *_Nonnull message);\n\ninline void_ptr allocate(size_t bytes)\n{\n    return malloc(bytes);\n}\n\n// -----------------------------------------------------------------------------\n// Primitive Types\n// -----------------------------------------------------------------------------\n\ntypedef struct never never;\ntypedef struct optional__never optional__never;\ntypedef struct BOOL BOOL;\ntypedef struct int32 int32;\ntypedef struct byte byte;\ntypedef struct code_point code_point;\ntypedef struct string string;\n\n// `never` type\nstruct never\n{\n};\n\n// `never?` type\nstruct optional__never\n{\n};\n\n// TODO this is a hack for now, the type of `none` should be `never?`\nstatic const void_ptr none = (void*)0;\n\n// For now, use `BOOL` as the emitted type\n// TODO C: switch `BOOL` to `bool`\n// TODO C: switch `TRUE` to `true`\n// TODO C: switch `FALSE` to `false`\n\n// `bool` type\nstruct BOOL\n{\n    _Bool value;\n};\n\nstatic const BOOL TRUE = { 1 };\nstatic const BOOL FALSE = { 0 };\n\n// Function used in conditions to make them take `bool`\ninline _Bool cond(BOOL cond) { return cond.value; }\n\n// Used by runtime for converting to bool\ninline BOOL bool_from(_Bool b) { return (BOOL){ b }; }\n\n// Wrap a bool operation that is bool based\ninline BOOL bool_op(_Bool b) { return (BOOL){ b }; }\n// Convert the arguments of a logical operation to bool\ninline _Bool bool_arg(BOOL b) { return b.value; }\n\ninline BOOL BOOL__0op__not(BOOL b) { return (BOOL){ !b.value }; }\n\nstring bool_to_string__1(BOOL b);\n\n// `int` type\nstruct int32\n{\n    int32_t value;\n};\n\ninline void op__add_assign(int32*_Nonnull lhs, int32 rhs) { lhs->value += rhs.value; }\ninline void op__sub_assign(int32*_Nonnull lhs, int32 rhs) { lhs->value -= rhs.value; }\ninline int32 int32__0op__neg(int32 v) { return (int32){-v.value}; }\ninline int32 int32__0op__add(int32 lhs, int32 rhs) { return (int32){ lhs.value + rhs.value}; }\ninline int32 int32__0op__sub(int32 lhs, int32 rhs) { return (int32){ lhs.value - rhs.value}; }\ninline int32 int32__0op__mul(int32 lhs, int32 rhs) { return (int32){ lhs.value * rhs.value}; }\ninline int32 int32__0op__div(int32 lhs, int32 rhs) { return (int32){ lhs.value / rhs.value}; }\ninline int32 int32__0op__remainder(int32 lhs, int32 rhs) { return (int32){ lhs.value % rhs.value}; }\ninline BOOL int32__0op__lt(int32 lhs, int32 rhs) { return bool_from(lhs.value < rhs.value); }\ninline BOOL int32__0op__lte(int32 lhs, int32 rhs) { return bool_from(lhs.value <= rhs.value); }\ninline BOOL int32__0op__gt(int32 lhs, int32 rhs) { return bool_from(lhs.value > rhs.value); }\ninline BOOL int32__0op__gte(int32 lhs, int32 rhs) { return bool_from(lhs.value >= rhs.value); }\n\nstring int_to_string__1(int32 i);\nstring int_to_hex_string__1(int32 i);\nint32 hex_string_to_int__1(string s);\ncode_point int_to_code_point__1(int32 i);\n\nstruct byte\n{\n    uint8_t value;\n};\n\nstruct code_point\n{\n    // don't use something like char32_t because C's handling of chars sucks\n    uint32_t value;\n};\n\ninline BOOL code_point__0op__lt(code_point lhs, code_point rhs) { return bool_from(lhs.value < rhs.value); }\ninline BOOL code_point__0op__lte(code_point lhs, code_point rhs) { return bool_from(lhs.value <= rhs.value); }\ninline BOOL code_point__0op__gt(code_point lhs, code_point rhs) { return bool_from(lhs.value > rhs.value); }\ninline BOOL code_point__0op__gte(code_point lhs, code_point rhs) { return bool_from(lhs.value >= rhs.value); }\n\ninline int32 code_point_as_int__1(code_point c) { return (int32){(int32_t)c.value}; }\nstring code_point_to_string__1(code_point c);\n\nstruct string\n{\n    int32 byte_length; // TODO rename to just byte_length, though there will be a byte_length\n    // property in the future, it doesn't make sense to directly expose it right now because this is\n    // not the correct implementation.\n\n    // don't use chars because C's handling of chars sucks\n    uint8_t const *_Nonnull Buffer; // TODO use byte and rename to `bytes`\n};\n\nstring string__0new__0();\nstring string__0new__1(string value);\nstring string__0new__2(code_point c, int32 repeat);\n\nstring string__0op__add(string lhs, string rhs);\nBOOL string__0op__lt(string lhs, string rhs);\nBOOL string__0op__lte(string lhs, string rhs);\nBOOL string__0op__gt(string lhs, string rhs);\nBOOL string__0op__gte(string lhs, string rhs);\ninline code_point string__0__0op__element(string value, int32 index)\n{\n    lib_assert(index.value >= 0 && index.value < value.byte_length.value);\n    return (code_point){value.Buffer[index.value]};\n}\n\ninline int32 string_byte_length__1(string s) { return s.byte_length; }\nstring substring__3(string s, int32 start, int32 length);\ninline string substring__2(string s, int32 start) { return substring__3(s, start, (int32){s.byte_length.value-start.value}); }\nstring string_replace__3(string s, string old_value, string new_value);\nint32 string_index_of__2(string s, code_point c);\nint32 string_last_index_of__2(string s, code_point c);\n\n// -----------------------------------------------------------------------------\n// Operators\n// -----------------------------------------------------------------------------\n\ninline BOOL BOOL__0op__equal(BOOL lhs, BOOL rhs)\n{\n    return bool_from(lhs.value == rhs.value);\n}\ninline BOOL int32__0op__equal(int32 lhs, int32 rhs)\n{\n    return bool_from(lhs.value == rhs.value);\n}\ninline BOOL code_point__0op__equal(code_point lhs, code_point rhs)\n{\n    return bool_from(lhs.value == rhs.value);\n}\nBOOL string__0op__equal(string lhs, string rhs);\n// TODO this currently exists becuase of the compare `none`, it shouldn't exist\ninline BOOL never__0op__equal(void_ptr lhs, void_ptr rhs)\n{\n    return bool_from(lhs == rhs);\n}\ninline BOOL void_ptr__0op__equal(void_ptr lhs, void_ptr rhs)\n{\n    return bool_from(lhs == rhs);\n}\n\ninline BOOL BOOL__0op__not_equal(BOOL lhs, BOOL rhs)\n{\n    return bool_from(lhs.value != rhs.value);\n}\ninline BOOL int32__0op__not_equal(int32 lhs, int32 rhs)\n{\n    return bool_from(lhs.value != rhs.value);\n}\ninline BOOL code_point__0op__not_equal(code_point lhs, code_point rhs)\n{\n    return bool_from(lhs.value != rhs.value);\n}\ninline BOOL string__0op__not_equal(string lhs, string rhs)\n{\n    return BOOL__0op__not(string__0op__equal(lhs, rhs));\n}\n// TODO this currently exists becuase of the compare `none`, it shouldn't exist\ninline BOOL never__0op__not_equal(void_ptr lhs, void_ptr rhs)\n{\n    return bool_from(lhs != rhs);\n}\ninline BOOL void_ptr__0op__not_equal(void_ptr lhs, void_ptr rhs)\n{\n    return bool_from(lhs != rhs);\n}\n\n// -----------------------------------------------------------------------------\n// Standard Library\n// -----------------------------------------------------------------------------\n// Parts of the standard library that are currently implemented in the runtime.\n\ntypedef struct string__0iter string__0iter;\ntypedef struct Strings__0 Strings__0;\ntypedef struct int__0iter int__0iter;\ntypedef struct Ints__0 Ints__0;\ntypedef struct void_ptr__0iter void_ptr__0iter;\n\ninline void_ptr allocate__1(int32 bytes)\n{\n    return malloc(bytes.value);\n}\n\ninline void free__1(void_ptr object)\n{\n    free(object);\n}\n\n#define assert__1(condition) assert1(condition, #condition, __FILE__, __LINE__)\n#define assert__2(condition, message) assert2(condition, #condition, message, __FILE__, __LINE__)\nvoid assert1(const BOOL condition, char const *_Nonnull code, char const *_Nonnull file, const int32_t line);\nvoid assert2(const BOOL condition, char const *_Nonnull code, const string message, char const *_Nonnull file, const int32_t line);\n\n#define NOT_IMPLEMENTED__0() NOT_IMPLEMENTED0(__func__, __FILE__, __LINE__)\n#define NOT_IMPLEMENTED__1(message) NOT_IMPLEMENTED1(message, __func__, __FILE__, __LINE__)\n_Noreturn void NOT_IMPLEMENTED0(char const *_Nonnull function, char const *_Nonnull file, const int32_t line);\n_Noreturn void NOT_IMPLEMENTED1(const string message, char const *_Nonnull function, char const *_Nonnull file, const int32_t line);\n\n#define UNREACHABLE__0() UNREACHABLE(__func__, __FILE__, __LINE__)\n_Noreturn void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const int32_t line);\n\nstring get_resource__1(string resource_name);\nvoid add_resource(string name, string value);\n\nvoid debug_write__1(string value);\nvoid debug_write_line__1(string value);\nvoid debug_write_line__0();\n\nstruct string__0iter\n{\n    string *_Nonnull values;\n    int32_t current;\n    int32_t count;\n};\n\nbool string__0next(string__0iter*_Nonnull iter);\ninline string string__0current(string__0iter const*_Nonnull iter)\n{\n    lib_assert(iter->current >= 0 && iter->current < iter->count);\n    return iter->values[iter->current];\n}\n\nstruct Strings__0\n{\n    string *_Nonnull values;\n    int32 count__;\n    int32 capacity__;\n};\n\nStrings__0 *_Nonnull Strings__0__0new__0(Strings__0 *_Nonnull self);\ninline string Strings__0__0op__element(Strings__0 const*_Nonnull strings, int32 const index)\n{\n    lib_assert(index.value >= 0 && index.value < strings->count__.value);\n    return strings->values[index.value];\n}\ninline void clear_strings__1(Strings__0 *_Nonnull strings)\n{\n    strings->count__ = {0};\n}\nvoid add_string__2(Strings__0 *_Nonnull strings, string value);\ninline string__0iter Strings__0__0iterate(Strings__0 const *_Nonnull strings)\n{\n    return (string__0iter)\n    {\n        .values = strings->values,\n        .current = -1,\n        .count = strings->count__.value\n    };\n}\ninline string__0iter string__0iterate(Strings__0 const *_Nonnull strings)\n{\n    return (string__0iter)\n    {\n        .values = strings->values,\n        .current = -1,\n        .count = strings->count__.value\n    };\n}\n\nstruct int__0iter\n{\n    int32 *_Nonnull values;\n    int32_t current;\n    int32_t count;\n};\n\nbool int__0next(int__0iter*_Nonnull iter);\ninline int32 int__0current(int__0iter const*_Nonnull iter)\n{\n    lib_assert(iter->current >= 0 && iter->current < iter->count);\n    return iter->values[iter->current];\n}\n\nstruct Ints__0\n{\n    int32 *_Nonnull values;\n    int32 count__;\n    int32 capacity__;\n};\n\nInts__0 *_Nonnull Ints__0__0new__0(Ints__0 *_Nonnull self);\ninline int32 Ints__0__0op__element(Ints__0 const*_Nonnull ints, int32 const index)\n{\n    lib_assert(index.value >= 0 && index.value < ints->count__.value);\n    return ints->values[index.value];\n}\ninline void clear_ints__1(Ints__0 *_Nonnull ints)\n{\n    ints->count__ = {0};\n}\nvoid add_int__2(Ints__0 *_Nonnull ints, int32 value);\ninline int__0iter Ints__0__0iterate(Ints__0 const*_Nonnull ints)\n{\n    return int__0iter\n    {\n        .values = ints->values,\n        .current = -1,\n        .count = ints->count__.value\n    };\n}\ninline int__0iter int__0iterate(Ints__0 const*_Nonnull ints)\n{\n    return int__0iter\n    {\n        .values = ints->values,\n        .current = -1,\n        .count = ints->count__.value\n    };\n}\n\nstruct void_ptr__0iter\n{\n    void_ptr *_Nonnull values;\n    int32_t current;\n    int32_t count;\n};\n\nbool void_ptr__0next(void_ptr__0iter*_Nonnull iter);\ninline void_ptr void_ptr__0current(void_ptr__0iter const*_Nonnull iter)\n{\n    lib_assert(iter->current >= 0 && iter->current < iter->count);\n    return iter->values[iter->current];\n}\n\ntemplate<typename T>\nstruct system__collections__List__1\n{\n    T *_Nonnull values;\n    int32 count__;\n    int32 capacity__;\n\n    // Adamant Members\n    void add__1(T value);\n    void clear__0() { count__ = {0}; }\n};\n\ntemplate<typename T>\nvoid system__collections__List__1<T>::add__1(T value)\n{\n    if(count__.value >= capacity__.value)\n    {\n        int32_t newCapacity = capacity__.value == 0 ? 16 : capacity__.value * 2;\n        // Allocate uninitalized buffer (note `sizeof(char) == 1` always)\n        // Needed if T is a value type to avoid needing a default constructor\n        T* newValues = (T*)new char[newCapacity * sizeof(T)];\n        memcpy(newValues, values, count__.value * sizeof(T));\n        if(capacity__.value != 0)\n            delete[] values; // delete the old array\n        values = newValues;\n        capacity__ = (int32){newCapacity};\n    }\n    values[count__.value] = value;\n    count__.value++;\n}\n\ntemplate<typename T>\nT system__collections__List__1__0op__element(system__collections__List__1<T> const*_Nonnull list, int32 const index)\n{\n    lib_assert(index.value >= 0 && index.value < list->count__.value);\n    return list->values[index.value];\n}\n\ntemplate<typename T>\nsystem__collections__List__1<T> *_Nonnull system__collections__List__1__0new__0(system__collections__List__1<T> *_Nonnull self)\n{\n    self->values = NULL;\n    self->count__ = {0};\n    self->capacity__ = {0};\n    return self;\n}\n\ntemplate<typename T>\nvoid_ptr__0iter system__collections__List__1__0iterate(system__collections__List__1<T> const *_Nonnull list)\n{\n    return (void_ptr__0iter)\n    {\n        .values = (void_ptr*_Nonnull)list->values, // force cast could be bad if T is not a pointer\n        .current = -1,\n        .count = list->count__.value\n    };\n}\n\ntemplate<typename T>\nvoid_ptr__0iter void_ptr__0iterate(system__collections__List__1<T> const *_Nonnull list)\n{\n    return (void_ptr__0iter)\n    {\n        .values = (void_ptr*_Nonnull)list->values, // force cast could be bad if T is not a pointer\n        .current = -1,\n        .count = list->count__.value\n    };\n}\n\nclass system__console__Console__0\n{\npublic:\n    void Write__1(string value);\n    void WriteLine__1(string value);\n    void WriteLine__0();\n};\n\nstruct system__console__Arguments__0\n{\n    string *_Nonnull values;\n\n    system__console__Arguments__0(int argc, char const *_Nonnull const *_Nonnull argv);\n\n    const int Count;\n\n    // Adamant Members\n    int32 op__magnitude() const { return (int32){Count}; }\n};\n\ninline string system__console__Arguments__0__0op__element(system__console__Arguments__0 const*_Nonnull arguments, int32 const index)\n{\n    lib_assert(index.value >= 0 && index.value < arguments->Count);\n    return arguments->values[index.value];\n}\n\ninline string__0iter system__console__Arguments__0__0iterate(system__console__Arguments__0 const*_Nonnull arguments)\n{\n    return (string__0iter)\n    {\n        .values = arguments->values,\n        .current = -1,\n        .count = arguments->Count\n    };\n}\n\nstruct system__io__File_Reader__0\n{\n    FILE *_Nonnull file;\n\n    string ReadToEndSync__0();\n    void Close__0();\n};\n\nsystem__io__File_Reader__0 *_Nonnull system__io__File_Reader__0__0new__1(system__io__File_Reader__0 *_Nonnull self, const string& fileName);\n\nstruct system__io__File_Writer__0\n{\n    FILE *_Nonnull file;\n\n    void Write__1(const string& value);\n    void Close__0();\n};\n\nsystem__io__File_Writer__0 *_Nonnull system__io__File_Writer__0__0new__1(system__io__File_Writer__0 *_Nonnull self, const string& fileName);\n\nstruct system__text__String_Builder__0\n{\n    uint8_t *_Nullable buffer;\n    int capacity;\n    int length;\n    void ensure_capacity(int needed);\n\n    // Adamant Members\n    // TODO byte_length should be a property\n    int32 byte_length__0() const { return (int32){length}; }\n    void Append__1(string const & value);\n    void Append__1(system__text__String_Builder__0 const *_Nonnull value);\n    void AppendLine__1(string const& value);\n    void AppendLine__0();\n    void Remove__2(int32 start, int32 length);\n    void Remove__1(int32 start);\n    string ToString__0();\n};\n\ninline system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__0(system__text__String_Builder__0 *_Nonnull self)\n{\n    self->buffer = 0;\n    self->capacity = 0;\n    self->length = 0;\n    return self;\n}\n\nsystem__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__1(system__text__String_Builder__0 *_Nonnull self, string const & value);\nsystem__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__with_capacity__1(system__text__String_Builder__0 *_Nonnull self, int32 capacity);\n"});

	return main__2(new system__console__Console__0(), new system__console__Arguments__0(argc, argv)).value;
}
