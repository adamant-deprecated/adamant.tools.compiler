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
	p_string name_;
	C_(p_string const name_);
	auto method_() const -> p_string;
};

// Global Definitions

// Definitions

::C_::C_(p_string const name_)
{
	this->name_ = name_;
}

auto ::C_::method_() const -> p_string
{
	return name_;
}

auto Main_() -> void
{
	p_string const s_ = (new ::C_(p_string("Bob")))->method_();
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
