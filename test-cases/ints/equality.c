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
	x__ = int32__0op__equal(((int32){1}), ((int32){2}));
	x__ = int32__0op__not_equal(((int32){1}), ((int32){2}));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
