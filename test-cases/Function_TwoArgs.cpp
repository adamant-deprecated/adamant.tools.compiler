#include "runtime.h"

// Declarations
auto Func(int const a, int const b) -> int;
auto Main() -> int;

// Class Declarations

// Definitions
auto Func(int const a, int const b) -> int
{
	return b;
}

auto Main() -> int
{
	return Func(0, 42);
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
