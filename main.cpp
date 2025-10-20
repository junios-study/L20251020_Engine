#include <iostream>
#include "Actor.h"
#include "Player.h"

using namespace std;


int main()
{
	AActor* AActors[2];
	AActors[0] = new AActor();
	AActors[1] = new APlayer();

	for (int i = 0; i < 2; ++i)
	{
		AActors[i]->Tick(); // 형태 바뀜, 형태 많다. 다형성, Polymophism
	}

	AActor* MyActor = new AActor();
	APlayer* MyPlayer = new APlayer();

	MyActor->Tick();
	MyPlayer->Tick();


	cout << 1 << endl;

	return 0;
}
