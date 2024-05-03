#ifndef SANPHAM_H
#define SANPHAM_H

#include <iostream>
#include <fstream>

class SanPham : public DoiTuong {
private:
    double Gia;

public:
    SanPham();
    SanPham(const std::string &MaSP, const std::string &TenSP, double Gia);

    std::string getMaSP() const;
    void setMaSP(const std::string &maSP);
    std::string getTenSP() const;
    void setTenSP(const std::string &tenSP);
    double getGia() const;
    void setGia(double gia);

    void nhap();
    void xuat() const;
    void luuVaoFile(const std::string &tenFile) const;
};

#endif /* SANPHAM_H */

