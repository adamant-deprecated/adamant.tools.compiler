#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main_(system__console__Console *_Nonnull const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main_(system__console__Console *_Nonnull const console_) -> void
{
	system__collections__List<string> *_Nonnull const strings_ = new_system__collections__List<string>();
	strings_->add_(string("Hello"));
	strings_->add_(string("World!"));
	if (cond(not_equal_op(strings_->op__magnitude(), i32(2))))
	{
		console_->WriteLine_(string("List length not 2!"));
	}

	console_->WriteLine_(string("strings[0]=").op__add(strings_->op__Element(i32(0))));
	for (string const s_ : *(strings_))
	{
		console_->WriteLine_(s_);
	}

	console_->WriteLine_();
	strings_->clear_();
	system__collections__List<system__text__String_Builder *_Nonnull> *_Nonnull const builders_ = new_system__collections__List<system__text__String_Builder *_Nonnull>();
	builders_->add_(new_system__text__String_Builder(string("sb[0]: ")));
	builders_->add_(new_system__text__String_Builder(string("sb[1]: ")));
	for (system__text__String_Builder *_Nonnull const sb_ : *(builders_))
	{
		sb_->Append_(string("value"));
	}

	for (system__text__String_Builder *_Nonnull const sb_ : *(builders_))
	{
		console_->WriteLine_(sb_->ToString_());
	}
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
