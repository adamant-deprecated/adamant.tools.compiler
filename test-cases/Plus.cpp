#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Main_() -> void
{
	int x_ = 1 + 2;
	x_ = 1 - 2;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main_();
	return 0;
}
