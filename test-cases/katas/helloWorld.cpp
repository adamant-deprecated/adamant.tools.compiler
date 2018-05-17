#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main_(system__console__Console *_Nonnull const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main_(system__console__Console *_Nonnull const console_) -> void
{
	console_->WriteLine_(string("Hello World!"));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_(new system__console__Console());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
