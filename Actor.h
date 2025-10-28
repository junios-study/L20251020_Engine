#pragma once

#include "Vector.h"
#include <vector>

class UComponent;

class AActor
{
public:
	AActor();
	virtual ~AActor();

	//virtual function table ->vftbl
	//override
	virtual void Tick(); //�̰� �ڽ��� ������ �Ҽ��� �ִ�.

	__forceinline FVector2D GetActorLocation() const
	{
		return Location;
	}

	void SetActorLocation(FVector2D Value)
	{
		//Location = Value;
		Location.X = Value.X;
		Location.Y = Value.Y;
	}

	//virtual void SimulatePhysics();
	bool CheckCollsion(const AActor* Other);


	virtual void ActorBeginOverlap();
	virtual void Hit();

	void AddComponent(UComponent* InComponent);

protected:
	FVector2D Location;


	std::vector<class UComponent*> Components;

public:
	bool bIsCollision = false; 
	bool bIsOverlap = true;

};

