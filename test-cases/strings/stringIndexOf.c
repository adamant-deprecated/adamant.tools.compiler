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
	string const s__ = ((string){{19},(uint8_t*)u8"A good test string!"});
	console_write_line__2(console__, s__);
	console_write_line__2(console__, string__0op__add(((string){{20},(uint8_t*)u8"First index of 't': "}), int_to_string__1(string_index_of__2(s__, ((code_point){/*t*/0x74})))));
	console_write_line__2(console__, string__0op__add(((string){{19},(uint8_t*)u8"Last index of 't': "}), int_to_string__1(string_last_index_of__2(s__, ((code_point){/*t*/0x74})))));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
