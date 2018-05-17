#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto True__0() -> bit;
auto main__0() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto True__0() -> bit
{
	return bit__true;
}

auto main__0() -> void
{
	bit x__;
	x__ = bit__op(bit__arg(bit__true) && bit__arg(bit__false));
	x__ = bit__op(bit__arg(bit__true) || bit__arg(bit__false));
	x__ = bit__op__not(bit__true);
	x__ = bit__op(bit__arg(True__0()) || bit__arg(True__0()));
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
