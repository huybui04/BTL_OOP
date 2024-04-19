#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class KhachHang {
private:
    std::string MaKH, TenKH, SDT;

public:
    KhachHang();
    KhachHang(std::string MaKH, std::string TenKH, std::string SDT);
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

