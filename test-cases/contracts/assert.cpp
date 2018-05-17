#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__0() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main__0() -> void
{
	i32 const x__ = i32(5);
	i32 const y__ = i32(5);
	i32 const z__ = i32(6);
	assert__2(equal_op(x__, y__), string("x=").op__add(x__)->op__add(string(" y="))->op__add(y__));
	assert__2(equal_op(y__, z__), string("y=").op__add(y__)->op__add(string(" z="))->op__add(z__));
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
