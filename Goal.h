#pragma once
#include "Actor.h"
class AGoal : public AActor
{
public:
	AGoal();
	virtual ~AGoal();

	class UPaperFilpbookComponent* Flipbook = nullptr;
};

