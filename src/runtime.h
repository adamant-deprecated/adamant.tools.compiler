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

class NoneType
{
public:
	template<class T>
	operator T*() const { return static_cast<T*>(0); }
};
static const NoneType None = NoneType();

template<typename T>
struct Maybe
{
private:
	T data;
	bool hasValue;

public:
	Maybe(T const & value) : data(value), hasValue(true) {}
	Maybe(::NoneType const & none) : hasValue(false) {}
	T& operator->() { return data; }
	T const & operator->() const
	{
		if(!hasValue) throw "Access to null Maybe value";
		return data;
	}
	T  & operator* ()
	{
		if(!hasValue) throw "Access to null Maybe value";
		return data;
	}
	T const & operator* () const
	{
		if(!hasValue) throw "Access to null Maybe value";
		return data;
	}
	bool operator==(T const & other) const
	{
		return hasValue && data == other;
	}
	bool operator!=(T const & other) const
	{
		return hasValue && data != other;
	}
};

namespace System
{
	namespace Console
	{
		class Console
		{
		public:
			void Write(string value);
			void WriteLine(string value);
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

	namespace IO
	{
		class FileReader
		{
		private:
			std::FILE* file;

		public:
			FileReader(const string& fileName);
			string ReadToEndSync();
			void Close() { std::fclose(file); }
		};

		class FileWriter
		{
		private:
			std::FILE* file;

		public:
			FileWriter(const string& fileName);
			void Write(const string& value);
			void Close() { std::fclose(file); }
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