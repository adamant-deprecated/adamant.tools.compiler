#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_() -> int;
auto Func_() -> int;

// Class Declarations

// Definitions

auto Main_() -> int
{
	return Func_();
}

auto Func_() -> int
{
	return 1;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main_();
}
