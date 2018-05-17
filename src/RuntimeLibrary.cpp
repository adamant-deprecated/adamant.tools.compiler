#include "RuntimeLibrary.hpp"
#include <map>

// -----------------------------------------------------------------------------
// Primitive Types
// -----------------------------------------------------------------------------

uint__00 int__00::as_uint__0() const
{
    if(this->value < 0)
        throw std::range_error("Can't convert negative number to unsigned");

    return uint__00(this->value);
}

char code_point__00__to_char(code_point__00 v)
{
    if(v.value > 0xFF)
        throw std::range_error("Unicode char values not yet supported");

    return v.value;
}

string__00::string__00(const char* s)
    : Length(std::strlen(s)), Buffer(s)
{
}

string__00::string__00(int length, const char* s)
    : Length(length), Buffer(s)
{
}

char const * string__00::cstr() const
{
    auto buffer = new char[Length + 1];
    std::memcpy(buffer, Buffer, Length);
    buffer[Length] = 0;
    return buffer;
}

string__00::string__00(int__00 other)
    : Length(0), Buffer(0)
{
    char* buffer = new char[12]; // -2,147,483,648 to 2,147,483,647 plus null terminator
    int length = std::sprintf(buffer,"%d", other.value);
    if(length <= 0) throw std::runtime_error("Could not convert int to string");
    Length = length;
    Buffer = buffer;
}

string__00::string__00(code_point__00 other)
    : Length(1), Buffer(new char[1] { code_point__00__to_char(other) })
{
}

string__00::string__00(bool__00 other)
    : string__00(other.value ? "true" : "false")
{
}

string__00 string__00__0new__0()
{
    string__00 self;
    self.Length = 0;
    self.Buffer = 0;
    return self;
}
string__00 string__00__0new__1(string__00 value)
{
    return value;
}

string__00 string__00__0new__2(code_point__00 c, int__00 repeat)
{
    string__00 self;
    self.Length = repeat.value;
    char* buffer = new char[repeat.value];
    char ch = code_point__00__to_char(c);
    for (int i = 0; i < repeat.value; i++)
        buffer[i] = ch;

    self.Buffer = buffer;
    return self;
}

string__00 string__00::Substring__2(int__00 start, int__00 length) const
{
    return string__00(length.value, Buffer + start.value);
}

string__00 string__00::Replace__2(string__00 oldValue, string__00 newValue) const
{
    system__text__String_Builder__0 builder = system__text__String_Builder__0(); // TODO initialize capacity
    int limit = Length - oldValue.Length + 1;
    int lastIndex = 0;
    // TODO the Substring calls in here are leaking memory
    for(int i=0; i < limit; i++)
        if (cond(equal_op(Substring__2(int__00(i), int__00(oldValue.Length)), oldValue)))
        {
            builder.Append__1(Substring__2(int__00(lastIndex), int__00(i-lastIndex)));
            builder.Append__1(newValue);
            i += oldValue.Length; // skip over the value we just matched
            lastIndex = i;
            i--; // we need i-- to offset the i++ that is about to happen
        }

    builder.Append__1(Substring__2(int__00(lastIndex), int__00(Length - lastIndex)));
    return builder.ToString__0();
}

int__00 string__00::LastIndexOf__1(code_point__00 c) const
{
    for(int i = Length - 1; i >= 0; i--)
        if(Buffer[i] == code_point__00__to_char(c))
            return int__00(i);

    return int__00(-1); // TODO should return none
}

int__00 string__00::index_of__1(code_point__00 c) const
{
    for(int i = 0; i < Length; i++)
        if(Buffer[i] == code_point__00__to_char(c))
            return int__00(i);

    return int__00(-1);
}

string__00 string__00::op__add(string__00 const & value) const
{
    int newLength = Length + value.Length;
    char* chars = new char[newLength];
    size_t offset = sizeof(char) * Length;
    std::memcpy(chars, Buffer, offset);
    std::memcpy(chars + offset, value.Buffer, value.Length);
    return string__00(newLength, chars);
}

auto equal_op(string__00 lhs, string__00 rhs) -> bool__00
{
    if (lhs.Length != rhs.Length)
        return false__00;

    for (int i = 0; i < lhs.Length; i++)
        if (lhs.Buffer[i] != rhs.Buffer[i])
            return false__00;

    return true__00;
}

bool__00 string__00__0op__less_than(string__00 lhs, string__00 rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    bool result = std::strcmp(left, right) < 0;
    delete[] left;
    delete[] right;
    return bool__00_from(result);
}
bool__00 string__00__0op__less_than_or_equal(string__00 lhs, string__00 rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    bool result = std::strcmp(left, right) <= 0;
    delete[] left;
    delete[] right;
    return bool__00_from(result);
}
bool__00 string__00__0op__greater_than(string__00 lhs, string__00 rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    bool result = std::strcmp(left, right) > 0;
    delete[] left;
    delete[] right;
    return bool__00_from(result);
}
bool__00 string__00__0op__greater_than_or_equal(string__00 lhs, string__00 rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    bool result = std::strcmp(left, right) >= 0;
    delete[] left;
    delete[] right;
    return bool__00_from(result);
}

bool operator < (string__00 const & lhs, string__00 const & rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    bool result = std::strcmp(left, right) < 0;
    delete[] left;
    delete[] right;
    return result;
}

// -----------------------------------------------------------------------------
// Standard Library
// -----------------------------------------------------------------------------

std::map<string__00, string__00> resourceValues;

string__00 const & ResourceManager::GetString__1(string__00 resourceName)
{
    return resourceValues.at(resourceName);
}
void ResourceManager::AddResource(string__00 name, string__00 value)
{
    resourceValues.insert(std::make_pair(name, value));
}

ResourceManager *const resource_manager__ = new ResourceManager();

void debug_write__1(string__00 value)
{
    std::fprintf(stderr, "%.*s", value.Length, value.Buffer);
}
void debug_write_line__1(string__00 value)
{
    std::fprintf(stderr, "%.*s\n", value.Length, value.Buffer);
}
void debug_write_line__0()
{
    std::fprintf(stderr, "\n");
}

void system__console__Console__0::Write__1(string__00 value)
{
    std::printf("%.*s", value.Length, value.Buffer);
}

void system__console__Console__0::WriteLine__1(string__00 value)
{
    std::printf("%.*s\n", value.Length, value.Buffer);
}

void system__console__Console__0::WriteLine__0()
{
    std::printf("\n");
}

system__console__Arguments__0::system__console__Arguments__0(int argc, char const *const * argv)
    : Count(argc-1)
{
    args = new string__00[Count];
    for (int i = 0; i < Count; i++)
        args[i] = string__00(argv[i+1]);
}

system__io__File_Reader__0 *_Nonnull system__io__File_Reader__0__0new__1(system__io__File_Reader__0 *_Nonnull self, const string__00& fileName)
{
    char const *_Nonnull fname = fileName.cstr();
    self->file = std::fopen(fname, "rb");
    delete[] fname;
    return self;
}

string__00 system__io__File_Reader__0::ReadToEndSync__0()
{
    std::fseek(file, 0, SEEK_END);
    auto length = std::ftell(file);
    std::fseek(file, 0, SEEK_SET);
    auto buffer = new char[length];
    length = std::fread(buffer, sizeof(char), length, file);
    return string__00(length, buffer);
}

void system__io__File_Reader__0::Close__0()
{
    std::fclose(file);
}

system__io__File_Writer__0 *_Nonnull system__io__File_Writer__0__0new__1(system__io__File_Writer__0 *_Nonnull self, const string__00& fileName)
{
    char const *_Nonnull fname = fileName.cstr();
    self->file = std::fopen(fname, "wb"); // TODO check error
    delete[] fname;
    return self;
}

void system__io__File_Writer__0::Write__1(const string__00& value)
{
    std::fwrite(value.Buffer, sizeof(char), value.Length, file);
}

void system__io__File_Writer__0::Close__0()
{
    std::fclose(file);
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
            std::memcpy(new_buffer, buffer, length);

        if(capacity > 0)
            delete[] buffer;

        buffer = new_buffer;
        capacity = new_capacity;
    }
}

system__text__String_Builder__0 *_Nonnull system__text__String_Builder__0__0new__1(system__text__String_Builder__0 *_Nonnull self, string__00 const & value)
{
    system__text__String_Builder__0__0new__0(self);
    self->ensure_capacity(value.Length);
    std::memcpy(self->buffer, value.Buffer, value.Length);
    self->length = value.Length;
    return self;
}

system__text__String_Builder__0 *_Nonnull new_system__text__String_Builder__0__0new__with_capacity__1(system__text__String_Builder__0 *_Nonnull self, int__00 capacity)
{
    system__text__String_Builder__0__0new__0(self);
    self->ensure_capacity(capacity.value);
    return self;
}

void system__text__String_Builder__0::Append__1(string__00 const & value)
{
    int new_length = length + value.Length;
    ensure_capacity(new_length);
    std::memcpy(buffer+length, value.Buffer, value.Length);
    length = new_length;
}

void system__text__String_Builder__0::Append__1(system__text__String_Builder__0 const *_Nonnull value)
{
    int new_length = length + value->length;
    ensure_capacity(new_length);
    std::memcpy(buffer+length, value->buffer, value->length);
    length = new_length;
}

void system__text__String_Builder__0::AppendLine__1(string__00 const & value)
{
    int new_length = length + value.Length + 1;
    ensure_capacity(new_length);
    std::memcpy(buffer+length, value.Buffer, value.Length);
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

void system__text__String_Builder__0::Remove__2(int__00 start, int__00 length)
{
    if(start.value >= this->length)
        throw std::runtime_error("String_Builder.Remove() start >= length");

    int end = start.value + length.value;
    if(end > this->length) // greater than because end is one past the end of the remove
        throw std::runtime_error("String_Builder.Remove() end > length");

    std::memmove(buffer+start.value, buffer+end, this->length-end);
    this->length -= length.value;
}

void system__text__String_Builder__0::Remove__1(int__00 start)
{
    if(start.value >= length)
        throw std::runtime_error("String_Builder.Remove() start >= length");

    length = start.value;
}

string__00 system__text__String_Builder__0::ToString__0()
{
    string__00 result(length, buffer);
    // give up ownership of buffer
    buffer = 0;
    length = 0;
    capacity = 0;
    return result;
}
