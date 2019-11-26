#include"pBall.h"
#include"pPaddle.h"
#include"gameManager.h"
int main()
{
	gameManager Game(24, 25);
	Game.Run();
	return 0;
}