#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Test;

// Function Declarations
auto main_() -> i32;

// Class Declarations

class t_Test
{
public:
	i32 value_;
	auto construct() -> ::t_Test*;
};

// Global Definitions

// Definitions

auto ::t_Test::construct() -> ::t_Test*
{
	::t_Test* self = this;
	value_ = i32(0);
	return self;
}

auto main_() -> i32
{
	t_Test const *_Nonnull const t_ = (new t_Test())->construct();
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
