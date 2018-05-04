#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main_() -> void
{
	i32 const x_ = i32(5);
	i32 const y_ = i32(5);
	i32 const z_ = i32(6);
	assert_(equal_op(x_, y_), str("x=").op_add(x_)->op_add(str(" y="))->op_add(y_));
	assert_(equal_op(y_, z_), str("y=").op_add(y_)->op_add(str(" z="))->op_add(z_));
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
