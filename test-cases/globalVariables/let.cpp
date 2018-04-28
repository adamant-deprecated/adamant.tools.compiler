#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Main_() -> p_int;

// Class Declarations

// Global Definitions
p_int const Result_ = p_int(42);

// Definitions

auto Main_() -> p_int
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
