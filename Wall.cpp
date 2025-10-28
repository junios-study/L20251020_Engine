#include "Wall.h"
#include "PaperFilpbookComponent.h"
#include "CollisionComponent.h"

AWall::AWall()
{
	UPaperFilpbookComponent* Paper = new UPaperFilpbookComponent();
	Paper->SetShape('*');
	Paper->ZOrder = 1000;
	Paper->Color = SDL_Color{ 128, 128, 128, 0 };
	SetupAttachment(Paper);

	UCollisionComponent* Collision = new UCollisionComponent();
	Collision->bIsCollision = true;
	Collision->bIsOverlap = false;
	SetupAttachment(Collision);
}

AWall::~AWall()
{
}
