#include "RuntimeLibrary.hpp"
#include <map>

// -----------------------------------------------------------------------------
// Primitive Types
// -----------------------------------------------------------------------------

p_uint p_int::AsUInt_() const
{
    if(this->value < 0)
        throw std::range_error("Can't convert negative number to unsigned");

    return this->value;
}

char p_code_point::CharValue() const
{
    if(this->raw_value > 0xFF)
        throw std::range_error("Unicode char values not yet supported");

    return this->raw_value;
}

p_string p_string::construct(p_code_point c, p_int repeat)
{
    p_string self;
    self.Length = repeat.value;
    char* buffer = new char[repeat.value];
    for (int i = 0; i < repeat.value; i++)
        buffer[i] = c.CharValue();

    self.Buffer = buffer;
    return self;
}

p_string::p_string(const char* s)
    : Length(std::strlen(s)), Buffer(s)
{
}

p_string::p_string(int length, const char* s)
    : Length(length), Buffer(s)
{
}

char const * p_string::cstr() const
{
    auto buffer = new char[Length + 1];
    std::memcpy(buffer, Buffer, Length);
    buffer[Length] = 0;
    return buffer;
}

p_string::p_string(p_int other)
    : Length(0), Buffer(0)
{
    char* buffer = new char[12]; // -2,147,483,648 to 2,147,483,647 plus null terminator
    int length = std::sprintf(buffer,"%d", other.value);
    if(length <= 0) throw std::runtime_error("Could not convert int to string");
    Length = length;
    Buffer = buffer;
}

p_string::p_string(p_code_point other)
    : Length(1), Buffer(new char[1] { other.CharValue() })
{
}

p_string p_string::Substring_(p_int start, p_int length) const
{
    return p_string(length.value, Buffer + start.value);
}

p_string p_string::Replace_(p_string oldValue, p_string newValue) const
{
    system_::Text_::String_Builder_ builder = system_::Text_::String_Builder_(); // TODO initialize capacity
    int limit = Length - oldValue.Length + 1;
    int lastIndex = 0;
    // TODO the Substring calls in here are leaking memory
    for(int i=0; i < limit; i++)
        if (equal_op(Substring_(i, oldValue.Length), oldValue).value)
        {
            builder.Append_(Substring_(lastIndex, i-lastIndex));
            builder.Append_(newValue);
            i += oldValue.Length; // skip over the value we just matched
            lastIndex = i;
            i--; // we need i-- to offset the i++ that is about to happen
        }

    builder.Append_(Substring_(lastIndex, Length - lastIndex));
    return builder.ToString_();
}

p_int p_string::LastIndexOf_(p_code_point c) const
{
    for(int i = Length - 1; i >= 0; i--)
        if(Buffer[i] == c.CharValue())
            return i;

    return -1; // TODO should return none
}

p_int p_string::index_of_(p_code_point c) const
{
    for(int i = 0; i < Length; i++)
        if(Buffer[i] == c.CharValue())
            return i;

    return -1;
}

p_string p_string::op_add(p_string const & value) const
{
    int newLength = Length + value.Length;
    char* chars = new char[newLength];
    size_t offset = sizeof(char) * Length;
    std::memcpy(chars, Buffer, offset);
    std::memcpy(chars + offset, value.Buffer, value.Length);
    return p_string(newLength, chars);
}

auto equal_op(p_string lhs, p_string rhs) -> p_bool
{
    if (lhs.Length != rhs.Length)
        return p_bool(false);

    for (int i = 0; i < lhs.Length; i++)
        if (lhs.Buffer[i] != rhs.Buffer[i])
            return p_bool(false);

    return p_bool(true);
}

p_bool p_string::op_less_than(p_string other) const
{
    char const* left = this->cstr();
    char const* right = other.cstr();
    bool result = std::strcmp(left, right) < 0;
    delete[] left;
    delete[] right;
    return p_bool(result);
}

p_bool p_string::op_less_than_or_equal(p_string other) const
{
    char const* left = this->cstr();
    char const* right = other.cstr();
    bool result = std::strcmp(left, right) <= 0;
    delete[] left;
    delete[] right;
    return p_bool(result);
}

p_bool p_string::op_greater_than(p_string other) const
{
    char const* left = this->cstr();
    char const* right = other.cstr();
    bool result = std::strcmp(left, right) > 0;
    delete[] left;
    delete[] right;
    return p_bool(result);
}

p_bool p_string::op_greater_than_or_equal(p_string other) const
{
    char const* left = this->cstr();
    char const* right = other.cstr();
    bool result = std::strcmp(left, right) >= 0;
    delete[] left;
    delete[] right;
    return p_bool(result);
}

bool operator < (p_string const & lhs, p_string const & rhs)
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

std::map<p_string, p_string> resourceValues;

p_string const & ResourceManager::GetString_(p_string resourceName)
{
    return resourceValues.at(resourceName);
}
void ResourceManager::AddResource(p_string name, p_string value)
{
    resourceValues.insert(std::make_pair(name, value));
}

ResourceManager *const resource_manager_ = new ResourceManager();

void debug_write_(p_string value)
{
    std::fprintf(stderr, "%.*s", value.Length, value.Buffer);
}
void debug_write_line_(p_string value)
{
    std::fprintf(stderr, "%.*s\n", value.Length, value.Buffer);
}
void debug_write_line_()
{
    std::fprintf(stderr, "\n");
}

namespace system_
{
    namespace Console_
    {
        void Console_::Write_(p_string value)
        {
            std::printf("%.*s", value.Length, value.Buffer);
        }

        void Console_::WriteLine_(p_string value)
        {
            std::printf("%.*s\n", value.Length, value.Buffer);
        }

        void Console_::WriteLine_()
        {
            std::printf("\n");
        }

        Arguments_::Arguments_(int argc, char const *const * argv)
            : Count(argc-1)
        {
            args = new p_string[Count];
            for (int i = 0; i < Count; i++)
                args[i] = p_string(argv[i+1]);
        }
    }

    namespace IO_
    {
        File_Reader_* File_Reader_::construct(const p_string& fileName)
        {
            std::FILE* foo;
            auto fname = fileName.cstr();
            file = std::fopen(fname, "rb");
            delete[] fname;
            return this;
        }

        p_string File_Reader_::ReadToEndSync_()
        {
            std::fseek(file, 0, SEEK_END);
            auto length = std::ftell(file);
            std::fseek(file, 0, SEEK_SET);
            auto buffer = new char[length];
            length = std::fread(buffer, sizeof(char), length, file);
            return p_string(length, buffer);
        }

        void File_Reader_::Close_()
        {
            std::fclose(file);
        }

        File_Writer_* File_Writer_::construct(const p_string& fileName)
        {
            auto fname = fileName.cstr();
            file = std::fopen(fname, "wb"); // TODO check error
            delete[] fname;
            return this;
        }

        void File_Writer_::Write_(const p_string& value)
        {
            std::fwrite(value.Buffer, sizeof(char), value.Length, file);
        }

        void File_Writer_::Close_()
        {
            std::fclose(file);
        }
    }

    namespace Text_
    {
        void String_Builder_::ensure_capacity(int needed)
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

        String_Builder_* String_Builder_::construct(p_string const & value)
        {
            ensure_capacity(value.Length);
            std::memcpy(buffer, value.Buffer, value.Length);
            length = value.Length;
            return this;
        }

        String_Builder_ *_Nonnull String_Builder_::construct_with_capacity(p_int capacity)
        {
            ensure_capacity(capacity.value);
            return this;
        }

        void String_Builder_::Append_(p_string const & value)
        {
            int new_length = length + value.Length;
            ensure_capacity(new_length);
            std::memcpy(buffer+length, value.Buffer, value.Length);
            length = new_length;
        }

        void String_Builder_::Append_(String_Builder_ const * value)
        {
            int new_length = length + value->length;
            ensure_capacity(new_length);
            std::memcpy(buffer+length, value->buffer, value->length);
            length = new_length;
        }

        void String_Builder_::AppendLine_(p_string const & value)
        {
            int new_length = length + value.Length + 1;
            ensure_capacity(new_length);
            std::memcpy(buffer+length, value.Buffer, value.Length);
            buffer[new_length-1] = '\n';
            length = new_length;
        }

        void String_Builder_::AppendLine_()
        {
            int new_length = length + 1;
            ensure_capacity(new_length);
            buffer[new_length-1] = '\n';
            length = new_length;
        }

        void String_Builder_::Remove_(p_int start, p_int length)
        {
            if(start.value >= this->length)
                throw std::runtime_error("String_Builder.Remove() start >= length");

            int end = start.value + length.value;
            if(end > this->length) // greater than because end is one past the end of the remove
                throw std::runtime_error("String_Builder.Remove() end > length");

            std::memmove(buffer+start.value, buffer+end, this->length-end);
            this->length -= length.value;
        }

        void String_Builder_::Remove_(p_int start)
        {
            if(start.value >= length)
                throw std::runtime_error("String_Builder.Remove() start >= length");

            length = start.value;
        }

        p_string String_Builder_::ToString_()
        {
            p_string result(length, buffer);
            // give up ownership of buffer
            buffer = 0;
            length = 0;
            capacity = 0;
            return result;
        }
    }
}
