#include "RuntimeLibrary.h"

// Type Declarations
class Test_;

// Function Declarations
auto Func_(p_optional<p_string> const x_, p_optional<p_uint> const y_) -> p_optional<p_int> const;
auto Main_(::System_::Console_::Console_ *_Nonnull const console_) -> void;

// Class Declarations

class Test_
{
public:
	p_bool op_Equal(Test_ const * other) const { return this == other; }
	p_bool op_NotEqual(Test_ const * other) const { return this != other; }
	auto construct() -> ::Test_* { return this; }
};

// Global Definitions

// Definitions

auto Func_(p_optional<p_string> const x_, p_optional<p_uint> const y_) -> p_optional<p_int> const
{
	p_optional<p_int> const z_ = ::None;
	::Test_ const *_Nullable const t_ = ::None;
	::System_::Text_::String_Builder_ *_Nullable const sb_ = ::None;
	::System_::Collections_::List_<p_optional<p_int> const> const *_Nonnull const l_ = (new ::System_::Collections_::List_<p_optional<p_int> const>())->construct();
	::Test_ *_Nullable const m_ = ::None;
	p_optional<p_optional<p_int> const> const d_ = ::None;
	return ::None;
}

auto Main_(::System_::Console_::Console_ *_Nonnull const console_) -> void
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
