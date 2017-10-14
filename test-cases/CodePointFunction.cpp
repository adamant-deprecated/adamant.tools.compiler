#include "RuntimeLibrary.h"

// Declarations
auto Identity(char const value) -> char;
auto Main() -> void;

// Class Declarations

// Definitions
auto Identity(char const value) -> char
{
	return value;
}

auto Main() -> void
{
	Identity('a');
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
