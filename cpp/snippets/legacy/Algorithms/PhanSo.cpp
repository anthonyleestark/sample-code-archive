#include <iostream>
#include "PhanSo.h"
using namespace std;

int UCLN(int num1, int num2)
{
	while (num1 != num2)
	{
		if (num1 > num2)
			num1 = num1 - num2;
		else
			num2 = num2 - num1;
	}
	return num1;
}

PhanSo::PhanSo()
{
	tu = 0;
	mau = 1;
}

PhanSo::PhanSo(int t, int m)
{
	tu = t;
	mau = m;
}

void PhanSo::NhapPS()
{
	cout << "Nhap tu so: "; cin >> tu;
	cout << "Nhap mau so: "; cin >> mau;
}

void PhanSo::XuatPS() const
{
	cout << tu << "/" << mau << endl;
}

void PhanSo::RutGon()
{
	int uoc = UCLN(tu, mau);
	tu = tu / uoc; mau = mau / uoc;
}

PhanSo PhanSo::Cong(const PhanSo& ps)
{
	PhanSo res;
	res.tu = this->tu*ps.mau + ps.tu*this->mau;
	res.mau = this->mau*ps.mau;
	res.RutGon();
	return res;
}
PhanSo PhanSo::Tru(const PhanSo& ps)
{
	return this->Cong({ -ps.tu, ps.mau });
}

PhanSo PhanSo::Nhan(const PhanSo& ps)
{
	PhanSo res;
	res.tu = this->tu*ps.tu;
	res.mau = this->mau*ps.mau;
	return res;
}

PhanSo PhanSo::Chia(const PhanSo& ps)
{
	return this->Nhan({ ps.mau, ps.tu });
}

void phanso_main()
{
	PhanSo ps(1,2), ps1(1, 3);
	cout << "Tong hai phan so: "; (ps.Cong(ps1)).XuatPS();
	cout << "Hieu hai phan so: "; (ps.Tru(ps1)).XuatPS();
	cout << "Tich hai phan so: "; (ps.Nhan(ps1)).XuatPS();
	cout << "Thuong hai phan so: "; (ps.Chia(ps1)).XuatPS();
}