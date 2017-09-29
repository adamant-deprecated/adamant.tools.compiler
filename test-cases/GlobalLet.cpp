#include "runtime.h"

// Declarations
int Main();

// Class Declarations

// Definitions
int const Result = 42;

int Main()
{
	return Result;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
