#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Test;

// Function Declarations
auto main_(t_System__Console__Console *_Nonnull const console_) -> void;

// Class Declarations

class t_Test
{
public:
private:
	bit value_;
public:
	auto change_(bit const value_) -> void;
	auto construct() -> ::t_Test* { return this; }
};

// Global Definitions

// Definitions

auto ::t_Test::change_(bit const value_) -> void
{
	auto self = this;
	self->value_ = value_;
}

auto main_(t_System__Console__Console *_Nonnull const console_) -> void
{
	t_Test *_Nonnull const test_ = (new t_Test())->construct();
	test_->change_(bit_true);
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_(new t_system__console__Console());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
