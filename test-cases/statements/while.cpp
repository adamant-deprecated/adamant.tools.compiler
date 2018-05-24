#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
int__00 main__0();

// Class Declarations

// Global Definitions

// Definitions

int__00 main__0()
{
	while (cond(TRUE))
	{
		return int__00(0);
	}

	UNREACHABLE__0();
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	return main__0().value;
}
