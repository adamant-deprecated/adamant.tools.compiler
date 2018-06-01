#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
system__text__String_Builder__0 *_Nonnull Func__2(int32 x__, int32 const y__);
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

system__text__String_Builder__0 *_Nonnull Func__2(int32 x__, int32 const y__)
{
	op__add_assign(&(x__), ((int32){1}));
	int32 const i__ = int32__0op__add(x__, ((int32){2}));
	int32 j__ = int32__0op__sub(y__, ((int32){23}));
	j__ = i__;
	system__text__String_Builder__0 *_Nonnull const stringA__ = system__text__String_Builder__0__0new__1(allocate(sizeof(system__text__String_Builder__0)), ((string){5,(uint8_t const*)"Hello"}));
	system__text__String_Builder__0 const *_Nonnull stringB__;
	stringB__ = stringA__;
	return stringA__;
}

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	console_write_line__2(console__, sb_to_string__1(Func__2(((int32){1}), ((int32){2}))));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
