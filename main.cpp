#include <iostream>
#include "Actor.h"
#include "Player.h"

#include <vector> //STL

using namespace std;



int main()
{
	//자료 구조. 메모리에 저장하기 위한 방법, Strandart Template Library(STL) C++, boost::asio(IOCP, epoll)
	vector<AActor*> Actors;
	Actors.push_back(new AActor());
	Actors.push_back(new APlayer());

	//for (int i = 0; i < Actors.size(); ++i)
	for (auto Data : Actors)
	{
		Data->Tick(); // 형태 바뀜, 형태 많다. 다형성, Polymophism
	}
	 
	for (int i = 0; i < Actors.size(); ++i)
	{
		delete Actors[i];
	}
	Actors.clear();


	return 0;
}
