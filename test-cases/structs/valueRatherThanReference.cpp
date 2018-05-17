#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Reference_Type__0 Reference_Type__0;
typedef struct Value_Type__0 Value_Type__0;

// Function Declarations
Reference_Type__0 *_Nonnull Reference_Type__0__0new__0(Reference_Type__0 *_Nonnull self);
inline Reference_Type__0 *_Nonnull new_Reference_Type__0();
Value_Type__0 Value_Type__0__0new__0();
inline Value_Type__0 new_Value_Type__0();
auto main__0() -> void;

// Class Declarations

struct Reference_Type__0
{
};

struct Value_Type__0
{
	Value_Type__0 * operator->() { return this; }
	Value_Type__0 const * operator->() const { return this; }
	Value_Type__0 & operator* () { return *this; }
	Value_Type__0 const & operator* () const { return *this; }
};

// Global Definitions

// Definitions

Reference_Type__0 *_Nonnull Reference_Type__0__0new__0(Reference_Type__0 *_Nonnull self) { return self; }

inline Reference_Type__0 *_Nonnull new_Reference_Type__0()
{
	return Reference_Type__0__0new__0(new Reference_Type__0());
}

Value_Type__0 Value_Type__0__0new__0() { return {}; }

inline Value_Type__0 new_Value_Type__0()
{
	return Value_Type__0__0new__0();
}

auto main__0() -> void
{
	Reference_Type__0 const *_Nonnull const r__ = new_Reference_Type__0();
	Value_Type__0 const v__ = new_Value_Type__0();
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__0();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
