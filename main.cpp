#include <iostream>
#include "Actor.h"
#include "Player.h"

#include <vector> //STL

using namespace std;



int main()
{
	//�ڷ� ����. �޸𸮿� �����ϱ� ���� ���, Strandart Template Library(STL) C++, boost::asio(IOCP, epoll)
	vector<AActor*> Actors;
	Actors.push_back(new AActor());
	Actors.push_back(new APlayer());

	//for (int i = 0; i < Actors.size(); ++i)
	for (auto Data : Actors)
	{
		Data->Tick(); // ���� �ٲ�, ���� ����. ������, Polymophism
	}
	 
	for (int i = 0; i < Actors.size(); ++i)
	{
		delete Actors[i];
	}
	Actors.clear();


	return 0;
}
