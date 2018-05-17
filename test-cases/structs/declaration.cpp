#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test Test;

// Function Declarations
Test c_Test(string const name_);
inline Test new_Test(string const name_);
auto main_() -> void;

// Class Declarations

struct Test
{
	Test * operator->() { return this; }
	Test const * operator->() const { return this; }
	Test & operator* () { return *this; }
	Test const & operator* () const { return *this; }
	string name_;
	auto method_() const -> string;
};

// Global Definitions

// Definitions

Test c_Test(string const name_)
{
	Test self;
	self->name_ = name_;
	return self;
}

inline Test new_Test(string const name_)
{
	return c_Test(name_);
}

auto ::Test::method_() const -> string
{
	auto self = this;
	return name_;
}

auto main_() -> void
{
	Test const t_ = new_Test(string("Bob"));
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
