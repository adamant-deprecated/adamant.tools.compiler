#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
void main__0();

// Class Declarations

// Global Definitions

// Definitions

void main__0()
{
	debug_write__1(((string){8,(uint8_t const*)"prefix: "}));
	debug_write_line__1(((string){5,(uint8_t const*)"value"}));
	debug_write_line__0();
	debug_write_line__1(((string){3,(uint8_t const*)"eom"}));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
