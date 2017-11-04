#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto True_() -> bool;
auto Main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto True_() -> bool
{
	return true;
}

auto Main_() -> void
{
	bool x_;
	x_ = true && false;
	x_ = true || false;
	x_ = !true;
	x_ = True_() || True_();
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main_();
	return 0;
}
