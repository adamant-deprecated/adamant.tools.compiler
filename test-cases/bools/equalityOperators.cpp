#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto True_() -> p_bool;
auto Main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto True_() -> p_bool
{
	return p_bool(true);
}

auto Main_() -> void
{
	p_bool x_;
	x_ = equal_op(p_bool(true), p_bool(false));
	x_ = not_equal_op(p_bool(true), p_bool(false));
	x_ = equal_op(True_(), True_());
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
