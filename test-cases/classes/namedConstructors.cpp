#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct C C;

// Function Declarations
C *_Nonnull c_C(C *_Nonnull self, str const name_);
inline C *_Nonnull new_C(str const name_);
C *_Nonnull c_C__one(C *_Nonnull self, str const name_);
inline C *_Nonnull new_C__one(str const name_);
C *_Nonnull c_C__two(C *_Nonnull self, str const name_);
inline C *_Nonnull new_C__two(str const name_);
auto main_() -> void;

// Class Declarations

struct C
{
	str name_;
	i32 kind_;
};

// Global Definitions

// Definitions

C *_Nonnull c_C(C *_Nonnull self, str const name_)
{
	self->name_ = name_;
	self->kind_ = i32(0);
	return self;
}

inline C *_Nonnull new_C(str const name_)
{
	return c_C(new C(), name_);
}

C *_Nonnull c_C__one(C *_Nonnull self, str const name_)
{
	self->name_ = name_;
	self->kind_ = i32(1);
	return self;
}

inline C *_Nonnull new_C__one(str const name_)
{
	return c_C__one(new C(), name_);
}

C *_Nonnull c_C__two(C *_Nonnull self, str const name_)
{
	self->name_ = name_;
	self->kind_ = i32(2);
	return self;
}

inline C *_Nonnull new_C__two(str const name_)
{
	return c_C__two(new C(), name_);
}

auto main_() -> void
{
	new_C(str("0"));
	new_C__one(str("1"));
	new_C__two(str("2"));
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
