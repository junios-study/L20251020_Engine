#include "Engine.h"

int main(int argc, char* argv[])
{
	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	delete GEngine;

	return 0;
}
