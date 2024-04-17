//#ifndef DSHOADONNHAP_H
//#define DSHOADONNHAP_H
//
//#include <iostream>
//#include <vector>
//#include "HoaDonNhap.h"
//
//class DSHoaDonNhap {
//private:
//    std::vector<HoaDonNhap> danhSachHoaDon;
//
//public:
//    std::vector<HoaDonNhap> getDSHDN() const;
//    void themHoaDon(const HoaDonNhap &hoaDon);
//    void xoaHoaDon(std::string maHDN);
//    void suaHoaDon(std::string maHDN, const HoaDonNhap &hoaDonMoi);
//    HoaDonNhap timKiemHoaDon(std::string maHDN);
//    void docDuLieuTuFile(std::string tenFile);
//    void ghiDuLieuVaoFile(std::string tenFile);
//};
//
//#endif /* DSHOADONNHAP_H */
#ifndef DSHOADONNHAP_H
#define DSHOADONNHAP_H

//#include <iostream>
#include <vector>
#include "HoaDonNhap.h"

class DSHoaDonNhap {
private:
    std::vector<std::string> danhSachHoaDon; // Thay d?i ki?u d? li?u

public:
    std::vector<std::string> getDSHDN() const;
    void themHoaDon(const std::string &maHDN); // Thay d?i tham s? c?a hàm themHoaDon
    void xoaHoaDon(std::string maHDN);
    void suaHoaDon(std::string maHDN, const std::string &maHDNMoi); // Thay d?i tham s? c?a hàm suaHoaDon
    std::string timKiemHoaDon(std::string maHDN); // Thay d?i ki?u tr? v? c?a hàm timKiemHoaDon
    void docDuLieuTuFile(std::string tenFile);
    void ghiDuLieuVaoFile(std::string tenFile);
};

#endif /* DSHOADONNHAP_H */

