#include "runtime.cpp"

int Identity(const int value)
{
	return value;
}

int Main()
{
	return Identity(42);
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	return Main();
}
