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

//���丮 ����(������ ���Լ��� ��)
AActor* UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);

	return NewActor;
}
