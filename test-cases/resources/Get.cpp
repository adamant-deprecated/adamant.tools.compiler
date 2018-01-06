#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_(::System_::Console_::Console_ *const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Main_(::System_::Console_::Console_ *const console_) -> void
{
	console_->Write_(resource_manager_->GetString_(p_string("Hello.rsrc")));
	console_->Write_(resource_manager_->GetString_(p_string("World.rsrc")));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	resource_manager_->AddResource(p_string("Hello.rsrc"), p_string("Hello to\nall my \"cool\" friends\\enemies.\n"));
	resource_manager_->AddResource(p_string("World.rsrc"), p_string("Goodbye world!\n"));

	Main_(new ::System_::Console_::Console_());
	return 0;
}
