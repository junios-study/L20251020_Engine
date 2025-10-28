#pragma once

#include "Actor.h"

class UCollisionComponent;
class UPaperFilpbookComponent;

class APlayer : public AActor
{
public:
	APlayer();
	virtual ~APlayer();

	virtual void Tick() override; //�̰� �θ����� �ִ°ǵ� ������ ��, �� �ڽĵ� ������ ����

	UCollisionComponent* Collision;
	UPaperFilpbookComponent* Flipbook;
};

