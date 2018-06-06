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
	x__ = code_point__0op__equal(((code_point){/*a*/0x61}), ((code_point){/*b*/0x62}));
	x__ = code_point__0op__not_equal(((code_point){/*a*/0x61}), ((code_point){/*b*/0x62}));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
