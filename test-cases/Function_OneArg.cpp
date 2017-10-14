#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Identity_(int const value_) -> int;
auto Main_() -> int;

// Class Declarations

// Definitions
auto Identity_(int const value_) -> int
{
	return value_;
}

auto Main_() -> int
{
	return Identity_(42);
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main_();
}
