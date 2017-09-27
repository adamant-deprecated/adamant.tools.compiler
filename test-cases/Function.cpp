#include "runtime.h"

// Declarations
int Func();
int Main();

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
int main(int argc, const char * argv[])
{
	return Main();
}
