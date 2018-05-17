#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test Test;

// Function Declarations
Test *_Nonnull Test__new__0(Test *_Nonnull self);
inline Test *_Nonnull new_Test();
auto main__0() -> void;

// Class Declarations

struct Test
{
};

// Global Definitions

// Definitions

Test *_Nonnull Test__new__0(Test *_Nonnull self) { return self; }

inline Test *_Nonnull new_Test()
{
	return Test__new__0(new Test());
}

auto main__0() -> void
{
	Test const *_Nonnull const a__ = new_Test();
	Test const *_Nonnull const b__ = new_Test();
	bit x__;
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
