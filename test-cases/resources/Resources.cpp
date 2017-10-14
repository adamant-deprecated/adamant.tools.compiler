#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_(::System_::Console_::Console_ *const console_) -> void;

// Class Declarations

// Definitions
auto Main_(::System_::Console_::Console_ *const console_) -> void
{
	console_->WriteLine_(resource_manager_->GetString_(string("Hello.rsrc")));
	console_->WriteLine_(resource_manager_->GetString_(string("World.rsrc")));
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	resource_manager_->AddResource(::string("Hello.rsrc"), ::string("Hello to\nall my \"cool\" friends\\enemies."));
	resource_manager_->AddResource(::string("World.rsrc"), ::string("Goodbye world!"));

	Main_(new ::System_::Console_::Console_());
	return 0;
}
