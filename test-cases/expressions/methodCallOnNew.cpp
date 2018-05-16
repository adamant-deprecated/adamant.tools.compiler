#include "RuntimeLibrary.hpp"

// Type Declarations
struct t_Test;

// Function Declarations
t_Test *_Nonnull c_t_Test(t_Test *_Nonnull self);
inline t_Test *_Nonnull new_t_Test();
auto main_() -> void;

// Class Declarations

struct t_Test
{
	bit value_;
};

// Global Definitions

// Definitions

t_Test *_Nonnull c_t_Test(t_Test *_Nonnull self)
{
	self->value_ = bit_true;
	return self;
}

inline t_Test *_Nonnull new_t_Test()
{
	return c_t_Test(new t_Test());
}

auto main_() -> void
{
	bit const value_ = new_t_Test()->value_;
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
