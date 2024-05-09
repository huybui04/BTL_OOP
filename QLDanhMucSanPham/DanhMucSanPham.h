#ifndef DANHMUCSANPHAM_H
#define DANHMUCSANPHAM_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "../QLSanPham/SanPham.h"
#include "../QLSanPham/DSsanpham.h"
#include "../DoiTuong.h"

using namespace std;
class DanhMucSanPham : public DoiTuong
{
private:
	vector<SanPham> spTheoDanhMuc;

public:
	DanhMucSanPham();
	DanhMucSanPham(const string &MaDM, const string &TenDM);

	string getMaDM() const;
	void setMaDM(const string &MaDM);
	string getTenDM() const;
	void setTenDM(const string &TenDM);

	void nhap();
	void xuat() const;
	void luuVaoFile(const string &tenTep) const;
};

#endif