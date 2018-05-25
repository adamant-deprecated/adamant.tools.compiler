#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	int32 x__ = (int32){1};
	for (;;)
	{
		if (cond(equal_op(int32__0op__remainder(x__, (int32){3}), (int32){0})))
		{
			if (cond(equal_op(int32__0op__remainder(x__, (int32){5}), (int32){0})))
			{
				console__->WriteLine__1(string("FizzBuzz"));
			}
			else
			{
				console__->WriteLine__1(string("Fizz"));
			}
		}
		else if (cond(equal_op(int32__0op__remainder(x__, (int32){5}), (int32){0})))
		{
			console__->WriteLine__1(string("Buzz"));
		}
		else
		{
			console__->WriteLine__1(x__);
		}

		op__add_assign(&(x__), (int32){1});
		if (cond(int32__0op__gt(x__, (int32){100})))
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
