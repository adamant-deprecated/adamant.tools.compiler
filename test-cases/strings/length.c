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
	string mut s__ = ((string){{19},(uint8_t*)u8"A good test string!"});
	console_write_line__2(console__, string__0op__add(string__0op__add(int_to_string__1(string_byte_length__1(s__)), ((string){{2},(uint8_t*)u8": "})), s__));
	s__ = ((string){{20},(uint8_t*)u8"Yep,\twe know length!"});
	console_write_line__2(console__, string__0op__add(string__0op__add(int_to_string__1(string_byte_length__1(s__)), ((string){{2},(uint8_t*)u8": "})), s__));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
