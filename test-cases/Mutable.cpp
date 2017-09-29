#include "runtime.h"

// Declarations
::System::Text::StringBuilder * Func(int x, int const y);
void Main(::System::Console::Console *const console);

// Class Declarations

// Definitions
::System::Text::StringBuilder * Func(int x, int const y)
{
	x += 1;
	int const i = x + 2;
	int j = y - 23;
	j = i;
	::System::Text::StringBuilder *const stringA = new ::System::Text::StringBuilder(string("Hello"));
	::System::Text::StringBuilder const * stringB;
	stringB = stringA;
	return stringA;
}

void Main(::System::Console::Console *const console)
{
	console->WriteLine(Func(1, 2)->ToString());
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main(new ::System::Console::Console());
	return 0;
}
