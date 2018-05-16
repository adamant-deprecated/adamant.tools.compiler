#include "RuntimeLibrary.hpp"

// Type Declarations
struct t_Test;

// Function Declarations
t_Test c_t_Test(str const name_);
inline t_Test new_t_Test(str const name_);
auto main_() -> void;

// Class Declarations

struct t_Test final
{
public:
	t_Test * operator->() { return this; }
	t_Test const * operator->() const { return this; }
	t_Test & operator* () { return *this; }
	t_Test const & operator* () const { return *this; }
	str name_;
	auto method_() const -> str;
};

// Global Definitions

// Definitions

t_Test c_t_Test(str const name_)
{
	t_Test self;
	self->name_ = name_;
	return self;
}

inline t_Test new_t_Test(str const name_)
{
	return c_t_Test(name_);
}

auto ::t_Test::method_() const -> str
{
	auto self = this;
	return name_;
}

auto main_() -> void
{
	t_Test const t_ = new_t_Test(str("Bob"));
	t_.method_();
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
