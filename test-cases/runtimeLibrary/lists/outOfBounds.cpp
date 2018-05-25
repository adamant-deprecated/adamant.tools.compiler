#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
int32 main__0();

// Class Declarations

// Global Definitions

// Definitions

int32 main__0()
{
	system__collections__List__1<int32> const *_Nonnull const values__ = system__collections__List__1__0new__0<int32>(allocate(sizeof(system__collections__List__1<int32>)));
	return op__element(values__, ((int32){0}));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	return main__0().value;
}
