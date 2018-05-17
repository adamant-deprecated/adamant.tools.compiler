#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main_(system__console__Console *_Nonnull const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main_(system__console__Console *_Nonnull const console_) -> void
{
	i32 const v_ = i32(42);
	p_optional<i32> const n_ = none;
	bit r_;
	r_ = equal_op(v_, n_);
	console_->WriteLine_(string("v == n: ").op__add(r_));
	r_ = equal_op(n_, v_);
	console_->WriteLine_(string("n == v: ").op__add(r_));
	r_ = equal_op(n_, n_);
	console_->WriteLine_(string("n == v: ").op__add(r_));
	r_ = equal_op(i32(42), none);
	console_->WriteLine_(string("42 == none: ").op__add(r_));
	r_ = equal_op(none, i32(42));
	console_->WriteLine_(string("none == 42: ").op__add(r_));
	r_ = equal_op(none, none);
	console_->WriteLine_(string("none == none: ").op__add(r_));
	r_ = not_equal_op(v_, n_);
	console_->WriteLine_(string("v =/= n: ").op__add(r_));
	r_ = not_equal_op(n_, v_);
	console_->WriteLine_(string("n =/= v: ").op__add(r_));
	r_ = not_equal_op(n_, n_);
	console_->WriteLine_(string("n =/= v: ").op__add(r_));
	r_ = not_equal_op(i32(42), none);
	console_->WriteLine_(string("42 =/= none: ").op__add(r_));
	r_ = not_equal_op(none, i32(42));
	console_->WriteLine_(string("none =/= 42: ").op__add(r_));
	r_ = not_equal_op(none, none);
	console_->WriteLine_(string("none =/= none: ").op__add(r_));
	system__text__String_Builder const *_Nullable const sb_ = none;
	r_ = equal_op(sb_, none);
	console_->WriteLine_(string("sb == none: ").op__add(r_));
	r_ = equal_op(none, sb_);
	console_->WriteLine_(string("none == sb: ").op__add(r_));
	r_ = not_equal_op(sb_, none);
	console_->WriteLine_(string("sb =/= none: ").op__add(r_));
	r_ = not_equal_op(none, sb_);
	console_->WriteLine_(string("none =/= sb: ").op__add(r_));
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
