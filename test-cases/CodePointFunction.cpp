#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Identity_(char const value_) -> char;
auto Main_() -> void;

// Class Declarations

// Definitions
auto Identity_(char const value_) -> char
{
	return value_;
}

auto Main_() -> void
{
	Identity_('a');
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main_();
	return 0;
}
