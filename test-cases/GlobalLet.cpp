#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_() -> int;

// Class Declarations

// Definitions
int const Result_ = 42;

auto Main_() -> int
{
	return Result_;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main_();
}
