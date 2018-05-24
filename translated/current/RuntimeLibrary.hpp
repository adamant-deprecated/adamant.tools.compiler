// On windows this disables warnings about using fopen_s instead of fopen
// It must be defined before including the headers.
// #define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define assert__2(condition, message) assert__2__impl(condition, #condition, message, __FILE__, __LINE__)
#define assert__1(condition) assert__1__impl(condition, #condition, __FILE__, __LINE__)

typedef struct bool__00 bool__00;
typedef struct string__00 string__00;

inline void assert__2__impl(const bool__00 condition, char const *_Nonnull code, const string__00 message, char const *_Nonnull file, const int32_t line);
inline void assert__1__impl(const bool__00 condition, char const *_Nonnull code, char const *_Nonnull file, const int32_t line);

// -----------------------------------------------------------------------------
// Primitive Types
// -----------------------------------------------------------------------------

// `bool`
struct bool__00
{
    bool value;
};

// `true`
static const bool__00 true__00 = { true };
// `false`
static const bool__00 false__00 = { false };

// Function used in conditions to make them take `bool__00`
inline bool cond(bool__00 cond) { return cond.value; }

// Used by runtime for converting to bool__00
inline bool__00 bool__00_from(bool v) { return bool__00 { v }; }

// Wrap a bool__00 operation that is bool based
inline bool__00 bool__00__op(bool v) { return bool__00 { v }; }
// Convert the arguments of a logical operation to bool
inline bool bool__00__arg(bool__00 v) { return v.value; }
inline bool__00 bool__00__0op__not(bool__00 v) { return bool__00 { !v.value }; }

// `never`
struct never__00
{
};

// `never?`
struct o_never__00
{
    // TODO get rid of this conversion operator when compiler emits conversions
    template<class T>
    operator T*_Nullable() const { return static_cast<T*>(0); }
};

static const o_never__00 none;

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
    p_optional(o_never__00 none) : hasValue(false) {}
    auto has_value() const -> bool__00 { return bool__00_from(hasValue); }
    auto value() const -> T { return data; }

    T & operator->()
    {
        assert__2(bool__00_from(hasValue), "Access to `none` Optional value");
        return data;
    }
    T const & operator->() const
    {
        assert__2(bool__00_from(hasValue), "Access to `none` Optional value");
        return data;
    }
    T & operator* ()
    {
        assert__2(bool__00_from(hasValue), "Access to `none` Optional value");
        return data;
    }
    T const & operator* () const
    {
        assert__2(bool__00_from(hasValue), "Access to `none` Optional value");
        return data;
    }
};

struct uint__00;

// `int`
struct int__00
{
    // Runtime Use Members
    int32_t value;

    explicit int__00() = default;
    explicit int__00(int32_t value): value(value) {}

    int__00 *_Nonnull operator->() { return this; }
    int__00 const *_Nonnull operator->() const { return this; }
    int__00 & operator* () { return *this; }
    int__00 const & operator* () const { return *this; }

    // Hack to support conversion of uint to int for now
    int__00(uint__00 value);

    // Adamant Members
    void op__add_assign(int__00 other) { this->value += other.value; }
    void op__subtract_assign(int__00 other) { this->value -= other.value; }
    bool__00 op__less_than(int__00 other) const { return bool__00_from(this->value < other.value); }
    bool__00 op__less_than_or_equal(int__00 other) const { return bool__00_from(this->value <= other.value); }
    bool__00 op__greater_than(int__00 other) const { return bool__00_from(this->value > other.value); }
    bool__00 op__greater_than_or_equal(int__00 other) const { return bool__00_from(this->value >= other.value); }
    int__00 op__add(int__00 other) const { return int__00(this->value + other.value); }
    int__00 op__subtract(int__00 other) const { return int__00(this->value - other.value); }
    int__00 op__multiply(int__00 other) const { return int__00(this->value * other.value); }
    int__00 op__divide(int__00 other) const { return int__00(this->value / other.value); }
    int__00 op__remainder(int__00 other) const { return int__00(this->value % other.value); }
    int__00 op__magnitude() const;

    // Hack because we don't support as correctly yet
    uint__00 as_uint__0() const;
};

inline int__00 int__00__0op__negate(int__00 v) { return int__00(-v.value); }
inline bool__00 int__00__0op__less_than(int__00 lhs, int__00 rhs) { return bool__00_from(lhs.value < rhs.value); }
inline bool__00 int__00__0op__less_than_or_equal(int__00 lhs, int__00 rhs) { return bool__00_from(lhs.value <= rhs.value); }
inline bool__00 int__00__0op__greater_than(int__00 lhs, int__00 rhs) { return bool__00_from(lhs.value > rhs.value); }
inline bool__00 int__00__0op__greater_than_or_equal(int__00 lhs, int__00 rhs) { return bool__00_from(lhs.value >= rhs.value); }

// `uint`
struct uint__00
{
    // Runtime Use Members
    uint32_t value;

    explicit uint__00() = default;
    explicit uint__00(uint32_t value): value(value) {}

    uint__00 *_Nonnull operator->() { return this; }
    uint__00 const *_Nonnull operator->() const { return this; }
    uint__00 & operator* () { return *this; }
    uint__00 const & operator* () const { return *this; }

    // Hack to support conversion of int to uint for now
    uint__00(int__00 value): value(value.value) {}

    // Adamant Members
    void op__add_assign(uint__00 other) { this->value += other.value; }
    void op__subtract_assign(uint__00 other) { this->value -= other.value; }
    bool__00 op__less_than(uint__00 other) const { return bool__00_from(this->value < other.value); }
    bool__00 op__less_than_or_equal(uint__00 other) const { return bool__00_from(this->value <= other.value); }
    bool__00 op__greater_than(uint__00 other) const { return bool__00_from(this->value > other.value); }
    bool__00 op__greater_than_or_equal(uint__00 other) const { return bool__00_from(this->value >= other.value); }
    uint__00 op__add(uint__00 other) const { return uint__00(this->value + other.value); }
    uint__00 op__subtract(uint__00 other) const { return uint__00(this->value - other.value); }
};

inline bool__00 uint__00__0op__less_than(uint__00 lhs, uint__00 rhs) { return bool__00_from(lhs.value < rhs.value); }
inline bool__00 uint__00__0op__less_than_or_equal(uint__00 lhs, uint__00 rhs) { return bool__00_from(lhs.value <= rhs.value); }
inline bool__00 uint__00__0op__greater_than(uint__00 lhs, uint__00 rhs) { return bool__00_from(lhs.value > rhs.value); }
inline bool__00 uint__00__0op__greater_than_or_equal(uint__00 lhs, uint__00 rhs) { return bool__00_from(lhs.value >= rhs.value); }

inline int__00::int__00(uint__00 value)
    : value(value.value)
{
}

struct code_point__00
{
    uint32_t value;

    // Runtime Use Members
    explicit code_point__00() = default;
    explicit code_point__00(char value): value(value) {}

    code_point__00 *_Nonnull operator->() { return this; }
    code_point__00 const *_Nonnull operator->() const { return this; }
    code_point__00 & operator* () { return *this; }
    code_point__00 const & operator* () const { return *this; }
};

char code_point__00__to_char(code_point__00 v);

// TODO: Not sure code_point__00 should support comparision operations
inline bool__00 code_point__00__0op__less_than(code_point__00 lhs, code_point__00 rhs) { return bool__00_from(lhs.value < rhs.value); }
inline bool__00 code_point__00__0op__less_than_or_equal(code_point__00 lhs, code_point__00 rhs) { return bool__00_from(lhs.value <= rhs.value); }
inline bool__00 code_point__00__0op__greater_than(code_point__00 lhs, code_point__00 rhs) { return bool__00_from(lhs.value > rhs.value); }
inline bool__00 code_point__00__0op__greater_than_or_equal(code_point__00 lhs, code_point__00 rhs) { return bool__00_from(lhs.value >= rhs.value); }

struct string__00
{
    // Runtime Use Members
    char const *_Nonnull Buffer;
    int Length;

    explicit string__00() = default;
    explicit string__00(char const *_Nonnull s);
    explicit string__00(int length, char const *_Nonnull s);
    char const *_Nonnull cstr() const;
    string__00 const *_Nonnull operator->() const { return this; }
    string__00 const & operator* () const { return *this; }

    typedef char const *_Nonnull const_iterator;
    const_iterator begin() const { return &Buffer[0]; }
    const_iterator end() const { return &Buffer[Length]; }

    // Hack to support conversion of int and code_point__00 to string__00s for now
    string__00(int__00 other);
    string__00(code_point__00 other);
    explicit string__00(bool__00 other);

    // Adamant Members
    // TODO ByteLength should be a property
    int__00 ByteLength__0() const { return int__00(Length); }

    string__00 Substring__2(int__00 start, int__00 length) const;
    string__00 Substring__1(int__00 start) const { return Substring__2(start, int__00(Length-start.value)); }
    string__00 Replace__2(string__00 oldValue, string__00 newValue) const;
    int__00 LastIndexOf__1(code_point__00 c) const;
    int__00 index_of__1(code_point__00 c) const;

    // TODO check index bounds
    code_point__00 op__Element(int__00 const index) const { return code_point__00(Buffer[index.value]); }
    string__00 op__add(string__00 const & value) const;
    string__00 op__add(bool__00 value) const { return this->op__add(string__00(value)); }
};

bool__00 string__00__0op__less_than(string__00 lhs, string__00 rhs);
bool__00 string__00__0op__less_than_or_equal(string__00 lhs, string__00 rhs);
bool__00 string__00__0op__greater_than(string__00 lhs, string__00 rhs);
bool__00 string__00__0op__greater_than_or_equal(string__00 lhs, string__00 rhs);

string__00 string__00__0new__0();
string__00 string__00__0new__1(string__00 value);
string__00 string__00__0new__2(code_point__00 c, int__00 repeat);


inline int__00 int__00::op__magnitude() const
{
    assert__2(bool__00_from(this->value!=INT32_MIN), string__00("Can't take |int.Min|"));
    return int__00(this->value < 0 ? -this->value : this->value);
}

// -----------------------------------------------------------------------------
// Operators
// -----------------------------------------------------------------------------

inline auto equal_op(bool__00 lhs, bool__00 rhs) -> bool__00
{
    return bool__00_from(lhs.value == rhs.value);
}
inline auto equal_op(p_optional<bool__00> lhs, p_optional<bool__00> rhs) -> bool__00
{
    if(lhs.has_value().value)
        return bool__00__op(bool__00__arg(rhs.has_value()) && bool__00__arg(equal_op(lhs.value(), rhs.value())));
    else
        return bool__00__0op__not(rhs.has_value());
}

inline auto equal_op(int__00 lhs, int__00 rhs) -> bool__00
{
    return bool__00_from(lhs.value == rhs.value);
}
inline auto equal_op(p_optional<int__00> lhs, p_optional<int__00> rhs) -> bool__00
{
    if(lhs.has_value().value)
        return bool__00__op(bool__00__arg(rhs.has_value()) && bool__00__arg(equal_op(lhs.value(), rhs.value())));
    else
        return bool__00__0op__not(rhs.has_value());
}

inline auto equal_op(o_never__00 lhs, o_never__00 rhs) -> bool__00
{
    return true__00;
}

inline auto equal_op(code_point__00 lhs, code_point__00 rhs) -> bool__00
{
    return bool__00_from(lhs.value == rhs.value);
}

auto equal_op(string__00 lhs, string__00 rhs) -> bool__00;

// TODO implement this without templates
template<typename T>
inline auto equal_op(T const *_Nullable lhs, o_never__00 rhs) -> bool__00
{
    return bool__00_from(lhs == 0);
}

// TODO implement this without templates
template<typename T>
inline auto equal_op(o_never__00 lhs, T const *_Nullable rhs) -> bool__00
{
    return bool__00_from(0 == rhs);
}

// TODO Get rid of this ability
template<typename T>
inline auto equal_op(T const *_Nullable lhs, T const *_Nullable const & rhs) -> bool__00
{
    return bool__00_from(lhs == 0);
}

inline auto not_equal_op(int__00 lhs, int__00 rhs) -> bool__00
{
    return bool__00_from(lhs.value != rhs.value);
}
inline auto not_equal_op(p_optional<int__00> lhs, p_optional<int__00> rhs) -> bool__00
{
    if(lhs.has_value().value)
        return bool__00__op(bool__00__arg(bool__00__0op__not(rhs.has_value())) || bool__00__arg(not_equal_op(lhs.value(), rhs.value())));
    else
        return rhs.has_value();
}

// TODO implement this without templates
template<typename T>
inline auto not_equal_op(T lhs, T  rhs) -> bool__00
{
    return bool__00__0op__not(equal_op(lhs, rhs));
}

// TODO implement this without templates
template<typename T>
inline auto not_equal_op(T const *_Nullable lhs, o_never__00 rhs) -> bool__00
{
    return bool__00_from(lhs != 0);
}

// TODO implement this without templates
template<typename T>
inline auto not_equal_op(o_never__00 lhs, T const *_Nullable rhs) -> bool__00
{
    return bool__00_from(0 != rhs);
}

// -----------------------------------------------------------------------------
// Standard Library
// -----------------------------------------------------------------------------
// Parts of the standard library that are currently implemented in the runtime.

// This type is used to emulate C style void pointers in C++. That is, they
// implictly convert to/from other pointer types.
class voidp
{
    void *_Nonnull p;
public:
    template<class T>
    voidp (T *_Nonnull pp) : p ((void *_Nonnull)pp) {}
    template<class T>
    operator T *_Nonnull() { return (T *) p; }
};

// Version of allocate used directly by the runtime
inline voidp allocate(size_t bytes)
{
    return malloc(bytes);
}

inline voidp allocate__1(int__00 bytes)
{
    return malloc(bytes.value);
}

inline void free__1(voidp object)
{
    free(object);
}

inline void assert__2__impl(const bool__00 condition, char const *_Nonnull code, const string__00 message, char const *_Nonnull file, const int32_t line)
{
    if(!condition.value)
    {
        printf_s("%s", string__00("Assertion failed: ").op__add(string__00(code)).op__add(string__00(", ")).op__add(message)
            .op__add(string__00(", file ")).op__add(string__00(file)).op__add(string__00(", line ")).op__add(int__00(line)).cstr());
        exit(70);
    }
}

inline void assert__1__impl(const bool__00 condition, char const *_Nonnull code, char const *_Nonnull file, const int32_t line)
{
    if(!condition.value)
    {
        printf_s("%s", string__00("Assertion failed: ").op__add(string__00(code))
            .op__add(string__00(", file ")).op__add(string__00(file)).op__add(string__00(", line ")).op__add(int__00(line)).cstr());
        exit(70);
    }
}

_Noreturn inline void NOT_IMPLEMENTED(const string__00 message, char const *_Nonnull function, char const *_Nonnull file, const int32_t line)
{
    printf_s("%s", string__00("Function ").op__add(string__00(function))
        .op__add(string__00(" not yet implemented, ")).op__add(message).op__add(string__00(", ")).op__add(string__00(file)).op__add(string__00(", line ")).op__add(int__00(line)).cstr());
    exit(70);
}

_Noreturn inline void NOT_IMPLEMENTED(char const *_Nonnull function, char const *_Nonnull file, const int32_t line)
{
    printf_s("%s", string__00("Function ").op__add(string__00(function))
        .op__add(string__00(" not yet implemented, ")).op__add(string__00(file)).op__add(string__00(", line ")).op__add(int__00(line)).cstr());
    exit(70);
}

#define NOT_IMPLEMENTED__1(message) NOT_IMPLEMENTED(message, __func__, __FILE__, __LINE__)
#define NOT_IMPLEMENTED__0() NOT_IMPLEMENTED(__func__, __FILE__, __LINE__)

_Noreturn inline void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const int32_t line)
{
    printf_s("%s", string__00("Reached \"UNREACHABLE\" statement in function ").op__add(string__00(function))
        .op__add(string__00(", ")).op__add(string__00(file)).op__add(string__00(", line ")).op__add(int__00(line)).cstr());
    exit(70);
}

#define UNREACHABLE__0() UNREACHABLE(__func__, __FILE__, __LINE__)

class ResourceManager
{
public:
    string__00 const & GetString__1(string__00 resourceName);
    void AddResource(string__00 name, string__00 value);
};

extern ResourceManager *_Nonnull const resource_manager__;

void debug_write__1(string__00 value);
void debug_write_line__1(string__00 value);
void debug_write_line__0();

template<typename T>
struct system__collections__List__1
{
    T *_Nonnull values;
    int length;
    int capacity;

    // Runtime Use Members
    typedef T const *_Nonnull const_iterator;
    const_iterator begin() const { return values; }
    const_iterator end() const { return &values[length]; }

    // Adamant Members
    void add__1(T value);
    void clear__0() { length = 0; }
    int__00 op__magnitude() const { return int__00(length); }
    T const & op__Element(int__00 const index) const;
};

template<typename T>
void system__collections__List__1<T>::add__1(T value)
{
    if(length >= capacity)
    {
        int newCapacity = capacity == 0 ? 16 : capacity * 2;
        // Allocate uninitalized buffer (note `sizeof(char) == 1` always)
        // Needed if T is a value type to avoid needing a default constructor
        T* newValues = (T*)new char[newCapacity * sizeof(T)];
        memcpy_s(newValues, newCapacity * sizeof(T), values, length * sizeof(T));
        values = newValues;
        capacity = newCapacity;
    }
    values[length] = value;
    length++;
}

template<typename T>
T const & system__collections__List__1<T>::op__Element(int__00 const index) const
{
    assert__1(bool__00_from(index.value >= 0 && index.value < length));
    return values[index.value];
}

template<typename T>
system__collections__List__1<T> *_Nonnull system__collections__List__1__0new__0(system__collections__List__1<T> *_Nonnull self)
{
    self->values = 0;
    self->length = 0;
    self->capacity = 0;
    return self;
}

class system__console__Console__0
{
public:
    void Write__1(string__00 value);
    void WriteLine__1(string__00 value);
    void WriteLine__0();
};

class system__console__Arguments__0
{
private:
    string__00 *_Nonnull args;
public:
    // Runtime Use Members
    typedef string__00 const *_Nonnull const_iterator;

    system__console__Arguments__0(int argc, char const *_Nonnull const *_Nonnull argv);
    const_iterator begin() const { return &args[0]; }
    const_iterator end() const { return &args[Count]; }

    const int Count;

    // Adamant Members
    int__00 op__magnitude() const { return int__00(Count); }
    string__00 const & op__Element(int__00 const index) const
    {
        assert__1(bool__00_from(index.value >= 0 && index.value < Count));
        return args[index.value];
    }
};

struct system__io__File_Reader__0
{
    FILE *_Nonnull file;

    string__00 ReadToEndSync__0();
    void Close__0();
};

system__io__File_Reader__0 *_Nonnull system__io__File_Reader__0__0new__1(system__io__File_Reader__0 *_Nonnull self, const string__00& fileName);

struct system__io__File_Writer__0
{
    FILE *_Nonnull file;

    void Write__1(const string__00& value);
    void Close__0();
};

system__io__File_Writer__0 *_Nonnull system__io__File_Writer__0__0new__1(system__io__File_Writer__0 *_Nonnull self, const string__00& fileName);

struct system__text__String_Builder__0
{
    char *_Nullable buffer;
    int capacity;
    int length;
    void ensure_capacity(int needed);

    // Adamant Members
    // TODO byte_length should be a property
    int__00 byte_length__0() const { return int__00(length); }
    void Append__1(string__00 const & value);
    void Append__1(system__text__String_Builder__0 const *_Nonnull value);
    void AppendLine__1(string__00 const& value);
    void AppendLine__0();
    void Remove__2(int__00 start, int__00 length);
    void Remove__1(int__00 start);
    string__00 ToString__0();
};

inline system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__0(system__text__String_Builder__0 *_Nonnull self)
{
    self->buffer = 0;
    self->capacity = 0;
    self->length = 0;
    return self;
}

system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__1(system__text__String_Builder__0 *_Nonnull self, string__00 const & value);
system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__with_capacity__1(system__text__String_Builder__0 *_Nonnull self, int__00 capacity);
