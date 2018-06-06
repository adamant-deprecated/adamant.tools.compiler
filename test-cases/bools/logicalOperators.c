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
	x__ = bool_op(bool_arg(TRUE) && bool_arg(FALSE));
	x__ = bool_op(bool_arg(TRUE) || bool_arg(FALSE));
	x__ = BOOL__0op__not(TRUE);
	x__ = bool_op(bool_arg(True__0()) || bool_arg(True__0()));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
