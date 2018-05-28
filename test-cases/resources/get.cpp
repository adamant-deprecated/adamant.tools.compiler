#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	console__->Write__1(get_resource__1(((string){10,(uint8_t const*)"hello.rsrc"})));
	console__->Write__1(get_resource__1(((string){10,(uint8_t const*)"world.rsrc"})));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	add_resource((string){10,(uint8_t const*)"hello.rsrc"}, (string){40,(uint8_t const*)"Hello to\nall my \"cool\" friends\\enemies.\n"});
	add_resource((string){10,(uint8_t const*)"world.rsrc"}, (string){15,(uint8_t const*)"Goodbye world!\n"});

	main__1(new system__console__Console__0());
	return 0;
}
