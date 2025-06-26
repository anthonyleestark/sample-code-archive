#include <iostream>
#include <exception>
using namespace std;

template <typename T>
T Nhap()
{
	T a;
	cout << "Nhap so nguyen bat ky: ";
	while (!(cin >> a)) {
		cout << "Nhap sai. Vui long nhap lai!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Nhap so nguyen bat ky: ";
	}
	return a;
}

void wronginput_main()
{
	int a;
	a = Nhap<int>();
	cout << "So vua nhap la: " << a << endl;
	float b;
	b = Nhap<float>();
	cout << "So vua nhap la: " << b << endl;
}