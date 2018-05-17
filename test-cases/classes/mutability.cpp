#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Mutable_Object__0 Mutable_Object__0;
typedef struct immutable_object__0 immutable_object__0;

// Function Declarations
Mutable_Object__0 *_Nonnull Mutable_Object__0__0new__0(Mutable_Object__0 *_Nonnull self);
inline Mutable_Object__0 *_Nonnull new_Mutable_Object__0();
immutable_object__0 *_Nonnull immutable_object__0__0new__0(immutable_object__0 *_Nonnull self);
inline immutable_object__0 *_Nonnull new_immutable_object__0();
void main__0();

// Class Declarations

struct Mutable_Object__0
{
};

struct immutable_object__0
{
};

// Global Definitions

// Definitions

Mutable_Object__0 *_Nonnull Mutable_Object__0__0new__0(Mutable_Object__0 *_Nonnull self) { return self; }

inline Mutable_Object__0 *_Nonnull new_Mutable_Object__0()
{
	return Mutable_Object__0__0new__0(new Mutable_Object__0());
}

immutable_object__0 *_Nonnull immutable_object__0__0new__0(immutable_object__0 *_Nonnull self) { return self; }

inline immutable_object__0 *_Nonnull new_immutable_object__0()
{
	return immutable_object__0__0new__0(new immutable_object__0());
}

void main__0()
{
	Mutable_Object__0 const *_Nonnull const m__ = new_Mutable_Object__0();
	immutable_object__0 const *_Nonnull const i__ = new_immutable_object__0();
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
