#include "Engine.h"
#include "Player.h"
#include "World.h"
#include "SDL3/SDL.h"
#include "PaperFilpbookComponent.h"

#include <iostream>

APlayer::APlayer()
{
	bIsCollision = true;
	bIsOverlap = true;

	UPaperFilpbookComponent* Paper = new UPaperFilpbookComponent();
	Paper->SetShape('P');
	Paper->SetOwner(this);
	Paper->ZOrder = 1003;
	Paper->Color = SDL_Color{ 255, 0, 0, 255 };
	AddComponent(Paper);

}

APlayer::~APlayer()
{

}


void APlayer::Tick()
{
	//많이 안 쓰지만 어쩔수 없이 해야 되는 전역 변수
	int KeyCode = GEngine->GetKeyCode();
	FVector2D SaveLocation;
	SaveLocation = Location;

	if (KeyCode == SDLK_w || KeyCode == SDLK_UP)
	{
		Location.Y--;
	}
	if (KeyCode == SDLK_s || KeyCode == SDLK_DOWN)
	{
		Location.Y++;
	}
	if (KeyCode == SDLK_a || KeyCode == SDLK_LEFT)
	{
		Location.X--;
	}
	if (KeyCode == SDLK_d || KeyCode == SDLK_RIGHT)
	{
		Location.X++;
	}

	if (KeyCode == SDLK_ESCAPE)
	{
		exit(-1);
	}

	std::vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);

	bool bFlag = false;

	for (auto OtherActor : AllActors)
	{
		if (CheckCollsion(OtherActor))
		{
			bFlag = true;
			break;
		}
	}

	if (bFlag)
	{
		Location = SaveLocation;
	}
}

