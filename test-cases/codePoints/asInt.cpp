#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	code_point c__ = ((code_point){/*a*/0x61});
	console__->WriteLine__1(op__add(op__add(op__add(((string){1,(uint8_t const*)"'"}), code_point_to_string__1(c__)), ((string){3,(uint8_t const*)"': "})), int_to_string__1(code_point_as_int__1(c__))));
	c__ = ((code_point){/*z*/0x7A});
	console__->WriteLine__1(op__add(op__add(op__add(((string){1,(uint8_t const*)"'"}), code_point_to_string__1(c__)), ((string){3,(uint8_t const*)"': "})), int_to_string__1(code_point_as_int__1(c__))));
	c__ = ((code_point){/*\\*/0x5C});
	console__->WriteLine__1(op__add(op__add(op__add(((string){1,(uint8_t const*)"'"}), code_point_to_string__1(c__)), ((string){3,(uint8_t const*)"': "})), int_to_string__1(code_point_as_int__1(c__))));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(new system__console__Console__0());
	return 0;
}
