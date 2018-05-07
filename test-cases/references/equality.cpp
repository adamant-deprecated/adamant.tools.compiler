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
	auto construct() -> t_Test *_Nonnull { return this; }
};

// Global Definitions

// Definitions

inline t_Test *_Nonnull new_t_Test()
{
	return (new t_Test())->construct();
}

auto main_() -> void
{
	t_Test const *_Nonnull const a_ = new_t_Test();
	t_Test const *_Nonnull const b_ = new_t_Test();
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
