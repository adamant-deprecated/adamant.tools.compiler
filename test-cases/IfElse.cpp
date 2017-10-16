#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_() -> int;

// Class Declarations

// Definitions

auto Main_() -> int
{
	if (true)
	{
		return 0;
	}
	else
	{
		return 42;
	}
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main_();
}
