#include <iostream>
using namespace std;
int main()
{
	int count, n;
	cin >> count;
	for (int dem = 1; dem <= count; dem++)
	{
		cin >> n;
		// kiểm tra n là snt ko
		bool isPrime = true;
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n%i == 0)
				isPrime = false;
		}
		if (isPrime)
			cout << n << endl;
		else
		{
			// tạo mảng thừa số nguyên tố giảm dần
			int *nArray = new int[n];
			int arrayID = 0;
			for (int i = n - 1; i >= 2; i--)
			{
				// kiểm tra i là số nguyên tố
				isPrime = true;
				for (int y = 2; y <= sqrt(i); y++)
				{
					if (i % y == 0)
					{
						isPrime = false;
						break;
					}
				}
				if (isPrime)
				{
					// nếu n chia hết cho i thì add vào mảng
					if (n % i == 0)
					{
						nArray[arrayID] = i;
						n = n / i;
						arrayID++;
						// tăng i lên để xét lại nếu có nhiều thừa số trùng nhau
						// vd: 97 = 37*3*3*3
						i++;
					}
				}
			}
			// in ra kết quả
			for (int t = 0; t <= arrayID - 2; t++)
				// in ra số và dấu x
				cout << nArray[t] << " x ";
			// in ra số cuối cùng
			cout << nArray[arrayID - 1] << endl;
		}
	}
	// system("pause");
	return 0;
}