#include "Engine.h"
#include <iostream>

//container
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

#include <algorithm>


//class 설계
//자료구조(STL) 사용 잘하냐

int main(int argc, char* argv[])
{


	std::vector<int> V;
	V.push_back(1);
	V.push_back(2);
	V.push_back(3);

	std::sort(V.begin(), V.end());
	std::find(V.begin(), V.end(), 3);

	//[][][]
	//for (std::vector<int>::iterator i = V.begin() ; i != V.end(); ++i)
	for (auto i = V.begin(); i != V.end(); ++i)
	{
		std::cout << *i << ", ";
	}
	std::cout << std::endl;

	std::list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);

	L.sort();
	//std::find(L.begin(), L.end(), 3);

	//c++ 14 -> c++ 17
	//for (std::list<int>::iterator i = L.begin(); i != L.end(); ++i)
	for (auto Data : L)
	{
		std::cout << Data << ", ";
	}
	std::cout << std::endl;

}
		
 