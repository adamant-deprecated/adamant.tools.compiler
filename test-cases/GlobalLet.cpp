#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_() -> int;

// Class Declarations

// Global Definitions
int const Result_ = 42;

// Definitions

auto Main_() -> int
{
	return Result_;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main_();
}
