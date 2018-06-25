# `adamant.tools.compiler.semantics`

The representation of semantics in the compiler is more complicated than in some other compilers. This is to simultaneously support in-memory incremental compilation, parallel compilation and the ownership model.

The semantic model is represented as an annotated abstract syntax tree (`Program_Fragment`). The annotations provide information about type checking, borrow checking, and name binding. Cross links in the tree are not direct references in order to prevent issues with lifetimes without having to completely recreate the tree during in-memory incremental compilation. Instead, they are provided as names (`Name`). These names can be used to rapidly reference tree nodes by lookup through a symbol tree (`Symbol`). Likewise, types are represented as essentially special names (`Type`) that can be looked up in the symbol tree. The symbol tree and abstract syntax tree compose a package (`Package`).

During analysis, the semantic model is being built up and not all the symbols and annotations for a given node may be available at any given point. This prevents use of the strongly typed abstract syntax and symbol tree during analysis. Instead structures associating data with the concrete syntax tree nodes are created and then frozen to provide many of the benefits that having a strongly typed abstract syntax tree for each step/phase would. The idea is that a series of interfaces will provide a transition from requesting certain properties on arbitrary nodes to only being able to request them on the node that should have that attribute (i.e. `declares_type(x)`). During the transitions, a check/assert phase can ensure that the attribute being frozen has been applied to all and only the nodes that it should be on. Additionally, symbols are provisionally constructed as a tree of symbol declarations (`Syntax_Symbol`). This allows the traversing of the syntax tree as if it had a complete symbol tree.

## Analyses Performed

The various semantic analyses performed are:

* Declared Type Name Binding - bind all declared type names
* Variable Name Binding - bind variable and field references to their declarations
* Type Checking - check the type correctness of initializers and function bodies
* Type Inference - type inference within functions
* Overload Resolution - resolve which overload is being called
* Borrow Checking - check the lifetime and borrow rules
* Constant Evaluation - evaluate constant expressions (needed because their result can affect type checking and inference)
* Safety Rules - that unsafe operations are only performed in unsafe contexts
* Effect Type Inference - inferring and checking the effect types of functions

## Analysis Steps

1. Build the symbol declaration tree with declares types (omit types for fields, globals and functions).
2. Bind globals, fields and parameters, assign function types and associate name binders with function scopes.
3. Name binding, type checking, type inference and overload resolution are done for each function in parallel.
4. Borrow checking
5. Safety Rules
6. Effect Typing
7. Abstract syntax tree and symbol tree building

## Design Notes

The Roslyn C# compiler avoids the issue of having a weakly typed analysis phase by using lazy evaluation. Thus it creates a strongly typed semantic model which it lazily evaluates. It then appears that all semantic annotations are available on all nodes when they are calculated on the fly and the results memoized. This strategy was rejected for the Adamant compiler because it relies heavily on locking for multi-threaded safety and still introduces issues of weak typing when evaluating annotations because cycles must be avoided and broken. The threading model of Adamant is meant to steer developers away from heavy reliance on locking for thread coordination. There was concern that the use of so many locks would hurt performance.
