#ifndef CALAMVIEC_H
#define CALAMVIEC_H

#include <iostream>
#include <fstream>

class CaLamViec {
private:
    std::string MaCa;
    std::string TenCa;
    std::string GioBatDau;
    std::string GioKetThuc;
    double Luong;

public:
    CaLamViec();
    CaLamViec(const std::string &maCa, const std::string &tenCa, const std::string &gioBatDau, const std::string &gioKetThuc, double luong);

    std::string getMaCa() const;
    void setMaCa(const std::string &maCa);
    std::string getTenCa() const;
    void setTenCa(const std::string &tenCa);
    std::string getGioBatDau() const;
    void setGioBatDau(const std::string &gioBatDau);
    std::string getGioKetThuc() const;
    void setGioKetThuc(const std::string &gioKetThuc);
    double getLuong() const;
    void setLuong(double luong);

    void nhap();
    void xuat() const;
    void luuVaoFile(const std::string &tenFile) const;
};

#endif /* CALAMVIEC_H */

