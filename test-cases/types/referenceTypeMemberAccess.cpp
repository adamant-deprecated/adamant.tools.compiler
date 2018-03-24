#include "RuntimeLibrary.h"

// Type Declarations
class Test_;

// Function Declarations
auto Main_() -> p_int;

// Class Declarations

class Test_
{
public:
	p_bool op_Equal(Test_ const * other) const { return this == other; }
	p_bool op_NotEqual(Test_ const * other) const { return this != other; }
	p_int value_;
	auto construct() -> ::Test_*;
};

// Global Definitions

// Definitions

auto ::Test_::construct() -> ::Test_*
{
	::Test_* self = this;
	value_ = p_int(0);
	return self;
}

auto Main_() -> p_int
{
	::Test_ const *_Nonnull const t_ = (new ::Test_())->construct();
	return t_->value_;
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		return Main_().value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
