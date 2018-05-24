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
	x__ = string__0op__less_than(string("a"), string("b"));
	x__ = string__0op__less_than_or_equal(string("a"), string("b"));
	x__ = string__0op__greater_than(string("a"), string("b"));
	x__ = string__0op__greater_than_or_equal(string("a"), string("b"));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
