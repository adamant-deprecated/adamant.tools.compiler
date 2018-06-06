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
	x__ = string__0op__lt(((string){1,(uint8_t const*)"a"}), ((string){1,(uint8_t const*)"b"}));
	x__ = string__0op__lte(((string){1,(uint8_t const*)"a"}), ((string){1,(uint8_t const*)"b"}));
	x__ = string__0op__gt(((string){1,(uint8_t const*)"a"}), ((string){1,(uint8_t const*)"b"}));
	x__ = string__0op__gte(((string){1,(uint8_t const*)"a"}), ((string){1,(uint8_t const*)"b"}));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
