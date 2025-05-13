#include <iostream>
using namespace std;

int FindMiddle(int nArray[], int nID)
{
	int nSumMiddle = 0;
	if (nID % 2 != 0)
		nSumMiddle = nArray[int(nID / 2)];
	else
		nSumMiddle = nArray[int(nID / 2) - 1] + nArray[int(nID / 2)];
	return nSumMiddle;
}

int isSmooth(int nArray[], int nID)
{
	int nMiddle = FindMiddle(nArray, nID);
	if ((nArray[0] == nMiddle) && (nArray[nID - 1] == nMiddle))
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	cin >> n;
	int *nArray = new int[n];
	for (int i = 0; i < n; i++)
		cin >> nArray[i];
	int smooth = isSmooth(nArray, n);
	cout << smooth;
	return 0;
}