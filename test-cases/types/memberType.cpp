#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test__0 Test__0;

// Function Declarations
Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self);
inline Test__0 *_Nonnull new_Test__0();
auto main__0() -> void;

// Class Declarations

struct Test__0
{
	int__00 value__;
};

// Global Definitions

// Definitions

Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self)
{
	self->value__ = int__00(1);
	return self;
}

inline Test__0 *_Nonnull new_Test__0()
{
	return Test__0__0new__0(new Test__0());
}

auto main__0() -> void
{
	Test__0 const *_Nonnull const t__ = new_Test__0();
	bool__00 const b__ = int__00__0op__less_than(t__->value__, int__00(5));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__0();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
