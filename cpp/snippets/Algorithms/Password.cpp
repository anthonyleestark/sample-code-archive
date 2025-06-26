#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include "windows.h"
using namespace std;

enum KEY_CODE { KEY_ENTER = 13, KEY_BACKSPACE = 8 };

void EnterPassword(string &password)
{
	int key;
	char character;
	
	cout << "Enter your password: ";
	
	while (true)
	{
		key = _getch();
		if ((key >= 48 && key <= 57) || (key >= 65 && key <= 90) || (key >= 97 && key <= 122))
		{
			character = (char)key;
			password.push_back(character);
			cout << "*";
		}
		else if (key == KEY_ENTER)
			break;
		else if (key == KEY_BACKSPACE)
		{
			int passlength = password.length();
			if (passlength > 0)
			{
				//system("cls");
				//cout << "Enter your password: ";
				//password.pop_back();
				//for (int i = 0; i < passlength - 1; i++)
				//	cout << "*";
				POINT curPos;
				GetCursorPos(&curPos);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (SHORT) curPos.x - 20 , (SHORT) curPos.y});
				cout << " ";
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (SHORT) curPos.x - 20 , (SHORT) curPos.y });
			}
		}
	}
}

void ShowPassword(string password)
{
	cout << "Your password is: " << password << endl;
}

void password_main()
{
	char sel;
	string password;
	SetConsoleTitle(L"Password Sample");
	EnterPassword(password);
	cout << endl << "Password was entered successfully!!!" << endl;
	cout << "Do you want to show the password entered: (Y/N) "; cin >> sel;
	if (sel == 'Y' || sel == 'y')
		ShowPassword(password);
	// system("pause");
}