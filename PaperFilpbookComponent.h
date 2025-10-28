#pragma once
#include "SceneComponent.h"
#include "SDL3/SDL.h"

class UPaperFilpbookComponent : public USceneComponent
{
public:
	UPaperFilpbookComponent();
	virtual ~UPaperFilpbookComponent();

	virtual void Tick() override;

	virtual void Render() override;

	__forceinline char GetShape()
	{
		return Shape;
	}

	void SetShape(char Value)
	{
		Shape = Value;
	}

	__forceinline int GetZOrder() const
	{
		return ZOrder;
	}

	int ZOrder = 0;
	SDL_Color Color = { 255, 255, 255, 255 };

protected:
	char Shape = ' ';

};

