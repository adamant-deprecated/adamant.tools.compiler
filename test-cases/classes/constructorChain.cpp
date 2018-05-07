#include "RuntimeLibrary.hpp"

// Type Declarations
class t_C;

// Function Declarations
auto main_() -> void;

// Class Declarations

class t_C
{
public:
	str name_;
	auto construct(str const name_) -> ::t_C*;
	auto method_() const -> str;
};

// Global Definitions

// Definitions

auto ::t_C::construct(str const name_) -> ::t_C*
{
	::t_C* self = this;
	self->name_ = name_;
	return self;
}

auto ::t_C::method_() const -> str
{
	auto self = this;
	return name_;
}

auto main_() -> void
{
	str const s_ = (new t_C())->construct(str("Bob"))->method_();
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
