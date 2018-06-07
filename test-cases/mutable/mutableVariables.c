#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type__ID = 0,
};
typedef enum Type_ID Type_ID;

// Type Declarations

// Function Declarations
system__text__String_Builder__0 mut ref mut Func__2(int32 mut x__, int32 const y__);
void mut main__1(system__console__Console__0 mut ref const console__);

// Class Declarations

// Global Definitions

// Definitions

system__text__String_Builder__0 mut ref mut Func__2(int32 mut x__, int32 const y__)
{
	op__add_assign(&(x__), ((int32){1}));
	int32 const i__ = int32__0op__add(x__, ((int32){2}));
	int32 mut j__ = int32__0op__sub(y__, ((int32){23}));
	j__ = i__;
	system__text__String_Builder__0 mut ref const string_a__ = system__text__String_Builder__0__0new__1(allocate(sizeof(system__text__String_Builder__0)), ((string){5,(uint8_t const*)"Hello"}));
	system__text__String_Builder__0 const ref mut string_b__;
	string_b__ = string_a__;
	return string_a__;
}

void mut main__1(system__console__Console__0 mut ref const console__)
{
	console_write_line__2(console__, sb_to_string__1(Func__2(((int32){1}), ((int32){2}))));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
