#include "RuntimeLibrary.h"

// Declarations
auto True() -> bool;
auto Main() -> void;

// Class Declarations

// Definitions
auto True() -> bool
{
	return true;
}

auto Main() -> void
{
	bool x;
	x = true && false;
	x = true || false;
	x = !true;
	x = True() || True();
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
