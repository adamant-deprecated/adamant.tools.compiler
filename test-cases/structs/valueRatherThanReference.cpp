#include "RuntimeLibrary.h"

// Type Declarations
class Refernce_Type_;
struct Value_Type_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class Refernce_Type_
{
public:
	p_bool op_Equal(Refernce_Type_ const * other) const { return this == other; }
	p_bool op_NotEqual(Refernce_Type_ const * other) const { return this != other; }
};

struct Value_Type_
{
public:
	Value_Type_ * operator->() { return this; }
	Value_Type_ const * operator->() const { return this; }
	Value_Type_ & operator* () { return *this; }
	Value_Type_ const & operator* () const { return *this; }
};

// Global Definitions

// Definitions

auto Main_() -> void
{
	::Refernce_Type_ const *const r_ = (new ::Refernce_Type_());
	::Value_Type_ const v_ = ::Value_Type_();
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
