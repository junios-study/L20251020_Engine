#include "DynamicArray.h"

TDynamicArray::TDynamicArray()
{
}

TDynamicArray::~TDynamicArray()
{
}

void TDynamicArray::PushBack(int Value)
{
	if (Index < Size)
	{
		Data[Index] = Value;
		Index++;
	}
	else
	{
		//Data, Size = 5
		//[1][2][3][4][5]
		//NewArray, Size = 6
		//[][][][][][]

		int* NewArray = new int[Size + 1];

		for (int i = 0; i < Size; ++i)
		{
			NewArray[i] = Data[i];
		}
		//NewArray, Size = 6
		//[1][2][3][4][5][]

		delete[] Data;
		Data = NewArray;
		Size++;

		//[1][2][3][4][5][6]
		Data[Index] = Value;
		Index++;
	}
}
