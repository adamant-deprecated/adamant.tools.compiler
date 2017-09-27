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
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
