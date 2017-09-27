#include "runtime.h"

// Declarations
void Main();

// Definitions
void Main()
{
	string s = string("\"\\");
	char c = '\'';
	c = '\\';
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
