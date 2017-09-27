#include "runtime.h"

// Declarations
int Main();

// Definitions
const int Result = 42;

int Main()
{
	return Result;
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	return Main();
}
