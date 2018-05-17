#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct C C;

// Function Declarations
C *_Nonnull C__0new__1(C *_Nonnull self, string__00 const name__);
inline C *_Nonnull new_C(string__00 const name__);
C *_Nonnull C__0new__one__1(C *_Nonnull self, string__00 const name__);
inline C *_Nonnull new_C__one(string__00 const name__);
C *_Nonnull C__0new__two__1(C *_Nonnull self, string__00 const name__);
inline C *_Nonnull new_C__two(string__00 const name__);
auto main__0() -> void;

// Class Declarations

struct C
{
	string__00 name__;
	int__00 kind__;
};

// Global Definitions

// Definitions

C *_Nonnull C__0new__1(C *_Nonnull self, string__00 const name__)
{
	self->name__ = name__;
	self->kind__ = int__00(0);
	return self;
}

inline C *_Nonnull new_C(string__00 const name__)
{
	return C__0new__1(new C(), name__);
}

C *_Nonnull C__0new__one__1(C *_Nonnull self, string__00 const name__)
{
	self->name__ = name__;
	self->kind__ = int__00(1);
	return self;
}

inline C *_Nonnull new_C__one(string__00 const name__)
{
	return C__0new__one__1(new C(), name__);
}

C *_Nonnull C__0new__two__1(C *_Nonnull self, string__00 const name__)
{
	self->name__ = name__;
	self->kind__ = int__00(2);
	return self;
}

inline C *_Nonnull new_C__two(string__00 const name__)
{
	return C__0new__two__1(new C(), name__);
}

auto main__0() -> void
{
	new_C(string__00("0"));
	new_C__one(string__00("1"));
	new_C__two(string__00("2"));
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
