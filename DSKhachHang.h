#ifndef DSKHACHHANG_H
#define DSKHACHHANG_H

#include "KhachHang.h"
#include <bits/stdc++.h>

class DSKhachHang
{
private:
    std::vector<KhachHang> danhSachKhachHang;

public:
    void themKhachHang(const KhachHang &khachHang);
    void docTuFile(const std::string &tenFile);
    void hienThiDanhSach() const;
    void suaKhachHang(const std::string &maKH, const KhachHang &khachHang);
    void xoaKhachHang(const std::string &maKH);
    void luuVaoFile(const std::string &tenTep) const;

    std::vector<KhachHang> getDanhSachKhachHang() const;
    KhachHang *timKiemTheoMa(const string &maKH);
};

#endif /* DSKHACHHANG_H */
