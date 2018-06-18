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
	string const s__ = ((string){{24},(uint8_t*)u8"A good good Test String!"});
	console_write_line__2(console__, s__);
	console_write_line__2(console__, string_replace__3(s__, ((string){{4},(uint8_t*)u8"good"}), ((string){{3},(uint8_t*)u8"bad"})));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
