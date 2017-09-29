#include "runtime.h"

// Declarations
void Main(::System::Console::Console *const console);

// Class Declarations

// Definitions
void Main(::System::Console::Console *const console)
{
	console->WriteLine(string("Hello World!"));
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main(new ::System::Console::Console());
	return 0;
}
