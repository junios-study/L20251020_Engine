#include "Engine.h"
#include "Player.h"
#include "World.h"
#include "SDL3/SDL.h"
#include "PaperFilpbookComponent.h"
#include "CollisionComponent.h"

#include <iostream>

APlayer::APlayer()
{
	Flipbook = new UPaperFilpbookComponent();
	Flipbook->SetShape('P');
	Flipbook->ZOrder = 1003;
	Flipbook->Color = SDL_Color{ 255, 0, 0, 255 };
	SetupAttachment(Flipbook);

	Collision = new UCollisionComponent();
	Collision->bIsCollision = true;
	Collision->bIsOverlap = true;
	SetupAttachment(Collision);

}

APlayer::~APlayer()
{

}


void APlayer::Tick()
{
	//���� �� ������ ��¿�� ���� �ؾ� �Ǵ� ���� ����
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
		for (auto Component : OtherActor->Components)
		{
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(Component);
			if (OtherCollision)
			{
				if (Collision->CheckCollsion(OtherCollision))
				{
					bFlag = true;
					break;
				}
			}
		}
	}

	if (bFlag)
	{
		Location = SaveLocation;
	}
}

