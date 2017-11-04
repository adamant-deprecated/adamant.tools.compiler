#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_() -> int;

// Class Declarations

// Global Definitions

// Definitions

auto Main_() -> int
{
	int const result_ = 42;
	return result_;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main_();
}
