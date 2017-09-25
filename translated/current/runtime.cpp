#include <cstring>
#include <cstdio>

struct string
{
public:
	int Length;
	const char* Buffer;

	string();
	string(char c, int repeat);
	string(const char* s);
	string(int length, const char* s);
	char* cstr() const;
	string Substring(int start, int length) const;
	string Replace(string oldValue, string newValue) const;
	char operator[] (const int index) const;
	string operator+(const string& value) const;
	string operator+(const char& value) const;
	const string* operator->() const { return this; }
	const string& operator* () const { return *this; }
	bool operator==(const string &other) const;
	bool operator!=(const string &other) const { return !(*this == other); }

	typedef const char* const_iterator;
	const_iterator begin() const { return &Buffer[0]; }
	const_iterator end() const { return &Buffer[Length]; }
};

string::string()
	: Length(0), Buffer(0)
{
}

string::string(char c, int repeat)
	: Length(repeat)
{
	char* buffer = new char[repeat];
	for (int i = 0; i < repeat; i++)
		buffer[i] = c;

	Buffer = buffer;
}

string::string(const char* s)
	: Length(std::strlen(s)), Buffer(s)
{
}

string::string(int length, const char* s)
	: Length(length), Buffer(s)
{
}

char* string::cstr() const
{
	auto buffer = new char[Length + 1];
	std::memcpy(buffer, Buffer, Length);
	buffer[Length] = 0;
	return buffer;
}

string string::Substring(int start, int length) const
{
	return string(length, Buffer + start);
}

string string::Replace(string oldValue, string newValue) const
{
	string buffer = "";
	int limit = Length - oldValue.Length + 1;
	int lastIndex = 0;
	for(int i=0; i < limit; i++)
		if (Substring(i, oldValue.Length) == oldValue)
		{
			buffer = buffer + Substring(lastIndex, i-lastIndex) + newValue;
			i += oldValue.Length; // skip over the value we just matched
			lastIndex = i;
			i--; // we need i-- to offset the i++ that is about to happen
		}

	buffer = buffer + Substring(lastIndex, Length - lastIndex);
	return buffer;
}

char string::operator[] (const int index) const
{
	return Buffer[index];
}

string string::operator+(const string& value) const
{
	int newLength = Length + value.Length;
	char* chars = new char[newLength];
	size_t offset = sizeof(char)*Length;
	std::memcpy(chars, Buffer, offset);
	std::memcpy(chars + offset, value.Buffer, value.Length);
	return string(newLength, chars);
}

string string::operator+(const char& value) const
{
	int newLength = Length + 1;
	char* chars = new char[newLength];
	size_t offset = sizeof(char)*Length;
	std::memcpy(chars, Buffer, offset);
	chars[Length] = value;
	return string(newLength, chars);
}

bool string::operator==(const string &other) const
{
	if (Length != other.Length)
		return false;

	for (int i = 0; i < Length; i++)
		if (Buffer[i] != other.Buffer[i])
			return false;

	return true;
}

namespace System
{
	namespace Console
	{
		class Console
		{
		public:
			// TODO the const here is a hack until we have proper mutability
			void Write(string value) const;
			void WriteLine(string value) const;
		};

		void Console::Write(string value) const
		{
			std::printf("%.*s", value.Length, value.Buffer);
		}

		void Console::WriteLine(string value) const
		{
			std::printf("%.*s\n", value.Length, value.Buffer);
		}

		class Arguments
		{
		private:
			string* args;
		public:
			typedef const string* const_iterator;
			const int Count;

			Arguments(int argc, const char * argv[]);
			const_iterator begin() const { return &args[0]; }
			const_iterator end() const { return &args[Count]; }
			const string& Get(const int index) const { return args[index]; }
		};

		Arguments::Arguments(int argc, const char * argv[])
			: Count(argc-1)
		{
			args = new string[Count];
			for (int i = 0; i < Count; i++)
				args[i] = string(argv[i+1]);
		}
	}

	namespace Collections
	{
		template<typename T>
		class Array
		{
		private:
			T* data;

		public:
			const int Count;

			Array(int capacity);
			T operator [](int i) const { return data[i]; }
			T& operator [](int i) { return data[i]; }
		};

		template<typename T>
		Array<T>::Array(int capacity)
			: Count(capacity), data(new T[capacity])
		{
		}
	}

	namespace IO
	{
		class FileReader
		{
		private:
			std::FILE* file;

		public:
			FileReader(const string& fileName);
			string ReadToEndSync() const;
			void Close() const { std::fclose(file); }
		};

		FileReader::FileReader(const string& fileName)
		{
			auto fname = fileName.cstr();
			fopen_s(&file, fname, "rb");
			delete[] fname;
		}

		string FileReader::ReadToEndSync() const
		{
			std::fseek(file, 0, SEEK_END);
			auto length = std::ftell(file);
			std::fseek(file, 0, SEEK_SET);
			auto buffer = new char[length];
			length = std::fread(buffer, sizeof(char), length, file);
			return string(length, buffer);
		}

		class FileWriter
		{
		private:
			std::FILE* file;

		public:
			FileWriter(const string& fileName);
			void Write(const string& value) const;
			void Close() const { std::fclose(file); }
		};

		FileWriter::FileWriter(const string& fileName)
		{
			auto fname = fileName.cstr();
			fopen_s(&file, fname, "wb"); // TODO check error
			delete[] fname;
		}

		void FileWriter::Write(const string& value) const
		{
			std::fwrite(value.Buffer, sizeof(char), value.Length, file);
		}
	}

	namespace Text
	{
		class StringBuilder
		{
		private:
			string buffer;
		public:
			StringBuilder();
			StringBuilder(const string& value);
			void Append(const string& value);
			void AppendLine(const string& value);
			void AppendLine();
			string ToString() const { return buffer; }
		};

		StringBuilder::StringBuilder(const string& value)
			: buffer(value)
		{
		}

		StringBuilder::StringBuilder()
			: buffer("")
		{
		}

		void StringBuilder::Append(const string& value)
		{
			buffer = buffer + value;
		}

		void StringBuilder::AppendLine(const string& value)
		{
			buffer = buffer + value + string("\r\n");
		}

		void StringBuilder::AppendLine()
		{
			buffer = buffer + string("\r\n");
		}
	}
}