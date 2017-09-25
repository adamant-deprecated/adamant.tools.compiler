#include "runtime.cpp"

int Main()
{
	if (false)
	{
		return 0;
	}
	else if (false)
	{
		return 42;
	}
	else if (false)
	{
		return 10;
	}
	else
	{
		return 0;
	}
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	return Main();
}
