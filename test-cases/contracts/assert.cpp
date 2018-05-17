#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__0();

// Class Declarations

// Global Definitions

// Definitions

void main__0()
{
	int__00 const x__ = int__00(5);
	int__00 const y__ = int__00(5);
	int__00 const z__ = int__00(6);
	assert__2(equal_op(x__, y__), string__00("x=").op__add(x__)->op__add(string__00(" y="))->op__add(y__));
	assert__2(equal_op(y__, z__), string__00("y=").op__add(y__)->op__add(string__00(" z="))->op__add(z__));
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
