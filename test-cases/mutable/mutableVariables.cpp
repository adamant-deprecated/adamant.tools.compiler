#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
system__text__String_Builder__0 *_Nonnull Func__2(int__00 x__, int__00 const y__);
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

system__text__String_Builder__0 *_Nonnull Func__2(int__00 x__, int__00 const y__)
{
	x__.op__add_assign(int__00(1));
	int__00 const i__ = x__.op__add(int__00(2));
	int__00 j__ = y__.op__subtract(int__00(23));
	j__ = i__;
	system__text__String_Builder__0 *_Nonnull const stringA__ = system__text__String_Builder__0__0new__1(allocate(sizeof(system__text__String_Builder__0)), string__00("Hello"));
	system__text__String_Builder__0 const *_Nonnull stringB__;
	stringB__ = stringA__;
	return stringA__;
}

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	console__->WriteLine__1(Func__2(int__00(1), int__00(2))->ToString__0());
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(new system__console__Console__0());
	return 0;
}
