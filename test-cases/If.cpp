#include "RuntimeLibrary.h"

// Declarations
auto Main() -> int;

// Class Declarations

// Definitions
auto Main() -> int
{
	if (true)
	{
		return 0;
	}
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
