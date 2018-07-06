#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type_ID = 0,
	Base__0__0Type_ID,
	A__0__0Type_ID,
	B__0__0Type_ID,
};
typedef enum Type_ID Type_ID;

// Type Declarations

typedef struct Base__0 Base__0;
typedef struct vtable__Base__0 vtable__Base__0;
typedef struct self__Base__0 self__Base__0;
typedef struct { vtable__Base__0 const*_Nonnull restrict vt;  self__Base__0 const*_Nonnull restrict self; } ref__Base__0;
typedef struct { vtable__Base__0 const*_Nonnull restrict vt;  self__Base__0 *_Nonnull restrict self; } ref__0mut__Base__0;

typedef struct A__0 A__0;
typedef struct vtable__A__0 vtable__A__0;
typedef struct self__A__0 self__A__0;
typedef struct { vtable__A__0 const*_Nonnull restrict vt;  self__A__0 const*_Nonnull restrict self; } ref__A__0;
typedef struct { vtable__A__0 const*_Nonnull restrict vt;  self__A__0 *_Nonnull restrict self; } ref__0mut__A__0;

typedef struct B__0 B__0;
typedef struct vtable__B__0 vtable__B__0;
typedef struct self__B__0 self__B__0;
typedef struct { vtable__B__0 const*_Nonnull restrict vt;  self__B__0 const*_Nonnull restrict self; } ref__B__0;
typedef struct { vtable__B__0 const*_Nonnull restrict vt;  self__B__0 *_Nonnull restrict self; } ref__0mut__B__0;

// Function Declarations
Base__0 mut ref mut Base__0__0new__0(Base__0 mut ref const self);
A__0 mut ref mut A__0__0new__0(A__0 mut ref const self);
B__0 mut ref mut B__0__0new__0(B__0 mut ref const self);
int32 mut main__0();

// Class Declarations

struct Base__0
{
	Type_ID type_id;
};

struct A__0
{
	Type_ID type_id;
	int32 mut value_a__;
};

struct B__0
{
	Type_ID type_id;
	int32 mut value_b__;
};

// Global Definitions

// Definitions

Base__0 mut ref mut Base__0__0new__0(Base__0 mut ref const self) { self->type_id = Base__0__0Type_ID; return self; }

A__0 mut ref mut A__0__0new__0(A__0 mut ref const self)
{
	self->type_id = A__0__0Type_ID;
	self->value_a__ = ((int32){1});
	return self;
}

B__0 mut ref mut B__0__0new__0(B__0 mut ref const self)
{
	self->type_id = B__0__0Type_ID;
	self->value_b__ = ((int32){2});
	return self;
}

int32 mut main__0()
{
	Base__0 mut ref const v_mut__ = as_any_mut__1(A__0__0new__0(allocate(sizeof(A__0))));
	Base__0 const ref const v__ = as_any__1(B__0__0new__0(allocate(sizeof(B__0))));
	/* match */ { void const ref const match_value = v__;
	   switch(*(Type_ID const ref)match_value)
	{
		case A__0__0Type_ID:
		{
			A__0 const ref const a__ = match_value;
			return a__->value_a__;
		}
		break;
		case B__0__0Type_ID:
		{
			B__0 const ref const b__ = match_value;
			return b__->value_b__;
		}
		break;
		default:
		{
			return ((int32){0});
		}
		break;
	}}
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	return main__0().value;
}
