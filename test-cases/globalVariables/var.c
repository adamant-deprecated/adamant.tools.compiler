#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
int32 mut main__0();

// Class Declarations

// Global Definitions
int32 mut Result__ = ((int32){42});

// Definitions

int32 mut main__0()
{
	return Result__;
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	return main__0().value;
}
