#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Func() -> int;
auto Main() -> int;

// Class Declarations

// Definitions
auto Func() -> int
{
	return 1;
}

auto Main() -> int
{
	return Func();
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
