#include "runtime.h"

void Main(const ::System::Console::Console* console, const ::System::Console::Arguments* args)
{
	for (const string arg : *(args))
	{
		console->WriteLine(arg);
	}
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	Main(new ::System::Console::Console(), new ::System::Console::Arguments(argc, argv));
	return 0;
}
