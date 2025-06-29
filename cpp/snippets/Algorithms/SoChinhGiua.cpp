#include <iostream>
#include <cmath>
using namespace std;

int sochuso(int n)
{
	int dem = 0;
	while (n > 0)
	{
		n = n / 10;
		dem++;
	}
	return dem;
}

int vitri(int n, int i)
{
	int result = (n / (int) pow(10, (double)sochuso(n) - i)) % 10;
	return result;
}

int sochinhgiua(int n)
{
	int cg;
	int dem = sochuso(n);
	if (dem % 2 != 0)
		cg = vitri(n, (dem / 2) + 1);
	else
		cg = vitri(n, (dem / 2)) * 10 + vitri(n, (dem / 2) + 1);
	return cg;
}

int main()
{
	int n, a, max = 0, cgmax = 0;
	cin >> n;
	if (n < 10000)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a;
			if (sochinhgiua(a) >= cgmax)
			{
				cgmax = sochinhgiua(a);
				max = a;
			}
		}
	}
	else
		max = 0;
	cout << max << endl;
}