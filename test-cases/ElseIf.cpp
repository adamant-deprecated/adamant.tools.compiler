#include "runtime.h"

// Declarations
int Main();

// Class Declarations

// Definitions
int Main()
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
