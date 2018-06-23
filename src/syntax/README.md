# `adamant.tools.compiler.syntax`

The syntax is represented as a concrete syntax tree composed of strongly typed syntax tokens (`Token`) and syntax nodes (`Syntax_Node`). Both of these are unified as syntax (`Syntax`). These form a tree which exists in reference to some source code (`Source_Text`). The syntax and source code taken together are a concrete syntax tree (`Syntax_Tree`).
