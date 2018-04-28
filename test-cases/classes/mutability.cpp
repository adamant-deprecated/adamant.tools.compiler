#include "RuntimeLibrary.hpp"

// Type Declarations
class Mutable_Object_;
class immutable_object_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class Mutable_Object_
{
public:
	p_bool op_equal(Mutable_Object_ const * other) const { return this == other; }
	p_bool op_not_equal(Mutable_Object_ const * other) const { return this != other; }
	auto construct() -> ::Mutable_Object_* { return this; }
};

class immutable_object_
{
public:
	p_bool op_equal(immutable_object_ const * other) const { return this == other; }
	p_bool op_not_equal(immutable_object_ const * other) const { return this != other; }
	auto construct() -> ::immutable_object_* { return this; }
};

// Global Definitions

// Definitions

auto Main_() -> void
{
	::Mutable_Object_ const *_Nonnull const m_ = (new ::Mutable_Object_())->construct();
	::immutable_object_ const *_Nonnull const i_ = (new ::immutable_object_())->construct();
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		Main_();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
