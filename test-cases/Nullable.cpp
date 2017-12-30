#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Func_(::Maybe<p_string> const x_, ::Maybe<p_uint> const y_) -> ::Maybe<p_int>;
auto Main_(::System_::Console_::Console_ *const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Func_(::Maybe<p_string> const x_, ::Maybe<p_uint> const y_) -> ::Maybe<p_int>
{
	::Maybe<p_int> const z_ = ::None;
	::System_::Text_::String_Builder_ const *const s_ = ::None;
	return ::None;
}

auto Main_(::System_::Console_::Console_ *const console_) -> void
{
	Func_(::None, ::None);
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	Main_(new ::System_::Console_::Console_());
	return 0;
}
