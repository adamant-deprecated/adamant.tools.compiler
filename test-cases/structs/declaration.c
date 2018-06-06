#include "RuntimeLibrary.h"

// Type Declarations
typedef struct Test__0 Test__0;

// Function Declarations
Test__0 mut Test__0__0new__1(string const name__);
void mut main__0();

// Class Declarations

struct Test__0
{
	string mut name__;
};

// Global Definitions

// Definitions

Test__0 mut Test__0__0new__1(string const name__)
{
	Test__0 mut self;
	self.name__ = name__;
	return self;
}

void mut main__0()
{
	Test__0 const t__ = Test__0__0new__1(((string){3,(uint8_t const*)"Bob"}));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
