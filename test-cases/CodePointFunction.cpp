#include "runtime.cpp"

char Identity(char value)
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
