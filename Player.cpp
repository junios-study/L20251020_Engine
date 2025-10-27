#include "Engine.h"
#include "Player.h"
#include "World.h"

#include <iostream>

APlayer::APlayer()
{
	ZOrder = 1003;
	bIsCollision = true;
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

	if (KeyCode == 'w')
	{
		Location.Y--;
	}
	if (KeyCode == 's')
	{
		Location.Y++;
	}
	if (KeyCode == 'a')
	{
		Location.X--;
	}
	if (KeyCode == 'd')
	{
		Location.X++;
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

