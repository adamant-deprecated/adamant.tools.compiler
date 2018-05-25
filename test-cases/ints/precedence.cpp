#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
void main__0();

// Class Declarations

// Global Definitions

// Definitions

void main__0()
{
	int32 x__;
	x__ = (int32){1}.op__add((int32){3}.op__sub((int32){1})->op__div((int32){2}));
	x__ = (int32){1}.op__add((int32){3}).op__sub((int32){1}.op__div((int32){2}));
}

// Entry Point Adapter
int32_t main(int argc, char const *const * argv)
{
	main__0();
	return 0;
}
