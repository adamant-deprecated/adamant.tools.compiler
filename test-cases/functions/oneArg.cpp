#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
int32 Identity__1(int32 const value__);
int32 main__0();

// Class Declarations

// Global Definitions

// Definitions

int32 Identity__1(int32 const value__)
{
	return value__;
}

int32 main__0()
{
	return Identity__1((int32){42});
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	return main__0().value;
}
