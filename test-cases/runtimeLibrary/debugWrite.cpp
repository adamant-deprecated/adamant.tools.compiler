#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__0();

// Class Declarations

// Global Definitions

// Definitions

void main__0()
{
	debug_write__1(string("prefix: "));
	debug_write_line__1(string("value"));
	debug_write_line__0();
	debug_write_line__1(string("eom"));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
