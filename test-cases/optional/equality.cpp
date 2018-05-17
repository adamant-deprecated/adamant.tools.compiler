#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	int__00 const v__ = int__00(42);
	p_optional<int__00> const n__ = none;
	bool__00 r__;
	r__ = equal_op(v__, n__);
	console__->WriteLine__1(string__00("v == n: ").op__add(r__));
	r__ = equal_op(n__, v__);
	console__->WriteLine__1(string__00("n == v: ").op__add(r__));
	r__ = equal_op(n__, n__);
	console__->WriteLine__1(string__00("n == v: ").op__add(r__));
	r__ = equal_op(int__00(42), none);
	console__->WriteLine__1(string__00("42 == none: ").op__add(r__));
	r__ = equal_op(none, int__00(42));
	console__->WriteLine__1(string__00("none == 42: ").op__add(r__));
	r__ = equal_op(none, none);
	console__->WriteLine__1(string__00("none == none: ").op__add(r__));
	r__ = not_equal_op(v__, n__);
	console__->WriteLine__1(string__00("v =/= n: ").op__add(r__));
	r__ = not_equal_op(n__, v__);
	console__->WriteLine__1(string__00("n =/= v: ").op__add(r__));
	r__ = not_equal_op(n__, n__);
	console__->WriteLine__1(string__00("n =/= v: ").op__add(r__));
	r__ = not_equal_op(int__00(42), none);
	console__->WriteLine__1(string__00("42 =/= none: ").op__add(r__));
	r__ = not_equal_op(none, int__00(42));
	console__->WriteLine__1(string__00("none =/= 42: ").op__add(r__));
	r__ = not_equal_op(none, none);
	console__->WriteLine__1(string__00("none =/= none: ").op__add(r__));
	system__text__String_Builder__0 const *_Nullable const sb__ = none;
	r__ = equal_op(sb__, none);
	console__->WriteLine__1(string__00("sb == none: ").op__add(r__));
	r__ = equal_op(none, sb__);
	console__->WriteLine__1(string__00("none == sb: ").op__add(r__));
	r__ = not_equal_op(sb__, none);
	console__->WriteLine__1(string__00("sb =/= none: ").op__add(r__));
	r__ = not_equal_op(none, sb__);
	console__->WriteLine__1(string__00("none =/= sb: ").op__add(r__));
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
