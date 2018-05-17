#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Func__1(bit const value__) -> bit;
auto main__0() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Func__1(bit const value__) -> bit
{
	return bit__false;
}

auto main__0() -> void
{
	Func__1(bit__true);
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
