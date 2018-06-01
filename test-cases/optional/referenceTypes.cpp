#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test__0 Test__0;

// Function Declarations
Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self);
Test__0 const *_Nullable Func__1(Test__0 const *_Nullable const x__);
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

struct Test__0
{
};

// Global Definitions

// Definitions

Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self) { return self; }

Test__0 const *_Nullable Func__1(Test__0 const *_Nullable const x__)
{
	Test__0 const *_Nullable const t__ = none;
	system__text__String_Builder__0 *_Nullable const sb__ = none;
	system__collections__List__1 const *_Nonnull const l__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	Test__0 *_Nullable const m__ = none;
	return none;
}

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	Func__1(none);
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
