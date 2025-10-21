#include "Engine.h"
#include <iostream>

#include <vector>
#include "DynamicArray.h"

int main(int argc, char* argv[])
{
	TDynamicArray D;

	std::cout << D.Size << std::endl;

	D.PushBack(1);
	D.PushBack(3);
	D.PushBack(2);
	D.PushBack(5);
	D.PushBack(4);

	std::cout << D.Size << std::endl;

	for (int i = 0; i < D.Size; ++i)
	{
		std::cout << D.Data[i] << std::endl;
	}

	return 0;
}
		
