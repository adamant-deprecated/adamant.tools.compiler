#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main_(t_system__console__Console *_Nonnull const console_, t_system__console__Arguments const *_Nonnull const args_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main_(t_system__console__Console *_Nonnull const console_, t_system__console__Arguments const *_Nonnull const args_) -> void
{
	for (str const arg_ : *(args_))
	{
		console_->WriteLine_(arg_);
	}
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_(new t_system__console__Console(), new t_system__console__Arguments(argc, argv));
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
