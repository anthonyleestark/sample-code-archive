#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int TimMax(int array[], int n)
{
	int max = array[0];
	for (int i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}
int main()
{
	int nSoTP, *pKhoangCach;
	cin >> nSoTP;
	// if (nSoTP <= 1 || nSoTP >= 1000000)
		// return 0;
	pKhoangCach = new int[nSoTP];
	for (int count = 0; count < nSoTP; count++)
		cin >> pKhoangCach[count];
	int nKhoangCachMin = TimMax(pKhoangCach, nSoTP);
	for (int i = 0; i < nSoTP; i++)
		for (int j = 0; j < nSoTP; j++)
			if ((pKhoangCach[i] != pKhoangCach[j]) && (abs(pKhoangCach[i] - pKhoangCach[j]) < nKhoangCachMin))
				nKhoangCachMin = abs(pKhoangCach[i] - pKhoangCach[j]);
	cout << nKhoangCachMin;
	return 0;
}