#ifndef KHUVUC_H
#define KHUVUC_H

#include <iostream>
#include <fstream>
#include <sstream>

class KhuVuc {
private:
    std::string MaKV;
    std::string TenKV;

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

