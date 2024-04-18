#ifndef DSCHITIETHOADONNHAP_H
#define DSCHITIETHOADONNHAP_H

#include <vector>
#include "ChiTietHoaDonNhap.h"

class DSChiTietHoaDonNhap {
private:
    std::vector<ChiTietHoaDonNhap> danhSachChiTietHoaDonNhap;

public:
    std::vector<ChiTietHoaDonNhap> getCTHDN() const;
    void themChiTiet(const ChiTietHoaDonNhap &chiTiet);
    void suaChiTiet(const std::string &maHDN, const ChiTietHoaDonNhap &chiTietMoi); 
    void xoaChiTiet(const std::string &maHDN);
    ChiTietHoaDonNhap timKiemChiTiet(const std::string &maHDN);
    void ghiDuLieuVaoFile(std::string tenFile);
};

#endif /* DSCHITIETHOADONNHAP_H */

