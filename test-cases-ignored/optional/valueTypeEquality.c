#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	int32 const v__ = int32(42);
	optional__int32 const n__ = none;
	BOOL r__;
	r__ = equal_op(v__, n__);
	console__->WriteLine__1(string("v == n: ").op__add(r__));
	r__ = equal_op(n__, v__);
	console__->WriteLine__1(string("n == v: ").op__add(r__));
	r__ = equal_op(n__, n__);
	console__->WriteLine__1(string("n == v: ").op__add(r__));
	r__ = equal_op(int32(42), none);
	console__->WriteLine__1(string("42 == none: ").op__add(r__));
	r__ = equal_op(none, int32(42));
	console__->WriteLine__1(string("none == 42: ").op__add(r__));
	r__ = equal_op(none, none);
	console__->WriteLine__1(string("none == none: ").op__add(r__));
	r__ = not_equal_op(v__, n__);
	console__->WriteLine__1(string("v =/= n: ").op__add(r__));
	r__ = not_equal_op(n__, v__);
	console__->WriteLine__1(string("n =/= v: ").op__add(r__));
	r__ = not_equal_op(n__, n__);
	console__->WriteLine__1(string("n =/= v: ").op__add(r__));
	r__ = not_equal_op(int32(42), none);
	console__->WriteLine__1(string("42 =/= none: ").op__add(r__));
	r__ = not_equal_op(none, int32(42));
	console__->WriteLine__1(string("none =/= 42: ").op__add(r__));
	r__ = not_equal_op(none, none);
	console__->WriteLine__1(string("none =/= none: ").op__add(r__));
	system__text__String_Builder__0 const *_Nullable const sb__ = none;
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
int32_t main(int argc, char const *const * argv)
{
	main__1(new system__console__Console__0());
	return 0;
}
