#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
code_point mut Identity__1(code_point const value__);
void mut main__0();

// Class Declarations

// Global Definitions

// Definitions

code_point mut Identity__1(code_point const value__)
{
	return value__;
}

void mut main__0()
{
	Identity__1(((code_point){/*a*/0x61}));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
