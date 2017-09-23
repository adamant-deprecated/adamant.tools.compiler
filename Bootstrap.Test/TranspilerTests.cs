using System.Collections.Generic;
using System.IO;
using NUnit.Framework;

namespace Bootstrap.Transpiler.Test
{
	[TestFixture]
	public class TranspilerTests
	{
		[Test]
		[TestCaseSource(nameof(TranspileTestCases))]
		public void TranspileTest(string source, string expected)
		{
			var transpiler = new Transpiler();
			Assert.AreEqual(expected, transpiler.Transpile(source));
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
