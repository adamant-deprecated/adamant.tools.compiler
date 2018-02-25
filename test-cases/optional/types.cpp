#include "RuntimeLibrary.h"

// Type Declarations
class Test_;

// Function Declarations
auto Func_(p_optional<p_string> const x_, p_optional<p_uint> const y_) -> p_optional<p_int>;
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

auto Func_(p_optional<p_string> const x_, p_optional<p_uint> const y_) -> p_optional<p_int>
{
	p_optional<p_int> const z_ = ::None;
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
