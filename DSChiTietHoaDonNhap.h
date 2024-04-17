//#ifndef DSCHITIETHOADONNHAP_H
//#define DSCHITIETHOADONNHAP_H
//
//#include <vector>
//#include "ChiTietHoaDonNhap.h"
//
//class DSChiTietHoaDonNhap {
//private:
//    std::vector<ChiTietHoaDonNhap> danhSachChiTietHoaDonNhap;
//
//public:
//    std::vector<ChiTietHoaDonNhap> getCTHDN() const;
//    void themChiTiet(const ChiTietHoaDonNhap &chiTiet);
//    void suaChiTiet(const HoaDonNhap &hdn, const ChiTietHoaDonNhap &chiTietMoi);
//    void xoaChiTiet(const HoaDonNhap &hdn);
//    ChiTietHoaDonNhap timKiemChiTiet(const HoaDonNhap &hdn);
//    void ghiDuLieuVaoFile(std::string tenFile);
//};
//
//#endif /* DSCHITIETHOADONNHAP_H */
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
    void suaChiTiet(const std::string &maHDN, const ChiTietHoaDonNhap &chiTietMoi); // Thay d?i tham s? c?a hàm suaChiTiet
    void xoaChiTiet(const std::string &maHDN); // Thay d?i tham s? c?a hàm xoaChiTiet
    ChiTietHoaDonNhap timKiemChiTiet(const std::string &maHDN); // Thay d?i tham s? c?a hàm timKiemChiTiet
    void ghiDuLieuVaoFile(std::string tenFile);
};

#endif /* DSCHITIETHOADONNHAP_H */

