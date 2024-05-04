#ifndef NGUYENLIEU_H
#define NGUYENLIEU_H

#include <iostream>
#include <fstream>
#include "../DoiTuong.h"

class NguyenLieu : public DoiTuong
{
private:
    std::string NSX;
    std::string HSD;
    double Gia;

public:
    NguyenLieu();
    NguyenLieu(const std::string &MaNL, const std::string &TenNL, const std::string &NSX, const std::string &HSD, double Gia);

    std::string getMaNL() const;
    void setMaNL(const std::string &maNL);
    std::string getTenNL() const;
    void setTenNL(const std::string &tenNL);
    std::string getNSX() const;
    void setNSX(const std::string &nsx);
    std::string getHSD() const;
    void setHSD(const std::string &hsd);
    double getGia() const;
    void setGia(double gia);

    void nhap();
    void xuat() const;
    void luuVaoFile(const std::string &tenFile) const;
};

#endif /* NGUYENLIEU_H */
