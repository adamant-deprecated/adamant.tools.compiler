#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type__ID = 0,
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
	string mut s__ = ((string){2,(uint8_t const*)"\"\\"});
	code_point mut c__ = ((code_point){/*\'*/0x27});
	c__ = ((code_point){/*\\*/0x5C});
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
