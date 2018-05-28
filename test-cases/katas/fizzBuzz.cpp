#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	int32 x__ = ((int32){1});
	for (;;)
	{
		if (cond(int32__0op__equal(int32__0op__remainder(x__, ((int32){3})), ((int32){0}))))
		{
			if (cond(int32__0op__equal(int32__0op__remainder(x__, ((int32){5})), ((int32){0}))))
			{
				console__->WriteLine__1(((string){8,(uint8_t const*)"FizzBuzz"}));
			}
			else
			{
				console__->WriteLine__1(((string){4,(uint8_t const*)"Fizz"}));
			}
		}
		else if (cond(int32__0op__equal(int32__0op__remainder(x__, ((int32){5})), ((int32){0}))))
		{
			console__->WriteLine__1(((string){4,(uint8_t const*)"Buzz"}));
		}
		else
		{
			console__->WriteLine__1(int_to_string__1(x__));
		}

		op__add_assign(&(x__), ((int32){1}));
		if (cond(int32__0op__gt(x__, ((int32){100}))))
		{
			break;
		}
	}
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(new system__console__Console__0());
	return 0;
}
