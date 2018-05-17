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
auto compile__1(system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const sources__) -> Package const *_Nonnull;
auto write__2(system__console__Console *_Nonnull const console__, system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull const diagnostics__) -> void;
auto has_errors__1(system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull const diagnostics__) -> bool__00;
auto main__2(system__console__Console *_Nonnull const console__, system__console__Arguments const *_Nonnull const args__) -> int__00;
auto read_source__1(string__00 const path__) -> Source_Text const *_Nonnull;
auto run_unit_tests__1(system__console__Console *_Nonnull const console__) -> void;
Source_Text *_Nonnull Source_Text__0new__3(Source_Text *_Nonnull self, string__00 const package__, string__00 const path__, string__00 const text__);
inline Source_Text *_Nonnull new_Source_Text(string__00 const package__, string__00 const path__, string__00 const text__);
auto line_starts__1(string__00 const text__) -> system__collections__List<int__00> const *_Nonnull;
auto source_byte_length__1(Source_Text const *_Nonnull const source__) -> int__00;
auto position_of_start__2(Source_Text const *_Nonnull const source__, Text_Span const *_Nonnull const span__) -> Text_Position const *_Nonnull;
Text_Line *_Nonnull Text_Line__0new__3(Text_Line *_Nonnull self, Source_Text const *_Nonnull const source__, int__00 const start__, int__00 const length__);
inline Text_Line *_Nonnull new_Text_Line(Source_Text const *_Nonnull const source__, int__00 const start__, int__00 const length__);
Text_Line *_Nonnull Text_Line__0new__spanning__3(Text_Line *_Nonnull self, Source_Text const *_Nonnull const source__, int__00 const start__, int__00 const end__);
inline Text_Line *_Nonnull new_Text_Line__spanning(Source_Text const *_Nonnull const source__, int__00 const start__, int__00 const end__);
Text_Lines *_Nonnull Text_Lines__0new__2(Text_Lines *_Nonnull self, Source_Text const *_Nonnull const source__, system__collections__List<int__00> const *_Nonnull const start_of_line__);
inline Text_Lines *_Nonnull new_Text_Lines(Source_Text const *_Nonnull const source__, system__collections__List<int__00> const *_Nonnull const start_of_line__);
auto line_count__1(Text_Lines const *_Nonnull const lines__) -> int__00;
auto get_line__2(Text_Lines const *_Nonnull const lines__, int__00 const line_number__) -> Text_Line const *_Nonnull;
auto line_containing_offset__2(Text_Lines const *_Nonnull const lines__, int__00 const character_offset__) -> int__00;
Text_Position *_Nonnull Text_Position__0new__3(Text_Position *_Nonnull self, int__00 const character_offset__, int__00 const line__, int__00 const column__);
inline Text_Position *_Nonnull new_Text_Position(int__00 const character_offset__, int__00 const line__, int__00 const column__);
auto unit_test_Text_Position__0() -> void;
auto Text_Position_retains_given_offeset_line_and_column__0() -> void;
Text_Span *_Nonnull Text_Span__0new__2(Text_Span *_Nonnull self, int__00 const start__, int__00 const length__);
inline Text_Span *_Nonnull new_Text_Span(int__00 const start__, int__00 const length__);
auto format_error__1(string__00 const message__) -> string__00;
Source_File_Builder *_Nonnull Source_File_Builder__0new__0(Source_File_Builder *_Nonnull self);
inline Source_File_Builder *_Nonnull new_Source_File_Builder();
auto error__2(Source_File_Builder *_Nonnull const file__, string__00 const message__) -> void;
auto begin_line__2(Source_File_Builder *_Nonnull const file__, string__00 const value__) -> void;
auto write__2(Source_File_Builder *_Nonnull const file__, string__00 const value__) -> void;
auto end_line__2(Source_File_Builder *_Nonnull const file__, string__00 const value__) -> void;
auto write_line__2(Source_File_Builder *_Nonnull const file__, string__00 const value__) -> void;
auto blank_line__1(Source_File_Builder *_Nonnull const file__) -> void;
auto element_separator_line__1(Source_File_Builder *_Nonnull const file__) -> void;
auto statement_separator_line__1(Source_File_Builder *_Nonnull const file__) -> void;
auto begin_block__1(Source_File_Builder *_Nonnull const file__) -> void;
auto end_block__1(Source_File_Builder *_Nonnull const file__) -> void;
auto end_block_with_semicolon__1(Source_File_Builder *_Nonnull const file__) -> void;
auto byte_length__1(Source_File_Builder const *_Nonnull const file__) -> int__00;
auto to_string__1(Source_File_Builder *_Nonnull const file__) -> string__00;
Compilation_Unit *_Nonnull Compilation_Unit__0new__2(Compilation_Unit *_Nonnull self, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__);
inline Compilation_Unit *_Nonnull new_Compilation_Unit(Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__);
auto collect_diagnostics__2(Compilation_Unit const *_Nonnull const compilation_unit__, system__collections__List<Diagnostic const *_Nonnull> *_Nonnull const diagnostics__) -> void;
Package *_Nonnull Package__0new__4(Package *_Nonnull self, Package_Name const *_Nonnull const name__, system__collections__List<Package_Reference> const *_Nonnull const references__, system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units__, Symbol const *_Nonnull const symbol__);
inline Package *_Nonnull new_Package(Package_Name const *_Nonnull const name__, system__collections__List<Package_Reference> const *_Nonnull const references__, system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units__, Symbol const *_Nonnull const symbol__);
auto all_diagnostics__1(Package const *_Nonnull const package__) -> system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull;
Package_Reference Package_Reference__0new__1(Package const *_Nonnull const package__);
inline Package_Reference new_Package_Reference(Package const *_Nonnull const package__);
Package_Reference Package_Reference__0new__2(string__00 const name__, Package const *_Nonnull const package__);
inline Package_Reference new_Package_Reference(string__00 const name__, Package const *_Nonnull const package__);
auto build_primitives_package__0() -> Package const *_Nonnull;
auto build_primitive_symbols__1(Package_Name const *_Nonnull const package_name__) -> system__collections__List<Symbol const *_Nonnull> *_Nonnull;
auto build_adamant_language_namespace_symbol__1(Name const *_Nonnull const global_namespace__) -> Symbol const *_Nonnull;
auto build_optional_type_symbol__1(Name const *_Nonnull const language_namespace__) -> Symbol const *_Nonnull;
auto build_primitive_symbol__2(string__00 const name__, Name const *_Nonnull const namespace__) -> Symbol const *_Nonnull;
auto build_fixed_point_primitives__3(system__collections__List<Symbol const *_Nonnull> *_Nonnull const symbols__, int__00 const bits__, Name const *_Nonnull const namespace__) -> void;
auto unit_test_build_primitives_package__0() -> void;
auto Package_name_is_dollar_primitives__0() -> void;
auto Package_has_no_references_or_compilation_units__0() -> void;
auto Package_symbol_has_package_name__0() -> void;
auto Package_symbol_has_children__0() -> void;
auto Package_contains_the_string_type__0() -> void;
auto Package_contains_optional_type__0() -> void;
auto build_runtime_library_package__0() -> Package const *_Nonnull;
auto build_runtime_library_symbols__1(Package_Name const *_Nonnull const package_name__) -> system__collections__List<Symbol const *_Nonnull> *_Nonnull;
auto build_function_symbol__1(Name const *_Nonnull const name__) -> Symbol const *_Nonnull;
auto build_namespace_symbol__2(Name const *_Nonnull const name__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const symbols__) -> Symbol const *_Nonnull;
auto build_class_symbol__2(Name const *_Nonnull const namespace__, string__00 const class_name__) -> Symbol const *_Nonnull;
auto build_class_symbol__3(Name const *_Nonnull const namespace__, string__00 const class_name__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__) -> Symbol const *_Nonnull;
auto build_generic_class_symbol__3(Name const *_Nonnull const namespace__, string__00 const class_name__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__) -> Symbol const *_Nonnull;
auto build_constructor_symbol__1(string__00 const name__) -> Symbol const *_Nonnull;
auto unit_test_build_runtime_library_package__0() -> void;
auto Runtime_Library_Package_contains_system_package__0() -> void;
auto System_namespace_contains_console_namespace__0() -> void;
auto Console_namespace_contains_Console_class__0() -> void;
auto System_namespace_contains_collections_namespace__0() -> void;
auto Collections_namespace_contains_List_class__0() -> void;
auto analyze_semantics__1(Syntax_Node const *_Nonnull const package_syntax__) -> Package const *_Nonnull;
Semantic_Node *_Nonnull Semantic_Node__0new__token__1(Semantic_Node *_Nonnull self, Syntax_Node const *_Nonnull const syntax__);
inline Semantic_Node *_Nonnull new_Semantic_Node__token(Syntax_Node const *_Nonnull const syntax__);
Semantic_Node *_Nonnull Semantic_Node__0new__concrete__2(Semantic_Node *_Nonnull self, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__);
inline Semantic_Node *_Nonnull new_Semantic_Node__concrete(Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__);
Semantic_Node *_Nonnull Semantic_Node__0new__of_type__3(Semantic_Node *_Nonnull self, Type const *_Nonnull const of_type__, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__);
inline Semantic_Node *_Nonnull new_Semantic_Node__of_type(Type const *_Nonnull const of_type__, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__);
Semantic_Node *_Nonnull Semantic_Node__0new__declares_type__3(Semantic_Node *_Nonnull self, Type const *_Nonnull const type__, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__);
inline Semantic_Node *_Nonnull new_Semantic_Node__declares_type(Type const *_Nonnull const type__, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__);
Semantic_Node *_Nonnull Semantic_Node__0new__referencing_type__3(Semantic_Node *_Nonnull self, Type const *_Nonnull const type__, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__);
inline Semantic_Node *_Nonnull new_Semantic_Node__referencing_type(Type const *_Nonnull const type__, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__);
auto get_text_span__1(Semantic_Node const *_Nonnull const node__) -> Text_Span const *_Nonnull;
auto get_text__1(Semantic_Node const *_Nonnull const node__) -> string__00;
auto first_child__2(Semantic_Node const *_Nonnull const node__, int__00 const kind__) -> Semantic_Node const *_Nullable;
auto children_of_kind__2(Semantic_Node const *_Nonnull const node__, int__00 const kind__) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull;
auto node_members__1(Semantic_Node const *_Nonnull const node__) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull;
auto node_statements__1(Semantic_Node const *_Nonnull const node__) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull;
auto node_parameters__1(Semantic_Node const *_Nonnull const node__) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull;
auto node_argument_count__1(Semantic_Node const *_Nonnull const node__) -> int__00;
auto node_access_modifier__1(Semantic_Node const *_Nonnull const node__) -> Semantic_Node const *_Nullable;
auto node_has_child__2(Semantic_Node const *_Nonnull const node__, int__00 const kind__) -> bool__00;
auto add_diagnostic__2(Semantic_Node *_Nonnull const node__, Diagnostic const *_Nonnull const diagnostic__) -> void;
auto diagnostics__1(Semantic_Node const *_Nonnull const node__) -> system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull;
auto collect_diagnostics__2(Semantic_Node const *_Nonnull const node__, system__collections__List<Diagnostic const *_Nonnull> *_Nonnull const diagnostics__) -> void;
Semantic_Tree_Builder *_Nonnull Semantic_Tree_Builder__0new__0(Semantic_Tree_Builder *_Nonnull self);
inline Semantic_Tree_Builder *_Nonnull new_Semantic_Tree_Builder();
auto build_compilation_units__3(Semantic_Tree_Builder const *_Nonnull const builder__, Syntax_Node const *_Nonnull const package_syntax__, Name_Table const *_Nonnull const name_table__) -> system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull;
auto build_compilation_unit_semantic_node__3(Semantic_Tree_Builder const *_Nonnull const builder__, Syntax_Node const *_Nonnull const compilation_unit_syntax__, Name_Table const *_Nonnull const name_table__) -> Compilation_Unit const *_Nonnull;
auto build_semantic_node__4(Semantic_Tree_Builder const *_Nonnull const builder__, Syntax_Node const *_Nonnull const syntax__, Name_Table const *_Nonnull const name_table__, Name_Subtable const *_Nonnull const scope__) -> Semantic_Node const *_Nonnull;
auto build_parameters_semantic_node__4(Semantic_Tree_Builder const *_Nonnull const builder__, Syntax_Node const *_Nonnull const parameters_syntax__, Name_Table const *_Nonnull const name_table__, Name_Subtable const *_Nonnull const scope__) -> Semantic_Node *_Nonnull;
auto build_type_name_semantic_node__4(Semantic_Tree_Builder const *_Nonnull const builder__, Syntax_Node const *_Nonnull const syntax__, Name_Table const *_Nonnull const name_table__, Name_Subtable const *_Nonnull const scope__) -> Semantic_Node *_Nonnull;
auto build_type_arguments_semantic_node__5(Semantic_Tree_Builder const *_Nonnull const builder__, Syntax_Node const *_Nonnull const syntax__, Name_Table const *_Nonnull const name_table__, Name_Subtable const *_Nonnull const scope__, system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const children__) -> system__collections__List<Type const *_Nonnull> const *_Nonnull;
auto build_constructor_name_semantic_node__4(Semantic_Tree_Builder const *_Nonnull const builder__, Syntax_Node const *_Nonnull const syntax__, Name_Table const *_Nonnull const name_table__, Name_Subtable const *_Nonnull const scope__) -> Semantic_Node const *_Nonnull;
auto add_resolution_error__1(Semantic_Node *_Nonnull const node__) -> void;
auto add_resolution_error__2(Semantic_Node *_Nonnull const node__, Semantic_Node const *_Nonnull const qualifier__) -> void;
auto add_could_not_determine_type_error__1(Semantic_Node *_Nonnull const node__) -> void;
auto build_symbols__2(Package_Name const *_Nonnull const package_name__, system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units__) -> Symbol const *_Nonnull;
Compilation_Unit_Parser *_Nonnull Compilation_Unit_Parser__0new__1(Compilation_Unit_Parser *_Nonnull self, Token_Stream *_Nonnull const token_stream__);
inline Compilation_Unit_Parser *_Nonnull new_Compilation_Unit_Parser(Token_Stream *_Nonnull const token_stream__);
auto parse__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull;
auto accept_token__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nullable;
auto expect_token__2(Compilation_Unit_Parser *_Nonnull const parser__, int__00 const tokenType__) -> Syntax_Node const *_Nonnull;
auto parse_type_name__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull;
auto parse_non_optional_type__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull;
auto parse_type__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull;
auto parse_atom__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull;
auto parse_call_arguments__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull;
auto parse_expression__2(Compilation_Unit_Parser *_Nonnull const parser__, int__00 const minPrecedence__) -> Syntax_Node const *_Nonnull;
auto parse_expression__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull;
auto parse_statement__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull;
auto parse_if_statement__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull;
auto parse_variable_declaration__2(Compilation_Unit_Parser *_Nonnull const parser__, bool__00 const allowInitializer__) -> Syntax_Node const *_Nonnull;
auto parse_block__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull;
auto parse_parameter_list__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull;
auto parse_member_declaration__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull;
auto parse_declaration__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull;
auto parse_compilation_unit__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull;
auto lexically_analyze__1(Source_Text const *_Nonnull const source__) -> Token_Stream *_Nonnull;
auto parse_package__1(system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const sources__) -> Syntax_Node const *_Nonnull;
Syntax_Node *_Nonnull Syntax_Node__0new__4(Syntax_Node *_Nonnull self, int__00 const type__, Source_Text const *_Nonnull const source__, uint__00 const start__, uint__00 const length__);
inline Syntax_Node *_Nonnull new_Syntax_Node(int__00 const type__, Source_Text const *_Nonnull const source__, uint__00 const start__, uint__00 const length__);
Syntax_Node *_Nonnull Syntax_Node__0new__5(Syntax_Node *_Nonnull self, int__00 const type__, bool__00 const isMissing__, Source_Text const *_Nonnull const source__, uint__00 const start__, uint__00 const length__);
inline Syntax_Node *_Nonnull new_Syntax_Node(int__00 const type__, bool__00 const isMissing__, Source_Text const *_Nonnull const source__, uint__00 const start__, uint__00 const length__);
Syntax_Node *_Nonnull Syntax_Node__0new__2(Syntax_Node *_Nonnull self, int__00 const type__, Syntax_Node const *_Nonnull const child__);
inline Syntax_Node *_Nonnull new_Syntax_Node(int__00 const type__, Syntax_Node const *_Nonnull const child__);
Syntax_Node *_Nonnull Syntax_Node__0new__2(Syntax_Node *_Nonnull self, int__00 const type__, system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const children__);
inline Syntax_Node *_Nonnull new_Syntax_Node(int__00 const type__, system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const children__);
Syntax_Node *_Nonnull Syntax_Node__0new__missing__3(Syntax_Node *_Nonnull self, int__00 const type__, Source_Text const *_Nonnull const source__, uint__00 const start__);
inline Syntax_Node *_Nonnull new_Syntax_Node__missing(int__00 const type__, Source_Text const *_Nonnull const source__, uint__00 const start__);
Syntax_Node *_Nonnull Syntax_Node__0new__skipped__1(Syntax_Node *_Nonnull self, Syntax_Node const *_Nonnull const skipped_node__);
inline Syntax_Node *_Nonnull new_Syntax_Node__skipped(Syntax_Node const *_Nonnull const skipped_node__);
Syntax_Node *_Nonnull Syntax_Node__0new__skipped__1(Syntax_Node *_Nonnull self, system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const skipped_nodes__);
inline Syntax_Node *_Nonnull new_Syntax_Node__skipped(system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const skipped_nodes__);
auto get_text__1(Syntax_Node const *_Nonnull const syntax__) -> string__00;
auto first_child_syntax__2(Syntax_Node const *_Nonnull const syntax__, int__00 const type__) -> Syntax_Node const *_Nullable;
auto has_child__2(Syntax_Node const *_Nonnull const syntax__, int__00 const type__) -> bool__00;
auto add__2(Syntax_Node const *_Nonnull const syntax__, Diagnostic const *_Nonnull const diagnostic__) -> void;
auto all_diagnostics__1(Syntax_Node const *_Nonnull const syntax__) -> system__collections__List<Diagnostic const *_Nonnull> *_Nonnull;
auto collect_syntax_diagnostics__2(Syntax_Node const *_Nonnull const syntax__, system__collections__List<Diagnostic const *_Nonnull> *_Nonnull const diagnostics__) -> void;
auto members__1(Syntax_Node const *_Nonnull const syntax__) -> system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull;
auto parameters__1(Syntax_Node const *_Nonnull const syntax__) -> system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull;
auto statements__1(Syntax_Node const *_Nonnull const syntax__) -> system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull;
auto access_modifier__1(Syntax_Node const *_Nonnull const syntax__) -> Syntax_Node const *_Nullable;
Token_Stream *_Nonnull Token_Stream__0new__1(Token_Stream *_Nonnull self, Source_Text const *_Nonnull const source__);
inline Token_Stream *_Nonnull new_Token_Stream(Source_Text const *_Nonnull const source__);
auto next_token__1(Token_Stream *_Nonnull const tokens__) -> Syntax_Node const *_Nullable;
auto end_of_file_token__1(Token_Stream *_Nonnull const tokens__) -> Syntax_Node const *_Nullable;
auto new_identifier_or_keyword_token__2(Token_Stream *_Nonnull const tokens__, uint__00 const end__) -> Syntax_Node const *_Nonnull;
auto new_operator_token__2(Token_Stream *_Nonnull const tokens__, int__00 const type__) -> Syntax_Node const *_Nonnull;
auto new_operator_token__3(Token_Stream *_Nonnull const tokens__, int__00 const type__, uint__00 const length__) -> Syntax_Node const *_Nonnull;
auto new_token__3(Token_Stream *_Nonnull const tokens__, int__00 const type__, uint__00 const end__) -> Syntax_Node const *_Nonnull;
auto is_identifier_char__1(code_point__00 const c__) -> bool__00;
auto is_number_char__1(code_point__00 const c__) -> bool__00;
Diagnostic *_Nonnull Diagnostic__0new__5(Diagnostic *_Nonnull self, int__00 const level__, int__00 const phase__, Source_Text const *_Nonnull const source__, Text_Span const *_Nonnull const span__, string__00 const message__);
inline Diagnostic *_Nonnull new_Diagnostic(int__00 const level__, int__00 const phase__, Source_Text const *_Nonnull const source__, Text_Span const *_Nonnull const span__, string__00 const message__);
Emitter *_Nonnull Emitter__0new__2(Emitter *_Nonnull self, Package const *_Nonnull const package__, system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const resources__);
inline Emitter *_Nonnull new_Emitter(Package const *_Nonnull const package__, system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const resources__);
auto emit__1(Emitter *_Nonnull const emitter__) -> string__00;
auto mangle_name__1(Type const *_Nonnull const type__) -> string__00;
auto mangle_function_name__2(string__00 const name__, int__00 const parameter_count__) -> string__00;
auto mangle_field_name__1(string__00 const name__) -> string__00;
auto contains_multi_underscore_runs__1(string__00 const value__) -> bool__00;
auto append_fixing_underscores__2(system__text__String_Builder *_Nonnull const builder__, string__00 const value__) -> void;
auto convert_primitive_type_name__1(Type const *_Nonnull const type__) -> string__00;
auto convert_type_name__1(Semantic_Node const *_Nonnull const type_node__) -> system__text__String_Builder *_Nonnull;
auto convert_type_name__1(Type const *_Nonnull const type__) -> system__text__String_Builder *_Nonnull;
auto convert_reference_type__3(bool__00 const mutable_binding__, Type const *_Nonnull type__, bool__00 const nullable__) -> string__00;
auto convert_type__3(bool__00 const mutable_binding__, Type const *_Nonnull type__, bool__00 const optional__) -> string__00;
auto convert_type__2(bool__00 const mutable_binding__, Semantic_Node const *_Nonnull const type_node__) -> string__00;
auto convert_parameter_list__4(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const parameters__, string__00 const self_type__, bool__00 const is_main_function__) -> string__00;
auto convert_method_parameter_list__3(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const parameters__, string__00 const self_type__) -> string__00;
auto convert_parameter_list__3(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const parameters__, bool__00 const is_main_function__) -> string__00;
auto convert_parameter_list__2(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const parameters__) -> string__00;
auto convert_expression__2(Semantic_Node const *_Nonnull const syntax__, Source_File_Builder *_Nonnull const builder__) -> void;
auto convert_member_access__2(Semantic_Node const *_Nonnull const lhs__, Source_File_Builder *_Nonnull const builder__) -> void;
auto emit_statement__2(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const statement__) -> void;
auto emit_method_body__3(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const block__, bool__00 const is_associated_function__) -> void;
auto emit_constructor_body__4(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const block__, string__00 const self_type__, bool__00 const is_value_type__) -> void;
auto emit_member_declaration__4(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const member__, string__00 const class_name__, bool__00 const is_value_type__) -> void;
auto emit_default_constructor__3(Emitter *_Nonnull const emitter__, string__00 const type_name__, bool__00 const is_value_type__) -> void;
auto emit_declaration__2(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const declaration__) -> void;
auto emit_compilation_unit__2(Emitter *_Nonnull const emitter__, Compilation_Unit const *_Nonnull const unit__) -> void;
auto emit_preamble__1(Emitter *_Nonnull const emitter__) -> void;
auto emit_entry_point_adapter__1(Emitter *_Nonnull const emitter__) -> void;
Name *_Nonnull Name__0new__global_namespace__0(Name *_Nonnull self);
inline Name *_Nonnull new_Name__global_namespace();
Name *_Nonnull Name__0new__global_namespace__1(Name *_Nonnull self, Package_Name const *_Nonnull const package__);
inline Name *_Nonnull new_Name__global_namespace(Package_Name const *_Nonnull const package__);
Name *_Nonnull Name__0new__3(Name *_Nonnull self, Name const *_Nonnull const qualifier__, int__00 const kind__, string__00 const name__);
inline Name *_Nonnull new_Name(Name const *_Nonnull const qualifier__, int__00 const kind__, string__00 const name__);
Name *_Nonnull Name__0new__4(Name *_Nonnull self, Name const *_Nonnull const qualifier__, int__00 const kind__, string__00 const name__, bool__00 const is_special__);
inline Name *_Nonnull new_Name(Name const *_Nonnull const qualifier__, int__00 const kind__, string__00 const name__, bool__00 const is_special__);
Name *_Nonnull Name__0new__special__3(Name *_Nonnull self, Name const *_Nonnull const qualifier__, int__00 const kind__, string__00 const name__);
inline Name *_Nonnull new_Name__special(Name const *_Nonnull const qualifier__, int__00 const kind__, string__00 const name__);
Name *_Nonnull Name__0new__4(Name *_Nonnull self, Package_Name const *_Nullable const package__, int__00 const kind__, system__collections__List<string__00> const *_Nonnull const segments__, bool__00 const is_special__);
inline Name *_Nonnull new_Name(Package_Name const *_Nullable const package__, int__00 const kind__, system__collections__List<string__00> const *_Nonnull const segments__, bool__00 const is_special__);
auto unqualified_name__1(Name const *_Nonnull const name__) -> string__00;
auto full_name__1(Name const *_Nonnull const name__) -> string__00;
auto is_qualified_by__2(Name const *_Nonnull const name__, Name const *_Nonnull const qualifier__) -> bool__00;
auto qualifier_is__2(Name const *_Nonnull const name__, Name const *_Nonnull const qualifier__) -> bool__00;
auto names__2(Name const *_Nonnull const name__, Name const *_Nonnull const other__) -> bool__00;
auto is_package_qualified__1(Name const *_Nonnull const name__) -> bool__00;
auto remove_package__1(Name const *_Nonnull const name__) -> Name const *_Nonnull;
auto unit_test_Name__0() -> void;
auto name_with_unspecified_package_names_name_with_package__0() -> void;
auto name_with_unspecified_package_names_itself__0() -> void;
Package_Name *_Nonnull Package_Name__0new__1(Package_Name *_Nonnull self, string__00 const name__);
inline Package_Name *_Nonnull new_Package_Name(string__00 const name__);
auto full_name__1(Package_Name const *_Nonnull const package_name__) -> string__00;
Symbol *_Nonnull Symbol__0new__identifier__1(Symbol *_Nonnull self, string__00 const name__);
inline Symbol *_Nonnull new_Symbol__identifier(string__00 const name__);
Symbol *_Nonnull Symbol__0new__identifier__2(Symbol *_Nonnull self, string__00 const name__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__);
inline Symbol *_Nonnull new_Symbol__identifier(string__00 const name__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__);
Symbol *_Nonnull Symbol__0new__identifier__2(Symbol *_Nonnull self, string__00 const name__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__);
inline Symbol *_Nonnull new_Symbol__identifier(string__00 const name__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__);
Symbol *_Nonnull Symbol__0new__constructor__2(Symbol *_Nonnull self, string__00 const name__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__);
inline Symbol *_Nonnull new_Symbol__constructor(string__00 const name__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__);
Symbol *_Nonnull Symbol__0new__package__2(Symbol *_Nonnull self, string__00 const name__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__);
inline Symbol *_Nonnull new_Symbol__package(string__00 const name__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__);
Symbol *_Nonnull Symbol__0new__declaring__3(Symbol *_Nonnull self, Type const *_Nonnull const declares_type__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__);
inline Symbol *_Nonnull new_Symbol__declaring(Type const *_Nonnull const declares_type__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__);
Symbol *_Nonnull Symbol__0new__of_type__4(Symbol *_Nonnull self, string__00 const name__, Type const *_Nonnull const of_type__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__);
inline Symbol *_Nonnull new_Symbol__of_type(string__00 const name__, Type const *_Nonnull const of_type__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__);
auto get_child__3(Symbol const *_Nonnull const symbol__, string__00 const name__, int__00 const kind__) -> Symbol const *_Nullable;
auto unit_test_Symbol__0() -> void;
auto Package_symbol_children_can_be_found_by_name_and_kind__0() -> void;
Type *_Nonnull Type__0new__3(Type *_Nonnull self, int__00 const kind__, Name const *_Nonnull const name__, bool__00 const is_mutable__);
inline Type *_Nonnull new_Type(int__00 const kind__, Name const *_Nonnull const name__, bool__00 const is_mutable__);
Type *_Nonnull Type__0new__parameter__1(Type *_Nonnull self, string__00 const name__);
inline Type *_Nonnull new_Type__parameter(string__00 const name__);
Type *_Nonnull Type__0new__4(Type *_Nonnull self, int__00 const kind__, Name const *_Nonnull const name__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__, bool__00 const is_mutable__);
inline Type *_Nonnull new_Type(int__00 const kind__, Name const *_Nonnull const name__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__, bool__00 const is_mutable__);
Type *_Nonnull Type__0new__primitive__1(Type *_Nonnull self, Name const *_Nonnull const name__);
inline Type *_Nonnull new_Type__primitive(Name const *_Nonnull const name__);
Type *_Nonnull Type__0new__primitive__2(Type *_Nonnull self, Name const *_Nonnull const name__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__);
inline Type *_Nonnull new_Type__primitive(Name const *_Nonnull const name__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__);
Type *_Nonnull Type__0new__namespace__1(Type *_Nonnull self, Name const *_Nonnull const name__);
inline Type *_Nonnull new_Type__namespace(Name const *_Nonnull const name__);
Type *_Nonnull Type__0new__generic__2(Type *_Nonnull self, Type const *_Nonnull const definition__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_arguments__);
inline Type *_Nonnull new_Type__generic(Type const *_Nonnull const definition__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_arguments__);
Type *_Nonnull Type__0new__6(Type *_Nonnull self, int__00 const kind__, Name const *_Nonnull const name__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__, bool__00 const is_primitive__, bool__00 const is_potentially_mutable__, bool__00 const is_mutable__);
inline Type *_Nonnull new_Type(int__00 const kind__, Name const *_Nonnull const name__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__, bool__00 const is_primitive__, bool__00 const is_potentially_mutable__, bool__00 const is_mutable__);
auto make_mutable_type__1(Type const *_Nonnull const type__) -> Type const *_Nonnull;
auto make_immutable_type__1(Type const *_Nonnull const type__) -> Type const *_Nonnull;
auto remove_type_package__1(Type const *_Nonnull const type__) -> Type const *_Nonnull;
Name_Subtable *_Nonnull Name_Subtable__0new__global_namespace__1(Name_Subtable *_Nonnull self, Name_Table const *_Nonnull const name_table__);
inline Name_Subtable *_Nonnull new_Name_Subtable__global_namespace(Name_Table const *_Nonnull const name_table__);
Name_Subtable *_Nonnull Name_Subtable__0new__global_namespace__2(Name_Subtable *_Nonnull self, Name_Table const *_Nonnull const name_table__, Package_Name const *_Nonnull const package_name__);
inline Name_Subtable *_Nonnull new_Name_Subtable__global_namespace(Name_Table const *_Nonnull const name_table__, Package_Name const *_Nonnull const package_name__);
Name_Subtable *_Nonnull Name_Subtable__0new__3(Name_Subtable *_Nonnull self, Name_Subtable const *_Nonnull const parent__, Name const *_Nonnull const name__, Type const *_Nonnull const type__);
inline Name_Subtable *_Nonnull new_Name_Subtable(Name_Subtable const *_Nonnull const parent__, Name const *_Nonnull const name__, Type const *_Nonnull const type__);
auto add_subtable__3(Name_Subtable *_Nonnull const scope__, Name const *_Nonnull const name__, Type const *_Nonnull const type__) -> void;
auto find__2(Name_Subtable const *_Nonnull const scope__, string__00 const name__) -> Name_Subtable *_Nullable;
auto find_special__2(Name_Subtable const *_Nonnull const scope__, string__00 const name__) -> Name_Subtable *_Nullable;
auto find__3(Name_Subtable const *_Nonnull const scope__, string__00 const name__, bool__00 const is_special__) -> Name_Subtable *_Nullable;
auto lookup__2(Name_Subtable const *_Nonnull const scope__, string__00 const name__) -> Name_Subtable *_Nullable;
auto lookup_special__2(Name_Subtable const *_Nonnull const scope__, string__00 const name__) -> Name_Subtable *_Nullable;
auto lookup__3(Name_Subtable const *_Nonnull const scope__, string__00 const name__, bool__00 const is_special__) -> Name_Subtable *_Nullable;
auto get_scope__2(Name_Subtable const *_Nonnull const scope__, Name const *_Nonnull const name__) -> Name_Subtable const *_Nullable;
auto bind_type__2(Name_Subtable *_Nonnull const scope__, Type const *_Nonnull const type__) -> void;
auto as_mut__1(Name_Subtable const *_Nonnull const scope__) -> Name_Subtable *_Nonnull;
auto unit_test_Name_Subtable__0() -> void;
auto global_namespace_contains_added_name__0() -> void;
auto namespace_contains_added_name__0() -> void;
Name_Table *_Nonnull Name_Table__0new__0(Name_Table *_Nonnull self);
inline Name_Table *_Nonnull new_Name_Table();
auto add_package__2(Name_Table *_Nonnull const name_table__, Package_Name const *_Nonnull const package_name__) -> Name const *_Nonnull;
auto add_name__3(Name_Table *_Nonnull const name_table__, Name const *_Nonnull const parent__, Symbol const *_Nonnull const symbol__) -> Name const *_Nonnull;
auto add_name__3(Name_Table *_Nonnull const name_table__, Name const *_Nonnull const name__, Type const *_Nonnull const type__) -> void;
auto get_name__2(Name_Table const *_Nonnull const name_table__, Name const *_Nonnull const name__) -> Name_Subtable const *_Nullable;
auto build_name_table__3(Package_Name const *_Nonnull const package_name__, Syntax_Node const *_Nonnull const package_syntax__, system__collections__List<Package_Reference> const *_Nonnull const references__) -> Name_Table const *_Nonnull;
auto add_referenced__2(Name_Table *_Nonnull const name_table__, system__collections__List<Package_Reference> const *_Nonnull const references__) -> void;
auto add_symbol__3(Name_Table *_Nonnull const name_table__, Name const *_Nonnull const parent__, Symbol const *_Nonnull const symbol__) -> void;
auto add_package__3(Name_Table *_Nonnull const name_table__, Package_Name const *_Nonnull const package_name__, Syntax_Node const *_Nonnull const package_syntax__) -> void;
auto add_compilation_unit__3(Name_Table *_Nonnull const name_table__, Name const *_Nonnull const global_namespace__, Syntax_Node const *_Nonnull const compilation_unit__) -> void;
auto add_syntax__3(Name_Table *_Nonnull const name_table__, Name const *_Nonnull const parent__, Syntax_Node const *_Nonnull const syntax__) -> void;
auto add_function__3(Name_Table *_Nonnull const name_table__, Name const *_Nonnull const name__, Syntax_Node const *_Nonnull const function__) -> void;
auto unit_test_Name_Table_Builder__0() -> void;
auto table_contains_referenced_child_names__0() -> void;
auto can_get_root_namespace_from_name__0() -> void;
auto can_get_Console_class_from_name_without_package__0() -> void;
auto can_get_Optional_class_from_name_with_package__0() -> void;

// Class Declarations

struct Source_Text
{
	string__00 package__;
	string__00 path__;
	string__00 name__;
	string__00 text__;
	Text_Lines const *_Nonnull lines__;
};

struct Text_Line
{
	Source_Text const *_Nonnull source__;
	int__00 start__;
	int__00 byte_length__;
};

struct Text_Lines
{
	Source_Text const *_Nonnull source__;
	system__collections__List<int__00> const *_Nonnull start_of_line__;
};

struct Text_Position
{
	int__00 character_offset__;
	int__00 line__;
	int__00 column__;
};

struct Text_Span
{
	int__00 start__;
	int__00 byte_length__;
};

struct Source_File_Builder
{
	system__text__String_Builder *_Nonnull code__;
	system__text__String_Builder *_Nonnull indent__;
	bool__00 firstElement__;
	bool__00 afterBlock__;
};

struct Compilation_Unit
{
	Syntax_Node const *_Nonnull syntax__;
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull declarations__;
};

struct Package
{
	Package_Name const *_Nonnull name__;
	system__collections__List<Package_Reference> const *_Nonnull references__;
	system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull compilation_units__;
	Symbol const *_Nonnull symbol__;
};

struct Package_Reference
{
	Package_Reference * operator->() { return this; }
	Package_Reference const * operator->() const { return this; }
	Package_Reference & operator* () { return *this; }
	Package_Reference const & operator* () const { return *this; }
	string__00 name__;
	Package const *_Nonnull package__;
};

struct Semantic_Node
{
	Syntax_Node const *_Nonnull syntax__;
	int__00 kind__;
	bool__00 is_missing__;
	Source_Text const *_Nonnull source__;
	uint__00 start__;
	uint__00 byte_length__;
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull children__;
	system__collections__List<Diagnostic const *_Nonnull> *_Nonnull node_diagnostics__;
	Type const *_Nullable of_type__;
	Type const *_Nullable converted_type__;
	Type const *_Nullable declares_type__;
	Type const *_Nullable referenced_type__;
};

struct Semantic_Tree_Builder
{
	Name const *_Nonnull optional_type_name__;
};

struct Compilation_Unit_Parser
{
	Token_Stream *_Nonnull token_stream__;
	Syntax_Node const *_Nullable token__;
	Syntax_Node const *_Nullable compilation_unit__;
};

struct Syntax_Node
{
	int__00 kind__;
	bool__00 is_missing__;
	Source_Text const *_Nonnull source__;
	uint__00 start__;
	uint__00 byte_length__;
	system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull children__;
	system__collections__List<Diagnostic const *_Nonnull> *_Nonnull node_diagnostics__;
};

struct Token_Stream
{
	Source_Text const *_Nonnull source__;
	uint__00 position__;
	system__collections__List<Diagnostic const *_Nonnull> *_Nonnull diagnostics__;
	bool__00 end_of_file__;
};

struct Diagnostic
{
	int__00 level__;
	int__00 phase__;
	Source_Text const *_Nonnull source__;
	Text_Span const *_Nonnull span__;
	Text_Position const *_Nonnull position__;
	string__00 message__;
};

struct Emitter
{
	Package const *_Nonnull package__;
	system__collections__List<Source_Text const *_Nonnull> const *_Nonnull resources__;
	Source_File_Builder *_Nonnull type_declarations__;
	Source_File_Builder *_Nonnull function_declarations__;
	Source_File_Builder *_Nonnull class_declarations__;
	Source_File_Builder *_Nonnull global_definitions__;
	Source_File_Builder *_Nonnull definitions__;
	string__00 main_function_name__;
	string__00 main_function_return_type__;
	bool__00 main_function_accepts_console__;
	bool__00 main_function_accepts_args__;
};

struct Name
{
	Package_Name const *_Nullable package__;
	int__00 kind__;
	system__collections__List<string__00> const *_Nonnull segments__;
	bool__00 is_special__;
};

struct Package_Name
{
	string__00 unqualified__;
};

struct Symbol
{
	string__00 name__;
	bool__00 is_special_name__;
	int__00 kind__;
	Type const *_Nonnull of_type__;
	Type const *_Nonnull declares_type__;
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull declarations__;
	system__collections__List<Symbol const *_Nonnull> const *_Nonnull children__;
};

struct Type
{
	int__00 kind__;
	Name const *_Nonnull name__;
	system__collections__List<Type const *_Nonnull> const *_Nonnull type_parameters__;
	bool__00 is_primitive__;
	bool__00 is_value_type__;
	bool__00 is_potentially_mutable__;
	bool__00 is_mutable__;
};

struct Name_Subtable
{
	Name_Table const *_Nonnull name_table__;
	Name_Subtable const *_Nullable parent__;
	Name const *_Nonnull name__;
	Type const *_Nonnull type__;
	system__collections__List<Name_Subtable *_Nonnull> *_Nonnull subtables__;
};

struct Name_Table
{
	Name_Subtable *_Nonnull any_package__;
	system__collections__List<Name_Subtable *_Nonnull> *_Nonnull packages__;
};

// Global Definitions
int__00 const Success__ = int__00(0);
int__00 const UsageError__ = int__00(64);
int__00 const DataError__ = int__00(65);
int__00 const SkippedTokens__ = int__00__0op__negate(int__00(1));
int__00 const EndOfFileToken__ = int__00(0);
int__00 const LeftBrace__ = int__00(1);
int__00 const RightBrace__ = int__00(2);
int__00 const LeftParen__ = int__00(3);
int__00 const RightParen__ = int__00(4);
int__00 const Semicolon__ = int__00(5);
int__00 const Comma__ = int__00(6);
int__00 const Dot__ = int__00(7);
int__00 const Colon__ = int__00(8);
int__00 const LeftBracket__ = int__00(9);
int__00 const RightBracket__ = int__00(10);
int__00 const Question__ = int__00(11);
int__00 const EqualsEquals__ = int__00(12);
int__00 const Equals__ = int__00(13);
int__00 const PlusEquals__ = int__00(14);
int__00 const Plus__ = int__00(15);
int__00 const Arrow__ = int__00(16);
int__00 const MinusEquals__ = int__00(17);
int__00 const Minus__ = int__00(18);
int__00 const Slash__ = int__00(19);
int__00 const EqualsSlashEquals__ = int__00(20);
int__00 const LessThanEquals__ = int__00(21);
int__00 const LessThan__ = int__00(22);
int__00 const GreaterThanEquals__ = int__00(23);
int__00 const GreaterThan__ = int__00(24);
int__00 const StringLiteral__ = int__00(25);
int__00 const CodePointLiteral__ = int__00(26);
int__00 const Identifier__ = int__00(27);
int__00 const Number__ = int__00(28);
int__00 const NewKeyword__ = int__00(29);
int__00 const NotOperator__ = int__00(30);
int__00 const NullReservedWord__ = int__00(31);
int__00 const SelfKeyword__ = int__00(32);
int__00 const TrueKeyword__ = int__00(33);
int__00 const FalseKeyword__ = int__00(34);
int__00 const IdentifierName__ = int__00(35);
int__00 const GenericName__ = int__00(36);
int__00 const QualifiedName__ = int__00(37);
int__00 const PackageQualifiedName__ = int__00(38);
int__00 const MutableKeyword__ = int__00(39);
int__00 const OptionalType__ = int__00(40);
int__00 const PredefinedType__ = int__00(41);
int__00 const CodePoint__ = int__00(42);
int__00 const String__ = int__00(43);
int__00 const Int__ = int__00(44);
int__00 const Bool__ = int__00(45);
int__00 const Void__ = int__00(46);
int__00 const UnsignedInt__ = int__00(47);
int__00 const ParameterList__ = int__00(48);
int__00 const Parameter__ = int__00(49);
int__00 const SelfParameter__ = int__00(50);
int__00 const VarKeyword__ = int__00(51);
int__00 const MutableType__ = int__00(52);
int__00 const NewExpression__ = int__00(53);
int__00 const ArgumentList__ = int__00(54);
int__00 const NotExpression__ = int__00(55);
int__00 const ParenthesizedExpression__ = int__00(56);
int__00 const NoneLiteralExpression__ = int__00(57);
int__00 const SelfExpression__ = int__00(58);
int__00 const TrueLiteralExpression__ = int__00(59);
int__00 const FalseLiteralExpression__ = int__00(60);
int__00 const StringLiteralExpression__ = int__00(61);
int__00 const CodePointLiteralExpression__ = int__00(62);
int__00 const NumericLiteralExpression__ = int__00(63);
int__00 const AssignmentExpression__ = int__00(64);
int__00 const OrExpression__ = int__00(65);
int__00 const AndExpression__ = int__00(66);
int__00 const EqualExpression__ = int__00(67);
int__00 const NotEqualExpression__ = int__00(68);
int__00 const AndKeyword__ = int__00(69);
int__00 const OrKeyword__ = int__00(70);
int__00 const ComparisonExpression__ = int__00(71);
int__00 const AddExpression__ = int__00(72);
int__00 const SubtractExpression__ = int__00(73);
int__00 const InvocationExpression__ = int__00(74);
int__00 const MemberAccessExpression__ = int__00(75);
int__00 const ElementAccessExpression__ = int__00(76);
int__00 const NegateExpression__ = int__00(77);
int__00 const ReturnKeyword__ = int__00(78);
int__00 const ReturnStatement__ = int__00(79);
int__00 const LoopKeyword__ = int__00(80);
int__00 const LoopStatement__ = int__00(81);
int__00 const Block__ = int__00(82);
int__00 const WhileKeyword__ = int__00(83);
int__00 const WhileStatement__ = int__00(84);
int__00 const ForKeyword__ = int__00(85);
int__00 const ForStatement__ = int__00(86);
int__00 const LetKeyword__ = int__00(87);
int__00 const VariableDeclaration__ = int__00(88);
int__00 const LocalDeclarationStatement__ = int__00(89);
int__00 const InKeyword__ = int__00(90);
int__00 const DoKeyword__ = int__00(91);
int__00 const DoWhileStatement__ = int__00(92);
int__00 const IfKeyword__ = int__00(93);
int__00 const ElseKeyword__ = int__00(94);
int__00 const IfStatement__ = int__00(95);
int__00 const ElseClause__ = int__00(96);
int__00 const BreakKeyword__ = int__00(97);
int__00 const BreakStatement__ = int__00(98);
int__00 const ContinueKeyword__ = int__00(99);
int__00 const ContinueStatement__ = int__00(100);
int__00 const ExpressionStatement__ = int__00(101);
int__00 const PublicKeyword__ = int__00(102);
int__00 const ProtectedKeyword__ = int__00(103);
int__00 const InternalKeyword__ = int__00(104);
int__00 const PrivateKeyword__ = int__00(105);
int__00 const ConstructorDeclaration__ = int__00(106);
int__00 const FieldDeclaration__ = int__00(107);
int__00 const MethodDeclaration__ = int__00(108);
int__00 const GlobalDeclaration__ = int__00(109);
int__00 const ClassKeyword__ = int__00(110);
int__00 const ClassDeclaration__ = int__00(111);
int__00 const EnumKeyword__ = int__00(112);
int__00 const StructKeyword__ = int__00(113);
int__00 const EnumDeclaration__ = int__00(114);
int__00 const EnumMemberDeclaration__ = int__00(115);
int__00 const FunctionDeclaration__ = int__00(116);
int__00 const CompilationUnit__ = int__00(117);
int__00 const PackageNode__ = int__00(118);
int__00 const Percent__ = int__00(119);
int__00 const RemainderExpression__ = int__00(120);
int__00 const Pipe__ = int__00(121);
int__00 const MagnitudeExpression__ = int__00(122);
int__00 const Asterisk__ = int__00(123);
int__00 const MultiplyExpression__ = int__00(124);
int__00 const DivideExpression__ = int__00(125);
int__00 const NoneKeyword__ = int__00(126);
int__00 const StructDeclaration__ = int__00(127);
int__00 const ImmutableType__ = int__00(128);
int__00 const NamespaceDeclaration__ = int__00(129);
int__00 const Lexing__ = int__00(1);
int__00 const Parsing__ = int__00(2);
int__00 const Analysis__ = int__00(3);
int__00 const Info__ = int__00(1);
int__00 const Warning__ = int__00(2);
int__00 const RuntimeError__ = int__00(3);
int__00 const CompilationError__ = int__00(4);
int__00 const FatalCompilationError__ = int__00(5);
int__00 const NamespaceName__ = int__00(1);
int__00 const TypeName__ = int__00(2);
int__00 const FunctionName__ = int__00(3);
int__00 const TypeParameterName__ = int__00(4);
int__00 const VariableName__ = int__00(5);
int__00 const IdentifierSymbol__ = int__00(0);
int__00 const PackageSymbol__ = int__00(1);
int__00 const ReferenceType__ = int__00(1);
int__00 const ValueType__ = int__00(2);
int__00 const NamespaceType__ = int__00(3);
int__00 const TypeParameterType__ = int__00(4);
int__00 const FunctionType__ = int__00(5);

// Definitions

auto compile__1(system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const sources__) -> Package const *_Nonnull
{
	Syntax_Node const *_Nonnull const package_syntax__ = parse_package__1(sources__);
	Package const *_Nonnull const package__ = analyze_semantics__1(package_syntax__);
	return package__;
}

auto write__2(system__console__Console *_Nonnull const console__, system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull const diagnostics__) -> void
{
	for (Diagnostic const *_Nonnull const diagnostic__ : *(diagnostics__))
	{
		Text_Position const *_Nonnull const position__ = diagnostic__->position__;
		string__00 severity__;
		if (cond(equal_op(diagnostic__->level__, Info__)))
		{
			severity__ = string__00("Informational");
		}
		else if (cond(equal_op(diagnostic__->level__, Warning__)))
		{
			severity__ = string__00("Warning");
		}
		else
		{
			severity__ = string__00("Error");
		}

		console__->WriteLine__1(diagnostic__->source__->path__->op__add(string__00(":"))->op__add(position__->line__)->op__add(string__00(":"))->op__add(position__->column__)->op__add(string__00(" "))->op__add(severity__)->op__add(string__00(":")));
		console__->WriteLine__1(string__00("  ").op__add(diagnostic__->message__));
	}
}

auto has_errors__1(system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull const diagnostics__) -> bool__00
{
	for (Diagnostic const *_Nonnull const diagnostic__ : *(diagnostics__))
	{
		if (cond(diagnostic__->level__->op__greater_than_or_equal(CompilationError__)))
		{
			return true__00;
		}
	}

	return false__00;
}

auto main__2(system__console__Console *_Nonnull const console__, system__console__Arguments const *_Nonnull const args__) -> int__00
{
	if (cond(bool__00__op(bool__00__arg(equal_op(args__->op__magnitude(), int__00(1))) && bool__00__arg(equal_op(args__->op__Element(int__00(0)), string__00("--unit-test"))))))
	{
		run_unit_tests__1(console__);
		return int__00(0);
	}

	system__collections__List<string__00> *_Nonnull const sourceFilePaths__ = new_system__collections__List<string__00>();
	system__collections__List<string__00> *_Nonnull const resourceFilePaths__ = new_system__collections__List<string__00>();
	string__00 outputFilePath__ = string__00("");
	bool__00 verbose__ = false__00;
	int__00 argType__ = int__00(0);
	for (string__00 const arg__ : *(args__))
	{
		if (cond(equal_op(argType__, int__00(0))))
		{
			if (cond(equal_op(arg__, string__00("-r"))))
			{
				argType__ = int__00(1);
			}
			else if (cond(equal_op(arg__, string__00("-o"))))
			{
				argType__ = int__00(2);
			}
			else if (cond(bool__00__op(bool__00__arg(equal_op(arg__, string__00("-v"))) || bool__00__arg(equal_op(arg__, string__00("--verbose"))))))
			{
				verbose__ = true__00;
			}
			else
			{
				sourceFilePaths__->add__1(arg__);
			}
		}
		else if (cond(equal_op(argType__, int__00(1))))
		{
			resourceFilePaths__->add__1(arg__);
			argType__ = int__00(0);
		}
		else if (cond(equal_op(argType__, int__00(2))))
		{
			outputFilePath__ = arg__;
			argType__ = int__00(0);
		}
	}

	if (cond(verbose__))
	{
		console__->WriteLine__1(string__00("Adamant Compiler v0.1.0"));
	}

	if (cond(bool__00__op(bool__00__arg(equal_op(sourceFilePaths__->op__magnitude(), int__00(0))) || bool__00__arg(equal_op(outputFilePath__, string__00(""))))))
	{
		console__->WriteLine__1(string__00("Args: <Input File(s)> -o <OutputFile> -r <Resource File>"));
		return UsageError__;
	}

	system__collections__List<Source_Text const *_Nonnull> *_Nonnull const resources__ = new_system__collections__List<Source_Text const *_Nonnull>();
	if (cond(resourceFilePaths__->op__magnitude()->op__greater_than(int__00(0))))
	{
		if (cond(verbose__))
		{
			console__->WriteLine__1(string__00("Reading Resources:"));
		}

		for (string__00 const resourceFilePath__ : *(resourceFilePaths__))
		{
			if (cond(verbose__))
			{
				console__->WriteLine__1(string__00("  ").op__add(resourceFilePath__));
			}

			resources__->add__1(read_source__1(resourceFilePath__));
		}
	}

	if (cond(verbose__))
	{
		console__->WriteLine__1(string__00("Compiling:"));
	}

	system__collections__List<Source_Text const *_Nonnull> *_Nonnull const sources__ = new_system__collections__List<Source_Text const *_Nonnull>();
	for (string__00 const sourceFilePath__ : *(sourceFilePaths__))
	{
		if (cond(verbose__))
		{
			console__->WriteLine__1(string__00("  ").op__add(sourceFilePath__));
		}

		sources__->add__1(read_source__1(sourceFilePath__));
	}

	Package const *_Nonnull const package__ = compile__1(sources__);
	system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull const diagnostics__ = all_diagnostics__1(package__);
	write__2(console__, diagnostics__);
	if (cond(has_errors__1(diagnostics__)))
	{
		return DataError__;
	}

	Emitter *_Nonnull emitter__ = new_Emitter(package__, resources__);
	string__00 const translated__ = emit__1(emitter__);
	if (cond(verbose__))
	{
		console__->Write__1(string__00("Output: "));
		console__->WriteLine__1(outputFilePath__);
	}

	system__io__File_Writer *_Nonnull const outputFile__ = new_system__io__File_Writer(outputFilePath__);
	outputFile__->Write__1(translated__);
	outputFile__->Close__0();
	string__00 outputDirPath__ = outputFilePath__;
	int__00 index__ = outputDirPath__.LastIndexOf__1(code_point__00('/'));
	if (cond(not_equal_op(index__, int__00__0op__negate(int__00(1)))))
	{
		outputDirPath__ = outputDirPath__.Substring__2(int__00(0), index__.op__add(int__00(1)));
	}

	index__ = outputDirPath__.LastIndexOf__1(code_point__00('\\'));
	if (cond(not_equal_op(index__, int__00__0op__negate(int__00(1)))))
	{
		outputDirPath__ = outputDirPath__.Substring__2(int__00(0), index__.op__add(int__00(1)));
	}

	if (cond(verbose__))
	{
		console__->Write__1(string__00("Outputting RuntimeLibrary to: "));
		console__->WriteLine__1(outputDirPath__);
	}

	system__io__File_Writer *_Nonnull resourceFile__ = new_system__io__File_Writer(outputDirPath__.op__add(string__00("RuntimeLibrary.hpp")));
	resourceFile__->Write__1(resource_manager__->GetString__1(string__00("RuntimeLibrary.hpp")));
	resourceFile__->Close__0();
	resourceFile__ = new_system__io__File_Writer(outputDirPath__.op__add(string__00("RuntimeLibrary.cpp")));
	resourceFile__->Write__1(resource_manager__->GetString__1(string__00("RuntimeLibrary.cpp")));
	resourceFile__->Close__0();
	return Success__;
}

auto read_source__1(string__00 const path__) -> Source_Text const *_Nonnull
{
	system__io__File_Reader *_Nonnull const file__ = new_system__io__File_Reader(path__);
	string__00 const contents__ = file__->ReadToEndSync__0();
	file__->Close__0();
	return new_Source_Text(string__00("<default>"), path__, contents__);
}

auto run_unit_tests__1(system__console__Console *_Nonnull const console__) -> void
{
	console__->WriteLine__1(string__00("Running Unit Tests..."));
	unit_test_Text_Position__0();
	unit_test_build_primitives_package__0();
	unit_test_build_runtime_library_package__0();
	unit_test_Name__0();
	unit_test_Name_Subtable__0();
	unit_test_Name_Table_Builder__0();
	unit_test_Symbol__0();
}

Source_Text *_Nonnull Source_Text__0new__3(Source_Text *_Nonnull self, string__00 const package__, string__00 const path__, string__00 const text__)
{
	self->package__ = package__;
	self->path__ = path__;
	string__00 name__ = path__;
	int__00 index__ = name__.LastIndexOf__1(code_point__00('/'));
	if (cond(not_equal_op(index__, int__00__0op__negate(int__00(1)))))
	{
		name__ = name__.Substring__1(index__.op__add(int__00(1)));
	}

	index__ = name__.LastIndexOf__1(code_point__00('\\'));
	if (cond(not_equal_op(index__, int__00__0op__negate(int__00(1)))))
	{
		name__ = name__.Substring__1(index__.op__add(int__00(1)));
	}

	self->name__ = name__;
	self->text__ = text__;
	self->lines__ = new_Text_Lines(self, line_starts__1(text__));
	return self;
}

inline Source_Text *_Nonnull new_Source_Text(string__00 const package__, string__00 const path__, string__00 const text__)
{
	return Source_Text__0new__3(new Source_Text(), package__, path__, text__);
}

auto line_starts__1(string__00 const text__) -> system__collections__List<int__00> const *_Nonnull
{
	int__00 const length__ = text__.ByteLength__0();
	system__collections__List<int__00> *_Nonnull const starting_positions__ = new_system__collections__List<int__00>();
	starting_positions__->add__1(int__00(0));
	int__00 position__ = int__00(0);
	while (cond(int__00__0op__less_than(position__, length__)))
	{
		code_point__00 const c__ = text__.op__Element(position__);
		position__.op__add_assign(int__00(1));
		if (cond(bool__00__op(bool__00__arg(code_point__00__0op__greater_than(c__, code_point__00('\r'))) && bool__00__arg(code_point__00__0op__less_than_or_equal(c__, code_point__00('\x7F'))))))
		{
			continue;
		}

		if (cond(equal_op(c__, code_point__00('\r'))))
		{
			if (cond(bool__00__op(bool__00__arg(int__00__0op__less_than(position__, length__)) && bool__00__arg(equal_op(text__.op__Element(position__), code_point__00('\n'))))))
			{
				position__.op__add_assign(int__00(1));
			}
		}
		else if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(c__, code_point__00('\n'))) || bool__00__arg(equal_op(c__, code_point__00('\x0B'))))) || bool__00__arg(equal_op(c__, code_point__00('\f'))))) || bool__00__arg(equal_op(c__, code_point__00('\x85'))))))
		{
		}
		else
		{
			continue;
		}

		starting_positions__->add__1(position__);
	}

	return starting_positions__;
}

auto source_byte_length__1(Source_Text const *_Nonnull const source__) -> int__00
{
	return source__->text__.ByteLength__0();
}

auto position_of_start__2(Source_Text const *_Nonnull const source__, Text_Span const *_Nonnull const span__) -> Text_Position const *_Nonnull
{
	int__00 const char_offset__ = span__->start__;
	int__00 const line_number__ = line_containing_offset__2(source__->lines__, char_offset__);
	int__00 const line_start__ = get_line__2(source__->lines__, line_number__)->start__;
	int__00 column__ = char_offset__.op__subtract(line_start__)->op__add(int__00(1));
	int__00 i__ = line_start__;
	while (cond(int__00__0op__less_than(i__, char_offset__)))
	{
		if (cond(equal_op(source__->text__.op__Element(i__), code_point__00('\t'))))
		{
			column__.op__add_assign(int__00(3));
		}

		i__.op__add_assign(int__00(1));
	}

	return new_Text_Position(char_offset__, line_number__, column__);
}

Text_Line *_Nonnull Text_Line__0new__3(Text_Line *_Nonnull self, Source_Text const *_Nonnull const source__, int__00 const start__, int__00 const length__)
{
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = length__;
	return self;
}

inline Text_Line *_Nonnull new_Text_Line(Source_Text const *_Nonnull const source__, int__00 const start__, int__00 const length__)
{
	return Text_Line__0new__3(new Text_Line(), source__, start__, length__);
}

Text_Line *_Nonnull Text_Line__0new__spanning__3(Text_Line *_Nonnull self, Source_Text const *_Nonnull const source__, int__00 const start__, int__00 const end__)
{
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = end__.op__subtract(start__);
	return self;
}

inline Text_Line *_Nonnull new_Text_Line__spanning(Source_Text const *_Nonnull const source__, int__00 const start__, int__00 const end__)
{
	return Text_Line__0new__spanning__3(new Text_Line(), source__, start__, end__);
}

Text_Lines *_Nonnull Text_Lines__0new__2(Text_Lines *_Nonnull self, Source_Text const *_Nonnull const source__, system__collections__List<int__00> const *_Nonnull const start_of_line__)
{
	self->source__ = source__;
	self->start_of_line__ = start_of_line__;
	return self;
}

inline Text_Lines *_Nonnull new_Text_Lines(Source_Text const *_Nonnull const source__, system__collections__List<int__00> const *_Nonnull const start_of_line__)
{
	return Text_Lines__0new__2(new Text_Lines(), source__, start_of_line__);
}

auto line_count__1(Text_Lines const *_Nonnull const lines__) -> int__00
{
	return lines__->start_of_line__->op__magnitude();
}

auto get_line__2(Text_Lines const *_Nonnull const lines__, int__00 const line_number__) -> Text_Line const *_Nonnull
{
	assert__2(int__00__0op__greater_than(line_number__, int__00(0)), string__00("line ").op__add(line_number__));
	assert__2(int__00__0op__less_than_or_equal(line_number__, line_count__1(lines__)), string__00("line ").op__add(line_number__));
	int__00 const line_index__ = line_number__.op__subtract(int__00(1));
	int__00 const line_start__ = lines__->start_of_line__->op__Element(line_index__);
	if (cond(equal_op(line_index__, line_count__1(lines__)->op__subtract(int__00(1)))))
	{
		return new_Text_Line__spanning(lines__->source__, line_start__, source_byte_length__1(lines__->source__));
	}

	int__00 const line_end__ = lines__->start_of_line__->op__Element(line_index__.op__add(int__00(1)));
	return new_Text_Line__spanning(lines__->source__, line_start__, line_end__);
}

auto line_containing_offset__2(Text_Lines const *_Nonnull const lines__, int__00 const character_offset__) -> int__00
{
	assert__2(int__00__0op__greater_than_or_equal(character_offset__, int__00(0)), string__00("offset ").op__add(character_offset__));
	assert__2(int__00__0op__less_than_or_equal(character_offset__, source_byte_length__1(lines__->source__)), string__00("offset ").op__add(character_offset__)->op__add(string__00(" source length "))->op__add(source_byte_length__1(lines__->source__)));
	int__00 left__ = int__00(0);
	int__00 right__ = line_count__1(lines__)->op__subtract(int__00(1));
	while (cond(int__00__0op__less_than_or_equal(left__, right__)))
	{
		int__00 const mid__ = left__.op__add(right__.op__subtract(left__)->op__divide(int__00(2)));
		int__00 const mid_line_start__ = lines__->start_of_line__->op__Element(mid__);
		if (cond(int__00__0op__less_than(mid_line_start__, character_offset__)))
		{
			left__ = mid__.op__add(int__00(1));
		}
		else if (cond(int__00__0op__greater_than(mid_line_start__, character_offset__)))
		{
			right__ = mid__.op__subtract(int__00(1));
		}
		else
		{
			return mid__.op__add(int__00(1));
		}
	}

	return left__;
}

Text_Position *_Nonnull Text_Position__0new__3(Text_Position *_Nonnull self, int__00 const character_offset__, int__00 const line__, int__00 const column__)
{
	self->character_offset__ = character_offset__;
	self->line__ = line__;
	self->column__ = column__;
	return self;
}

inline Text_Position *_Nonnull new_Text_Position(int__00 const character_offset__, int__00 const line__, int__00 const column__)
{
	return Text_Position__0new__3(new Text_Position(), character_offset__, line__, column__);
}

auto unit_test_Text_Position__0() -> void
{
	Text_Position_retains_given_offeset_line_and_column__0();
}

auto Text_Position_retains_given_offeset_line_and_column__0() -> void
{
	Text_Position const *_Nonnull const position__ = new_Text_Position(int__00(23), int__00(2), int__00(5));
	assert__2(equal_op(position__->character_offset__, int__00(23)), string__00(""));
	assert__2(equal_op(position__->line__, int__00(2)), string__00(""));
	assert__2(equal_op(position__->column__, int__00(5)), string__00(""));
}

Text_Span *_Nonnull Text_Span__0new__2(Text_Span *_Nonnull self, int__00 const start__, int__00 const length__)
{
	self->start__ = start__;
	self->byte_length__ = length__;
	return self;
}

inline Text_Span *_Nonnull new_Text_Span(int__00 const start__, int__00 const length__)
{
	return Text_Span__0new__2(new Text_Span(), start__, length__);
}

auto format_error__1(string__00 const message__) -> string__00
{
	return string__00("<$ ").op__add(message__)->op__add(string__00(" $>"));
}

Source_File_Builder *_Nonnull Source_File_Builder__0new__0(Source_File_Builder *_Nonnull self)
{
	self->code__ = new_system__text__String_Builder();
	self->indent__ = new_system__text__String_Builder();
	self->firstElement__ = true__00;
	self->afterBlock__ = true__00;
	return self;
}

inline Source_File_Builder *_Nonnull new_Source_File_Builder()
{
	return Source_File_Builder__0new__0(new Source_File_Builder());
}

auto error__2(Source_File_Builder *_Nonnull const file__, string__00 const message__) -> void
{
	file__->code__->Append__1(format_error__1(message__));
}

auto begin_line__2(Source_File_Builder *_Nonnull const file__, string__00 const value__) -> void
{
	file__->code__->Append__1(file__->indent__);
	file__->code__->Append__1(value__);
	file__->firstElement__ = file__->afterBlock__ = false__00;
}

auto write__2(Source_File_Builder *_Nonnull const file__, string__00 const value__) -> void
{
	file__->code__->Append__1(value__);
	file__->firstElement__ = file__->afterBlock__ = false__00;
}

auto end_line__2(Source_File_Builder *_Nonnull const file__, string__00 const value__) -> void
{
	file__->code__->Append__1(value__);
	file__->code__->AppendLine__0();
	file__->firstElement__ = file__->afterBlock__ = false__00;
}

auto write_line__2(Source_File_Builder *_Nonnull const file__, string__00 const value__) -> void
{
	file__->code__->Append__1(file__->indent__);
	file__->code__->Append__1(value__);
	file__->code__->AppendLine__0();
	file__->firstElement__ = file__->afterBlock__ = false__00;
}

auto blank_line__1(Source_File_Builder *_Nonnull const file__) -> void
{
	file__->code__->AppendLine__0();
	file__->firstElement__ = true__00;
	file__->afterBlock__ = false__00;
}

auto element_separator_line__1(Source_File_Builder *_Nonnull const file__) -> void
{
	if (cond(bool__00__0op__not(file__->firstElement__)))
	{
		file__->code__->AppendLine__0();
		file__->firstElement__ = true__00;
		file__->afterBlock__ = false__00;
	}
}

auto statement_separator_line__1(Source_File_Builder *_Nonnull const file__) -> void
{
	if (cond(file__->afterBlock__))
	{
		file__->code__->AppendLine__0();
		file__->firstElement__ = true__00;
		file__->afterBlock__ = false__00;
	}
}

auto begin_block__1(Source_File_Builder *_Nonnull const file__) -> void
{
	write_line__2(file__, string__00("{"));
	file__->indent__->Append__1(string__00("\t"));
	file__->firstElement__ = file__->afterBlock__ = false__00;
}

auto end_block__1(Source_File_Builder *_Nonnull const file__) -> void
{
	file__->indent__->Remove__2(int__00(0), int__00(1));
	write_line__2(file__, string__00("}"));
	file__->afterBlock__ = true__00;
}

auto end_block_with_semicolon__1(Source_File_Builder *_Nonnull const file__) -> void
{
	file__->indent__->Remove__2(int__00(0), int__00(1));
	write_line__2(file__, string__00("};"));
}

auto byte_length__1(Source_File_Builder const *_Nonnull const file__) -> int__00
{
	return file__->code__->byte_length__0();
}

auto to_string__1(Source_File_Builder *_Nonnull const file__) -> string__00
{
	return file__->code__->ToString__0();
}

Compilation_Unit *_Nonnull Compilation_Unit__0new__2(Compilation_Unit *_Nonnull self, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__)
{
	self->syntax__ = syntax__;
	self->declarations__ = declarations__;
	return self;
}

inline Compilation_Unit *_Nonnull new_Compilation_Unit(Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__)
{
	return Compilation_Unit__0new__2(new Compilation_Unit(), syntax__, declarations__);
}

auto collect_diagnostics__2(Compilation_Unit const *_Nonnull const compilation_unit__, system__collections__List<Diagnostic const *_Nonnull> *_Nonnull const diagnostics__) -> void
{
	collect_syntax_diagnostics__2(compilation_unit__->syntax__, diagnostics__);
	for (Semantic_Node const *_Nonnull const declaration__ : *(compilation_unit__->declarations__))
	{
		collect_diagnostics__2(declaration__, diagnostics__);
	}
}

Package *_Nonnull Package__0new__4(Package *_Nonnull self, Package_Name const *_Nonnull const name__, system__collections__List<Package_Reference> const *_Nonnull const references__, system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units__, Symbol const *_Nonnull const symbol__)
{
	self->name__ = name__;
	self->references__ = references__;
	self->compilation_units__ = compilation_units__;
	self->symbol__ = symbol__;
	return self;
}

inline Package *_Nonnull new_Package(Package_Name const *_Nonnull const name__, system__collections__List<Package_Reference> const *_Nonnull const references__, system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units__, Symbol const *_Nonnull const symbol__)
{
	return Package__0new__4(new Package(), name__, references__, compilation_units__, symbol__);
}

auto all_diagnostics__1(Package const *_Nonnull const package__) -> system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull
{
	system__collections__List<Diagnostic const *_Nonnull> *_Nonnull diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	for (Compilation_Unit const *_Nonnull const compilation_unit__ : *(package__->compilation_units__))
	{
		collect_diagnostics__2(compilation_unit__, diagnostics__);
	}

	return diagnostics__;
}

Package_Reference Package_Reference__0new__1(Package const *_Nonnull const package__)
{
	Package_Reference self;
	self->name__ = package__->name__->unqualified__;
	self->package__ = package__;
	return self;
}

inline Package_Reference new_Package_Reference(Package const *_Nonnull const package__)
{
	return Package_Reference__0new__1(package__);
}

Package_Reference Package_Reference__0new__2(string__00 const name__, Package const *_Nonnull const package__)
{
	Package_Reference self;
	self->name__ = name__;
	self->package__ = package__;
	return self;
}

inline Package_Reference new_Package_Reference(string__00 const name__, Package const *_Nonnull const package__)
{
	return Package_Reference__0new__2(name__, package__);
}

auto build_primitives_package__0() -> Package const *_Nonnull
{
	Package_Name const *_Nonnull const name__ = new_Package_Name(string__00("$primitives"));
	system__collections__List<Package_Reference> const *_Nonnull const references__ = new_system__collections__List<Package_Reference>();
	system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units__ = new_system__collections__List<Compilation_Unit const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const primitive_symbols__ = build_primitive_symbols__1(name__);
	assert__2(primitive_symbols__->op__magnitude()->op__greater_than(int__00(0)), string__00("|primitive_symbols|=").op__add(primitive_symbols__->op__magnitude()));
	Symbol const *_Nonnull const package_symbol__ = new_Symbol__package(name__->unqualified__, primitive_symbols__);
	assert__2(package_symbol__->children__->op__magnitude()->op__greater_than(int__00(0)), string__00("|package_symbol.children|=").op__add(package_symbol__->children__->op__magnitude()));
	return new_Package(name__, references__, compilation_units__, package_symbol__);
}

auto build_primitive_symbols__1(Package_Name const *_Nonnull const package_name__) -> system__collections__List<Symbol const *_Nonnull> *_Nonnull
{
	Name const *_Nonnull const global_namespace__ = new_Name__global_namespace(package_name__);
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const symbols__ = new_system__collections__List<Symbol const *_Nonnull>();
	symbols__->add__1(build_adamant_language_namespace_symbol__1(global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("void"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("never"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("bool"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("code_point"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("string"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("int8"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("int16"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("int"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("int64"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("int128"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("byte"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("uint16"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("uint"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("uint64"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("uint128"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("float32"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("float"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("float128"), global_namespace__));
	build_fixed_point_primitives__3(symbols__, int__00(8), global_namespace__);
	build_fixed_point_primitives__3(symbols__, int__00(16), global_namespace__);
	build_fixed_point_primitives__3(symbols__, int__00(32), global_namespace__);
	build_fixed_point_primitives__3(symbols__, int__00(64), global_namespace__);
	symbols__->add__1(build_primitive_symbol__2(string__00("decimal32"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("decimal"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("decimal128"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("size"), global_namespace__));
	symbols__->add__1(build_primitive_symbol__2(string__00("offset"), global_namespace__));
	return symbols__;
}

auto build_adamant_language_namespace_symbol__1(Name const *_Nonnull const global_namespace__) -> Symbol const *_Nonnull
{
	Name const *_Nonnull const adamant_namespace__ = new_Name(global_namespace__, NamespaceName__, string__00("adamant"));
	Name const *_Nonnull const language_namespace__ = new_Name(adamant_namespace__, NamespaceName__, string__00("language"));
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const language_children__ = new_system__collections__List<Symbol const *_Nonnull>();
	language_children__->add__1(build_optional_type_symbol__1(language_namespace__));
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const adamant_children__ = new_system__collections__List<Symbol const *_Nonnull>();
	adamant_children__->add__1(new_Symbol__identifier(unqualified_name__1(language_namespace__), language_children__));
	return new_Symbol__identifier(unqualified_name__1(adamant_namespace__), adamant_children__);
}

auto build_optional_type_symbol__1(Name const *_Nonnull const language_namespace__) -> Symbol const *_Nonnull
{
	Name const *_Nonnull const optional_name__ = new_Name(language_namespace__, TypeName__, string__00("optional"));
	system__collections__List<Type const *_Nonnull> *_Nonnull const type_parameters__ = new_system__collections__List<Type const *_Nonnull>();
	type_parameters__->add__1(new_Type(TypeParameterType__, new_Name(optional_name__, TypeParameterName__, string__00("T")), true__00));
	Type const *_Nonnull const type__ = new_Type__primitive(optional_name__, type_parameters__);
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const declarations__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Symbol const *_Nonnull>();
	return new_Symbol__declaring(type__, declarations__, children__);
}

auto build_primitive_symbol__2(string__00 const name__, Name const *_Nonnull const namespace__) -> Symbol const *_Nonnull
{
	Type const *_Nonnull const type__ = new_Type__primitive(new_Name__special(namespace__, TypeName__, name__));
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const declarations__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Symbol const *_Nonnull>();
	return new_Symbol__declaring(type__, declarations__, children__);
}

auto build_fixed_point_primitives__3(system__collections__List<Symbol const *_Nonnull> *_Nonnull const symbols__, int__00 const bits__, Name const *_Nonnull const namespace__) -> void
{
}

auto unit_test_build_primitives_package__0() -> void
{
	Package_name_is_dollar_primitives__0();
	Package_has_no_references_or_compilation_units__0();
	Package_symbol_has_package_name__0();
	Package_symbol_has_children__0();
	Package_contains_the_string_type__0();
	Package_contains_optional_type__0();
}

auto Package_name_is_dollar_primitives__0() -> void
{
	Package const *_Nonnull const package__ = build_primitives_package__0();
	Package_Name const *_Nonnull const name__ = package__->name__;
	assert__2(equal_op(name__->unqualified__, string__00("$primitives")), string__00(""));
}

auto Package_has_no_references_or_compilation_units__0() -> void
{
	Package const *_Nonnull const package__ = build_primitives_package__0();
	assert__2(equal_op(package__->references__->op__magnitude(), int__00(0)), string__00(""));
	assert__2(equal_op(package__->compilation_units__->op__magnitude(), int__00(0)), string__00(""));
}

auto Package_symbol_has_package_name__0() -> void
{
	Package const *_Nonnull const package__ = build_primitives_package__0();
	Symbol const *_Nonnull const symbol__ = package__->symbol__;
	assert__2(equal_op(symbol__->kind__, PackageSymbol__), string__00(""));
	assert__2(equal_op(symbol__->name__, package__->name__->unqualified__), string__00(""));
}

auto Package_symbol_has_children__0() -> void
{
	Package const *_Nonnull const package__ = build_primitives_package__0();
	assert__2(package__->symbol__->children__->op__magnitude()->op__greater_than(int__00(0)), string__00(""));
}

auto Package_contains_the_string_type__0() -> void
{
	Package const *_Nonnull const package__ = build_primitives_package__0();
	Symbol const *_Nonnull const string_symbol__ = get_child__3(package__->symbol__, string__00("string"), IdentifierSymbol__);
	assert__2(not_equal_op(string_symbol__, none), string__00(""));
}

auto Package_contains_optional_type__0() -> void
{
	Package const *_Nonnull const package__ = build_primitives_package__0();
	Symbol const *_Nullable const adamant_symbol__ = get_child__3(package__->symbol__, string__00("adamant"), IdentifierSymbol__);
	assert__2(not_equal_op(adamant_symbol__, none), string__00(""));
	Symbol const *_Nullable const langauge_symbol__ = get_child__3(adamant_symbol__, string__00("language"), IdentifierSymbol__);
	assert__2(not_equal_op(langauge_symbol__, none), string__00(""));
	Symbol const *_Nullable const optional_symbol__ = get_child__3(langauge_symbol__, string__00("optional"), IdentifierSymbol__);
	assert__2(not_equal_op(optional_symbol__, none), string__00(""));
}

auto build_runtime_library_package__0() -> Package const *_Nonnull
{
	Package_Name const *_Nonnull const name__ = new_Package_Name(string__00("$runtime"));
	system__collections__List<Package_Reference> const *_Nonnull const references__ = new_system__collections__List<Package_Reference>();
	system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units__ = new_system__collections__List<Compilation_Unit const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const symbols__ = build_runtime_library_symbols__1(name__);
	assert__2(symbols__->op__magnitude()->op__greater_than(int__00(0)), string__00("|symbols|=").op__add(symbols__->op__magnitude()));
	Symbol const *_Nonnull const package_symbol__ = new_Symbol__package(name__->unqualified__, symbols__);
	assert__2(package_symbol__->children__->op__magnitude()->op__greater_than(int__00(0)), string__00("|package_symbol.children|=").op__add(package_symbol__->children__->op__magnitude()));
	return new_Package(name__, references__, compilation_units__, package_symbol__);
}

auto build_runtime_library_symbols__1(Package_Name const *_Nonnull const package_name__) -> system__collections__List<Symbol const *_Nonnull> *_Nonnull
{
	Name const *_Nonnull const global_namespace__ = new_Name__global_namespace(package_name__);
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const symbols__ = new_system__collections__List<Symbol const *_Nonnull>();
	symbols__->add__1(build_function_symbol__1(new_Name(global_namespace__, FunctionName__, string__00("NOT_IMPLEMENTED"))));
	symbols__->add__1(build_function_symbol__1(new_Name(global_namespace__, FunctionName__, string__00("UNREACHABLE"))));
	symbols__->add__1(build_function_symbol__1(new_Name(global_namespace__, FunctionName__, string__00("assert"))));
	symbols__->add__1(build_function_symbol__1(new_Name(global_namespace__, FunctionName__, string__00("debug_write"))));
	symbols__->add__1(build_function_symbol__1(new_Name(global_namespace__, FunctionName__, string__00("debug_write_line"))));
	symbols__->add__1(build_function_symbol__1(new_Name(global_namespace__, VariableName__, string__00("resource_manager"))));
	Name const *_Nonnull const system_namespace__ = new_Name(global_namespace__, NamespaceName__, string__00("system"));
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const system_symbols__ = new_system__collections__List<Symbol const *_Nonnull>();
	Name const *_Nonnull const collections_namespace__ = new_Name(system_namespace__, NamespaceName__, string__00("collections"));
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const collections_symbols__ = new_system__collections__List<Symbol const *_Nonnull>();
	system__collections__List<Type const *_Nonnull> *_Nonnull const list_type_parameters__ = new_system__collections__List<Type const *_Nonnull>();
	list_type_parameters__->add__1(new_Type__parameter(string__00("T")));
	collections_symbols__->add__1(build_generic_class_symbol__3(collections_namespace__, string__00("List"), list_type_parameters__));
	system_symbols__->add__1(build_namespace_symbol__2(collections_namespace__, collections_symbols__));
	Name const *_Nonnull const console_namespace__ = new_Name(system_namespace__, NamespaceName__, string__00("console"));
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const console_symbols__ = new_system__collections__List<Symbol const *_Nonnull>();
	console_symbols__->add__1(build_class_symbol__2(console_namespace__, string__00("Console")));
	console_symbols__->add__1(build_class_symbol__2(console_namespace__, string__00("Arguments")));
	system_symbols__->add__1(build_namespace_symbol__2(console_namespace__, console_symbols__));
	Name const *_Nonnull const io_namespace__ = new_Name(system_namespace__, NamespaceName__, string__00("io"));
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const io_symbols__ = new_system__collections__List<Symbol const *_Nonnull>();
	io_symbols__->add__1(build_class_symbol__2(io_namespace__, string__00("File_Reader")));
	io_symbols__->add__1(build_class_symbol__2(io_namespace__, string__00("File_Writer")));
	system_symbols__->add__1(build_namespace_symbol__2(io_namespace__, io_symbols__));
	Name const *_Nonnull const text_namespace__ = new_Name(system_namespace__, NamespaceName__, string__00("text"));
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const text_symbols__ = new_system__collections__List<Symbol const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const string_builder_symbols__ = new_system__collections__List<Symbol const *_Nonnull>();
	string_builder_symbols__->add__1(build_constructor_symbol__1(string__00("with_capacity")));
	text_symbols__->add__1(build_class_symbol__3(text_namespace__, string__00("String_Builder"), string_builder_symbols__));
	system_symbols__->add__1(build_namespace_symbol__2(text_namespace__, text_symbols__));
	symbols__->add__1(build_namespace_symbol__2(system_namespace__, system_symbols__));
	return symbols__;
}

auto build_function_symbol__1(Name const *_Nonnull const name__) -> Symbol const *_Nonnull
{
	Type const *_Nonnull const type__ = new_Type(FunctionType__, name__, false__00);
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__ = new_system__collections__List<Symbol const *_Nonnull>();
	return new_Symbol__of_type(unqualified_name__1(name__), type__, declarations__, children__);
}

auto build_namespace_symbol__2(Name const *_Nonnull const name__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const symbols__) -> Symbol const *_Nonnull
{
	Type const *_Nonnull const type__ = new_Type__namespace(name__);
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	return new_Symbol__declaring(type__, declarations__, symbols__);
}

auto build_class_symbol__2(Name const *_Nonnull const namespace__, string__00 const class_name__) -> Symbol const *_Nonnull
{
	Type const *_Nonnull const type__ = new_Type(ReferenceType__, new_Name(namespace__, TypeName__, class_name__), true__00);
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__ = new_system__collections__List<Symbol const *_Nonnull>();
	return new_Symbol__declaring(type__, declarations__, children__);
}

auto build_class_symbol__3(Name const *_Nonnull const namespace__, string__00 const class_name__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__) -> Symbol const *_Nonnull
{
	Type const *_Nonnull const type__ = new_Type(ReferenceType__, new_Name(namespace__, TypeName__, class_name__), true__00);
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	return new_Symbol__declaring(type__, declarations__, children__);
}

auto build_generic_class_symbol__3(Name const *_Nonnull const namespace__, string__00 const class_name__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__) -> Symbol const *_Nonnull
{
	Type const *_Nonnull const type__ = new_Type(ReferenceType__, new_Name(namespace__, TypeName__, class_name__), type_parameters__, true__00);
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__ = new_system__collections__List<Symbol const *_Nonnull>();
	return new_Symbol__declaring(type__, declarations__, children__);
}

auto build_constructor_symbol__1(string__00 const name__) -> Symbol const *_Nonnull
{
	string__00 const constructor_name__ = string__00("new_").op__add(name__);
	system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	return new_Symbol__constructor(constructor_name__, declarations__);
}

auto unit_test_build_runtime_library_package__0() -> void
{
	Runtime_Library_Package_contains_system_package__0();
	System_namespace_contains_console_namespace__0();
	Console_namespace_contains_Console_class__0();
	System_namespace_contains_collections_namespace__0();
	Collections_namespace_contains_List_class__0();
}

auto Runtime_Library_Package_contains_system_package__0() -> void
{
	Package const *_Nonnull const package__ = build_runtime_library_package__0();
	assert__2(not_equal_op(get_child__3(package__->symbol__, string__00("system"), IdentifierSymbol__), none), string__00(""));
}

auto System_namespace_contains_console_namespace__0() -> void
{
	Package const *_Nonnull const package__ = build_runtime_library_package__0();
	Symbol const *_Nonnull const system_namespace__ = get_child__3(package__->symbol__, string__00("system"), IdentifierSymbol__);
	assert__2(not_equal_op(get_child__3(system_namespace__, string__00("console"), IdentifierSymbol__), none), string__00(""));
}

auto Console_namespace_contains_Console_class__0() -> void
{
	Package const *_Nonnull const package__ = build_runtime_library_package__0();
	Symbol const *_Nonnull const system_namespace__ = get_child__3(package__->symbol__, string__00("system"), IdentifierSymbol__);
	Symbol const *_Nonnull const console_namespace__ = get_child__3(system_namespace__, string__00("console"), IdentifierSymbol__);
	assert__2(not_equal_op(get_child__3(console_namespace__, string__00("Console"), IdentifierSymbol__), none), string__00(""));
}

auto System_namespace_contains_collections_namespace__0() -> void
{
	Package const *_Nonnull const package__ = build_runtime_library_package__0();
	Symbol const *_Nonnull const system_namespace__ = get_child__3(package__->symbol__, string__00("system"), IdentifierSymbol__);
	assert__2(not_equal_op(get_child__3(system_namespace__, string__00("collections"), IdentifierSymbol__), none), string__00(""));
}

auto Collections_namespace_contains_List_class__0() -> void
{
	Package const *_Nonnull const package__ = build_runtime_library_package__0();
	Symbol const *_Nonnull const system_namespace__ = get_child__3(package__->symbol__, string__00("system"), IdentifierSymbol__);
	Symbol const *_Nonnull const console_namespace__ = get_child__3(system_namespace__, string__00("collections"), IdentifierSymbol__);
	assert__2(not_equal_op(get_child__3(console_namespace__, string__00("List"), IdentifierSymbol__), none), string__00(""));
}

auto analyze_semantics__1(Syntax_Node const *_Nonnull const package_syntax__) -> Package const *_Nonnull
{
	assert__2(equal_op(package_syntax__->kind__, PackageNode__), string__00("package_syntax.kind=").op__add(package_syntax__->kind__));
	Package_Name const *_Nonnull const name__ = new_Package_Name(string__00("default"));
	Package const *_Nonnull const primitives_package__ = build_primitives_package__0();
	Package const *_Nonnull const runtime_package__ = build_runtime_library_package__0();
	system__collections__List<Package_Reference> *_Nonnull const references__ = new_system__collections__List<Package_Reference>();
	references__->add__1(new_Package_Reference(primitives_package__));
	references__->add__1(new_Package_Reference(runtime_package__));
	Name_Table const *_Nonnull const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Semantic_Tree_Builder const *_Nonnull const semantic_tree_builder__ = new_Semantic_Tree_Builder();
	system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units__ = build_compilation_units__3(semantic_tree_builder__, package_syntax__, name_table__);
	Symbol const *_Nonnull const package_symbol__ = build_symbols__2(name__, compilation_units__);
	Package const *_Nonnull const package__ = new_Package(name__, references__, compilation_units__, package_symbol__);
	return package__;
}

Semantic_Node *_Nonnull Semantic_Node__0new__token__1(Semantic_Node *_Nonnull self, Syntax_Node const *_Nonnull const syntax__)
{
	assert__2(not_equal_op(syntax__, none), string__00(""));
	self->syntax__ = syntax__;
	self->kind__ = syntax__->kind__;
	self->is_missing__ = syntax__->is_missing__;
	self->source__ = syntax__->source__;
	self->start__ = syntax__->start__;
	self->byte_length__ = syntax__->byte_length__;
	self->children__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	self->node_diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	self->of_type__ = none;
	self->converted_type__ = none;
	self->declares_type__ = none;
	self->referenced_type__ = none;
	return self;
}

inline Semantic_Node *_Nonnull new_Semantic_Node__token(Syntax_Node const *_Nonnull const syntax__)
{
	return Semantic_Node__0new__token__1(new Semantic_Node(), syntax__);
}

Semantic_Node *_Nonnull Semantic_Node__0new__concrete__2(Semantic_Node *_Nonnull self, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__)
{
	assert__2(not_equal_op(syntax__, none), string__00(""));
	self->syntax__ = syntax__;
	self->kind__ = syntax__->kind__;
	self->is_missing__ = syntax__->is_missing__;
	self->source__ = syntax__->source__;
	self->start__ = syntax__->start__;
	self->byte_length__ = syntax__->byte_length__;
	self->children__ = children__;
	self->node_diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	self->of_type__ = none;
	self->converted_type__ = none;
	self->declares_type__ = none;
	self->referenced_type__ = none;
	return self;
}

inline Semantic_Node *_Nonnull new_Semantic_Node__concrete(Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__)
{
	return Semantic_Node__0new__concrete__2(new Semantic_Node(), syntax__, children__);
}

Semantic_Node *_Nonnull Semantic_Node__0new__of_type__3(Semantic_Node *_Nonnull self, Type const *_Nonnull const of_type__, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__)
{
	assert__2(not_equal_op(of_type__, none), string__00(""));
	assert__2(not_equal_op(syntax__, none), string__00(""));
	self->syntax__ = syntax__;
	self->kind__ = syntax__->kind__;
	self->is_missing__ = syntax__->is_missing__;
	self->source__ = syntax__->source__;
	self->start__ = syntax__->start__;
	self->byte_length__ = syntax__->byte_length__;
	self->children__ = children__;
	self->node_diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	self->of_type__ = of_type__;
	self->converted_type__ = of_type__;
	self->declares_type__ = none;
	self->referenced_type__ = none;
	return self;
}

inline Semantic_Node *_Nonnull new_Semantic_Node__of_type(Type const *_Nonnull const of_type__, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__)
{
	return Semantic_Node__0new__of_type__3(new Semantic_Node(), of_type__, syntax__, children__);
}

Semantic_Node *_Nonnull Semantic_Node__0new__declares_type__3(Semantic_Node *_Nonnull self, Type const *_Nonnull const type__, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__)
{
	assert__2(not_equal_op(type__, none), string__00(""));
	assert__2(not_equal_op(syntax__, none), string__00(""));
	self->syntax__ = syntax__;
	self->kind__ = syntax__->kind__;
	self->is_missing__ = syntax__->is_missing__;
	self->source__ = syntax__->source__;
	self->start__ = syntax__->start__;
	self->byte_length__ = syntax__->byte_length__;
	self->children__ = children__;
	self->node_diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	self->of_type__ = none;
	self->converted_type__ = none;
	self->declares_type__ = type__;
	self->referenced_type__ = none;
	return self;
}

inline Semantic_Node *_Nonnull new_Semantic_Node__declares_type(Type const *_Nonnull const type__, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__)
{
	return Semantic_Node__0new__declares_type__3(new Semantic_Node(), type__, syntax__, children__);
}

Semantic_Node *_Nonnull Semantic_Node__0new__referencing_type__3(Semantic_Node *_Nonnull self, Type const *_Nonnull const type__, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__)
{
	assert__2(not_equal_op(type__, none), string__00(""));
	assert__2(not_equal_op(syntax__, none), string__00(""));
	self->syntax__ = syntax__;
	self->kind__ = syntax__->kind__;
	self->is_missing__ = syntax__->is_missing__;
	self->source__ = syntax__->source__;
	self->start__ = syntax__->start__;
	self->byte_length__ = syntax__->byte_length__;
	self->children__ = children__;
	self->node_diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	self->of_type__ = none;
	self->converted_type__ = none;
	self->declares_type__ = none;
	self->referenced_type__ = type__;
	return self;
}

inline Semantic_Node *_Nonnull new_Semantic_Node__referencing_type(Type const *_Nonnull const type__, Syntax_Node const *_Nonnull const syntax__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const children__)
{
	return Semantic_Node__0new__referencing_type__3(new Semantic_Node(), type__, syntax__, children__);
}

auto get_text_span__1(Semantic_Node const *_Nonnull const node__) -> Text_Span const *_Nonnull
{
	return new_Text_Span(node__->start__, node__->byte_length__);
}

auto get_text__1(Semantic_Node const *_Nonnull const node__) -> string__00
{
	if (cond(equal_op(node__->source__, none)))
	{
		return string__00("$No Source$");
	}

	return node__->source__->text__.Substring__2(node__->start__, node__->byte_length__);
}

auto first_child__2(Semantic_Node const *_Nonnull const node__, int__00 const kind__) -> Semantic_Node const *_Nullable
{
	for (Semantic_Node const *_Nonnull const child__ : *(node__->children__))
	{
		if (cond(equal_op(child__->kind__, kind__)))
		{
			return child__;
		}
	}

	return none;
}

auto children_of_kind__2(Semantic_Node const *_Nonnull const node__, int__00 const kind__) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull
{
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	for (Semantic_Node const *_Nonnull const child__ : *(node__->children__))
	{
		if (cond(equal_op(child__->kind__, kind__)))
		{
			children__->add__1(child__);
		}
	}

	return children__;
}

auto node_members__1(Semantic_Node const *_Nonnull const node__) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull
{
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const members__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	for (Semantic_Node const *_Nonnull const child__ : *(node__->children__))
	{
		if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(child__->kind__, ConstructorDeclaration__)) || bool__00__arg(equal_op(child__->kind__, FieldDeclaration__)))) || bool__00__arg(equal_op(child__->kind__, MethodDeclaration__)))))
		{
			members__->add__1(child__);
		}
	}

	return members__;
}

auto node_statements__1(Semantic_Node const *_Nonnull const node__) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull
{
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const statements__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	for (Semantic_Node const *_Nonnull const child__ : *(node__->children__))
	{
		if (cond(bool__00__op(bool__00__arg(not_equal_op(child__->kind__, LeftBrace__)) && bool__00__arg(not_equal_op(child__->kind__, RightBrace__)))))
		{
			statements__->add__1(child__);
		}
	}

	return statements__;
}

auto node_parameters__1(Semantic_Node const *_Nonnull const node__) -> system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull
{
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const parameters__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	for (Semantic_Node const *_Nonnull const child__ : *(node__->children__))
	{
		if (cond(bool__00__op(bool__00__arg(equal_op(child__->kind__, Parameter__)) || bool__00__arg(equal_op(child__->kind__, SelfParameter__)))))
		{
			parameters__->add__1(child__);
		}
	}

	return parameters__;
}

auto node_argument_count__1(Semantic_Node const *_Nonnull const node__) -> int__00
{
	int__00 count__ = int__00(0);
	for (Semantic_Node const *_Nonnull const child__ : *(node__->children__))
	{
		if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(child__->kind__, LeftParen__)) || bool__00__arg(equal_op(child__->kind__, RightParen__)))) || bool__00__arg(equal_op(child__->kind__, Comma__)))))
		{
			continue;
		}

		count__.op__add_assign(int__00(1));
	}

	return count__;
}

auto node_access_modifier__1(Semantic_Node const *_Nonnull const node__) -> Semantic_Node const *_Nullable
{
	for (Semantic_Node const *_Nonnull const child__ : *(node__->children__))
	{
		if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(child__->kind__, PublicKeyword__)) || bool__00__arg(equal_op(child__->kind__, ProtectedKeyword__)))) || bool__00__arg(equal_op(child__->kind__, PrivateKeyword__)))) || bool__00__arg(equal_op(child__->kind__, InternalKeyword__)))))
		{
			return child__;
		}
	}

	return none;
}

auto node_has_child__2(Semantic_Node const *_Nonnull const node__, int__00 const kind__) -> bool__00
{
	for (Semantic_Node const *_Nonnull const child__ : *(node__->children__))
	{
		if (cond(equal_op(child__->kind__, kind__)))
		{
			return true__00;
		}
	}

	return false__00;
}

auto add_diagnostic__2(Semantic_Node *_Nonnull const node__, Diagnostic const *_Nonnull const diagnostic__) -> void
{
	node__->node_diagnostics__->add__1(diagnostic__);
}

auto diagnostics__1(Semantic_Node const *_Nonnull const node__) -> system__collections__List<Diagnostic const *_Nonnull> const *_Nonnull
{
	return node__->node_diagnostics__;
}

auto collect_diagnostics__2(Semantic_Node const *_Nonnull const node__, system__collections__List<Diagnostic const *_Nonnull> *_Nonnull const diagnostics__) -> void
{
	for (Diagnostic const *_Nonnull const diagnostic__ : *(node__->node_diagnostics__))
	{
		diagnostics__->add__1(diagnostic__);
	}

	for (Semantic_Node const *_Nonnull const child__ : *(node__->children__))
	{
		collect_diagnostics__2(child__, diagnostics__);
	}
}

Semantic_Tree_Builder *_Nonnull Semantic_Tree_Builder__0new__0(Semantic_Tree_Builder *_Nonnull self)
{
	Package_Name const *_Nonnull const primitives_package__ = new_Package_Name(string__00("$primitives"));
	Name const *_Nonnull const global_namespace__ = new_Name__global_namespace(primitives_package__);
	Name const *_Nonnull const adamant_namespace__ = new_Name(global_namespace__, NamespaceName__, string__00("adamant"));
	Name const *_Nonnull const language_namespace__ = new_Name(adamant_namespace__, NamespaceName__, string__00("language"));
	self->optional_type_name__ = new_Name(language_namespace__, TypeName__, string__00("optional"));
	return self;
}

inline Semantic_Tree_Builder *_Nonnull new_Semantic_Tree_Builder()
{
	return Semantic_Tree_Builder__0new__0(new Semantic_Tree_Builder());
}

auto build_compilation_units__3(Semantic_Tree_Builder const *_Nonnull const builder__, Syntax_Node const *_Nonnull const package_syntax__, Name_Table const *_Nonnull const name_table__) -> system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull
{
	assert__2(equal_op(package_syntax__->kind__, PackageNode__), string__00("package_syntax.kind=").op__add(package_syntax__->kind__));
	assert__2(not_equal_op(lookup_special__2(name_table__->any_package__, string__00("string")), none), string__00("name_table.any_package.name=").op__add(full_name__1(name_table__->any_package__->name__)));
	system__collections__List<Compilation_Unit const *_Nonnull> *_Nonnull const compilation_units__ = new_system__collections__List<Compilation_Unit const *_Nonnull>();
	for (Syntax_Node const *_Nonnull const compilation_unit_syntax__ : *(package_syntax__->children__))
	{
		compilation_units__->add__1(build_compilation_unit_semantic_node__3(builder__, compilation_unit_syntax__, name_table__));
	}

	return compilation_units__;
}

auto build_compilation_unit_semantic_node__3(Semantic_Tree_Builder const *_Nonnull const builder__, Syntax_Node const *_Nonnull const compilation_unit_syntax__, Name_Table const *_Nonnull const name_table__) -> Compilation_Unit const *_Nonnull
{
	assert__2(equal_op(compilation_unit_syntax__->kind__, CompilationUnit__), string__00("compilation_unit_syntax.kind=").op__add(compilation_unit_syntax__->kind__));
	Name_Subtable const *_Nonnull const scope__ = none;
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const declarations__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	for (Syntax_Node const *_Nonnull const declaration_syntax__ : *(compilation_unit_syntax__->children__))
	{
		declarations__->add__1(build_semantic_node__4(builder__, declaration_syntax__, name_table__, name_table__->any_package__));
	}

	return new_Compilation_Unit(compilation_unit_syntax__, declarations__);
}

auto build_semantic_node__4(Semantic_Tree_Builder const *_Nonnull const builder__, Syntax_Node const *_Nonnull const syntax__, Name_Table const *_Nonnull const name_table__, Name_Subtable const *_Nonnull const scope__) -> Semantic_Node const *_Nonnull
{
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	if (cond(bool__00__op(bool__00__arg(equal_op(syntax__->kind__, FunctionDeclaration__)) || bool__00__arg(equal_op(syntax__->kind__, MethodDeclaration__)))))
	{
		children__->add__1(build_semantic_node__4(builder__, access_modifier__1(syntax__), name_table__, scope__));
		Syntax_Node const *_Nonnull const function_name__ = first_child_syntax__2(syntax__, Identifier__);
		children__->add__1(build_semantic_node__4(builder__, function_name__, name_table__, scope__));
		Name_Subtable *_Nonnull const function_scope__ = find__2(scope__, get_text__1(function_name__));
		assert__2(not_equal_op(function_scope__, none), string__00("get_text(function_name)=").op__add(get_text__1(function_name__)));
		Syntax_Node const *_Nonnull const parameters__ = first_child_syntax__2(syntax__, ParameterList__);
		children__->add__1(build_parameters_semantic_node__4(builder__, parameters__, name_table__, function_scope__));
		Syntax_Node const *_Nonnull const return_type__ = syntax__->children__->op__Element(int__00(4));
		children__->add__1(build_type_name_semantic_node__4(builder__, return_type__, name_table__, scope__));
		Type const *_Nonnull const function_type__ = new_Type(FunctionType__, function_scope__->name__, false__00);
		bind_type__2(function_scope__, function_type__);
		Syntax_Node const *_Nonnull const body__ = first_child_syntax__2(syntax__, Block__);
		if (cond(not_equal_op(body__, none)))
		{
			children__->add__1(build_semantic_node__4(builder__, body__, name_table__, function_scope__));
		}

		return new_Semantic_Node__concrete(syntax__, children__);
	}
	else if (cond(bool__00__op(bool__00__arg(equal_op(syntax__->kind__, ClassDeclaration__)) || bool__00__arg(equal_op(syntax__->kind__, StructDeclaration__)))))
	{
		Syntax_Node const *_Nonnull const type_name__ = first_child_syntax__2(syntax__, Identifier__);
		children__->add__1(build_semantic_node__4(builder__, type_name__, name_table__, scope__));
		Name_Subtable const *_Nonnull const type_scope__ = find__2(scope__, get_text__1(type_name__));
		assert__2(not_equal_op(type_scope__, none), string__00("get_text(type_name)=").op__add(get_text__1(type_name__)));
		for (Syntax_Node const *_Nonnull const member__ : *(members__1(syntax__)))
		{
			children__->add__1(build_semantic_node__4(builder__, member__, name_table__, type_scope__));
		}

		return new_Semantic_Node__declares_type(type_scope__->type__, syntax__, children__);
	}
	else if (cond(equal_op(syntax__->kind__, ConstructorDeclaration__)))
	{
		children__->add__1(build_semantic_node__4(builder__, access_modifier__1(syntax__), name_table__, scope__));
		string__00 full_name__ = string__00("new");
		Syntax_Node const *_Nullable const constructor_name__ = first_child_syntax__2(syntax__, Identifier__);
		if (cond(not_equal_op(constructor_name__, none)))
		{
			full_name__ = string__00("new_").op__add(get_text__1(constructor_name__));
			children__->add__1(new_Semantic_Node__token(constructor_name__));
		}

		Name_Subtable const *_Nonnull const constructor_scope__ = find_special__2(scope__, full_name__);
		assert__2(not_equal_op(constructor_scope__, none), string__00("full_name=").op__add(full_name__));
		Syntax_Node const *_Nonnull const parameters__ = first_child_syntax__2(syntax__, ParameterList__);
		children__->add__1(build_parameters_semantic_node__4(builder__, parameters__, name_table__, constructor_scope__));
		Syntax_Node const *_Nonnull const body__ = first_child_syntax__2(syntax__, Block__);
		if (cond(not_equal_op(body__, none)))
		{
			children__->add__1(build_semantic_node__4(builder__, body__, name_table__, constructor_scope__));
		}

		return new_Semantic_Node__concrete(syntax__, children__);
	}
	else if (cond(equal_op(syntax__->kind__, IdentifierName__)))
	{
		Name_Subtable const *_Nonnull const name_scope__ = lookup__2(scope__, get_text__1(syntax__));
		if (cond(equal_op(name_scope__, none)))
		{
			Semantic_Node *_Nonnull const node__ = new_Semantic_Node__token(syntax__);
			if (cond(bool__00__0op__not(syntax__->is_missing__)))
			{
				add_resolution_error__1(node__);
			}

			return node__;
		}
		else
		{
			int__00 const place__ = syntax__->start__;
			if (cond(equal_op(name_scope__->type__, none)))
			{
				return new_Semantic_Node__concrete(syntax__, children__);
			}
			else
			{
				return new_Semantic_Node__of_type(name_scope__->type__, syntax__, children__);
			}
		}
	}
	else if (cond(equal_op(syntax__->kind__, MemberAccessExpression__)))
	{
		Semantic_Node const *_Nonnull const lhs__ = build_semantic_node__4(builder__, syntax__->children__->op__Element(int__00(0)), name_table__, scope__);
		children__->add__1(lhs__);
		Semantic_Node *_Nonnull rhs__;
		Syntax_Node const *_Nonnull const member_name__ = syntax__->children__->op__Element(int__00(2));
		if (cond(equal_op(lhs__->of_type__, none)))
		{
			rhs__ = new_Semantic_Node__token(member_name__);
		}
		else
		{
			Name_Subtable const *_Nonnull const access_scope__ = get_name__2(name_table__, lhs__->of_type__->name__);
			Name_Subtable const *_Nonnull const member_scope__ = find__2(access_scope__, get_text__1(member_name__));
			if (cond(equal_op(member_scope__, none)))
			{
				rhs__ = new_Semantic_Node__token(member_name__);
			}
			else
			{
				system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const no_children__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
				if (cond(equal_op(member_scope__->type__, none)))
				{
					rhs__ = new_Semantic_Node__token(member_name__);
				}
				else
				{
					rhs__ = new_Semantic_Node__of_type(member_scope__->type__, member_name__, no_children__);
				}
			}
		}

		children__->add__1(rhs__);
		if (cond(equal_op(rhs__->of_type__, none)))
		{
			return new_Semantic_Node__concrete(syntax__, children__);
		}
		else
		{
			return new_Semantic_Node__of_type(rhs__->of_type__, syntax__, children__);
		}
	}
	else if (cond(equal_op(syntax__->kind__, NewExpression__)))
	{
		children__->add__1(build_constructor_name_semantic_node__4(builder__, syntax__->children__->op__Element(int__00(1)), name_table__, scope__));
		children__->add__1(build_semantic_node__4(builder__, first_child_syntax__2(syntax__, ArgumentList__), name_table__, scope__));
		return new_Semantic_Node__concrete(syntax__, children__);
	}
	else if (cond(equal_op(syntax__->kind__, LocalDeclarationStatement__)))
	{
		Syntax_Node const *_Nonnull const variable_declaration_syntax__ = first_child_syntax__2(syntax__, VariableDeclaration__);
		children__->add__1(build_semantic_node__4(builder__, variable_declaration_syntax__, name_table__, scope__));
		return new_Semantic_Node__concrete(syntax__, children__);
	}
	else if (cond(equal_op(syntax__->kind__, VariableDeclaration__)))
	{
		Syntax_Node const *_Nonnull const binding_syntax__ = syntax__->children__->op__Element(int__00(0));
		children__->add__1(new_Semantic_Node__token(binding_syntax__));
		Syntax_Node const *_Nonnull const identifier__ = first_child_syntax__2(syntax__, Identifier__);
		children__->add__1(new_Semantic_Node__token(identifier__));
		Syntax_Node const *_Nonnull const type_syntax__ = syntax__->children__->op__Element(int__00(3));
		Semantic_Node const *_Nonnull const type_node__ = build_type_name_semantic_node__4(builder__, type_syntax__, name_table__, scope__);
		assert__2(not_equal_op(type_node__->referenced_type__, none), get_text__1(type_node__));
		Name_Subtable *_Nonnull const variable_scope__ = lookup__2(scope__, get_text__1(identifier__));
		assert__2(not_equal_op(variable_scope__, none), get_text__1(syntax__));
		bind_type__2(variable_scope__, type_node__->referenced_type__);
		bind_type__2(as_mut__1(get_name__2(name_table__, variable_scope__->name__)), type_node__->referenced_type__);
		children__->add__1(type_node__);
		if (cond(equal_op(syntax__->children__->op__magnitude(), int__00(6))))
		{
			Syntax_Node const *_Nonnull const initalizer__ = syntax__->children__->op__Element(int__00(5));
			children__->add__1(build_semantic_node__4(builder__, initalizer__, name_table__, scope__));
		}

		return new_Semantic_Node__concrete(syntax__, children__);
	}
	else if (cond(bool__00__op(bool__00__arg(equal_op(syntax__->kind__, TrueLiteralExpression__)) || bool__00__arg(equal_op(syntax__->kind__, FalseLiteralExpression__)))))
	{
		return new_Semantic_Node__of_type(lookup_special__2(scope__, string__00("bool"))->type__, syntax__, children__);
	}
	else if (cond(equal_op(syntax__->kind__, StringLiteralExpression__)))
	{
		return new_Semantic_Node__of_type(lookup_special__2(scope__, string__00("string"))->type__, syntax__, children__);
	}
	else if (cond(equal_op(syntax__->kind__, CodePointLiteralExpression__)))
	{
		return new_Semantic_Node__of_type(lookup_special__2(scope__, string__00("code_point"))->type__, syntax__, children__);
	}
	else if (cond(equal_op(syntax__->kind__, NumericLiteralExpression__)))
	{
		return new_Semantic_Node__of_type(lookup_special__2(scope__, string__00("int"))->type__, syntax__, children__);
	}
	else if (cond(equal_op(syntax__->children__->op__magnitude(), int__00(0))))
	{
		return new_Semantic_Node__token(syntax__);
	}
	else
	{
		for (Syntax_Node const *_Nonnull const child_syntax__ : *(syntax__->children__))
		{
			children__->add__1(build_semantic_node__4(builder__, child_syntax__, name_table__, scope__));
		}

		return new_Semantic_Node__concrete(syntax__, children__);
	}
}

auto build_parameters_semantic_node__4(Semantic_Tree_Builder const *_Nonnull const builder__, Syntax_Node const *_Nonnull const parameters_syntax__, Name_Table const *_Nonnull const name_table__, Name_Subtable const *_Nonnull const scope__) -> Semantic_Node *_Nonnull
{
	assert__2(equal_op(parameters_syntax__->kind__, ParameterList__), string__00("parameters_syntax.kind=").op__add(parameters_syntax__->kind__));
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const parameter_nodes__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	for (Syntax_Node const *_Nonnull const parameter__ : *(parameters__1(parameters_syntax__)))
	{
		system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
		if (cond(equal_op(parameter__->kind__, Parameter__)))
		{
			Syntax_Node const *_Nullable const var_syntax__ = first_child_syntax__2(parameter__, VarKeyword__);
			if (cond(not_equal_op(var_syntax__, none)))
			{
				children__->add__1(new_Semantic_Node__token(var_syntax__));
			}

			Syntax_Node const *_Nonnull const identifier__ = first_child_syntax__2(parameter__, Identifier__);
			children__->add__1(new_Semantic_Node__token(identifier__));
			Syntax_Node const *_Nonnull const type_syntax__ = parameter__->children__->op__Element(parameter__->children__->op__magnitude()->op__subtract(int__00(1)));
			Semantic_Node const *_Nonnull const type_node__ = build_type_name_semantic_node__4(builder__, type_syntax__, name_table__, scope__);
			assert__2(not_equal_op(type_node__->referenced_type__, none), get_text__1(parameter__));
			children__->add__1(type_node__);
			Name_Subtable *_Nonnull const parameter_scope__ = lookup__2(scope__, get_text__1(identifier__));
			assert__2(not_equal_op(parameter_scope__, none), get_text__1(identifier__));
			bind_type__2(parameter_scope__, type_node__->referenced_type__);
			parameter_nodes__->add__1(new_Semantic_Node__of_type(type_node__->referenced_type__, parameter__, children__));
		}
		else if (cond(equal_op(parameter__->kind__, SelfParameter__)))
		{
			for (Syntax_Node const *_Nonnull const child_syntax__ : *(parameter__->children__))
			{
				children__->add__1(new_Semantic_Node__token(child_syntax__));
			}

			parameter_nodes__->add__1(new_Semantic_Node__concrete(parameter__, children__));
		}
		else
		{
			NOT_IMPLEMENTED__1(string__00("parameter.kind=").op__add(parameter__->kind__));
		}
	}

	return new_Semantic_Node__concrete(parameters_syntax__, parameter_nodes__);
}

auto build_type_name_semantic_node__4(Semantic_Tree_Builder const *_Nonnull const builder__, Syntax_Node const *_Nonnull const syntax__, Name_Table const *_Nonnull const name_table__, Name_Subtable const *_Nonnull const scope__) -> Semantic_Node *_Nonnull
{
	system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	if (cond(equal_op(syntax__->kind__, PredefinedType__)))
	{
		string__00 const primitive_name__ = get_text__1(syntax__->children__->op__Element(int__00(0)));
		Name_Subtable const *_Nullable const primitive_entry__ = lookup_special__2(scope__, primitive_name__);
		assert__2(not_equal_op(primitive_entry__, none), string__00("No entry for primitive `").op__add(primitive_name__)->op__add(string__00("`")));
		return new_Semantic_Node__referencing_type(primitive_entry__->type__, syntax__, children__);
	}
	else if (cond(equal_op(syntax__->kind__, IdentifierName__)))
	{
		if (cond(syntax__->is_missing__))
		{
			return new_Semantic_Node__token(syntax__);
		}

		string__00 const name__ = get_text__1(syntax__);
		Name_Subtable const *_Nullable const entry__ = lookup__2(scope__, name__);
		if (cond(equal_op(entry__, none)))
		{
			Semantic_Node *_Nonnull const node__ = new_Semantic_Node__token(syntax__);
			add_resolution_error__1(node__);
			return node__;
		}
		else
		{
			return new_Semantic_Node__referencing_type(entry__->type__, syntax__, children__);
		}
	}
	else if (cond(equal_op(syntax__->kind__, QualifiedName__)))
	{
		Syntax_Node const *_Nonnull const qualifier_syntax__ = syntax__->children__->op__Element(int__00(0));
		Semantic_Node *_Nonnull const qualifier__ = build_type_name_semantic_node__4(builder__, qualifier_syntax__, name_table__, scope__);
		children__->add__1(qualifier__);
		Syntax_Node const *_Nonnull const qualified_syntax__ = syntax__->children__->op__Element(int__00(2));
		if (cond(equal_op(qualified_syntax__->kind__, IdentifierName__)))
		{
			Syntax_Node const *_Nonnull const name_syntax__ = qualified_syntax__;
			if (cond(equal_op(qualifier__->referenced_type__, none)))
			{
				add_could_not_determine_type_error__1(qualifier__);
				Semantic_Node *_Nonnull const name_node__ = new_Semantic_Node__token(name_syntax__);
				add_resolution_error__2(name_node__, qualifier__);
				children__->add__1(name_node__);
				return new_Semantic_Node__concrete(syntax__, children__);
			}
			else
			{
				Type const *_Nonnull const containing_type__ = qualifier__->referenced_type__;
				Name_Subtable const *_Nonnull const containing_scope__ = get_name__2(name_table__, containing_type__->name__);
				assert__2(not_equal_op(containing_scope__, none), full_name__1(containing_type__->name__));
				Name_Subtable const *_Nonnull const referenced_scope__ = find__2(containing_scope__, get_text__1(name_syntax__));
				if (cond(equal_op(referenced_scope__, none)))
				{
					Semantic_Node *_Nonnull const name_node__ = new_Semantic_Node__token(name_syntax__);
					add_resolution_error__2(name_node__, qualifier__);
					children__->add__1(name_node__);
					return new_Semantic_Node__concrete(syntax__, children__);
				}

				Type const *_Nonnull const referenced_type__ = referenced_scope__->type__;
				Semantic_Node const *_Nonnull const name_node__ = new_Semantic_Node__referencing_type(referenced_type__, name_syntax__, new_system__collections__List<Semantic_Node const *_Nonnull>());
				children__->add__1(name_node__);
				return new_Semantic_Node__referencing_type(referenced_type__, syntax__, children__);
			}
		}
		else if (cond(equal_op(qualified_syntax__->kind__, GenericName__)))
		{
			Syntax_Node const *_Nonnull const name_syntax__ = first_child_syntax__2(qualified_syntax__, IdentifierName__);
			system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const generic_name_children__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
			if (cond(equal_op(qualifier__->referenced_type__, none)))
			{
				add_could_not_determine_type_error__1(qualifier__);
				Semantic_Node *_Nonnull const name_node__ = new_Semantic_Node__token(name_syntax__);
				add_resolution_error__2(name_node__, qualifier__);
				generic_name_children__->add__1(name_node__);
				build_type_arguments_semantic_node__5(builder__, qualified_syntax__, name_table__, scope__, generic_name_children__);
				Semantic_Node *_Nonnull const qualified_name__ = new_Semantic_Node__concrete(qualified_syntax__, generic_name_children__);
				children__->add__1(qualified_name__);
				return new_Semantic_Node__concrete(syntax__, children__);
			}
			else
			{
				Type const *_Nonnull const containing_type__ = qualifier__->referenced_type__;
				Name_Subtable const *_Nonnull const containing_scope__ = get_name__2(name_table__, containing_type__->name__);
				assert__2(not_equal_op(containing_scope__, none), full_name__1(containing_type__->name__));
				Name_Subtable const *_Nonnull const referenced_scope__ = find__2(containing_scope__, get_text__1(name_syntax__));
				if (cond(equal_op(referenced_scope__, none)))
				{
					Semantic_Node *_Nonnull const name_node__ = new_Semantic_Node__token(name_syntax__);
					add_resolution_error__2(name_node__, qualifier__);
					generic_name_children__->add__1(name_node__);
					build_type_arguments_semantic_node__5(builder__, qualified_syntax__, name_table__, scope__, generic_name_children__);
					Semantic_Node *_Nonnull const qualified_name__ = new_Semantic_Node__concrete(qualified_syntax__, generic_name_children__);
					children__->add__1(qualified_name__);
					return new_Semantic_Node__concrete(syntax__, children__);
				}

				Type const *_Nonnull const referenced_type_name__ = referenced_scope__->type__;
				Semantic_Node const *_Nonnull const name_node__ = new_Semantic_Node__referencing_type(referenced_type_name__, name_syntax__, new_system__collections__List<Semantic_Node const *_Nonnull>());
				generic_name_children__->add__1(name_node__);
				system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__ = build_type_arguments_semantic_node__5(builder__, qualified_syntax__, name_table__, scope__, generic_name_children__);
				Type const *_Nonnull const referenced_type__ = new_Type__generic(referenced_type_name__, type_parameters__);
				Semantic_Node *_Nonnull const qualified_name__ = new_Semantic_Node__referencing_type(referenced_type__, qualified_syntax__, generic_name_children__);
				children__->add__1(qualified_name__);
				return new_Semantic_Node__referencing_type(referenced_type__, syntax__, children__);
			}
		}
		else
		{
			UNREACHABLE__0();
		}

		UNREACHABLE__0();
	}
	else if (cond(equal_op(syntax__->kind__, MutableType__)))
	{
		Semantic_Node *_Nonnull const inner_type__ = build_type_name_semantic_node__4(builder__, syntax__->children__->op__Element(int__00(1)), name_table__, scope__);
		children__->add__1(inner_type__);
		if (cond(equal_op(inner_type__->referenced_type__, none)))
		{
			add_could_not_determine_type_error__1(inner_type__);
			return new_Semantic_Node__concrete(syntax__, children__);
		}

		Type const *_Nonnull const type__ = make_mutable_type__1(inner_type__->referenced_type__);
		return new_Semantic_Node__referencing_type(type__, syntax__, children__);
	}
	else if (cond(equal_op(syntax__->kind__, ImmutableType__)))
	{
		Semantic_Node *_Nonnull const inner_type__ = build_type_name_semantic_node__4(builder__, syntax__->children__->op__Element(int__00(0)), name_table__, scope__);
		children__->add__1(inner_type__);
		if (cond(equal_op(inner_type__->referenced_type__, none)))
		{
			add_could_not_determine_type_error__1(inner_type__);
			return new_Semantic_Node__concrete(syntax__, children__);
		}

		Type const *_Nonnull const type__ = make_immutable_type__1(inner_type__->referenced_type__);
		return new_Semantic_Node__referencing_type(type__, syntax__, children__);
	}
	else if (cond(equal_op(syntax__->kind__, OptionalType__)))
	{
		Semantic_Node *_Nonnull const inner_type__ = build_type_name_semantic_node__4(builder__, syntax__->children__->op__Element(int__00(0)), name_table__, scope__);
		children__->add__1(inner_type__);
		if (cond(equal_op(inner_type__->referenced_type__, none)))
		{
			add_could_not_determine_type_error__1(inner_type__);
			return new_Semantic_Node__concrete(syntax__, children__);
		}

		Name_Subtable const *_Nullable const optional_type_scope__ = get_name__2(name_table__, builder__->optional_type_name__);
		assert__2(not_equal_op(optional_type_scope__, none), string__00(""));
		Type const *_Nonnull const optional_type__ = optional_type_scope__->type__;
		system__collections__List<Type const *_Nonnull> *_Nonnull const type_arguments__ = new_system__collections__List<Type const *_Nonnull>();
		type_arguments__->add__1(inner_type__->referenced_type__);
		Type const *_Nonnull const type__ = new_Type__generic(optional_type__, type_arguments__);
		return new_Semantic_Node__referencing_type(type__, syntax__, children__);
	}
	else
	{
		int__00 const place__ = syntax__->start__;
		NOT_IMPLEMENTED__1(string__00("syntax.kind=").op__add(syntax__->kind__)->op__add(string__00(" at "))->op__add(place__));
	}
}

auto build_type_arguments_semantic_node__5(Semantic_Tree_Builder const *_Nonnull const builder__, Syntax_Node const *_Nonnull const syntax__, Name_Table const *_Nonnull const name_table__, Name_Subtable const *_Nonnull const scope__, system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const children__) -> system__collections__List<Type const *_Nonnull> const *_Nonnull
{
	system__collections__List<Type const *_Nonnull> *_Nonnull const type_parameters__ = new_system__collections__List<Type const *_Nonnull>();
	if (cond(equal_op(syntax__->kind__, IdentifierName__)))
	{
		return type_parameters__;
	}

	assert__2(equal_op(syntax__->kind__, GenericName__), string__00("syntax.kind==").op__add(syntax__->kind__));
	bool__00 in_type_arguments__ = false__00;
	for (Syntax_Node const *_Nonnull const type_argument__ : *(syntax__->children__))
	{
		if (cond(in_type_arguments__))
		{
			if (cond(not_equal_op(type_argument__->kind__, GreaterThan__)))
			{
				Semantic_Node const *_Nonnull const type_node__ = build_type_name_semantic_node__4(builder__, type_argument__, name_table__, scope__);
				type_parameters__->add__1(type_node__->referenced_type__);
				children__->add__1(type_node__);
			}
		}
		else if (cond(equal_op(type_argument__->kind__, LessThan__)))
		{
			in_type_arguments__ = true__00;
		}
	}

	return type_parameters__;
}

auto build_constructor_name_semantic_node__4(Semantic_Tree_Builder const *_Nonnull const builder__, Syntax_Node const *_Nonnull const syntax__, Name_Table const *_Nonnull const name_table__, Name_Subtable const *_Nonnull const scope__) -> Semantic_Node const *_Nonnull
{
	if (cond(bool__00__op(bool__00__arg(equal_op(syntax__->kind__, QualifiedName__)) && bool__00__arg(equal_op(syntax__->children__->op__Element(int__00(2))->kind__, IdentifierName__)))))
	{
		system__collections__List<Semantic_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
		Semantic_Node const *_Nonnull const type_node__ = build_type_name_semantic_node__4(builder__, syntax__->children__->op__Element(int__00(0)), name_table__, scope__);
		children__->add__1(type_node__);
		Syntax_Node const *_Nonnull const qualifier__ = syntax__->children__->op__Element(int__00(0));
		Syntax_Node const *_Nonnull const name__ = syntax__->children__->op__Element(int__00(2));
		string__00 const constructor_name__ = string__00("new_").op__add(get_text__1(name__));
		Type const *_Nonnull const referenced_type__ = type_node__->referenced_type__;
		assert__2(not_equal_op(referenced_type__, none), string__00("no referenced type for `").op__add(get_text__1(type_node__))->op__add(string__00("`")));
		Name_Subtable const *_Nullable const constructor_scope__ = lookup_special__2(get_name__2(name_table__, referenced_type__->name__), constructor_name__);
		if (cond(not_equal_op(constructor_scope__, none)))
		{
			children__->add__1(new_Semantic_Node__token(name__));
			return new_Semantic_Node__concrete(syntax__, children__);
		}
	}

	return build_type_name_semantic_node__4(builder__, syntax__, name_table__, scope__);
}

auto add_resolution_error__1(Semantic_Node *_Nonnull const node__) -> void
{
	add_diagnostic__2(node__, new_Diagnostic(FatalCompilationError__, Analysis__, node__->source__, get_text_span__1(node__), string__00("Could not resolve name `").op__add(get_text__1(node__))->op__add(string__00("`"))));
}

auto add_resolution_error__2(Semantic_Node *_Nonnull const node__, Semantic_Node const *_Nonnull const qualifier__) -> void
{
	add_diagnostic__2(node__, new_Diagnostic(FatalCompilationError__, Analysis__, node__->source__, get_text_span__1(node__), string__00("Could not resolve name `").op__add(get_text__1(node__))->op__add(string__00("` because qualifier `"))->op__add(get_text__1(qualifier__))->op__add(string__00("` could not be resolved."))));
}

auto add_could_not_determine_type_error__1(Semantic_Node *_Nonnull const node__) -> void
{
	add_diagnostic__2(node__, new_Diagnostic(FatalCompilationError__, Analysis__, node__->source__, get_text_span__1(node__), string__00("Could not determine type for `").op__add(get_text__1(node__))->op__add(string__00("`"))));
}

auto build_symbols__2(Package_Name const *_Nonnull const package_name__, system__collections__List<Compilation_Unit const *_Nonnull> const *_Nonnull const compilation_units__) -> Symbol const *_Nonnull
{
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const symbols__ = new_system__collections__List<Symbol const *_Nonnull>();
	return new_Symbol__package(package_name__->unqualified__, symbols__);
}

Compilation_Unit_Parser *_Nonnull Compilation_Unit_Parser__0new__1(Compilation_Unit_Parser *_Nonnull self, Token_Stream *_Nonnull const token_stream__)
{
	self->token_stream__ = token_stream__;
	self->compilation_unit__ = none;
	return self;
}

inline Compilation_Unit_Parser *_Nonnull new_Compilation_Unit_Parser(Token_Stream *_Nonnull const token_stream__)
{
	return Compilation_Unit_Parser__0new__1(new Compilation_Unit_Parser(), token_stream__);
}

auto parse__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull
{
	if (cond(equal_op(parser__->compilation_unit__, none)))
	{
		parser__->token__ = next_token__1(parser__->token_stream__);
		parser__->compilation_unit__ = parse_compilation_unit__1(parser__);
	}

	return parser__->compilation_unit__;
}

auto accept_token__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nullable
{
	Syntax_Node const *_Nullable const node__ = parser__->token__;
	parser__->token__ = next_token__1(parser__->token_stream__);
	return node__;
}

auto expect_token__2(Compilation_Unit_Parser *_Nonnull const parser__, int__00 const tokenType__) -> Syntax_Node const *_Nonnull
{
	if (cond(equal_op(parser__->token__, none)))
	{
		return new_Syntax_Node__missing(tokenType__, parser__->token_stream__->source__, source_byte_length__1(parser__->token_stream__->source__));
	}

	if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__, none)) || bool__00__arg(not_equal_op(parser__->token__->kind__, tokenType__)))))
	{
		return new_Syntax_Node__missing(tokenType__, parser__->token_stream__->source__, parser__->token__->start__);
	}

	Syntax_Node const *_Nullable const node__ = parser__->token__;
	parser__->token__ = next_token__1(parser__->token_stream__);
	return node__;
}

auto parse_type_name__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull
{
	if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, CodePoint__)) || bool__00__arg(equal_op(parser__->token__->kind__, String__)))) || bool__00__arg(equal_op(parser__->token__->kind__, Int__)))) || bool__00__arg(equal_op(parser__->token__->kind__, Bool__)))) || bool__00__arg(equal_op(parser__->token__->kind__, Void__)))) || bool__00__arg(equal_op(parser__->token__->kind__, UnsignedInt__)))))
	{
		return new_Syntax_Node(PredefinedType__, accept_token__1(parser__));
	}
	else
	{
		Syntax_Node const *_Nonnull type__ = new_Syntax_Node(IdentifierName__, expect_token__2(parser__, Identifier__));
		while (cond(equal_op(parser__->token__->kind__, Dot__)))
		{
			system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
			children__->add__1(type__);
			children__->add__1(expect_token__2(parser__, Dot__));
			Syntax_Node const *_Nonnull const identifier__ = expect_token__2(parser__, Identifier__);
			if (cond(equal_op(parser__->token__->kind__, LessThan__)))
			{
				system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const genericNameChildren__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
				genericNameChildren__->add__1(new_Syntax_Node(IdentifierName__, identifier__));
				genericNameChildren__->add__1(expect_token__2(parser__, LessThan__));
				genericNameChildren__->add__1(parse_type__1(parser__));
				genericNameChildren__->add__1(expect_token__2(parser__, GreaterThan__));
				children__->add__1(new_Syntax_Node(GenericName__, genericNameChildren__));
			}
			else
			{
				children__->add__1(new_Syntax_Node(IdentifierName__, identifier__));
			}

			type__ = new_Syntax_Node(QualifiedName__, children__);
		}

		return type__;
	}
}

auto parse_non_optional_type__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	if (cond(equal_op(parser__->token__->kind__, MutableKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, MutableKeyword__));
		children__->add__1(parse_type_name__1(parser__));
		return new_Syntax_Node(MutableType__, children__);
	}
	else
	{
		children__->add__1(parse_type_name__1(parser__));
		return new_Syntax_Node(ImmutableType__, children__);
	}
}

auto parse_type__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull
{
	Syntax_Node const *_Nonnull type__ = parse_non_optional_type__1(parser__);
	while (cond(equal_op(parser__->token__->kind__, Question__)))
	{
		system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
		children__->add__1(type__);
		children__->add__1(expect_token__2(parser__, Question__));
		type__ = new_Syntax_Node(ImmutableType__, new_Syntax_Node(OptionalType__, children__));
	}

	return type__;
}

auto parse_atom__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	if (cond(equal_op(parser__->token__->kind__, NewKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, NewKeyword__));
		children__->add__1(parse_type_name__1(parser__));
		children__->add__1(parse_call_arguments__1(parser__));
		return new_Syntax_Node(NewExpression__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, NotOperator__)))
	{
		children__->add__1(expect_token__2(parser__, NotOperator__));
		children__->add__1(parse_expression__2(parser__, int__00(8)));
		return new_Syntax_Node(NotExpression__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, LeftParen__)))
	{
		children__->add__1(expect_token__2(parser__, LeftParen__));
		children__->add__1(parse_expression__1(parser__));
		children__->add__1(expect_token__2(parser__, RightParen__));
		return new_Syntax_Node(ParenthesizedExpression__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, Pipe__)))
	{
		children__->add__1(expect_token__2(parser__, Pipe__));
		children__->add__1(parse_expression__1(parser__));
		children__->add__1(expect_token__2(parser__, Pipe__));
		return new_Syntax_Node(MagnitudeExpression__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, Minus__)))
	{
		children__->add__1(expect_token__2(parser__, Minus__));
		children__->add__1(parse_expression__2(parser__, int__00(8)));
		return new_Syntax_Node(NegateExpression__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, NoneKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, NoneKeyword__));
		return new_Syntax_Node(NoneLiteralExpression__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, SelfKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, SelfKeyword__));
		return new_Syntax_Node(SelfExpression__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, TrueKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, TrueKeyword__));
		return new_Syntax_Node(TrueLiteralExpression__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, FalseKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, FalseKeyword__));
		return new_Syntax_Node(FalseLiteralExpression__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, Number__)))
	{
		children__->add__1(expect_token__2(parser__, Number__));
		return new_Syntax_Node(NumericLiteralExpression__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, Identifier__)))
	{
		children__->add__1(expect_token__2(parser__, Identifier__));
		return new_Syntax_Node(IdentifierName__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, StringLiteral__)))
	{
		children__->add__1(expect_token__2(parser__, StringLiteral__));
		return new_Syntax_Node(StringLiteralExpression__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, CodePointLiteral__)))
	{
		children__->add__1(expect_token__2(parser__, CodePointLiteral__));
		return new_Syntax_Node(CodePointLiteralExpression__, children__);
	}

	return new_Syntax_Node(IdentifierName__, expect_token__2(parser__, Identifier__));
}

auto parse_call_arguments__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	children__->add__1(expect_token__2(parser__, LeftParen__));
	if (cond(not_equal_op(parser__->token__->kind__, RightParen__)))
	{
		for (;;)
		{
			children__->add__1(parse_expression__1(parser__));
			if (cond(equal_op(parser__->token__->kind__, Comma__)))
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
	return new_Syntax_Node(ArgumentList__, children__);
}

auto parse_expression__2(Compilation_Unit_Parser *_Nonnull const parser__, int__00 const minPrecedence__) -> Syntax_Node const *_Nonnull
{
	Syntax_Node const *_Nonnull expression__ = parse_atom__1(parser__);
	for (;;)
	{
		system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
		children__->add__1(expression__);
		int__00 precedence__;
		bool__00 leftAssociative__;
		bool__00 suffixOperator__ = false__00;
		int__00 expressionType__;
		if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, Equals__)) || bool__00__arg(equal_op(parser__->token__->kind__, PlusEquals__)))) || bool__00__arg(equal_op(parser__->token__->kind__, MinusEquals__)))) && bool__00__arg(int__00__0op__less_than_or_equal(minPrecedence__, int__00(1))))))
		{
			precedence__ = int__00(1);
			leftAssociative__ = false__00;
			children__->add__1(accept_token__1(parser__));
			expressionType__ = AssignmentExpression__;
		}
		else if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, OrKeyword__)) && bool__00__arg(int__00__0op__less_than_or_equal(minPrecedence__, int__00(2))))))
		{
			precedence__ = int__00(2);
			leftAssociative__ = true__00;
			children__->add__1(expect_token__2(parser__, OrKeyword__));
			expressionType__ = OrExpression__;
		}
		else if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, AndKeyword__)) && bool__00__arg(int__00__0op__less_than_or_equal(minPrecedence__, int__00(3))))))
		{
			precedence__ = int__00(3);
			leftAssociative__ = true__00;
			children__->add__1(expect_token__2(parser__, AndKeyword__));
			expressionType__ = AndExpression__;
		}
		else if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, EqualsEquals__)) && bool__00__arg(int__00__0op__less_than_or_equal(minPrecedence__, int__00(4))))))
		{
			precedence__ = int__00(4);
			leftAssociative__ = true__00;
			children__->add__1(expect_token__2(parser__, EqualsEquals__));
			expressionType__ = EqualExpression__;
		}
		else if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, EqualsSlashEquals__)) && bool__00__arg(int__00__0op__less_than_or_equal(minPrecedence__, int__00(4))))))
		{
			precedence__ = int__00(4);
			leftAssociative__ = true__00;
			children__->add__1(expect_token__2(parser__, EqualsSlashEquals__));
			expressionType__ = NotEqualExpression__;
		}
		else if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, LessThan__)) || bool__00__arg(equal_op(parser__->token__->kind__, LessThanEquals__)))) || bool__00__arg(equal_op(parser__->token__->kind__, GreaterThan__)))) || bool__00__arg(equal_op(parser__->token__->kind__, GreaterThanEquals__)))) && bool__00__arg(int__00__0op__less_than_or_equal(minPrecedence__, int__00(5))))))
		{
			precedence__ = int__00(5);
			leftAssociative__ = true__00;
			children__->add__1(accept_token__1(parser__));
			expressionType__ = ComparisonExpression__;
		}
		else if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, Plus__)) && bool__00__arg(int__00__0op__less_than_or_equal(minPrecedence__, int__00(6))))))
		{
			precedence__ = int__00(6);
			leftAssociative__ = true__00;
			children__->add__1(expect_token__2(parser__, Plus__));
			expressionType__ = AddExpression__;
		}
		else if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, Minus__)) && bool__00__arg(int__00__0op__less_than_or_equal(minPrecedence__, int__00(6))))))
		{
			precedence__ = int__00(6);
			leftAssociative__ = true__00;
			children__->add__1(expect_token__2(parser__, Minus__));
			expressionType__ = SubtractExpression__;
		}
		else if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, Asterisk__)) && bool__00__arg(int__00__0op__less_than_or_equal(minPrecedence__, int__00(7))))))
		{
			precedence__ = int__00(7);
			leftAssociative__ = true__00;
			children__->add__1(expect_token__2(parser__, Asterisk__));
			expressionType__ = MultiplyExpression__;
		}
		else if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, Slash__)) && bool__00__arg(int__00__0op__less_than_or_equal(minPrecedence__, int__00(7))))))
		{
			precedence__ = int__00(7);
			leftAssociative__ = true__00;
			children__->add__1(expect_token__2(parser__, Slash__));
			expressionType__ = DivideExpression__;
		}
		else if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, Percent__)) && bool__00__arg(int__00__0op__less_than_or_equal(minPrecedence__, int__00(7))))))
		{
			precedence__ = int__00(7);
			leftAssociative__ = true__00;
			children__->add__1(expect_token__2(parser__, Percent__));
			expressionType__ = RemainderExpression__;
		}
		else if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, LeftParen__)) && bool__00__arg(int__00__0op__less_than_or_equal(minPrecedence__, int__00(9))))))
		{
			precedence__ = int__00(9);
			leftAssociative__ = true__00;
			suffixOperator__ = true__00;
			children__->add__1(parse_call_arguments__1(parser__));
			expressionType__ = InvocationExpression__;
		}
		else if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, Dot__)) && bool__00__arg(int__00__0op__less_than_or_equal(minPrecedence__, int__00(9))))))
		{
			precedence__ = int__00(9);
			leftAssociative__ = true__00;
			children__->add__1(expect_token__2(parser__, Dot__));
			expressionType__ = MemberAccessExpression__;
		}
		else if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, LeftBracket__)) && bool__00__arg(int__00__0op__less_than_or_equal(minPrecedence__, int__00(9))))))
		{
			precedence__ = int__00(9);
			leftAssociative__ = true__00;
			suffixOperator__ = true__00;
			children__->add__1(expect_token__2(parser__, LeftBracket__));
			children__->add__1(parse_expression__1(parser__));
			children__->add__1(expect_token__2(parser__, RightBracket__));
			expressionType__ = ElementAccessExpression__;
		}
		else
		{
			return expression__;
		}

		if (cond(bool__00__0op__not(suffixOperator__)))
		{
			if (cond(leftAssociative__))
			{
				precedence__.op__add_assign(int__00(1));
			}

			children__->add__1(parse_expression__2(parser__, precedence__));
			expression__ = new_Syntax_Node(expressionType__, children__);
		}
		else
		{
			expression__ = new_Syntax_Node(expressionType__, children__);
		}
	}
}

auto parse_expression__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull
{
	return parse_expression__2(parser__, int__00(1));
}

auto parse_statement__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	if (cond(equal_op(parser__->token__->kind__, ReturnKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, ReturnKeyword__));
		if (cond(not_equal_op(parser__->token__->kind__, Semicolon__)))
		{
			children__->add__1(parse_expression__1(parser__));
		}

		children__->add__1(expect_token__2(parser__, Semicolon__));
		return new_Syntax_Node(ReturnStatement__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, LoopKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, LoopKeyword__));
		children__->add__1(parse_block__1(parser__));
		return new_Syntax_Node(LoopStatement__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, WhileKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, WhileKeyword__));
		children__->add__1(parse_expression__1(parser__));
		children__->add__1(parse_block__1(parser__));
		return new_Syntax_Node(WhileStatement__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, ForKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, ForKeyword__));
		children__->add__1(parse_variable_declaration__2(parser__, false__00));
		children__->add__1(expect_token__2(parser__, InKeyword__));
		children__->add__1(parse_expression__1(parser__));
		children__->add__1(parse_block__1(parser__));
		return new_Syntax_Node(ForStatement__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, DoKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, DoKeyword__));
		children__->add__1(parse_block__1(parser__));
		children__->add__1(expect_token__2(parser__, WhileKeyword__));
		children__->add__1(parse_expression__1(parser__));
		children__->add__1(expect_token__2(parser__, Semicolon__));
		return new_Syntax_Node(DoWhileStatement__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, IfKeyword__)))
	{
		return parse_if_statement__1(parser__);
	}

	if (cond(equal_op(parser__->token__->kind__, BreakKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, BreakKeyword__));
		children__->add__1(expect_token__2(parser__, Semicolon__));
		return new_Syntax_Node(BreakStatement__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, ContinueKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, ContinueKeyword__));
		children__->add__1(expect_token__2(parser__, Semicolon__));
		return new_Syntax_Node(ContinueStatement__, children__);
	}

	if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, VarKeyword__)) || bool__00__arg(equal_op(parser__->token__->kind__, LetKeyword__)))))
	{
		children__->add__1(parse_variable_declaration__2(parser__, true__00));
		children__->add__1(expect_token__2(parser__, Semicolon__));
		return new_Syntax_Node(LocalDeclarationStatement__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, LeftBrace__)))
	{
		return parse_block__1(parser__);
	}

	children__->add__1(parse_expression__1(parser__));
	children__->add__1(expect_token__2(parser__, Semicolon__));
	return new_Syntax_Node(ExpressionStatement__, children__);
}

auto parse_if_statement__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	children__->add__1(expect_token__2(parser__, IfKeyword__));
	children__->add__1(parse_expression__1(parser__));
	children__->add__1(parse_block__1(parser__));
	if (cond(equal_op(parser__->token__->kind__, ElseKeyword__)))
	{
		system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const elseChildren__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
		elseChildren__->add__1(expect_token__2(parser__, ElseKeyword__));
		if (cond(equal_op(parser__->token__->kind__, IfKeyword__)))
		{
			elseChildren__->add__1(parse_if_statement__1(parser__));
		}
		else
		{
			elseChildren__->add__1(parse_block__1(parser__));
		}

		children__->add__1(new_Syntax_Node(ElseClause__, elseChildren__));
	}

	return new_Syntax_Node(IfStatement__, children__);
}

auto parse_variable_declaration__2(Compilation_Unit_Parser *_Nonnull const parser__, bool__00 const allowInitializer__) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, LetKeyword__)) && bool__00__arg(not_equal_op(parser__->token__->kind__, VarKeyword__)))))
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
	if (cond(bool__00__op(bool__00__arg(allowInitializer__) && bool__00__arg(equal_op(parser__->token__->kind__, Equals__)))))
	{
		children__->add__1(expect_token__2(parser__, Equals__));
		children__->add__1(parse_expression__1(parser__));
	}

	return new_Syntax_Node(VariableDeclaration__, children__);
}

auto parse_block__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	children__->add__1(expect_token__2(parser__, LeftBrace__));
	while (cond(bool__00__op(bool__00__arg(not_equal_op(parser__->token__->kind__, RightBrace__)) && bool__00__arg(not_equal_op(parser__->token__->kind__, EndOfFileToken__)))))
	{
		Syntax_Node const *_Nonnull const startToken__ = parser__->token__;
		children__->add__1(parse_statement__1(parser__));
		if (cond(equal_op(parser__->token__, startToken__)))
		{
			system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const skipped__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
			while (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(not_equal_op(parser__->token__->kind__, LeftBrace__)) && bool__00__arg(not_equal_op(parser__->token__->kind__, RightBrace__)))) && bool__00__arg(not_equal_op(parser__->token__->kind__, EndOfFileToken__)))))
			{
				int__00 const currentTokenType__ = parser__->token__->kind__;
				skipped__->add__1(accept_token__1(parser__));
				if (cond(equal_op(currentTokenType__, Semicolon__)))
				{
					break;
				}
			}

			children__->add__1(new_Syntax_Node__skipped(skipped__));
		}
	}

	children__->add__1(expect_token__2(parser__, RightBrace__));
	return new_Syntax_Node(Block__, children__);
}

auto parse_parameter_list__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	children__->add__1(expect_token__2(parser__, LeftParen__));
	if (cond(not_equal_op(parser__->token__->kind__, RightParen__)))
	{
		for (;;)
		{
			system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const parameterChildren__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
			if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, MutableKeyword__)) || bool__00__arg(equal_op(parser__->token__->kind__, SelfKeyword__)))))
			{
				if (cond(equal_op(parser__->token__->kind__, MutableKeyword__)))
				{
					parameterChildren__->add__1(expect_token__2(parser__, MutableKeyword__));
				}

				parameterChildren__->add__1(expect_token__2(parser__, SelfKeyword__));
				children__->add__1(new_Syntax_Node(SelfParameter__, parameterChildren__));
			}
			else
			{
				bool__00 const mutableBinding__ = equal_op(parser__->token__->kind__, VarKeyword__);
				if (cond(equal_op(parser__->token__->kind__, VarKeyword__)))
				{
					parameterChildren__->add__1(expect_token__2(parser__, VarKeyword__));
				}

				parameterChildren__->add__1(expect_token__2(parser__, Identifier__));
				parameterChildren__->add__1(expect_token__2(parser__, Colon__));
				Syntax_Node const *_Nonnull const type__ = parse_type__1(parser__);
				parameterChildren__->add__1(type__);
				children__->add__1(new_Syntax_Node(Parameter__, parameterChildren__));
			}

			if (cond(equal_op(parser__->token__->kind__, Comma__)))
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
	return new_Syntax_Node(ParameterList__, children__);
}

auto parse_member_declaration__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, PublicKeyword__)) || bool__00__arg(equal_op(parser__->token__->kind__, ProtectedKeyword__)))) || bool__00__arg(equal_op(parser__->token__->kind__, InternalKeyword__)))) || bool__00__arg(equal_op(parser__->token__->kind__, PrivateKeyword__)))))
	{
		children__->add__1(accept_token__1(parser__));
	}
	else
	{
		children__->add__1(expect_token__2(parser__, PublicKeyword__));
	}

	if (cond(equal_op(parser__->token__->kind__, NewKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, NewKeyword__));
		if (cond(equal_op(parser__->token__->kind__, Identifier__)))
		{
			children__->add__1(expect_token__2(parser__, Identifier__));
		}

		children__->add__1(parse_parameter_list__1(parser__));
		children__->add__1(parse_block__1(parser__));
		return new_Syntax_Node(ConstructorDeclaration__, children__);
	}

	if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, VarKeyword__)) || bool__00__arg(equal_op(parser__->token__->kind__, LetKeyword__)))))
	{
		children__->add__1(parse_variable_declaration__2(parser__, false__00));
		children__->add__1(expect_token__2(parser__, Semicolon__));
		return new_Syntax_Node(FieldDeclaration__, children__);
	}

	children__->add__1(expect_token__2(parser__, Identifier__));
	children__->add__1(parse_parameter_list__1(parser__));
	children__->add__1(expect_token__2(parser__, Arrow__));
	children__->add__1(parse_type__1(parser__));
	children__->add__1(parse_block__1(parser__));
	return new_Syntax_Node(MethodDeclaration__, children__);
}

auto parse_declaration__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, PublicKeyword__)) || bool__00__arg(equal_op(parser__->token__->kind__, ProtectedKeyword__)))) || bool__00__arg(equal_op(parser__->token__->kind__, InternalKeyword__)))) || bool__00__arg(equal_op(parser__->token__->kind__, PrivateKeyword__)))))
	{
		children__->add__1(accept_token__1(parser__));
	}
	else
	{
		children__->add__1(expect_token__2(parser__, PublicKeyword__));
	}

	if (cond(bool__00__op(bool__00__arg(equal_op(parser__->token__->kind__, VarKeyword__)) || bool__00__arg(equal_op(parser__->token__->kind__, LetKeyword__)))))
	{
		children__->add__1(parse_variable_declaration__2(parser__, true__00));
		children__->add__1(expect_token__2(parser__, Semicolon__));
		return new_Syntax_Node(GlobalDeclaration__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, ClassKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, ClassKeyword__));
		children__->add__1(expect_token__2(parser__, Identifier__));
		children__->add__1(expect_token__2(parser__, LeftBrace__));
		while (cond(bool__00__op(bool__00__arg(not_equal_op(parser__->token__->kind__, RightBrace__)) && bool__00__arg(not_equal_op(parser__->token__->kind__, EndOfFileToken__)))))
		{
			Syntax_Node const *_Nonnull const startToken__ = parser__->token__;
			children__->add__1(parse_member_declaration__1(parser__));
			if (cond(equal_op(parser__->token__, startToken__)))
			{
				children__->add__1(new_Syntax_Node__skipped(accept_token__1(parser__)));
			}
		}

		children__->add__1(expect_token__2(parser__, RightBrace__));
		return new_Syntax_Node(ClassDeclaration__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, StructKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, StructKeyword__));
		children__->add__1(expect_token__2(parser__, Identifier__));
		children__->add__1(expect_token__2(parser__, LeftBrace__));
		while (cond(bool__00__op(bool__00__arg(not_equal_op(parser__->token__->kind__, RightBrace__)) && bool__00__arg(not_equal_op(parser__->token__->kind__, EndOfFileToken__)))))
		{
			Syntax_Node const *_Nonnull const startToken__ = parser__->token__;
			children__->add__1(parse_member_declaration__1(parser__));
			if (cond(equal_op(parser__->token__, startToken__)))
			{
				children__->add__1(new_Syntax_Node__skipped(accept_token__1(parser__)));
			}
		}

		children__->add__1(expect_token__2(parser__, RightBrace__));
		return new_Syntax_Node(StructDeclaration__, children__);
	}

	if (cond(equal_op(parser__->token__->kind__, EnumKeyword__)))
	{
		children__->add__1(expect_token__2(parser__, EnumKeyword__));
		children__->add__1(expect_token__2(parser__, StructKeyword__));
		children__->add__1(expect_token__2(parser__, Identifier__));
		children__->add__1(expect_token__2(parser__, LeftBrace__));
		while (cond(bool__00__op(bool__00__arg(not_equal_op(parser__->token__->kind__, RightBrace__)) && bool__00__arg(not_equal_op(parser__->token__->kind__, EndOfFileToken__)))))
		{
			system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const memberChildren__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
			memberChildren__->add__1(expect_token__2(parser__, Identifier__));
			if (cond(equal_op(parser__->token__->kind__, Equals__)))
			{
				memberChildren__->add__1(expect_token__2(parser__, Equals__));
				memberChildren__->add__1(expect_token__2(parser__, Number__));
			}

			if (cond(not_equal_op(parser__->token__->kind__, RightBrace__)))
			{
				memberChildren__->add__1(expect_token__2(parser__, Comma__));
			}

			children__->add__1(new_Syntax_Node(EnumMemberDeclaration__, memberChildren__));
		}

		children__->add__1(expect_token__2(parser__, RightBrace__));
		return new_Syntax_Node(EnumDeclaration__, children__);
	}

	children__->add__1(expect_token__2(parser__, Identifier__));
	children__->add__1(parse_parameter_list__1(parser__));
	children__->add__1(expect_token__2(parser__, Arrow__));
	children__->add__1(parse_type__1(parser__));
	children__->add__1(parse_block__1(parser__));
	return new_Syntax_Node(FunctionDeclaration__, children__);
}

auto parse_compilation_unit__1(Compilation_Unit_Parser *_Nonnull const parser__) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	while (cond(bool__00__op(bool__00__arg(not_equal_op(parser__->token__, none)) && bool__00__arg(not_equal_op(parser__->token__->kind__, EndOfFileToken__)))))
	{
		Syntax_Node const *_Nonnull const startToken__ = parser__->token__;
		children__->add__1(parse_declaration__1(parser__));
		if (cond(equal_op(parser__->token__, startToken__)))
		{
			children__->add__1(new_Syntax_Node__skipped(accept_token__1(parser__)));
		}
	}

	children__->add__1(expect_token__2(parser__, EndOfFileToken__));
	return new_Syntax_Node(CompilationUnit__, children__);
}

auto lexically_analyze__1(Source_Text const *_Nonnull const source__) -> Token_Stream *_Nonnull
{
	return new_Token_Stream(source__);
}

auto parse_package__1(system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const sources__) -> Syntax_Node const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	for (Source_Text const *_Nonnull const source__ : *(sources__))
	{
		Token_Stream *_Nonnull const token_stream__ = lexically_analyze__1(source__);
		Compilation_Unit_Parser *_Nonnull const compilation_unit_parser__ = new_Compilation_Unit_Parser(token_stream__);
		children__->add__1(parse__1(compilation_unit_parser__));
	}

	return new_Syntax_Node(PackageNode__, children__);
}

Syntax_Node *_Nonnull Syntax_Node__0new__4(Syntax_Node *_Nonnull self, int__00 const type__, Source_Text const *_Nonnull const source__, uint__00 const start__, uint__00 const length__)
{
	self->kind__ = type__;
	self->is_missing__ = false__00;
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = length__;
	self->children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	self->node_diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	return self;
}

inline Syntax_Node *_Nonnull new_Syntax_Node(int__00 const type__, Source_Text const *_Nonnull const source__, uint__00 const start__, uint__00 const length__)
{
	return Syntax_Node__0new__4(new Syntax_Node(), type__, source__, start__, length__);
}

Syntax_Node *_Nonnull Syntax_Node__0new__5(Syntax_Node *_Nonnull self, int__00 const type__, bool__00 const isMissing__, Source_Text const *_Nonnull const source__, uint__00 const start__, uint__00 const length__)
{
	self->kind__ = type__;
	self->is_missing__ = isMissing__;
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = length__;
	self->children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	self->node_diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	return self;
}

inline Syntax_Node *_Nonnull new_Syntax_Node(int__00 const type__, bool__00 const isMissing__, Source_Text const *_Nonnull const source__, uint__00 const start__, uint__00 const length__)
{
	return Syntax_Node__0new__5(new Syntax_Node(), type__, isMissing__, source__, start__, length__);
}

Syntax_Node *_Nonnull Syntax_Node__0new__2(Syntax_Node *_Nonnull self, int__00 const type__, Syntax_Node const *_Nonnull const child__)
{
	self->kind__ = type__;
	self->is_missing__ = child__->is_missing__;
	self->source__ = child__->source__;
	self->start__ = child__->start__;
	self->byte_length__ = child__->byte_length__;
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	children__->add__1(child__);
	self->children__ = children__;
	self->node_diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	return self;
}

inline Syntax_Node *_Nonnull new_Syntax_Node(int__00 const type__, Syntax_Node const *_Nonnull const child__)
{
	return Syntax_Node__0new__2(new Syntax_Node(), type__, child__);
}

Syntax_Node *_Nonnull Syntax_Node__0new__2(Syntax_Node *_Nonnull self, int__00 const type__, system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const children__)
{
	self->kind__ = type__;
	self->is_missing__ = false__00;
	self->source__ = children__->op__Element(int__00(0))->source__;
	self->start__ = children__->op__Element(int__00(0))->start__;
	Syntax_Node const *_Nonnull const lastChild__ = children__->op__Element(children__->op__magnitude()->op__subtract(int__00(1)));
	self->byte_length__ = lastChild__->start__.op__subtract(self->start__)->op__add(lastChild__->byte_length__);
	self->children__ = children__;
	self->node_diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	return self;
}

inline Syntax_Node *_Nonnull new_Syntax_Node(int__00 const type__, system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const children__)
{
	return Syntax_Node__0new__2(new Syntax_Node(), type__, children__);
}

Syntax_Node *_Nonnull Syntax_Node__0new__missing__3(Syntax_Node *_Nonnull self, int__00 const type__, Source_Text const *_Nonnull const source__, uint__00 const start__)
{
	self->kind__ = type__;
	self->is_missing__ = true__00;
	self->source__ = source__;
	self->start__ = start__;
	self->byte_length__ = int__00(0);
	self->children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	self->node_diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	Text_Span const *_Nonnull const span__ = new_Text_Span(start__, int__00(0));
	self->node_diagnostics__->add__1(new_Diagnostic(CompilationError__, Parsing__, source__, span__, string__00("Missing token of type ").op__add(type__)));
	return self;
}

inline Syntax_Node *_Nonnull new_Syntax_Node__missing(int__00 const type__, Source_Text const *_Nonnull const source__, uint__00 const start__)
{
	return Syntax_Node__0new__missing__3(new Syntax_Node(), type__, source__, start__);
}

Syntax_Node *_Nonnull Syntax_Node__0new__skipped__1(Syntax_Node *_Nonnull self, Syntax_Node const *_Nonnull const skipped_node__)
{
	self->kind__ = SkippedTokens__;
	self->is_missing__ = skipped_node__->is_missing__;
	self->source__ = skipped_node__->source__;
	self->start__ = skipped_node__->start__;
	self->byte_length__ = skipped_node__->byte_length__;
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	children__->add__1(skipped_node__);
	self->children__ = children__;
	self->node_diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	Text_Span const *_Nonnull const span__ = new_Text_Span(skipped_node__->start__, skipped_node__->byte_length__);
	self->node_diagnostics__->add__1(new_Diagnostic(CompilationError__, Parsing__, skipped_node__->source__, span__, string__00("Skipped unexpected token of type ").op__add(skipped_node__->kind__)));
	return self;
}

inline Syntax_Node *_Nonnull new_Syntax_Node__skipped(Syntax_Node const *_Nonnull const skipped_node__)
{
	return Syntax_Node__0new__skipped__1(new Syntax_Node(), skipped_node__);
}

Syntax_Node *_Nonnull Syntax_Node__0new__skipped__1(Syntax_Node *_Nonnull self, system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const skipped_nodes__)
{
	self->kind__ = SkippedTokens__;
	self->is_missing__ = false__00;
	self->source__ = skipped_nodes__->op__Element(int__00(0))->source__;
	self->start__ = skipped_nodes__->op__Element(int__00(0))->start__;
	Syntax_Node const *_Nonnull const lastChild__ = skipped_nodes__->op__Element(skipped_nodes__->op__magnitude()->op__subtract(int__00(1)));
	self->byte_length__ = lastChild__->start__.op__subtract(self->start__)->op__add(lastChild__->byte_length__);
	self->children__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	self->node_diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	Text_Span const *_Nonnull const span__ = new_Text_Span(self->start__, self->byte_length__);
	self->node_diagnostics__->add__1(new_Diagnostic(CompilationError__, Parsing__, self->source__, span__, string__00("Skipped ").op__add(skipped_nodes__->op__magnitude())->op__add(string__00(" unexpected token(s)"))));
	return self;
}

inline Syntax_Node *_Nonnull new_Syntax_Node__skipped(system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull const skipped_nodes__)
{
	return Syntax_Node__0new__skipped__1(new Syntax_Node(), skipped_nodes__);
}

auto get_text__1(Syntax_Node const *_Nonnull const syntax__) -> string__00
{
	return syntax__->source__->text__.Substring__2(syntax__->start__, syntax__->byte_length__);
}

auto first_child_syntax__2(Syntax_Node const *_Nonnull const syntax__, int__00 const type__) -> Syntax_Node const *_Nullable
{
	for (Syntax_Node const *_Nonnull const child__ : *(syntax__->children__))
	{
		if (cond(equal_op(child__->kind__, type__)))
		{
			return child__;
		}
	}

	return none;
}

auto has_child__2(Syntax_Node const *_Nonnull const syntax__, int__00 const type__) -> bool__00
{
	for (Syntax_Node const *_Nonnull const child__ : *(syntax__->children__))
	{
		if (cond(equal_op(child__->kind__, type__)))
		{
			return true__00;
		}
	}

	return false__00;
}

auto add__2(Syntax_Node const *_Nonnull const syntax__, Diagnostic const *_Nonnull const diagnostic__) -> void
{
	syntax__->node_diagnostics__->add__1(diagnostic__);
}

auto all_diagnostics__1(Syntax_Node const *_Nonnull const syntax__) -> system__collections__List<Diagnostic const *_Nonnull> *_Nonnull
{
	system__collections__List<Diagnostic const *_Nonnull> *_Nonnull diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	collect_syntax_diagnostics__2(syntax__, diagnostics__);
	return diagnostics__;
}

auto collect_syntax_diagnostics__2(Syntax_Node const *_Nonnull const syntax__, system__collections__List<Diagnostic const *_Nonnull> *_Nonnull const diagnostics__) -> void
{
	for (Diagnostic const *_Nonnull const diagnostic__ : *(syntax__->node_diagnostics__))
	{
		diagnostics__->add__1(diagnostic__);
	}

	for (Syntax_Node const *_Nonnull const child__ : *(syntax__->children__))
	{
		collect_syntax_diagnostics__2(child__, diagnostics__);
	}
}

auto members__1(Syntax_Node const *_Nonnull const syntax__) -> system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const members__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	for (Syntax_Node const *_Nonnull const child__ : *(syntax__->children__))
	{
		if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(child__->kind__, ConstructorDeclaration__)) || bool__00__arg(equal_op(child__->kind__, FieldDeclaration__)))) || bool__00__arg(equal_op(child__->kind__, MethodDeclaration__)))))
		{
			members__->add__1(child__);
		}
	}

	return members__;
}

auto parameters__1(Syntax_Node const *_Nonnull const syntax__) -> system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const parameters__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	for (Syntax_Node const *_Nonnull const child__ : *(syntax__->children__))
	{
		if (cond(bool__00__op(bool__00__arg(equal_op(child__->kind__, Parameter__)) || bool__00__arg(equal_op(child__->kind__, SelfParameter__)))))
		{
			parameters__->add__1(child__);
		}
	}

	return parameters__;
}

auto statements__1(Syntax_Node const *_Nonnull const syntax__) -> system__collections__List<Syntax_Node const *_Nonnull> const *_Nonnull
{
	system__collections__List<Syntax_Node const *_Nonnull> *_Nonnull const statements__ = new_system__collections__List<Syntax_Node const *_Nonnull>();
	for (Syntax_Node const *_Nonnull const child__ : *(syntax__->children__))
	{
		if (cond(bool__00__op(bool__00__arg(not_equal_op(child__->kind__, LeftBrace__)) && bool__00__arg(not_equal_op(child__->kind__, RightBrace__)))))
		{
			statements__->add__1(child__);
		}
	}

	return statements__;
}

auto access_modifier__1(Syntax_Node const *_Nonnull const syntax__) -> Syntax_Node const *_Nullable
{
	for (Syntax_Node const *_Nonnull const child__ : *(syntax__->children__))
	{
		if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(child__->kind__, PublicKeyword__)) || bool__00__arg(equal_op(child__->kind__, ProtectedKeyword__)))) || bool__00__arg(equal_op(child__->kind__, InternalKeyword__)))) || bool__00__arg(equal_op(child__->kind__, PrivateKeyword__)))))
		{
			return child__;
		}
	}

	return none;
}

Token_Stream *_Nonnull Token_Stream__0new__1(Token_Stream *_Nonnull self, Source_Text const *_Nonnull const source__)
{
	self->source__ = source__;
	self->position__ = int__00(0);
	self->diagnostics__ = new_system__collections__List<Diagnostic const *_Nonnull>();
	self->end_of_file__ = false__00;
	return self;
}

inline Token_Stream *_Nonnull new_Token_Stream(Source_Text const *_Nonnull const source__)
{
	return Token_Stream__0new__1(new Token_Stream(), source__);
}

auto next_token__1(Token_Stream *_Nonnull const tokens__) -> Syntax_Node const *_Nullable
{
	if (cond(uint__00__0op__greater_than_or_equal(tokens__->position__, source_byte_length__1(tokens__->source__))))
	{
		return end_of_file_token__1(tokens__);
	}

	uint__00 end__ = int__00__0op__negate(int__00(1));
	while (cond(uint__00__0op__less_than(tokens__->position__, source_byte_length__1(tokens__->source__))))
	{
		code_point__00 const curChar__ = tokens__->source__->text__.op__Element(tokens__->position__);
		if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(curChar__, code_point__00(' '))) || bool__00__arg(equal_op(curChar__, code_point__00('\t'))))) || bool__00__arg(equal_op(curChar__, code_point__00('\n'))))) || bool__00__arg(equal_op(curChar__, code_point__00('\r'))))))
		{
			tokens__->position__.op__add_assign(int__00(1));
			continue;
		}
		else if (cond(equal_op(curChar__, code_point__00('{'))))
		{
			return new_operator_token__2(tokens__, LeftBrace__);
		}
		else if (cond(equal_op(curChar__, code_point__00('}'))))
		{
			return new_operator_token__2(tokens__, RightBrace__);
		}
		else if (cond(equal_op(curChar__, code_point__00('('))))
		{
			return new_operator_token__2(tokens__, LeftParen__);
		}
		else if (cond(equal_op(curChar__, code_point__00(')'))))
		{
			return new_operator_token__2(tokens__, RightParen__);
		}
		else if (cond(equal_op(curChar__, code_point__00(';'))))
		{
			return new_operator_token__2(tokens__, Semicolon__);
		}
		else if (cond(equal_op(curChar__, code_point__00(','))))
		{
			return new_operator_token__2(tokens__, Comma__);
		}
		else if (cond(equal_op(curChar__, code_point__00('.'))))
		{
			return new_operator_token__2(tokens__, Dot__);
		}
		else if (cond(equal_op(curChar__, code_point__00(':'))))
		{
			return new_operator_token__2(tokens__, Colon__);
		}
		else if (cond(equal_op(curChar__, code_point__00('['))))
		{
			return new_operator_token__2(tokens__, LeftBracket__);
		}
		else if (cond(equal_op(curChar__, code_point__00(']'))))
		{
			return new_operator_token__2(tokens__, RightBracket__);
		}
		else if (cond(equal_op(curChar__, code_point__00('?'))))
		{
			return new_operator_token__2(tokens__, Question__);
		}
		else if (cond(equal_op(curChar__, code_point__00('|'))))
		{
			return new_operator_token__2(tokens__, Pipe__);
		}
		else if (cond(equal_op(curChar__, code_point__00('*'))))
		{
			return new_operator_token__2(tokens__, Asterisk__);
		}
		else if (cond(equal_op(curChar__, code_point__00('='))))
		{
			if (cond(bool__00__op(bool__00__arg(tokens__->position__.op__add(int__00(1))->op__less_than(source_byte_length__1(tokens__->source__))) && bool__00__arg(equal_op(tokens__->source__->text__.op__Element(tokens__->position__.op__add(int__00(1))), code_point__00('='))))))
			{
				return new_operator_token__3(tokens__, EqualsEquals__, int__00(2));
			}

			if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(tokens__->position__.op__add(int__00(2))->op__less_than(source_byte_length__1(tokens__->source__))) && bool__00__arg(equal_op(tokens__->source__->text__.op__Element(tokens__->position__.op__add(int__00(1))), code_point__00('/'))))) && bool__00__arg(equal_op(tokens__->source__->text__.op__Element(tokens__->position__.op__add(int__00(2))), code_point__00('='))))))
			{
				return new_operator_token__3(tokens__, EqualsSlashEquals__, int__00(3));
			}

			return new_operator_token__2(tokens__, Equals__);
		}
		else if (cond(equal_op(curChar__, code_point__00('+'))))
		{
			if (cond(bool__00__op(bool__00__arg(tokens__->position__.op__add(int__00(1))->op__less_than(source_byte_length__1(tokens__->source__))) && bool__00__arg(equal_op(tokens__->source__->text__.op__Element(tokens__->position__.op__add(int__00(1))), code_point__00('='))))))
			{
				return new_operator_token__3(tokens__, PlusEquals__, int__00(2));
			}

			return new_operator_token__2(tokens__, Plus__);
		}
		else if (cond(equal_op(curChar__, code_point__00('-'))))
		{
			if (cond(bool__00__op(bool__00__arg(tokens__->position__.op__add(int__00(1))->op__less_than(source_byte_length__1(tokens__->source__))) && bool__00__arg(equal_op(tokens__->source__->text__.op__Element(tokens__->position__.op__add(int__00(1))), code_point__00('>'))))))
			{
				return new_operator_token__3(tokens__, Arrow__, int__00(2));
			}

			if (cond(bool__00__op(bool__00__arg(tokens__->position__.op__add(int__00(1))->op__less_than(source_byte_length__1(tokens__->source__))) && bool__00__arg(equal_op(tokens__->source__->text__.op__Element(tokens__->position__.op__add(int__00(1))), code_point__00('='))))))
			{
				return new_operator_token__3(tokens__, MinusEquals__, int__00(2));
			}

			return new_operator_token__2(tokens__, Minus__);
		}
		else if (cond(equal_op(curChar__, code_point__00('/'))))
		{
			if (cond(bool__00__op(bool__00__arg(tokens__->position__.op__add(int__00(1))->op__less_than(source_byte_length__1(tokens__->source__))) && bool__00__arg(equal_op(tokens__->source__->text__.op__Element(tokens__->position__.op__add(int__00(1))), code_point__00('/'))))))
			{
				while (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(uint__00__0op__less_than(tokens__->position__, source_byte_length__1(tokens__->source__))) && bool__00__arg(not_equal_op(tokens__->source__->text__.op__Element(tokens__->position__), code_point__00('\r'))))) && bool__00__arg(not_equal_op(tokens__->source__->text__.op__Element(tokens__->position__), code_point__00('\n'))))))
				{
					tokens__->position__.op__add_assign(int__00(1));
				}

				continue;
			}

			if (cond(bool__00__op(bool__00__arg(tokens__->position__.op__add(int__00(1))->op__less_than(source_byte_length__1(tokens__->source__))) && bool__00__arg(equal_op(tokens__->source__->text__.op__Element(tokens__->position__.op__add(int__00(1))), code_point__00('*'))))))
			{
				tokens__->position__.op__add_assign(int__00(2));
				bool__00 lastCharStar__ = false__00;
				while (cond(bool__00__op(bool__00__arg(uint__00__0op__less_than(tokens__->position__, source_byte_length__1(tokens__->source__))) && bool__00__arg(bool__00__0op__not(bool__00__op(bool__00__arg(lastCharStar__) && bool__00__arg(equal_op(tokens__->source__->text__.op__Element(tokens__->position__), code_point__00('/')))))))))
				{
					lastCharStar__ = equal_op(tokens__->source__->text__.op__Element(tokens__->position__), code_point__00('*'));
					tokens__->position__.op__add_assign(int__00(1));
				}

				tokens__->position__.op__add_assign(int__00(1));
				continue;
			}

			return new_operator_token__2(tokens__, Slash__);
		}
		else if (cond(equal_op(curChar__, code_point__00('%'))))
		{
			return new_operator_token__2(tokens__, Percent__);
		}
		else if (cond(equal_op(curChar__, code_point__00('<'))))
		{
			if (cond(bool__00__op(bool__00__arg(tokens__->position__.op__add(int__00(1))->op__less_than(source_byte_length__1(tokens__->source__))) && bool__00__arg(equal_op(tokens__->source__->text__.op__Element(tokens__->position__.op__add(int__00(1))), code_point__00('='))))))
			{
				return new_operator_token__3(tokens__, LessThanEquals__, int__00(2));
			}

			return new_operator_token__2(tokens__, LessThan__);
		}
		else if (cond(equal_op(curChar__, code_point__00('>'))))
		{
			if (cond(bool__00__op(bool__00__arg(tokens__->position__.op__add(int__00(1))->op__less_than(source_byte_length__1(tokens__->source__))) && bool__00__arg(equal_op(tokens__->source__->text__.op__Element(tokens__->position__.op__add(int__00(1))), code_point__00('='))))))
			{
				return new_operator_token__3(tokens__, GreaterThanEquals__, int__00(2));
			}

			return new_operator_token__2(tokens__, GreaterThan__);
		}
		else if (cond(equal_op(curChar__, code_point__00('"'))))
		{
			end__ = tokens__->position__.op__add(int__00(1));
			bool__00 escaped__ = false__00;
			while (cond(bool__00__op(bool__00__arg(uint__00__0op__less_than(end__, source_byte_length__1(tokens__->source__))) && bool__00__arg(bool__00__op(bool__00__arg(not_equal_op(tokens__->source__->text__.op__Element(end__), code_point__00('"'))) || bool__00__arg(escaped__))))))
			{
				escaped__ = bool__00__op(bool__00__arg(equal_op(tokens__->source__->text__.op__Element(end__), code_point__00('\\'))) && bool__00__arg(bool__00__0op__not(escaped__)));
				end__.op__add_assign(int__00(1));
			}

			end__.op__add_assign(int__00(1));
			return new_token__3(tokens__, StringLiteral__, end__);
		}
		else if (cond(equal_op(curChar__, code_point__00('\''))))
		{
			end__ = tokens__->position__.op__add(int__00(1));
			bool__00 escaped__ = false__00;
			while (cond(bool__00__op(bool__00__arg(uint__00__0op__less_than(end__, source_byte_length__1(tokens__->source__))) && bool__00__arg(bool__00__op(bool__00__arg(not_equal_op(tokens__->source__->text__.op__Element(end__), code_point__00('\''))) || bool__00__arg(escaped__))))))
			{
				escaped__ = bool__00__op(bool__00__arg(equal_op(tokens__->source__->text__.op__Element(end__), code_point__00('\\'))) && bool__00__arg(bool__00__0op__not(escaped__)));
				end__.op__add_assign(int__00(1));
			}

			end__.op__add_assign(int__00(1));
			return new_token__3(tokens__, CodePointLiteral__, end__);
		}
		else
		{
			if (cond(is_identifier_char__1(curChar__)))
			{
				end__ = tokens__->position__.op__add(int__00(1));
				while (cond(is_identifier_char__1(tokens__->source__->text__.op__Element(end__))))
				{
					end__.op__add_assign(int__00(1));
				}

				return new_identifier_or_keyword_token__2(tokens__, end__);
			}

			if (cond(is_number_char__1(curChar__)))
			{
				end__ = tokens__->position__.op__add(int__00(1));
				while (cond(is_number_char__1(tokens__->source__->text__.op__Element(end__))))
				{
					end__.op__add_assign(int__00(1));
				}

				return new_token__3(tokens__, Number__, end__);
			}

			Text_Span const *_Nonnull diagnosticSpan__ = new_Text_Span(tokens__->position__, int__00(1));
			tokens__->diagnostics__->add__1(new_Diagnostic(CompilationError__, Lexing__, tokens__->source__, diagnosticSpan__, string__00("Invalid character `").op__add(curChar__)->op__add(string__00("`"))));
			tokens__->position__ = end__;
		}
	}

	return end_of_file_token__1(tokens__);
}

auto end_of_file_token__1(Token_Stream *_Nonnull const tokens__) -> Syntax_Node const *_Nullable
{
	if (cond(tokens__->end_of_file__))
	{
		return none;
	}

	tokens__->end_of_file__ = true__00;
	return new_token__3(tokens__, EndOfFileToken__, tokens__->position__);
}

auto new_identifier_or_keyword_token__2(Token_Stream *_Nonnull const tokens__, uint__00 const end__) -> Syntax_Node const *_Nonnull
{
	uint__00 const length__ = end__.op__subtract(tokens__->position__);
	string__00 const value__ = tokens__->source__->text__.Substring__2(tokens__->position__, length__);
	int__00 type__;
	if (cond(equal_op(value__, string__00("new"))))
	{
		type__ = NewKeyword__;
	}
	else if (cond(equal_op(value__, string__00("not"))))
	{
		type__ = NotOperator__;
	}
	else if (cond(equal_op(value__, string__00("null"))))
	{
		type__ = NullReservedWord__;
	}
	else if (cond(equal_op(value__, string__00("self"))))
	{
		type__ = SelfKeyword__;
	}
	else if (cond(equal_op(value__, string__00("true"))))
	{
		type__ = TrueKeyword__;
	}
	else if (cond(equal_op(value__, string__00("false"))))
	{
		type__ = FalseKeyword__;
	}
	else if (cond(equal_op(value__, string__00("mut"))))
	{
		type__ = MutableKeyword__;
	}
	else if (cond(equal_op(value__, string__00("code_point"))))
	{
		type__ = CodePoint__;
	}
	else if (cond(equal_op(value__, string__00("string"))))
	{
		type__ = String__;
	}
	else if (cond(equal_op(value__, string__00("int"))))
	{
		type__ = Int__;
	}
	else if (cond(equal_op(value__, string__00("bool"))))
	{
		type__ = Bool__;
	}
	else if (cond(equal_op(value__, string__00("void"))))
	{
		type__ = Void__;
	}
	else if (cond(equal_op(value__, string__00("uint"))))
	{
		type__ = UnsignedInt__;
	}
	else if (cond(equal_op(value__, string__00("var"))))
	{
		type__ = VarKeyword__;
	}
	else if (cond(equal_op(value__, string__00("and"))))
	{
		type__ = AndKeyword__;
	}
	else if (cond(equal_op(value__, string__00("or"))))
	{
		type__ = OrKeyword__;
	}
	else if (cond(equal_op(value__, string__00("return"))))
	{
		type__ = ReturnKeyword__;
	}
	else if (cond(equal_op(value__, string__00("loop"))))
	{
		type__ = LoopKeyword__;
	}
	else if (cond(equal_op(value__, string__00("while"))))
	{
		type__ = WhileKeyword__;
	}
	else if (cond(equal_op(value__, string__00("for"))))
	{
		type__ = ForKeyword__;
	}
	else if (cond(equal_op(value__, string__00("let"))))
	{
		type__ = LetKeyword__;
	}
	else if (cond(equal_op(value__, string__00("in"))))
	{
		type__ = InKeyword__;
	}
	else if (cond(equal_op(value__, string__00("do"))))
	{
		type__ = DoKeyword__;
	}
	else if (cond(equal_op(value__, string__00("if"))))
	{
		type__ = IfKeyword__;
	}
	else if (cond(equal_op(value__, string__00("else"))))
	{
		type__ = ElseKeyword__;
	}
	else if (cond(equal_op(value__, string__00("break"))))
	{
		type__ = BreakKeyword__;
	}
	else if (cond(equal_op(value__, string__00("continue"))))
	{
		type__ = ContinueKeyword__;
	}
	else if (cond(equal_op(value__, string__00("private"))))
	{
		type__ = PrivateKeyword__;
	}
	else if (cond(equal_op(value__, string__00("protected"))))
	{
		type__ = ProtectedKeyword__;
	}
	else if (cond(equal_op(value__, string__00("public"))))
	{
		type__ = PublicKeyword__;
	}
	else if (cond(equal_op(value__, string__00("internal"))))
	{
		type__ = InternalKeyword__;
	}
	else if (cond(equal_op(value__, string__00("class"))))
	{
		type__ = ClassKeyword__;
	}
	else if (cond(equal_op(value__, string__00("enum"))))
	{
		type__ = EnumKeyword__;
	}
	else if (cond(equal_op(value__, string__00("struct"))))
	{
		type__ = StructKeyword__;
	}
	else if (cond(equal_op(value__, string__00("none"))))
	{
		type__ = NoneKeyword__;
	}
	else
	{
		type__ = Identifier__;
		if (cond(bool__00__op(bool__00__arg(value__.ByteLength__0()->op__greater_than(int__00(1))) && bool__00__arg(equal_op(value__.op__Element(value__.ByteLength__0()->op__subtract(int__00(1))), code_point__00('_'))))))
		{
			Text_Span const *_Nonnull diagnosticSpan__ = new_Text_Span(tokens__->position__, end__.op__subtract(tokens__->position__));
			tokens__->diagnostics__->add__1(new_Diagnostic(CompilationError__, Lexing__, tokens__->source__, diagnosticSpan__, string__00("Identifiers ending with underscore are reserved `").op__add(value__)->op__add(string__00("`"))));
		}
	}

	return new_token__3(tokens__, type__, end__);
}

auto new_operator_token__2(Token_Stream *_Nonnull const tokens__, int__00 const type__) -> Syntax_Node const *_Nonnull
{
	return new_token__3(tokens__, type__, tokens__->position__.op__add(int__00(1)));
}

auto new_operator_token__3(Token_Stream *_Nonnull const tokens__, int__00 const type__, uint__00 const length__) -> Syntax_Node const *_Nonnull
{
	return new_token__3(tokens__, type__, tokens__->position__.op__add(length__));
}

auto new_token__3(Token_Stream *_Nonnull const tokens__, int__00 const type__, uint__00 const end__) -> Syntax_Node const *_Nonnull
{
	Syntax_Node *_Nonnull const token__ = new_Syntax_Node(type__, tokens__->source__, tokens__->position__, end__.op__subtract(tokens__->position__));
	for (Diagnostic const *_Nonnull const diagnostic__ : *(tokens__->diagnostics__))
	{
		add__2(token__, diagnostic__);
	}

	tokens__->diagnostics__->clear__0();
	tokens__->position__ = end__;
	return token__;
}

auto is_identifier_char__1(code_point__00 const c__) -> bool__00
{
	return bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(code_point__00__0op__greater_than_or_equal(c__, code_point__00('a'))) && bool__00__arg(code_point__00__0op__less_than_or_equal(c__, code_point__00('z'))))) || bool__00__arg(bool__00__op(bool__00__arg(code_point__00__0op__greater_than_or_equal(c__, code_point__00('A'))) && bool__00__arg(code_point__00__0op__less_than_or_equal(c__, code_point__00('Z'))))))) || bool__00__arg(equal_op(c__, code_point__00('_'))));
}

auto is_number_char__1(code_point__00 const c__) -> bool__00
{
	return bool__00__op(bool__00__arg(code_point__00__0op__greater_than_or_equal(c__, code_point__00('0'))) && bool__00__arg(code_point__00__0op__less_than_or_equal(c__, code_point__00('9'))));
}

Diagnostic *_Nonnull Diagnostic__0new__5(Diagnostic *_Nonnull self, int__00 const level__, int__00 const phase__, Source_Text const *_Nonnull const source__, Text_Span const *_Nonnull const span__, string__00 const message__)
{
	self->level__ = level__;
	self->phase__ = phase__;
	self->source__ = source__;
	self->span__ = span__;
	self->position__ = position_of_start__2(source__, span__);
	self->message__ = message__;
	return self;
}

inline Diagnostic *_Nonnull new_Diagnostic(int__00 const level__, int__00 const phase__, Source_Text const *_Nonnull const source__, Text_Span const *_Nonnull const span__, string__00 const message__)
{
	return Diagnostic__0new__5(new Diagnostic(), level__, phase__, source__, span__, message__);
}

Emitter *_Nonnull Emitter__0new__2(Emitter *_Nonnull self, Package const *_Nonnull const package__, system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const resources__)
{
	self->package__ = package__;
	self->resources__ = resources__;
	return self;
}

inline Emitter *_Nonnull new_Emitter(Package const *_Nonnull const package__, system__collections__List<Source_Text const *_Nonnull> const *_Nonnull const resources__)
{
	return Emitter__0new__2(new Emitter(), package__, resources__);
}

auto emit__1(Emitter *_Nonnull const emitter__) -> string__00
{
	emitter__->type_declarations__ = new_Source_File_Builder();
	emitter__->function_declarations__ = new_Source_File_Builder();
	emitter__->class_declarations__ = new_Source_File_Builder();
	emitter__->global_definitions__ = new_Source_File_Builder();
	emitter__->definitions__ = new_Source_File_Builder();
	emitter__->main_function_return_type__ = string__00("");
	emitter__->main_function_accepts_console__ = false__00;
	emitter__->main_function_accepts_args__ = false__00;
	emit_preamble__1(emitter__);
	for (Compilation_Unit const *_Nonnull const compilation_unit__ : *(emitter__->package__->compilation_units__))
	{
		emit_compilation_unit__2(emitter__, compilation_unit__);
	}

	emit_entry_point_adapter__1(emitter__);
	int__00 const total_size__ = byte_length__1(emitter__->type_declarations__)->op__add(byte_length__1(emitter__->function_declarations__))->op__add(byte_length__1(emitter__->class_declarations__))->op__add(byte_length__1(emitter__->global_definitions__))->op__add(byte_length__1(emitter__->definitions__));
	system__text__String_Builder *_Nonnull const cpp_code__ = new_system__text__String_Builder();
	cpp_code__->Append__1(to_string__1(emitter__->type_declarations__));
	cpp_code__->Append__1(to_string__1(emitter__->function_declarations__));
	cpp_code__->Append__1(to_string__1(emitter__->class_declarations__));
	cpp_code__->Append__1(to_string__1(emitter__->global_definitions__));
	cpp_code__->Append__1(to_string__1(emitter__->definitions__));
	return cpp_code__->ToString__0();
}

auto mangle_name__1(Type const *_Nonnull const type__) -> string__00
{
	system__text__String_Builder *_Nonnull const builder__ = new_system__text__String_Builder();
	bool__00 first_segment__ = true__00;
	for (string__00 const segment__ : *(type__->name__->segments__))
	{
		if (cond(first_segment__))
		{
			first_segment__ = false__00;
		}
		else
		{
			builder__->Append__1(string__00("__"));
		}

		if (cond(bool__00__0op__not(contains_multi_underscore_runs__1(segment__))))
		{
			builder__->Append__1(segment__);
		}
		else
		{
			append_fixing_underscores__2(builder__, segment__);
		}
	}

	builder__->Append__1(string__00("__"));
	builder__->Append__1(type__->type_parameters__->op__magnitude());
	return builder__->ToString__0();
}

auto mangle_function_name__2(string__00 const name__, int__00 const parameter_count__) -> string__00
{
	system__text__String_Builder *_Nonnull const builder__ = new_system__text__String_Builder();
	if (cond(bool__00__0op__not(contains_multi_underscore_runs__1(name__))))
	{
		builder__->Append__1(name__);
	}
	else
	{
		append_fixing_underscores__2(builder__, name__);
	}

	builder__->Append__1(string__00("__"));
	builder__->Append__1(parameter_count__);
	return builder__->ToString__0();
}

auto mangle_field_name__1(string__00 const name__) -> string__00
{
	if (cond(bool__00__0op__not(contains_multi_underscore_runs__1(name__))))
	{
		return name__.op__add(string__00("__"));
	}
	else
	{
		system__text__String_Builder *_Nonnull const builder__ = new_system__text__String_Builder();
		append_fixing_underscores__2(builder__, name__);
		builder__->Append__1(string__00("__"));
		return builder__->ToString__0();
	}
}

auto contains_multi_underscore_runs__1(string__00 const value__) -> bool__00
{
	int__00 i__ = int__00(0);
	bool__00 last_char_underscore__ = false__00;
	while (cond(int__00__0op__less_than(i__, value__.ByteLength__0())))
	{
		if (cond(equal_op(value__.op__Element(i__), code_point__00('_'))))
		{
			if (cond(last_char_underscore__))
			{
				return true__00;
			}

			last_char_underscore__ = true__00;
		}
		else
		{
			last_char_underscore__ = false__00;
		}

		i__.op__add_assign(int__00(1));
	}

	return false__00;
}

auto append_fixing_underscores__2(system__text__String_Builder *_Nonnull const builder__, string__00 const value__) -> void
{
	int__00 underscores__ = int__00(0);
	int__00 i__ = int__00(0);
	while (cond(int__00__0op__less_than(i__, value__.ByteLength__0())))
	{
		if (cond(equal_op(value__.op__Element(i__), code_point__00('_'))))
		{
			underscores__.op__add_assign(int__00(1));
		}
		else if (cond(int__00__0op__greater_than(underscores__, int__00(0))))
		{
			if (cond(int__00__0op__greater_than_or_equal(underscores__, int__00(2))))
			{
				builder__->Append__1(string__00("_"));
			}

			underscores__ = int__00(0);
		}

		builder__->Append__1(new_string__00(value__.op__Element(i__), int__00(1)));
		i__.op__add_assign(int__00(1));
	}
}

auto convert_primitive_type_name__1(Type const *_Nonnull const type__) -> string__00
{
	string__00 const name__ = unqualified_name__1(type__->name__);
	assert__2(type__->is_primitive__, name__);
	if (cond(equal_op(name__, string__00("void"))))
	{
		return string__00("void");
	}
	else
	{
		return name__.op__add(string__00("__00"));
	}
}

auto convert_type_name__1(Semantic_Node const *_Nonnull const type_node__) -> system__text__String_Builder *_Nonnull
{
	assert__2(not_equal_op(type_node__->referenced_type__, none), get_text__1(type_node__));
	return convert_type_name__1(type_node__->referenced_type__);
}

auto convert_type_name__1(Type const *_Nonnull const type__) -> system__text__String_Builder *_Nonnull
{
	system__text__String_Builder *_Nonnull const cpp_type__ = new_system__text__String_Builder();
	if (cond(type__->is_primitive__))
	{
		cpp_type__->Append__1(convert_primitive_type_name__1(type__));
	}
	else
	{
		cpp_type__->Append__1(mangle_name__1(type__));
	}

	if (cond(type__->type_parameters__->op__magnitude()->op__greater_than(int__00(0))))
	{
		cpp_type__->Append__1(string__00("<"));
		bool__00 first__ = true__00;
		for (Type const *_Nonnull const type_parameter__ : *(type__->type_parameters__))
		{
			if (cond(first__))
			{
				first__ = false__00;
			}
			else
			{
				cpp_type__->Append__1(string__00(", "));
			}

			cpp_type__->Append__1(convert_type__3(true__00, type_parameter__, false__00));
		}

		cpp_type__->Append__1(string__00(">"));
	}

	return cpp_type__;
}

auto convert_reference_type__3(bool__00 const mutable_binding__, Type const *_Nonnull type__, bool__00 const nullable__) -> string__00
{
	system__text__String_Builder *_Nonnull const cpp_type__ = convert_type_name__1(type__);
	if (cond(bool__00__0op__not(type__->is_mutable__)))
	{
		cpp_type__->Append__1(string__00(" const"));
	}

	cpp_type__->Append__1(string__00(" *"));
	if (cond(nullable__))
	{
		cpp_type__->Append__1(string__00("_Nullable"));
	}
	else
	{
		cpp_type__->Append__1(string__00("_Nonnull"));
	}

	if (cond(bool__00__0op__not(mutable_binding__)))
	{
		cpp_type__->Append__1(string__00(" const"));
	}

	return cpp_type__->ToString__0();
}

auto convert_type__3(bool__00 const mutable_binding__, Type const *_Nonnull type__, bool__00 const optional__) -> string__00
{
	assert__2(not_equal_op(type__, none), string__00(""));
	if (cond(bool__00__op(bool__00__arg(type__->is_primitive__) && bool__00__arg(equal_op(unqualified_name__1(type__->name__), string__00("optional"))))))
	{
		Type const *_Nonnull const optional_type__ = type__->type_parameters__->op__Element(int__00(0));
		if (cond(optional_type__->is_value_type__))
		{
			system__text__String_Builder *_Nonnull const cpp_type__ = new_system__text__String_Builder(string__00("p_optional<"));
			cpp_type__->Append__1(convert_type__3(true__00, optional_type__, true__00));
			cpp_type__->Append__1(string__00(">"));
			if (cond(bool__00__op(bool__00__arg(bool__00__0op__not(mutable_binding__)) && bool__00__arg(bool__00__0op__not(type__->is_mutable__)))))
			{
				cpp_type__->Append__1(string__00(" const"));
			}

			return cpp_type__->ToString__0();
		}
		else
		{
			return convert_type__3(mutable_binding__, optional_type__, true__00);
		}
	}
	else
	{
		if (cond(type__->is_value_type__))
		{
			system__text__String_Builder *_Nonnull const cpp_type__ = convert_type_name__1(type__);
			if (cond(bool__00__op(bool__00__arg(bool__00__0op__not(mutable_binding__)) && bool__00__arg(bool__00__0op__not(type__->is_mutable__)))))
			{
				cpp_type__->Append__1(string__00(" const"));
			}

			return cpp_type__->ToString__0();
		}
		else
		{
			return convert_reference_type__3(mutable_binding__, type__, optional__);
		}
	}
}

auto convert_type__2(bool__00 const mutable_binding__, Semantic_Node const *_Nonnull const type_node__) -> string__00
{
	assert__2(not_equal_op(type_node__->referenced_type__, none), get_text__1(type_node__));
	return convert_type__3(mutable_binding__, type_node__->referenced_type__, false__00);
}

auto convert_parameter_list__4(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const parameters__, string__00 const self_type__, bool__00 const is_main_function__) -> string__00
{
	assert__2(equal_op(parameters__->kind__, ParameterList__), string__00("parameters.kind=").op__add(parameters__->kind__));
	system__text__String_Builder *_Nonnull const builder__ = new_system__text__String_Builder();
	builder__->Append__1(string__00("("));
	if (cond(self_type__.ByteLength__0()->op__greater_than(int__00(0))))
	{
		builder__->Append__1(self_type__);
		builder__->Append__1(string__00(" self"));
	}

	bool__00 first_parameter__ = equal_op(self_type__.ByteLength__0(), int__00(0));
	for (Semantic_Node const *_Nonnull const parameter__ : *(children_of_kind__2(parameters__, Parameter__)))
	{
		if (cond(bool__00__0op__not(first_parameter__)))
		{
			builder__->Append__1(string__00(", "));
		}
		else
		{
			first_parameter__ = false__00;
		}

		bool__00 const mutable_binding__ = node_has_child__2(parameter__, VarKeyword__);
		Semantic_Node const *_Nonnull const type_node__ = parameter__->children__->op__Element(parameter__->children__->op__magnitude()->op__subtract(int__00(1)));
		builder__->Append__1(convert_type__2(mutable_binding__, type_node__));
		builder__->Append__1(string__00(" "));
		builder__->Append__1(mangle_field_name__1(get_text__1(first_child__2(parameter__, Identifier__))));
		if (cond(is_main_function__))
		{
			string__00 type_string__;
			if (cond(equal_op(type_node__->kind__, MutableType__)))
			{
				type_string__ = get_text__1(type_node__->children__->op__Element(int__00(0)));
			}
			else
			{
				type_string__ = get_text__1(type_node__);
			}

			if (cond(equal_op(type_string__, string__00("system.console.Console"))))
			{
				emitter__->main_function_accepts_console__ = true__00;
			}

			if (cond(equal_op(type_string__, string__00("system.console.Arguments"))))
			{
				emitter__->main_function_accepts_args__ = true__00;
			}
		}
	}

	builder__->Append__1(string__00(")"));
	return builder__->ToString__0();
}

auto convert_method_parameter_list__3(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const parameters__, string__00 const self_type__) -> string__00
{
	return convert_parameter_list__4(emitter__, parameters__, self_type__, false__00);
}

auto convert_parameter_list__3(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const parameters__, bool__00 const is_main_function__) -> string__00
{
	return convert_parameter_list__4(emitter__, parameters__, string__00(""), is_main_function__);
}

auto convert_parameter_list__2(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const parameters__) -> string__00
{
	return convert_parameter_list__4(emitter__, parameters__, string__00(""), false__00);
}

auto convert_expression__2(Semantic_Node const *_Nonnull const syntax__, Source_File_Builder *_Nonnull const builder__) -> void
{
	if (cond(equal_op(syntax__->kind__, NewExpression__)))
	{
		string__00 constructor_name__ = string__00("");
		Semantic_Node const *_Nonnull type_node__ = syntax__->children__->op__Element(int__00(0));
		if (cond(equal_op(type_node__->kind__, QualifiedName__)))
		{
			Semantic_Node const *_Nonnull const name_node__ = type_node__->children__->op__Element(int__00(1));
			if (cond(bool__00__op(bool__00__arg(equal_op(name_node__->kind__, IdentifierName__)) && bool__00__arg(equal_op(name_node__->referenced_type__, none)))))
			{
				constructor_name__ = string__00("__").op__add(get_text__1(name_node__));
				type_node__ = type_node__->children__->op__Element(int__00(0));
			}
		}

		Type const *_Nonnull const type__ = type_node__->referenced_type__;
		assert__2(not_equal_op(type__, none), get_text__1(type_node__));
		write__2(builder__, string__00("new_"));
		write__2(builder__, convert_type_name__1(type__)->ToString__0());
		write__2(builder__, constructor_name__);
		Semantic_Node const *_Nonnull const argumentList__ = syntax__->children__->op__Element(int__00(1));
		convert_expression__2(argumentList__, builder__);
	}
	else if (cond(equal_op(syntax__->kind__, ArgumentList__)))
	{
		write__2(builder__, string__00("("));
		bool__00 first_expression__ = true__00;
		for (Semantic_Node const *_Nonnull const arg__ : *(syntax__->children__))
		{
			if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(not_equal_op(arg__->kind__, LeftParen__)) && bool__00__arg(not_equal_op(arg__->kind__, RightParen__)))) && bool__00__arg(not_equal_op(arg__->kind__, Comma__)))))
			{
				if (cond(first_expression__))
				{
					first_expression__ = false__00;
				}
				else
				{
					write__2(builder__, string__00(", "));
				}

				convert_expression__2(arg__, builder__);
			}
		}

		write__2(builder__, string__00(")"));
	}
	else if (cond(equal_op(syntax__->kind__, NotExpression__)))
	{
		write__2(builder__, string__00("bool__00__0op__not("));
		convert_expression__2(syntax__->children__->op__Element(int__00(1)), builder__);
		write__2(builder__, string__00(")"));
	}
	else if (cond(equal_op(syntax__->kind__, MagnitudeExpression__)))
	{
		convert_expression__2(syntax__->children__->op__Element(int__00(1)), builder__);
		convert_member_access__2(syntax__->children__->op__Element(int__00(1)), builder__);
		write__2(builder__, string__00("op__magnitude()"));
	}
	else if (cond(equal_op(syntax__->kind__, ParenthesizedExpression__)))
	{
		convert_expression__2(syntax__->children__->op__Element(int__00(1)), builder__);
	}
	else if (cond(equal_op(syntax__->kind__, NegateExpression__)))
	{
		write__2(builder__, string__00("int__00__0op__negate("));
		convert_expression__2(syntax__->children__->op__Element(int__00(1)), builder__);
		write__2(builder__, string__00(")"));
	}
	else if (cond(equal_op(syntax__->kind__, NoneLiteralExpression__)))
	{
		write__2(builder__, string__00("none"));
	}
	else if (cond(equal_op(syntax__->kind__, SelfExpression__)))
	{
		write__2(builder__, string__00("self"));
	}
	else if (cond(equal_op(syntax__->kind__, NumericLiteralExpression__)))
	{
		write__2(builder__, string__00("int__00(").op__add(get_text__1(syntax__))->op__add(string__00(")")));
	}
	else if (cond(bool__00__op(bool__00__arg(equal_op(syntax__->kind__, TrueLiteralExpression__)) || bool__00__arg(equal_op(syntax__->kind__, FalseLiteralExpression__)))))
	{
		write__2(builder__, get_text__1(syntax__)->op__add(string__00("__00")));
	}
	else if (cond(equal_op(syntax__->kind__, CodePointLiteralExpression__)))
	{
		write__2(builder__, string__00("code_point__00(").op__add(get_text__1(syntax__))->op__add(string__00(")")));
	}
	else if (cond(equal_op(syntax__->kind__, IdentifierName__)))
	{
		write__2(builder__, mangle_field_name__1(get_text__1(syntax__)));
	}
	else if (cond(equal_op(syntax__->kind__, StringLiteralExpression__)))
	{
		write__2(builder__, string__00("string__00(").op__add(get_text__1(syntax__))->op__add(string__00(")")));
	}
	else if (cond(equal_op(syntax__->kind__, AssignmentExpression__)))
	{
		int__00 const operator__ = syntax__->children__->op__Element(int__00(1))->kind__;
		if (cond(equal_op(operator__, Equals__)))
		{
			convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
			write__2(builder__, string__00(" "));
			write__2(builder__, get_text__1(syntax__->children__->op__Element(int__00(1))));
			write__2(builder__, string__00(" "));
			convert_expression__2(syntax__->children__->op__Element(int__00(2)), builder__);
		}
		else
		{
			convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
			convert_member_access__2(syntax__->children__->op__Element(int__00(0)), builder__);
			write__2(builder__, string__00("op__"));
			if (cond(equal_op(operator__, PlusEquals__)))
			{
				write__2(builder__, string__00("add_assign"));
			}
			else if (cond(equal_op(operator__, MinusEquals__)))
			{
				write__2(builder__, string__00("subtract_assign"));
			}
			else
			{
				error__2(builder__, string__00("Unsupported assignment operator ").op__add(operator__));
			}

			write__2(builder__, string__00("("));
			convert_expression__2(syntax__->children__->op__Element(int__00(2)), builder__);
			write__2(builder__, string__00(")"));
		}
	}
	else if (cond(equal_op(syntax__->kind__, EqualExpression__)))
	{
		write__2(builder__, string__00("equal_op("));
		convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
		write__2(builder__, string__00(", "));
		convert_expression__2(syntax__->children__->op__Element(int__00(2)), builder__);
		write__2(builder__, string__00(")"));
	}
	else if (cond(equal_op(syntax__->kind__, NotEqualExpression__)))
	{
		write__2(builder__, string__00("not_equal_op("));
		convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
		write__2(builder__, string__00(", "));
		convert_expression__2(syntax__->children__->op__Element(int__00(2)), builder__);
		write__2(builder__, string__00(")"));
	}
	else if (cond(equal_op(syntax__->kind__, ComparisonExpression__)))
	{
		int__00 const operator__ = syntax__->children__->op__Element(int__00(1))->kind__;
		Type const *_Nonnull const type__ = syntax__->children__->op__Element(int__00(0))->of_type__;
		if (cond(not_equal_op(type__, none)))
		{
			write__2(builder__, convert_primitive_type_name__1(type__));
			if (cond(equal_op(operator__, LessThan__)))
			{
				write__2(builder__, string__00("__0op__less_than"));
			}
			else if (cond(equal_op(operator__, LessThanEquals__)))
			{
				write__2(builder__, string__00("__0op__less_than_or_equal"));
			}
			else if (cond(equal_op(operator__, GreaterThan__)))
			{
				write__2(builder__, string__00("__0op__greater_than"));
			}
			else if (cond(equal_op(operator__, GreaterThanEquals__)))
			{
				write__2(builder__, string__00("__0op__greater_than_or_equal"));
			}
			else
			{
				error__2(builder__, string__00("Unsupported comparison operator ").op__add(operator__));
			}

			write__2(builder__, string__00("("));
			convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
			write__2(builder__, string__00(", "));
			convert_expression__2(syntax__->children__->op__Element(int__00(2)), builder__);
			write__2(builder__, string__00(")"));
		}
		else
		{
			convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
			convert_member_access__2(syntax__->children__->op__Element(int__00(0)), builder__);
			write__2(builder__, string__00("op__"));
			if (cond(equal_op(operator__, LessThan__)))
			{
				write__2(builder__, string__00("less_than"));
			}
			else if (cond(equal_op(operator__, LessThanEquals__)))
			{
				write__2(builder__, string__00("less_than_or_equal"));
			}
			else if (cond(equal_op(operator__, GreaterThan__)))
			{
				write__2(builder__, string__00("greater_than"));
			}
			else if (cond(equal_op(operator__, GreaterThanEquals__)))
			{
				write__2(builder__, string__00("greater_than_or_equal"));
			}
			else
			{
				error__2(builder__, string__00("Unsupported comparison operator ").op__add(operator__));
			}

			write__2(builder__, string__00("("));
			convert_expression__2(syntax__->children__->op__Element(int__00(2)), builder__);
			write__2(builder__, string__00(")"));
		}
	}
	else if (cond(equal_op(syntax__->kind__, AddExpression__)))
	{
		convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
		convert_member_access__2(syntax__->children__->op__Element(int__00(0)), builder__);
		write__2(builder__, string__00("op__add("));
		convert_expression__2(syntax__->children__->op__Element(int__00(2)), builder__);
		write__2(builder__, string__00(")"));
	}
	else if (cond(equal_op(syntax__->kind__, SubtractExpression__)))
	{
		convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
		convert_member_access__2(syntax__->children__->op__Element(int__00(0)), builder__);
		write__2(builder__, string__00("op__subtract("));
		convert_expression__2(syntax__->children__->op__Element(int__00(2)), builder__);
		write__2(builder__, string__00(")"));
	}
	else if (cond(equal_op(syntax__->kind__, MultiplyExpression__)))
	{
		convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
		convert_member_access__2(syntax__->children__->op__Element(int__00(0)), builder__);
		write__2(builder__, string__00("op__multiply("));
		convert_expression__2(syntax__->children__->op__Element(int__00(2)), builder__);
		write__2(builder__, string__00(")"));
	}
	else if (cond(equal_op(syntax__->kind__, DivideExpression__)))
	{
		convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
		convert_member_access__2(syntax__->children__->op__Element(int__00(0)), builder__);
		write__2(builder__, string__00("op__divide("));
		convert_expression__2(syntax__->children__->op__Element(int__00(2)), builder__);
		write__2(builder__, string__00(")"));
	}
	else if (cond(equal_op(syntax__->kind__, RemainderExpression__)))
	{
		convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
		convert_member_access__2(syntax__->children__->op__Element(int__00(0)), builder__);
		write__2(builder__, string__00("op__remainder("));
		convert_expression__2(syntax__->children__->op__Element(int__00(2)), builder__);
		write__2(builder__, string__00(")"));
	}
	else if (cond(equal_op(syntax__->kind__, OrExpression__)))
	{
		write__2(builder__, string__00("bool__00__op(bool__00__arg("));
		convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
		write__2(builder__, string__00(") || bool__00__arg("));
		convert_expression__2(syntax__->children__->op__Element(int__00(2)), builder__);
		write__2(builder__, string__00("))"));
	}
	else if (cond(equal_op(syntax__->kind__, AndExpression__)))
	{
		write__2(builder__, string__00("bool__00__op(bool__00__arg("));
		convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
		write__2(builder__, string__00(") && bool__00__arg("));
		convert_expression__2(syntax__->children__->op__Element(int__00(2)), builder__);
		write__2(builder__, string__00("))"));
	}
	else if (cond(equal_op(syntax__->kind__, InvocationExpression__)))
	{
		convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
		Semantic_Node const *_Nonnull const parameters_node__ = syntax__->children__->op__Element(int__00(1));
		write__2(builder__, node_argument_count__1(parameters_node__));
		convert_expression__2(parameters_node__, builder__);
	}
	else if (cond(equal_op(syntax__->kind__, MemberAccessExpression__)))
	{
		convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
		convert_member_access__2(syntax__->children__->op__Element(int__00(0)), builder__);
		convert_expression__2(syntax__->children__->op__Element(int__00(1)), builder__);
	}
	else if (cond(equal_op(syntax__->kind__, ElementAccessExpression__)))
	{
		convert_expression__2(syntax__->children__->op__Element(int__00(0)), builder__);
		convert_member_access__2(syntax__->children__->op__Element(int__00(0)), builder__);
		write__2(builder__, string__00("op__Element("));
		convert_expression__2(syntax__->children__->op__Element(int__00(2)), builder__);
		write__2(builder__, string__00(")"));
	}
	else
	{
		error__2(builder__, string__00("Could not convert expression of type ").op__add(syntax__->kind__));
	}
}

auto convert_member_access__2(Semantic_Node const *_Nonnull const lhs__, Source_File_Builder *_Nonnull const builder__) -> void
{
	Type const *_Nullable const type__ = lhs__->of_type__;
	if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(not_equal_op(type__, none)) && bool__00__arg(type__->is_value_type__))) && bool__00__arg(bool__00__0op__not(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(type__->is_primitive__) && bool__00__arg(equal_op(unqualified_name__1(type__->name__), string__00("optional"))))) && bool__00__arg(bool__00__0op__not(type__->type_parameters__->op__Element(int__00(0))->is_value_type__))))))))
	{
		write__2(builder__, string__00("."));
	}
	else
	{
		write__2(builder__, string__00("->"));
	}
}

auto emit_statement__2(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const statement__) -> void
{
	statement_separator_line__1(emitter__->definitions__);
	if (cond(equal_op(statement__->kind__, ReturnStatement__)))
	{
		if (cond(equal_op(statement__->children__->op__magnitude(), int__00(2))))
		{
			write_line__2(emitter__->definitions__, string__00("return;"));
		}
		else
		{
			begin_line__2(emitter__->definitions__, string__00("return "));
			convert_expression__2(statement__->children__->op__Element(int__00(1)), emitter__->definitions__);
			end_line__2(emitter__->definitions__, string__00(";"));
		}
	}
	else if (cond(equal_op(statement__->kind__, LoopStatement__)))
	{
		write_line__2(emitter__->definitions__, string__00("for (;;)"));
		emit_statement__2(emitter__, statement__->children__->op__Element(int__00(1)));
	}
	else if (cond(equal_op(statement__->kind__, Block__)))
	{
		begin_block__1(emitter__->definitions__);
		for (Semantic_Node const *_Nonnull const block_statement__ : *(node_statements__1(statement__)))
		{
			emit_statement__2(emitter__, block_statement__);
		}

		end_block__1(emitter__->definitions__);
	}
	else if (cond(equal_op(statement__->kind__, WhileStatement__)))
	{
		begin_line__2(emitter__->definitions__, string__00("while (cond("));
		convert_expression__2(statement__->children__->op__Element(int__00(1)), emitter__->definitions__);
		end_line__2(emitter__->definitions__, string__00("))"));
		emit_statement__2(emitter__, statement__->children__->op__Element(int__00(2)));
	}
	else if (cond(equal_op(statement__->kind__, ForStatement__)))
	{
		begin_line__2(emitter__->definitions__, string__00("for ("));
		Semantic_Node const *_Nonnull const variable_declaration__ = first_child__2(statement__, VariableDeclaration__);
		bool__00 const mutable_binding__ = node_has_child__2(variable_declaration__, VarKeyword__);
		string__00 const name__ = get_text__1(first_child__2(variable_declaration__, Identifier__));
		Semantic_Node const *_Nonnull const type__ = variable_declaration__->children__->op__Element(int__00(2));
		write__2(emitter__->definitions__, convert_type__2(mutable_binding__, type__)->op__add(string__00(" "))->op__add(mangle_field_name__1(name__)));
		write__2(emitter__->definitions__, string__00(" : *("));
		convert_expression__2(statement__->children__->op__Element(int__00(3)), emitter__->definitions__);
		end_line__2(emitter__->definitions__, string__00("))"));
		emit_statement__2(emitter__, statement__->children__->op__Element(int__00(4)));
	}
	else if (cond(equal_op(statement__->kind__, DoWhileStatement__)))
	{
		write_line__2(emitter__->definitions__, string__00("do"));
		emit_statement__2(emitter__, statement__->children__->op__Element(int__00(1)));
		begin_line__2(emitter__->definitions__, string__00("while (cond("));
		convert_expression__2(statement__->children__->op__Element(int__00(3)), emitter__->definitions__);
		end_line__2(emitter__->definitions__, string__00("));"));
	}
	else if (cond(equal_op(statement__->kind__, IfStatement__)))
	{
		Semantic_Node const *_Nullable if_statement__ = statement__;
		begin_line__2(emitter__->definitions__, string__00(""));
		for (;;)
		{
			write__2(emitter__->definitions__, string__00("if (cond("));
			convert_expression__2(if_statement__->children__->op__Element(int__00(1)), emitter__->definitions__);
			end_line__2(emitter__->definitions__, string__00("))"));
			emit_statement__2(emitter__, if_statement__->children__->op__Element(int__00(2)));
			Semantic_Node const *_Nullable const elseClause__ = first_child__2(if_statement__, ElseClause__);
			if (cond(not_equal_op(elseClause__, none)))
			{
				if_statement__ = first_child__2(elseClause__, IfStatement__);
				if (cond(not_equal_op(if_statement__, none)))
				{
					begin_line__2(emitter__->definitions__, string__00("else "));
				}
				else
				{
					write_line__2(emitter__->definitions__, string__00("else"));
					emit_statement__2(emitter__, elseClause__->children__->op__Element(int__00(1)));
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	else if (cond(equal_op(statement__->kind__, BreakStatement__)))
	{
		write_line__2(emitter__->definitions__, string__00("break;"));
	}
	else if (cond(equal_op(statement__->kind__, ContinueStatement__)))
	{
		write_line__2(emitter__->definitions__, string__00("continue;"));
	}
	else if (cond(equal_op(statement__->kind__, LocalDeclarationStatement__)))
	{
		Semantic_Node const *_Nonnull const variable_declaration__ = first_child__2(statement__, VariableDeclaration__);
		string__00 const variable_name__ = get_text__1(first_child__2(variable_declaration__, Identifier__));
		Semantic_Node const *_Nonnull const variable_type__ = variable_declaration__->children__->op__Element(int__00(2));
		bool__00 const mutable_binding__ = node_has_child__2(variable_declaration__, VarKeyword__);
		begin_line__2(emitter__->definitions__, convert_type__2(mutable_binding__, variable_type__));
		write__2(emitter__->definitions__, string__00(" ").op__add(mangle_field_name__1(variable_name__)));
		if (cond(variable_declaration__->children__->op__magnitude()->op__greater_than(int__00(3))))
		{
			write__2(emitter__->definitions__, string__00(" = "));
			convert_expression__2(variable_declaration__->children__->op__Element(int__00(3)), emitter__->definitions__);
		}

		end_line__2(emitter__->definitions__, string__00(";"));
	}
	else if (cond(equal_op(statement__->kind__, ExpressionStatement__)))
	{
		begin_line__2(emitter__->definitions__, string__00(""));
		convert_expression__2(statement__->children__->op__Element(int__00(0)), emitter__->definitions__);
		end_line__2(emitter__->definitions__, string__00(";"));
	}
	else
	{
		NOT_IMPLEMENTED__1(string__00("statement.kind=").op__add(statement__->kind__));
	}
}

auto emit_method_body__3(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const block__, bool__00 const is_associated_function__) -> void
{
	begin_block__1(emitter__->definitions__);
	if (cond(bool__00__0op__not(is_associated_function__)))
	{
		write_line__2(emitter__->definitions__, string__00("auto self = this;"));
	}

	for (Semantic_Node const *_Nonnull const statement__ : *(node_statements__1(block__)))
	{
		emit_statement__2(emitter__, statement__);
	}

	end_block__1(emitter__->definitions__);
}

auto emit_constructor_body__4(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const block__, string__00 const self_type__, bool__00 const is_value_type__) -> void
{
	begin_block__1(emitter__->definitions__);
	if (cond(is_value_type__))
	{
		write_line__2(emitter__->definitions__, self_type__.op__add(string__00(" self;")));
	}

	for (Semantic_Node const *_Nonnull const statement__ : *(node_statements__1(block__)))
	{
		emit_statement__2(emitter__, statement__);
	}

	write_line__2(emitter__->definitions__, string__00("return self;"));
	end_block__1(emitter__->definitions__);
}

auto emit_member_declaration__4(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const member__, string__00 const class_name__, bool__00 const is_value_type__) -> void
{
	if (cond(equal_op(member__->kind__, ConstructorDeclaration__)))
	{
		Semantic_Node const *_Nonnull const parameters_node__ = first_child__2(member__, ParameterList__);
		string__00 new_function_name__ = string__00("new_").op__add(class_name__);
		string__00 constructor_full_name__ = class_name__.op__add(string__00("__0new__"));
		Semantic_Node const *_Nullable const constructor_name_node__ = first_child__2(member__, Identifier__);
		if (cond(not_equal_op(constructor_name_node__, none)))
		{
			string__00 const constructor_name__ = get_text__1(constructor_name_node__);
			new_function_name__ = new_function_name__.op__add(string__00("__"))->op__add(constructor_name__);
			constructor_full_name__ = constructor_full_name__.op__add(constructor_name__)->op__add(string__00("__"));
		}

		constructor_full_name__ = constructor_full_name__.op__add(parameters_node__->children__->op__magnitude());
		string__00 return_type__ = class_name__;
		if (cond(bool__00__0op__not(is_value_type__)))
		{
			return_type__ = return_type__.op__add(string__00(" *_Nonnull"));
		}

		string__00 constructor_parameters__;
		if (cond(bool__00__0op__not(is_value_type__)))
		{
			constructor_parameters__ = convert_method_parameter_list__3(emitter__, parameters_node__, return_type__);
		}
		else
		{
			constructor_parameters__ = convert_parameter_list__2(emitter__, parameters_node__);
		}

		string__00 constructor_signature__ = return_type__.op__add(string__00(" "))->op__add(constructor_full_name__)->op__add(constructor_parameters__);
		write_line__2(emitter__->function_declarations__, constructor_signature__.op__add(string__00(";")));
		element_separator_line__1(emitter__->definitions__);
		write_line__2(emitter__->definitions__, constructor_signature__);
		emit_constructor_body__4(emitter__, first_child__2(member__, Block__), return_type__, is_value_type__);
		string__00 const new_function_signature__ = string__00("inline ").op__add(return_type__)->op__add(string__00(" "))->op__add(new_function_name__)->op__add(convert_parameter_list__2(emitter__, parameters_node__));
		write_line__2(emitter__->function_declarations__, new_function_signature__.op__add(string__00(";")));
		element_separator_line__1(emitter__->definitions__);
		write_line__2(emitter__->definitions__, new_function_signature__);
		begin_block__1(emitter__->definitions__);
		if (cond(bool__00__0op__not(is_value_type__)))
		{
			begin_line__2(emitter__->definitions__, string__00("return ").op__add(constructor_full_name__)->op__add(string__00("(new "))->op__add(class_name__)->op__add(string__00("()")));
		}
		else
		{
			begin_line__2(emitter__->definitions__, string__00("return ").op__add(constructor_full_name__)->op__add(string__00("(")));
		}

		bool__00 first_parameter__ = is_value_type__;
		for (Semantic_Node const *_Nonnull const parameter__ : *(first_child__2(member__, ParameterList__)->children__))
		{
			if (cond(bool__00__0op__not(first_parameter__)))
			{
				write__2(emitter__->definitions__, string__00(", "));
			}
			else
			{
				first_parameter__ = false__00;
			}

			write__2(emitter__->definitions__, mangle_field_name__1(get_text__1(first_child__2(parameter__, Identifier__))));
		}

		end_line__2(emitter__->definitions__, string__00(");"));
		end_block__1(emitter__->definitions__);
	}
	else if (cond(equal_op(member__->kind__, FieldDeclaration__)))
	{
		Semantic_Node const *_Nonnull const variable_declaration__ = first_child__2(member__, VariableDeclaration__);
		string__00 const field_name__ = get_text__1(first_child__2(variable_declaration__, Identifier__));
		Semantic_Node const *_Nonnull const field_type__ = variable_declaration__->children__->op__Element(int__00(2));
		string__00 const cpp_type__ = convert_type__2(true__00, field_type__);
		write_line__2(emitter__->class_declarations__, cpp_type__.op__add(string__00(" "))->op__add(mangle_field_name__1(field_name__))->op__add(string__00(";")));
	}
	else if (cond(equal_op(member__->kind__, MethodDeclaration__)))
	{
		Semantic_Node const *_Nonnull const parameters_node__ = first_child__2(member__, ParameterList__);
		Semantic_Node const *_Nullable const self_parameter__ = first_child__2(parameters_node__, SelfParameter__);
		int__00 parameter_count__ = parameters_node__->children__->op__magnitude();
		if (cond(not_equal_op(self_parameter__, none)))
		{
			parameter_count__.op__subtract_assign(int__00(1));
		}

		string__00 const method_name__ = mangle_function_name__2(get_text__1(first_child__2(member__, Identifier__)), parameter_count__);
		string__00 const parameters__ = convert_parameter_list__2(emitter__, parameters_node__);
		bool__00 const is_associated_function__ = equal_op(self_parameter__, none);
		bool__00 const mutable_self__ = bool__00__op(bool__00__arg(bool__00__0op__not(is_associated_function__)) && bool__00__arg(node_has_child__2(self_parameter__, MutableKeyword__)));
		Semantic_Node const *_Nonnull const return_type_node__ = member__->children__->op__Element(int__00(3));
		string__00 const cpp_type__ = convert_type__2(true__00, return_type_node__);
		string__00 static_modifier__ = string__00("");
		if (cond(is_associated_function__))
		{
			static_modifier__ = string__00("static ");
		}

		string__00 constModifier__ = string__00("");
		if (cond(bool__00__op(bool__00__arg(bool__00__0op__not(mutable_self__)) && bool__00__arg(bool__00__0op__not(is_associated_function__)))))
		{
			constModifier__ = string__00("const ");
		}

		write_line__2(emitter__->class_declarations__, static_modifier__.op__add(string__00("auto "))->op__add(method_name__)->op__add(parameters__)->op__add(string__00(" "))->op__add(constModifier__)->op__add(string__00("-> "))->op__add(cpp_type__)->op__add(string__00(";")));
		element_separator_line__1(emitter__->definitions__);
		write_line__2(emitter__->definitions__, string__00("auto ::").op__add(class_name__)->op__add(string__00("::"))->op__add(method_name__)->op__add(parameters__)->op__add(string__00(" "))->op__add(constModifier__)->op__add(string__00("-> "))->op__add(cpp_type__));
		Semantic_Node const *_Nonnull const block__ = first_child__2(member__, Block__);
		emit_method_body__3(emitter__, block__, is_associated_function__);
	}
	else
	{
		error__2(emitter__->definitions__, string__00("Could not emit member of type ").op__add(member__->kind__));
	}
}

auto emit_default_constructor__3(Emitter *_Nonnull const emitter__, string__00 const type_name__, bool__00 const is_value_type__) -> void
{
	string__00 const default_constructor_name__ = type_name__.op__add(string__00("__0new__0"));
	string__00 return_type__ = type_name__;
	if (cond(bool__00__0op__not(is_value_type__)))
	{
		return_type__ = return_type__.op__add(string__00(" *_Nonnull"));
	}

	string__00 constructor_signature__ = return_type__.op__add(string__00(" "))->op__add(default_constructor_name__)->op__add(string__00("("));
	if (cond(bool__00__0op__not(is_value_type__)))
	{
		constructor_signature__ = constructor_signature__.op__add(return_type__)->op__add(string__00(" self"));
	}

	constructor_signature__ = constructor_signature__.op__add(string__00(")"));
	write_line__2(emitter__->function_declarations__, constructor_signature__.op__add(string__00(";")));
	element_separator_line__1(emitter__->definitions__);
	begin_line__2(emitter__->definitions__, constructor_signature__);
	if (cond(is_value_type__))
	{
		end_line__2(emitter__->definitions__, string__00(" { return {}; }"));
	}
	else
	{
		end_line__2(emitter__->definitions__, string__00(" { return self; }"));
	}

	string__00 const new_function_signature__ = string__00("inline ").op__add(return_type__)->op__add(string__00(" new_"))->op__add(type_name__)->op__add(string__00("()"));
	write_line__2(emitter__->function_declarations__, new_function_signature__.op__add(string__00(";")));
	element_separator_line__1(emitter__->definitions__);
	write_line__2(emitter__->definitions__, new_function_signature__);
	begin_block__1(emitter__->definitions__);
	if (cond(bool__00__0op__not(is_value_type__)))
	{
		write_line__2(emitter__->definitions__, string__00("return ").op__add(default_constructor_name__)->op__add(string__00("(new "))->op__add(type_name__)->op__add(string__00("());")));
	}
	else
	{
		write_line__2(emitter__->definitions__, string__00("return ").op__add(default_constructor_name__)->op__add(string__00("();")));
	}

	end_block__1(emitter__->definitions__);
}

auto emit_declaration__2(Emitter *_Nonnull const emitter__, Semantic_Node const *_Nonnull const declaration__) -> void
{
	if (cond(equal_op(declaration__->kind__, GlobalDeclaration__)))
	{
		Semantic_Node const *_Nonnull const variable_declaration__ = first_child__2(declaration__, VariableDeclaration__);
		string__00 const variable_name__ = get_text__1(first_child__2(variable_declaration__, Identifier__));
		Semantic_Node const *_Nonnull const variable_type__ = variable_declaration__->children__->op__Element(int__00(2));
		bool__00 const mutable_binding__ = node_has_child__2(variable_declaration__, VarKeyword__);
		string__00 const cpp_type__ = convert_type__2(mutable_binding__, variable_type__);
		begin_line__2(emitter__->global_definitions__, cpp_type__);
		write__2(emitter__->global_definitions__, string__00(" ").op__add(mangle_field_name__1(variable_name__))->op__add(string__00(" = ")));
		Semantic_Node const *_Nonnull const expression__ = variable_declaration__->children__->op__Element(int__00(3));
		convert_expression__2(expression__, emitter__->global_definitions__);
		end_line__2(emitter__->global_definitions__, string__00(";"));
	}
	else if (cond(equal_op(declaration__->kind__, ClassDeclaration__)))
	{
		Type const *_Nonnull const declared_type__ = declaration__->declares_type__;
		assert__2(not_equal_op(declared_type__, none), get_text__1(first_child__2(declaration__, Identifier__)));
		string__00 const class_name__ = mangle_name__1(declared_type__);
		write_line__2(emitter__->type_declarations__, string__00("typedef struct ").op__add(class_name__)->op__add(string__00(" "))->op__add(class_name__)->op__add(string__00(";")));
		element_separator_line__1(emitter__->class_declarations__);
		write_line__2(emitter__->class_declarations__, string__00("struct ").op__add(class_name__));
		begin_block__1(emitter__->class_declarations__);
		bool__00 has_constructors__ = false__00;
		for (Semantic_Node const *_Nonnull const member__ : *(node_members__1(declaration__)))
		{
			has_constructors__ = bool__00__op(bool__00__arg(has_constructors__) || bool__00__arg(equal_op(member__->kind__, ConstructorDeclaration__)));
			emit_member_declaration__4(emitter__, member__, class_name__, false__00);
		}

		if (cond(bool__00__0op__not(has_constructors__)))
		{
			emit_default_constructor__3(emitter__, class_name__, false__00);
		}

		end_block_with_semicolon__1(emitter__->class_declarations__);
	}
	else if (cond(equal_op(declaration__->kind__, StructDeclaration__)))
	{
		Type const *_Nonnull const declared_type__ = declaration__->declares_type__;
		assert__2(not_equal_op(declared_type__, none), get_text__1(first_child__2(declaration__, Identifier__)));
		string__00 const struct_name__ = mangle_name__1(declared_type__);
		write_line__2(emitter__->type_declarations__, string__00("typedef struct ").op__add(struct_name__)->op__add(string__00(" "))->op__add(struct_name__)->op__add(string__00(";")));
		element_separator_line__1(emitter__->class_declarations__);
		write_line__2(emitter__->class_declarations__, string__00("struct ").op__add(struct_name__));
		begin_block__1(emitter__->class_declarations__);
		write_line__2(emitter__->class_declarations__, struct_name__.op__add(string__00(" * operator->() { return this; }")));
		write_line__2(emitter__->class_declarations__, struct_name__.op__add(string__00(" const * operator->() const { return this; }")));
		write_line__2(emitter__->class_declarations__, struct_name__.op__add(string__00(" & operator* () { return *this; }")));
		write_line__2(emitter__->class_declarations__, struct_name__.op__add(string__00(" const & operator* () const { return *this; }")));
		bool__00 has_constructors__ = false__00;
		for (Semantic_Node const *_Nonnull const member__ : *(node_members__1(declaration__)))
		{
			has_constructors__ = bool__00__op(bool__00__arg(has_constructors__) || bool__00__arg(equal_op(member__->kind__, ConstructorDeclaration__)));
			emit_member_declaration__4(emitter__, member__, struct_name__, true__00);
		}

		if (cond(bool__00__0op__not(has_constructors__)))
		{
			emit_default_constructor__3(emitter__, struct_name__, true__00);
		}

		end_block_with_semicolon__1(emitter__->class_declarations__);
	}
	else if (cond(equal_op(declaration__->kind__, EnumDeclaration__)))
	{
		string__00 const enum_name__ = get_text__1(first_child__2(declaration__, Identifier__));
		write_line__2(emitter__->type_declarations__, string__00("enum class ").op__add(enum_name__)->op__add(string__00("_;")));
		element_separator_line__1(emitter__->class_declarations__);
		write_line__2(emitter__->class_declarations__, string__00("enum class ").op__add(enum_name__)->op__add(string__00("_")));
		begin_block__1(emitter__->class_declarations__);
		for (Semantic_Node const *_Nonnull const member__ : *(declaration__->children__))
		{
			if (cond(equal_op(member__->kind__, EnumMemberDeclaration__)))
			{
				string__00 const member_name__ = get_text__1(member__->children__->op__Element(int__00(0)));
				begin_line__2(emitter__->class_declarations__, member_name__.op__add(string__00("_")));
				Semantic_Node const *_Nullable const member_value__ = first_child__2(member__, Number__);
				if (cond(not_equal_op(member_value__, none)))
				{
					write__2(emitter__->class_declarations__, string__00(" = "));
					write__2(emitter__->class_declarations__, get_text__1(member_value__));
				}

				end_line__2(emitter__->class_declarations__, string__00(","));
			}
		}

		end_block_with_semicolon__1(emitter__->class_declarations__);
	}
	else if (cond(equal_op(declaration__->kind__, FunctionDeclaration__)))
	{
		Semantic_Node const *_Nonnull const parameters_node__ = first_child__2(declaration__, ParameterList__);
		string__00 name__ = get_text__1(first_child__2(declaration__, Identifier__));
		bool__00 const is_main__ = equal_op(name__, string__00("main"));
		name__ = mangle_function_name__2(name__, parameters_node__->children__->op__magnitude());
		if (cond(is_main__))
		{
			emitter__->main_function_name__ = name__;
		}

		string__00 const parameters__ = convert_parameter_list__3(emitter__, parameters_node__, is_main__);
		Semantic_Node const *_Nonnull const return_type_node__ = declaration__->children__->op__Element(int__00(3));
		string__00 const cpp_type__ = convert_type__2(true__00, return_type_node__);
		write_line__2(emitter__->function_declarations__, string__00("auto ").op__add(name__)->op__add(parameters__)->op__add(string__00(" -> "))->op__add(cpp_type__)->op__add(string__00(";")));
		element_separator_line__1(emitter__->definitions__);
		write_line__2(emitter__->definitions__, string__00("auto ").op__add(name__)->op__add(parameters__)->op__add(string__00(" -> "))->op__add(cpp_type__));
		if (cond(is_main__))
		{
			if (cond(not_equal_op(emitter__->main_function_return_type__, string__00(""))))
			{
				error__2(emitter__->definitions__, string__00("Multiple declarations of main"));
			}

			emitter__->main_function_return_type__ = cpp_type__;
		}

		emit_statement__2(emitter__, first_child__2(declaration__, Block__));
	}
	else if (cond(equal_op(declaration__->kind__, EndOfFileToken__)))
	{
	}
	else
	{
		error__2(emitter__->definitions__, string__00("Could not emit declaration of type ").op__add(declaration__->kind__));
	}
}

auto emit_compilation_unit__2(Emitter *_Nonnull const emitter__, Compilation_Unit const *_Nonnull const unit__) -> void
{
	for (Semantic_Node const *_Nonnull const declaration__ : *(unit__->declarations__))
	{
		emit_declaration__2(emitter__, declaration__);
	}
}

auto emit_preamble__1(Emitter *_Nonnull const emitter__) -> void
{
	write_line__2(emitter__->type_declarations__, string__00("#include \"RuntimeLibrary.hpp\""));
	blank_line__1(emitter__->type_declarations__);
	write_line__2(emitter__->type_declarations__, string__00("// Type Declarations"));
	blank_line__1(emitter__->function_declarations__);
	write_line__2(emitter__->function_declarations__, string__00("// Function Declarations"));
	blank_line__1(emitter__->class_declarations__);
	write_line__2(emitter__->class_declarations__, string__00("// Class Declarations"));
	blank_line__1(emitter__->global_definitions__);
	write_line__2(emitter__->global_definitions__, string__00("// Global Definitions"));
	blank_line__1(emitter__->definitions__);
	write_line__2(emitter__->definitions__, string__00("// Definitions"));
}

auto emit_entry_point_adapter__1(Emitter *_Nonnull const emitter__) -> void
{
	element_separator_line__1(emitter__->definitions__);
	write_line__2(emitter__->definitions__, string__00("// Entry Point Adapter"));
	write_line__2(emitter__->definitions__, string__00("std::int32_t main(int argc, char const *const * argv)"));
	begin_block__1(emitter__->definitions__);
	write_line__2(emitter__->definitions__, string__00("try"));
	begin_block__1(emitter__->definitions__);
	for (Source_Text const *_Nonnull const resource__ : *(emitter__->resources__))
	{
		begin_line__2(emitter__->definitions__, string__00("resource_manager__->AddResource(string__00(\""));
		write__2(emitter__->definitions__, resource__->name__);
		write__2(emitter__->definitions__, string__00("\"), string__00(\""));
		write__2(emitter__->definitions__, resource__->text__.Replace__2(string__00("\\"), string__00("\\\\"))->Replace__2(string__00("\n"), string__00("\\n"))->Replace__2(string__00("\r"), string__00("\\r"))->Replace__2(string__00("\""), string__00("\\\"")));
		end_line__2(emitter__->definitions__, string__00("\"));"));
	}

	if (cond(emitter__->resources__->op__magnitude()->op__greater_than(int__00(0))))
	{
		end_line__2(emitter__->definitions__, string__00(""));
	}

	system__text__String_Builder *_Nonnull const args__ = new_system__text__String_Builder();
	if (cond(emitter__->main_function_accepts_console__))
	{
		args__->Append__1(string__00("new system__console__Console__0()"));
	}

	if (cond(emitter__->main_function_accepts_args__))
	{
		if (cond(emitter__->main_function_accepts_console__))
		{
			args__->Append__1(string__00(", "));
		}

		args__->Append__1(string__00("new system__console__Arguments__0(argc, argv)"));
	}

	if (cond(equal_op(emitter__->main_function_return_type__, string__00("void"))))
	{
		write_line__2(emitter__->definitions__, emitter__->main_function_name__.op__add(string__00("("))->op__add(args__->ToString__0())->op__add(string__00(");")));
		write_line__2(emitter__->definitions__, string__00("return 0;"));
	}
	else
	{
		write_line__2(emitter__->definitions__, string__00("return ").op__add(emitter__->main_function_name__)->op__add(string__00("("))->op__add(args__->ToString__0())->op__add(string__00(").value;")));
	}

	end_block__1(emitter__->definitions__);
	write_line__2(emitter__->definitions__, string__00("catch(std::exception &ex)"));
	begin_block__1(emitter__->definitions__);
	write_line__2(emitter__->definitions__, string__00("std::printf(\"Program exited due to error:\\n\");"));
	write_line__2(emitter__->definitions__, string__00("std::printf(\"%s\", ex.what());"));
	write_line__2(emitter__->definitions__, string__00("return 70;"));
	end_block__1(emitter__->definitions__);
	end_block__1(emitter__->definitions__);
}

Name *_Nonnull Name__0new__global_namespace__0(Name *_Nonnull self)
{
	self->package__ = none;
	self->kind__ = NamespaceName__;
	self->segments__ = new_system__collections__List<string__00>();
	self->is_special__ = false__00;
	return self;
}

inline Name *_Nonnull new_Name__global_namespace()
{
	return Name__0new__global_namespace__0(new Name());
}

Name *_Nonnull Name__0new__global_namespace__1(Name *_Nonnull self, Package_Name const *_Nonnull const package__)
{
	assert__2(not_equal_op(package__, none), string__00(""));
	self->package__ = package__;
	self->kind__ = NamespaceName__;
	self->segments__ = new_system__collections__List<string__00>();
	self->is_special__ = false__00;
	return self;
}

inline Name *_Nonnull new_Name__global_namespace(Package_Name const *_Nonnull const package__)
{
	return Name__0new__global_namespace__1(new Name(), package__);
}

Name *_Nonnull Name__0new__3(Name *_Nonnull self, Name const *_Nonnull const qualifier__, int__00 const kind__, string__00 const name__)
{
	assert__2(not_equal_op(qualifier__, none), string__00(""));
	assert__2(name__.ByteLength__0()->op__greater_than(int__00(0)), string__00(""));
	self->package__ = qualifier__->package__;
	self->kind__ = kind__;
	system__collections__List<string__00> *_Nonnull const segments__ = new_system__collections__List<string__00>();
	for (string__00 const segment__ : *(qualifier__->segments__))
	{
		segments__->add__1(segment__);
	}

	segments__->add__1(name__);
	self->segments__ = segments__;
	self->is_special__ = false__00;
	return self;
}

inline Name *_Nonnull new_Name(Name const *_Nonnull const qualifier__, int__00 const kind__, string__00 const name__)
{
	return Name__0new__3(new Name(), qualifier__, kind__, name__);
}

Name *_Nonnull Name__0new__4(Name *_Nonnull self, Name const *_Nonnull const qualifier__, int__00 const kind__, string__00 const name__, bool__00 const is_special__)
{
	assert__2(not_equal_op(qualifier__, none), string__00(""));
	assert__2(name__.ByteLength__0()->op__greater_than(int__00(0)), string__00(""));
	self->package__ = qualifier__->package__;
	self->kind__ = kind__;
	system__collections__List<string__00> *_Nonnull const segments__ = new_system__collections__List<string__00>();
	for (string__00 const segment__ : *(qualifier__->segments__))
	{
		segments__->add__1(segment__);
	}

	segments__->add__1(name__);
	self->segments__ = segments__;
	self->is_special__ = is_special__;
	return self;
}

inline Name *_Nonnull new_Name(Name const *_Nonnull const qualifier__, int__00 const kind__, string__00 const name__, bool__00 const is_special__)
{
	return Name__0new__4(new Name(), qualifier__, kind__, name__, is_special__);
}

Name *_Nonnull Name__0new__special__3(Name *_Nonnull self, Name const *_Nonnull const qualifier__, int__00 const kind__, string__00 const name__)
{
	assert__2(not_equal_op(qualifier__, none), string__00(""));
	assert__2(name__.ByteLength__0()->op__greater_than(int__00(0)), string__00(""));
	self->package__ = qualifier__->package__;
	self->kind__ = kind__;
	system__collections__List<string__00> *_Nonnull const segments__ = new_system__collections__List<string__00>();
	for (string__00 const segment__ : *(qualifier__->segments__))
	{
		segments__->add__1(segment__);
	}

	segments__->add__1(name__);
	self->segments__ = segments__;
	self->is_special__ = true__00;
	return self;
}

inline Name *_Nonnull new_Name__special(Name const *_Nonnull const qualifier__, int__00 const kind__, string__00 const name__)
{
	return Name__0new__special__3(new Name(), qualifier__, kind__, name__);
}

Name *_Nonnull Name__0new__4(Name *_Nonnull self, Package_Name const *_Nullable const package__, int__00 const kind__, system__collections__List<string__00> const *_Nonnull const segments__, bool__00 const is_special__)
{
	self->package__ = package__;
	self->kind__ = kind__;
	self->segments__ = segments__;
	self->is_special__ = is_special__;
	return self;
}

inline Name *_Nonnull new_Name(Package_Name const *_Nullable const package__, int__00 const kind__, system__collections__List<string__00> const *_Nonnull const segments__, bool__00 const is_special__)
{
	return Name__0new__4(new Name(), package__, kind__, segments__, is_special__);
}

auto unqualified_name__1(Name const *_Nonnull const name__) -> string__00
{
	if (cond(equal_op(name__->segments__->op__magnitude(), int__00(0))))
	{
		return string__00("");
	}

	return name__->segments__->op__Element(name__->segments__->op__magnitude()->op__subtract(int__00(1)));
}

auto full_name__1(Name const *_Nonnull const name__) -> string__00
{
	string__00 result__ = string__00("");
	if (cond(not_equal_op(name__->package__, none)))
	{
		result__ = full_name__1(name__->package__);
	}

	result__ = result__.op__add(string__00("::"));
	bool__00 first__ = true__00;
	for (string__00 const segment__ : *(name__->segments__))
	{
		if (cond(first__))
		{
			first__ = false__00;
			result__ = result__.op__add(segment__);
			continue;
		}

		result__ = result__.op__add(string__00("."))->op__add(segment__);
	}

	return result__;
}

auto is_qualified_by__2(Name const *_Nonnull const name__, Name const *_Nonnull const qualifier__) -> bool__00
{
	if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(not_equal_op(name__->package__, none)) && bool__00__arg(not_equal_op(qualifier__->package__, none)))) && bool__00__arg(not_equal_op(full_name__1(name__->package__), full_name__1(qualifier__->package__))))) || bool__00__arg(name__->segments__->op__magnitude()->op__less_than_or_equal(qualifier__->segments__->op__magnitude())))))
	{
		return false__00;
	}

	int__00 i__ = int__00(0);
	for (string__00 const segment__ : *(qualifier__->segments__))
	{
		if (cond(not_equal_op(segment__, name__->segments__->op__Element(i__))))
		{
			return false__00;
		}

		i__.op__add_assign(int__00(1));
	}

	return true__00;
}

auto qualifier_is__2(Name const *_Nonnull const name__, Name const *_Nonnull const qualifier__) -> bool__00
{
	return bool__00__op(bool__00__arg(equal_op(qualifier__->segments__->op__magnitude()->op__add(int__00(1)), name__->segments__->op__magnitude())) && bool__00__arg(is_qualified_by__2(name__, qualifier__)));
}

auto names__2(Name const *_Nonnull const name__, Name const *_Nonnull const other__) -> bool__00
{
	if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(not_equal_op(name__->package__, none)) && bool__00__arg(bool__00__op(bool__00__arg(equal_op(other__->package__, none)) || bool__00__arg(not_equal_op(full_name__1(name__->package__), full_name__1(other__->package__))))))) || bool__00__arg(not_equal_op(name__->segments__->op__magnitude(), other__->segments__->op__magnitude())))))
	{
		return false__00;
	}

	int__00 i__ = int__00(0);
	for (string__00 const segment__ : *(other__->segments__))
	{
		if (cond(not_equal_op(segment__, name__->segments__->op__Element(i__))))
		{
			return false__00;
		}

		i__.op__add_assign(int__00(1));
	}

	return true__00;
}

auto is_package_qualified__1(Name const *_Nonnull const name__) -> bool__00
{
	return not_equal_op(name__->package__, none);
}

auto remove_package__1(Name const *_Nonnull const name__) -> Name const *_Nonnull
{
	if (cond(equal_op(name__->package__, none)))
	{
		return name__;
	}
	else
	{
		return new_Name(none, name__->kind__, name__->segments__, name__->is_special__);
	}
}

auto unit_test_Name__0() -> void
{
	name_with_unspecified_package_names_name_with_package__0();
	name_with_unspecified_package_names_itself__0();
}

auto name_with_unspecified_package_names_name_with_package__0() -> void
{
	Name const *_Nonnull const name_without_package__ = new_Name(new_Name__global_namespace(), NamespaceName__, string__00("system"));
	Name const *_Nonnull const name_with_package__ = new_Name(new_Name__global_namespace(new_Package_Name(string__00("package"))), NamespaceName__, string__00("system"));
	assert__2(names__2(name_without_package__, name_with_package__), string__00(""));
}

auto name_with_unspecified_package_names_itself__0() -> void
{
	Name const *_Nonnull const name_without_package__ = new_Name(new_Name__global_namespace(), NamespaceName__, string__00("system"));
	assert__2(names__2(name_without_package__, name_without_package__), string__00(""));
}

Package_Name *_Nonnull Package_Name__0new__1(Package_Name *_Nonnull self, string__00 const name__)
{
	assert__2(name__.ByteLength__0()->op__greater_than(int__00(0)), string__00(""));
	self->unqualified__ = name__;
	return self;
}

inline Package_Name *_Nonnull new_Package_Name(string__00 const name__)
{
	return Package_Name__0new__1(new Package_Name(), name__);
}

auto full_name__1(Package_Name const *_Nonnull const package_name__) -> string__00
{
	return package_name__->unqualified__;
}

Symbol *_Nonnull Symbol__0new__identifier__1(Symbol *_Nonnull self, string__00 const name__)
{
	assert__2(name__.ByteLength__0()->op__greater_than(int__00(0)), string__00(""));
	self->name__ = name__;
	self->kind__ = IdentifierSymbol__;
	self->is_special_name__ = false__00;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->declarations__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	self->children__ = new_system__collections__List<Symbol const *_Nonnull>();
	return self;
}

inline Symbol *_Nonnull new_Symbol__identifier(string__00 const name__)
{
	return Symbol__0new__identifier__1(new Symbol(), name__);
}

Symbol *_Nonnull Symbol__0new__identifier__2(Symbol *_Nonnull self, string__00 const name__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__)
{
	assert__2(name__.ByteLength__0()->op__greater_than(int__00(0)), string__00(""));
	assert__2(not_equal_op(declarations__, none), string__00("name=").op__add(name__));
	self->name__ = name__;
	self->kind__ = IdentifierSymbol__;
	self->is_special_name__ = false__00;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->declarations__ = declarations__;
	self->children__ = new_system__collections__List<Symbol const *_Nonnull>();
	return self;
}

inline Symbol *_Nonnull new_Symbol__identifier(string__00 const name__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__)
{
	return Symbol__0new__identifier__2(new Symbol(), name__, declarations__);
}

Symbol *_Nonnull Symbol__0new__identifier__2(Symbol *_Nonnull self, string__00 const name__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__)
{
	assert__2(name__.ByteLength__0()->op__greater_than(int__00(0)), string__00(""));
	assert__2(not_equal_op(children__, none), string__00("name=").op__add(name__));
	self->name__ = name__;
	self->kind__ = IdentifierSymbol__;
	self->is_special_name__ = false__00;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->declarations__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	self->children__ = children__;
	return self;
}

inline Symbol *_Nonnull new_Symbol__identifier(string__00 const name__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__)
{
	return Symbol__0new__identifier__2(new Symbol(), name__, children__);
}

Symbol *_Nonnull Symbol__0new__constructor__2(Symbol *_Nonnull self, string__00 const name__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__)
{
	assert__2(name__.ByteLength__0()->op__greater_than(int__00(0)), string__00(""));
	assert__2(not_equal_op(declarations__, none), string__00("name=").op__add(name__));
	self->name__ = name__;
	self->kind__ = IdentifierSymbol__;
	self->is_special_name__ = true__00;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->declarations__ = declarations__;
	self->children__ = new_system__collections__List<Symbol const *_Nonnull>();
	return self;
}

inline Symbol *_Nonnull new_Symbol__constructor(string__00 const name__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__)
{
	return Symbol__0new__constructor__2(new Symbol(), name__, declarations__);
}

Symbol *_Nonnull Symbol__0new__package__2(Symbol *_Nonnull self, string__00 const name__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__)
{
	assert__2(name__.ByteLength__0()->op__greater_than(int__00(0)), string__00(""));
	assert__2(not_equal_op(children__, none), string__00("name=").op__add(name__));
	self->name__ = name__;
	self->kind__ = PackageSymbol__;
	self->is_special_name__ = false__00;
	self->of_type__ = none;
	self->declares_type__ = none;
	self->declarations__ = new_system__collections__List<Semantic_Node const *_Nonnull>();
	self->children__ = children__;
	return self;
}

inline Symbol *_Nonnull new_Symbol__package(string__00 const name__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__)
{
	return Symbol__0new__package__2(new Symbol(), name__, children__);
}

Symbol *_Nonnull Symbol__0new__declaring__3(Symbol *_Nonnull self, Type const *_Nonnull const declares_type__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__)
{
	assert__2(not_equal_op(declares_type__, none), string__00(""));
	assert__2(not_equal_op(declarations__, none), string__00("name=").op__add(unqualified_name__1(declares_type__->name__)));
	assert__2(not_equal_op(children__, none), string__00("name=").op__add(unqualified_name__1(declares_type__->name__)));
	self->name__ = unqualified_name__1(declares_type__->name__);
	self->is_special_name__ = declares_type__->name__->is_special__;
	self->of_type__ = none;
	self->declares_type__ = declares_type__;
	self->declarations__ = declarations__;
	self->children__ = children__;
	return self;
}

inline Symbol *_Nonnull new_Symbol__declaring(Type const *_Nonnull const declares_type__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__)
{
	return Symbol__0new__declaring__3(new Symbol(), declares_type__, declarations__, children__);
}

Symbol *_Nonnull Symbol__0new__of_type__4(Symbol *_Nonnull self, string__00 const name__, Type const *_Nonnull const of_type__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__)
{
	assert__2(not_equal_op(of_type__, none), string__00("name=").op__add(name__));
	assert__2(not_equal_op(declarations__, none), string__00("name=").op__add(name__));
	assert__2(not_equal_op(children__, none), string__00("name=").op__add(name__));
	self->name__ = name__;
	self->is_special_name__ = false__00;
	self->of_type__ = of_type__;
	self->declares_type__ = none;
	self->declarations__ = declarations__;
	self->children__ = children__;
	return self;
}

inline Symbol *_Nonnull new_Symbol__of_type(string__00 const name__, Type const *_Nonnull const of_type__, system__collections__List<Semantic_Node const *_Nonnull> const *_Nonnull const declarations__, system__collections__List<Symbol const *_Nonnull> const *_Nonnull const children__)
{
	return Symbol__0new__of_type__4(new Symbol(), name__, of_type__, declarations__, children__);
}

auto get_child__3(Symbol const *_Nonnull const symbol__, string__00 const name__, int__00 const kind__) -> Symbol const *_Nullable
{
	for (Symbol const *_Nonnull const child__ : *(symbol__->children__))
	{
		if (cond(bool__00__op(bool__00__arg(equal_op(child__->name__, name__)) && bool__00__arg(equal_op(child__->kind__, kind__)))))
		{
			return child__;
		}
	}

	return none;
}

auto unit_test_Symbol__0() -> void
{
	Package_symbol_children_can_be_found_by_name_and_kind__0();
}

auto Package_symbol_children_can_be_found_by_name_and_kind__0() -> void
{
	system__collections__List<Symbol const *_Nonnull> *_Nonnull const children__ = new_system__collections__List<Symbol const *_Nonnull>();
	children__->add__1(new_Symbol__identifier(string__00("child")));
	Symbol const *_Nonnull const package_with_children__ = new_Symbol__package(string__00("package"), children__);
	assert__2(not_equal_op(get_child__3(package_with_children__, string__00("child"), IdentifierSymbol__), none), string__00(""));
}

Type *_Nonnull Type__0new__3(Type *_Nonnull self, int__00 const kind__, Name const *_Nonnull const name__, bool__00 const is_mutable__)
{
	assert__2(not_equal_op(name__, none), string__00(""));
	self->kind__ = kind__;
	self->name__ = name__;
	self->type_parameters__ = new_system__collections__List<Type const *_Nonnull>();
	self->is_primitive__ = false__00;
	self->is_value_type__ = equal_op(kind__, ValueType__);
	self->is_potentially_mutable__ = is_mutable__;
	self->is_mutable__ = is_mutable__;
	return self;
}

inline Type *_Nonnull new_Type(int__00 const kind__, Name const *_Nonnull const name__, bool__00 const is_mutable__)
{
	return Type__0new__3(new Type(), kind__, name__, is_mutable__);
}

Type *_Nonnull Type__0new__parameter__1(Type *_Nonnull self, string__00 const name__)
{
	self->kind__ = TypeParameterType__;
	self->name__ = new_Name(new_Name__global_namespace(), TypeParameterName__, name__);
	self->type_parameters__ = new_system__collections__List<Type const *_Nonnull>();
	self->is_primitive__ = false__00;
	self->is_value_type__ = false__00;
	self->is_potentially_mutable__ = true__00;
	self->is_mutable__ = false__00;
	return self;
}

inline Type *_Nonnull new_Type__parameter(string__00 const name__)
{
	return Type__0new__parameter__1(new Type(), name__);
}

Type *_Nonnull Type__0new__4(Type *_Nonnull self, int__00 const kind__, Name const *_Nonnull const name__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__, bool__00 const is_mutable__)
{
	self->kind__ = kind__;
	self->name__ = name__;
	self->type_parameters__ = type_parameters__;
	self->is_primitive__ = false__00;
	self->is_value_type__ = equal_op(kind__, ValueType__);
	self->is_potentially_mutable__ = is_mutable__;
	self->is_mutable__ = is_mutable__;
	return self;
}

inline Type *_Nonnull new_Type(int__00 const kind__, Name const *_Nonnull const name__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__, bool__00 const is_mutable__)
{
	return Type__0new__4(new Type(), kind__, name__, type_parameters__, is_mutable__);
}

Type *_Nonnull Type__0new__primitive__1(Type *_Nonnull self, Name const *_Nonnull const name__)
{
	self->kind__ = ValueType__;
	self->name__ = name__;
	self->type_parameters__ = new_system__collections__List<Type const *_Nonnull>();
	self->is_primitive__ = true__00;
	self->is_value_type__ = true__00;
	self->is_potentially_mutable__ = false__00;
	self->is_mutable__ = false__00;
	return self;
}

inline Type *_Nonnull new_Type__primitive(Name const *_Nonnull const name__)
{
	return Type__0new__primitive__1(new Type(), name__);
}

Type *_Nonnull Type__0new__primitive__2(Type *_Nonnull self, Name const *_Nonnull const name__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__)
{
	self->kind__ = ValueType__;
	self->name__ = name__;
	self->type_parameters__ = type_parameters__;
	self->is_primitive__ = true__00;
	self->is_value_type__ = true__00;
	self->is_potentially_mutable__ = false__00;
	self->is_mutable__ = false__00;
	return self;
}

inline Type *_Nonnull new_Type__primitive(Name const *_Nonnull const name__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__)
{
	return Type__0new__primitive__2(new Type(), name__, type_parameters__);
}

Type *_Nonnull Type__0new__namespace__1(Type *_Nonnull self, Name const *_Nonnull const name__)
{
	self->kind__ = NamespaceType__;
	self->name__ = name__;
	self->is_primitive__ = false__00;
	self->type_parameters__ = new_system__collections__List<Type const *_Nonnull>();
	self->is_value_type__ = true__00;
	self->is_potentially_mutable__ = false__00;
	self->is_mutable__ = false__00;
	return self;
}

inline Type *_Nonnull new_Type__namespace(Name const *_Nonnull const name__)
{
	return Type__0new__namespace__1(new Type(), name__);
}

Type *_Nonnull Type__0new__generic__2(Type *_Nonnull self, Type const *_Nonnull const definition__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_arguments__)
{
	assert__2(not_equal_op(definition__, none), string__00(""));
	assert__2(not_equal_op(type_arguments__, none), full_name__1(definition__->name__));
	assert__2(equal_op(definition__->type_parameters__->op__magnitude(), type_arguments__->op__magnitude()), full_name__1(definition__->name__)->op__add(string__00(" "))->op__add(definition__->type_parameters__->op__magnitude())->op__add(string__00(" given "))->op__add(type_arguments__->op__magnitude()));
	self->kind__ = definition__->kind__;
	self->name__ = definition__->name__;
	self->type_parameters__ = type_arguments__;
	self->is_primitive__ = definition__->is_primitive__;
	self->is_value_type__ = definition__->is_value_type__;
	self->is_potentially_mutable__ = definition__->is_potentially_mutable__;
	self->is_mutable__ = definition__->is_mutable__;
	return self;
}

inline Type *_Nonnull new_Type__generic(Type const *_Nonnull const definition__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_arguments__)
{
	return Type__0new__generic__2(new Type(), definition__, type_arguments__);
}

Type *_Nonnull Type__0new__6(Type *_Nonnull self, int__00 const kind__, Name const *_Nonnull const name__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__, bool__00 const is_primitive__, bool__00 const is_potentially_mutable__, bool__00 const is_mutable__)
{
	self->kind__ = kind__;
	self->name__ = name__;
	self->type_parameters__ = type_parameters__;
	self->is_primitive__ = is_primitive__;
	self->is_value_type__ = equal_op(kind__, ValueType__);
	self->is_potentially_mutable__ = is_potentially_mutable__;
	self->is_mutable__ = is_mutable__;
	return self;
}

inline Type *_Nonnull new_Type(int__00 const kind__, Name const *_Nonnull const name__, system__collections__List<Type const *_Nonnull> const *_Nonnull const type_parameters__, bool__00 const is_primitive__, bool__00 const is_potentially_mutable__, bool__00 const is_mutable__)
{
	return Type__0new__6(new Type(), kind__, name__, type_parameters__, is_primitive__, is_potentially_mutable__, is_mutable__);
}

auto make_mutable_type__1(Type const *_Nonnull const type__) -> Type const *_Nonnull
{
	assert__2(type__->is_potentially_mutable__, string__00("self.name=").op__add(full_name__1(type__->name__)));
	return new_Type(type__->kind__, type__->name__, type__->type_parameters__, type__->is_primitive__, type__->is_potentially_mutable__, true__00);
}

auto make_immutable_type__1(Type const *_Nonnull const type__) -> Type const *_Nonnull
{
	return new_Type(type__->kind__, type__->name__, type__->type_parameters__, type__->is_primitive__, type__->is_potentially_mutable__, false__00);
}

auto remove_type_package__1(Type const *_Nonnull const type__) -> Type const *_Nonnull
{
	assert__2(equal_op(type__->kind__, NamespaceType__), string__00("kind=").op__add(type__->kind__));
	if (cond(is_package_qualified__1(type__->name__)))
	{
		return new_Type(type__->kind__, remove_package__1(type__->name__), type__->type_parameters__, type__->is_primitive__, type__->is_potentially_mutable__, type__->is_mutable__);
	}
	else
	{
		return type__;
	}
}

Name_Subtable *_Nonnull Name_Subtable__0new__global_namespace__1(Name_Subtable *_Nonnull self, Name_Table const *_Nonnull const name_table__)
{
	self->name_table__ = name_table__;
	self->parent__ = none;
	self->name__ = new_Name__global_namespace();
	self->type__ = new_Type__namespace(self->name__);
	self->subtables__ = new_system__collections__List<Name_Subtable *_Nonnull>();
	return self;
}

inline Name_Subtable *_Nonnull new_Name_Subtable__global_namespace(Name_Table const *_Nonnull const name_table__)
{
	return Name_Subtable__0new__global_namespace__1(new Name_Subtable(), name_table__);
}

Name_Subtable *_Nonnull Name_Subtable__0new__global_namespace__2(Name_Subtable *_Nonnull self, Name_Table const *_Nonnull const name_table__, Package_Name const *_Nonnull const package_name__)
{
	self->name_table__ = name_table__;
	self->parent__ = none;
	self->name__ = new_Name__global_namespace(package_name__);
	self->type__ = new_Type__namespace(self->name__);
	self->subtables__ = new_system__collections__List<Name_Subtable *_Nonnull>();
	return self;
}

inline Name_Subtable *_Nonnull new_Name_Subtable__global_namespace(Name_Table const *_Nonnull const name_table__, Package_Name const *_Nonnull const package_name__)
{
	return Name_Subtable__0new__global_namespace__2(new Name_Subtable(), name_table__, package_name__);
}

Name_Subtable *_Nonnull Name_Subtable__0new__3(Name_Subtable *_Nonnull self, Name_Subtable const *_Nonnull const parent__, Name const *_Nonnull const name__, Type const *_Nonnull const type__)
{
	self->name_table__ = parent__->name_table__;
	self->parent__ = parent__;
	self->name__ = name__;
	self->type__ = type__;
	self->subtables__ = new_system__collections__List<Name_Subtable *_Nonnull>();
	return self;
}

inline Name_Subtable *_Nonnull new_Name_Subtable(Name_Subtable const *_Nonnull const parent__, Name const *_Nonnull const name__, Type const *_Nonnull const type__)
{
	return Name_Subtable__0new__3(new Name_Subtable(), parent__, name__, type__);
}

auto add_subtable__3(Name_Subtable *_Nonnull const scope__, Name const *_Nonnull const name__, Type const *_Nonnull const type__) -> void
{
	assert__2(is_qualified_by__2(name__, scope__->name__), string__00("\"").op__add(full_name__1(name__))->op__add(string__00("\" is not a child of \""))->op__add(full_name__1(scope__->name__))->op__add(string__00("\"")));
	if (cond(qualifier_is__2(name__, scope__->name__)))
	{
		if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(scope__->name__->package__, none)) && bool__00__arg(not_equal_op(type__, none)))) && bool__00__arg(equal_op(type__->kind__, NamespaceType__)))))
		{
			scope__->subtables__->add__1(new_Name_Subtable(scope__, remove_package__1(name__), remove_type_package__1(type__)));
		}
		else
		{
			scope__->subtables__->add__1(new_Name_Subtable(scope__, name__, type__));
		}

		return;
	}

	for (Name_Subtable *_Nonnull const subtable__ : *(scope__->subtables__))
	{
		if (cond(is_qualified_by__2(name__, subtable__->name__)))
		{
			add_subtable__3(subtable__, name__, type__);
			return;
		}
	}

	assert__2(equal_op(name__->segments__->op__magnitude(), scope__->name__->segments__->op__magnitude()->op__add(int__00(1))), string__00("Can't add \"").op__add(full_name__1(name__))->op__add(string__00("\" to \""))->op__add(full_name__1(scope__->name__))->op__add(string__00("\"")));
}

auto find__2(Name_Subtable const *_Nonnull const scope__, string__00 const name__) -> Name_Subtable *_Nullable
{
	return find__3(scope__, name__, false__00);
}

auto find_special__2(Name_Subtable const *_Nonnull const scope__, string__00 const name__) -> Name_Subtable *_Nullable
{
	return find__3(scope__, name__, true__00);
}

auto find__3(Name_Subtable const *_Nonnull const scope__, string__00 const name__, bool__00 const is_special__) -> Name_Subtable *_Nullable
{
	for (Name_Subtable *_Nonnull const subtable__ : *(scope__->subtables__))
	{
		if (cond(bool__00__op(bool__00__arg(equal_op(unqualified_name__1(subtable__->name__), name__)) && bool__00__arg(equal_op(subtable__->name__->is_special__, is_special__)))))
		{
			return subtable__;
		}
	}

	return none;
}

auto lookup__2(Name_Subtable const *_Nonnull const scope__, string__00 const name__) -> Name_Subtable *_Nullable
{
	return lookup__3(scope__, name__, false__00);
}

auto lookup_special__2(Name_Subtable const *_Nonnull const scope__, string__00 const name__) -> Name_Subtable *_Nullable
{
	return lookup__3(scope__, name__, true__00);
}

auto lookup__3(Name_Subtable const *_Nonnull const scope__, string__00 const name__, bool__00 const is_special__) -> Name_Subtable *_Nullable
{
	Name_Subtable *_Nullable subtable__ = find__3(scope__, name__, is_special__);
	if (cond(bool__00__op(bool__00__arg(equal_op(subtable__, none)) && bool__00__arg(not_equal_op(scope__->parent__, none)))))
	{
		subtable__ = lookup__3(scope__->parent__, name__, is_special__);
	}

	return subtable__;
}

auto get_scope__2(Name_Subtable const *_Nonnull const scope__, Name const *_Nonnull const name__) -> Name_Subtable const *_Nullable
{
	if (cond(names__2(name__, scope__->name__)))
	{
		return scope__;
	}
	else if (cond(bool__00__0op__not(is_qualified_by__2(name__, scope__->name__))))
	{
		return none;
	}

	for (Name_Subtable const *_Nonnull const subtable__ : *(scope__->subtables__))
	{
		Name_Subtable const *_Nullable const value__ = get_scope__2(subtable__, name__);
		if (cond(not_equal_op(value__, none)))
		{
			return value__;
		}
	}

	return none;
}

auto bind_type__2(Name_Subtable *_Nonnull const scope__, Type const *_Nonnull const type__) -> void
{
	assert__2(not_equal_op(type__, none), full_name__1(scope__->name__));
	if (cond(not_equal_op(scope__->type__, none)))
	{
		assert__2(equal_op(full_name__1(scope__->type__->name__), full_name__1(type__->name__)), full_name__1(scope__->name__)->op__add(string__00(" currently `"))->op__add(full_name__1(scope__->type__->name__))->op__add(string__00("` trying to set to `"))->op__add(full_name__1(type__->name__))->op__add(string__00("`")));
	}

	scope__->type__ = type__;
}

auto as_mut__1(Name_Subtable const *_Nonnull const scope__) -> Name_Subtable *_Nonnull
{
	return find__3(scope__->parent__, unqualified_name__1(scope__->name__), scope__->name__->is_special__);
}

auto unit_test_Name_Subtable__0() -> void
{
	global_namespace_contains_added_name__0();
	namespace_contains_added_name__0();
}

auto global_namespace_contains_added_name__0() -> void
{
	Name_Table const *_Nonnull const name_table__ = new_Name_Table();
	Name_Subtable *_Nonnull const global_namespace__ = new_Name_Subtable__global_namespace(name_table__);
	Name const *_Nonnull const test_name__ = new_Name(global_namespace__->name__, TypeName__, string__00("test"));
	add_subtable__3(global_namespace__, test_name__, none);
	assert__2(not_equal_op(find__2(global_namespace__, string__00("test")), none), string__00(""));
	assert__2(not_equal_op(get_scope__2(global_namespace__, test_name__), none), string__00(""));
}

auto namespace_contains_added_name__0() -> void
{
	Name_Table const *_Nonnull const name_table__ = new_Name_Table();
	Name_Subtable *_Nonnull const global_namespace__ = new_Name_Subtable__global_namespace(name_table__);
	Name const *_Nonnull const namespace_name__ = new_Name(global_namespace__->name__, NamespaceName__, string__00("namespace"));
	add_subtable__3(global_namespace__, namespace_name__, none);
	add_subtable__3(global_namespace__, new_Name(namespace_name__, TypeName__, string__00("test")), none);
	Name_Subtable const *_Nonnull const namespace__ = find__2(global_namespace__, string__00("namespace"));
	assert__2(not_equal_op(find__2(namespace__, string__00("test")), none), string__00(""));
}

Name_Table *_Nonnull Name_Table__0new__0(Name_Table *_Nonnull self)
{
	self->any_package__ = new_Name_Subtable__global_namespace(self);
	self->packages__ = new_system__collections__List<Name_Subtable *_Nonnull>();
	return self;
}

inline Name_Table *_Nonnull new_Name_Table()
{
	return Name_Table__0new__0(new Name_Table());
}

auto add_package__2(Name_Table *_Nonnull const name_table__, Package_Name const *_Nonnull const package_name__) -> Name const *_Nonnull
{
	Name_Subtable *_Nonnull const subtable__ = new_Name_Subtable__global_namespace(name_table__, package_name__);
	name_table__->packages__->add__1(subtable__);
	return subtable__->name__;
}

auto add_name__3(Name_Table *_Nonnull const name_table__, Name const *_Nonnull const parent__, Symbol const *_Nonnull const symbol__) -> Name const *_Nonnull
{
	Name const *_Nonnull name__;
	if (cond(not_equal_op(symbol__->declares_type__, none)))
	{
		name__ = new_Name(parent__, TypeName__, symbol__->name__, symbol__->is_special_name__);
		add_name__3(name_table__, name__, symbol__->declares_type__);
	}
	else
	{
		name__ = new_Name(parent__, FunctionName__, symbol__->name__, symbol__->is_special_name__);
		add_name__3(name_table__, name__, symbol__->of_type__);
	}

	return name__;
}

auto add_name__3(Name_Table *_Nonnull const name_table__, Name const *_Nonnull const name__, Type const *_Nonnull const type__) -> void
{
	add_subtable__3(name_table__->any_package__, name__, type__);
	for (Name_Subtable *_Nonnull const package__ : *(name_table__->packages__))
	{
		if (cond(is_qualified_by__2(name__, package__->name__)))
		{
			add_subtable__3(package__, name__, type__);
			return;
		}
	}

	assert__2(false__00, string__00("Can't add name \"").op__add(full_name__1(name__))->op__add(string__00("\" because package doesn't exist in table.")));
}

auto get_name__2(Name_Table const *_Nonnull const name_table__, Name const *_Nonnull const name__) -> Name_Subtable const *_Nullable
{
	if (cond(equal_op(name__->package__, none)))
	{
		return get_scope__2(name_table__->any_package__, name__);
	}

	for (Name_Subtable const *_Nonnull const package__ : *(name_table__->packages__))
	{
		if (cond(is_qualified_by__2(name__, package__->name__)))
		{
			return get_scope__2(package__, name__);
		}
	}

	return none;
}

auto build_name_table__3(Package_Name const *_Nonnull const package_name__, Syntax_Node const *_Nonnull const package_syntax__, system__collections__List<Package_Reference> const *_Nonnull const references__) -> Name_Table const *_Nonnull
{
	assert__2(equal_op(package_syntax__->kind__, PackageNode__), string__00("package_syntax.kind=").op__add(package_syntax__->kind__));
	Name_Table *_Nonnull const name_table__ = new_Name_Table();
	add_referenced__2(name_table__, references__);
	add_package__3(name_table__, package_name__, package_syntax__);
	return name_table__;
}

auto add_referenced__2(Name_Table *_Nonnull const name_table__, system__collections__List<Package_Reference> const *_Nonnull const references__) -> void
{
	for (Package_Reference const reference__ : *(references__))
	{
		Package_Name const *_Nonnull const reference_name__ = new_Package_Name(reference__.name__);
		Name const *_Nonnull const global_namespace__ = add_package__2(name_table__, reference_name__);
		for (Symbol const *_Nonnull const symbol__ : *(reference__.package__->symbol__->children__))
		{
			add_symbol__3(name_table__, global_namespace__, symbol__);
		}
	}
}

auto add_symbol__3(Name_Table *_Nonnull const name_table__, Name const *_Nonnull const parent__, Symbol const *_Nonnull const symbol__) -> void
{
	Name const *_Nonnull const name__ = add_name__3(name_table__, parent__, symbol__);
	for (Symbol const *_Nonnull const child__ : *(symbol__->children__))
	{
		add_symbol__3(name_table__, name__, child__);
	}
}

auto add_package__3(Name_Table *_Nonnull const name_table__, Package_Name const *_Nonnull const package_name__, Syntax_Node const *_Nonnull const package_syntax__) -> void
{
	assert__2(equal_op(package_syntax__->kind__, PackageNode__), string__00("package_syntax.kind=").op__add(package_syntax__->kind__));
	Name const *_Nonnull const global_namespace__ = add_package__2(name_table__, package_name__);
	for (Syntax_Node const *_Nonnull const compilation_unit__ : *(package_syntax__->children__))
	{
		add_compilation_unit__3(name_table__, global_namespace__, compilation_unit__);
	}
}

auto add_compilation_unit__3(Name_Table *_Nonnull const name_table__, Name const *_Nonnull const global_namespace__, Syntax_Node const *_Nonnull const compilation_unit__) -> void
{
	assert__2(equal_op(compilation_unit__->kind__, CompilationUnit__), string__00("compilation_unit.kind=").op__add(compilation_unit__->kind__));
	for (Syntax_Node const *_Nonnull const declaration__ : *(compilation_unit__->children__))
	{
		add_syntax__3(name_table__, global_namespace__, declaration__);
	}
}

auto add_syntax__3(Name_Table *_Nonnull const name_table__, Name const *_Nonnull const parent__, Syntax_Node const *_Nonnull const syntax__) -> void
{
	if (cond(bool__00__op(bool__00__arg(equal_op(syntax__->kind__, FunctionDeclaration__)) || bool__00__arg(equal_op(syntax__->kind__, MethodDeclaration__)))))
	{
		Name const *_Nonnull const name__ = new_Name(parent__, FunctionName__, get_text__1(first_child_syntax__2(syntax__, Identifier__)));
		add_function__3(name_table__, name__, syntax__);
	}
	else if (cond(bool__00__op(bool__00__arg(equal_op(syntax__->kind__, ClassDeclaration__)) || bool__00__arg(equal_op(syntax__->kind__, StructDeclaration__)))))
	{
		string__00 const unqualified_name__ = get_text__1(first_child_syntax__2(syntax__, Identifier__));
		int__00 type_kind__;
		if (cond(equal_op(syntax__->kind__, ClassDeclaration__)))
		{
			type_kind__ = ReferenceType__;
		}
		else
		{
			type_kind__ = ValueType__;
		}

		Name const *_Nonnull const name__ = new_Name(parent__, TypeName__, unqualified_name__);
		Type const *_Nonnull const type__ = new_Type(type_kind__, name__, true__00);
		add_name__3(name_table__, name__, type__);
		for (Syntax_Node const *_Nonnull const member__ : *(members__1(syntax__)))
		{
			add_syntax__3(name_table__, name__, member__);
		}
	}
	else if (cond(equal_op(syntax__->kind__, ConstructorDeclaration__)))
	{
		string__00 full_name__ = string__00("new");
		Syntax_Node const *_Nullable const constructor_name__ = first_child_syntax__2(syntax__, Identifier__);
		if (cond(not_equal_op(constructor_name__, none)))
		{
			full_name__ = string__00("new_").op__add(get_text__1(constructor_name__));
		}

		Name const *_Nonnull const name__ = new_Name__special(parent__, FunctionName__, full_name__);
		add_function__3(name_table__, name__, syntax__);
		Name const *_Nonnull const self_name__ = new_Name__special(name__, VariableName__, string__00("self"));
		Type const *_Nonnull const self_type__ = none;
		add_name__3(name_table__, self_name__, self_type__);
	}
	else if (cond(equal_op(syntax__->kind__, FieldDeclaration__)))
	{
		string__00 const unqualified_name__ = get_text__1(first_child_syntax__2(first_child_syntax__2(syntax__, VariableDeclaration__), Identifier__));
		Name const *_Nonnull const name__ = new_Name(parent__, TypeName__, unqualified_name__);
		Type const *_Nullable const no_type__ = none;
		add_name__3(name_table__, name__, no_type__);
	}
	else if (cond(equal_op(syntax__->kind__, EnumDeclaration__)))
	{
		string__00 const unqualified_name__ = get_text__1(first_child_syntax__2(syntax__, Identifier__));
		Name const *_Nonnull const name__ = new_Name(parent__, TypeName__, unqualified_name__);
		Type const *_Nonnull const type__ = new_Type(ReferenceType__, name__, true__00);
		add_name__3(name_table__, name__, type__);
	}
	else if (cond(equal_op(syntax__->kind__, GlobalDeclaration__)))
	{
		string__00 const unqualified_name__ = get_text__1(first_child_syntax__2(first_child_syntax__2(syntax__, VariableDeclaration__), Identifier__));
		Name const *_Nonnull const name__ = new_Name(parent__, TypeName__, unqualified_name__);
		Type const *_Nullable const no_type__ = none;
		add_name__3(name_table__, name__, no_type__);
	}
	else if (cond(equal_op(syntax__->kind__, Block__)))
	{
		for (Syntax_Node const *_Nonnull const statement__ : *(statements__1(syntax__)))
		{
			add_syntax__3(name_table__, parent__, statement__);
		}
	}
	else if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(syntax__->kind__, LoopStatement__)) || bool__00__arg(equal_op(syntax__->kind__, WhileStatement__)))) || bool__00__arg(equal_op(syntax__->kind__, DoWhileStatement__)))))
	{
		add_syntax__3(name_table__, parent__, first_child_syntax__2(syntax__, Block__));
	}
	else if (cond(equal_op(syntax__->kind__, ForStatement__)))
	{
		Syntax_Node const *_Nonnull const identifier__ = first_child_syntax__2(first_child_syntax__2(syntax__, VariableDeclaration__), Identifier__);
		Name const *_Nonnull const name__ = new_Name(parent__, VariableName__, get_text__1(identifier__));
		Type const *_Nullable const no_type__ = none;
		add_name__3(name_table__, name__, no_type__);
		add_syntax__3(name_table__, parent__, first_child_syntax__2(syntax__, Block__));
	}
	else if (cond(equal_op(syntax__->kind__, IfStatement__)))
	{
		add_syntax__3(name_table__, parent__, first_child_syntax__2(syntax__, Block__));
		Syntax_Node const *_Nullable const else_clause__ = first_child_syntax__2(syntax__, ElseClause__);
		if (cond(not_equal_op(else_clause__, none)))
		{
			add_syntax__3(name_table__, parent__, else_clause__);
		}
	}
	else if (cond(equal_op(syntax__->kind__, ElseClause__)))
	{
		Syntax_Node const *_Nullable const block__ = first_child_syntax__2(syntax__, Block__);
		if (cond(not_equal_op(block__, none)))
		{
			add_syntax__3(name_table__, parent__, block__);
		}
		else
		{
			add_syntax__3(name_table__, parent__, first_child_syntax__2(syntax__, IfStatement__));
		}
	}
	else if (cond(equal_op(syntax__->kind__, LocalDeclarationStatement__)))
	{
		Syntax_Node const *_Nonnull const identifier__ = first_child_syntax__2(first_child_syntax__2(syntax__, VariableDeclaration__), Identifier__);
		Name const *_Nonnull const name__ = new_Name(parent__, VariableName__, get_text__1(identifier__));
		Type const *_Nullable const no_type__ = none;
		add_name__3(name_table__, name__, no_type__);
	}
	else if (cond(equal_op(syntax__->kind__, Parameter__)))
	{
		Syntax_Node const *_Nonnull const identifier__ = first_child_syntax__2(syntax__, Identifier__);
		Name const *_Nonnull const name__ = new_Name(parent__, VariableName__, get_text__1(identifier__));
		Type const *_Nullable const no_type__ = none;
		add_name__3(name_table__, name__, no_type__);
	}
	else if (cond(equal_op(syntax__->kind__, SelfParameter__)))
	{
		Name const *_Nonnull const name__ = new_Name__special(parent__, VariableName__, string__00("self"));
		Type const *_Nullable const no_type__ = none;
		add_name__3(name_table__, name__, no_type__);
	}
	else if (cond(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(bool__00__op(bool__00__arg(equal_op(syntax__->kind__, ExpressionStatement__)) || bool__00__arg(equal_op(syntax__->kind__, ReturnStatement__)))) || bool__00__arg(equal_op(syntax__->kind__, BreakStatement__)))) || bool__00__arg(equal_op(syntax__->kind__, ContinueStatement__)))) || bool__00__arg(equal_op(syntax__->kind__, EndOfFileToken__)))))
	{
	}
	else
	{
		NOT_IMPLEMENTED__1(string__00("syntax.kind=").op__add(syntax__->kind__));
	}
}

auto add_function__3(Name_Table *_Nonnull const name_table__, Name const *_Nonnull const name__, Syntax_Node const *_Nonnull const function__) -> void
{
	Type const *_Nullable const no_type__ = none;
	add_name__3(name_table__, name__, no_type__);
	Syntax_Node const *_Nonnull const parameters_syntax__ = first_child_syntax__2(function__, ParameterList__);
	for (Syntax_Node const *_Nonnull const parameter__ : *(parameters__1(parameters_syntax__)))
	{
		add_syntax__3(name_table__, name__, parameter__);
	}

	Syntax_Node const *_Nonnull const body__ = first_child_syntax__2(function__, Block__);
	add_syntax__3(name_table__, name__, body__);
}

auto unit_test_Name_Table_Builder__0() -> void
{
	table_contains_referenced_child_names__0();
	can_get_root_namespace_from_name__0();
	can_get_Console_class_from_name_without_package__0();
	can_get_Optional_class_from_name_with_package__0();
}

auto table_contains_referenced_child_names__0() -> void
{
	Package_Name const *_Nonnull const name__ = new_Package_Name(string__00("default"));
	Package const *_Nonnull const runtime_package__ = build_runtime_library_package__0();
	system__collections__List<Package_Reference> *_Nonnull const references__ = new_system__collections__List<Package_Reference>();
	references__->add__1(new_Package_Reference(runtime_package__));
	Syntax_Node const *_Nonnull const package_syntax__ = new_Syntax_Node(PackageNode__, none, int__00(0), int__00(0));
	Name_Table const *_Nonnull const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Name_Subtable const *_Nonnull const namespace__ = find__2(name_table__->any_package__, string__00("system"));
	assert__2(not_equal_op(find__2(namespace__, string__00("console")), none), string__00(""));
	Name const *_Nonnull const system_namespace_name__ = new_Name(new_Name__global_namespace(), NamespaceName__, string__00("system"));
	assert__2(not_equal_op(get_name__2(name_table__, system_namespace_name__), none), string__00(""));
	Name const *_Nonnull const console_namespace_name__ = new_Name(system_namespace_name__, NamespaceName__, string__00("console"));
	assert__2(not_equal_op(get_name__2(name_table__, console_namespace_name__), none), string__00(""));
	Name const *_Nonnull const console_class_name__ = new_Name(console_namespace_name__, TypeName__, string__00("Console"));
	assert__2(not_equal_op(get_name__2(name_table__, console_class_name__), none), string__00(""));
}

auto can_get_root_namespace_from_name__0() -> void
{
	Package_Name const *_Nonnull const name__ = new_Package_Name(string__00("default"));
	Package const *_Nonnull const runtime_package__ = build_runtime_library_package__0();
	system__collections__List<Package_Reference> *_Nonnull const references__ = new_system__collections__List<Package_Reference>();
	references__->add__1(new_Package_Reference(runtime_package__));
	Syntax_Node const *_Nonnull const package_syntax__ = new_Syntax_Node(PackageNode__, none, int__00(0), int__00(0));
	Name_Table const *_Nonnull const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Name const *_Nonnull const namespace_name__ = new_Name(new_Name__global_namespace(), NamespaceName__, string__00("system"));
	assert__2(not_equal_op(get_name__2(name_table__, namespace_name__), none), string__00(""));
}

auto can_get_Console_class_from_name_without_package__0() -> void
{
	Package_Name const *_Nonnull const name__ = new_Package_Name(string__00("default"));
	Package const *_Nonnull const runtime_package__ = build_runtime_library_package__0();
	system__collections__List<Package_Reference> *_Nonnull const references__ = new_system__collections__List<Package_Reference>();
	references__->add__1(new_Package_Reference(runtime_package__));
	Syntax_Node const *_Nonnull const package_syntax__ = new_Syntax_Node(PackageNode__, none, int__00(0), int__00(0));
	Name_Table const *_Nonnull const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Name const *_Nonnull const system_namespace_name__ = new_Name(new_Name__global_namespace(), NamespaceName__, string__00("system"));
	Name const *_Nonnull const console_namespace_name__ = new_Name(system_namespace_name__, NamespaceName__, string__00("console"));
	Name const *_Nonnull const console_class_name__ = new_Name(console_namespace_name__, TypeName__, string__00("Console"));
	assert__2(not_equal_op(get_name__2(name_table__, console_class_name__), none), string__00(""));
}

auto can_get_Optional_class_from_name_with_package__0() -> void
{
	Package_Name const *_Nonnull const name__ = new_Package_Name(string__00("default"));
	Package const *_Nonnull const primitives_package__ = build_primitives_package__0();
	system__collections__List<Package_Reference> *_Nonnull const references__ = new_system__collections__List<Package_Reference>();
	references__->add__1(new_Package_Reference(primitives_package__));
	Syntax_Node const *_Nonnull const package_syntax__ = new_Syntax_Node(PackageNode__, none, int__00(0), int__00(0));
	Name_Table const *_Nonnull const name_table__ = build_name_table__3(name__, package_syntax__, references__);
	Package_Name const *_Nonnull const package_name__ = new_Package_Name(string__00("$primitives"));
	Name const *_Nonnull const adamant_namespace_name__ = new_Name(new_Name__global_namespace(), NamespaceName__, string__00("adamant"));
	Name const *_Nonnull const language_namespace_name__ = new_Name(adamant_namespace_name__, NamespaceName__, string__00("language"));
	assert__2(not_equal_op(get_name__2(name_table__, language_namespace_name__), none), string__00(""));
	Name const *_Nonnull const optional_class_name__ = new_Name(language_namespace_name__, TypeName__, string__00("optional"));
	assert__2(not_equal_op(get_name__2(name_table__, optional_class_name__), none), string__00(""));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		resource_manager__->AddResource(string__00("RuntimeLibrary.cpp"), string__00("#include \"RuntimeLibrary.hpp\"\n#include <map>\n\n// -----------------------------------------------------------------------------\n// Primitive Types\n// -----------------------------------------------------------------------------\n\nuint__00 int__00::as_uint__0() const\n{\n    if(this->value < 0)\n        throw std::range_error(\"Can't convert negative number to unsigned\");\n\n    return uint__00(this->value);\n}\n\nchar code_point__00__to_char(code_point__00 v)\n{\n    if(v.value > 0xFF)\n        throw std::range_error(\"Unicode char values not yet supported\");\n\n    return v.value;\n}\n\nstring__00 string__00::construct(code_point__00 c, int__00 repeat)\n{\n    string__00 self;\n    self.Length = repeat.value;\n    char* buffer = new char[repeat.value];\n    for (int i = 0; i < repeat.value; i++)\n        buffer[i] = code_point__00__to_char(c);\n\n    self.Buffer = buffer;\n    return self;\n}\n\nstring__00::string__00(const char* s)\n    : Length(std::strlen(s)), Buffer(s)\n{\n}\n\nstring__00::string__00(int length, const char* s)\n    : Length(length), Buffer(s)\n{\n}\n\nchar const * string__00::cstr() const\n{\n    auto buffer = new char[Length + 1];\n    std::memcpy(buffer, Buffer, Length);\n    buffer[Length] = 0;\n    return buffer;\n}\n\nstring__00::string__00(int__00 other)\n    : Length(0), Buffer(0)\n{\n    char* buffer = new char[12]; // -2,147,483,648 to 2,147,483,647 plus null terminator\n    int length = std::sprintf(buffer,\"%d\", other.value);\n    if(length <= 0) throw std::runtime_error(\"Could not convert int to string\");\n    Length = length;\n    Buffer = buffer;\n}\n\nstring__00::string__00(code_point__00 other)\n    : Length(1), Buffer(new char[1] { code_point__00__to_char(other) })\n{\n}\n\nstring__00::string__00(bool__00 other)\n    : string__00(other.value ? \"true\" : \"false\")\n{\n}\n\nstring__00 string__00::Substring__2(int__00 start, int__00 length) const\n{\n    return string__00(length.value, Buffer + start.value);\n}\n\nstring__00 string__00::Replace__2(string__00 oldValue, string__00 newValue) const\n{\n    system__text__String_Builder__0 builder = system__text__String_Builder__0(); // TODO initialize capacity\n    int limit = Length - oldValue.Length + 1;\n    int lastIndex = 0;\n    // TODO the Substring calls in here are leaking memory\n    for(int i=0; i < limit; i++)\n        if (cond(equal_op(Substring__2(int__00(i), int__00(oldValue.Length)), oldValue)))\n        {\n            builder.Append__1(Substring__2(int__00(lastIndex), int__00(i-lastIndex)));\n            builder.Append__1(newValue);\n            i += oldValue.Length; // skip over the value we just matched\n            lastIndex = i;\n            i--; // we need i-- to offset the i++ that is about to happen\n        }\n\n    builder.Append__1(Substring__2(int__00(lastIndex), int__00(Length - lastIndex)));\n    return builder.ToString__0();\n}\n\nint__00 string__00::LastIndexOf__1(code_point__00 c) const\n{\n    for(int i = Length - 1; i >= 0; i--)\n        if(Buffer[i] == code_point__00__to_char(c))\n            return int__00(i);\n\n    return int__00(-1); // TODO should return none\n}\n\nint__00 string__00::index_of__1(code_point__00 c) const\n{\n    for(int i = 0; i < Length; i++)\n        if(Buffer[i] == code_point__00__to_char(c))\n            return int__00(i);\n\n    return int__00(-1);\n}\n\nstring__00 string__00::op__add(string__00 const & value) const\n{\n    int newLength = Length + value.Length;\n    char* chars = new char[newLength];\n    size_t offset = sizeof(char) * Length;\n    std::memcpy(chars, Buffer, offset);\n    std::memcpy(chars + offset, value.Buffer, value.Length);\n    return string__00(newLength, chars);\n}\n\nauto equal_op(string__00 lhs, string__00 rhs) -> bool__00\n{\n    if (lhs.Length != rhs.Length)\n        return false__00;\n\n    for (int i = 0; i < lhs.Length; i++)\n        if (lhs.Buffer[i] != rhs.Buffer[i])\n            return false__00;\n\n    return true__00;\n}\n\nbool__00 string__00__0op__less_than(string__00 lhs, string__00 rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) < 0;\n    delete[] left;\n    delete[] right;\n    return bool__00_from(result);\n}\nbool__00 string__00__0op__less_than_or_equal(string__00 lhs, string__00 rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) <= 0;\n    delete[] left;\n    delete[] right;\n    return bool__00_from(result);\n}\nbool__00 string__00__0op__greater_than(string__00 lhs, string__00 rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) > 0;\n    delete[] left;\n    delete[] right;\n    return bool__00_from(result);\n}\nbool__00 string__00__0op__greater_than_or_equal(string__00 lhs, string__00 rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) >= 0;\n    delete[] left;\n    delete[] right;\n    return bool__00_from(result);\n}\n\nbool operator < (string__00 const & lhs, string__00 const & rhs)\n{\n    char const* left = lhs.cstr();\n    char const* right = rhs.cstr();\n    bool result = std::strcmp(left, right) < 0;\n    delete[] left;\n    delete[] right;\n    return result;\n}\n\n// -----------------------------------------------------------------------------\n// Standard Library\n// -----------------------------------------------------------------------------\n\nstd::map<string__00, string__00> resourceValues;\n\nstring__00 const & ResourceManager::GetString__1(string__00 resourceName)\n{\n    return resourceValues.at(resourceName);\n}\nvoid ResourceManager::AddResource(string__00 name, string__00 value)\n{\n    resourceValues.insert(std::make_pair(name, value));\n}\n\nResourceManager *const resource_manager__ = new ResourceManager();\n\nvoid debug_write__1(string__00 value)\n{\n    std::fprintf(stderr, \"%.*s\", value.Length, value.Buffer);\n}\nvoid debug_write_line__1(string__00 value)\n{\n    std::fprintf(stderr, \"%.*s\\n\", value.Length, value.Buffer);\n}\nvoid debug_write_line__0()\n{\n    std::fprintf(stderr, \"\\n\");\n}\n\nvoid system__console__Console__0::Write__1(string__00 value)\n{\n    std::printf(\"%.*s\", value.Length, value.Buffer);\n}\n\nvoid system__console__Console__0::WriteLine__1(string__00 value)\n{\n    std::printf(\"%.*s\\n\", value.Length, value.Buffer);\n}\n\nvoid system__console__Console__0::WriteLine__0()\n{\n    std::printf(\"\\n\");\n}\n\nsystem__console__Arguments__0::system__console__Arguments__0(int argc, char const *const * argv)\n    : Count(argc-1)\n{\n    args = new string__00[Count];\n    for (int i = 0; i < Count; i++)\n        args[i] = string__00(argv[i+1]);\n}\n\nsystem__io__File_Reader__0 *_Nonnull system__io__File_Reader__0::construct(const string__00& fileName)\n{\n    std::FILE* foo;\n    auto fname = fileName.cstr();\n    file = std::fopen(fname, \"rb\");\n    delete[] fname;\n    return this;\n}\n\nstring__00 system__io__File_Reader__0::ReadToEndSync__0()\n{\n    std::fseek(file, 0, SEEK_END);\n    auto length = std::ftell(file);\n    std::fseek(file, 0, SEEK_SET);\n    auto buffer = new char[length];\n    length = std::fread(buffer, sizeof(char), length, file);\n    return string__00(length, buffer);\n}\n\nvoid system__io__File_Reader__0::Close__0()\n{\n    std::fclose(file);\n}\n\nsystem__io__File_Writer__0 *_Nonnull system__io__File_Writer__0::construct(const string__00& fileName)\n{\n    auto fname = fileName.cstr();\n    file = std::fopen(fname, \"wb\"); // TODO check error\n    delete[] fname;\n    return this;\n}\n\nvoid system__io__File_Writer__0::Write__1(const string__00& value)\n{\n    std::fwrite(value.Buffer, sizeof(char), value.Length, file);\n}\n\nvoid system__io__File_Writer__0::Close__0()\n{\n    std::fclose(file);\n}\n\nvoid system__text__String_Builder__0::ensure_capacity(int needed)\n{\n    int new_capacity = capacity == 0 ? 128 : capacity;\n    while(new_capacity < needed)\n    {\n        new_capacity *= 2;\n    }\n\n    if(new_capacity > capacity)\n    {\n        char* new_buffer = new char[new_capacity];\n        if(length > 0)\n            std::memcpy(new_buffer, buffer, length);\n\n        if(capacity > 0)\n            delete[] buffer;\n\n        buffer = new_buffer;\n        capacity = new_capacity;\n    }\n}\n\nsystem__text__String_Builder__0 *_Nonnull system__text__String_Builder__0::construct(string__00 const & value)\n{\n    ensure_capacity(value.Length);\n    std::memcpy(buffer, value.Buffer, value.Length);\n    length = value.Length;\n    return this;\n}\n\nsystem__text__String_Builder__0 *_Nonnull system__text__String_Builder__0::construct_with_capacity(int__00 capacity)\n{\n    ensure_capacity(capacity.value);\n    return this;\n}\n\nvoid system__text__String_Builder__0::Append__1(string__00 const & value)\n{\n    int new_length = length + value.Length;\n    ensure_capacity(new_length);\n    std::memcpy(buffer+length, value.Buffer, value.Length);\n    length = new_length;\n}\n\nvoid system__text__String_Builder__0::Append__1(system__text__String_Builder__0 const *_Nonnull value)\n{\n    int new_length = length + value->length;\n    ensure_capacity(new_length);\n    std::memcpy(buffer+length, value->buffer, value->length);\n    length = new_length;\n}\n\nvoid system__text__String_Builder__0::AppendLine__1(string__00 const & value)\n{\n    int new_length = length + value.Length + 1;\n    ensure_capacity(new_length);\n    std::memcpy(buffer+length, value.Buffer, value.Length);\n    buffer[new_length-1] = '\\n';\n    length = new_length;\n}\n\nvoid system__text__String_Builder__0::AppendLine__0()\n{\n    int new_length = length + 1;\n    ensure_capacity(new_length);\n    buffer[new_length-1] = '\\n';\n    length = new_length;\n}\n\nvoid system__text__String_Builder__0::Remove__2(int__00 start, int__00 length)\n{\n    if(start.value >= this->length)\n        throw std::runtime_error(\"String_Builder.Remove() start >= length\");\n\n    int end = start.value + length.value;\n    if(end > this->length) // greater than because end is one past the end of the remove\n        throw std::runtime_error(\"String_Builder.Remove() end > length\");\n\n    std::memmove(buffer+start.value, buffer+end, this->length-end);\n    this->length -= length.value;\n}\n\nvoid system__text__String_Builder__0::Remove__1(int__00 start)\n{\n    if(start.value >= length)\n        throw std::runtime_error(\"String_Builder.Remove() start >= length\");\n\n    length = start.value;\n}\n\nstring__00 system__text__String_Builder__0::ToString__0()\n{\n    string__00 result(length, buffer);\n    // give up ownership of buffer\n    buffer = 0;\n    length = 0;\n    capacity = 0;\n    return result;\n}\n"));
		resource_manager__->AddResource(string__00("RuntimeLibrary.hpp"), string__00("// On windows this disables warnings about using fopen_s instead of fopen\n// It must be defined before including the headers.\n#define _CRT_SECURE_NO_WARNINGS\n#include <cstring>\n#include <cstdio>\n#include <cstdint>\n#include <stdexcept>\n#include <string>\n\n// -----------------------------------------------------------------------------\n// Primitive Types\n// -----------------------------------------------------------------------------\n\n// `bool`\nstruct bool__00\n{\n    bool value;\n};\n\n// `true`\nstatic const bool__00 true__00 = { true };\n// `false`\nstatic const bool__00 false__00 = { false };\n\n// Function used in conditions to make them take `bool__00`\ninline bool cond(bool__00 cond) { return cond.value; }\n\n// Used by runtime for converting to bool__00\ninline bool__00 bool__00_from(bool v) { return bool__00 { v }; }\n\n// Wrap a bool__00 operation that is bool based\ninline bool__00 bool__00__op(bool v) { return bool__00 { v }; }\n// Convert the arguments of a logical operation to bool\ninline bool bool__00__arg(bool__00 v) { return v.value; }\ninline bool__00 bool__00__0op__not(bool__00 v) { return bool__00 { !v.value }; }\n\n// `never`\nstruct never\n{\n};\n\n// `never?`\nstruct o_never\n{\n    // TODO get rid of this conversion operator when compiler emits conversions\n    template<class T>\n    operator T*_Nullable() const { return static_cast<T*>(0); }\n};\n\nstatic const o_never none;\n\ntemplate<typename T>\nstruct p_optional final\n{\nprivate:\n    bool hasValue;\n    union\n    {\n        T data;\n    };\n\npublic:\n    // TODO make this constructor explicit\n    p_optional(T const & value) : data(value), hasValue(true) {}\n    // TODO get rid of this conversion operator when compiler emits conversions\n    p_optional(o_never none) : hasValue(false) {}\n    auto has_value() const -> bool__00 { return bool__00_from(hasValue); }\n    auto value() const -> T { return data; }\n\n    T & operator->()\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n    T const & operator->() const\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n    T & operator* ()\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n    T const & operator* () const\n    {\n        if(!hasValue) throw std::runtime_error(\"Access to `none` Optional value\");\n        return data;\n    }\n};\n\nstruct uint__00;\n\n// `int`\nstruct int__00\n{\n    // Runtime Use Members\n    std::int32_t value;\n\n    explicit int__00() = default;\n    explicit int__00(std::int32_t value): value(value) {}\n\n    int__00 *_Nonnull operator->() { return this; }\n    int__00 const *_Nonnull operator->() const { return this; }\n    int__00 & operator* () { return *this; }\n    int__00 const & operator* () const { return *this; }\n\n    // Hack to support conversion of uint to int for now\n    int__00(uint__00 value);\n\n    // Adamant Members\n    static auto construct() -> int__00 { return int__00(0); }\n    static auto copy(int__00 const & other) -> int__00 { return other; }\n    void op__add_assign(int__00 other) { this->value += other.value; }\n    void op__subtract_assign(int__00 other) { this->value -= other.value; }\n    bool__00 op__less_than(int__00 other) const { return bool__00_from(this->value < other.value); }\n    bool__00 op__less_than_or_equal(int__00 other) const { return bool__00_from(this->value <= other.value); }\n    bool__00 op__greater_than(int__00 other) const { return bool__00_from(this->value > other.value); }\n    bool__00 op__greater_than_or_equal(int__00 other) const { return bool__00_from(this->value >= other.value); }\n    int__00 op__add(int__00 other) const { return int__00(this->value + other.value); }\n    int__00 op__subtract(int__00 other) const { return int__00(this->value - other.value); }\n    int__00 op__multiply(int__00 other) const { return int__00(this->value * other.value); }\n    int__00 op__divide(int__00 other) const { return int__00(this->value / other.value); }\n    int__00 op__remainder(int__00 other) const { return int__00(this->value % other.value); }\n    int__00 op__magnitude() const { if(this->value==INT32_MIN) throw std::overflow_error(\"Can't take |int.Min|\"); return int__00(this->value < 0 ? -this->value : this->value); }\n\n    // Hack because we don't support as correctly yet\n    uint__00 as_uint__0() const;\n};\n\ninline int__00 int__00__0op__negate(int__00 v) { return int__00(-v.value); }\ninline bool__00 int__00__0op__less_than(int__00 lhs, int__00 rhs) { return bool__00_from(lhs.value < rhs.value); }\ninline bool__00 int__00__0op__less_than_or_equal(int__00 lhs, int__00 rhs) { return bool__00_from(lhs.value <= rhs.value); }\ninline bool__00 int__00__0op__greater_than(int__00 lhs, int__00 rhs) { return bool__00_from(lhs.value > rhs.value); }\ninline bool__00 int__00__0op__greater_than_or_equal(int__00 lhs, int__00 rhs) { return bool__00_from(lhs.value >= rhs.value); }\n\n// `uint`\nstruct uint__00\n{\n    // Runtime Use Members\n    std::uint32_t value;\n\n    explicit uint__00() = default;\n    explicit uint__00(std::uint32_t value): value(value) {}\n\n    uint__00 *_Nonnull operator->() { return this; }\n    uint__00 const *_Nonnull operator->() const { return this; }\n    uint__00 & operator* () { return *this; }\n    uint__00 const & operator* () const { return *this; }\n\n    // Hack to support conversion of int to uint for now\n    uint__00(int__00 value): value(value.value) {}\n\n    // Adamant Members\n    static auto construct() -> uint__00 { return uint__00(0); }\n    void op__add_assign(uint__00 other) { this->value += other.value; }\n    void op__subtract_assign(uint__00 other) { this->value -= other.value; }\n    bool__00 op__less_than(uint__00 other) const { return bool__00_from(this->value < other.value); }\n    bool__00 op__less_than_or_equal(uint__00 other) const { return bool__00_from(this->value <= other.value); }\n    bool__00 op__greater_than(uint__00 other) const { return bool__00_from(this->value > other.value); }\n    bool__00 op__greater_than_or_equal(uint__00 other) const { return bool__00_from(this->value >= other.value); }\n    uint__00 op__add(uint__00 other) const { return uint__00(this->value + other.value); }\n    uint__00 op__subtract(uint__00 other) const { return uint__00(this->value - other.value); }\n};\n\ninline bool__00 uint__00__0op__less_than(uint__00 lhs, uint__00 rhs) { return bool__00_from(lhs.value < rhs.value); }\ninline bool__00 uint__00__0op__less_than_or_equal(uint__00 lhs, uint__00 rhs) { return bool__00_from(lhs.value <= rhs.value); }\ninline bool__00 uint__00__0op__greater_than(uint__00 lhs, uint__00 rhs) { return bool__00_from(lhs.value > rhs.value); }\ninline bool__00 uint__00__0op__greater_than_or_equal(uint__00 lhs, uint__00 rhs) { return bool__00_from(lhs.value >= rhs.value); }\n\ninline int__00::int__00(uint__00 value)\n    : value(value.value)\n{\n}\n\nstruct code_point__00\n{\n    std::uint32_t value;\n\n    // Runtime Use Members\n    explicit code_point__00() = default;\n    explicit code_point__00(char value): value(value) {}\n\n    code_point__00 *_Nonnull operator->() { return this; }\n    code_point__00 const *_Nonnull operator->() const { return this; }\n    code_point__00 & operator* () { return *this; }\n    code_point__00 const & operator* () const { return *this; }\n\n    // Adamant Members\n    // static auto construct() -> code_point__00 { return code_point__00('\\0'); }\n};\n\nchar code_point__00__to_char(code_point__00 v);\n\n// TODO: Not sure code_point__00 should support comparision operations\ninline bool__00 code_point__00__0op__less_than(code_point__00 lhs, code_point__00 rhs) { return bool__00_from(lhs.value < rhs.value); }\ninline bool__00 code_point__00__0op__less_than_or_equal(code_point__00 lhs, code_point__00 rhs) { return bool__00_from(lhs.value <= rhs.value); }\ninline bool__00 code_point__00__0op__greater_than(code_point__00 lhs, code_point__00 rhs) { return bool__00_from(lhs.value > rhs.value); }\ninline bool__00 code_point__00__0op__greater_than_or_equal(code_point__00 lhs, code_point__00 rhs) { return bool__00_from(lhs.value >= rhs.value); }\n\nstruct string__00\n{\n    // Runtime Use Members\n    char const *_Nonnull Buffer;\n    int Length;\n\n    explicit string__00() = default;\n    explicit string__00(char const *_Nonnull s);\n    explicit string__00(int length, char const *_Nonnull s);\n    char const *_Nonnull cstr() const;\n    string__00 const *_Nonnull operator->() const { return this; }\n    string__00 const & operator* () const { return *this; }\n\n    typedef char const *_Nonnull const_iterator;\n    const_iterator begin() const { return &Buffer[0]; }\n    const_iterator end() const { return &Buffer[Length]; }\n\n    // Hack to support conversion of int and code_point__00 to string__00s for now\n    string__00(int__00 other);\n    string__00(code_point__00 other);\n    explicit string__00(bool__00 other);\n\n    // Adamant Members\n    static auto construct() -> string__00 { string__00 self; self.Length = 0; self.Buffer = 0; return self; }\n    static auto construct(string__00 value) -> string__00 { return value; }\n    static auto construct(code_point__00 c, int__00 repeat) -> string__00;\n    // TODO ByteLength should be a property\n    int__00 ByteLength__0() const { return int__00(Length); }\n\n    string__00 Substring__2(int__00 start, int__00 length) const;\n    string__00 Substring__1(int__00 start) const { return Substring__2(start, int__00(Length-start.value)); }\n    string__00 Replace__2(string__00 oldValue, string__00 newValue) const;\n    int__00 LastIndexOf__1(code_point__00 c) const;\n    int__00 index_of__1(code_point__00 c) const;\n\n    // TODO check index bounds\n    code_point__00 op__Element(int__00 const index) const { return code_point__00(Buffer[index.value]); }\n    string__00 op__add(string__00 const & value) const;\n    string__00 op__add(bool__00 value) const { return this->op__add(string__00(value)); }\n};\n\nbool__00 string__00__0op__less_than(string__00 lhs, string__00 rhs);\nbool__00 string__00__0op__less_than_or_equal(string__00 lhs, string__00 rhs);\nbool__00 string__00__0op__greater_than(string__00 lhs, string__00 rhs);\nbool__00 string__00__0op__greater_than_or_equal(string__00 lhs, string__00 rhs);\n\ninline string__00 new_string__00()\n{\n    return string__00::construct();\n}\ninline string__00 new_string__00(string__00 value)\n{\n    return string__00::construct(value);\n}\ninline string__00 new_string__00(code_point__00 c, int__00 repeat)\n{\n    return string__00::construct(c, repeat);\n}\n\n// -----------------------------------------------------------------------------\n// Operators\n// -----------------------------------------------------------------------------\n\ninline auto equal_op(bool__00 lhs, bool__00 rhs) -> bool__00\n{\n    return bool__00_from(lhs.value == rhs.value);\n}\ninline auto equal_op(p_optional<bool__00> lhs, p_optional<bool__00> rhs) -> bool__00\n{\n    if(lhs.has_value().value)\n        return bool__00__op(bool__00__arg(rhs.has_value()) && bool__00__arg(equal_op(lhs.value(), rhs.value())));\n    else\n        return bool__00__0op__not(rhs.has_value());\n}\n\ninline auto equal_op(int__00 lhs, int__00 rhs) -> bool__00\n{\n    return bool__00_from(lhs.value == rhs.value);\n}\ninline auto equal_op(p_optional<int__00> lhs, p_optional<int__00> rhs) -> bool__00\n{\n    if(lhs.has_value().value)\n        return bool__00__op(bool__00__arg(rhs.has_value()) && bool__00__arg(equal_op(lhs.value(), rhs.value())));\n    else\n        return bool__00__0op__not(rhs.has_value());\n}\n\ninline auto equal_op(o_never lhs, o_never rhs) -> bool__00\n{\n    return true__00;\n}\n\ninline auto equal_op(code_point__00 lhs, code_point__00 rhs) -> bool__00\n{\n    return bool__00_from(lhs.value == rhs.value);\n}\n\nauto equal_op(string__00 lhs, string__00 rhs) -> bool__00;\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto equal_op(T const *_Nullable lhs, o_never rhs) -> bool__00\n{\n    return bool__00_from(lhs == 0);\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto equal_op(o_never lhs, T const *_Nullable rhs) -> bool__00\n{\n    return bool__00_from(0 == rhs);\n}\n\n// TODO Get rid of this ability\ntemplate<typename T>\ninline auto equal_op(T const *_Nullable lhs, T const *_Nullable const & rhs) -> bool__00\n{\n    return bool__00_from(lhs == 0);\n}\n\ninline auto not_equal_op(int__00 lhs, int__00 rhs) -> bool__00\n{\n    return bool__00_from(lhs.value != rhs.value);\n}\ninline auto not_equal_op(p_optional<int__00> lhs, p_optional<int__00> rhs) -> bool__00\n{\n    if(lhs.has_value().value)\n        return bool__00__op(bool__00__arg(bool__00__0op__not(rhs.has_value())) || bool__00__arg(not_equal_op(lhs.value(), rhs.value())));\n    else\n        return rhs.has_value();\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto not_equal_op(T lhs, T  rhs) -> bool__00\n{\n    return bool__00__0op__not(equal_op(lhs, rhs));\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto not_equal_op(T const *_Nullable lhs, o_never rhs) -> bool__00\n{\n    return bool__00_from(lhs != 0);\n}\n\n// TODO implement this without templates\ntemplate<typename T>\ninline auto not_equal_op(o_never lhs, T const *_Nullable rhs) -> bool__00\n{\n    return bool__00_from(0 != rhs);\n}\n\n// -----------------------------------------------------------------------------\n// Standard Library\n// -----------------------------------------------------------------------------\n// Parts of the standard library that are currently implemented in the runtime.\n\ninline void assert(const bool__00 condition, char const *_Nonnull code, const string__00 message, char const *_Nonnull file, const std::int32_t line)\n{\n    if(!condition.value)\n        throw std::runtime_error(\n            string__00(\"Assertion failed: \").op__add(string__00(code)).op__add(string__00(\", \")).op__add(message)\n            .op__add(string__00(\", file \")).op__add(string__00(file)).op__add(string__00(\", line \")).op__add(int__00(line)).cstr());\n}\n\n#define assert__2(condition, message) assert(condition, #condition, message, __FILE__, __LINE__)\n\n\n_Noreturn inline void NOT_IMPLEMENTED(const string__00 message, char const *_Nonnull function, char const *_Nonnull file, const std::int32_t line)\n{\n    throw std::runtime_error(\n        string__00(\"Function \").op__add(string__00(function))\n        .op__add(string__00(\" not yet implemented, \")).op__add(message).op__add(string__00(\", \")).op__add(string__00(file)).op__add(string__00(\", line \")).op__add(int__00(line)).cstr());\n}\n\n_Noreturn inline void NOT_IMPLEMENTED(char const *_Nonnull function, char const *_Nonnull file, const std::int32_t line)\n{\n    throw std::runtime_error(\n        string__00(\"Function \").op__add(string__00(function))\n        .op__add(string__00(\" not yet implemented, \")).op__add(string__00(file)).op__add(string__00(\", line \")).op__add(int__00(line)).cstr());\n}\n\n#define NOT_IMPLEMENTED__1(message) NOT_IMPLEMENTED(message, __func__, __FILE__, __LINE__)\n#define NOT_IMPLEMENTED__0() NOT_IMPLEMENTED(__func__, __FILE__, __LINE__)\n\n_Noreturn inline void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const std::int32_t line)\n{\n    throw std::runtime_error(\n        string__00(\"Reached \\\"UNREACHABLE\\\" statement in function \").op__add(string__00(function))\n        .op__add(string__00(\", \")).op__add(string__00(file)).op__add(string__00(\", line \")).op__add(int__00(line)).cstr());\n}\n\n#define UNREACHABLE__0() UNREACHABLE(__func__, __FILE__, __LINE__)\n\nclass ResourceManager\n{\npublic:\n    string__00 const & GetString__1(string__00 resourceName);\n    void AddResource(string__00 name, string__00 value);\n};\n\nextern ResourceManager *_Nonnull const resource_manager__;\n\nvoid debug_write__1(string__00 value);\nvoid debug_write_line__1(string__00 value);\nvoid debug_write_line__0();\n\ntemplate<typename T>\nclass system__collections__List__1\n{\nprivate:\n    T *_Nonnull values;\n    int length;\n    int capacity;\n\npublic:\n    // Runtime Use Members\n    typedef T const *_Nonnull const_iterator;\n    const_iterator begin() const { return values; }\n    const_iterator end() const { return &values[length]; }\n\n    // Adamant Members\n    system__collections__List__1 *_Nonnull construct() { values = 0; length = 0; capacity = 0; return this; }\n    void add__1(T value);\n    void clear__0() { length = 0; }\n    int__00 op__magnitude() const { return int__00(length); }\n    T const & op__Element(int__00 const index) const;\n};\n\ntemplate<typename T>\nvoid system__collections__List__1<T>::add__1(T value)\n{\n    if(length >= capacity)\n    {\n        int newCapacity = capacity == 0 ? 16 : capacity * 2;\n        // Allocate uninitalized buffer (note `sizeof(char) == 1` always)\n        // Needed if T is a value type to avoid needing a default constructor\n        T* newValues = (T*)new char[newCapacity * sizeof(T)];\n        std::memcpy(newValues, values, length * sizeof(T));\n        values = newValues;\n        capacity = newCapacity;\n    }\n    values[length] = value;\n    length++;\n}\n\ntemplate<typename T>\nT const & system__collections__List__1<T>::op__Element(int__00 const index) const\n{\n    if(index.value < 0 || index.value >= length)\n        throw std::out_of_range(\"List index out of bounds\");\n    return values[index.value];\n}\n\ntemplate<typename T>\nsystem__collections__List__1<T> *_Nonnull new_system__collections__List__1()\n{\n    return (new system__collections__List__1<T>())->construct();\n}\n\nclass system__console__Console__0\n{\npublic:\n    void Write__1(string__00 value);\n    void WriteLine__1(string__00 value);\n    void WriteLine__0();\n};\n\nclass system__console__Arguments__0\n{\nprivate:\n    string__00 *_Nonnull args;\npublic:\n    // Runtime Use Members\n    typedef string__00 const *_Nonnull const_iterator;\n\n    system__console__Arguments__0(int argc, char const *_Nonnull const *_Nonnull argv);\n    const_iterator begin() const { return &args[0]; }\n    const_iterator end() const { return &args[Count]; }\n\n    const int Count;\n\n    // Adamant Members\n    int__00 op__magnitude() const { return int__00(Count); }\n    string__00 const & op__Element(int__00 const index) const\n    {\n        if(index.value < 0 || index.value >= Count)\n            throw std::out_of_range(\"Argument index out of bounds\");\n        return args[index.value];\n    }\n};\n\nclass system__io__File_Reader__0\n{\nprivate:\n    std::FILE *_Nonnull file;\n\npublic:\n    system__io__File_Reader__0 *_Nonnull construct(const string__00& fileName);\n    string__00 ReadToEndSync__0();\n    void Close__0();\n};\n\ninline system__io__File_Reader__0 *_Nonnull new_system__io__File_Reader__0(const string__00& fileName)\n{\n    return (new system__io__File_Reader__0())->construct(fileName);\n}\n\nclass system__io__File_Writer__0\n{\nprivate:\n    std::FILE *_Nonnull file;\n\npublic:\n    system__io__File_Writer__0 *_Nonnull construct(const string__00& fileName);\n    void Write__1(const string__00& value);\n    void Close__0();\n};\n\ninline system__io__File_Writer__0 *_Nonnull new_system__io__File_Writer__0(const string__00& fileName)\n{\n    return (new system__io__File_Writer__0())->construct(fileName);\n}\n\nclass system__text__String_Builder__0\n{\nprivate:\n    char *_Nullable buffer;\n    int capacity;\n    int length;\n    void ensure_capacity(int needed);\npublic:\n    // Runtime Use Members\n    system__text__String_Builder__0(): buffer(0), capacity(0), length(0) { }\n\n    // Adamant Members\n    system__text__String_Builder__0 *_Nonnull construct() { return this; }\n    system__text__String_Builder__0 *_Nonnull construct(string__00 const & value);\n    system__text__String_Builder__0 *_Nonnull construct_with_capacity(int__00 capacity);\n    // TODO byte_length should be a property\n    int__00 byte_length__0() const { return int__00(length); }\n    void Append__1(string__00 const & value);\n    void Append__1(system__text__String_Builder__0 const *_Nonnull value);\n    void AppendLine__1(string__00 const& value);\n    void AppendLine__0();\n    void Remove__2(int__00 start, int__00 length);\n    void Remove__1(int__00 start);\n    string__00 ToString__0();\n};\n\ninline system__text__String_Builder__0 *_Nonnull new_system__text__String_Builder__0()\n{\n    return (new system__text__String_Builder__0())->construct();\n}\n\ninline system__text__String_Builder__0 *_Nonnull new_system__text__String_Builder__0(string__00 const & value)\n{\n    return (new system__text__String_Builder__0())->construct(value);\n}\n\ninline system__text__String_Builder__0 *_Nonnull new_system__text__String_Builder__0__with_capacity(int__00 capacity)\n{\n    return (new system__text__String_Builder__0())->construct_with_capacity(capacity);\n}\n"));

		return main__2(new system__console__Console(), new system__console__Arguments(argc, argv)).value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
