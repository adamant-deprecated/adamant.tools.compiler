#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main_() -> i32;

// Class Declarations

// Global Definitions

// Definitions

auto main_() -> i32
{
	i32 result_;
	result_ = i32(40);
	result_.op__add_assign(i32(3));
	result_.op__subtract_assign(i32(1));
	return result_;
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
