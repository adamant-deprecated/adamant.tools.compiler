#include "RuntimeLibrary.h"

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
	p_string s_;
	static auto construct() -> ::Test_;
};

// Global Definitions

// Definitions

auto ::Test_::construct() -> ::Test_
{
	::Test_ self;
	s_ = p_string("This is a test");
	p_bool const v_ = self.s_.index_of_(p_code_point('c')).op_Equal(p_int(2));
	return self;
}

auto Main_() -> void
{
	p_int const l_ = ::Test_::construct().s_.index_of_(p_code_point('s'));
	p_bool const v_ = p_string("abc").index_of_(p_code_point('c')).op_Equal(p_int(2));
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
