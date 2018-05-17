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

char cp_to_char(cp v)
{
    if(v.value > 0xFF)
        throw std::range_error("Unicode char values not yet supported");

    return v.value;
}

str str::construct(cp c, i32 repeat)
{
    str self;
    self.Length = repeat.value;
    char* buffer = new char[repeat.value];
    for (int i = 0; i < repeat.value; i++)
        buffer[i] = cp_to_char(c);

    self.Buffer = buffer;
    return self;
}

str::str(const char* s)
    : Length(std::strlen(s)), Buffer(s)
{
}

str::str(int length, const char* s)
    : Length(length), Buffer(s)
{
}

char const * str::cstr() const
{
    auto buffer = new char[Length + 1];
    std::memcpy(buffer, Buffer, Length);
    buffer[Length] = 0;
    return buffer;
}

str::str(i32 other)
    : Length(0), Buffer(0)
{
    char* buffer = new char[12]; // -2,147,483,648 to 2,147,483,647 plus null terminator
    int length = std::sprintf(buffer,"%d", other.value);
    if(length <= 0) throw std::runtime_error("Could not convert int to string");
    Length = length;
    Buffer = buffer;
}

str::str(cp other)
    : Length(1), Buffer(new char[1] { cp_to_char(other) })
{
}

str::str(bit other)
    : str(other.value ? "true" : "false")
{
}

str str::Substring_(i32 start, i32 length) const
{
    return str(length.value, Buffer + start.value);
}

str str::Replace_(str oldValue, str newValue) const
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

i32 str::LastIndexOf_(cp c) const
{
    for(int i = Length - 1; i >= 0; i--)
        if(Buffer[i] == cp_to_char(c))
            return i32(i);

    return i32(-1); // TODO should return none
}

i32 str::index_of_(cp c) const
{
    for(int i = 0; i < Length; i++)
        if(Buffer[i] == cp_to_char(c))
            return i32(i);

    return i32(-1);
}

str str::op_add(str const & value) const
{
    int newLength = Length + value.Length;
    char* chars = new char[newLength];
    size_t offset = sizeof(char) * Length;
    std::memcpy(chars, Buffer, offset);
    std::memcpy(chars + offset, value.Buffer, value.Length);
    return str(newLength, chars);
}

auto equal_op(str lhs, str rhs) -> bit
{
    if (lhs.Length != rhs.Length)
        return bit_false;

    for (int i = 0; i < lhs.Length; i++)
        if (lhs.Buffer[i] != rhs.Buffer[i])
            return bit_false;

    return bit_true;
}

bit str_less_than(str lhs, str rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    bool result = std::strcmp(left, right) < 0;
    delete[] left;
    delete[] right;
    return bit_from(result);
}
bit str_less_than_or_equal(str lhs, str rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    bool result = std::strcmp(left, right) <= 0;
    delete[] left;
    delete[] right;
    return bit_from(result);
}
bit str_greater_than(str lhs, str rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    bool result = std::strcmp(left, right) > 0;
    delete[] left;
    delete[] right;
    return bit_from(result);
}
bit str_greater_than_or_equal(str lhs, str rhs)
{
    char const* left = lhs.cstr();
    char const* right = rhs.cstr();
    bool result = std::strcmp(left, right) >= 0;
    delete[] left;
    delete[] right;
    return bit_from(result);
}

bool operator < (str const & lhs, str const & rhs)
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

std::map<str, str> resourceValues;

str const & ResourceManager::GetString_(str resourceName)
{
    return resourceValues.at(resourceName);
}
void ResourceManager::AddResource(str name, str value)
{
    resourceValues.insert(std::make_pair(name, value));
}

ResourceManager *const resource_manager_ = new ResourceManager();

void debug_write_(str value)
{
    std::fprintf(stderr, "%.*s", value.Length, value.Buffer);
}
void debug_write_line_(str value)
{
    std::fprintf(stderr, "%.*s\n", value.Length, value.Buffer);
}
void debug_write_line_()
{
    std::fprintf(stderr, "\n");
}

void system__console__Console::Write_(str value)
{
    std::printf("%.*s", value.Length, value.Buffer);
}

void system__console__Console::WriteLine_(str value)
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
    args = new str[Count];
    for (int i = 0; i < Count; i++)
        args[i] = str(argv[i+1]);
}

system__io__File_Reader *_Nonnull system__io__File_Reader::construct(const str& fileName)
{
    std::FILE* foo;
    auto fname = fileName.cstr();
    file = std::fopen(fname, "rb");
    delete[] fname;
    return this;
}

str system__io__File_Reader::ReadToEndSync_()
{
    std::fseek(file, 0, SEEK_END);
    auto length = std::ftell(file);
    std::fseek(file, 0, SEEK_SET);
    auto buffer = new char[length];
    length = std::fread(buffer, sizeof(char), length, file);
    return str(length, buffer);
}

void system__io__File_Reader::Close_()
{
    std::fclose(file);
}

system__io__File_Writer *_Nonnull system__io__File_Writer::construct(const str& fileName)
{
    auto fname = fileName.cstr();
    file = std::fopen(fname, "wb"); // TODO check error
    delete[] fname;
    return this;
}

void system__io__File_Writer::Write_(const str& value)
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

system__text__String_Builder *_Nonnull system__text__String_Builder::construct(str const & value)
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

void system__text__String_Builder::Append_(str const & value)
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

void system__text__String_Builder::AppendLine_(str const & value)
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

str system__text__String_Builder::ToString_()
{
    str result(length, buffer);
    // give up ownership of buffer
    buffer = 0;
    length = 0;
    capacity = 0;
    return result;
}
