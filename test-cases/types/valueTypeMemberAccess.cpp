#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
int32 main__0();

// Class Declarations

// Global Definitions

// Definitions

int32 main__0()
{
	string const s__ = ((string){3,(uint8_t const*)"abc"});
	return s__.index_of__1(((code_point){(uint8_t)'c'}));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	return main__0().value;
}
