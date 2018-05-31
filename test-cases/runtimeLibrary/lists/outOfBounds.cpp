#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test__0 Test__0;

// Function Declarations
Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self);
void main__0();

// Class Declarations

struct Test__0
{
};

// Global Definitions

// Definitions

Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self) { return self; }

void main__0()
{
	system__collections__List__1<Test__0 const *_Nonnull> const *_Nonnull const values__ = system__collections__List__1__0new__0<Test__0 const *_Nonnull>(allocate(sizeof(system__collections__List__1<Test__0 const *_Nonnull>)));
	system__collections__List__1__0op__element(values__, ((int32){0}));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
