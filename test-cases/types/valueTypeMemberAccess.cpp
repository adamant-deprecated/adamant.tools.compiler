#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
int32 main__0();

// Class Declarations

// Global Definitions

// Definitions

int32 main__0()
{
	string const s__ = string("abc");
	return s__.index_of__1(code_point('c'));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	return main__0().value;
}
