#include "RuntimeLibrary.hpp"

// Type Declarations
class Test_;

// Function Declarations
auto main_(::System_::Console_::Console_ *_Nonnull const console_) -> void;

// Class Declarations

class Test_
{
public:
private:
	bit value_;
public:
	auto change_(bit const value_) -> void;
	auto construct() -> ::Test_* { return this; }
};

// Global Definitions

// Definitions

auto ::Test_::change_(bit const value_) -> void
{
	auto self = this;
	self->value_ = value_;
}

auto main_(::System_::Console_::Console_ *_Nonnull const console_) -> void
{
	::Test_ *_Nonnull const test_ = (new ::Test_())->construct();
	test_->change_(bit_true);
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_(new ::System_::Console_::Console_());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
