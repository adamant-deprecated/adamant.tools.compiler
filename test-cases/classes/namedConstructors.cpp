#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct C__0 C__0;

// Function Declarations
C__0 *_Nonnull C__0__0new__1(C__0 *_Nonnull self, string const name__);
C__0 *_Nonnull C__0__0new__one__1(C__0 *_Nonnull self, string const name__);
C__0 *_Nonnull C__0__0new__two__1(C__0 *_Nonnull self, string const name__);
void main__0();

// Class Declarations

struct C__0
{
	string name__;
	int32 kind__;
};

// Global Definitions

// Definitions

C__0 *_Nonnull C__0__0new__1(C__0 *_Nonnull self, string const name__)
{
	self->name__ = name__;
	self->kind__ = ((int32){0});
	return self;
}

C__0 *_Nonnull C__0__0new__one__1(C__0 *_Nonnull self, string const name__)
{
	self->name__ = name__;
	self->kind__ = ((int32){1});
	return self;
}

C__0 *_Nonnull C__0__0new__two__1(C__0 *_Nonnull self, string const name__)
{
	self->name__ = name__;
	self->kind__ = ((int32){2});
	return self;
}

void main__0()
{
	C__0__0new__1(allocate(sizeof(C__0)), ((string){1,(uint8_t const*)"0"}));
	C__0__0new__one__1(allocate(sizeof(C__0)), ((string){1,(uint8_t const*)"1"}));
	C__0__0new__two__1(allocate(sizeof(C__0)), ((string){1,(uint8_t const*)"2"}));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
