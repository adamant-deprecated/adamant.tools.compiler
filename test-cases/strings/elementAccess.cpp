#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__0() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main__0() -> void
{
	code_point__00 result__;
	result__ = string__00("hello").op__Element(int__00(0));
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
