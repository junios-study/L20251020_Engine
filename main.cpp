#include "Engine.h"
#include <iostream>

int main(int argc, char* argv[])
{
	//GEngine->Init();
	//GEngine->Run();
	//GEngine->Term();

	//delete GEngine;

	int Numbers[10] = { 10, 2, 3, 4, 6, 5, 7, 8, 9, 1 };

	//O(n*n)
	//int Numbers[5] = { 5, 2, 3, 4, 1 }; // 25 => n & 2

	for (int j = 0; j < 10; ++j)
	{
		for (int i = 0; i < 10; ++i)
		{
			if (Numbers[j] < Numbers[i])
			{
				int Temp = Numbers[j];
				Numbers[j] = Numbers[i];
				Numbers[i] = Temp;
			}
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << Numbers[i] << std::endl;
	}

	


	return 0;
}
