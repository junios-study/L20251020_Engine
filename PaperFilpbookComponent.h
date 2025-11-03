#pragma once
#include "SceneComponent.h"
#include "SDL3/SDL.h"

#include <string>

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

	void LoadBMP(std::string Filename);

	int ZOrder = 0;
	SDL_Color Color = { 255, 255, 255, 255 };
	SDL_Surface* BitmapImage = nullptr;
	SDL_Texture* Texture = nullptr;
	SDL_Color ColorKey = { 255, 0, 255, 255 };
	bool bAnimation = false;
	float SpiriteCountX = 5;
	float SpiriteCountY = 5;
	float XIndex = 0;
	float YIndex = 0;
	int SizeX = 60;
	int SizeY = 60;
	float AnimationUpdateTime = 0.2f;

protected:
	char Shape = ' ';
	float elpasedTime = 0.0f;

};

