#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct C C;

// Function Declarations
C *_Nonnull C__new__1(C *_Nonnull self, string const name_);
inline C *_Nonnull new_C(string const name_);
C *_Nonnull C__new__one__1(C *_Nonnull self, string const name_);
inline C *_Nonnull new_C__one(string const name_);
C *_Nonnull C__new__two__1(C *_Nonnull self, string const name_);
inline C *_Nonnull new_C__two(string const name_);
auto main_() -> void;

// Class Declarations

struct C
{
	string name_;
	i32 kind_;
};

// Global Definitions

// Definitions

C *_Nonnull C__new__1(C *_Nonnull self, string const name_)
{
	self->name_ = name_;
	self->kind_ = i32(0);
	return self;
}

inline C *_Nonnull new_C(string const name_)
{
	return C__new__1(new C(), name_);
}

C *_Nonnull C__new__one__1(C *_Nonnull self, string const name_)
{
	self->name_ = name_;
	self->kind_ = i32(1);
	return self;
}

inline C *_Nonnull new_C__one(string const name_)
{
	return C__new__one__1(new C(), name_);
}

C *_Nonnull C__new__two__1(C *_Nonnull self, string const name_)
{
	self->name_ = name_;
	self->kind_ = i32(2);
	return self;
}

inline C *_Nonnull new_C__two(string const name_)
{
	return C__new__two__1(new C(), name_);
}

auto main_() -> void
{
	new_C(string("0"));
	new_C__one(string("1"));
	new_C__two(string("2"));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
