#include "RuntimeLibrary.h"

// Type Declarations
class C;

// Function Declarations
auto Main() -> void;

// Class Declarations
class C
{
public:
	::string Name;
	C(::string const name);
	auto Method() -> ::string;
};

// Definitions
::C::C(::string const name)
{
	Name = name;
}

auto ::C::Method() -> ::string
{
	return Name;
}

auto Main() -> void
{
	::C const *const c = new ::C(::string("Bob"));
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
