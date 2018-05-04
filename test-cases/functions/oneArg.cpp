#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Identity_(i32 const value_) -> i32;
auto main_() -> i32;

// Class Declarations

// Global Definitions

// Definitions

auto Identity_(i32 const value_) -> i32
{
	return value_;
}

auto main_() -> i32
{
	return Identity_(i32(42));
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
