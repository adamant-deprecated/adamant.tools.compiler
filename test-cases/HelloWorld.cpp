#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main(::System::Console::Console *const console) -> void;

// Class Declarations

// Definitions
auto Main(::System::Console::Console *const console) -> void
{
	console->WriteLine(::string("Hello World!"));
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main(new ::System::Console::Console());
	return 0;
}
