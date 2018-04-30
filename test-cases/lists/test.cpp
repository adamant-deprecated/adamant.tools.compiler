#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto Main_(::System_::Console_::Console_ *_Nonnull const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Main_(::System_::Console_::Console_ *_Nonnull const console_) -> void
{
	::System_::Collections_::List_<str> *_Nonnull const strings_ = (new ::System_::Collections_::List_<str>())->construct();
	strings_->Add_(str("Hello"));
	strings_->Add_(str("World!"));
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
	strings_->Clear_();
	::System_::Collections_::List_<::System_::Text_::String_Builder_ *_Nonnull> *_Nonnull const builders_ = (new ::System_::Collections_::List_<::System_::Text_::String_Builder_ *_Nonnull>())->construct();
	builders_->Add_((new ::System_::Text_::String_Builder_())->construct(str("sb[0]: ")));
	builders_->Add_((new ::System_::Text_::String_Builder_())->construct(str("sb[1]: ")));
	for (::System_::Text_::String_Builder_ *_Nonnull const sb_ : *(builders_))
	{
		sb_->Append_(str("value"));
	}

	for (::System_::Text_::String_Builder_ *_Nonnull const sb_ : *(builders_))
	{
		console_->WriteLine_(sb_->ToString_());
	}
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
