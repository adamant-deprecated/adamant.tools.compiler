#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main_(system__console__Console *_Nonnull const console_) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main_(system__console__Console *_Nonnull const console_) -> void
{
	i32 x_ = i32(1);
	for (;;)
	{
		if (cond(equal_op(x_.op__remainder(i32(3)), i32(0))))
		{
			if (cond(equal_op(x_.op__remainder(i32(5)), i32(0))))
			{
				console_->WriteLine_(string("FizzBuzz"));
			}
			else
			{
				console_->WriteLine_(string("Fizz"));
			}
		}
		else if (cond(equal_op(x_.op__remainder(i32(5)), i32(0))))
		{
			console_->WriteLine_(string("Buzz"));
		}
		else
		{
			console_->WriteLine_(x_);
		}

		x_.op__add_assign(i32(1));
		if (cond(i32__op__greater_than(x_, i32(100))))
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
		main_(new system__console__Console());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
