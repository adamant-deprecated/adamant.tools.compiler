#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test__0 Test__0;

// Function Declarations
Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self);
void main__0();

// Class Declarations

struct Test__0
{
	int32 value__;
};

// Global Definitions

// Definitions

Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self)
{
	self->value__ = (int32){1};
	return self;
}

void main__0()
{
	Test__0 const *_Nonnull const t__ = Test__0__0new__0(allocate(sizeof(Test__0)));
	BOOL const b__ = int32__0op__lt(t__->value__, (int32){5});
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
