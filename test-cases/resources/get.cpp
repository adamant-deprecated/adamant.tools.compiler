#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__1(system__console__Console *_Nonnull const console__) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main__1(system__console__Console *_Nonnull const console__) -> void
{
	console__->Write__1(resource_manager__->GetString__1(string("hello.rsrc")));
	console__->Write__1(resource_manager__->GetString__1(string("world.rsrc")));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		resource_manager__->AddResource(string("hello.rsrc"), string("Hello to\nall my \"cool\" friends\\enemies.\n"));
		resource_manager__->AddResource(string("world.rsrc"), string("Goodbye world!\n"));

		main__1(new system__console__Console());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
