#include <iostream>
#include "Header.h"
#include<math.h>
using namespace std;

int DTools::findNumberDayOfMonth(int m, int y)
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return 31;
	if (m == 4 || m == 6 || m == 9 || m == 11)
		return 30;
	if (m == 2)
	{
		if (isLeapYear(y)) return 29;
		return 28;

	}
}

int DTools::findNumberDayToDateInYear(int d, int m, int y)
{
	int temp = 0;

	// Tinh tong so ngay cac thang truoc do
	for (int i = 1; i < m; i++)
		temp += findNumberDayOfMonth(m, y);

	temp += d;

	return temp;
}


	


bool DTools::isLeapYear(int y)
{
	if (y % 4 != 0) return false;
	else if (y % 100 != 0) return true;
	else if (y % 400 != 0) return false;
	else return true;
}

bool DTools::isDateValid(int d, int m, int y)
{
	if (d < 1 || d > findNumberDayOfMonth(d, y))
		return false;
	if (m < 1 || m > 12)
		return false;
	return true;
	
}

void CDate::im()
{
	cout << "Type in day, month, year: ";
	cin >> day >> month >> year;
}

void CDate::ex()
{
	cout << day << "/" << month << "/" << year;
}



CDate CDate::tru(CDate a)
{
	
}

CDate CDate::tru(int DAY)
{
	day -= DAY;
	//ngay hop le ko lam gi ca.
	//lap lai den khi ngay hop le.

	//duyet ngay:
	int temp;
	while (day < 1)
	{
		if (month == 1)
		{
			year--;
			month = 12;
			day += T.findNumberDayOfMonth(month, year);
		}
		else
		{
			month--;
			day += T.findNumberDayOfMonth(month, year);
		};
		
	}
}

CDate CDate::cong(int DAY)
{
	day += DAY;
	//ngay hop le ko lam gi ca.
	//lap lai den khi ngay hop le.

	int temp;
	//duyet ngay:
	while (day > (temp = T.findNumberDayOfMonth(month, year)))
	{
		day -= temp;
		month++;
		if (month == 13)
		{
			year++;
			month = 1;
		}
	}
}

CDate CDate::truTru()
{
	CDate temp = *this;

	if (day == 1)
	{
		if (month == 1)
		{
			temp.year -= 1;
			temp.month = 12;
			temp.day = 31;
		}
		else
		{
			temp.month -= 1;
			temp.day = T.findNumberDayOfMonth(month, year);
		}
	}
	else
	{
		temp.day -= 1;
	}

	return temp;
}

CDate CDate::congCong()
{
	
	CDate temp = *this;

	if (day == T.findNumberDayOfMonth(month, year))
	{
		if (month == 12)
		{
			temp.year += 1;
			temp.month = 1;
			temp.day = 1;
		}
		else
		{
			temp.month += 1;
			temp.day = 1;
		}
	}
	else
	{
		temp.day += 1;
	}
	return temp;
}

