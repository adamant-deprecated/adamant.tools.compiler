#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
void main__0();

// Class Declarations

// Global Definitions

// Definitions

void main__0()
{
	BOOL x__;
	x__ = bool_op(bool_arg(BOOL__0op__not(TRUE)) && bool_arg(FALSE));
	x__ = bool_op(bool_arg(BOOL__0op__not(TRUE)) || bool_arg(FALSE));
	x__ = bool_op(bool_arg(FALSE) || bool_arg(bool_op(bool_arg(TRUE) && bool_arg(TRUE))));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
