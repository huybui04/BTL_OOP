#ifndef DSHOADONBAN_H
#define DSHOADONBAN_H

#include "HoaDonBan.h"

class DSHoaDonBan
{
private:
    std::vector<HoaDonBan> danhSachHoaDon;

public:
    std::vector<HoaDonBan> getDSHDB() const;
    void themHoaDon(const HoaDonBan &hoaDon);
    void xoaHoaDon(const std::string &maHDB);
    void suaHoaDon(const std::string &maHDB, const HoaDonBan &hoaDonMoi);
    void hienThiDanhSach() const;
    HoaDonBan timKiemHoaDon(const std::string &maHDB);
    HoaDonBan *timKiemHoaDonTheoMa(const std::string &maHDB);

    void docDuLieuTuFile(const std::string &tenFile);
    void ghiDuLieuVaoFile(const std::string &tenFile);
};

#endif /* DSHOADONBAN_H */
