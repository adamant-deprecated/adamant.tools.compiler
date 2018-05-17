#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct C__0 C__0;

// Function Declarations
C__0 *_Nonnull C__0__0new__1(C__0 *_Nonnull self, string__00 const name__);
C__0 *_Nonnull C__0__0new__one__1(C__0 *_Nonnull self, string__00 const name__);
C__0 *_Nonnull C__0__0new__two__1(C__0 *_Nonnull self, string__00 const name__);
void main__0();

// Class Declarations

struct C__0
{
	string__00 name__;
	int__00 kind__;
};

// Global Definitions

// Definitions

C__0 *_Nonnull C__0__0new__1(C__0 *_Nonnull self, string__00 const name__)
{
	self->name__ = name__;
	self->kind__ = int__00(0);
	return self;
}

C__0 *_Nonnull C__0__0new__one__1(C__0 *_Nonnull self, string__00 const name__)
{
	self->name__ = name__;
	self->kind__ = int__00(1);
	return self;
}

C__0 *_Nonnull C__0__0new__two__1(C__0 *_Nonnull self, string__00 const name__)
{
	self->name__ = name__;
	self->kind__ = int__00(2);
	return self;
}

void main__0()
{
	C__0__0new__1(allocate(sizeof(C__0)), string__00("0"));
	C__0__0new__one__1(allocate(sizeof(C__0)), string__00("1"));
	C__0__0new__two__1(allocate(sizeof(C__0)), string__00("2"));
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
