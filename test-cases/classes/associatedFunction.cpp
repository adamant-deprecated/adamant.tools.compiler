#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct C__0 C__0;

// Function Declarations
C__0 *_Nonnull C__0__0new__0(C__0 *_Nonnull self);
void main__0();

// Class Declarations

struct C__0
{
	string__00 method__0() const;
	static string__00 function__0();
};

// Global Definitions

// Definitions

string__00 C__0::method__0() const
{
	auto self = this;
	return function__0();
}

string__00 C__0::function__0()
{
	return string__00("hello");
}

C__0 *_Nonnull C__0__0new__0(C__0 *_Nonnull self) { return self; }

void main__0()
{
	C__0 const *_Nonnull const c__ = C__0__0new__0(allocate(sizeof(C__0)));
	c__->method__0();
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
