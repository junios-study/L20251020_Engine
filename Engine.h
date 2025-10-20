#pragma once
class UWorld;

class FEngine
{
public:
	FEngine();
	virtual ~FEngine();

	virtual void Init();
	virtual void Run();
	virtual void Term();

	__forceinline UWorld* GetWorld() const
	{
		return World;
	}

protected:
	void Input();
	void Tick();
	void Render();

	class UWorld* World;

	bool bIsRunning = true;
};

