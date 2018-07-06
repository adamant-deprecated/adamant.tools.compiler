#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type__ID = 0,
};
typedef enum Type_ID Type_ID;

// Type Declarations

// Function Declarations
int32 mut identity__1(int32 const v__);
int32 mut main__0();

// Class Declarations

// Global Definitions

// Definitions

int32 mut identity__1(int32 const v__)
{
	return v__;
}

int32 mut main__0()
{
	system__collections__List__1 mut ref const ints__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	int32 const x__ = identity__1(((int32){0}));
	add_int__2(ints__, x__);
	add_int__2(ints__, identity__1(((int32){5})));
	return identity__1(identity__1(x__));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	return main__0().value;
}
