#include <cstring>
#include <cstdio>

struct string
{
public:
	int Length;
	const char* Buffer;

	string();
	string(const char* s);
	string(const string& s);
	string(int length, const char* s);
	char* cstr() const;
	string Substring(int start, int length);
};

string::string()
	: Length(0), Buffer(0)
{
}

string::string(const char* s)
	: Length(std::strlen(s)), Buffer(s)
{
}

string::string(const string& s)
	: Length(s.Length), Buffer(s.Buffer)
{
}

string::string(int length, const char* s)
	: Length(length), Buffer(s)
{
}

string string::Substring(int start, int length)
{
	return string(length, Buffer+start);
}

char* string::cstr() const
{
	auto buffer = new char[Length+1];
	std::memcpy(buffer, Buffer, Length);
	buffer[Length]=0;
	return buffer;
}

namespace System
{
	class Console
	{
	public:
		void Write(string value);
		void WriteLine(string value);
	};

	void Console::Write(string value)
	{
		std::printf("%.*s", value.Length, value.Buffer);
	}

	void Console::WriteLine(string value)
	{
		std::printf("%.*s\n", value.Length, value.Buffer);
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

			FileReader(string fileName);

		public:
			static FileReader* New_Open(string fileName);
			string ReadToEndSync();
		};

		FileReader::FileReader(string fileName)
		{
			auto fname = fileName.cstr();
			fopen_s(&file, fname, "r"); // TODO check error
			delete[] fname;
		}

		FileReader* FileReader::New_Open(string fileName)
		{
			return new FileReader(fileName);
		}

		string FileReader::ReadToEndSync()
		{
			std::fseek(file, 0, SEEK_END);
			auto length = std::ftell(file);
			std::fseek(file, 0, SEEK_SET);
			auto buffer = new char[length];
			length = fread(buffer, 1, length, file);
			return string(length, buffer);
		}
	}

	namespace Text
	{
		class StringBuilder
		{
		};
	}
}