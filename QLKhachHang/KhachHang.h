#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iostream>
#include <fstream>
#include "../Nguoi.h"

class KhachHang : public Nguoi
{
private: 
	std::string MaKH;
public:
    KhachHang();
    KhachHang(const std::string &CCCD, const std::string &TenKH, const std::string &SDT, const std::string &DiaChi, const std::string &GioiTinh, const std::string &NgaySinh, const std::string &MaKH);

	std::string getCCCD() const;
    void setCCCD(const std::string &cccd);
    std::string getTenKH() const;
    void setTenKH(const std::string &tenKH);
    std::string getSDT() const;
    void setSDT(const std::string &sdt);
    std::string getDiaChi() const;
    void setDiaChi(const std::string &diaChi);
    std::string getGioiTinh() const;
    void setGioiTinh(const std::string &gioiTinh);
	std::string getNgaySinh() const;
    void setNgaySinh(const std::string &ngaySinh);
	std::string getMaKH() const;
	void setMaKH(const std::string &maKH);

    void nhap();
    void xuat() const;
    void luuVaoFile(const std::string &tenFile) const;
};

#endif /* KHACHHANG_H */
