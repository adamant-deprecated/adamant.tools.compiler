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
	console__->WriteLine__1(s__);
	console__->WriteLine__1(op__add(((string){20,(uint8_t const*)"First index of 't': "}), string_index_of__2(s__, ((code_point){/*t*/0x74}))));
	console__->WriteLine__1(op__add(((string){19,(uint8_t const*)"Last index of 't': "}), string_last_index_of__2(s__, ((code_point){/*t*/0x74}))));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__1(new system__console__Console__0());
	return 0;
}
