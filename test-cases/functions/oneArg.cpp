#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
int__00 Identity__1(int__00 const value__);
int__00 main__0();

// Class Declarations

// Global Definitions

// Definitions

int__00 Identity__1(int__00 const value__)
{
	return value__;
}

int__00 main__0()
{
	return Identity__1(int__00(42));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	return main__0().value;
}
