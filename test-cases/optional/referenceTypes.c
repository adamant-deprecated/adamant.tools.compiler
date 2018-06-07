#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type__ID = 0,
	Test__0__0Type_ID,
};
typedef enum Type_ID Type_ID;

// Type Declarations
typedef struct Test__0 Test__0;

// Function Declarations
Test__0 mut ref mut Test__0__0new__0(Test__0 mut ref const self);
Test__0 const opt_ref mut Func__1(Test__0 const opt_ref const x__);
void mut main__1(system__console__Console__0 mut ref const console__);

// Class Declarations

struct Test__0
{
	Type_ID type_id;
};

// Global Definitions

// Definitions

Test__0 mut ref mut Test__0__0new__0(Test__0 mut ref const self) { self->type_id = Test__0__0Type_ID; return self; }

Test__0 const opt_ref mut Func__1(Test__0 const opt_ref const x__)
{
	Test__0 const opt_ref const t__ = none;
	system__text__String_Builder__0 mut opt_ref const sb__ = none;
	system__collections__List__1 const ref const l__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	Test__0 mut opt_ref const m__ = none;
	return none;
}

void mut main__1(system__console__Console__0 mut ref const console__)
{
	Func__1(none);
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
