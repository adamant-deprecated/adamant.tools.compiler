# Adamant v0.1.0 Language Spec

  * Code is in ASCII encoding
  * The first parameter is the input file, the second the output file
  * The output is C++ code
  * Only top-level functions are supported (Declaration order doesn't matter)
  * There are no access modifiers, everything is assumed public
  * Compiler errors are written to the output file
  * Little to no error checking is performed
  * All memory is leaked and never deleted
  * Primitive types:
	* int - a four byte signed integer
	* string - an immutable collection of characters
	* void - for functions that don't return a value
	* bool
	* code_point - currently treated as ASCII char instead of Unicode Code Point
  * Literals:
    * true/false
	* "strings"
	* 'c' ASCII characters
  * Operators:
    * not and or
	* \+ \-
    