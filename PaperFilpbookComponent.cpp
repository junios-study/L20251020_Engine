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
	if (BitmapImage)
	{
		SDL_DestroySurface(BitmapImage);
		BitmapImage = nullptr;
	}

	if (Texture)
	{
		SDL_DestroyTexture(Texture);
		Texture = nullptr;
	}
}

void UPaperFilpbookComponent::Tick()
{
	if (bAnimation)
	{
		elpasedTime += (float)GEngine->GetWorldDeltaSeconds();
		if (elpasedTime >= AnimationUpdateTime)
		{
			XIndex++;
			XIndex = (float)((int)XIndex % (int)SpiriteCountX);
			elpasedTime = 0;
		}
	}
}

void UPaperFilpbookComponent::Render()
{
	//COORD Posistion;
	//Posistion.X = GetOwner()->GetActorLocation().X;
	//Posistion.Y = GetOwner()->GetActorLocation().Y;

	//SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Posistion);
	//std::cout << Shape;

	if (!BitmapImage && !Texture)
	{
		SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r,
			Color.g, Color.b, Color.a);


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
	else
	{
		SDL_FRect SourceRect;
		if (bAnimation)
		{
			float SpirteSizeX = (float)BitmapImage->w / SpiriteCountX;
			float SpirteSizeY = (float)BitmapImage->h / SpiriteCountY;
			SourceRect = { 
				XIndex * SpirteSizeX,
				YIndex * SpirteSizeY,
				SpirteSizeX,
				SpirteSizeY
			};
		}
		else
		{
			SourceRect = { 0, 0, (float)BitmapImage->w, (float)BitmapImage->h };
		}

		SDL_FRect DestinationRect = {
			(float)(GetOwner()->GetActorLocation().X * SizeX),
			(float)(GetOwner()->GetActorLocation().Y * SizeY),
			(float)SizeX,
			(float)SizeY
		};
		SDL_RenderCopy(GEngine->MyRenderer, Texture, &SourceRect, &DestinationRect);
	}
}

void UPaperFilpbookComponent::LoadBMP(std::string Filename)
{
	BitmapImage = SDL_LoadBMP(Filename.c_str());

	
	SDL_SetColorKey(BitmapImage, true, SDL_MapRGBA(SDL_GetPixelFormatDetails(BitmapImage->format),
		nullptr,
		ColorKey.r,
		ColorKey.g,
		ColorKey.b,
		ColorKey.a)
	);

	Texture = SDL_CreateTextureFromSurface(GEngine->MyRenderer, BitmapImage);
}
