#include "pPaddle.h"
//HAM KHOI TAO MAC DINH THANH TRUOT 
pPaddle::pPaddle()
{
	x = y = 0;
}
//HAM KHOI TAO THANH TRUOT VOI TOA DO. TRUYEN` VAO`
pPaddle::pPaddle(int posX, int posY) :pPaddle()
{
	defaultX = posX;//LUU TAO DO MAC DINH
	defaultY = posY;
	x = posX;//THIET LAP TOA DO HIEN TAI
	y = posY;
}
//HAM XUAT TOA DO HIEN TAI CUA THANH TRUOT
ostream & operator<<(ostream & out, pPaddle c)
{
	out << "Paddle [" << c.x << "," << c.y << "]";
	return out;
}
//HAM RESET VI TRI CUA THANH TRUOT VE MAC DINH
void pPaddle::reset()
{
	x = defaultX; y = defaultY;
}