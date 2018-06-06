#include "RuntimeLibrary.h"

// Type Declarations
typedef struct Test__0 Test__0;

// Function Declarations
Test__0 mut ref mut Test__0__0new__0(Test__0 mut ref const self);
void mut main__0();

// Class Declarations

struct Test__0
{
};

// Global Definitions

// Definitions

Test__0 mut ref mut Test__0__0new__0(Test__0 mut ref const self) { return self; }

void mut main__0()
{
	system__collections__List__1 const ref const values__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	void_ptr__0op__equal(values__, values__);
	void_ptr__0op__not_equal(values__, values__);
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
