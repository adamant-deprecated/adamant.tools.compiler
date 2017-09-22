using System;
using System.Web;

namespace Bootstrap.Transpiler
{
	public static class Lexer
	{
		public static void ReadFirstToken(Context c)
		{
			if(c.NextTokenPosition != 0)
				throw new NotSupportedException("Can't read first token of context that already has tokens read.");

			ReadToken(c);
		}

		private static void ReadToken(Context c)
		{
			var position = c.NextTokenPosition;
			var tokenEnd = -1;
			while(position < c.Source.Length)
			{
				var curChar = c.Source[position];
				switch(curChar)
				{
					case ' ':
					case '\t':
					case '\n':
					case '\r':
						position += 1;
						continue;
					case '{':
					case '}':
					case '(':
					case ')':
					case ';':
						tokenEnd = position + 1;
						goto done;
					case '-':
						if(position + 1 < c.Source.Length && c.Source[position + 1] == '>')
						{
							// it is `->`
							tokenEnd = position + 2;
							goto done;
						}
						// it is `-`
						tokenEnd = position + 1;
						goto done;
					default:
						if(IsIdentifierChar(curChar))
						{
							tokenEnd = position + 1;
							while(IsIdentifierChar(c.Source[tokenEnd]))
								tokenEnd++;
							goto done;
						}
						if(IsNumberChar(curChar))
						{
							tokenEnd = position + 1;
							while(IsNumberChar(c.Source[tokenEnd]))
								tokenEnd++;
							goto done;
						}
						c.Error("Invalid character '{0}'", HttpUtility.JavaScriptStringEncode(curChar.ToString()));
						position += 1;
						break;
				}
			}

			done:
			if(tokenEnd == -1)
			{
				c.Token = null;
				c.NextTokenPosition = position;
			}
			else
			{
				c.Token = c.Source.Substring(position, tokenEnd - position);
				c.NextTokenPosition = tokenEnd;
			}
		}

		private static bool IsIdentifierChar(char c)
		{
			return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
		}

		private static bool IsNumberChar(char c)
		{
			return c >= '0' && c <= '9';
		}

		public static bool Accept(Context c, string expected)
		{
			var accepted = c.Token == expected;
			if(accepted)
				ReadToken(c);

			return accepted;
		}

		public static void Expect(Context c, string expected)
		{
			if(c.Token != expected)
			{
				c.Error("Expected '{0}' but found '{1}'", expected, c.Token);
			}
			else
				ReadToken(c);
		}

		public static string ExpectIdentifier(Context c)
		{
			foreach(var @char in c.Token)
				if(!IsIdentifierChar(@char))
				{
					c.Error("Expected identifier, found '{0}'", HttpUtility.JavaScriptStringEncode(c.Token));
					return "<missing>";
				}

			var identifier = c.Token;
			ReadToken(c);
			return identifier;
		}

		public static string ExpectType(Context c)
		{
			foreach(var @char in c.Token)
				if(!IsIdentifierChar(@char))
				{
					c.Error("Expected type, found '{0}'", HttpUtility.JavaScriptStringEncode(c.Token));
					return "<missing>";
				}

			var identifier = c.Token;
			ReadToken(c);
			return identifier;
		}

		public static string ExpectNumber(Context c)
		{
			foreach(var @char in c.Token)
				if(!IsNumberChar(@char))
				{
					c.Error("Expected number, found '{0}'", HttpUtility.JavaScriptStringEncode(c.Token));
					return "<missing>";
				}

			var number = c.Token;
			ReadToken(c);
			return number;
		}
	}
}
