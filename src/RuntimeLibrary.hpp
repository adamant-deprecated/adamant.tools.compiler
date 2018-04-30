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
    i32 op_negate() const { return i32(-this->value); }
    i32 op_multiply(i32 other) const { return i32(this->value * other.value); }
    i32 op_divide(i32 other) const { return i32(this->value / other.value); }
    i32 op_remainder(i32 other) const { return i32(this->value % other.value); }
    i32 op_magnitude() const { if(this->value==INT32_MIN) throw std::overflow_error("Can't take |int.Min|"); return i32(this->value < 0 ? -this->value : this->value); }

    // Hack because we don't support as correctly yet
    u32 AsUInt_() const;
};

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
    // TODO: Not sure code_point should support these operations
    bit op_less_than(cp other) const { return bit_from(this->value < other.value); }
    bit op_less_than_or_equal(cp other) const { return bit_from(this->value <= other.value); }
    bit op_greater_than(cp other) const { return bit_from(this->value > other.value); }
    bit op_greater_than_or_equal(cp other) const { return bit_from(this->value >= other.value); }

};

char cp_to_char(cp v);

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
    p_string(i32 other);
    p_string(cp other);
    explicit p_string(bit other);

    // Adamant Members
    static auto construct() -> p_string { p_string self; self.Length = 0; self.Buffer = 0; return self; }
    static auto construct(p_string value) -> p_string { return value; }
    static auto construct(cp c, i32 repeat) -> p_string;
    // TODO ByteLength should be a property
    i32 ByteLength_() const { return i32(Length); }

    p_string Substring_(i32 start, i32 length) const;
    p_string Substring_(i32 start) const { return Substring_(start, i32(Length-start.value)); }
    p_string Replace_(p_string oldValue, p_string newValue) const;
    i32 LastIndexOf_(cp c) const;
    i32 index_of_(cp c) const;

    // TODO check index bounds
    cp op_Element(i32 const index) const { return cp(Buffer[index.value]); }
    p_string op_add(p_string const & value) const;
    p_string op_add(bit value) const { return this->op_add(p_string(value)); }
    bit op_less_than(p_string other) const;
    bit op_less_than_or_equal(p_string other) const;
    bit op_greater_than(p_string other) const;
    bit op_greater_than_or_equal(p_string other) const;
};

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

auto equal_op(p_string lhs, p_string rhs) -> bit;

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
_Noreturn inline void THROW_EXCEPTION_(const p_string& value)
{
    throw std::runtime_error(value.cstr());
}


inline void assert(const bit condition, const p_string code, const p_string message, const p_string file, const std::int32_t line)
{
    if(!condition.value)
        throw std::runtime_error(
            p_string("Assertion failed: ").op_add(code).op_add(", ").op_add(message)
            .op_add(", file ").op_add(file).op_add(", line ").op_add(i32(line)).cstr());
}

#define assert_(condition, message) assert(condition, #condition, message, __FILE__, __LINE__)


_Noreturn inline void NOT_IMPLEMENTED(const p_string message, const p_string function, const p_string file, const std::int32_t line)
{
    throw std::runtime_error(
        p_string("Function ").op_add(function)
        .op_add(p_string(" not yet implemented, ")).op_add(message).op_add(p_string(", ")).op_add(file).op_add(p_string(", line ")).op_add(i32(line)).cstr());
}

#define NOT_IMPLEMENTED_(message) NOT_IMPLEMENTED(message, __func__, __FILE__, __LINE__)


_Noreturn inline void UNREACHABLE(const p_string function, const p_string file, const std::int32_t line)
{
    throw std::runtime_error(
        p_string("Reached \"UNREACHABLE\" statement in function ").op_add(function)
        .op_add(p_string(", ")).op_add(file).op_add(p_string(", line ")).op_add(i32(line)).cstr());
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
            List_ *_Nonnull construct() { values = 0; length = 0; capacity = 0; return this; }
            void Add_(T value) { add_(value); }
            void Clear_() { clear_(); }
            void add_(T value);
            void clear_() { length = 0; }
            i32 op_magnitude() const { return i32(length); }
            T const & op_Element(i32 const index) const;
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
        T const & List_<T>::op_Element(i32 const index) const
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
            i32 op_magnitude() const { return i32(Count); }
            p_string const & op_Element(i32 const index) const
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
            String_Builder_ *_Nonnull construct() { return this; }
            String_Builder_ *_Nonnull construct(p_string const & value);
            String_Builder_ *_Nonnull construct_with_capacity(i32 capacity);
            // TODO byte_length_ should be a property
            i32 byte_length_() const { return i32(length); }
            void Append_(p_string const & value);
            void Append_(String_Builder_ const *_Nonnull value);
            void AppendLine_(p_string const& value);
            void AppendLine_();
            void Remove_(i32 start, i32 length);
            void Remove_(i32 start);
            p_string ToString_();
        };
    }
}

namespace System_ = system_;
