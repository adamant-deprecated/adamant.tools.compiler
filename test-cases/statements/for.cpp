#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__2(system__console__Console *_Nonnull const console__, system__console__Arguments const *_Nonnull const args__) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main__2(system__console__Console *_Nonnull const console__, system__console__Arguments const *_Nonnull const args__) -> void
{
	for (string__00 const arg__ : *(args__))
	{
		console__->WriteLine__1(arg__);
	}
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__2(new system__console__Console(), new system__console__Arguments(argc, argv));
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
