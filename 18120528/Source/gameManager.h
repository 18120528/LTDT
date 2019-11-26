#pragma once
#include"iostream"
#include"time.h"
#include"conio.h"
using namespace std;
#include"pBall.h"
#include"pPaddle.h"
class gameManager
{
private:
	int width, height;//WIDTH: CHIEU` DAI`---HEIGHT: DO. CAO
	int score1, score2;//DIEM SO CUA 2 NGUOI` CHOI
	char right1, left1, right2, left2;//CAC BIEN LUU GIA TRI DE DIEU KHIEN TU BAN PHIM
	bool quit;//BIEN DIEU KIEN DE THOAT GAME
	pBall * ball;
	pPaddle * player1;
	pPaddle * player2;
public:
	gameManager(int w, int h);
	~gameManager();
	void ScoreUP(pPaddle* player);
	void Draw();
	void Input();
	void Logic();
	void Run();
};

