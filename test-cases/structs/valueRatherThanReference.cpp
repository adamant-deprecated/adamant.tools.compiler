#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Reference_Type Reference_Type;
typedef struct Value_Type Value_Type;

// Function Declarations
Reference_Type *_Nonnull Reference_Type__new__0(Reference_Type *_Nonnull self);
inline Reference_Type *_Nonnull new_Reference_Type();
Value_Type Value_Type__new__0();
inline Value_Type new_Value_Type();
auto main__0() -> void;

// Class Declarations

struct Reference_Type
{
};

struct Value_Type
{
	Value_Type * operator->() { return this; }
	Value_Type const * operator->() const { return this; }
	Value_Type & operator* () { return *this; }
	Value_Type const & operator* () const { return *this; }
};

// Global Definitions

// Definitions

Reference_Type *_Nonnull Reference_Type__new__0(Reference_Type *_Nonnull self) { return self; }

inline Reference_Type *_Nonnull new_Reference_Type()
{
	return Reference_Type__new__0(new Reference_Type());
}

Value_Type Value_Type__new__0() { return {}; }

inline Value_Type new_Value_Type()
{
	return Value_Type__new__0();
}

auto main__0() -> void
{
	Reference_Type const *_Nonnull const r__ = new_Reference_Type();
	Value_Type const v__ = new_Value_Type();
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
