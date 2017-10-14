#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main(::System::Console::Console *const console) -> void;

// Class Declarations

// Definitions
auto Main(::System::Console::Console *const console) -> void
{
	::System::Collections::List<::string> *const strings = new ::System::Collections::List<::string>();
	strings->Add(::string("Hello"));
	strings->Add(::string("World!"));
	if (strings->Length() != 2)
	{
		console->WriteLine(::string("List length not 2!"));
	}

	console->WriteLine(strings->Get(0));
	for (::string const s : *(strings))
	{
		console->Write(s);
	}

	console->WriteLine();
	::System::Collections::List<::System::Text::StringBuilder *> *const builders = new ::System::Collections::List<::System::Text::StringBuilder *>();
	builders->Add(new ::System::Text::StringBuilder(::string("sb[0]: ")));
	builders->Add(new ::System::Text::StringBuilder(::string("sb[1]: ")));
	for (::System::Text::StringBuilder *const sb : *(builders))
	{
		sb->Append(::string("value"));
	}

	for (::System::Text::StringBuilder const *const sb : *(builders))
	{
		console->WriteLine(sb->ToString());
	}
}

// Entry Point Adapter
int main(int argc, char const *const * argv)
{
	Main(new ::System::Console::Console());
	return 0;
}
