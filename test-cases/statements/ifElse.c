#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
int32 main__0();

// Class Declarations

// Global Definitions

// Definitions

int32 main__0()
{
	if (cond(TRUE))
	{
		return ((int32){0});
	}
	else
	{
		return ((int32){42});
	}
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	return main__0().value;
}
