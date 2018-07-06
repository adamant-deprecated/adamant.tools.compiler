#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type_ID = 0,
	Mutable_Class__0__0Type_ID,
	Immutable_Class__0__0Type_ID,
};
typedef enum Type_ID Type_ID;

// Type Declarations

typedef struct Mutable_Class__0 Mutable_Class__0;
typedef struct vtable__Mutable_Class__0 vtable__Mutable_Class__0;
typedef struct self__Mutable_Class__0 self__Mutable_Class__0;
typedef struct { vtable__Mutable_Class__0 const*_Nonnull restrict vt;  self__Mutable_Class__0 const*_Nonnull restrict self; } ref__Mutable_Class__0;
typedef struct { vtable__Mutable_Class__0 const*_Nonnull restrict vt;  self__Mutable_Class__0 *_Nonnull restrict self; } ref__0mut__Mutable_Class__0;

typedef struct Immutable_Class__0 Immutable_Class__0;
typedef struct vtable__Immutable_Class__0 vtable__Immutable_Class__0;
typedef struct self__Immutable_Class__0 self__Immutable_Class__0;
typedef struct { vtable__Immutable_Class__0 const*_Nonnull restrict vt;  self__Immutable_Class__0 const*_Nonnull restrict self; } ref__Immutable_Class__0;
typedef struct { vtable__Immutable_Class__0 const*_Nonnull restrict vt;  self__Immutable_Class__0 *_Nonnull restrict self; } ref__0mut__Immutable_Class__0;

// Function Declarations
Mutable_Class__0 mut ref mut Mutable_Class__0__0new__0(Mutable_Class__0 mut ref const self);
Immutable_Class__0 mut ref mut Immutable_Class__0__0new__0(Immutable_Class__0 mut ref const self);
void mut main__0();

// Class Declarations

struct Mutable_Class__0
{
	Type_ID type_id;
};

struct Immutable_Class__0
{
	Type_ID type_id;
};

// Global Definitions

// Definitions

Mutable_Class__0 mut ref mut Mutable_Class__0__0new__0(Mutable_Class__0 mut ref const self) { self->type_id = Mutable_Class__0__0Type_ID; return self; }

Immutable_Class__0 mut ref mut Immutable_Class__0__0new__0(Immutable_Class__0 mut ref const self) { self->type_id = Immutable_Class__0__0Type_ID; return self; }

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
