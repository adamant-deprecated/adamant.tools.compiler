#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto True_() -> bit;
auto main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto True_() -> bit
{
	return bit_true;
}

auto main_() -> void
{
	bit x_;
	x_ = equal_op(bit_true, bit_false);
	x_ = not_equal_op(bit_true, bit_false);
	x_ = equal_op(True_(), True_());
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
