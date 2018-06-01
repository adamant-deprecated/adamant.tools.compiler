#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	Strings__0 *_Nonnull const strings__ = Strings__0__0new__0(allocate(sizeof(Strings__0)));
	add_string__2(strings__, ((string){5,(uint8_t const*)"Hello"}));
	add_string__2(strings__, ((string){6,(uint8_t const*)"World!"}));
	if (cond(int32__0op__not_equal(strings__->count__, ((int32){2}))))
	{
		console__->WriteLine__1(((string){18,(uint8_t const*)"List length not 2!"}));
	}

	console__->WriteLine__1(string__0op__add(((string){11,(uint8_t const*)"strings[0]="}), Strings__0__0op__element(strings__, ((int32){0}))));
	for (string__0iter iter = Strings__0__0iterate(strings__); string__0next(&iter);)
	{
		string const s__ = string__0current(&iter);
		console__->WriteLine__1(s__);
	}

	console__->WriteLine__0();
	clear_strings__1(strings__);
	system__collections__List__1 *_Nonnull const builders__ = system__collections__List__1__0new__0(allocate(sizeof(system__collections__List__1)));
	add_item__2(builders__, system__text__String_Builder__0__0new__1(allocate(sizeof(system__text__String_Builder__0)), ((string){7,(uint8_t const*)"sb[0]: "})));
	add_item__2(builders__, system__text__String_Builder__0__0new__1(allocate(sizeof(system__text__String_Builder__0)), ((string){7,(uint8_t const*)"sb[1]: "})));
	for (void_ptr__0iter iter = system__collections__List__1__0iterate(builders__); void_ptr__0next(&iter);)
	{
		system__text__String_Builder__0 *_Nonnull const sb__ = void_ptr__0current(&iter);
		sb__->Append__1(((string){5,(uint8_t const*)"value"}));
	}

	for (void_ptr__0iter iter = system__collections__List__1__0iterate(builders__); void_ptr__0next(&iter);)
	{
		system__text__String_Builder__0 *_Nonnull const sb__ = void_ptr__0current(&iter);
		console__->WriteLine__1(sb__->ToString__0());
	}

	clear_list__1(builders__);
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(new system__console__Console__0());
	return 0;
}
