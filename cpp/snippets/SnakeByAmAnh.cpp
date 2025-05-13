#include <iostream>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#define XX 120
#define YY 30
using namespace std;
void SetColor(WORD color) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void gotoxy(int x, int y) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
struct XY {
	int x, y;
};
bool UP, DOWN, LEFT, RIGHT;
int x, y, mm, speed;
void key() {
	if (_kbhit()) {
		char n = _getch();
		if (n == 72) {
			if (DOWN == true)
				return;
			else {
				UP = true;
				LEFT = false;
				RIGHT = false;
			}
		}
		else
			if (n == 75) {
				if (RIGHT == true)
					return;
				else {
					UP = false;
					LEFT = true;
					DOWN = false;
				}
			}
			else
				if (n == 77) {
					if (LEFT == true)
						return;
					else {
						UP = false;
						RIGHT = true;
						DOWN = false;
					}
				}
				else
					if (n == 80) {
						if (UP == true)
							return;
						else {
							LEFT = false;
							RIGHT = false;
							DOWN = true;
						}
					}
					else {
						if (n == 45) {
							if (speed <= 500)
								speed += 10;
						}
						else
							if (n == 61)
								if (speed >= 11)
									speed -= 10;
					}
	}
}
bool eatfood(XY snike[], XY *food) {
	if (snike[0].x == food->x&&snike[0].y == food->y)
		return true;
	return false;
}
void draw(XY snike[], XY *food) {
	int n = rand() % 15 + 1;
	gotoxy(food->x, food->y); cout << '*';
	SetColor(n);
	if (eatfood(snike, food) == true)
		mm++;
	gotoxy(x, y);
	cout << '&';
	for (int i = mm - 2; i >= 0; i--) {
		snike[i + 1] = snike[i];
		gotoxy(snike[i].x, snike[i].y);
		cout << '&';
	}
	snike[0].x = x;
	snike[0].y = y;
}
void intel() {
	if (UP == true)
		--y;
	else
		if (DOWN == true)
			++y;
		else
			if (LEFT == true)
				--x;
			else
				if (RIGHT == true)
					++x;
}
void reset(XY snike[]) {
	for (int i = 0; i < mm; i++) {
		snike[i].x = x++;
		snike[i].y = y;
	}
}
bool die(XY snike[]) {
	if (snike[0].y == 0 || snike[0].y == YY ||
		snike[0].x == 0 || snike[0].x == XX)
		return true;
	for (int i = 8; i < mm; i++)
		if (snike[0].x == snike[i].x&&snike[0].y == snike[i].y)
			return true;
	return false;
}
void score(unsigned int scorerun) {
	gotoxy(XX - 15, 1);
	cout << "Score: " << scorerun;
}
void openfood(XY snike[], XY *food) {
one:
	bool test = false;
	int x = rand() % 118 + 1;
	int y = rand() % 28 + 1;
	for (int i = 0; i<mm; i++)
		if (x == snike[i].x&&y == snike[i].y) {
			test = true;
			break;
		}
	if (test == true)
		goto one;
	food->x = x;
	food->y = y;
}
int main() {
one:
	UP = false; DOWN = false; LEFT = true; RIGHT = false;
	mm = 3; speed = 50; x = XX / 2; y = YY / 2;
	XY snike[2500], *food;
	food = new XY;
	bool Ofood = false;
	unsigned int scorerun = 0;
	reset(snike);
	srand(time(NULL));
	while (1) {
		system("cls");
		score(scorerun);
		if (Ofood == false) {
			openfood(snike, food);
			Ofood = true;
		}
		key();
		if (eatfood(snike, food) == true) {
			scorerun += 5;
			Ofood = false;
		}
		intel();
		draw(snike, food);
		Sleep(speed);
		if (die(snike) == true)
			break;
	}
	system("cls");
	gotoxy(XX / 2, YY / 2 - 1);
	cout << "SCORE: " << scorerun;
	gotoxy(XX / 2, YY / 2);
	cout << "press 1 to continue...";
	int k; cin >> k;
	if (k == 1)
		goto one;
	system("cls");
	return 1;
}