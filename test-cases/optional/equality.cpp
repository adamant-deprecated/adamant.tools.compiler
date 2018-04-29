#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Main_(::System_::Console_::Console_ *_Nonnull const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Main_(::System_::Console_::Console_ *_Nonnull const console_) -> void
{
	i32 const v_ = i32(42);
	p_optional<i32> const n_ = none;
	bit r_;
	r_ = equal_op(v_, n_);
	console_->WriteLine_(p_string("v == n: ").op_add(r_));
	r_ = equal_op(n_, v_);
	console_->WriteLine_(p_string("n == v: ").op_add(r_));
	r_ = equal_op(n_, n_);
	console_->WriteLine_(p_string("n == v: ").op_add(r_));
	r_ = equal_op(i32(42), none);
	console_->WriteLine_(p_string("42 == none: ").op_add(r_));
	r_ = equal_op(none, i32(42));
	console_->WriteLine_(p_string("none == 42: ").op_add(r_));
	r_ = equal_op(none, none);
	console_->WriteLine_(p_string("none == none: ").op_add(r_));
	r_ = not_equal_op(v_, n_);
	console_->WriteLine_(p_string("v =/= n: ").op_add(r_));
	r_ = not_equal_op(n_, v_);
	console_->WriteLine_(p_string("n =/= v: ").op_add(r_));
	r_ = not_equal_op(n_, n_);
	console_->WriteLine_(p_string("n =/= v: ").op_add(r_));
	r_ = not_equal_op(i32(42), none);
	console_->WriteLine_(p_string("42 =/= none: ").op_add(r_));
	r_ = not_equal_op(none, i32(42));
	console_->WriteLine_(p_string("none =/= 42: ").op_add(r_));
	r_ = not_equal_op(none, none);
	console_->WriteLine_(p_string("none =/= none: ").op_add(r_));
	::System_::Text_::String_Builder_ const *_Nullable const sb_ = none;
	r_ = equal_op(sb_, none);
	console_->WriteLine_(p_string("sb == none: ").op_add(r_));
	r_ = equal_op(none, sb_);
	console_->WriteLine_(p_string("none == sb: ").op_add(r_));
	r_ = not_equal_op(sb_, none);
	console_->WriteLine_(p_string("sb =/= none: ").op_add(r_));
	r_ = not_equal_op(none, sb_);
	console_->WriteLine_(p_string("none =/= sb: ").op_add(r_));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		Main_(new ::System_::Console_::Console_());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
