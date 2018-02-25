#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_() -> p_int;

// Class Declarations

// Global Definitions

// Definitions

auto Main_() -> p_int
{
	if (p_bool(false).Value)
	{
		return p_int(0);
	}
	else if (p_bool(false).Value)
	{
		return p_int(42);
	}
	else if (p_bool(false).Value)
	{
		return p_int(10);
	}
	else
	{
		return p_int(0);
	}
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		return Main_().Value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
