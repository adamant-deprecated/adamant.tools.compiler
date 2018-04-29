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
	x_ = p_int(1).AsUInt_()->op_less_than(p_int(2).AsUInt_());
	x_ = p_int(1).AsUInt_()->op_less_than_or_equal(p_int(2).AsUInt_());
	x_ = p_int(1).AsUInt_()->op_greater_than(p_int(2).AsUInt_());
	x_ = p_int(1).AsUInt_()->op_greater_than_or_equal(p_int(2).AsUInt_());
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
