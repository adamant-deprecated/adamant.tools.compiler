#include "runtime.h"

// Declarations
void Main();

// Definitions
void Main()
{
	for (;;)
	{
		break;
		continue;
	}
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	Main();
	return 0;
}
