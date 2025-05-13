/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
for
while
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
int search(int a[], int n, int k, int left = 0, int right = 0)
{
	if (right == 0)
		right = n - 1;
	int mid = (left + right) / 2;
	if (a[mid] == k)
		return mid;
	else if (left == right)
		return -1; // Ko tim thay
	else
	{
		if (a[mid] < k)
			left = mid + 1;
		else
			right = mid - 1;
		return search(a, n, k, left, right);
	}
}

int dequynhiphan_main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		int id = search(a, n, x);

		cout << id;
		cout << endl;
	}

	delete[]a;
	return 1;
}