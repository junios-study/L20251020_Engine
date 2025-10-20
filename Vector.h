#pragma once

//Data ÀúÀå¿ë
struct FVector2D
{
public:
	FVector2D(int InX = 0, int inY = 0) :
		X(InX), Y(InX)
	{

	}

	virtual ~FVector2D()
	{

	}

	int X;
	int Y;
};