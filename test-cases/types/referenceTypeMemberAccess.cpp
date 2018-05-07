#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Test;

// Function Declarations
inline t_Test *_Nonnull new_t_Test();
auto main_() -> i32;

// Class Declarations

class t_Test
{
public:
	i32 value_;
	auto construct() -> t_Test *_Nonnull;
};

// Global Definitions

// Definitions

auto t_Test::construct() -> t_Test *_Nonnull
{
	t_Test *_Nonnull self = this;
	value_ = i32(0);
	return self;
}

inline t_Test *_Nonnull new_t_Test()
{
	return (new t_Test())->construct();
}

auto main_() -> i32
{
	t_Test const *_Nonnull const t_ = new_t_Test();
	return t_->value_;
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
