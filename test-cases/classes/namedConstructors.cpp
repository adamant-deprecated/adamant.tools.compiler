#include "RuntimeLibrary.hpp"

// Type Declarations
class C_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class C_
{
public:
	p_string name_;
	p_int kind_;
	auto construct(p_string const name_) -> ::C_*;
	auto construct_one(p_string const name_) -> ::C_*;
	auto construct_two(p_string const name_) -> ::C_*;
};

// Global Definitions

// Definitions

auto ::C_::construct(p_string const name_) -> ::C_*
{
	::C_* self = this;
	self->name_ = name_;
	self->kind_ = p_int(0);
	return self;
}

auto ::C_::construct_one(p_string const name_) -> ::C_*
{
	::C_* self = this;
	self->name_ = name_;
	self->kind_ = p_int(1);
	return self;
}

auto ::C_::construct_two(p_string const name_) -> ::C_*
{
	::C_* self = this;
	self->name_ = name_;
	self->kind_ = p_int(2);
	return self;
}

auto Main_() -> void
{
	(new ::C_())->construct(p_string("0"));
	(new ::C_())->construct_one(p_string("1"));
	(new ::C_())->construct_two(p_string("2"));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		Main_();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
