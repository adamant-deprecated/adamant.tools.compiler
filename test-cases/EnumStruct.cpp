#include "runtime.h"

// Declarations
enum class day_of_week;
auto Main() -> void;

// Class Declarations
enum class day_of_week
{
	Sunday = 0,
	Monday = 1,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
};

// Definitions
auto Main() -> void
{
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main();
	return 0;
}
