#include "runtime.h"

// Declarations
void Main(::System::Console::Console *const console, ::System::Console::Arguments const *const args);

// Definitions
void Main(::System::Console::Console *const console, ::System::Console::Arguments const *const args)
{
	for (string const arg : *(args))
	{
		console->WriteLine(arg);
	}
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main(new ::System::Console::Console(), new ::System::Console::Arguments(argc, argv));
	return 0;
}
