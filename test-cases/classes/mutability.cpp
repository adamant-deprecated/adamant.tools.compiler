#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Mutable_Object;
class t_immutable_object;

// Function Declarations
auto main_() -> void;

// Class Declarations

class t_Mutable_Object
{
public:
	auto construct() -> ::t_Mutable_Object* { return this; }
};

class t_immutable_object
{
public:
	auto construct() -> ::t_immutable_object* { return this; }
};

// Global Definitions

// Definitions

auto main_() -> void
{
	t_Mutable_Object const *_Nonnull const m_ = (new t_Mutable_Object())->construct();
	t_immutable_object const *_Nonnull const i_ = (new t_immutable_object())->construct();
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
