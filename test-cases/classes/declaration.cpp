#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct C__0 C__0;

// Function Declarations
C__0 *_Nonnull C__0__0new__1(C__0 *_Nonnull self, string__00 const name__);
inline C__0 *_Nonnull new_C__0(string__00 const name__);
void main__0();

// Class Declarations

struct C__0
{
	string__00 name__;
	string__00 method__0() const;
};

// Global Definitions

// Definitions

C__0 *_Nonnull C__0__0new__1(C__0 *_Nonnull self, string__00 const name__)
{
	self->name__ = name__;
	return self;
}

inline C__0 *_Nonnull new_C__0(string__00 const name__)
{
	return C__0__0new__1(new C__0(), name__);
}

string__00 C__0::method__0() const
{
	auto self = this;
	return name__;
}

void main__0()
{
	C__0 const *_Nonnull const c__ = new_C__0(string__00("Bob"));
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
