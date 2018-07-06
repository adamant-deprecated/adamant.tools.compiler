#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type_ID = 0,
};
typedef enum Type_ID Type_ID;

// Type Declarations

// Function Declarations
void mut main__1(system__console__Console__0 mut ref const console__);

// Class Declarations

// Global Definitions

// Definitions

void mut main__1(system__console__Console__0 mut ref const console__)
{
	system__text__String_Builder__0 const ref const v__ = system__text__String_Builder__0__0new__0(allocate(sizeof(system__text__String_Builder__0)));
	system__text__String_Builder__0 const opt_ref const n__ = none;
	BOOL mut r__;
	r__ = void_ptr__0op__equal(v__, n__);
	console_write_line__2(console__, string__0op__add(((string){{8},(uint8_t*)u8"v == n: "}), bool_to_string__1(r__)));
	r__ = void_ptr__0op__equal(n__, v__);
	console_write_line__2(console__, string__0op__add(((string){{8},(uint8_t*)u8"n == v: "}), bool_to_string__1(r__)));
	r__ = void_ptr__0op__equal(n__, n__);
	console_write_line__2(console__, string__0op__add(((string){{8},(uint8_t*)u8"n == n: "}), bool_to_string__1(r__)));
	r__ = void_ptr__0op__equal(n__, none);
	console_write_line__2(console__, string__0op__add(((string){{11},(uint8_t*)u8"n == none: "}), bool_to_string__1(r__)));
	r__ = never__0op__equal(none, n__);
	console_write_line__2(console__, string__0op__add(((string){{11},(uint8_t*)u8"none == n: "}), bool_to_string__1(r__)));
	r__ = never__0op__equal(none, none);
	console_write_line__2(console__, string__0op__add(((string){{14},(uint8_t*)u8"none == none: "}), bool_to_string__1(r__)));
	r__ = void_ptr__0op__not_equal(v__, n__);
	console_write_line__2(console__, string__0op__add(((string){{9},(uint8_t*)u8"v =/= n: "}), bool_to_string__1(r__)));
	r__ = void_ptr__0op__not_equal(n__, v__);
	console_write_line__2(console__, string__0op__add(((string){{9},(uint8_t*)u8"n =/= v: "}), bool_to_string__1(r__)));
	r__ = void_ptr__0op__not_equal(n__, n__);
	console_write_line__2(console__, string__0op__add(((string){{9},(uint8_t*)u8"n =/= n: "}), bool_to_string__1(r__)));
	r__ = void_ptr__0op__not_equal(n__, none);
	console_write_line__2(console__, string__0op__add(((string){{12},(uint8_t*)u8"n =/= none: "}), bool_to_string__1(r__)));
	r__ = never__0op__not_equal(none, n__);
	console_write_line__2(console__, string__0op__add(((string){{12},(uint8_t*)u8"none =/= n: "}), bool_to_string__1(r__)));
	r__ = never__0op__not_equal(none, none);
	console_write_line__2(console__, string__0op__add(((string){{15},(uint8_t*)u8"none =/= none: "}), bool_to_string__1(r__)));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
