#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
int__00 main__0();

// Class Declarations

// Global Definitions

// Definitions

int__00 main__0()
{
	if (cond(false__00))
	{
		return int__00(0);
	}
	else if (cond(false__00))
	{
		return int__00(42);
	}
	else if (cond(false__00))
	{
		return int__00(10);
	}
	else
	{
		return int__00(0);
	}
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
