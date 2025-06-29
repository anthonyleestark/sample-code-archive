#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

void TimeOffset(SYSTEMTIME stTime, int nOffset)
{
	UINT nSeconds = (stTime.wHour * 3600) + (stTime.wMinute * 60) + (stTime.wSecond);
    nSeconds += nOffset;
    stTime.wHour = nSeconds / 3600;
    stTime.wMinute = (nSeconds % 3600) / 60;
    stTime.wSecond = (nSeconds % 3600) % 60;
    cout << "New time after calculate offset: " << stTime.wHour << ":" << stTime.wMinute << ":" << stTime.wSecond << endl;
}

void main()
{
    SYSTEMTIME stTime;
    stTime.wHour = 15; stTime.wMinute = 20; stTime.wSecond = 0;

    int nInput = 0;
    do {
        cout << "Enter offset: ";
        cin >> nInput;
        if (nInput == -9999)
            break;
        TimeOffset(stTime, nInput);
    } while (nInput != -9999);
}