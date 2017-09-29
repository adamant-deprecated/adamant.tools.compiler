#include "runtime.h"

// Declarations
auto Main() -> void;

// Class Declarations

// Definitions
auto Main() -> void
{
	char result;
	result = ::string("hello")[0];
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
