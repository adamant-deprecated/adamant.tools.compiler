#include "RuntimeLibrary.hpp"

// Type Declarations
class Test_;

// Function Declarations
auto Main_() -> i32;

// Class Declarations

class Test_
{
public:
	i32 value_;
	auto construct() -> ::Test_*;
};

// Global Definitions

// Definitions

auto ::Test_::construct() -> ::Test_*
{
	::Test_* self = this;
	value_ = i32(0);
	return self;
}

auto Main_() -> i32
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
