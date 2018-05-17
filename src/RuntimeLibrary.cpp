#include "RuntimeLibrary.hpp"
#include <map>

// -----------------------------------------------------------------------------
// Primitive Types
// -----------------------------------------------------------------------------

u32 i32::as_uint_() const
{
    if(this->value < 0)
        throw std::range_error("Can't convert negative number to unsigned");

    return u32(this->value);
}

char code_point__to_char(code_point v)
{
    if(v.value > 0xFF)
        throw std::range_error("Unicode char values not yet supported");

    return v.value;
}

string string::construct(code_point c, i32 repeat)
{
    string self;
    self.Length = repeat.value;
    char* buffer = new char[repeat.value];
    for (int i = 0; i < repeat.value; i++)
        buffer[i] = code_point__to_char(c);

    self.Buffer = buffer;
    return self;
}

string::string(const char* s)
    : Length(std::strlen(s)), Buffer(s)
{
}

string::string(int length, const char* s)
    : Length(length), Buffer(s)
{
}

char const * string::cstr() const
{
    auto buffer = new char[Length + 1];
    std::memcpy(buffer, Buffer, Length);
    buffer[Length] = 0;
    return buffer;
}

string::string(i32 other)
    : Length(0), Buffer(0)
{
    char* buffer = new char[12]; // -2,147,483,648 to 2,147,483,647 plus null terminator
    int length = std::sprintf(buffer,"%d", other.value);
    if(length <= 0) throw std::runtime_error("Could not convert int to string");
    Length = length;
    Buffer = buffer;
}

string::string(code_point other)
    : Length(1), Buffer(new char[1] { code_point__to_char(other) })
{
}

string::string(bit other)
    : string(other.value ? "true" : "false")
{
}

string string::Substring_(i32 start, i32 length) const
{
    return string(length.value, Buffer + start.value);
}

string string::Replace_(string oldValue, string newValue) const
{
    system__text__String_Builder builder = system__text__String_Builder(); // TODO initialize capacity
    int limit = Length - oldValue.Length + 1;
    int lastIndex = 0;
    // TODO the Substring calls in here are leaking memory
    for(int i=0; i < limit; i++)
        if (cond(equal_op(Substring_(i32(i), i32(oldValue.Length)), oldValue)))
        {
            builder.Append_(Substring_(i32(lastIndex), i32(i-lastIndex)));
            builder.Append_(newValue);
            i += oldValue.Length; // skip over the value we just matched
            lastIndex = i;
            i--; // we need i-- to offset the i++ that is about to happen
        }

    builder.Append_(Substring_(i32(lastIndex), i32(Length - lastIndex)));
    return builder.ToString_();
}

i32 string::LastIndexOf_(code_point c) const
{
    for(int i = Length - 1; i >= 0; i--)
        if(Buffer[i] == code_point__to_char(c))
            return i32(i);

    return i32(-1); // TODO should return none
}

i32 string::index_of_(code_point c) const
{
    for(int i = 0; i < Length; i++)
        if(Buffer[i] == code_point__to_char(c))
            return i32(i);

    return i32(-1);
}

string string::op__add(string const & value) const
{
    int newLength = Length + value.Length;
    char* chars = new char[newLength];
    size_t offset = sizeof(char) * Length;
    std::memcpy(chars, Buffer, offset);
    std::memcpy(chars + offset, value.Buffer, value.Length);
    return string(newLength, chars);
}

auto equal_op(string lhs, string rhs) -> bit
{
    if (lhs.Length != rhs.Length)
        return bit__false;

    for (int i = 0; i < lhs.Length; i++)
        if (lhs.Buffer[i] != rhs.Buffer[i])
            return bit__false;

    return bit__true;
}

bit string__op__less_than(string lhs, string rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    bool result = std::strcmp(left, right) < 0;
    delete[] left;
    delete[] right;
    return bit_from(result);
}
bit string__op__less_than_or_equal(string lhs, string rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    bool result = std::strcmp(left, right) <= 0;
    delete[] left;
    delete[] right;
    return bit_from(result);
}
bit string__op__greater_than(string lhs, string rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    bool result = std::strcmp(left, right) > 0;
    delete[] left;
    delete[] right;
    return bit_from(result);
}
bit string__op__greater_than_or_equal(string lhs, string rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    bool result = std::strcmp(left, right) >= 0;
    delete[] left;
    delete[] right;
    return bit_from(result);
}

bool operator < (string const & lhs, string const & rhs)
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

std::map<string, string> resourceValues;

string const & ResourceManager::GetString_(string resourceName)
{
    return resourceValues.at(resourceName);
}
void ResourceManager::AddResource(string name, string value)
{
    resourceValues.insert(std::make_pair(name, value));
}

ResourceManager *const resource_manager_ = new ResourceManager();

void debug_write_(string value)
{
    std::fprintf(stderr, "%.*s", value.Length, value.Buffer);
}
void debug_write_line_(string value)
{
    std::fprintf(stderr, "%.*s\n", value.Length, value.Buffer);
}
void debug_write_line_()
{
    std::fprintf(stderr, "\n");
}

void system__console__Console::Write_(string value)
{
    std::printf("%.*s", value.Length, value.Buffer);
}

void system__console__Console::WriteLine_(string value)
{
    std::printf("%.*s\n", value.Length, value.Buffer);
}

void system__console__Console::WriteLine_()
{
    std::printf("\n");
}

system__console__Arguments::system__console__Arguments(int argc, char const *const * argv)
    : Count(argc-1)
{
    args = new string[Count];
    for (int i = 0; i < Count; i++)
        args[i] = string(argv[i+1]);
}

system__io__File_Reader *_Nonnull system__io__File_Reader::construct(const string& fileName)
{
    std::FILE* foo;
    auto fname = fileName.cstr();
    file = std::fopen(fname, "rb");
    delete[] fname;
    return this;
}

string system__io__File_Reader::ReadToEndSync_()
{
    std::fseek(file, 0, SEEK_END);
    auto length = std::ftell(file);
    std::fseek(file, 0, SEEK_SET);
    auto buffer = new char[length];
    length = std::fread(buffer, sizeof(char), length, file);
    return string(length, buffer);
}

void system__io__File_Reader::Close_()
{
    std::fclose(file);
}

system__io__File_Writer *_Nonnull system__io__File_Writer::construct(const string& fileName)
{
    auto fname = fileName.cstr();
    file = std::fopen(fname, "wb"); // TODO check error
    delete[] fname;
    return this;
}

void system__io__File_Writer::Write_(const string& value)
{
    std::fwrite(value.Buffer, sizeof(char), value.Length, file);
}

void system__io__File_Writer::Close_()
{
    std::fclose(file);
}

void system__text__String_Builder::ensure_capacity(int needed)
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

system__text__String_Builder *_Nonnull system__text__String_Builder::construct(string const & value)
{
    ensure_capacity(value.Length);
    std::memcpy(buffer, value.Buffer, value.Length);
    length = value.Length;
    return this;
}

system__text__String_Builder *_Nonnull system__text__String_Builder::construct_with_capacity(i32 capacity)
{
    ensure_capacity(capacity.value);
    return this;
}

void system__text__String_Builder::Append_(string const & value)
{
    int new_length = length + value.Length;
    ensure_capacity(new_length);
    std::memcpy(buffer+length, value.Buffer, value.Length);
    length = new_length;
}

void system__text__String_Builder::Append_(system__text__String_Builder const *_Nonnull value)
{
    int new_length = length + value->length;
    ensure_capacity(new_length);
    std::memcpy(buffer+length, value->buffer, value->length);
    length = new_length;
}

void system__text__String_Builder::AppendLine_(string const & value)
{
    int new_length = length + value.Length + 1;
    ensure_capacity(new_length);
    std::memcpy(buffer+length, value.Buffer, value.Length);
    buffer[new_length-1] = '\n';
    length = new_length;
}

void system__text__String_Builder::AppendLine_()
{
    int new_length = length + 1;
    ensure_capacity(new_length);
    buffer[new_length-1] = '\n';
    length = new_length;
}

void system__text__String_Builder::Remove_(i32 start, i32 length)
{
    if(start.value >= this->length)
        throw std::runtime_error("String_Builder.Remove() start >= length");

    int end = start.value + length.value;
    if(end > this->length) // greater than because end is one past the end of the remove
        throw std::runtime_error("String_Builder.Remove() end > length");

    std::memmove(buffer+start.value, buffer+end, this->length-end);
    this->length -= length.value;
}

void system__text__String_Builder::Remove_(i32 start)
{
    if(start.value >= length)
        throw std::runtime_error("String_Builder.Remove() start >= length");

    length = start.value;
}

string system__text__String_Builder::ToString_()
{
    string result(length, buffer);
    // give up ownership of buffer
    buffer = 0;
    length = 0;
    capacity = 0;
    return result;
}
