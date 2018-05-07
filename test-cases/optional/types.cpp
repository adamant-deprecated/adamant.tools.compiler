#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Test;

// Function Declarations
auto Func_(p_optional<str> const x_, p_optional<u32> const y_) -> p_optional<i32>;
auto main_(t_System__Console__Console *_Nonnull const console_) -> void;

// Class Declarations

class t_Test
{
public:
	auto construct() -> ::t_Test* { return this; }
};

// Global Definitions

// Definitions

auto Func_(p_optional<str> const x_, p_optional<u32> const y_) -> p_optional<i32>
{
	p_optional<i32> const z_ = none;
	t_Test const *_Nullable const t_ = none;
	t_System__Text__String_Builder *_Nullable const sb_ = none;
	t_System__Collections__List<p_optional<i32>> const *_Nonnull const l_ = (new t_System__Collections__List<p_optional<i32>>())->construct();
	t_Test *_Nullable const m_ = none;
	p_optional<p_optional<i32>> const d_ = none;
	return none;
}

auto main_(t_System__Console__Console *_Nonnull const console_) -> void
{
	Func_(none, none);
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_(new t_system__console__Console());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
