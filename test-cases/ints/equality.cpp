#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Main_() -> void
{
	p_bool x_;
	x_ = equal_op(p_int(1), p_int(2));
	x_ = not_equal_op(p_int(1), p_int(2));
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
