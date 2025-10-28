#include "Monster.h"
#include "Engine.h"
#include "Actor.h"
#include "World.h"
#include <vector>
#include "PaperFilpbookComponent.h"
#include "Component.h"
#include "CollisionComponent.h"

AMonster::AMonster()
{
	Flipbook = new UPaperFilpbookComponent();
	Flipbook->SetShape('M');
	Flipbook->ZOrder = 1001;
	Flipbook->Color = SDL_Color{ 0, 0, 255, 0 };
	SetupAttachment(Flipbook);

	Collision = new UCollisionComponent();
	Collision->bIsCollision = true;
	Collision->bIsOverlap = true;
	SetupAttachment(Collision);
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	TotalTime += (float)GEngine->GetWorldDeltaSeconds();
	if (TotalTime <= ExecuteTime)
	{
		return;
	}

	TotalTime = 0.f;

	int KeyCode = rand() % 4;

	FVector2D SaveLocation;
	SaveLocation = Location;

	if (KeyCode == 0)
	{
		Location.Y--;
	}
	if (KeyCode == 1)
	{
		Location.Y++;
	}
	if (KeyCode == 2)
	{
		Location.X--;
	}
	if (KeyCode == 3)
	{
		Location.X++;
	}
	std::vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);

	bool bFlag = false;

	for (auto OtherActor : AllActors)
	{
		UCollisionComponent* OtherCollision = OtherActor->GetComponent<UCollisionComponent>();

		if (OtherCollision)
		{
			if (Collision->CheckCollsion(OtherCollision))
			{
				bFlag = true;
				break;
			}
		}
	}

	if (bFlag)
	{
		Location = SaveLocation;
	}
}
