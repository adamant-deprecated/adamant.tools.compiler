#include "runtime.h"

// Declarations
int Main();

// Class Declarations

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
int main(int argc, char const *const * argv)
{
	return Main();
}
