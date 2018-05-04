#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main_() -> i32;

// Class Declarations

// Global Definitions

// Definitions

auto main_() -> i32
{
	if (cond(bit_true))
	{
		return i32(0);
	}
	else
	{
		return i32(42);
	}
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		return main_().value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
