using System.Collections.Generic;
using System.IO;
using NUnit.Framework;

namespace Bootstrap.Transpiler.Test
{
	[TestFixture]
	public class ParserTests
	{
		[Test]
		[TestCaseSource(nameof(TranspileTestCases))]
		public void TranspileTest(string source, string expected)
		{
			Assert.AreEqual(expected, Parser.Transpile(source));
		}

		private static IEnumerable<TestCaseData> TranspileTestCases()
		{
			foreach(var fileName in Directory.EnumerateFiles(@"..\..\..\test-cases", "*.ad"))
			{
				string source;
				string expected;
				using(var file = File.OpenText(fileName))
				{
					source = file.ReadToEnd();
				}
				using(var file = File.OpenText(Path.ChangeExtension(fileName, "cpp")))
				{
					expected = file.ReadToEnd();
				}
				yield return new TestCaseData(source, expected).SetName(Path.GetFileName(fileName));
			}
		}
	}
}
