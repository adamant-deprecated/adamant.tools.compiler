#include "RuntimeLibrary.hpp"

// Type Declarations
class Reference_Type_;
struct Value_Type_;

// Function Declarations
auto Main_() -> void;

// Class Declarations

class Reference_Type_
{
public:
	auto construct() -> ::Reference_Type_* { return this; }
};

struct Value_Type_ final
{
public:
	Value_Type_ * operator->() { return this; }
	Value_Type_ const * operator->() const { return this; }
	Value_Type_ & operator* () { return *this; }
	Value_Type_ const & operator* () const { return *this; }
	static auto construct() -> ::Value_Type_ { return Value_Type_(); }
};

// Global Definitions

// Definitions

auto Main_() -> void
{
	::Reference_Type_ const *_Nonnull const r_ = (new ::Reference_Type_())->construct();
	::Value_Type_ const v_ = ::Value_Type_::construct();
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		Main_();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}
