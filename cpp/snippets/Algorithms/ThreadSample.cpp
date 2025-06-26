#include <iostream>
#include <math.h>
#include "afxwin.h"
#include "windows.h"
using namespace std;

#ifndef _AFXDLL
#define _AFXDLL
#endif // !_AFXDLL

int done = 0;

UINT TinhToan(LPVOID lpParam)
{
	long long result = 0;
	bool isPrime; long long i = 0; long n = 0;
	long number = *(long*)lpParam;
	while (n < number)
	{
		isPrime = TRUE;
		for (long j = 2; j < sqrt(i); j++)
			if (i % j == 0)
				isPrime = FALSE;
		if (isPrime == TRUE)
			n++;
		i++;
	}
	result = i;
	cout << "So nguyen to thu " << number << " la: " << result << endl;
	done++;
	return 0;
}

void thread_main()
{
	long n[9];
	for (int i = 0; i < 8; i++)
	{
		cout << "Nhap vao so can tinh: ";
		cin >> n[i];
	}
	cout << endl << "Dang tinh toan... Ham nao xong truoc se in ket qua truoc..." << endl << endl;
	for (int i = 0; i < 8; i++)
		AfxBeginThread(TinhToan, (LPVOID)&n[i]);
	while (done < 8);
}