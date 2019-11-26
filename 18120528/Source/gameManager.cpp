#include "gameManager.h"
//KHOI TAO SAN CHOI TRUYEN` VAO` DO DAI VA` CHIEU RONG
gameManager::gameManager(int w, int h)//W: CHIEU` DAI`---H: CHIEU` RONG.
{
	srand(time(NULL));
	quit = false;//DIEU KIEN DE THOAT GAME
	right1 = 'x'; right2 = 'm';//THIET LAP CAC PHIM DIEU KHIEN
	left1 = 'z'; left2 = 'n';
	score1 = score2 = 0;//BIEN' LUU DIEM SO CUA 2 NGUOI CHOI 
	width = w; height = h;
	ball = new pBall(w / 2, h / 2);//CHO VI TRI QUA BONG O CHINH GIUA SAN CHOI
	player1 = new pPaddle(w / 2 - 2, h - 2);//GAN' VI TRI CUA 2 NGUOI` CHOI
	player2 = new pPaddle(w / 2 - 2, 1);
}
//HAM` HUY
gameManager::~gameManager()
{
	delete ball, player1, player2;
}
//HAM TANG DIEM SO'
void gameManager::ScoreUP(pPaddle* player)
{
	if (player == player1)
		score1++;
	else
		if (player == player2)
			score2++;
	//SAU KHI TANG DIEM THI SANG VAN' MOI' VI TRI CUA CAC PHAN` TU VE` MAC DINH.
	ball->reset();
	player1->reset();
	player2->reset();
}
//HAM` VE~
void gameManager::Draw()
{
	system("cls");//CLEAR MAN` HINH` CONSOLE
	for (int i = 0; i < width + 2; i++)//IN BIEN TREN
		cout << "\xB2";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//LAY TOA DO CAC PHAN TU
			int ballx = ball->getX();
			int bally = ball->getY();
			int player1x = player1->getX();
			int player2x = player2->getX();
			int player1y = player1->getY();
			int player2y = player2->getY();
			//VE CAC PHAN TU THEO VI TRI HIEN TAI CUA NO
			if (j == 0)
				cout << "\xB2";
			if (ballx == j && bally == i)
				cout << "O"; //ball
			else if (player1x == j && player1y == i)
				cout << "\xDB"; //player1
			else if (player2x == j && player2y == i)
				cout << "\xDB"; //player2

			else if (player1x + 1 == j && player1y == i)
				cout << "\xDB"; //player1
			else if (player1x + 2 == j && player1y == i)
				cout << "\xDB"; //player1
			else if (player1x + 3 == j && player1y == i)
				cout << "\xDB"; //player1
			///////////////////////////////////////////////
			else if (player2x + 1 == j && player2y == i)
				cout << "\xDB"; //player2
			else if (player2x + 2 == j && player2y == i)
				cout << "\xDB"; //player2
			else if (player2x + 3 == j && player2y == i)
				cout << "\xDB"; //player2

			else
				cout << " ";
			if (j == width- 1)
				cout << "\xB2";
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)//IN BIEN DUOI'
		cout << "\xB2";
	cout << endl;
	cout << "Score 1: " << score1 << endl << "Score 2: " << score2 << endl;//IN DIEM SO'
	cout << "<-: z(n) ->: x(m)___q De Thoat";
}
//HAM DIEU KHIEN TU BAN PHIM
void gameManager::Input()
{
	ball->move();
	int ballx = ball->getX();
	int bally = ball->getY();
	int player1x = player1->getX();
	int player2x = player2->getX();
	int player1y = player1->getY();
	int player2y = player2->getY();

	if (_kbhit())
	{
		char current = _getch();//NHAN GIA TRI TU BAN PHIM
		if (current == right1)
			if (player1x < width - 4)//DIEU KIEN DE CON TRUOT CHAY TRONG SAN CHOI
				player1->moveRIGHT();
		if (current == right2)
			if (player2x <width - 4)//DIEU KIEN DE CON TRUOT CHAY TRONG SAN CHOI
				player2->moveRIGHT();
		if (current == left1)//DIEU KIEN DE CON TRUOT CHAY TRONG SAN CHOI
			if (player1x  >0)
				player1->moveLEFT();
		if (current == left2)
			if (player2x >0)//DIEU KIEN DE CON TRUOT CHAY TRONG SAN CHOI
				player2->moveLEFT();

		if (ball->getDir() == STOP)//NEU QUA BONG DUNG YEN THI CHO NO DI CHUYEN THEO 1 HUONG NGAU NHIEN
			ball->RandomDir();

		if (current == 'q')//NEU NHAP q THI THOAT GAME
			quit = true;
	}
}
//HAM DI CHUYEN CUA QUA BONG
void gameManager::Logic()
{
	int ballx = ball->getX();
	int bally = ball->getY();
	int player1x = player1->getX();
	int player2x = player2->getX();
	int player1y = player1->getY();
	int player2y = player2->getY();
	//XET VI TRI CUA QUA BONG NEU O? RIA` SAN CHOI HOAC THANH TRUOT THI DI CHUYEN VOI HUONG' KHAC'
	//NEU VI TRI CUA QUA BONG O RIA` TREN VA` DUOI CUA SAN CHOI THI TANG DIEM CHO PLAYER
	//bottom paddle
	for (int i = 0; i <= 4; i++)
		if (bally == player1y - 1)
			if (ballx == player1x + i)
				ball->changeDir((Dir)(rand()%2+3));

	//top paddle
	for (int i = 0; i <= 4; i++)
		if (bally == player2y + 1)
			if (ballx == player2x + i)
				ball->changeDir((Dir)(rand() % 2 + 5));
	//right wall
	if (ballx == width)
		ball->changeDir(ball->getDir() == UPRIGHT ? UPLEFT : DOWNLEFT);

	//left wall
	if (ballx == 1)
		ball->changeDir(ball->getDir() == UPLEFT ? UPRIGHT : DOWNRIGHT);
	//bottom wall
	if (bally == height+1)
		ScoreUP(player2);
	//top wall
	if (bally == -1)
		ScoreUP(player1);
}
//HAM CHAY GAME
void gameManager::Run()
{
	while (!quit)//XET BIEN' DIEU KIEN DUNG` GAME
	{
		Draw();
		Input();
		Logic();
	}
}

