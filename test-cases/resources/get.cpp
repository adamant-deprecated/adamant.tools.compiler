#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_(::System_::Console_::Console_ *const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Main_(::System_::Console_::Console_ *const console_) -> void
{
	console_->Write_(resource_manager_->GetString_(p_string("hello.rsrc")));
	console_->Write_(resource_manager_->GetString_(p_string("world.rsrc")));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		resource_manager_->AddResource(p_string("hello.rsrc"), p_string("Hello to\nall my \"cool\" friends\\enemies.\n"));
		resource_manager_->AddResource(p_string("world.rsrc"), p_string("Goodbye world!\n"));

		Main_(new ::System_::Console_::Console_());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
