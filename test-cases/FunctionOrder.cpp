#include "runtime.h"

// Declarations
int Main();
int Func();

// Class Declarations

// Definitions
int Main()
{
	return Func();
}

int Func()
{
	return 1;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
