#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test__0 Test__0;

// Function Declarations
Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self);
inline Test__0 *_Nonnull new_Test__0();
p_optional<int__00> Func__2(p_optional<string__00> const x__, p_optional<uint__00> const y__);
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

struct Test__0
{
};

// Global Definitions

// Definitions

Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self) { return self; }

inline Test__0 *_Nonnull new_Test__0()
{
	return Test__0__0new__0(new Test__0());
}

p_optional<int__00> Func__2(p_optional<string__00> const x__, p_optional<uint__00> const y__)
{
	p_optional<int__00> const z__ = none;
	Test__0 const *_Nullable const t__ = none;
	system__text__String_Builder__0 *_Nullable const sb__ = none;
	system__collections__List__1<p_optional<int__00>> const *_Nonnull const l__ = new_system__collections__List__1<p_optional<int__00>>();
	Test__0 *_Nullable const m__ = none;
	p_optional<p_optional<int__00>> const d__ = none;
	return none;
}

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	Func__2(none, none);
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__1(new system__console__Console__0());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
