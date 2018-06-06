#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
int32 mut Func__2(int32 const a__, int32 const b__);
int32 mut main__0();

// Class Declarations

// Global Definitions

// Definitions

int32 mut Func__2(int32 const a__, int32 const b__)
{
	return b__;
}

int32 mut main__0()
{
	return Func__2(((int32){0}), ((int32){42}));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	return main__0().value;
}
