#include "runtime.h"

// Declarations
auto Main(::System::Console::Console *const console) -> void;

// Class Declarations

// Definitions
auto Main(::System::Console::Console *const console) -> void
{
	::System::Collections::List<::string> *const l = new ::System::Collections::List<::string>();
	l->Add(::string("Hello"));
	l->Add(::string("World!"));
	if (l->Length() != 2)
	{
		console->WriteLine(::string("List length not 2!"));
	}

	console->WriteLine(l->Get(0));
	for (::string const s : *(l))
	{
		console->Write(s);
	}

	console->WriteLine();
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main(new ::System::Console::Console());
	return 0;
}
