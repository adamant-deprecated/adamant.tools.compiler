#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_(::System_::Console_::Console_ *const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto Main_(::System_::Console_::Console_ *const console_) -> void
{
	p_int x_ = p_int(1);
	for (;;)
	{
		if (x_->op_Mod(p_int(3))->op_Equal(p_int(0)).Value)
		{
			if (x_->op_Mod(p_int(5))->op_Equal(p_int(0)).Value)
			{
				console_->WriteLine_(p_string("FizzBuzz"));
			}
			else
			{
				console_->WriteLine_(p_string("Fizz"));
			}
		}
		else if (x_->op_Mod(p_int(5))->op_Equal(p_int(0)).Value)
		{
			console_->WriteLine_(p_string("Buzz"));
		}
		else
		{
			console_->WriteLine_(x_);
		}

		x_->op_PlusAssign(p_int(1));
		if (x_->op_GreaterThan(p_int(100)).Value)
		{
			break;
		}
	}
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	Main_(new ::System_::Console_::Console_());
	return 0;
}
