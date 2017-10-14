#include "runtime.h"

// Declarations
auto Main(::System::Console::Console *const console) -> void;

// Class Declarations

// Definitions
auto Main(::System::Console::Console *const console) -> void
{
	console->WriteLine(resource_manager->GetString(::string("Hello.rsrc")));
	console->WriteLine(resource_manager->GetString(::string("World.rsrc")));
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	resource_manager->AddResource(::string("Hello.rsrc"), ::string("Hello to\nall my \"cool\" friends\\enemies."));
	resource_manager->AddResource(::string("World.rsrc"), ::string("Goodbye world!"));

	Main(new ::System::Console::Console());
	return 0;
}
