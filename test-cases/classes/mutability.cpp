#include "RuntimeLibrary.hpp"

// Type Declarations
class t_Mutable_Object;
class t_immutable_object;

// Function Declarations
t_Mutable_Object *_Nonnull c_t_Mutable_Object(t_Mutable_Object *_Nonnull self);
inline t_Mutable_Object *_Nonnull new_t_Mutable_Object();
t_immutable_object *_Nonnull c_t_immutable_object(t_immutable_object *_Nonnull self);
inline t_immutable_object *_Nonnull new_t_immutable_object();
auto main_() -> void;

// Class Declarations

class t_Mutable_Object
{
public:
};

class t_immutable_object
{
public:
};

// Global Definitions

// Definitions

t_Mutable_Object *_Nonnull c_t_Mutable_Object(t_Mutable_Object *_Nonnull self) { return self; }

inline t_Mutable_Object *_Nonnull new_t_Mutable_Object()
{
	return c_t_Mutable_Object(new t_Mutable_Object());
}

t_immutable_object *_Nonnull c_t_immutable_object(t_immutable_object *_Nonnull self) { return self; }

inline t_immutable_object *_Nonnull new_t_immutable_object()
{
	return c_t_immutable_object(new t_immutable_object());
}

auto main_() -> void
{
	t_Mutable_Object const *_Nonnull const m_ = new_t_Mutable_Object();
	t_immutable_object const *_Nonnull const i_ = new_t_immutable_object();
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
