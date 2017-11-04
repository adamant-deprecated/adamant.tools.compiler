#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Func_(bool const value_) -> bool;
auto Main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Func_(bool const value_) -> bool
{
	return false;
}

auto Main_() -> void
{
	Func_(true);
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main_();
	return 0;
}
