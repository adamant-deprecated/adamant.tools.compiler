#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type__ID = 0,
	C__0__0Type_ID,
};
typedef enum Type_ID Type_ID;

// Type Declarations
typedef struct C__0 C__0;

// Function Declarations
C__0 mut ref mut C__0__0new__1(C__0 mut ref const self, string const name__);
C__0 mut ref mut C__0__0new__one__1(C__0 mut ref const self, string const name__);
C__0 mut ref mut C__0__0new__two__1(C__0 mut ref const self, string const name__);
void mut main__0();

// Class Declarations

struct C__0
{
	Type_ID type_id;
	string mut name__;
	int32 mut kind__;
};

// Global Definitions

// Definitions

C__0 mut ref mut C__0__0new__1(C__0 mut ref const self, string const name__)
{
	self->type_id = C__0__0Type_ID;
	self->name__ = name__;
	self->kind__ = ((int32){0});
	return self;
}

C__0 mut ref mut C__0__0new__one__1(C__0 mut ref const self, string const name__)
{
	self->type_id = C__0__0Type_ID;
	self->name__ = name__;
	self->kind__ = ((int32){1});
	return self;
}

C__0 mut ref mut C__0__0new__two__1(C__0 mut ref const self, string const name__)
{
	self->type_id = C__0__0Type_ID;
	self->name__ = name__;
	self->kind__ = ((int32){2});
	return self;
}

void mut main__0()
{
	C__0__0new__1(allocate(sizeof(C__0)), ((string){{1},(uint8_t*)u8"0"}));
	C__0__0new__one__1(allocate(sizeof(C__0)), ((string){{1},(uint8_t*)u8"1"}));
	C__0__0new__two__1(allocate(sizeof(C__0)), ((string){{1},(uint8_t*)u8"2"}));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
