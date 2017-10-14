#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Func(bool const value) -> bool;
auto Main() -> void;

// Class Declarations

// Definitions
auto Func(bool const value) -> bool
{
	return false;
}

auto Main() -> void
{
	Func(true);
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
