#include "RuntimeLibrary.h"

// Type Declarations
typedef struct Mutable_Class__0 Mutable_Class__0;
typedef struct Immutable_Class__0 Immutable_Class__0;

// Function Declarations
Mutable_Class__0 mut ref mut Mutable_Class__0__0new__0(Mutable_Class__0 mut ref const self);
Immutable_Class__0 mut ref mut Immutable_Class__0__0new__0(Immutable_Class__0 mut ref const self);
void mut main__0();

// Class Declarations

struct Mutable_Class__0
{
	int32_t type_id;
};

struct Immutable_Class__0
{
	int32_t type_id;
};

// Global Definitions

// Definitions

Mutable_Class__0 mut ref mut Mutable_Class__0__0new__0(Mutable_Class__0 mut ref const self) { self->type_id = 26974994; return self; }

Immutable_Class__0 mut ref mut Immutable_Class__0__0new__0(Immutable_Class__0 mut ref const self) { self->type_id = -1808719288; return self; }

void mut main__0()
{
	Mutable_Class__0 const ref const m__ = Mutable_Class__0__0new__0(allocate(sizeof(Mutable_Class__0)));
	Immutable_Class__0 const ref const i__ = Immutable_Class__0__0new__0(allocate(sizeof(Immutable_Class__0)));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
