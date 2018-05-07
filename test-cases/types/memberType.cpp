#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Test;

// Function Declarations
auto main_() -> void;

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
	value_ = i32(1);
	return self;
}

auto main_() -> void
{
	t_Test const *_Nonnull const t_ = (new t_Test())->construct();
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
