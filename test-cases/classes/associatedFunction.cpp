#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct C__0 C__0;

// Function Declarations
C__0 *_Nonnull C__0__0new__0(C__0 *_Nonnull self);
inline C__0 *_Nonnull new_C__0();
auto main__0() -> void;

// Class Declarations

struct C__0
{
	auto method__0() const -> string__00;
	static auto function__0() -> string__00;
};

// Global Definitions

// Definitions

auto ::C__0::method__0() const -> string__00
{
	auto self = this;
	return function__0();
}

auto ::C__0::function__0() -> string__00
{
	return string__00("hello");
}

C__0 *_Nonnull C__0__0new__0(C__0 *_Nonnull self) { return self; }

inline C__0 *_Nonnull new_C__0()
{
	return C__0__0new__0(new C__0());
}

auto main__0() -> void
{
	C__0 const *_Nonnull const c__ = new_C__0();
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
