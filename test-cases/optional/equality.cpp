#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__1(system__console__Console *_Nonnull const console__) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main__1(system__console__Console *_Nonnull const console__) -> void
{
	i32 const v__ = i32(42);
	p_optional<i32> const n__ = none;
	bit r__;
	r__ = equal_op(v__, n__);
	console__->WriteLine__1(string("v == n: ").op__add(r__));
	r__ = equal_op(n__, v__);
	console__->WriteLine__1(string("n == v: ").op__add(r__));
	r__ = equal_op(n__, n__);
	console__->WriteLine__1(string("n == v: ").op__add(r__));
	r__ = equal_op(i32(42), none);
	console__->WriteLine__1(string("42 == none: ").op__add(r__));
	r__ = equal_op(none, i32(42));
	console__->WriteLine__1(string("none == 42: ").op__add(r__));
	r__ = equal_op(none, none);
	console__->WriteLine__1(string("none == none: ").op__add(r__));
	r__ = not_equal_op(v__, n__);
	console__->WriteLine__1(string("v =/= n: ").op__add(r__));
	r__ = not_equal_op(n__, v__);
	console__->WriteLine__1(string("n =/= v: ").op__add(r__));
	r__ = not_equal_op(n__, n__);
	console__->WriteLine__1(string("n =/= v: ").op__add(r__));
	r__ = not_equal_op(i32(42), none);
	console__->WriteLine__1(string("42 =/= none: ").op__add(r__));
	r__ = not_equal_op(none, i32(42));
	console__->WriteLine__1(string("none =/= 42: ").op__add(r__));
	r__ = not_equal_op(none, none);
	console__->WriteLine__1(string("none =/= none: ").op__add(r__));
	system__text__String_Builder const *_Nullable const sb__ = none;
	r__ = equal_op(sb__, none);
	console__->WriteLine__1(string("sb == none: ").op__add(r__));
	r__ = equal_op(none, sb__);
	console__->WriteLine__1(string("none == sb: ").op__add(r__));
	r__ = not_equal_op(sb__, none);
	console__->WriteLine__1(string("sb =/= none: ").op__add(r__));
	r__ = not_equal_op(none, sb__);
	console__->WriteLine__1(string("none =/= sb: ").op__add(r__));
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
