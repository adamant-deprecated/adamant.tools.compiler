#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type_ID = 0,
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
	console_write__2(console__, get_resource__1(((string){{10},(uint8_t*)u8"hello.rsrc"})));
	console_write__2(console__, get_resource__1(((string){{10},(uint8_t*)u8"world.rsrc"})));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	add_resource((string){{10},(uint8_t*)u8"hello.rsrc"}, (string){{40},(uint8_t*)u8"Hello to\nall my \"cool\" friends\\enemies.\n"});
	add_resource((string){{10},(uint8_t*)u8"world.rsrc"}, (string){{15},(uint8_t*)u8"Goodbye world!\n"});

	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
