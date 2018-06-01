#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test__0 Test__0;

// Function Declarations
Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self);
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

struct Test__0
{
	BOOL value__;
	void change__1(BOOL const value__);
};

// Global Definitions

// Definitions

void Test__0::change__1(BOOL const value__)
{
	auto self = this;
	self->value__ = value__;
}

Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self) { return self; }

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	Test__0 *_Nonnull const test__ = Test__0__0new__0(allocate(sizeof(Test__0)));
	test__->change__1(TRUE);
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
