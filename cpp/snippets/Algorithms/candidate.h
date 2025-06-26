#pragma once

#include <iostream>
#include <conio.h>
#include<string>
using namespace std;

class Candidate
{
	int msTS;
	string ten;
	string ngaySinh;
	int diemToan;
	int diemVan;
	int diemAnh;
public:
	void nhapDuLieuTS();
	void xuatThongTinTS();
	bool check15();
};
class TestCandidate
{
	int soTS;
	Candidate *danhSach;
public:
	void nhapSoSvVaKhoiTaoDanhSach();
	void nhapDuLieuDanhSach();
	void InTSDiemTongTren15();
};
