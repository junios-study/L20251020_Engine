#include "Engine.h"
#include <iostream>
#include <fstream>
#include <string>

#include "World.h"
#include "Wall.h"


FEngine::FEngine():
	World(nullptr)
{
}

FEngine::~FEngine()
{
}

void FEngine::Init()
{
	World = new UWorld();

	std::ifstream MapFile("level01.map");

	if (MapFile.is_open())
	{
		char Buffer[1024] = { 0, };
		int Y = 0;
		while (MapFile.getline(Buffer, 80))
		{
			std::string Line = Buffer;
			for (int X = 0; X < Line.size(); ++X)
			{
				if (Line[X] == '*')
				{
					AActor* NewActor = new AWall();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape('*');
					World->SpawnActor(NewActor);
				}
			}
			Y++;
		}
	}

	MapFile.close();
}

void FEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void FEngine::Term()
{
}

void FEngine::Input()
{
}

void FEngine::Tick()
{
}

void FEngine::Render()
{
}
