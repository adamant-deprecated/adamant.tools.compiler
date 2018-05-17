#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__1(system__console__Console *_Nonnull const console__) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main__1(system__console__Console *_Nonnull const console__) -> void
{
	system__collections__List<string> *_Nonnull const strings__ = new_system__collections__List<string>();
	strings__->add__1(string("Hello"));
	strings__->add__1(string("World!"));
	if (cond(not_equal_op(strings__->op__magnitude(), i32(2))))
	{
		console__->WriteLine__1(string("List length not 2!"));
	}

	console__->WriteLine__1(string("strings[0]=").op__add(strings__->op__Element(i32(0))));
	for (string const s__ : *(strings__))
	{
		console__->WriteLine__1(s__);
	}

	console__->WriteLine__0();
	strings__->clear__0();
	system__collections__List<system__text__String_Builder *_Nonnull> *_Nonnull const builders__ = new_system__collections__List<system__text__String_Builder *_Nonnull>();
	builders__->add__1(new_system__text__String_Builder(string("sb[0]: ")));
	builders__->add__1(new_system__text__String_Builder(string("sb[1]: ")));
	for (system__text__String_Builder *_Nonnull const sb__ : *(builders__))
	{
		sb__->Append__1(string("value"));
	}

	for (system__text__String_Builder *_Nonnull const sb__ : *(builders__))
	{
		console__->WriteLine__1(sb__->ToString__0());
	}
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__1(new system__console__Console());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
