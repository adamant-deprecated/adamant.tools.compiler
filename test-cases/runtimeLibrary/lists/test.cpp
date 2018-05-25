#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	system__collections__List__1<string> *_Nonnull const strings__ = system__collections__List__1__0new__0<string>(allocate(sizeof(system__collections__List__1<string>)));
	strings__->add__1(((string){5,(uint8_t const*)"Hello"}));
	strings__->add__1(((string){6,(uint8_t const*)"World!"}));
	if (cond(not_equal_op(strings__->op__magnitude(), (int32){2})))
	{
		console__->WriteLine__1(((string){18,(uint8_t const*)"List length not 2!"}));
	}

	console__->WriteLine__1(op__add(((string){11,(uint8_t const*)"strings[0]="}), strings__->op__Element((int32){0})));
	for (string const s__ : *(strings__))
	{
		console__->WriteLine__1(s__);
	}

	console__->WriteLine__0();
	strings__->clear__0();
	system__collections__List__1<system__text__String_Builder__0 *_Nonnull> *_Nonnull const builders__ = system__collections__List__1__0new__0<system__text__String_Builder__0 *_Nonnull>(allocate(sizeof(system__collections__List__1<system__text__String_Builder__0 *_Nonnull>)));
	builders__->add__1(system__text__String_Builder__0__0new__1(allocate(sizeof(system__text__String_Builder__0)), ((string){7,(uint8_t const*)"sb[0]: "})));
	builders__->add__1(system__text__String_Builder__0__0new__1(allocate(sizeof(system__text__String_Builder__0)), ((string){7,(uint8_t const*)"sb[1]: "})));
	for (system__text__String_Builder__0 *_Nonnull const sb__ : *(builders__))
	{
		sb__->Append__1(((string){5,(uint8_t const*)"value"}));
	}

	for (system__text__String_Builder__0 *_Nonnull const sb__ : *(builders__))
	{
		console__->WriteLine__1(sb__->ToString__0());
	}
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(new system__console__Console__0());
	return 0;
}
