#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type_ID = 0,
};
typedef enum Type_ID Type_ID;

// Type Declarations

// Function Declarations
void mut main__2(system__console__Console__0 mut ref const console__, system__console__Arguments__0 const ref const args__);

// Class Declarations

// Global Definitions

// Definitions

void mut main__2(system__console__Console__0 mut ref const console__, system__console__Arguments__0 const ref const args__)
{
	for (string__0iter mut iter = system__console__Arguments__0__0iterate(args__); string__0next(&iter);)
	{
		string const arg__ = string__0current(&iter);
		console_write_line__2(console__, arg__);
	}
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__2(allocate(sizeof(system__console__Console__0)), convert_arguments(argc, argv));
	return 0;
}
