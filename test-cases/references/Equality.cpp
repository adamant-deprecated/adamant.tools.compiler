#include "RuntimeLibrary.h"

// Type Declarations
class Test_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class Test_
{
public:
	p_bool op_Equal(Test_ const * other) const { return this == other; }
	p_bool op_NotEqual(Test_ const * other) const { return this != other; }
};

// Global Definitions

// Definitions

auto Main_() -> void
{
	::Test_ const *const a_ = (new ::Test_());
	::Test_ const *const b_ = (new ::Test_());
	p_bool x_;
	x_ = a_->op_Equal(b_);
	x_ = a_->op_NotEqual(b_);
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
