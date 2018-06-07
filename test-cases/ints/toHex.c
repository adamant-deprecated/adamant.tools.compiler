#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type__ID = 0,
};
typedef enum Type_ID Type_ID;

// Type Declarations

// Function Declarations
void mut main__1(system__console__Console__0 mut ref const console__);

// Class Declarations

// Global Definitions

// Definitions

void mut main__1(system__console__Console__0 mut ref const console__)
{
	int32 mut i__ = ((int32){0});
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
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
