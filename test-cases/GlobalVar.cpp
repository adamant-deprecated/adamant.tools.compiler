#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main() -> int;

// Class Declarations

// Definitions
int Result = 42;

auto Main() -> int
{
	return Result;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
