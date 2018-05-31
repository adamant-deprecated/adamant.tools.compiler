#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__2(system__console__Console__0 *_Nonnull const console__, system__console__Arguments__0 const *_Nonnull const args__);

// Class Declarations

// Global Definitions

// Definitions

void main__2(system__console__Console__0 *_Nonnull const console__, system__console__Arguments__0 const *_Nonnull const args__)
{
	for (string__0iter iter = system__console__Arguments__0__0iterate(args__); string__0next(&iter);)
	{
		string const arg__ = string__0current(&iter);
		console__->WriteLine__1(arg__);
	}
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__2(new system__console__Console__0(), new system__console__Arguments__0(argc, argv));
	return 0;
}
