#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type__ID = 0,
};
typedef enum Type_ID Type_ID;

// Type Declarations

// Function Declarations
BOOL mut Func__1(BOOL const value__);
void mut main__0();

// Class Declarations

// Global Definitions

// Definitions

BOOL mut Func__1(BOOL const value__)
{
	return FALSE;
}

void mut main__0()
{
	Func__1(TRUE);
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
