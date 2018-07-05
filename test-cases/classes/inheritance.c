#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type__ID = 0,
	Base__0__0Type_ID,
	Derived__0__0Type_ID,
};
typedef enum Type_ID Type_ID;

// Type Declarations
typedef struct Base__0 Base__0;
typedef struct Derived__0 Derived__0;

// Function Declarations
Base__0 mut ref mut Base__0__0new__0(Base__0 mut ref const self);
Derived__0 mut ref mut Derived__0__0new__0(Derived__0 mut ref const self);
void mut main__1(system__console__Console__0 mut ref const console__);

// Class Declarations

struct Base__0
{
	Type_ID type_id;
	BOOL mut base_field__;
};

struct Derived__0
{
	Type_ID type_id;
	BOOL mut base_field__;
	BOOL mut derived_field__;
};

// Global Definitions

// Definitions

Base__0 mut ref mut Base__0__0new__0(Base__0 mut ref const self)
{
	self->type_id = Base__0__0Type_ID;
	self->base_field__ = TRUE;
	return self;
}

Derived__0 mut ref mut Derived__0__0new__0(Derived__0 mut ref const self)
{
	self->type_id = Derived__0__0Type_ID;
	self->base_field__ = TRUE;
	self->derived_field__ = TRUE;
	return self;
}

void mut main__1(system__console__Console__0 mut ref const console__)
{
	Derived__0 const ref const d__ = Derived__0__0new__0(allocate(sizeof(Derived__0)));
	if (cond(d__->derived_field__))
	{
		console_write_line__2(console__, ((string){{19},(uint8_t*)u8"Has `derived_field`"}));
	}

	if (cond(d__->base_field__))
	{
		console_write_line__2(console__, ((string){{22},(uint8_t*)u8"Inherited `base_field`"}));
	}

	Base__0 const ref const b__ = d__;
	if (cond(b__->base_field__))
	{
		console_write_line__2(console__, ((string){{27},(uint8_t*)u8"Assigned and used as `Base`"}));
	}
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
