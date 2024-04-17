//#ifndef CHITIETHOADONNHAP_H
//#define CHITIETHOADONNHAP_H
//
//#include "HoaDonNhap.h"
//#include "NguyenLieu.h"
//
//class ChiTietHoaDonNhap {
//private:
//    HoaDonNhap HDN;
//    NguyenLieu NL;
//    int SoLuongNhap;
//
//public:
//    ChiTietHoaDonNhap();
//    ChiTietHoaDonNhap(const HoaDonNhap &HDN, const NguyenLieu &NL, int SoLuongNhap);
//
//    HoaDonNhap getHDN() const;
//    void setHDN(const HoaDonNhap &hdn);
//
//    NguyenLieu getNL() const;
//    void setNL(const NguyenLieu &nl);
//
//    int getSoLuongNhap() const;
//    void setSoLuongNhap(int soluong);
//
//    double tinhThanhTien() const;
//};
//
//#endif /* CHITIETHOADONNHAP_H */
#ifndef CHITIETHOADONNHAP_H
#define CHITIETHOADONNHAP_H

//#include "HoaDonNhap.h"
#include "NguyenLieu.h"

class ChiTietHoaDonNhap {
private:
    std::string MaHDN; // Thêm MaHDN d? luu mã hóa don nh?p
    std::string MaNL; // Thêm MaNL d? luu mã nguyên li?u
    int SoLuongNhap;

public:
    ChiTietHoaDonNhap();
    ChiTietHoaDonNhap(const std::string &maHDN, const std::string &maNL, int SoLuongNhap); // S?a d?i constructor

    std::string getMaHDN() const; // Thêm getter cho MaHDN
    void setMaHDN(const std::string &maHDN); // Thêm setter cho MaHDN

    std::string getMaNL() const; // Thêm getter cho MaNL
    void setMaNL(const std::string &maNL); // Thêm setter cho MaNL

    int getSoLuongNhap() const;
    void setSoLuongNhap(int soluong);

    double tinhThanhTien() const;
};

#endif /* CHITIETHOADONNHAP_H */

