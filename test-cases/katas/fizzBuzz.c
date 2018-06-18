#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type__ID = 0,
};
typedef enum Type_ID Type_ID;

// Type Declarations

// Function Declarations
void mut main__1(system__console__Console__0 mut ref const console__);

// Class Declarations

// Global Definitions

// Definitions

void mut main__1(system__console__Console__0 mut ref const console__)
{
	int32 mut x__ = ((int32){1});
	for (;;)
	{
		if (cond(int32__0op__equal(int32__0op__remainder(x__, ((int32){3})), ((int32){0}))))
		{
			if (cond(int32__0op__equal(int32__0op__remainder(x__, ((int32){5})), ((int32){0}))))
			{
				console_write_line__2(console__, ((string){{8},(uint8_t*)u8"FizzBuzz"}));
			}
			else
			{
				console_write_line__2(console__, ((string){{4},(uint8_t*)u8"Fizz"}));
			}
		}
		else if (cond(int32__0op__equal(int32__0op__remainder(x__, ((int32){5})), ((int32){0}))))
		{
			console_write_line__2(console__, ((string){{4},(uint8_t*)u8"Buzz"}));
		}
		else
		{
			console_write_line__2(console__, int_to_string__1(x__));
		}

		op__add_assign(&(x__), ((int32){1}));
		if (cond(int32__0op__gt(x__, ((int32){100}))))
		{
			break;
		}
	}
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
