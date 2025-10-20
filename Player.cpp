#include "Engine.h"
#include "Player.h"

#include <iostream>

APlayer::APlayer()
{
}

APlayer::~APlayer()
{
}


void APlayer::Tick()
{
	//많이 안 쓰지만 어쩔수 없이 해야 되는 전역 변수
	int KeyCode = GEngine->GetKeyCode();

}
