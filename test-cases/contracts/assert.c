#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
void mut main__0();

// Class Declarations

// Global Definitions

// Definitions

void mut main__0()
{
	int32 const x__ = ((int32){5});
	int32 const y__ = ((int32){5});
	int32 const z__ = ((int32){6});
	assert__2(int32__0op__equal(x__, y__), string__0op__add(string__0op__add(string__0op__add(((string){2,(uint8_t const*)"x="}), int_to_string__1(x__)), ((string){3,(uint8_t const*)" y="})), int_to_string__1(y__)));
	assert__2(int32__0op__equal(y__, z__), string__0op__add(string__0op__add(string__0op__add(((string){2,(uint8_t const*)"y="}), int_to_string__1(y__)), ((string){3,(uint8_t const*)" z="})), int_to_string__1(z__)));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
