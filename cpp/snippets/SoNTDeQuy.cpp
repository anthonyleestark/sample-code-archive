#include <iostream>
using namespace std;

bool isPrime(int n)
{
	bool isPrime = true;
	for (int j = 2; j <= sqrt(n); j++)
		if (n % j == 0)
			isPrime = false;
	return isPrime;
}

int TongNT(int n)
{
	if (n == 0)
		return 0;
	else
	{
		/*int tong = 0, count = 1, num = 2;
		while (count <= n)
		{
			if (isPrime(num))
			{
				tong = tong + num;
				count++;
			}
			num++;
		}
		return tong;*/
	}
}

void main()
{
	cout << TongNT(5) << endl;
}