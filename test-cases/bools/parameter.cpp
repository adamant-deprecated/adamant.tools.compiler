#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Func_(bit const value_) -> bit;
auto Main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Func_(bit const value_) -> bit
{
	return bit_false;
}

auto Main_() -> void
{
	Func_(bit_true);
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
