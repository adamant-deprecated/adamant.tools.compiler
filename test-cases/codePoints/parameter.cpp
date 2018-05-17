#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Identity__1(code_point const value__) -> code_point;
auto main__0() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Identity__1(code_point const value__) -> code_point
{
	return value__;
}

auto main__0() -> void
{
	Identity__1(code_point('a'));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__0();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
