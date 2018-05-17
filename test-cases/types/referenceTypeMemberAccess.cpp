#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test Test;

// Function Declarations
Test *_Nonnull Test__new__0(Test *_Nonnull self);
inline Test *_Nonnull new_Test();
auto main_() -> i32;

// Class Declarations

struct Test
{
	i32 value_;
};

// Global Definitions

// Definitions

Test *_Nonnull Test__new__0(Test *_Nonnull self)
{
	self->value_ = i32(0);
	return self;
}

inline Test *_Nonnull new_Test()
{
	return Test__new__0(new Test());
}

auto main_() -> i32
{
	Test const *_Nonnull const t_ = new_Test();
	return t_->value_;
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		return main_().value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
