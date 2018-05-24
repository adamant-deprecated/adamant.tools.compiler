#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__0();

// Class Declarations

// Global Definitions

// Definitions

void main__0()
{
	int__00 x__;
	x__ = int__00(1).op__add(int__00(3).op__subtract(int__00(1))->op__divide(int__00(2)));
	x__ = int__00(1).op__add(int__00(3)).op__subtract(int__00(1).op__divide(int__00(2)));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
