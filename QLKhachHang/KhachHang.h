#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iostream>
#include <fstream>
#include "../Nguoi.h"

class KhachHang : public Nguoi
{
public:
    KhachHang();
    KhachHang(const std::string &MaKH, const std::string &TenKH, const std::string &SDT);

    std::string getMaKH() const;
    void setMaKH(std::string maKH);
    std::string getTenKH() const;
    void setTenKH(std::string tenKH);
    std::string getSDT() const;
    void setSDT(std::string sdt);

    void nhap();
    void xuat() const;
    void luuVaoFile(const std::string &tenFile) const;
};

#endif /* KHACHHANG_H */
