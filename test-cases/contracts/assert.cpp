#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__0();

// Class Declarations

// Global Definitions

// Definitions

void main__0()
{
	int32 const x__ = (int32){5};
	int32 const y__ = (int32){5};
	int32 const z__ = (int32){6};
	assert__2(equal_op(x__, y__), op__add(op__add(op__add(string("x="), x__), string(" y=")), y__));
	assert__2(equal_op(y__, z__), op__add(op__add(op__add(string("y="), y__), string(" z=")), z__));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
