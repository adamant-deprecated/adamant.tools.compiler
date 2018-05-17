#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Func__2(int__00 x__, int__00 const y__) -> system__text__String_Builder__0 *_Nonnull;
auto main__1(system__console__Console__0 *_Nonnull const console__) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Func__2(int__00 x__, int__00 const y__) -> system__text__String_Builder__0 *_Nonnull
{
	x__.op__add_assign(int__00(1));
	int__00 const i__ = x__.op__add(int__00(2));
	int__00 j__ = y__.op__subtract(int__00(23));
	j__ = i__;
	system__text__String_Builder__0 *_Nonnull const stringA__ = new_system__text__String_Builder__0(string__00("Hello"));
	system__text__String_Builder__0 const *_Nonnull stringB__;
	stringB__ = stringA__;
	return stringA__;
}

auto main__1(system__console__Console__0 *_Nonnull const console__) -> void
{
	console__->WriteLine__1(Func__2(int__00(1), int__00(2))->ToString__0());
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
