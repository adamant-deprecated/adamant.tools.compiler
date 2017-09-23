using System;
using System.IO;

namespace Bootstrap.Transpiler
{
	public static class Program
	{
		public static void Main(string[] args)
		{
			Console.WriteLine("Adamant Compiler v0.1.0");
			if(args.Length != 1)
			{
				Console.WriteLine("Must pass a single argument of the source file");
				return;
			}
			var fileName = args[0];
			Console.Write("Compiling: ");
			Console.WriteLine(fileName);
			string source;
			using(var file = File.OpenText(fileName))
			{
				source = file.ReadToEnd();
			}

			var transpiler = new Transpiler();
			var translated = transpiler.Transpile(source);
			using(var file = File.CreateText(Path.ChangeExtension(fileName, "cpp")))
			{
				file.Write(translated);
			}
		}
	}
}
