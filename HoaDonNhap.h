//#ifndef HOADONNHAP_H
//#define HOADONNHAP_H
//
//#include <iostream>
//#include <vector>
//#include "NhanVien.h"
//#include "NhaCungCap.h"
//#include "ChiTietHoaDonNhap.h"
//
//class HoaDonNhap {
//private:
//    std::string MaHDN, NgayNhap;
//    NhanVien nv;
//    NhaCungCap ncc;
//    std::vector<ChiTietHoaDonNhap> dsCTHDN;
//
//public:
//    HoaDonNhap();
//    HoaDonNhap(std::string maHDN, std::string ngayNhap, const NhanVien &nhanVien, const NhaCungCap &nhaCungCap);
//
//    void setMaHDN(std::string maHDN);
//    std::string getMaHDN() const;
//
//    void setNgayNhap(std::string ngayNhap);
//    std::string getNgayNhap() const;
//
//    void setNhanVien(const NhanVien &nhanVien);
//    NhanVien getNhanVien() const;
//
//    void setNhaCungCap(const NhaCungCap &nhaCungCap);
//    NhaCungCap getNhaCungCap() const;
//
//    void setDsCTHDN(const std::vector<ChiTietHoaDonNhap> &ds);
//    std::vector<ChiTietHoaDonNhap> getDsCTHDN() const;
//
//    void themChiTietHoaDon(const ChiTietHoaDonNhap &chiTiet);
//    double tinhTongTien() const;
//    void hienThi() const;
//};
//
//#endif /* HOADONNHAP_H */

#ifndef HOADONNHAP_H
#define HOADONNHAP_H

#include <iostream>
#include <vector>
#include "NhanVien.h"
#include "NhaCungCap.h"
#include "ChiTietHoaDonNhap.h"

class HoaDonNhap {
private:
    std::string MaHDN, NgayNhap;
    std::string MaNV, MaNCC; // Thay d?i ki?u d? li?u thành string
    std::vector<ChiTietHoaDonNhap> dsCTHDN;

public:
    HoaDonNhap();
    HoaDonNhap(std::string maHDN, std::string ngayNhap, const std::string &maNV, const std::string &maNCC);

    void setMaHDN(std::string maHDN);
    std::string getMaHDN() const;

    void setNgayNhap(std::string ngayNhap);
    std::string getNgayNhap() const;

    void setMaNV(const std::string &maNV); // Thêm setter và getter cho MaNV
    std::string getMaNV() const;

    void setMaNCC(const std::string &maNCC); // Thêm setter và getter cho MaNCC
    std::string getMaNCC() const;

    void setDsCTHDN(const std::vector<ChiTietHoaDonNhap> &ds);
    std::vector<ChiTietHoaDonNhap> getDsCTHDN() const;

    void themChiTietHoaDon(const ChiTietHoaDonNhap &chiTiet);
    double tinhTongTien() const;
    void hienThi() const;
};

#endif /* HOADONNHAP_H */

