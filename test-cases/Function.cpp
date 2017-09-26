#include "runtime.h"

int Func()
{
	return 1;
}

int Main()
{
	return Func();
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	return Main();
}
