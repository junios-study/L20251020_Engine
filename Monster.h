#pragma once
#include "Actor.h"

class UCollisionComponent;
class UPaperFilpbookComponent;

class AMonster : public AActor
{
public:
	AMonster();
	virtual ~AMonster();

	virtual void Tick() override;

	float ExecuteTime  = 0.2f;
	float TotalTime = 0.f;

	UCollisionComponent* Collision;
	UPaperFilpbookComponent* Flipbook;
};

