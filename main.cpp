#include "Engine.h"

int main(int argc, char* argv[])
{
	FEngine* MyEngine = new FEngine();

	MyEngine->Init();
	MyEngine->Run();
	MyEngine->Term();

	delete MyEngine;
	MyEngine = nullptr;

	return 0;
}
