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
	code_point mut c__ = ((code_point){/*a*/0x61});
	console_write_line__2(console__, string__0op__add(string__0op__add(string__0op__add(((string){1,(uint8_t const*)"'"}), code_point_to_string__1(c__)), ((string){3,(uint8_t const*)"': "})), int_to_string__1(code_point_as_int__1(c__))));
	c__ = ((code_point){/*z*/0x7A});
	console_write_line__2(console__, string__0op__add(string__0op__add(string__0op__add(((string){1,(uint8_t const*)"'"}), code_point_to_string__1(c__)), ((string){3,(uint8_t const*)"': "})), int_to_string__1(code_point_as_int__1(c__))));
	c__ = ((code_point){/*\\*/0x5C});
	console_write_line__2(console__, string__0op__add(string__0op__add(string__0op__add(((string){1,(uint8_t const*)"'"}), code_point_to_string__1(c__)), ((string){3,(uint8_t const*)"': "})), int_to_string__1(code_point_as_int__1(c__))));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
