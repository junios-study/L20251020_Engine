#include "PaperFilpbookComponent.h"
#include "Vector.h"
#include <Windows.h>
#include "Actor.h"
#include <iostream>
#include "Engine.h"


UPaperFilpbookComponent::UPaperFilpbookComponent()
{
}

UPaperFilpbookComponent::~UPaperFilpbookComponent()
{
}

void UPaperFilpbookComponent::Tick()
{
}

void UPaperFilpbookComponent::Render()
{
	//COORD Posistion;
	//Posistion.X = GetOwner()->GetActorLocation().X;
	//Posistion.Y = GetOwner()->GetActorLocation().Y;

	//SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Posistion);
	//std::cout << Shape;

	SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r,
		Color.g, Color.b, Color.a);
	int SizeX = 30;
	int SizeY = 30;

	//SDL_RenderDrawPoint(GEngine->MyRenderer, (float)Location.X, (float)Location.Y);
	SDL_FRect DrawRect =
	{
		(float)(GetOwner()->GetActorLocation().X * SizeX),
		(float)(GetOwner()->GetActorLocation().Y * SizeY),
		(float)SizeX,
		(float)SizeY
	};
	SDL_RenderFillRect(GEngine->MyRenderer, &DrawRect);
}
