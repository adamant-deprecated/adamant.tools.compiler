#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Func__2(i32 x__, i32 const y__) -> system__text__String_Builder *_Nonnull;
auto main__1(system__console__Console *_Nonnull const console__) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Func__2(i32 x__, i32 const y__) -> system__text__String_Builder *_Nonnull
{
	x__.op__add_assign(i32(1));
	i32 const i__ = x__.op__add(i32(2));
	i32 j__ = y__.op__subtract(i32(23));
	j__ = i__;
	system__text__String_Builder *_Nonnull const stringA__ = new_system__text__String_Builder(string("Hello"));
	system__text__String_Builder const *_Nonnull stringB__;
	stringB__ = stringA__;
	return stringA__;
}

auto main__1(system__console__Console *_Nonnull const console__) -> void
{
	console__->WriteLine__1(Func__2(i32(1), i32(2))->ToString__0());
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
