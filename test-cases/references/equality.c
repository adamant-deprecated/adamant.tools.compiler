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
void mut main__0();

// Class Declarations

struct Test__0
{
	Type_ID type_id;
};

// Global Definitions

// Definitions

Test__0 mut ref mut Test__0__0new__0(Test__0 mut ref const self) { self->type_id = Test__0__0Type_ID; return self; }

void mut main__0()
{
	Test__0 const ref const a__ = Test__0__0new__0(allocate(sizeof(Test__0)));
	Test__0 const ref const b__ = Test__0__0new__0(allocate(sizeof(Test__0)));
	BOOL mut x__;
	x__ = void_ptr__0op__equal(a__, b__);
	x__ = void_ptr__0op__not_equal(a__, b__);
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
