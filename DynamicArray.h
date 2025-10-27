#pragma once

#include <string.h>
#include <stdio.h>

//compile 할때 코드 생성, 에러가 예측이 됨.
template<typename T>
class TDynamicArray
{
public:
	TDynamicArray()
	{
	}

	//deep copy
	//copy constructor(복사 생성자)
	TDynamicArray(const TDynamicArray<T>& RHS)
	{
		this->Size = RHS.Size;
		this->Capacity = RHS.Capacity;

		this->CurrentIndex = RHS.CurrentIndex;

		this->Data = new T[Capacity];
		memmove(this->Data, RHS.Data, Size * sizeof(int));
	}

	virtual ~TDynamicArray()
	{
		if (Data)
		{
			delete[] Data;
		}
	}

protected:
	T* Data = nullptr;

	size_t Size = 0;
	size_t Capacity = 0;

	int CurrentIndex = 0;

public:
	size_t GetSize()
	{
		return Size;
	}

	size_t GetCapacity()
	{
		return Capacity;
	}

	T& operator[](size_t _Index)
	{
		return Data[_Index];
	}

	void PushBack(T Value)
	{
		if (CurrentIndex < Capacity)
		{
			Data[CurrentIndex] = Value;
			CurrentIndex++;
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
			//for (size_t i = 0; i < Size; ++i)
			//{
			//	NewArray[i] = Data[i];
			//}

			//memcpy(NewArray, Data, Size * sizeof(T));
			memmove(NewArray, Data, Size * sizeof(int));

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
			Data[CurrentIndex] = Value;
			CurrentIndex++;
		}
	}
};