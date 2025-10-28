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

	//template<typename T>
	//UComponent* GetComponent<T>()
	//{
	//	dynamic_cast<T*>(Comepnot)
	//}



	virtual void ActorBeginOverlap();
	virtual void Hit();

	void SetupAttachment(UComponent* InComponent);

	std::vector<class UComponent*> Components;

protected:
	FVector2D Location;


	

public:


};

