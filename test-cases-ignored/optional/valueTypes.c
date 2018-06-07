#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type__ID = 0,
};
typedef enum Type_ID Type_ID;

// Type Declarations

// Function Declarations
optional__int32 mut Func__2(optional__string const x__, optional__int32 const y__);
void mut main__1(system__console__Console__0 mut ref const console__);

// Class Declarations

// Global Definitions

// Definitions

optional__int32 mut Func__2(optional__string const x__, optional__uint32 const y__)
{
	optional__int32 const z__ = none;
	return none;
}

void mut main__1(system__console__Console__0 mut ref const console__)
{
	Func__2(none, none);
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
