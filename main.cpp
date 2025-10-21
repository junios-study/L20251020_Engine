#include "Engine.h"
#include <iostream>
#include <algorithm>

void A()
{
	std::cout << "A" << std::endl;
}

void B()
{
	std::cout << "B" << std::endl;
}

int Sum(int A, int B)
{
	return A + B;
}

int Minus(int A, int B)
{
	return A - B;
}

void Print(int A, int B, int (*FP)(int,  int))
{
	std::cout << FP(A, B) << std::endl;
}

void Sort(bool (*Compare)(int A, int B))
{
	int Numbers[10] = { 10, 6, 5, 2, 9, 7, 4, 3, 1, 8 };
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (Compare(Numbers[i], Numbers[j]))
			{
				int Temp = Numbers[i];
				Numbers[i] = Numbers[j];
				Numbers[j] = Temp;
			}
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << Numbers[i] << std::endl;
	}
}

bool Greater(int A, int B)
{
	return A > B;
}

bool Less(int A, int B)
{
	return A < B;
}

//Callback
void OnReceive(int (*Callback)())
{
	bool bEnd = false;
	while (!bEnd)
	{

	}

	Callback();
}

int main(int argc, char* argv[])
{
	Sort(Less);

	//Print(2, 3, Minus);

	//void (*FunctionPointer)();

	//if (false)
	//{
	//	FunctionPointer = A;
	//}
	//else
	//{
	//	FunctionPointer = B;
	//}

	////std::cout << A << std::endl;
	////std::cout << FunctionPointer << std::endl;

	//FunctionPointer();

	return 0;
}
		