#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
int__00 Func__2(int__00 const a__, int__00 const b__);
int__00 main__0();

// Class Declarations

// Global Definitions

// Definitions

int__00 Func__2(int__00 const a__, int__00 const b__)
{
	return b__;
}

int__00 main__0()
{
	return Func__2(int__00(0), int__00(42));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	return main__0().value;
}
