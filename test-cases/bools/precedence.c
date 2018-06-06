#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
void mut main__0();

// Class Declarations

// Global Definitions

// Definitions

void mut main__0()
{
	BOOL mut x__;
	x__ = bool_op(bool_arg(BOOL__0op__not(TRUE)) && bool_arg(FALSE));
	x__ = bool_op(bool_arg(BOOL__0op__not(TRUE)) || bool_arg(FALSE));
	x__ = bool_op(bool_arg(FALSE) || bool_arg(bool_op(bool_arg(TRUE) && bool_arg(TRUE))));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
