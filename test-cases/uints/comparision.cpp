#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__0();

// Class Declarations

// Global Definitions

// Definitions

void main__0()
{
	bool__00 x__;
	x__ = int__00(1).as_uint__0()->op__less_than(int__00(2).as_uint__0());
	x__ = int__00(1).as_uint__0()->op__less_than_or_equal(int__00(2).as_uint__0());
	x__ = int__00(1).as_uint__0()->op__greater_than(int__00(2).as_uint__0());
	x__ = int__00(1).as_uint__0()->op__greater_than_or_equal(int__00(2).as_uint__0());
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
