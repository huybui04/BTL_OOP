#ifndef DSHOADONNHAP_H
#define DSHOADONNHAP_H

#include <vector>
#include "HoaDonNhap.h"

class DSHoaDonNhap
{
private:
    std::vector<HoaDonNhap> danhSachHoaDon;

public:
    std::vector<HoaDonNhap> getDSHDN() const;
    void hienThiDanhSach() const;
    void themHoaDon(const HoaDonNhap &hoaDon);
    void xoaHoaDon(const std::string &maHDN);
    void suaHoaDon(const std::string &maHDN, const HoaDonNhap &hoaDonMoi);
    HoaDonNhap timKiemHoaDon(const std::string &maHDN);
    HoaDonNhap *timKiemHoaDonTheoMa(const std::string &maHDN);
    
    void docDuLieuTuFile(const std::string &tenFile);
    void ghiDuLieuVaoFile(const std::string &tenFile);
};

#endif /* DSHOADONNHAP_H */
