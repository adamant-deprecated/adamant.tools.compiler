#include "runtime.h"

// Declarations
class C;
void Main();

// Class Declarations
class C
{
};

// Definitions
void Main()
{
	::C const *const c = new ::C();
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
