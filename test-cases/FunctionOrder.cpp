#include "runtime.h"

// Declarations
int Main();
int Func();

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
int main(int argc, const char * argv[])
{
	return Main();
}
