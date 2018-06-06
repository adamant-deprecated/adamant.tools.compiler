#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
BOOL mut True__0();
void mut main__0();

// Class Declarations

// Global Definitions

// Definitions

BOOL mut True__0()
{
	return TRUE;
}

void mut main__0()
{
	BOOL mut x__;
	x__ = BOOL__0op__equal(TRUE, FALSE);
	x__ = BOOL__0op__not_equal(TRUE, FALSE);
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
