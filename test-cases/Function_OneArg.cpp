#include "runtime.h"

// Declarations
auto Identity(int const value) -> int;
auto Main() -> int;

// Class Declarations

// Definitions
auto Identity(int const value) -> int
{
	return value;
}

auto Main() -> int
{
	return Identity(42);
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
