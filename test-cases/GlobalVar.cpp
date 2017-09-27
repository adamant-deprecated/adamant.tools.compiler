#include "runtime.h"

// Declarations
int Main();

// Definitions
int Result = 42;

int Main()
{
	return Result;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
