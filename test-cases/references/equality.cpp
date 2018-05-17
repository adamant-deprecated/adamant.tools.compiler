#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test Test;

// Function Declarations
Test *_Nonnull Test__new__0(Test *_Nonnull self);
inline Test *_Nonnull new_Test();
auto main_() -> void;

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

auto main_() -> void
{
	Test const *_Nonnull const a_ = new_Test();
	Test const *_Nonnull const b_ = new_Test();
	bit x_;
	x_ = equal_op(a_, b_);
	x_ = not_equal_op(a_, b_);
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
