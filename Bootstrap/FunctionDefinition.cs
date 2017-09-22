namespace Bootstrap.Transpiler
{
	public class FunctionDefinition
	{
		public readonly string Name;
		public readonly string ReturnType;

		public FunctionDefinition(string name, string returnType)
		{
			Name = name;
			ReturnType = returnType;
		}
	}
}