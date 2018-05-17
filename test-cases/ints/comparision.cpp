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
	x__ = int__00__0op__less_than(int__00(1), int__00(2));
	x__ = int__00__0op__less_than_or_equal(int__00(1), int__00(2));
	x__ = int__00__0op__greater_than(int__00(1), int__00(2));
	x__ = int__00__0op__greater_than_or_equal(int__00(1), int__00(2));
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
