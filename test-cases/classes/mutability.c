#include "RuntimeLibrary.h"

// Type Declarations
typedef struct Mutable_Object__0 Mutable_Object__0;
typedef struct Immutable_object__0 Immutable_object__0;

// Function Declarations
Mutable_Object__0 *_Nonnull Mutable_Object__0__0new__0(Mutable_Object__0 *_Nonnull self);
Immutable_object__0 *_Nonnull Immutable_object__0__0new__0(Immutable_object__0 *_Nonnull self);
void main__0();

// Class Declarations

struct Mutable_Object__0
{
};

struct Immutable_object__0
{
};

// Global Definitions

// Definitions

Mutable_Object__0 *_Nonnull Mutable_Object__0__0new__0(Mutable_Object__0 *_Nonnull self) { return self; }

Immutable_object__0 *_Nonnull Immutable_object__0__0new__0(Immutable_object__0 *_Nonnull self) { return self; }

void main__0()
{
	Mutable_Object__0 const *_Nonnull const m__ = Mutable_Object__0__0new__0(allocate(sizeof(Mutable_Object__0)));
	Immutable_object__0 const *_Nonnull const i__ = Immutable_object__0__0new__0(allocate(sizeof(Immutable_object__0)));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
