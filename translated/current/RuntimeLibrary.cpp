#include "RuntimeLibrary.h"
#include <map>

p_uint p_int::AsUInt_() const
{
	if(this->Value < 0)
		throw "Can't convert negative number to unsigned";

	return this->Value;
}

char p_code_point::CharValue() const
{
	if(this->Value > 0xFF)
		throw "Unicode char values not yet supported";

	return this->Value;
}

p_string::p_string()
	: Length_(0), Buffer(0)
{
}

p_string::p_string(p_code_point c, p_int repeat)
	: Length_(repeat)
{
	char* buffer = new char[repeat.Value];
	for (int i = 0; i < repeat.Value; i++)
		buffer[i] = c.CharValue();

	Buffer = buffer;
}

p_string::p_string(const char* s)
	: Length_(std::strlen(s)), Buffer(s)
{
}

p_string::p_string(int length, const char* s)
	: Length_(length), Buffer(s)
{
}

char const * p_string::cstr() const
{
	auto buffer = new char[Length_.Value + 1];
	std::memcpy(buffer, Buffer, Length_.Value);
	buffer[Length_.Value] = 0;
	return buffer;
}

p_string::p_string(p_int other)
	: Length_(0), Buffer(0)
{
	char* buffer = new char[12]; // -2,147,483,648 to 2,147,483,647 plus null terminator
	std::sprintf(buffer,"%d", other.Value);
	Length_ = std::strlen(buffer);
	Buffer = buffer;
}

p_string p_string::Substring_(p_int start, p_int length) const
{
	return p_string(length.Value, Buffer + start.Value);
}

p_string p_string::Replace_(p_string oldValue, p_string newValue) const
{
	p_string buffer = "";
	int limit = Length_.Value - oldValue.Length_.Value + 1;
	int lastIndex = 0;
	for(int i=0; i < limit; i++)
		if (Substring_(i, oldValue.Length_).op_Equal(oldValue).Value)
		{
			buffer = buffer.op_Plus(Substring_(lastIndex, i-lastIndex)).op_Plus(newValue);
			i += oldValue.Length_.Value; // skip over the value we just matched
			lastIndex = i;
			i--; // we need i-- to offset the i++ that is about to happen
		}

	buffer = buffer.op_Plus(Substring_(lastIndex, Length_.Value - lastIndex));
	return buffer;
}

p_int p_string::LastIndexOf_(p_code_point c) const
{
	for(int i = Length_.Value - 1; i >= 0; i--)
		if(Buffer[i] == c.CharValue())
			return i;

	return -1;
}

p_string p_string::op_Plus(p_string const & value) const
{
	int newLength = Length_.Value + value.Length_.Value;
	char* chars = new char[newLength];
	size_t offset = sizeof(char) * Length_.Value;
	std::memcpy(chars, Buffer, offset);
	std::memcpy(chars + offset, value.Buffer, value.Length_.Value);
	return p_string(newLength, chars);
}

p_bool p_string::op_Equal(p_string const & other) const
{
	if (Length_.Value != other.Length_.Value)
		return false;

	for (int i = 0; i < Length_.Value; i++)
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

namespace System_
{
	namespace Console_
	{
		void Console_::Write_(p_string value)
		{
			std::printf("%.*s", value.Length_.Value, value.Buffer);
		}

		void Console_::WriteLine_(p_string value)
		{
			std::printf("%.*s\n", value.Length_.Value, value.Buffer);
		}

		void Console_::WriteLine_()
		{
			std::printf("\n");
		}

		Arguments_::Arguments_(int argc, char const *const * argv)
			: Count_(argc-1)
		{
			args = new p_string[Count_];
			for (int i = 0; i < Count_; i++)
				args[i] = p_string(argv[i+1]);
		}
	}

	namespace IO_
	{
		File_Reader_::File_Reader_(const p_string& fileName)
		{
			std::FILE* foo;
			auto fname = fileName.cstr();
			file = std::fopen(fname, "rb");
			delete[] fname;
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

		File_Writer_::File_Writer_(const p_string& fileName)
		{
			auto fname = fileName.cstr();
			file = std::fopen(fname, "wb"); // TODO check error
			delete[] fname;
		}

		void File_Writer_::Write_(const p_string& value)
		{
			std::fwrite(value.Buffer, sizeof(char), value.Length_.Value, file);
		}

		void File_Writer_::Close_()
		{
			std::fclose(file);
		}
	}

	namespace Text_
	{
		String_Builder_::String_Builder_(p_string const & value)
			: buffer(value)
		{
		}

		String_Builder_::String_Builder_()
			: buffer("")
		{
		}

		void String_Builder_::Append_(p_string const & value)
		{
			buffer = buffer.op_Plus(value);
		}

		void String_Builder_::Append_(String_Builder_ const * value)
		{
			buffer = buffer.op_Plus(value->buffer);
		}

		void String_Builder_::AppendLine_(p_string const & value)
		{
			buffer = buffer.op_Plus(value).op_Plus(p_string("\n"));
		}

		void String_Builder_::AppendLine_()
		{
			buffer = buffer.op_Plus(p_string("\n"));
		}

		void String_Builder_::Remove_(p_int start, p_int length)
		{
			buffer = buffer.Substring_(0, start).op_Plus(buffer.Substring_(start.Value+length.Value));
		}

		void String_Builder_::Remove_(p_int start)
		{
			String_Builder_::Remove_(start, buffer.Length_.Value-start.Value);
		}
	}
}
