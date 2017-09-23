using System;
using System.IO;

namespace Bootstrap.Transpiler
{
	public static class Program
	{
		public static void Main(string[] args)
		{
			Console.WriteLine("Adamant Compiler v0.1.0");
			if(args.Length != 2)
			{
				Console.WriteLine("Args: <Input File> <OutputFile>");
				return;
			}
			var inputFile = args[0];
			Console.Write("Compiling: ");
			Console.WriteLine(inputFile);
			string source;
			using(var file = File.OpenText(inputFile))
			{
				source = file.ReadToEnd();
			}

			var transpiler = new Transpiler();
			var translated = transpiler.Transpile(source);
			var outputFile = args[1];
			Console.Write("Output: ");
			Console.WriteLine(outputFile);
			using(var file = File.CreateText(outputFile))
			{
				file.Write(translated);
			}
		}
	}
}
