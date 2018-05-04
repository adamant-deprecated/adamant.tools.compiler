#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main_() -> void
{
	bit x_;
	x_ = bit_op(bit_arg(bit_not(bit_true)) && bit_arg(bit_false));
	x_ = bit_op(bit_arg(bit_not(bit_true)) || bit_arg(bit_false));
	x_ = bit_op(bit_arg(bit_false) || bit_arg(bit_op(bit_arg(bit_true) && bit_arg(bit_true))));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
