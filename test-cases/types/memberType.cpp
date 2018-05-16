#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Test;

// Function Declarations
t_Test *_Nonnull c_t_Test(t_Test *_Nonnull self);
inline t_Test *_Nonnull new_t_Test();
auto main_() -> void;

// Class Declarations

class t_Test
{
public:
	i32 value_;
};

// Global Definitions

// Definitions

t_Test *_Nonnull c_t_Test(t_Test *_Nonnull self)
{
	value_ = i32(1);
	return self;
}

inline t_Test *_Nonnull new_t_Test()
{
	return c_t_Test(new t_Test());
}

auto main_() -> void
{
	t_Test const *_Nonnull const t_ = new_t_Test();
	bit const b_ = i32_less_than(t_->value_, i32(5));
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
