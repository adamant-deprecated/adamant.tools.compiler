#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__0();

// Class Declarations

// Global Definitions

// Definitions

void main__0()
{
	system__collections__List__1<int__00> const *_Nonnull const values__ = system__collections__List__1__0new__0<int__00>(allocate(sizeof(system__collections__List__1<int__00>)));
	equal_op(values__, values__);
	not_equal_op(values__, values__);
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__0();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
