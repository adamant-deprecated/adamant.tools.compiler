# Adamant v0.1.0 Language Spec

  * Code is in ASCII encoding
  * Code is read from standard in and assembly written to standard out
  * The output is an llvm assembly file with the same name but differ
  * Only top-level functions are supported and must be declared before being used
  * There are no access modifiers, everything is assumed public
  * There are not comments
  * Compiler errors are written to the output file
  * Little to no error checking is performed
  * All memory is leaked and never deleted
  * Primitive types:
	* int - a four byte signed integer
	* string - an immutable collection of characters
	* void - for functions that don't return a value
	* bool
  * Primitive functions:
	* Length(char) -> int - length of string
	* ReadChar() -> int - reads a character from standard in, -1 for end of input
	* Write(string) -> void - write string to standard out
	* Exit(int) -> void - terminate the program with the given exit code
  * Primitive values:
    * true/false
  * Operators:
    * not
	* \+ concatenate string
  * Constants:
    * "strings"
	* 'c' ASCII characters