#include "RuntimeLibrary.hpp"

// Type Declarations
class Test_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class Test_
{
public:
	bit value_;
	auto construct() -> ::Test_*;
};

// Global Definitions

// Definitions

auto ::Test_::construct() -> ::Test_*
{
	::Test_* self = this;
	value_ = bit_true;
	return self;
}

auto Main_() -> void
{
	bit const value_ = (new ::Test_())->construct()->value_;
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
