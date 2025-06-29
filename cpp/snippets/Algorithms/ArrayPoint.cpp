#include <iostream>
using namespace std;

void func(int *a, int n)
{
	int size = sizeof(*a) / sizeof(&a[0]);
	for (int i = 0; i < size; i++)
		a[i] = i + n;
}

void main()
{
	int a[10];
	func(a, 3);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl << "So phan tu mang: " << (sizeof(a) / sizeof(a[0])) << endl;
}