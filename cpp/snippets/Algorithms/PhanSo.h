#pragma once
struct PhanSo
{
private:
	int tu, mau;
public:
	PhanSo();
	PhanSo(int, int);
	void NhapPS();
	void XuatPS() const;
	friend int UCLN(int, int);
	void RutGon();

	PhanSo Cong(const PhanSo&);
	PhanSo Tru(const PhanSo&);
	PhanSo Nhan(const PhanSo&);
	PhanSo Chia(const PhanSo&);
};