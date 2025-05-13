#include <iostream>
using namespace std;

void NhapMang(int nArray[][], int &Line, int &Col)
{
	cout << "Nhap so dong: "; cin >> Line;
	cout << "Nhap so cot: "; cin >> Col;
	for (int i = 0; i < Line; i++)
		for (int j = 0; j < Col; j++)
		{
			cout << "Nhap A[" << i << ", " << j << "] = "; cin >> nArray[i][j];
		}
}

void XuatMang(int nArray[][], int Line, int Col)
{
	for (int i = 0; i < Line; i++)
	{
		for (int j = 0; j < Col; j++)
			cout << nArray[i][j] << "\t";
		cout << endl;
	}
}

void TimMaxMin(int nArray[][], int Line, int Col)
{
	int nMax = nArray[0][0], nMin = nArray[0][0];
	int nMaxPosX = 0, nMaxPosY = 0, nMinPosX = 0, nMinPosY = 0;
	for (int i = 0; i < Line; i++)
		for (int j = 0; j < Col; j++)
		{
			if (nArray[i][j] > nMax)
			{
				nMax = nArray[i][j];
				nMaxPosX = i; nMaxPosY = j;
			}
			if (nArray[i][j] < nMin)
			{
				nMin = nArray[i][j];
				nMinPosX = i; nMinPosY = j;
			}
		}
	cout << "Phan tu lon nhat: " << nMax << ". Vi tri [" << nMaxPosX << ", " << nMaxPosY << "]" << endl;
	cout << "Phan tu nho nhat: " << nMin << ". Vi tri [" << nMinPosX << ", " << nMinPosY << "]" << endl;
}

void SapXep(int nArray[][], int Line, int Col)
{

}

void TimMaxK(int nArray[][], int Line, int Col)
{
	
}