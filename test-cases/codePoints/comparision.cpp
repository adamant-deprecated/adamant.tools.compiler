#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__0() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main__0() -> void
{
	bool__00 x__;
	x__ = code_point__00__op__less_than(code_point__00('a'), code_point__00('b'));
	x__ = code_point__00__op__less_than_or_equal(code_point__00('a'), code_point__00('b'));
	x__ = code_point__00__op__greater_than(code_point__00('a'), code_point__00('b'));
	x__ = code_point__00__op__greater_than_or_equal(code_point__00('a'), code_point__00('b'));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__0();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
