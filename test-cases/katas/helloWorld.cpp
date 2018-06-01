#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	console_write_line__2(console__, ((string){12,(uint8_t const*)"Hello World!"}));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(new system__console__Console__0());
	return 0;
}
