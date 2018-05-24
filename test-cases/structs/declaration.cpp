#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test__0 Test__0;

// Function Declarations
Test__0 Test__0__0new__1(string__00 const name__);
void main__0();

// Class Declarations

struct Test__0
{
	string__00 name__;
	string__00 method__0() const;
};

// Global Definitions

// Definitions

Test__0 Test__0__0new__1(string__00 const name__)
{
	Test__0 self;
	self.name__ = name__;
	return self;
}

string__00 Test__0::method__0() const
{
	auto self = this;
	return name__;
}

void main__0()
{
	Test__0 const t__ = Test__0__0new__1(string__00("Bob"));
	t__.method__0();
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
