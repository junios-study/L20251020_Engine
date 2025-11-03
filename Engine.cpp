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
#include "Timer.h"
#include "Input.h"
#include "PaperFilpbookComponent.h"


//FEngine* GEngine = nullptr;

FEngine* FEngine::Instance = nullptr;

FEngine::FEngine():
	World(nullptr), MyEvent(SDL_Event())
{
	MyRenderer = nullptr;
	MyWindow = nullptr;
	Timer = new UTimer();
	InputDevice = new UInput();
}

FEngine::~FEngine()
{
	if (World)
	{
		delete World;
	}

	if (Timer)
	{
		delete Timer;
	}

	if (InputDevice)
	{
		delete InputDevice;
	}
}

void FEngine::Init()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	MyWindow = SDL_CreateWindow("Engine", 800, 600, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	OpenLevel("level02.map");
}

void FEngine::OpenLevel(std::string LevelName)
{
	srand((unsigned int)time(nullptr));

	World = new UWorld();

	std::ifstream MapFile(LevelName.c_str());
	int MaxX = 0;
	int MaxY = 0;

	if (MapFile.is_open())
	{
		char Buffer[1024] = { 0, };
		int Y = 0;
		while (MapFile.getline(Buffer, 80))
		{
			std::string Line = Buffer;
			if (MaxX <= (int)Line.size())
			{
				MaxX = (int)Line.size();
			}

			for (int X = 0; X < Line.size(); ++X)
			{
				if (Line[X] == '*')
				{
					AActor* NewActor = new AWall();
					NewActor->SetActorLocation(FVector2D(X, Y));
					//NewActor->SetShape(Line[X]);
					NewActor->GetComponent<UPaperFilpbookComponent>()->LoadBMP("./Data/Wall.bmp");
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'P')
				{
					AActor* NewActor = new APlayer();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->GetComponent<UPaperFilpbookComponent>()->LoadBMP("./Data/Player.bmp");
					NewActor->GetComponent<UPaperFilpbookComponent>()->bAnimation = true;
					//NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'M')
				{
					AActor* NewActor = new AMonster();
					NewActor->SetActorLocation(FVector2D(X, Y));
					//unity Style
					UPaperFilpbookComponent* Flipbook = NewActor->GetComponent<UPaperFilpbookComponent>();
					Flipbook->ColorKey = { 255, 255, 255, 255 };
					Flipbook->LoadBMP("./Data/Slime.bmp");
					//NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'G')
				{
					AActor* NewActor = new AGoal();
					NewActor->SetActorLocation(FVector2D(X, Y));
					//NewActor->SetShape(Line[X]);
					AGoal* DownActor = dynamic_cast<AGoal*>(NewActor);
					//UnrealStyle
					if (DownActor)
					{
						DownActor->Flipbook->ColorKey = { 255, 255, 255, 255 };
						DownActor->Flipbook->LoadBMP("./Data/Goal.bmp");
					}

					World->SpawnActor(NewActor);
				}

				{
					AActor* NewActor = new AFloor();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->GetComponent<UPaperFilpbookComponent>()->LoadBMP("./Data/Floor.bmp");
					//NewActor->SetShape(' ');
					World->SpawnActor(NewActor);
				}
			}
			Y++;

			if (MaxY <= Y)
			{
				MaxY = Y;
			}
		}

	}
	MapFile.close();

	World->SortActor();

	//UE Gameplay Framework
	World->SpawnActor(new AGameMode());

	SDL_SetWindowSize(MyWindow, MaxX * 60, MaxY * 60);

}

void FEngine::Run()
{
	while (bIsRunning)
	{
		Timer->Tick();

		if (SDL_PollEvent(&MyEvent))
		{
			switch (MyEvent.type)
			{
			case SDL_QUIT:
				bIsRunning = false;
				break;
			}
		}

		Input();
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
	InputDevice->Tick();
	//if (_kbhit())
	//{
	//	KeyCode = _getch();
	//}
}

void FEngine::Tick()
{
	GetWorld()->Tick();
}

void FEngine::Render()
{
	SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
	SDL_RenderClear(MyRenderer);

	GetWorld()->Render();

	SDL_RenderPresent(MyRenderer);
}


double FEngine::GetWorldDeltaSeconds() const
{
	return Timer->DeltaSeconds;
}
