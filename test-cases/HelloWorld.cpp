#include "runtime.cpp"

void Main(::System::Console* console)
{
	console->WriteLine(string("Hello World!"));
}

// Entry Point Adapter
int main(int argc, const char * argv[])
{
	Main(new ::System::Console());
	return 0;
}
