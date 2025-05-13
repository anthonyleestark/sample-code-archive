#include <iostream>
using namespace std;

int FindMin(int nArray[], int nID)
{
	int min = nArray[0];
	for (int i = 0; i < nID; i++)
		if (nArray[i] < min)
			min = nArray[i];
	return min;
}

int CountNumber(int nArray[], int nID, int number)
{
	int count = 0;
	for (int i = 0; i < nID; i++)
		if (nArray[i] == number)
			count++;
	return count;
}

int main()
{
	int n, nNumberMin, count;
	cin >> n;
	int *nArray = new int[n];
	for (int i = 0; i < n; i++)
		cin >> nArray[i];
	nNumberMin = FindMin(nArray, n);
	count = CountNumber(nArray, n, nNumberMin);
	cout << nNumberMin << " " << count;
	return 0;
}