#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__0() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main__0() -> void
{
	bit x__;
	x__ = bit__op(bit__arg(bit__op__not(bit__true)) && bit__arg(bit__false));
	x__ = bit__op(bit__arg(bit__op__not(bit__true)) || bit__arg(bit__false));
	x__ = bit__op(bit__arg(bit__false) || bit__arg(bit__op(bit__arg(bit__true) && bit__arg(bit__true))));
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
