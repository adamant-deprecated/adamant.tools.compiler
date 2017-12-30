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
	x_ = LogicalAnd(p_bool(true)->op_Not(), [&] { return p_bool(false); });
	x_ = LogicalOr(p_bool(true)->op_Not(), [&] { return p_bool(false); });
	x_ = LogicalOr(p_bool(false), [&] { return LogicalAnd(p_bool(true), [&] { return p_bool(true); }); });
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	Main_();
	return 0;
}
