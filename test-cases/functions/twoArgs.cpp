#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Func__2(i32 const a__, i32 const b__) -> i32;
auto main__0() -> i32;

// Class Declarations

// Global Definitions

// Definitions

auto Func__2(i32 const a__, i32 const b__) -> i32
{
	return b__;
}

auto main__0() -> i32
{
	return Func__2(i32(0), i32(42));
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
