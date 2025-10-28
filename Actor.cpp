#include "Actor.h"
#include <iostream>
#include <Windows.h>
#include "Engine.h"

AActor::AActor() :
	Shape(' '), Location(0, 0)
{
}

AActor::~AActor()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	COORD Posistion;
	Posistion.X = Location.X;
	Posistion.Y = Location.Y;

	SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Posistion);
	std::cout << Shape;

	SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r,
		Color.g, Color.b, Color.a);
	int SizeX = 30;
	int SizeY = 30;

	//SDL_RenderDrawPoint(GEngine->MyRenderer, (float)Location.X, (float)Location.Y);
	SDL_FRect DrawRect =
	{ 
		(float)(Location.X * SizeX),
		(float)(Location.Y * SizeY),
		(float)SizeX,
		(float)SizeY
	};
	SDL_RenderFillRect(GEngine->MyRenderer, &DrawRect);
}

bool AActor::CheckCollsion(const AActor* OtherActor)
{
	if (OtherActor->bIsOverlap)
	{
		return false;
	}

	if (this != OtherActor && OtherActor->bIsCollision && bIsCollision &&
		this->Location == OtherActor->Location) //영역 계산
	{
		return true;
	}

	return false;
}

void AActor::ActorBeginOverlap()
{
}

void AActor::Hit()
{
}
