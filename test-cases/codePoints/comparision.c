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
	x__ = code_point__0op__lt(((code_point){/*a*/0x61}), ((code_point){/*b*/0x62}));
	x__ = code_point__0op__lte(((code_point){/*a*/0x61}), ((code_point){/*b*/0x62}));
	x__ = code_point__0op__gt(((code_point){/*a*/0x61}), ((code_point){/*b*/0x62}));
	x__ = code_point__0op__gte(((code_point){/*a*/0x61}), ((code_point){/*b*/0x62}));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}