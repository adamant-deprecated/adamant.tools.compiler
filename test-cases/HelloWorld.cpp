#include "runtime.cpp"

void Main(const ::System::Console::Console* console)
{
	console->WriteLine(string("Hello World!"));
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	Main(new ::System::Console::Console());
	return 0;
}
