#include "Candidate.h"

int candidate_main()
{
	TestCandidate A;
	A.nhapSoSvVaKhoiTaoDanhSach();
	A.nhapDuLieuDanhSach();
	A.InTSDiemTongTren15();

	_getch();
	return 0;
}

void Candidate::nhapDuLieuTS()
{
	cout << "Nhap ten SV: ";
	getline(cin, ten);
	
	cout << "Nhap ngay thang nam sinh: ";
	getline(cin, ngaySinh);
	cout << "Nhap diem Toan -> Van -> Anh: ";
	cin >> diemToan >> diemVan >> diemAnh;

}

void Candidate::xuatThongTinTS()
{
	cout << "\nTen: " << ten;
	cout << "\nMa So Thi Sinh: " << msTS;
	cout << "\nDiem Toan - Van - Anh: " << diemToan << " " << diemVan << " " << diemAnh;
}

bool Candidate::check15()
{
	if (diemToan + diemAnh + diemVan > 15) return true;
	return false;
}

void TestCandidate::nhapSoSvVaKhoiTaoDanhSach()
{
	cout << "Nhap so Thi Sinh: ";
	cin >> soTS;
	danhSach = new Candidate[soTS];
}

void TestCandidate::nhapDuLieuDanhSach()
{
	for (int i = 0; i < soTS; i++)
	{
		cout << "Thi Sinh thu " << i<<":\n";
		danhSach[i].nhapDuLieuTS();
	}
}

void TestCandidate::InTSDiemTongTren15()
{
	for (int i = 0; i < soTS; i++)
	{
//		if (danhSach[i].check15) danhSach[i].xuatThongTinTS();
	}
}
