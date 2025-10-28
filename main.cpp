#include "Engine.h"
#include <SDL3/SDL_main.h>

//class Animal
//{
//public:
//	void Eat() {}
//};
//
//class Plant
//{
//public:
//	void Eat() {}
//};
//
////기능을 분해해서 기능 추가 하듯이 작업
////Component base 프로그램
//class 도깨비 : public AMonster, APlayer
//{
//	void Tick();
//};
// 
//class 파리지옥 :public Plant, Animal //C++ 다중 상속, X, interface
//{
//
//};

int SDL_main(int argc, char* argv[])
{
	//파리지옥 A;

	//A.Eat();

	SDL_Time deltaSeconds = SDL_GetTicks64();

	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	deltaSeconds = SDL_GetTicks64() - deltaSeconds;
	return 0;
}
