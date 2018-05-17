#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test Test;

// Function Declarations
Test *_Nonnull Test__new__0(Test *_Nonnull self);
inline Test *_Nonnull new_Test();
auto Func_(p_optional<string> const x_, p_optional<u32> const y_) -> p_optional<i32>;
auto main_(system__console__Console *_Nonnull const console_) -> void;

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

auto Func_(p_optional<string> const x_, p_optional<u32> const y_) -> p_optional<i32>
{
	p_optional<i32> const z_ = none;
	Test const *_Nullable const t_ = none;
	system__text__String_Builder *_Nullable const sb_ = none;
	system__collections__List<p_optional<i32>> const *_Nonnull const l_ = new_system__collections__List<p_optional<i32>>();
	Test *_Nullable const m_ = none;
	p_optional<p_optional<i32>> const d_ = none;
	return none;
}

auto main_(system__console__Console *_Nonnull const console_) -> void
{
	Func_(none, none);
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_(new system__console__Console());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
