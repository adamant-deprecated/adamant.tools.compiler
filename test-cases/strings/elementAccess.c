#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
void mut main__0();

// Class Declarations

// Global Definitions

// Definitions

void mut main__0()
{
	code_point mut result__;
	result__ = string__0__0op__element(((string){5,(uint8_t const*)"hello"}), ((int32){0}));
	result__ = string__0__0op__element(((string){7,(uint8_t const*)"goodbye"}), ((int32){4}));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
