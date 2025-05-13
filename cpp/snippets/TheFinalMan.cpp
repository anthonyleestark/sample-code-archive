#include <iostream>
using namespace std;

void BatDau(int a[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = 0;
}

void Choi(int a[], int n)
{
	int i = 0, number = n;
	while (number > 1)
	{
		if (a[i] != -1)
			a[i] = 1; // Bat dau dem tu 1
		if (i == n - 1)
			i = -1; // Quay ve truoc vi tri dau tien
		if (a[i] == 1 || i == -1)
		{
			a[i + 1] = -1; // Nguoi tiep theo se bi ra khoi vong
			number--; // So nguoi con lai giam dan
		}
		i += 2;
	}
}

void ConLai(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] != -1)
		{
			cout << i + 1 << endl;
			break;
		}
}

void thefinalman_main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	BatDau(a, n);
	Choi(a, n);
	ConLai(a, n);
	system("pause");
}