#include "RuntimeLibrary.hpp"

// Type Declarations
class Test_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class Test_
{
public:
	p_bool op_equal(Test_ const * other) const { return this == other; }
	p_bool op_not_equal(Test_ const * other) const { return this != other; }
	auto construct() -> ::Test_* { return this; }
};

// Global Definitions

// Definitions

auto Main_() -> void
{
	::Test_ const *_Nonnull const v_ = (new ::Test_())->construct();
	::Test_ const *_Nullable const n_ = p_none;
	p_bool x_;
	x_ = v_->op_equal(n_);
	x_ = v_->op_not_equal(n_);
	x_ = n_->op_equal(v_);
	x_ = n_->op_not_equal(v_);
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
