#include "RuntimeLibrary.hpp"

// Type Declarations
class Test_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class Test_
{
public:
	auto construct() -> ::Test_* { return this; }
};

// Global Definitions

// Definitions

auto Main_() -> void
{
	::Test_ const *_Nonnull const a_ = (new ::Test_())->construct();
	::Test_ const *_Nonnull const b_ = (new ::Test_())->construct();
	bit x_;
	x_ = equal_op(a_, b_);
	x_ = not_equal_op(a_, b_);
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		Main_();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
