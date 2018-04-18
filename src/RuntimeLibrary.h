// On windows this disables warnings about using fopen_s instead of fopen
// It must be defined before including the headers.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <cstdint>
#include <stdexcept>
#include <string>


// -----------------------------------------------------------------------------
// Utility Types
// -----------------------------------------------------------------------------
// Utility types that help ensure proper use of C++

// A base class for all structs that prevents the default special members
struct Struct_Base
{
protected:
	Struct_Base() noexcept {}
	Struct_Base(Struct_Base const & other) = delete;
};

// A base class for all classes that prevents the default special members
// and ensures a virutal destructor
class Class_Base
{
protected:
	Class_Base() noexcept {}
	Class_Base(Class_Base const & other) = delete;
public:
	virtual ~Class_Base() noexcept = default;
};

template<typename T>
struct Optional final: Struct_Base
{
private:
	bool has_value;
	union
	{
		char dummy;
		T value;
	};

public:
	Optional() : has_value(false) {}
	Optional(T&& value) : has_value(true) { new (&value) T(std::move(value)); }

	T & operator->()
	{
		if(!has_value) throw std::runtime_error("Access to empty Optional value");
		return &value;
	}
	T const & operator->() const
	{
		if(!has_value) throw std::runtime_error("Access to empty Optional value");
		return &value;
	}
	T & operator* ()
	{
		if(!has_value) throw std::runtime_error("Access to empty Optional value");
		return &value;
	}
	T const & operator* () const
	{
		if(!has_value) throw std::runtime_error("Access to empty Optional value");
		return &value;
	}

	~Optional()
	{
		if(has_value) (&value)->~T();
	}
};


// -----------------------------------------------------------------------------
// Runtime Types
// -----------------------------------------------------------------------------
// Types used to model the language semantics

struct Borrows;

/// Reference to the borrows tracker of a value
struct Borrows_Ref final: Struct_Base
{
private:
	Borrows *_Nullable borrows;

	Borrows_Ref(Borrows *_Nullable borrows): borrows(borrows) {}
	static auto own() -> Borrows_Ref { return Borrows_Ref(0); }

public:
	Borrows_Ref(Borrows_Ref&& other): borrows(other.borrows) {}

	friend struct Borrows;
};

/// Tracks borrows at runtime
struct Borrows final: Struct_Base
{
private:
	const std::uint32_t Writing = UINT32_MAX;
	std::uint32_t borrows = 0;

public:
	Borrows() noexcept {}
	auto take_mut(char const *_Nonnull kind) -> Borrows_Ref;
	auto take(char const *_Nonnull kind) -> Borrows_Ref;
	auto borrow_mut(char const *_Nonnull kind) -> Borrows_Ref;
	auto borrow(char const *_Nonnull kind) -> Borrows_Ref;
	auto destruct(char const *_Nonnull kind) -> void;
};

template<typename T>
struct ref_mut;

template<typename T>
struct ref;

template<typename T>
struct ref_own final: Struct_Base
{
private:
	T *_Nonnull value;
	Borrows mutable borrows;

	// Must be constructed through alloc()
	ref_own(T *_Nonnull other): value(other) {}

public:
	// no default constructor
	ref_own() = delete;

	// no copy constructor
	ref_own(ref_own<T> const & other) = delete;

	// default move constructor
	ref_own(ref_own<T>&& other) noexcept = default;

	// no copy assignment operator
	ref_own<T>& operator=(ref_own<T> const& other) = delete;

	// default move assignment operator
	ref_own<T>& operator=(ref_own<T>&& other) noexcept = default;

	// allocate a new owned object. NOT INITALIZED
	// Note: this calls the default constructor because we have to setup the vtable
	static auto alloc() -> ref_own<T> { return ref_own(new T()); }

	auto take_mut() const -> ref_mut<T>
	{
		return ref_mut<T>(borrows.take_mut("owned reference"), value);
	}
	auto take() const -> ref<T>
	{
		return ref<T>(borrows.take("owned reference"), value);
	}
	auto borrow_mut() const -> ref_mut<T>
	{
		return ref_mut<T>(borrows.borrow_mut("owned reference"), value);
	}
	auto borrow() const -> ref<T>
	{
		return ref<T>(borrows.borrow("owned reference"), value);
	}

	~ref_own<T>()
	{
		borrows.destruct("owned reference");
		delete value;
	}
};

enum Binding_State
{
	Uninitialized,
	Initialized,
	Moved
};

template<typename T>
struct Binding final: Struct_Base
{
private:
	Optional<T> value;
	Binding_State binding_state = Binding_State::Uninitialized;
	Borrows borrows;
	// Take the value, potentially leaving in a bad state
	auto steal_value() -> T;

public:
	Binding() {}
	Binding(T&& other): value(std::move(other)) {}
	Binding(Binding<T>&& other): value(other.steal_value()) {}
	// Move or copy (if implicitly copyable) value out of binding
	auto move_value() -> T;
};

template<typename T>
auto Binding<T>::move_value() -> T
{
	if(binding_state == Binding_State::Uninitialized)
		throw std::runtime_error("Can't access a binding before it is initialized");
	if(binding_state == Binding_State::Moved)
		throw std::runtime_error("Can't access moved value");

	if(T::ImplicitCopy)
	{
		return T::copy(*value);
	}
	else
	{
		binding_state = Binding_State::Moved;
		return std::move(value);
	}
}

template<typename T>
struct var final: Struct_Base
{
public:
	// default constructor
	var() = default;

	// var(T&& value): value(value) {}
};

template<typename T>
struct let final: Struct_Base
{
private:
	Binding<T> binding;
public:
	let() {};
	explicit let(let<T>& other): binding(other.move_value()) {}
	let(T&& other): binding(std::move(other)) {}
	auto move_value() -> T { return binding.move_value(); }

	// let(let<T>&& other): binding<T>((T)other) {}
	// let(let<T>& other): binding<T>((T)other) {}
	// no copy constructor
	// let(let<T> const & other): base(other.value()) {}

	// // default move constructor
	// let(let<T>&& other) noexcept = default;

	// // no copy assignment operator
	// let<T>& operator=(let<T> const& other) = delete;

	// // default move assignment operator
	// let<T>& operator=(let<T>&& other) noexcept = default;

	// This is the strange syntax for a move conversion operator
	operator T() && { return binding.move_value(); }

	// template<typename U>
	// auto op_equal(U other) const -> decltype(binding<T const>::get_value().op_equal(other)) { return binding<T const>::get_value().op_equal(other); }
};

/// a mutable borrow
template<typename T>
struct ref_mut final: Struct_Base
{
private:
	std::uint32_t mutable *_Nullable borrows;
	T *_Nonnull value;
	ref_mut(std::uint32_t *_Nullable borrows, T *_Nonnull value): borrows(borrows), value(value) {}

public:
	// no default constructor
	ref_mut() = delete;

	// no copy constructor
	ref_mut(ref_mut<T> const & other) = delete;

	// default move constructor
	ref_mut(ref_mut<T>&& other) noexcept = default;

	// no copy assignment operator
	ref_mut<T>& operator=(ref_mut<T> const& other) = delete;

	// default move assignment operator
	ref_mut<T>& operator=(ref_mut<T>&& other) noexcept;

	ref_mut(ref_own<T>&& other) { return other.take_mut(); }
	ref_mut(ref_own<T>& other) { return other.borrow_mut(); }

	friend struct ::ref_own<T>;
};

/// a non-mutable borrow
template<typename T>
struct ref: Struct_Base
{
private:
	std::uint32_t mutable *_Nullable borrows;
	T const *_Nonnull value;
	ref(std::uint32_t *_Nullable borrows, T *_Nonnull value): borrows(borrows), value(value) {}

public:
	ref(ref_own<T>&& other) { return other.take(); }
	ref(ref_own<T>& other) { return other.borrow(); }

	template<typename U>
	auto op_equal(U other) const -> decltype(value->op_equal(other)) { return value->op_equal(other); }

	friend struct ::ref_own<T>;
};

// -----------------------------------------------------------------------------
// Logical Operators
// -----------------------------------------------------------------------------
// Use special templates taking closures to support short circuit evaluation

template<typename T, typename F>
T op_and(T const & lhs, F rhs)
{
	return lhs.op_false().value ? lhs : lhs.op_and(rhs());
}

template<typename T, typename F>
T op_or(T const & lhs, F rhs)
{
	return lhs.op_true().value ? lhs : lhs.op_or(rhs());
}

// -----------------------------------------------------------------------------
// Primitive Types
// -----------------------------------------------------------------------------

class None
{
public:
	template<class T>
	operator T*_Nullable() const { return static_cast<T*>(0); }
};
static const None p_none = None();

template<typename T>
struct p_optional final: Struct_Base
{
private:
	bool hasValue;
	union
    {
        T data;
    };

public:
	p_optional(T const & value) : data(value), hasValue(true) {}
	p_optional(None const none) : hasValue(false) {}
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

struct p_bool
{
public:
	// Runtime Members
	bool value;

	p_bool() = default;
	p_bool(bool value): value(value) {}
	p_bool& operator=(p_bool const& value) = default;

	p_bool *_Nonnull operator->() { return this; }
	p_bool const *_Nonnull operator->() const { return this; }
	p_bool & operator* () { return *this; }
	p_bool const & operator* () const { return *this; }

	// Adamant Members
	static auto construct() -> p_bool { return p_bool(false); }
	p_bool op_not() const { return !this->value; }
	p_bool op_true() const { return this->value; }
	p_bool op_false() const { return !this->value; }
	p_bool op_and(p_bool other) const { return this->value & other.value; }
	p_bool op_or(p_bool other) const { return this->value | other.value; }
	p_bool op_equal(p_bool other) const { return this->value == other.value; }
	p_bool op_not_equal(p_bool other) const { return this->value != other.value; }
};

struct p_uint;

struct p_int
{
public:
	// Runtime Use Members
	static const bool ImplicitCopy = true;
	std::int32_t value;

	p_int() = default;
	p_int(std::int32_t value): value(value) {}

	p_int *_Nonnull operator->() { return this; }
	p_int const *_Nonnull operator->() const { return this; }
	p_int & operator* () { return *this; }
	p_int const & operator* () const { return *this; }

	// Hack to support conversion of uint to int for now
	p_int(p_uint value);

	// Adamant Members
	static auto construct() -> p_int { return 0; }
	static auto copy(p_int const & other) -> p_int { return other; }
	void op_add_assign(p_int other) { this->value += other.value; }
	void op_subtract_assign(p_int other) { this->value -= other.value; }
	p_bool op_equal(p_int other) const { return this->value == other.value; }
	p_bool op_not_equal(p_int other) const { return this->value != other.value; }
	p_bool op_less_than(p_int other) const { return this->value < other.value; }
	p_bool op_less_than_or_equal(p_int other) const { return this->value <= other.value; }
	p_bool op_greater_than(p_int other) const { return this->value > other.value; }
	p_bool op_greater_than_or_equal(p_int other) const { return this->value >= other.value; }
	p_int op_add(p_int other) const { return this->value + other.value; }
	p_int op_subtract(p_int other) const { return this->value - other.value; }
	p_int op_negate() const { return -this->value; }
	p_int op_multiply(p_int other) const { return this->value * other.value; }
	p_int op_divide(p_int other) const { return this->value / other.value; }
	p_int op_remainder(p_int other) const { return this->value % other.value; }
	p_int op_magnitude() const { if(this->value==INT32_MIN) throw std::overflow_error("Can't take |int.Min|"); return this->value < 0 ? -this->value : this->value; }

	// Hack because we don't support as correctly yet
	p_uint AsUInt_() const;
};

struct p_uint
{
public:
	// Runtime Use Members
	std::uint32_t value;

	p_uint() = default;
	p_uint(std::uint32_t value): value(value) {}

	p_uint *_Nonnull operator->() { return this; }
	p_uint const *_Nonnull operator->() const { return this; }
	p_uint & operator* () { return *this; }
	p_uint const & operator* () const { return *this; }

	// Hack to support conversion of int to uint for now
	p_uint(p_int value): value(value.value) {}

	// Adamant Members
	static auto construct() -> p_uint { return 0; }
	void op_add_assign(p_uint other) { this->value += other.value; }
	void op_subtract_assign(p_uint other) { this->value -= other.value; }
	p_bool op_equal(p_uint other) const { return this->value == other.value; }
	p_bool op_not_equal(p_uint other) const { return this->value != other.value; }
	p_bool op_less_than(p_uint other) const { return this->value < other.value; }
	p_bool op_less_than_or_equal(p_uint other) const { return this->value <= other.value; }
	p_bool op_greater_than(p_uint other) const { return this->value > other.value; }
	p_bool op_greater_than_or_equal(p_uint other) const { return this->value >= other.value; }
	p_uint op_add(p_uint other) const { return this->value + other.value; }
	p_uint op_subtract(p_uint other) const { return this->value - other.value; }
};

inline p_int::p_int(p_uint value)
	: value(value.value)
{
}

struct p_code_point
{
private:
	std::uint32_t value;

public:
	// Runtime Use Members
	p_code_point() = default;
	p_code_point(char value): value(value) {}
	char CharValue() const;

	p_code_point *_Nonnull operator->() { return this; }
	p_code_point const *_Nonnull operator->() const { return this; }
	p_code_point & operator* () { return *this; }
	p_code_point const & operator* () const { return *this; }

	// Adamant Members
	static auto construct() -> p_code_point { return '\0'; }
	p_bool op_equal(p_code_point const & other) const { return this->value == other.value; }
	p_bool op_not_equal(p_code_point const & other) const { return this->value != other.value; }
	// TODO: Not sure code_point should support these operations
	p_bool op_less_than(p_code_point other) const { return this->value < other.value; }
	p_bool op_less_than_or_equal(p_code_point other) const { return this->value <= other.value; }
	p_bool op_greater_than(p_code_point other) const { return this->value > other.value; }
	p_bool op_greater_than_or_equal(p_code_point other) const { return this->value >= other.value; }

};

struct p_string
{
public:
	// Runtime Use Members
	char const *_Nonnull Buffer;
	int Length;

	p_string() = default;
	p_string(char const *_Nonnull s);
	p_string(int length, char const *_Nonnull s);
	char const *_Nonnull cstr() const;
	p_string const *_Nonnull operator->() const { return this; }
	p_string const & operator* () const { return *this; }

	typedef char const *_Nonnull const_iterator;
	const_iterator begin() const { return &Buffer[0]; }
	const_iterator end() const { return &Buffer[Length]; }

	// Hack to support conversion of int and code_point to strings for now
	p_string(p_int other);
	p_string(p_code_point other);

	// Adamant Members
	static auto construct() -> p_string { p_string self; self.Length = 0; self.Buffer = 0; return self; }
	static auto construct(p_string value) -> p_string { return value; }
	static auto construct(p_code_point c, p_int repeat) -> p_string;
	// TODO ByteLength should be a property
	p_int ByteLength_() const { return Length; }

	p_string Substring_(p_int start, p_int length) const;
	p_string Substring_(p_int start) const { return Substring_(start, Length-start.value); }
	p_string Replace_(p_string oldValue, p_string newValue) const;
	p_int LastIndexOf_(p_code_point c) const;
	p_int index_of_(p_code_point c) const;

	p_code_point op_Element(p_int const index) const { return Buffer[index.value]; }
	p_string op_add(p_string const & value) const;
	p_bool op_equal(p_string const & other) const;
	p_bool op_not_equal(p_string const & other) const { return !this->op_equal(other).value; }
	p_bool op_less_than(p_string other) const;
	p_bool op_less_than_or_equal(p_string other) const;
	p_bool op_greater_than(p_string other) const;
	p_bool op_greater_than_or_equal(p_string other) const;
};

// -----------------------------------------------------------------------------
// Standard Library
// -----------------------------------------------------------------------------
// Parts of the standard library that are currently implemented in the runtime.

// A placeholder function until we get proper exceptions implemented
_Noreturn inline void THROW_EXCEPTION_(const p_string& value)
{
	throw std::runtime_error(value.cstr());
}


inline void assert(const p_bool condition, const p_string code, const p_string message, const p_string file, const std::int32_t line)
{
	if(!condition.value)
		throw std::runtime_error(
			p_string("Assertion failed: ").op_add(code).op_add(", ").op_add(message)
			.op_add(", file ").op_add(file).op_add(", line ").op_add(p_int(line)).cstr());
}

#define assert_(condition, message) assert(condition, #condition, message, __FILE__, __LINE__)


_Noreturn inline void NOT_IMPLEMENTED(const p_string message, const p_string function, const p_string file, const std::int32_t line)
{
	throw std::runtime_error(
		p_string("Function ").op_add(function)
		.op_add(p_string(" not yet implemented, ")).op_add(message).op_add(p_string(", ")).op_add(file).op_add(p_string(", line ")).op_add(p_int(line)).cstr());
}

#define NOT_IMPLEMENTED_(message) NOT_IMPLEMENTED(message, __func__, __FILE__, __LINE__)


_Noreturn inline void UNREACHABLE(const p_string function, const p_string file, const std::int32_t line)
{
	throw std::runtime_error(
		p_string("Reached \"UNREACHABLE\" statement in function ").op_add(function)
		.op_add(p_string(", ")).op_add(file).op_add(p_string(", line ")).op_add(p_int(line)).cstr());
}

#define UNREACHABLE_() UNREACHABLE(__func__, __FILE__, __LINE__)

class ResourceManager
{
public:
	p_string const & GetString_(p_string resourceName);
	void AddResource(p_string name, p_string value);
};

extern ResourceManager *_Nonnull const resource_manager_;

void debug_write_(p_string value);
void debug_write_line_(p_string value);
void debug_write_line_();

namespace system_
{
	namespace Collections_
	{
		template<typename T>
		class List_
		{
		private:
			T *_Nonnull values;
			int length;
			int capacity;

		public:
			// Runtime Use Members
			typedef T const *_Nonnull const_iterator;
			const_iterator begin() const { return values; }
			const_iterator end() const { return &values[length]; }

			// Adamant Members
			p_bool op_equal(List_<T> const *_Nonnull other) const { return this == other; }
			p_bool op_not_equal(List_<T> const *_Nonnull other) const { return this != other; }

			List_ *_Nonnull construct() { values = 0; length = 0; capacity = 0; return this; }
			void Add_(T value) { add_(value); }
			void Clear_() { clear_(); }
			void add_(T value);
			void clear_() { length = 0; }
			p_int op_magnitude() const { return length; }
			T const & op_Element(p_int const index) const;
		};

		template<typename T>
		void List_<T>::add_(T value)
		{
			if(length >= capacity)
			{
				int newCapacity = capacity == 0 ? 16 : capacity * 2;
				// Allocate uninitalized buffer (note `sizeof(char) == 1` always)
				// Needed if T is a value type to avoid needing a default constructor
				T* newValues = (T*)new char[newCapacity * sizeof(T)];
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
			if(index.value < 0 || index.value >= length)
				throw std::out_of_range("List index out of bounds");
			return values[index.value];
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
			p_string *_Nonnull args;
		public:
			// Runtime Use Members
			typedef p_string const *_Nonnull const_iterator;

			Arguments_(int argc, char const *_Nonnull const *_Nonnull argv);
			const_iterator begin() const { return &args[0]; }
			const_iterator end() const { return &args[Count]; }

			const int Count;

			// Adamant Members
			p_int op_magnitude() const { return Count; }
			p_string const & op_Element(p_int const index) const
			{
				if(index.value < 0 || index.value >= Count)
					throw std::out_of_range("Argument index out of bounds");
				return args[index.value];
			}
		};
	}

	namespace IO_
	{
		class File_Reader_
		{
		private:
			std::FILE *_Nonnull file;

		public:
			File_Reader_ *_Nonnull construct(const p_string& fileName);
			p_string ReadToEndSync_();
			void Close_();
		};

		class File_Writer_
		{
		private:
			std::FILE *_Nonnull file;

		public:
			File_Writer_ *_Nonnull construct(const p_string& fileName);
			void Write_(const p_string& value);
			void Close_();
		};
	}

	namespace Text_
	{
		class String_Builder_
		{
		private:
			char *_Nullable buffer;
			int capacity;
			int length;
			void ensure_capacity(int needed);
		public:
			// Runtime Use Members
			String_Builder_(): buffer(0), capacity(0), length(0) { }

			// Adamant Members
			p_bool op_equal(String_Builder_ const *_Nonnull other) const { return this == other; }
			p_bool op_not_equal(String_Builder_ const *_Nonnull other) const { return this != other; }

			String_Builder_ *_Nonnull construct() { return this; }
			String_Builder_ *_Nonnull construct(p_string const & value);
			String_Builder_ *_Nonnull construct_with_capacity(p_int capacity);
            // TODO ByteLength should be a property
	        p_int byte_length_() const { return length; }
			void Append_(p_string const & value);
			void Append_(String_Builder_ const *_Nonnull value);
			void AppendLine_(p_string const& value);
			void AppendLine_();
			void Remove_(p_int start, p_int length);
			void Remove_(p_int start);
			p_string ToString_();
		};
	}
}

namespace System_ = system_;
