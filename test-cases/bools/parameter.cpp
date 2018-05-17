#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
bool__00 Func__1(bool__00 const value__);
void main__0();

// Class Declarations

// Global Definitions

// Definitions

bool__00 Func__1(bool__00 const value__)
{
	return false__00;
}

void main__0()
{
	Func__1(true__00);
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
