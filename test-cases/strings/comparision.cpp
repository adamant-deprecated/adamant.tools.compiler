#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Main_() -> void
{
	bit x_;
	x_ = str("a").op_less_than(str("b"));
	x_ = str("a").op_less_than_or_equal(str("b"));
	x_ = str("a").op_greater_than(str("b"));
	x_ = str("a").op_greater_than_or_equal(str("b"));
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
