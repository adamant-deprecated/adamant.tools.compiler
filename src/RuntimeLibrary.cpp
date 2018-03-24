#include "RuntimeLibrary.h"
#include <map>

p_uint p_int::AsUInt_() const
{
	if(this->value < 0)
		throw std::range_error("Can't convert negative number to unsigned");

	return this->value;
}

char p_code_point::CharValue() const
{
	if(this->value > 0xFF)
		throw std::range_error("Unicode char values not yet supported");

	return this->value;
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
	p_string buffer = "";
	int limit = Length - oldValue.Length + 1;
	int lastIndex = 0;
	for(int i=0; i < limit; i++)
		if (Substring_(i, oldValue.Length).op_equal(oldValue).value)
		{
			buffer = buffer.op_add(Substring_(lastIndex, i-lastIndex)).op_add(newValue);
			i += oldValue.Length; // skip over the value we just matched
			lastIndex = i;
			i--; // we need i-- to offset the i++ that is about to happen
		}

	buffer = buffer.op_add(Substring_(lastIndex, Length - lastIndex));
	return buffer;
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

p_bool p_string::op_equal(p_string const & other) const
{
	if (Length != other.Length)
		return false;

	for (int i = 0; i < Length; i++)
		if (Buffer[i] != other.Buffer[i])
			return false;

	return true;
}

bool operator < (p_string const & lhs, p_string const & rhs)
{
    return std::strcmp(lhs.cstr(), rhs.cstr()) < 0;
}

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
		String_Builder_* String_Builder_::construct(p_string const & value)
		{
			buffer = value;
			return this;
		}

		void String_Builder_::Append_(p_string const & value)
		{
			buffer = buffer.op_add(value);
		}

		void String_Builder_::Append_(String_Builder_ const * value)
		{
			buffer = buffer.op_add(value->buffer);
		}

		void String_Builder_::AppendLine_(p_string const & value)
		{
			buffer = buffer.op_add(value).op_add(p_string("\n"));
		}

		void String_Builder_::AppendLine_()
		{
			buffer = buffer.op_add(p_string("\n"));
		}

		void String_Builder_::Remove_(p_int start, p_int length)
		{
			buffer = buffer.Substring_(0, start).op_add(buffer.Substring_(start.value+length.value));
		}

		void String_Builder_::Remove_(p_int start)
		{
			String_Builder_::Remove_(start, buffer.Length-start.value);
		}
	}
}