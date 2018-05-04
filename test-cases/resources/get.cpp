#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main_(::System_::Console_::Console_ *_Nonnull const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main_(::System_::Console_::Console_ *_Nonnull const console_) -> void
{
	console_->Write_(resource_manager_->GetString_(str("hello.rsrc")));
	console_->Write_(resource_manager_->GetString_(str("world.rsrc")));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		resource_manager_->AddResource(str("hello.rsrc"), str("Hello to\nall my \"cool\" friends\\enemies.\n"));
		resource_manager_->AddResource(str("world.rsrc"), str("Goodbye world!\n"));

		main_(new ::System_::Console_::Console_());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
