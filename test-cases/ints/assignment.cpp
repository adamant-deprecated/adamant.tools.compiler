#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Main_() -> p_int;

// Class Declarations

// Global Definitions

// Definitions

auto Main_() -> p_int
{
	p_int result_;
	result_ = p_int(40);
	result_.op_add_assign(p_int(3));
	result_.op_subtract_assign(p_int(1));
	return result_;
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		return Main_().value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
