# `adamant.tools.compiler.emit.c`

Emit C code for the semantic tree.

## Name Mangling

For some time, the name mangling scheme was rather complex. It was intended to produce names that could never conflict and never be spoofed by names in the source code. At the same time, it was trying to keep the mangled names as short as possible and maintain as much readability as possible. Eventually, it was decided this approach wasn't the best.

Reviewing the LLVM identifier rules, any character can be used in an identifier by simply enclosing the identifier in quotes. So when the compiler is transitioned from emitting C to LLVM, it will be able to simply use the source syntax like dots, parentheses and angle brackets in the identifiers. Thus any name mangling scheme used now will be discarded. Given this, it seemed to make sense to have a scheme that is easier to read and closer to a direct translation of the names. This lead to a simplified name mangling scheme that produces longer but more readable names. It was however realized that they could still easily be made unique.

The name mangling makes use of two things to produce unique manglings. First, no identifier can begin with a digit. Second, it uses double underscore as a unique separator by escaping existing double underscores.

The name mangling occurs in two phases. In the first phase, the name of the individual element (i.e. class, struct, method or function) is mangled. In the second phase, it is combined with the names of connected elements like namespaces and arguments to produce a full name. In this process, parts are separated by a double underscore and keywords and special type names are distinguished by zero prefixes.

### Phase 1

This phase ensures that there can be no conflicts with standard C identifiers and escapes the double underscore so it can be used as a separator. Note that all names even namespaces need to be modified.

1. For any run of more than one underscore, add another underscore on the end. (This ensures no double underscores occur in the identifier)
2. For types **and namespaces**, append double underscore and the number of type parameters, even if zero.
3. For functions, append double underscore and the number of parameters, even if zero.
4. For fields and variables, append a double underscore. For redeclarations of a variable, append a unique sequence number.

### Phase 2

This phase is specified in a short hand notation of concatenating strings.

1. `containing_namespace + "__" + namespace`
2. `namespace + "__" + class_name`
3. `namespace + "__" + struct_name`
4. `type_name + "__0new__" + constructor_name`
5. `type_name + "__0new__" + number_of_parameters`
6. `type_name + "__0get__" + property_name`
7. `type_name + "__0set__" + property_name`
8. `type_name + "__0op__" + operator_name`

### Special Names

Since all names are mangled, we are free to use C style names without concern for conflict except with the C standard library. This allows for shorter cleaner code

* Tuples: `tuple` + number_of_type_parameters + `__` + type_parameters_separated_by_underscores
* Primitives: type except that
  * `int32`
  * `uint32`
  * `BOOL`
* Optional: `optional__` + the_type_that_is_optional
* True & False: `TRUE`, `FALSE`
* None: `none`

## References and Pointers

The above name mangling produces a base name for the value type. However, classes are passed by reference and there are also references to variables. These are converted to pointers in C. However, for clarity, a number of macros have been defined. This allows the use of the clang `_Nonnull` and `_Nullable` extensions without cluttering the code with them. The macros are:

* `ref` expands to `*_Nonnull restrict` i.e. a non-null pointer
* `opt_ref` stands for optional references and expands to `*_Nullable restrict`
* `ptr` expands to `*_Nonnull` i.e. a non-null pointer
* `opt_ptr` stands for optional pointer and expands to `*_Nullable`
* `mut` stands for mutable and expands to empty string. It is used as a marker for non-constant types

For clarity we follow the convention of always writing types in C from right-to-left. This ensures that types can be read off in one direction, even if it is odd that they are read right-to-left. For example, `var x: ref mut int` becomes `int32 mut ref mut x`. Note that classes declare references types, but when emitted to C, the variables types explicitly state they are references. For example, `let sb: mut String_Builder` becomes `String_Builder mut ref const sb`. Even for types that aren't references, the reverse order is followed. For example, `let x: int` becomes `int const x`.

Here `ref var` and `ref mut` are treated as identical. This is in part because they can't really be distinguished in C's type system. However, it is also because it seems likely that they will be unified in Adamant eventually.
