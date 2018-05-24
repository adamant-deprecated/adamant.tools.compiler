#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
int__00 main__0();

// Class Declarations

// Global Definitions

// Definitions

int__00 main__0()
{
	int__00 result__;
	result__ = int__00(40);
	result__.op__add_assign(int__00(3));
	result__.op__subtract_assign(int__00(1));
	return result__;
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	return main__0().value;
}
