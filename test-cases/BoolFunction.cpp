#include "runtime.h"

// Declarations
bool Func(bool const value);
void Main();

// Class Declarations

// Definitions
bool Func(bool const value)
{
	return false;
}

void Main()
{
	Func(true);
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
