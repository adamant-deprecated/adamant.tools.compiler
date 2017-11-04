#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Func_() -> int;
auto Main_() -> int;

// Class Declarations

// Global Definitions

// Definitions

auto Func_() -> int
{
	return 1;
}

auto Main_() -> int
{
	return Func_();
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main_();
}
