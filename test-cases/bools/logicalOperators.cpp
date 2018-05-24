#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
BOOL True__0();
void main__0();

// Class Declarations

// Global Definitions

// Definitions

BOOL True__0()
{
	return TRUE;
}

void main__0()
{
	BOOL x__;
	x__ = bool__00__op(bool__00__arg(TRUE) && bool__00__arg(FALSE));
	x__ = bool__00__op(bool__00__arg(TRUE) || bool__00__arg(FALSE));
	x__ = bool__00__0op__not(TRUE);
	x__ = bool__00__op(bool__00__arg(True__0()) || bool__00__arg(True__0()));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
