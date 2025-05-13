#include <iostream>
using namespace std;
void main()
{
	int N = 0;
	cin >> N;
	int count = 1, number = 2;
	while (count <= N)
	{
		bool isPrime = true;
		for (int j = 2; j <= sqrt(number); j++)
			if (number % j == 0)
				isPrime = false;
		if (isPrime)
		{
			cout << number << endl;
			count++;
		}
		number++;
	}
	system("pause");
}