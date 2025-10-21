#include "Engine.h"
#include <iostream>

class StaticClass
{
protected:
	StaticClass()
	{

	}

	static StaticClass* Instance;
public:

	static StaticClass* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new StaticClass();
		}

		return Instance;
	}
};

StaticClass* StaticClass::Instance = nullptr;



int main(int argc, char* argv[])
{
	StaticClass::GetInstance();


	return 0;
}
