#include "Floor.h"
#include "PaperFilpbookComponent.h"

AFloor::AFloor()
{
	UPaperFilpbookComponent* Paper = new UPaperFilpbookComponent();
	Paper->SetShape(' ');
	Paper->SetOwner(this);
	Paper->ZOrder = 0;
	Paper->Color = SDL_Color{ 0, 0, 0, 0 };
	SetupAttachment(Paper);
}

AFloor::~AFloor()
{
}
