// On windows this disables warnings about using fopen_s instead of fopen
// It must be defined before including the headers.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <cstdint>
#include <stdexcept>
#include <string>

// -----------------------------------------------------------------------------
// Primitive Types
// -----------------------------------------------------------------------------

// `bool`
struct bit
{
    bool value;
};

// `true`
static const bit bit__true = { true };
// `false`
static const bit bit__false = { false };

// Function used in conditions to make them take `bit`
inline bool cond(bit cond) { return cond.value; }

// Used by runtime for converting to bit
inline bit bit_from(bool v) { return bit { v }; }

// Wrap a bit operation that is bool based
inline bit bit__op(bool v) { return bit { v }; }
// Convert the arguments of a logical operation to bool
inline bool bit__arg(bit v) { return v.value; }
inline bit bit__op__not(bit v) { return bit { !v.value }; }

// `never`
struct never
{
};

// `never?`
struct o_never
{
    // TODO get rid of this conversion operator when compiler emits conversions
    template<class T>
    operator T*_Nullable() const { return static_cast<T*>(0); }
};

static const o_never none;

template<typename T>
struct p_optional final
{
private:
    bool hasValue;
    union
    {
        T data;
    };

public:
    // TODO make this constructor explicit
    p_optional(T const & value) : data(value), hasValue(true) {}
    // TODO get rid of this conversion operator when compiler emits conversions
    p_optional(o_never none) : hasValue(false) {}
    auto has_value() const -> bit { return bit_from(hasValue); }
    auto value() const -> T { return data; }

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

struct u32;

// `int`
struct i32
{
    // Runtime Use Members
    std::int32_t value;

    explicit i32() = default;
    explicit i32(std::int32_t value): value(value) {}

    i32 *_Nonnull operator->() { return this; }
    i32 const *_Nonnull operator->() const { return this; }
    i32 & operator* () { return *this; }
    i32 const & operator* () const { return *this; }

    // Hack to support conversion of uint to int for now
    i32(u32 value);

    // Adamant Members
    static auto construct() -> i32 { return i32(0); }
    static auto copy(i32 const & other) -> i32 { return other; }
    void op__add_assign(i32 other) { this->value += other.value; }
    void op__subtract_assign(i32 other) { this->value -= other.value; }
    bit op__less_than(i32 other) const { return bit_from(this->value < other.value); }
    bit op__less_than_or_equal(i32 other) const { return bit_from(this->value <= other.value); }
    bit op__greater_than(i32 other) const { return bit_from(this->value > other.value); }
    bit op__greater_than_or_equal(i32 other) const { return bit_from(this->value >= other.value); }
    i32 op__add(i32 other) const { return i32(this->value + other.value); }
    i32 op__subtract(i32 other) const { return i32(this->value - other.value); }
    i32 op__multiply(i32 other) const { return i32(this->value * other.value); }
    i32 op__divide(i32 other) const { return i32(this->value / other.value); }
    i32 op__remainder(i32 other) const { return i32(this->value % other.value); }
    i32 op__magnitude() const { if(this->value==INT32_MIN) throw std::overflow_error("Can't take |int.Min|"); return i32(this->value < 0 ? -this->value : this->value); }

    // Hack because we don't support as correctly yet
    u32 as_uint__0() const;
};

inline i32 i32__op__negate(i32 v) { return i32(-v.value); }
inline bit i32__op__less_than(i32 lhs, i32 rhs) { return bit_from(lhs.value < rhs.value); }
inline bit i32__op__less_than_or_equal(i32 lhs, i32 rhs) { return bit_from(lhs.value <= rhs.value); }
inline bit i32__op__greater_than(i32 lhs, i32 rhs) { return bit_from(lhs.value > rhs.value); }
inline bit i32__op__greater_than_or_equal(i32 lhs, i32 rhs) { return bit_from(lhs.value >= rhs.value); }

// `uint`
struct u32
{
    // Runtime Use Members
    std::uint32_t value;

    explicit u32() = default;
    explicit u32(std::uint32_t value): value(value) {}

    u32 *_Nonnull operator->() { return this; }
    u32 const *_Nonnull operator->() const { return this; }
    u32 & operator* () { return *this; }
    u32 const & operator* () const { return *this; }

    // Hack to support conversion of int to uint for now
    u32(i32 value): value(value.value) {}

    // Adamant Members
    static auto construct() -> u32 { return u32(0); }
    void op__add_assign(u32 other) { this->value += other.value; }
    void op__subtract_assign(u32 other) { this->value -= other.value; }
    bit op__less_than(u32 other) const { return bit_from(this->value < other.value); }
    bit op__less_than_or_equal(u32 other) const { return bit_from(this->value <= other.value); }
    bit op__greater_than(u32 other) const { return bit_from(this->value > other.value); }
    bit op__greater_than_or_equal(u32 other) const { return bit_from(this->value >= other.value); }
    u32 op__add(u32 other) const { return u32(this->value + other.value); }
    u32 op__subtract(u32 other) const { return u32(this->value - other.value); }
};

inline bit u32__op__less_than(u32 lhs, u32 rhs) { return bit_from(lhs.value < rhs.value); }
inline bit u32__op__less_than_or_equal(u32 lhs, u32 rhs) { return bit_from(lhs.value <= rhs.value); }
inline bit u32__op__greater_than(u32 lhs, u32 rhs) { return bit_from(lhs.value > rhs.value); }
inline bit u32__op__greater_than_or_equal(u32 lhs, u32 rhs) { return bit_from(lhs.value >= rhs.value); }

inline i32::i32(u32 value)
    : value(value.value)
{
}

struct code_point
{
    std::uint32_t value;

    // Runtime Use Members
    explicit code_point() = default;
    explicit code_point(char value): value(value) {}

    code_point *_Nonnull operator->() { return this; }
    code_point const *_Nonnull operator->() const { return this; }
    code_point & operator* () { return *this; }
    code_point const & operator* () const { return *this; }

    // Adamant Members
    // static auto construct() -> code_point { return code_point('\0'); }
};

char code_point__to_char(code_point v);

// TODO: Not sure code_point should support comparision operations
inline bit code_point__op__less_than(code_point lhs, code_point rhs) { return bit_from(lhs.value < rhs.value); }
inline bit code_point__op__less_than_or_equal(code_point lhs, code_point rhs) { return bit_from(lhs.value <= rhs.value); }
inline bit code_point__op__greater_than(code_point lhs, code_point rhs) { return bit_from(lhs.value > rhs.value); }
inline bit code_point__op__greater_than_or_equal(code_point lhs, code_point rhs) { return bit_from(lhs.value >= rhs.value); }

struct string
{
    // Runtime Use Members
    char const *_Nonnull Buffer;
    int Length;

    explicit string() = default;
    explicit string(char const *_Nonnull s);
    explicit string(int length, char const *_Nonnull s);
    char const *_Nonnull cstr() const;
    string const *_Nonnull operator->() const { return this; }
    string const & operator* () const { return *this; }

    typedef char const *_Nonnull const_iterator;
    const_iterator begin() const { return &Buffer[0]; }
    const_iterator end() const { return &Buffer[Length]; }

    // Hack to support conversion of int and code_point to strings for now
    string(i32 other);
    string(code_point other);
    explicit string(bit other);

    // Adamant Members
    static auto construct() -> string { string self; self.Length = 0; self.Buffer = 0; return self; }
    static auto construct(string value) -> string { return value; }
    static auto construct(code_point c, i32 repeat) -> string;
    // TODO ByteLength should be a property
    i32 ByteLength__0() const { return i32(Length); }

    string Substring__2(i32 start, i32 length) const;
    string Substring__1(i32 start) const { return Substring__2(start, i32(Length-start.value)); }
    string Replace__2(string oldValue, string newValue) const;
    i32 LastIndexOf__1(code_point c) const;
    i32 index_of__1(code_point c) const;

    // TODO check index bounds
    code_point op__Element(i32 const index) const { return code_point(Buffer[index.value]); }
    string op__add(string const & value) const;
    string op__add(bit value) const { return this->op__add(string(value)); }
};

bit string__op__less_than(string lhs, string rhs);
bit string__op__less_than_or_equal(string lhs, string rhs);
bit string__op__greater_than(string lhs, string rhs);
bit string__op__greater_than_or_equal(string lhs, string rhs);

inline string new_string()
{
    return string::construct();
}
inline string new_string(string value)
{
    return string::construct(value);
}
inline string new_string(code_point c, i32 repeat)
{
    return string::construct(c, repeat);
}

// -----------------------------------------------------------------------------
// Operators
// -----------------------------------------------------------------------------

inline auto equal_op(bit lhs, bit rhs) -> bit
{
    return bit_from(lhs.value == rhs.value);
}
inline auto equal_op(p_optional<bit> lhs, p_optional<bit> rhs) -> bit
{
    if(lhs.has_value().value)
        return bit__op(bit__arg(rhs.has_value()) && bit__arg(equal_op(lhs.value(), rhs.value())));
    else
        return bit__op__not(rhs.has_value());
}

inline auto equal_op(i32 lhs, i32 rhs) -> bit
{
    return bit_from(lhs.value == rhs.value);
}
inline auto equal_op(p_optional<i32> lhs, p_optional<i32> rhs) -> bit
{
    if(lhs.has_value().value)
        return bit__op(bit__arg(rhs.has_value()) && bit__arg(equal_op(lhs.value(), rhs.value())));
    else
        return bit__op__not(rhs.has_value());
}

inline auto equal_op(o_never lhs, o_never rhs) -> bit
{
    return bit__true;
}

inline auto equal_op(code_point lhs, code_point rhs) -> bit
{
    return bit_from(lhs.value == rhs.value);
}

auto equal_op(string lhs, string rhs) -> bit;

// TODO implement this without templates
template<typename T>
inline auto equal_op(T const *_Nullable lhs, o_never rhs) -> bit
{
    return bit_from(lhs == 0);
}

// TODO implement this without templates
template<typename T>
inline auto equal_op(o_never lhs, T const *_Nullable rhs) -> bit
{
    return bit_from(0 == rhs);
}

// TODO Get rid of this ability
template<typename T>
inline auto equal_op(T const *_Nullable lhs, T const *_Nullable const & rhs) -> bit
{
    return bit_from(lhs == 0);
}

inline auto not_equal_op(i32 lhs, i32 rhs) -> bit
{
    return bit_from(lhs.value != rhs.value);
}
inline auto not_equal_op(p_optional<i32> lhs, p_optional<i32> rhs) -> bit
{
    if(lhs.has_value().value)
        return bit__op(bit__arg(bit__op__not(rhs.has_value())) || bit__arg(not_equal_op(lhs.value(), rhs.value())));
    else
        return rhs.has_value();
}

// TODO implement this without templates
template<typename T>
inline auto not_equal_op(T lhs, T  rhs) -> bit
{
    return bit__op__not(equal_op(lhs, rhs));
}

// TODO implement this without templates
template<typename T>
inline auto not_equal_op(T const *_Nullable lhs, o_never rhs) -> bit
{
    return bit_from(lhs != 0);
}

// TODO implement this without templates
template<typename T>
inline auto not_equal_op(o_never lhs, T const *_Nullable rhs) -> bit
{
    return bit_from(0 != rhs);
}

// -----------------------------------------------------------------------------
// Standard Library
// -----------------------------------------------------------------------------
// Parts of the standard library that are currently implemented in the runtime.

inline void assert(const bit condition, char const *_Nonnull code, const string message, char const *_Nonnull file, const std::int32_t line)
{
    if(!condition.value)
        throw std::runtime_error(
            string("Assertion failed: ").op__add(string(code)).op__add(string(", ")).op__add(message)
            .op__add(string(", file ")).op__add(string(file)).op__add(string(", line ")).op__add(i32(line)).cstr());
}

#define assert__2(condition, message) assert(condition, #condition, message, __FILE__, __LINE__)


_Noreturn inline void NOT_IMPLEMENTED(const string message, char const *_Nonnull function, char const *_Nonnull file, const std::int32_t line)
{
    throw std::runtime_error(
        string("Function ").op__add(string(function))
        .op__add(string(" not yet implemented, ")).op__add(message).op__add(string(", ")).op__add(string(file)).op__add(string(", line ")).op__add(i32(line)).cstr());
}

_Noreturn inline void NOT_IMPLEMENTED(char const *_Nonnull function, char const *_Nonnull file, const std::int32_t line)
{
    throw std::runtime_error(
        string("Function ").op__add(string(function))
        .op__add(string(" not yet implemented, ")).op__add(string(file)).op__add(string(", line ")).op__add(i32(line)).cstr());
}

#define NOT_IMPLEMENTED__1(message) NOT_IMPLEMENTED(message, __func__, __FILE__, __LINE__)
#define NOT_IMPLEMENTED__0() NOT_IMPLEMENTED(__func__, __FILE__, __LINE__)

_Noreturn inline void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const std::int32_t line)
{
    throw std::runtime_error(
        string("Reached \"UNREACHABLE\" statement in function ").op__add(string(function))
        .op__add(string(", ")).op__add(string(file)).op__add(string(", line ")).op__add(i32(line)).cstr());
}

#define UNREACHABLE__0() UNREACHABLE(__func__, __FILE__, __LINE__)

class ResourceManager
{
public:
    string const & GetString__1(string resourceName);
    void AddResource(string name, string value);
};

extern ResourceManager *_Nonnull const resource_manager__;

void debug_write__1(string value);
void debug_write_line__1(string value);
void debug_write_line__0();

template<typename T>
class system__collections__List
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
    system__collections__List *_Nonnull construct() { values = 0; length = 0; capacity = 0; return this; }
    void add__1(T value);
    void clear__0() { length = 0; }
    i32 op__magnitude() const { return i32(length); }
    T const & op__Element(i32 const index) const;
};

template<typename T>
void system__collections__List<T>::add__1(T value)
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
T const & system__collections__List<T>::op__Element(i32 const index) const
{
    if(index.value < 0 || index.value >= length)
        throw std::out_of_range("List index out of bounds");
    return values[index.value];
}

template<typename T>
system__collections__List<T> *_Nonnull new_system__collections__List()
{
    return (new system__collections__List<T>())->construct();
}

class system__console__Console
{
public:
    void Write__1(string value);
    void WriteLine__1(string value);
    void WriteLine__0();
};

class system__console__Arguments
{
private:
    string *_Nonnull args;
public:
    // Runtime Use Members
    typedef string const *_Nonnull const_iterator;

    system__console__Arguments(int argc, char const *_Nonnull const *_Nonnull argv);
    const_iterator begin() const { return &args[0]; }
    const_iterator end() const { return &args[Count]; }

    const int Count;

    // Adamant Members
    i32 op__magnitude() const { return i32(Count); }
    string const & op__Element(i32 const index) const
    {
        if(index.value < 0 || index.value >= Count)
            throw std::out_of_range("Argument index out of bounds");
        return args[index.value];
    }
};

class system__io__File_Reader
{
private:
    std::FILE *_Nonnull file;

public:
    system__io__File_Reader *_Nonnull construct(const string& fileName);
    string ReadToEndSync__0();
    void Close__0();
};

inline system__io__File_Reader *_Nonnull new_system__io__File_Reader(const string& fileName)
{
    return (new system__io__File_Reader())->construct(fileName);
}

class system__io__File_Writer
{
private:
    std::FILE *_Nonnull file;

public:
    system__io__File_Writer *_Nonnull construct(const string& fileName);
    void Write__1(const string& value);
    void Close__0();
};

inline system__io__File_Writer *_Nonnull new_system__io__File_Writer(const string& fileName)
{
    return (new system__io__File_Writer())->construct(fileName);
}

class system__text__String_Builder
{
private:
    char *_Nullable buffer;
    int capacity;
    int length;
    void ensure_capacity(int needed);
public:
    // Runtime Use Members
    system__text__String_Builder(): buffer(0), capacity(0), length(0) { }

    // Adamant Members
    system__text__String_Builder *_Nonnull construct() { return this; }
    system__text__String_Builder *_Nonnull construct(string const & value);
    system__text__String_Builder *_Nonnull construct_with_capacity(i32 capacity);
    // TODO byte_length should be a property
    i32 byte_length__0() const { return i32(length); }
    void Append__1(string const & value);
    void Append__1(system__text__String_Builder const *_Nonnull value);
    void AppendLine__1(string const& value);
    void AppendLine__0();
    void Remove__2(i32 start, i32 length);
    void Remove__1(i32 start);
    string ToString__0();
};

inline system__text__String_Builder *_Nonnull new_system__text__String_Builder()
{
    return (new system__text__String_Builder())->construct();
}

inline system__text__String_Builder *_Nonnull new_system__text__String_Builder(string const & value)
{
    return (new system__text__String_Builder())->construct(value);
}

inline system__text__String_Builder *_Nonnull new_system__text__String_Builder__with_capacity(i32 capacity)
{
    return (new system__text__String_Builder())->construct_with_capacity(capacity);
}
