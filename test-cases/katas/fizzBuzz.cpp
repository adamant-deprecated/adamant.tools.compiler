#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main_(::System_::Console_::Console_ *_Nonnull const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main_(::System_::Console_::Console_ *_Nonnull const console_) -> void
{
	i32 x_ = i32(1);
	for (;;)
	{
		if (cond(equal_op(x_.op_remainder(i32(3)), i32(0))))
		{
			if (cond(equal_op(x_.op_remainder(i32(5)), i32(0))))
			{
				console_->WriteLine_(str("FizzBuzz"));
			}
			else
			{
				console_->WriteLine_(str("Fizz"));
			}
		}
		else if (cond(equal_op(x_.op_remainder(i32(5)), i32(0))))
		{
			console_->WriteLine_(str("Buzz"));
		}
		else
		{
			console_->WriteLine_(x_);
		}

		x_.op_add_assign(i32(1));
		if (cond(i32_greater_than(x_, i32(100))))
		{
			break;
		}
	}
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_(new ::System_::Console_::Console_());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
