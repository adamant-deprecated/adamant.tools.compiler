#include "runtime.cpp"

bool Func(bool value)
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
