#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct C__0 C__0;

// Function Declarations
C__0 *_Nonnull C__0__0new__1(C__0 *_Nonnull self, string__00 const name__);
void main__0();

// Class Declarations

struct C__0
{
	string__00 name__;
	string__00 method__0() const;
	string__00 double_name__0() const;
};

// Global Definitions

// Definitions

C__0 *_Nonnull C__0__0new__1(C__0 *_Nonnull self, string__00 const name__)
{
	self->name__ = name__;
	return self;
}

string__00 C__0::method__0() const
{
	auto self = this;
	return double_name__0();
}

string__00 C__0::double_name__0() const
{
	auto self = this;
	return name__.op__add(name__);
}

void main__0()
{
	C__0 const *_Nonnull const c__ = C__0__0new__1(allocate(sizeof(C__0)), string__00("Bob"));
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
