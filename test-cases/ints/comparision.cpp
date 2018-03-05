#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Main_() -> void
{
	p_bool x_;
	x_ = p_int(1).op_LessThan(p_int(2));
	x_ = p_int(1).op_LessThanOrEqual(p_int(2));
	x_ = p_int(1).op_GreaterThan(p_int(2));
	x_ = p_int(1).op_GreaterThanOrEqual(p_int(2));
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
