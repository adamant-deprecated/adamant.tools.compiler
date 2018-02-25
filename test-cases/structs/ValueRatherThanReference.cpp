#include "RuntimeLibrary.h"

// Type Declarations
class reference_type_;
struct value_type_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class reference_type_
{
public:
	p_bool op_Equal(reference_type_ const * other) const { return this == other; }
	p_bool op_NotEqual(reference_type_ const * other) const { return this != other; }
};

struct value_type_
{
public:
	value_type_ * operator->() { return this; }
	value_type_ const * operator->() const { return this; }
	value_type_ & operator* () { return *this; }
	value_type_ const & operator* () const { return *this; }
};

// Global Definitions

// Definitions

auto Main_() -> void
{
	::reference_type_ const *const r_ = (new ::reference_type_());
	::value_type_ const v_ = ::value_type_();
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
