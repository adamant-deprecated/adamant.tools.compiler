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
	x__ = string__0op__lt(((string){1,(uint8_t const*)"a"}), ((string){1,(uint8_t const*)"b"}));
	x__ = string__0op__lte(((string){1,(uint8_t const*)"a"}), ((string){1,(uint8_t const*)"b"}));
	x__ = string__0op__gt(((string){1,(uint8_t const*)"a"}), ((string){1,(uint8_t const*)"b"}));
	x__ = string__0op__gte(((string){1,(uint8_t const*)"a"}), ((string){1,(uint8_t const*)"b"}));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
