#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_() -> void;

// Class Declarations

// Definitions

auto Main_() -> void
{
	char result_;
	result_ = string("hello")[0];
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main_();
	return 0;
}
