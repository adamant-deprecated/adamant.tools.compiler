# adamant.tools.compiler.semantics.names

Names provide a way of referring to any declared name in a program. They can be used to find parts of the semantic tree by traversing the symbols. Names may be specific enough to select out a single item or may be general so that multiple items match. For example, a method name may match all overloads of a method, or it may provide an arity so it matches only overloads with the given arity, or it may name the argument types so that it matches only a specific overload.

Note that names include information about generic type parameters since `Class<T>` is a distinct name from `Class`.
