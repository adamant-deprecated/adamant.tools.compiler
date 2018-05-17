#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__0() -> i32;

// Class Declarations

// Global Definitions

// Definitions

auto main__0() -> i32
{
	if (cond(bit__false))
	{
		return i32(0);
	}
	else if (cond(bit__false))
	{
		return i32(42);
	}
	else if (cond(bit__false))
	{
		return i32(10);
	}
	else
	{
		return i32(0);
	}
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		return main__0().value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
