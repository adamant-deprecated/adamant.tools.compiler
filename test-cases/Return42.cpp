#include "runtime.h"

// Declarations
int Main();

// Definitions
int Main()
{
	return 42;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
