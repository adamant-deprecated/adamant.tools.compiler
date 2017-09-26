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

		class FileWriter
		{
		private:
			std::FILE* file;

		public:
			FileWriter(const string& fileName);
			void Write(const string& value) const;
			void Close() const { std::fclose(file); }
		};
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
	}
}