#include "runtime.h"

// Declarations
int Main();

// Definitions
int Main()
{
	int result = 42;
	return result;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
