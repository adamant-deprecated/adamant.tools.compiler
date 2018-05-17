#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test Test;

// Function Declarations
Test *_Nonnull Test__new__0(Test *_Nonnull self);
inline Test *_Nonnull new_Test();
auto main_(system__console__Console *_Nonnull const console_) -> void;

// Class Declarations

struct Test
{
	bit value_;
	auto change_(bit const value_) -> void;
};

// Global Definitions

// Definitions

auto ::Test::change_(bit const value_) -> void
{
	auto self = this;
	self->value_ = value_;
}

Test *_Nonnull Test__new__0(Test *_Nonnull self) { return self; }

inline Test *_Nonnull new_Test()
{
	return Test__new__0(new Test());
}

auto main_(system__console__Console *_Nonnull const console_) -> void
{
	Test *_Nonnull const test_ = new_Test();
	test_->change_(bit__true);
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_(new system__console__Console());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
