#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Func__1(bool__00 const value__) -> bool__00;
auto main__0() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Func__1(bool__00 const value__) -> bool__00
{
	return false__00;
}

auto main__0() -> void
{
	Func__1(true__00);
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
