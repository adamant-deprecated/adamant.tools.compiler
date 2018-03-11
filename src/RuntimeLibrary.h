// On windows this disables warnings about using fopen_s instead of fopen
// It must be defined before including the headers.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <cstdint>
#include <stdexcept>

template<typename T, typename F>
T LogicalAnd(T const & lhs, F rhs)
{
	return lhs.op_False().Value ? lhs : lhs.op_And(rhs());
}

template<typename T, typename F>
T LogicalOr(T const & lhs, F rhs)
{
	return lhs.op_True().Value ? lhs : lhs.op_Or(rhs());
}

struct p_bool
{
public:
	// Runtime Use Members
	bool Value;

	p_bool(): Value(false) {}
	p_bool(bool value): Value(value) {}
	p_bool * operator->() { return this; }
	p_bool const * operator->() const { return this; }
	p_bool & operator* () { return *this; }
	p_bool const & operator* () const { return *this; }

	// Adamant Members
	p_bool op_Not() const { return !this->Value; }
	p_bool op_True() const { return this->Value; }
	p_bool op_False() const { return !this->Value; }
	p_bool op_And(p_bool other) const { return this->Value & other.Value; }
	p_bool op_Or(p_bool other) const { return this->Value | other.Value; }
};

struct p_uint;

struct p_int
{
public:
	// Runtime Use Members
	std::int32_t Value;

	p_int(std::int32_t value): Value(value) {}
	p_int * operator->() { return this; }
	p_int const * operator->() const { return this; }
	p_int & operator* () { return *this; }
	p_int const & operator* () const { return *this; }

	// Hack to support conversion of uint to int for now
	p_int(p_uint value);

	// Adamant Members
	p_int(): Value(0) {}
	void op_AddAssign(p_int other) { this->Value += other.Value; }
	void op_SubtractAssign(p_int other) { this->Value -= other.Value; }
	p_bool op_Equal(p_int other) const { return this->Value == other.Value; }
	p_bool op_NotEqual(p_int other) const { return this->Value != other.Value; }
	p_bool op_LessThan(p_int other) const { return this->Value < other.Value; }
	p_bool op_LessThanOrEqual(p_int other) const { return this->Value <= other.Value; }
	p_bool op_GreaterThan(p_int other) const { return this->Value > other.Value; }
	p_bool op_GreaterThanOrEqual(p_int other) const { return this->Value >= other.Value; }
	p_int op_Add(p_int other) const { return this->Value + other.Value; }
	p_int op_Subtract(p_int other) const { return this->Value - other.Value; }
	p_int op_Negate() const { return -this->Value; }
	p_int op_Multiply(p_int other) const { return this->Value * other.Value; }
	p_int op_Divide(p_int other) const { return this->Value / other.Value; }
	p_int op_Remainder(p_int other) const { return this->Value % other.Value; }
	p_int op_Magnitude() const { if(this->Value==INT32_MIN) throw std::overflow_error("Can't take |int.Min|"); return this->Value < 0 ? -this->Value : this->Value; }

	// Hack because we don't support as correctly yet
	p_uint AsUInt_() const;
};

struct p_uint
{
public:
	// Runtime Use Members
	std::uint32_t Value;

	p_uint(std::uint32_t value): Value(value) {}
	p_uint * operator->() { return this; }
	p_uint const * operator->() const { return this; }
	p_uint & operator* () { return *this; }
	p_uint const & operator* () const { return *this; }

	// Hack to support conversion of int to uint for now
	p_uint(p_int value): Value(value.Value) {}

	// Adamant Members
	p_uint(): Value(0) {}
	void op_AddAssign(p_uint other) { this->Value += other.Value; }
	void op_SubtractAssign(p_uint other) { this->Value -= other.Value; }
	p_bool op_Equal(p_uint other) const { return this->Value == other.Value; }
	p_bool op_NotEqual(p_uint other) const { return this->Value != other.Value; }
	p_bool op_LessThan(p_uint other) const { return this->Value < other.Value; }
	p_bool op_LessThanOrEqual(p_uint other) const { return this->Value <= other.Value; }
	p_bool op_GreaterThan(p_uint other) const { return this->Value > other.Value; }
	p_bool op_GreaterThanOrEqual(p_uint other) const { return this->Value >= other.Value; }
	p_uint op_Add(p_uint other) const { return this->Value + other.Value; }
	p_uint op_Subtract(p_uint other) const { return this->Value - other.Value; }
};

inline p_int::p_int(p_uint value)
	: Value(value.Value)
{
}

struct p_code_point
{
private:
	std::uint32_t Value;

public:
	// Runtime Use Members
	p_code_point(): Value(0) {}
	p_code_point(char value): Value(value) {}
	p_code_point * operator->() { return this; }
	p_code_point const * operator->() const { return this; }
	p_code_point & operator* () { return *this; }
	p_code_point const & operator* () const { return *this; }
	char CharValue() const;

	// Adamant Members
	p_bool op_Equal(p_code_point const & other) const { return this->Value == other.Value; }
	p_bool op_NotEqual(p_code_point const & other) const { return this->Value != other.Value; }
	// TODO: Not sure code_point should support these operations
	p_bool op_LessThan(p_code_point other) const { return this->Value < other.Value; }
	p_bool op_LessThanOrEqual(p_code_point other) const { return this->Value <= other.Value; }
	p_bool op_GreaterThan(p_code_point other) const { return this->Value > other.Value; }
	p_bool op_GreaterThanOrEqual(p_code_point other) const { return this->Value >= other.Value; }

};

struct p_string
{
public:
	// Runtime Use Members
	char const * Buffer;
	int Length;

	p_string();
	p_string(char const * s);
	p_string(int length, char const * s);
	char const * cstr() const;
	p_string const * operator->() const { return this; }
	p_string const & operator* () const { return *this; }

	typedef char const * const_iterator;
	const_iterator begin() const { return &Buffer[0]; }
	const_iterator end() const { return &Buffer[Length]; }

	// Hack to support conversion of int and code_point to strings for now
	p_string(p_int other);
	p_string(p_code_point other);

	// Adamant Members
	// TODO ByteLength should be a property
	p_int ByteLength_() const { return this->Length; }

	p_string(p_code_point c, p_int repeat);

	p_string Substring_(p_int start, p_int length) const;
	p_string Substring_(p_int start) const { return Substring_(start, Length-start.Value); }
	p_string Replace_(p_string oldValue, p_string newValue) const;
	p_int LastIndexOf_(p_code_point c) const;
	p_int index_of_(p_code_point c) const;

	p_code_point op_Element(p_int const index) const { return Buffer[index.Value]; }
	p_string op_Add(p_string const & value) const;
	p_bool op_Equal(p_string const & other) const;
	p_bool op_NotEqual(p_string const & other) const { return !this->op_Equal(other).Value; }
	p_bool op_LessThan(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) < 0; }
	p_bool op_LessThanOrEqual(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) <= 0; }
	p_bool op_GreaterThan(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) > 0; }
	p_bool op_GreaterThanOrEqual(p_string other) const { return std::strcmp(this->cstr(), other.cstr()) >= 0; }
};

class ResourceManager
{
public:
	p_string const & GetString_(p_string resourceName);
	void AddResource(p_string name, p_string value);
};

extern ResourceManager *const resource_manager_;

class NoneType
{
public:
	template<class T>
	operator T*() const { return static_cast<T*>(0); }
};
static const NoneType None = NoneType();

template<typename T>
struct p_optional
{
private:
	bool hasValue;
	union
    {
        T data;
    };

public:
	p_optional(T const & value) : data(value), hasValue(true) {}
	p_optional(::NoneType const & none) : hasValue(false) {}
	T & operator->()
	{
		if(!hasValue) throw std::runtime_error("Access to `none` Optional value");
		return data;
	}
	T const & operator->() const
	{
		if(!hasValue) throw std::runtime_error("Access to `none` Optional value");
		return data;
	}
	T & operator* ()
	{
		if(!hasValue) throw std::runtime_error("Access to `none` Optional value");
		return data;
	}
	T const & operator* () const
	{
		if(!hasValue) throw std::runtime_error("Access to `none` Optional value");
		return data;
	}
};

// A placeholder function until we get proper exceptions implemented
_Noreturn inline void THROW_EXCEPTION_(const p_string& value)
{
	throw std::runtime_error(value.cstr());
}

inline void assert(const p_bool condition, const p_string code, const p_string file, const std::int32_t line)
{
	if(!condition.Value)
		throw std::runtime_error(
			p_string("Assertion failed: ").op_Add(code)
			.op_Add(p_string(", file ")).op_Add(file).op_Add(p_string(", line ")).op_Add(p_int(line)).cstr());
}

#define assert_(condition) assert(condition, #condition, __FILE__, __LINE__)

inline void assert_msg(const p_bool condition, const p_string code, const p_string message, const p_string file, const std::int32_t line)
{
	if(!condition.Value)
		throw std::runtime_error(
			p_string("Assertion failed: ").op_Add(code).op_Add(", ").op_Add(message)
			.op_Add(", file ").op_Add(file).op_Add(", line ").op_Add(p_int(line)).cstr());
}

#define assert_msg_(condition, message) assert(condition, #condition, message, __FILE__, __LINE__)

_Noreturn inline void NOT_IMPLEMENTED(const p_string function, const p_string file, const std::int32_t line)
{
	throw std::runtime_error(
		p_string("Function ").op_Add(function)
		.op_Add(p_string(" not yet implemented, ")).op_Add(file).op_Add(p_string(", line ")).op_Add(p_int(line)).cstr());
}

_Noreturn inline void NOT_IMPLEMENTED(const p_string message, const p_string function, const p_string file, const std::int32_t line)
{
	throw std::runtime_error(
		p_string("Function ").op_Add(function)
		.op_Add(p_string(" not yet implemented, ")).op_Add(message).op_Add(p_string(", ")).op_Add(file).op_Add(p_string(", line ")).op_Add(p_int(line)).cstr());
}

#define NOT_IMPLEMENTED_(...) NOT_IMPLEMENTED( __VA_ARGS__ __VA_OPT__(,) _func__, __FILE__, __LINE__)


_Noreturn inline void UNREACHABLE(const p_string function, const p_string file, const std::int32_t line)
{
	throw std::runtime_error(
		p_string("Reached \"UNREACHABLE\" statement in function ").op_Add(function)
		.op_Add(p_string(", ")).op_Add(file).op_Add(p_string(", line ")).op_Add(p_int(line)).cstr());
}

#define UNREACHABLE_(condition) UNIMPLEMENTED(__func__, __FILE__, __LINE__)

namespace system_
{
	namespace Collections_
	{
		template<typename T>
		class List_
		{
		private:
			T* values;
			int length;
			int capacity;

		public:
			// Runtime Use Members
			typedef T const * const_iterator;
			const_iterator begin() const { return values; }
			const_iterator end() const { return &values[length]; }

			// Adamant Members
			List_() : values(0), length(0), capacity(0) { }
			void Add_(T value) { add_(value); }
			void Clear_() { clear_(); }
			void add_(T value);
			void clear_() { length = 0; }
			p_int op_Magnitude() const { return length; }
			T const & op_Element(p_int const index) const;
		};

		template<typename T>
		void List_<T>::add_(T value)
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

		template<typename T>
		T const & List_<T>::op_Element(p_int const index) const
		{
			if(index.Value < 0 || index.Value >= length)
				throw std::out_of_range("List index out of bounds");
			return values[index.Value];
		}
	}

	namespace Console_
	{
		class Console_
		{
		public:
			void Write_(p_string value);
			void WriteLine_(p_string value);
			void WriteLine_();
		};

		class Arguments_
		{
		private:
			p_string* args;
		public:
			// Runtime Use Members
			typedef p_string const * const_iterator;

			Arguments_(int argc, char const *const * argv);
			const_iterator begin() const { return &args[0]; }
			const_iterator end() const { return &args[Count]; }

			const int Count;

			// Adamant Members

			p_int op_Magnitude() const { return Count; }
			p_string const & Get_(int const index) const { return args[index]; }
		};
	}

	namespace IO_
	{
		class File_Reader_
		{
		private:
			std::FILE* file;

		public:
			File_Reader_(const p_string& fileName);
			p_string ReadToEndSync_();
			void Close_();
		};

		class File_Writer_
		{
		private:
			std::FILE* file;

		public:
			File_Writer_(const p_string& fileName);
			void Write_(const p_string& value);
			void Close_();
		};
	}

	namespace Text_
	{
		class String_Builder_
		{
		private:
			p_string buffer;
		public:
			String_Builder_();
			String_Builder_(p_string const & value);
			void Append_(p_string const & value);
			void Append_(String_Builder_ const * value);
			void AppendLine_(p_string const& value);
			void AppendLine_();
			void Remove_(p_int start, p_int length);
			void Remove_(p_int start);
			p_string ToString_() const { return buffer; }
		};
	}
}

namespace System_ = system_;
