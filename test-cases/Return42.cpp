#include "runtime.h"

// Declarations
int Main();

// Definitions
int Main()
{
	return 42;
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	return Main();
}
