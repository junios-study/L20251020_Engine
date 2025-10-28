#include "Wall.h"
#include "PaperFilpbookComponent.h"

AWall::AWall()
{
	bIsCollision = true;
	bIsOverlap = false;

	UPaperFilpbookComponent* Paper = new UPaperFilpbookComponent();
	Paper->SetShape('*');
	Paper->SetOwner(this);
	Paper->ZOrder = 1000;
	Paper->Color = SDL_Color{ 128, 128, 128, 0 };
	AddComponent(Paper);
}

AWall::~AWall()
{
}
