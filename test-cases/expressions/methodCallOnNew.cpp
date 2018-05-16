#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test Test;

// Function Declarations
Test *_Nonnull c_Test(Test *_Nonnull self);
inline Test *_Nonnull new_Test();
auto main_() -> void;

// Class Declarations

struct Test
{
	bit value_;
};

// Global Definitions

// Definitions

Test *_Nonnull c_Test(Test *_Nonnull self)
{
	self->value_ = bit_true;
	return self;
}

inline Test *_Nonnull new_Test()
{
	return c_Test(new Test());
}

auto main_() -> void
{
	bit const value_ = new_Test()->value_;
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
