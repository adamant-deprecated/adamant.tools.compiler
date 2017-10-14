#include "RuntimeLibrary.h"

// Declarations
auto Main() -> void;

// Class Declarations

// Definitions
auto Main() -> void
{
	int x = 1 + 2;
	x = 1 - 2;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
