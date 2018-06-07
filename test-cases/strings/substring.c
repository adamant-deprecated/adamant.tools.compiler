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
	string const s__ = ((string){19,(uint8_t const*)"A good Test String!"});
	console_write_line__2(console__, substring__3(s__, ((int32){2}), ((int32){4})));
	console_write_line__2(console__, substring__2(s__, ((int32){12})));
	console_write_line__2(console__, substring__3(s__, ((int32){19}), ((int32){0})));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
