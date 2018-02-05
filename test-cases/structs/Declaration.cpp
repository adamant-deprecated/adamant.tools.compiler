#include "RuntimeLibrary.h"

// Type Declarations
struct test_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

struct test_
{
public:
	test_ * operator->() { return this; }
	test_ const * operator->() const { return this; }
	test_ & operator* () { return *this; }
	test_ const & operator* () const { return *this; }
	p_string Name_;
	test_(p_string const name_);
	auto Method_() const -> p_string;
};

// Global Definitions

// Definitions

::test_::test_(p_string const name_)
{
	Name_ = name_;
}

auto ::test_::Method_() const -> p_string
{
	return Name_;
}

auto Main_() -> void
{
	::test_ const t_ = ::test_(p_string("Bob"));
	t_->Method_();
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
