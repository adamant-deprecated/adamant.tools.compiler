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
	r__ = void_ptr__0op__equal(v__, n__);
	console_write_line__2(console__, string__0op__add(((string){8,(uint8_t const*)"v == n: "}), bool_to_string__1(r__)));
	r__ = void_ptr__0op__equal(n__, v__);
	console_write_line__2(console__, string__0op__add(((string){8,(uint8_t const*)"n == v: "}), bool_to_string__1(r__)));
	r__ = void_ptr__0op__equal(n__, n__);
	console_write_line__2(console__, string__0op__add(((string){8,(uint8_t const*)"n == n: "}), bool_to_string__1(r__)));
	r__ = void_ptr__0op__equal(n__, none);
	console_write_line__2(console__, string__0op__add(((string){11,(uint8_t const*)"n == none: "}), bool_to_string__1(r__)));
	r__ = never__0op__equal(none, n__);
	console_write_line__2(console__, string__0op__add(((string){11,(uint8_t const*)"none == n: "}), bool_to_string__1(r__)));
	r__ = never__0op__equal(none, none);
	console_write_line__2(console__, string__0op__add(((string){14,(uint8_t const*)"none == none: "}), bool_to_string__1(r__)));
	r__ = void_ptr__0op__not_equal(v__, n__);
	console_write_line__2(console__, string__0op__add(((string){9,(uint8_t const*)"v =/= n: "}), bool_to_string__1(r__)));
	r__ = void_ptr__0op__not_equal(n__, v__);
	console_write_line__2(console__, string__0op__add(((string){9,(uint8_t const*)"n =/= v: "}), bool_to_string__1(r__)));
	r__ = void_ptr__0op__not_equal(n__, n__);
	console_write_line__2(console__, string__0op__add(((string){9,(uint8_t const*)"n =/= n: "}), bool_to_string__1(r__)));
	r__ = void_ptr__0op__not_equal(n__, none);
	console_write_line__2(console__, string__0op__add(((string){12,(uint8_t const*)"n =/= none: "}), bool_to_string__1(r__)));
	r__ = never__0op__not_equal(none, n__);
	console_write_line__2(console__, string__0op__add(((string){12,(uint8_t const*)"none =/= n: "}), bool_to_string__1(r__)));
	r__ = never__0op__not_equal(none, none);
	console_write_line__2(console__, string__0op__add(((string){15,(uint8_t const*)"none =/= none: "}), bool_to_string__1(r__)));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(new system__console__Console__0());
	return 0;
}
