#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	system__collections__List__1<string__00> *_Nonnull const strings__ = system__collections__List__1__0new__0<string__00>(allocate(sizeof(system__collections__List__1<string__00>)));
	strings__->add__1(string__00("Hello"));
	strings__->add__1(string__00("World!"));
	if (cond(not_equal_op(strings__->op__magnitude(), int__00(2))))
	{
		console__->WriteLine__1(string__00("List length not 2!"));
	}

	console__->WriteLine__1(string__00("strings[0]=").op__add(strings__->op__Element(int__00(0))));
	for (string__00 const s__ : *(strings__))
	{
		console__->WriteLine__1(s__);
	}

	console__->WriteLine__0();
	strings__->clear__0();
	system__collections__List__1<system__text__String_Builder__0 *_Nonnull> *_Nonnull const builders__ = system__collections__List__1__0new__0<system__text__String_Builder__0 *_Nonnull>(allocate(sizeof(system__collections__List__1<system__text__String_Builder__0 *_Nonnull>)));
	builders__->add__1(system__text__String_Builder__0__0new__1(allocate(sizeof(system__text__String_Builder__0)), string__00("sb[0]: ")));
	builders__->add__1(system__text__String_Builder__0__0new__1(allocate(sizeof(system__text__String_Builder__0)), string__00("sb[1]: ")));
	for (system__text__String_Builder__0 *_Nonnull const sb__ : *(builders__))
	{
		sb__->Append__1(string__00("value"));
	}

	for (system__text__String_Builder__0 *_Nonnull const sb__ : *(builders__))
	{
		console__->WriteLine__1(sb__->ToString__0());
	}
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__1(new system__console__Console__0());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
