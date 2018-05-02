#include "RuntimeLibrary.hpp"

// Type Declarations
class C_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class C_
{
public:
	str name_;
	auto construct(str const name_) -> ::C_*;
	auto method_() const -> str;
private:
	auto double_name_() const -> str;
};

// Global Definitions

// Definitions

auto ::C_::construct(str const name_) -> ::C_*
{
	::C_* self = this;
	self->name_ = name_;
	return self;
}

auto ::C_::method_() const -> str
{
	auto self = this;
	return double_name_();
}

auto ::C_::double_name_() const -> str
{
	auto self = this;
	return name_.op_add(name_);
}

auto Main_() -> void
{
	::C_ const *_Nonnull const c_ = (new ::C_())->construct(str("Bob"));
	c_->method_();
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
