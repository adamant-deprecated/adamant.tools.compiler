#include "runtime.h"

// Declarations
int Func(int const a, int const b);
int Main();

// Definitions
int Func(int const a, int const b)
{
	return b;
}

int Main()
{
	return Func(0, 42);
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
