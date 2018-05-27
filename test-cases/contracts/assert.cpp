#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__0();

// Class Declarations

// Global Definitions

// Definitions

void main__0()
{
	int32 const x__ = ((int32){5});
	int32 const y__ = ((int32){5});
	int32 const z__ = ((int32){6});
	assert__2(equal_op(x__, y__), op__add(op__add(op__add(((string){2,(uint8_t const*)"x="}), int_to_string__1(x__)), ((string){3,(uint8_t const*)" y="})), int_to_string__1(y__)));
	assert__2(equal_op(y__, z__), op__add(op__add(op__add(((string){2,(uint8_t const*)"y="}), int_to_string__1(y__)), ((string){3,(uint8_t const*)" z="})), int_to_string__1(z__)));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
