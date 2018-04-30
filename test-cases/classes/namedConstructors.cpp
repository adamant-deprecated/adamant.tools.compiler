#include "RuntimeLibrary.hpp"

// Type Declarations
class C_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class C_
{
public:
	str name_;
	i32 kind_;
	auto construct(str const name_) -> ::C_*;
	auto construct_one(str const name_) -> ::C_*;
	auto construct_two(str const name_) -> ::C_*;
};

// Global Definitions

// Definitions

auto ::C_::construct(str const name_) -> ::C_*
{
	::C_* self = this;
	self->name_ = name_;
	self->kind_ = i32(0);
	return self;
}

auto ::C_::construct_one(str const name_) -> ::C_*
{
	::C_* self = this;
	self->name_ = name_;
	self->kind_ = i32(1);
	return self;
}

auto ::C_::construct_two(str const name_) -> ::C_*
{
	::C_* self = this;
	self->name_ = name_;
	self->kind_ = i32(2);
	return self;
}

auto Main_() -> void
{
	(new ::C_())->construct(str("0"));
	(new ::C_())->construct_one(str("1"));
	(new ::C_())->construct_two(str("2"));
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
