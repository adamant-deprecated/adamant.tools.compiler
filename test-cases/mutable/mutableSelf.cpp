#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test Test;

// Function Declarations
Test *_Nonnull Test__0new__0(Test *_Nonnull self);
inline Test *_Nonnull new_Test();
auto main__1(system__console__Console *_Nonnull const console__) -> void;

// Class Declarations

struct Test
{
	bit value__;
	auto change__1(bit const value__) -> void;
};

// Global Definitions

// Definitions

auto ::Test::change__1(bit const value__) -> void
{
	auto self = this;
	self->value__ = value__;
}

Test *_Nonnull Test__0new__0(Test *_Nonnull self) { return self; }

inline Test *_Nonnull new_Test()
{
	return Test__0new__0(new Test());
}

auto main__1(system__console__Console *_Nonnull const console__) -> void
{
	Test *_Nonnull const test__ = new_Test();
	test__->change__1(bit__true);
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__1(new system__console__Console());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
