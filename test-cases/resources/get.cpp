#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	console__->Write__1(resource_manager__->GetString__1(string__00("hello.rsrc")));
	console__->Write__1(resource_manager__->GetString__1(string__00("world.rsrc")));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		resource_manager__->AddResource(string__00("hello.rsrc"), string__00("Hello to\nall my \"cool\" friends\\enemies.\n"));
		resource_manager__->AddResource(string__00("world.rsrc"), string__00("Goodbye world!\n"));

		main__1(new system__console__Console__0());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
