#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
code_point__00 Identity__1(code_point__00 const value__);
void main__0();

// Class Declarations

// Global Definitions

// Definitions

code_point__00 Identity__1(code_point__00 const value__)
{
	return value__;
}

void main__0()
{
	Identity__1(code_point__00('a'));
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
