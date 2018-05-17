#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Test__0 Test__0;

// Function Declarations
Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self);
void main__1(system__console__Console__0 *_Nonnull const console__);

// Class Declarations

struct Test__0
{
	bool__00 value__;
	void change__1(bool__00 const value__);
};

// Global Definitions

// Definitions

void Test__0::change__1(bool__00 const value__)
{
	auto self = this;
	self->value__ = value__;
}

Test__0 *_Nonnull Test__0__0new__0(Test__0 *_Nonnull self) { return self; }

void main__1(system__console__Console__0 *_Nonnull const console__)
{
	Test__0 *_Nonnull const test__ = Test__0__0new__0(allocate(sizeof(Test__0)));
	test__->change__1(true__00);
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__1(new system__console__Console__0());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
