#include "runtime.h"

// Declarations
auto Main() -> int;

// Class Declarations

// Definitions
auto Main() -> int
{
	if (false)
	{
		return 0;
	}
	else if (false)
	{
		return 42;
	}
	else if (false)
	{
		return 10;
	}
	else
	{
		return 0;
	}
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
