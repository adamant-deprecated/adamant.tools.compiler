#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Reference_Type;
struct t_Value_Type;

// Function Declarations
inline t_Reference_Type *_Nonnull new_t_Reference_Type();
inline t_Value_Type new_t_Value_Type();
auto main_() -> void;

// Class Declarations

class t_Reference_Type
{
public:
	auto construct() -> t_Reference_Type *_Nonnull { return this; }
};

struct t_Value_Type final
{
public:
	t_Value_Type * operator->() { return this; }
	t_Value_Type const * operator->() const { return this; }
	t_Value_Type & operator* () { return *this; }
	t_Value_Type const & operator* () const { return *this; }
	static auto construct() -> t_Value_Type { return t_Value_Type(); }
};

// Global Definitions

// Definitions

inline t_Reference_Type *_Nonnull new_t_Reference_Type()
{
	return (new t_Reference_Type())->construct();
}

inline t_Value_Type new_t_Value_Type()
{
	return t_Value_Type::construct();
}

auto main_() -> void
{
	t_Reference_Type const *_Nonnull const r_ = new_t_Reference_Type();
	t_Value_Type const v_ = new_t_Value_Type();
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
