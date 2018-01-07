#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Identity_(p_code_point const value_) -> p_code_point;
auto Main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Identity_(p_code_point const value_) -> p_code_point
{
	return value_;
}

auto Main_() -> void
{
	Identity_(p_code_point('a'));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		Main_();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
