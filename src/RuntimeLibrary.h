// On windows this disables warnings about using fopen_s instead of fopen
// It must be defined before including the headers.
// Note that we can't switch to the "secure" functions because they don't
// compile in linux on Travis CI
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdnoreturn.h>

// -----------------------------------------------------------------------------
// Emit Support
// -----------------------------------------------------------------------------
// These are things which make emitting easier or clearer

#define ref *_Nonnull restrict
#define opt_ref *_Nullable restrict
#define ptr *_Nonnull
#define opt_ptr *_Nullable
#define mut

#define let const
#define var

#define NON_EXHAUSTIVE_MATCH(type_id) NON_EXHAUSTIVE_MATCH_IMPL(type_id, __func__, __FILE__, __LINE__);
noreturn void NON_EXHAUSTIVE_MATCH_IMPL(int32_t type_id, char const *_Nonnull function, char const *_Nonnull file, int32_t line);

// -----------------------------------------------------------------------------
// Library Utils
// -----------------------------------------------------------------------------

typedef void*_Nullable void_ptr;
typedef void const*_Nullable const_void_ptr;

#define lib_assert(condition) lib_assert1(condition, #condition)
void lib_assert1(const _Bool condition, char const *_Nonnull code);
#define lib_assert_msg(condition, message) lib_assert2(condition, #condition, message)
void lib_assert2(const _Bool condition, char const *_Nonnull code, char const *_Nonnull message);

inline void_ptr allocate(size_t bytes)
{
    return malloc(bytes);
}

// -----------------------------------------------------------------------------
// Primitive Types
// -----------------------------------------------------------------------------

typedef struct never never;
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
// Because we need to be able to assign `none` to a varible of type `never?` we
// have to typedef it as void pointer even though that is wrong.
typedef void_ptr optional__never;

// TODO this is a hack for now, the type of `none` should be `never?`
static const void_ptr none = NULL;

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
    // Though there will be a byte_length property in the future,
    // it doesn't make sense to directly expose it right now because this is
    // not the correct implementation.
    int32 byte_length;

    // don't use chars because C's handling of chars sucks
    uint8_t const *_Nullable bytes;
};

string string__0new__0();
string string__0new__1(string value);
string string__0new__2(code_point c, int32 repeat);

string string__0op__add(string lhs, string rhs);
BOOL string__0op__lt(string lhs, string rhs);
BOOL string__0op__lte(string lhs, string rhs);
BOOL string__0op__gt(string lhs, string rhs);
BOOL string__0op__gte(string lhs, string rhs);
inline code_point string__0__0op__element(string value, int32 index)
{
    lib_assert(index.value >= 0 && index.value < value.byte_length.value);
    return (code_point){value.bytes[index.value]};
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

inline BOOL BOOL__0op__equal(BOOL lhs, BOOL rhs)
{
    return bool_from(lhs.value == rhs.value);
}
inline BOOL int32__0op__equal(int32 lhs, int32 rhs)
{
    return bool_from(lhs.value == rhs.value);
}
inline BOOL code_point__0op__equal(code_point lhs, code_point rhs)
{
    return bool_from(lhs.value == rhs.value);
}
BOOL string__0op__equal(string lhs, string rhs);
// TODO this currently exists becuase of the compare `none`, it shouldn't exist
inline BOOL never__0op__equal(const_void_ptr lhs, const_void_ptr rhs)
{
    return bool_from(lhs == rhs);
}
inline BOOL void_ptr__0op__equal(const_void_ptr lhs, const_void_ptr rhs)
{
    return bool_from(lhs == rhs);
}

inline BOOL BOOL__0op__not_equal(BOOL lhs, BOOL rhs)
{
    return bool_from(lhs.value != rhs.value);
}
inline BOOL int32__0op__not_equal(int32 lhs, int32 rhs)
{
    return bool_from(lhs.value != rhs.value);
}
inline BOOL code_point__0op__not_equal(code_point lhs, code_point rhs)
{
    return bool_from(lhs.value != rhs.value);
}
inline BOOL string__0op__not_equal(string lhs, string rhs)
{
    return BOOL__0op__not(string__0op__equal(lhs, rhs));
}
// TODO this currently exists becuase of the compare `none`, it shouldn't exist
inline BOOL never__0op__not_equal(const_void_ptr lhs, const_void_ptr rhs)
{
    return bool_from(lhs != rhs);
}
inline BOOL void_ptr__0op__not_equal(const_void_ptr lhs, const_void_ptr rhs)
{
    return bool_from(lhs != rhs);
}

// -----------------------------------------------------------------------------
// Standard Library
// -----------------------------------------------------------------------------
// Parts of the standard library that are currently implemented in the runtime.

typedef struct string__0iter string__0iter;
typedef struct Strings__0 Strings__0;
typedef struct int__0iter int__0iter;
typedef struct Ints__0 Ints__0;
typedef struct void_ptr__0iter void_ptr__0iter;
typedef struct system__collections__List__1 system__collections__List__1;
typedef struct system__console__Console__0 system__console__Console__0;
typedef struct system__console__Arguments__0 system__console__Arguments__0;
typedef struct system__io__File_Reader__0 system__io__File_Reader__0;
typedef struct system__io__File_Writer__0 system__io__File_Writer__0;
typedef struct system__text__String_Builder__0 system__text__String_Builder__0;

inline void const ref as_any__1(void const ref const value)
{
    return value;
}

inline void mut ref as_any_mut__1(void mut ref const value)
{
    return value;
}

inline void_ptr allocate__1(int32 bytes)
{
    return malloc(bytes.value);
}

// TODO rename dellocate()
inline void free__1(const_void_ptr object)
{
    // TODO hack cast away const
    free((void*_Nonnull)object);
}

#define assert__1(condition) assert1(condition, #condition, __FILE__, __LINE__)
#define assert__2(condition, message) assert2(condition, #condition, message, __FILE__, __LINE__)
void assert1(const BOOL condition, char const *_Nonnull code, char const *_Nonnull file, const int32_t line);
void assert2(const BOOL condition, char const *_Nonnull code, const string message, char const *_Nonnull file, const int32_t line);

#define NOT_IMPLEMENTED__0() NOT_IMPLEMENTED0(__func__, __FILE__, __LINE__)
#define NOT_IMPLEMENTED__1(message) NOT_IMPLEMENTED1(message, __func__, __FILE__, __LINE__)
noreturn void NOT_IMPLEMENTED0(char const *_Nonnull function, char const *_Nonnull file, const int32_t line);
noreturn void NOT_IMPLEMENTED1(const string message, char const *_Nonnull function, char const *_Nonnull file, const int32_t line);

#define UNREACHABLE__0() UNREACHABLE(__func__, __FILE__, __LINE__)
noreturn void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const int32_t line);

string get_resource__1(string resource_name);
void add_resource(string name, string value);

void debug_write__1(string value);
void debug_write_line__1(string value);
void debug_write_line__0();

struct string__0iter
{
    string *_Nullable values;
    int32_t current;
    int32_t count;
};

_Bool string__0next(string__0iter*_Nonnull iter);
inline string string__0current(string__0iter const*_Nonnull iter)
{
    lib_assert(iter->current >= 0 && iter->current < iter->count);
    return iter->values[iter->current];
}

struct Strings__0
{
    string *_Nullable values;
    int32 count__;
    int32 capacity__;
};

Strings__0 *_Nonnull Strings__0__0new__0(Strings__0 *_Nonnull self);
inline string Strings__0__0op__element(Strings__0 const*_Nonnull strings, int32 const index)
{
    lib_assert(index.value >= 0 && index.value < strings->count__.value);
    return strings->values[index.value];
}
inline void clear_strings__1(Strings__0 *_Nonnull strings)
{
    strings->count__ = (int32){0};
}
void add_string__2(Strings__0 *_Nonnull strings, string value);
inline string__0iter Strings__0__0iterate(Strings__0 const *_Nonnull strings)
{
    return (string__0iter)
    {
        .values = strings->values,
        .current = -1,
        .count = strings->count__.value
    };
}
inline string__0iter string__0iterate(Strings__0 const *_Nonnull strings)
{
    return (string__0iter)
    {
        .values = strings->values,
        .current = -1,
        .count = strings->count__.value
    };
}

struct int__0iter
{
    int32 *_Nullable values;
    int32_t current;
    int32_t count;
};

_Bool int__0next(int__0iter*_Nonnull iter);
inline int32 int__0current(int__0iter const*_Nonnull iter)
{
    lib_assert(iter->current >= 0 && iter->current < iter->count);
    return iter->values[iter->current];
}

struct Ints__0
{
    int32 *_Nullable values;
    int32 count__;
    int32 capacity__;
};

Ints__0 *_Nonnull Ints__0__0new__0(Ints__0 *_Nonnull self);
inline int32 Ints__0__0op__element(Ints__0 const*_Nonnull ints, int32 const index)
{
    lib_assert(index.value >= 0 && index.value < ints->count__.value);
    return ints->values[index.value];
}
inline void clear_ints__1(Ints__0 *_Nonnull ints)
{
    ints->count__ = (int32){0};
}
void add_int__2(Ints__0 *_Nonnull ints, int32 value);
inline int__0iter Ints__0__0iterate(Ints__0 const*_Nonnull ints)
{
    return (int__0iter)
    {
        .values = ints->values,
        .current = -1,
        .count = ints->count__.value
    };
}
inline int__0iter int__0iterate(Ints__0 const*_Nonnull ints)
{
    return (int__0iter)
    {
        .values = ints->values,
        .current = -1,
        .count = ints->count__.value
    };
}

struct void_ptr__0iter
{
    void_ptr *_Nullable values;
    int32_t current;
    int32_t count;
};

_Bool void_ptr__0next(void_ptr__0iter*_Nonnull iter);
inline void_ptr void_ptr__0current(void_ptr__0iter const*_Nonnull iter)
{
    lib_assert(iter->current >= 0 && iter->current < iter->count);
    return iter->values[iter->current];
}

struct system__collections__List__1
{
    void_ptr *_Nullable values;
    int32 count__;
    int32 capacity__;
};

inline system__collections__List__1 *_Nonnull system__collections__List__1__0new__0(system__collections__List__1 *_Nonnull self)
{
    self->values = NULL;
    self->count__ = (int32){0};
    self->capacity__ = (int32){0};
    return self;
}

// TODO hack that we take const_void_ptr but then treat it as mutable
void add_item__2(system__collections__List__1 *_Nonnull list, const_void_ptr value);

inline void clear_list__1(system__collections__List__1 *_Nonnull list)
{
    list->count__ = (int32){0};
}

inline const_void_ptr system__collections__List__1__0op__element(system__collections__List__1 const*_Nonnull list, int32 const index)
{
    lib_assert(index.value >= 0);
    lib_assert(index.value < list->count__.value);
    return list->values[index.value];
}

inline void_ptr__0iter system__collections__List__1__0iterate(system__collections__List__1 const *_Nonnull list)
{
    return (void_ptr__0iter)
    {
        .values = list->values,
        .current = -1,
        .count = list->count__.value
    };
}

inline void_ptr__0iter void_ptr__0iterate(system__collections__List__1 const *_Nonnull list)
{
    return (void_ptr__0iter)
    {
        .values = list->values,
        .current = -1,
        .count = list->count__.value
    };
}

struct system__console__Console__0
{
};

void console_write__2(system__console__Console__0 *_Nonnull console, string value);
void console_write_line__2(system__console__Console__0 *_Nonnull console, string value);
void console_write_line__1(system__console__Console__0 *_Nonnull console);

struct system__console__Arguments__0
{
    string *_Nonnull values;
    int32 count__;
};

system__console__Arguments__0 const *_Nonnull convert_arguments(int argc, char const *_Nonnull const *_Nonnull argv);

inline string system__console__Arguments__0__0op__element(system__console__Arguments__0 const*_Nonnull arguments, int32 const index)
{
    lib_assert(index.value >= 0 && index.value < arguments->count__.value);
    return arguments->values[index.value];
}

inline string__0iter system__console__Arguments__0__0iterate(system__console__Arguments__0 const*_Nonnull arguments)
{
    return (string__0iter)
    {
        .values = arguments->values,
        .current = -1,
        .count = arguments->count__.value
    };
}

struct system__io__File_Reader__0
{
    FILE *_Nonnull file;
};

system__io__File_Reader__0 *_Nonnull system__io__File_Reader__0__0new__1(system__io__File_Reader__0 *_Nonnull self, string file_name);
string file_read_to_end__1(system__io__File_Reader__0 *_Nonnull reader);
void close_file_reader__1(system__io__File_Reader__0 *_Nonnull reader);

struct system__io__File_Writer__0
{
    FILE *_Nonnull file;
};

system__io__File_Writer__0 *_Nonnull system__io__File_Writer__0__0new__1(system__io__File_Writer__0 *_Nonnull self, string file_name);
void file_write__2(system__io__File_Writer__0 *_Nonnull writer, string value);
void close_file_writer__1(system__io__File_Writer__0 *_Nonnull writer);

struct system__text__String_Builder__0
{
    uint8_t *_Nullable bytes;
    int capacity;
    int32 byte_length__;
};

void ensure_sb_capacity(system__text__String_Builder__0*_Nonnull sb, int needed);

inline system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__0(system__text__String_Builder__0 *_Nonnull self)
{
    self->bytes = 0;
    self->capacity = 0;
    self->byte_length__ = (int32){0};
    return self;
}
system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__1(system__text__String_Builder__0 *_Nonnull self, string value);
system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__with_capacity__1(system__text__String_Builder__0 *_Nonnull self, int32 capacity);

void sb_append__2(system__text__String_Builder__0 *_Nonnull sb, string value);
void sb_append_sb__2(system__text__String_Builder__0 *_Nonnull sb, system__text__String_Builder__0 const *_Nonnull value);
void sb_append_line__2(system__text__String_Builder__0 *_Nonnull sb, string value);
void sb_append_line__1(system__text__String_Builder__0 *_Nonnull sb);
void sb_remove__3(system__text__String_Builder__0 *_Nonnull sb, int32 start, int32 length);
void sb_remove__2(system__text__String_Builder__0 *_Nonnull sb, int32 start);
string sb_to_string__1(system__text__String_Builder__0 *_Nonnull sb);
