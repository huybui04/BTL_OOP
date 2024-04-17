#ifndef CHITIETHOADONBAN_H
#define CHITIETHOADONBAN_H

#include <iostream>

class ChiTietHoaDonBan {
private:
	std::string MaHDB;
	std::string MaSP;
    int SoLuong;
    std::vector<SanPham> dssp;

public:
    ChiTietHoaDonBan();
    
    ChiTietHoaDonBan(const std::vector<SanPham> &dssp);
    
	ChiTietHoaDonBan(const std::string &MaHDB, const std::string &MaSP, int soLuong);
	
	ChiTietHoaDonBan(const std::string &MaHDB, const std::string &MaSp, int soLuong, const std::vector<SanPham> &dssp);

	std::string getMaHDB() const;
	void setMaHDB(const std::string &MaHDB);
	
	std::string getMaSP() const;
	void setMaSP(const std::string &MaSP);
	   
	std::vector<SanPham> getDSSP() const;
	void setDSSP(const std::vector<SanPham> &dssp);
	   
    int getSoLuong() const;
    void setSoLuong(int soLuong);
    
	void xuat() const;

    double tinhThanhTien() const;
};

#endif /* CHITIETHOADONBAN_H */

