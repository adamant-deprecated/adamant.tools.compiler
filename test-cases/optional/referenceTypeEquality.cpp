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
	console__->WriteLine__1(op__add(((string){8,(uint8_t const*)"v == n: "}), r__));
	r__ = equal_op(n__, v__);
	console__->WriteLine__1(op__add(((string){8,(uint8_t const*)"n == v: "}), r__));
	r__ = equal_op(n__, n__);
	console__->WriteLine__1(op__add(((string){8,(uint8_t const*)"n == n: "}), r__));
	r__ = equal_op(n__, none);
	console__->WriteLine__1(op__add(((string){11,(uint8_t const*)"n == none: "}), r__));
	r__ = equal_op(none, n__);
	console__->WriteLine__1(op__add(((string){11,(uint8_t const*)"none == n: "}), r__));
	r__ = equal_op(none, none);
	console__->WriteLine__1(op__add(((string){14,(uint8_t const*)"none == none: "}), r__));
	r__ = not_equal_op(v__, n__);
	console__->WriteLine__1(op__add(((string){9,(uint8_t const*)"v =/= n: "}), r__));
	r__ = not_equal_op(n__, v__);
	console__->WriteLine__1(op__add(((string){9,(uint8_t const*)"n =/= v: "}), r__));
	r__ = not_equal_op(n__, n__);
	console__->WriteLine__1(op__add(((string){9,(uint8_t const*)"n =/= n: "}), r__));
	r__ = not_equal_op(n__, none);
	console__->WriteLine__1(op__add(((string){12,(uint8_t const*)"n =/= none: "}), r__));
	r__ = not_equal_op(none, n__);
	console__->WriteLine__1(op__add(((string){12,(uint8_t const*)"none =/= n: "}), r__));
	r__ = not_equal_op(none, none);
	console__->WriteLine__1(op__add(((string){15,(uint8_t const*)"none =/= none: "}), r__));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(new system__console__Console__0());
	return 0;
}
