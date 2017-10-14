#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_(::System_::Console_::Console_ *const console_) -> void;

// Class Declarations

// Definitions
auto Main_(::System_::Console_::Console_ *const console_) -> void
{
	console_->WriteLine_(string("Hello World!"));
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main_(new ::System_::Console_::Console_());
	return 0;
}
