#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Reference_Type;
struct t_Value_Type;

// Function Declarations
t_Reference_Type *_Nonnull c_t_Reference_Type(t_Reference_Type *_Nonnull self);
inline t_Reference_Type *_Nonnull new_t_Reference_Type();
t_Value_Type c_t_Value_Type();
inline t_Value_Type new_t_Value_Type();
auto main_() -> void;

// Class Declarations

class t_Reference_Type
{
public:
};

struct t_Value_Type final
{
public:
	t_Value_Type * operator->() { return this; }
	t_Value_Type const * operator->() const { return this; }
	t_Value_Type & operator* () { return *this; }
	t_Value_Type const & operator* () const { return *this; }
};

// Global Definitions

// Definitions

t_Reference_Type *_Nonnull c_t_Reference_Type(t_Reference_Type *_Nonnull self) { return self; }

inline t_Reference_Type *_Nonnull new_t_Reference_Type()
{
	return c_t_Reference_Type(new t_Reference_Type());
}

t_Value_Type c_t_Value_Type() { return {}; }

inline t_Value_Type new_t_Value_Type()
{
	return c_t_Value_Type();
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
