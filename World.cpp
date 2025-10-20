#include "World.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

std::vector<AActor*> UWorld::GetAllActors() const
{
	return Actors;
}

//팩토리 패턴(생성도 이함수가 함)
AActor* UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);

	return NewActor;
}
