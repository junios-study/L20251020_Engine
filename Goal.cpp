#include "Goal.h"
#include "PaperFilpbookComponent.h"

AGoal::AGoal()
{
	Flipbook = new UPaperFilpbookComponent();
	Flipbook->SetShape('G');
	Flipbook->SetOwner(this);
	Flipbook->ZOrder = 1000;
	Flipbook->Color = SDL_Color{ 255, 255, 0, 0 };
	SetupAttachment(Flipbook);
}

AGoal::~AGoal()
{
}
