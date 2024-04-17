#ifndef DSHOADONBAN_H
#define DSHOADONBAN_H

//#include <iostream>
//#include <vector>
#include "HoaDonBan.h"

class DSHoaDonBan {
private:
    std::vector<HoaDonBan> danhSachHoaDon;

public:
    std::vector<HoaDonBan> getDSHDB() const;
    void themHoaDon(const HoaDonBan &hoaDon);
    void xoaHoaDon(const std::string &maHDB);
    void suaHoaDon(const std::string &maHDB, const HoaDonBan &hoaDonMoi);
    HoaDonBan timKiemHoaDon(const std::string &maHDB);
    void docDuLieuTuFile(const std::string &tenFile);
    void ghiDuLieuVaoFile(const std::string &tenFile);
};

#endif /* DSHOADONBAN_H */

