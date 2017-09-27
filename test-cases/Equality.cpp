#include "runtime.h"

// Declarations
void Main();

// Definitions
void Main()
{
	bool x;
	x = 1 == 2;
	x = 1 != 2;
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	Main();
	return 0;
}
