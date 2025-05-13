#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number)
{
	if (number == 0)
		return true;
	if (number == 1)
		return false;
	bool check = true;
	for (int run = 2; run <= sqrt(number); run++)
		if (number % run == 0)
		{
			check = false;
			break;
		}
	return check;
}

int main()
{
	int N, K, *pArray;
	cin >> N;
	cin >> K;
	if (N <= 0 || N >= 1000)
		return 0;
	pArray = new int[N];
	// Nhap mang
	for (int count = 0; count < N; count++)
		cin >> pArray[count];
	// Tong so nguyen to
	int nSumPrime = 0;
	for (int count = 0; count < N; count++)
	{
		if (isPrime(pArray[count]) == true)
			nSumPrime += pArray[count];
	}
	cout << nSumPrime << endl;
	// So thu K khong phai nguyen to
	if ((K >= 0 && K <= 1000) && (K < N))
	{
		int count = -1, dem = 0;
		for (; dem < N; dem++)
		{
			if (isPrime(pArray[dem]) == false)
				count++;
			if (count == K)
				break;
		}
		cout << pArray[dem] << endl;
	}
	return 0;
}