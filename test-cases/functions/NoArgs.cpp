#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Func_() -> p_int;
auto Main_() -> p_int;

// Class Declarations

// Global Definitions

// Definitions

auto Func_() -> p_int
{
	return p_int(42);
}

auto Main_() -> p_int
{
	return Func_();
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	return Main_().Value;
}
