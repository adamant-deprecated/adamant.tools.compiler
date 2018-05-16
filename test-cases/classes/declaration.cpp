#include "RuntimeLibrary.hpp"

// Type Declarations
struct t_C;

// Function Declarations
t_C *_Nonnull c_t_C(t_C *_Nonnull self, str const name_);
inline t_C *_Nonnull new_t_C(str const name_);
auto main_() -> void;

// Class Declarations

struct t_C
{
	str name_;
	auto method_() const -> str;
};

// Global Definitions

// Definitions

t_C *_Nonnull c_t_C(t_C *_Nonnull self, str const name_)
{
	self->name_ = name_;
	return self;
}

inline t_C *_Nonnull new_t_C(str const name_)
{
	return c_t_C(new t_C(), name_);
}

auto ::t_C::method_() const -> str
{
	auto self = this;
	return name_;
}

auto main_() -> void
{
	t_C const *_Nonnull const c_ = new_t_C(str("Bob"));
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
