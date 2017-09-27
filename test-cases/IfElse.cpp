#include "runtime.h"

// Declarations
int Main();

// Definitions
int Main()
{
	if (true)
	{
		return 0;
	}
	else
	{
		return 42;
	}
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
