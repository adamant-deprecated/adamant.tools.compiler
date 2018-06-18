#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type__ID = 0,
	Source_Text__0__0Type_ID,
	Text_Line__0__0Type_ID,
	Text_Lines__0__0Type_ID,
	Text_Position__0__0Type_ID,
	Text_Span__0__0Type_ID,
	Source_File_Builder__0__0Type_ID,
	Compilation_Unit__0__0Type_ID,
	Package__0__0Type_ID,
	Package_Reference__0__0Type_ID,
	Program_Fragment__0__0Type_ID,
	Semantic_Node__0__0Type_ID,
	Semantic_Tree_Builder__0__0Type_ID,
	Compilation_Unit_Parser__0__0Type_ID,
	Syntax__0__0Type_ID,
	Syntax_Node__0__0Type_ID,
	Token__0__0Type_ID,
	Token_Stream__0__0Type_ID,
	Diagnostic__0__0Type_ID,
	Emitter__0__0Type_ID,
	Expression__0__0Type_ID,
	Integer_Literal_Expression__0__0Type_ID,
	Literal_Expression__0__0Type_ID,
	Negate_Expression__0__0Type_ID,
	Unary_Expression__0__0Type_ID,
	Name__0__0Type_ID,
	Package_Name__0__0Type_ID,
	Symbol__0__0Type_ID,
	Type__0__0Type_ID,
	Name_Subtable__0__0Type_ID,
	Name_Table__0__0Type_ID,
};
typedef enum Type_ID Type_ID;

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
typedef struct Program_Fragment__0 Program_Fragment__0;
typedef struct Semantic_Node__0 Semantic_Node__0;
typedef struct Semantic_Tree_Builder__0 Semantic_Tree_Builder__0;
typedef struct Compilation_Unit_Parser__0 Compilation_Unit_Parser__0;
typedef struct Syntax__0 Syntax__0;
typedef struct Syntax_Node__0 Syntax_Node__0;
typedef struct Token__0 Token__0;
typedef struct Token_Stream__0 Token_Stream__0;
typedef struct Diagnostic__0 Diagnostic__0;
typedef struct Emitter__0 Emitter__0;
typedef struct Expression__0 Expression__0;
typedef struct Integer_Literal_Expression__0 Integer_Literal_Expression__0;
typedef struct Literal_Expression__0 Literal_Expression__0;
typedef struct Negate_Expression__0 Negate_Expression__0;
typedef struct Unary_Expression__0 Unary_Expression__0;
typedef struct Name__0 Name__0;
typedef struct Package_Name__0 Package_Name__0;
typedef struct Symbol__0 Symbol__0;
typedef struct Type__0 Type__0;
typedef struct Name_Subtable__0 Name_Subtable__0;
typedef struct Name_Table__0 Name_Table__0;

// Function Declarations
Package__0 const ref mut compile__1(system__collections__List__1 const ref const sources__);
void mut console_write_diagnostics__2(system__console__Console__0 mut ref const console__, system__collections__List__1 const ref const diagnostics__);
BOOL mut has_errors__1(system__collections__List__1 const ref const diagnostics__);
int32 mut main__2(system__console__Console__0 mut ref const console__, system__console__Arguments__0 const ref const args__);
Source_Text__0 const ref mut read_source__1(string const path__);
void mut run_unit_tests__1(system__console__Console__0 mut ref const console__);
Source_Text__0 mut ref mut Source_Text__0__0new__3(Source_Text__0 mut ref const self, string const package__, string const path__, string const text__);
Ints__0 const ref mut line_starts__1(string const text__);
int32 mut source_byte_length__1(Source_Text__0 const ref const source__);
Text_Position__0 const ref mut position_of_start__2(Source_Text__0 const ref const source__, Text_Span__0 const ref const span__);
Text_Line__0 mut ref mut Text_Line__0__0new__3(Text_Line__0 mut ref const self, Source_Text__0 const ref const source__, int32 const start__, int32 const length__);
Text_Line__0 mut ref mut Text_Line__0__0new__spanning__3(Text_Line__0 mut ref const self, Source_Text__0 const ref const source__, int32 const start__, int32 const end__);
Text_Lines__0 mut ref mut Text_Lines__0__0new__2(Text_Lines__0 mut ref const self, Source_Text__0 const ref const source__, Ints__0 const ref const start_of_line__);
int32 mut line_count__1(Text_Lines__0 const ref const lines__);
Text_Line__0 const ref mut get_line__2(Text_Lines__0 const ref const lines__, int32 const line_number__);
int32 mut line_containing_offset__2(Text_Lines__0 const ref const lines__, int32 const character_offset__);
Text_Position__0 mut ref mut Text_Position__0__0new__3(Text_Position__0 mut ref const self, int32 const character_offset__, int32 const line__, int32 const column__);
void mut unit_test_Text_Position__0();
void mut Text_Position_retains_given_offeset_line_and_column__0();
Text_Span__0 mut ref mut Text_Span__0__0new__2(Text_Span__0 mut ref const self, int32 const start__, int32 const length__);
string mut format_error__1(string const message__);
Source_File_Builder__0 mut ref mut Source_File_Builder__0__0new__0(Source_File_Builder__0 mut ref const self);
void mut error__2(Source_File_Builder__0 mut ref const file__, string const message__);
void mut begin_line__2(Source_File_Builder__0 mut ref const file__, string const value__);
void mut write__2(Source_File_Builder__0 mut ref const file__, string const value__);
void mut end_line__2(Source_File_Builder__0 mut ref const file__, string const value__);
void mut write_line__2(Source_File_Builder__0 mut ref const file__, string const value__);
void mut blank_line__1(Source_File_Builder__0 mut ref const file__);
void mut element_separator_line__1(Source_File_Builder__0 mut ref const file__);
void mut statement_separator_line__1(Source_File_Builder__0 mut ref const file__);
void mut begin_block__1(Source_File_Builder__0 mut ref const file__);
void mut begin_block_with__2(Source_File_Builder__0 mut ref const file__, string const value__);
void mut end_block__1(Source_File_Builder__0 mut ref const file__);
void mut end_block_with_semicolon__1(Source_File_Builder__0 mut ref const file__);
void mut end_block_with__2(Source_File_Builder__0 mut ref const file__, string const value__);
int32 mut byte_length__1(Source_File_Builder__0 const ref const file__);
string mut to_string__1(Source_File_Builder__0 mut ref const file__);
Compilation_Unit__0 mut ref mut Compilation_Unit__0__0new__2(Compilation_Unit__0 mut ref const self, Syntax_Node__0 const ref const syntax__, system__collections__List__1 const ref const declarations__);
void mut collect_diagnostics__2(Compilation_Unit__0 const ref const compilation_unit__, system__collections__List__1 mut ref const diagnostics__);
Package__0 mut ref mut Package__0__0new__4(Package__0 mut ref const self, Package_Name__0 const ref const name__, system__collections__List__1 const ref const references__, system__collections__List__1 const ref const compilation_units__, Symbol__0 const ref const symbol__);
system__collections__List__1 const ref mut all_diagnostics__1(Package__0 const ref const package__);
Package_Reference__0 mut ref mut Package_Reference__0__0new__1(Package_Reference__0 mut ref const self, Package__0 const ref const package__);
Package_Reference__0 mut ref mut Package_Reference__0__0new__2(Package_Reference__0 mut ref const self, string const name__, Package__0 const ref const package__);
Package__0 const ref mut build_primitives_package__0();
system__collections__List__1 mut ref mut build_primitive_symbols__1(Package_Name__0 const ref const package_name__);
Symbol__0 const ref mut build_adamant_language_namespace_symbol__1(Name__0 const ref const global_namespace__);
Symbol__0 const ref mut build_optional_type_symbol__1(Name__0 const ref const language_namespace__);
Symbol__0 const ref mut build_primitive_symbol__2(string const name__, Name__0 const ref const namespace__);
void mut build_fixed_point_primitives__3(system__collections__List__1 mut ref const symbols__, int32 const bits__, Name__0 const ref const namespace__);
void mut unit_test_build_primitives_package__0();
void mut Package_name_is_dollar_primitives__0();
void mut Package_has_no_references_or_compilation_units__0();
void mut Package_symbol_has_package_name__0();
void mut Package_symbol_has_children__0();
void mut Package_contains_the_string_type__0();
void mut Package_contains_optional_type__0();
Program_Fragment__0 mut ref mut Program_Fragment__0__0new__0(Program_Fragment__0 mut ref const self);
Package__0 const ref mut build_runtime_library_package__0();
system__collections__List__1 mut ref mut build_runtime_library_symbols__1(Package_Name__0 const ref const package_name__);
Symbol__0 const ref mut build_function_symbol__1(Name__0 const ref const name__);
Symbol__0 const ref mut build_namespace_symbol__2(Name__0 const ref const name__, system__collections__List__1 const ref const symbols__);
Symbol__0 const ref mut build_class_symbol__2(Name__0 const ref const namespace__, string const class_name__);
Symbol__0 const ref mut build_class_symbol__3(Name__0 const ref const namespace__, string const class_name__, system__collections__List__1 const ref const children__);
Symbol__0 const ref mut build_generic_class_symbol__3(Name__0 const ref const namespace__, string const class_name__, system__collections__List__1 const ref const type_parameters__);
Symbol__0 const ref mut build_constructor_symbol__1(string const name__);
void mut unit_test_build_runtime_library_package__0();
void mut Runtime_Library_Package_contains_system_package__0();
void mut System_namespace_contains_console_namespace__0();
void mut Console_namespace_contains_Console_class__0();
void mut System_namespace_contains_collections_namespace__0();
void mut Collections_namespace_contains_List_class__0();
Package__0 const ref mut analyze_semantics__1(Syntax_Node__0 const ref const package_syntax__);
Semantic_Node__0 mut ref mut Semantic_Node__0__0new__token__1(Semantic_Node__0 mut ref const self, Token__0 const ref const token__);
Semantic_Node__0 mut ref mut Semantic_Node__0__0new__concrete__1(Semantic_Node__0 mut ref const self, Syntax_Node__0 const ref const node__);
Semantic_Node__0 mut ref mut Semantic_Node__0__0new__concrete__2(Semantic_Node__0 mut ref const self, Syntax_Node__0 const ref const node__, Diagnostic__0 const ref const diagnostic__);
Semantic_Node__0 mut ref mut Semantic_Node__0__0new__concrete_with_children__2(Semantic_Node__0 mut ref const self, Syntax_Node__0 const ref const node__, system__collections__List__1 const ref const children__);
Semantic_Node__0 mut ref mut Semantic_Node__0__0new__of_type__3(Semantic_Node__0 mut ref const self, Type__0 const ref const of_type__, Syntax_Node__0 const ref const node__, system__collections__List__1 const ref const children__);
Semantic_Node__0 mut ref mut Semantic_Node__0__0new__declares_type__3(Semantic_Node__0 mut ref const self, Type__0 const ref const type__, Syntax_Node__0 const ref const node__, system__collections__List__1 const ref const children__);
Semantic_Node__0 mut ref mut Semantic_Node__0__0new__referencing_type__3(Semantic_Node__0 mut ref const self, Type__0 const ref const type__, Syntax_Node__0 const ref const node__, system__collections__List__1 const ref const children__);
Program_Fragment__0 const ref mut semantic_node_as_program_fragment__1(Semantic_Node__0 const ref const node__);
Text_Span__0 const ref mut get_semantic_node_text_span__1(Semantic_Node__0 const ref const node__);
string mut get_semantic_node_text__1(Semantic_Node__0 const ref const node__);
Semantic_Node__0 const opt_ref mut first_child__2(Semantic_Node__0 const ref const node__, int32 const kind__);
system__collections__List__1 const ref mut children_of_kind__2(Semantic_Node__0 const ref const node__, int32 const kind__);
system__collections__List__1 const ref mut node_members__1(Semantic_Node__0 const ref const node__);
system__collections__List__1 const ref mut node_statements__1(Semantic_Node__0 const ref const node__);
system__collections__List__1 const ref mut node_parameters__1(Semantic_Node__0 const ref const node__);
int32 mut node_argument_count__1(Semantic_Node__0 const ref const node__);
Semantic_Node__0 const opt_ref mut node_access_modifier__1(Semantic_Node__0 const ref const node__);
BOOL mut node_has_child__2(Semantic_Node__0 const ref const node__, int32 const kind__);
system__collections__List__1 const ref mut diagnostics__1(Semantic_Node__0 const ref const node__);
void mut collect_node_diagnostics__2(Semantic_Node__0 const ref const node__, system__collections__List__1 mut ref const diagnostics__);
Semantic_Tree_Builder__0 mut ref mut Semantic_Tree_Builder__0__0new__0(Semantic_Tree_Builder__0 mut ref const self);
system__collections__List__1 const ref mut build_compilation_units__3(Semantic_Tree_Builder__0 const ref const builder__, Syntax_Node__0 const ref const package_syntax__, Name_Table__0 const ref const name_table__);
Compilation_Unit__0 const ref mut build_compilation_unit_semantic_node__3(Semantic_Tree_Builder__0 const ref const builder__, Syntax_Node__0 const ref const compilation_unit_syntax__, Name_Table__0 const ref const name_table__);
Semantic_Node__0 const ref mut build_semantic_node__4(Semantic_Tree_Builder__0 const ref const builder__, Syntax_Node__0 const ref const syntax__, Name_Table__0 const ref const name_table__, Name_Subtable__0 const ref const scope__);
Semantic_Node__0 mut ref mut build_parameters_semantic_node__4(Semantic_Tree_Builder__0 const ref const builder__, Syntax_Node__0 const ref const parameters_syntax__, Name_Table__0 const ref const name_table__, Name_Subtable__0 const ref const scope__);
Semantic_Node__0 mut ref mut build_type_name_semantic_node__4(Semantic_Tree_Builder__0 const ref const builder__, Syntax_Node__0 const ref const syntax__, Name_Table__0 const ref const name_table__, Name_Subtable__0 const ref const scope__);
Type__0 const ref mut build_optional_type__3(Semantic_Tree_Builder__0 const ref const builder__, Name_Table__0 const ref const name_table__, Type__0 const ref const base_type__);
system__collections__List__1 const ref mut build_type_arguments_semantic_node__5(Semantic_Tree_Builder__0 const ref const builder__, Syntax_Node__0 const ref const syntax__, Name_Table__0 const ref const name_table__, Name_Subtable__0 const ref const scope__, system__collections__List__1 mut ref const children__);
Semantic_Node__0 const ref mut build_constructor_name_semantic_node__4(Semantic_Tree_Builder__0 const ref const builder__, Syntax_Node__0 const ref const syntax__, Name_Table__0 const ref const name_table__, Name_Subtable__0 const ref const scope__);
Syntax_Node__0 const ref mut as_syntax_node__1(Syntax_Node__0 const ref const syntax__);
Diagnostic__0 const ref mut resolution_error__1(Syntax_Node__0 const ref const node__);
Diagnostic__0 const ref mut resolution_error__2(Syntax_Node__0 const ref const node__, Semantic_Node__0 const ref const qualifier__);
Symbol__0 const ref mut build_symbols__2(Package_Name__0 const ref const package_name__, system__collections__List__1 const ref const compilation_units__);
Compilation_Unit_Parser__0 mut ref mut Compilation_Unit_Parser__0__0new__1(Compilation_Unit_Parser__0 mut ref const self, Token_Stream__0 mut ref const token_stream__);
Syntax__0 const ref mut parse__1(Compilation_Unit_Parser__0 mut ref const parser__);
Token__0 const opt_ref mut accept_token__1(Compilation_Unit_Parser__0 mut ref const parser__);
Token__0 const ref mut expect_token__2(Compilation_Unit_Parser__0 mut ref const parser__, int32 const kind__);
Syntax__0 const ref mut parse_type_name__1(Compilation_Unit_Parser__0 mut ref const parser__);
Syntax__0 const ref mut parse_non_optional_type__1(Compilation_Unit_Parser__0 mut ref const parser__);
Syntax__0 const ref mut parse_type__1(Compilation_Unit_Parser__0 mut ref const parser__);
Syntax__0 const ref mut parse_atom__1(Compilation_Unit_Parser__0 mut ref const parser__);
Syntax__0 const ref mut parse_call_arguments__1(Compilation_Unit_Parser__0 mut ref const parser__);
Syntax__0 const ref mut parse_expression__2(Compilation_Unit_Parser__0 mut ref const parser__, int32 const min_precedence__);
Syntax__0 const ref mut parse_expression__1(Compilation_Unit_Parser__0 mut ref const parser__);
Syntax__0 const ref mut parse_match_arm__1(Compilation_Unit_Parser__0 mut ref const parser__);
Syntax__0 const ref mut parse_statement__1(Compilation_Unit_Parser__0 mut ref const parser__);
Syntax__0 const ref mut parse_if_statement__1(Compilation_Unit_Parser__0 mut ref const parser__);
Syntax__0 const ref mut parse_variable_declaration__2(Compilation_Unit_Parser__0 mut ref const parser__, BOOL const allow_initializer__);
Syntax__0 const ref mut parse_block__1(Compilation_Unit_Parser__0 mut ref const parser__);
Syntax__0 const ref mut parse_parameter_list__1(Compilation_Unit_Parser__0 mut ref const parser__);
Syntax__0 const ref mut parse_member_declaration__1(Compilation_Unit_Parser__0 mut ref const parser__);
Syntax__0 const ref mut parse_declaration__1(Compilation_Unit_Parser__0 mut ref const parser__);
Syntax__0 const ref mut parse_compilation_unit__1(Compilation_Unit_Parser__0 mut ref const parser__);
Token_Stream__0 mut ref mut lexically_analyze__1(Source_Text__0 const ref const source__);
Syntax_Node__0 const ref mut parse_package__1(system__collections__List__1 const ref const sources__);
Syntax__0 mut ref mut Syntax__0__0new__0(Syntax__0 mut ref const self);
string mut syntax_to_string__1(Syntax__0 const ref const syntax__);
Syntax_Node__0 mut ref mut Syntax_Node__0__0new__4(Syntax_Node__0 mut ref const self, int32 const type__, Source_Text__0 const ref const source__, int32 const start__, int32 const length__);
Syntax_Node__0 mut ref mut Syntax_Node__0__0new__5(Syntax_Node__0 mut ref const self, int32 const type__, BOOL const is_missing__, Source_Text__0 const ref const source__, int32 const start__, int32 const length__);
Syntax_Node__0 mut ref mut Syntax_Node__0__0new__2(Syntax_Node__0 mut ref const self, int32 const type__, Syntax__0 const ref const child__);
Syntax_Node__0 mut ref mut Syntax_Node__0__0new__with_children__2(Syntax_Node__0 mut ref const self, int32 const type__, system__collections__List__1 const ref const children__);
Syntax_Node__0 mut ref mut Syntax_Node__0__0new__skipped__1(Syntax_Node__0 mut ref const self, Token__0 const ref const token__);
Syntax_Node__0 mut ref mut Syntax_Node__0__0new__skipped_many__1(Syntax_Node__0 mut ref const self, system__collections__List__1 const ref const tokens__);
Syntax__0 const ref mut syntax_node_as_syntax__1(Syntax_Node__0 const ref const node__);
Text_Span__0 const ref mut get_syntax_node_text_span__1(Syntax_Node__0 const ref const node__);
string mut get_syntax_node_text__1(Syntax_Node__0 const ref const syntax__);
Token__0 const opt_ref mut first_child_token__2(Syntax_Node__0 const ref const syntax__, int32 const kind__);
Syntax_Node__0 const opt_ref mut first_child_syntax_node__2(Syntax_Node__0 const ref const syntax__, int32 const kind__);
BOOL mut has_child__2(Syntax_Node__0 const ref const syntax__, int32 const type__);
system__collections__List__1 mut ref mut all_node_diagnostics__1(Syntax_Node__0 const ref const syntax__);
void mut collect_syntax_diagnostics__2(Syntax_Node__0 const ref const syntax__, system__collections__List__1 mut ref const diagnostics__);
system__collections__List__1 const ref mut members__1(Syntax_Node__0 const ref const syntax__);
system__collections__List__1 const ref mut parameters__1(Syntax_Node__0 const ref const syntax__);
system__collections__List__1 const ref mut statements__1(Syntax_Node__0 const ref const syntax__);
Token__0 const opt_ref mut access_modifier__1(Syntax_Node__0 const ref const syntax__);
Token__0 mut ref mut Token__0__0new__5(Token__0 mut ref const self, int32 const kind__, Source_Text__0 const ref const source__, int32 const start__, int32 const byte_length__, system__collections__List__1 const ref const diagnostics__);
Token__0 mut ref mut Token__0__0new__6(Token__0 mut ref const self, int32 const kind__, Source_Text__0 const ref const source__, int32 const start__, int32 const byte_length__, system__collections__List__1 const ref const diagnostics__, string const value__);
Token__0 mut ref mut Token__0__0new__missing__3(Token__0 mut ref const self, int32 const kind__, Source_Text__0 const ref const source__, int32 const start__);
Syntax__0 const ref mut token_as_syntax__1(Token__0 const ref const token__);
string mut get_token_text__1(Token__0 const ref const token__);
Token_Stream__0 mut ref mut Token_Stream__0__0new__1(Token_Stream__0 mut ref const self, Source_Text__0 const ref const source__);
Token__0 const opt_ref mut next_token__1(Token_Stream__0 mut ref const tokens__);
Token__0 const opt_ref mut end_of_file_token__1(Token_Stream__0 mut ref const tokens__);
Token__0 const ref mut new_identifier_or_keyword_token__2(Token_Stream__0 mut ref const tokens__, int32 const end__);
Token__0 const ref mut new_operator_token__2(Token_Stream__0 mut ref const tokens__, int32 const kind__);
Token__0 const ref mut new_operator_token__3(Token_Stream__0 mut ref const tokens__, int32 const kind__, int32 const length__);
Token__0 const ref mut new_token__3(Token_Stream__0 mut ref const tokens__, int32 const kind__, int32 const end__);
Token__0 const ref mut new_token__4(Token_Stream__0 mut ref const tokens__, int32 const kind__, int32 const end__, string const value__);
BOOL mut is_identifier_char__1(code_point const c__);
BOOL mut is_number_char__1(code_point const c__);
Diagnostic__0 mut ref mut Diagnostic__0__0new__5(Diagnostic__0 mut ref const self, int32 const level__, int32 const phase__, Source_Text__0 const ref const source__, Text_Span__0 const ref const span__, string const message__);
Emitter__0 mut ref mut Emitter__0__0new__2(Emitter__0 mut ref const self, Package__0 const ref const package__, system__collections__List__1 const ref const resources__);
string mut emit__1(Emitter__0 mut ref const emitter__);
string mut mangle_name__1(Type__0 const ref const type__);
string mut mangle_function_name__2(string const name__, int32 const parameter_count__);
string mut mangle_field_name__1(string const name__);
BOOL mut contains_multi_underscore_runs__1(string const value__);
void mut append_fixing_underscores__2(system__text__String_Builder__0 mut ref const builder__, string const value__);
string mut convert_primitive_type_name__1(Type__0 const ref const type__);
system__text__String_Builder__0 mut ref mut convert_type_name__1(Type__0 const ref const type__);
system__text__String_Builder__0 mut ref mut convert_type_name__2(Type__0 const ref const type__, BOOL const include_type_parameters__);
void mut convert_type_name_parameters__2(system__text__String_Builder__0 mut ref const builder__, Type__0 const ref const type__);
string mut convert_reference_type__3(BOOL const mutable_binding__, Type__0 const ref mut type__, BOOL const nullable__);
string mut convert_type__3(BOOL const mutable_binding__, Type__0 const ref mut type__, BOOL const optional__);
string mut convert_type__2(BOOL const mutable_binding__, Semantic_Node__0 const ref const type_node__);
string mut convert_parameter_list__4(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const parameters__, string const self_type__, BOOL const is_main_function__);
string mut convert_method_parameter_list__3(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const parameters__, string const self_type__);
string mut convert_parameter_list__3(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const parameters__, BOOL const is_main_function__);
string mut convert_parameter_list__2(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const parameters__);
void mut convert_expression__2(Semantic_Node__0 const ref const syntax__, Source_File_Builder__0 mut ref const builder__);
int32 mut literal_length__1(string const value__);
code_point mut code_point_literal_value__1(string const value__);
void mut convert_reference_type_constructor_arguments__3(Semantic_Node__0 const ref const syntax__, Source_File_Builder__0 mut ref const builder__, string const type_name__);
void mut convert_member_access__2(Semantic_Node__0 const ref const lhs__, Source_File_Builder__0 mut ref const builder__);
Type__0 const ref mut as_type__1(Type__0 const ref const type__);
void mut emit_statement__2(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const statement__);
void mut emit_method_body__3(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const block__, BOOL const is_associated_function__);
void mut emit_constructor_body__4(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const block__, string const type_name__, BOOL const is_value_type__);
void mut emit_member_declaration__4(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const member__, string const class_name__, BOOL const is_value_type__);
void mut emit_default_constructor__3(Emitter__0 mut ref const emitter__, string const type_name__, BOOL const is_value_type__);
void mut emit_declaration__2(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const declaration__);
void mut emit_compilation_unit__2(Emitter__0 mut ref const emitter__, Compilation_Unit__0 const ref const unit__);
void mut emit_preamble__1(Emitter__0 mut ref const emitter__);
void mut emit_entry_point_adapter__1(Emitter__0 mut ref const emitter__);
void mut emit_postamble__1(Emitter__0 mut ref const emitter__);
Expression__0 mut ref mut Expression__0__0new__0(Expression__0 mut ref const self);
Program_Fragment__0 const ref mut expression_as_program_fragment__1(Expression__0 const ref const expression__);
Integer_Literal_Expression__0 mut ref mut Integer_Literal_Expression__0__0new__2(Integer_Literal_Expression__0 mut ref const self, Type__0 const ref const type__, Syntax_Node__0 const ref const node__);
Program_Fragment__0 const ref mut integer_literal_expression_as_program_fragment__1(Integer_Literal_Expression__0 const ref const expression__);
Literal_Expression__0 mut ref mut Literal_Expression__0__0new__0(Literal_Expression__0 mut ref const self);
Expression__0 const ref mut literal_expression_as_expression__1(Literal_Expression__0 const ref const expression__);
Negate_Expression__0 mut ref mut Negate_Expression__0__0new__0(Negate_Expression__0 mut ref const self);
Unary_Expression__0 const ref mut negate_expression_as_unary_expression__1(Negate_Expression__0 const ref const expression__);
Unary_Expression__0 mut ref mut Unary_Expression__0__0new__0(Unary_Expression__0 mut ref const self);
Expression__0 const ref mut unary_expression_as_expression__1(Unary_Expression__0 const ref const expression__);
Name__0 mut ref mut Name__0__0new__global_namespace__0(Name__0 mut ref const self);
Name__0 mut ref mut Name__0__0new__global_namespace__1(Name__0 mut ref const self, Package_Name__0 const ref const package__);
Name__0 mut ref mut Name__0__0new__3(Name__0 mut ref const self, Name__0 const ref const qualifier__, int32 const kind__, string const name__);
Name__0 mut ref mut Name__0__0new__4(Name__0 mut ref const self, Name__0 const ref const qualifier__, int32 const kind__, string const name__, BOOL const is_special__);
Name__0 mut ref mut Name__0__0new__special__3(Name__0 mut ref const self, Name__0 const ref const qualifier__, int32 const kind__, string const name__);
Name__0 mut ref mut Name__0__0new__exactly__4(Name__0 mut ref const self, Package_Name__0 const opt_ref const package__, int32 const kind__, Strings__0 const ref const segments__, BOOL const is_special__);
string mut unqualified_name__1(Name__0 const ref const name__);
string mut full_name__1(Name__0 const ref const name__);
BOOL mut is_qualified_by__2(Name__0 const ref const name__, Name__0 const ref const qualifier__);
BOOL mut qualifier_is__2(Name__0 const ref const name__, Name__0 const ref const qualifier__);
BOOL mut names__2(Name__0 const ref const name__, Name__0 const ref const other__);
BOOL mut is_package_qualified__1(Name__0 const ref const name__);
Name__0 const ref mut remove_package__1(Name__0 const ref const name__);
void mut unit_test_Name__0();
void mut name_with_unspecified_package_names_name_with_package__0();
void mut name_with_unspecified_package_names_itself__0();
Package_Name__0 mut ref mut Package_Name__0__0new__1(Package_Name__0 mut ref const self, string const name__);
string mut full_package_name__1(Package_Name__0 const ref const package_name__);
Symbol__0 mut ref mut Symbol__0__0new__identifier__1(Symbol__0 mut ref const self, string const name__);
Symbol__0 mut ref mut Symbol__0__0new__identifier__2(Symbol__0 mut ref const self, string const name__, system__collections__List__1 const ref const children__);
Symbol__0 mut ref mut Symbol__0__0new__constructor__2(Symbol__0 mut ref const self, string const name__, system__collections__List__1 const ref const declarations__);
Symbol__0 mut ref mut Symbol__0__0new__package__2(Symbol__0 mut ref const self, string const name__, system__collections__List__1 const ref const children__);
Symbol__0 mut ref mut Symbol__0__0new__declaring__3(Symbol__0 mut ref const self, Type__0 const ref const declares_type__, system__collections__List__1 const ref const declarations__, system__collections__List__1 const ref const children__);
Symbol__0 mut ref mut Symbol__0__0new__of_type__4(Symbol__0 mut ref const self, string const name__, Type__0 const ref const of_type__, system__collections__List__1 const ref const declarations__, system__collections__List__1 const ref const children__);
Symbol__0 const opt_ref mut get_child_symbol__3(Symbol__0 const ref const symbol__, string const name__, int32 const kind__);
void mut unit_test_Symbol__0();
void mut Package_symbol_children_can_be_found_by_name_and_kind__0();
Type__0 mut ref mut Type__0__0new__3(Type__0 mut ref const self, int32 const kind__, Name__0 const ref const name__, BOOL const is_mutable__);
Type__0 mut ref mut Type__0__0new__parameter__1(Type__0 mut ref const self, string const name__);
Type__0 mut ref mut Type__0__0new__4(Type__0 mut ref const self, int32 const kind__, Name__0 const ref const name__, system__collections__List__1 const ref const type_parameters__, BOOL const is_mutable__);
Type__0 mut ref mut Type__0__0new__primitive__1(Type__0 mut ref const self, Name__0 const ref const name__);
Type__0 mut ref mut Type__0__0new__primitive__2(Type__0 mut ref const self, Name__0 const ref const name__, system__collections__List__1 const ref const type_parameters__);
Type__0 mut ref mut Type__0__0new__namespace__1(Type__0 mut ref const self, Name__0 const ref const name__);
Type__0 mut ref mut Type__0__0new__generic__2(Type__0 mut ref const self, Type__0 const ref const definition__, system__collections__List__1 const ref const type_arguments__);
Type__0 mut ref mut Type__0__0new__6(Type__0 mut ref const self, int32 const kind__, Name__0 const ref const name__, system__collections__List__1 const ref const type_parameters__, BOOL const is_primitive__, BOOL const is_potentially_mutable__, BOOL const is_mutable__);
Type__0 const ref mut make_mutable_type__1(Type__0 const ref const type__);
Type__0 const ref mut make_immutable_type__1(Type__0 const ref const type__);
Type__0 const ref mut remove_type_package__1(Type__0 const ref const type__);
Name_Subtable__0 mut ref mut Name_Subtable__0__0new__global_namespace__1(Name_Subtable__0 mut ref const self, Name_Table__0 const ref const name_table__);
Name_Subtable__0 mut ref mut Name_Subtable__0__0new__global_namespace__2(Name_Subtable__0 mut ref const self, Name_Table__0 const ref const name_table__, Package_Name__0 const ref const package_name__);
Name_Subtable__0 mut ref mut Name_Subtable__0__0new__3(Name_Subtable__0 mut ref const self, Name_Subtable__0 const ref const parent__, Name__0 const ref const name__, Type__0 const ref const type__);
void mut add_subtable__3(Name_Subtable__0 mut ref const scope__, Name__0 const ref const name__, Type__0 const opt_ref const type__);
Name_Subtable__0 mut opt_ref mut find__2(Name_Subtable__0 const ref const scope__, string const name__);
Name_Subtable__0 mut opt_ref mut find_special__2(Name_Subtable__0 const ref const scope__, string const name__);
Name_Subtable__0 mut opt_ref mut find__3(Name_Subtable__0 const ref const scope__, string const name__, BOOL const is_special__);
Name_Subtable__0 mut opt_ref mut lookup__2(Name_Subtable__0 const ref const scope__, string const name__);
Name_Subtable__0 mut opt_ref mut lookup_special__2(Name_Subtable__0 const ref const scope__, string const name__);
Name_Subtable__0 mut opt_ref mut lookup__3(Name_Subtable__0 const ref const scope__, string const name__, BOOL const is_special__);
Name_Subtable__0 const opt_ref mut get_scope__2(Name_Subtable__0 const ref const scope__, Name__0 const ref const name__);
void mut bind_type__2(Name_Subtable__0 mut ref const scope__, Type__0 const ref const type__);
Name_Subtable__0 mut ref mut as_mut__1(Name_Subtable__0 const ref const scope__);
void mut unit_test_Name_Subtable__0();
void mut global_namespace_contains_added_name__0();
void mut namespace_contains_added_name__0();
Name_Table__0 mut ref mut Name_Table__0__0new__0(Name_Table__0 mut ref const self);
Name__0 const ref mut add_package__2(Name_Table__0 mut ref const name_table__, Package_Name__0 const ref const package_name__);
Name__0 const ref mut add_symbol_name__3(Name_Table__0 mut ref const name_table__, Name__0 const ref const parent__, Symbol__0 const ref const symbol__);
void mut add_type_name__3(Name_Table__0 mut ref const name_table__, Name__0 const ref const name__, Type__0 const opt_ref const type__);
Name_Subtable__0 const opt_ref mut get_name__2(Name_Table__0 const ref const name_table__, Name__0 const ref const name__);
Name_Table__0 const ref mut build_name_table__3(Package_Name__0 const ref const package_name__, Syntax_Node__0 const ref const package_syntax__, system__collections__List__1 const ref const references__);
void mut add_referenced__2(Name_Table__0 mut ref const name_table__, system__collections__List__1 const ref const references__);
void mut add_symbol__3(Name_Table__0 mut ref const name_table__, Name__0 const ref const parent__, Symbol__0 const ref const symbol__);
void mut add_package__3(Name_Table__0 mut ref const name_table__, Package_Name__0 const ref const package_name__, Syntax_Node__0 const ref const package_syntax__);
void mut add_compilation_unit__3(Name_Table__0 mut ref const name_table__, Name__0 const ref const global_namespace__, Syntax_Node__0 const ref const compilation_unit__);
void mut add_syntax__3(Name_Table__0 mut ref const name_table__, Name__0 const ref const parent__, Syntax_Node__0 const ref const syntax__);
void mut add_function__3(Name_Table__0 mut ref const name_table__, Name__0 const ref const name__, Syntax_Node__0 const ref const function__);
void mut unit_test_Name_Table_Builder__0();
void mut table_contains_referenced_child_names__0();
void mut can_get_root_namespace_from_name__0();
void mut can_get_Console_class_from_name_without_package__0();
void mut can_get_Optional_class_from_name_with_package__0();

// Class Declarations

struct Source_Text__0
{
	Type_ID type_id;
	string mut package__;
	string mut path__;
	string mut name__;
	string mut text__;
	Text_Lines__0 const ref mut lines__;
};

struct Text_Line__0
{
	Type_ID type_id;
	Source_Text__0 const ref mut source__;
	int32 mut start__;
	int32 mut byte_length__;
};

struct Text_Lines__0
{
	Type_ID type_id;
	Source_Text__0 const ref mut source__;
	Ints__0 const ref mut start_of_line__;
};

struct Text_Position__0
{
	Type_ID type_id;
	int32 mut character_offset__;
	int32 mut line__;
	int32 mut column__;
};

struct Text_Span__0
{
	Type_ID type_id;
	int32 mut start__;
	int32 mut byte_length__;
};

struct Source_File_Builder__0
{
	Type_ID type_id;
	system__text__String_Builder__0 mut ref mut code__;
	system__text__String_Builder__0 mut ref mut indent__;
	BOOL mut first_element__;
	BOOL mut after_block__;
};

struct Compilation_Unit__0
{
	Type_ID type_id;
	Syntax_Node__0 const ref mut syntax__;
	system__collections__List__1 const ref mut declarations__;
};

struct Package__0
{
	Type_ID type_id;
	Package_Name__0 const ref mut name__;
	system__collections__List__1 const ref mut references__;
	system__collections__List__1 const ref mut compilation_units__;
	Symbol__0 const ref mut symbol__;
};

struct Package_Reference__0
{
	Type_ID type_id;
	string mut name__;
	Package__0 const ref mut package__;
};

struct Program_Fragment__0
{
	Type_ID type_id;
	Syntax__0 const ref mut syntax__;
	BOOL mut is_missing__;
	Source_Text__0 const ref mut source__;
	int32 mut start__;
	int32 mut byte_length__;
	system__collections__List__1 const ref mut children__;
	system__collections__List__1 const ref mut diagnostics__;
};

struct Semantic_Node__0
{
	Type_ID type_id;
	Syntax__0 const ref mut syntax__;
	BOOL mut is_missing__;
	Source_Text__0 const ref mut source__;
	int32 mut start__;
	int32 mut byte_length__;
	system__collections__List__1 const ref mut children__;
	system__collections__List__1 const ref mut diagnostics__;
	Type__0 const opt_ref mut of_type__;
	Type__0 const opt_ref mut declares_type__;
	Type__0 const opt_ref mut referenced_type__;
	int32 mut kind__;
};

struct Semantic_Tree_Builder__0
{
	Type_ID type_id;
	Name__0 const ref mut optional_type_name__;
};

struct Compilation_Unit_Parser__0
{
	Type_ID type_id;
	Token_Stream__0 mut ref mut token_stream__;
	Token__0 const opt_ref mut token__;
	Syntax__0 const opt_ref mut compilation_unit__;
};

struct Syntax__0
{
	Type_ID type_id;
	BOOL mut is_missing__;
	Source_Text__0 const ref mut source__;
	int32 mut start__;
	int32 mut byte_length__;
	system__collections__List__1 const ref mut diagnostics__;
};

struct Syntax_Node__0
{
	Type_ID type_id;
	BOOL mut is_missing__;
	Source_Text__0 const ref mut source__;
	int32 mut start__;
	int32 mut byte_length__;
	system__collections__List__1 mut ref mut diagnostics__;
	int32 mut kind__;
	system__collections__List__1 const ref mut children__;
};

struct Token__0
{
	Type_ID type_id;
	BOOL mut is_missing__;
	Source_Text__0 const ref mut source__;
	int32 mut start__;
	int32 mut byte_length__;
	system__collections__List__1 const ref mut diagnostics__;
	int32 mut kind__;
	system__collections__List__1 const ref mut children__;
	string mut value__;
};

struct Token_Stream__0
{
	Type_ID type_id;
	Source_Text__0 const ref mut source__;
	int32 mut position__;
	system__collections__List__1 mut ref mut diagnostics__;
	BOOL mut end_of_file__;
};

struct Diagnostic__0
{
	Type_ID type_id;
	int32 mut level__;
	int32 mut phase__;
	Source_Text__0 const ref mut source__;
	Text_Span__0 const ref mut span__;
	Text_Position__0 const ref mut position__;
	string mut message__;
};

struct Emitter__0
{
	Type_ID type_id;
	Package__0 const ref mut package__;
	system__collections__List__1 const ref mut resources__;
	Source_File_Builder__0 mut ref mut includes__;
	Source_File_Builder__0 mut ref mut type_id_declaration__;
	Source_File_Builder__0 mut ref mut type_declarations__;
	Source_File_Builder__0 mut ref mut function_declarations__;
	Source_File_Builder__0 mut ref mut class_declarations__;
	Source_File_Builder__0 mut ref mut global_definitions__;
	Source_File_Builder__0 mut ref mut definitions__;
	string mut main_function_name__;
	string mut main_function_return_type__;
	BOOL mut main_function_accepts_console__;
	BOOL mut main_function_accepts_args__;
};

struct Expression__0
{
	Type_ID type_id;
	Syntax__0 const ref mut syntax__;
	BOOL mut is_missing__;
	Source_Text__0 const ref mut source__;
	int32 mut start__;
	int32 mut byte_length__;
	system__collections__List__1 const ref mut children__;
	system__collections__List__1 const ref mut diagnostics__;
	Type__0 const ref mut type__;
};

struct Integer_Literal_Expression__0
{
	Type_ID type_id;
	Syntax__0 const ref mut syntax__;
	BOOL mut is_missing__;
	Source_Text__0 const ref mut source__;
	int32 mut start__;
	int32 mut byte_length__;
	system__collections__List__1 const ref mut children__;
	system__collections__List__1 const ref mut diagnostics__;
	Type__0 const ref mut type__;
	int32 mut value__;
};

struct Literal_Expression__0
{
	Type_ID type_id;
	Syntax__0 const ref mut syntax__;
	BOOL mut is_missing__;
	Source_Text__0 const ref mut source__;
	int32 mut start__;
	int32 mut byte_length__;
	system__collections__List__1 const ref mut children__;
	system__collections__List__1 const ref mut diagnostics__;
	Type__0 const ref mut type__;
};

struct Negate_Expression__0
{
	Type_ID type_id;
	Syntax__0 const ref mut syntax__;
	BOOL mut is_missing__;
	Source_Text__0 const ref mut source__;
	int32 mut start__;
	int32 mut byte_length__;
	system__collections__List__1 const ref mut children__;
	system__collections__List__1 const ref mut diagnostics__;
	Type__0 const ref mut type__;
	Expression__0 const ref mut operand__;
};

struct Unary_Expression__0
{
	Type_ID type_id;
	Syntax__0 const ref mut syntax__;
	BOOL mut is_missing__;
	Source_Text__0 const ref mut source__;
	int32 mut start__;
	int32 mut byte_length__;
	system__collections__List__1 const ref mut children__;
	system__collections__List__1 const ref mut diagnostics__;
	Type__0 const ref mut type__;
	Expression__0 const ref mut operand__;
};

struct Name__0
{
	Type_ID type_id;
	Package_Name__0 const opt_ref mut package__;
	int32 mut kind__;
	Strings__0 const ref mut segments__;
	BOOL mut is_special__;
};

struct Package_Name__0
{
	Type_ID type_id;
	string mut unqualified__;
};

struct Symbol__0
{
	Type_ID type_id;
	string mut name__;
	system__collections__List__1 const ref mut children__;
	system__collections__List__1 const ref mut declarations__;
	BOOL mut is_special_name__;
	int32 mut kind__;
	Type__0 const ref mut of_type__;
	Type__0 const ref mut declares_type__;
};

struct Type__0
{
	Type_ID type_id;
	int32 mut kind__;
	Name__0 const ref mut name__;
	system__collections__List__1 const ref mut type_parameters__;
	BOOL mut is_primitive__;
	BOOL mut is_value_type__;
	BOOL mut is_potentially_mutable__;
	BOOL mut is_mutable__;
};

struct Name_Subtable__0
{
	Type_ID type_id;
	Name_Table__0 const ref mut name_table__;
	Name_Subtable__0 const opt_ref mut parent__;
	Name__0 const ref mut name__;
	Type__0 const ref mut type__;
	system__collections__List__1 mut ref mut subtables__;
};

struct Name_Table__0
{
	Type_ID type_id;
	Name_Subtable__0 mut ref mut any_package__;
	system__collections__List__1 mut ref mut packages__;
};

// Global Definitions
int32 const Success__ = ((int32){0});
int32 const UsageError__ = ((int32){64});
int32 const DataError__ = ((int32){65});
int32 const SkippedTokens__ = ((int32){99999});
int32 const IdentifierName__ = ((int32){35});
int32 const GenericName__ = ((int32){36});
int32 const QualifiedName__ = ((int32){37});
int32 const PackageQualifiedName__ = ((int32){38});
int32 const OptionalType__ = ((int32){40});
int32 const ParameterList__ = ((int32){48});
int32 const Parameter__ = ((int32){49});
int32 const SelfParameter__ = ((int32){50});
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
int32 const IntegerLiteralExpression__ = ((int32){63});
int32 const AssignmentExpression__ = ((int32){64});
int32 const OrExpression__ = ((int32){65});
int32 const AndExpression__ = ((int32){66});
int32 const EqualExpression__ = ((int32){67});
int32 const NotEqualExpression__ = ((int32){68});
int32 const ComparisonExpression__ = ((int32){71});
int32 const AddExpression__ = ((int32){72});
int32 const SubtractExpression__ = ((int32){73});
int32 const InvocationExpression__ = ((int32){74});
int32 const MemberAccessExpression__ = ((int32){75});
int32 const ElementAccessExpression__ = ((int32){76});
int32 const NegateExpression__ = ((int32){77});
int32 const ReturnStatement__ = ((int32){79});
int32 const LoopStatement__ = ((int32){81});
int32 const Block__ = ((int32){82});
int32 const WhileStatement__ = ((int32){84});
int32 const ForStatement__ = ((int32){86});
int32 const VariableDeclaration__ = ((int32){88});
int32 const LocalDeclarationStatement__ = ((int32){89});
int32 const DoWhileStatement__ = ((int32){92});
int32 const IfStatement__ = ((int32){95});
int32 const ElseClause__ = ((int32){96});
int32 const BreakStatement__ = ((int32){98});
int32 const ContinueStatement__ = ((int32){100});
int32 const ExpressionStatement__ = ((int32){101});
int32 const ConstructorDeclaration__ = ((int32){106});
int32 const FieldDeclaration__ = ((int32){107});
int32 const MethodDeclaration__ = ((int32){108});
int32 const GlobalDeclaration__ = ((int32){109});
int32 const ClassDeclaration__ = ((int32){111});
int32 const EnumDeclaration__ = ((int32){114});
int32 const EnumMemberDeclaration__ = ((int32){115});
int32 const FunctionDeclaration__ = ((int32){116});
int32 const CompilationUnit__ = ((int32){117});
int32 const PackageNode__ = ((int32){118});
int32 const RemainderExpression__ = ((int32){120});
int32 const MultiplyExpression__ = ((int32){124});
int32 const DivideExpression__ = ((int32){125});
int32 const StructDeclaration__ = ((int32){127});
int32 const ImmutableType__ = ((int32){128});
int32 const NamespaceDeclaration__ = ((int32){129});
int32 const MatchStatement__ = ((int32){131});
int32 const MatchArm__ = ((int32){134});
int32 const MatchPattern__ = ((int32){135});
int32 const EndOfFile__ = ((int32){0});
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
int32 const Integer__ = ((int32){28});
int32 const NewKeyword__ = ((int32){29});
int32 const NotKeyword__ = ((int32){30});
int32 const NullReservedWord__ = ((int32){31});
int32 const SelfKeyword__ = ((int32){32});
int32 const TrueKeyword__ = ((int32){33});
int32 const FalseKeyword__ = ((int32){34});
int32 const MutableKeyword__ = ((int32){39});
int32 const PredefinedType__ = ((int32){41});
int32 const CodePoint__ = ((int32){42});
int32 const String__ = ((int32){43});
int32 const Int__ = ((int32){44});
int32 const Bool__ = ((int32){45});
int32 const Void__ = ((int32){46});
int32 const UnsignedInt__ = ((int32){47});
int32 const VarKeyword__ = ((int32){51});
int32 const AndKeyword__ = ((int32){69});
int32 const OrKeyword__ = ((int32){70});
int32 const ReturnKeyword__ = ((int32){78});
int32 const LoopKeyword__ = ((int32){80});
int32 const WhileKeyword__ = ((int32){83});
int32 const ForKeyword__ = ((int32){85});
int32 const LetKeyword__ = ((int32){87});
int32 const InKeyword__ = ((int32){90});
int32 const DoKeyword__ = ((int32){91});
int32 const IfKeyword__ = ((int32){93});
int32 const ElseKeyword__ = ((int32){94});
int32 const BreakKeyword__ = ((int32){97});
int32 const ContinueKeyword__ = ((int32){99});
int32 const PublicKeyword__ = ((int32){102});
int32 const ProtectedKeyword__ = ((int32){103});
int32 const InternalKeyword__ = ((int32){104});
int32 const PrivateKeyword__ = ((int32){105});
int32 const ClassKeyword__ = ((int32){110});
int32 const EnumKeyword__ = ((int32){112});
int32 const StructKeyword__ = ((int32){113});
int32 const Percent__ = ((int32){119});
int32 const Pipe__ = ((int32){121});
int32 const FatArrow__ = ((int32){122});
int32 const Asterisk__ = ((int32){123});
int32 const NoneKeyword__ = ((int32){126});
int32 const MatchKeyword__ = ((int32){130});
int32 const AbstractKeyword__ = ((int32){136});
int32 const Caret__ = ((int32){137});
int32 const CaretDot__ = ((int32){138});
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

Package__0 const ref mut compile__1(system__collections__List__1 const ref const sources__)
{
	Syntax_Node__0 const ref const package_syntax__ = parse_package__1(sources__);
	Package__0 const ref const package__ = analyze_semantics__1(package_syntax__);
	return package__;
}

void mut console_write_diagnostics__2(system__console__Console__0 mut ref const console__, system__collections__List__1 const ref const diagnostics__)
{
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(diagnostics__); void_ptr__0next(&iter);)
	{
		Diagnostic__0 const ref const diagnostic__ = void_ptr__0current(&iter);
		Text_Position__0 const ref const position__ = diagnostic__->position__;
		string mut severity__;
		if (cond(int32__0op__equal(diagnostic__->level__, Info__)))
		{
			severity__ = ((string){{13},(uint8_t*)u8"Informational"});
		}
		else if (cond(int32__0op__equal(diagnostic__->level__, Warning__)))
		{
			severity__ = ((string){{7},(uint8_t*)u8"Warning"});
		}
		else
		{
			severity__ = ((string){{5},(uint8_t*)u8"Error"});
		}

		console_write_line__2(console__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(diagnostic__->source__->path__, ((string){{1},(uint8_t*)u8":"})), int_to_string__1(position__->line__)), ((string){{1},(uint8_t*)u8":"})), int_to_string__1(position__->column__)), ((string){{1},(uint8_t*)u8" "})), severity__), ((string){{1},(uint8_t*)u8":"})));
		console_write_line__2(console__, string__0op__add(((string){{2},(uint8_t*)u8"  "}), diagnostic__->message__));
	}
}

BOOL mut has_errors__1(system__collections__List__1 const ref const diagnostics__)
{
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(diagnostics__); void_ptr__0next(&iter);)
	{
		Diagnostic__0 const ref const diagnostic__ = void_ptr__0current(&iter);
		if (cond(int32__0op__gte(diagnostic__->level__, CompilationError__)))
		{
			return TRUE;
		}
	}

	return FALSE;
}

int32 mut main__2(system__console__Console__0 mut ref const console__, system__console__Arguments__0 const ref const args__)
{
	if (cond(bool_op(bool_arg(int32__0op__equal(args__->count__, ((int32){1}))) && bool_arg(string__0op__equal(system__console__Arguments__0__0op__element(args__, ((int32){0})), ((string){{11},(uint8_t*)u8"--unit-test"}))))))
	{
		run_unit_tests__1(console__);
		return ((int32){0});
	}

	Strings__0 mut ref const source_file_paths__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	Strings__0 mut ref const resource_file_paths__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	string mut output_file_path__ = ((string){{0},(uint8_t*)u8""});
	BOOL mut verbose__ = FALSE;
	int32 mut arg_type__ = ((int32){0});
	for (string__0iter mut iter = system__console__Arguments__0__0iterate(args__); string__0next(&iter);)
	{
		string const arg__ = string__0current(&iter);
		if (cond(int32__0op__equal(arg_type__, ((int32){0}))))
		{
			if (cond(string__0op__equal(arg__, ((string){{2},(uint8_t*)u8"-r"}))))
			{
				arg_type__ = ((int32){1});
			}
			else if (cond(string__0op__equal(arg__, ((string){{2},(uint8_t*)u8"-o"}))))
			{
				arg_type__ = ((int32){2});
			}
			else if (cond(bool_op(bool_arg(string__0op__equal(arg__, ((string){{2},(uint8_t*)u8"-v"}))) || bool_arg(string__0op__equal(arg__, ((string){{9},(uint8_t*)u8"--verbose"}))))))
			{
				verbose__ = TRUE;
			}
			else
			{
				add_string__2(source_file_paths__, arg__);
			}
		}
		else if (cond(int32__0op__equal(arg_type__, ((int32){1}))))
		{
			add_string__2(resource_file_paths__, arg__);
			arg_type__ = ((int32){0});
		}
		else if (cond(int32__0op__equal(arg_type__, ((int32){2}))))
		{
			output_file_path__ = arg__;
			arg_type__ = ((int32){0});
		}
	}

	if (cond(verbose__))
	{
		console_write_line__2(console__, ((string){{23},(uint8_t*)u8"Adamant Compiler v0.1.0"}));
	}

	if (cond(bool_op(bool_arg(int32__0op__equal(source_file_paths__->count__, ((int32){0}))) || bool_arg(string__0op__equal(output_file_path__, ((string){{0},(uint8_t*)u8""}))))))
	{
		console_write_line__2(console__, ((string){{57},(uint8_t*)u8"Args: <Input File(s)> -o <Output File> -r <Resource File>"}));
		return UsageError__;
	}

	system__collections__List__1 mut ref const resources__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	if (cond(int32__0op__gt(resource_file_paths__->count__, ((int32){0}))))
	{
		if (cond(verbose__))
		{
			console_write_line__2(console__, ((string){{18},(uint8_t*)u8"Reading Resources:"}));
		}

		for (string__0iter mut iter = Strings__0__0iterate(resource_file_paths__); string__0next(&iter);)
		{
			string const resource_file_path__ = string__0current(&iter);
			if (cond(verbose__))
			{
				console_write_line__2(console__, string__0op__add(((string){{2},(uint8_t*)u8"  "}), resource_file_path__));
			}

			add_item__2(resources__, read_source__1(resource_file_path__));
		}
	}

	if (cond(verbose__))
	{
		console_write_line__2(console__, ((string){{10},(uint8_t*)u8"Compiling:"}));
	}

	system__collections__List__1 mut ref const sources__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (string__0iter mut iter = Strings__0__0iterate(source_file_paths__); string__0next(&iter);)
	{
		string const source_file_path__ = string__0current(&iter);
		if (cond(verbose__))
		{
			console_write_line__2(console__, string__0op__add(((string){{2},(uint8_t*)u8"  "}), source_file_path__));
		}

		add_item__2(sources__, read_source__1(source_file_path__));
	}

	Package__0 const ref const package__ = compile__1(sources__);
	system__collections__List__1 const ref const diagnostics__ = all_diagnostics__1(package__);
	console_write_diagnostics__2(console__, diagnostics__);
	if (cond(has_errors__1(diagnostics__)))
	{
		return DataError__;
	}

	Emitter__0 mut ref mut emitter__ = Emitter__0__0new__2(allocate(sizeof(Emitter__0)), package__, resources__);
	string const translated__ = emit__1(emitter__);
	if (cond(verbose__))
	{
		console_write__2(console__, ((string){{8},(uint8_t*)u8"Output: "}));
		console_write_line__2(console__, output_file_path__);
	}

	system__io__File_Writer__0 mut ref const output_file__ = system__io__File_Writer__0__0new__1(allocate(sizeof(system__io__File_Writer__0)), output_file_path__);
	file_write__2(output_file__, translated__);
	close_file_writer__1(output_file__);
	string mut output_dir_path__ = output_file_path__;
	int32 mut index__ = string_last_index_of__2(output_dir_path__, ((code_point){/*/*/0x2F}));
	if (cond(int32__0op__not_equal(index__, int32__0op__neg(((int32){1})))))
	{
		output_dir_path__ = substring__3(output_dir_path__, ((int32){0}), int32__0op__add(index__, ((int32){1})));
	}

	index__ = string_last_index_of__2(output_dir_path__, ((code_point){/*\\*/0x5C}));
	if (cond(int32__0op__not_equal(index__, int32__0op__neg(((int32){1})))))
	{
		output_dir_path__ = substring__3(output_dir_path__, ((int32){0}), int32__0op__add(index__, ((int32){1})));
	}

	if (cond(verbose__))
	{
		console_write__2(console__, ((string){{30},(uint8_t*)u8"Outputting RuntimeLibrary to: "}));
		console_write_line__2(console__, output_dir_path__);
	}

	system__io__File_Writer__0 mut ref mut resource_file__ = system__io__File_Writer__0__0new__1(allocate(sizeof(system__io__File_Writer__0)), string__0op__add(output_dir_path__, ((string){{16},(uint8_t*)u8"RuntimeLibrary.h"})));
	file_write__2(resource_file__, get_resource__1(((string){{16},(uint8_t*)u8"RuntimeLibrary.h"})));
	close_file_writer__1(resource_file__);
	resource_file__ = system__io__File_Writer__0__0new__1(allocate(sizeof(system__io__File_Writer__0)), string__0op__add(output_dir_path__, ((string){{16},(uint8_t*)u8"RuntimeLibrary.c"})));
	file_write__2(resource_file__, get_resource__1(((string){{16},(uint8_t*)u8"RuntimeLibrary.c"})));
	close_file_writer__1(resource_file__);
	return Success__;
}

Source_Text__0 const ref mut read_source__1(string const path__)
{
	system__io__File_Reader__0 mut ref const file__ = system__io__File_Reader__0__0new__1(allocate(sizeof(system__io__File_Reader__0)), path__);
	string const contents__ = file_read_to_end__1(file__);
	close_file_reader__1(file__);
	return Source_Text__0__0new__3(allocate(sizeof(Source_Text__0)), ((string){{9},(uint8_t*)u8"<default>"}), path__, contents__);
}

void mut run_unit_tests__1(system__console__Console__0 mut ref const console__)
{
	console_write_line__2(console__, ((string){{21},(uint8_t*)u8"Running Unit Tests..."}));
	unit_test_Text_Position__0();
	unit_test_build_primitives_package__0();
	unit_test_build_runtime_library_package__0();
	unit_test_Name__0();
	unit_test_Name_Subtable__0();
	unit_test_Name_Table_Builder__0();
	unit_test_Symbol__0();
}

Source_Text__0 mut ref mut Source_Text__0__0new__3(Source_Text__0 mut ref const self, string const package__, string const path__, string const text__)
{
	self->type_id = Source_Text__0__0Type_ID;
	self->package__ = package__;
	self->path__ = path__;
	string mut name__ = path__;
	int32 mut index__ = string_last_index_of__2(name__, ((code_point){/*/*/0x2F}));
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

Ints__0 const ref mut line_starts__1(string const text__)
{
	int32 const length__ = string_byte_length__1(text__);
	Ints__0 mut ref const starting_positions__ = Ints__0__0new__0(allocate(sizeof(Ints__0)));
	add_int__2(starting_positions__, ((int32){0}));
	int32 mut position__ = ((int32){0});
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

int32 mut source_byte_length__1(Source_Text__0 const ref const source__)
{
	return string_byte_length__1(source__->text__);
}

Text_Position__0 const ref mut position_of_start__2(Source_Text__0 const ref const source__, Text_Span__0 const ref const span__)
{
	int32 const char_offset__ = span__->start__;
	int32 const line_number__ = line_containing_offset__2(source__->lines__, char_offset__);
	int32 const line_start__ = get_line__2(source__->lines__, line_number__)->start__;
	int32 mut column__ = int32__0op__add(int32__0op__sub(char_offset__, line_start__), ((int32){1}));
	int32 mut i__ = line_start__;
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

Text_Line__0 mut ref mut Text_Line__0__0new__3(Text_Line__0 mut ref const self, Source_Text__0 const ref const source__, int32 const start__, int32 const length__)
{
	self->type_id = Text_Line__0__0Type_ID;
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = length__;
	return self;
}

Text_Line__0 mut ref mut Text_Line__0__0new__spanning__3(Text_Line__0 mut ref const self, Source_Text__0 const ref const source__, int32 const start__, int32 const end__)
{
	self->type_id = Text_Line__0__0Type_ID;
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = int32__0op__sub(end__, start__);
	return self;
}

Text_Lines__0 mut ref mut Text_Lines__0__0new__2(Text_Lines__0 mut ref const self, Source_Text__0 const ref const source__, Ints__0 const ref const start_of_line__)
{
	self->type_id = Text_Lines__0__0Type_ID;
	self->source__ = source__;
	self->start_of_line__ = start_of_line__;
	return self;
}

int32 mut line_count__1(Text_Lines__0 const ref const lines__)
{
	return lines__->start_of_line__->count__;
}

Text_Line__0 const ref mut get_line__2(Text_Lines__0 const ref const lines__, int32 const line_number__)
{
	assert__2(int32__0op__gt(line_number__, ((int32){0})), string__0op__add(((string){{5},(uint8_t*)u8"line "}), int_to_string__1(line_number__)));
	assert__2(int32__0op__lte(line_number__, line_count__1(lines__)), string__0op__add(((string){{5},(uint8_t*)u8"line "}), int_to_string__1(line_number__)));
	int32 const line_index__ = int32__0op__sub(line_number__, ((int32){1}));
	int32 const line_start__ = Ints__0__0op__element(lines__->start_of_line__, line_index__);
	if (cond(int32__0op__equal(line_index__, int32__0op__sub(line_count__1(lines__), ((int32){1})))))
	{
		return Text_Line__0__0new__spanning__3(allocate(sizeof(Text_Line__0)), lines__->source__, line_start__, source_byte_length__1(lines__->source__));
	}

	int32 const line_end__ = Ints__0__0op__element(lines__->start_of_line__, int32__0op__add(line_index__, ((int32){1})));
	return Text_Line__0__0new__spanning__3(allocate(sizeof(Text_Line__0)), lines__->source__, line_start__, line_end__);
}

int32 mut line_containing_offset__2(Text_Lines__0 const ref const lines__, int32 const character_offset__)
{
	assert__2(int32__0op__gte(character_offset__, ((int32){0})), string__0op__add(((string){{7},(uint8_t*)u8"offset "}), int_to_string__1(character_offset__)));
	assert__2(int32__0op__lte(character_offset__, source_byte_length__1(lines__->source__)), string__0op__add(string__0op__add(string__0op__add(((string){{7},(uint8_t*)u8"offset "}), int_to_string__1(character_offset__)), ((string){{15},(uint8_t*)u8" source length "})), int_to_string__1(source_byte_length__1(lines__->source__))));
	int32 mut left__ = ((int32){0});
	int32 mut right__ = int32__0op__sub(line_count__1(lines__), ((int32){1}));
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

Text_Position__0 mut ref mut Text_Position__0__0new__3(Text_Position__0 mut ref const self, int32 const character_offset__, int32 const line__, int32 const column__)
{
	self->type_id = Text_Position__0__0Type_ID;
	self->character_offset__ = character_offset__;
	self->line__ = line__;
	self->column__ = column__;
	return self;
}

void mut unit_test_Text_Position__0()
{
	Text_Position_retains_given_offeset_line_and_column__0();
}

void mut Text_Position_retains_given_offeset_line_and_column__0()
{
	Text_Position__0 const ref const position__ = Text_Position__0__0new__3(allocate(sizeof(Text_Position__0)), ((int32){23}), ((int32){2}), ((int32){5}));
	assert__1(int32__0op__equal(position__->character_offset__, ((int32){23})));
	assert__1(int32__0op__equal(position__->line__, ((int32){2})));
	assert__1(int32__0op__equal(position__->column__, ((int32){5})));
}

Text_Span__0 mut ref mut Text_Span__0__0new__2(Text_Span__0 mut ref const self, int32 const start__, int32 const length__)
{
	self->type_id = Text_Span__0__0Type_ID;
	self->start__ = start__;
	self->byte_length__ = length__;
	return self;
}

string mut format_error__1(string const message__)
{
	return string__0op__add(string__0op__add(((string){{3},(uint8_t*)u8"<$ "}), message__), ((string){{3},(uint8_t*)u8" $>"}));
}

Source_File_Builder__0 mut ref mut Source_File_Builder__0__0new__0(Source_File_Builder__0 mut ref const self)
{
	self->type_id = Source_File_Builder__0__0Type_ID;
	self->code__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	self->indent__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	self->first_element__ = TRUE;
	self->after_block__ = TRUE;
	return self;
}

void mut error__2(Source_File_Builder__0 mut ref const file__, string const message__)
{
	sb_append__2(file__->code__, format_error__1(message__));
}

void mut begin_line__2(Source_File_Builder__0 mut ref const file__, string const value__)
{
	sb_append_sb__2(file__->code__, file__->indent__);
	sb_append__2(file__->code__, value__);
	file__->first_element__ = file__->after_block__ = FALSE;
}

void mut write__2(Source_File_Builder__0 mut ref const file__, string const value__)
{
	sb_append__2(file__->code__, value__);
	file__->first_element__ = file__->after_block__ = FALSE;
}

void mut end_line__2(Source_File_Builder__0 mut ref const file__, string const value__)
{
	sb_append__2(file__->code__, value__);
	sb_append_line__1(file__->code__);
	file__->first_element__ = file__->after_block__ = FALSE;
}

void mut write_line__2(Source_File_Builder__0 mut ref const file__, string const value__)
{
	sb_append_sb__2(file__->code__, file__->indent__);
	sb_append__2(file__->code__, value__);
	sb_append_line__1(file__->code__);
	file__->first_element__ = file__->after_block__ = FALSE;
}

void mut blank_line__1(Source_File_Builder__0 mut ref const file__)
{
	sb_append_line__1(file__->code__);
	file__->first_element__ = TRUE;
	file__->after_block__ = FALSE;
}

void mut element_separator_line__1(Source_File_Builder__0 mut ref const file__)
{
	if (cond(BOOL__0op__not(file__->first_element__)))
	{
		sb_append_line__1(file__->code__);
		file__->first_element__ = TRUE;
		file__->after_block__ = FALSE;
	}
}

void mut statement_separator_line__1(Source_File_Builder__0 mut ref const file__)
{
	if (cond(file__->after_block__))
	{
		sb_append_line__1(file__->code__);
		file__->first_element__ = TRUE;
		file__->after_block__ = FALSE;
	}
}

void mut begin_block__1(Source_File_Builder__0 mut ref const file__)
{
	write_line__2(file__, ((string){{1},(uint8_t*)u8"{"}));
	sb_append__2(file__->indent__, ((string){{1},(uint8_t*)u8"\t"}));
	file__->first_element__ = file__->after_block__ = FALSE;
}

void mut begin_block_with__2(Source_File_Builder__0 mut ref const file__, string const value__)
{
	write_line__2(file__, value__);
	sb_append__2(file__->indent__, ((string){{1},(uint8_t*)u8"\t"}));
	file__->first_element__ = file__->after_block__ = FALSE;
}

void mut end_block__1(Source_File_Builder__0 mut ref const file__)
{
	sb_remove__3(file__->indent__, ((int32){0}), ((int32){1}));
	write_line__2(file__, ((string){{1},(uint8_t*)u8"}"}));
	file__->after_block__ = TRUE;
}

void mut end_block_with_semicolon__1(Source_File_Builder__0 mut ref const file__)
{
	sb_remove__3(file__->indent__, ((int32){0}), ((int32){1}));
	write_line__2(file__, ((string){{2},(uint8_t*)u8"};"}));
}

void mut end_block_with__2(Source_File_Builder__0 mut ref const file__, string const value__)
{
	sb_remove__3(file__->indent__, ((int32){0}), ((int32){1}));
	write_line__2(file__, value__);
}

int32 mut byte_length__1(Source_File_Builder__0 const ref const file__)
{
	return file__->code__->byte_length__;
}

string mut to_string__1(Source_File_Builder__0 mut ref const file__)
{
	return sb_to_string__1(file__->code__);
}

Compilation_Unit__0 mut ref mut Compilation_Unit__0__0new__2(Compilation_Unit__0 mut ref const self, Syntax_Node__0 const ref const syntax__, system__collections__List__1 const ref const declarations__)
{
	self->type_id = Compilation_Unit__0__0Type_ID;
	self->syntax__ = syntax__;
	self->declarations__ = declarations__;
	return self;
}

void mut collect_diagnostics__2(Compilation_Unit__0 const ref const compilation_unit__, system__collections__List__1 mut ref const diagnostics__)
{
	collect_syntax_diagnostics__2(compilation_unit__->syntax__, diagnostics__);
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(compilation_unit__->declarations__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const ref const declaration__ = void_ptr__0current(&iter);
		collect_node_diagnostics__2(declaration__, diagnostics__);
	}
}

Package__0 mut ref mut Package__0__0new__4(Package__0 mut ref const self, Package_Name__0 const ref const name__, system__collections__List__1 const ref const references__, system__collections__List__1 const ref const compilation_units__, Symbol__0 const ref const symbol__)
{
	self->type_id = Package__0__0Type_ID;
	self->name__ = name__;
	self->references__ = references__;
	self->compilation_units__ = compilation_units__;
	self->symbol__ = symbol__;
	return self;
}

system__collections__List__1 const ref mut all_diagnostics__1(Package__0 const ref const package__)
{
	system__collections__List__1 mut ref mut diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(package__->compilation_units__); void_ptr__0next(&iter);)
	{
		Compilation_Unit__0 const ref const compilation_unit__ = void_ptr__0current(&iter);
		collect_diagnostics__2(compilation_unit__, diagnostics__);
	}

	return diagnostics__;
}

Package_Reference__0 mut ref mut Package_Reference__0__0new__1(Package_Reference__0 mut ref const self, Package__0 const ref const package__)
{
	self->type_id = Package_Reference__0__0Type_ID;
	self->name__ = package__->name__->unqualified__;
	self->package__ = package__;
	return self;
}

Package_Reference__0 mut ref mut Package_Reference__0__0new__2(Package_Reference__0 mut ref const self, string const name__, Package__0 const ref const package__)
{
	self->type_id = Package_Reference__0__0Type_ID;
	self->name__ = name__;
	self->package__ = package__;
	return self;
}

Package__0 const ref mut build_primitives_package__0()
{
	Package_Name__0 const ref const name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){{11},(uint8_t*)u8"$primitives"}));
	system__collections__List__1 const ref const references__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	system__collections__List__1 const ref const compilation_units__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	system__collections__List__1 mut ref const primitive_symbols__ = build_primitive_symbols__1(name__);
	assert__2(int32__0op__gt(primitive_symbols__->count__, ((int32){0})), string__0op__add(((string){{24},(uint8_t*)u8"primitive_symbols.count="}), int_to_string__1(primitive_symbols__->count__)));
	Symbol__0 const ref const package_symbol__ = Symbol__0__0new__package__2(allocate(sizeof(Symbol__0)), name__->unqualified__, primitive_symbols__);
	assert__2(int32__0op__gt(package_symbol__->children__->count__, ((int32){0})), string__0op__add(((string){{30},(uint8_t*)u8"package_symbol.children.count="}), int_to_string__1(package_symbol__->children__->count__)));
	return Package__0__0new__4(allocate(sizeof(Package__0)), name__, references__, compilation_units__, package_symbol__);
}

system__collections__List__1 mut ref mut build_primitive_symbols__1(Package_Name__0 const ref const package_name__)
{
	Name__0 const ref const global_namespace__ = Name__0__0new__global_namespace__1(allocate(sizeof(Name__0)), package_name__);
	system__collections__List__1 mut ref const symbols__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(symbols__, build_adamant_language_namespace_symbol__1(global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{4},(uint8_t*)u8"void"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{5},(uint8_t*)u8"never"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{4},(uint8_t*)u8"bool"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{10},(uint8_t*)u8"code_point"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{6},(uint8_t*)u8"string"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{4},(uint8_t*)u8"int8"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{5},(uint8_t*)u8"int16"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{3},(uint8_t*)u8"int"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{5},(uint8_t*)u8"int64"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{6},(uint8_t*)u8"int128"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{4},(uint8_t*)u8"byte"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{6},(uint8_t*)u8"uint16"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{4},(uint8_t*)u8"uint"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{6},(uint8_t*)u8"uint64"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{7},(uint8_t*)u8"uint128"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{7},(uint8_t*)u8"float32"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{5},(uint8_t*)u8"float"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{8},(uint8_t*)u8"float128"}), global_namespace__));
	build_fixed_point_primitives__3(symbols__, ((int32){8}), global_namespace__);
	build_fixed_point_primitives__3(symbols__, ((int32){16}), global_namespace__);
	build_fixed_point_primitives__3(symbols__, ((int32){32}), global_namespace__);
	build_fixed_point_primitives__3(symbols__, ((int32){64}), global_namespace__);
	add_item__2(symbols__, build_primitive_symbol__2(((string){{9},(uint8_t*)u8"decimal32"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{7},(uint8_t*)u8"decimal"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{10},(uint8_t*)u8"decimal128"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{4},(uint8_t*)u8"size"}), global_namespace__));
	add_item__2(symbols__, build_primitive_symbol__2(((string){{6},(uint8_t*)u8"offset"}), global_namespace__));
	return symbols__;
}

Symbol__0 const ref mut build_adamant_language_namespace_symbol__1(Name__0 const ref const global_namespace__)
{
	Name__0 const ref const adamant_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, NamespaceName__, ((string){{7},(uint8_t*)u8"adamant"}));
	Name__0 const ref const language_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), adamant_namespace__, NamespaceName__, ((string){{8},(uint8_t*)u8"language"}));
	system__collections__List__1 mut ref const language_children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(language_children__, build_optional_type_symbol__1(language_namespace__));
	system__collections__List__1 mut ref const adamant_children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(adamant_children__, Symbol__0__0new__identifier__2(allocate(sizeof(Symbol__0)), unqualified_name__1(language_namespace__), language_children__));
	return Symbol__0__0new__identifier__2(allocate(sizeof(Symbol__0)), unqualified_name__1(adamant_namespace__), adamant_children__);
}

Symbol__0 const ref mut build_optional_type_symbol__1(Name__0 const ref const language_namespace__)
{
	Name__0 const ref const optional_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), language_namespace__, TypeName__, ((string){{8},(uint8_t*)u8"optional"}));
	system__collections__List__1 mut ref const type_parameters__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(type_parameters__, Type__0__0new__3(allocate(sizeof(Type__0)), TypeParameterType__, Name__0__0new__3(allocate(sizeof(Name__0)), optional_name__, TypeParameterName__, ((string){{1},(uint8_t*)u8"T"})), TRUE));
	Type__0 const ref const type__ = Type__0__0new__primitive__2(allocate(sizeof(Type__0)), optional_name__, type_parameters__);
	system__collections__List__1 mut ref const declarations__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return Symbol__0__0new__declaring__3(allocate(sizeof(Symbol__0)), type__, declarations__, children__);
}

Symbol__0 const ref mut build_primitive_symbol__2(string const name__, Name__0 const ref const namespace__)
{
	Type__0 const ref const type__ = Type__0__0new__primitive__1(allocate(sizeof(Type__0)), Name__0__0new__special__3(allocate(sizeof(Name__0)), namespace__, TypeName__, name__));
	system__collections__List__1 mut ref const declarations__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return Symbol__0__0new__declaring__3(allocate(sizeof(Symbol__0)), type__, declarations__, children__);
}

void mut build_fixed_point_primitives__3(system__collections__List__1 mut ref const symbols__, int32 const bits__, Name__0 const ref const namespace__)
{
}

void mut unit_test_build_primitives_package__0()
{
	Package_name_is_dollar_primitives__0();
	Package_has_no_references_or_compilation_units__0();
	Package_symbol_has_package_name__0();
	Package_symbol_has_children__0();
	Package_contains_the_string_type__0();
	Package_contains_optional_type__0();
}

void mut Package_name_is_dollar_primitives__0()
{
	Package__0 const ref const package__ = build_primitives_package__0();
	Package_Name__0 const ref const name__ = package__->name__;
	assert__1(string__0op__equal(name__->unqualified__, ((string){{11},(uint8_t*)u8"$primitives"})));
}

void mut Package_has_no_references_or_compilation_units__0()
{
	Package__0 const ref const package__ = build_primitives_package__0();
	assert__1(int32__0op__equal(package__->references__->count__, ((int32){0})));
	assert__1(int32__0op__equal(package__->compilation_units__->count__, ((int32){0})));
}

void mut Package_symbol_has_package_name__0()
{
	Package__0 const ref const package__ = build_primitives_package__0();
	Symbol__0 const ref const symbol__ = package__->symbol__;
	assert__1(int32__0op__equal(symbol__->kind__, PackageSymbol__));
	string const symbol_name__ = symbol__->name__;
	assert__1(string__0op__equal(symbol_name__, package__->name__->unqualified__));
}

void mut Package_symbol_has_children__0()
{
	Package__0 const ref const package__ = build_primitives_package__0();
	assert__1(int32__0op__gt(package__->symbol__->children__->count__, ((int32){0})));
}

void mut Package_contains_the_string_type__0()
{
	Package__0 const ref const package__ = build_primitives_package__0();
	Symbol__0 const ref const string_symbol__ = get_child_symbol__3(package__->symbol__, ((string){{6},(uint8_t*)u8"string"}), IdentifierSymbol__);
	assert__1(void_ptr__0op__not_equal(string_symbol__, none));
}

void mut Package_contains_optional_type__0()
{
	Package__0 const ref const package__ = build_primitives_package__0();
	Symbol__0 const opt_ref const adamant_symbol__ = get_child_symbol__3(package__->symbol__, ((string){{7},(uint8_t*)u8"adamant"}), IdentifierSymbol__);
	assert__1(void_ptr__0op__not_equal(adamant_symbol__, none));
	Symbol__0 const opt_ref const langauge_symbol__ = get_child_symbol__3(adamant_symbol__, ((string){{8},(uint8_t*)u8"language"}), IdentifierSymbol__);
	assert__1(void_ptr__0op__not_equal(langauge_symbol__, none));
	Symbol__0 const opt_ref const optional_symbol__ = get_child_symbol__3(langauge_symbol__, ((string){{8},(uint8_t*)u8"optional"}), IdentifierSymbol__);
	assert__1(void_ptr__0op__not_equal(optional_symbol__, none));
}

Program_Fragment__0 mut ref mut Program_Fragment__0__0new__0(Program_Fragment__0 mut ref const self) { self->type_id = Program_Fragment__0__0Type_ID; return self; }

Package__0 const ref mut build_runtime_library_package__0()
{
	Package_Name__0 const ref const name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){{8},(uint8_t*)u8"$runtime"}));
	system__collections__List__1 const ref const references__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	system__collections__List__1 const ref const compilation_units__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	system__collections__List__1 const ref const symbols__ = build_runtime_library_symbols__1(name__);
	assert__2(int32__0op__equal(symbols__->count__, ((int32){42})), string__0op__add(((string){{14},(uint8_t*)u8"symbols.count="}), int_to_string__1(symbols__->count__)));
	Symbol__0 const ref const package_symbol__ = Symbol__0__0new__package__2(allocate(sizeof(Symbol__0)), name__->unqualified__, symbols__);
	assert__2(int32__0op__gt(package_symbol__->children__->count__, ((int32){0})), string__0op__add(((string){{30},(uint8_t*)u8"package_symbol.children.count="}), int_to_string__1(package_symbol__->children__->count__)));
	return Package__0__0new__4(allocate(sizeof(Package__0)), name__, references__, compilation_units__, package_symbol__);
}

system__collections__List__1 mut ref mut build_runtime_library_symbols__1(Package_Name__0 const ref const package_name__)
{
	Name__0 const ref const global_namespace__ = Name__0__0new__global_namespace__1(allocate(sizeof(Name__0)), package_name__);
	system__collections__List__1 mut ref const symbols__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{8},(uint8_t*)u8"allocate"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{4},(uint8_t*)u8"free"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{14},(uint8_t*)u8"bool_to_string"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{13},(uint8_t*)u8"int_to_string"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{17},(uint8_t*)u8"int_to_hex_string"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{17},(uint8_t*)u8"hex_string_to_int"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{17},(uint8_t*)u8"int_to_code_point"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{20},(uint8_t*)u8"code_point_to_string"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{18},(uint8_t*)u8"string_byte_length"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{9},(uint8_t*)u8"substring"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{14},(uint8_t*)u8"string_replace"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{15},(uint8_t*)u8"string_index_of"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{20},(uint8_t*)u8"string_last_index_of"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{17},(uint8_t*)u8"code_point_as_int"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{15},(uint8_t*)u8"NOT_IMPLEMENTED"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{11},(uint8_t*)u8"UNREACHABLE"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{6},(uint8_t*)u8"assert"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{11},(uint8_t*)u8"debug_write"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{16},(uint8_t*)u8"debug_write_line"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{12},(uint8_t*)u8"get_resource"}))));
	add_item__2(symbols__, build_class_symbol__2(global_namespace__, ((string){{7},(uint8_t*)u8"Strings"})));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{13},(uint8_t*)u8"clear_strings"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{10},(uint8_t*)u8"add_string"}))));
	add_item__2(symbols__, build_class_symbol__2(global_namespace__, ((string){{4},(uint8_t*)u8"Ints"})));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{10},(uint8_t*)u8"clear_ints"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{7},(uint8_t*)u8"add_int"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{10},(uint8_t*)u8"clear_list"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{8},(uint8_t*)u8"add_item"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{13},(uint8_t*)u8"console_write"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{18},(uint8_t*)u8"console_write_line"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{16},(uint8_t*)u8"file_read_to_end"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{17},(uint8_t*)u8"close_file_reader"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{10},(uint8_t*)u8"file_write"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{17},(uint8_t*)u8"close_file_writer"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{9},(uint8_t*)u8"sb_append"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{12},(uint8_t*)u8"sb_append_sb"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{14},(uint8_t*)u8"sb_append_line"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{9},(uint8_t*)u8"sb_remove"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{12},(uint8_t*)u8"sb_to_string"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{6},(uint8_t*)u8"as_any"}))));
	add_item__2(symbols__, build_function_symbol__1(Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, FunctionName__, ((string){{10},(uint8_t*)u8"as_any_mut"}))));
	Name__0 const ref const system_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, NamespaceName__, ((string){{6},(uint8_t*)u8"system"}));
	system__collections__List__1 mut ref const system_symbols__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	Name__0 const ref const collections_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), system_namespace__, NamespaceName__, ((string){{11},(uint8_t*)u8"collections"}));
	system__collections__List__1 mut ref const collections_symbols__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	system__collections__List__1 mut ref const list_type_parameters__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(list_type_parameters__, Type__0__0new__parameter__1(allocate(sizeof(Type__0)), ((string){{1},(uint8_t*)u8"T"})));
	add_item__2(collections_symbols__, build_generic_class_symbol__3(collections_namespace__, ((string){{4},(uint8_t*)u8"List"}), list_type_parameters__));
	add_item__2(system_symbols__, build_namespace_symbol__2(collections_namespace__, collections_symbols__));
	Name__0 const ref const console_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), system_namespace__, NamespaceName__, ((string){{7},(uint8_t*)u8"console"}));
	system__collections__List__1 mut ref const console_symbols__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(console_symbols__, build_class_symbol__2(console_namespace__, ((string){{7},(uint8_t*)u8"Console"})));
	add_item__2(console_symbols__, build_class_symbol__2(console_namespace__, ((string){{9},(uint8_t*)u8"Arguments"})));
	add_item__2(system_symbols__, build_namespace_symbol__2(console_namespace__, console_symbols__));
	Name__0 const ref const io_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), system_namespace__, NamespaceName__, ((string){{2},(uint8_t*)u8"io"}));
	system__collections__List__1 mut ref const io_symbols__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(io_symbols__, build_class_symbol__2(io_namespace__, ((string){{11},(uint8_t*)u8"File_Reader"})));
	add_item__2(io_symbols__, build_class_symbol__2(io_namespace__, ((string){{11},(uint8_t*)u8"File_Writer"})));
	add_item__2(system_symbols__, build_namespace_symbol__2(io_namespace__, io_symbols__));
	Name__0 const ref const text_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), system_namespace__, NamespaceName__, ((string){{4},(uint8_t*)u8"text"}));
	system__collections__List__1 mut ref const text_symbols__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	system__collections__List__1 mut ref const string_builder_symbols__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(string_builder_symbols__, build_constructor_symbol__1(((string){{13},(uint8_t*)u8"with_capacity"})));
	add_item__2(text_symbols__, build_class_symbol__3(text_namespace__, ((string){{14},(uint8_t*)u8"String_Builder"}), string_builder_symbols__));
	add_item__2(system_symbols__, build_namespace_symbol__2(text_namespace__, text_symbols__));
	add_item__2(symbols__, build_namespace_symbol__2(system_namespace__, system_symbols__));
	return symbols__;
}

Symbol__0 const ref mut build_function_symbol__1(Name__0 const ref const name__)
{
	Type__0 const ref const type__ = Type__0__0new__3(allocate(sizeof(Type__0)), FunctionType__, name__, FALSE);
	system__collections__List__1 const ref const declarations__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	system__collections__List__1 const ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return Symbol__0__0new__of_type__4(allocate(sizeof(Symbol__0)), unqualified_name__1(name__), type__, declarations__, children__);
}

Symbol__0 const ref mut build_namespace_symbol__2(Name__0 const ref const name__, system__collections__List__1 const ref const symbols__)
{
	Type__0 const ref const type__ = Type__0__0new__namespace__1(allocate(sizeof(Type__0)), name__);
	system__collections__List__1 const ref const declarations__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return Symbol__0__0new__declaring__3(allocate(sizeof(Symbol__0)), type__, declarations__, symbols__);
}

Symbol__0 const ref mut build_class_symbol__2(Name__0 const ref const namespace__, string const class_name__)
{
	Type__0 const ref const type__ = Type__0__0new__3(allocate(sizeof(Type__0)), ReferenceType__, Name__0__0new__3(allocate(sizeof(Name__0)), namespace__, TypeName__, class_name__), TRUE);
	system__collections__List__1 const ref const declarations__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	system__collections__List__1 const ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return Symbol__0__0new__declaring__3(allocate(sizeof(Symbol__0)), type__, declarations__, children__);
}

Symbol__0 const ref mut build_class_symbol__3(Name__0 const ref const namespace__, string const class_name__, system__collections__List__1 const ref const children__)
{
	Type__0 const ref const type__ = Type__0__0new__3(allocate(sizeof(Type__0)), ReferenceType__, Name__0__0new__3(allocate(sizeof(Name__0)), namespace__, TypeName__, class_name__), TRUE);
	system__collections__List__1 const ref const declarations__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return Symbol__0__0new__declaring__3(allocate(sizeof(Symbol__0)), type__, declarations__, children__);
}

Symbol__0 const ref mut build_generic_class_symbol__3(Name__0 const ref const namespace__, string const class_name__, system__collections__List__1 const ref const type_parameters__)
{
	Type__0 const ref const type__ = Type__0__0new__4(allocate(sizeof(Type__0)), ReferenceType__, Name__0__0new__3(allocate(sizeof(Name__0)), namespace__, TypeName__, class_name__), type_parameters__, TRUE);
	system__collections__List__1 const ref const declarations__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	system__collections__List__1 const ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return Symbol__0__0new__declaring__3(allocate(sizeof(Symbol__0)), type__, declarations__, children__);
}

Symbol__0 const ref mut build_constructor_symbol__1(string const name__)
{
	string const constructor_name__ = string__0op__add(((string){{4},(uint8_t*)u8"new_"}), name__);
	system__collections__List__1 const ref const declarations__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return Symbol__0__0new__constructor__2(allocate(sizeof(Symbol__0)), constructor_name__, declarations__);
}

void mut unit_test_build_runtime_library_package__0()
{
	Runtime_Library_Package_contains_system_package__0();
	System_namespace_contains_console_namespace__0();
	Console_namespace_contains_Console_class__0();
	System_namespace_contains_collections_namespace__0();
	Collections_namespace_contains_List_class__0();
}

void mut Runtime_Library_Package_contains_system_package__0()
{
	Package__0 const ref const package__ = build_runtime_library_package__0();
	assert__1(never__0op__not_equal(get_child_symbol__3(package__->symbol__, ((string){{6},(uint8_t*)u8"system"}), IdentifierSymbol__), none));
}

void mut System_namespace_contains_console_namespace__0()
{
	Package__0 const ref const package__ = build_runtime_library_package__0();
	Symbol__0 const opt_ref const system_namespace__ = get_child_symbol__3(package__->symbol__, ((string){{6},(uint8_t*)u8"system"}), IdentifierSymbol__);
	assert__1(void_ptr__0op__not_equal(system_namespace__, none));
	assert__1(never__0op__not_equal(get_child_symbol__3(system_namespace__, ((string){{7},(uint8_t*)u8"console"}), IdentifierSymbol__), none));
}

void mut Console_namespace_contains_Console_class__0()
{
	Package__0 const ref const package__ = build_runtime_library_package__0();
	Symbol__0 const opt_ref const system_namespace__ = get_child_symbol__3(package__->symbol__, ((string){{6},(uint8_t*)u8"system"}), IdentifierSymbol__);
	assert__1(void_ptr__0op__not_equal(system_namespace__, none));
	Symbol__0 const opt_ref const console_namespace__ = get_child_symbol__3(system_namespace__, ((string){{7},(uint8_t*)u8"console"}), IdentifierSymbol__);
	assert__1(void_ptr__0op__not_equal(console_namespace__, none));
	assert__1(never__0op__not_equal(get_child_symbol__3(console_namespace__, ((string){{7},(uint8_t*)u8"Console"}), IdentifierSymbol__), none));
}

void mut System_namespace_contains_collections_namespace__0()
{
	Package__0 const ref const package__ = build_runtime_library_package__0();
	Symbol__0 const opt_ref const system_namespace__ = get_child_symbol__3(package__->symbol__, ((string){{6},(uint8_t*)u8"system"}), IdentifierSymbol__);
	assert__1(void_ptr__0op__not_equal(system_namespace__, none));
	assert__1(never__0op__not_equal(get_child_symbol__3(system_namespace__, ((string){{11},(uint8_t*)u8"collections"}), IdentifierSymbol__), none));
}

void mut Collections_namespace_contains_List_class__0()
{
	Package__0 const ref const package__ = build_runtime_library_package__0();
	Symbol__0 const opt_ref const system_namespace__ = get_child_symbol__3(package__->symbol__, ((string){{6},(uint8_t*)u8"system"}), IdentifierSymbol__);
	assert__1(void_ptr__0op__not_equal(system_namespace__, none));
	Symbol__0 const opt_ref const collections_namespace__ = get_child_symbol__3(system_namespace__, ((string){{11},(uint8_t*)u8"collections"}), IdentifierSymbol__);
	assert__1(void_ptr__0op__not_equal(collections_namespace__, none));
	assert__1(never__0op__not_equal(get_child_symbol__3(collections_namespace__, ((string){{4},(uint8_t*)u8"List"}), IdentifierSymbol__), none));
}

Package__0 const ref mut analyze_semantics__1(Syntax_Node__0 const ref const package_syntax__)
{
	assert__2(int32__0op__equal(package_syntax__->kind__, PackageNode__), string__0op__add(((string){{20},(uint8_t*)u8"package_syntax.kind="}), int_to_string__1(package_syntax__->kind__)));
	Package_Name__0 const ref const name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){{7},(uint8_t*)u8"default"}));
	Package__0 const ref const primitives_package__ = build_primitives_package__0();
	Package__0 const ref const runtime_package__ = build_runtime_library_package__0();
	system__collections__List__1 mut ref const references__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(references__, Package_Reference__0__0new__1(allocate(sizeof(Package_Reference__0)), primitives_package__));
	add_item__2(references__, Package_Reference__0__0new__1(allocate(sizeof(Package_Reference__0)), runtime_package__));
	Name_Table__0 const ref const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Semantic_Tree_Builder__0 const ref const semantic_tree_builder__ = Semantic_Tree_Builder__0__0new__0(allocate(sizeof(Semantic_Tree_Builder__0)));
	system__collections__List__1 const ref const compilation_units__ = build_compilation_units__3(semantic_tree_builder__, package_syntax__, name_table__);
	Symbol__0 const ref const package_symbol__ = build_symbols__2(name__, compilation_units__);
	Package__0 const ref const package__ = Package__0__0new__4(allocate(sizeof(Package__0)), name__, references__, compilation_units__, package_symbol__);
	return package__;
}

Semantic_Node__0 mut ref mut Semantic_Node__0__0new__token__1(Semantic_Node__0 mut ref const self, Token__0 const ref const token__)
{
	self->type_id = Semantic_Node__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(token__, none));
	self->syntax__ = token_as_syntax__1(token__);
	self->kind__ = token__->kind__;
	self->is_missing__ = token__->is_missing__;
	self->source__ = token__->source__;
	self->start__ = token__->start__;
	self->byte_length__ = token__->byte_length__;
	self->children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->of_type__ = none;
	self->declares_type__ = none;
	self->referenced_type__ = none;
	return self;
}

Semantic_Node__0 mut ref mut Semantic_Node__0__0new__concrete__1(Semantic_Node__0 mut ref const self, Syntax_Node__0 const ref const node__)
{
	self->type_id = Semantic_Node__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(node__, none));
	self->syntax__ = syntax_node_as_syntax__1(node__);
	self->kind__ = node__->kind__;
	self->is_missing__ = node__->is_missing__;
	self->source__ = node__->source__;
	self->start__ = node__->start__;
	self->byte_length__ = node__->byte_length__;
	self->children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->of_type__ = none;
	self->declares_type__ = none;
	self->referenced_type__ = none;
	return self;
}

Semantic_Node__0 mut ref mut Semantic_Node__0__0new__concrete__2(Semantic_Node__0 mut ref const self, Syntax_Node__0 const ref const node__, Diagnostic__0 const ref const diagnostic__)
{
	self->type_id = Semantic_Node__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(node__, none));
	self->syntax__ = syntax_node_as_syntax__1(node__);
	self->kind__ = node__->kind__;
	self->is_missing__ = node__->is_missing__;
	self->source__ = node__->source__;
	self->start__ = node__->start__;
	self->byte_length__ = node__->byte_length__;
	self->children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	system__collections__List__1 mut ref const diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(diagnostics__, diagnostic__);
	self->diagnostics__ = diagnostics__;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->referenced_type__ = none;
	return self;
}

Semantic_Node__0 mut ref mut Semantic_Node__0__0new__concrete_with_children__2(Semantic_Node__0 mut ref const self, Syntax_Node__0 const ref const node__, system__collections__List__1 const ref const children__)
{
	self->type_id = Semantic_Node__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(node__, none));
	self->syntax__ = syntax_node_as_syntax__1(node__);
	self->kind__ = node__->kind__;
	self->is_missing__ = node__->is_missing__;
	self->source__ = node__->source__;
	self->start__ = node__->start__;
	self->byte_length__ = node__->byte_length__;
	self->children__ = children__;
	self->diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->of_type__ = none;
	self->declares_type__ = none;
	self->referenced_type__ = none;
	return self;
}

Semantic_Node__0 mut ref mut Semantic_Node__0__0new__of_type__3(Semantic_Node__0 mut ref const self, Type__0 const ref const of_type__, Syntax_Node__0 const ref const node__, system__collections__List__1 const ref const children__)
{
	self->type_id = Semantic_Node__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(of_type__, none));
	assert__1(void_ptr__0op__not_equal(node__, none));
	self->syntax__ = syntax_node_as_syntax__1(node__);
	self->kind__ = node__->kind__;
	self->is_missing__ = node__->is_missing__;
	self->source__ = node__->source__;
	self->start__ = node__->start__;
	self->byte_length__ = node__->byte_length__;
	self->children__ = children__;
	self->diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->of_type__ = of_type__;
	self->declares_type__ = none;
	self->referenced_type__ = none;
	return self;
}

Semantic_Node__0 mut ref mut Semantic_Node__0__0new__declares_type__3(Semantic_Node__0 mut ref const self, Type__0 const ref const type__, Syntax_Node__0 const ref const node__, system__collections__List__1 const ref const children__)
{
	self->type_id = Semantic_Node__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(type__, none));
	assert__1(void_ptr__0op__not_equal(node__, none));
	self->syntax__ = syntax_node_as_syntax__1(node__);
	self->kind__ = node__->kind__;
	self->is_missing__ = node__->is_missing__;
	self->source__ = node__->source__;
	self->start__ = node__->start__;
	self->byte_length__ = node__->byte_length__;
	self->children__ = children__;
	self->diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->of_type__ = none;
	self->declares_type__ = type__;
	self->referenced_type__ = none;
	return self;
}

Semantic_Node__0 mut ref mut Semantic_Node__0__0new__referencing_type__3(Semantic_Node__0 mut ref const self, Type__0 const ref const type__, Syntax_Node__0 const ref const node__, system__collections__List__1 const ref const children__)
{
	self->type_id = Semantic_Node__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(type__, none));
	assert__1(void_ptr__0op__not_equal(node__, none));
	self->syntax__ = syntax_node_as_syntax__1(node__);
	self->kind__ = node__->kind__;
	self->is_missing__ = node__->is_missing__;
	self->source__ = node__->source__;
	self->start__ = node__->start__;
	self->byte_length__ = node__->byte_length__;
	self->children__ = children__;
	self->diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->of_type__ = none;
	self->declares_type__ = none;
	self->referenced_type__ = type__;
	return self;
}

Program_Fragment__0 const ref mut semantic_node_as_program_fragment__1(Semantic_Node__0 const ref const node__)
{
	return as_any__1(node__);
}

Text_Span__0 const ref mut get_semantic_node_text_span__1(Semantic_Node__0 const ref const node__)
{
	return Text_Span__0__0new__2(allocate(sizeof(Text_Span__0)), node__->start__, node__->byte_length__);
}

string mut get_semantic_node_text__1(Semantic_Node__0 const ref const node__)
{
	if (cond(void_ptr__0op__equal(node__->source__, none)))
	{
		return ((string){{11},(uint8_t*)u8"$No Source$"});
	}

	return substring__3(node__->source__->text__, node__->start__, node__->byte_length__);
}

Semantic_Node__0 const opt_ref mut first_child__2(Semantic_Node__0 const ref const node__, int32 const kind__)
{
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Program_Fragment__0 const ref const child__ = void_ptr__0current(&iter);
		/* match */ { void const ref const match_value = child__;
		   switch(*(Type_ID const ref)match_value)
		{
			case Semantic_Node__0__0Type_ID:
			{
				Semantic_Node__0 const ref const node__ = match_value;
				if (cond(int32__0op__equal(node__->kind__, kind__)))
				{
					return node__;
				}
			}
			break;
			case Expression__0__0Type_ID:
			{
			}
			break;
			default:
			   NON_EXHAUSTIVE_MATCH(*(Type_ID const ref)match_value);
		}}
	}

	return none;
}

system__collections__List__1 const ref mut children_of_kind__2(Semantic_Node__0 const ref const node__, int32 const kind__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Program_Fragment__0 const ref const child__ = void_ptr__0current(&iter);
		/* match */ { void const ref const match_value = child__;
		   switch(*(Type_ID const ref)match_value)
		{
			case Semantic_Node__0__0Type_ID:
			{
				Semantic_Node__0 const ref const node__ = match_value;
				if (cond(int32__0op__equal(node__->kind__, kind__)))
				{
					add_item__2(children__, node__);
				}
			}
			break;
			case Expression__0__0Type_ID:
			{
			}
			break;
			default:
			   NON_EXHAUSTIVE_MATCH(*(Type_ID const ref)match_value);
		}}
	}

	return children__;
}

system__collections__List__1 const ref mut node_members__1(Semantic_Node__0 const ref const node__)
{
	system__collections__List__1 mut ref const members__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Program_Fragment__0 const ref const child__ = void_ptr__0current(&iter);
		/* match */ { void const ref const match_value = child__;
		   switch(*(Type_ID const ref)match_value)
		{
			case Semantic_Node__0__0Type_ID:
			{
				Semantic_Node__0 const ref const node__ = match_value;
				if (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(node__->kind__, ConstructorDeclaration__)) || bool_arg(int32__0op__equal(node__->kind__, FieldDeclaration__)))) || bool_arg(int32__0op__equal(node__->kind__, MethodDeclaration__)))))
				{
					add_item__2(members__, node__);
				}
			}
			break;
			case Expression__0__0Type_ID:
			{
			}
			break;
			default:
			   NON_EXHAUSTIVE_MATCH(*(Type_ID const ref)match_value);
		}}
	}

	return members__;
}

system__collections__List__1 const ref mut node_statements__1(Semantic_Node__0 const ref const node__)
{
	system__collections__List__1 mut ref const statements__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Program_Fragment__0 const ref const child__ = void_ptr__0current(&iter);
		/* match */ { void const ref const match_value = child__;
		   switch(*(Type_ID const ref)match_value)
		{
			case Semantic_Node__0__0Type_ID:
			{
				Semantic_Node__0 const ref const node__ = match_value;
				if (cond(bool_op(bool_arg(int32__0op__not_equal(node__->kind__, LeftBrace__)) && bool_arg(int32__0op__not_equal(node__->kind__, RightBrace__)))))
				{
					add_item__2(statements__, node__);
				}
			}
			break;
			case Expression__0__0Type_ID:
			{
			}
			break;
			default:
			   NON_EXHAUSTIVE_MATCH(*(Type_ID const ref)match_value);
		}}
	}

	return statements__;
}

system__collections__List__1 const ref mut node_parameters__1(Semantic_Node__0 const ref const node__)
{
	system__collections__List__1 mut ref const parameters__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Program_Fragment__0 const ref const child__ = void_ptr__0current(&iter);
		/* match */ { void const ref const match_value = child__;
		   switch(*(Type_ID const ref)match_value)
		{
			case Semantic_Node__0__0Type_ID:
			{
				Semantic_Node__0 const ref const node__ = match_value;
				if (cond(bool_op(bool_arg(int32__0op__equal(node__->kind__, Parameter__)) || bool_arg(int32__0op__equal(node__->kind__, SelfParameter__)))))
				{
					add_item__2(parameters__, node__);
				}
			}
			break;
			case Expression__0__0Type_ID:
			{
			}
			break;
			default:
			   NON_EXHAUSTIVE_MATCH(*(Type_ID const ref)match_value);
		}}
	}

	return parameters__;
}

int32 mut node_argument_count__1(Semantic_Node__0 const ref const node__)
{
	int32 mut count__ = ((int32){0});
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Program_Fragment__0 const ref const child__ = void_ptr__0current(&iter);
		/* match */ { void const ref const match_value = child__;
		   switch(*(Type_ID const ref)match_value)
		{
			case Semantic_Node__0__0Type_ID:
			{
				Semantic_Node__0 const ref const node__ = match_value;
				if (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(node__->kind__, LeftParen__)) || bool_arg(int32__0op__equal(node__->kind__, RightParen__)))) || bool_arg(int32__0op__equal(node__->kind__, Comma__)))))
				{
					continue;
				}

				op__add_assign(&(count__), ((int32){1}));
			}
			break;
			case Expression__0__0Type_ID:
			{
			}
			break;
			default:
			   NON_EXHAUSTIVE_MATCH(*(Type_ID const ref)match_value);
		}}
	}

	return count__;
}

Semantic_Node__0 const opt_ref mut node_access_modifier__1(Semantic_Node__0 const ref const node__)
{
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Program_Fragment__0 const ref const child__ = void_ptr__0current(&iter);
		/* match */ { void const ref const match_value = child__;
		   switch(*(Type_ID const ref)match_value)
		{
			case Semantic_Node__0__0Type_ID:
			{
				Semantic_Node__0 const ref const node__ = match_value;
				if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(node__->kind__, PublicKeyword__)) || bool_arg(int32__0op__equal(node__->kind__, ProtectedKeyword__)))) || bool_arg(int32__0op__equal(node__->kind__, PrivateKeyword__)))) || bool_arg(int32__0op__equal(node__->kind__, InternalKeyword__)))))
				{
					return node__;
				}
			}
			break;
			case Expression__0__0Type_ID:
			{
			}
			break;
			default:
			   NON_EXHAUSTIVE_MATCH(*(Type_ID const ref)match_value);
		}}
	}

	return none;
}

BOOL mut node_has_child__2(Semantic_Node__0 const ref const node__, int32 const kind__)
{
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Program_Fragment__0 const ref const child__ = void_ptr__0current(&iter);
		/* match */ { void const ref const match_value = child__;
		   switch(*(Type_ID const ref)match_value)
		{
			case Semantic_Node__0__0Type_ID:
			{
				Semantic_Node__0 const ref const node__ = match_value;
				if (cond(int32__0op__equal(node__->kind__, kind__)))
				{
					return TRUE;
				}
			}
			break;
			case Expression__0__0Type_ID:
			{
			}
			break;
			default:
			   NON_EXHAUSTIVE_MATCH(*(Type_ID const ref)match_value);
		}}
	}

	return FALSE;
}

system__collections__List__1 const ref mut diagnostics__1(Semantic_Node__0 const ref const node__)
{
	return node__->diagnostics__;
}

void mut collect_node_diagnostics__2(Semantic_Node__0 const ref const node__, system__collections__List__1 mut ref const diagnostics__)
{
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(node__->diagnostics__); void_ptr__0next(&iter);)
	{
		Diagnostic__0 const ref const diagnostic__ = void_ptr__0current(&iter);
		add_item__2(diagnostics__, diagnostic__);
	}

	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(node__->children__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const ref const child__ = void_ptr__0current(&iter);
		collect_node_diagnostics__2(child__, diagnostics__);
	}
}

Semantic_Tree_Builder__0 mut ref mut Semantic_Tree_Builder__0__0new__0(Semantic_Tree_Builder__0 mut ref const self)
{
	self->type_id = Semantic_Tree_Builder__0__0Type_ID;
	Package_Name__0 const ref const primitives_package__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){{11},(uint8_t*)u8"$primitives"}));
	Name__0 const ref const global_namespace__ = Name__0__0new__global_namespace__1(allocate(sizeof(Name__0)), primitives_package__);
	Name__0 const ref const adamant_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__, NamespaceName__, ((string){{7},(uint8_t*)u8"adamant"}));
	Name__0 const ref const language_namespace__ = Name__0__0new__3(allocate(sizeof(Name__0)), adamant_namespace__, NamespaceName__, ((string){{8},(uint8_t*)u8"language"}));
	self->optional_type_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), language_namespace__, TypeName__, ((string){{8},(uint8_t*)u8"optional"}));
	return self;
}

system__collections__List__1 const ref mut build_compilation_units__3(Semantic_Tree_Builder__0 const ref const builder__, Syntax_Node__0 const ref const package_syntax__, Name_Table__0 const ref const name_table__)
{
	assert__2(int32__0op__equal(package_syntax__->kind__, PackageNode__), string__0op__add(((string){{20},(uint8_t*)u8"package_syntax.kind="}), int_to_string__1(package_syntax__->kind__)));
	assert__2(never__0op__not_equal(lookup_special__2(name_table__->any_package__, ((string){{6},(uint8_t*)u8"string"})), none), string__0op__add(((string){{28},(uint8_t*)u8"name_table.any_package.name="}), full_name__1(name_table__->any_package__->name__)));
	system__collections__List__1 mut ref const compilation_units__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (void_ptr__0iter mut iter = void_ptr__0iterate(package_syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const ref const compilation_unit_syntax__ = void_ptr__0current(&iter);
		add_item__2(compilation_units__, build_compilation_unit_semantic_node__3(builder__, compilation_unit_syntax__, name_table__));
	}

	return compilation_units__;
}

Compilation_Unit__0 const ref mut build_compilation_unit_semantic_node__3(Semantic_Tree_Builder__0 const ref const builder__, Syntax_Node__0 const ref const compilation_unit_syntax__, Name_Table__0 const ref const name_table__)
{
	assert__2(int32__0op__equal(compilation_unit_syntax__->kind__, CompilationUnit__), string__0op__add(((string){{29},(uint8_t*)u8"compilation_unit_syntax.kind="}), int_to_string__1(compilation_unit_syntax__->kind__)));
	system__collections__List__1 mut ref const declarations__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (void_ptr__0iter mut iter = void_ptr__0iterate(compilation_unit_syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const ref const declaration_syntax__ = void_ptr__0current(&iter);
		add_item__2(declarations__, build_semantic_node__4(builder__, declaration_syntax__, name_table__, name_table__->any_package__));
	}

	return Compilation_Unit__0__0new__2(allocate(sizeof(Compilation_Unit__0)), compilation_unit_syntax__, declarations__);
}

Semantic_Node__0 const ref mut build_semantic_node__4(Semantic_Tree_Builder__0 const ref const builder__, Syntax_Node__0 const ref const syntax__, Name_Table__0 const ref const name_table__, Name_Subtable__0 const ref const scope__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	if (cond(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, FunctionDeclaration__)) || bool_arg(int32__0op__equal(syntax__->kind__, MethodDeclaration__)))))
	{
		add_item__2(children__, build_semantic_node__4(builder__, as_any__1(access_modifier__1(syntax__)), name_table__, scope__));
		Token__0 const ref const function_name__ = first_child_token__2(syntax__, Identifier__);
		add_item__2(children__, build_semantic_node__4(builder__, as_any__1(function_name__), name_table__, scope__));
		Name_Subtable__0 mut ref const function_scope__ = find__2(scope__, get_token_text__1(function_name__));
		assert__2(void_ptr__0op__not_equal(function_scope__, none), string__0op__add(((string){{36},(uint8_t*)u8"get_syntax_node_text(function_name)="}), get_token_text__1(function_name__)));
		Syntax_Node__0 const ref const parameters__ = first_child_syntax_node__2(syntax__, ParameterList__);
		add_item__2(children__, build_parameters_semantic_node__4(builder__, parameters__, name_table__, function_scope__));
		Syntax_Node__0 const ref const return_type__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){4}));
		add_item__2(children__, build_type_name_semantic_node__4(builder__, return_type__, name_table__, scope__));
		Type__0 const ref const function_type__ = Type__0__0new__3(allocate(sizeof(Type__0)), FunctionType__, function_scope__->name__, FALSE);
		bind_type__2(function_scope__, function_type__);
		Syntax_Node__0 const ref const body__ = first_child_syntax_node__2(syntax__, Block__);
		if (cond(void_ptr__0op__not_equal(body__, none)))
		{
			add_item__2(children__, build_semantic_node__4(builder__, body__, name_table__, function_scope__));
		}

		return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
	}
	else if (cond(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, ClassDeclaration__)) || bool_arg(int32__0op__equal(syntax__->kind__, StructDeclaration__)))))
	{
		Token__0 const ref const type_name__ = first_child_token__2(syntax__, Identifier__);
		add_item__2(children__, build_semantic_node__4(builder__, as_any__1(type_name__), name_table__, scope__));
		Name_Subtable__0 const ref const type_scope__ = find__2(scope__, get_token_text__1(type_name__));
		assert__2(void_ptr__0op__not_equal(type_scope__, none), string__0op__add(((string){{32},(uint8_t*)u8"get_syntax_node_text(type_name)="}), get_token_text__1(type_name__)));
		for (void_ptr__0iter mut iter = void_ptr__0iterate(members__1(syntax__)); void_ptr__0next(&iter);)
		{
			Syntax_Node__0 const ref const member__ = void_ptr__0current(&iter);
			add_item__2(children__, build_semantic_node__4(builder__, member__, name_table__, type_scope__));
		}

		return Semantic_Node__0__0new__declares_type__3(allocate(sizeof(Semantic_Node__0)), type_scope__->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ConstructorDeclaration__)))
	{
		add_item__2(children__, build_semantic_node__4(builder__, as_any__1(access_modifier__1(syntax__)), name_table__, scope__));
		string mut full_name__ = ((string){{3},(uint8_t*)u8"new"});
		Token__0 const opt_ref const constructor_name__ = first_child_token__2(syntax__, Identifier__);
		if (cond(void_ptr__0op__not_equal(constructor_name__, none)))
		{
			full_name__ = string__0op__add(((string){{4},(uint8_t*)u8"new_"}), get_token_text__1(constructor_name__));
			add_item__2(children__, Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), constructor_name__));
		}

		Name_Subtable__0 const ref const constructor_scope__ = find_special__2(scope__, full_name__);
		assert__2(void_ptr__0op__not_equal(constructor_scope__, none), string__0op__add(((string){{10},(uint8_t*)u8"full_name="}), full_name__));
		Syntax_Node__0 const ref const parameters__ = first_child_syntax_node__2(syntax__, ParameterList__);
		add_item__2(children__, build_parameters_semantic_node__4(builder__, parameters__, name_table__, constructor_scope__));
		Syntax_Node__0 const ref const body__ = first_child_syntax_node__2(syntax__, Block__);
		if (cond(void_ptr__0op__not_equal(body__, none)))
		{
			add_item__2(children__, build_semantic_node__4(builder__, body__, name_table__, constructor_scope__));
		}

		return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, IdentifierName__)))
	{
		Name_Subtable__0 const ref const name_scope__ = lookup__2(scope__, get_syntax_node_text__1(syntax__));
		if (cond(void_ptr__0op__equal(name_scope__, none)))
		{
			if (cond(BOOL__0op__not(syntax__->is_missing__)))
			{
				return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, resolution_error__1(syntax__));
			}
			else
			{
				return Semantic_Node__0__0new__concrete__1(allocate(sizeof(Semantic_Node__0)), syntax__);
			}
		}
		else
		{
			if (cond(never__0op__equal(name_scope__->type__, none)))
			{
				return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
			}
			else
			{
				return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), name_scope__->type__, syntax__, children__);
			}
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, MemberAccessExpression__)))
	{
		Semantic_Node__0 const ref const lhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		add_item__2(children__, lhs__);
		Semantic_Node__0 const ref mut rhs__;
		Syntax_Node__0 const ref const member_name__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){2}));
		if (cond(void_ptr__0op__equal(lhs__->of_type__, none)))
		{
			rhs__ = Semantic_Node__0__0new__concrete__1(allocate(sizeof(Semantic_Node__0)), member_name__);
		}
		else
		{
			Name_Subtable__0 const ref const access_scope__ = get_name__2(name_table__, lhs__->of_type__->name__);
			Name_Subtable__0 const ref const member_scope__ = find__2(access_scope__, get_syntax_node_text__1(member_name__));
			if (cond(void_ptr__0op__equal(member_scope__, none)))
			{
				rhs__ = Semantic_Node__0__0new__concrete__1(allocate(sizeof(Semantic_Node__0)), member_name__);
			}
			else
			{
				system__collections__List__1 const ref const no_children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
				if (cond(never__0op__equal(member_scope__->type__, none)))
				{
					rhs__ = Semantic_Node__0__0new__concrete__1(allocate(sizeof(Semantic_Node__0)), member_name__);
				}
				else
				{
					rhs__ = Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), member_scope__->type__, member_name__, no_children__);
				}
			}
		}

		add_item__2(children__, rhs__);
		if (cond(void_ptr__0op__equal(rhs__->of_type__, none)))
		{
			return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
		}
		else
		{
			return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), rhs__->of_type__, syntax__, children__);
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NewExpression__)))
	{
		add_item__2(children__, build_constructor_name_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), name_table__, scope__));
		add_item__2(children__, build_semantic_node__4(builder__, first_child_syntax_node__2(syntax__, ArgumentList__), name_table__, scope__));
		return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, LocalDeclarationStatement__)))
	{
		Syntax_Node__0 const ref const variable_declaration_syntax__ = first_child_syntax_node__2(syntax__, VariableDeclaration__);
		add_item__2(children__, build_semantic_node__4(builder__, variable_declaration_syntax__, name_table__, scope__));
		return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, VariableDeclaration__)))
	{
		Token__0 const ref const binding_syntax__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		add_item__2(children__, Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), binding_syntax__));
		Token__0 const ref const identifier__ = first_child_token__2(syntax__, Identifier__);
		add_item__2(children__, Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), identifier__));
		Syntax_Node__0 const ref const type_syntax__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){3}));
		Semantic_Node__0 const ref const type_node__ = build_type_name_semantic_node__4(builder__, type_syntax__, name_table__, scope__);
		assert__2(void_ptr__0op__not_equal(type_node__->referenced_type__, none), get_semantic_node_text__1(type_node__));
		Name_Subtable__0 mut ref const variable_scope__ = lookup__2(scope__, get_token_text__1(identifier__));
		assert__2(void_ptr__0op__not_equal(variable_scope__, none), get_syntax_node_text__1(syntax__));
		bind_type__2(variable_scope__, type_node__->referenced_type__);
		bind_type__2(as_mut__1(get_name__2(name_table__, variable_scope__->name__)), type_node__->referenced_type__);
		add_item__2(children__, type_node__);
		if (cond(int32__0op__equal(syntax__->children__->count__, ((int32){6}))))
		{
			Syntax_Node__0 const ref const initalizer__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){5}));
			add_item__2(children__, build_semantic_node__4(builder__, initalizer__, name_table__, scope__));
		}

		return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, MatchPattern__)))
	{
		Token__0 const ref const identifier__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		add_item__2(children__, Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), identifier__));
		Token__0 const ref const colon__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}));
		add_item__2(children__, Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), colon__));
		Syntax_Node__0 const ref const type_syntax__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){2}));
		Semantic_Node__0 const ref const type_node__ = build_type_name_semantic_node__4(builder__, type_syntax__, name_table__, scope__);
		add_item__2(children__, type_node__);
		return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
	}
	else if (cond(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, TrueLiteralExpression__)) || bool_arg(int32__0op__equal(syntax__->kind__, FalseLiteralExpression__)))))
	{
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{4},(uint8_t*)u8"bool"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, StringLiteralExpression__)))
	{
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{6},(uint8_t*)u8"string"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, CodePointLiteralExpression__)))
	{
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{10},(uint8_t*)u8"code_point"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, IntegerLiteralExpression__)))
	{
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{3},(uint8_t*)u8"int"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NoneLiteralExpression__)))
	{
		Type__0 const ref const type__ = build_optional_type__3(builder__, name_table__, lookup_special__2(scope__, ((string){{5},(uint8_t*)u8"never"}))->type__);
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, SelfExpression__)))
	{
		add_item__2(children__, Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), first_child_token__2(syntax__, SelfKeyword__)));
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{4},(uint8_t*)u8"self"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NegateExpression__)))
	{
		Semantic_Node__0 const ref const operand__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), name_table__, scope__);
		add_item__2(children__, operand__);
		assert__2(void_ptr__0op__not_equal(operand__->of_type__, none), get_syntax_node_text__1(syntax__));
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{3},(uint8_t*)u8"int"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, AddExpression__)))
	{
		Semantic_Node__0 const ref const lhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		Semantic_Node__0 const ref const rhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), name_table__, scope__);
		add_item__2(children__, lhs__);
		add_item__2(children__, rhs__);
		Type__0 const ref mut type__ = lhs__->of_type__;
		if (cond(void_ptr__0op__equal(type__, none)))
		{
			type__ = rhs__->of_type__;
		}

		if (cond(void_ptr__0op__equal(type__, none)))
		{
			type__ = lookup_special__2(scope__, ((string){{3},(uint8_t*)u8"int"}))->type__;
		}

		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, SubtractExpression__)))
	{
		Semantic_Node__0 const ref const lhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		Semantic_Node__0 const ref const rhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), name_table__, scope__);
		add_item__2(children__, lhs__);
		add_item__2(children__, rhs__);
		assert__2(void_ptr__0op__not_equal(rhs__->of_type__, none), get_syntax_node_text__1(syntax__));
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{3},(uint8_t*)u8"int"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, MultiplyExpression__)))
	{
		Semantic_Node__0 const ref const lhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		Semantic_Node__0 const ref const rhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), name_table__, scope__);
		add_item__2(children__, lhs__);
		add_item__2(children__, rhs__);
		assert__2(void_ptr__0op__not_equal(lhs__->of_type__, none), get_syntax_node_text__1(syntax__));
		assert__2(void_ptr__0op__not_equal(rhs__->of_type__, none), get_syntax_node_text__1(syntax__));
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{3},(uint8_t*)u8"int"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, DivideExpression__)))
	{
		Semantic_Node__0 const ref const lhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		Semantic_Node__0 const ref const rhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), name_table__, scope__);
		add_item__2(children__, lhs__);
		add_item__2(children__, rhs__);
		assert__2(void_ptr__0op__not_equal(lhs__->of_type__, none), get_syntax_node_text__1(syntax__));
		assert__2(void_ptr__0op__not_equal(rhs__->of_type__, none), get_syntax_node_text__1(syntax__));
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{3},(uint8_t*)u8"int"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, RemainderExpression__)))
	{
		Semantic_Node__0 const ref const lhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		Semantic_Node__0 const ref const rhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), name_table__, scope__);
		add_item__2(children__, lhs__);
		add_item__2(children__, rhs__);
		assert__2(void_ptr__0op__not_equal(lhs__->of_type__, none), get_syntax_node_text__1(syntax__));
		assert__2(void_ptr__0op__not_equal(rhs__->of_type__, none), get_syntax_node_text__1(syntax__));
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{3},(uint8_t*)u8"int"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ParenthesizedExpression__)))
	{
		Semantic_Node__0 const ref const operand__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), name_table__, scope__);
		add_item__2(children__, operand__);
		assert__2(void_ptr__0op__not_equal(operand__->of_type__, none), get_syntax_node_text__1(syntax__));
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), operand__->of_type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, EqualExpression__)))
	{
		Semantic_Node__0 const ref const lhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		Semantic_Node__0 const ref const rhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), name_table__, scope__);
		add_item__2(children__, lhs__);
		add_item__2(children__, rhs__);
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{4},(uint8_t*)u8"bool"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NotEqualExpression__)))
	{
		Semantic_Node__0 const ref const lhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		Semantic_Node__0 const ref const rhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), name_table__, scope__);
		add_item__2(children__, lhs__);
		add_item__2(children__, rhs__);
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{4},(uint8_t*)u8"bool"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ComparisonExpression__)))
	{
		Semantic_Node__0 const ref const lhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		Semantic_Node__0 const ref const rhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), name_table__, scope__);
		add_item__2(children__, lhs__);
		add_item__2(children__, Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), system__collections__List__1__0op__element(syntax__->children__, ((int32){1}))));
		add_item__2(children__, rhs__);
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{4},(uint8_t*)u8"bool"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, AndExpression__)))
	{
		Semantic_Node__0 const ref const lhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		Semantic_Node__0 const ref const rhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), name_table__, scope__);
		add_item__2(children__, lhs__);
		add_item__2(children__, rhs__);
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{4},(uint8_t*)u8"bool"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, OrExpression__)))
	{
		Semantic_Node__0 const ref const lhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		Semantic_Node__0 const ref const rhs__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), name_table__, scope__);
		add_item__2(children__, lhs__);
		add_item__2(children__, rhs__);
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{4},(uint8_t*)u8"bool"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NotExpression__)))
	{
		Semantic_Node__0 const ref const operand__ = build_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), name_table__, scope__);
		add_item__2(children__, operand__);
		return Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), lookup_special__2(scope__, ((string){{4},(uint8_t*)u8"bool"}))->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->children__->count__, ((int32){0}))))
	{
		return Semantic_Node__0__0new__concrete__1(allocate(sizeof(Semantic_Node__0)), syntax__);
	}
	else
	{
		for (void_ptr__0iter mut iter = void_ptr__0iterate(syntax__->children__); void_ptr__0next(&iter);)
		{
			Syntax_Node__0 const ref const child_syntax__ = void_ptr__0current(&iter);
			add_item__2(children__, build_semantic_node__4(builder__, child_syntax__, name_table__, scope__));
		}

		return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
	}
}

Semantic_Node__0 mut ref mut build_parameters_semantic_node__4(Semantic_Tree_Builder__0 const ref const builder__, Syntax_Node__0 const ref const parameters_syntax__, Name_Table__0 const ref const name_table__, Name_Subtable__0 const ref const scope__)
{
	assert__2(int32__0op__equal(parameters_syntax__->kind__, ParameterList__), string__0op__add(((string){{23},(uint8_t*)u8"parameters_syntax.kind="}), int_to_string__1(parameters_syntax__->kind__)));
	system__collections__List__1 mut ref const parameter_nodes__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (void_ptr__0iter mut iter = void_ptr__0iterate(parameters__1(parameters_syntax__)); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const ref const parameter__ = void_ptr__0current(&iter);
		system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
		if (cond(int32__0op__equal(parameter__->kind__, Parameter__)))
		{
			Token__0 const opt_ref const var_syntax__ = first_child_token__2(parameter__, VarKeyword__);
			if (cond(void_ptr__0op__not_equal(var_syntax__, none)))
			{
				add_item__2(children__, Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), var_syntax__));
			}

			Token__0 const ref const identifier__ = first_child_token__2(parameter__, Identifier__);
			add_item__2(children__, Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), identifier__));
			Syntax_Node__0 const ref const type_syntax__ = system__collections__List__1__0op__element(parameter__->children__, int32__0op__sub(parameter__->children__->count__, ((int32){1})));
			Semantic_Node__0 const ref const type_node__ = build_type_name_semantic_node__4(builder__, type_syntax__, name_table__, scope__);
			assert__2(void_ptr__0op__not_equal(type_node__->referenced_type__, none), get_syntax_node_text__1(parameter__));
			add_item__2(children__, type_node__);
			Name_Subtable__0 mut ref const parameter_scope__ = lookup__2(scope__, get_token_text__1(identifier__));
			assert__2(void_ptr__0op__not_equal(parameter_scope__, none), get_token_text__1(identifier__));
			bind_type__2(parameter_scope__, type_node__->referenced_type__);
			add_item__2(parameter_nodes__, Semantic_Node__0__0new__of_type__3(allocate(sizeof(Semantic_Node__0)), type_node__->referenced_type__, parameter__, children__));
		}
		else if (cond(int32__0op__equal(parameter__->kind__, SelfParameter__)))
		{
			for (void_ptr__0iter mut iter = void_ptr__0iterate(parameter__->children__); void_ptr__0next(&iter);)
			{
				Syntax_Node__0 const ref const child_syntax__ = void_ptr__0current(&iter);
				add_item__2(children__, Semantic_Node__0__0new__concrete__1(allocate(sizeof(Semantic_Node__0)), child_syntax__));
			}

			add_item__2(parameter_nodes__, Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), parameter__, children__));
		}
		else
		{
			NOT_IMPLEMENTED__1(string__0op__add(((string){{15},(uint8_t*)u8"parameter.kind="}), int_to_string__1(parameter__->kind__)));
		}
	}

	return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), parameters_syntax__, parameter_nodes__);
}

Semantic_Node__0 mut ref mut build_type_name_semantic_node__4(Semantic_Tree_Builder__0 const ref const builder__, Syntax_Node__0 const ref const syntax__, Name_Table__0 const ref const name_table__, Name_Subtable__0 const ref const scope__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	if (cond(int32__0op__equal(syntax__->kind__, PredefinedType__)))
	{
		string const primitive_name__ = get_syntax_node_text__1(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})));
		Name_Subtable__0 const opt_ref const primitive_entry__ = lookup_special__2(scope__, primitive_name__);
		assert__2(void_ptr__0op__not_equal(primitive_entry__, none), string__0op__add(string__0op__add(((string){{24},(uint8_t*)u8"No entry for primitive `"}), primitive_name__), ((string){{1},(uint8_t*)u8"`"})));
		return Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), primitive_entry__->type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, IdentifierName__)))
	{
		if (cond(syntax__->is_missing__))
		{
			return Semantic_Node__0__0new__concrete__1(allocate(sizeof(Semantic_Node__0)), syntax__);
		}

		string const name__ = get_syntax_node_text__1(syntax__);
		Name_Subtable__0 const opt_ref const entry__ = lookup__2(scope__, name__);
		if (cond(void_ptr__0op__equal(entry__, none)))
		{
			return Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), syntax__, resolution_error__1(syntax__));
		}
		else
		{
			return Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), entry__->type__, syntax__, children__);
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, QualifiedName__)))
	{
		Syntax_Node__0 const ref const qualifier_syntax__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		Semantic_Node__0 const ref const qualifier__ = build_type_name_semantic_node__4(builder__, qualifier_syntax__, name_table__, scope__);
		add_item__2(children__, qualifier__);
		Syntax_Node__0 const ref const qualified_syntax__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){2}));
		if (cond(int32__0op__equal(qualified_syntax__->kind__, IdentifierName__)))
		{
			Syntax_Node__0 const ref const name_syntax__ = qualified_syntax__;
			if (cond(void_ptr__0op__equal(qualifier__->referenced_type__, none)))
			{
				Semantic_Node__0 const ref const name_node__ = Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), name_syntax__, resolution_error__2(name_syntax__, qualifier__));
				add_item__2(children__, name_node__);
				return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
			}
			else
			{
				Type__0 const ref const containing_type__ = qualifier__->referenced_type__;
				Name_Subtable__0 const ref const containing_scope__ = get_name__2(name_table__, containing_type__->name__);
				assert__2(void_ptr__0op__not_equal(containing_scope__, none), full_name__1(containing_type__->name__));
				Name_Subtable__0 const ref const referenced_scope__ = find__2(containing_scope__, get_syntax_node_text__1(name_syntax__));
				if (cond(void_ptr__0op__equal(referenced_scope__, none)))
				{
					Semantic_Node__0 const ref const name_node__ = Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), name_syntax__, resolution_error__2(name_syntax__, qualifier__));
					add_item__2(children__, name_node__);
					return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
				}

				Type__0 const ref const referenced_type__ = referenced_scope__->type__;
				Semantic_Node__0 const ref const name_node__ = Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), referenced_type__, name_syntax__, system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1))));
				add_item__2(children__, name_node__);
				return Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), referenced_type__, syntax__, children__);
			}
		}
		else if (cond(int32__0op__equal(qualified_syntax__->kind__, GenericName__)))
		{
			Syntax_Node__0 const ref const name_syntax__ = first_child_syntax_node__2(qualified_syntax__, IdentifierName__);
			system__collections__List__1 mut ref const generic_name_children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
			if (cond(void_ptr__0op__equal(qualifier__->referenced_type__, none)))
			{
				Semantic_Node__0 const ref const name_node__ = Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), name_syntax__, resolution_error__2(name_syntax__, qualifier__));
				add_item__2(generic_name_children__, name_node__);
				build_type_arguments_semantic_node__5(builder__, qualified_syntax__, name_table__, scope__, generic_name_children__);
				Semantic_Node__0 mut ref const qualified_name__ = Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), qualified_syntax__, generic_name_children__);
				add_item__2(children__, qualified_name__);
				return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
			}
			else
			{
				Type__0 const ref const containing_type__ = qualifier__->referenced_type__;
				Name_Subtable__0 const ref const containing_scope__ = get_name__2(name_table__, containing_type__->name__);
				assert__2(void_ptr__0op__not_equal(containing_scope__, none), full_name__1(containing_type__->name__));
				Name_Subtable__0 const ref const referenced_scope__ = find__2(containing_scope__, get_syntax_node_text__1(name_syntax__));
				if (cond(void_ptr__0op__equal(referenced_scope__, none)))
				{
					Semantic_Node__0 const ref const name_node__ = Semantic_Node__0__0new__concrete__2(allocate(sizeof(Semantic_Node__0)), name_syntax__, resolution_error__2(name_syntax__, qualifier__));
					add_item__2(generic_name_children__, name_node__);
					build_type_arguments_semantic_node__5(builder__, qualified_syntax__, name_table__, scope__, generic_name_children__);
					Semantic_Node__0 mut ref const qualified_name__ = Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), qualified_syntax__, generic_name_children__);
					add_item__2(children__, qualified_name__);
					return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
				}

				Type__0 const ref const referenced_type_name__ = referenced_scope__->type__;
				Semantic_Node__0 const ref const name_node__ = Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), referenced_type_name__, name_syntax__, system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1))));
				add_item__2(generic_name_children__, name_node__);
				system__collections__List__1 const ref const type_parameters__ = build_type_arguments_semantic_node__5(builder__, qualified_syntax__, name_table__, scope__, generic_name_children__);
				Type__0 const ref const referenced_type__ = Type__0__0new__generic__2(allocate(sizeof(Type__0)), referenced_type_name__, type_parameters__);
				Semantic_Node__0 mut ref const qualified_name__ = Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), referenced_type__, qualified_syntax__, generic_name_children__);
				add_item__2(children__, qualified_name__);
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
		Semantic_Node__0 const ref const inner_type__ = build_type_name_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), name_table__, scope__);
		add_item__2(children__, inner_type__);
		if (cond(void_ptr__0op__equal(inner_type__->referenced_type__, none)))
		{
			return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
		}

		Type__0 const ref const type__ = make_mutable_type__1(inner_type__->referenced_type__);
		return Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ImmutableType__)))
	{
		Semantic_Node__0 const ref const inner_type__ = build_type_name_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		add_item__2(children__, inner_type__);
		if (cond(void_ptr__0op__equal(inner_type__->referenced_type__, none)))
		{
			return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
		}

		Type__0 const ref const type__ = make_immutable_type__1(inner_type__->referenced_type__);
		return Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), type__, syntax__, children__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, OptionalType__)))
	{
		Semantic_Node__0 const ref const inner_type__ = build_type_name_semantic_node__4(builder__, system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), name_table__, scope__);
		add_item__2(children__, inner_type__);
		if (cond(void_ptr__0op__equal(inner_type__->referenced_type__, none)))
		{
			return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
		}

		Type__0 const ref const type__ = build_optional_type__3(builder__, name_table__, inner_type__->referenced_type__);
		return Semantic_Node__0__0new__referencing_type__3(allocate(sizeof(Semantic_Node__0)), type__, syntax__, children__);
	}
	else
	{
		int32 const place__ = syntax__->start__;
		NOT_IMPLEMENTED__1(string__0op__add(string__0op__add(string__0op__add(((string){{12},(uint8_t*)u8"syntax.kind="}), int_to_string__1(syntax__->kind__)), ((string){{4},(uint8_t*)u8" at "})), int_to_string__1(place__)));
	}
}

Type__0 const ref mut build_optional_type__3(Semantic_Tree_Builder__0 const ref const builder__, Name_Table__0 const ref const name_table__, Type__0 const ref const base_type__)
{
	Name_Subtable__0 const opt_ref const optional_type_scope__ = get_name__2(name_table__, builder__->optional_type_name__);
	assert__1(void_ptr__0op__not_equal(optional_type_scope__, none));
	Type__0 const ref const optional_type__ = optional_type_scope__->type__;
	system__collections__List__1 mut ref const type_arguments__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(type_arguments__, base_type__);
	Type__0 const ref const type__ = Type__0__0new__generic__2(allocate(sizeof(Type__0)), optional_type__, type_arguments__);
	return type__;
}

system__collections__List__1 const ref mut build_type_arguments_semantic_node__5(Semantic_Tree_Builder__0 const ref const builder__, Syntax_Node__0 const ref const syntax__, Name_Table__0 const ref const name_table__, Name_Subtable__0 const ref const scope__, system__collections__List__1 mut ref const children__)
{
	system__collections__List__1 mut ref const type_parameters__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	if (cond(int32__0op__equal(syntax__->kind__, IdentifierName__)))
	{
		return type_parameters__;
	}

	assert__2(int32__0op__equal(syntax__->kind__, GenericName__), string__0op__add(((string){{13},(uint8_t*)u8"syntax.kind=="}), int_to_string__1(syntax__->kind__)));
	BOOL mut in_type_arguments__ = FALSE;
	for (void_ptr__0iter mut iter = void_ptr__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const ref const type_argument__ = void_ptr__0current(&iter);
		if (cond(in_type_arguments__))
		{
			if (cond(int32__0op__not_equal(type_argument__->kind__, GreaterThan__)))
			{
				Semantic_Node__0 const ref const type_node__ = build_type_name_semantic_node__4(builder__, type_argument__, name_table__, scope__);
				add_item__2(type_parameters__, type_node__->referenced_type__);
				add_item__2(children__, type_node__);
			}
		}
		else if (cond(int32__0op__equal(type_argument__->kind__, LessThan__)))
		{
			in_type_arguments__ = TRUE;
		}
	}

	return type_parameters__;
}

Semantic_Node__0 const ref mut build_constructor_name_semantic_node__4(Semantic_Tree_Builder__0 const ref const builder__, Syntax_Node__0 const ref const syntax__, Name_Table__0 const ref const name_table__, Name_Subtable__0 const ref const scope__)
{
	if (cond(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, QualifiedName__)) && bool_arg(int32__0op__equal(as_syntax_node__1(system__collections__List__1__0op__element(syntax__->children__, ((int32){2})))->kind__, IdentifierName__)))))
	{
		system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
		Syntax_Node__0 const ref const qualifier__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		Semantic_Node__0 const ref const type_node__ = build_type_name_semantic_node__4(builder__, qualifier__, name_table__, scope__);
		add_item__2(children__, type_node__);
		Token__0 const ref const name__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){2}));
		string const constructor_name__ = string__0op__add(((string){{4},(uint8_t*)u8"new_"}), get_token_text__1(name__));
		Type__0 const ref const referenced_type__ = type_node__->referenced_type__;
		assert__2(void_ptr__0op__not_equal(referenced_type__, none), string__0op__add(string__0op__add(((string){{24},(uint8_t*)u8"no referenced type for `"}), get_semantic_node_text__1(type_node__)), ((string){{1},(uint8_t*)u8"`"})));
		Name_Subtable__0 const opt_ref const constructor_scope__ = lookup_special__2(get_name__2(name_table__, referenced_type__->name__), constructor_name__);
		if (cond(void_ptr__0op__not_equal(constructor_scope__, none)))
		{
			add_item__2(children__, Semantic_Node__0__0new__token__1(allocate(sizeof(Semantic_Node__0)), name__));
			return Semantic_Node__0__0new__concrete_with_children__2(allocate(sizeof(Semantic_Node__0)), syntax__, children__);
		}
	}

	return build_type_name_semantic_node__4(builder__, syntax__, name_table__, scope__);
}

Syntax_Node__0 const ref mut as_syntax_node__1(Syntax_Node__0 const ref const syntax__)
{
	return syntax__;
}

Diagnostic__0 const ref mut resolution_error__1(Syntax_Node__0 const ref const node__)
{
	return Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), FatalCompilationError__, Analysis__, node__->source__, get_syntax_node_text_span__1(node__), string__0op__add(string__0op__add(((string){{24},(uint8_t*)u8"Could not resolve name `"}), get_syntax_node_text__1(node__)), ((string){{1},(uint8_t*)u8"`"})));
}

Diagnostic__0 const ref mut resolution_error__2(Syntax_Node__0 const ref const node__, Semantic_Node__0 const ref const qualifier__)
{
	return Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), FatalCompilationError__, Analysis__, node__->source__, get_syntax_node_text_span__1(node__), string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){{24},(uint8_t*)u8"Could not resolve name `"}), get_syntax_node_text__1(node__)), ((string){{21},(uint8_t*)u8"` because qualifier `"})), get_semantic_node_text__1(qualifier__)), ((string){{24},(uint8_t*)u8"` could not be resolved."})));
}

Symbol__0 const ref mut build_symbols__2(Package_Name__0 const ref const package_name__, system__collections__List__1 const ref const compilation_units__)
{
	system__collections__List__1 mut ref const symbols__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return Symbol__0__0new__package__2(allocate(sizeof(Symbol__0)), package_name__->unqualified__, symbols__);
}

Compilation_Unit_Parser__0 mut ref mut Compilation_Unit_Parser__0__0new__1(Compilation_Unit_Parser__0 mut ref const self, Token_Stream__0 mut ref const token_stream__)
{
	self->type_id = Compilation_Unit_Parser__0__0Type_ID;
	self->token_stream__ = token_stream__;
	self->compilation_unit__ = none;
	return self;
}

Syntax__0 const ref mut parse__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	if (cond(void_ptr__0op__equal(parser__->compilation_unit__, none)))
	{
		parser__->token__ = next_token__1(parser__->token_stream__);
		parser__->compilation_unit__ = parse_compilation_unit__1(parser__);
	}

	return parser__->compilation_unit__;
}

Token__0 const opt_ref mut accept_token__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	Token__0 const opt_ref const token__ = parser__->token__;
	parser__->token__ = next_token__1(parser__->token_stream__);
	return token__;
}

Token__0 const ref mut expect_token__2(Compilation_Unit_Parser__0 mut ref const parser__, int32 const kind__)
{
	if (cond(void_ptr__0op__equal(parser__->token__, none)))
	{
		return Token__0__0new__missing__3(allocate(sizeof(Token__0)), kind__, parser__->token_stream__->source__, source_byte_length__1(parser__->token_stream__->source__));
	}
	else
	{
		if (cond(int32__0op__not_equal(parser__->token__->kind__, kind__)))
		{
			return Token__0__0new__missing__3(allocate(sizeof(Token__0)), kind__, parser__->token_stream__->source__, parser__->token__->start__);
		}

		Token__0 const ref const token__ = parser__->token__;
		parser__->token__ = next_token__1(parser__->token_stream__);
		return token__;
	}
}

Syntax__0 const ref mut parse_type_name__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, CodePoint__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, String__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, Int__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, Bool__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, Void__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, UnsignedInt__)))))
	{
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), PredefinedType__, token_as_syntax__1(accept_token__1(parser__))));
	}
	else
	{
		Syntax_Node__0 const ref mut type__ = Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), IdentifierName__, token_as_syntax__1(expect_token__2(parser__, Identifier__)));
		while (cond(int32__0op__equal(parser__->token__->kind__, Dot__)))
		{
			system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
			add_item__2(children__, type__);
			add_item__2(children__, expect_token__2(parser__, Dot__));
			Token__0 const ref const identifier__ = expect_token__2(parser__, Identifier__);
			if (cond(int32__0op__equal(parser__->token__->kind__, LessThan__)))
			{
				system__collections__List__1 mut ref const generic_name_children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
				add_item__2(generic_name_children__, Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), IdentifierName__, token_as_syntax__1(identifier__)));
				add_item__2(generic_name_children__, expect_token__2(parser__, LessThan__));
				add_item__2(generic_name_children__, parse_type__1(parser__));
				add_item__2(generic_name_children__, expect_token__2(parser__, GreaterThan__));
				add_item__2(children__, Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), GenericName__, generic_name_children__));
			}
			else
			{
				add_item__2(children__, Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), IdentifierName__, token_as_syntax__1(identifier__)));
			}

			type__ = Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), QualifiedName__, children__);
		}

		return syntax_node_as_syntax__1(type__);
	}
}

Syntax__0 const ref mut parse_non_optional_type__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	if (cond(int32__0op__equal(parser__->token__->kind__, MutableKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, MutableKeyword__));
		add_item__2(children__, parse_type_name__1(parser__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), MutableType__, children__));
	}
	else
	{
		add_item__2(children__, parse_type_name__1(parser__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), ImmutableType__, children__));
	}
}

Syntax__0 const ref mut parse_type__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	Syntax__0 const ref mut type__ = parse_non_optional_type__1(parser__);
	while (cond(int32__0op__equal(parser__->token__->kind__, Question__)))
	{
		system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
		add_item__2(children__, type__);
		add_item__2(children__, expect_token__2(parser__, Question__));
		type__ = syntax_node_as_syntax__1(Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), ImmutableType__, syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), OptionalType__, children__))));
	}

	return type__;
}

Syntax__0 const ref mut parse_atom__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	if (cond(int32__0op__equal(parser__->token__->kind__, NewKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, NewKeyword__));
		add_item__2(children__, parse_type_name__1(parser__));
		add_item__2(children__, parse_call_arguments__1(parser__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), NewExpression__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, NotKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, NotKeyword__));
		add_item__2(children__, parse_expression__2(parser__, ((int32){8})));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), NotExpression__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, LeftParen__)))
	{
		add_item__2(children__, expect_token__2(parser__, LeftParen__));
		add_item__2(children__, parse_expression__1(parser__));
		add_item__2(children__, expect_token__2(parser__, RightParen__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), ParenthesizedExpression__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, Minus__)))
	{
		add_item__2(children__, expect_token__2(parser__, Minus__));
		add_item__2(children__, parse_expression__2(parser__, ((int32){8})));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), NegateExpression__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, NoneKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, NoneKeyword__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), NoneLiteralExpression__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, SelfKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, SelfKeyword__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), SelfExpression__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, TrueKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, TrueKeyword__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), TrueLiteralExpression__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, FalseKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, FalseKeyword__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), FalseLiteralExpression__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, Integer__)))
	{
		add_item__2(children__, expect_token__2(parser__, Integer__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), IntegerLiteralExpression__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, Identifier__)))
	{
		add_item__2(children__, expect_token__2(parser__, Identifier__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), IdentifierName__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, StringLiteral__)))
	{
		add_item__2(children__, expect_token__2(parser__, StringLiteral__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), StringLiteralExpression__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, CodePointLiteral__)))
	{
		add_item__2(children__, expect_token__2(parser__, CodePointLiteral__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), CodePointLiteralExpression__, children__));
	}

	return syntax_node_as_syntax__1(Syntax_Node__0__0new__2(allocate(sizeof(Syntax_Node__0)), IdentifierName__, token_as_syntax__1(expect_token__2(parser__, Identifier__))));
}

Syntax__0 const ref mut parse_call_arguments__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(children__, expect_token__2(parser__, LeftParen__));
	if (cond(int32__0op__not_equal(parser__->token__->kind__, RightParen__)))
	{
		for (;;)
		{
			add_item__2(children__, parse_expression__1(parser__));
			if (cond(int32__0op__equal(parser__->token__->kind__, Comma__)))
			{
				add_item__2(children__, expect_token__2(parser__, Comma__));
			}
			else
			{
				break;
			}
		}
	}

	add_item__2(children__, expect_token__2(parser__, RightParen__));
	return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), ArgumentList__, children__));
}

Syntax__0 const ref mut parse_expression__2(Compilation_Unit_Parser__0 mut ref const parser__, int32 const min_precedence__)
{
	Syntax__0 const ref mut expression__ = parse_atom__1(parser__);
	for (;;)
	{
		system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
		add_item__2(children__, expression__);
		int32 mut precedence__;
		BOOL mut left_associative__;
		BOOL mut suffix_operator__ = FALSE;
		int32 mut expression_type__;
		if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, Equals__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, PlusEquals__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, MinusEquals__)))) && bool_arg(int32__0op__lte(min_precedence__, ((int32){1}))))))
		{
			precedence__ = ((int32){1});
			left_associative__ = FALSE;
			add_item__2(children__, accept_token__1(parser__));
			expression_type__ = AssignmentExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, OrKeyword__)) && bool_arg(int32__0op__lte(min_precedence__, ((int32){2}))))))
		{
			precedence__ = ((int32){2});
			left_associative__ = TRUE;
			add_item__2(children__, expect_token__2(parser__, OrKeyword__));
			expression_type__ = OrExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, AndKeyword__)) && bool_arg(int32__0op__lte(min_precedence__, ((int32){3}))))))
		{
			precedence__ = ((int32){3});
			left_associative__ = TRUE;
			add_item__2(children__, expect_token__2(parser__, AndKeyword__));
			expression_type__ = AndExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, EqualsEquals__)) && bool_arg(int32__0op__lte(min_precedence__, ((int32){4}))))))
		{
			precedence__ = ((int32){4});
			left_associative__ = TRUE;
			add_item__2(children__, expect_token__2(parser__, EqualsEquals__));
			expression_type__ = EqualExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, EqualsSlashEquals__)) && bool_arg(int32__0op__lte(min_precedence__, ((int32){4}))))))
		{
			precedence__ = ((int32){4});
			left_associative__ = TRUE;
			add_item__2(children__, expect_token__2(parser__, EqualsSlashEquals__));
			expression_type__ = NotEqualExpression__;
		}
		else if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, LessThan__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, LessThanEquals__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, GreaterThan__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, GreaterThanEquals__)))) && bool_arg(int32__0op__lte(min_precedence__, ((int32){5}))))))
		{
			precedence__ = ((int32){5});
			left_associative__ = TRUE;
			add_item__2(children__, accept_token__1(parser__));
			expression_type__ = ComparisonExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, Plus__)) && bool_arg(int32__0op__lte(min_precedence__, ((int32){6}))))))
		{
			precedence__ = ((int32){6});
			left_associative__ = TRUE;
			add_item__2(children__, expect_token__2(parser__, Plus__));
			expression_type__ = AddExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, Minus__)) && bool_arg(int32__0op__lte(min_precedence__, ((int32){6}))))))
		{
			precedence__ = ((int32){6});
			left_associative__ = TRUE;
			add_item__2(children__, expect_token__2(parser__, Minus__));
			expression_type__ = SubtractExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, Asterisk__)) && bool_arg(int32__0op__lte(min_precedence__, ((int32){7}))))))
		{
			precedence__ = ((int32){7});
			left_associative__ = TRUE;
			add_item__2(children__, expect_token__2(parser__, Asterisk__));
			expression_type__ = MultiplyExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, Slash__)) && bool_arg(int32__0op__lte(min_precedence__, ((int32){7}))))))
		{
			precedence__ = ((int32){7});
			left_associative__ = TRUE;
			add_item__2(children__, expect_token__2(parser__, Slash__));
			expression_type__ = DivideExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, Percent__)) && bool_arg(int32__0op__lte(min_precedence__, ((int32){7}))))))
		{
			precedence__ = ((int32){7});
			left_associative__ = TRUE;
			add_item__2(children__, expect_token__2(parser__, Percent__));
			expression_type__ = RemainderExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, LeftParen__)) && bool_arg(int32__0op__lte(min_precedence__, ((int32){9}))))))
		{
			precedence__ = ((int32){9});
			left_associative__ = TRUE;
			suffix_operator__ = TRUE;
			add_item__2(children__, parse_call_arguments__1(parser__));
			expression_type__ = InvocationExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, Dot__)) && bool_arg(int32__0op__lte(min_precedence__, ((int32){9}))))))
		{
			precedence__ = ((int32){9});
			left_associative__ = TRUE;
			add_item__2(children__, expect_token__2(parser__, Dot__));
			expression_type__ = MemberAccessExpression__;
		}
		else if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, LeftBracket__)) && bool_arg(int32__0op__lte(min_precedence__, ((int32){9}))))))
		{
			precedence__ = ((int32){9});
			left_associative__ = TRUE;
			suffix_operator__ = TRUE;
			add_item__2(children__, expect_token__2(parser__, LeftBracket__));
			add_item__2(children__, parse_expression__1(parser__));
			add_item__2(children__, expect_token__2(parser__, RightBracket__));
			expression_type__ = ElementAccessExpression__;
		}
		else
		{
			return expression__;
		}

		if (cond(BOOL__0op__not(suffix_operator__)))
		{
			if (cond(left_associative__))
			{
				op__add_assign(&(precedence__), ((int32){1}));
			}

			add_item__2(children__, parse_expression__2(parser__, precedence__));
			expression__ = syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), expression_type__, children__));
		}
		else
		{
			expression__ = syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), expression_type__, children__));
		}
	}
}

Syntax__0 const ref mut parse_expression__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	return parse_expression__2(parser__, ((int32){1}));
}

Syntax__0 const ref mut parse_match_arm__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	system__collections__List__1 mut ref const pattern_children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(pattern_children__, expect_token__2(parser__, Identifier__));
	add_item__2(pattern_children__, expect_token__2(parser__, Colon__));
	add_item__2(pattern_children__, parse_type__1(parser__));
	add_item__2(children__, Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), MatchPattern__, pattern_children__));
	add_item__2(children__, expect_token__2(parser__, FatArrow__));
	add_item__2(children__, parse_block__1(parser__));
	return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), MatchArm__, children__));
}

Syntax__0 const ref mut parse_statement__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	if (cond(int32__0op__equal(parser__->token__->kind__, ReturnKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, ReturnKeyword__));
		if (cond(int32__0op__not_equal(parser__->token__->kind__, Semicolon__)))
		{
			add_item__2(children__, parse_expression__1(parser__));
		}

		add_item__2(children__, expect_token__2(parser__, Semicolon__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), ReturnStatement__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, LoopKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, LoopKeyword__));
		add_item__2(children__, parse_block__1(parser__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), LoopStatement__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, WhileKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, WhileKeyword__));
		add_item__2(children__, parse_expression__1(parser__));
		add_item__2(children__, parse_block__1(parser__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), WhileStatement__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, ForKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, ForKeyword__));
		add_item__2(children__, parse_variable_declaration__2(parser__, FALSE));
		add_item__2(children__, expect_token__2(parser__, InKeyword__));
		add_item__2(children__, parse_expression__1(parser__));
		add_item__2(children__, parse_block__1(parser__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), ForStatement__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, DoKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, DoKeyword__));
		add_item__2(children__, parse_block__1(parser__));
		add_item__2(children__, expect_token__2(parser__, WhileKeyword__));
		add_item__2(children__, parse_expression__1(parser__));
		add_item__2(children__, expect_token__2(parser__, Semicolon__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), DoWhileStatement__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, IfKeyword__)))
	{
		return parse_if_statement__1(parser__);
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, MatchKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, MatchKeyword__));
		add_item__2(children__, parse_expression__1(parser__));
		add_item__2(children__, expect_token__2(parser__, LeftBrace__));
		while (cond(bool_op(bool_arg(int32__0op__not_equal(parser__->token__->kind__, RightBrace__)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, EndOfFile__)))))
		{
			Token__0 const opt_ref const start_token__ = parser__->token__;
			add_item__2(children__, parse_match_arm__1(parser__));
			if (cond(void_ptr__0op__equal(parser__->token__, start_token__)))
			{
				add_item__2(children__, Syntax_Node__0__0new__skipped__1(allocate(sizeof(Syntax_Node__0)), accept_token__1(parser__)));
			}

			if (cond(int32__0op__equal(parser__->token__->kind__, Comma__)))
			{
				add_item__2(children__, expect_token__2(parser__, Comma__));
			}
			else
			{
				break;
			}
		}

		add_item__2(children__, expect_token__2(parser__, RightBrace__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), MatchStatement__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, BreakKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, BreakKeyword__));
		add_item__2(children__, expect_token__2(parser__, Semicolon__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), BreakStatement__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, ContinueKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, ContinueKeyword__));
		add_item__2(children__, expect_token__2(parser__, Semicolon__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), ContinueStatement__, children__));
	}

	if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, VarKeyword__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, LetKeyword__)))))
	{
		add_item__2(children__, parse_variable_declaration__2(parser__, TRUE));
		add_item__2(children__, expect_token__2(parser__, Semicolon__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), LocalDeclarationStatement__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, LeftBrace__)))
	{
		return parse_block__1(parser__);
	}

	add_item__2(children__, parse_expression__1(parser__));
	add_item__2(children__, expect_token__2(parser__, Semicolon__));
	return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), ExpressionStatement__, children__));
}

Syntax__0 const ref mut parse_if_statement__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(children__, expect_token__2(parser__, IfKeyword__));
	add_item__2(children__, parse_expression__1(parser__));
	add_item__2(children__, parse_block__1(parser__));
	if (cond(int32__0op__equal(parser__->token__->kind__, ElseKeyword__)))
	{
		system__collections__List__1 mut ref const else_children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
		add_item__2(else_children__, expect_token__2(parser__, ElseKeyword__));
		if (cond(int32__0op__equal(parser__->token__->kind__, IfKeyword__)))
		{
			add_item__2(else_children__, parse_if_statement__1(parser__));
		}
		else
		{
			add_item__2(else_children__, parse_block__1(parser__));
		}

		add_item__2(children__, Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), ElseClause__, else_children__));
	}

	return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), IfStatement__, children__));
}

Syntax__0 const ref mut parse_variable_declaration__2(Compilation_Unit_Parser__0 mut ref const parser__, BOOL const allow_initializer__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, LetKeyword__)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, VarKeyword__)))))
	{
		add_item__2(children__, expect_token__2(parser__, LetKeyword__));
	}
	else
	{
		add_item__2(children__, expect_token__2(parser__, VarKeyword__));
	}

	add_item__2(children__, expect_token__2(parser__, Identifier__));
	add_item__2(children__, expect_token__2(parser__, Colon__));
	add_item__2(children__, parse_type__1(parser__));
	if (cond(bool_op(bool_arg(allow_initializer__) && bool_arg(int32__0op__equal(parser__->token__->kind__, Equals__)))))
	{
		add_item__2(children__, expect_token__2(parser__, Equals__));
		add_item__2(children__, parse_expression__1(parser__));
	}

	return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), VariableDeclaration__, children__));
}

Syntax__0 const ref mut parse_block__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(children__, expect_token__2(parser__, LeftBrace__));
	while (cond(bool_op(bool_arg(int32__0op__not_equal(parser__->token__->kind__, RightBrace__)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, EndOfFile__)))))
	{
		Token__0 const opt_ref const start_token__ = parser__->token__;
		add_item__2(children__, parse_statement__1(parser__));
		if (cond(void_ptr__0op__equal(parser__->token__, start_token__)))
		{
			system__collections__List__1 mut ref const skipped__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
			while (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__not_equal(parser__->token__->kind__, LeftBrace__)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, RightBrace__)))) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, EndOfFile__)))))
			{
				int32 const current_token_type__ = parser__->token__->kind__;
				add_item__2(skipped__, accept_token__1(parser__));
				if (cond(int32__0op__equal(current_token_type__, Semicolon__)))
				{
					break;
				}
			}

			add_item__2(children__, Syntax_Node__0__0new__skipped_many__1(allocate(sizeof(Syntax_Node__0)), skipped__));
		}
	}

	add_item__2(children__, expect_token__2(parser__, RightBrace__));
	return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), Block__, children__));
}

Syntax__0 const ref mut parse_parameter_list__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(children__, expect_token__2(parser__, LeftParen__));
	if (cond(int32__0op__not_equal(parser__->token__->kind__, RightParen__)))
	{
		for (;;)
		{
			system__collections__List__1 mut ref const parameter_children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
			if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, MutableKeyword__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, SelfKeyword__)))))
			{
				if (cond(int32__0op__equal(parser__->token__->kind__, MutableKeyword__)))
				{
					add_item__2(parameter_children__, expect_token__2(parser__, MutableKeyword__));
				}

				add_item__2(parameter_children__, expect_token__2(parser__, SelfKeyword__));
				add_item__2(children__, Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), SelfParameter__, parameter_children__));
			}
			else
			{
				if (cond(int32__0op__equal(parser__->token__->kind__, VarKeyword__)))
				{
					add_item__2(parameter_children__, expect_token__2(parser__, VarKeyword__));
				}

				add_item__2(parameter_children__, expect_token__2(parser__, Identifier__));
				add_item__2(parameter_children__, expect_token__2(parser__, Colon__));
				Syntax__0 const ref const type__ = parse_type__1(parser__);
				add_item__2(parameter_children__, type__);
				add_item__2(children__, Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), Parameter__, parameter_children__));
			}

			if (cond(int32__0op__equal(parser__->token__->kind__, Comma__)))
			{
				add_item__2(children__, expect_token__2(parser__, Comma__));
			}
			else
			{
				break;
			}
		}
	}

	add_item__2(children__, expect_token__2(parser__, RightParen__));
	return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), ParameterList__, children__));
}

Syntax__0 const ref mut parse_member_declaration__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, PublicKeyword__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, ProtectedKeyword__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, InternalKeyword__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, PrivateKeyword__)))))
	{
		add_item__2(children__, accept_token__1(parser__));
	}
	else
	{
		add_item__2(children__, expect_token__2(parser__, PublicKeyword__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, NewKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, NewKeyword__));
		if (cond(int32__0op__equal(parser__->token__->kind__, Identifier__)))
		{
			add_item__2(children__, expect_token__2(parser__, Identifier__));
		}

		add_item__2(children__, parse_parameter_list__1(parser__));
		add_item__2(children__, parse_block__1(parser__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), ConstructorDeclaration__, children__));
	}

	if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, VarKeyword__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, LetKeyword__)))))
	{
		add_item__2(children__, parse_variable_declaration__2(parser__, FALSE));
		add_item__2(children__, expect_token__2(parser__, Semicolon__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), FieldDeclaration__, children__));
	}

	add_item__2(children__, expect_token__2(parser__, Identifier__));
	add_item__2(children__, parse_parameter_list__1(parser__));
	add_item__2(children__, expect_token__2(parser__, Arrow__));
	add_item__2(children__, parse_type__1(parser__));
	add_item__2(children__, parse_block__1(parser__));
	return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), MethodDeclaration__, children__));
}

Syntax__0 const ref mut parse_declaration__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, PublicKeyword__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, ProtectedKeyword__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, InternalKeyword__)))) || bool_arg(int32__0op__equal(parser__->token__->kind__, PrivateKeyword__)))))
	{
		add_item__2(children__, accept_token__1(parser__));
	}
	else
	{
		add_item__2(children__, expect_token__2(parser__, PublicKeyword__));
	}

	if (cond(bool_op(bool_arg(int32__0op__equal(parser__->token__->kind__, VarKeyword__)) || bool_arg(int32__0op__equal(parser__->token__->kind__, LetKeyword__)))))
	{
		add_item__2(children__, parse_variable_declaration__2(parser__, TRUE));
		add_item__2(children__, expect_token__2(parser__, Semicolon__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), GlobalDeclaration__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, ClassKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, ClassKeyword__));
		add_item__2(children__, expect_token__2(parser__, Identifier__));
		add_item__2(children__, expect_token__2(parser__, LeftBrace__));
		while (cond(bool_op(bool_arg(int32__0op__not_equal(parser__->token__->kind__, RightBrace__)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, EndOfFile__)))))
		{
			Token__0 const opt_ref const start_token__ = parser__->token__;
			add_item__2(children__, parse_member_declaration__1(parser__));
			if (cond(void_ptr__0op__equal(parser__->token__, start_token__)))
			{
				add_item__2(children__, Syntax_Node__0__0new__skipped__1(allocate(sizeof(Syntax_Node__0)), accept_token__1(parser__)));
			}
		}

		add_item__2(children__, expect_token__2(parser__, RightBrace__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), ClassDeclaration__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, StructKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, StructKeyword__));
		add_item__2(children__, expect_token__2(parser__, Identifier__));
		add_item__2(children__, expect_token__2(parser__, LeftBrace__));
		while (cond(bool_op(bool_arg(int32__0op__not_equal(parser__->token__->kind__, RightBrace__)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, EndOfFile__)))))
		{
			Token__0 const opt_ref const start_token__ = parser__->token__;
			add_item__2(children__, parse_member_declaration__1(parser__));
			if (cond(void_ptr__0op__equal(parser__->token__, start_token__)))
			{
				add_item__2(children__, Syntax_Node__0__0new__skipped__1(allocate(sizeof(Syntax_Node__0)), accept_token__1(parser__)));
			}
		}

		add_item__2(children__, expect_token__2(parser__, RightBrace__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), StructDeclaration__, children__));
	}

	if (cond(int32__0op__equal(parser__->token__->kind__, EnumKeyword__)))
	{
		add_item__2(children__, expect_token__2(parser__, EnumKeyword__));
		add_item__2(children__, expect_token__2(parser__, StructKeyword__));
		add_item__2(children__, expect_token__2(parser__, Identifier__));
		add_item__2(children__, expect_token__2(parser__, LeftBrace__));
		while (cond(bool_op(bool_arg(int32__0op__not_equal(parser__->token__->kind__, RightBrace__)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, EndOfFile__)))))
		{
			system__collections__List__1 mut ref const member_children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
			add_item__2(member_children__, expect_token__2(parser__, Identifier__));
			if (cond(int32__0op__equal(parser__->token__->kind__, Equals__)))
			{
				add_item__2(member_children__, expect_token__2(parser__, Equals__));
				add_item__2(member_children__, expect_token__2(parser__, Integer__));
			}

			if (cond(int32__0op__not_equal(parser__->token__->kind__, RightBrace__)))
			{
				add_item__2(member_children__, expect_token__2(parser__, Comma__));
			}

			add_item__2(children__, Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), EnumMemberDeclaration__, member_children__));
		}

		add_item__2(children__, expect_token__2(parser__, RightBrace__));
		return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), EnumDeclaration__, children__));
	}

	add_item__2(children__, expect_token__2(parser__, Identifier__));
	add_item__2(children__, parse_parameter_list__1(parser__));
	add_item__2(children__, expect_token__2(parser__, Arrow__));
	add_item__2(children__, parse_type__1(parser__));
	add_item__2(children__, parse_block__1(parser__));
	return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), FunctionDeclaration__, children__));
}

Syntax__0 const ref mut parse_compilation_unit__1(Compilation_Unit_Parser__0 mut ref const parser__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	while (cond(bool_op(bool_arg(void_ptr__0op__not_equal(parser__->token__, none)) && bool_arg(int32__0op__not_equal(parser__->token__->kind__, EndOfFile__)))))
	{
		Token__0 const opt_ref const start_token__ = parser__->token__;
		add_item__2(children__, parse_declaration__1(parser__));
		if (cond(void_ptr__0op__equal(parser__->token__, start_token__)))
		{
			add_item__2(children__, Syntax_Node__0__0new__skipped__1(allocate(sizeof(Syntax_Node__0)), accept_token__1(parser__)));
		}
	}

	add_item__2(children__, expect_token__2(parser__, EndOfFile__));
	return syntax_node_as_syntax__1(Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), CompilationUnit__, children__));
}

Token_Stream__0 mut ref mut lexically_analyze__1(Source_Text__0 const ref const source__)
{
	return Token_Stream__0__0new__1(allocate(sizeof(Token_Stream__0)), source__);
}

Syntax_Node__0 const ref mut parse_package__1(system__collections__List__1 const ref const sources__)
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(sources__); void_ptr__0next(&iter);)
	{
		Source_Text__0 const ref const source__ = void_ptr__0current(&iter);
		Token_Stream__0 mut ref const token_stream__ = lexically_analyze__1(source__);
		Compilation_Unit_Parser__0 mut ref const compilation_unit_parser__ = Compilation_Unit_Parser__0__0new__1(allocate(sizeof(Compilation_Unit_Parser__0)), token_stream__);
		add_item__2(children__, parse__1(compilation_unit_parser__));
	}

	return Syntax_Node__0__0new__with_children__2(allocate(sizeof(Syntax_Node__0)), PackageNode__, children__);
}

Syntax__0 mut ref mut Syntax__0__0new__0(Syntax__0 mut ref const self) { self->type_id = Syntax__0__0Type_ID; return self; }

string mut syntax_to_string__1(Syntax__0 const ref const syntax__)
{
	/* match */ { void const ref const match_value = syntax__;
	   switch(*(Type_ID const ref)match_value)
	{
		case Token__0__0Type_ID:
		{
			Token__0 const ref const token__ = match_value;
			return string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){{11},(uint8_t*)u8"Token.kind="}), int_to_string__1(token__->kind__)), ((string){{3},(uint8_t*)u8", \""})), get_token_text__1(token__)), ((string){{1},(uint8_t*)u8"\""}));
		}
		break;
		case Syntax_Node__0__0Type_ID:
		{
			Syntax_Node__0 const ref const node__ = match_value;
			return string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){{17},(uint8_t*)u8"Syntax_Node.kind="}), int_to_string__1(node__->kind__)), ((string){{3},(uint8_t*)u8", \""})), get_syntax_node_text__1(node__)), ((string){{1},(uint8_t*)u8"\""}));
		}
		break;
		default:
		   NON_EXHAUSTIVE_MATCH(*(Type_ID const ref)match_value);
	}}
}

Syntax_Node__0 mut ref mut Syntax_Node__0__0new__4(Syntax_Node__0 mut ref const self, int32 const type__, Source_Text__0 const ref const source__, int32 const start__, int32 const length__)
{
	self->type_id = Syntax_Node__0__0Type_ID;
	self->is_missing__ = FALSE;
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = length__;
	self->diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->kind__ = type__;
	self->children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return self;
}

Syntax_Node__0 mut ref mut Syntax_Node__0__0new__5(Syntax_Node__0 mut ref const self, int32 const type__, BOOL const is_missing__, Source_Text__0 const ref const source__, int32 const start__, int32 const length__)
{
	self->type_id = Syntax_Node__0__0Type_ID;
	self->is_missing__ = is_missing__;
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = length__;
	self->diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->kind__ = type__;
	self->children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return self;
}

Syntax_Node__0 mut ref mut Syntax_Node__0__0new__2(Syntax_Node__0 mut ref const self, int32 const type__, Syntax__0 const ref const child__)
{
	self->type_id = Syntax_Node__0__0Type_ID;
	self->is_missing__ = child__->is_missing__;
	self->source__ = child__->source__;
	self->start__ = child__->start__;
	self->byte_length__ = child__->byte_length__;
	self->diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->kind__ = type__;
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(children__, child__);
	self->children__ = children__;
	return self;
}

Syntax_Node__0 mut ref mut Syntax_Node__0__0new__with_children__2(Syntax_Node__0 mut ref const self, int32 const type__, system__collections__List__1 const ref const children__)
{
	self->type_id = Syntax_Node__0__0Type_ID;
	self->kind__ = type__;
	self->is_missing__ = FALSE;
	Syntax__0 const ref const first_child__ = system__collections__List__1__0op__element(children__, ((int32){0}));
	self->source__ = first_child__->source__;
	self->start__ = first_child__->start__;
	Syntax__0 const ref const last_child__ = system__collections__List__1__0op__element(children__, int32__0op__sub(children__->count__, ((int32){1})));
	self->byte_length__ = int32__0op__add(int32__0op__sub(last_child__->start__, self->start__), last_child__->byte_length__);
	self->children__ = children__;
	self->diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return self;
}

Syntax_Node__0 mut ref mut Syntax_Node__0__0new__skipped__1(Syntax_Node__0 mut ref const self, Token__0 const ref const token__)
{
	self->type_id = Syntax_Node__0__0Type_ID;
	self->is_missing__ = token__->is_missing__;
	self->source__ = token__->source__;
	self->start__ = token__->start__;
	self->byte_length__ = token__->byte_length__;
	system__collections__List__1 mut ref const diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	Text_Span__0 const ref const span__ = Text_Span__0__0new__2(allocate(sizeof(Text_Span__0)), token__->start__, token__->byte_length__);
	add_item__2(diagnostics__, Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), CompilationError__, Parsing__, token__->source__, span__, string__0op__add(((string){{33},(uint8_t*)u8"Skipped unexpected token of kind "}), int_to_string__1(token__->kind__))));
	self->diagnostics__ = diagnostics__;
	self->kind__ = SkippedTokens__;
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(children__, token__);
	self->children__ = children__;
	return self;
}

Syntax_Node__0 mut ref mut Syntax_Node__0__0new__skipped_many__1(Syntax_Node__0 mut ref const self, system__collections__List__1 const ref const tokens__)
{
	self->type_id = Syntax_Node__0__0Type_ID;
	self->is_missing__ = FALSE;
	assert__1(int32__0op__gt(tokens__->count__, ((int32){0})));
	Syntax_Node__0 const ref const first_child__ = system__collections__List__1__0op__element(tokens__, ((int32){0}));
	self->source__ = first_child__->source__;
	self->start__ = first_child__->start__;
	Syntax_Node__0 const ref const last_child__ = system__collections__List__1__0op__element(tokens__, int32__0op__sub(tokens__->count__, ((int32){1})));
	self->byte_length__ = int32__0op__add(int32__0op__sub(last_child__->start__, self->start__), last_child__->byte_length__);
	system__collections__List__1 mut ref const diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	Text_Span__0 const ref const span__ = Text_Span__0__0new__2(allocate(sizeof(Text_Span__0)), self->start__, self->byte_length__);
	add_item__2(diagnostics__, Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), CompilationError__, Parsing__, self->source__, span__, string__0op__add(string__0op__add(((string){{8},(uint8_t*)u8"Skipped "}), int_to_string__1(tokens__->count__)), ((string){{20},(uint8_t*)u8" unexpected token(s)"}))));
	self->diagnostics__ = diagnostics__;
	self->kind__ = SkippedTokens__;
	self->children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return self;
}

Syntax__0 const ref mut syntax_node_as_syntax__1(Syntax_Node__0 const ref const node__)
{
	return as_any__1(node__);
}

Text_Span__0 const ref mut get_syntax_node_text_span__1(Syntax_Node__0 const ref const node__)
{
	return Text_Span__0__0new__2(allocate(sizeof(Text_Span__0)), node__->start__, node__->byte_length__);
}

string mut get_syntax_node_text__1(Syntax_Node__0 const ref const syntax__)
{
	return substring__3(syntax__->source__->text__, syntax__->start__, syntax__->byte_length__);
}

Token__0 const opt_ref mut first_child_token__2(Syntax_Node__0 const ref const syntax__, int32 const kind__)
{
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const ref const child__ = void_ptr__0current(&iter);
		/* match */ { void const ref const match_value = child__;
		   switch(*(Type_ID const ref)match_value)
		{
			case Token__0__0Type_ID:
			{
				Token__0 const ref const token__ = match_value;
				if (cond(int32__0op__equal(token__->kind__, kind__)))
				{
					return token__;
				}
			}
			break;
			case Syntax_Node__0__0Type_ID:
			{
			}
			break;
			default:
			   NON_EXHAUSTIVE_MATCH(*(Type_ID const ref)match_value);
		}}
	}

	return none;
}

Syntax_Node__0 const opt_ref mut first_child_syntax_node__2(Syntax_Node__0 const ref const syntax__, int32 const kind__)
{
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const ref const child__ = void_ptr__0current(&iter);
		/* match */ { void const ref const match_value = child__;
		   switch(*(Type_ID const ref)match_value)
		{
			case Syntax_Node__0__0Type_ID:
			{
				Syntax_Node__0 const ref const node__ = match_value;
				if (cond(int32__0op__equal(node__->kind__, kind__)))
				{
					return node__;
				}
			}
			break;
			case Token__0__0Type_ID:
			{
			}
			break;
			default:
			   NON_EXHAUSTIVE_MATCH(*(Type_ID const ref)match_value);
		}}
	}

	return none;
}

BOOL mut has_child__2(Syntax_Node__0 const ref const syntax__, int32 const type__)
{
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const ref const child__ = void_ptr__0current(&iter);
		if (cond(int32__0op__equal(child__->kind__, type__)))
		{
			return TRUE;
		}
	}

	return FALSE;
}

system__collections__List__1 mut ref mut all_node_diagnostics__1(Syntax_Node__0 const ref const syntax__)
{
	system__collections__List__1 mut ref mut diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	collect_syntax_diagnostics__2(syntax__, diagnostics__);
	return diagnostics__;
}

void mut collect_syntax_diagnostics__2(Syntax_Node__0 const ref const syntax__, system__collections__List__1 mut ref const diagnostics__)
{
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(syntax__->diagnostics__); void_ptr__0next(&iter);)
	{
		Diagnostic__0 const ref const diagnostic__ = void_ptr__0current(&iter);
		add_item__2(diagnostics__, diagnostic__);
	}

	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const ref const child__ = void_ptr__0current(&iter);
		collect_syntax_diagnostics__2(child__, diagnostics__);
	}
}

system__collections__List__1 const ref mut members__1(Syntax_Node__0 const ref const syntax__)
{
	system__collections__List__1 mut ref const members__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const ref const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(child__->kind__, ConstructorDeclaration__)) || bool_arg(int32__0op__equal(child__->kind__, FieldDeclaration__)))) || bool_arg(int32__0op__equal(child__->kind__, MethodDeclaration__)))))
		{
			add_item__2(members__, child__);
		}
	}

	return members__;
}

system__collections__List__1 const ref mut parameters__1(Syntax_Node__0 const ref const syntax__)
{
	system__collections__List__1 mut ref const parameters__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const ref const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(int32__0op__equal(child__->kind__, Parameter__)) || bool_arg(int32__0op__equal(child__->kind__, SelfParameter__)))))
		{
			add_item__2(parameters__, child__);
		}
	}

	return parameters__;
}

system__collections__List__1 const ref mut statements__1(Syntax_Node__0 const ref const syntax__)
{
	system__collections__List__1 mut ref const statements__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const ref const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(int32__0op__not_equal(child__->kind__, LeftBrace__)) && bool_arg(int32__0op__not_equal(child__->kind__, RightBrace__)))))
		{
			add_item__2(statements__, child__);
		}
	}

	return statements__;
}

Token__0 const opt_ref mut access_modifier__1(Syntax_Node__0 const ref const syntax__)
{
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Token__0 const ref const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(child__->kind__, PublicKeyword__)) || bool_arg(int32__0op__equal(child__->kind__, ProtectedKeyword__)))) || bool_arg(int32__0op__equal(child__->kind__, InternalKeyword__)))) || bool_arg(int32__0op__equal(child__->kind__, PrivateKeyword__)))))
		{
			return child__;
		}
	}

	return none;
}

Token__0 mut ref mut Token__0__0new__5(Token__0 mut ref const self, int32 const kind__, Source_Text__0 const ref const source__, int32 const start__, int32 const byte_length__, system__collections__List__1 const ref const diagnostics__)
{
	self->type_id = Token__0__0Type_ID;
	self->is_missing__ = FALSE;
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = byte_length__;
	self->diagnostics__ = diagnostics__;
	self->kind__ = kind__;
	self->children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->value__ = ((string){{0},(uint8_t*)u8""});
	return self;
}

Token__0 mut ref mut Token__0__0new__6(Token__0 mut ref const self, int32 const kind__, Source_Text__0 const ref const source__, int32 const start__, int32 const byte_length__, system__collections__List__1 const ref const diagnostics__, string const value__)
{
	self->type_id = Token__0__0Type_ID;
	self->is_missing__ = FALSE;
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = byte_length__;
	self->diagnostics__ = diagnostics__;
	self->kind__ = kind__;
	self->children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->value__ = value__;
	return self;
}

Token__0 mut ref mut Token__0__0new__missing__3(Token__0 mut ref const self, int32 const kind__, Source_Text__0 const ref const source__, int32 const start__)
{
	self->type_id = Token__0__0Type_ID;
	self->is_missing__ = TRUE;
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = ((int32){0});
	system__collections__List__1 mut ref const diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	Text_Span__0 const ref const span__ = Text_Span__0__0new__2(allocate(sizeof(Text_Span__0)), start__, ((int32){0}));
	add_item__2(diagnostics__, Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), CompilationError__, Parsing__, source__, span__, string__0op__add(((string){{22},(uint8_t*)u8"Missing token of kind "}), int_to_string__1(kind__))));
	self->diagnostics__ = diagnostics__;
	self->kind__ = kind__;
	self->children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->value__ = ((string){{0},(uint8_t*)u8""});
	return self;
}

Syntax__0 const ref mut token_as_syntax__1(Token__0 const ref const token__)
{
	return as_any__1(token__);
}

string mut get_token_text__1(Token__0 const ref const token__)
{
	return substring__3(token__->source__->text__, token__->start__, token__->byte_length__);
}

Token_Stream__0 mut ref mut Token_Stream__0__0new__1(Token_Stream__0 mut ref const self, Source_Text__0 const ref const source__)
{
	self->type_id = Token_Stream__0__0Type_ID;
	self->source__ = source__;
	self->position__ = ((int32){0});
	self->diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->end_of_file__ = FALSE;
	return self;
}

Token__0 const opt_ref mut next_token__1(Token_Stream__0 mut ref const tokens__)
{
	if (cond(int32__0op__gte(tokens__->position__, source_byte_length__1(tokens__->source__))))
	{
		return end_of_file_token__1(tokens__);
	}

	int32 mut end__ = int32__0op__neg(((int32){1}));
	while (cond(int32__0op__lt(tokens__->position__, source_byte_length__1(tokens__->source__))))
	{
		code_point const cur_char__ = string__0__0op__element(tokens__->source__->text__, tokens__->position__);
		if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(code_point__0op__equal(cur_char__, ((code_point){/* */0x20}))) || bool_arg(code_point__0op__equal(cur_char__, ((code_point){/*\t*/0x9}))))) || bool_arg(code_point__0op__equal(cur_char__, ((code_point){/*\n*/0xA}))))) || bool_arg(code_point__0op__equal(cur_char__, ((code_point){/*\r*/0xD}))))))
		{
			op__add_assign(&(tokens__->position__), ((int32){1}));
			continue;
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*{*/0x7B}))))
		{
			return new_operator_token__2(tokens__, LeftBrace__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*}*/0x7D}))))
		{
			return new_operator_token__2(tokens__, RightBrace__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*(*/0x28}))))
		{
			return new_operator_token__2(tokens__, LeftParen__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*)*/0x29}))))
		{
			return new_operator_token__2(tokens__, RightParen__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*;*/0x3B}))))
		{
			return new_operator_token__2(tokens__, Semicolon__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*,*/0x2C}))))
		{
			return new_operator_token__2(tokens__, Comma__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*.*/0x2E}))))
		{
			return new_operator_token__2(tokens__, Dot__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*:*/0x3A}))))
		{
			return new_operator_token__2(tokens__, Colon__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*[*/0x5B}))))
		{
			return new_operator_token__2(tokens__, LeftBracket__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*]*/0x5D}))))
		{
			return new_operator_token__2(tokens__, RightBracket__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*?*/0x3F}))))
		{
			return new_operator_token__2(tokens__, Question__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*|*/0x7C}))))
		{
			return new_operator_token__2(tokens__, Pipe__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/***/0x2A}))))
		{
			return new_operator_token__2(tokens__, Asterisk__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*^*/0x5E}))))
		{
			if (cond(bool_op(bool_arg(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){1})), source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){1}))), ((code_point){/*.*/0x2E}))))))
			{
				return new_operator_token__3(tokens__, CaretDot__, ((int32){2}));
			}

			return new_operator_token__2(tokens__, Caret__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*=*/0x3D}))))
		{
			if (cond(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){1})), source_byte_length__1(tokens__->source__))))
			{
				code_point const next_char__ = string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){1})));
				if (cond(code_point__0op__equal(next_char__, ((code_point){/*=*/0x3D}))))
				{
					return new_operator_token__3(tokens__, EqualsEquals__, ((int32){2}));
				}

				if (cond(code_point__0op__equal(next_char__, ((code_point){/*>*/0x3E}))))
				{
					return new_operator_token__3(tokens__, FatArrow__, ((int32){2}));
				}

				if (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){2})), source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__equal(next_char__, ((code_point){/*/*/0x2F}))))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){2}))), ((code_point){/*=*/0x3D}))))))
				{
					return new_operator_token__3(tokens__, EqualsSlashEquals__, ((int32){3}));
				}
			}

			return new_operator_token__2(tokens__, Equals__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*+*/0x2B}))))
		{
			if (cond(bool_op(bool_arg(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){1})), source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){1}))), ((code_point){/*=*/0x3D}))))))
			{
				return new_operator_token__3(tokens__, PlusEquals__, ((int32){2}));
			}

			return new_operator_token__2(tokens__, Plus__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*-*/0x2D}))))
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
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*/*/0x2F}))))
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
				BOOL mut last_char_star__ = FALSE;
				while (cond(bool_op(bool_arg(int32__0op__lt(tokens__->position__, source_byte_length__1(tokens__->source__))) && bool_arg(BOOL__0op__not(bool_op(bool_arg(last_char_star__) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, tokens__->position__), ((code_point){/*/*/0x2F})))))))))
				{
					last_char_star__ = code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, tokens__->position__), ((code_point){/***/0x2A}));
					op__add_assign(&(tokens__->position__), ((int32){1}));
				}

				op__add_assign(&(tokens__->position__), ((int32){1}));
				continue;
			}

			return new_operator_token__2(tokens__, Slash__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*%*/0x25}))))
		{
			return new_operator_token__2(tokens__, Percent__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*<*/0x3C}))))
		{
			if (cond(bool_op(bool_arg(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){1})), source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){1}))), ((code_point){/*=*/0x3D}))))))
			{
				return new_operator_token__3(tokens__, LessThanEquals__, ((int32){2}));
			}

			return new_operator_token__2(tokens__, LessThan__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*>*/0x3E}))))
		{
			if (cond(bool_op(bool_arg(int32__0op__lt(int32__0op__add(tokens__->position__, ((int32){1})), source_byte_length__1(tokens__->source__))) && bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, int32__0op__add(tokens__->position__, ((int32){1}))), ((code_point){/*=*/0x3D}))))))
			{
				return new_operator_token__3(tokens__, GreaterThanEquals__, ((int32){2}));
			}

			return new_operator_token__2(tokens__, GreaterThan__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*"*/0x22}))))
		{
			end__ = int32__0op__add(tokens__->position__, ((int32){1}));
			BOOL mut escaped__ = FALSE;
			while (cond(bool_op(bool_arg(int32__0op__lt(end__, source_byte_length__1(tokens__->source__))) && bool_arg(bool_op(bool_arg(code_point__0op__not_equal(string__0__0op__element(tokens__->source__->text__, end__), ((code_point){/*"*/0x22}))) || bool_arg(escaped__))))))
			{
				escaped__ = bool_op(bool_arg(code_point__0op__equal(string__0__0op__element(tokens__->source__->text__, end__), ((code_point){/*\\*/0x5C}))) && bool_arg(BOOL__0op__not(escaped__)));
				op__add_assign(&(end__), ((int32){1}));
			}

			op__add_assign(&(end__), ((int32){1}));
			return new_token__3(tokens__, StringLiteral__, end__);
		}
		else if (cond(code_point__0op__equal(cur_char__, ((code_point){/*\'*/0x27}))))
		{
			end__ = int32__0op__add(tokens__->position__, ((int32){1}));
			BOOL mut escaped__ = FALSE;
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
			if (cond(is_identifier_char__1(cur_char__)))
			{
				end__ = int32__0op__add(tokens__->position__, ((int32){1}));
				while (cond(is_identifier_char__1(string__0__0op__element(tokens__->source__->text__, end__))))
				{
					op__add_assign(&(end__), ((int32){1}));
				}

				return new_identifier_or_keyword_token__2(tokens__, end__);
			}

			if (cond(is_number_char__1(cur_char__)))
			{
				end__ = int32__0op__add(tokens__->position__, ((int32){1}));
				while (cond(is_number_char__1(string__0__0op__element(tokens__->source__->text__, end__))))
				{
					op__add_assign(&(end__), ((int32){1}));
				}

				return new_token__4(tokens__, Integer__, end__, substring__3(tokens__->source__->text__, tokens__->position__, int32__0op__sub(end__, tokens__->position__)));
			}

			Text_Span__0 const ref mut diagnostic_span__ = Text_Span__0__0new__2(allocate(sizeof(Text_Span__0)), tokens__->position__, ((int32){1}));
			add_item__2(tokens__->diagnostics__, Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), CompilationError__, Lexing__, tokens__->source__, diagnostic_span__, string__0op__add(string__0op__add(((string){{19},(uint8_t*)u8"Invalid character `"}), code_point_to_string__1(cur_char__)), ((string){{1},(uint8_t*)u8"`"}))));
			tokens__->position__ = end__;
		}
	}

	return end_of_file_token__1(tokens__);
}

Token__0 const opt_ref mut end_of_file_token__1(Token_Stream__0 mut ref const tokens__)
{
	if (cond(tokens__->end_of_file__))
	{
		return none;
	}

	tokens__->end_of_file__ = TRUE;
	return new_token__3(tokens__, EndOfFile__, tokens__->position__);
}

Token__0 const ref mut new_identifier_or_keyword_token__2(Token_Stream__0 mut ref const tokens__, int32 const end__)
{
	int32 const length__ = int32__0op__sub(end__, tokens__->position__);
	string const value__ = substring__3(tokens__->source__->text__, tokens__->position__, length__);
	int32 mut kind__;
	if (cond(string__0op__equal(value__, ((string){{3},(uint8_t*)u8"new"}))))
	{
		kind__ = NewKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{3},(uint8_t*)u8"not"}))))
	{
		kind__ = NotKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"null"}))))
	{
		kind__ = NullReservedWord__;
	}
	else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"self"}))))
	{
		kind__ = SelfKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"true"}))))
	{
		kind__ = TrueKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{5},(uint8_t*)u8"false"}))))
	{
		kind__ = FalseKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{3},(uint8_t*)u8"mut"}))))
	{
		kind__ = MutableKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{10},(uint8_t*)u8"code_point"}))))
	{
		kind__ = CodePoint__;
	}
	else if (cond(string__0op__equal(value__, ((string){{6},(uint8_t*)u8"string"}))))
	{
		kind__ = String__;
	}
	else if (cond(string__0op__equal(value__, ((string){{3},(uint8_t*)u8"int"}))))
	{
		kind__ = Int__;
	}
	else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"bool"}))))
	{
		kind__ = Bool__;
	}
	else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"void"}))))
	{
		kind__ = Void__;
	}
	else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"uint"}))))
	{
		kind__ = UnsignedInt__;
	}
	else if (cond(string__0op__equal(value__, ((string){{3},(uint8_t*)u8"var"}))))
	{
		kind__ = VarKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{3},(uint8_t*)u8"and"}))))
	{
		kind__ = AndKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{2},(uint8_t*)u8"or"}))))
	{
		kind__ = OrKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{6},(uint8_t*)u8"return"}))))
	{
		kind__ = ReturnKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"loop"}))))
	{
		kind__ = LoopKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{5},(uint8_t*)u8"while"}))))
	{
		kind__ = WhileKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{3},(uint8_t*)u8"for"}))))
	{
		kind__ = ForKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{3},(uint8_t*)u8"let"}))))
	{
		kind__ = LetKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{2},(uint8_t*)u8"in"}))))
	{
		kind__ = InKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{2},(uint8_t*)u8"do"}))))
	{
		kind__ = DoKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{2},(uint8_t*)u8"if"}))))
	{
		kind__ = IfKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"else"}))))
	{
		kind__ = ElseKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{5},(uint8_t*)u8"break"}))))
	{
		kind__ = BreakKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{8},(uint8_t*)u8"continue"}))))
	{
		kind__ = ContinueKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{7},(uint8_t*)u8"private"}))))
	{
		kind__ = PrivateKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{9},(uint8_t*)u8"protected"}))))
	{
		kind__ = ProtectedKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{6},(uint8_t*)u8"public"}))))
	{
		kind__ = PublicKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{8},(uint8_t*)u8"internal"}))))
	{
		kind__ = InternalKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{5},(uint8_t*)u8"class"}))))
	{
		kind__ = ClassKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"enum"}))))
	{
		kind__ = EnumKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{6},(uint8_t*)u8"struct"}))))
	{
		kind__ = StructKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"none"}))))
	{
		kind__ = NoneKeyword__;
	}
	else if (cond(string__0op__equal(value__, ((string){{5},(uint8_t*)u8"match"}))))
	{
		kind__ = MatchKeyword__;
	}
	else
	{
		kind__ = Identifier__;
		if (cond(bool_op(bool_arg(int32__0op__gt(string_byte_length__1(value__), ((int32){1}))) && bool_arg(code_point__0op__equal(string__0__0op__element(value__, int32__0op__sub(string_byte_length__1(value__), ((int32){1}))), ((code_point){/*_*/0x5F}))))))
		{
			Text_Span__0 const ref mut diagnostic_span__ = Text_Span__0__0new__2(allocate(sizeof(Text_Span__0)), tokens__->position__, int32__0op__sub(end__, tokens__->position__));
			add_item__2(tokens__->diagnostics__, Diagnostic__0__0new__5(allocate(sizeof(Diagnostic__0)), CompilationError__, Lexing__, tokens__->source__, diagnostic_span__, string__0op__add(string__0op__add(((string){{49},(uint8_t*)u8"Identifiers ending with underscore are reserved `"}), value__), ((string){{1},(uint8_t*)u8"`"}))));
		}
	}

	return new_token__3(tokens__, kind__, end__);
}

Token__0 const ref mut new_operator_token__2(Token_Stream__0 mut ref const tokens__, int32 const kind__)
{
	return new_token__3(tokens__, kind__, int32__0op__add(tokens__->position__, ((int32){1})));
}

Token__0 const ref mut new_operator_token__3(Token_Stream__0 mut ref const tokens__, int32 const kind__, int32 const length__)
{
	return new_token__3(tokens__, kind__, int32__0op__add(tokens__->position__, length__));
}

Token__0 const ref mut new_token__3(Token_Stream__0 mut ref const tokens__, int32 const kind__, int32 const end__)
{
	system__collections__List__1 mut ref const token_diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(tokens__->diagnostics__); void_ptr__0next(&iter);)
	{
		Diagnostic__0 const ref const diagnostic__ = void_ptr__0current(&iter);
		add_item__2(token_diagnostics__, diagnostic__);
	}

	clear_list__1(tokens__->diagnostics__);
	Token__0 const ref const token__ = Token__0__0new__5(allocate(sizeof(Token__0)), kind__, tokens__->source__, tokens__->position__, int32__0op__sub(end__, tokens__->position__), token_diagnostics__);
	tokens__->position__ = end__;
	return token__;
}

Token__0 const ref mut new_token__4(Token_Stream__0 mut ref const tokens__, int32 const kind__, int32 const end__, string const value__)
{
	system__collections__List__1 mut ref const token_diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(tokens__->diagnostics__); void_ptr__0next(&iter);)
	{
		Diagnostic__0 const ref const diagnostic__ = void_ptr__0current(&iter);
		add_item__2(token_diagnostics__, diagnostic__);
	}

	clear_list__1(tokens__->diagnostics__);
	Token__0 const ref const token__ = Token__0__0new__6(allocate(sizeof(Token__0)), kind__, tokens__->source__, tokens__->position__, int32__0op__sub(end__, tokens__->position__), token_diagnostics__, value__);
	tokens__->position__ = end__;
	return token__;
}

BOOL mut is_identifier_char__1(code_point const c__)
{
	return bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(code_point__0op__gte(c__, ((code_point){/*a*/0x61}))) && bool_arg(code_point__0op__lte(c__, ((code_point){/*z*/0x7A}))))) || bool_arg(bool_op(bool_arg(code_point__0op__gte(c__, ((code_point){/*A*/0x41}))) && bool_arg(code_point__0op__lte(c__, ((code_point){/*Z*/0x5A}))))))) || bool_arg(code_point__0op__equal(c__, ((code_point){/*_*/0x5F}))));
}

BOOL mut is_number_char__1(code_point const c__)
{
	return bool_op(bool_arg(code_point__0op__gte(c__, ((code_point){/*0*/0x30}))) && bool_arg(code_point__0op__lte(c__, ((code_point){/*9*/0x39}))));
}

Diagnostic__0 mut ref mut Diagnostic__0__0new__5(Diagnostic__0 mut ref const self, int32 const level__, int32 const phase__, Source_Text__0 const ref const source__, Text_Span__0 const ref const span__, string const message__)
{
	self->type_id = Diagnostic__0__0Type_ID;
	self->level__ = level__;
	self->phase__ = phase__;
	self->source__ = source__;
	self->span__ = span__;
	self->position__ = position_of_start__2(source__, span__);
	self->message__ = message__;
	return self;
}

Emitter__0 mut ref mut Emitter__0__0new__2(Emitter__0 mut ref const self, Package__0 const ref const package__, system__collections__List__1 const ref const resources__)
{
	self->type_id = Emitter__0__0Type_ID;
	self->package__ = package__;
	self->resources__ = resources__;
	return self;
}

string mut emit__1(Emitter__0 mut ref const emitter__)
{
	emitter__->includes__ = Source_File_Builder__0__0new__0(allocate(sizeof(Source_File_Builder__0)));
	emitter__->type_id_declaration__ = Source_File_Builder__0__0new__0(allocate(sizeof(Source_File_Builder__0)));
	emitter__->type_declarations__ = Source_File_Builder__0__0new__0(allocate(sizeof(Source_File_Builder__0)));
	emitter__->function_declarations__ = Source_File_Builder__0__0new__0(allocate(sizeof(Source_File_Builder__0)));
	emitter__->class_declarations__ = Source_File_Builder__0__0new__0(allocate(sizeof(Source_File_Builder__0)));
	emitter__->global_definitions__ = Source_File_Builder__0__0new__0(allocate(sizeof(Source_File_Builder__0)));
	emitter__->definitions__ = Source_File_Builder__0__0new__0(allocate(sizeof(Source_File_Builder__0)));
	emitter__->main_function_return_type__ = ((string){{0},(uint8_t*)u8""});
	emitter__->main_function_accepts_console__ = FALSE;
	emitter__->main_function_accepts_args__ = FALSE;
	emit_preamble__1(emitter__);
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(emitter__->package__->compilation_units__); void_ptr__0next(&iter);)
	{
		Compilation_Unit__0 const ref const compilation_unit__ = void_ptr__0current(&iter);
		emit_compilation_unit__2(emitter__, compilation_unit__);
	}

	emit_entry_point_adapter__1(emitter__);
	emit_postamble__1(emitter__);
	int32 const total_size__ = int32__0op__add(int32__0op__add(int32__0op__add(int32__0op__add(int32__0op__add(int32__0op__add(int32__0op__add(((int32){0}), byte_length__1(emitter__->includes__)), byte_length__1(emitter__->type_id_declaration__)), byte_length__1(emitter__->type_declarations__)), byte_length__1(emitter__->function_declarations__)), byte_length__1(emitter__->class_declarations__)), byte_length__1(emitter__->global_definitions__)), byte_length__1(emitter__->definitions__));
	system__text__String_Builder__0 mut ref const c_code__ = system__text__String_Builder__0__0new__with_capacity__1(allocate(sizeof(system__text__String_Builder__0)), total_size__);
	sb_append__2(c_code__, to_string__1(emitter__->includes__));
	sb_append__2(c_code__, to_string__1(emitter__->type_id_declaration__));
	sb_append__2(c_code__, to_string__1(emitter__->type_declarations__));
	sb_append__2(c_code__, to_string__1(emitter__->function_declarations__));
	sb_append__2(c_code__, to_string__1(emitter__->class_declarations__));
	sb_append__2(c_code__, to_string__1(emitter__->global_definitions__));
	sb_append__2(c_code__, to_string__1(emitter__->definitions__));
	return sb_to_string__1(c_code__);
}

string mut mangle_name__1(Type__0 const ref const type__)
{
	system__text__String_Builder__0 mut ref const builder__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	BOOL mut first_segment__ = TRUE;
	for (string__0iter mut iter = string__0iterate(type__->name__->segments__); string__0next(&iter);)
	{
		string const segment__ = string__0current(&iter);
		if (cond(first_segment__))
		{
			first_segment__ = FALSE;
		}
		else
		{
			sb_append__2(builder__, ((string){{2},(uint8_t*)u8"__"}));
		}

		if (cond(BOOL__0op__not(contains_multi_underscore_runs__1(segment__))))
		{
			sb_append__2(builder__, segment__);
		}
		else
		{
			append_fixing_underscores__2(builder__, segment__);
		}
	}

	sb_append__2(builder__, ((string){{2},(uint8_t*)u8"__"}));
	sb_append__2(builder__, int_to_string__1(type__->type_parameters__->count__));
	return sb_to_string__1(builder__);
}

string mut mangle_function_name__2(string const name__, int32 const parameter_count__)
{
	system__text__String_Builder__0 mut ref const builder__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	if (cond(BOOL__0op__not(contains_multi_underscore_runs__1(name__))))
	{
		sb_append__2(builder__, name__);
	}
	else
	{
		append_fixing_underscores__2(builder__, name__);
	}

	sb_append__2(builder__, ((string){{2},(uint8_t*)u8"__"}));
	sb_append__2(builder__, int_to_string__1(parameter_count__));
	return sb_to_string__1(builder__);
}

string mut mangle_field_name__1(string const name__)
{
	if (cond(BOOL__0op__not(contains_multi_underscore_runs__1(name__))))
	{
		return string__0op__add(name__, ((string){{2},(uint8_t*)u8"__"}));
	}
	else
	{
		system__text__String_Builder__0 mut ref const builder__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
		append_fixing_underscores__2(builder__, name__);
		sb_append__2(builder__, ((string){{2},(uint8_t*)u8"__"}));
		return sb_to_string__1(builder__);
	}
}

BOOL mut contains_multi_underscore_runs__1(string const value__)
{
	int32 mut i__ = ((int32){0});
	BOOL mut last_char_underscore__ = FALSE;
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

void mut append_fixing_underscores__2(system__text__String_Builder__0 mut ref const builder__, string const value__)
{
	int32 mut underscores__ = ((int32){0});
	int32 mut i__ = ((int32){0});
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
				sb_append__2(builder__, ((string){{1},(uint8_t*)u8"_"}));
			}

			underscores__ = ((int32){0});
		}

		sb_append__2(builder__, string__0new__2(string__0__0op__element(value__, i__), ((int32){1})));
		op__add_assign(&(i__), ((int32){1}));
	}
}

string mut convert_primitive_type_name__1(Type__0 const ref const type__)
{
	string const name__ = unqualified_name__1(type__->name__);
	assert__2(type__->is_primitive__, name__);
	if (cond(string__0op__equal(name__, ((string){{4},(uint8_t*)u8"bool"}))))
	{
		return ((string){{4},(uint8_t*)u8"BOOL"});
	}
	else if (cond(string__0op__equal(name__, ((string){{3},(uint8_t*)u8"int"}))))
	{
		return ((string){{5},(uint8_t*)u8"int32"});
	}
	else if (cond(string__0op__equal(name__, ((string){{4},(uint8_t*)u8"uint"}))))
	{
		return ((string){{6},(uint8_t*)u8"uint32"});
	}
	else
	{
		return name__;
	}
}

system__text__String_Builder__0 mut ref mut convert_type_name__1(Type__0 const ref const type__)
{
	return convert_type_name__2(type__, TRUE);
}

system__text__String_Builder__0 mut ref mut convert_type_name__2(Type__0 const ref const type__, BOOL const include_type_parameters__)
{
	system__text__String_Builder__0 mut ref const c_type__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	if (cond(type__->is_primitive__))
	{
		sb_append__2(c_type__, convert_primitive_type_name__1(type__));
	}
	else
	{
		sb_append__2(c_type__, mangle_name__1(type__));
	}

	return c_type__;
}

void mut convert_type_name_parameters__2(system__text__String_Builder__0 mut ref const builder__, Type__0 const ref const type__)
{
	for (void_ptr__0iter mut iter = void_ptr__0iterate(type__->type_parameters__); void_ptr__0next(&iter);)
	{
		Type__0 const ref mut type_parameter__ = void_ptr__0current(&iter);
		sb_append__2(builder__, ((string){{2},(uint8_t*)u8"__"}));
		if (cond(bool_op(bool_arg(type_parameter__->is_primitive__) && bool_arg(string__0op__equal(unqualified_name__1(type_parameter__->name__), ((string){{8},(uint8_t*)u8"optional"}))))))
		{
			type_parameter__ = system__collections__List__1__0op__element(type_parameter__->type_parameters__, ((int32){0}));
		}

		if (cond(type_parameter__->is_primitive__))
		{
			sb_append__2(builder__, convert_primitive_type_name__1(type_parameter__));
		}
		else
		{
			sb_append__2(builder__, ((string){{8},(uint8_t*)u8"void_ptr"}));
		}
	}
}

string mut convert_reference_type__3(BOOL const mutable_binding__, Type__0 const ref mut type__, BOOL const nullable__)
{
	system__text__String_Builder__0 mut ref const c_type__ = convert_type_name__1(type__);
	if (cond(type__->is_mutable__))
	{
		sb_append__2(c_type__, ((string){{4},(uint8_t*)u8" mut"}));
	}
	else
	{
		sb_append__2(c_type__, ((string){{6},(uint8_t*)u8" const"}));
	}

	if (cond(nullable__))
	{
		sb_append__2(c_type__, ((string){{8},(uint8_t*)u8" opt_ref"}));
	}
	else
	{
		sb_append__2(c_type__, ((string){{4},(uint8_t*)u8" ref"}));
	}

	if (cond(mutable_binding__))
	{
		sb_append__2(c_type__, ((string){{4},(uint8_t*)u8" mut"}));
	}
	else
	{
		sb_append__2(c_type__, ((string){{6},(uint8_t*)u8" const"}));
	}

	return sb_to_string__1(c_type__);
}

string mut convert_type__3(BOOL const mutable_binding__, Type__0 const ref mut type__, BOOL const optional__)
{
	assert__1(void_ptr__0op__not_equal(type__, none));
	if (cond(bool_op(bool_arg(type__->is_primitive__) && bool_arg(string__0op__equal(unqualified_name__1(type__->name__), ((string){{8},(uint8_t*)u8"optional"}))))))
	{
		Type__0 const ref const optional_type__ = system__collections__List__1__0op__element(type__->type_parameters__, ((int32){0}));
		if (cond(optional_type__->is_value_type__))
		{
			system__text__String_Builder__0 mut ref const c_type__ = system__text__String_Builder__0__0new__1(allocate(sizeof(system__text__String_Builder__0)), ((string){{10},(uint8_t*)u8"optional__"}));
			if (cond(mutable_binding__))
			{
				sb_append__2(c_type__, ((string){{6},(uint8_t*)u8"0var__"}));
			}

			if (cond(type__->is_mutable__))
			{
				sb_append__2(c_type__, ((string){{6},(uint8_t*)u8"0mut__"}));
			}

			sb_append__2(c_type__, convert_type__3(TRUE, optional_type__, TRUE));
			return sb_to_string__1(c_type__);
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
			system__text__String_Builder__0 mut ref const c_type__ = convert_type_name__1(type__);
			if (cond(bool_op(bool_arg(mutable_binding__) || bool_arg(type__->is_mutable__))))
			{
				sb_append__2(c_type__, ((string){{4},(uint8_t*)u8" mut"}));
			}
			else
			{
				sb_append__2(c_type__, ((string){{6},(uint8_t*)u8" const"}));
			}

			return sb_to_string__1(c_type__);
		}
		else
		{
			return convert_reference_type__3(mutable_binding__, type__, optional__);
		}
	}
}

string mut convert_type__2(BOOL const mutable_binding__, Semantic_Node__0 const ref const type_node__)
{
	assert__2(void_ptr__0op__not_equal(type_node__->referenced_type__, none), get_semantic_node_text__1(type_node__));
	return convert_type__3(mutable_binding__, type_node__->referenced_type__, FALSE);
}

string mut convert_parameter_list__4(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const parameters__, string const self_type__, BOOL const is_main_function__)
{
	assert__2(int32__0op__equal(parameters__->kind__, ParameterList__), string__0op__add(((string){{16},(uint8_t*)u8"parameters.kind="}), int_to_string__1(parameters__->kind__)));
	system__text__String_Builder__0 mut ref const builder__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	sb_append__2(builder__, ((string){{1},(uint8_t*)u8"("}));
	if (cond(int32__0op__gt(string_byte_length__1(self_type__), ((int32){0}))))
	{
		sb_append__2(builder__, self_type__);
		sb_append__2(builder__, ((string){{5},(uint8_t*)u8" self"}));
	}

	BOOL mut first_parameter__ = int32__0op__equal(string_byte_length__1(self_type__), ((int32){0}));
	for (void_ptr__0iter mut iter = void_ptr__0iterate(children_of_kind__2(parameters__, Parameter__)); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const ref const parameter__ = void_ptr__0current(&iter);
		if (cond(BOOL__0op__not(first_parameter__)))
		{
			sb_append__2(builder__, ((string){{2},(uint8_t*)u8", "}));
		}
		else
		{
			first_parameter__ = FALSE;
		}

		BOOL const mutable_binding__ = node_has_child__2(parameter__, VarKeyword__);
		Semantic_Node__0 const ref const type_node__ = system__collections__List__1__0op__element(parameter__->children__, int32__0op__sub(parameter__->children__->count__, ((int32){1})));
		sb_append__2(builder__, convert_type__2(mutable_binding__, type_node__));
		sb_append__2(builder__, ((string){{1},(uint8_t*)u8" "}));
		sb_append__2(builder__, mangle_field_name__1(get_semantic_node_text__1(first_child__2(parameter__, Identifier__))));
		if (cond(is_main_function__))
		{
			string mut type_string__;
			if (cond(int32__0op__equal(type_node__->kind__, MutableType__)))
			{
				type_string__ = get_semantic_node_text__1(system__collections__List__1__0op__element(type_node__->children__, ((int32){0})));
			}
			else
			{
				type_string__ = get_semantic_node_text__1(type_node__);
			}

			if (cond(string__0op__equal(type_string__, ((string){{22},(uint8_t*)u8"system.console.Console"}))))
			{
				emitter__->main_function_accepts_console__ = TRUE;
			}

			if (cond(string__0op__equal(type_string__, ((string){{24},(uint8_t*)u8"system.console.Arguments"}))))
			{
				emitter__->main_function_accepts_args__ = TRUE;
			}
		}
	}

	sb_append__2(builder__, ((string){{1},(uint8_t*)u8")"}));
	return sb_to_string__1(builder__);
}

string mut convert_method_parameter_list__3(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const parameters__, string const self_type__)
{
	return convert_parameter_list__4(emitter__, parameters__, self_type__, FALSE);
}

string mut convert_parameter_list__3(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const parameters__, BOOL const is_main_function__)
{
	return convert_parameter_list__4(emitter__, parameters__, ((string){{0},(uint8_t*)u8""}), is_main_function__);
}

string mut convert_parameter_list__2(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const parameters__)
{
	return convert_parameter_list__4(emitter__, parameters__, ((string){{0},(uint8_t*)u8""}), FALSE);
}

void mut convert_expression__2(Semantic_Node__0 const ref const syntax__, Source_File_Builder__0 mut ref const builder__)
{
	if (cond(int32__0op__equal(syntax__->kind__, NewExpression__)))
	{
		string mut constructor_name__ = ((string){{0},(uint8_t*)u8""});
		Semantic_Node__0 const ref mut type_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		if (cond(int32__0op__equal(type_node__->kind__, QualifiedName__)))
		{
			Semantic_Node__0 const ref const name_node__ = system__collections__List__1__0op__element(type_node__->children__, ((int32){1}));
			if (cond(bool_op(bool_arg(int32__0op__equal(name_node__->kind__, IdentifierName__)) && bool_arg(void_ptr__0op__equal(name_node__->referenced_type__, none)))))
			{
				constructor_name__ = string__0op__add(((string){{2},(uint8_t*)u8"__"}), get_semantic_node_text__1(name_node__));
				type_node__ = system__collections__List__1__0op__element(type_node__->children__, ((int32){0}));
			}
		}

		Type__0 const ref const type__ = type_node__->referenced_type__;
		assert__2(void_ptr__0op__not_equal(type__, none), get_semantic_node_text__1(type_node__));
		write__2(builder__, sb_to_string__1(convert_type_name__2(type__, FALSE)));
		write__2(builder__, ((string){{6},(uint8_t*)u8"__0new"}));
		write__2(builder__, constructor_name__);
		write__2(builder__, ((string){{2},(uint8_t*)u8"__"}));
		Semantic_Node__0 const ref const argument_list__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}));
		write__2(builder__, int_to_string__1(node_argument_count__1(argument_list__)));
		if (cond(type__->is_value_type__))
		{
			convert_expression__2(argument_list__, builder__);
		}
		else
		{
			convert_reference_type_constructor_arguments__3(argument_list__, builder__, sb_to_string__1(convert_type_name__1(type__)));
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ArgumentList__)))
	{
		write__2(builder__, ((string){{1},(uint8_t*)u8"("}));
		BOOL mut first_expression__ = TRUE;
		for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
		{
			Semantic_Node__0 const ref const arg__ = void_ptr__0current(&iter);
			if (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__not_equal(arg__->kind__, LeftParen__)) && bool_arg(int32__0op__not_equal(arg__->kind__, RightParen__)))) && bool_arg(int32__0op__not_equal(arg__->kind__, Comma__)))))
			{
				if (cond(first_expression__))
				{
					first_expression__ = FALSE;
				}
				else
				{
					write__2(builder__, ((string){{2},(uint8_t*)u8", "}));
				}

				convert_expression__2(arg__, builder__);
			}
		}

		write__2(builder__, ((string){{1},(uint8_t*)u8")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NotExpression__)))
	{
		write__2(builder__, ((string){{15},(uint8_t*)u8"BOOL__0op__not("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){{1},(uint8_t*)u8")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ParenthesizedExpression__)))
	{
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NegateExpression__)))
	{
		write__2(builder__, ((string){{16},(uint8_t*)u8"int32__0op__neg("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){{1},(uint8_t*)u8")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NoneLiteralExpression__)))
	{
		write__2(builder__, ((string){{4},(uint8_t*)u8"none"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, SelfExpression__)))
	{
		write__2(builder__, ((string){{4},(uint8_t*)u8"self"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, IntegerLiteralExpression__)))
	{
		write__2(builder__, string__0op__add(string__0op__add(((string){{9},(uint8_t*)u8"((int32){"}), get_semantic_node_text__1(syntax__)), ((string){{2},(uint8_t*)u8"})"})));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, TrueLiteralExpression__)))
	{
		write__2(builder__, ((string){{4},(uint8_t*)u8"TRUE"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, FalseLiteralExpression__)))
	{
		write__2(builder__, ((string){{5},(uint8_t*)u8"FALSE"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, CodePointLiteralExpression__)))
	{
		string const raw_value__ = get_semantic_node_text__1(syntax__);
		code_point const code_point_value__ = code_point_literal_value__1(raw_value__);
		write__2(builder__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){{16},(uint8_t*)u8"((code_point){/*"}), substring__3(raw_value__, ((int32){1}), int32__0op__sub(string_byte_length__1(raw_value__), ((int32){2})))), ((string){{4},(uint8_t*)u8"*/0x"})), int_to_hex_string__1(code_point_as_int__1(code_point_value__))), ((string){{2},(uint8_t*)u8"})"})));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, IdentifierName__)))
	{
		write__2(builder__, mangle_field_name__1(get_semantic_node_text__1(syntax__)));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, StringLiteralExpression__)))
	{
		string const value__ = get_semantic_node_text__1(syntax__);
		write__2(builder__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){{11},(uint8_t*)u8"((string){{"}), int_to_string__1(literal_length__1(value__))), ((string){{14},(uint8_t*)u8"},(uint8_t*)u8"})), value__), ((string){{2},(uint8_t*)u8"})"})));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, AssignmentExpression__)))
	{
		Semantic_Node__0 const ref const child__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}));
		int32 const operator__ = child__->kind__;
		if (cond(int32__0op__equal(operator__, Equals__)))
		{
			convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
			write__2(builder__, ((string){{1},(uint8_t*)u8" "}));
			write__2(builder__, get_semantic_node_text__1(system__collections__List__1__0op__element(syntax__->children__, ((int32){1}))));
			write__2(builder__, ((string){{1},(uint8_t*)u8" "}));
			convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), builder__);
		}
		else
		{
			write__2(builder__, ((string){{4},(uint8_t*)u8"op__"}));
			if (cond(int32__0op__equal(operator__, PlusEquals__)))
			{
				write__2(builder__, ((string){{10},(uint8_t*)u8"add_assign"}));
			}
			else if (cond(int32__0op__equal(operator__, MinusEquals__)))
			{
				write__2(builder__, ((string){{10},(uint8_t*)u8"sub_assign"}));
			}
			else
			{
				error__2(builder__, string__0op__add(((string){{32},(uint8_t*)u8"Unsupported assignment operator "}), int_to_string__1(operator__)));
			}

			write__2(builder__, ((string){{3},(uint8_t*)u8"(&("}));
			convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
			write__2(builder__, ((string){{3},(uint8_t*)u8"), "}));
			convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), builder__);
			write__2(builder__, ((string){{1},(uint8_t*)u8")"}));
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, EqualExpression__)))
	{
		Semantic_Node__0 const ref const lhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		Semantic_Node__0 const ref const rhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}));
		Type__0 const ref mut type__ = lhs_node__->of_type__;
		if (cond(void_ptr__0op__equal(type__, none)))
		{
			type__ = rhs_node__->of_type__;
		}

		if (cond(void_ptr__0op__not_equal(type__, none)))
		{
			if (cond(bool_op(bool_arg(type__->is_primitive__) && bool_arg(string__0op__equal(unqualified_name__1(type__->name__), ((string){{8},(uint8_t*)u8"optional"}))))))
			{
				type__ = system__collections__List__1__0op__element(type__->type_parameters__, ((int32){0}));
			}

			if (cond(type__->is_primitive__))
			{
				write__2(builder__, convert_primitive_type_name__1(type__));
			}
			else
			{
				write__2(builder__, ((string){{8},(uint8_t*)u8"void_ptr"}));
			}

			write__2(builder__, ((string){{13},(uint8_t*)u8"__0op__equal("}));
		}
		else
		{
			write__2(builder__, ((string){{18},(uint8_t*)u8"int32__0op__equal("}));
		}

		convert_expression__2(lhs_node__, builder__);
		write__2(builder__, ((string){{2},(uint8_t*)u8", "}));
		convert_expression__2(rhs_node__, builder__);
		write__2(builder__, ((string){{1},(uint8_t*)u8")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, NotEqualExpression__)))
	{
		Semantic_Node__0 const ref const lhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		Semantic_Node__0 const ref const rhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}));
		Type__0 const ref mut type__ = lhs_node__->of_type__;
		if (cond(void_ptr__0op__equal(type__, none)))
		{
			type__ = rhs_node__->of_type__;
		}

		if (cond(void_ptr__0op__not_equal(type__, none)))
		{
			if (cond(bool_op(bool_arg(type__->is_primitive__) && bool_arg(string__0op__equal(unqualified_name__1(type__->name__), ((string){{8},(uint8_t*)u8"optional"}))))))
			{
				type__ = system__collections__List__1__0op__element(type__->type_parameters__, ((int32){0}));
			}

			if (cond(type__->is_primitive__))
			{
				write__2(builder__, convert_primitive_type_name__1(type__));
			}
			else
			{
				write__2(builder__, ((string){{8},(uint8_t*)u8"void_ptr"}));
			}

			write__2(builder__, ((string){{17},(uint8_t*)u8"__0op__not_equal("}));
		}
		else
		{
			write__2(builder__, ((string){{22},(uint8_t*)u8"int32__0op__not_equal("}));
		}

		convert_expression__2(lhs_node__, builder__);
		write__2(builder__, ((string){{2},(uint8_t*)u8", "}));
		convert_expression__2(rhs_node__, builder__);
		write__2(builder__, ((string){{1},(uint8_t*)u8")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ComparisonExpression__)))
	{
		Semantic_Node__0 const ref mut child__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}));
		int32 const operator__ = child__->kind__;
		child__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		Type__0 const ref const type__ = child__->of_type__;
		if (cond(void_ptr__0op__not_equal(type__, none)))
		{
			write__2(builder__, convert_primitive_type_name__1(type__));
		}
		else
		{
			write__2(builder__, ((string){{5},(uint8_t*)u8"int32"}));
		}

		if (cond(int32__0op__equal(operator__, LessThan__)))
		{
			write__2(builder__, ((string){{9},(uint8_t*)u8"__0op__lt"}));
		}
		else if (cond(int32__0op__equal(operator__, LessThanEquals__)))
		{
			write__2(builder__, ((string){{10},(uint8_t*)u8"__0op__lte"}));
		}
		else if (cond(int32__0op__equal(operator__, GreaterThan__)))
		{
			write__2(builder__, ((string){{9},(uint8_t*)u8"__0op__gt"}));
		}
		else if (cond(int32__0op__equal(operator__, GreaterThanEquals__)))
		{
			write__2(builder__, ((string){{10},(uint8_t*)u8"__0op__gte"}));
		}
		else
		{
			error__2(builder__, string__0op__add(((string){{32},(uint8_t*)u8"Unsupported comparison operator "}), int_to_string__1(operator__)));
		}

		write__2(builder__, ((string){{1},(uint8_t*)u8"("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){{2},(uint8_t*)u8", "}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), builder__);
		write__2(builder__, ((string){{1},(uint8_t*)u8")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, AddExpression__)))
	{
		Semantic_Node__0 const ref const lhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		Semantic_Node__0 const ref const rhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}));
		Type__0 const ref mut type__ = lhs_node__->of_type__;
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
			write__2(builder__, ((string){{6},(uint8_t*)u8"string"}));
		}

		write__2(builder__, ((string){{11},(uint8_t*)u8"__0op__add("}));
		convert_expression__2(lhs_node__, builder__);
		write__2(builder__, ((string){{2},(uint8_t*)u8", "}));
		convert_expression__2(rhs_node__, builder__);
		write__2(builder__, ((string){{1},(uint8_t*)u8")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, SubtractExpression__)))
	{
		Semantic_Node__0 const ref const lhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		Semantic_Node__0 const ref const rhs_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}));
		write__2(builder__, ((string){{16},(uint8_t*)u8"int32__0op__sub("}));
		convert_expression__2(lhs_node__, builder__);
		write__2(builder__, ((string){{2},(uint8_t*)u8", "}));
		convert_expression__2(rhs_node__, builder__);
		write__2(builder__, ((string){{1},(uint8_t*)u8")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, MultiplyExpression__)))
	{
		write__2(builder__, ((string){{16},(uint8_t*)u8"int32__0op__mul("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){{2},(uint8_t*)u8", "}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), builder__);
		write__2(builder__, ((string){{1},(uint8_t*)u8")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, DivideExpression__)))
	{
		write__2(builder__, ((string){{16},(uint8_t*)u8"int32__0op__div("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){{2},(uint8_t*)u8", "}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), builder__);
		write__2(builder__, ((string){{1},(uint8_t*)u8")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, RemainderExpression__)))
	{
		write__2(builder__, ((string){{22},(uint8_t*)u8"int32__0op__remainder("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){{2},(uint8_t*)u8", "}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), builder__);
		write__2(builder__, ((string){{1},(uint8_t*)u8")"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, OrExpression__)))
	{
		write__2(builder__, ((string){{17},(uint8_t*)u8"bool_op(bool_arg("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){{14},(uint8_t*)u8") || bool_arg("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), builder__);
		write__2(builder__, ((string){{2},(uint8_t*)u8"))"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, AndExpression__)))
	{
		write__2(builder__, ((string){{17},(uint8_t*)u8"bool_op(bool_arg("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){{14},(uint8_t*)u8") && bool_arg("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){1})), builder__);
		write__2(builder__, ((string){{2},(uint8_t*)u8"))"}));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, InvocationExpression__)))
	{
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		Semantic_Node__0 const ref const parameters_node__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){1}));
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
		Semantic_Node__0 const ref const child__ = system__collections__List__1__0op__element(syntax__->children__, ((int32){0}));
		Type__0 const ref mut type__ = child__->of_type__;
		if (cond(void_ptr__0op__not_equal(type__, none)))
		{
			write__2(builder__, mangle_name__1(type__));
			write__2(builder__, ((string){{3},(uint8_t*)u8"__0"}));
		}
		else
		{
			write__2(builder__, ((string){{31},(uint8_t*)u8"system__collections__List__1__0"}));
		}

		write__2(builder__, ((string){{12},(uint8_t*)u8"op__element("}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){0})), builder__);
		write__2(builder__, ((string){{2},(uint8_t*)u8", "}));
		convert_expression__2(system__collections__List__1__0op__element(syntax__->children__, ((int32){2})), builder__);
		write__2(builder__, ((string){{1},(uint8_t*)u8")"}));
	}
	else
	{
		error__2(builder__, string__0op__add(((string){{37},(uint8_t*)u8"Could not convert expression of type "}), int_to_string__1(syntax__->kind__)));
	}
}

int32 mut literal_length__1(string const value__)
{
	int32 mut length__ = int32__0op__sub(string_byte_length__1(value__), ((int32){2}));
	BOOL mut escaped__ = FALSE;
	int32 mut i__ = ((int32){0});
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

code_point mut code_point_literal_value__1(string const value__)
{
	int32 const length__ = string_byte_length__1(value__);
	if (cond(int32__0op__equal(length__, ((int32){3}))))
	{
		return string__0__0op__element(value__, ((int32){1}));
	}
	else if (cond(int32__0op__equal(length__, ((int32){4}))))
	{
		if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"'\\\"'"}))))
		{
			return ((code_point){/*\"*/0x22});
		}
		else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"'\\\\'"}))))
		{
			return ((code_point){/*\\*/0x5C});
		}
		else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"'\\''"}))))
		{
			return ((code_point){/*\'*/0x27});
		}
		else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"'\\n'"}))))
		{
			return ((code_point){/*\n*/0xA});
		}
		else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"'\\r'"}))))
		{
			return ((code_point){/*\r*/0xD});
		}
		else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"'\\0'"}))))
		{
			return ((code_point){/*\0*/0x0});
		}
		else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"'\\b'"}))))
		{
			return ((code_point){/*\b*/0x8});
		}
		else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"'\\f'"}))))
		{
			return ((code_point){/*\f*/0xC});
		}
		else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"'\\t'"}))))
		{
			return ((code_point){/*\t*/0x9});
		}
		else if (cond(string__0op__equal(value__, ((string){{4},(uint8_t*)u8"'\\b'"}))))
		{
			return ((code_point){/*\b*/0x8});
		}
		else
		{
			assert__2(FALSE, string__0op__add(((string){{39},(uint8_t*)u8"Unsupported code_point escape sequence "}), value__));
		}
	}
	else if (cond(int32__0op__equal(length__, ((int32){6}))))
	{
		if (cond(string__0op__not_equal(substring__3(value__, ((int32){0}), ((int32){3})), ((string){{3},(uint8_t*)u8"'\\x"}))))
		{
			assert__2(FALSE, string__0op__add(((string){{39},(uint8_t*)u8"Unsupported code_point escape sequence "}), value__));
		}
		else
		{
			return int_to_code_point__1(hex_string_to_int__1(substring__3(value__, ((int32){3}), ((int32){2}))));
		}
	}
	else
	{
		assert__2(FALSE, string__0op__add(((string){{39},(uint8_t*)u8"Unsupported code_point escape sequence "}), value__));
	}

	UNREACHABLE__0();
}

void mut convert_reference_type_constructor_arguments__3(Semantic_Node__0 const ref const syntax__, Source_File_Builder__0 mut ref const builder__, string const type_name__)
{
	assert__1(int32__0op__equal(syntax__->kind__, ArgumentList__));
	write__2(builder__, ((string){{17},(uint8_t*)u8"(allocate(sizeof("}));
	write__2(builder__, type_name__);
	write__2(builder__, ((string){{2},(uint8_t*)u8"))"}));
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const ref const arg__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__not_equal(arg__->kind__, LeftParen__)) && bool_arg(int32__0op__not_equal(arg__->kind__, RightParen__)))) && bool_arg(int32__0op__not_equal(arg__->kind__, Comma__)))))
		{
			write__2(builder__, ((string){{2},(uint8_t*)u8", "}));
			convert_expression__2(arg__, builder__);
		}
	}

	write__2(builder__, ((string){{1},(uint8_t*)u8")"}));
}

void mut convert_member_access__2(Semantic_Node__0 const ref const lhs__, Source_File_Builder__0 mut ref const builder__)
{
	Type__0 const opt_ref const type__ = lhs__->of_type__;
	if (cond(bool_op(bool_arg(bool_op(bool_arg(void_ptr__0op__not_equal(type__, none)) && bool_arg(type__->is_value_type__))) && bool_arg(BOOL__0op__not(bool_op(bool_arg(bool_op(bool_arg(type__->is_primitive__) && bool_arg(string__0op__equal(unqualified_name__1(type__->name__), ((string){{8},(uint8_t*)u8"optional"}))))) && bool_arg(BOOL__0op__not(as_type__1(system__collections__List__1__0op__element(type__->type_parameters__, ((int32){0})))->is_value_type__))))))))
	{
		write__2(builder__, ((string){{1},(uint8_t*)u8"."}));
	}
	else
	{
		write__2(builder__, ((string){{2},(uint8_t*)u8"->"}));
	}
}

Type__0 const ref mut as_type__1(Type__0 const ref const type__)
{
	return type__;
}

void mut emit_statement__2(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const statement__)
{
	statement_separator_line__1(emitter__->definitions__);
	if (cond(int32__0op__equal(statement__->kind__, ReturnStatement__)))
	{
		if (cond(int32__0op__equal(statement__->children__->count__, ((int32){2}))))
		{
			write_line__2(emitter__->definitions__, ((string){{7},(uint8_t*)u8"return;"}));
		}
		else
		{
			begin_line__2(emitter__->definitions__, ((string){{7},(uint8_t*)u8"return "}));
			convert_expression__2(system__collections__List__1__0op__element(statement__->children__, ((int32){1})), emitter__->definitions__);
			end_line__2(emitter__->definitions__, ((string){{1},(uint8_t*)u8";"}));
		}
	}
	else if (cond(int32__0op__equal(statement__->kind__, LoopStatement__)))
	{
		write_line__2(emitter__->definitions__, ((string){{8},(uint8_t*)u8"for (;;)"}));
		emit_statement__2(emitter__, system__collections__List__1__0op__element(statement__->children__, ((int32){1})));
	}
	else if (cond(int32__0op__equal(statement__->kind__, Block__)))
	{
		begin_block__1(emitter__->definitions__);
		for (void_ptr__0iter mut iter = void_ptr__0iterate(node_statements__1(statement__)); void_ptr__0next(&iter);)
		{
			Semantic_Node__0 const ref const block_statement__ = void_ptr__0current(&iter);
			emit_statement__2(emitter__, block_statement__);
		}

		end_block__1(emitter__->definitions__);
	}
	else if (cond(int32__0op__equal(statement__->kind__, WhileStatement__)))
	{
		begin_line__2(emitter__->definitions__, ((string){{12},(uint8_t*)u8"while (cond("}));
		convert_expression__2(system__collections__List__1__0op__element(statement__->children__, ((int32){1})), emitter__->definitions__);
		end_line__2(emitter__->definitions__, ((string){{2},(uint8_t*)u8"))"}));
		emit_statement__2(emitter__, system__collections__List__1__0op__element(statement__->children__, ((int32){2})));
	}
	else if (cond(int32__0op__equal(statement__->kind__, ForStatement__)))
	{
		Semantic_Node__0 const ref const variable_declaration__ = first_child__2(statement__, VariableDeclaration__);
		BOOL const mutable_binding__ = node_has_child__2(variable_declaration__, VarKeyword__);
		string const variable_name__ = get_semantic_node_text__1(first_child__2(variable_declaration__, Identifier__));
		Semantic_Node__0 const ref const variable_type_node__ = system__collections__List__1__0op__element(variable_declaration__->children__, ((int32){2}));
		Semantic_Node__0 const ref const iterator_expression__ = system__collections__List__1__0op__element(statement__->children__, ((int32){3}));
		Type__0 const ref const iterator_over_type__ = variable_type_node__->referenced_type__;
		assert__2(void_ptr__0op__not_equal(iterator_over_type__, none), get_semantic_node_text__1(variable_type_node__));
		string mut iterator_type__;
		if (cond(iterator_over_type__->is_primitive__))
		{
			iterator_type__ = convert_primitive_type_name__1(iterator_over_type__);
		}
		else
		{
			iterator_type__ = ((string){{8},(uint8_t*)u8"void_ptr"});
		}

		Type__0 const ref const collection_type__ = iterator_expression__->of_type__;
		string mut iteratable_type__;
		if (cond(void_ptr__0op__not_equal(collection_type__, none)))
		{
			iteratable_type__ = mangle_name__1(collection_type__);
		}
		else
		{
			iteratable_type__ = iterator_type__;
		}

		begin_line__2(emitter__->definitions__, ((string){{5},(uint8_t*)u8"for ("}));
		write__2(emitter__->definitions__, iterator_type__);
		write__2(emitter__->definitions__, ((string){{19},(uint8_t*)u8"__0iter mut iter = "}));
		write__2(emitter__->definitions__, iteratable_type__);
		write__2(emitter__->definitions__, ((string){{11},(uint8_t*)u8"__0iterate("}));
		convert_expression__2(iterator_expression__, emitter__->definitions__);
		write__2(emitter__->definitions__, ((string){{3},(uint8_t*)u8"); "}));
		write__2(emitter__->definitions__, iterator_type__);
		end_line__2(emitter__->definitions__, ((string){{16},(uint8_t*)u8"__0next(&iter);)"}));
		begin_block__1(emitter__->definitions__);
		begin_line__2(emitter__->definitions__, ((string){{0},(uint8_t*)u8""}));
		write__2(emitter__->definitions__, convert_type__2(mutable_binding__, variable_type_node__));
		write__2(emitter__->definitions__, ((string){{1},(uint8_t*)u8" "}));
		write__2(emitter__->definitions__, mangle_field_name__1(variable_name__));
		write__2(emitter__->definitions__, ((string){{3},(uint8_t*)u8" = "}));
		write__2(emitter__->definitions__, iterator_type__);
		end_line__2(emitter__->definitions__, ((string){{18},(uint8_t*)u8"__0current(&iter);"}));
		Semantic_Node__0 const ref const for_loop_body__ = system__collections__List__1__0op__element(statement__->children__, ((int32){4}));
		for (void_ptr__0iter mut iter = void_ptr__0iterate(node_statements__1(for_loop_body__)); void_ptr__0next(&iter);)
		{
			Semantic_Node__0 const ref const block_statement__ = void_ptr__0current(&iter);
			emit_statement__2(emitter__, block_statement__);
		}

		end_block__1(emitter__->definitions__);
	}
	else if (cond(int32__0op__equal(statement__->kind__, DoWhileStatement__)))
	{
		write_line__2(emitter__->definitions__, ((string){{2},(uint8_t*)u8"do"}));
		emit_statement__2(emitter__, system__collections__List__1__0op__element(statement__->children__, ((int32){1})));
		begin_line__2(emitter__->definitions__, ((string){{12},(uint8_t*)u8"while (cond("}));
		convert_expression__2(system__collections__List__1__0op__element(statement__->children__, ((int32){3})), emitter__->definitions__);
		end_line__2(emitter__->definitions__, ((string){{3},(uint8_t*)u8"));"}));
	}
	else if (cond(int32__0op__equal(statement__->kind__, IfStatement__)))
	{
		Semantic_Node__0 const opt_ref mut if_statement__ = statement__;
		begin_line__2(emitter__->definitions__, ((string){{0},(uint8_t*)u8""}));
		for (;;)
		{
			write__2(emitter__->definitions__, ((string){{9},(uint8_t*)u8"if (cond("}));
			convert_expression__2(system__collections__List__1__0op__element(if_statement__->children__, ((int32){1})), emitter__->definitions__);
			end_line__2(emitter__->definitions__, ((string){{2},(uint8_t*)u8"))"}));
			emit_statement__2(emitter__, system__collections__List__1__0op__element(if_statement__->children__, ((int32){2})));
			Semantic_Node__0 const opt_ref const else_clause__ = first_child__2(if_statement__, ElseClause__);
			if (cond(void_ptr__0op__not_equal(else_clause__, none)))
			{
				if_statement__ = first_child__2(else_clause__, IfStatement__);
				if (cond(void_ptr__0op__not_equal(if_statement__, none)))
				{
					begin_line__2(emitter__->definitions__, ((string){{5},(uint8_t*)u8"else "}));
				}
				else
				{
					write_line__2(emitter__->definitions__, ((string){{4},(uint8_t*)u8"else"}));
					emit_statement__2(emitter__, system__collections__List__1__0op__element(else_clause__->children__, ((int32){1})));
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	else if (cond(int32__0op__equal(statement__->kind__, MatchStatement__)))
	{
		begin_line__2(emitter__->definitions__, ((string){{49},(uint8_t*)u8"/* match */ { void const ref const match_value = "}));
		convert_expression__2(system__collections__List__1__0op__element(statement__->children__, ((int32){1})), emitter__->definitions__);
		end_line__2(emitter__->definitions__, ((string){{1},(uint8_t*)u8";"}));
		write_line__2(emitter__->definitions__, ((string){{42},(uint8_t*)u8"   switch(*(Type_ID const ref)match_value)"}));
		begin_block__1(emitter__->definitions__);
		for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(statement__->children__); void_ptr__0next(&iter);)
		{
			Semantic_Node__0 const ref const match_arm__ = void_ptr__0current(&iter);
			if (cond(int32__0op__equal(match_arm__->kind__, MatchArm__)))
			{
				Semantic_Node__0 const ref const match_pattern__ = first_child__2(match_arm__, MatchPattern__);
				Semantic_Node__0 const ref const match_variable_type_node__ = system__collections__List__1__0op__element(match_pattern__->children__, ((int32){2}));
				string const variable_name__ = get_semantic_node_text__1(first_child__2(match_pattern__, Identifier__));
				Semantic_Node__0 const ref const match_block__ = first_child__2(match_arm__, Block__);
				assert__2(void_ptr__0op__not_equal(match_variable_type_node__->referenced_type__, none), get_semantic_node_text__1(match_variable_type_node__));
				string const type_name__ = sb_to_string__1(convert_type_name__1(match_variable_type_node__->referenced_type__));
				write_line__2(emitter__->definitions__, string__0op__add(string__0op__add(((string){{5},(uint8_t*)u8"case "}), type_name__), ((string){{11},(uint8_t*)u8"__0Type_ID:"})));
				begin_block__1(emitter__->definitions__);
				if (cond(code_point__0op__not_equal(string__0__0op__element(variable_name__, ((int32){0})), ((code_point){/*_*/0x5F}))))
				{
					begin_line__2(emitter__->definitions__, convert_type__2(FALSE, match_variable_type_node__));
					write__2(emitter__->definitions__, ((string){{1},(uint8_t*)u8" "}));
					write__2(emitter__->definitions__, mangle_field_name__1(variable_name__));
					end_line__2(emitter__->definitions__, ((string){{15},(uint8_t*)u8" = match_value;"}));
				}

				for (void_ptr__0iter mut iter = void_ptr__0iterate(node_statements__1(match_block__)); void_ptr__0next(&iter);)
				{
					Semantic_Node__0 const ref const block_statement__ = void_ptr__0current(&iter);
					emit_statement__2(emitter__, block_statement__);
				}

				end_block__1(emitter__->definitions__);
				write_line__2(emitter__->definitions__, ((string){{6},(uint8_t*)u8"break;"}));
			}
		}

		write_line__2(emitter__->definitions__, ((string){{8},(uint8_t*)u8"default:"}));
		write_line__2(emitter__->definitions__, ((string){{57},(uint8_t*)u8"   NON_EXHAUSTIVE_MATCH(*(Type_ID const ref)match_value);"}));
		end_block_with__2(emitter__->definitions__, ((string){{2},(uint8_t*)u8"}}"}));
	}
	else if (cond(int32__0op__equal(statement__->kind__, BreakStatement__)))
	{
		write_line__2(emitter__->definitions__, ((string){{6},(uint8_t*)u8"break;"}));
	}
	else if (cond(int32__0op__equal(statement__->kind__, ContinueStatement__)))
	{
		write_line__2(emitter__->definitions__, ((string){{9},(uint8_t*)u8"continue;"}));
	}
	else if (cond(int32__0op__equal(statement__->kind__, LocalDeclarationStatement__)))
	{
		Semantic_Node__0 const ref const variable_declaration__ = first_child__2(statement__, VariableDeclaration__);
		string const variable_name__ = get_semantic_node_text__1(first_child__2(variable_declaration__, Identifier__));
		Semantic_Node__0 const ref const variable_type__ = system__collections__List__1__0op__element(variable_declaration__->children__, ((int32){2}));
		BOOL const mutable_binding__ = node_has_child__2(variable_declaration__, VarKeyword__);
		begin_line__2(emitter__->definitions__, convert_type__2(mutable_binding__, variable_type__));
		write__2(emitter__->definitions__, string__0op__add(((string){{1},(uint8_t*)u8" "}), mangle_field_name__1(variable_name__)));
		if (cond(int32__0op__gt(variable_declaration__->children__->count__, ((int32){3}))))
		{
			write__2(emitter__->definitions__, ((string){{3},(uint8_t*)u8" = "}));
			convert_expression__2(system__collections__List__1__0op__element(variable_declaration__->children__, ((int32){3})), emitter__->definitions__);
		}

		end_line__2(emitter__->definitions__, ((string){{1},(uint8_t*)u8";"}));
	}
	else if (cond(int32__0op__equal(statement__->kind__, ExpressionStatement__)))
	{
		begin_line__2(emitter__->definitions__, ((string){{0},(uint8_t*)u8""}));
		convert_expression__2(system__collections__List__1__0op__element(statement__->children__, ((int32){0})), emitter__->definitions__);
		end_line__2(emitter__->definitions__, ((string){{1},(uint8_t*)u8";"}));
	}
	else
	{
		NOT_IMPLEMENTED__1(string__0op__add(((string){{15},(uint8_t*)u8"statement.kind="}), int_to_string__1(statement__->kind__)));
	}
}

void mut emit_method_body__3(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const block__, BOOL const is_associated_function__)
{
	begin_block__1(emitter__->definitions__);
	if (cond(BOOL__0op__not(is_associated_function__)))
	{
		write_line__2(emitter__->definitions__, ((string){{17},(uint8_t*)u8"auto self = this;"}));
	}

	for (void_ptr__0iter mut iter = void_ptr__0iterate(node_statements__1(block__)); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const ref const statement__ = void_ptr__0current(&iter);
		emit_statement__2(emitter__, statement__);
	}

	end_block__1(emitter__->definitions__);
}

void mut emit_constructor_body__4(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const block__, string const type_name__, BOOL const is_value_type__)
{
	begin_block__1(emitter__->definitions__);
	if (cond(is_value_type__))
	{
		write_line__2(emitter__->definitions__, string__0op__add(type_name__, ((string){{10},(uint8_t*)u8" mut self;"})));
	}
	else
	{
		write_line__2(emitter__->definitions__, string__0op__add(string__0op__add(((string){{16},(uint8_t*)u8"self->type_id = "}), type_name__), ((string){{11},(uint8_t*)u8"__0Type_ID;"})));
	}

	for (void_ptr__0iter mut iter = void_ptr__0iterate(node_statements__1(block__)); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const ref const statement__ = void_ptr__0current(&iter);
		emit_statement__2(emitter__, statement__);
	}

	write_line__2(emitter__->definitions__, ((string){{12},(uint8_t*)u8"return self;"}));
	end_block__1(emitter__->definitions__);
}

void mut emit_member_declaration__4(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const member__, string const class_name__, BOOL const is_value_type__)
{
	if (cond(int32__0op__equal(member__->kind__, ConstructorDeclaration__)))
	{
		Semantic_Node__0 const ref const parameters_node__ = first_child__2(member__, ParameterList__);
		string mut new_function_name__ = string__0op__add(((string){{4},(uint8_t*)u8"new_"}), class_name__);
		string mut constructor_full_name__ = string__0op__add(class_name__, ((string){{8},(uint8_t*)u8"__0new__"}));
		Semantic_Node__0 const opt_ref const constructor_name_node__ = first_child__2(member__, Identifier__);
		if (cond(void_ptr__0op__not_equal(constructor_name_node__, none)))
		{
			string const constructor_name__ = get_semantic_node_text__1(constructor_name_node__);
			new_function_name__ = string__0op__add(string__0op__add(new_function_name__, ((string){{2},(uint8_t*)u8"__"})), constructor_name__);
			constructor_full_name__ = string__0op__add(string__0op__add(constructor_full_name__, constructor_name__), ((string){{2},(uint8_t*)u8"__"}));
		}

		constructor_full_name__ = string__0op__add(constructor_full_name__, int_to_string__1(parameters_node__->children__->count__));
		string mut return_type__ = string__0op__add(class_name__, ((string){{4},(uint8_t*)u8" mut"}));
		if (cond(BOOL__0op__not(is_value_type__)))
		{
			return_type__ = string__0op__add(return_type__, ((string){{8},(uint8_t*)u8" ref mut"}));
		}

		string mut constructor_parameters__;
		if (cond(BOOL__0op__not(is_value_type__)))
		{
			constructor_parameters__ = convert_method_parameter_list__3(emitter__, parameters_node__, string__0op__add(class_name__, ((string){{14},(uint8_t*)u8" mut ref const"})));
		}
		else
		{
			constructor_parameters__ = convert_parameter_list__2(emitter__, parameters_node__);
		}

		string mut constructor_signature__ = string__0op__add(string__0op__add(string__0op__add(return_type__, ((string){{1},(uint8_t*)u8" "})), constructor_full_name__), constructor_parameters__);
		write_line__2(emitter__->function_declarations__, string__0op__add(constructor_signature__, ((string){{1},(uint8_t*)u8";"})));
		element_separator_line__1(emitter__->definitions__);
		write_line__2(emitter__->definitions__, constructor_signature__);
		emit_constructor_body__4(emitter__, first_child__2(member__, Block__), class_name__, is_value_type__);
	}
	else if (cond(int32__0op__equal(member__->kind__, FieldDeclaration__)))
	{
		Semantic_Node__0 const ref const variable_declaration__ = first_child__2(member__, VariableDeclaration__);
		string const field_name__ = get_semantic_node_text__1(first_child__2(variable_declaration__, Identifier__));
		Semantic_Node__0 const ref const field_type__ = system__collections__List__1__0op__element(variable_declaration__->children__, ((int32){2}));
		string const c_type__ = convert_type__2(TRUE, field_type__);
		write_line__2(emitter__->class_declarations__, string__0op__add(string__0op__add(string__0op__add(c_type__, ((string){{1},(uint8_t*)u8" "})), mangle_field_name__1(field_name__)), ((string){{1},(uint8_t*)u8";"})));
	}
	else if (cond(int32__0op__equal(member__->kind__, MethodDeclaration__)))
	{
		Semantic_Node__0 const ref const parameters_node__ = first_child__2(member__, ParameterList__);
		Semantic_Node__0 const opt_ref const self_parameter__ = first_child__2(parameters_node__, SelfParameter__);
		int32 mut parameter_count__ = parameters_node__->children__->count__;
		if (cond(void_ptr__0op__not_equal(self_parameter__, none)))
		{
			op__sub_assign(&(parameter_count__), ((int32){1}));
		}

		string const method_name__ = mangle_function_name__2(get_semantic_node_text__1(first_child__2(member__, Identifier__)), parameter_count__);
		string const parameters__ = convert_parameter_list__2(emitter__, parameters_node__);
		BOOL const is_associated_function__ = void_ptr__0op__equal(self_parameter__, none);
		BOOL const mutable_self__ = bool_op(bool_arg(BOOL__0op__not(is_associated_function__)) && bool_arg(node_has_child__2(self_parameter__, MutableKeyword__)));
		Semantic_Node__0 const ref const return_type_node__ = system__collections__List__1__0op__element(member__->children__, ((int32){3}));
		string const c_type__ = convert_type__2(TRUE, return_type_node__);
		string mut static_modifier__ = ((string){{0},(uint8_t*)u8""});
		if (cond(is_associated_function__))
		{
			static_modifier__ = ((string){{7},(uint8_t*)u8"static "});
		}

		string mut const_modifier__ = ((string){{0},(uint8_t*)u8""});
		if (cond(bool_op(bool_arg(BOOL__0op__not(mutable_self__)) && bool_arg(BOOL__0op__not(is_associated_function__)))))
		{
			const_modifier__ = ((string){{6},(uint8_t*)u8" const"});
		}

		write_line__2(emitter__->class_declarations__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(static_modifier__, c_type__), ((string){{1},(uint8_t*)u8" "})), method_name__), parameters__), const_modifier__), ((string){{1},(uint8_t*)u8";"})));
		element_separator_line__1(emitter__->definitions__);
		write_line__2(emitter__->definitions__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(c_type__, ((string){{1},(uint8_t*)u8" "})), class_name__), ((string){{2},(uint8_t*)u8"::"})), method_name__), parameters__), const_modifier__));
		Semantic_Node__0 const ref const block__ = first_child__2(member__, Block__);
		emit_method_body__3(emitter__, block__, is_associated_function__);
	}
	else
	{
		error__2(emitter__->definitions__, string__0op__add(((string){{30},(uint8_t*)u8"Could not emit member of type "}), int_to_string__1(member__->kind__)));
	}
}

void mut emit_default_constructor__3(Emitter__0 mut ref const emitter__, string const type_name__, BOOL const is_value_type__)
{
	string const default_constructor_name__ = string__0op__add(type_name__, ((string){{9},(uint8_t*)u8"__0new__0"}));
	string mut return_type__ = string__0op__add(type_name__, ((string){{4},(uint8_t*)u8" mut"}));
	if (cond(BOOL__0op__not(is_value_type__)))
	{
		return_type__ = string__0op__add(return_type__, ((string){{8},(uint8_t*)u8" ref mut"}));
	}

	string mut constructor_signature__ = string__0op__add(string__0op__add(string__0op__add(return_type__, ((string){{1},(uint8_t*)u8" "})), default_constructor_name__), ((string){{1},(uint8_t*)u8"("}));
	if (cond(BOOL__0op__not(is_value_type__)))
	{
		constructor_signature__ = string__0op__add(string__0op__add(constructor_signature__, type_name__), ((string){{19},(uint8_t*)u8" mut ref const self"}));
	}

	constructor_signature__ = string__0op__add(constructor_signature__, ((string){{1},(uint8_t*)u8")"}));
	write_line__2(emitter__->function_declarations__, string__0op__add(constructor_signature__, ((string){{1},(uint8_t*)u8";"})));
	element_separator_line__1(emitter__->definitions__);
	begin_line__2(emitter__->definitions__, constructor_signature__);
	if (cond(is_value_type__))
	{
		end_line__2(emitter__->definitions__, string__0op__add(string__0op__add(((string){{11},(uint8_t*)u8" { return ("}), return_type__), ((string){{6},(uint8_t*)u8"){}; }"})));
	}
	else
	{
		end_line__2(emitter__->definitions__, string__0op__add(string__0op__add(((string){{19},(uint8_t*)u8" { self->type_id = "}), type_name__), ((string){{26},(uint8_t*)u8"__0Type_ID; return self; }"})));
	}
}

void mut emit_declaration__2(Emitter__0 mut ref const emitter__, Semantic_Node__0 const ref const declaration__)
{
	if (cond(int32__0op__equal(declaration__->kind__, GlobalDeclaration__)))
	{
		Semantic_Node__0 const ref const variable_declaration__ = first_child__2(declaration__, VariableDeclaration__);
		string const variable_name__ = get_semantic_node_text__1(first_child__2(variable_declaration__, Identifier__));
		Semantic_Node__0 const ref const variable_type__ = system__collections__List__1__0op__element(variable_declaration__->children__, ((int32){2}));
		BOOL const mutable_binding__ = node_has_child__2(variable_declaration__, VarKeyword__);
		string const c_type__ = convert_type__2(mutable_binding__, variable_type__);
		begin_line__2(emitter__->global_definitions__, c_type__);
		write__2(emitter__->global_definitions__, string__0op__add(string__0op__add(((string){{1},(uint8_t*)u8" "}), mangle_field_name__1(variable_name__)), ((string){{3},(uint8_t*)u8" = "})));
		Semantic_Node__0 const ref const expression__ = system__collections__List__1__0op__element(variable_declaration__->children__, ((int32){3}));
		convert_expression__2(expression__, emitter__->global_definitions__);
		end_line__2(emitter__->global_definitions__, ((string){{1},(uint8_t*)u8";"}));
	}
	else if (cond(int32__0op__equal(declaration__->kind__, ClassDeclaration__)))
	{
		Type__0 const ref const declared_type__ = declaration__->declares_type__;
		assert__2(void_ptr__0op__not_equal(declared_type__, none), get_semantic_node_text__1(first_child__2(declaration__, Identifier__)));
		string const class_name__ = mangle_name__1(declared_type__);
		write_line__2(emitter__->type_id_declaration__, string__0op__add(class_name__, ((string){{11},(uint8_t*)u8"__0Type_ID,"})));
		write_line__2(emitter__->type_declarations__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){{15},(uint8_t*)u8"typedef struct "}), class_name__), ((string){{1},(uint8_t*)u8" "})), class_name__), ((string){{1},(uint8_t*)u8";"})));
		element_separator_line__1(emitter__->class_declarations__);
		write_line__2(emitter__->class_declarations__, string__0op__add(((string){{7},(uint8_t*)u8"struct "}), class_name__));
		begin_block__1(emitter__->class_declarations__);
		write_line__2(emitter__->class_declarations__, ((string){{16},(uint8_t*)u8"Type_ID type_id;"}));
		BOOL mut has_constructors__ = FALSE;
		for (void_ptr__0iter mut iter = void_ptr__0iterate(node_members__1(declaration__)); void_ptr__0next(&iter);)
		{
			Semantic_Node__0 const ref const member__ = void_ptr__0current(&iter);
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
		Type__0 const ref const declared_type__ = declaration__->declares_type__;
		assert__2(void_ptr__0op__not_equal(declared_type__, none), get_semantic_node_text__1(first_child__2(declaration__, Identifier__)));
		string const struct_name__ = mangle_name__1(declared_type__);
		write_line__2(emitter__->type_declarations__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){{15},(uint8_t*)u8"typedef struct "}), struct_name__), ((string){{1},(uint8_t*)u8" "})), struct_name__), ((string){{1},(uint8_t*)u8";"})));
		element_separator_line__1(emitter__->class_declarations__);
		write_line__2(emitter__->class_declarations__, string__0op__add(((string){{7},(uint8_t*)u8"struct "}), struct_name__));
		begin_block__1(emitter__->class_declarations__);
		BOOL mut has_constructors__ = FALSE;
		for (void_ptr__0iter mut iter = void_ptr__0iterate(node_members__1(declaration__)); void_ptr__0next(&iter);)
		{
			Semantic_Node__0 const ref const member__ = void_ptr__0current(&iter);
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
		string const enum_name__ = get_semantic_node_text__1(first_child__2(declaration__, Identifier__));
		write_line__2(emitter__->type_declarations__, string__0op__add(string__0op__add(((string){{5},(uint8_t*)u8"enum "}), enum_name__), ((string){{1},(uint8_t*)u8"_"})));
		begin_block__1(emitter__->type_declarations__);
		for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(declaration__->children__); void_ptr__0next(&iter);)
		{
			Semantic_Node__0 const ref const member__ = void_ptr__0current(&iter);
			if (cond(int32__0op__equal(member__->kind__, EnumMemberDeclaration__)))
			{
				string const member_name__ = get_semantic_node_text__1(system__collections__List__1__0op__element(member__->children__, ((int32){0})));
				begin_line__2(emitter__->type_declarations__, string__0op__add(member_name__, ((string){{1},(uint8_t*)u8"_"})));
				Semantic_Node__0 const opt_ref const member_value__ = first_child__2(member__, Integer__);
				if (cond(void_ptr__0op__not_equal(member_value__, none)))
				{
					write__2(emitter__->type_declarations__, ((string){{3},(uint8_t*)u8" = "}));
					write__2(emitter__->type_declarations__, get_semantic_node_text__1(member_value__));
				}

				end_line__2(emitter__->type_declarations__, ((string){{1},(uint8_t*)u8","}));
			}
		}

		end_block_with_semicolon__1(emitter__->type_declarations__);
		write_line__2(emitter__->type_declarations__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){{13},(uint8_t*)u8"typedef enum "}), enum_name__), ((string){{2},(uint8_t*)u8"_ "})), enum_name__), ((string){{2},(uint8_t*)u8"_;"})));
	}
	else if (cond(int32__0op__equal(declaration__->kind__, FunctionDeclaration__)))
	{
		Semantic_Node__0 const ref const parameters_node__ = first_child__2(declaration__, ParameterList__);
		string mut name__ = get_semantic_node_text__1(first_child__2(declaration__, Identifier__));
		BOOL const is_main__ = string__0op__equal(name__, ((string){{4},(uint8_t*)u8"main"}));
		name__ = mangle_function_name__2(name__, parameters_node__->children__->count__);
		if (cond(is_main__))
		{
			emitter__->main_function_name__ = name__;
		}

		string const parameters__ = convert_parameter_list__3(emitter__, parameters_node__, is_main__);
		Semantic_Node__0 const ref const return_type_node__ = system__collections__List__1__0op__element(declaration__->children__, ((int32){3}));
		string const c_type__ = convert_type__2(TRUE, return_type_node__);
		write_line__2(emitter__->function_declarations__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(c_type__, ((string){{1},(uint8_t*)u8" "})), name__), parameters__), ((string){{1},(uint8_t*)u8";"})));
		element_separator_line__1(emitter__->definitions__);
		write_line__2(emitter__->definitions__, string__0op__add(string__0op__add(string__0op__add(c_type__, ((string){{1},(uint8_t*)u8" "})), name__), parameters__));
		if (cond(is_main__))
		{
			if (cond(string__0op__not_equal(emitter__->main_function_return_type__, ((string){{0},(uint8_t*)u8""}))))
			{
				error__2(emitter__->definitions__, ((string){{29},(uint8_t*)u8"Multiple declarations of main"}));
			}

			emitter__->main_function_return_type__ = c_type__;
		}

		emit_statement__2(emitter__, first_child__2(declaration__, Block__));
	}
	else if (cond(int32__0op__equal(declaration__->kind__, EndOfFile__)))
	{
	}
	else
	{
		error__2(emitter__->definitions__, string__0op__add(((string){{35},(uint8_t*)u8"Could not emit declaration of type "}), int_to_string__1(declaration__->kind__)));
	}
}

void mut emit_compilation_unit__2(Emitter__0 mut ref const emitter__, Compilation_Unit__0 const ref const unit__)
{
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(unit__->declarations__); void_ptr__0next(&iter);)
	{
		Semantic_Node__0 const ref const declaration__ = void_ptr__0current(&iter);
		emit_declaration__2(emitter__, declaration__);
	}
}

void mut emit_preamble__1(Emitter__0 mut ref const emitter__)
{
	write_line__2(emitter__->includes__, ((string){{27},(uint8_t*)u8"#include \"RuntimeLibrary.h\""}));
	blank_line__1(emitter__->type_id_declaration__);
	write_line__2(emitter__->type_id_declaration__, ((string){{23},(uint8_t*)u8"// Type ID Declarations"}));
	write_line__2(emitter__->type_id_declaration__, ((string){{12},(uint8_t*)u8"enum Type_ID"}));
	begin_block__1(emitter__->type_id_declaration__);
	write_line__2(emitter__->type_id_declaration__, ((string){{21},(uint8_t*)u8"never__0Type__ID = 0,"}));
	blank_line__1(emitter__->type_declarations__);
	write_line__2(emitter__->type_declarations__, ((string){{20},(uint8_t*)u8"// Type Declarations"}));
	blank_line__1(emitter__->function_declarations__);
	write_line__2(emitter__->function_declarations__, ((string){{24},(uint8_t*)u8"// Function Declarations"}));
	blank_line__1(emitter__->class_declarations__);
	write_line__2(emitter__->class_declarations__, ((string){{21},(uint8_t*)u8"// Class Declarations"}));
	blank_line__1(emitter__->global_definitions__);
	write_line__2(emitter__->global_definitions__, ((string){{21},(uint8_t*)u8"// Global Definitions"}));
	blank_line__1(emitter__->definitions__);
	write_line__2(emitter__->definitions__, ((string){{14},(uint8_t*)u8"// Definitions"}));
}

void mut emit_entry_point_adapter__1(Emitter__0 mut ref const emitter__)
{
	element_separator_line__1(emitter__->definitions__);
	write_line__2(emitter__->definitions__, ((string){{22},(uint8_t*)u8"// Entry Point Adapter"}));
	write_line__2(emitter__->definitions__, ((string){{53},(uint8_t*)u8"int32_t main(int argc, char const ptr const ptr argv)"}));
	begin_block__1(emitter__->definitions__);
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(emitter__->resources__); void_ptr__0next(&iter);)
	{
		Source_Text__0 const ref const resource__ = void_ptr__0current(&iter);
		string const resource_name__ = string__0op__add(string__0op__add(((string){{1},(uint8_t*)u8"\""}), resource__->name__), ((string){{1},(uint8_t*)u8"\""}));
		string mut resource_text__ = resource__->text__;
		resource_text__ = string_replace__3(resource_text__, ((string){{1},(uint8_t*)u8"\\"}), ((string){{2},(uint8_t*)u8"\\\\"}));
		resource_text__ = string_replace__3(resource_text__, ((string){{1},(uint8_t*)u8"\n"}), ((string){{2},(uint8_t*)u8"\\n"}));
		resource_text__ = string_replace__3(resource_text__, ((string){{1},(uint8_t*)u8"\r"}), ((string){{2},(uint8_t*)u8"\\r"}));
		resource_text__ = string_replace__3(resource_text__, ((string){{1},(uint8_t*)u8"\""}), ((string){{2},(uint8_t*)u8"\\\""}));
		resource_text__ = string__0op__add(string__0op__add(((string){{1},(uint8_t*)u8"\""}), resource_text__), ((string){{1},(uint8_t*)u8"\""}));
		begin_line__2(emitter__->definitions__, string__0op__add(string__0op__add(((string){{23},(uint8_t*)u8"add_resource((string){{"}), int_to_string__1(literal_length__1(resource_name__))), ((string){{14},(uint8_t*)u8"},(uint8_t*)u8"})));
		write__2(emitter__->definitions__, resource_name__);
		write__2(emitter__->definitions__, string__0op__add(string__0op__add(((string){{13},(uint8_t*)u8"}, (string){{"}), int_to_string__1(literal_length__1(resource_text__))), ((string){{14},(uint8_t*)u8"},(uint8_t*)u8"})));
		write__2(emitter__->definitions__, resource_text__);
		end_line__2(emitter__->definitions__, ((string){{3},(uint8_t*)u8"});"}));
	}

	if (cond(int32__0op__gt(emitter__->resources__->count__, ((int32){0}))))
	{
		end_line__2(emitter__->definitions__, ((string){{0},(uint8_t*)u8""}));
	}

	system__text__String_Builder__0 mut ref const args__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	if (cond(emitter__->main_function_accepts_console__))
	{
		sb_append__2(args__, ((string){{45},(uint8_t*)u8"allocate(sizeof(system__console__Console__0))"}));
	}

	if (cond(emitter__->main_function_accepts_args__))
	{
		if (cond(emitter__->main_function_accepts_console__))
		{
			sb_append__2(args__, ((string){{2},(uint8_t*)u8", "}));
		}

		sb_append__2(args__, ((string){{29},(uint8_t*)u8"convert_arguments(argc, argv)"}));
	}

	if (cond(string__0op__equal(emitter__->main_function_return_type__, ((string){{8},(uint8_t*)u8"void mut"}))))
	{
		write_line__2(emitter__->definitions__, string__0op__add(string__0op__add(string__0op__add(emitter__->main_function_name__, ((string){{1},(uint8_t*)u8"("})), sb_to_string__1(args__)), ((string){{2},(uint8_t*)u8");"})));
		write_line__2(emitter__->definitions__, ((string){{9},(uint8_t*)u8"return 0;"}));
	}
	else
	{
		write_line__2(emitter__->definitions__, string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){{7},(uint8_t*)u8"return "}), emitter__->main_function_name__), ((string){{1},(uint8_t*)u8"("})), sb_to_string__1(args__)), ((string){{8},(uint8_t*)u8").value;"})));
	}

	end_block__1(emitter__->definitions__);
}

void mut emit_postamble__1(Emitter__0 mut ref const emitter__)
{
	end_block_with_semicolon__1(emitter__->type_id_declaration__);
	write_line__2(emitter__->type_id_declaration__, ((string){{29},(uint8_t*)u8"typedef enum Type_ID Type_ID;"}));
}

Expression__0 mut ref mut Expression__0__0new__0(Expression__0 mut ref const self) { self->type_id = Expression__0__0Type_ID; return self; }

Program_Fragment__0 const ref mut expression_as_program_fragment__1(Expression__0 const ref const expression__)
{
	return as_any__1(expression__);
}

Integer_Literal_Expression__0 mut ref mut Integer_Literal_Expression__0__0new__2(Integer_Literal_Expression__0 mut ref const self, Type__0 const ref const type__, Syntax_Node__0 const ref const node__)
{
	self->type_id = Integer_Literal_Expression__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(type__, none));
	assert__1(void_ptr__0op__not_equal(node__, none));
	assert__1(int32__0op__equal(node__->kind__, IntegerLiteralExpression__));
	self->syntax__ = syntax_node_as_syntax__1(node__);
	self->is_missing__ = node__->is_missing__;
	self->source__ = node__->source__;
	self->start__ = node__->start__;
	self->byte_length__ = node__->byte_length__;
	self->children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->diagnostics__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->type__ = type__;
	self->value__ = ((int32){0});
	return self;
}

Program_Fragment__0 const ref mut integer_literal_expression_as_program_fragment__1(Integer_Literal_Expression__0 const ref const expression__)
{
	return as_any__1(expression__);
}

Literal_Expression__0 mut ref mut Literal_Expression__0__0new__0(Literal_Expression__0 mut ref const self) { self->type_id = Literal_Expression__0__0Type_ID; return self; }

Expression__0 const ref mut literal_expression_as_expression__1(Literal_Expression__0 const ref const expression__)
{
	return as_any__1(expression__);
}

Negate_Expression__0 mut ref mut Negate_Expression__0__0new__0(Negate_Expression__0 mut ref const self) { self->type_id = Negate_Expression__0__0Type_ID; return self; }

Unary_Expression__0 const ref mut negate_expression_as_unary_expression__1(Negate_Expression__0 const ref const expression__)
{
	return as_any__1(expression__);
}

Unary_Expression__0 mut ref mut Unary_Expression__0__0new__0(Unary_Expression__0 mut ref const self) { self->type_id = Unary_Expression__0__0Type_ID; return self; }

Expression__0 const ref mut unary_expression_as_expression__1(Unary_Expression__0 const ref const expression__)
{
	return as_any__1(expression__);
}

Name__0 mut ref mut Name__0__0new__global_namespace__0(Name__0 mut ref const self)
{
	self->type_id = Name__0__0Type_ID;
	self->package__ = none;
	self->kind__ = NamespaceName__;
	self->segments__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	self->is_special__ = FALSE;
	return self;
}

Name__0 mut ref mut Name__0__0new__global_namespace__1(Name__0 mut ref const self, Package_Name__0 const ref const package__)
{
	self->type_id = Name__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(package__, none));
	self->package__ = package__;
	self->kind__ = NamespaceName__;
	self->segments__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	self->is_special__ = FALSE;
	return self;
}

Name__0 mut ref mut Name__0__0new__3(Name__0 mut ref const self, Name__0 const ref const qualifier__, int32 const kind__, string const name__)
{
	self->type_id = Name__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(qualifier__, none));
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	self->package__ = qualifier__->package__;
	self->kind__ = kind__;
	Strings__0 mut ref const segments__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	for (string__0iter mut iter = Strings__0__0iterate(qualifier__->segments__); string__0next(&iter);)
	{
		string const segment__ = string__0current(&iter);
		add_string__2(segments__, segment__);
	}

	add_string__2(segments__, name__);
	self->segments__ = segments__;
	self->is_special__ = FALSE;
	return self;
}

Name__0 mut ref mut Name__0__0new__4(Name__0 mut ref const self, Name__0 const ref const qualifier__, int32 const kind__, string const name__, BOOL const is_special__)
{
	self->type_id = Name__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(qualifier__, none));
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	self->package__ = qualifier__->package__;
	self->kind__ = kind__;
	Strings__0 mut ref const segments__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	for (string__0iter mut iter = Strings__0__0iterate(qualifier__->segments__); string__0next(&iter);)
	{
		string const segment__ = string__0current(&iter);
		add_string__2(segments__, segment__);
	}

	add_string__2(segments__, name__);
	self->segments__ = segments__;
	self->is_special__ = is_special__;
	return self;
}

Name__0 mut ref mut Name__0__0new__special__3(Name__0 mut ref const self, Name__0 const ref const qualifier__, int32 const kind__, string const name__)
{
	self->type_id = Name__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(qualifier__, none));
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	self->package__ = qualifier__->package__;
	self->kind__ = kind__;
	Strings__0 mut ref const segments__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	for (string__0iter mut iter = Strings__0__0iterate(qualifier__->segments__); string__0next(&iter);)
	{
		string const segment__ = string__0current(&iter);
		add_string__2(segments__, segment__);
	}

	add_string__2(segments__, name__);
	self->segments__ = segments__;
	self->is_special__ = TRUE;
	return self;
}

Name__0 mut ref mut Name__0__0new__exactly__4(Name__0 mut ref const self, Package_Name__0 const opt_ref const package__, int32 const kind__, Strings__0 const ref const segments__, BOOL const is_special__)
{
	self->type_id = Name__0__0Type_ID;
	self->package__ = package__;
	self->kind__ = kind__;
	self->segments__ = segments__;
	self->is_special__ = is_special__;
	return self;
}

string mut unqualified_name__1(Name__0 const ref const name__)
{
	if (cond(int32__0op__equal(name__->segments__->count__, ((int32){0}))))
	{
		return ((string){{0},(uint8_t*)u8""});
	}

	return Strings__0__0op__element(name__->segments__, int32__0op__sub(name__->segments__->count__, ((int32){1})));
}

string mut full_name__1(Name__0 const ref const name__)
{
	string mut result__ = ((string){{0},(uint8_t*)u8""});
	if (cond(void_ptr__0op__not_equal(name__->package__, none)))
	{
		result__ = full_package_name__1(name__->package__);
	}

	result__ = string__0op__add(result__, ((string){{2},(uint8_t*)u8"::"}));
	BOOL mut first__ = TRUE;
	for (string__0iter mut iter = Strings__0__0iterate(name__->segments__); string__0next(&iter);)
	{
		string const segment__ = string__0current(&iter);
		if (cond(first__))
		{
			first__ = FALSE;
			result__ = string__0op__add(result__, segment__);
			continue;
		}

		result__ = string__0op__add(string__0op__add(result__, ((string){{1},(uint8_t*)u8"."})), segment__);
	}

	return result__;
}

BOOL mut is_qualified_by__2(Name__0 const ref const name__, Name__0 const ref const qualifier__)
{
	if (cond(int32__0op__lte(name__->segments__->count__, qualifier__->segments__->count__)))
	{
		return FALSE;
	}

	if (cond(bool_op(bool_arg(void_ptr__0op__not_equal(name__->package__, none)) && bool_arg(void_ptr__0op__not_equal(qualifier__->package__, none)))))
	{
		string const full_package_name__ = full_package_name__1(name__->package__);
		if (cond(string__0op__not_equal(full_package_name__, full_package_name__1(qualifier__->package__))))
		{
			return FALSE;
		}
	}

	int32 mut i__ = ((int32){0});
	for (string__0iter mut iter = Strings__0__0iterate(qualifier__->segments__); string__0next(&iter);)
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

BOOL mut qualifier_is__2(Name__0 const ref const name__, Name__0 const ref const qualifier__)
{
	return bool_op(bool_arg(int32__0op__equal(int32__0op__add(((int32){1}), qualifier__->segments__->count__), name__->segments__->count__)) && bool_arg(is_qualified_by__2(name__, qualifier__)));
}

BOOL mut names__2(Name__0 const ref const name__, Name__0 const ref const other__)
{
	if (cond(int32__0op__not_equal(name__->segments__->count__, other__->segments__->count__)))
	{
		return FALSE;
	}

	if (cond(void_ptr__0op__not_equal(name__->package__, none)))
	{
		string const full_package_name__ = full_package_name__1(name__->package__);
		if (cond(bool_op(bool_arg(void_ptr__0op__equal(other__->package__, none)) || bool_arg(string__0op__not_equal(full_package_name__, full_package_name__1(other__->package__))))))
		{
			return FALSE;
		}
	}

	int32 mut i__ = ((int32){0});
	for (string__0iter mut iter = Strings__0__0iterate(other__->segments__); string__0next(&iter);)
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

BOOL mut is_package_qualified__1(Name__0 const ref const name__)
{
	return void_ptr__0op__not_equal(name__->package__, none);
}

Name__0 const ref mut remove_package__1(Name__0 const ref const name__)
{
	if (cond(void_ptr__0op__equal(name__->package__, none)))
	{
		return name__;
	}
	else
	{
		return Name__0__0new__exactly__4(allocate(sizeof(Name__0)), none, name__->kind__, name__->segments__, name__->is_special__);
	}
}

void mut unit_test_Name__0()
{
	name_with_unspecified_package_names_name_with_package__0();
	name_with_unspecified_package_names_itself__0();
}

void mut name_with_unspecified_package_names_name_with_package__0()
{
	Name__0 const ref const name_without_package__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__0(allocate(sizeof(Name__0))), NamespaceName__, ((string){{6},(uint8_t*)u8"system"}));
	Name__0 const ref const name_with_package__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__1(allocate(sizeof(Name__0)), Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){{7},(uint8_t*)u8"package"}))), NamespaceName__, ((string){{6},(uint8_t*)u8"system"}));
	assert__1(names__2(name_without_package__, name_with_package__));
}

void mut name_with_unspecified_package_names_itself__0()
{
	Name__0 const ref const name_without_package__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__0(allocate(sizeof(Name__0))), NamespaceName__, ((string){{6},(uint8_t*)u8"system"}));
	assert__1(names__2(name_without_package__, name_without_package__));
}

Package_Name__0 mut ref mut Package_Name__0__0new__1(Package_Name__0 mut ref const self, string const name__)
{
	self->type_id = Package_Name__0__0Type_ID;
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	self->unqualified__ = name__;
	return self;
}

string mut full_package_name__1(Package_Name__0 const ref const package_name__)
{
	return package_name__->unqualified__;
}

Symbol__0 mut ref mut Symbol__0__0new__identifier__1(Symbol__0 mut ref const self, string const name__)
{
	self->type_id = Symbol__0__0Type_ID;
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	self->name__ = name__;
	self->kind__ = IdentifierSymbol__;
	self->is_special_name__ = FALSE;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->declarations__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return self;
}

Symbol__0 mut ref mut Symbol__0__0new__identifier__2(Symbol__0 mut ref const self, string const name__, system__collections__List__1 const ref const children__)
{
	self->type_id = Symbol__0__0Type_ID;
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	assert__2(void_ptr__0op__not_equal(children__, none), string__0op__add(((string){{5},(uint8_t*)u8"name="}), name__));
	self->name__ = name__;
	self->kind__ = IdentifierSymbol__;
	self->is_special_name__ = FALSE;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->declarations__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->children__ = children__;
	return self;
}

Symbol__0 mut ref mut Symbol__0__0new__constructor__2(Symbol__0 mut ref const self, string const name__, system__collections__List__1 const ref const declarations__)
{
	self->type_id = Symbol__0__0Type_ID;
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	assert__2(void_ptr__0op__not_equal(declarations__, none), string__0op__add(((string){{5},(uint8_t*)u8"name="}), name__));
	self->name__ = name__;
	self->kind__ = IdentifierSymbol__;
	self->is_special_name__ = TRUE;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->declarations__ = declarations__;
	self->children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return self;
}

Symbol__0 mut ref mut Symbol__0__0new__package__2(Symbol__0 mut ref const self, string const name__, system__collections__List__1 const ref const children__)
{
	self->type_id = Symbol__0__0Type_ID;
	assert__1(int32__0op__gt(string_byte_length__1(name__), ((int32){0})));
	assert__2(void_ptr__0op__not_equal(children__, none), string__0op__add(((string){{5},(uint8_t*)u8"name="}), name__));
	self->name__ = name__;
	self->kind__ = PackageSymbol__;
	self->is_special_name__ = FALSE;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->declarations__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->children__ = children__;
	return self;
}

Symbol__0 mut ref mut Symbol__0__0new__declaring__3(Symbol__0 mut ref const self, Type__0 const ref const declares_type__, system__collections__List__1 const ref const declarations__, system__collections__List__1 const ref const children__)
{
	self->type_id = Symbol__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(declares_type__, none));
	assert__2(void_ptr__0op__not_equal(declarations__, none), string__0op__add(((string){{5},(uint8_t*)u8"name="}), unqualified_name__1(declares_type__->name__)));
	assert__2(void_ptr__0op__not_equal(children__, none), string__0op__add(((string){{5},(uint8_t*)u8"name="}), unqualified_name__1(declares_type__->name__)));
	self->name__ = unqualified_name__1(declares_type__->name__);
	self->kind__ = IdentifierSymbol__;
	self->is_special_name__ = declares_type__->name__->is_special__;
	self->of_type__ = none;
	self->declares_type__ = declares_type__;
	self->declarations__ = declarations__;
	self->children__ = children__;
	return self;
}

Symbol__0 mut ref mut Symbol__0__0new__of_type__4(Symbol__0 mut ref const self, string const name__, Type__0 const ref const of_type__, system__collections__List__1 const ref const declarations__, system__collections__List__1 const ref const children__)
{
	self->type_id = Symbol__0__0Type_ID;
	assert__2(void_ptr__0op__not_equal(of_type__, none), string__0op__add(((string){{5},(uint8_t*)u8"name="}), name__));
	assert__2(void_ptr__0op__not_equal(declarations__, none), string__0op__add(((string){{5},(uint8_t*)u8"name="}), name__));
	assert__2(void_ptr__0op__not_equal(children__, none), string__0op__add(((string){{5},(uint8_t*)u8"name="}), name__));
	self->name__ = name__;
	self->kind__ = IdentifierSymbol__;
	self->is_special_name__ = FALSE;
	self->of_type__ = of_type__;
	self->declares_type__ = none;
	self->declarations__ = declarations__;
	self->children__ = children__;
	return self;
}

Symbol__0 const opt_ref mut get_child_symbol__3(Symbol__0 const ref const symbol__, string const name__, int32 const kind__)
{
	assert__1(void_ptr__0op__not_equal(symbol__, none));
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(symbol__->children__); void_ptr__0next(&iter);)
	{
		Symbol__0 const ref const child__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(string__0op__equal(child__->name__, name__)) && bool_arg(int32__0op__equal(child__->kind__, kind__)))))
		{
			return child__;
		}
	}

	return none;
}

void mut unit_test_Symbol__0()
{
	Package_symbol_children_can_be_found_by_name_and_kind__0();
}

void mut Package_symbol_children_can_be_found_by_name_and_kind__0()
{
	system__collections__List__1 mut ref const children__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(children__, Symbol__0__0new__identifier__1(allocate(sizeof(Symbol__0)), ((string){{5},(uint8_t*)u8"child"})));
	Symbol__0 const ref const package_with_children__ = Symbol__0__0new__package__2(allocate(sizeof(Symbol__0)), ((string){{7},(uint8_t*)u8"package"}), children__);
	assert__1(never__0op__not_equal(get_child_symbol__3(package_with_children__, ((string){{5},(uint8_t*)u8"child"}), IdentifierSymbol__), none));
}

Type__0 mut ref mut Type__0__0new__3(Type__0 mut ref const self, int32 const kind__, Name__0 const ref const name__, BOOL const is_mutable__)
{
	self->type_id = Type__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(name__, none));
	self->kind__ = kind__;
	self->name__ = name__;
	self->type_parameters__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->is_primitive__ = FALSE;
	self->is_value_type__ = int32__0op__equal(kind__, ValueType__);
	self->is_potentially_mutable__ = is_mutable__;
	self->is_mutable__ = is_mutable__;
	return self;
}

Type__0 mut ref mut Type__0__0new__parameter__1(Type__0 mut ref const self, string const name__)
{
	self->type_id = Type__0__0Type_ID;
	self->kind__ = TypeParameterType__;
	self->name__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__0(allocate(sizeof(Name__0))), TypeParameterName__, name__);
	self->type_parameters__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->is_primitive__ = FALSE;
	self->is_value_type__ = FALSE;
	self->is_potentially_mutable__ = TRUE;
	self->is_mutable__ = FALSE;
	return self;
}

Type__0 mut ref mut Type__0__0new__4(Type__0 mut ref const self, int32 const kind__, Name__0 const ref const name__, system__collections__List__1 const ref const type_parameters__, BOOL const is_mutable__)
{
	self->type_id = Type__0__0Type_ID;
	self->kind__ = kind__;
	self->name__ = name__;
	self->type_parameters__ = type_parameters__;
	self->is_primitive__ = FALSE;
	self->is_value_type__ = int32__0op__equal(kind__, ValueType__);
	self->is_potentially_mutable__ = is_mutable__;
	self->is_mutable__ = is_mutable__;
	return self;
}

Type__0 mut ref mut Type__0__0new__primitive__1(Type__0 mut ref const self, Name__0 const ref const name__)
{
	self->type_id = Type__0__0Type_ID;
	self->kind__ = ValueType__;
	self->name__ = name__;
	self->type_parameters__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->is_primitive__ = TRUE;
	self->is_value_type__ = TRUE;
	self->is_potentially_mutable__ = FALSE;
	self->is_mutable__ = FALSE;
	return self;
}

Type__0 mut ref mut Type__0__0new__primitive__2(Type__0 mut ref const self, Name__0 const ref const name__, system__collections__List__1 const ref const type_parameters__)
{
	self->type_id = Type__0__0Type_ID;
	self->kind__ = ValueType__;
	self->name__ = name__;
	self->type_parameters__ = type_parameters__;
	self->is_primitive__ = TRUE;
	self->is_value_type__ = TRUE;
	self->is_potentially_mutable__ = FALSE;
	self->is_mutable__ = FALSE;
	return self;
}

Type__0 mut ref mut Type__0__0new__namespace__1(Type__0 mut ref const self, Name__0 const ref const name__)
{
	self->type_id = Type__0__0Type_ID;
	self->kind__ = NamespaceType__;
	self->name__ = name__;
	self->is_primitive__ = FALSE;
	self->type_parameters__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	self->is_value_type__ = TRUE;
	self->is_potentially_mutable__ = FALSE;
	self->is_mutable__ = FALSE;
	return self;
}

Type__0 mut ref mut Type__0__0new__generic__2(Type__0 mut ref const self, Type__0 const ref const definition__, system__collections__List__1 const ref const type_arguments__)
{
	self->type_id = Type__0__0Type_ID;
	assert__1(void_ptr__0op__not_equal(definition__, none));
	assert__2(void_ptr__0op__not_equal(type_arguments__, none), full_name__1(definition__->name__));
	assert__2(int32__0op__equal(definition__->type_parameters__->count__, type_arguments__->count__), string__0op__add(string__0op__add(string__0op__add(string__0op__add(full_name__1(definition__->name__), ((string){{1},(uint8_t*)u8" "})), int_to_string__1(definition__->type_parameters__->count__)), ((string){{7},(uint8_t*)u8" given "})), int_to_string__1(type_arguments__->count__)));
	self->kind__ = definition__->kind__;
	self->name__ = definition__->name__;
	self->type_parameters__ = type_arguments__;
	self->is_primitive__ = definition__->is_primitive__;
	self->is_value_type__ = definition__->is_value_type__;
	self->is_potentially_mutable__ = definition__->is_potentially_mutable__;
	self->is_mutable__ = definition__->is_mutable__;
	return self;
}

Type__0 mut ref mut Type__0__0new__6(Type__0 mut ref const self, int32 const kind__, Name__0 const ref const name__, system__collections__List__1 const ref const type_parameters__, BOOL const is_primitive__, BOOL const is_potentially_mutable__, BOOL const is_mutable__)
{
	self->type_id = Type__0__0Type_ID;
	self->kind__ = kind__;
	self->name__ = name__;
	self->type_parameters__ = type_parameters__;
	self->is_primitive__ = is_primitive__;
	self->is_value_type__ = int32__0op__equal(kind__, ValueType__);
	self->is_potentially_mutable__ = is_potentially_mutable__;
	self->is_mutable__ = is_mutable__;
	return self;
}

Type__0 const ref mut make_mutable_type__1(Type__0 const ref const type__)
{
	assert__2(type__->is_potentially_mutable__, string__0op__add(((string){{10},(uint8_t*)u8"self.name="}), full_name__1(type__->name__)));
	return Type__0__0new__6(allocate(sizeof(Type__0)), type__->kind__, type__->name__, type__->type_parameters__, type__->is_primitive__, type__->is_potentially_mutable__, TRUE);
}

Type__0 const ref mut make_immutable_type__1(Type__0 const ref const type__)
{
	return Type__0__0new__6(allocate(sizeof(Type__0)), type__->kind__, type__->name__, type__->type_parameters__, type__->is_primitive__, type__->is_potentially_mutable__, FALSE);
}

Type__0 const ref mut remove_type_package__1(Type__0 const ref const type__)
{
	assert__2(int32__0op__equal(type__->kind__, NamespaceType__), string__0op__add(((string){{5},(uint8_t*)u8"kind="}), int_to_string__1(type__->kind__)));
	if (cond(is_package_qualified__1(type__->name__)))
	{
		return Type__0__0new__6(allocate(sizeof(Type__0)), type__->kind__, remove_package__1(type__->name__), type__->type_parameters__, type__->is_primitive__, type__->is_potentially_mutable__, type__->is_mutable__);
	}
	else
	{
		return type__;
	}
}

Name_Subtable__0 mut ref mut Name_Subtable__0__0new__global_namespace__1(Name_Subtable__0 mut ref const self, Name_Table__0 const ref const name_table__)
{
	self->type_id = Name_Subtable__0__0Type_ID;
	self->name_table__ = name_table__;
	self->parent__ = none;
	self->name__ = Name__0__0new__global_namespace__0(allocate(sizeof(Name__0)));
	self->type__ = Type__0__0new__namespace__1(allocate(sizeof(Type__0)), self->name__);
	self->subtables__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return self;
}

Name_Subtable__0 mut ref mut Name_Subtable__0__0new__global_namespace__2(Name_Subtable__0 mut ref const self, Name_Table__0 const ref const name_table__, Package_Name__0 const ref const package_name__)
{
	self->type_id = Name_Subtable__0__0Type_ID;
	self->name_table__ = name_table__;
	self->parent__ = none;
	self->name__ = Name__0__0new__global_namespace__1(allocate(sizeof(Name__0)), package_name__);
	self->type__ = Type__0__0new__namespace__1(allocate(sizeof(Type__0)), self->name__);
	self->subtables__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return self;
}

Name_Subtable__0 mut ref mut Name_Subtable__0__0new__3(Name_Subtable__0 mut ref const self, Name_Subtable__0 const ref const parent__, Name__0 const ref const name__, Type__0 const ref const type__)
{
	self->type_id = Name_Subtable__0__0Type_ID;
	self->name_table__ = parent__->name_table__;
	self->parent__ = parent__;
	self->name__ = name__;
	self->type__ = type__;
	self->subtables__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return self;
}

void mut add_subtable__3(Name_Subtable__0 mut ref const scope__, Name__0 const ref const name__, Type__0 const opt_ref const type__)
{
	assert__2(is_qualified_by__2(name__, scope__->name__), string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){{1},(uint8_t*)u8"\""}), full_name__1(name__)), ((string){{21},(uint8_t*)u8"\" is not a child of \""})), full_name__1(scope__->name__)), ((string){{1},(uint8_t*)u8"\""})));
	if (cond(qualifier_is__2(name__, scope__->name__)))
	{
		if (cond(bool_op(bool_arg(bool_op(bool_arg(void_ptr__0op__equal(scope__->name__->package__, none)) && bool_arg(void_ptr__0op__not_equal(type__, none)))) && bool_arg(int32__0op__equal(type__->kind__, NamespaceType__)))))
		{
			add_item__2(scope__->subtables__, Name_Subtable__0__0new__3(allocate(sizeof(Name_Subtable__0)), scope__, remove_package__1(name__), remove_type_package__1(type__)));
		}
		else
		{
			add_item__2(scope__->subtables__, Name_Subtable__0__0new__3(allocate(sizeof(Name_Subtable__0)), scope__, name__, type__));
		}

		return;
	}

	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(scope__->subtables__); void_ptr__0next(&iter);)
	{
		Name_Subtable__0 mut ref const subtable__ = void_ptr__0current(&iter);
		if (cond(is_qualified_by__2(name__, subtable__->name__)))
		{
			add_subtable__3(subtable__, name__, type__);
			return;
		}
	}

	assert__2(int32__0op__equal(name__->segments__->count__, int32__0op__add(((int32){1}), scope__->name__->segments__->count__)), string__0op__add(string__0op__add(string__0op__add(string__0op__add(((string){{11},(uint8_t*)u8"Can't add \""}), full_name__1(name__)), ((string){{6},(uint8_t*)u8"\" to \""})), full_name__1(scope__->name__)), ((string){{1},(uint8_t*)u8"\""})));
}

Name_Subtable__0 mut opt_ref mut find__2(Name_Subtable__0 const ref const scope__, string const name__)
{
	return find__3(scope__, name__, FALSE);
}

Name_Subtable__0 mut opt_ref mut find_special__2(Name_Subtable__0 const ref const scope__, string const name__)
{
	return find__3(scope__, name__, TRUE);
}

Name_Subtable__0 mut opt_ref mut find__3(Name_Subtable__0 const ref const scope__, string const name__, BOOL const is_special__)
{
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(scope__->subtables__); void_ptr__0next(&iter);)
	{
		Name_Subtable__0 mut ref const subtable__ = void_ptr__0current(&iter);
		if (cond(bool_op(bool_arg(string__0op__equal(unqualified_name__1(subtable__->name__), name__)) && bool_arg(BOOL__0op__equal(subtable__->name__->is_special__, is_special__)))))
		{
			return subtable__;
		}
	}

	return none;
}

Name_Subtable__0 mut opt_ref mut lookup__2(Name_Subtable__0 const ref const scope__, string const name__)
{
	return lookup__3(scope__, name__, FALSE);
}

Name_Subtable__0 mut opt_ref mut lookup_special__2(Name_Subtable__0 const ref const scope__, string const name__)
{
	return lookup__3(scope__, name__, TRUE);
}

Name_Subtable__0 mut opt_ref mut lookup__3(Name_Subtable__0 const ref const scope__, string const name__, BOOL const is_special__)
{
	Name_Subtable__0 mut opt_ref mut subtable__ = find__3(scope__, name__, is_special__);
	if (cond(bool_op(bool_arg(void_ptr__0op__equal(subtable__, none)) && bool_arg(void_ptr__0op__not_equal(scope__->parent__, none)))))
	{
		subtable__ = lookup__3(scope__->parent__, name__, is_special__);
	}

	return subtable__;
}

Name_Subtable__0 const opt_ref mut get_scope__2(Name_Subtable__0 const ref const scope__, Name__0 const ref const name__)
{
	if (cond(names__2(name__, scope__->name__)))
	{
		return scope__;
	}
	else if (cond(BOOL__0op__not(is_qualified_by__2(name__, scope__->name__))))
	{
		return none;
	}

	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(scope__->subtables__); void_ptr__0next(&iter);)
	{
		Name_Subtable__0 const ref const subtable__ = void_ptr__0current(&iter);
		Name_Subtable__0 const opt_ref const value__ = get_scope__2(subtable__, name__);
		if (cond(void_ptr__0op__not_equal(value__, none)))
		{
			return value__;
		}
	}

	return none;
}

void mut bind_type__2(Name_Subtable__0 mut ref const scope__, Type__0 const ref const type__)
{
	assert__2(void_ptr__0op__not_equal(type__, none), full_name__1(scope__->name__));
	if (cond(void_ptr__0op__not_equal(scope__->type__, none)))
	{
		string const scope_type_name__ = full_name__1(scope__->type__->name__);
		assert__2(string__0op__equal(scope_type_name__, full_name__1(type__->name__)), string__0op__add(string__0op__add(string__0op__add(string__0op__add(string__0op__add(full_name__1(scope__->name__), ((string){{12},(uint8_t*)u8" currently `"})), scope_type_name__), ((string){{20},(uint8_t*)u8"` trying to set to `"})), full_name__1(type__->name__)), ((string){{1},(uint8_t*)u8"`"})));
	}

	scope__->type__ = type__;
}

Name_Subtable__0 mut ref mut as_mut__1(Name_Subtable__0 const ref const scope__)
{
	return find__3(scope__->parent__, unqualified_name__1(scope__->name__), scope__->name__->is_special__);
}

void mut unit_test_Name_Subtable__0()
{
	global_namespace_contains_added_name__0();
	namespace_contains_added_name__0();
}

void mut global_namespace_contains_added_name__0()
{
	Name_Table__0 const ref const name_table__ = Name_Table__0__0new__0(allocate(sizeof(Name_Table__0)));
	Name_Subtable__0 mut ref const global_namespace__ = Name_Subtable__0__0new__global_namespace__1(allocate(sizeof(Name_Subtable__0)), name_table__);
	Name__0 const ref const test_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__->name__, TypeName__, ((string){{4},(uint8_t*)u8"test"}));
	add_subtable__3(global_namespace__, test_name__, none);
	assert__1(never__0op__not_equal(find__2(global_namespace__, ((string){{4},(uint8_t*)u8"test"})), none));
	assert__1(never__0op__not_equal(get_scope__2(global_namespace__, test_name__), none));
}

void mut namespace_contains_added_name__0()
{
	Name_Table__0 const ref const name_table__ = Name_Table__0__0new__0(allocate(sizeof(Name_Table__0)));
	Name_Subtable__0 mut ref const global_namespace__ = Name_Subtable__0__0new__global_namespace__1(allocate(sizeof(Name_Subtable__0)), name_table__);
	Name__0 const ref const namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), global_namespace__->name__, NamespaceName__, ((string){{9},(uint8_t*)u8"namespace"}));
	add_subtable__3(global_namespace__, namespace_name__, none);
	add_subtable__3(global_namespace__, Name__0__0new__3(allocate(sizeof(Name__0)), namespace_name__, TypeName__, ((string){{4},(uint8_t*)u8"test"})), none);
	Name_Subtable__0 const ref const namespace__ = find__2(global_namespace__, ((string){{9},(uint8_t*)u8"namespace"}));
	assert__1(never__0op__not_equal(find__2(namespace__, ((string){{4},(uint8_t*)u8"test"})), none));
}

Name_Table__0 mut ref mut Name_Table__0__0new__0(Name_Table__0 mut ref const self)
{
	self->type_id = Name_Table__0__0Type_ID;
	self->any_package__ = Name_Subtable__0__0new__global_namespace__1(allocate(sizeof(Name_Subtable__0)), self);
	self->packages__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	return self;
}

Name__0 const ref mut add_package__2(Name_Table__0 mut ref const name_table__, Package_Name__0 const ref const package_name__)
{
	Name_Subtable__0 mut ref const subtable__ = Name_Subtable__0__0new__global_namespace__2(allocate(sizeof(Name_Subtable__0)), name_table__, package_name__);
	add_item__2(name_table__->packages__, subtable__);
	return subtable__->name__;
}

Name__0 const ref mut add_symbol_name__3(Name_Table__0 mut ref const name_table__, Name__0 const ref const parent__, Symbol__0 const ref const symbol__)
{
	Name__0 const ref mut name__;
	if (cond(void_ptr__0op__not_equal(symbol__->declares_type__, none)))
	{
		name__ = Name__0__0new__4(allocate(sizeof(Name__0)), parent__, TypeName__, symbol__->name__, symbol__->is_special_name__);
		add_type_name__3(name_table__, name__, symbol__->declares_type__);
	}
	else
	{
		name__ = Name__0__0new__4(allocate(sizeof(Name__0)), parent__, FunctionName__, symbol__->name__, symbol__->is_special_name__);
		add_type_name__3(name_table__, name__, symbol__->of_type__);
	}

	return name__;
}

void mut add_type_name__3(Name_Table__0 mut ref const name_table__, Name__0 const ref const name__, Type__0 const opt_ref const type__)
{
	add_subtable__3(name_table__->any_package__, name__, type__);
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(name_table__->packages__); void_ptr__0next(&iter);)
	{
		Name_Subtable__0 mut ref const package__ = void_ptr__0current(&iter);
		if (cond(is_qualified_by__2(name__, package__->name__)))
		{
			add_subtable__3(package__, name__, type__);
			return;
		}
	}

	assert__2(FALSE, string__0op__add(string__0op__add(((string){{16},(uint8_t*)u8"Can't add name \""}), full_name__1(name__)), ((string){{41},(uint8_t*)u8"\" because package doesn't exist in table."})));
}

Name_Subtable__0 const opt_ref mut get_name__2(Name_Table__0 const ref const name_table__, Name__0 const ref const name__)
{
	if (cond(void_ptr__0op__equal(name__->package__, none)))
	{
		return get_scope__2(name_table__->any_package__, name__);
	}

	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(name_table__->packages__); void_ptr__0next(&iter);)
	{
		Name_Subtable__0 const ref const package__ = void_ptr__0current(&iter);
		if (cond(is_qualified_by__2(name__, package__->name__)))
		{
			return get_scope__2(package__, name__);
		}
	}

	return none;
}

Name_Table__0 const ref mut build_name_table__3(Package_Name__0 const ref const package_name__, Syntax_Node__0 const ref const package_syntax__, system__collections__List__1 const ref const references__)
{
	assert__2(int32__0op__equal(package_syntax__->kind__, PackageNode__), string__0op__add(((string){{20},(uint8_t*)u8"package_syntax.kind="}), int_to_string__1(package_syntax__->kind__)));
	Name_Table__0 mut ref const name_table__ = Name_Table__0__0new__0(allocate(sizeof(Name_Table__0)));
	add_referenced__2(name_table__, references__);
	add_package__3(name_table__, package_name__, package_syntax__);
	return name_table__;
}

void mut add_referenced__2(Name_Table__0 mut ref const name_table__, system__collections__List__1 const ref const references__)
{
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(references__); void_ptr__0next(&iter);)
	{
		Package_Reference__0 const ref const reference__ = void_ptr__0current(&iter);
		Package_Name__0 const ref const reference_name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), reference__->name__);
		Name__0 const ref const global_namespace__ = add_package__2(name_table__, reference_name__);
		for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(reference__->package__->symbol__->children__); void_ptr__0next(&iter);)
		{
			Symbol__0 const ref const symbol__ = void_ptr__0current(&iter);
			add_symbol__3(name_table__, global_namespace__, symbol__);
		}
	}
}

void mut add_symbol__3(Name_Table__0 mut ref const name_table__, Name__0 const ref const parent__, Symbol__0 const ref const symbol__)
{
	Name__0 const ref const name__ = add_symbol_name__3(name_table__, parent__, symbol__);
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(symbol__->children__); void_ptr__0next(&iter);)
	{
		Symbol__0 const ref const child__ = void_ptr__0current(&iter);
		add_symbol__3(name_table__, name__, child__);
	}
}

void mut add_package__3(Name_Table__0 mut ref const name_table__, Package_Name__0 const ref const package_name__, Syntax_Node__0 const ref const package_syntax__)
{
	assert__2(int32__0op__equal(package_syntax__->kind__, PackageNode__), string__0op__add(((string){{20},(uint8_t*)u8"package_syntax.kind="}), int_to_string__1(package_syntax__->kind__)));
	Name__0 const ref const global_namespace__ = add_package__2(name_table__, package_name__);
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(package_syntax__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const ref const compilation_unit__ = void_ptr__0current(&iter);
		add_compilation_unit__3(name_table__, global_namespace__, compilation_unit__);
	}
}

void mut add_compilation_unit__3(Name_Table__0 mut ref const name_table__, Name__0 const ref const global_namespace__, Syntax_Node__0 const ref const compilation_unit__)
{
	assert__2(int32__0op__equal(compilation_unit__->kind__, CompilationUnit__), string__0op__add(((string){{22},(uint8_t*)u8"compilation_unit.kind="}), int_to_string__1(compilation_unit__->kind__)));
	for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(compilation_unit__->children__); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const ref const declaration__ = void_ptr__0current(&iter);
		add_syntax__3(name_table__, global_namespace__, declaration__);
	}
}

void mut add_syntax__3(Name_Table__0 mut ref const name_table__, Name__0 const ref const parent__, Syntax_Node__0 const ref const syntax__)
{
	if (cond(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, FunctionDeclaration__)) || bool_arg(int32__0op__equal(syntax__->kind__, MethodDeclaration__)))))
	{
		Name__0 const ref const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, FunctionName__, get_token_text__1(first_child_token__2(syntax__, Identifier__)));
		add_function__3(name_table__, name__, syntax__);
	}
	else if (cond(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, ClassDeclaration__)) || bool_arg(int32__0op__equal(syntax__->kind__, StructDeclaration__)))))
	{
		string const unqualified_name__ = get_token_text__1(first_child_token__2(syntax__, Identifier__));
		int32 mut type_kind__;
		if (cond(int32__0op__equal(syntax__->kind__, ClassDeclaration__)))
		{
			type_kind__ = ReferenceType__;
		}
		else
		{
			type_kind__ = ValueType__;
		}

		Name__0 const ref const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, TypeName__, unqualified_name__);
		Type__0 const ref const type__ = Type__0__0new__3(allocate(sizeof(Type__0)), type_kind__, name__, TRUE);
		add_type_name__3(name_table__, name__, type__);
		for (void_ptr__0iter mut iter = void_ptr__0iterate(members__1(syntax__)); void_ptr__0next(&iter);)
		{
			Syntax_Node__0 const ref const member__ = void_ptr__0current(&iter);
			add_syntax__3(name_table__, name__, member__);
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ConstructorDeclaration__)))
	{
		string mut full_name__ = ((string){{3},(uint8_t*)u8"new"});
		Token__0 const opt_ref const constructor_name__ = first_child_token__2(syntax__, Identifier__);
		if (cond(void_ptr__0op__not_equal(constructor_name__, none)))
		{
			full_name__ = string__0op__add(((string){{4},(uint8_t*)u8"new_"}), get_token_text__1(constructor_name__));
		}

		Name__0 const ref const name__ = Name__0__0new__special__3(allocate(sizeof(Name__0)), parent__, FunctionName__, full_name__);
		add_function__3(name_table__, name__, syntax__);
		Name__0 const ref const self_name__ = Name__0__0new__special__3(allocate(sizeof(Name__0)), name__, VariableName__, ((string){{4},(uint8_t*)u8"self"}));
		Type__0 const ref const self_type__ = get_name__2(name_table__, parent__)->type__;
		assert__1(void_ptr__0op__not_equal(self_type__, none));
		add_type_name__3(name_table__, self_name__, self_type__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, FieldDeclaration__)))
	{
		string const unqualified_name__ = get_token_text__1(first_child_token__2(first_child_syntax_node__2(syntax__, VariableDeclaration__), Identifier__));
		Name__0 const ref const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, TypeName__, unqualified_name__);
		Type__0 const opt_ref const no_type__ = none;
		add_type_name__3(name_table__, name__, no_type__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, EnumDeclaration__)))
	{
		string const unqualified_name__ = get_token_text__1(first_child_token__2(syntax__, Identifier__));
		Name__0 const ref const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, TypeName__, unqualified_name__);
		Type__0 const ref const type__ = Type__0__0new__3(allocate(sizeof(Type__0)), ReferenceType__, name__, TRUE);
		add_type_name__3(name_table__, name__, type__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, GlobalDeclaration__)))
	{
		string const unqualified_name__ = get_token_text__1(first_child_token__2(first_child_syntax_node__2(syntax__, VariableDeclaration__), Identifier__));
		Name__0 const ref const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, TypeName__, unqualified_name__);
		Type__0 const opt_ref const no_type__ = none;
		add_type_name__3(name_table__, name__, no_type__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, Block__)))
	{
		for (void_ptr__0iter mut iter = void_ptr__0iterate(statements__1(syntax__)); void_ptr__0next(&iter);)
		{
			Syntax_Node__0 const ref const statement__ = void_ptr__0current(&iter);
			add_syntax__3(name_table__, parent__, statement__);
		}
	}
	else if (cond(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, LoopStatement__)) || bool_arg(int32__0op__equal(syntax__->kind__, WhileStatement__)))) || bool_arg(int32__0op__equal(syntax__->kind__, DoWhileStatement__)))))
	{
		add_syntax__3(name_table__, parent__, first_child_syntax_node__2(syntax__, Block__));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ForStatement__)))
	{
		Token__0 const ref const identifier__ = first_child_token__2(first_child_syntax_node__2(syntax__, VariableDeclaration__), Identifier__);
		Name__0 const ref const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, VariableName__, get_token_text__1(identifier__));
		Type__0 const opt_ref const no_type__ = none;
		add_type_name__3(name_table__, name__, no_type__);
		add_syntax__3(name_table__, parent__, first_child_syntax_node__2(syntax__, Block__));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, IfStatement__)))
	{
		add_syntax__3(name_table__, parent__, first_child_syntax_node__2(syntax__, Block__));
		Syntax_Node__0 const opt_ref const else_clause__ = first_child_syntax_node__2(syntax__, ElseClause__);
		if (cond(void_ptr__0op__not_equal(else_clause__, none)))
		{
			add_syntax__3(name_table__, parent__, else_clause__);
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, MatchStatement__)))
	{
		for (void_ptr__0iter mut iter = system__collections__List__1__0iterate(syntax__->children__); void_ptr__0next(&iter);)
		{
			Syntax_Node__0 const ref const child__ = void_ptr__0current(&iter);
			if (cond(int32__0op__equal(child__->kind__, MatchArm__)))
			{
				add_syntax__3(name_table__, parent__, child__);
			}
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, MatchArm__)))
	{
		Token__0 const ref const identifier__ = first_child_token__2(first_child_syntax_node__2(syntax__, MatchPattern__), Identifier__);
		Name__0 const ref const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, VariableName__, get_token_text__1(identifier__));
		Type__0 const opt_ref const no_type__ = none;
		add_type_name__3(name_table__, name__, no_type__);
		add_syntax__3(name_table__, parent__, first_child_syntax_node__2(syntax__, Block__));
	}
	else if (cond(int32__0op__equal(syntax__->kind__, ElseClause__)))
	{
		Syntax_Node__0 const opt_ref const block__ = first_child_syntax_node__2(syntax__, Block__);
		if (cond(void_ptr__0op__not_equal(block__, none)))
		{
			add_syntax__3(name_table__, parent__, block__);
		}
		else
		{
			add_syntax__3(name_table__, parent__, first_child_syntax_node__2(syntax__, IfStatement__));
		}
	}
	else if (cond(int32__0op__equal(syntax__->kind__, LocalDeclarationStatement__)))
	{
		Token__0 const ref const identifier__ = first_child_token__2(first_child_syntax_node__2(syntax__, VariableDeclaration__), Identifier__);
		Name__0 const ref const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, VariableName__, get_token_text__1(identifier__));
		Type__0 const opt_ref const no_type__ = none;
		add_type_name__3(name_table__, name__, no_type__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, Parameter__)))
	{
		Token__0 const ref const identifier__ = first_child_token__2(syntax__, Identifier__);
		Name__0 const ref const name__ = Name__0__0new__3(allocate(sizeof(Name__0)), parent__, VariableName__, get_token_text__1(identifier__));
		Type__0 const opt_ref const no_type__ = none;
		add_type_name__3(name_table__, name__, no_type__);
	}
	else if (cond(int32__0op__equal(syntax__->kind__, SelfParameter__)))
	{
		Name__0 const ref const name__ = Name__0__0new__special__3(allocate(sizeof(Name__0)), parent__, VariableName__, ((string){{4},(uint8_t*)u8"self"}));
		Type__0 const ref const self_type__ = get_name__2(name_table__, parent__)->parent__->type__;
		assert__1(void_ptr__0op__not_equal(self_type__, none));
		add_type_name__3(name_table__, name__, self_type__);
	}
	else if (cond(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(bool_op(bool_arg(int32__0op__equal(syntax__->kind__, ExpressionStatement__)) || bool_arg(int32__0op__equal(syntax__->kind__, ReturnStatement__)))) || bool_arg(int32__0op__equal(syntax__->kind__, BreakStatement__)))) || bool_arg(int32__0op__equal(syntax__->kind__, ContinueStatement__)))) || bool_arg(int32__0op__equal(syntax__->kind__, EndOfFile__)))))
	{
	}
	else
	{
		NOT_IMPLEMENTED__1(string__0op__add(((string){{12},(uint8_t*)u8"syntax.kind="}), int_to_string__1(syntax__->kind__)));
	}
}

void mut add_function__3(Name_Table__0 mut ref const name_table__, Name__0 const ref const name__, Syntax_Node__0 const ref const function__)
{
	Type__0 const opt_ref const no_type__ = none;
	add_type_name__3(name_table__, name__, no_type__);
	Syntax_Node__0 const ref const parameters_syntax__ = first_child_syntax_node__2(function__, ParameterList__);
	for (void_ptr__0iter mut iter = void_ptr__0iterate(parameters__1(parameters_syntax__)); void_ptr__0next(&iter);)
	{
		Syntax_Node__0 const ref const parameter__ = void_ptr__0current(&iter);
		add_syntax__3(name_table__, name__, parameter__);
	}

	Syntax_Node__0 const ref const body__ = first_child_syntax_node__2(function__, Block__);
	add_syntax__3(name_table__, name__, body__);
}

void mut unit_test_Name_Table_Builder__0()
{
	table_contains_referenced_child_names__0();
	can_get_root_namespace_from_name__0();
	can_get_Console_class_from_name_without_package__0();
	can_get_Optional_class_from_name_with_package__0();
}

void mut table_contains_referenced_child_names__0()
{
	Package_Name__0 const ref const name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){{7},(uint8_t*)u8"default"}));
	Package__0 const ref const runtime_package__ = build_runtime_library_package__0();
	system__collections__List__1 mut ref const references__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(references__, Package_Reference__0__0new__1(allocate(sizeof(Package_Reference__0)), runtime_package__));
	Source_Text__0 const ref const source__ = Source_Text__0__0new__3(allocate(sizeof(Source_Text__0)), name__->unqualified__, ((string){{9},(uint8_t*)u8"//test.ad"}), ((string){{19},(uint8_t*)u8"// test source text"}));
	Syntax_Node__0 const ref const package_syntax__ = Syntax_Node__0__0new__4(allocate(sizeof(Syntax_Node__0)), PackageNode__, source__, ((int32){0}), ((int32){0}));
	Name_Table__0 const ref const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Name_Subtable__0 const ref const namespace__ = find__2(name_table__->any_package__, ((string){{6},(uint8_t*)u8"system"}));
	assert__1(never__0op__not_equal(find__2(namespace__, ((string){{7},(uint8_t*)u8"console"})), none));
	Name__0 const ref const system_namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__0(allocate(sizeof(Name__0))), NamespaceName__, ((string){{6},(uint8_t*)u8"system"}));
	assert__1(never__0op__not_equal(get_name__2(name_table__, system_namespace_name__), none));
	Name__0 const ref const console_namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), system_namespace_name__, NamespaceName__, ((string){{7},(uint8_t*)u8"console"}));
	assert__1(never__0op__not_equal(get_name__2(name_table__, console_namespace_name__), none));
	Name__0 const ref const console_class_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), console_namespace_name__, TypeName__, ((string){{7},(uint8_t*)u8"Console"}));
	assert__1(never__0op__not_equal(get_name__2(name_table__, console_class_name__), none));
}

void mut can_get_root_namespace_from_name__0()
{
	Package_Name__0 const ref const name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){{7},(uint8_t*)u8"default"}));
	Package__0 const ref const runtime_package__ = build_runtime_library_package__0();
	system__collections__List__1 mut ref const references__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(references__, Package_Reference__0__0new__1(allocate(sizeof(Package_Reference__0)), runtime_package__));
	Source_Text__0 const ref const source__ = Source_Text__0__0new__3(allocate(sizeof(Source_Text__0)), name__->unqualified__, ((string){{9},(uint8_t*)u8"//test.ad"}), ((string){{19},(uint8_t*)u8"// test source text"}));
	Syntax_Node__0 const ref const package_syntax__ = Syntax_Node__0__0new__4(allocate(sizeof(Syntax_Node__0)), PackageNode__, source__, ((int32){0}), ((int32){0}));
	Name_Table__0 const ref const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Name__0 const ref const namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__0(allocate(sizeof(Name__0))), NamespaceName__, ((string){{6},(uint8_t*)u8"system"}));
	assert__1(never__0op__not_equal(get_name__2(name_table__, namespace_name__), none));
}

void mut can_get_Console_class_from_name_without_package__0()
{
	Package_Name__0 const ref const name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){{7},(uint8_t*)u8"default"}));
	Package__0 const ref const runtime_package__ = build_runtime_library_package__0();
	system__collections__List__1 mut ref const references__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(references__, Package_Reference__0__0new__1(allocate(sizeof(Package_Reference__0)), runtime_package__));
	Source_Text__0 const ref const source__ = Source_Text__0__0new__3(allocate(sizeof(Source_Text__0)), name__->unqualified__, ((string){{9},(uint8_t*)u8"//test.ad"}), ((string){{19},(uint8_t*)u8"// test source text"}));
	Syntax_Node__0 const ref const package_syntax__ = Syntax_Node__0__0new__4(allocate(sizeof(Syntax_Node__0)), PackageNode__, source__, ((int32){0}), ((int32){0}));
	Name_Table__0 const ref const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Name__0 const ref const system_namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__0(allocate(sizeof(Name__0))), NamespaceName__, ((string){{6},(uint8_t*)u8"system"}));
	Name__0 const ref const console_namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), system_namespace_name__, NamespaceName__, ((string){{7},(uint8_t*)u8"console"}));
	Name__0 const ref const console_class_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), console_namespace_name__, TypeName__, ((string){{7},(uint8_t*)u8"Console"}));
	assert__1(never__0op__not_equal(get_name__2(name_table__, console_class_name__), none));
}

void mut can_get_Optional_class_from_name_with_package__0()
{
	Package_Name__0 const ref const name__ = Package_Name__0__0new__1(allocate(sizeof(Package_Name__0)), ((string){{7},(uint8_t*)u8"default"}));
	Package__0 const ref const primitives_package__ = build_primitives_package__0();
	system__collections__List__1 mut ref const references__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(references__, Package_Reference__0__0new__1(allocate(sizeof(Package_Reference__0)), primitives_package__));
	Source_Text__0 const ref const source__ = Source_Text__0__0new__3(allocate(sizeof(Source_Text__0)), name__->unqualified__, ((string){{9},(uint8_t*)u8"//test.ad"}), ((string){{19},(uint8_t*)u8"// test source text"}));
	Syntax_Node__0 const ref const package_syntax__ = Syntax_Node__0__0new__4(allocate(sizeof(Syntax_Node__0)), PackageNode__, source__, ((int32){0}), ((int32){0}));
	Name_Table__0 const ref const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Name__0 const ref const adamant_namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), Name__0__0new__global_namespace__0(allocate(sizeof(Name__0))), NamespaceName__, ((string){{7},(uint8_t*)u8"adamant"}));
	Name__0 const ref const language_namespace_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), adamant_namespace_name__, NamespaceName__, ((string){{8},(uint8_t*)u8"language"}));
	assert__1(never__0op__not_equal(get_name__2(name_table__, language_namespace_name__), none));
	Name__0 const ref const optional_class_name__ = Name__0__0new__3(allocate(sizeof(Name__0)), language_namespace_name__, TypeName__, ((string){{8},(uint8_t*)u8"optional"}));
	assert__1(never__0op__not_equal(get_name__2(name_table__, optional_class_name__), none));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	add_resource((string){{16},(uint8_t*)u8"RuntimeLibrary.c"}, (string){{24733},(uint8_t*)u8"#include \"RuntimeLibrary.h\"\n\n#include <string.h>\n#include <assert.h>\n\n// -----------------------------------------------------------------------------\n// Static Checks\n// -----------------------------------------------------------------------------\n\n// At least on windows, this macro seems to be missing\n#ifndef static_assert\n#define static_assert _Static_assert\n#endif\n\n// Because we assume we can cast from char* to uint8_t* they need to be the same size\nstatic_assert(sizeof(char) == sizeof(uint8_t), \"chars must be 8 bits\");\n\n// Because we assume we can cast from uint8_t* to byte* they need to be the same size\nstatic_assert(sizeof(uint8_t) == sizeof(byte), \"bytes must be 8 bits\");\n\n// Bool sizing assertions.\nstatic_assert(sizeof(_Bool) == sizeof(BOOL), \"BOOL size\");\ntypedef struct { _Bool a; _Bool b; } raw;\ntypedef struct { BOOL a; BOOL b; } wrapped;\nstatic_assert(sizeof(raw) == sizeof(wrapped), \"Wrapping doesn't change size\");\n\nstatic_assert(sizeof(_Bool) != sizeof(raw), \"_Bools don't pack\");\nstatic_assert(sizeof(_Bool) != sizeof(wrapped), \"Wrapped _bools don't pack\");\n\ntypedef struct { _Bool a:1; _Bool b:1; } field;\nstatic_assert(sizeof(_Bool) == sizeof(field), \"Bit fields pack\");\n\ntypedef struct { _Bool a:1; uint8_t x; _Bool b:1; } split_field;\nstatic_assert(sizeof(split_field) == 3, \"Split bit fields don't pack\");\n\n// Testing that the style we use for literals can be used as a const\nconst code_point test_code_point = ((code_point){0xFF});\n\n// Note: there is no such thing as a constant array initializer in C. We have to\n// take the pointer to the string literal.\nconst string test_string = ((string){{5},(uint8_t*)u8\"hello\"});\n\n// -----------------------------------------------------------------------------\n// Emit Support\n// -----------------------------------------------------------------------------\n// These are things which make emitting easier or clearer\n\nnoreturn void NON_EXHAUSTIVE_MATCH_IMPL(int32_t type_id, char const *_Nonnull function, char const *_Nonnull file, int32_t line)\n{\n    printf(\"Non-exhustive match. Type_ID=%i not covered in function %s in %s, line %i\", type_id, function, file, line);\n    exit(70);\n}\n\n// -----------------------------------------------------------------------------\n// Library Utils\n// -----------------------------------------------------------------------------\n\nstatic const _Bool _true=1;\nstatic const _Bool _false=0;\n\nvoid lib_assert1(const _Bool condition, char const *_Nonnull code)\n{\n    if(!condition)\n    {\n        printf(\"Assertion failed: %s\", code);\n        exit(70);\n    }\n}\n\nvoid lib_assert2(const _Bool condition, char const *_Nonnull code, char const *_Nonnull message)\n{\n    if(!condition)\n    {\n        printf(\"Assertion failed: %s, %s\", code, message);\n        exit(70);\n    }\n}\n\nextern inline void_ptr allocate(size_t bytes);\n\nstatic inline int32 int32_from(int32_t v)\n{\n    return (int32){ v };\n}\n\n// TODO change this to something like byte_from\nuint8_t code_point__to_char(code_point v)\n{\n    lib_assert(v.value <= 0xFF);\n    return v.value;\n}\n\nchar const * cstr_from(string value)\n{\n    int32_t length = value.byte_length.value;\n    char* bytes = allocate(length + 1);\n    memcpy(bytes, value.bytes, length);\n    bytes[length] = 0;\n    return bytes;\n}\n\nstring string_from_cstr(char const* s)\n{\n    return (string){int32_from(strlen(s)), (uint8_t*)s};\n}\n\n// -----------------------------------------------------------------------------\n// Primitive Types\n// -----------------------------------------------------------------------------\n\nextern inline _Bool cond(BOOL cond);\nextern inline BOOL bool_from(_Bool b);\nextern inline BOOL bool_op(_Bool b);\nextern inline _Bool bool_arg(BOOL b);\nextern inline BOOL BOOL__0op__not(BOOL b);\n\nstring bool_to_string__1(BOOL b)\n{\n    if(cond(b))\n        return (string){int32_from(4),(uint8_t*)u8\"true\"};\n    else\n        return (string){int32_from(5),(uint8_t*)u8\"false\"};\n}\n\nextern inline void op__add_assign(int32*_Nonnull lhs, int32 rhs);\nextern inline void op__sub_assign(int32*_Nonnull lhs, int32 rhs);\nextern inline int32 int32__0op__neg(int32 v);\nextern inline int32 int32__0op__add(int32 lhs, int32 rhs);\nextern inline int32 int32__0op__sub(int32 lhs, int32 rhs);\nextern inline int32 int32__0op__mul(int32 lhs, int32 rhs);\nextern inline int32 int32__0op__div(int32 lhs, int32 rhs);\nextern inline int32 int32__0op__remainder(int32 lhs, int32 rhs);\nextern inline BOOL int32__0op__lt(int32 lhs, int32 rhs);\nextern inline BOOL int32__0op__lte(int32 lhs, int32 rhs);\nextern inline BOOL int32__0op__gt(int32 lhs, int32 rhs);\nextern inline BOOL int32__0op__gte(int32 lhs, int32 rhs);\n\nstring int_to_string__1(int32 i)\n{\n    uint8_t* bytes = allocate(12); // -2,147,483,648 plus null terminator\n    int length = sprintf((char*)bytes, \"%d\", i.value);\n    lib_assert(length > 0);\n    return (string){int32_from(length), bytes};\n}\nstring int_to_hex_string__1(int32 i)\n{\n    lib_assert(i.value >= 0);\n    uint8_t* bytes = allocate(9); // FF_FF_FF_FF plus null terminator\n    int length = sprintf((char*)bytes, \"%X\", i.value);\n    lib_assert(length > 0);\n    return (string){int32_from(length), bytes};\n}\n\nint32 hex_string_to_int__1(string s)\n{\n    char const* cstr = cstr_from(s);\n    int32_t i = strtoul(cstr, NULL, 16);\n    free__1(cstr);\n    return (int32){i};\n}\n\ncode_point int_to_code_point__1(int32 i)\n{\n    lib_assert(i.value >= 0);\n    return (code_point){(uint32_t)i.value};\n}\n\nextern inline BOOL code_point__0op__lt(code_point lhs, code_point rhs);\nextern inline BOOL code_point__0op__lte(code_point lhs, code_point rhs);\nextern inline BOOL code_point__0op__gt(code_point lhs, code_point rhs);\nextern inline BOOL code_point__0op__gte(code_point lhs, code_point rhs);\nextern inline int32 code_point_as_int__1(code_point c);\n\nstring code_point_to_string__1(code_point c)\n{\n    uint8_t* bytes = allocate(sizeof(uint8_t));\n    *bytes = code_point__to_char(c);\n    return (string){int32_from(1), bytes};\n}\n\nstring string__0new__0()\n{\n    return (string){int32_from(0), 0};\n}\n\nstring string__0new__1(string value)\n{\n    return value;\n}\n\nstring string__0new__2(code_point c, int32 repeat)\n{\n    uint8_t* bytes = allocate(repeat.value);\n    uint8_t ch = code_point__to_char(c);\n    for (int i = 0; i < repeat.value; i++)\n        bytes[i] = ch;\n\n    return (string){repeat, bytes};\n}\n\nstring string__0op__add(string lhs, string rhs)\n{\n    int new_length = lhs.byte_length.value + rhs.byte_length.value;\n    uint8_t* chars = allocate(new_length);\n    size_t offset = sizeof(uint8_t) * lhs.byte_length.value;\n    memcpy(chars, lhs.bytes, offset);\n    memcpy(chars + offset, rhs.bytes, rhs.byte_length.value);\n    return (string){int32_from(new_length), chars};\n}\n\nBOOL string__0op__equal(string lhs, string rhs)\n{\n    if (lhs.byte_length.value != rhs.byte_length.value)\n        return FALSE;\n\n    for (int i = 0; i < lhs.byte_length.value; i++)\n        if (lhs.bytes[i] != rhs.bytes[i])\n            return FALSE;\n\n    return TRUE;\n}\n\nBOOL string__0op__lt(string lhs, string rhs)\n{\n    char const* left = cstr_from(lhs);\n    char const* right = cstr_from(rhs);\n    _Bool result = strcmp(left, right) < 0;\n    free__1(left);\n    free__1(right);\n    return bool_from(result);\n}\nBOOL string__0op__lte(string lhs, string rhs)\n{\n    char const* left = cstr_from(lhs);\n    char const* right = cstr_from(rhs);\n    _Bool result = strcmp(left, right) <= 0;\n    free__1(left);\n    free__1(right);\n    return bool_from(result);\n}\nBOOL string__0op__gt(string lhs, string rhs)\n{\n    char const* left = cstr_from(lhs);\n    char const* right = cstr_from(rhs);\n    BOOL result = bool_from(strcmp(left, right) > 0);\n    free__1(left);\n    free__1(right);\n    return result;\n}\nBOOL string__0op__gte(string lhs, string rhs)\n{\n    char const* left = cstr_from(lhs);\n    char const* right = cstr_from(rhs);\n    BOOL result = bool_from(strcmp(left, right) >= 0);\n    free__1(left);\n    free__1(right);\n    return result;\n}\n\nextern inline code_point string__0__0op__element(string value, int32 index);\nextern inline int32 string_byte_length__1(string s);\n\nstring substring__3(string s, int32 start, int32 length)\n{\n    // You can ask for a zero length substring at the end of the string\n    lib_assert(start.value <= s.byte_length.value);\n    lib_assert(start.value+length.value <= s.byte_length.value);\n    return (string){length, s.bytes + start.value};\n}\n\nextern inline string substring__2(string s, int32 start);\n\nstring string_replace__3(string s, string old_value, string new_value)\n{\n    // We make one one the stack then manually call the constructor\n    system__text__String_Builder__0 builder;\n    system__text__String_Builder__0__0new__with_capacity__1(&builder, s.byte_length);\n    int limit = s.byte_length.value - old_value.byte_length.value + 1;\n    int last_index = 0;\n    for(int i=0; i < limit; i++)\n        if(cond(string__0op__equal(substring__3(s, int32_from(i), old_value.byte_length), old_value)))\n        {\n            sb_append__2(&builder, substring__3(s, int32_from(last_index), int32_from(i-last_index)));\n            sb_append__2(&builder, new_value);\n            i += old_value.byte_length.value; // skip over the value we just matched\n            last_index = i;\n            i--; // we need i-- to offset the i++ that is about to happen\n        }\n\n    sb_append__2(&builder, substring__3(s, int32_from(last_index), int32_from(s.byte_length.value - last_index)));\n    return sb_to_string__1(&builder);\n}\nint32 string_index_of__2(string s, code_point c)\n{\n    uint8_t value = code_point__to_char(c);\n    for(int i = 0; i < s.byte_length.value; i++)\n        if(s.bytes[i] == value)\n            return int32_from(i);\n\n    // TODO we should return `int?` and return `none` in this case\n    return int32_from(-1);\n}\nint32 string_last_index_of__2(string s, code_point c)\n{\n    uint8_t value = code_point__to_char(c);\n    for(int i = s.byte_length.value - 1; i >= 0; i--)\n        if(s.bytes[i] == value)\n            return int32_from(i);\n\n    // TODO we should return `int?` and return `none` in this case\n    return int32_from(-1);\n}\n\n// -----------------------------------------------------------------------------\n// Operators\n// -----------------------------------------------------------------------------\n\nextern inline BOOL BOOL__0op__equal(BOOL lhs, BOOL rhs);\nextern inline BOOL int32__0op__equal(int32 lhs, int32 rhs);\nextern inline BOOL code_point__0op__equal(code_point lhs, code_point rhs);\nextern BOOL string__0op__equal(string lhs, string rhs);\n// TODO this currently exists becuase of the compare `none`, it shouldn't exist\nextern inline BOOL never__0op__equal(const_void_ptr lhs, const_void_ptr rhs);\nextern inline BOOL void_ptr__0op__equal(const_void_ptr lhs, const_void_ptr rhs);\n\nextern inline BOOL BOOL__0op__not_equal(BOOL lhs, BOOL rhs);\nextern inline BOOL int32__0op__not_equal(int32 lhs, int32 rhs);\nextern inline BOOL code_point__0op__not_equal(code_point lhs, code_point rhs);\nextern inline BOOL string__0op__not_equal(string lhs, string rhs);\n// TODO this currently exists becuase of the compare `none`, it shouldn't exist\nextern inline BOOL never__0op__not_equal(const_void_ptr lhs, const_void_ptr rhs);\nextern inline BOOL void_ptr__0op__not_equal(const_void_ptr lhs, const_void_ptr rhs);\n\n// -----------------------------------------------------------------------------\n// Standard Library\n// -----------------------------------------------------------------------------\n\nextern inline void const ref as_any__1(void const ref const value);\nextern inline void mut ref as_any_mut__1(void mut ref const value);\n\nextern inline void_ptr allocate__1(int32 bytes);\nextern inline void free__1(const_void_ptr object);\n\nvoid assert1(const BOOL condition, char const *_Nonnull code, char const *_Nonnull file, const int32_t line)\n{\n    if(!condition.value)\n    {\n        printf(\"Assertion failed: %s, file %s, line %i\", code, file, line);\n        exit(70);\n    }\n}\n\nvoid assert2(const BOOL condition, char const *_Nonnull code, const string message, char const *_Nonnull file, const int32_t line)\n{\n    if(!condition.value)\n    {\n        printf(\"Assertion failed: %s, %s, file %s, line %i\", code, cstr_from(message), file, line);\n        exit(70);\n    }\n}\n\nnoreturn void NOT_IMPLEMENTED0(char const *_Nonnull function, char const *_Nonnull file, const int32_t line)\n{\n    printf(\"Function %s not yet implemented, %s, line %i\", function, file, line);\n    exit(70);\n}\n\nnoreturn void NOT_IMPLEMENTED1(const string message, char const *_Nonnull function, char const *_Nonnull file, const int32_t line)\n{\n    printf(\"Function %s not yet implemented, %s, %s, line %i\", function, cstr_from(message), file, line);\n    exit(70);\n}\n\nnoreturn void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const int32_t line)\n{\n    printf(\"Reached \\\"UNREACHABLE\\\" statement in function %s, %s, line %i\", function, file, line);\n    exit(70);\n}\n\nstatic int32_t resource_count = 0;\nstatic string resource_name[1024];\nstatic string resource_value[1024];\n\nvoid add_resource(string name, string value)\n{\n    lib_assert_msg(resource_count < 1024, \"only 1024 resources are currently supported\");\n    resource_name[resource_count] = name;\n    resource_value[resource_count] = value;\n    resource_count += 1;\n}\n\nstring get_resource__1(string name)\n{\n    for(int32_t i=0; i < resource_count; i++)\n        if(cond(string__0op__equal(resource_name[i], name)))\n            return resource_value[i];\n\n    lib_assert_msg(_false, cstr_from(name));\n    UNREACHABLE__0();\n}\n\nvoid debug_write__1(string value)\n{\n    fprintf(stderr, \"%.*s\", value.byte_length.value, value.bytes);\n}\nvoid debug_write_line__1(string value)\n{\n    fprintf(stderr, \"%.*s\\n\", value.byte_length.value, value.bytes);\n}\nvoid debug_write_line__0()\n{\n    fprintf(stderr, \"\\n\");\n}\n\n_Bool string__0next(string__0iter*_Nonnull iter)\n{\n    iter->current++;\n    if(iter->current >= iter->count)\n    {\n        iter->current = iter->count; // prevent current from further increase\n        return _false;\n    }\n    return _true;\n}\n\nextern inline string string__0current(string__0iter const*_Nonnull iter);\n\nStrings__0 *_Nonnull Strings__0__0new__0(Strings__0 *_Nonnull self)\n{\n    self->values = NULL;\n    self->count__ = (int32){0};\n    self->capacity__ = (int32){0};\n    return self;\n}\n\nextern inline string Strings__0__0op__element(Strings__0 const*_Nonnull strings, int32 const index);\nextern inline void clear_strings__1(Strings__0 *_Nonnull strings);\n\nvoid add_string__2(Strings__0 *_Nonnull strings, string value)\n{\n    if(strings->count__.value >= strings->capacity__.value)\n    {\n        int32_t new_capacity = strings->capacity__.value == 0 ? 16 : strings->capacity__.value * 2;\n        // Allocate uninitalized bytes (note `sizeof(char) == 1` always)\n        // Needed if T is a value type to avoid needing a default constructor\n        string* new_values = allocate(new_capacity * sizeof(string));\n        memcpy(new_values, strings->values, strings->count__.value * sizeof(string));\n        if(strings->capacity__.value != 0)\n            free__1(strings->values); // delete the old array\n        strings->values = new_values;\n        strings->capacity__ = (int32){new_capacity};\n    }\n    strings->values[strings->count__.value] = value;\n    strings->count__.value++;\n}\n\nextern inline string__0iter Strings__0__0iterate(Strings__0 const *_Nonnull strings);\nextern inline string__0iter string__0iterate(Strings__0 const *_Nonnull strings);\n\n_Bool int__0next(int__0iter*_Nonnull iter)\n{\n    iter->current++;\n    if(iter->current >= iter->count)\n    {\n        iter->current = iter->count; // prevent current from further increase\n        return _false;\n    }\n    return _true;\n}\n\nextern inline int32 int__0current(int__0iter const*_Nonnull iter);\n\nInts__0 *_Nonnull Ints__0__0new__0(Ints__0 *_Nonnull self)\n{\n    self->values = NULL;\n    self->count__ = (int32){0};\n    self->capacity__ = (int32){0};\n    return self;\n}\n\nextern inline int32 Ints__0__0op__element(Ints__0 const*_Nonnull ints, int32 const index);\nextern inline void clear_ints__1(Ints__0 *_Nonnull ints);\n\nvoid add_int__2(Ints__0 *_Nonnull ints, int32 value)\n{\n    if(ints->count__.value >= ints->capacity__.value)\n    {\n        int32_t new_capacity = ints->capacity__.value == 0 ? 16 : ints->capacity__.value * 2;\n        // Allocate uninitalized bytes (note `sizeof(char) == 1` always)\n        // Needed if T is a value type to avoid needing a default constructor\n        int32* new_values = allocate(new_capacity * sizeof(int32));\n        memcpy(new_values, ints->values, ints->count__.value * sizeof(int32));\n        if(ints->capacity__.value != 0)\n            free__1(ints->values); // delete the old array\n        ints->values = new_values;\n        ints->capacity__ = (int32){new_capacity};\n    }\n    ints->values[ints->count__.value] = value;\n    ints->count__.value++;\n}\n\nextern inline int__0iter Ints__0__0iterate(Ints__0 const*_Nonnull ints);\nextern inline int__0iter int__0iterate(Ints__0 const*_Nonnull ints);\n\n_Bool void_ptr__0next(void_ptr__0iter*_Nonnull iter)\n{\n    iter->current++;\n    if(iter->current >= iter->count)\n    {\n        iter->current = iter->count; // prevent current from further increase\n        return _false;\n    }\n    return _true;\n}\n\nextern inline void_ptr void_ptr__0current(void_ptr__0iter const*_Nonnull iter);\n\nextern inline system__collections__List__1 *_Nonnull system__collections__List__1__0new__0(system__collections__List__1 *_Nonnull self);\n\nvoid add_item__2(system__collections__List__1 *_Nonnull list, const_void_ptr value)\n{\n    if(list->count__.value >= list->capacity__.value)\n    {\n        int32_t new_capacity = list->capacity__.value == 0 ? 16 : list->capacity__.value * 2;\n        // Allocate uninitalized bytes (note `sizeof(char) == 1` always)\n        void_ptr* new_values = allocate(new_capacity * sizeof(void_ptr));\n        memcpy(new_values, list->values, list->count__.value * sizeof(void_ptr));\n        if(list->capacity__.value != 0)\n            free__1(list->values); // delete the old array\n        list->values = new_values;\n        list->capacity__ = (int32){new_capacity};\n    }\n    list->values[list->count__.value] = (void*_Nullable)value; // TODO hack, we cast away const\n    list->count__.value++;\n}\n\nextern inline void clear_list__1(system__collections__List__1 *_Nonnull list);\nextern inline const_void_ptr system__collections__List__1__0op__element(system__collections__List__1 const*_Nonnull list, int32 const index);\nextern inline void_ptr__0iter system__collections__List__1__0iterate(system__collections__List__1 const *_Nonnull list);\nextern inline void_ptr__0iter void_ptr__0iterate(system__collections__List__1 const *_Nonnull list);\n\nvoid console_write__2(system__console__Console__0 *_Nonnull console, string value)\n{\n    printf(\"%.*s\", value.byte_length.value, value.bytes);\n}\nvoid console_write_line__2(system__console__Console__0 *_Nonnull console, string value)\n{\n    printf(\"%.*s\\n\", value.byte_length.value, value.bytes);\n}\nvoid console_write_line__1(system__console__Console__0 *_Nonnull console)\n{\n    printf(\"\\n\");\n}\n\nsystem__console__Arguments__0 const *_Nonnull convert_arguments(int argc, char const *_Nonnull const *_Nonnull argv)\n{\n    system__console__Arguments__0 *_Nonnull self = allocate(sizeof(system__console__Arguments__0));\n    self->count__ = (int32){argc-1};\n    self->values = allocate(self->count__.value * sizeof(string));\n    for (int i = 0; i < self->count__.value; i++)\n        self->values[i] = string_from_cstr(argv[i+1]);\n    return self;\n}\n\nextern inline string system__console__Arguments__0__0op__element(system__console__Arguments__0 const*_Nonnull arguments, int32 const index);\nextern inline string__0iter system__console__Arguments__0__0iterate(system__console__Arguments__0 const*_Nonnull arguments);\n\nsystem__io__File_Reader__0 *_Nonnull system__io__File_Reader__0__0new__1(system__io__File_Reader__0 *_Nonnull self, string file_name)\n{\n    char const *_Nonnull fname = cstr_from(file_name);\n    self->file= fopen(fname, \"rb\"); // TODO report error up to caller\n    free__1(fname);\n    return self;\n}\n\nstring file_read_to_end__1(system__io__File_Reader__0 *_Nonnull reader)\n{\n    fseek(reader->file, 0, SEEK_END);\n    long int length = ftell(reader->file);\n    fseek(reader->file, 0, SEEK_SET);\n    uint8_t*_Nonnull bytes = allocate(length);\n    length = fread(bytes, sizeof(uint8_t), length, reader->file);\n    return (string){int32_from(length), bytes};\n}\nvoid close_file_reader__1(system__io__File_Reader__0 *_Nonnull reader)\n{\n    fclose(reader->file);\n}\n\nsystem__io__File_Writer__0 *_Nonnull system__io__File_Writer__0__0new__1(system__io__File_Writer__0 *_Nonnull self, string file_name)\n{\n    char const *_Nonnull fname = cstr_from(file_name);\n    self->file = fopen(fname, \"wb\"); // TODO report error up to caller\n    free__1(fname);\n    return self;\n}\n\nvoid file_write__2(system__io__File_Writer__0 *_Nonnull writer, string value)\n{\n    fwrite(value.bytes, sizeof(char), value.byte_length.value, writer->file);\n}\nvoid close_file_writer__1(system__io__File_Writer__0 *_Nonnull writer)\n{\n    fclose(writer->file);\n}\n\nvoid ensure_sb_capacity(system__text__String_Builder__0*_Nonnull sb, int needed)\n{\n    int new_capacity = sb->capacity == 0 ? 128 : sb->capacity;\n    while(new_capacity < needed)\n    {\n        new_capacity *= 2;\n    }\n\n    if(new_capacity > sb->capacity)\n    {\n        uint8_t* new_buffer =  allocate(new_capacity);\n        if(sb->byte_length__.value > 0)\n            memcpy(new_buffer, sb->bytes, sb->byte_length__.value*sizeof(uint8_t));\n\n        if(sb->capacity > 0)\n            free__1(sb->bytes);\n\n        sb->bytes = new_buffer;\n        sb->capacity = new_capacity;\n    }\n}\n\nextern inline system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__0(system__text__String_Builder__0 *_Nonnull self);\n\nsystem__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__1(system__text__String_Builder__0 *_Nonnull self, string value)\n{\n    system__text__String_Builder__0__0new__0(self);\n    ensure_sb_capacity(self, value.byte_length.value);\n    memcpy(self->bytes, value.bytes, value.byte_length.value);\n    self->byte_length__.value = value.byte_length.value;\n    return self;\n}\n\nsystem__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__with_capacity__1(system__text__String_Builder__0 *_Nonnull self, int32 capacity)\n{\n    system__text__String_Builder__0__0new__0(self);\n    ensure_sb_capacity(self, capacity.value);\n    return self;\n}\n\nvoid sb_append__2(system__text__String_Builder__0 *_Nonnull sb, string value)\n{\n    int32_t new_length = sb->byte_length__.value + value.byte_length.value;\n    ensure_sb_capacity(sb, new_length);\n    memcpy(sb->bytes+sb->byte_length__.value, value.bytes, value.byte_length.value);\n    sb->byte_length__.value = new_length;\n}\n\nvoid sb_append_sb__2(system__text__String_Builder__0 *_Nonnull sb, system__text__String_Builder__0 const *_Nonnull value)\n{\n    int32_t new_length = sb->byte_length__.value + value->byte_length__.value;\n    ensure_sb_capacity(sb, new_length);\n    memcpy(sb->bytes+sb->byte_length__.value, value->bytes, value->byte_length__.value);\n    sb->byte_length__.value = new_length;\n}\n\nvoid sb_append_line__2(system__text__String_Builder__0 *_Nonnull sb, string value)\n{\n    int32_t new_length = sb->byte_length__.value + value.byte_length.value + 1;\n    ensure_sb_capacity(sb, new_length);\n    memcpy(sb->bytes+sb->byte_length__.value, value.bytes, value.byte_length.value);\n    sb->bytes[new_length-1] = '\\n';\n    sb->byte_length__.value = new_length;\n}\n\nvoid sb_append_line__1(system__text__String_Builder__0 *_Nonnull sb)\n{\n    int32_t new_length = sb->byte_length__.value + 1;\n    ensure_sb_capacity(sb, new_length);\n    sb->bytes[new_length-1] = '\\n';\n    sb->byte_length__.value = new_length;\n}\n\nvoid sb_remove__3(system__text__String_Builder__0 *_Nonnull sb, int32 start, int32 length)\n{\n    lib_assert(start.value < sb->byte_length__.value);\n\n    int32_t end = start.value + length.value;\n    lib_assert(end <= sb->byte_length__.value); // less than or equal because end is one past the end of the remove\n\n    memmove(sb->bytes+start.value, sb->bytes+end, sb->byte_length__.value-end);\n    sb->byte_length__.value -= length.value;\n}\n\nvoid sb_remove__2(system__text__String_Builder__0 *_Nonnull sb, int32 start)\n{\n    lib_assert(start.value < sb->byte_length__.value);\n    sb->byte_length__.value = start.value;\n}\n\nstring sb_to_string__1(system__text__String_Builder__0 *_Nonnull sb)\n{\n    string result = {int32_from(sb->byte_length__.value), sb->bytes};\n    // give up ownership of bytes\n    sb->bytes = 0;\n    sb->byte_length__.value = 0;\n    sb->capacity = 0;\n    return result;\n}\n"});
	add_resource((string){{16},(uint8_t*)u8"RuntimeLibrary.h"}, (string){{17664},(uint8_t*)u8"// On windows this disables warnings about using fopen_s instead of fopen\n// It must be defined before including the headers.\n// Note that we can't switch to the \"secure\" functions because they don't\n// compile in linux on Travis CI\n#define _CRT_SECURE_NO_WARNINGS\n\n#include <stdlib.h>\n#include <stdint.h>\n#include <stdio.h>\n#include <stdnoreturn.h>\n\n// -----------------------------------------------------------------------------\n// Emit Support\n// -----------------------------------------------------------------------------\n// These are things which make emitting easier or clearer\n\n#define ref *_Nonnull restrict\n#define opt_ref *_Nullable restrict\n#define ptr *_Nonnull\n#define opt_ptr *_Nullable\n#define mut\n\n#define NON_EXHAUSTIVE_MATCH(type_id) NON_EXHAUSTIVE_MATCH_IMPL(type_id, __func__, __FILE__, __LINE__);\nnoreturn void NON_EXHAUSTIVE_MATCH_IMPL(int32_t type_id, char const *_Nonnull function, char const *_Nonnull file, int32_t line);\n\n// -----------------------------------------------------------------------------\n// Library Utils\n// -----------------------------------------------------------------------------\n\ntypedef void*_Nullable void_ptr;\ntypedef void const*_Nullable const_void_ptr;\n\n#define lib_assert(condition) lib_assert1(condition, #condition)\nvoid lib_assert1(const _Bool condition, char const *_Nonnull code);\n#define lib_assert_msg(condition, message) lib_assert2(condition, #condition, message)\nvoid lib_assert2(const _Bool condition, char const *_Nonnull code, char const *_Nonnull message);\n\ninline void_ptr allocate(size_t bytes)\n{\n    return malloc(bytes);\n}\n\n// -----------------------------------------------------------------------------\n// Primitive Types\n// -----------------------------------------------------------------------------\n\ntypedef struct never never;\ntypedef struct optional__never optional__never;\ntypedef struct BOOL BOOL;\ntypedef struct int32 int32;\ntypedef struct byte byte;\ntypedef struct code_point code_point;\ntypedef struct string string;\n\n// `never` type\nstruct never\n{\n};\n\n// `never?` type\nstruct optional__never\n{\n};\n\n// TODO this is a hack for now, the type of `none` should be `never?`\nstatic const void_ptr none = NULL;\n\n// For now, use `BOOL` as the emitted type\n// TODO C: switch `BOOL` to `bool`\n// TODO C: switch `TRUE` to `true`\n// TODO C: switch `FALSE` to `false`\n\n// `bool` type\nstruct BOOL\n{\n    _Bool value;\n};\n\nstatic const BOOL TRUE = { 1 };\nstatic const BOOL FALSE = { 0 };\n\n// Function used in conditions to make them take `bool`\ninline _Bool cond(BOOL cond) { return cond.value; }\n\n// Used by runtime for converting to bool\ninline BOOL bool_from(_Bool b) { return (BOOL){ b }; }\n\n// Wrap a bool operation that is bool based\ninline BOOL bool_op(_Bool b) { return (BOOL){ b }; }\n// Convert the arguments of a logical operation to bool\ninline _Bool bool_arg(BOOL b) { return b.value; }\n\ninline BOOL BOOL__0op__not(BOOL b) { return (BOOL){ !b.value }; }\n\nstring bool_to_string__1(BOOL b);\n\n// `int` type\nstruct int32\n{\n    int32_t value;\n};\n\ninline void op__add_assign(int32*_Nonnull lhs, int32 rhs) { lhs->value += rhs.value; }\ninline void op__sub_assign(int32*_Nonnull lhs, int32 rhs) { lhs->value -= rhs.value; }\ninline int32 int32__0op__neg(int32 v) { return (int32){-v.value}; }\ninline int32 int32__0op__add(int32 lhs, int32 rhs) { return (int32){ lhs.value + rhs.value}; }\ninline int32 int32__0op__sub(int32 lhs, int32 rhs) { return (int32){ lhs.value - rhs.value}; }\ninline int32 int32__0op__mul(int32 lhs, int32 rhs) { return (int32){ lhs.value * rhs.value}; }\ninline int32 int32__0op__div(int32 lhs, int32 rhs) { return (int32){ lhs.value / rhs.value}; }\ninline int32 int32__0op__remainder(int32 lhs, int32 rhs) { return (int32){ lhs.value % rhs.value}; }\ninline BOOL int32__0op__lt(int32 lhs, int32 rhs) { return bool_from(lhs.value < rhs.value); }\ninline BOOL int32__0op__lte(int32 lhs, int32 rhs) { return bool_from(lhs.value <= rhs.value); }\ninline BOOL int32__0op__gt(int32 lhs, int32 rhs) { return bool_from(lhs.value > rhs.value); }\ninline BOOL int32__0op__gte(int32 lhs, int32 rhs) { return bool_from(lhs.value >= rhs.value); }\n\nstring int_to_string__1(int32 i);\nstring int_to_hex_string__1(int32 i);\nint32 hex_string_to_int__1(string s);\ncode_point int_to_code_point__1(int32 i);\n\nstruct byte\n{\n    uint8_t value;\n};\n\nstruct code_point\n{\n    // don't use something like char32_t because C's handling of chars sucks\n    uint32_t value;\n};\n\ninline BOOL code_point__0op__lt(code_point lhs, code_point rhs) { return bool_from(lhs.value < rhs.value); }\ninline BOOL code_point__0op__lte(code_point lhs, code_point rhs) { return bool_from(lhs.value <= rhs.value); }\ninline BOOL code_point__0op__gt(code_point lhs, code_point rhs) { return bool_from(lhs.value > rhs.value); }\ninline BOOL code_point__0op__gte(code_point lhs, code_point rhs) { return bool_from(lhs.value >= rhs.value); }\n\ninline int32 code_point_as_int__1(code_point c) { return (int32){(int32_t)c.value}; }\nstring code_point_to_string__1(code_point c);\n\nstruct string\n{\n    // Though there will be a byte_length property in the future,\n    // it doesn't make sense to directly expose it right now because this is\n    // not the correct implementation.\n    int32 byte_length;\n\n    // don't use chars because C's handling of chars sucks\n    uint8_t const *_Nonnull bytes;\n};\n\nstring string__0new__0();\nstring string__0new__1(string value);\nstring string__0new__2(code_point c, int32 repeat);\n\nstring string__0op__add(string lhs, string rhs);\nBOOL string__0op__lt(string lhs, string rhs);\nBOOL string__0op__lte(string lhs, string rhs);\nBOOL string__0op__gt(string lhs, string rhs);\nBOOL string__0op__gte(string lhs, string rhs);\ninline code_point string__0__0op__element(string value, int32 index)\n{\n    lib_assert(index.value >= 0 && index.value < value.byte_length.value);\n    return (code_point){value.bytes[index.value]};\n}\n\ninline int32 string_byte_length__1(string s) { return s.byte_length; }\nstring substring__3(string s, int32 start, int32 length);\ninline string substring__2(string s, int32 start) { return substring__3(s, start, (int32){s.byte_length.value-start.value}); }\nstring string_replace__3(string s, string old_value, string new_value);\nint32 string_index_of__2(string s, code_point c);\nint32 string_last_index_of__2(string s, code_point c);\n\n// -----------------------------------------------------------------------------\n// Operators\n// -----------------------------------------------------------------------------\n\ninline BOOL BOOL__0op__equal(BOOL lhs, BOOL rhs)\n{\n    return bool_from(lhs.value == rhs.value);\n}\ninline BOOL int32__0op__equal(int32 lhs, int32 rhs)\n{\n    return bool_from(lhs.value == rhs.value);\n}\ninline BOOL code_point__0op__equal(code_point lhs, code_point rhs)\n{\n    return bool_from(lhs.value == rhs.value);\n}\nBOOL string__0op__equal(string lhs, string rhs);\n// TODO this currently exists becuase of the compare `none`, it shouldn't exist\ninline BOOL never__0op__equal(const_void_ptr lhs, const_void_ptr rhs)\n{\n    return bool_from(lhs == rhs);\n}\ninline BOOL void_ptr__0op__equal(const_void_ptr lhs, const_void_ptr rhs)\n{\n    return bool_from(lhs == rhs);\n}\n\ninline BOOL BOOL__0op__not_equal(BOOL lhs, BOOL rhs)\n{\n    return bool_from(lhs.value != rhs.value);\n}\ninline BOOL int32__0op__not_equal(int32 lhs, int32 rhs)\n{\n    return bool_from(lhs.value != rhs.value);\n}\ninline BOOL code_point__0op__not_equal(code_point lhs, code_point rhs)\n{\n    return bool_from(lhs.value != rhs.value);\n}\ninline BOOL string__0op__not_equal(string lhs, string rhs)\n{\n    return BOOL__0op__not(string__0op__equal(lhs, rhs));\n}\n// TODO this currently exists becuase of the compare `none`, it shouldn't exist\ninline BOOL never__0op__not_equal(const_void_ptr lhs, const_void_ptr rhs)\n{\n    return bool_from(lhs != rhs);\n}\ninline BOOL void_ptr__0op__not_equal(const_void_ptr lhs, const_void_ptr rhs)\n{\n    return bool_from(lhs != rhs);\n}\n\n// -----------------------------------------------------------------------------\n// Standard Library\n// -----------------------------------------------------------------------------\n// Parts of the standard library that are currently implemented in the runtime.\n\ntypedef struct string__0iter string__0iter;\ntypedef struct Strings__0 Strings__0;\ntypedef struct int__0iter int__0iter;\ntypedef struct Ints__0 Ints__0;\ntypedef struct void_ptr__0iter void_ptr__0iter;\ntypedef struct system__collections__List__1 system__collections__List__1;\ntypedef struct system__console__Console__0 system__console__Console__0;\ntypedef struct system__console__Arguments__0 system__console__Arguments__0;\ntypedef struct system__io__File_Reader__0 system__io__File_Reader__0;\ntypedef struct system__io__File_Writer__0 system__io__File_Writer__0;\ntypedef struct system__text__String_Builder__0 system__text__String_Builder__0;\n\ninline void const ref as_any__1(void const ref const value)\n{\n    return value;\n}\n\ninline void mut ref as_any_mut__1(void mut ref const value)\n{\n    return value;\n}\n\ninline void_ptr allocate__1(int32 bytes)\n{\n    return malloc(bytes.value);\n}\n\n// TODO rename dellocate()\ninline void free__1(const_void_ptr object)\n{\n    // TODO hack cast away const\n    free((void*_Nonnull)object);\n}\n\n#define assert__1(condition) assert1(condition, #condition, __FILE__, __LINE__)\n#define assert__2(condition, message) assert2(condition, #condition, message, __FILE__, __LINE__)\nvoid assert1(const BOOL condition, char const *_Nonnull code, char const *_Nonnull file, const int32_t line);\nvoid assert2(const BOOL condition, char const *_Nonnull code, const string message, char const *_Nonnull file, const int32_t line);\n\n#define NOT_IMPLEMENTED__0() NOT_IMPLEMENTED0(__func__, __FILE__, __LINE__)\n#define NOT_IMPLEMENTED__1(message) NOT_IMPLEMENTED1(message, __func__, __FILE__, __LINE__)\nnoreturn void NOT_IMPLEMENTED0(char const *_Nonnull function, char const *_Nonnull file, const int32_t line);\nnoreturn void NOT_IMPLEMENTED1(const string message, char const *_Nonnull function, char const *_Nonnull file, const int32_t line);\n\n#define UNREACHABLE__0() UNREACHABLE(__func__, __FILE__, __LINE__)\nnoreturn void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const int32_t line);\n\nstring get_resource__1(string resource_name);\nvoid add_resource(string name, string value);\n\nvoid debug_write__1(string value);\nvoid debug_write_line__1(string value);\nvoid debug_write_line__0();\n\nstruct string__0iter\n{\n    string *_Nullable values;\n    int32_t current;\n    int32_t count;\n};\n\n_Bool string__0next(string__0iter*_Nonnull iter);\ninline string string__0current(string__0iter const*_Nonnull iter)\n{\n    lib_assert(iter->current >= 0 && iter->current < iter->count);\n    return iter->values[iter->current];\n}\n\nstruct Strings__0\n{\n    string *_Nullable values;\n    int32 count__;\n    int32 capacity__;\n};\n\nStrings__0 *_Nonnull Strings__0__0new__0(Strings__0 *_Nonnull self);\ninline string Strings__0__0op__element(Strings__0 const*_Nonnull strings, int32 const index)\n{\n    lib_assert(index.value >= 0 && index.value < strings->count__.value);\n    return strings->values[index.value];\n}\ninline void clear_strings__1(Strings__0 *_Nonnull strings)\n{\n    strings->count__ = (int32){0};\n}\nvoid add_string__2(Strings__0 *_Nonnull strings, string value);\ninline string__0iter Strings__0__0iterate(Strings__0 const *_Nonnull strings)\n{\n    return (string__0iter)\n    {\n        .values = strings->values,\n        .current = -1,\n        .count = strings->count__.value\n    };\n}\ninline string__0iter string__0iterate(Strings__0 const *_Nonnull strings)\n{\n    return (string__0iter)\n    {\n        .values = strings->values,\n        .current = -1,\n        .count = strings->count__.value\n    };\n}\n\nstruct int__0iter\n{\n    int32 *_Nullable values;\n    int32_t current;\n    int32_t count;\n};\n\n_Bool int__0next(int__0iter*_Nonnull iter);\ninline int32 int__0current(int__0iter const*_Nonnull iter)\n{\n    lib_assert(iter->current >= 0 && iter->current < iter->count);\n    return iter->values[iter->current];\n}\n\nstruct Ints__0\n{\n    int32 *_Nullable values;\n    int32 count__;\n    int32 capacity__;\n};\n\nInts__0 *_Nonnull Ints__0__0new__0(Ints__0 *_Nonnull self);\ninline int32 Ints__0__0op__element(Ints__0 const*_Nonnull ints, int32 const index)\n{\n    lib_assert(index.value >= 0 && index.value < ints->count__.value);\n    return ints->values[index.value];\n}\ninline void clear_ints__1(Ints__0 *_Nonnull ints)\n{\n    ints->count__ = (int32){0};\n}\nvoid add_int__2(Ints__0 *_Nonnull ints, int32 value);\ninline int__0iter Ints__0__0iterate(Ints__0 const*_Nonnull ints)\n{\n    return (int__0iter)\n    {\n        .values = ints->values,\n        .current = -1,\n        .count = ints->count__.value\n    };\n}\ninline int__0iter int__0iterate(Ints__0 const*_Nonnull ints)\n{\n    return (int__0iter)\n    {\n        .values = ints->values,\n        .current = -1,\n        .count = ints->count__.value\n    };\n}\n\nstruct void_ptr__0iter\n{\n    void_ptr *_Nullable values;\n    int32_t current;\n    int32_t count;\n};\n\n_Bool void_ptr__0next(void_ptr__0iter*_Nonnull iter);\ninline void_ptr void_ptr__0current(void_ptr__0iter const*_Nonnull iter)\n{\n    lib_assert(iter->current >= 0 && iter->current < iter->count);\n    return iter->values[iter->current];\n}\n\nstruct system__collections__List__1\n{\n    void_ptr *_Nullable values;\n    int32 count__;\n    int32 capacity__;\n};\n\ninline system__collections__List__1 *_Nonnull system__collections__List__1__0new__0(system__collections__List__1 *_Nonnull self)\n{\n    self->values = NULL;\n    self->count__ = (int32){0};\n    self->capacity__ = (int32){0};\n    return self;\n}\n\n// TODO hack that we take const_void_ptr but then treat it as mutable\nvoid add_item__2(system__collections__List__1 *_Nonnull list, const_void_ptr value);\n\ninline void clear_list__1(system__collections__List__1 *_Nonnull list)\n{\n    list->count__ = (int32){0};\n}\n\ninline const_void_ptr system__collections__List__1__0op__element(system__collections__List__1 const*_Nonnull list, int32 const index)\n{\n    lib_assert(index.value >= 0 && index.value < list->count__.value);\n    return list->values[index.value];\n}\n\ninline void_ptr__0iter system__collections__List__1__0iterate(system__collections__List__1 const *_Nonnull list)\n{\n    return (void_ptr__0iter)\n    {\n        .values = list->values,\n        .current = -1,\n        .count = list->count__.value\n    };\n}\n\ninline void_ptr__0iter void_ptr__0iterate(system__collections__List__1 const *_Nonnull list)\n{\n    return (void_ptr__0iter)\n    {\n        .values = list->values,\n        .current = -1,\n        .count = list->count__.value\n    };\n}\n\nstruct system__console__Console__0\n{\n};\n\nvoid console_write__2(system__console__Console__0 *_Nonnull console, string value);\nvoid console_write_line__2(system__console__Console__0 *_Nonnull console, string value);\nvoid console_write_line__1(system__console__Console__0 *_Nonnull console);\n\nstruct system__console__Arguments__0\n{\n    string *_Nonnull values;\n    int32 count__;\n};\n\nsystem__console__Arguments__0 const *_Nonnull convert_arguments(int argc, char const *_Nonnull const *_Nonnull argv);\n\ninline string system__console__Arguments__0__0op__element(system__console__Arguments__0 const*_Nonnull arguments, int32 const index)\n{\n    lib_assert(index.value >= 0 && index.value < arguments->count__.value);\n    return arguments->values[index.value];\n}\n\ninline string__0iter system__console__Arguments__0__0iterate(system__console__Arguments__0 const*_Nonnull arguments)\n{\n    return (string__0iter)\n    {\n        .values = arguments->values,\n        .current = -1,\n        .count = arguments->count__.value\n    };\n}\n\nstruct system__io__File_Reader__0\n{\n    FILE *_Nonnull file;\n};\n\nsystem__io__File_Reader__0 *_Nonnull system__io__File_Reader__0__0new__1(system__io__File_Reader__0 *_Nonnull self, string file_name);\nstring file_read_to_end__1(system__io__File_Reader__0 *_Nonnull reader);\nvoid close_file_reader__1(system__io__File_Reader__0 *_Nonnull reader);\n\nstruct system__io__File_Writer__0\n{\n    FILE *_Nonnull file;\n};\n\nsystem__io__File_Writer__0 *_Nonnull system__io__File_Writer__0__0new__1(system__io__File_Writer__0 *_Nonnull self, string file_name);\nvoid file_write__2(system__io__File_Writer__0 *_Nonnull writer, string value);\nvoid close_file_writer__1(system__io__File_Writer__0 *_Nonnull writer);\n\nstruct system__text__String_Builder__0\n{\n    uint8_t *_Nullable bytes;\n    int capacity;\n    int32 byte_length__;\n};\n\nvoid ensure_sb_capacity(system__text__String_Builder__0*_Nonnull sb, int needed);\n\ninline system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__0(system__text__String_Builder__0 *_Nonnull self)\n{\n    self->bytes = 0;\n    self->capacity = 0;\n    self->byte_length__ = (int32){0};\n    return self;\n}\nsystem__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__1(system__text__String_Builder__0 *_Nonnull self, string value);\nsystem__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__with_capacity__1(system__text__String_Builder__0 *_Nonnull self, int32 capacity);\n\nvoid sb_append__2(system__text__String_Builder__0 *_Nonnull sb, string value);\nvoid sb_append_sb__2(system__text__String_Builder__0 *_Nonnull sb, system__text__String_Builder__0 const *_Nonnull value);\nvoid sb_append_line__2(system__text__String_Builder__0 *_Nonnull sb, string value);\nvoid sb_append_line__1(system__text__String_Builder__0 *_Nonnull sb);\nvoid sb_remove__3(system__text__String_Builder__0 *_Nonnull sb, int32 start, int32 length);\nvoid sb_remove__2(system__text__String_Builder__0 *_Nonnull sb, int32 start);\nstring sb_to_string__1(system__text__String_Builder__0 *_Nonnull sb);\n"});

	return main__2(allocate(sizeof(system__console__Console__0)), convert_arguments(argc, argv)).value;
}
