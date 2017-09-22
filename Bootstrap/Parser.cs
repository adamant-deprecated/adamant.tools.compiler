namespace Bootstrap.Transpiler
{
	public static class Parser
	{
		public static void ParseDeclaration(Context c)
		{
			Lexer.Expect(c, "let");
			var name = Lexer.ExpectIdentifier(c);
			Lexer.Expect(c, ":");
			var type = Lexer.ExpectType(c);
			Lexer.Expect(c, ";");
			// TODO emit the variable
		}

		public static void ParseExpression(Context c)
		{
			var number = Lexer.ExpectNumber(c);
			c.Write(number);
		}

		public static bool ParseStatement(Context c)
		{
			if(Lexer.Accept(c, "return"))
			{
				if(Lexer.Accept(c, ";"))
					c.WriteLine("return;");
				else
				{
					c.BeginLine("return ");
					ParseExpression(c);
					Lexer.Expect(c, ";");
					c.EndLine(";");
				}
			}

			return false;
		}

		public static void ParseBlock(Context c)
		{
			Lexer.Expect(c, "{");
			c.BeginBlock();
			while(ParseStatement(c)) ;
			Lexer.Expect(c, "}");
			c.EndBlock();
		}

		public static void ParseFunction(Context c)
		{
			var name = Lexer.ExpectIdentifier(c);
			Lexer.Expect(c, "(");
			//for(;;)
			//{
			//	//if(!ParseArgument())
			//	//	break;
			//}
			Lexer.Expect(c, ")");
			Lexer.Expect(c, "->");
			var returnType = Lexer.ExpectType(c);
			c.WriteLine("// {0}() -> {1}", name, returnType);
			c.WriteLine("{1} {0}()", name, returnType);
			c.Functions.Add(name, new FunctionDefinition(name, returnType));
			ParseBlock(c);
		}

		public static void ParseProgram(Context c)
		{
			/*loop
			{
				if token == "<EOF>"
					{ return; }

				if token == "let"
					{ ParseDeclaration(); }*/

			ParseFunction(c);
			//}

			c.WriteLine("// Entry Point Adapter");
			c.WriteLine("int main(int argc, const char * argv[])");
			c.BeginBlock();
			var mainFunction = c.Functions["Main"];
			if(mainFunction.ReturnType == "void")
			{
				c.WriteLine("Main();");
				c.WriteLine("return 0;");
			}
			else
				c.WriteLine("return Main();");
			c.EndBlock();
		}

		public static string Transpile(string source)
		{
			var c = new Context(source);
			Lexer.ReadFirstToken(c);
			ParseProgram(c);
			return c.Output.ToString();
		}
	}
}
