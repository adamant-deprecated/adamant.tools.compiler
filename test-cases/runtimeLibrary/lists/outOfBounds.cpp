#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
int__00 main__0();

// Class Declarations

// Global Definitions

// Definitions

int__00 main__0()
{
	system__collections__List__1<int__00> const *_Nonnull const values__ = system__collections__List__1__0new__0<int__00>(allocate(sizeof(system__collections__List__1<int__00>)));
	return values__->op__Element(int__00(0));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		return main__0().value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
