#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Main_() -> void
{
	bit x_;
	x_ = op_and(bit_true.op_not(), [&] { return bit_false; });
	x_ = op_or(bit_true.op_not(), [&] { return bit_false; });
	x_ = op_or(bit_false, [&] { return op_and(bit_true, [&] { return bit_true; }); });
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
