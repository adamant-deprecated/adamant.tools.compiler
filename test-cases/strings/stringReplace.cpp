#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	string const s__ = ((string){24,(uint8_t const*)"A good good Test String!"});
	console_write_line__2(console__, s__);
	console_write_line__2(console__, string_replace__3(s__, ((string){4,(uint8_t const*)"good"}), ((string){3,(uint8_t const*)"bad"})));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(new system__console__Console__0());
	return 0;
}
