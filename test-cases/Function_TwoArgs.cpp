#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Func_(int const a_, int const b_) -> int;
auto Main_() -> int;

// Class Declarations

// Global Definitions

// Definitions

auto Func_(int const a_, int const b_) -> int
{
	return b_;
}

auto Main_() -> int
{
	return Func_(0, 42);
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main_();
}
