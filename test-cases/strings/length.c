#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	string s__ = ((string){19,(uint8_t const*)"A good test string!"});
	console_write_line__2(console__, string__0op__add(string__0op__add(int_to_string__1(string_byte_length__1(s__)), ((string){2,(uint8_t const*)": "})), s__));
	s__ = ((string){20,(uint8_t const*)"Yep,\twe know length!"});
	console_write_line__2(console__, string__0op__add(string__0op__add(int_to_string__1(string_byte_length__1(s__)), ((string){2,(uint8_t const*)": "})), s__));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}