#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_(::System_::Console_::Console_ *const console_, ::System_::Console_::Arguments_ const *const args_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Main_(::System_::Console_::Console_ *const console_, ::System_::Console_::Arguments_ const *const args_) -> void
{
	for (p_string const arg_ : *(args_))
	{
		console_->WriteLine_(arg_);
	}
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	Main_(new ::System_::Console_::Console_(), new ::System_::Console_::Arguments_(argc, argv));
	return 0;
}
