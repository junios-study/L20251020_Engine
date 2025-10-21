#include "Engine.h"
#include <iostream>
#include <algorithm>
#include <vector>

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

//void Print(int* Numbers, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		std::cout << Numbers[i] << std::endl;
//	}
//}
//
//void Print(float* Numbers, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		std::cout << Numbers[i] << std::endl;
//	}
//}
//
/////
////c언어 X
//void Print(void* Numbers, int _SizeOfElement,  int _NumberOfElement)
//{
//	//자료형 하나의 크기
//	//자료 갯수
//	for (int i = 0; i < _NumberOfElement; ++i)
//	{
//	}
//}

//meta programming
template<typename T>
void Print(T* Numbers, int Size)
{
	for (int i = 0; i < Size; ++i)
	{
		std::cout << Numbers[i] << std::endl;
	}
}

//void Print(float* Numbers, int Size)
//{
//	for (int i = 0; i < Size; ++i)
//	{
//		std::cout << Numbers[i] << std::endl;
//	}
//}

//void Print(int* Numbers, int Size)
//{
//	for (int i = 0; i < Size; ++i)
//	{
//		std::cout << Numbers[i] << std::endl;
//	}
//}

class IntClass
{
public:
	int Data;
};

//compile
//template<class T>
template<typename T>
class TemplateClass
{
public:
	T Data;
};


int main(int argc, char* argv[])
{
	float Numbers[10] = { 10.1f, 6.2f, 5, 2, 9, 7, 4, 3, 1, 8.1f };
	int IntNumbers[10] = { 10, 6, 5, 2, 9, 7, 4, 3, 1, 8 };
	bool BoolNumbers[10] = { true, false };
	std::string StringNumbers[10] = { "Hello", "World"};

	IntClass IC;
	IC.Data = 1;
	TemplateClass<float> FC;
	FC.Data = 2.0f;

	std::vector<int> IntArray;

	
	//Print<std::string>(BoolNumbers, 10);
	///Print<int>(IntNumbers, 10);


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
		