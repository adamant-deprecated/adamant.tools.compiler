#include "RuntimeLibrary.hpp"

// -----------------------------------------------------------------------------
// Static Checks
// -----------------------------------------------------------------------------

// Because we assume we can cast from char* to uint8_t* they need to be the same size
static_assert(sizeof(char) == sizeof(uint8_t), "chars must be 8 bits");

// Because we assume we can cast from uint8_t* to byte* they need to be the same size
static_assert(sizeof(uint8_t) == sizeof(byte), "bytes must be 8 bits");

// Testing that the style we use for literals can be used as a const
// const code_point test_code_point = ((code_point){0xFF});
// TODO: C allows string literals that are one byte shorter than the array so no null terminator
// TODO: C also has UTF-8 literals u8"hello"
// const string test_string = ((string){5,(uint8_t const[]){0x34,0x7F,0x45,0xaf,0x69}});

// -----------------------------------------------------------------------------
// Library Utils
// -----------------------------------------------------------------------------

void lib_assert1(const _Bool condition, char const *_Nonnull code)
{
    if(!condition)
    {
        printf("Assertion failed: %s", code);
        exit(70);
    }
}

void lib_assert2(const _Bool condition, char const *_Nonnull code, char const *_Nonnull message)
{
    if(!condition)
    {
        printf("Assertion failed: %s, %s", code, message);
        exit(70);
    }
}

inline int32 int32_from(int32_t v) { return (int32){ v }; }

// TODO change this to something like byte_from
uint8_t code_point__to_char(code_point v)
{
    lib_assert(v.value <= 0xFF);
    return v.value;
}

char const * cstr_from(string value)
{
    int32_t length = value.byte_length.value;
    char* buffer = new char[length + 1];
    memcpy(buffer, value.Buffer, length);
    buffer[length] = 0;
    return buffer;
}

string string_from_cstr(char const* s)
{
    return (string){(int32_t)strlen(s), (uint8_t const*)s};
}

// -----------------------------------------------------------------------------
// Primitive Types
// -----------------------------------------------------------------------------

string bool_to_string__1(BOOL b)
{
    if(cond(b))
        return (string){4,(uint8_t const*)"true"};
    else
        return (string){5,(uint8_t const*)"false"};
}

string int_to_string__1(int32 i)
{
    uint8_t* buffer = new uint8_t[12]; // -2,147,483,648 plus null terminator
    int length = sprintf((char*)buffer, "%d", i.value);
    lib_assert(length > 0);
    return (string){length, buffer};
}
string int_to_hex_string__1(int32 i)
{
    lib_assert(i.value >= 0);
    uint8_t* buffer = new uint8_t[9]; // FF_FF_FF_FF plus null terminator
    int length = sprintf((char*)buffer, "%X", i.value);
    lib_assert(length > 0);
    return (string){length, buffer};
}

int32 hex_string_to_int__1(string s)
{
    char const* cstr = cstr_from(s);
    int32_t i = strtoul(cstr, NULL, 16);
    delete[] cstr;
    return (int32){i};
}

code_point int_to_code_point__1(int32 i)
{
    lib_assert(i.value >= 0);
    return (code_point){(uint32_t)i.value};
}

string code_point_to_string__1(code_point c)
{
    return (string){1, new uint8_t[1] { code_point__to_char(c) }};
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
    uint8_t* buffer = new uint8_t[repeat.value];
    uint8_t ch = code_point__to_char(c);
    for (int i = 0; i < repeat.value; i++)
        buffer[i] = ch;

    return (string){repeat, buffer};
}

string string__0op__add(string lhs, string rhs)
{
    int new_length = lhs.byte_length.value + rhs.byte_length.value;
    uint8_t* chars = new uint8_t[new_length];
    size_t offset = sizeof(uint8_t) * lhs.byte_length.value;
    memcpy(chars, lhs.Buffer, offset);
    memcpy(chars + offset, rhs.Buffer, rhs.byte_length.value);
    return (string){new_length, chars};
}

BOOL string__0op__equal(string lhs, string rhs)
{
    if (lhs.byte_length.value != rhs.byte_length.value)
        return FALSE;

    for (int i = 0; i < lhs.byte_length.value; i++)
        if (lhs.Buffer[i] != rhs.Buffer[i])
            return FALSE;

    return TRUE;
}

BOOL string__0op__lt(string lhs, string rhs)
{
    char const* left = cstr_from(lhs);
    char const* right = cstr_from(rhs);
    _Bool result = strcmp(left, right) < 0;
    delete[] left;
    delete[] right;
    return bool_from(result);
}
BOOL string__0op__lte(string lhs, string rhs)
{
    char const* left = cstr_from(lhs);
    char const* right = cstr_from(rhs);
    _Bool result = strcmp(left, right) <= 0;
    delete[] left;
    delete[] right;
    return bool_from(result);
}
BOOL string__0op__gt(string lhs, string rhs)
{
    char const* left = cstr_from(lhs);
    char const* right = cstr_from(rhs);
    BOOL result = bool_from(strcmp(left, right) > 0);
    delete[] left;
    delete[] right;
    return result;
}
BOOL string__0op__gte(string lhs, string rhs)
{
    char const* left = cstr_from(lhs);
    char const* right = cstr_from(rhs);
    BOOL result = bool_from(strcmp(left, right) >= 0);
    delete[] left;
    delete[] right;
    return result;
}

string substring__3(string s, int32 start, int32 length)
{
    // You can ask for a zero length substring at the end of the string
    lib_assert(start.value <= s.byte_length.value);
    lib_assert(start.value+length.value <= s.byte_length.value);
    return (string){length, s.Buffer + start.value};
}
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
            builder.Append__1(substring__3(s, int32_from(last_index), int32_from(i-last_index)));
            builder.Append__1(new_value);
            i += old_value.byte_length.value; // skip over the value we just matched
            last_index = i;
            i--; // we need i-- to offset the i++ that is about to happen
        }

    builder.Append__1(substring__3(s, int32_from(last_index), int32_from(s.byte_length.value - last_index)));
    return builder.ToString__0();
}
int32 string_index_of__2(string s, code_point c)
{
    uint8_t value = code_point__to_char(c);
    for(int i = 0; i < s.byte_length.value; i++)
        if(s.Buffer[i] == value)
            return int32_from(i);

    // TODO we should return `int?` and return `none` in this case
    return int32_from(-1);
}
int32 string_last_index_of__2(string s, code_point c)
{
    uint8_t value = code_point__to_char(c);
    for(int i = s.byte_length.value - 1; i >= 0; i--)
        if(s.Buffer[i] == value)
            return int32_from(i);

    // TODO we should return `int?` and return `none` in this case
    return int32_from(-1);
}

// Operator used when we put strings into a map for resource manager
_Bool operator < (string const & lhs, string const & rhs)
{
    char const* left = cstr_from(lhs);
    char const* right = cstr_from(rhs);
    _Bool result = strcmp(left, right) < 0;
    delete[] left;
    delete[] right;
    return result;
}

// -----------------------------------------------------------------------------
// Standard Library
// -----------------------------------------------------------------------------

void assert1(const BOOL condition, char const *_Nonnull code, char const *_Nonnull file, const int32_t line)
{
    if(!condition.value)
    {
        printf("Assertion failed: %s, file %s, line %i", code, file, line);
        exit(70);
    }
}

void assert2(const BOOL condition, char const *_Nonnull code, const string message, char const *_Nonnull file, const int32_t line)
{
    if(!condition.value)
    {
        printf("Assertion failed: %s, %s, file %s, line %i", code, cstr_from(message), file, line);
        exit(70);
    }
}

_Noreturn void NOT_IMPLEMENTED0(char const *_Nonnull function, char const *_Nonnull file, const int32_t line)
{
    printf("Function %s not yet implemented, %s, line %i", function, file, line);
    exit(70);
}

_Noreturn void NOT_IMPLEMENTED1(const string message, char const *_Nonnull function, char const *_Nonnull file, const int32_t line)
{
    printf("Function %s not yet implemented, %s, %s, line %i", function, cstr_from(message), file, line);
    exit(70);
}

_Noreturn void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const int32_t line)
{
    printf("Reached \"UNREACHABLE\" statement in function %s, %s, line %i", function, file, line);
    exit(70);
}

int32_t resource_count = 0;
string resource_name[1024];
string resource_value[1024];

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

    lib_assert_msg(false, cstr_from(name));
    UNREACHABLE__0();
}

void debug_write__1(string value)
{
    fprintf(stderr, "%.*s", value.byte_length.value, value.Buffer);
}
void debug_write_line__1(string value)
{
    fprintf(stderr, "%.*s\n", value.byte_length.value, value.Buffer);
}
void debug_write_line__0()
{
    fprintf(stderr, "\n");
}

bool string__0next(string__0iter*_Nonnull iter)
{
    iter->current++;
    if(iter->current >= iter->count)
    {
        iter->current = iter->count; // prevent current from further increase
        return false;
    }
    return true;
}

Strings__0 *_Nonnull Strings__0__0new__0(Strings__0 *_Nonnull self)
{
    self->values = NULL;
    self->count__ = {0};
    self->capacity__ = {0};
    return self;
}

void add_string__2(Strings__0 *_Nonnull strings, string value)
{
    if(strings->count__.value >= strings->capacity__.value)
    {
        int32_t new_capacity = strings->capacity__.value == 0 ? 16 : strings->capacity__.value * 2;
        // Allocate uninitalized buffer (note `sizeof(char) == 1` always)
        // Needed if T is a value type to avoid needing a default constructor
        string* new_values = (string*)new char[new_capacity * sizeof(string)];
        memcpy(new_values, strings->values, strings->count__.value * sizeof(string));
        if(strings->capacity__.value != 0)
            delete[] strings->values; // delete the old array
        strings->values = new_values;
        strings->capacity__ = {new_capacity};
    }
    strings->values[strings->count__.value] = value;
    strings->count__.value++;
}

bool int__0next(int__0iter*_Nonnull iter)
{
    iter->current++;
    if(iter->current >= iter->count)
    {
        iter->current = iter->count; // prevent current from further increase
        return false;
    }
    return true;
}

Ints__0 *_Nonnull Ints__0__0new__0(Ints__0 *_Nonnull self)
{
    self->values = NULL;
    self->count__ = {0};
    self->capacity__ = {0};
    return self;
}

void add_int__2(Ints__0 *_Nonnull ints, int32 value)
{
    if(ints->count__.value >= ints->capacity__.value)
    {
        int32_t new_capacity = ints->capacity__.value == 0 ? 16 : ints->capacity__.value * 2;
        // Allocate uninitalized buffer (note `sizeof(char) == 1` always)
        // Needed if T is a value type to avoid needing a default constructor
        int32* new_values = (int32*)new char[new_capacity * sizeof(int32)];
        memcpy(new_values, ints->values, ints->count__.value * sizeof(int32));
        if(ints->capacity__.value != 0)
            delete[] ints->values; // delete the old array
        ints->values = new_values;
        ints->capacity__ = {new_capacity};
    }
    ints->values[ints->count__.value] = value;
    ints->count__.value++;
}

bool void_ptr__0next(void_ptr__0iter*_Nonnull iter)
{
    iter->current++;
    if(iter->current >= iter->count)
    {
        iter->current = iter->count; // prevent current from further increase
        return false;
    }
    return true;
}

void add_item__2(system__collections__List__1 *_Nonnull list, void_ptr value)
{
    if(list->count__.value >= list->capacity__.value)
    {
        int32_t new_capacity = list->capacity__.value == 0 ? 16 : list->capacity__.value * 2;
        // Allocate uninitalized buffer (note `sizeof(char) == 1` always)
        void_ptr* new_values = (void_ptr*)new char[new_capacity * sizeof(void_ptr)];
        memcpy(new_values, list->values, list->count__.value * sizeof(void_ptr));
        if(list->capacity__.value != 0)
            delete[] list->values; // delete the old array
        list->values = new_values;
        list->capacity__ = (int32){new_capacity};
    }
    list->values[list->count__.value] = value;
    list->count__.value++;
}

void console_write__2(system__console__Console__0 *_Nonnull console, string value)
{
    printf("%.*s", value.byte_length.value, value.Buffer);
}
void console_write_line__2(system__console__Console__0 *_Nonnull console, string value)
{
    printf("%.*s\n", value.byte_length.value, value.Buffer);
}
void console_write_line__1(system__console__Console__0 *_Nonnull console)
{
    printf("\n");
}

// system__console__Arguments__0::system__console__Arguments__0(int argc, char const *const * argv)
//     : count__((int32){argc-1})
// {
//     values = new string[count__.value];
//     for (int i = 0; i < count__.value; i++)
//         values[i] = string_from_cstr(argv[i+1]);
// }

system__console__Arguments__0 const *_Nonnull convert_arguments(int argc, char const *_Nonnull const *_Nonnull argv)
{
    system__console__Arguments__0 *_Nonnull self = allocate(sizeof(system__console__Arguments__0));
    self->count__ = (int32){argc-1};
    self->values = new string[self->count__.value];
    for (int i = 0; i < self->count__.value; i++)
        self->values[i] = string_from_cstr(argv[i+1]);
    return self;
}

system__io__File_Reader__0 *_Nonnull system__io__File_Reader__0__0new__1(system__io__File_Reader__0 *_Nonnull self, const string& fileName)
{
    char const *_Nonnull fname = cstr_from(fileName);
    self->file= fopen(fname, "rb"); // TODO check for error
    delete[] fname;
    return self;
}

string system__io__File_Reader__0::ReadToEndSync__0()
{
    fseek(file, 0, SEEK_END);
    auto length = ftell(file);
    fseek(file, 0, SEEK_SET);
    auto buffer = new uint8_t[length];
    length = fread(buffer, sizeof(uint8_t), length, file);
    return (string){(int32_t)length, buffer};
}

void system__io__File_Reader__0::Close__0()
{
    fclose(file);
}

system__io__File_Writer__0 *_Nonnull system__io__File_Writer__0__0new__1(system__io__File_Writer__0 *_Nonnull self, const string& fileName)
{
    char const *_Nonnull fname = cstr_from(fileName);
    self->file = fopen(fname, "wb"); // TODO check error
    delete[] fname;
    return self;
}

void system__io__File_Writer__0::Write__1(const string& value)
{
    fwrite(value.Buffer, sizeof(char), value.byte_length.value, file);
}

void system__io__File_Writer__0::Close__0()
{
    fclose(file);
}

void system__text__String_Builder__0::ensure_capacity(int needed)
{
    int new_capacity = capacity == 0 ? 128 : capacity;
    while(new_capacity < needed)
    {
        new_capacity *= 2;
    }

    if(new_capacity > capacity)
    {
        uint8_t* new_buffer = new uint8_t[new_capacity];
        if(length > 0)
            memcpy(new_buffer, buffer, length*sizeof(uint8_t));

        if(capacity > 0)
            delete[] buffer;

        buffer = new_buffer;
        capacity = new_capacity;
    }
}

system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__1(system__text__String_Builder__0 *_Nonnull self, string const & value)
{
    system__text__String_Builder__0__0new__0(self);
    self->ensure_capacity(value.byte_length.value);
    memcpy(self->buffer, value.Buffer, value.byte_length.value);
    self->length = value.byte_length.value;
    return self;
}

system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__with_capacity__1(system__text__String_Builder__0 *_Nonnull self, int32 capacity)
{
    system__text__String_Builder__0__0new__0(self);
    self->ensure_capacity(capacity.value);
    return self;
}

void system__text__String_Builder__0::Append__1(string const & value)
{
    int new_length = length + value.byte_length.value;
    ensure_capacity(new_length);
    memcpy(buffer+length, value.Buffer, value.byte_length.value);
    length = new_length;
}

void system__text__String_Builder__0::Append__1(system__text__String_Builder__0 const *_Nonnull value)
{
    int new_length = length + value->length;
    ensure_capacity(new_length);
    memcpy(buffer+length, value->buffer, value->length);
    length = new_length;
}

void system__text__String_Builder__0::AppendLine__1(string const & value)
{
    int new_length = length + value.byte_length.value + 1;
    ensure_capacity(new_length);
    memcpy(buffer+length, value.Buffer, value.byte_length.value);
    buffer[new_length-1] = '\n';
    length = new_length;
}

void system__text__String_Builder__0::AppendLine__0()
{
    int new_length = length + 1;
    ensure_capacity(new_length);
    buffer[new_length-1] = '\n';
    length = new_length;
}

void system__text__String_Builder__0::Remove__2(int32 start, int32 length)
{
    lib_assert(start.value < this->length);

    int end = start.value + length.value;
    lib_assert(end <= this->length); // less than or equal because end is one past the end of the remove

    memmove(buffer+start.value, buffer+end, this->length-end);
    this->length -= length.value;
}

void system__text__String_Builder__0::Remove__1(int32 start)
{
    lib_assert(start.value < length);
    length = start.value;
}

string system__text__String_Builder__0::ToString__0()
{
    string result = {length, buffer};
    // give up ownership of buffer
    buffer = 0;
    length = 0;
    capacity = 0;
    return result;
}
