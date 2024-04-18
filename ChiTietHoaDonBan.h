#ifndef CHITIETHOADONBAN_H
#define CHITIETHOADONBAN_H

#include <iostream>

class ChiTietHoaDonBan {
private:
	std::string MaHDB;
	std::string MaSP;
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
	   
	SanPham  getSP() const;
	void setSP(const SanPham &sp);
	   
    int getSoLuong() const;
    void setSoLuong(int soLuong);
    
	void xuat() const;

    double tinhThanhTien() const;
};

#endif /* CHITIETHOADONBAN_H */

