#include "runtime.h"

// Declarations
auto Main() -> int;
auto Func() -> int;

// Class Declarations

// Definitions
auto Main() -> int
{
	return Func();
}

auto Func() -> int
{
	return 1;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
