#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	int32 i__ = ((int32){0});
	console_write_line__2(console__, string__0op__add(string__0op__add(int_to_string__1(i__), ((string){4,(uint8_t const*)": 0x"})), int_to_hex_string__1(i__)));
	i__ = ((int32){15});
	console_write_line__2(console__, string__0op__add(string__0op__add(int_to_string__1(i__), ((string){4,(uint8_t const*)": 0x"})), int_to_hex_string__1(i__)));
	i__ = ((int32){255});
	console_write_line__2(console__, string__0op__add(string__0op__add(int_to_string__1(i__), ((string){4,(uint8_t const*)": 0x"})), int_to_hex_string__1(i__)));
	i__ = ((int32){512});
	console_write_line__2(console__, string__0op__add(string__0op__add(int_to_string__1(i__), ((string){4,(uint8_t const*)": 0x"})), int_to_hex_string__1(i__)));
	i__ = ((int32){2147483647});
	console_write_line__2(console__, string__0op__add(string__0op__add(int_to_string__1(i__), ((string){4,(uint8_t const*)": 0x"})), int_to_hex_string__1(i__)));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}