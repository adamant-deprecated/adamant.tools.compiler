// On windows this disables warnings about using fopen_s instead of fopen
// It must be defined before including the headers.
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

// TODO C: Consider using *_s versions of standard lib functions

// -----------------------------------------------------------------------------
// C++ Compatibility
// -----------------------------------------------------------------------------
// This section defines things that make C++ behave more like C so we can make
// the transition to C.
#ifdef __cplusplus

// Use `_Bool` as the native bool type
#define _Bool bool

// This type is used to emulate C style void pointers in C++. That is, they
// implictly convert to/from other pointer types.
class void_ptr
{
private:
    void *_Nullable ptr;
public:
    template<class T>
    void_ptr(T *_Nullable value) : ptr((void *_Nullable)value) {}
    template<class T>
    operator T *_Nullable() const { return (T *)ptr; }
    _Bool operator==(void_ptr rhs) const { return ptr == rhs.ptr; }
    template<class T>
    _Bool operator==(T *_Nullable rhs) const { return ptr == rhs; }
};

#else

#define void_ptr void*_Nullable

#endif

// -----------------------------------------------------------------------------
// Library Utils
// -----------------------------------------------------------------------------

#define lib_assert(condition) lib_assert1(condition, #condition)
void lib_assert1(const _Bool condition, char const *_Nonnull code);

inline void_ptr allocate(size_t bytes)
{
    return malloc(bytes);
}

// -----------------------------------------------------------------------------
// Primitive Types
// -----------------------------------------------------------------------------

typedef struct never never;
typedef struct optional__never optional__never;
typedef struct BOOL BOOL;
typedef struct int32 int32;
typedef struct byte byte;
typedef struct code_point code_point;
typedef struct string string;

// `never` type
struct never
{
};

// `never?` type
struct optional__never
{
};

// TODO this is a hack for now, the type of `none` should be `never?`
static const void_ptr none = (void*)0;

// For now, use `BOOL` as the emitted type
// TODO C: switch `BOOL` to `bool`
// TODO C: switch `TRUE` to `true`
// TODO C: switch `FALSE` to `false`

// `bool` type
struct BOOL
{
    _Bool value;
};

static const BOOL TRUE = { 1 };
static const BOOL FALSE = { 0 };

// Function used in conditions to make them take `bool`
inline _Bool cond(BOOL cond) { return cond.value; }

// Used by runtime for converting to bool
inline BOOL bool_from(_Bool b) { return (BOOL){ b }; }

// Wrap a bool operation that is bool based
inline BOOL bool_op(_Bool b) { return (BOOL){ b }; }
// Convert the arguments of a logical operation to bool
inline _Bool bool_arg(BOOL b) { return b.value; }

inline BOOL BOOL__0op__not(BOOL b) { return (BOOL){ !b.value }; }

string bool_to_string__1(BOOL b);

// `int` type
struct int32
{
    int32_t value;
};

inline void op__add_assign(int32*_Nonnull lhs, int32 rhs) { lhs->value += rhs.value; }
inline void op__sub_assign(int32*_Nonnull lhs, int32 rhs) { lhs->value -= rhs.value; }
inline int32 int32__0op__neg(int32 v) { return (int32){-v.value}; }
inline int32 int32__0op__add(int32 lhs, int32 rhs) { return (int32){ lhs.value + rhs.value}; }
inline int32 int32__0op__sub(int32 lhs, int32 rhs) { return (int32){ lhs.value - rhs.value}; }
inline int32 int32__0op__mul(int32 lhs, int32 rhs) { return (int32){ lhs.value * rhs.value}; }
inline int32 int32__0op__div(int32 lhs, int32 rhs) { return (int32){ lhs.value / rhs.value}; }
inline int32 int32__0op__remainder(int32 lhs, int32 rhs) { return (int32){ lhs.value % rhs.value}; }
inline BOOL int32__0op__lt(int32 lhs, int32 rhs) { return bool_from(lhs.value < rhs.value); }
inline BOOL int32__0op__lte(int32 lhs, int32 rhs) { return bool_from(lhs.value <= rhs.value); }
inline BOOL int32__0op__gt(int32 lhs, int32 rhs) { return bool_from(lhs.value > rhs.value); }
inline BOOL int32__0op__gte(int32 lhs, int32 rhs) { return bool_from(lhs.value >= rhs.value); }

string int_to_string__1(int32 i);
string int_to_hex_string__1(int32 i);
int32 hex_string_to_int__1(string s);
code_point int_to_code_point__1(int32 i);

struct byte
{
    uint8_t value;
};

struct code_point
{
    // don't use something like char32_t because C's handling of chars sucks
    uint32_t value;
};

inline BOOL code_point__0op__lt(code_point lhs, code_point rhs) { return bool_from(lhs.value < rhs.value); }
inline BOOL code_point__0op__lte(code_point lhs, code_point rhs) { return bool_from(lhs.value <= rhs.value); }
inline BOOL code_point__0op__gt(code_point lhs, code_point rhs) { return bool_from(lhs.value > rhs.value); }
inline BOOL code_point__0op__gte(code_point lhs, code_point rhs) { return bool_from(lhs.value >= rhs.value); }

inline int32 code_point_as_int__1(code_point c) { return (int32){(int32_t)c.value}; }
string code_point_to_string__1(code_point c);

struct string
{
    int32 byte_length; // TODO rename to just byte_length, though there will be a byte_length
    // property in the future, it doesn't make sense to directly expose it right now because this is
    // not the correct implementation.

    // don't use chars because C's handling of chars sucks
    uint8_t const *_Nonnull Buffer; // TODO use byte and rename to `bytes`
};

string string__0new__0();
string string__0new__1(string value);
string string__0new__2(code_point c, int32 repeat);

string string__0op__add(string lhs, string rhs);
BOOL string__0op__lt(string lhs, string rhs);
BOOL string__0op__lte(string lhs, string rhs);
BOOL string__0op__gt(string lhs, string rhs);
BOOL string__0op__gte(string lhs, string rhs);
inline code_point op__element(string value, int32 index)
{
    lib_assert(index.value >= 0 && index.value < value.byte_length.value);
    return (code_point){value.Buffer[index.value]};
}

inline int32 string_byte_length__1(string s) { return s.byte_length; }
string substring__3(string s, int32 start, int32 length);
inline string substring__2(string s, int32 start) { return substring__3(s, start, (int32){s.byte_length.value-start.value}); }
string string_replace__3(string s, string old_value, string new_value);
int32 string_index_of__2(string s, code_point c);
int32 string_last_index_of__2(string s, code_point c);

// -----------------------------------------------------------------------------
// Operators
// -----------------------------------------------------------------------------

inline BOOL equal_op(BOOL lhs, BOOL rhs)
{
    return bool_from(lhs.value == rhs.value);
}

inline BOOL equal_op(int32 lhs, int32 rhs)
{
    return bool_from(lhs.value == rhs.value);
}

inline BOOL equal_op(void_ptr lhs, void_ptr rhs)
{
    return bool_from(lhs == rhs);
}

inline BOOL equal_op(code_point lhs, code_point rhs)
{
    return bool_from(lhs.value == rhs.value);
}

BOOL equal_op(string lhs, string rhs);

inline BOOL not_equal_op(int32 lhs, int32 rhs)
{
    return bool_from(lhs.value != rhs.value);
}

// TODO implement this without templates
template<typename T>
inline BOOL not_equal_op(T lhs, T  rhs)
{
    return BOOL__0op__not(equal_op(lhs, rhs));
}

inline BOOL not_equal_op(void_ptr lhs, void_ptr rhs)
{
    return BOOL__0op__not(bool_from(lhs == rhs));
}

// -----------------------------------------------------------------------------
// Standard Library
// -----------------------------------------------------------------------------
// Parts of the standard library that are currently implemented in the runtime.

inline void_ptr allocate__1(int32 bytes)
{
    return malloc(bytes.value);
}

inline void free__1(void_ptr object)
{
    free(object);
}

#define assert__1(condition) assert1(condition, #condition, __FILE__, __LINE__)
#define assert__2(condition, message) assert2(condition, #condition, message, __FILE__, __LINE__)
void assert1(const BOOL condition, char const *_Nonnull code, char const *_Nonnull file, const int32_t line);
void assert2(const BOOL condition, char const *_Nonnull code, const string message, char const *_Nonnull file, const int32_t line);

#define NOT_IMPLEMENTED__0() NOT_IMPLEMENTED0(__func__, __FILE__, __LINE__)
#define NOT_IMPLEMENTED__1(message) NOT_IMPLEMENTED1(message, __func__, __FILE__, __LINE__)
_Noreturn void NOT_IMPLEMENTED0(char const *_Nonnull function, char const *_Nonnull file, const int32_t line);
_Noreturn void NOT_IMPLEMENTED1(const string message, char const *_Nonnull function, char const *_Nonnull file, const int32_t line);

#define UNREACHABLE__0() UNREACHABLE(__func__, __FILE__, __LINE__)
_Noreturn void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const int32_t line);


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
    int32 op__magnitude() const { return (int32){length}; }
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
        memcpy(newValues, values, length * sizeof(T));
        values = newValues;
        capacity = newCapacity;
    }
    values[length] = value;
    length++;
}

template<typename T>
T op__element(system__collections__List__1<T> const*_Nonnull list, int32 const index)
{
    lib_assert(index.value >= 0 && index.value < list->length);
    return list->values[index.value];
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
    void Write__1(string value);
    void WriteLine__1(string value);
    void WriteLine__0();
};

class system__console__Arguments__0
{
public:
    string *_Nonnull args;

    // Runtime Use Members
    typedef string const *_Nonnull const_iterator;

    system__console__Arguments__0(int argc, char const *_Nonnull const *_Nonnull argv);
    const_iterator begin() const { return &args[0]; }
    const_iterator end() const { return &args[Count]; }

    const int Count;

    // Adamant Members
    int32 op__magnitude() const { return (int32){Count}; }

};

inline string op__element(system__console__Arguments__0 const*_Nonnull arguments, int32 const index)
{
    lib_assert(index.value >= 0 && index.value < arguments->Count);
    return arguments->args[index.value];
}

struct system__io__File_Reader__0
{
    FILE *_Nonnull file;

    string ReadToEndSync__0();
    void Close__0();
};

system__io__File_Reader__0 *_Nonnull system__io__File_Reader__0__0new__1(system__io__File_Reader__0 *_Nonnull self, const string& fileName);

struct system__io__File_Writer__0
{
    FILE *_Nonnull file;

    void Write__1(const string& value);
    void Close__0();
};

system__io__File_Writer__0 *_Nonnull system__io__File_Writer__0__0new__1(system__io__File_Writer__0 *_Nonnull self, const string& fileName);

struct system__text__String_Builder__0
{
    uint8_t *_Nullable buffer;
    int capacity;
    int length;
    void ensure_capacity(int needed);

    // Adamant Members
    // TODO byte_length should be a property
    int32 byte_length__0() const { return (int32){length}; }
    void Append__1(string const & value);
    void Append__1(system__text__String_Builder__0 const *_Nonnull value);
    void AppendLine__1(string const& value);
    void AppendLine__0();
    void Remove__2(int32 start, int32 length);
    void Remove__1(int32 start);
    string ToString__0();
};

inline system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__0(system__text__String_Builder__0 *_Nonnull self)
{
    self->buffer = 0;
    self->capacity = 0;
    self->length = 0;
    return self;
}

system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__1(system__text__String_Builder__0 *_Nonnull self, string const & value);
system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__with_capacity__1(system__text__String_Builder__0 *_Nonnull self, int32 capacity);
