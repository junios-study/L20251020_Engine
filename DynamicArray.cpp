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
		//배열을 사이즈를 늘린다.

	}
}
