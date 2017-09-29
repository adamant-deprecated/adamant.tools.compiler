#include "runtime.h"

// Declarations
char Identity(char const value);
void Main();

// Class Declarations

// Definitions
char Identity(char const value)
{
	return value;
}

void Main()
{
	Identity('a');
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
