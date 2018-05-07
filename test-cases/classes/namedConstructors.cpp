#include "RuntimeLibrary.hpp"

// Type Declarations
class t_C;

// Function Declarations
auto main_() -> void;

// Class Declarations

class t_C
{
public:
	str name_;
	i32 kind_;
	auto construct(str const name_) -> ::t_C*;
	auto construct_one(str const name_) -> ::t_C*;
	auto construct_two(str const name_) -> ::t_C*;
};

// Global Definitions

// Definitions

auto ::t_C::construct(str const name_) -> ::t_C*
{
	::t_C* self = this;
	self->name_ = name_;
	self->kind_ = i32(0);
	return self;
}

auto ::t_C::construct_one(str const name_) -> ::t_C*
{
	::t_C* self = this;
	self->name_ = name_;
	self->kind_ = i32(1);
	return self;
}

auto ::t_C::construct_two(str const name_) -> ::t_C*
{
	::t_C* self = this;
	self->name_ = name_;
	self->kind_ = i32(2);
	return self;
}

auto main_() -> void
{
	(new t_C())->construct(str("0"));
	(new t_C())->construct_one(str("1"));
	(new t_C())->construct_two(str("2"));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
