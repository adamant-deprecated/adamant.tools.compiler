#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Test;

// Function Declarations
inline t_Test *_Nonnull new_t_Test();
auto main_() -> void;

// Class Declarations

class t_Test
{
public:
	bit value_;
	auto construct() -> t_Test *_Nonnull;
};

// Global Definitions

// Definitions

auto t_Test::construct() -> t_Test *_Nonnull
{
	t_Test *_Nonnull self = this;
	value_ = bit_true;
	return self;
}

inline t_Test *_Nonnull new_t_Test()
{
	return (new t_Test())->construct();
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
