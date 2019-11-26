#pragma once
#include"iostream"
#include"time.h"
#include"conio.h"
using namespace std;
enum Dir { STOP = 0, LEFT = 1, RIGHT = 2, UPLEFT = 3,  UPRIGHT = 4 ,DOWNLEFT = 5 , DOWNRIGHT = 6 };
class pBall
{
private:
	int x, y;//TOA DO HIEN TAI CUA QUA BONG'
	int defaultX, defaultY;//TOA DO. MAC. DINH. CUA QUA BONG'
	Dir direction;//HUONG' DI CHUYEN CUA QUA BONG'
public:
	pBall(int posX, int posY);
	void reset();
	void changeDir(Dir d);
	void RandomDir();
	void move();
	friend ostream & operator<<(ostream & out, pBall c);
	inline int getX() { return x; };
	inline int getY() { return y; };
	inline int getDir() { return direction; };
};
