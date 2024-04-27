#ifndef DSCHITIETHOADONNHAP_H
#define DSCHITIETHOADONNHAP_H

#include <vector>
#include "ChiTietHoaDonNhap.h"

class DSChiTietHoaDonNhap {
private:
    std::vector<ChiTietHoaDonNhap> danhSachChiTietHoaDonNhap;

public:
    std::vector<ChiTietHoaDonNhap> getDSCTHDN() const;
    void themChiTiet(const ChiTietHoaDonNhap &chiTiet);
    void suaChiTiet(const std::string &maHDN, const ChiTietHoaDonNhap &chiTietMoi); 
    void xoaChiTiet(const std::string &maHDN);
    void hienThiDanhSach() const;
    ChiTietHoaDonNhap timKiemChiTiet(const std::string &maHDN);
	ChiTietHoaDonNhap *timKiemChiTietHoaDonTheoMa(const std::string &maHDN);
	    
    void docDuLieuTuFile(const std::string &tenFile);
    void ghiDuLieuVaoFile(const std::string &tenFile);
};

#endif /* DSCHITIETHOADONNHAP_H */

