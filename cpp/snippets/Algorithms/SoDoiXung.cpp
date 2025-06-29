#include <iostream>
#include <math.h>
using namespace std;  // Khi mà ta gặp mấy bài chia lấy nguyên, lấy dư đều cần kiểu nguyên
//long countnum(long &x) // còn hàm mũ pow lại cần kiểu thực thì bị loạn xạ kiểu dữ liệu hết lên ....
//{
//	int i = 0;
//	while (x > 0)
//	{
//		x = x / 10;
//		i++;
//	}
//	return (i-1)/2;  // Thu được số lượng chữ số ở đuôi hoặc đầu, ở giữa chỉ 1 chữ số;
//}
//long headnum(long n) // số đầu
//{
//	double t = countnum(n) + 1;
//	long x = (long) pow(10.0, t);  // pow chỉ xài kiểu thực (ban đầu kiểu int tau chuyển lại long rồi đó)
//	return n / x;
//}
//long endnum(long n) // số cuối
//{
//	double t = countnum(n);
//	long x = (long) pow(10.0, t); // pow chỉ xài kiểu thực (ban đầu kiểu int tau chuyển lại long rồi đó)
//	return n%x;
//}

// mấy hàm phía trên không cần thiết
// một hàm thôi là đủ

long long reverse_num(long long n) // đảo ngược số n
{
	long long u = 0;
	long long x = n; // gán biến tạm x = n
	while (x > 0)
	{
		u = u*10 + (x % 10); //chỗ này đã sửa
		x = x / 10;
	}
	return u; //chỗ này là u
}

// chỗ này là so sánh số n với số đảo ngược của n bằng hàm reverse_num(long n)

int main()
{
	long long n;
	cin >> n;
	if (n == reverse_num(n)) // khi n == số đảo ngược
		cout << "la so doi xung";
	else cout << "khong phai la so doi xung";
	system("pause");
	return 0;
}