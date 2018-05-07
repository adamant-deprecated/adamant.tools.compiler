#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Test;

// Function Declarations
auto main_() -> void;

// Class Declarations

class t_Test
{
public:
	auto construct() -> ::t_Test* { return this; }
};

// Global Definitions

// Definitions

auto main_() -> void
{
	t_Test const *_Nonnull const a_ = (new t_Test())->construct();
	t_Test const *_Nonnull const b_ = (new t_Test())->construct();
	bit x_;
	x_ = equal_op(a_, b_);
	x_ = not_equal_op(a_, b_);
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
