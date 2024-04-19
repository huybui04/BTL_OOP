#ifndef CHITIETSANPHAM_H
#define CHITIETSANPHAM_H

#include <iostream>
#include "NguyenLieu.h"
#include "SanPham.h"

class ChiTietSanPham
{
private:
    std::string MaNL;
    std::string MaSP;
    int SoLuongSuDung;
    NguyenLieu NL;
    SanPham SP;

public:
    ChiTietSanPham();
    ChiTietSanPham(const std::string &MaNL, const std::string &MaSP, const int &SoLuongSuDung);
    ChiTietSanPham(const std::string &MaNL, const std::string &MaSP, const int &SoLuongSuDung, const NguyenLieu &NL, const SanPham &SP);

    std::string getMaNL() const;
    void setMaNL(const std::string &MaNL);

    std::string getMaSP() const;
    void setMaSP(const std::string &MaSP);

    NguyenLieu getNL() const;
    void setNL(const NguyenLieu &NL);

    SanPham getSP() const;
    void setSP(const SanPham &SP);

    int getSoLuongSuDung() const;
    void setSoLuongSuDung(int SoLuongSuDung);

    void nhap() const;
    void xuat() const;
    void luuVaoFile(const std::string &tenFile) const;
};

#endif /* CHITIETSANPHAM_H */

