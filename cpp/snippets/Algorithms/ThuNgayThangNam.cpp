#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int thu(int ngay, int thang, int nam)
{
	if (thang<3)
	{
		thang = thang + 12;
		nam = nam - 1;
	}
	return(abs(ngay + 2 * thang + 3 * (thang + 1) / 5 + nam + nam / 4) % 7);
}

int print(int thu)
{
	if (thu == 0)
		cout << "8";
	else
		cout << thu + 1;
	return 0;
}

bool isLeapYear(int nam)
{
	if ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0))
		return true;
	else return false;
}

int songay(int thang, int nam)
{
	int nDay;
	switch (thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		nDay = 31; break;
	case 4: case 6: case 9: case 11:
		nDay = 30; break;
	default:
		if (isLeapYear(nam))
			nDay = 29;
		else nDay = 28;
	}
	return nDay;
}

int checkdate(int ngay, int thang, int nam)
{
	if ((ngay < 1 && ngay > songay(thang, nam)) || (thang > 12 && thang < 1) || nam < 1900)
		return 0;
	else return 1;
}

int main()
{
	int ngay, thang, nam;
	do {
		cin >> ngay >> thang >> nam;
		if (checkdate(ngay, thang, nam) == 0)
			cout << "0";
		else
			print(thu(ngay, thang, nam));
	} while (1);
	return 0;
}