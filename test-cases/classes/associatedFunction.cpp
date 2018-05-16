#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct C C;

// Function Declarations
C *_Nonnull c_C(C *_Nonnull self);
inline C *_Nonnull new_C();
auto main_() -> void;

// Class Declarations

struct C
{
	auto method_() const -> str;
	static auto function_() -> str;
};

// Global Definitions

// Definitions

auto ::C::method_() const -> str
{
	auto self = this;
	return function_();
}

auto ::C::function_() -> str
{
	return str("hello");
}

C *_Nonnull c_C(C *_Nonnull self) { return self; }

inline C *_Nonnull new_C()
{
	return c_C(new C());
}

auto main_() -> void
{
	C const *_Nonnull const c_ = new_C();
	c_->method_();
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
