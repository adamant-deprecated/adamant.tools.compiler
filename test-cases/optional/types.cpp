#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test Test;

// Function Declarations
Test *_Nonnull Test__new__0(Test *_Nonnull self);
inline Test *_Nonnull new_Test();
auto Func__2(p_optional<string> const x__, p_optional<u32> const y__) -> p_optional<i32>;
auto main__1(system__console__Console *_Nonnull const console__) -> void;

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

auto Func__2(p_optional<string> const x__, p_optional<u32> const y__) -> p_optional<i32>
{
	p_optional<i32> const z__ = none;
	Test const *_Nullable const t__ = none;
	system__text__String_Builder *_Nullable const sb__ = none;
	system__collections__List<p_optional<i32>> const *_Nonnull const l__ = new_system__collections__List<p_optional<i32>>();
	Test *_Nullable const m__ = none;
	p_optional<p_optional<i32>> const d__ = none;
	return none;
}

auto main__1(system__console__Console *_Nonnull const console__) -> void
{
	Func__2(none, none);
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__1(new system__console__Console());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
