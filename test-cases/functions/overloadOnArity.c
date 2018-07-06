#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type__ID = 0,
};
typedef enum Type_ID Type_ID;

// Type Declarations

// Function Declarations
int32 mut test__0();
int32 mut test__1(int32 const v__);
void mut main__1(system__console__Console__0 const ref const console__);

// Class Declarations

// Global Definitions

// Definitions

int32 mut test__0()
{
	return ((int32){5});
}

int32 mut test__1(int32 const v__)
{
	return v__;
}

void mut main__1(system__console__Console__0 const ref const console__)
{
	console_write_line__2(console__, string__0op__add(((string){{11},(uint8_t*)u8"`test()` = "}), int_to_string__1(test__0())));
	console_write_line__2(console__, string__0op__add(((string){{12},(uint8_t*)u8"`test(1)` = "}), int_to_string__1(test__1(((int32){1})))));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
