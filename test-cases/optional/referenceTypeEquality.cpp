#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	system__text__String_Builder__0 const *_Nonnull const v__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	system__text__String_Builder__0 const *_Nullable const n__ = none;
	BOOL r__;
	r__ = equal_op(v__, n__);
	console__->WriteLine__1(string("v == n: ").op__add(r__));
	r__ = equal_op(n__, v__);
	console__->WriteLine__1(string("n == v: ").op__add(r__));
	r__ = equal_op(n__, n__);
	console__->WriteLine__1(string("n == n: ").op__add(r__));
	r__ = equal_op(n__, none);
	console__->WriteLine__1(string("n == none: ").op__add(r__));
	r__ = equal_op(none, n__);
	console__->WriteLine__1(string("none == n: ").op__add(r__));
	r__ = equal_op(none, none);
	console__->WriteLine__1(string("none == none: ").op__add(r__));
	r__ = not_equal_op(v__, n__);
	console__->WriteLine__1(string("v =/= n: ").op__add(r__));
	r__ = not_equal_op(n__, v__);
	console__->WriteLine__1(string("n =/= v: ").op__add(r__));
	r__ = not_equal_op(n__, n__);
	console__->WriteLine__1(string("n =/= n: ").op__add(r__));
	r__ = not_equal_op(n__, none);
	console__->WriteLine__1(string("n =/= none: ").op__add(r__));
	r__ = not_equal_op(none, n__);
	console__->WriteLine__1(string("none =/= n: ").op__add(r__));
	r__ = not_equal_op(none, none);
	console__->WriteLine__1(string("none =/= none: ").op__add(r__));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(new system__console__Console__0());
	return 0;
}
