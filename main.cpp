#include "Engine.h"
#include <iostream>

#include <vector>
#include "DynamicArray.h"
#include "Vector.h"


void Swap(int& A, int& B)
{
	int Temp = A;
	A = B;
	B = Temp;
}


int main(int argc, char* argv[])
{
	int A = 10;
	int B = 20;

	Swap(A, B);

	std::cout << A << std::endl;
	std::cout << B << std::endl;

}
		
