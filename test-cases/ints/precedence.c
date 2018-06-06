#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
void mut main__0();

// Class Declarations

// Global Definitions

// Definitions

void mut main__0()
{
	int32 mut x__;
	x__ = int32__0op__add(((int32){1}), int32__0op__div(int32__0op__sub(((int32){3}), ((int32){1})), ((int32){2})));
	x__ = int32__0op__sub(int32__0op__add(((int32){1}), ((int32){3})), int32__0op__div(((int32){1}), ((int32){2})));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
