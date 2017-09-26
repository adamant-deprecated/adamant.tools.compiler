#include "runtime.h"

void Main()
{
	string(string("foo"));
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	Main();
	return 0;
}
