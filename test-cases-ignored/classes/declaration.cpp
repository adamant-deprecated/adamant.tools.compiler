#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct C__0 C__0;

// Function Declarations
C__0 *_Nonnull C__0__0new__1(C__0 *_Nonnull self, string const name__);
void main__0();

// Class Declarations

struct C__0
{
	string name__;
	string method__0() const;
};

// Global Definitions

// Definitions

C__0 *_Nonnull C__0__0new__1(C__0 *_Nonnull self, string const name__)
{
	self->name__ = name__;
	return self;
}

string C__0::method__0() const
{
	auto self = this;
	return name__;
}

void main__0()
{
	C__0 const *_Nonnull const c__ = C__0__0new__1(allocate(sizeof(C__0)), ((string){3,(uint8_t const*)"Bob"}));
	c__->method__0();
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
