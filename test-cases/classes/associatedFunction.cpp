#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct C C;

// Function Declarations
C *_Nonnull C__0new__0(C *_Nonnull self);
inline C *_Nonnull new_C();
auto main__0() -> void;

// Class Declarations

struct C
{
	auto method__0() const -> string;
	static auto function__0() -> string;
};

// Global Definitions

// Definitions

auto ::C::method__0() const -> string
{
	auto self = this;
	return function__0();
}

auto ::C::function__0() -> string
{
	return string("hello");
}

C *_Nonnull C__0new__0(C *_Nonnull self) { return self; }

inline C *_Nonnull new_C()
{
	return C__0new__0(new C());
}

auto main__0() -> void
{
	C const *_Nonnull const c__ = new_C();
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
