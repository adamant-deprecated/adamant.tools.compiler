#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct C C;

// Function Declarations
C *_Nonnull c_C(C *_Nonnull self, str const name_);
inline C *_Nonnull new_C(str const name_);
auto main_() -> void;

// Class Declarations

struct C
{
	str name_;
	auto method_() const -> str;
	auto double_name_() const -> str;
};

// Global Definitions

// Definitions

C *_Nonnull c_C(C *_Nonnull self, str const name_)
{
	self->name_ = name_;
	return self;
}

inline C *_Nonnull new_C(str const name_)
{
	return c_C(new C(), name_);
}

auto ::C::method_() const -> str
{
	auto self = this;
	return double_name_();
}

auto ::C::double_name_() const -> str
{
	auto self = this;
	return name_.op_add(name_);
}

auto main_() -> void
{
	C const *_Nonnull const c_ = new_C(str("Bob"));
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
