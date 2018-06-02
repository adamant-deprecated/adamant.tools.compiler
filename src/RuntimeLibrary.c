#include "RuntimeLibrary.h"

#include <string.h>

// -----------------------------------------------------------------------------
// Static Checks
// -----------------------------------------------------------------------------

static inline void static_checks()
{
    // Because we assume we can cast from char* to uint8_t* they need to be the same size
    _Static_assert(sizeof(char) == sizeof(uint8_t), "chars must be 8 bits");

    // Because we assume we can cast from uint8_t* to byte* they need to be the same size
    _Static_assert(sizeof(uint8_t) == sizeof(byte), "bytes must be 8 bits");

    // Testing that the style we use for literals can be used as a const
    const code_point test_code_point = ((code_point){0xFF});
    // TODO: C allows string literals that are one byte shorter than the array so no null terminator
    // TODO: C also has UTF-8 literals u8"hello"
    // TODO change the emitted literals?
    const string test_string = ((string){5,(uint8_t const[]){u8"hello"}});
}

// -----------------------------------------------------------------------------
// Library Utils
// -----------------------------------------------------------------------------

static const _Bool _true=1;
static const _Bool _false=0;

void lib_assert1(const _Bool condition, char const *_Nonnull code)
{
    if(!condition)
    {
        printf_s("Assertion failed: %s", code);
        exit(70);
    }
}

void lib_assert2(const _Bool condition, char const *_Nonnull code, char const *_Nonnull message)
{
    if(!condition)
    {
        printf_s("Assertion failed: %s, %s", code, message);
        exit(70);
    }
}

extern inline void_ptr allocate(size_t bytes);

static inline int32 int32_from(int32_t v)
{
    return (int32){ v };
}

// TODO change this to something like byte_from
uint8_t code_point__to_char(code_point v)
{
    lib_assert(v.value <= 0xFF);
    return v.value;
}

char const * cstr_from(string value)
{
    int32_t length = value.byte_length.value;
    char* bytes = allocate(length + 1);
    memcpy_s(bytes, length + 1, value.bytes, length);
    bytes[length] = 0;
    return bytes;
}

string string_from_cstr(char const* s)
{
    return (string){(int32_t)strlen(s), (uint8_t const*)s};
}

// -----------------------------------------------------------------------------
// Primitive Types
// -----------------------------------------------------------------------------

extern inline _Bool cond(BOOL cond);
extern inline BOOL bool_from(_Bool b);
extern inline BOOL bool_op(_Bool b);
extern inline _Bool bool_arg(BOOL b);
extern inline BOOL BOOL__0op__not(BOOL b);

string bool_to_string__1(BOOL b)
{
    if(cond(b))
        return (string){4,(uint8_t const*)"true"};
    else
        return (string){5,(uint8_t const*)"false"};
}

extern inline void op__add_assign(int32*_Nonnull lhs, int32 rhs);
extern inline void op__sub_assign(int32*_Nonnull lhs, int32 rhs);
extern inline int32 int32__0op__neg(int32 v);
extern inline int32 int32__0op__add(int32 lhs, int32 rhs);
extern inline int32 int32__0op__sub(int32 lhs, int32 rhs);
extern inline int32 int32__0op__mul(int32 lhs, int32 rhs);
extern inline int32 int32__0op__div(int32 lhs, int32 rhs);
extern inline int32 int32__0op__remainder(int32 lhs, int32 rhs);
extern inline BOOL int32__0op__lt(int32 lhs, int32 rhs);
extern inline BOOL int32__0op__lte(int32 lhs, int32 rhs);
extern inline BOOL int32__0op__gt(int32 lhs, int32 rhs);
extern inline BOOL int32__0op__gte(int32 lhs, int32 rhs);

string int_to_string__1(int32 i)
{
    uint8_t* bytes = allocate(12); // -2,147,483,648 plus null terminator
    int length = sprintf_s((char*)bytes, 12, "%d", i.value);
    lib_assert(length > 0);
    return (string){length, bytes};
}
string int_to_hex_string__1(int32 i)
{
    lib_assert(i.value >= 0);
    uint8_t* bytes = allocate(9); // FF_FF_FF_FF plus null terminator
    int length = sprintf_s((char*)bytes, 9, "%X", i.value);
    lib_assert(length > 0);
    return (string){length, bytes};
}

int32 hex_string_to_int__1(string s)
{
    char const* cstr = cstr_from(s);
    int32_t i = strtoul(cstr, NULL, 16);
    free__1(cstr);
    return (int32){i};
}

code_point int_to_code_point__1(int32 i)
{
    lib_assert(i.value >= 0);
    return (code_point){(uint32_t)i.value};
}

extern inline BOOL code_point__0op__lt(code_point lhs, code_point rhs);
extern inline BOOL code_point__0op__lte(code_point lhs, code_point rhs);
extern inline BOOL code_point__0op__gt(code_point lhs, code_point rhs);
extern inline BOOL code_point__0op__gte(code_point lhs, code_point rhs);
extern inline int32 code_point_as_int__1(code_point c);

string code_point_to_string__1(code_point c)
{
    uint8_t* bytes = allocate(sizeof(uint8_t));
    *bytes = code_point__to_char(c);
    return (string){1, bytes};
}

string string__0new__0()
{
    return (string){0, 0};
}

string string__0new__1(string value)
{
    return value;
}

string string__0new__2(code_point c, int32 repeat)
{
    uint8_t* bytes = allocate(repeat.value);
    uint8_t ch = code_point__to_char(c);
    for (int i = 0; i < repeat.value; i++)
        bytes[i] = ch;

    return (string){repeat, bytes};
}

string string__0op__add(string lhs, string rhs)
{
    int new_length = lhs.byte_length.value + rhs.byte_length.value;
    uint8_t* chars = allocate(new_length);
    size_t offset = sizeof(uint8_t) * lhs.byte_length.value;
    memcpy_s(chars, new_length, lhs.bytes, offset);
    memcpy_s(chars + offset, new_length - offset, rhs.bytes, rhs.byte_length.value);
    return (string){new_length, chars};
}

BOOL string__0op__equal(string lhs, string rhs)
{
    if (lhs.byte_length.value != rhs.byte_length.value)
        return FALSE;

    for (int i = 0; i < lhs.byte_length.value; i++)
        if (lhs.bytes[i] != rhs.bytes[i])
            return FALSE;

    return TRUE;
}

BOOL string__0op__lt(string lhs, string rhs)
{
    char const* left = cstr_from(lhs);
    char const* right = cstr_from(rhs);
    _Bool result = strcmp(left, right) < 0;
    free__1(left);
    free__1(right);
    return bool_from(result);
}
BOOL string__0op__lte(string lhs, string rhs)
{
    char const* left = cstr_from(lhs);
    char const* right = cstr_from(rhs);
    _Bool result = strcmp(left, right) <= 0;
    free__1(left);
    free__1(right);
    return bool_from(result);
}
BOOL string__0op__gt(string lhs, string rhs)
{
    char const* left = cstr_from(lhs);
    char const* right = cstr_from(rhs);
    BOOL result = bool_from(strcmp(left, right) > 0);
    free__1(left);
    free__1(right);
    return result;
}
BOOL string__0op__gte(string lhs, string rhs)
{
    char const* left = cstr_from(lhs);
    char const* right = cstr_from(rhs);
    BOOL result = bool_from(strcmp(left, right) >= 0);
    free__1(left);
    free__1(right);
    return result;
}

extern inline code_point string__0__0op__element(string value, int32 index);
extern inline int32 string_byte_length__1(string s);

string substring__3(string s, int32 start, int32 length)
{
    // You can ask for a zero length substring at the end of the string
    lib_assert(start.value <= s.byte_length.value);
    lib_assert(start.value+length.value <= s.byte_length.value);
    return (string){length, s.bytes + start.value};
}

extern inline string substring__2(string s, int32 start);

string string_replace__3(string s, string old_value, string new_value)
{
    // We make one one the stack then manually call the constructor
    system__text__String_Builder__0 builder;
    system__text__String_Builder__0__0new__with_capacity__1(&builder, s.byte_length);
    int limit = s.byte_length.value - old_value.byte_length.value + 1;
    int last_index = 0;
    for(int i=0; i < limit; i++)
        if(cond(string__0op__equal(substring__3(s, int32_from(i), old_value.byte_length), old_value)))
        {
            sb_append__2(&builder, substring__3(s, int32_from(last_index), int32_from(i-last_index)));
            sb_append__2(&builder, new_value);
            i += old_value.byte_length.value; // skip over the value we just matched
            last_index = i;
            i--; // we need i-- to offset the i++ that is about to happen
        }

    sb_append__2(&builder, substring__3(s, int32_from(last_index), int32_from(s.byte_length.value - last_index)));
    return sb_to_string__1(&builder);
}
int32 string_index_of__2(string s, code_point c)
{
    uint8_t value = code_point__to_char(c);
    for(int i = 0; i < s.byte_length.value; i++)
        if(s.bytes[i] == value)
            return int32_from(i);

    // TODO we should return `int?` and return `none` in this case
    return int32_from(-1);
}
int32 string_last_index_of__2(string s, code_point c)
{
    uint8_t value = code_point__to_char(c);
    for(int i = s.byte_length.value - 1; i >= 0; i--)
        if(s.bytes[i] == value)
            return int32_from(i);

    // TODO we should return `int?` and return `none` in this case
    return int32_from(-1);
}

// -----------------------------------------------------------------------------
// Operators
// -----------------------------------------------------------------------------

extern inline BOOL BOOL__0op__equal(BOOL lhs, BOOL rhs);
extern inline BOOL int32__0op__equal(int32 lhs, int32 rhs);
extern inline BOOL code_point__0op__equal(code_point lhs, code_point rhs);
extern BOOL string__0op__equal(string lhs, string rhs);
// TODO this currently exists becuase of the compare `none`, it shouldn't exist
extern inline BOOL never__0op__equal(const_void_ptr lhs, const_void_ptr rhs);
extern inline BOOL void_ptr__0op__equal(const_void_ptr lhs, const_void_ptr rhs);

extern inline BOOL BOOL__0op__not_equal(BOOL lhs, BOOL rhs);
extern inline BOOL int32__0op__not_equal(int32 lhs, int32 rhs);
extern inline BOOL code_point__0op__not_equal(code_point lhs, code_point rhs);
extern inline BOOL string__0op__not_equal(string lhs, string rhs);
// TODO this currently exists becuase of the compare `none`, it shouldn't exist
extern inline BOOL never__0op__not_equal(const_void_ptr lhs, const_void_ptr rhs);
extern inline BOOL void_ptr__0op__not_equal(const_void_ptr lhs, const_void_ptr rhs);

// -----------------------------------------------------------------------------
// Standard Library
// -----------------------------------------------------------------------------

extern inline void_ptr allocate__1(int32 bytes);
extern inline void free__1(const_void_ptr object);

void assert1(const BOOL condition, char const *_Nonnull code, char const *_Nonnull file, const int32_t line)
{
    if(!condition.value)
    {
        printf_s("Assertion failed: %s, file %s, line %i", code, file, line);
        exit(70);
    }
}

void assert2(const BOOL condition, char const *_Nonnull code, const string message, char const *_Nonnull file, const int32_t line)
{
    if(!condition.value)
    {
        printf_s("Assertion failed: %s, %s, file %s, line %i", code, cstr_from(message), file, line);
        exit(70);
    }
}

_Noreturn void NOT_IMPLEMENTED0(char const *_Nonnull function, char const *_Nonnull file, const int32_t line)
{
    printf_s("Function %s not yet implemented, %s, line %i", function, file, line);
    exit(70);
}

_Noreturn void NOT_IMPLEMENTED1(const string message, char const *_Nonnull function, char const *_Nonnull file, const int32_t line)
{
    printf_s("Function %s not yet implemented, %s, %s, line %i", function, cstr_from(message), file, line);
    exit(70);
}

_Noreturn void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const int32_t line)
{
    printf_s("Reached \"UNREACHABLE\" statement in function %s, %s, line %i", function, file, line);
    exit(70);
}

static int32_t resource_count = 0;
static string resource_name[1024];
static string resource_value[1024];

void add_resource(string name, string value)
{
    lib_assert_msg(resource_count < 1024, "only 1024 resources are currently supported");
    resource_name[resource_count] = name;
    resource_value[resource_count] = value;
    resource_count += 1;
}

string get_resource__1(string name)
{
    for(int32_t i=0; i < resource_count; i++)
        if(cond(string__0op__equal(resource_name[i], name)))
            return resource_value[i];

    lib_assert_msg(_false, cstr_from(name));
    UNREACHABLE__0();
}

void debug_write__1(string value)
{
    fprintf_s(stderr, "%.*s", value.byte_length.value, value.bytes);
}
void debug_write_line__1(string value)
{
    fprintf_s(stderr, "%.*s\n", value.byte_length.value, value.bytes);
}
void debug_write_line__0()
{
    fprintf_s(stderr, "\n");
}

_Bool string__0next(string__0iter*_Nonnull iter)
{
    iter->current++;
    if(iter->current >= iter->count)
    {
        iter->current = iter->count; // prevent current from further increase
        return _false;
    }
    return _true;
}

extern inline string string__0current(string__0iter const*_Nonnull iter);

Strings__0 *_Nonnull Strings__0__0new__0(Strings__0 *_Nonnull self)
{
    self->values = NULL;
    self->count__ = (int32){0};
    self->capacity__ = (int32){0};
    return self;
}

extern inline string Strings__0__0op__element(Strings__0 const*_Nonnull strings, int32 const index);
extern inline void clear_strings__1(Strings__0 *_Nonnull strings);

void add_string__2(Strings__0 *_Nonnull strings, string value)
{
    if(strings->count__.value >= strings->capacity__.value)
    {
        int32_t new_capacity = strings->capacity__.value == 0 ? 16 : strings->capacity__.value * 2;
        // Allocate uninitalized bytes (note `sizeof(char) == 1` always)
        // Needed if T is a value type to avoid needing a default constructor
        string* new_values = allocate(new_capacity * sizeof(string));
        memcpy_s(new_values, new_capacity * sizeof(string), strings->values, strings->count__.value * sizeof(string));
        if(strings->capacity__.value != 0)
            free__1(strings->values); // delete the old array
        strings->values = new_values;
        strings->capacity__ = (int32){new_capacity};
    }
    strings->values[strings->count__.value] = value;
    strings->count__.value++;
}

extern inline string__0iter Strings__0__0iterate(Strings__0 const *_Nonnull strings);
extern inline string__0iter string__0iterate(Strings__0 const *_Nonnull strings);

_Bool int__0next(int__0iter*_Nonnull iter)
{
    iter->current++;
    if(iter->current >= iter->count)
    {
        iter->current = iter->count; // prevent current from further increase
        return _false;
    }
    return _true;
}

extern inline int32 int__0current(int__0iter const*_Nonnull iter);

Ints__0 *_Nonnull Ints__0__0new__0(Ints__0 *_Nonnull self)
{
    self->values = NULL;
    self->count__ = (int32){0};
    self->capacity__ = (int32){0};
    return self;
}

extern inline int32 Ints__0__0op__element(Ints__0 const*_Nonnull ints, int32 const index);
extern inline void clear_ints__1(Ints__0 *_Nonnull ints);

void add_int__2(Ints__0 *_Nonnull ints, int32 value)
{
    if(ints->count__.value >= ints->capacity__.value)
    {
        int32_t new_capacity = ints->capacity__.value == 0 ? 16 : ints->capacity__.value * 2;
        // Allocate uninitalized bytes (note `sizeof(char) == 1` always)
        // Needed if T is a value type to avoid needing a default constructor
        int32* new_values = allocate(new_capacity * sizeof(int32));
        memcpy_s(new_values, new_capacity * sizeof(int32), ints->values, ints->count__.value * sizeof(int32));
        if(ints->capacity__.value != 0)
            free__1(ints->values); // delete the old array
        ints->values = new_values;
        ints->capacity__ = (int32){new_capacity};
    }
    ints->values[ints->count__.value] = value;
    ints->count__.value++;
}

extern inline int__0iter Ints__0__0iterate(Ints__0 const*_Nonnull ints);
extern inline int__0iter int__0iterate(Ints__0 const*_Nonnull ints);

_Bool void_ptr__0next(void_ptr__0iter*_Nonnull iter)
{
    iter->current++;
    if(iter->current >= iter->count)
    {
        iter->current = iter->count; // prevent current from further increase
        return _false;
    }
    return _true;
}

extern inline void_ptr void_ptr__0current(void_ptr__0iter const*_Nonnull iter);

extern inline system__collections__List__1 *_Nonnull system__collections__List__1__0new__0(system__collections__List__1 *_Nonnull self);

void add_item__2(system__collections__List__1 *_Nonnull list, const_void_ptr value)
{
    if(list->count__.value >= list->capacity__.value)
    {
        int32_t new_capacity = list->capacity__.value == 0 ? 16 : list->capacity__.value * 2;
        // Allocate uninitalized bytes (note `sizeof(char) == 1` always)
        void_ptr* new_values = allocate(new_capacity * sizeof(void_ptr));
        memcpy_s(new_values, new_capacity * sizeof(void_ptr), list->values, list->count__.value * sizeof(void_ptr));
        if(list->capacity__.value != 0)
            free__1(list->values); // delete the old array
        list->values = new_values;
        list->capacity__ = (int32){new_capacity};
    }
    list->values[list->count__.value] = (void*_Nullable)value; // TODO hack, we cast away const
    list->count__.value++;
}

extern inline void clear_list__1(system__collections__List__1 *_Nonnull list);
extern inline const_void_ptr system__collections__List__1__0op__element(system__collections__List__1 const*_Nonnull list, int32 const index);
extern inline void_ptr__0iter system__collections__List__1__0iterate(system__collections__List__1 const *_Nonnull list);
extern inline void_ptr__0iter void_ptr__0iterate(system__collections__List__1 const *_Nonnull list);

void console_write__2(system__console__Console__0 *_Nonnull console, string value)
{
    printf_s("%.*s", value.byte_length.value, value.bytes);
}
void console_write_line__2(system__console__Console__0 *_Nonnull console, string value)
{
    printf_s("%.*s\n", value.byte_length.value, value.bytes);
}
void console_write_line__1(system__console__Console__0 *_Nonnull console)
{
    printf_s("\n");
}

system__console__Arguments__0 const *_Nonnull convert_arguments(int argc, char const *_Nonnull const *_Nonnull argv)
{
    system__console__Arguments__0 *_Nonnull self = allocate(sizeof(system__console__Arguments__0));
    self->count__ = (int32){argc-1};
    self->values = allocate(self->count__.value * sizeof(string));
    for (int i = 0; i < self->count__.value; i++)
        self->values[i] = string_from_cstr(argv[i+1]);
    return self;
}

extern inline string system__console__Arguments__0__0op__element(system__console__Arguments__0 const*_Nonnull arguments, int32 const index);
extern inline string__0iter system__console__Arguments__0__0iterate(system__console__Arguments__0 const*_Nonnull arguments);

system__io__File_Reader__0 *_Nonnull system__io__File_Reader__0__0new__1(system__io__File_Reader__0 *_Nonnull self, string fileName)
{
    char const *_Nonnull fname = cstr_from(fileName);
    // TODO report error up to caller
    errno_t err;
    if( (err = fopen_s(&self->file, fname, "rb")) ) // extra parens silences warning about assignment
    {
        char err_msg[1024];
        strerror_s(err_msg, sizeof(err_msg), err);
        fprintf_s(stderr, "cannot open file for read '%s': %s\n", fname, err_msg);
        lib_assert(_false);
    }
    free__1(fname);
    return self;
}

string file_read_to_end__1(system__io__File_Reader__0 *_Nonnull reader)
{
    fseek(reader->file, 0, SEEK_END);
    long int length = ftell(reader->file);
    fseek(reader->file, 0, SEEK_SET);
    uint8_t*_Nonnull bytes = allocate(length);
    length = fread(bytes, sizeof(uint8_t), length, reader->file);
    return (string){(int32_t)length, bytes};
}
void close_file_reader__1(system__io__File_Reader__0 *_Nonnull reader)
{
    fclose(reader->file);
}

system__io__File_Writer__0 *_Nonnull system__io__File_Writer__0__0new__1(system__io__File_Writer__0 *_Nonnull self, string fileName)
{
    char const *_Nonnull fname = cstr_from(fileName);
    // TODO report error up to caller
    errno_t err;
    if( (err = fopen_s(&self->file, fname, "wb")) ) // extra parens silences warning about assignment
    {
        char err_msg[1024];
        strerror_s(err_msg, sizeof(err_msg), err);
        fprintf_s(stderr, "cannot open file for write '%s': %s\n", fname, err_msg);
        lib_assert(_false);
    }
    free__1(fname);
    return self;
}

void file_write__2(system__io__File_Writer__0 *_Nonnull writer, string value)
{
    fwrite(value.bytes, sizeof(char), value.byte_length.value, writer->file);
}
void close_file_writer__1(system__io__File_Writer__0 *_Nonnull writer)
{
    fclose(writer->file);
}

void ensure_sb_capacity(system__text__String_Builder__0*_Nonnull sb, int needed)
{
    int new_capacity = sb->capacity == 0 ? 128 : sb->capacity;
    while(new_capacity < needed)
    {
        new_capacity *= 2;
    }

    if(new_capacity > sb->capacity)
    {
        uint8_t* new_buffer =  allocate(new_capacity);
        if(sb->byte_length__.value > 0)
            memcpy_s(new_buffer, new_capacity, sb->bytes, sb->byte_length__.value*sizeof(uint8_t));

        if(sb->capacity > 0)
            free__1(sb->bytes);

        sb->bytes = new_buffer;
        sb->capacity = new_capacity;
    }
}

extern inline system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__0(system__text__String_Builder__0 *_Nonnull self);

system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__1(system__text__String_Builder__0 *_Nonnull self, string value)
{
    system__text__String_Builder__0__0new__0(self);
    ensure_sb_capacity(self, value.byte_length.value);
    memcpy_s(self->bytes, self->capacity, value.bytes, value.byte_length.value);
    self->byte_length__.value = value.byte_length.value;
    return self;
}

system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__with_capacity__1(system__text__String_Builder__0 *_Nonnull self, int32 capacity)
{
    system__text__String_Builder__0__0new__0(self);
    ensure_sb_capacity(self, capacity.value);
    return self;
}

void sb_append__2(system__text__String_Builder__0 *_Nonnull sb, string value)
{
    int32_t new_length = sb->byte_length__.value + value.byte_length.value;
    ensure_sb_capacity(sb, new_length);
    memcpy_s(sb->bytes+sb->byte_length__.value, sb->capacity-sb->byte_length__.value, value.bytes, value.byte_length.value);
    sb->byte_length__.value = new_length;
}

void sb_append_sb__2(system__text__String_Builder__0 *_Nonnull sb, system__text__String_Builder__0 const *_Nonnull value)
{
    int32_t new_length = sb->byte_length__.value + value->byte_length__.value;
    ensure_sb_capacity(sb, new_length);
    memcpy_s(sb->bytes+sb->byte_length__.value, sb->capacity-sb->byte_length__.value, value->bytes, value->byte_length__.value);
    sb->byte_length__.value = new_length;
}

void sb_append_line__2(system__text__String_Builder__0 *_Nonnull sb, string value)
{
    int32_t new_length = sb->byte_length__.value + value.byte_length.value + 1;
    ensure_sb_capacity(sb, new_length);
    memcpy_s(sb->bytes+sb->byte_length__.value, sb->capacity-sb->byte_length__.value, value.bytes, value.byte_length.value);
    sb->bytes[new_length-1] = '\n';
    sb->byte_length__.value = new_length;
}

void sb_append_line__1(system__text__String_Builder__0 *_Nonnull sb)
{
    int32_t new_length = sb->byte_length__.value + 1;
    ensure_sb_capacity(sb, new_length);
    sb->bytes[new_length-1] = '\n';
    sb->byte_length__.value = new_length;
}

void sb_remove__3(system__text__String_Builder__0 *_Nonnull sb, int32 start, int32 length)
{
    lib_assert(start.value < sb->byte_length__.value);

    int32_t end = start.value + length.value;
    lib_assert(end <= sb->byte_length__.value); // less than or equal because end is one past the end of the remove

    memmove_s(sb->bytes+start.value, sb->capacity-start.value, sb->bytes+end, sb->byte_length__.value-end);
    sb->byte_length__.value -= length.value;
}

void sb_remove__2(system__text__String_Builder__0 *_Nonnull sb, int32 start)
{
    lib_assert(start.value < sb->byte_length__.value);
    sb->byte_length__.value = start.value;
}

string sb_to_string__1(system__text__String_Builder__0 *_Nonnull sb)
{
    string result = {sb->byte_length__.value, sb->bytes};
    // give up ownership of bytes
    sb->bytes = 0;
    sb->byte_length__.value = 0;
    sb->capacity = 0;
    return result;
}
