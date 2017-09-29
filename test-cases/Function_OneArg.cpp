#include "runtime.h"

// Declarations
int Identity(int const value);
int Main();

// Class Declarations

// Definitions
int Identity(int const value)
{
	return value;
}

int Main()
{
	return Identity(42);
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main();
}
