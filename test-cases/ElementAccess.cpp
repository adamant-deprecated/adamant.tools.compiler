#include "runtime.h"

// Declarations
void Main();

// Definitions
void Main()
{
	char result;
	result = string("hello")[0];
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
