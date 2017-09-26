#include "runtime.h"

void Main()
{
	char result;
	result = string("hello")[0];
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	Main();
	return 0;
}
