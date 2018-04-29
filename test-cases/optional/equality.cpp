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
	p_int const v_ = p_int(0);
	p_optional<p_int> const n_ = p_none;
	p_bool x_;
	x_ = equal_op(v_, n_);
	x_ = not_equal_op(v_, n_);
	x_ = equal_op(n_, v_);
	x_ = not_equal_op(n_, v_);
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
