#include "runtime.h"

char Identity(const char value)
{
	return value;
}

void Main()
{
	Identity('a');
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	Main();
	return 0;
}
