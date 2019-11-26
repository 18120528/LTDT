#include"pBall.h"
//KHOI TAO QUA BONG' VOI THAM SO TRUYEN VAO LA TOA DO CUA NO'
pBall::pBall(int posX, int posY)
{
	defaultX = posX;//LUU TOA DO MAC DINH
	defaultY = posY;
	x = posX;//THIET LAP TOA DO HIEN TAI
	y = posY;
	direction = STOP;//HUONG' DI CHUYEN MAC DINH
}
//RESET TOA DO QUA BONG VE MAC DINH
void pBall::reset()
{
	x = defaultX;
	y = defaultY;
	direction = STOP;
}
//THAY DOI HUONG' DI CHUYEN
void pBall::changeDir(Dir d)
{
	direction = d;
}
//GAN' 1 HUONG' DI CHUYEN NGAU NHIEN
void pBall::RandomDir()
{
	direction = (Dir)((rand() % 2) + 1);
}
//HAM DI CHUYEN QUA BONG'
void pBall::move()
{
	switch (direction)
	{
	case STOP:
		break;
	case LEFT:
		x--;
		break;
	case  RIGHT:
		x++;
		break;
	case UPLEFT:
		x--; y--;
		break;
	case DOWNLEFT:
		x--; y++;
		break;
	case UPRIGHT:
		x++; y--;
		break;
	case DOWNRIGHT:
		x++; y++;
		break;
	default: break;
	}
}
//HAM XUAT' TOA DO VA` HUONG' QUA BONG'
ostream & operator<<(ostream & out, pBall c)
{
	out << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
	return out;
}

