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
Test__0 mut ref mut Test__0__0new__1(Test__0 mut ref const self, BOOL const value__);
void mut main__1(system__console__Console__0 mut ref const console__);

// Class Declarations

struct Test__0
{
	Type_ID type_id;
	BOOL mut value__;
};

// Global Definitions

// Definitions

Test__0 mut ref mut Test__0__0new__1(Test__0 mut ref const self, BOOL const value__)
{
	self->type_id = Test__0__0Type_ID;
	self->value__ = value__;
	return self;
}

void mut main__1(system__console__Console__0 mut ref const console__)
{
	Test__0 const ref const t__ = Test__0__0new__1(allocate(sizeof(Test__0)), FALSE);
	if (cond(BOOL__0op__not(t__->value__)))
	{
		console_write_line__2(console__, ((string){4,(uint8_t const*)"Hey!"}));
	}
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
