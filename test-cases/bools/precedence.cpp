#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__0();

// Class Declarations

// Global Definitions

// Definitions

void main__0()
{
	BOOL x__;
	x__ = bool__00__op(bool__00__arg(bool__00__0op__not(TRUE)) && bool__00__arg(FALSE));
	x__ = bool__00__op(bool__00__arg(bool__00__0op__not(TRUE)) || bool__00__arg(FALSE));
	x__ = bool__00__op(bool__00__arg(FALSE) || bool__00__arg(bool__00__op(bool__00__arg(TRUE) && bool__00__arg(TRUE))));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
