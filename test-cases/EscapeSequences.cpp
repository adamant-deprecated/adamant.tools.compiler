#include "RuntimeLibrary.h"

// Declarations
auto Main() -> void;

// Class Declarations

// Definitions
auto Main() -> void
{
	::string s = ::string("\"\\");
	char c = '\'';
	c = '\\';
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
