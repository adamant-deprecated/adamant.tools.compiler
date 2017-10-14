#include "RuntimeLibrary.h"

// Declarations
auto Func(::Maybe<::string> const x, ::Maybe<unsigned int> const y) -> ::Maybe<int>;
auto Main(::System::Console::Console *const console) -> void;

// Class Declarations

// Definitions
auto Func(::Maybe<::string> const x, ::Maybe<unsigned int> const y) -> ::Maybe<int>
{
	::Maybe<int> const z = ::None;
	::System::Text::StringBuilder const *const s = ::None;
	return ::None;
}

auto Main(::System::Console::Console *const console) -> void
{
	Func(::None, ::None);
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main(new ::System::Console::Console());
	return 0;
}
