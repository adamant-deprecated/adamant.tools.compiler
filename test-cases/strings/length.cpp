#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	string s__ = ((string){19,(uint8_t const*)"A good test string!"});
	console__->WriteLine__1(op__add(op__add(string_length__1(s__), ((string){2,(uint8_t const*)": "})), s__));
	s__ = ((string){20,(uint8_t const*)"Yep,\twe know length!"});
	console__->WriteLine__1(op__add(op__add(string_length__1(s__), ((string){2,(uint8_t const*)": "})), s__));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(new system__console__Console__0());
	return 0;
}
