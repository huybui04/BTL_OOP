#ifndef KHUVUC_H
#define KHUVUC_H

#include <iostream>
#include <fstream>

class KhuVuc : public DoiTuong {
public:
    KhuVuc();
    KhuVuc(const std::string &MaKV, const std::string &TenKV);

    std::string getMaKV() const;
    void setMaKV(const std::string &MaKV);
    std::string getTenKV() const;
    void setTenKV(const std::string &TenKV);

    void nhap();
    void xuat() const;
    void luuVaoFile(const std::string &tenTep) const;
};

#endif

