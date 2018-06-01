#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
int32 main__0();

// Class Declarations

// Global Definitions
int32 const Result__ = ((int32){42});

// Definitions

int32 main__0()
{
	return Result__;
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	return main__0().value;
}
