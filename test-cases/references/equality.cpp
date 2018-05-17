#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test__0 Test__0;

// Function Declarations
Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self);
void main__0();

// Class Declarations

struct Test__0
{
};

// Global Definitions

// Definitions

Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self) { return self; }

void main__0()
{
	Test__0 const *_Nonnull const a__ = Test__0__0new__0(allocate(sizeof(Test__0)));
	Test__0 const *_Nonnull const b__ = Test__0__0new__0(allocate(sizeof(Test__0)));
	bool__00 x__;
	x__ = equal_op(a__, b__);
	x__ = not_equal_op(a__, b__);
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
