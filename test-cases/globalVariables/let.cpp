#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Main_() -> i32;

// Class Declarations

// Global Definitions
i32 const Result_ = i32(42);

// Definitions

auto Main_() -> i32
{
	return Result_;
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
