#include "runtime.h"

// Declarations
class C;
void Main();

// Class Declarations
class C
{
public:
	string Name;
	C(string const name);
};

// Definitions
::C::C(string const name)
{
	Name = name;
}

void Main()
{
	::C const *const c = new ::C(string("Bob"));
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
