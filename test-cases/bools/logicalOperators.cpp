#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
bool__00 True__0();
void main__0();

// Class Declarations

// Global Definitions

// Definitions

bool__00 True__0()
{
	return true__00;
}

void main__0()
{
	bool__00 x__;
	x__ = bool__00__op(bool__00__arg(true__00) && bool__00__arg(false__00));
	x__ = bool__00__op(bool__00__arg(true__00) || bool__00__arg(false__00));
	x__ = bool__00__0op__not(true__00);
	x__ = bool__00__op(bool__00__arg(True__0()) || bool__00__arg(True__0()));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
