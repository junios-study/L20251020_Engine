#include "Wall.h"
#include "PaperFilpbookComponent.h"
#include "CollisionComponent.h"

AWall::AWall()
{
	UPaperFilpbookComponent* Paper = new UPaperFilpbookComponent();
	Paper->SetShape('*');
	Paper->SetOwner(this);
	Paper->ZOrder = 1000;
	Paper->Color = SDL_Color{ 128, 128, 128, 0 };
	AddComponent(Paper);

	UCollisionComponent* Collision = new UCollisionComponent();
	Collision->SetOwner(this);
	Collision->bIsCollision = true;
	Collision->bIsOverlap = false;
	AddComponent(Collision);
}

AWall::~AWall()
{
}
