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
////����� �����ؼ� ��� �߰� �ϵ��� �۾�
////Component base ���α׷�
//class ������ : public AMonster, APlayer
//{
//	void Tick();
//};
// 
//class �ĸ����� :public Plant, Animal //C++ ���� ���, X, interface
//{
//
//};

int SDL_main(int argc, char* argv[])
{
	//�ĸ����� A;

	//A.Eat();

	SDL_Time deltaSeconds = SDL_GetTicks64();

	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	deltaSeconds = SDL_GetTicks64() - deltaSeconds;
	return 0;
}
