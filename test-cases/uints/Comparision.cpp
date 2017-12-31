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
	x_ = p_int(1)->AsUInt_()->op_LessThan(p_int(2)->AsUInt_());
	x_ = p_int(1)->AsUInt_()->op_LessThanOrEqual(p_int(2)->AsUInt_());
	x_ = p_int(1)->AsUInt_()->op_GreaterThan(p_int(2)->AsUInt_());
	x_ = p_int(1)->AsUInt_()->op_GreaterThanOrEqual(p_int(2)->AsUInt_());
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	Main_();
	return 0;
}