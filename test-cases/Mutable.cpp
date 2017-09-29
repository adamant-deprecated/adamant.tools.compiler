#include "runtime.h"

// Declarations
auto Func(int x, int const y) -> ::System::Text::StringBuilder *;
auto Main(::System::Console::Console *const console) -> void;

// Class Declarations

// Definitions
auto Func(int x, int const y) -> ::System::Text::StringBuilder *
{
	x += 1;
	int const i = x + 2;
	int j = y - 23;
	j = i;
	::System::Text::StringBuilder *const stringA = new ::System::Text::StringBuilder(::string("Hello"));
	::System::Text::StringBuilder const * stringB;
	stringB = stringA;
	return stringA;
}

auto Main(::System::Console::Console *const console) -> void
{
	console->WriteLine(Func(1, 2)->ToString());
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main(new ::System::Console::Console());
	return 0;
}
