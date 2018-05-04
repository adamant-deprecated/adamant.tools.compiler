#include "RuntimeLibrary.hpp"

// Type Declarations
class Test_;

// Function Declarations
auto main_() -> void;

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
	value_ = i32(1);
	return self;
}

auto main_() -> void
{
	::Test_ const *_Nonnull const t_ = (new ::Test_())->construct();
	bit const b_ = i32_less_than(t_->value_, i32(5));
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
