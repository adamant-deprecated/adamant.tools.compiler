#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Func_(i32 x_, i32 const y_) -> system__text__String_Builder *_Nonnull;
auto main_(system__console__Console *_Nonnull const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Func_(i32 x_, i32 const y_) -> system__text__String_Builder *_Nonnull
{
	x_.op__add_assign(i32(1));
	i32 const i_ = x_.op__add(i32(2));
	i32 j_ = y_.op__subtract(i32(23));
	j_ = i_;
	system__text__String_Builder *_Nonnull const stringA_ = new_system__text__String_Builder(string("Hello"));
	system__text__String_Builder const *_Nonnull stringB_;
	stringB_ = stringA_;
	return stringA_;
}

auto main_(system__console__Console *_Nonnull const console_) -> void
{
	console_->WriteLine_(Func_(i32(1), i32(2))->ToString_());
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_(new system__console__Console());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
