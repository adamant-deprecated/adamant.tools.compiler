#include "runtime.h"

// Declarations
bool True();
void Main();

// Class Declarations

// Definitions
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
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
