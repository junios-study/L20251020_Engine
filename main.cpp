#include "Engine.h"
#include <iostream>

#include <vector>
#include "DynamicArray.h"
#include "Vector.h"

class UTexture
{
public:

	char Textures[100000000];
};

int main(int argc, char* argv[])
{

	FVector2D Player(10, 10);
	FVector2D Goal(20, 20);
	FVector2D NewPosition = (Player + Goal);
	//FVector2D NewPosition = Player.operator+(Goal);


	
	TDynamicArray<UTexture> Textures;
//	Textures[0];

	TDynamicArray<int> D;

	std::cout << D.GetSize() << std::endl;

	D.PushBack(1);
	D.PushBack(3);
	D.PushBack(2);
	D.PushBack(5);
	D.PushBack(4);

	std::cout << D.GetSize() << std::endl;

	for (int i = 0; i < D.GetSize(); ++i)
	{
		std::cout << D[i] << std::endl;
	}

	return 0;
}
		
