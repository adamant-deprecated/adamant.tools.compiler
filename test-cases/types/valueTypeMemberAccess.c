#include "RuntimeLibrary.h"

// Type Declarations
typedef struct Test__0 Test__0;

// Function Declarations
Test__0 Test__0__0new__0();
int32 main__0();

// Class Declarations

struct Test__0
{
	int32 value__;
};

// Global Definitions

// Definitions

Test__0 Test__0__0new__0()
{
	Test__0 self;
	self.value__ = ((int32){0});
	return self;
}

int32 main__0()
{
	Test__0 const t__ = Test__0__0new__0();
	return t__.value__;
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	return main__0().value;
}