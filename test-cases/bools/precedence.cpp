#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__0() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main__0() -> void
{
	bool__00 x__;
	x__ = bool__00__op(bool__00__arg(bool__00__op__not(true__00)) && bool__00__arg(false__00));
	x__ = bool__00__op(bool__00__arg(bool__00__op__not(true__00)) || bool__00__arg(false__00));
	x__ = bool__00__op(bool__00__arg(false__00) || bool__00__arg(bool__00__op(bool__00__arg(true__00) && bool__00__arg(true__00))));
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
