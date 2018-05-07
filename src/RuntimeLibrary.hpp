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
static const bit bit_true = { true };
// `false`
static const bit bit_false = { false };

// Function used in conditions to make them take `bit`
inline bool cond(bit cond) { return cond.value; }

// Used by runtime for converting to bit
inline bit bit_from(bool v) { return bit { v }; }

// Wrap a bit operation that is bool based
inline bit bit_op(bool v) { return bit { v }; }
// Convert the arguments of a logical operation to bool
inline bool bit_arg(bit v) { return v.value; }
inline bit bit_not(bit v) { return bit { !v.value }; }

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
    void op_add_assign(i32 other) { this->value += other.value; }
    void op_subtract_assign(i32 other) { this->value -= other.value; }
    bit op_less_than(i32 other) const { return bit_from(this->value < other.value); }
    bit op_less_than_or_equal(i32 other) const { return bit_from(this->value <= other.value); }
    bit op_greater_than(i32 other) const { return bit_from(this->value > other.value); }
    bit op_greater_than_or_equal(i32 other) const { return bit_from(this->value >= other.value); }
    i32 op_add(i32 other) const { return i32(this->value + other.value); }
    i32 op_subtract(i32 other) const { return i32(this->value - other.value); }
    i32 op_multiply(i32 other) const { return i32(this->value * other.value); }
    i32 op_divide(i32 other) const { return i32(this->value / other.value); }
    i32 op_remainder(i32 other) const { return i32(this->value % other.value); }
    i32 op_magnitude() const { if(this->value==INT32_MIN) throw std::overflow_error("Can't take |int.Min|"); return i32(this->value < 0 ? -this->value : this->value); }

    // Hack because we don't support as correctly yet
    u32 as_uint_() const;
};

inline i32 i32_negate(i32 v) { return i32(-v.value); }
inline bit i32_less_than(i32 lhs, i32 rhs) { return bit_from(lhs.value < rhs.value); }
inline bit i32_less_than_or_equal(i32 lhs, i32 rhs) { return bit_from(lhs.value <= rhs.value); }
inline bit i32_greater_than(i32 lhs, i32 rhs) { return bit_from(lhs.value > rhs.value); }
inline bit i32_greater_than_or_equal(i32 lhs, i32 rhs) { return bit_from(lhs.value >= rhs.value); }

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
    void op_add_assign(u32 other) { this->value += other.value; }
    void op_subtract_assign(u32 other) { this->value -= other.value; }
    bit op_less_than(u32 other) const { return bit_from(this->value < other.value); }
    bit op_less_than_or_equal(u32 other) const { return bit_from(this->value <= other.value); }
    bit op_greater_than(u32 other) const { return bit_from(this->value > other.value); }
    bit op_greater_than_or_equal(u32 other) const { return bit_from(this->value >= other.value); }
    u32 op_add(u32 other) const { return u32(this->value + other.value); }
    u32 op_subtract(u32 other) const { return u32(this->value - other.value); }
};

inline bit u32_less_than(u32 lhs, u32 rhs) { return bit_from(lhs.value < rhs.value); }
inline bit u32_less_than_or_equal(u32 lhs, u32 rhs) { return bit_from(lhs.value <= rhs.value); }
inline bit u32_greater_than(u32 lhs, u32 rhs) { return bit_from(lhs.value > rhs.value); }
inline bit u32_greater_than_or_equal(u32 lhs, u32 rhs) { return bit_from(lhs.value >= rhs.value); }

inline i32::i32(u32 value)
    : value(value.value)
{
}

struct cp
{
    std::uint32_t value;

    // Runtime Use Members
    explicit cp() = default;
    explicit cp(char value): value(value) {}

    cp *_Nonnull operator->() { return this; }
    cp const *_Nonnull operator->() const { return this; }
    cp & operator* () { return *this; }
    cp const & operator* () const { return *this; }

    // Adamant Members
    static auto construct() -> cp { return cp('\0'); }
};

char cp_to_char(cp v);

// TODO: Not sure code_point should support comparision operations
inline bit cp_less_than(cp lhs, cp rhs) { return bit_from(lhs.value < rhs.value); }
inline bit cp_less_than_or_equal(cp lhs, cp rhs) { return bit_from(lhs.value <= rhs.value); }
inline bit cp_greater_than(cp lhs, cp rhs) { return bit_from(lhs.value > rhs.value); }
inline bit cp_greater_than_or_equal(cp lhs, cp rhs) { return bit_from(lhs.value >= rhs.value); }

struct str
{
    // Runtime Use Members
    char const *_Nonnull Buffer;
    int Length;

    explicit str() = default;
    explicit str(char const *_Nonnull s);
    explicit str(int length, char const *_Nonnull s);
    char const *_Nonnull cstr() const;
    str const *_Nonnull operator->() const { return this; }
    str const & operator* () const { return *this; }

    typedef char const *_Nonnull const_iterator;
    const_iterator begin() const { return &Buffer[0]; }
    const_iterator end() const { return &Buffer[Length]; }

    // Hack to support conversion of int and code_point to strings for now
    str(i32 other);
    str(cp other);
    explicit str(bit other);

    // Adamant Members
    static auto construct() -> str { str self; self.Length = 0; self.Buffer = 0; return self; }
    static auto construct(str value) -> str { return value; }
    static auto construct(cp c, i32 repeat) -> str;
    // TODO ByteLength should be a property
    i32 ByteLength_() const { return i32(Length); }

    str Substring_(i32 start, i32 length) const;
    str Substring_(i32 start) const { return Substring_(start, i32(Length-start.value)); }
    str Replace_(str oldValue, str newValue) const;
    i32 LastIndexOf_(cp c) const;
    i32 index_of_(cp c) const;

    // TODO check index bounds
    cp op_Element(i32 const index) const { return cp(Buffer[index.value]); }
    str op_add(str const & value) const;
    str op_add(bit value) const { return this->op_add(str(value)); }
};

bit str_less_than(str lhs, str rhs);
bit str_less_than_or_equal(str lhs, str rhs);
bit str_greater_than(str lhs, str rhs);
bit str_greater_than_or_equal(str lhs, str rhs);

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
        return bit_op(bit_arg(rhs.has_value()) && bit_arg(equal_op(lhs.value(), rhs.value())));
    else
        return bit_not(rhs.has_value());
}

inline auto equal_op(i32 lhs, i32 rhs) -> bit
{
    return bit_from(lhs.value == rhs.value);
}
inline auto equal_op(p_optional<i32> lhs, p_optional<i32> rhs) -> bit
{
    if(lhs.has_value().value)
        return bit_op(bit_arg(rhs.has_value()) && bit_arg(equal_op(lhs.value(), rhs.value())));
    else
        return bit_not(rhs.has_value());
}

inline auto equal_op(o_never lhs, o_never rhs) -> bit
{
    return bit_true;
}

inline auto equal_op(cp lhs, cp rhs) -> bit
{
    return bit_from(lhs.value == rhs.value);
}

auto equal_op(str lhs, str rhs) -> bit;

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
        return bit_op(bit_arg(bit_not(rhs.has_value())) || bit_arg(not_equal_op(lhs.value(), rhs.value())));
    else
        return rhs.has_value();
}

// TODO implement this without templates
template<typename T>
inline auto not_equal_op(T lhs, T  rhs) -> bit
{
    return bit_not(equal_op(lhs, rhs));
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

// A placeholder function until we get proper exceptions implemented
_Noreturn inline void THROW_EXCEPTION_(const str& value)
{
    throw std::runtime_error(value.cstr());
}


inline void assert(const bit condition, char const *_Nonnull code, const str message, char const *_Nonnull file, const std::int32_t line)
{
    if(!condition.value)
        throw std::runtime_error(
            str("Assertion failed: ").op_add(str(code)).op_add(str(", ")).op_add(message)
            .op_add(str(", file ")).op_add(str(file)).op_add(str(", line ")).op_add(i32(line)).cstr());
}

#define assert_(condition, message) assert(condition, #condition, message, __FILE__, __LINE__)


_Noreturn inline void NOT_IMPLEMENTED(const str message, char const *_Nonnull function, char const *_Nonnull file, const std::int32_t line)
{
    throw std::runtime_error(
        str("Function ").op_add(str(function))
        .op_add(str(" not yet implemented, ")).op_add(message).op_add(str(", ")).op_add(str(file)).op_add(str(", line ")).op_add(i32(line)).cstr());
}

#define NOT_IMPLEMENTED_(message) NOT_IMPLEMENTED(message, __func__, __FILE__, __LINE__)


_Noreturn inline void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const std::int32_t line)
{
    throw std::runtime_error(
        str("Reached \"UNREACHABLE\" statement in function ").op_add(str(function))
        .op_add(str(", ")).op_add(str(file)).op_add(str(", line ")).op_add(i32(line)).cstr());
}

#define UNREACHABLE_() UNREACHABLE(__func__, __FILE__, __LINE__)

class ResourceManager
{
public:
    str const & GetString_(str resourceName);
    void AddResource(str name, str value);
};

extern ResourceManager *_Nonnull const resource_manager_;

void debug_write_(str value);
void debug_write_line_(str value);
void debug_write_line_();

template<typename T>
class t_system__collections__List
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
    t_system__collections__List *_Nonnull construct() { values = 0; length = 0; capacity = 0; return this; }
    void add_(T value);
    void clear_() { length = 0; }
    i32 op_magnitude() const { return i32(length); }
    T const & op_Element(i32 const index) const;
};

template<typename T>
using t_System__Collections__List = t_system__collections__List<T>;

template<typename T>
void t_system__collections__List<T>::add_(T value)
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
T const & t_system__collections__List<T>::op_Element(i32 const index) const
{
    if(index.value < 0 || index.value >= length)
        throw std::out_of_range("List index out of bounds");
    return values[index.value];
}

class t_system__console__Console
{
public:
    void Write_(str value);
    void WriteLine_(str value);
    void WriteLine_();
};

typedef t_system__console__Console t_System__Console__Console;

class t_system__console__Arguments
{
private:
    str *_Nonnull args;
public:
    // Runtime Use Members
    typedef str const *_Nonnull const_iterator;

    t_system__console__Arguments(int argc, char const *_Nonnull const *_Nonnull argv);
    const_iterator begin() const { return &args[0]; }
    const_iterator end() const { return &args[Count]; }

    const int Count;

    // Adamant Members
    i32 op_magnitude() const { return i32(Count); }
    str const & op_Element(i32 const index) const
    {
        if(index.value < 0 || index.value >= Count)
            throw std::out_of_range("Argument index out of bounds");
        return args[index.value];
    }
};

typedef t_system__console__Arguments t_System__Console__Arguments;

class t_system__io__File_Reader
{
private:
    std::FILE *_Nonnull file;

public:
    t_system__io__File_Reader *_Nonnull construct(const str& fileName);
    str ReadToEndSync_();
    void Close_();
};

typedef t_system__io__File_Reader t_System__IO__File_Reader;

class t_system__io__File_Writer
{
private:
    std::FILE *_Nonnull file;

public:
    t_system__io__File_Writer *_Nonnull construct(const str& fileName);
    void Write_(const str& value);
    void Close_();
};

typedef t_system__io__File_Writer t_System__IO__File_Writer;

class t_system__text__String_Builder
{
private:
    char *_Nullable buffer;
    int capacity;
    int length;
    void ensure_capacity(int needed);
public:
    // Runtime Use Members
    t_system__text__String_Builder(): buffer(0), capacity(0), length(0) { }

    // Adamant Members
    t_system__text__String_Builder *_Nonnull construct() { return this; }
    t_system__text__String_Builder *_Nonnull construct(str const & value);
    t_system__text__String_Builder *_Nonnull construct_with_capacity(i32 capacity);
    // TODO byte_length_ should be a property
    i32 byte_length_() const { return i32(length); }
    void Append_(str const & value);
    void Append_(t_system__text__String_Builder const *_Nonnull value);
    void AppendLine_(str const& value);
    void AppendLine_();
    void Remove_(i32 start, i32 length);
    void Remove_(i32 start);
    str ToString_();
};

typedef t_system__text__String_Builder t_System__Text__String_Builder;
