#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__1(system__console__Console *_Nonnull const console__) -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main__1(system__console__Console *_Nonnull const console__) -> void
{
	int__00 x__ = int__00(1);
	for (;;)
	{
		if (cond(equal_op(x__.op__remainder(int__00(3)), int__00(0))))
		{
			if (cond(equal_op(x__.op__remainder(int__00(5)), int__00(0))))
			{
				console__->WriteLine__1(string__00("FizzBuzz"));
			}
			else
			{
				console__->WriteLine__1(string__00("Fizz"));
			}
		}
		else if (cond(equal_op(x__.op__remainder(int__00(5)), int__00(0))))
		{
			console__->WriteLine__1(string__00("Buzz"));
		}
		else
		{
			console__->WriteLine__1(x__);
		}

		x__.op__add_assign(int__00(1));
		if (cond(int__00__0op__greater_than(x__, int__00(100))))
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
