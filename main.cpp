#include "Engine.h"
#include <SDL3/SDL_main.h>

int SDL_main(int argc, char* argv[])
{
	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	return 0;
}
