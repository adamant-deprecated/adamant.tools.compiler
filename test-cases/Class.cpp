#include "RuntimeLibrary.h"

// Type Declarations
class C_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class C_
{
public:
	string Name_;
	C_(string const name_);
	auto Method_() const -> string;
};

// Global Definitions

// Definitions

::C_::C_(string const name_)
{
	Name_ = name_;
}

auto ::C_::Method_() const -> string
{
	return Name_;
}

auto Main_() -> void
{
	::C_ const *const c_ = new ::C_(string("Bob"));
	c_->Method_();
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main_();
	return 0;
}
