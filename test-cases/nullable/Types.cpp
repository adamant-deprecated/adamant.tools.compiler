#include "RuntimeLibrary.h"

// Type Declarations
class Test_;

// Function Declarations
auto Func_(p_maybe<p_string> const x_, p_maybe<p_uint> const y_) -> p_maybe<p_int>;
auto Main_(::System_::Console_::Console_ *const console_) -> void;

// Class Declarations

class Test_
{
public:
	p_bool op_Equal(Test_ const * other) const { return this == other; }
	p_bool op_NotEqual(Test_ const * other) const { return this != other; }
};

// Global Definitions

// Definitions

auto Func_(p_maybe<p_string> const x_, p_maybe<p_uint> const y_) -> p_maybe<p_int>
{
	p_maybe<p_int> const z_ = ::None;
	::Test_ const *const t_ = ::None;
	::System_::Text_::String_Builder_ *const sb_ = ::None;
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
