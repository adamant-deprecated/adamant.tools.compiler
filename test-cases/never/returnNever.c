#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type__ID = 0,
};
typedef enum Type_ID Type_ID;

// Type Declarations

// Function Declarations
noreturn never mut test__0();
int32 mut main__0();

// Class Declarations

// Global Definitions

// Definitions

noreturn never mut test__0()
{
	assert__2(FALSE, ((string){{31},(uint8_t*)u8"prevent function from returning"}));
	UNREACHABLE__0();
}

int32 mut main__0()
{
	test__0();
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	return main__0().value;
}
