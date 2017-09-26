#include "runtime.h"

bool True()
{
	return true;
}

void Main()
{
	bool x;
	x = true && false;
	x = true || false;
	x = !true;
	x = True() || True();
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	Main();
	return 0;
}
