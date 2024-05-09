#ifndef SANPHAM_H
#define SANPHAM_H

#include <iostream>
#include <fstream>
#include "../DoiTuong.h"
using namespace std;

class SanPham : public DoiTuong
{
private:
    double Gia;
    string MaDanhMuc;

public:
    SanPham();
    SanPham(const string &MaSP, const string &TenSP, double Gia, const string &MaDanhMuc);

    string getMaSP() const;
    void setMaSP(const string &maSP);
    string getTenSP() const;
    void setTenSP(const string &tenSP);
    double getGia() const;
    void setGia(double gia);
    string getMaDanhMuc() const;
    void setMaDanhMuc(const string &maDanhMuc);

    void nhap();
    void xuat() const;
    void luuVaoFile(const string &tenFile) const;
};

#endif /* SANPHAM_H */
