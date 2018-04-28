#include "RuntimeLibrary.hpp"

// Type Declarations
struct Test_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

struct Test_ final
{
public:
	Test_ * operator->() { return this; }
	Test_ const * operator->() const { return this; }
	Test_ & operator* () { return *this; }
	Test_ const & operator* () const { return *this; }
	p_string name_;
	static auto construct(p_string const name_) -> ::Test_;
	auto method_() const -> p_string;
};

// Global Definitions

// Definitions

auto ::Test_::construct(p_string const name_) -> ::Test_
{
	::Test_ self;
	self->name_ = name_;
	return self;
}

auto ::Test_::method_() const -> p_string
{
	auto self = this;
	return name_;
}

auto Main_() -> void
{
	::Test_ const t_ = ::Test_::construct(p_string("Bob"));
	t_.method_();
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
