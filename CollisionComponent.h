#pragma once
#include "SceneComponent.h"

class AActor;

class UCollisionComponent : public USceneComponent
{
public:
	UCollisionComponent();
	virtual ~UCollisionComponent();

	//virtual void SimulatePhysics();
	bool CheckCollsion(const UCollisionComponent* Other);

	bool bIsCollision = false;
	bool bIsOverlap = true;
};

