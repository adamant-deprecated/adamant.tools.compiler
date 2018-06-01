#include "RuntimeLibrary.h"

// Type Declarations
typedef struct C__0 C__0;

// Function Declarations
C__0 *_Nonnull C__0__0new__0(C__0 *_Nonnull self);
void main__0();

// Class Declarations

struct C__0
{
	string method__0() const;
	static string function__0();
};

// Global Definitions

// Definitions

string C__0::method__0() const
{
	auto self = this;
	return function__0();
}

string C__0::function__0()
{
	return ((string){5,(uint8_t const*)"hello"});
}

C__0 *_Nonnull C__0__0new__0(C__0 *_Nonnull self) { return self; }

void main__0()
{
	C__0 const *_Nonnull const c__ = C__0__0new__0(allocate(sizeof(C__0)));
	c__->method__0();
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
