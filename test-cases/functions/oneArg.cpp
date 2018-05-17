#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Identity__1(int__00 const value__) -> int__00;
auto main__0() -> int__00;

// Class Declarations

// Global Definitions

// Definitions

auto Identity__1(int__00 const value__) -> int__00
{
	return value__;
}

auto main__0() -> int__00
{
	return Identity__1(int__00(42));
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
