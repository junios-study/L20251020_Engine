#include "Actor.h"
#include <iostream>
#include <Windows.h>
#include "Engine.h"

AActor::AActor() :
	Location(0, 0)
{
}

AActor::~AActor()
{
}

void AActor::Tick()
{
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

void AActor::AddComponent(UComponent* InComponent)
{
	Components.push_back(InComponent);
}
