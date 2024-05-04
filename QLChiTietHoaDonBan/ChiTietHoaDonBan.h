#ifndef CHITIETHOADONBAN_H
#define CHITIETHOADONBAN_H

#include "../ChiTietDoiTuong.h"
#include "../QLSanPham/SanPham.h"
#include <iostream>

class ChiTietHoaDonBan : public ChiTietDoiTuong
{
private:
	int SoLuong;
	SanPham SP;

public:
	ChiTietHoaDonBan();
	ChiTietHoaDonBan(const std::string &MaHDB, const std::string &MaSP, const int &soLuong);
	ChiTietHoaDonBan(const std::string &MaHDB, const std::string &MaSP, const int &soLuong, const SanPham &sp);

	std::string getMaHDB() const;
	void setMaHDB(const std::string &MaHDB);

	std::string getMaSP() const;
	void setMaSP(const std::string &MaSP);

	SanPham getSP() const;
	void setSP(const SanPham &sp);

	int getSoLuong() const;
	void setSoLuong(int soLuong);

	void nhap() const;
	void xuat() const;
	void hienThi() const;
	void luuVaoFile(const std::string &tenFile) const;

	double tinhThanhTien() const;
};

#endif /* CHITIETHOADONBAN_H */
