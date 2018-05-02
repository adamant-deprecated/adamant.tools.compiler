#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Main_() -> i32;

// Class Declarations

// Global Definitions

// Definitions

auto Main_() -> i32
{
	str const s_ = str("abc");
	return s_.index_of_(cp('c'));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		return Main_().value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
