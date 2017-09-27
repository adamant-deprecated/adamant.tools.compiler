#include <cstring>
#include <cstdio>

struct string
{
public:
	int Length;
	char const * Buffer;

	string();
	string(char c, int repeat);
	string(char const * s);
	string(int length, char const * s);
	char const * cstr() const;
	string Substring(int start, int length) const;
	string Replace(string oldValue, string newValue) const;
	char operator[] (int const index) const;
	string operator+(string const & value) const;
	string operator+(char const & value) const;
	string const * operator->() const { return this; }
	string const & operator* () const { return *this; }
	bool operator==(string const & other) const;
	bool operator!=(string const & other) const { return !(*this == other); }

	typedef char const * const_iterator;
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

			Arguments(int argc, char const *const * argv);
			const_iterator begin() const { return &args[0]; }
			const_iterator end() const { return &args[Count]; }
			string const & Get(int const index) const { return args[index]; }
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
			StringBuilder(string const & value);
			void Append(string const & value);
			void AppendLine(string const& value);
			void AppendLine();
			string ToString() const { return buffer; }
		};
	}
}