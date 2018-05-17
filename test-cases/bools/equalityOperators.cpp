#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto True__0() -> bool__00;
auto main__0() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto True__0() -> bool__00
{
	return true__00;
}

auto main__0() -> void
{
	bool__00 x__;
	x__ = equal_op(true__00, false__00);
	x__ = not_equal_op(true__00, false__00);
	x__ = equal_op(True__0(), True__0());
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__0();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
