#include <iostream>
#include <iomanip>
#include "stdio.h"
#include <string.h>
using namespace std;

#define ASCII_MAX 127;
#define ASCII_ADV 255;
#define UNICODE_MAX 65535;

char returnCode(int i)
{
	char character = NULL;
	switch (i)
	{
	case 0: cout << "NUL"; break;
	case 1: cout << "SOH"; break;
	case 2: cout << "STX"; break;
	case 3: cout << "ETX"; break;
	case 4: cout << "EOT"; break;
	case 5: cout << "ENQ"; break;
	case 6: cout << "ACK"; break;
	case 7: cout << "BEL"; break;
	case 8: cout << "BS"; break;
	case 9: cout << "HT"; break;
	case 10: cout << "LF"; break;
	case 11: cout << "VT"; break;
	case 12: cout << "FF"; break;
	case 13: cout << "CR"; break;
	case 14: cout << "SO"; break;
	case 15: cout << "SI"; break;
	case 16: cout << "DLE"; break;
	case 17: cout << "DC1"; break;
	case 18: cout << "DC2"; break;
	case 19: cout << "DC3"; break;
	case 20: cout << "DC4"; break;
	case 21: cout << "NAK"; break;
	case 22: cout << "SYN"; break;
	case 23: cout << "ETB"; break;
	case 24: cout << "CAN"; break;
	case 25: cout << "EM"; break;
	case 26: cout << "SUB"; break;
	case 27: cout << "ESC"; break;
	case 28: cout << "FS"; break;
	case 29: cout << "RS"; break;
	case 30: cout << "GS"; break;
	case 31: cout << "US"; break;
	case 127: cout << "DEL"; break;
	default: character = (char)i;
	}
	return character;
}

void convertToBinary(int n)
{
	if (n >= 2)
		convertToBinary(n / 2);
	cout << (n % 2)["01"];
}

void main()
{
	int sel, max_char = NULL;
	do {
		cout << "Select code table:\n\t1.ASCII\n\t2.Advanced ASCII\nEnter your selection: "; cin >> sel;
		switch (sel)
		{
		case 1: max_char = ASCII_MAX; break;
		case 2: max_char = ASCII_ADV; break;
		default: system("cls");
		}
	} while (max_char == NULL);
	cout << " Decimal\tBinary\t\tHexa\t\tCharacter" << endl;
	for (int i = 0; i <= max_char; i++)
	{
		cout << setw(5) << dec << i << "\t  ";
		cout << setw(8) << setfill('0');
		convertToBinary(i);
		cout << setfill(' ');
		cout << setw(13) << hex << i << "\t  ";
		cout<< returnCode(i) << endl;
	}
	system("pause");
}