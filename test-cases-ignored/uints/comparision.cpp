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
	x__ = (int32){1}.as_uint__0()->op__less_than((int32){2}.as_uint__0());
	x__ = (int32){1}.as_uint__0()->op__less_than_or_equal((int32){2}.as_uint__0());
	x__ = (int32){1}.as_uint__0()->op__greater_than((int32){2}.as_uint__0());
	x__ = (int32){1}.as_uint__0()->op__greater_than_or_equal((int32){2}.as_uint__0());
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
