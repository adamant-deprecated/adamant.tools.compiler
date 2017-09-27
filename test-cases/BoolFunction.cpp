#include "runtime.h"

// Declarations
bool Func(const bool value);
void Main();

// Definitions
bool Func(const bool value)
{
	return false;
}

void Main()
{
	Func(true);
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	Main();
	return 0;
}
