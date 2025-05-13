#include <iostream>
#include <math.h>
using namespace std;

long Fib1(long n)
{
	long a, b, c, k;
	if (n <= 1)
		return n;
	a = 0; b = 1;
	for (k = 2; k <= n; k++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

long Fib2(long n)
{
	if (n <= 1)
		return n;
	return Fib2(n - 1) + Fib2(n - 2);
}

void main()
{
	long n;
	cin >> n;
	cout << Fib2(n);
}