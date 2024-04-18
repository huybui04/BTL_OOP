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
    std::string MaNV, MaNCC; 
    std::vector<ChiTietHoaDonNhap> dsCTHDN;

public:
    HoaDonNhap();
    HoaDonNhap(std::string maHDN, std::string ngayNhap, const std::string &maNV, const std::string &maNCC);

    void setMaHDN(std::string maHDN);
    std::string getMaHDN() const;

    void setNgayNhap(std::string ngayNhap);
    std::string getNgayNhap() const;

    void setMaNV(const std::string &maNV); 
    std::string getMaNV() const;

    void setMaNCC(const std::string &maNCC); 
    std::string getMaNCC() const;

    void setDsCTHDN(const std::vector<ChiTietHoaDonNhap> &ds);
    std::vector<ChiTietHoaDonNhap> getDsCTHDN() const;

    void themChiTietHoaDon(const ChiTietHoaDonNhap &chiTiet);
    double tinhTongTien() const;
    void hienThi() const;
};

#endif /* HOADONNHAP_H */

