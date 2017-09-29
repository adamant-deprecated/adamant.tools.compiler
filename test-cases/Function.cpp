#include "runtime.h"

// Declarations
int Func();
int Main();

// Class Declarations

// Definitions
int Func()
{
	return 1;
}

int Main()
{
	return Func();
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
