#include "RuntimeLibrary.h"

// Type Declarations
class C_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class C_
{
public:
	p_bool op_Equal(C_ const * other) const { return this == other; }
	p_bool op_NotEqual(C_ const * other) const { return this != other; }
	p_string Name_;
	C_(p_string const name_);
	auto Method_() const -> p_string;
};

// Global Definitions

// Definitions

::C_::C_(p_string const name_)
{
	Name_ = name_;
}

auto ::C_::Method_() const -> p_string
{
	return Name_;
}

auto Main_() -> void
{
	::C_ const *const c_ = new ::C_(p_string("Bob"));
	c_->Method_();
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	Main_();
	return 0;
}
