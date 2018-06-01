# Translation

This document describes the translation of Adamant into C and gives reasons for the particular C construct chosen to represent Adamant constructs.

## `const` Keyword

Whenever `const` is used, it is placed after the thing it is making constant so that type declarations can always be read right to left.  If possible, it should not have a space between it and what it is making constant. For example, `foo const *` is a pointer to a constant foo, while `foo *const` is a constant pointer to a mutable foo.

## Identifiers

Identifiers in Adamant programs are translated to the same identifier followed by an underscore `_` character. This ensures that Adamant identifiers will never conflict with C keywords or components of the runtime (such as operator methods). It also prevents accidental use of C features. For example, at one point during compiler development, the C `this` keyword was used from inside Adamant code when it should have been the `self` keyword instead.

## Trailing Return Type Declaration

New style trailing return type declarations are used. This is to avoid parsing ambiguities caused when the return type was listed before and was always qualified to the global scope. The problem was that `::return_type ::class_name::method()` looked to the compiler like it might be a single declaration because the `::` operator before the class name was interpreted as joining the return type to it.
