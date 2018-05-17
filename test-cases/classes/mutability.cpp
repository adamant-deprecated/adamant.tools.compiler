#include "RuntimeLibrary.hpp"

// Type Declarations
typedef struct Mutable_Object Mutable_Object;
typedef struct immutable_object immutable_object;

// Function Declarations
Mutable_Object *_Nonnull Mutable_Object__new__0(Mutable_Object *_Nonnull self);
inline Mutable_Object *_Nonnull new_Mutable_Object();
immutable_object *_Nonnull immutable_object__new__0(immutable_object *_Nonnull self);
inline immutable_object *_Nonnull new_immutable_object();
auto main_() -> void;

// Class Declarations

struct Mutable_Object
{
};

struct immutable_object
{
};

// Global Definitions

// Definitions

Mutable_Object *_Nonnull Mutable_Object__new__0(Mutable_Object *_Nonnull self) { return self; }

inline Mutable_Object *_Nonnull new_Mutable_Object()
{
	return Mutable_Object__new__0(new Mutable_Object());
}

immutable_object *_Nonnull immutable_object__new__0(immutable_object *_Nonnull self) { return self; }

inline immutable_object *_Nonnull new_immutable_object()
{
	return immutable_object__new__0(new immutable_object());
}

auto main_() -> void
{
	Mutable_Object const *_Nonnull const m_ = new_Mutable_Object();
	immutable_object const *_Nonnull const i_ = new_immutable_object();
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
