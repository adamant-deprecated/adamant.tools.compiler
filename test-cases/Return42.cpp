#include "RuntimeLibrary.h"

// Declarations
auto Main() -> int;

// Class Declarations

// Definitions
auto Main() -> int
{
	return 42;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
