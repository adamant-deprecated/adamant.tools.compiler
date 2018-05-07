#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main_(t_System__Console__Console *_Nonnull const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main_(t_System__Console__Console *_Nonnull const console_) -> void
{
	t_system__collections__List<str> *_Nonnull const strings_ = new_t_system__collections__List<str>();
	strings_->add_(str("Hello"));
	strings_->add_(str("World!"));
	if (cond(not_equal_op(strings_->op_magnitude(), i32(2))))
	{
		console_->WriteLine_(str("List length not 2!"));
	}

	console_->WriteLine_(str("strings[0]=").op_add(strings_->op_Element(i32(0))));
	for (str const s_ : *(strings_))
	{
		console_->WriteLine_(s_);
	}

	console_->WriteLine_();
	strings_->clear_();
	t_system__collections__List<t_system__text__String_Builder *_Nonnull> *_Nonnull const builders_ = new_t_system__collections__List<t_system__text__String_Builder *_Nonnull>();
	builders_->add_(new_t_system__text__String_Builder(str("sb[0]: ")));
	builders_->add_(new_t_system__text__String_Builder(str("sb[1]: ")));
	for (t_system__text__String_Builder *_Nonnull const sb_ : *(builders_))
	{
		sb_->Append_(str("value"));
	}

	for (t_system__text__String_Builder *_Nonnull const sb_ : *(builders_))
	{
		console_->WriteLine_(sb_->ToString_());
	}
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_(new t_system__console__Console());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
