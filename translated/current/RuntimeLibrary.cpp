#include "RuntimeLibrary.hpp"
#include <map>

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

// -----------------------------------------------------------------------------
// Primitive Types
// -----------------------------------------------------------------------------

char code_point__to_char(code_point v)
{
    lib_assert(v.value <= 0xFF);
    return v.value;
}

string::string(const char* s)
    : Length(strlen(s)), Buffer(s)
{
}

string::string(int length, const char* s)
    : Length(length), Buffer(s)
{
}

char const * string::cstr() const
{
    auto buffer = new char[Length + 1];
    memcpy(buffer, Buffer, Length);
    buffer[Length] = 0;
    return buffer;
}

string::string(int32 other)
    : Length(0), Buffer(0)
{
    char* buffer = new char[12]; // -2,147,483,648 to 2,147,483,647 plus null terminator
    int length = sprintf(buffer, "%d", other.value);
    lib_assert(length > 0);
    Length = length;
    Buffer = buffer;
}

string::string(code_point other)
    : Length(1), Buffer(new char[1] { code_point__to_char(other) })
{
}

string::string(BOOL other)
    : string(other.value ? "true" : "false")
{
}

string string__0new__0()
{
    string self;
    self.Length = 0;
    self.Buffer = 0;
    return self;
}
string string__0new__1(string value)
{
    return value;
}

string string__0new__2(code_point c, int32 repeat)
{
    string self;
    self.Length = repeat.value;
    char* buffer = new char[repeat.value];
    char ch = code_point__to_char(c);
    for (int i = 0; i < repeat.value; i++)
        buffer[i] = ch;

    self.Buffer = buffer;
    return self;
}

string string::Substring__2(int32 start, int32 length) const
{
    return string(length.value, Buffer + start.value);
}

string string::Replace__2(string oldValue, string newValue) const
{
    system__text__String_Builder__0 builder = system__text__String_Builder__0(); // TODO initialize capacity
    int limit = Length - oldValue.Length + 1;
    int lastIndex = 0;
    // TODO the Substring calls in here are leaking memory
    for(int i=0; i < limit; i++)
        if (cond(equal_op(Substring__2(int32_from(i), int32_from(oldValue.Length)), oldValue)))
        {
            builder.Append__1(Substring__2(int32_from(lastIndex), int32_from(i-lastIndex)));
            builder.Append__1(newValue);
            i += oldValue.Length; // skip over the value we just matched
            lastIndex = i;
            i--; // we need i-- to offset the i++ that is about to happen
        }

    builder.Append__1(Substring__2(int32_from(lastIndex), int32_from(Length - lastIndex)));
    return builder.ToString__0();
}

int32 string::LastIndexOf__1(code_point c) const
{
    for(int i = Length - 1; i >= 0; i--)
        if(Buffer[i] == code_point__to_char(c))
            return int32_from(i);

    return int32_from(-1); // TODO should return none
}

int32 string::index_of__1(code_point c) const
{
    for(int i = 0; i < Length; i++)
        if(Buffer[i] == code_point__to_char(c))
            return int32_from(i);

    return int32_from(-1);
}

string string::op__add(string const & value) const
{
    int newLength = Length + value.Length;
    char* chars = new char[newLength];
    size_t offset = sizeof(char) * Length;
    memcpy(chars, Buffer, offset);
    memcpy(chars + offset, value.Buffer, value.Length);
    return string(newLength, chars);
}

auto equal_op(string lhs, string rhs) -> BOOL
{
    if (lhs.Length != rhs.Length)
        return FALSE;

    for (int i = 0; i < lhs.Length; i++)
        if (lhs.Buffer[i] != rhs.Buffer[i])
            return FALSE;

    return TRUE;
}

BOOL string__0op__less_than(string lhs, string rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    _Bool result = strcmp(left, right) < 0;
    delete[] left;
    delete[] right;
    return bool_from(result);
}
BOOL string__0op__less_than_or_equal(string lhs, string rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    _Bool result = strcmp(left, right) <= 0;
    delete[] left;
    delete[] right;
    return bool_from(result);
}
BOOL string__0op__greater_than(string lhs, string rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    BOOL result = bool_from(strcmp(left, right) > 0);
    delete[] left;
    delete[] right;
    return result;
}
BOOL string__0op__greater_than_or_equal(string lhs, string rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    BOOL result = bool_from(strcmp(left, right) >= 0);
    delete[] left;
    delete[] right;
    return result;
}

_Bool operator < (string const & lhs, string const & rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
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
        printf("%s", string("Assertion failed: ").op__add(string(code))
            .op__add(string(", file ")).op__add(string(file)).op__add(string(", line ")).op__add(int32_from(line)).cstr());
        exit(70);
    }
}

void assert2(const BOOL condition, char const *_Nonnull code, const string message, char const *_Nonnull file, const int32_t line)
{
    if(!condition.value)
    {
        printf("%s", string("Assertion failed: ").op__add(string(code)).op__add(string(", ")).op__add(message)
            .op__add(string(", file ")).op__add(string(file)).op__add(string(", line ")).op__add(int32_from(line)).cstr());
        exit(70);
    }
}

_Noreturn void NOT_IMPLEMENTED0(char const *_Nonnull function, char const *_Nonnull file, const int32_t line)
{
    printf("%s", string("Function ").op__add(string(function))
        .op__add(string(" not yet implemented, ")).op__add(string(file)).op__add(string(", line ")).op__add(int32_from(line)).cstr());
    exit(70);
}

_Noreturn void NOT_IMPLEMENTED1(const string message, char const *_Nonnull function, char const *_Nonnull file, const int32_t line)
{
    printf("%s", string("Function ").op__add(string(function))
        .op__add(string(" not yet implemented, ")).op__add(message).op__add(string(", ")).op__add(string(file)).op__add(string(", line ")).op__add(int32_from(line)).cstr());
    exit(70);
}

_Noreturn void UNREACHABLE(char const *_Nonnull function, char const *_Nonnull file, const int32_t line)
{
    printf("%s", string("Reached \"UNREACHABLE\" statement in function ").op__add(string(function))
        .op__add(string(", ")).op__add(string(file)).op__add(string(", line ")).op__add(int32_from(line)).cstr());
    exit(70);
}

std::map<string, string> resourceValues;

string const & ResourceManager::GetString__1(string resourceName)
{
    return resourceValues.at(resourceName);
}
void ResourceManager::AddResource(string name, string value)
{
    resourceValues.insert(std::make_pair(name, value));
}

ResourceManager *const resource_manager__ = new ResourceManager();

void debug_write__1(string value)
{
    fprintf(stderr, "%.*s", value.Length, value.Buffer);
}
void debug_write_line__1(string value)
{
    fprintf(stderr, "%.*s\n", value.Length, value.Buffer);
}
void debug_write_line__0()
{
    fprintf(stderr, "\n");
}

void system__console__Console__0::Write__1(string value)
{
    printf("%.*s", value.Length, value.Buffer);
}

void system__console__Console__0::WriteLine__1(string value)
{
    printf("%.*s\n", value.Length, value.Buffer);
}

void system__console__Console__0::WriteLine__0()
{
    printf("\n");
}

system__console__Arguments__0::system__console__Arguments__0(int argc, char const *const * argv)
    : Count(argc-1)
{
    args = new string[Count];
    for (int i = 0; i < Count; i++)
        args[i] = string(argv[i+1]);
}

system__io__File_Reader__0 *_Nonnull system__io__File_Reader__0__0new__1(system__io__File_Reader__0 *_Nonnull self, const string& fileName)
{
    char const *_Nonnull fname = fileName.cstr();
    self->file= fopen(fname, "rb"); // TODO check for error
    delete[] fname;
    return self;
}

string system__io__File_Reader__0::ReadToEndSync__0()
{
    fseek(file, 0, SEEK_END);
    auto length = ftell(file);
    fseek(file, 0, SEEK_SET);
    auto buffer = new char[length];
    length = fread(buffer, sizeof(char), length, file);
    return string(length, buffer);
}

void system__io__File_Reader__0::Close__0()
{
    fclose(file);
}

system__io__File_Writer__0 *_Nonnull system__io__File_Writer__0__0new__1(system__io__File_Writer__0 *_Nonnull self, const string& fileName)
{
    char const *_Nonnull fname = fileName.cstr();
    self->file = fopen(fname, "wb"); // TODO check error
    delete[] fname;
    return self;
}

void system__io__File_Writer__0::Write__1(const string& value)
{
    fwrite(value.Buffer, sizeof(char), value.Length, file);
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
        char* new_buffer = new char[new_capacity];
        if(length > 0)
            memcpy(new_buffer, buffer, length);

        if(capacity > 0)
            delete[] buffer;

        buffer = new_buffer;
        capacity = new_capacity;
    }
}

system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__1(system__text__String_Builder__0 *_Nonnull self, string const & value)
{
    system__text__String_Builder__0__0new__0(self);
    self->ensure_capacity(value.Length);
    memcpy(self->buffer, value.Buffer, value.Length);
    self->length = value.Length;
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
    int new_length = length + value.Length;
    ensure_capacity(new_length);
    memcpy(buffer+length, value.Buffer, value.Length);
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
    int new_length = length + value.Length + 1;
    ensure_capacity(new_length);
    memcpy(buffer+length, value.Buffer, value.Length);
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
    string result(length, buffer);
    // give up ownership of buffer
    buffer = 0;
    length = 0;
    capacity = 0;
    return result;
}
