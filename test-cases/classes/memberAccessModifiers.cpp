#include "RuntimeLibrary.hpp"

// Type Declarations
class t_C;

// Function Declarations
inline t_C *_Nonnull new_t_C(str const name_);
auto main_() -> void;

// Class Declarations

class t_C
{
public:
	str name_;
	auto construct(str const name_) -> t_C *_Nonnull;
	auto method_() const -> str;
private:
	auto double_name_() const -> str;
};

// Global Definitions

// Definitions

auto t_C::construct(str const name_) -> t_C *_Nonnull
{
	t_C *_Nonnull self = this;
	self->name_ = name_;
	return self;
}

inline t_C *_Nonnull new_t_C(str const name_)
{
	return (new t_C())->construct(name_);
}

auto ::t_C::method_() const -> str
{
	auto self = this;
	return double_name_();
}

auto ::t_C::double_name_() const -> str
{
	auto self = this;
	return name_.op_add(name_);
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
