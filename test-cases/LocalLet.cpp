#include "runtime.cpp"

int Main()
{
	const int result = 42;
	return result;
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	return Main();
}
