#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct C C;

// Function Declarations
C *_Nonnull C__0new__1(C *_Nonnull self, string const name__);
inline C *_Nonnull new_C(string const name__);
auto main__0() -> void;

// Class Declarations

struct C
{
	string name__;
	auto method__0() const -> string;
};

// Global Definitions

// Definitions

C *_Nonnull C__0new__1(C *_Nonnull self, string const name__)
{
	self->name__ = name__;
	return self;
}

inline C *_Nonnull new_C(string const name__)
{
	return C__0new__1(new C(), name__);
}

auto ::C::method__0() const -> string
{
	auto self = this;
	return name__;
}

auto main__0() -> void
{
	C const *_Nonnull const c__ = new_C(string("Bob"));
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
