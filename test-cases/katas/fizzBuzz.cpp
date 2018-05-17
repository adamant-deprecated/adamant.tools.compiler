#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__1(system__console__Console *_Nonnull const console__) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main__1(system__console__Console *_Nonnull const console__) -> void
{
	i32 x__ = i32(1);
	for (;;)
	{
		if (cond(equal_op(x__.op__remainder(i32(3)), i32(0))))
		{
			if (cond(equal_op(x__.op__remainder(i32(5)), i32(0))))
			{
				console__->WriteLine__1(string("FizzBuzz"));
			}
			else
			{
				console__->WriteLine__1(string("Fizz"));
			}
		}
		else if (cond(equal_op(x__.op__remainder(i32(5)), i32(0))))
		{
			console__->WriteLine__1(string("Buzz"));
		}
		else
		{
			console__->WriteLine__1(x__);
		}

		x__.op__add_assign(i32(1));
		if (cond(i32__op__greater_than(x__, i32(100))))
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
		main__1(new system__console__Console());
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
