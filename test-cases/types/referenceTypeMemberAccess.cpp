#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test Test;

// Function Declarations
Test *_Nonnull Test__0new__0(Test *_Nonnull self);
inline Test *_Nonnull new_Test();
auto main__0() -> int__00;

// Class Declarations

struct Test
{
	int__00 value__;
};

// Global Definitions

// Definitions

Test *_Nonnull Test__0new__0(Test *_Nonnull self)
{
	self->value__ = int__00(0);
	return self;
}

inline Test *_Nonnull new_Test()
{
	return Test__0new__0(new Test());
}

auto main__0() -> int__00
{
	Test const *_Nonnull const t__ = new_Test();
	return t__->value__;
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		return main__0().value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
