#ifndef HOADON_H
#define HOADON_H

#include <iostream>
#include <fstream>

class HoaDon {
protected:
    std::string MaHoaDon;
    std::string Ngay;

public:
    HoaDon();
    HoaDon(const std::string &ma, const std::string &ngay);

    std::string getMa() const;
    void setMa(const std::string &ma);
    std::string getNgay() const;
    void setNgay(const std::string &ngay);

    void nhap();
    void xuat() const;
    void luuVaoFile(const std::string &tenFile) const;
};

#endif /* HOADON_H */

