#include "runtime.h"

// Declarations
int Main();

// Definitions
int Main()
{
	int result;
	result = 42;
	result += 1;
	result -= 1;
	return result;
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	return Main();
}
