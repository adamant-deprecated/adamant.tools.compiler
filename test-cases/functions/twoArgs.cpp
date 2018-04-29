#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Func_(i32 const a_, i32 const b_) -> i32;
auto Main_() -> i32;

// Class Declarations

// Global Definitions

// Definitions

auto Func_(i32 const a_, i32 const b_) -> i32
{
	return b_;
}

auto Main_() -> i32
{
	return Func_(i32(0), i32(42));
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
