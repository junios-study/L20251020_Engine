#include "CollisionComponent.h"
#include "Actor.h"

UCollisionComponent::UCollisionComponent()
{
}

UCollisionComponent::~UCollisionComponent()
{
}

bool UCollisionComponent::CheckCollsion(const UCollisionComponent* Other)
{
	if (Other->bIsOverlap)
	{
		return false;
	}

	if (this != Other && Other->bIsCollision && bIsCollision &&
		this->GetOwner()->GetActorLocation() == Other->GetOwner()->GetActorLocation()) //영역 계산
	{
		return true;
	}

	return false;
}
