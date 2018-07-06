#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type_ID = 0,
};
typedef enum Type_ID Type_ID;

// Type Declarations

// Function Declarations
void mut main__0();

// Class Declarations

// Global Definitions

// Definitions

void mut main__0()
{
	BOOL mut x__;
	x__ = string__0op__lt(((string){{1},(uint8_t*)u8"a"}), ((string){{1},(uint8_t*)u8"b"}));
	x__ = string__0op__lte(((string){{1},(uint8_t*)u8"a"}), ((string){{1},(uint8_t*)u8"b"}));
	x__ = string__0op__gt(((string){{1},(uint8_t*)u8"a"}), ((string){{1},(uint8_t*)u8"b"}));
	x__ = string__0op__gte(((string){{1},(uint8_t*)u8"a"}), ((string){{1},(uint8_t*)u8"b"}));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
