#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Func_(p_int x_, p_int const y_) -> ::System_::Text_::String_Builder_ *;
auto Main_(::System_::Console_::Console_ *const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Func_(p_int x_, p_int const y_) -> ::System_::Text_::String_Builder_ *
{
	x_->op_AddAssign(p_int(1));
	p_int const i_ = x_->op_Add(p_int(2));
	p_int j_ = y_->op_Subtract(p_int(23));
	j_ = i_;
	::System_::Text_::String_Builder_ *const stringA_ = new ::System_::Text_::String_Builder_(p_string("Hello"));
	::System_::Text_::String_Builder_ const * stringB_;
	stringB_ = stringA_;
	return stringA_;
}

auto Main_(::System_::Console_::Console_ *const console_) -> void
{
	console_->WriteLine_(Func_(p_int(1), p_int(2))->ToString_());
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		Main_(new ::System_::Console_::Console_());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
