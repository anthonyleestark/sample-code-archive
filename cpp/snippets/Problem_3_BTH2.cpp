#include <iostream>
using namespace std;

//bool CheckDouble(int num1_1, int num1_2, int num2_1, int num2_2)
//{
//	if ((num1_1 == num2_2) && (num1_2 == num2_1))
//		return false;
//	else return true;
//}

int Distance(int nArray1[], int nArray2[], int nID)
{
	int nDistance = 0;
	int num1_1 = 0, num1_2 = 0, num2_1 = 0, num2_2 = 0;
	for (int i = 0; i < nID - 1; i++)
		for (int j = i + 1; j < nID; j++)
		{
			num1_1 = nArray1[i]; num1_2 = nArray1[j];
			for (int m = 0; m < nID - 1; m++)
				for (int n = m + 1; n < nID; n++)
				{
					num2_1 = nArray2[m]; num2_2 = nArray2[n];
					if ((num1_1 == num2_2) && (num1_2 == num2_1))
						nDistance++;
				}
		}
	return nDistance;
}

int main()
{
	int nID;
	cin >> nID;
	int *nArray1 = new int[nID];
	for (int i = 0; i < nID; i++)
		cin >> nArray1[i];
	int *nArray2 = new int[nID];
	for (int i = 0; i < nID; i++)
		cin >> nArray2[i];
	int nDistance = Distance(nArray1, nArray2, nID);
	cout << nDistance;
	return 0;
}