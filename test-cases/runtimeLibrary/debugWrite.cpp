#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__0();

// Class Declarations

// Global Definitions

// Definitions

void main__0()
{
	debug_write__1(string__00("prefix: "));
	debug_write_line__1(string__00("value"));
	debug_write_line__0();
	debug_write_line__1(string__00("eom"));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
