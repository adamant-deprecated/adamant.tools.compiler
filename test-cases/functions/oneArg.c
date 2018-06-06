#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
int32 mut Identity__1(int32 const value__);
int32 mut main__0();

// Class Declarations

// Global Definitions

// Definitions

int32 mut Identity__1(int32 const value__)
{
	return value__;
}

int32 mut main__0()
{
	return Identity__1(((int32){42}));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	return main__0().value;
}
