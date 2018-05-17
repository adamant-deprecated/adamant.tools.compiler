#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test Test;

// Function Declarations
Test Test__0new__1(string__00 const name__);
inline Test new_Test(string__00 const name__);
auto main__0() -> void;

// Class Declarations

struct Test
{
	Test * operator->() { return this; }
	Test const * operator->() const { return this; }
	Test & operator* () { return *this; }
	Test const & operator* () const { return *this; }
	string__00 name__;
	auto method__0() const -> string__00;
};

// Global Definitions

// Definitions

Test Test__0new__1(string__00 const name__)
{
	Test self;
	self->name__ = name__;
	return self;
}

inline Test new_Test(string__00 const name__)
{
	return Test__0new__1(name__);
}

auto ::Test::method__0() const -> string__00
{
	auto self = this;
	return name__;
}

auto main__0() -> void
{
	Test const t__ = new_Test(string__00("Bob"));
	t__.method__0();
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__0();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
