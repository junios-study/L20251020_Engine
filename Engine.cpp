#include "Engine.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <algorithm>

#include "World.h"
#include "Wall.h"
#include "Floor.h"
#include "Player.h"
#include "Goal.h"
#include "Monster.h"
#include "GameMode.h"


//FEngine* GEngine = nullptr;

FEngine* FEngine::Instance = nullptr;

FEngine::FEngine():
	World(nullptr)
{
}

FEngine::~FEngine()
{
}

void FEngine::Init()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	MyWindow = SDL_CreateWindow("Engine", 800, 600, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	OpenLevel();
}

void FEngine::OpenLevel()
{
	srand((unsigned int)time(nullptr));

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
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'P')
				{
					AActor* NewActor = new APlayer();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'M')
				{
					AActor* NewActor = new AMonster();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'G')
				{
					AActor* NewActor = new AGoal();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}

				{
					AActor* NewActor = new AFloor();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(' ');
					World->SpawnActor(NewActor);
				}
			}
			Y++;
		}

	}
	MapFile.close();

	World->SortActor();

	//UE Gameplay Framework
	World->SpawnActor(new AGameMode());
}

void FEngine::Run()
{
	while (bIsRunning)
	{
		SDL_PollEvent(&MyEvent);
		//Input();
		Tick();
		Render();
	}
}

void FEngine::Term()
{
	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();
}

void FEngine::Input()
{
	if (_kbhit())
	{
		KeyCode = _getch();
	}
}

void FEngine::Tick()
{
	GetWorld()->Tick();
}

void FEngine::Render()
{
//	system("cls");
	GetWorld()->Render();
}
