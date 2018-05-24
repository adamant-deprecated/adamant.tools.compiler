#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	console__->Write__1(resource_manager__->GetString__1(string("hello.rsrc")));
	console__->Write__1(resource_manager__->GetString__1(string("world.rsrc")));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	resource_manager__->AddResource(string("hello.rsrc"), string("Hello to\nall my \"cool\" friends\\enemies.\n"));
	resource_manager__->AddResource(string("world.rsrc"), string("Goodbye world!\n"));

	main__1(new system__console__Console__0());
	return 0;
}
