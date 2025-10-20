#include "Engine.h"

#include <iostream>

class Singleton
{
protected:
	Singleton()
	{
	}

public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new Singleton();
		}
		return Instance;
	}

protected:
	static Singleton* Instance;
};

Singleton* Singleton::Instance = nullptr;


int main(int argc, char* argv[])
{
	Singleton::GetInstance();
	Singleton S2;



//	std::cout << Singleton::Gold << std::endl;


	//FEngine* MyEngine = new FEngine();
	//FEngine* MyEngine2 = new FEngine();
	//FEngine* MyEngine3 = new FEngine();

	//GEngine = MyEngine;

	//GEngine = nullptr;
	//MyEngine->Init();
	//MyEngine->Run();
	//MyEngine->Term();

	//delete MyEngine;
	//MyEngine = nullptr;

	return 0;
}
