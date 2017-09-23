#include "runtime.cpp"

void Main()
{
	new string(string("foo"));
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	Main();
	return 0;
}
