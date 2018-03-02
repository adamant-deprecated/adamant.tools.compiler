#include "RuntimeLibrary.h"

// Type Declarations
class Mutable_Object_;
class immutable_object_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class Mutable_Object_
{
public:
	p_bool op_Equal(Mutable_Object_ const * other) const { return this == other; }
	p_bool op_NotEqual(Mutable_Object_ const * other) const { return this != other; }
};

class immutable_object_
{
public:
	p_bool op_Equal(immutable_object_ const * other) const { return this == other; }
	p_bool op_NotEqual(immutable_object_ const * other) const { return this != other; }
};

// Global Definitions

// Definitions

auto Main_() -> void
{
	::Mutable_Object_ const *_Nonnull const m_ = (new ::Mutable_Object_());
	::immutable_object_ const *_Nonnull const i_ = (new ::immutable_object_());
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
