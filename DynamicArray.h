#pragma once

#include <string.h>
#include <stdio.h>

template<typename T>
class TDynamicArray
{
public:
	TDynamicArray()
	{
	}

	virtual ~TDynamicArray()
	{

	}

	T* Data = nullptr;

	int Size = 0;
	int Capacity = 0;

	int Index = 0;

	void PushBack(T Value)
	{
		if (Index < Capacity)
		{
			Data[Index] = Value;
			Index++;
			Size++;
		}
		else
		{
			//Time, Space
			//Data, Size = 5
			//[1][2][3][4][5]
			//NewArray, Size = 1000000001
			//[][][][][][]
			if (Capacity == 0)
			{
				Capacity = 1;
			}
			int* NewArray = new int[Capacity * 2];

			//memory copy
			for (int i = 0; i < Size; ++i)
			{
				NewArray[i] = Data[i];
			}
			//memcpy(Data, NewArray, Size * sizeof(int));
			memmove(Data, NewArray, Size * sizeof(int));

			//NewArray, Size = 6
			//[1][2][3][4][5][]

			if (Data)
			{
				delete[] Data;
			}
			Data = NewArray;
			Capacity = Capacity * 2;
			Size++;

			//[1][2][3][4][5][6]
			Data[Index] = Value;
			Index++;
		}
	}
};