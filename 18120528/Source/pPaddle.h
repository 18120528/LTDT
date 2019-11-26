#pragma once
#include"iostream"
#include"time.h"
#include"conio.h"
using namespace std;
class pPaddle
{
private:
	int x, y;//TOA DO HIEN TAI CUA THANH TRUOT'
	int defaultX, defaultY;//TAO DO MAC DINH CUA THANH TRUOT
public:
	pPaddle();
	pPaddle(int posX, int posY);
	void reset();
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline void moveRIGHT() { x++; }
	inline void moveLEFT() { x--; }
	friend ostream & operator<<(ostream & out, pPaddle c);
};

