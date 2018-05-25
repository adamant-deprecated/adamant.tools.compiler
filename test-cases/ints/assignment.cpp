#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
int32 main__0();

// Class Declarations

// Global Definitions

// Definitions

int32 main__0()
{
	int32 result__;
	result__ = (int32){40};
	op__add_assign(&(result__), (int32){3});
	op__sub_assign(&(result__), (int32){1});
	return result__;
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	return main__0().value;
}
