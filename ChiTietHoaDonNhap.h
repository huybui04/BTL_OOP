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
    std::string MaHDN; // Th�m MaHDN d? luu m� h�a don nh?p
    std::string MaNL; // Th�m MaNL d? luu m� nguy�n li?u
    int SoLuongNhap;

public:
    ChiTietHoaDonNhap();
    ChiTietHoaDonNhap(const std::string &maHDN, const std::string &maNL, int SoLuongNhap); // S?a d?i constructor

    std::string getMaHDN() const; // Th�m getter cho MaHDN
    void setMaHDN(const std::string &maHDN); // Th�m setter cho MaHDN

    std::string getMaNL() const; // Th�m getter cho MaNL
    void setMaNL(const std::string &maNL); // Th�m setter cho MaNL

    int getSoLuongNhap() const;
    void setSoLuongNhap(int soluong);

    double tinhThanhTien() const;
};

#endif /* CHITIETHOADONNHAP_H */

