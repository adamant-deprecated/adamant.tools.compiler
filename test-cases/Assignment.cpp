#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_() -> int;

// Class Declarations

// Definitions

auto Main_() -> int
{
	int result_;
	result_ = 42;
	result_ += 1;
	result_ -= 1;
	return result_;
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	return Main_();
}
