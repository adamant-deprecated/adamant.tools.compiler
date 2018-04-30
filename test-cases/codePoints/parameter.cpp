#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Identity_(cp const value_) -> cp;
auto Main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Identity_(cp const value_) -> cp
{
	return value_;
}

auto Main_() -> void
{
	Identity_(cp('a'));
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
