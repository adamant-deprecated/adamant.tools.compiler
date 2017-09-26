#include "runtime.h"

int Func();

int Main()
{
	return Func();
}

int Func()
{
	return 1;
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	return Main();
}
