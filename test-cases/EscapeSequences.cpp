#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Main_() -> void
{
	p_string s_ = p_string("\"\\");
	p_code_point c_ = p_code_point('\'');
	c_ = p_code_point('\\');
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	Main_();
	return 0;
}
