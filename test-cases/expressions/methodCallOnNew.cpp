#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test Test;

// Function Declarations
Test *_Nonnull Test__0new__0(Test *_Nonnull self);
inline Test *_Nonnull new_Test();
auto main__0() -> void;

// Class Declarations

struct Test
{
	bool__00 value__;
};

// Global Definitions

// Definitions

Test *_Nonnull Test__0new__0(Test *_Nonnull self)
{
	self->value__ = true__00;
	return self;
}

inline Test *_Nonnull new_Test()
{
	return Test__0new__0(new Test());
}

auto main__0() -> void
{
	bool__00 const value__ = new_Test()->value__;
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
