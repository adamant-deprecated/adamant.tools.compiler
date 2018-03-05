#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_() -> p_int;
auto Func_() -> p_int;

// Class Declarations

// Global Definitions

// Definitions

auto Main_() -> p_int
{
	return Func_();
}

auto Func_() -> p_int
{
	return p_int(42);
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