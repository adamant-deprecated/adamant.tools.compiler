#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Test;

// Function Declarations
t_Test *_Nonnull c_t_Test(t_Test *_Nonnull self);
inline t_Test *_Nonnull new_t_Test();
auto main_(t_system__console__Console *_Nonnull const console_) -> void;

// Class Declarations

class t_Test
{
public:
private:
	bit value_;
public:
	auto change_(bit const value_) -> void;
};

// Global Definitions

// Definitions

auto ::t_Test::change_(bit const value_) -> void
{
	auto self = this;
	self->value_ = value_;
}

t_Test *_Nonnull c_t_Test(t_Test *_Nonnull self) { return self; }

inline t_Test *_Nonnull new_t_Test()
{
	return c_t_Test(new t_Test());
}

auto main_(t_system__console__Console *_Nonnull const console_) -> void
{
	t_Test *_Nonnull const test_ = new_t_Test();
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
