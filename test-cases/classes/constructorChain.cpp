#include "RuntimeLibrary.hpp"

// Type Declarations
class C_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class C_
{
public:
	p_bool op_equal(C_ const * other) const { return this == other; }
	p_bool op_not_equal(C_ const * other) const { return this != other; }
	p_string name_;
	auto construct(p_string const name_) -> ::C_*;
	auto method_() const -> p_string;
};

// Global Definitions

// Definitions

auto ::C_::construct(p_string const name_) -> ::C_*
{
	::C_* self = this;
	self->name_ = name_;
	return self;
}

auto ::C_::method_() const -> p_string
{
	auto self = this;
	return name_;
}

auto Main_() -> void
{
	p_string const s_ = (new ::C_())->construct(p_string("Bob"))->method_();
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
