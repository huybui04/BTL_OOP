#ifndef DANHMUCSANPHAM_H
#define DANHMUCSANPHAM_H

#include <iostream>
#include <fstream>
#include "../DoiTuong.h"

class DanhMucSanPham : public DoiTuong
{
public:
	DanhMucSanPham();
	DanhMucSanPham(const std::string &MaDM, const std::string &TenDM);

	std::string getMaDM() const;
	void setMaDM(const std::string &MaDM);
	std::string getTenDM() const;
	void setTenDM(const std::string &TenDM);

	void nhap();
	void xuat() const;
	void luuVaoFile(const std::string &tenTep) const;
};

#endif
