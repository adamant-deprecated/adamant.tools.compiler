#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Main_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Console_::Arguments_ const *_Nonnull const args_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Main_(::System_::Console_::Console_ *_Nonnull const console_, ::System_::Console_::Arguments_ const *_Nonnull const args_) -> void
{
	for (p_string const arg_ : *(args_))
	{
		console_->WriteLine_(arg_);
	}
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		Main_(new ::System_::Console_::Console_(), new ::System_::Console_::Arguments_(argc, argv));
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
