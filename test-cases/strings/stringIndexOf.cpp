#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

// Global Definitions

// Definitions

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	string const s__ = ((string){19,(uint8_t const*)"A good test string!"});
	console_write_line__2(console__, s__);
	console_write_line__2(console__, string__0op__add(((string){20,(uint8_t const*)"First index of 't': "}), int_to_string__1(string_index_of__2(s__, ((code_point){/*t*/0x74})))));
	console_write_line__2(console__, string__0op__add(((string){19,(uint8_t const*)"Last index of 't': "}), int_to_string__1(string_last_index_of__2(s__, ((code_point){/*t*/0x74})))));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(new system__console__Console__0());
	return 0;
}
