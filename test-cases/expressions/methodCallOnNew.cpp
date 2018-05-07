#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Test;

// Function Declarations
auto main_() -> void;

// Class Declarations

class t_Test
{
public:
	bit value_;
	auto construct() -> ::t_Test*;
};

// Global Definitions

// Definitions

auto ::t_Test::construct() -> ::t_Test*
{
	::t_Test* self = this;
	value_ = bit_true;
	return self;
}

auto main_() -> void
{
	bit const value_ = (new t_Test())->construct()->value_;
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
