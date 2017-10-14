// On windows this disables warnings about using fopen_s instead of fopen
// It must be defined before including the headers.  The includes have been moved
// here to avoid leaking this into the program being compiled.  This required the
// use of void* instead of FILE* in some places.
#define _CRT_SECURE_NO_WARNINGS
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
	namespace Collections
	{
		template<typename T>
		class List
		{
		private:
			T* values;
			int length;
			int capacity;
			//std::vector<T> values;
		public:
			typedef T const * const_iterator;

			List() : values(0), length(0), capacity(0) { }
			void Add(T value);// { values.push_back(value); }
			int Length() { return length; }//{ return values.size(); }
			const_iterator begin() const { return values; }
			const_iterator end() const { return &values[length]; }
			T const & Get(int const index) const { return values[index]; }
		};

		template<typename T>
		void List<T>::Add(T value)
		{
			if(length >= capacity)
			{
				int newCapacity = capacity == 0 ? 16 : capacity * 2;
				T* newValues = new T[newCapacity];
				std::memcpy(newValues, values, length * sizeof(T));
				values = newValues;
				capacity = newCapacity;
			}
			values[length] = value;
			length++;
		}
	}

	namespace Console
	{
		class Console
		{
		public:
			void Write(string value);
			void WriteLine(string value);
			void WriteLine();
		};

		class Arguments
		{
		private:
			string* args;
		public:
			typedef string const * const_iterator;
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
			void Close();
		};

		class FileWriter
		{
		private:
			std::FILE* file;

		public:
			FileWriter(const string& fileName);
			void Write(const string& value);
			void Close();
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
