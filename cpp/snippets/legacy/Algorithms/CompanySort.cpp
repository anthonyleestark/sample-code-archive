#include <iostream>
#include <string>
using namespace std;

struct NhanVien
{
	string MaNV;
	string HoTen;
	string PhongBan;
	int Luong, Thuong, ThucLanh;
};

void Swap(NhanVien &nv1, NhanVien &nv2)
{
	NhanVien temp = nv1;
	nv1 = nv2;
	nv2 = temp;
}

void SapXep(NhanVien danhsach[], int soluong)
{
	for (int i = 0; i < soluong; i++)
		for (int j = 0; j < soluong - 1; j++)
			if ((danhsach[j].PhongBan > danhsach[j + 1].PhongBan) || ((danhsach[j].PhongBan == danhsach[j + 1].PhongBan) && (danhsach[j].MaNV < danhsach[j + 1].MaNV)))
				Swap(danhsach[j], danhsach[j + 1]);
}

void Xuat(NhanVien danhsach[], int soluong)
{
	for (int i = 0; i < soluong; i++)
		cout << danhsach[i].HoTen << endl;
}

void companysort_main()
{
	int n;
	cin >> n;
	NhanVien *ds = new NhanVien[n];
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << endl << "Nhan vien thu " << i + 1 << endl;
		cout << "Ma NV: "; getline(cin, ds[i].MaNV);
		cout << "HoTen NV: "; getline(cin, ds[i].HoTen);
		cout << "Phong Ban: "; getline(cin, ds[i].PhongBan);
	}
	SapXep(ds, n);
	Xuat(ds, n);
}