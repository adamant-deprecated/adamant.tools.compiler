#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_(::System_::Console_::Console_ *const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Main_(::System_::Console_::Console_ *const console_) -> void
{
	console_->WriteLine_(p_string("Hello World!"));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	Main_(new ::System_::Console_::Console_());
	return 0;
}
