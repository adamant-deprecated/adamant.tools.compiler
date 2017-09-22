using System.Collections.Generic;
using System.Text;

namespace Bootstrap.Transpiler
{
	public class Context
	{
		public readonly string Source;
		public string Token;
		public int NextTokenPosition;
		public readonly StringBuilder Output = new StringBuilder();
		public int IndentDepth { get; private set; }
		public bool AfterBlock { get; private set; }
		public readonly Dictionary<string, FunctionDefinition> Functions = new Dictionary<string, FunctionDefinition>(); 

		public Context(string source)
		{
			Source = source;
		}

		public void Error(string format, params object[] args)
		{
			Output.AppendFormat("<$ " + format + " $>", args);
		}

		public void BeginLine(string format, params object[] args)
		{
			if(AfterBlock)
			{
				Output.AppendLine();
				AfterBlock = false;
			}
			Output.Append(new string('\t', IndentDepth));
			Output.AppendFormat(format, args);
		}

		public void Write(string format, params object[] args)
		{
			Output.AppendFormat(format, args);
		}

		public void EndLine(string format, params object[] args)
		{
			Output.AppendFormat(format, args);
			Output.AppendLine();
		}

		public void WriteLine(string format, params object[] args)
		{
			if(AfterBlock)
			{
				Output.AppendLine();
				AfterBlock = false;
			}
			Output.Append(new string('\t', IndentDepth));
			Output.AppendFormat(format, args);
			Output.AppendLine();
		}

		public void BeginBlock()
		{
			WriteLine("{{");
			IndentDepth++;
		}

		public void EndBlock()
		{
			AfterBlock = false; // so that we don't put a blank line between two closing braces
			IndentDepth--;
			WriteLine("}}");
			AfterBlock = true;
		}
	}
}