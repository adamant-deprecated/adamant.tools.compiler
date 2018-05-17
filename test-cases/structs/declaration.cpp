#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test__0 Test__0;

// Function Declarations
Test__0 Test__0__0new__1(string__00 const name__);
inline Test__0 new_Test__0(string__00 const name__);
auto main__0() -> void;

// Class Declarations

struct Test__0
{
	Test__0 * operator->() { return this; }
	Test__0 const * operator->() const { return this; }
	Test__0 & operator* () { return *this; }
	Test__0 const & operator* () const { return *this; }
	string__00 name__;
	auto method__0() const -> string__00;
};

// Global Definitions

// Definitions

Test__0 Test__0__0new__1(string__00 const name__)
{
	Test__0 self;
	self->name__ = name__;
	return self;
}

inline Test__0 new_Test__0(string__00 const name__)
{
	return Test__0__0new__1(name__);
}

auto ::Test__0::method__0() const -> string__00
{
	auto self = this;
	return name__;
}

auto main__0() -> void
{
	Test__0 const t__ = new_Test__0(string__00("Bob"));
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
