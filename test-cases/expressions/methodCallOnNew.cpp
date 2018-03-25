#include "RuntimeLibrary.h"

// Type Declarations
class Test_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class Test_
{
public:
	p_bool op_equal(Test_ const * other) const { return this == other; }
	p_bool op_not_equal(Test_ const * other) const { return this != other; }
	p_bool value_;
	auto construct() -> ::Test_*;
};

// Global Definitions

// Definitions

auto ::Test_::construct() -> ::Test_*
{
	::Test_* self = this;
	value_ = p_bool(true);
	return self;
}

auto Main_() -> void
{
	p_bool const value_ = (new ::Test_())->construct()->value_;
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