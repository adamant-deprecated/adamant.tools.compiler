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
	x__ = equal_op(((code_point){/*a*/0x61}), ((code_point){/*b*/0x62}));
	x__ = not_equal_op(((code_point){/*a*/0x61}), ((code_point){/*b*/0x62}));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
