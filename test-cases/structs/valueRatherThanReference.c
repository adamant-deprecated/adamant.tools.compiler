#include "RuntimeLibrary.h"

// Type Declarations
typedef struct Reference_Type__0 Reference_Type__0;
typedef struct Value_Type__0 Value_Type__0;

// Function Declarations
Reference_Type__0 mut ref mut Reference_Type__0__0new__0(Reference_Type__0 mut ref const self);
Value_Type__0 mut Value_Type__0__0new__0();
void mut main__0();

// Class Declarations

struct Reference_Type__0
{
	int32_t type_id;
};

struct Value_Type__0
{
};

// Global Definitions

// Definitions

Reference_Type__0 mut ref mut Reference_Type__0__0new__0(Reference_Type__0 mut ref const self) { self->type_id = 1293071651; return self; }

Value_Type__0 mut Value_Type__0__0new__0() { return (Value_Type__0 mut){}; }

void mut main__0()
{
	Reference_Type__0 const ref const r__ = Reference_Type__0__0new__0(allocate(sizeof(Reference_Type__0)));
	Value_Type__0 const v__ = Value_Type__0__0new__0();
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
