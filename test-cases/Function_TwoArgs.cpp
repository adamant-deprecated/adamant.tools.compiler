#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Func_(p_int const a_, p_int const b_) -> p_int;
auto Main_() -> p_int;

// Class Declarations

// Global Definitions

// Definitions

auto Func_(p_int const a_, p_int const b_) -> p_int
{
	return b_;
}

auto Main_() -> p_int
{
	return Func_(p_int(0), p_int(42));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	return Main_().Value;
}
