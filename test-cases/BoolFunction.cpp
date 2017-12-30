#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Func_(p_bool const value_) -> p_bool;
auto Main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Func_(p_bool const value_) -> p_bool
{
	return p_bool(false);
}

auto Main_() -> void
{
	Func_(p_bool(true));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	Main_();
	return 0;
}
