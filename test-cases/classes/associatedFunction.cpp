#include "RuntimeLibrary.hpp"

// Type Declarations
class C_;

// Function Declarations
auto main_() -> void;

// Class Declarations

class C_
{
public:
	auto method_() const -> str;
	static auto function_() -> str;
	auto construct() -> ::C_* { return this; }
};

// Global Definitions

// Definitions

auto ::C_::method_() const -> str
{
	auto self = this;
	return function_();
}

auto ::C_::function_() -> str
{
	return str("hello");
}

auto main_() -> void
{
	::C_ const *_Nonnull const c_ = (new ::C_())->construct();
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
