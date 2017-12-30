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
	x_ = p_code_point('a')->op_Equal(p_code_point('b'));
	x_ = p_code_point('a')->op_NotEqual(p_code_point('b'));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	Main_();
	return 0;
}
