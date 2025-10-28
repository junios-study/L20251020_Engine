#include "World.h"
#include "Actor.h"
#include "SceneComponent.h"
#include "PaperFilpbookComponent.h"
#include <algorithm>

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

void UWorld::GetAllActors(std::vector<AActor*>& OutActors) const
{
	OutActors = Actors;
}

//팩토리 패턴(생성도 이함수가 함)
AActor* UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);

	return NewActor;
}

void UWorld::Tick()
{
	//All Actors Process.
	for (auto Actor : Actors)
	{
		//runtime시에 결정됨. 문제는 이놈이 문제.
		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		for (auto Component : Actor->Components)
		{
			USceneComponent* Scene = dynamic_cast<USceneComponent*>(Component);
			if (Scene)
			{
				Scene->Render();
			}
		}
	}
}

bool CompareActor(const AActor* A, const AActor* B)
{
	UPaperFilpbookComponent* Scene1 = nullptr;
	for (auto Component : A->Components)
	{
		Scene1 = dynamic_cast<UPaperFilpbookComponent*>(Component);
		if (Scene1)
		{
			break;
		}
	}

	UPaperFilpbookComponent* Scene2 = nullptr;
	for (auto Component : B->Components)
	{
		Scene2 = dynamic_cast<UPaperFilpbookComponent*>(Component);
		if (Scene2)
		{
			break;
		}
	}

	if (!Scene1 || !Scene2)
	{
		return false;
	}

	return (Scene1->GetZOrder() < Scene2->GetZOrder());
}

//[][][][][]
void UWorld::SortActor()
{
	int Money = 0;
	//std::sort(Actors.begin(), Actors.end(), [] (const AActor * A, const AActor * B) {
	//	UPaperFilpbookComponent* Scene1 = nullptr;
	//	for (auto Component : A->Components)
	//	{
	//		Scene1 = dynamic_cast<UPaperFilpbookComponent*>(Component);
	//		if (Scene1)
	//		{
	//			break;
	//		}
	//	}

	//	UPaperFilpbookComponent* Scene2 = nullptr;
	//	for (auto Component : B->Components)
	//	{
	//		Scene2 = dynamic_cast<UPaperFilpbookComponent*>(Component);
	//		if (Scene2)
	//		{
	//			break;
	//		}
	//	}

	//	if (!Scene1 || !Scene2)
	//	{
	//		return false;
	//	}

	//	return (Scene1->GetZOrder() < Scene2->GetZOrder());
	//});

	//std::sort(Actors.begin(), Actors.end(), CompareActor);

	//return;
	for (int j = 0; j < Actors.size(); ++j)
	{
		//기준 액터에 UPaperFilpbookComponent 있는지 확인
		UPaperFilpbookComponent* Scene1 = nullptr;
		for (auto Component : Actors[j]->Components)
		{
			Scene1 = dynamic_cast<UPaperFilpbookComponent*>(Component);
			if (Scene1)
			{
				break;
			}
		}

		if (!Scene1)
		{
			continue;
		}

		for (int i = 0; i < Actors.size(); ++i)
		{
			//선택한 액터에 UPaperFilpbookComponent 있는지 확인
			UPaperFilpbookComponent* Scene2 = nullptr;
			for (auto Component : Actors[i]->Components)
			{
				Scene2 = dynamic_cast<UPaperFilpbookComponent*>(Component);
				if (Scene2)
				{
					break;
				}
			}

			if (!Scene2)
			{
				continue;
			}


			if (Scene1->GetZOrder() < Scene2->GetZOrder())
			{
				AActor* Temp = Actors[j];
				Actors[j] = Actors[i];
				Actors[i] = Temp;
			}
		}
	}
}

